// DolRecomp output
#include "../generated.h"

static void loop_8010FAA0(CPUState* ctx) {
label_8010FAA0:
    ctx->downcount -= 8;
    ctx->pc = 0x8010FAA0u;
    // 8010FAA0: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 8010FAA4: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 8010FAA8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x8010FAACu;
    // 8010FAAC: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 8010FAB0: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 8010FAB4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 8010FAB8: cmpw    r9, r8
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

    // 8010FABC: bc    4, 2, 0x8010FAA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010FAA0u;
                return;
            }
            goto label_8010FAA0;
        }
    }

    ctx->pc = 0x8010FAC0u;
}

static void loop_801103DC(CPUState* ctx) {
label_801103DC:
    ctx->downcount -= 8;
    ctx->pc = 0x801103DCu;
    // 801103DC: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 801103E0: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 801103E4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x801103E8u;
    // 801103E8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 801103EC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 801103F0: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 801103F4: cmpw    r9, r8
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

    // 801103F8: bc    4, 2, 0x801103DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801103DCu;
                return;
            }
            goto label_801103DC;
        }
    }

    ctx->pc = 0x801103FCu;
}

static void loop_80111AAC(CPUState* ctx) {
label_80111AAC:
    ctx->downcount -= 16;
    ctx->pc = 0x80111AACu;
    // 80111AAC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80111AB0: addic.  r27, r27, -24
    {
        u64 a = ctx->gpr[27];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[27] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[27];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    ctx->pc = 0x80111AB4u;
    // 80111AB4: stw     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80111AB8u;
    // 80111AB8: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80111ABCu;
    // 80111ABC: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80111AC0u;
    // 80111AC0: lwz     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80111AC4u;
    // 80111AC4: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80111AC8u;
    // 80111AC8: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80111ACCu;
    // 80111ACC: stw     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80111AD0u;
    // 80111AD0: lwz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80111AD4u;
    // 80111AD4: stw     r0, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80111AD8u;
    // 80111AD8: lwz     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80111ADC: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

    ctx->pc = 0x80111AE0u;
    // 80111AE0: stw     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80111AE4: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

    // 80111AE8: bc    4, 2, 0x80111AAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111AACu;
                return;
            }
            goto label_80111AAC;
        }
    }

    ctx->pc = 0x80111AECu;
}

static void loop_80111F70(CPUState* ctx) {
label_80111F70:
    ctx->downcount -= 8;
    ctx->pc = 0x80111F70u;
    // 80111F70: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 80111F74: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

    // 80111F78: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x80111F7Cu;
    // 80111F7C: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80111F80: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 80111F84: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

    // 80111F88: cmpw    r9, r8
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

    // 80111F8C: bc    4, 2, 0x80111F70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111F70u;
                return;
            }
            goto label_80111F70;
        }
    }

    ctx->pc = 0x80111F90u;
}

static void loop_801124CC(CPUState* ctx) {
label_801124CC:
    ctx->downcount -= 3;
    ctx->pc = 0x801124CCu;
    // 801124CC: stw     r26, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

    // 801124D0: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

    // 801124D4: bc    16, 0, 0x801124CC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801124CCu;
                return;
            }
            goto label_801124CC;
        }
    }

    ctx->pc = 0x801124D8u;
}

static void loop_80112868(CPUState* ctx) {
label_80112868:
    ctx->downcount -= 3;
    ctx->pc = 0x80112868u;
    // 80112868: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

    // 8011286C: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

    // 80112870: bc    16, 0, 0x80112868
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112868u;
                return;
            }
            goto label_80112868;
        }
    }

    ctx->pc = 0x80112874u;
}

static void loop_80112A0C(CPUState* ctx) {
label_80112A0C:
    ctx->downcount -= 16;
    ctx->pc = 0x80112A0Cu;
    // 80112A0C: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80112A10: addic.  r9, r9, -24
    {
        u64 a = ctx->gpr[9];
        u64 b = (u32)(s32)(-24);
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

    ctx->pc = 0x80112A14u;
    // 80112A14: stw     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112A18u;
    // 80112A18: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80112A1Cu;
    // 80112A1C: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112A20u;
    // 80112A20: lwz     r0, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80112A24u;
    // 80112A24: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112A28u;
    // 80112A28: lwz     r0, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80112A2Cu;
    // 80112A2C: stw     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112A30u;
    // 80112A30: lwz     r0, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80112A34u;
    // 80112A34: stw     r0, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112A38u;
    // 80112A38: lwz     r0, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80112A3C: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

    ctx->pc = 0x80112A40u;
    // 80112A40: stw     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80112A44: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

    // 80112A48: bc    4, 2, 0x80112A0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112A0Cu;
                return;
            }
            goto label_80112A0C;
        }
    }

    ctx->pc = 0x80112A4Cu;
}

static void loop_80112AB8(CPUState* ctx) {
label_80112AB8:
    ctx->downcount -= 16;
    ctx->pc = 0x80112AB8u;
    // 80112AB8: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80112ABC: addic.  r9, r9, -24
    {
        u64 a = ctx->gpr[9];
        u64 b = (u32)(s32)(-24);
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

    ctx->pc = 0x80112AC0u;
    // 80112AC0: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112AC4u;
    // 80112AC4: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80112AC8u;
    // 80112AC8: stw     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112ACCu;
    // 80112ACC: lwz     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80112AD0u;
    // 80112AD0: stw     r0, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112AD4u;
    // 80112AD4: lwz     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80112AD8u;
    // 80112AD8: stw     r0, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112ADCu;
    // 80112ADC: lwz     r0, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80112AE0u;
    // 80112AE0: stw     r0, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80112AE4u;
    // 80112AE4: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80112AE8: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

    ctx->pc = 0x80112AECu;
    // 80112AEC: stw     r0, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80112AF0: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

    // 80112AF4: bc    4, 2, 0x80112AB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112AB8u;
                return;
            }
            goto label_80112AB8;
        }
    }

    ctx->pc = 0x80112AF8u;
}

void func_8010F4C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8010F4C0u: goto label_8010F4C0;
    case 0x8010F4C4u: goto label_8010F4C4;
    case 0x8010F4C8u: goto label_8010F4C8;
    case 0x8010F4CCu: goto label_8010F4CC;
    case 0x8010F4D0u: goto label_8010F4D0;
    case 0x8010F4D4u: goto label_8010F4D4;
    case 0x8010F4D8u: goto label_8010F4D8;
    case 0x8010F4DCu: goto label_8010F4DC;
    case 0x8010F4E0u: goto label_8010F4E0;
    case 0x8010F4E4u: goto label_8010F4E4;
    case 0x8010F4E8u: goto label_8010F4E8;
    case 0x8010F4ECu: goto label_8010F4EC;
    case 0x8010F4F0u: goto label_8010F4F0;
    case 0x8010F4F4u: goto label_8010F4F4;
    case 0x8010F4F8u: goto label_8010F4F8;
    case 0x8010F4FCu: goto label_8010F4FC;
    case 0x8010F500u: goto label_8010F500;
    case 0x8010F504u: goto label_8010F504;
    case 0x8010F508u: goto label_8010F508;
    case 0x8010F50Cu: goto label_8010F50C;
    case 0x8010F510u: goto label_8010F510;
    case 0x8010F514u: goto label_8010F514;
    case 0x8010F518u: goto label_8010F518;
    case 0x8010F51Cu: goto label_8010F51C;
    case 0x8010F520u: goto label_8010F520;
    case 0x8010F524u: goto label_8010F524;
    case 0x8010F528u: goto label_8010F528;
    case 0x8010F52Cu: goto label_8010F52C;
    case 0x8010F530u: goto label_8010F530;
    case 0x8010F534u: goto label_8010F534;
    case 0x8010F538u: goto label_8010F538;
    case 0x8010F53Cu: goto label_8010F53C;
    case 0x8010F540u: goto label_8010F540;
    case 0x8010F544u: goto label_8010F544;
    case 0x8010F548u: goto label_8010F548;
    case 0x8010F54Cu: goto label_8010F54C;
    case 0x8010F550u: goto label_8010F550;
    case 0x8010F554u: goto label_8010F554;
    case 0x8010F558u: goto label_8010F558;
    case 0x8010F55Cu: goto label_8010F55C;
    case 0x8010F560u: goto label_8010F560;
    case 0x8010F564u: goto label_8010F564;
    case 0x8010F568u: goto label_8010F568;
    case 0x8010F56Cu: goto label_8010F56C;
    case 0x8010F570u: goto label_8010F570;
    case 0x8010F574u: goto label_8010F574;
    case 0x8010F578u: goto label_8010F578;
    case 0x8010F57Cu: goto label_8010F57C;
    case 0x8010F580u: goto label_8010F580;
    case 0x8010F584u: goto label_8010F584;
    case 0x8010F588u: goto label_8010F588;
    case 0x8010F58Cu: goto label_8010F58C;
    case 0x8010F590u: goto label_8010F590;
    case 0x8010F594u: goto label_8010F594;
    case 0x8010F598u: goto label_8010F598;
    case 0x8010F59Cu: goto label_8010F59C;
    case 0x8010F5A0u: goto label_8010F5A0;
    case 0x8010F5A4u: goto label_8010F5A4;
    case 0x8010F5A8u: goto label_8010F5A8;
    case 0x8010F5ACu: goto label_8010F5AC;
    case 0x8010F5B0u: goto label_8010F5B0;
    case 0x8010F5B4u: goto label_8010F5B4;
    case 0x8010F5B8u: goto label_8010F5B8;
    case 0x8010F5BCu: goto label_8010F5BC;
    case 0x8010F5C0u: goto label_8010F5C0;
    case 0x8010F5C4u: goto label_8010F5C4;
    case 0x8010F5C8u: goto label_8010F5C8;
    case 0x8010F5CCu: goto label_8010F5CC;
    case 0x8010F5D0u: goto label_8010F5D0;
    case 0x8010F5D4u: goto label_8010F5D4;
    case 0x8010F5D8u: goto label_8010F5D8;
    case 0x8010F5DCu: goto label_8010F5DC;
    case 0x8010F5E0u: goto label_8010F5E0;
    case 0x8010F5E4u: goto label_8010F5E4;
    case 0x8010F5E8u: goto label_8010F5E8;
    case 0x8010F5ECu: goto label_8010F5EC;
    case 0x8010F5F0u: goto label_8010F5F0;
    case 0x8010F5F4u: goto label_8010F5F4;
    case 0x8010F5F8u: goto label_8010F5F8;
    case 0x8010F5FCu: goto label_8010F5FC;
    case 0x8010F600u: goto label_8010F600;
    case 0x8010F604u: goto label_8010F604;
    case 0x8010F608u: goto label_8010F608;
    case 0x8010F60Cu: goto label_8010F60C;
    case 0x8010F610u: goto label_8010F610;
    case 0x8010F614u: goto label_8010F614;
    case 0x8010F618u: goto label_8010F618;
    case 0x8010F61Cu: goto label_8010F61C;
    case 0x8010F620u: goto label_8010F620;
    case 0x8010F624u: goto label_8010F624;
    case 0x8010F628u: goto label_8010F628;
    case 0x8010F62Cu: goto label_8010F62C;
    case 0x8010F630u: goto label_8010F630;
    case 0x8010F634u: goto label_8010F634;
    case 0x8010F638u: goto label_8010F638;
    case 0x8010F63Cu: goto label_8010F63C;
    case 0x8010F640u: goto label_8010F640;
    case 0x8010F644u: goto label_8010F644;
    case 0x8010F648u: goto label_8010F648;
    case 0x8010F64Cu: goto label_8010F64C;
    case 0x8010F650u: goto label_8010F650;
    case 0x8010F654u: goto label_8010F654;
    case 0x8010F658u: goto label_8010F658;
    case 0x8010F65Cu: goto label_8010F65C;
    case 0x8010F660u: goto label_8010F660;
    case 0x8010F664u: goto label_8010F664;
    case 0x8010F668u: goto label_8010F668;
    case 0x8010F66Cu: goto label_8010F66C;
    case 0x8010F670u: goto label_8010F670;
    case 0x8010F674u: goto label_8010F674;
    case 0x8010F678u: goto label_8010F678;
    case 0x8010F67Cu: goto label_8010F67C;
    case 0x8010F680u: goto label_8010F680;
    case 0x8010F684u: goto label_8010F684;
    case 0x8010F688u: goto label_8010F688;
    case 0x8010F68Cu: goto label_8010F68C;
    case 0x8010F690u: goto label_8010F690;
    case 0x8010F694u: goto label_8010F694;
    case 0x8010F698u: goto label_8010F698;
    case 0x8010F69Cu: goto label_8010F69C;
    case 0x8010F6A0u: goto label_8010F6A0;
    case 0x8010F6A4u: goto label_8010F6A4;
    case 0x8010F6A8u: goto label_8010F6A8;
    case 0x8010F6ACu: goto label_8010F6AC;
    case 0x8010F6B0u: goto label_8010F6B0;
    case 0x8010F6B4u: goto label_8010F6B4;
    case 0x8010F6B8u: goto label_8010F6B8;
    case 0x8010F6BCu: goto label_8010F6BC;
    case 0x8010F6C0u: goto label_8010F6C0;
    case 0x8010F6C4u: goto label_8010F6C4;
    case 0x8010F6C8u: goto label_8010F6C8;
    case 0x8010F6CCu: goto label_8010F6CC;
    case 0x8010F6D0u: goto label_8010F6D0;
    case 0x8010F6D4u: goto label_8010F6D4;
    case 0x8010F6D8u: goto label_8010F6D8;
    case 0x8010F6DCu: goto label_8010F6DC;
    case 0x8010F6E0u: goto label_8010F6E0;
    case 0x8010F6E4u: goto label_8010F6E4;
    case 0x8010F6E8u: goto label_8010F6E8;
    case 0x8010F6ECu: goto label_8010F6EC;
    case 0x8010F6F0u: goto label_8010F6F0;
    case 0x8010F6F4u: goto label_8010F6F4;
    case 0x8010F6F8u: goto label_8010F6F8;
    case 0x8010F6FCu: goto label_8010F6FC;
    case 0x8010F700u: goto label_8010F700;
    case 0x8010F704u: goto label_8010F704;
    case 0x8010F708u: goto label_8010F708;
    case 0x8010F70Cu: goto label_8010F70C;
    case 0x8010F710u: goto label_8010F710;
    case 0x8010F714u: goto label_8010F714;
    case 0x8010F718u: goto label_8010F718;
    case 0x8010F71Cu: goto label_8010F71C;
    case 0x8010F720u: goto label_8010F720;
    case 0x8010F724u: goto label_8010F724;
    case 0x8010F728u: goto label_8010F728;
    case 0x8010F72Cu: goto label_8010F72C;
    case 0x8010F730u: goto label_8010F730;
    case 0x8010F734u: goto label_8010F734;
    case 0x8010F738u: goto label_8010F738;
    case 0x8010F73Cu: goto label_8010F73C;
    case 0x8010F740u: goto label_8010F740;
    case 0x8010F744u: goto label_8010F744;
    case 0x8010F748u: goto label_8010F748;
    case 0x8010F74Cu: goto label_8010F74C;
    case 0x8010F750u: goto label_8010F750;
    case 0x8010F754u: goto label_8010F754;
    case 0x8010F758u: goto label_8010F758;
    case 0x8010F75Cu: goto label_8010F75C;
    case 0x8010F760u: goto label_8010F760;
    case 0x8010F764u: goto label_8010F764;
    case 0x8010F768u: goto label_8010F768;
    case 0x8010F76Cu: goto label_8010F76C;
    case 0x8010F770u: goto label_8010F770;
    case 0x8010F774u: goto label_8010F774;
    case 0x8010F778u: goto label_8010F778;
    case 0x8010F77Cu: goto label_8010F77C;
    case 0x8010F780u: goto label_8010F780;
    case 0x8010F784u: goto label_8010F784;
    case 0x8010F788u: goto label_8010F788;
    case 0x8010F78Cu: goto label_8010F78C;
    case 0x8010F790u: goto label_8010F790;
    case 0x8010F794u: goto label_8010F794;
    case 0x8010F798u: goto label_8010F798;
    case 0x8010F79Cu: goto label_8010F79C;
    case 0x8010F7A0u: goto label_8010F7A0;
    case 0x8010F7A4u: goto label_8010F7A4;
    case 0x8010F7A8u: goto label_8010F7A8;
    case 0x8010F7ACu: goto label_8010F7AC;
    case 0x8010F7B0u: goto label_8010F7B0;
    case 0x8010F7B4u: goto label_8010F7B4;
    case 0x8010F7B8u: goto label_8010F7B8;
    case 0x8010F7BCu: goto label_8010F7BC;
    case 0x8010F7C0u: goto label_8010F7C0;
    case 0x8010F7C4u: goto label_8010F7C4;
    case 0x8010F7C8u: goto label_8010F7C8;
    case 0x8010F7CCu: goto label_8010F7CC;
    case 0x8010F7D0u: goto label_8010F7D0;
    case 0x8010F7D4u: goto label_8010F7D4;
    case 0x8010F7D8u: goto label_8010F7D8;
    case 0x8010F7DCu: goto label_8010F7DC;
    case 0x8010F7E0u: goto label_8010F7E0;
    case 0x8010F7E4u: goto label_8010F7E4;
    case 0x8010F7E8u: goto label_8010F7E8;
    case 0x8010F7ECu: goto label_8010F7EC;
    case 0x8010F7F0u: goto label_8010F7F0;
    case 0x8010F7F4u: goto label_8010F7F4;
    case 0x8010F7F8u: goto label_8010F7F8;
    case 0x8010F7FCu: goto label_8010F7FC;
    case 0x8010F800u: goto label_8010F800;
    case 0x8010F804u: goto label_8010F804;
    case 0x8010F808u: goto label_8010F808;
    case 0x8010F80Cu: goto label_8010F80C;
    case 0x8010F810u: goto label_8010F810;
    case 0x8010F814u: goto label_8010F814;
    case 0x8010F818u: goto label_8010F818;
    case 0x8010F81Cu: goto label_8010F81C;
    case 0x8010F820u: goto label_8010F820;
    case 0x8010F824u: goto label_8010F824;
    case 0x8010F828u: goto label_8010F828;
    case 0x8010F82Cu: goto label_8010F82C;
    case 0x8010F830u: goto label_8010F830;
    case 0x8010F834u: goto label_8010F834;
    case 0x8010F838u: goto label_8010F838;
    case 0x8010F83Cu: goto label_8010F83C;
    case 0x8010F840u: goto label_8010F840;
    case 0x8010F844u: goto label_8010F844;
    case 0x8010F848u: goto label_8010F848;
    case 0x8010F84Cu: goto label_8010F84C;
    case 0x8010F850u: goto label_8010F850;
    case 0x8010F854u: goto label_8010F854;
    case 0x8010F858u: goto label_8010F858;
    case 0x8010F85Cu: goto label_8010F85C;
    case 0x8010F860u: goto label_8010F860;
    case 0x8010F864u: goto label_8010F864;
    case 0x8010F868u: goto label_8010F868;
    case 0x8010F86Cu: goto label_8010F86C;
    case 0x8010F870u: goto label_8010F870;
    case 0x8010F874u: goto label_8010F874;
    case 0x8010F878u: goto label_8010F878;
    case 0x8010F87Cu: goto label_8010F87C;
    case 0x8010F880u: goto label_8010F880;
    case 0x8010F884u: goto label_8010F884;
    case 0x8010F888u: goto label_8010F888;
    case 0x8010F88Cu: goto label_8010F88C;
    case 0x8010F890u: goto label_8010F890;
    case 0x8010F894u: goto label_8010F894;
    case 0x8010F898u: goto label_8010F898;
    case 0x8010F89Cu: goto label_8010F89C;
    case 0x8010F8A0u: goto label_8010F8A0;
    case 0x8010F8A4u: goto label_8010F8A4;
    case 0x8010F8A8u: goto label_8010F8A8;
    case 0x8010F8ACu: goto label_8010F8AC;
    case 0x8010F8B0u: goto label_8010F8B0;
    case 0x8010F8B4u: goto label_8010F8B4;
    case 0x8010F8B8u: goto label_8010F8B8;
    case 0x8010F8BCu: goto label_8010F8BC;
    case 0x8010F8C0u: goto label_8010F8C0;
    case 0x8010F8C4u: goto label_8010F8C4;
    case 0x8010F8C8u: goto label_8010F8C8;
    case 0x8010F8CCu: goto label_8010F8CC;
    case 0x8010F8D0u: goto label_8010F8D0;
    case 0x8010F8D4u: goto label_8010F8D4;
    case 0x8010F8D8u: goto label_8010F8D8;
    case 0x8010F8DCu: goto label_8010F8DC;
    case 0x8010F8E0u: goto label_8010F8E0;
    case 0x8010F8E4u: goto label_8010F8E4;
    case 0x8010F8E8u: goto label_8010F8E8;
    case 0x8010F8ECu: goto label_8010F8EC;
    case 0x8010F8F0u: goto label_8010F8F0;
    case 0x8010F8F4u: goto label_8010F8F4;
    case 0x8010F8F8u: goto label_8010F8F8;
    case 0x8010F8FCu: goto label_8010F8FC;
    case 0x8010F900u: goto label_8010F900;
    case 0x8010F904u: goto label_8010F904;
    case 0x8010F908u: goto label_8010F908;
    case 0x8010F90Cu: goto label_8010F90C;
    case 0x8010F910u: goto label_8010F910;
    case 0x8010F914u: goto label_8010F914;
    case 0x8010F918u: goto label_8010F918;
    case 0x8010F91Cu: goto label_8010F91C;
    case 0x8010F920u: goto label_8010F920;
    case 0x8010F924u: goto label_8010F924;
    case 0x8010F928u: goto label_8010F928;
    case 0x8010F92Cu: goto label_8010F92C;
    case 0x8010F930u: goto label_8010F930;
    case 0x8010F934u: goto label_8010F934;
    case 0x8010F938u: goto label_8010F938;
    case 0x8010F93Cu: goto label_8010F93C;
    case 0x8010F940u: goto label_8010F940;
    case 0x8010F944u: goto label_8010F944;
    case 0x8010F948u: goto label_8010F948;
    case 0x8010F94Cu: goto label_8010F94C;
    case 0x8010F950u: goto label_8010F950;
    case 0x8010F954u: goto label_8010F954;
    case 0x8010F958u: goto label_8010F958;
    case 0x8010F95Cu: goto label_8010F95C;
    case 0x8010F960u: goto label_8010F960;
    case 0x8010F964u: goto label_8010F964;
    case 0x8010F968u: goto label_8010F968;
    case 0x8010F96Cu: goto label_8010F96C;
    case 0x8010F970u: goto label_8010F970;
    case 0x8010F974u: goto label_8010F974;
    case 0x8010F978u: goto label_8010F978;
    case 0x8010F97Cu: goto label_8010F97C;
    case 0x8010F980u: goto label_8010F980;
    case 0x8010F984u: goto label_8010F984;
    case 0x8010F988u: goto label_8010F988;
    case 0x8010F98Cu: goto label_8010F98C;
    case 0x8010F990u: goto label_8010F990;
    case 0x8010F994u: goto label_8010F994;
    case 0x8010F998u: goto label_8010F998;
    case 0x8010F99Cu: goto label_8010F99C;
    case 0x8010F9A0u: goto label_8010F9A0;
    case 0x8010F9A4u: goto label_8010F9A4;
    case 0x8010F9A8u: goto label_8010F9A8;
    case 0x8010F9ACu: goto label_8010F9AC;
    case 0x8010F9B0u: goto label_8010F9B0;
    case 0x8010F9B4u: goto label_8010F9B4;
    case 0x8010F9B8u: goto label_8010F9B8;
    case 0x8010F9BCu: goto label_8010F9BC;
    case 0x8010F9C0u: goto label_8010F9C0;
    case 0x8010F9C4u: goto label_8010F9C4;
    case 0x8010F9C8u: goto label_8010F9C8;
    case 0x8010F9CCu: goto label_8010F9CC;
    case 0x8010F9D0u: goto label_8010F9D0;
    case 0x8010F9D4u: goto label_8010F9D4;
    case 0x8010F9D8u: goto label_8010F9D8;
    case 0x8010F9DCu: goto label_8010F9DC;
    case 0x8010F9E0u: goto label_8010F9E0;
    case 0x8010F9E4u: goto label_8010F9E4;
    case 0x8010F9E8u: goto label_8010F9E8;
    case 0x8010F9ECu: goto label_8010F9EC;
    case 0x8010F9F0u: goto label_8010F9F0;
    case 0x8010F9F4u: goto label_8010F9F4;
    case 0x8010F9F8u: goto label_8010F9F8;
    case 0x8010F9FCu: goto label_8010F9FC;
    case 0x8010FA00u: goto label_8010FA00;
    case 0x8010FA04u: goto label_8010FA04;
    case 0x8010FA08u: goto label_8010FA08;
    case 0x8010FA0Cu: goto label_8010FA0C;
    case 0x8010FA10u: goto label_8010FA10;
    case 0x8010FA14u: goto label_8010FA14;
    case 0x8010FA18u: goto label_8010FA18;
    case 0x8010FA1Cu: goto label_8010FA1C;
    case 0x8010FA20u: goto label_8010FA20;
    case 0x8010FA24u: goto label_8010FA24;
    case 0x8010FA28u: goto label_8010FA28;
    case 0x8010FA2Cu: goto label_8010FA2C;
    case 0x8010FA30u: goto label_8010FA30;
    case 0x8010FA34u: goto label_8010FA34;
    case 0x8010FA38u: goto label_8010FA38;
    case 0x8010FA3Cu: goto label_8010FA3C;
    case 0x8010FA40u: goto label_8010FA40;
    case 0x8010FA44u: goto label_8010FA44;
    case 0x8010FA48u: goto label_8010FA48;
    case 0x8010FA4Cu: goto label_8010FA4C;
    case 0x8010FA50u: goto label_8010FA50;
    case 0x8010FA54u: goto label_8010FA54;
    case 0x8010FA58u: goto label_8010FA58;
    case 0x8010FA5Cu: goto label_8010FA5C;
    case 0x8010FA60u: goto label_8010FA60;
    case 0x8010FA64u: goto label_8010FA64;
    case 0x8010FA68u: goto label_8010FA68;
    case 0x8010FA6Cu: goto label_8010FA6C;
    case 0x8010FA70u: goto label_8010FA70;
    case 0x8010FA74u: goto label_8010FA74;
    case 0x8010FA78u: goto label_8010FA78;
    case 0x8010FA7Cu: goto label_8010FA7C;
    case 0x8010FA80u: goto label_8010FA80;
    case 0x8010FA84u: goto label_8010FA84;
    case 0x8010FA88u: goto label_8010FA88;
    case 0x8010FA8Cu: goto label_8010FA8C;
    case 0x8010FA90u: goto label_8010FA90;
    case 0x8010FA94u: goto label_8010FA94;
    case 0x8010FA98u: goto label_8010FA98;
    case 0x8010FA9Cu: goto label_8010FA9C;
    case 0x8010FAA0u: goto label_8010FAA0;
    case 0x8010FAA4u: goto label_8010FAA4;
    case 0x8010FAA8u: goto label_8010FAA8;
    case 0x8010FAACu: goto label_8010FAAC;
    case 0x8010FAB0u: goto label_8010FAB0;
    case 0x8010FAB4u: goto label_8010FAB4;
    case 0x8010FAB8u: goto label_8010FAB8;
    case 0x8010FABCu: goto label_8010FABC;
    case 0x8010FAC0u: goto label_8010FAC0;
    case 0x8010FAC4u: goto label_8010FAC4;
    case 0x8010FAC8u: goto label_8010FAC8;
    case 0x8010FACCu: goto label_8010FACC;
    case 0x8010FAD0u: goto label_8010FAD0;
    case 0x8010FAD4u: goto label_8010FAD4;
    case 0x8010FAD8u: goto label_8010FAD8;
    case 0x8010FADCu: goto label_8010FADC;
    case 0x8010FAE0u: goto label_8010FAE0;
    case 0x8010FAE4u: goto label_8010FAE4;
    case 0x8010FAE8u: goto label_8010FAE8;
    case 0x8010FAECu: goto label_8010FAEC;
    case 0x8010FAF0u: goto label_8010FAF0;
    case 0x8010FAF4u: goto label_8010FAF4;
    case 0x8010FAF8u: goto label_8010FAF8;
    case 0x8010FAFCu: goto label_8010FAFC;
    case 0x8010FB00u: goto label_8010FB00;
    case 0x8010FB04u: goto label_8010FB04;
    case 0x8010FB08u: goto label_8010FB08;
    case 0x8010FB0Cu: goto label_8010FB0C;
    case 0x8010FB10u: goto label_8010FB10;
    case 0x8010FB14u: goto label_8010FB14;
    case 0x8010FB18u: goto label_8010FB18;
    case 0x8010FB1Cu: goto label_8010FB1C;
    case 0x8010FB20u: goto label_8010FB20;
    case 0x8010FB24u: goto label_8010FB24;
    case 0x8010FB28u: goto label_8010FB28;
    case 0x8010FB2Cu: goto label_8010FB2C;
    case 0x8010FB30u: goto label_8010FB30;
    case 0x8010FB34u: goto label_8010FB34;
    case 0x8010FB38u: goto label_8010FB38;
    case 0x8010FB3Cu: goto label_8010FB3C;
    case 0x8010FB40u: goto label_8010FB40;
    case 0x8010FB44u: goto label_8010FB44;
    case 0x8010FB48u: goto label_8010FB48;
    case 0x8010FB4Cu: goto label_8010FB4C;
    case 0x8010FB50u: goto label_8010FB50;
    case 0x8010FB54u: goto label_8010FB54;
    case 0x8010FB58u: goto label_8010FB58;
    case 0x8010FB5Cu: goto label_8010FB5C;
    case 0x8010FB60u: goto label_8010FB60;
    case 0x8010FB64u: goto label_8010FB64;
    case 0x8010FB68u: goto label_8010FB68;
    case 0x8010FB6Cu: goto label_8010FB6C;
    case 0x8010FB70u: goto label_8010FB70;
    case 0x8010FB74u: goto label_8010FB74;
    case 0x8010FB78u: goto label_8010FB78;
    case 0x8010FB7Cu: goto label_8010FB7C;
    case 0x8010FB80u: goto label_8010FB80;
    case 0x8010FB84u: goto label_8010FB84;
    case 0x8010FB88u: goto label_8010FB88;
    case 0x8010FB8Cu: goto label_8010FB8C;
    case 0x8010FB90u: goto label_8010FB90;
    case 0x8010FB94u: goto label_8010FB94;
    case 0x8010FB98u: goto label_8010FB98;
    case 0x8010FB9Cu: goto label_8010FB9C;
    case 0x8010FBA0u: goto label_8010FBA0;
    case 0x8010FBA4u: goto label_8010FBA4;
    case 0x8010FBA8u: goto label_8010FBA8;
    case 0x8010FBACu: goto label_8010FBAC;
    case 0x8010FBB0u: goto label_8010FBB0;
    case 0x8010FBB4u: goto label_8010FBB4;
    case 0x8010FBB8u: goto label_8010FBB8;
    case 0x8010FBBCu: goto label_8010FBBC;
    case 0x8010FBC0u: goto label_8010FBC0;
    case 0x8010FBC4u: goto label_8010FBC4;
    case 0x8010FBC8u: goto label_8010FBC8;
    case 0x8010FBCCu: goto label_8010FBCC;
    case 0x8010FBD0u: goto label_8010FBD0;
    case 0x8010FBD4u: goto label_8010FBD4;
    case 0x8010FBD8u: goto label_8010FBD8;
    case 0x8010FBDCu: goto label_8010FBDC;
    case 0x8010FBE0u: goto label_8010FBE0;
    case 0x8010FBE4u: goto label_8010FBE4;
    case 0x8010FBE8u: goto label_8010FBE8;
    case 0x8010FBECu: goto label_8010FBEC;
    case 0x8010FBF0u: goto label_8010FBF0;
    case 0x8010FBF4u: goto label_8010FBF4;
    case 0x8010FBF8u: goto label_8010FBF8;
    case 0x8010FBFCu: goto label_8010FBFC;
    case 0x8010FC00u: goto label_8010FC00;
    case 0x8010FC04u: goto label_8010FC04;
    case 0x8010FC08u: goto label_8010FC08;
    case 0x8010FC0Cu: goto label_8010FC0C;
    case 0x8010FC10u: goto label_8010FC10;
    case 0x8010FC14u: goto label_8010FC14;
    case 0x8010FC18u: goto label_8010FC18;
    case 0x8010FC1Cu: goto label_8010FC1C;
    case 0x8010FC20u: goto label_8010FC20;
    case 0x8010FC24u: goto label_8010FC24;
    case 0x8010FC28u: goto label_8010FC28;
    case 0x8010FC2Cu: goto label_8010FC2C;
    case 0x8010FC30u: goto label_8010FC30;
    case 0x8010FC34u: goto label_8010FC34;
    case 0x8010FC38u: goto label_8010FC38;
    case 0x8010FC3Cu: goto label_8010FC3C;
    case 0x8010FC40u: goto label_8010FC40;
    case 0x8010FC44u: goto label_8010FC44;
    case 0x8010FC48u: goto label_8010FC48;
    case 0x8010FC4Cu: goto label_8010FC4C;
    case 0x8010FC50u: goto label_8010FC50;
    case 0x8010FC54u: goto label_8010FC54;
    case 0x8010FC58u: goto label_8010FC58;
    case 0x8010FC5Cu: goto label_8010FC5C;
    case 0x8010FC60u: goto label_8010FC60;
    case 0x8010FC64u: goto label_8010FC64;
    case 0x8010FC68u: goto label_8010FC68;
    case 0x8010FC6Cu: goto label_8010FC6C;
    case 0x8010FC70u: goto label_8010FC70;
    case 0x8010FC74u: goto label_8010FC74;
    case 0x8010FC78u: goto label_8010FC78;
    case 0x8010FC7Cu: goto label_8010FC7C;
    case 0x8010FC80u: goto label_8010FC80;
    case 0x8010FC84u: goto label_8010FC84;
    case 0x8010FC88u: goto label_8010FC88;
    case 0x8010FC8Cu: goto label_8010FC8C;
    case 0x8010FC90u: goto label_8010FC90;
    case 0x8010FC94u: goto label_8010FC94;
    case 0x8010FC98u: goto label_8010FC98;
    case 0x8010FC9Cu: goto label_8010FC9C;
    case 0x8010FCA0u: goto label_8010FCA0;
    case 0x8010FCA4u: goto label_8010FCA4;
    case 0x8010FCA8u: goto label_8010FCA8;
    case 0x8010FCACu: goto label_8010FCAC;
    case 0x8010FCB0u: goto label_8010FCB0;
    case 0x8010FCB4u: goto label_8010FCB4;
    case 0x8010FCB8u: goto label_8010FCB8;
    case 0x8010FCBCu: goto label_8010FCBC;
    case 0x8010FCC0u: goto label_8010FCC0;
    case 0x8010FCC4u: goto label_8010FCC4;
    case 0x8010FCC8u: goto label_8010FCC8;
    case 0x8010FCCCu: goto label_8010FCCC;
    case 0x8010FCD0u: goto label_8010FCD0;
    case 0x8010FCD4u: goto label_8010FCD4;
    case 0x8010FCD8u: goto label_8010FCD8;
    case 0x8010FCDCu: goto label_8010FCDC;
    case 0x8010FCE0u: goto label_8010FCE0;
    case 0x8010FCE4u: goto label_8010FCE4;
    case 0x8010FCE8u: goto label_8010FCE8;
    case 0x8010FCECu: goto label_8010FCEC;
    case 0x8010FCF0u: goto label_8010FCF0;
    case 0x8010FCF4u: goto label_8010FCF4;
    case 0x8010FCF8u: goto label_8010FCF8;
    case 0x8010FCFCu: goto label_8010FCFC;
    case 0x8010FD00u: goto label_8010FD00;
    case 0x8010FD04u: goto label_8010FD04;
    case 0x8010FD08u: goto label_8010FD08;
    case 0x8010FD0Cu: goto label_8010FD0C;
    case 0x8010FD10u: goto label_8010FD10;
    case 0x8010FD14u: goto label_8010FD14;
    case 0x8010FD18u: goto label_8010FD18;
    case 0x8010FD1Cu: goto label_8010FD1C;
    case 0x8010FD20u: goto label_8010FD20;
    case 0x8010FD24u: goto label_8010FD24;
    case 0x8010FD28u: goto label_8010FD28;
    case 0x8010FD2Cu: goto label_8010FD2C;
    case 0x8010FD30u: goto label_8010FD30;
    case 0x8010FD34u: goto label_8010FD34;
    case 0x8010FD38u: goto label_8010FD38;
    case 0x8010FD3Cu: goto label_8010FD3C;
    case 0x8010FD40u: goto label_8010FD40;
    case 0x8010FD44u: goto label_8010FD44;
    case 0x8010FD48u: goto label_8010FD48;
    case 0x8010FD4Cu: goto label_8010FD4C;
    case 0x8010FD50u: goto label_8010FD50;
    case 0x8010FD54u: goto label_8010FD54;
    case 0x8010FD58u: goto label_8010FD58;
    case 0x8010FD5Cu: goto label_8010FD5C;
    case 0x8010FD60u: goto label_8010FD60;
    case 0x8010FD64u: goto label_8010FD64;
    case 0x8010FD68u: goto label_8010FD68;
    case 0x8010FD6Cu: goto label_8010FD6C;
    case 0x8010FD70u: goto label_8010FD70;
    case 0x8010FD74u: goto label_8010FD74;
    case 0x8010FD78u: goto label_8010FD78;
    case 0x8010FD7Cu: goto label_8010FD7C;
    case 0x8010FD80u: goto label_8010FD80;
    case 0x8010FD84u: goto label_8010FD84;
    case 0x8010FD88u: goto label_8010FD88;
    case 0x8010FD8Cu: goto label_8010FD8C;
    case 0x8010FD90u: goto label_8010FD90;
    case 0x8010FD94u: goto label_8010FD94;
    case 0x8010FD98u: goto label_8010FD98;
    case 0x8010FD9Cu: goto label_8010FD9C;
    case 0x8010FDA0u: goto label_8010FDA0;
    case 0x8010FDA4u: goto label_8010FDA4;
    case 0x8010FDA8u: goto label_8010FDA8;
    case 0x8010FDACu: goto label_8010FDAC;
    case 0x8010FDB0u: goto label_8010FDB0;
    case 0x8010FDB4u: goto label_8010FDB4;
    case 0x8010FDB8u: goto label_8010FDB8;
    case 0x8010FDBCu: goto label_8010FDBC;
    case 0x8010FDC0u: goto label_8010FDC0;
    case 0x8010FDC4u: goto label_8010FDC4;
    case 0x8010FDC8u: goto label_8010FDC8;
    case 0x8010FDCCu: goto label_8010FDCC;
    case 0x8010FDD0u: goto label_8010FDD0;
    case 0x8010FDD4u: goto label_8010FDD4;
    case 0x8010FDD8u: goto label_8010FDD8;
    case 0x8010FDDCu: goto label_8010FDDC;
    case 0x8010FDE0u: goto label_8010FDE0;
    case 0x8010FDE4u: goto label_8010FDE4;
    case 0x8010FDE8u: goto label_8010FDE8;
    case 0x8010FDECu: goto label_8010FDEC;
    case 0x8010FDF0u: goto label_8010FDF0;
    case 0x8010FDF4u: goto label_8010FDF4;
    case 0x8010FDF8u: goto label_8010FDF8;
    case 0x8010FDFCu: goto label_8010FDFC;
    case 0x8010FE00u: goto label_8010FE00;
    case 0x8010FE04u: goto label_8010FE04;
    case 0x8010FE08u: goto label_8010FE08;
    case 0x8010FE0Cu: goto label_8010FE0C;
    case 0x8010FE10u: goto label_8010FE10;
    case 0x8010FE14u: goto label_8010FE14;
    case 0x8010FE18u: goto label_8010FE18;
    case 0x8010FE1Cu: goto label_8010FE1C;
    case 0x8010FE20u: goto label_8010FE20;
    case 0x8010FE24u: goto label_8010FE24;
    case 0x8010FE28u: goto label_8010FE28;
    case 0x8010FE2Cu: goto label_8010FE2C;
    case 0x8010FE30u: goto label_8010FE30;
    case 0x8010FE34u: goto label_8010FE34;
    case 0x8010FE38u: goto label_8010FE38;
    case 0x8010FE3Cu: goto label_8010FE3C;
    case 0x8010FE40u: goto label_8010FE40;
    case 0x8010FE44u: goto label_8010FE44;
    case 0x8010FE48u: goto label_8010FE48;
    case 0x8010FE4Cu: goto label_8010FE4C;
    case 0x8010FE50u: goto label_8010FE50;
    case 0x8010FE54u: goto label_8010FE54;
    case 0x8010FE58u: goto label_8010FE58;
    case 0x8010FE5Cu: goto label_8010FE5C;
    case 0x8010FE60u: goto label_8010FE60;
    case 0x8010FE64u: goto label_8010FE64;
    case 0x8010FE68u: goto label_8010FE68;
    case 0x8010FE6Cu: goto label_8010FE6C;
    case 0x8010FE70u: goto label_8010FE70;
    case 0x8010FE74u: goto label_8010FE74;
    case 0x8010FE78u: goto label_8010FE78;
    case 0x8010FE7Cu: goto label_8010FE7C;
    case 0x8010FE80u: goto label_8010FE80;
    case 0x8010FE84u: goto label_8010FE84;
    case 0x8010FE88u: goto label_8010FE88;
    case 0x8010FE8Cu: goto label_8010FE8C;
    case 0x8010FE90u: goto label_8010FE90;
    case 0x8010FE94u: goto label_8010FE94;
    case 0x8010FE98u: goto label_8010FE98;
    case 0x8010FE9Cu: goto label_8010FE9C;
    case 0x8010FEA0u: goto label_8010FEA0;
    case 0x8010FEA4u: goto label_8010FEA4;
    case 0x8010FEA8u: goto label_8010FEA8;
    case 0x8010FEACu: goto label_8010FEAC;
    case 0x8010FEB0u: goto label_8010FEB0;
    case 0x8010FEB4u: goto label_8010FEB4;
    case 0x8010FEB8u: goto label_8010FEB8;
    case 0x8010FEBCu: goto label_8010FEBC;
    case 0x8010FEC0u: goto label_8010FEC0;
    case 0x8010FEC4u: goto label_8010FEC4;
    case 0x8010FEC8u: goto label_8010FEC8;
    case 0x8010FECCu: goto label_8010FECC;
    case 0x8010FED0u: goto label_8010FED0;
    case 0x8010FED4u: goto label_8010FED4;
    case 0x8010FED8u: goto label_8010FED8;
    case 0x8010FEDCu: goto label_8010FEDC;
    case 0x8010FEE0u: goto label_8010FEE0;
    case 0x8010FEE4u: goto label_8010FEE4;
    case 0x8010FEE8u: goto label_8010FEE8;
    case 0x8010FEECu: goto label_8010FEEC;
    case 0x8010FEF0u: goto label_8010FEF0;
    case 0x8010FEF4u: goto label_8010FEF4;
    case 0x8010FEF8u: goto label_8010FEF8;
    case 0x8010FEFCu: goto label_8010FEFC;
    case 0x8010FF00u: goto label_8010FF00;
    case 0x8010FF04u: goto label_8010FF04;
    case 0x8010FF08u: goto label_8010FF08;
    case 0x8010FF0Cu: goto label_8010FF0C;
    case 0x8010FF10u: goto label_8010FF10;
    case 0x8010FF14u: goto label_8010FF14;
    case 0x8010FF18u: goto label_8010FF18;
    case 0x8010FF1Cu: goto label_8010FF1C;
    case 0x8010FF20u: goto label_8010FF20;
    case 0x8010FF24u: goto label_8010FF24;
    case 0x8010FF28u: goto label_8010FF28;
    case 0x8010FF2Cu: goto label_8010FF2C;
    case 0x8010FF30u: goto label_8010FF30;
    case 0x8010FF34u: goto label_8010FF34;
    case 0x8010FF38u: goto label_8010FF38;
    case 0x8010FF3Cu: goto label_8010FF3C;
    case 0x8010FF40u: goto label_8010FF40;
    case 0x8010FF44u: goto label_8010FF44;
    case 0x8010FF48u: goto label_8010FF48;
    case 0x8010FF4Cu: goto label_8010FF4C;
    case 0x8010FF50u: goto label_8010FF50;
    case 0x8010FF54u: goto label_8010FF54;
    case 0x8010FF58u: goto label_8010FF58;
    case 0x8010FF5Cu: goto label_8010FF5C;
    case 0x8010FF60u: goto label_8010FF60;
    case 0x8010FF64u: goto label_8010FF64;
    case 0x8010FF68u: goto label_8010FF68;
    case 0x8010FF6Cu: goto label_8010FF6C;
    case 0x8010FF70u: goto label_8010FF70;
    case 0x8010FF74u: goto label_8010FF74;
    case 0x8010FF78u: goto label_8010FF78;
    case 0x8010FF7Cu: goto label_8010FF7C;
    case 0x8010FF80u: goto label_8010FF80;
    case 0x8010FF84u: goto label_8010FF84;
    case 0x8010FF88u: goto label_8010FF88;
    case 0x8010FF8Cu: goto label_8010FF8C;
    case 0x8010FF90u: goto label_8010FF90;
    case 0x8010FF94u: goto label_8010FF94;
    case 0x8010FF98u: goto label_8010FF98;
    case 0x8010FF9Cu: goto label_8010FF9C;
    case 0x8010FFA0u: goto label_8010FFA0;
    case 0x8010FFA4u: goto label_8010FFA4;
    case 0x8010FFA8u: goto label_8010FFA8;
    case 0x8010FFACu: goto label_8010FFAC;
    case 0x8010FFB0u: goto label_8010FFB0;
    case 0x8010FFB4u: goto label_8010FFB4;
    case 0x8010FFB8u: goto label_8010FFB8;
    case 0x8010FFBCu: goto label_8010FFBC;
    case 0x8010FFC0u: goto label_8010FFC0;
    case 0x8010FFC4u: goto label_8010FFC4;
    case 0x8010FFC8u: goto label_8010FFC8;
    case 0x8010FFCCu: goto label_8010FFCC;
    case 0x8010FFD0u: goto label_8010FFD0;
    case 0x8010FFD4u: goto label_8010FFD4;
    case 0x8010FFD8u: goto label_8010FFD8;
    case 0x8010FFDCu: goto label_8010FFDC;
    case 0x8010FFE0u: goto label_8010FFE0;
    case 0x8010FFE4u: goto label_8010FFE4;
    case 0x8010FFE8u: goto label_8010FFE8;
    case 0x8010FFECu: goto label_8010FFEC;
    case 0x8010FFF0u: goto label_8010FFF0;
    case 0x8010FFF4u: goto label_8010FFF4;
    case 0x8010FFF8u: goto label_8010FFF8;
    case 0x8010FFFCu: goto label_8010FFFC;
    case 0x80110000u: goto label_80110000;
    case 0x80110004u: goto label_80110004;
    case 0x80110008u: goto label_80110008;
    case 0x8011000Cu: goto label_8011000C;
    case 0x80110010u: goto label_80110010;
    case 0x80110014u: goto label_80110014;
    case 0x80110018u: goto label_80110018;
    case 0x8011001Cu: goto label_8011001C;
    case 0x80110020u: goto label_80110020;
    case 0x80110024u: goto label_80110024;
    case 0x80110028u: goto label_80110028;
    case 0x8011002Cu: goto label_8011002C;
    case 0x80110030u: goto label_80110030;
    case 0x80110034u: goto label_80110034;
    case 0x80110038u: goto label_80110038;
    case 0x8011003Cu: goto label_8011003C;
    case 0x80110040u: goto label_80110040;
    case 0x80110044u: goto label_80110044;
    case 0x80110048u: goto label_80110048;
    case 0x8011004Cu: goto label_8011004C;
    case 0x80110050u: goto label_80110050;
    case 0x80110054u: goto label_80110054;
    case 0x80110058u: goto label_80110058;
    case 0x8011005Cu: goto label_8011005C;
    case 0x80110060u: goto label_80110060;
    case 0x80110064u: goto label_80110064;
    case 0x80110068u: goto label_80110068;
    case 0x8011006Cu: goto label_8011006C;
    case 0x80110070u: goto label_80110070;
    case 0x80110074u: goto label_80110074;
    case 0x80110078u: goto label_80110078;
    case 0x8011007Cu: goto label_8011007C;
    case 0x80110080u: goto label_80110080;
    case 0x80110084u: goto label_80110084;
    case 0x80110088u: goto label_80110088;
    case 0x8011008Cu: goto label_8011008C;
    case 0x80110090u: goto label_80110090;
    case 0x80110094u: goto label_80110094;
    case 0x80110098u: goto label_80110098;
    case 0x8011009Cu: goto label_8011009C;
    case 0x801100A0u: goto label_801100A0;
    case 0x801100A4u: goto label_801100A4;
    case 0x801100A8u: goto label_801100A8;
    case 0x801100ACu: goto label_801100AC;
    case 0x801100B0u: goto label_801100B0;
    case 0x801100B4u: goto label_801100B4;
    case 0x801100B8u: goto label_801100B8;
    case 0x801100BCu: goto label_801100BC;
    case 0x801100C0u: goto label_801100C0;
    case 0x801100C4u: goto label_801100C4;
    case 0x801100C8u: goto label_801100C8;
    case 0x801100CCu: goto label_801100CC;
    case 0x801100D0u: goto label_801100D0;
    case 0x801100D4u: goto label_801100D4;
    case 0x801100D8u: goto label_801100D8;
    case 0x801100DCu: goto label_801100DC;
    case 0x801100E0u: goto label_801100E0;
    case 0x801100E4u: goto label_801100E4;
    case 0x801100E8u: goto label_801100E8;
    case 0x801100ECu: goto label_801100EC;
    case 0x801100F0u: goto label_801100F0;
    case 0x801100F4u: goto label_801100F4;
    case 0x801100F8u: goto label_801100F8;
    case 0x801100FCu: goto label_801100FC;
    case 0x80110100u: goto label_80110100;
    case 0x80110104u: goto label_80110104;
    case 0x80110108u: goto label_80110108;
    case 0x8011010Cu: goto label_8011010C;
    case 0x80110110u: goto label_80110110;
    case 0x80110114u: goto label_80110114;
    case 0x80110118u: goto label_80110118;
    case 0x8011011Cu: goto label_8011011C;
    case 0x80110120u: goto label_80110120;
    case 0x80110124u: goto label_80110124;
    case 0x80110128u: goto label_80110128;
    case 0x8011012Cu: goto label_8011012C;
    case 0x80110130u: goto label_80110130;
    case 0x80110134u: goto label_80110134;
    case 0x80110138u: goto label_80110138;
    case 0x8011013Cu: goto label_8011013C;
    case 0x80110140u: goto label_80110140;
    case 0x80110144u: goto label_80110144;
    case 0x80110148u: goto label_80110148;
    case 0x8011014Cu: goto label_8011014C;
    case 0x80110150u: goto label_80110150;
    case 0x80110154u: goto label_80110154;
    case 0x80110158u: goto label_80110158;
    case 0x8011015Cu: goto label_8011015C;
    case 0x80110160u: goto label_80110160;
    case 0x80110164u: goto label_80110164;
    case 0x80110168u: goto label_80110168;
    case 0x8011016Cu: goto label_8011016C;
    case 0x80110170u: goto label_80110170;
    case 0x80110174u: goto label_80110174;
    case 0x80110178u: goto label_80110178;
    case 0x8011017Cu: goto label_8011017C;
    case 0x80110180u: goto label_80110180;
    case 0x80110184u: goto label_80110184;
    case 0x80110188u: goto label_80110188;
    case 0x8011018Cu: goto label_8011018C;
    case 0x80110190u: goto label_80110190;
    case 0x80110194u: goto label_80110194;
    case 0x80110198u: goto label_80110198;
    case 0x8011019Cu: goto label_8011019C;
    case 0x801101A0u: goto label_801101A0;
    case 0x801101A4u: goto label_801101A4;
    case 0x801101A8u: goto label_801101A8;
    case 0x801101ACu: goto label_801101AC;
    case 0x801101B0u: goto label_801101B0;
    case 0x801101B4u: goto label_801101B4;
    case 0x801101B8u: goto label_801101B8;
    case 0x801101BCu: goto label_801101BC;
    case 0x801101C0u: goto label_801101C0;
    case 0x801101C4u: goto label_801101C4;
    case 0x801101C8u: goto label_801101C8;
    case 0x801101CCu: goto label_801101CC;
    case 0x801101D0u: goto label_801101D0;
    case 0x801101D4u: goto label_801101D4;
    case 0x801101D8u: goto label_801101D8;
    case 0x801101DCu: goto label_801101DC;
    case 0x801101E0u: goto label_801101E0;
    case 0x801101E4u: goto label_801101E4;
    case 0x801101E8u: goto label_801101E8;
    case 0x801101ECu: goto label_801101EC;
    case 0x801101F0u: goto label_801101F0;
    case 0x801101F4u: goto label_801101F4;
    case 0x801101F8u: goto label_801101F8;
    case 0x801101FCu: goto label_801101FC;
    case 0x80110200u: goto label_80110200;
    case 0x80110204u: goto label_80110204;
    case 0x80110208u: goto label_80110208;
    case 0x8011020Cu: goto label_8011020C;
    case 0x80110210u: goto label_80110210;
    case 0x80110214u: goto label_80110214;
    case 0x80110218u: goto label_80110218;
    case 0x8011021Cu: goto label_8011021C;
    case 0x80110220u: goto label_80110220;
    case 0x80110224u: goto label_80110224;
    case 0x80110228u: goto label_80110228;
    case 0x8011022Cu: goto label_8011022C;
    case 0x80110230u: goto label_80110230;
    case 0x80110234u: goto label_80110234;
    case 0x80110238u: goto label_80110238;
    case 0x8011023Cu: goto label_8011023C;
    case 0x80110240u: goto label_80110240;
    case 0x80110244u: goto label_80110244;
    case 0x80110248u: goto label_80110248;
    case 0x8011024Cu: goto label_8011024C;
    case 0x80110250u: goto label_80110250;
    case 0x80110254u: goto label_80110254;
    case 0x80110258u: goto label_80110258;
    case 0x8011025Cu: goto label_8011025C;
    case 0x80110260u: goto label_80110260;
    case 0x80110264u: goto label_80110264;
    case 0x80110268u: goto label_80110268;
    case 0x8011026Cu: goto label_8011026C;
    case 0x80110270u: goto label_80110270;
    case 0x80110274u: goto label_80110274;
    case 0x80110278u: goto label_80110278;
    case 0x8011027Cu: goto label_8011027C;
    case 0x80110280u: goto label_80110280;
    case 0x80110284u: goto label_80110284;
    case 0x80110288u: goto label_80110288;
    case 0x8011028Cu: goto label_8011028C;
    case 0x80110290u: goto label_80110290;
    case 0x80110294u: goto label_80110294;
    case 0x80110298u: goto label_80110298;
    case 0x8011029Cu: goto label_8011029C;
    case 0x801102A0u: goto label_801102A0;
    case 0x801102A4u: goto label_801102A4;
    case 0x801102A8u: goto label_801102A8;
    case 0x801102ACu: goto label_801102AC;
    case 0x801102B0u: goto label_801102B0;
    case 0x801102B4u: goto label_801102B4;
    case 0x801102B8u: goto label_801102B8;
    case 0x801102BCu: goto label_801102BC;
    case 0x801102C0u: goto label_801102C0;
    case 0x801102C4u: goto label_801102C4;
    case 0x801102C8u: goto label_801102C8;
    case 0x801102CCu: goto label_801102CC;
    case 0x801102D0u: goto label_801102D0;
    case 0x801102D4u: goto label_801102D4;
    case 0x801102D8u: goto label_801102D8;
    case 0x801102DCu: goto label_801102DC;
    case 0x801102E0u: goto label_801102E0;
    case 0x801102E4u: goto label_801102E4;
    case 0x801102E8u: goto label_801102E8;
    case 0x801102ECu: goto label_801102EC;
    case 0x801102F0u: goto label_801102F0;
    case 0x801102F4u: goto label_801102F4;
    case 0x801102F8u: goto label_801102F8;
    case 0x801102FCu: goto label_801102FC;
    case 0x80110300u: goto label_80110300;
    case 0x80110304u: goto label_80110304;
    case 0x80110308u: goto label_80110308;
    case 0x8011030Cu: goto label_8011030C;
    case 0x80110310u: goto label_80110310;
    case 0x80110314u: goto label_80110314;
    case 0x80110318u: goto label_80110318;
    case 0x8011031Cu: goto label_8011031C;
    case 0x80110320u: goto label_80110320;
    case 0x80110324u: goto label_80110324;
    case 0x80110328u: goto label_80110328;
    case 0x8011032Cu: goto label_8011032C;
    case 0x80110330u: goto label_80110330;
    case 0x80110334u: goto label_80110334;
    case 0x80110338u: goto label_80110338;
    case 0x8011033Cu: goto label_8011033C;
    case 0x80110340u: goto label_80110340;
    case 0x80110344u: goto label_80110344;
    case 0x80110348u: goto label_80110348;
    case 0x8011034Cu: goto label_8011034C;
    case 0x80110350u: goto label_80110350;
    case 0x80110354u: goto label_80110354;
    case 0x80110358u: goto label_80110358;
    case 0x8011035Cu: goto label_8011035C;
    case 0x80110360u: goto label_80110360;
    case 0x80110364u: goto label_80110364;
    case 0x80110368u: goto label_80110368;
    case 0x8011036Cu: goto label_8011036C;
    case 0x80110370u: goto label_80110370;
    case 0x80110374u: goto label_80110374;
    case 0x80110378u: goto label_80110378;
    case 0x8011037Cu: goto label_8011037C;
    case 0x80110380u: goto label_80110380;
    case 0x80110384u: goto label_80110384;
    case 0x80110388u: goto label_80110388;
    case 0x8011038Cu: goto label_8011038C;
    case 0x80110390u: goto label_80110390;
    case 0x80110394u: goto label_80110394;
    case 0x80110398u: goto label_80110398;
    case 0x8011039Cu: goto label_8011039C;
    case 0x801103A0u: goto label_801103A0;
    case 0x801103A4u: goto label_801103A4;
    case 0x801103A8u: goto label_801103A8;
    case 0x801103ACu: goto label_801103AC;
    case 0x801103B0u: goto label_801103B0;
    case 0x801103B4u: goto label_801103B4;
    case 0x801103B8u: goto label_801103B8;
    case 0x801103BCu: goto label_801103BC;
    case 0x801103C0u: goto label_801103C0;
    case 0x801103C4u: goto label_801103C4;
    case 0x801103C8u: goto label_801103C8;
    case 0x801103CCu: goto label_801103CC;
    case 0x801103D0u: goto label_801103D0;
    case 0x801103D4u: goto label_801103D4;
    case 0x801103D8u: goto label_801103D8;
    case 0x801103DCu: goto label_801103DC;
    case 0x801103E0u: goto label_801103E0;
    case 0x801103E4u: goto label_801103E4;
    case 0x801103E8u: goto label_801103E8;
    case 0x801103ECu: goto label_801103EC;
    case 0x801103F0u: goto label_801103F0;
    case 0x801103F4u: goto label_801103F4;
    case 0x801103F8u: goto label_801103F8;
    case 0x801103FCu: goto label_801103FC;
    case 0x80110400u: goto label_80110400;
    case 0x80110404u: goto label_80110404;
    case 0x80110408u: goto label_80110408;
    case 0x8011040Cu: goto label_8011040C;
    case 0x80110410u: goto label_80110410;
    case 0x80110414u: goto label_80110414;
    case 0x80110418u: goto label_80110418;
    case 0x8011041Cu: goto label_8011041C;
    case 0x80110420u: goto label_80110420;
    case 0x80110424u: goto label_80110424;
    case 0x80110428u: goto label_80110428;
    case 0x8011042Cu: goto label_8011042C;
    case 0x80110430u: goto label_80110430;
    case 0x80110434u: goto label_80110434;
    case 0x80110438u: goto label_80110438;
    case 0x8011043Cu: goto label_8011043C;
    case 0x80110440u: goto label_80110440;
    case 0x80110444u: goto label_80110444;
    case 0x80110448u: goto label_80110448;
    case 0x8011044Cu: goto label_8011044C;
    case 0x80110450u: goto label_80110450;
    case 0x80110454u: goto label_80110454;
    case 0x80110458u: goto label_80110458;
    case 0x8011045Cu: goto label_8011045C;
    case 0x80110460u: goto label_80110460;
    case 0x80110464u: goto label_80110464;
    case 0x80110468u: goto label_80110468;
    case 0x8011046Cu: goto label_8011046C;
    case 0x80110470u: goto label_80110470;
    case 0x80110474u: goto label_80110474;
    case 0x80110478u: goto label_80110478;
    case 0x8011047Cu: goto label_8011047C;
    case 0x80110480u: goto label_80110480;
    case 0x80110484u: goto label_80110484;
    case 0x80110488u: goto label_80110488;
    case 0x8011048Cu: goto label_8011048C;
    case 0x80110490u: goto label_80110490;
    case 0x80110494u: goto label_80110494;
    case 0x80110498u: goto label_80110498;
    case 0x8011049Cu: goto label_8011049C;
    case 0x801104A0u: goto label_801104A0;
    case 0x801104A4u: goto label_801104A4;
    case 0x801104A8u: goto label_801104A8;
    case 0x801104ACu: goto label_801104AC;
    case 0x801104B0u: goto label_801104B0;
    case 0x801104B4u: goto label_801104B4;
    case 0x801104B8u: goto label_801104B8;
    case 0x801104BCu: goto label_801104BC;
    case 0x801104C0u: goto label_801104C0;
    case 0x801104C4u: goto label_801104C4;
    case 0x801104C8u: goto label_801104C8;
    case 0x801104CCu: goto label_801104CC;
    case 0x801104D0u: goto label_801104D0;
    case 0x801104D4u: goto label_801104D4;
    case 0x801104D8u: goto label_801104D8;
    case 0x801104DCu: goto label_801104DC;
    case 0x801104E0u: goto label_801104E0;
    case 0x801104E4u: goto label_801104E4;
    case 0x801104E8u: goto label_801104E8;
    case 0x801104ECu: goto label_801104EC;
    case 0x801104F0u: goto label_801104F0;
    case 0x801104F4u: goto label_801104F4;
    case 0x801104F8u: goto label_801104F8;
    case 0x801104FCu: goto label_801104FC;
    case 0x80110500u: goto label_80110500;
    case 0x80110504u: goto label_80110504;
    case 0x80110508u: goto label_80110508;
    case 0x8011050Cu: goto label_8011050C;
    case 0x80110510u: goto label_80110510;
    case 0x80110514u: goto label_80110514;
    case 0x80110518u: goto label_80110518;
    case 0x8011051Cu: goto label_8011051C;
    case 0x80110520u: goto label_80110520;
    case 0x80110524u: goto label_80110524;
    case 0x80110528u: goto label_80110528;
    case 0x8011052Cu: goto label_8011052C;
    case 0x80110530u: goto label_80110530;
    case 0x80110534u: goto label_80110534;
    case 0x80110538u: goto label_80110538;
    case 0x8011053Cu: goto label_8011053C;
    case 0x80110540u: goto label_80110540;
    case 0x80110544u: goto label_80110544;
    case 0x80110548u: goto label_80110548;
    case 0x8011054Cu: goto label_8011054C;
    case 0x80110550u: goto label_80110550;
    case 0x80110554u: goto label_80110554;
    case 0x80110558u: goto label_80110558;
    case 0x8011055Cu: goto label_8011055C;
    case 0x80110560u: goto label_80110560;
    case 0x80110564u: goto label_80110564;
    case 0x80110568u: goto label_80110568;
    case 0x8011056Cu: goto label_8011056C;
    case 0x80110570u: goto label_80110570;
    case 0x80110574u: goto label_80110574;
    case 0x80110578u: goto label_80110578;
    case 0x8011057Cu: goto label_8011057C;
    case 0x80110580u: goto label_80110580;
    case 0x80110584u: goto label_80110584;
    case 0x80110588u: goto label_80110588;
    case 0x8011058Cu: goto label_8011058C;
    case 0x80110590u: goto label_80110590;
    case 0x80110594u: goto label_80110594;
    case 0x80110598u: goto label_80110598;
    case 0x8011059Cu: goto label_8011059C;
    case 0x801105A0u: goto label_801105A0;
    case 0x801105A4u: goto label_801105A4;
    case 0x801105A8u: goto label_801105A8;
    case 0x801105ACu: goto label_801105AC;
    case 0x801105B0u: goto label_801105B0;
    case 0x801105B4u: goto label_801105B4;
    case 0x801105B8u: goto label_801105B8;
    case 0x801105BCu: goto label_801105BC;
    case 0x801105C0u: goto label_801105C0;
    case 0x801105C4u: goto label_801105C4;
    case 0x801105C8u: goto label_801105C8;
    case 0x801105CCu: goto label_801105CC;
    case 0x801105D0u: goto label_801105D0;
    case 0x801105D4u: goto label_801105D4;
    case 0x801105D8u: goto label_801105D8;
    case 0x801105DCu: goto label_801105DC;
    case 0x801105E0u: goto label_801105E0;
    case 0x801105E4u: goto label_801105E4;
    case 0x801105E8u: goto label_801105E8;
    case 0x801105ECu: goto label_801105EC;
    case 0x801105F0u: goto label_801105F0;
    case 0x801105F4u: goto label_801105F4;
    case 0x801105F8u: goto label_801105F8;
    case 0x801105FCu: goto label_801105FC;
    case 0x80110600u: goto label_80110600;
    case 0x80110604u: goto label_80110604;
    case 0x80110608u: goto label_80110608;
    case 0x8011060Cu: goto label_8011060C;
    case 0x80110610u: goto label_80110610;
    case 0x80110614u: goto label_80110614;
    case 0x80110618u: goto label_80110618;
    case 0x8011061Cu: goto label_8011061C;
    case 0x80110620u: goto label_80110620;
    case 0x80110624u: goto label_80110624;
    case 0x80110628u: goto label_80110628;
    case 0x8011062Cu: goto label_8011062C;
    case 0x80110630u: goto label_80110630;
    case 0x80110634u: goto label_80110634;
    case 0x80110638u: goto label_80110638;
    case 0x8011063Cu: goto label_8011063C;
    case 0x80110640u: goto label_80110640;
    case 0x80110644u: goto label_80110644;
    case 0x80110648u: goto label_80110648;
    case 0x8011064Cu: goto label_8011064C;
    case 0x80110650u: goto label_80110650;
    case 0x80110654u: goto label_80110654;
    case 0x80110658u: goto label_80110658;
    case 0x8011065Cu: goto label_8011065C;
    case 0x80110660u: goto label_80110660;
    case 0x80110664u: goto label_80110664;
    case 0x80110668u: goto label_80110668;
    case 0x8011066Cu: goto label_8011066C;
    case 0x80110670u: goto label_80110670;
    case 0x80110674u: goto label_80110674;
    case 0x80110678u: goto label_80110678;
    case 0x8011067Cu: goto label_8011067C;
    case 0x80110680u: goto label_80110680;
    case 0x80110684u: goto label_80110684;
    case 0x80110688u: goto label_80110688;
    case 0x8011068Cu: goto label_8011068C;
    case 0x80110690u: goto label_80110690;
    case 0x80110694u: goto label_80110694;
    case 0x80110698u: goto label_80110698;
    case 0x8011069Cu: goto label_8011069C;
    case 0x801106A0u: goto label_801106A0;
    case 0x801106A4u: goto label_801106A4;
    case 0x801106A8u: goto label_801106A8;
    case 0x801106ACu: goto label_801106AC;
    case 0x801106B0u: goto label_801106B0;
    case 0x801106B4u: goto label_801106B4;
    case 0x801106B8u: goto label_801106B8;
    case 0x801106BCu: goto label_801106BC;
    case 0x801106C0u: goto label_801106C0;
    case 0x801106C4u: goto label_801106C4;
    case 0x801106C8u: goto label_801106C8;
    case 0x801106CCu: goto label_801106CC;
    case 0x801106D0u: goto label_801106D0;
    case 0x801106D4u: goto label_801106D4;
    case 0x801106D8u: goto label_801106D8;
    case 0x801106DCu: goto label_801106DC;
    case 0x801106E0u: goto label_801106E0;
    case 0x801106E4u: goto label_801106E4;
    case 0x801106E8u: goto label_801106E8;
    case 0x801106ECu: goto label_801106EC;
    case 0x801106F0u: goto label_801106F0;
    case 0x801106F4u: goto label_801106F4;
    case 0x801106F8u: goto label_801106F8;
    case 0x801106FCu: goto label_801106FC;
    case 0x80110700u: goto label_80110700;
    case 0x80110704u: goto label_80110704;
    case 0x80110708u: goto label_80110708;
    case 0x8011070Cu: goto label_8011070C;
    case 0x80110710u: goto label_80110710;
    case 0x80110714u: goto label_80110714;
    case 0x80110718u: goto label_80110718;
    case 0x8011071Cu: goto label_8011071C;
    case 0x80110720u: goto label_80110720;
    case 0x80110724u: goto label_80110724;
    case 0x80110728u: goto label_80110728;
    case 0x8011072Cu: goto label_8011072C;
    case 0x80110730u: goto label_80110730;
    case 0x80110734u: goto label_80110734;
    case 0x80110738u: goto label_80110738;
    case 0x8011073Cu: goto label_8011073C;
    case 0x80110740u: goto label_80110740;
    case 0x80110744u: goto label_80110744;
    case 0x80110748u: goto label_80110748;
    case 0x8011074Cu: goto label_8011074C;
    case 0x80110750u: goto label_80110750;
    case 0x80110754u: goto label_80110754;
    case 0x80110758u: goto label_80110758;
    case 0x8011075Cu: goto label_8011075C;
    case 0x80110760u: goto label_80110760;
    case 0x80110764u: goto label_80110764;
    case 0x80110768u: goto label_80110768;
    case 0x8011076Cu: goto label_8011076C;
    case 0x80110770u: goto label_80110770;
    case 0x80110774u: goto label_80110774;
    case 0x80110778u: goto label_80110778;
    case 0x8011077Cu: goto label_8011077C;
    case 0x80110780u: goto label_80110780;
    case 0x80110784u: goto label_80110784;
    case 0x80110788u: goto label_80110788;
    case 0x8011078Cu: goto label_8011078C;
    case 0x80110790u: goto label_80110790;
    case 0x80110794u: goto label_80110794;
    case 0x80110798u: goto label_80110798;
    case 0x8011079Cu: goto label_8011079C;
    case 0x801107A0u: goto label_801107A0;
    case 0x801107A4u: goto label_801107A4;
    case 0x801107A8u: goto label_801107A8;
    case 0x801107ACu: goto label_801107AC;
    case 0x801107B0u: goto label_801107B0;
    case 0x801107B4u: goto label_801107B4;
    case 0x801107B8u: goto label_801107B8;
    case 0x801107BCu: goto label_801107BC;
    case 0x801107C0u: goto label_801107C0;
    case 0x801107C4u: goto label_801107C4;
    case 0x801107C8u: goto label_801107C8;
    case 0x801107CCu: goto label_801107CC;
    case 0x801107D0u: goto label_801107D0;
    case 0x801107D4u: goto label_801107D4;
    case 0x801107D8u: goto label_801107D8;
    case 0x801107DCu: goto label_801107DC;
    case 0x801107E0u: goto label_801107E0;
    case 0x801107E4u: goto label_801107E4;
    case 0x801107E8u: goto label_801107E8;
    case 0x801107ECu: goto label_801107EC;
    case 0x801107F0u: goto label_801107F0;
    case 0x801107F4u: goto label_801107F4;
    case 0x801107F8u: goto label_801107F8;
    case 0x801107FCu: goto label_801107FC;
    case 0x80110800u: goto label_80110800;
    case 0x80110804u: goto label_80110804;
    case 0x80110808u: goto label_80110808;
    case 0x8011080Cu: goto label_8011080C;
    case 0x80110810u: goto label_80110810;
    case 0x80110814u: goto label_80110814;
    case 0x80110818u: goto label_80110818;
    case 0x8011081Cu: goto label_8011081C;
    case 0x80110820u: goto label_80110820;
    case 0x80110824u: goto label_80110824;
    case 0x80110828u: goto label_80110828;
    case 0x8011082Cu: goto label_8011082C;
    case 0x80110830u: goto label_80110830;
    case 0x80110834u: goto label_80110834;
    case 0x80110838u: goto label_80110838;
    case 0x8011083Cu: goto label_8011083C;
    case 0x80110840u: goto label_80110840;
    case 0x80110844u: goto label_80110844;
    case 0x80110848u: goto label_80110848;
    case 0x8011084Cu: goto label_8011084C;
    case 0x80110850u: goto label_80110850;
    case 0x80110854u: goto label_80110854;
    case 0x80110858u: goto label_80110858;
    case 0x8011085Cu: goto label_8011085C;
    case 0x80110860u: goto label_80110860;
    case 0x80110864u: goto label_80110864;
    case 0x80110868u: goto label_80110868;
    case 0x8011086Cu: goto label_8011086C;
    case 0x80110870u: goto label_80110870;
    case 0x80110874u: goto label_80110874;
    case 0x80110878u: goto label_80110878;
    case 0x8011087Cu: goto label_8011087C;
    case 0x80110880u: goto label_80110880;
    case 0x80110884u: goto label_80110884;
    case 0x80110888u: goto label_80110888;
    case 0x8011088Cu: goto label_8011088C;
    case 0x80110890u: goto label_80110890;
    case 0x80110894u: goto label_80110894;
    case 0x80110898u: goto label_80110898;
    case 0x8011089Cu: goto label_8011089C;
    case 0x801108A0u: goto label_801108A0;
    case 0x801108A4u: goto label_801108A4;
    case 0x801108A8u: goto label_801108A8;
    case 0x801108ACu: goto label_801108AC;
    case 0x801108B0u: goto label_801108B0;
    case 0x801108B4u: goto label_801108B4;
    case 0x801108B8u: goto label_801108B8;
    case 0x801108BCu: goto label_801108BC;
    case 0x801108C0u: goto label_801108C0;
    case 0x801108C4u: goto label_801108C4;
    case 0x801108C8u: goto label_801108C8;
    case 0x801108CCu: goto label_801108CC;
    case 0x801108D0u: goto label_801108D0;
    case 0x801108D4u: goto label_801108D4;
    case 0x801108D8u: goto label_801108D8;
    case 0x801108DCu: goto label_801108DC;
    case 0x801108E0u: goto label_801108E0;
    case 0x801108E4u: goto label_801108E4;
    case 0x801108E8u: goto label_801108E8;
    case 0x801108ECu: goto label_801108EC;
    case 0x801108F0u: goto label_801108F0;
    case 0x801108F4u: goto label_801108F4;
    case 0x801108F8u: goto label_801108F8;
    case 0x801108FCu: goto label_801108FC;
    case 0x80110900u: goto label_80110900;
    case 0x80110904u: goto label_80110904;
    case 0x80110908u: goto label_80110908;
    case 0x8011090Cu: goto label_8011090C;
    case 0x80110910u: goto label_80110910;
    case 0x80110914u: goto label_80110914;
    case 0x80110918u: goto label_80110918;
    case 0x8011091Cu: goto label_8011091C;
    case 0x80110920u: goto label_80110920;
    case 0x80110924u: goto label_80110924;
    case 0x80110928u: goto label_80110928;
    case 0x8011092Cu: goto label_8011092C;
    case 0x80110930u: goto label_80110930;
    case 0x80110934u: goto label_80110934;
    case 0x80110938u: goto label_80110938;
    case 0x8011093Cu: goto label_8011093C;
    case 0x80110940u: goto label_80110940;
    case 0x80110944u: goto label_80110944;
    case 0x80110948u: goto label_80110948;
    case 0x8011094Cu: goto label_8011094C;
    case 0x80110950u: goto label_80110950;
    case 0x80110954u: goto label_80110954;
    case 0x80110958u: goto label_80110958;
    case 0x8011095Cu: goto label_8011095C;
    case 0x80110960u: goto label_80110960;
    case 0x80110964u: goto label_80110964;
    case 0x80110968u: goto label_80110968;
    case 0x8011096Cu: goto label_8011096C;
    case 0x80110970u: goto label_80110970;
    case 0x80110974u: goto label_80110974;
    case 0x80110978u: goto label_80110978;
    case 0x8011097Cu: goto label_8011097C;
    case 0x80110980u: goto label_80110980;
    case 0x80110984u: goto label_80110984;
    case 0x80110988u: goto label_80110988;
    case 0x8011098Cu: goto label_8011098C;
    case 0x80110990u: goto label_80110990;
    case 0x80110994u: goto label_80110994;
    case 0x80110998u: goto label_80110998;
    case 0x8011099Cu: goto label_8011099C;
    case 0x801109A0u: goto label_801109A0;
    case 0x801109A4u: goto label_801109A4;
    case 0x801109A8u: goto label_801109A8;
    case 0x801109ACu: goto label_801109AC;
    case 0x801109B0u: goto label_801109B0;
    case 0x801109B4u: goto label_801109B4;
    case 0x801109B8u: goto label_801109B8;
    case 0x801109BCu: goto label_801109BC;
    case 0x801109C0u: goto label_801109C0;
    case 0x801109C4u: goto label_801109C4;
    case 0x801109C8u: goto label_801109C8;
    case 0x801109CCu: goto label_801109CC;
    case 0x801109D0u: goto label_801109D0;
    case 0x801109D4u: goto label_801109D4;
    case 0x801109D8u: goto label_801109D8;
    case 0x801109DCu: goto label_801109DC;
    case 0x801109E0u: goto label_801109E0;
    case 0x801109E4u: goto label_801109E4;
    case 0x801109E8u: goto label_801109E8;
    case 0x801109ECu: goto label_801109EC;
    case 0x801109F0u: goto label_801109F0;
    case 0x801109F4u: goto label_801109F4;
    case 0x801109F8u: goto label_801109F8;
    case 0x801109FCu: goto label_801109FC;
    case 0x80110A00u: goto label_80110A00;
    case 0x80110A04u: goto label_80110A04;
    case 0x80110A08u: goto label_80110A08;
    case 0x80110A0Cu: goto label_80110A0C;
    case 0x80110A10u: goto label_80110A10;
    case 0x80110A14u: goto label_80110A14;
    case 0x80110A18u: goto label_80110A18;
    case 0x80110A1Cu: goto label_80110A1C;
    case 0x80110A20u: goto label_80110A20;
    case 0x80110A24u: goto label_80110A24;
    case 0x80110A28u: goto label_80110A28;
    case 0x80110A2Cu: goto label_80110A2C;
    case 0x80110A30u: goto label_80110A30;
    case 0x80110A34u: goto label_80110A34;
    case 0x80110A38u: goto label_80110A38;
    case 0x80110A3Cu: goto label_80110A3C;
    case 0x80110A40u: goto label_80110A40;
    case 0x80110A44u: goto label_80110A44;
    case 0x80110A48u: goto label_80110A48;
    case 0x80110A4Cu: goto label_80110A4C;
    case 0x80110A50u: goto label_80110A50;
    case 0x80110A54u: goto label_80110A54;
    case 0x80110A58u: goto label_80110A58;
    case 0x80110A5Cu: goto label_80110A5C;
    case 0x80110A60u: goto label_80110A60;
    case 0x80110A64u: goto label_80110A64;
    case 0x80110A68u: goto label_80110A68;
    case 0x80110A6Cu: goto label_80110A6C;
    case 0x80110A70u: goto label_80110A70;
    case 0x80110A74u: goto label_80110A74;
    case 0x80110A78u: goto label_80110A78;
    case 0x80110A7Cu: goto label_80110A7C;
    case 0x80110A80u: goto label_80110A80;
    case 0x80110A84u: goto label_80110A84;
    case 0x80110A88u: goto label_80110A88;
    case 0x80110A8Cu: goto label_80110A8C;
    case 0x80110A90u: goto label_80110A90;
    case 0x80110A94u: goto label_80110A94;
    case 0x80110A98u: goto label_80110A98;
    case 0x80110A9Cu: goto label_80110A9C;
    case 0x80110AA0u: goto label_80110AA0;
    case 0x80110AA4u: goto label_80110AA4;
    case 0x80110AA8u: goto label_80110AA8;
    case 0x80110AACu: goto label_80110AAC;
    case 0x80110AB0u: goto label_80110AB0;
    case 0x80110AB4u: goto label_80110AB4;
    case 0x80110AB8u: goto label_80110AB8;
    case 0x80110ABCu: goto label_80110ABC;
    case 0x80110AC0u: goto label_80110AC0;
    case 0x80110AC4u: goto label_80110AC4;
    case 0x80110AC8u: goto label_80110AC8;
    case 0x80110ACCu: goto label_80110ACC;
    case 0x80110AD0u: goto label_80110AD0;
    case 0x80110AD4u: goto label_80110AD4;
    case 0x80110AD8u: goto label_80110AD8;
    case 0x80110ADCu: goto label_80110ADC;
    case 0x80110AE0u: goto label_80110AE0;
    case 0x80110AE4u: goto label_80110AE4;
    case 0x80110AE8u: goto label_80110AE8;
    case 0x80110AECu: goto label_80110AEC;
    case 0x80110AF0u: goto label_80110AF0;
    case 0x80110AF4u: goto label_80110AF4;
    case 0x80110AF8u: goto label_80110AF8;
    case 0x80110AFCu: goto label_80110AFC;
    case 0x80110B00u: goto label_80110B00;
    case 0x80110B04u: goto label_80110B04;
    case 0x80110B08u: goto label_80110B08;
    case 0x80110B0Cu: goto label_80110B0C;
    case 0x80110B10u: goto label_80110B10;
    case 0x80110B14u: goto label_80110B14;
    case 0x80110B18u: goto label_80110B18;
    case 0x80110B1Cu: goto label_80110B1C;
    case 0x80110B20u: goto label_80110B20;
    case 0x80110B24u: goto label_80110B24;
    case 0x80110B28u: goto label_80110B28;
    case 0x80110B2Cu: goto label_80110B2C;
    case 0x80110B30u: goto label_80110B30;
    case 0x80110B34u: goto label_80110B34;
    case 0x80110B38u: goto label_80110B38;
    case 0x80110B3Cu: goto label_80110B3C;
    case 0x80110B40u: goto label_80110B40;
    case 0x80110B44u: goto label_80110B44;
    case 0x80110B48u: goto label_80110B48;
    case 0x80110B4Cu: goto label_80110B4C;
    case 0x80110B50u: goto label_80110B50;
    case 0x80110B54u: goto label_80110B54;
    case 0x80110B58u: goto label_80110B58;
    case 0x80110B5Cu: goto label_80110B5C;
    case 0x80110B60u: goto label_80110B60;
    case 0x80110B64u: goto label_80110B64;
    case 0x80110B68u: goto label_80110B68;
    case 0x80110B6Cu: goto label_80110B6C;
    case 0x80110B70u: goto label_80110B70;
    case 0x80110B74u: goto label_80110B74;
    case 0x80110B78u: goto label_80110B78;
    case 0x80110B7Cu: goto label_80110B7C;
    case 0x80110B80u: goto label_80110B80;
    case 0x80110B84u: goto label_80110B84;
    case 0x80110B88u: goto label_80110B88;
    case 0x80110B8Cu: goto label_80110B8C;
    case 0x80110B90u: goto label_80110B90;
    case 0x80110B94u: goto label_80110B94;
    case 0x80110B98u: goto label_80110B98;
    case 0x80110B9Cu: goto label_80110B9C;
    case 0x80110BA0u: goto label_80110BA0;
    case 0x80110BA4u: goto label_80110BA4;
    case 0x80110BA8u: goto label_80110BA8;
    case 0x80110BACu: goto label_80110BAC;
    case 0x80110BB0u: goto label_80110BB0;
    case 0x80110BB4u: goto label_80110BB4;
    case 0x80110BB8u: goto label_80110BB8;
    case 0x80110BBCu: goto label_80110BBC;
    case 0x80110BC0u: goto label_80110BC0;
    case 0x80110BC4u: goto label_80110BC4;
    case 0x80110BC8u: goto label_80110BC8;
    case 0x80110BCCu: goto label_80110BCC;
    case 0x80110BD0u: goto label_80110BD0;
    case 0x80110BD4u: goto label_80110BD4;
    case 0x80110BD8u: goto label_80110BD8;
    case 0x80110BDCu: goto label_80110BDC;
    case 0x80110BE0u: goto label_80110BE0;
    case 0x80110BE4u: goto label_80110BE4;
    case 0x80110BE8u: goto label_80110BE8;
    case 0x80110BECu: goto label_80110BEC;
    case 0x80110BF0u: goto label_80110BF0;
    case 0x80110BF4u: goto label_80110BF4;
    case 0x80110BF8u: goto label_80110BF8;
    case 0x80110BFCu: goto label_80110BFC;
    case 0x80110C00u: goto label_80110C00;
    case 0x80110C04u: goto label_80110C04;
    case 0x80110C08u: goto label_80110C08;
    case 0x80110C0Cu: goto label_80110C0C;
    case 0x80110C10u: goto label_80110C10;
    case 0x80110C14u: goto label_80110C14;
    case 0x80110C18u: goto label_80110C18;
    case 0x80110C1Cu: goto label_80110C1C;
    case 0x80110C20u: goto label_80110C20;
    case 0x80110C24u: goto label_80110C24;
    case 0x80110C28u: goto label_80110C28;
    case 0x80110C2Cu: goto label_80110C2C;
    case 0x80110C30u: goto label_80110C30;
    case 0x80110C34u: goto label_80110C34;
    case 0x80110C38u: goto label_80110C38;
    case 0x80110C3Cu: goto label_80110C3C;
    case 0x80110C40u: goto label_80110C40;
    case 0x80110C44u: goto label_80110C44;
    case 0x80110C48u: goto label_80110C48;
    case 0x80110C4Cu: goto label_80110C4C;
    case 0x80110C50u: goto label_80110C50;
    case 0x80110C54u: goto label_80110C54;
    case 0x80110C58u: goto label_80110C58;
    case 0x80110C5Cu: goto label_80110C5C;
    case 0x80110C60u: goto label_80110C60;
    case 0x80110C64u: goto label_80110C64;
    case 0x80110C68u: goto label_80110C68;
    case 0x80110C6Cu: goto label_80110C6C;
    case 0x80110C70u: goto label_80110C70;
    case 0x80110C74u: goto label_80110C74;
    case 0x80110C78u: goto label_80110C78;
    case 0x80110C7Cu: goto label_80110C7C;
    case 0x80110C80u: goto label_80110C80;
    case 0x80110C84u: goto label_80110C84;
    case 0x80110C88u: goto label_80110C88;
    case 0x80110C8Cu: goto label_80110C8C;
    case 0x80110C90u: goto label_80110C90;
    case 0x80110C94u: goto label_80110C94;
    case 0x80110C98u: goto label_80110C98;
    case 0x80110C9Cu: goto label_80110C9C;
    case 0x80110CA0u: goto label_80110CA0;
    case 0x80110CA4u: goto label_80110CA4;
    case 0x80110CA8u: goto label_80110CA8;
    case 0x80110CACu: goto label_80110CAC;
    case 0x80110CB0u: goto label_80110CB0;
    case 0x80110CB4u: goto label_80110CB4;
    case 0x80110CB8u: goto label_80110CB8;
    case 0x80110CBCu: goto label_80110CBC;
    case 0x80110CC0u: goto label_80110CC0;
    case 0x80110CC4u: goto label_80110CC4;
    case 0x80110CC8u: goto label_80110CC8;
    case 0x80110CCCu: goto label_80110CCC;
    case 0x80110CD0u: goto label_80110CD0;
    case 0x80110CD4u: goto label_80110CD4;
    case 0x80110CD8u: goto label_80110CD8;
    case 0x80110CDCu: goto label_80110CDC;
    case 0x80110CE0u: goto label_80110CE0;
    case 0x80110CE4u: goto label_80110CE4;
    case 0x80110CE8u: goto label_80110CE8;
    case 0x80110CECu: goto label_80110CEC;
    case 0x80110CF0u: goto label_80110CF0;
    case 0x80110CF4u: goto label_80110CF4;
    case 0x80110CF8u: goto label_80110CF8;
    case 0x80110CFCu: goto label_80110CFC;
    case 0x80110D00u: goto label_80110D00;
    case 0x80110D04u: goto label_80110D04;
    case 0x80110D08u: goto label_80110D08;
    case 0x80110D0Cu: goto label_80110D0C;
    case 0x80110D10u: goto label_80110D10;
    case 0x80110D14u: goto label_80110D14;
    case 0x80110D18u: goto label_80110D18;
    case 0x80110D1Cu: goto label_80110D1C;
    case 0x80110D20u: goto label_80110D20;
    case 0x80110D24u: goto label_80110D24;
    case 0x80110D28u: goto label_80110D28;
    case 0x80110D2Cu: goto label_80110D2C;
    case 0x80110D30u: goto label_80110D30;
    case 0x80110D34u: goto label_80110D34;
    case 0x80110D38u: goto label_80110D38;
    case 0x80110D3Cu: goto label_80110D3C;
    case 0x80110D40u: goto label_80110D40;
    case 0x80110D44u: goto label_80110D44;
    case 0x80110D48u: goto label_80110D48;
    case 0x80110D4Cu: goto label_80110D4C;
    case 0x80110D50u: goto label_80110D50;
    case 0x80110D54u: goto label_80110D54;
    case 0x80110D58u: goto label_80110D58;
    case 0x80110D5Cu: goto label_80110D5C;
    case 0x80110D60u: goto label_80110D60;
    case 0x80110D64u: goto label_80110D64;
    case 0x80110D68u: goto label_80110D68;
    case 0x80110D6Cu: goto label_80110D6C;
    case 0x80110D70u: goto label_80110D70;
    case 0x80110D74u: goto label_80110D74;
    case 0x80110D78u: goto label_80110D78;
    case 0x80110D7Cu: goto label_80110D7C;
    case 0x80110D80u: goto label_80110D80;
    case 0x80110D84u: goto label_80110D84;
    case 0x80110D88u: goto label_80110D88;
    case 0x80110D8Cu: goto label_80110D8C;
    case 0x80110D90u: goto label_80110D90;
    case 0x80110D94u: goto label_80110D94;
    case 0x80110D98u: goto label_80110D98;
    case 0x80110D9Cu: goto label_80110D9C;
    case 0x80110DA0u: goto label_80110DA0;
    case 0x80110DA4u: goto label_80110DA4;
    case 0x80110DA8u: goto label_80110DA8;
    case 0x80110DACu: goto label_80110DAC;
    case 0x80110DB0u: goto label_80110DB0;
    case 0x80110DB4u: goto label_80110DB4;
    case 0x80110DB8u: goto label_80110DB8;
    case 0x80110DBCu: goto label_80110DBC;
    case 0x80110DC0u: goto label_80110DC0;
    case 0x80110DC4u: goto label_80110DC4;
    case 0x80110DC8u: goto label_80110DC8;
    case 0x80110DCCu: goto label_80110DCC;
    case 0x80110DD0u: goto label_80110DD0;
    case 0x80110DD4u: goto label_80110DD4;
    case 0x80110DD8u: goto label_80110DD8;
    case 0x80110DDCu: goto label_80110DDC;
    case 0x80110DE0u: goto label_80110DE0;
    case 0x80110DE4u: goto label_80110DE4;
    case 0x80110DE8u: goto label_80110DE8;
    case 0x80110DECu: goto label_80110DEC;
    case 0x80110DF0u: goto label_80110DF0;
    case 0x80110DF4u: goto label_80110DF4;
    case 0x80110DF8u: goto label_80110DF8;
    case 0x80110DFCu: goto label_80110DFC;
    case 0x80110E00u: goto label_80110E00;
    case 0x80110E04u: goto label_80110E04;
    case 0x80110E08u: goto label_80110E08;
    case 0x80110E0Cu: goto label_80110E0C;
    case 0x80110E10u: goto label_80110E10;
    case 0x80110E14u: goto label_80110E14;
    case 0x80110E18u: goto label_80110E18;
    case 0x80110E1Cu: goto label_80110E1C;
    case 0x80110E20u: goto label_80110E20;
    case 0x80110E24u: goto label_80110E24;
    case 0x80110E28u: goto label_80110E28;
    case 0x80110E2Cu: goto label_80110E2C;
    case 0x80110E30u: goto label_80110E30;
    case 0x80110E34u: goto label_80110E34;
    case 0x80110E38u: goto label_80110E38;
    case 0x80110E3Cu: goto label_80110E3C;
    case 0x80110E40u: goto label_80110E40;
    case 0x80110E44u: goto label_80110E44;
    case 0x80110E48u: goto label_80110E48;
    case 0x80110E4Cu: goto label_80110E4C;
    case 0x80110E50u: goto label_80110E50;
    case 0x80110E54u: goto label_80110E54;
    case 0x80110E58u: goto label_80110E58;
    case 0x80110E5Cu: goto label_80110E5C;
    case 0x80110E60u: goto label_80110E60;
    case 0x80110E64u: goto label_80110E64;
    case 0x80110E68u: goto label_80110E68;
    case 0x80110E6Cu: goto label_80110E6C;
    case 0x80110E70u: goto label_80110E70;
    case 0x80110E74u: goto label_80110E74;
    case 0x80110E78u: goto label_80110E78;
    case 0x80110E7Cu: goto label_80110E7C;
    case 0x80110E80u: goto label_80110E80;
    case 0x80110E84u: goto label_80110E84;
    case 0x80110E88u: goto label_80110E88;
    case 0x80110E8Cu: goto label_80110E8C;
    case 0x80110E90u: goto label_80110E90;
    case 0x80110E94u: goto label_80110E94;
    case 0x80110E98u: goto label_80110E98;
    case 0x80110E9Cu: goto label_80110E9C;
    case 0x80110EA0u: goto label_80110EA0;
    case 0x80110EA4u: goto label_80110EA4;
    case 0x80110EA8u: goto label_80110EA8;
    case 0x80110EACu: goto label_80110EAC;
    case 0x80110EB0u: goto label_80110EB0;
    case 0x80110EB4u: goto label_80110EB4;
    case 0x80110EB8u: goto label_80110EB8;
    case 0x80110EBCu: goto label_80110EBC;
    case 0x80110EC0u: goto label_80110EC0;
    case 0x80110EC4u: goto label_80110EC4;
    case 0x80110EC8u: goto label_80110EC8;
    case 0x80110ECCu: goto label_80110ECC;
    case 0x80110ED0u: goto label_80110ED0;
    case 0x80110ED4u: goto label_80110ED4;
    case 0x80110ED8u: goto label_80110ED8;
    case 0x80110EDCu: goto label_80110EDC;
    case 0x80110EE0u: goto label_80110EE0;
    case 0x80110EE4u: goto label_80110EE4;
    case 0x80110EE8u: goto label_80110EE8;
    case 0x80110EECu: goto label_80110EEC;
    case 0x80110EF0u: goto label_80110EF0;
    case 0x80110EF4u: goto label_80110EF4;
    case 0x80110EF8u: goto label_80110EF8;
    case 0x80110EFCu: goto label_80110EFC;
    case 0x80110F00u: goto label_80110F00;
    case 0x80110F04u: goto label_80110F04;
    case 0x80110F08u: goto label_80110F08;
    case 0x80110F0Cu: goto label_80110F0C;
    case 0x80110F10u: goto label_80110F10;
    case 0x80110F14u: goto label_80110F14;
    case 0x80110F18u: goto label_80110F18;
    case 0x80110F1Cu: goto label_80110F1C;
    case 0x80110F20u: goto label_80110F20;
    case 0x80110F24u: goto label_80110F24;
    case 0x80110F28u: goto label_80110F28;
    case 0x80110F2Cu: goto label_80110F2C;
    case 0x80110F30u: goto label_80110F30;
    case 0x80110F34u: goto label_80110F34;
    case 0x80110F38u: goto label_80110F38;
    case 0x80110F3Cu: goto label_80110F3C;
    case 0x80110F40u: goto label_80110F40;
    case 0x80110F44u: goto label_80110F44;
    case 0x80110F48u: goto label_80110F48;
    case 0x80110F4Cu: goto label_80110F4C;
    case 0x80110F50u: goto label_80110F50;
    case 0x80110F54u: goto label_80110F54;
    case 0x80110F58u: goto label_80110F58;
    case 0x80110F5Cu: goto label_80110F5C;
    case 0x80110F60u: goto label_80110F60;
    case 0x80110F64u: goto label_80110F64;
    case 0x80110F68u: goto label_80110F68;
    case 0x80110F6Cu: goto label_80110F6C;
    case 0x80110F70u: goto label_80110F70;
    case 0x80110F74u: goto label_80110F74;
    case 0x80110F78u: goto label_80110F78;
    case 0x80110F7Cu: goto label_80110F7C;
    case 0x80110F80u: goto label_80110F80;
    case 0x80110F84u: goto label_80110F84;
    case 0x80110F88u: goto label_80110F88;
    case 0x80110F8Cu: goto label_80110F8C;
    case 0x80110F90u: goto label_80110F90;
    case 0x80110F94u: goto label_80110F94;
    case 0x80110F98u: goto label_80110F98;
    case 0x80110F9Cu: goto label_80110F9C;
    case 0x80110FA0u: goto label_80110FA0;
    case 0x80110FA4u: goto label_80110FA4;
    case 0x80110FA8u: goto label_80110FA8;
    case 0x80110FACu: goto label_80110FAC;
    case 0x80110FB0u: goto label_80110FB0;
    case 0x80110FB4u: goto label_80110FB4;
    case 0x80110FB8u: goto label_80110FB8;
    case 0x80110FBCu: goto label_80110FBC;
    case 0x80110FC0u: goto label_80110FC0;
    case 0x80110FC4u: goto label_80110FC4;
    case 0x80110FC8u: goto label_80110FC8;
    case 0x80110FCCu: goto label_80110FCC;
    case 0x80110FD0u: goto label_80110FD0;
    case 0x80110FD4u: goto label_80110FD4;
    case 0x80110FD8u: goto label_80110FD8;
    case 0x80110FDCu: goto label_80110FDC;
    case 0x80110FE0u: goto label_80110FE0;
    case 0x80110FE4u: goto label_80110FE4;
    case 0x80110FE8u: goto label_80110FE8;
    case 0x80110FECu: goto label_80110FEC;
    case 0x80110FF0u: goto label_80110FF0;
    case 0x80110FF4u: goto label_80110FF4;
    case 0x80110FF8u: goto label_80110FF8;
    case 0x80110FFCu: goto label_80110FFC;
    case 0x80111000u: goto label_80111000;
    case 0x80111004u: goto label_80111004;
    case 0x80111008u: goto label_80111008;
    case 0x8011100Cu: goto label_8011100C;
    case 0x80111010u: goto label_80111010;
    case 0x80111014u: goto label_80111014;
    case 0x80111018u: goto label_80111018;
    case 0x8011101Cu: goto label_8011101C;
    case 0x80111020u: goto label_80111020;
    case 0x80111024u: goto label_80111024;
    case 0x80111028u: goto label_80111028;
    case 0x8011102Cu: goto label_8011102C;
    case 0x80111030u: goto label_80111030;
    case 0x80111034u: goto label_80111034;
    case 0x80111038u: goto label_80111038;
    case 0x8011103Cu: goto label_8011103C;
    case 0x80111040u: goto label_80111040;
    case 0x80111044u: goto label_80111044;
    case 0x80111048u: goto label_80111048;
    case 0x8011104Cu: goto label_8011104C;
    case 0x80111050u: goto label_80111050;
    case 0x80111054u: goto label_80111054;
    case 0x80111058u: goto label_80111058;
    case 0x8011105Cu: goto label_8011105C;
    case 0x80111060u: goto label_80111060;
    case 0x80111064u: goto label_80111064;
    case 0x80111068u: goto label_80111068;
    case 0x8011106Cu: goto label_8011106C;
    case 0x80111070u: goto label_80111070;
    case 0x80111074u: goto label_80111074;
    case 0x80111078u: goto label_80111078;
    case 0x8011107Cu: goto label_8011107C;
    case 0x80111080u: goto label_80111080;
    case 0x80111084u: goto label_80111084;
    case 0x80111088u: goto label_80111088;
    case 0x8011108Cu: goto label_8011108C;
    case 0x80111090u: goto label_80111090;
    case 0x80111094u: goto label_80111094;
    case 0x80111098u: goto label_80111098;
    case 0x8011109Cu: goto label_8011109C;
    case 0x801110A0u: goto label_801110A0;
    case 0x801110A4u: goto label_801110A4;
    case 0x801110A8u: goto label_801110A8;
    case 0x801110ACu: goto label_801110AC;
    case 0x801110B0u: goto label_801110B0;
    case 0x801110B4u: goto label_801110B4;
    case 0x801110B8u: goto label_801110B8;
    case 0x801110BCu: goto label_801110BC;
    case 0x801110C0u: goto label_801110C0;
    case 0x801110C4u: goto label_801110C4;
    case 0x801110C8u: goto label_801110C8;
    case 0x801110CCu: goto label_801110CC;
    case 0x801110D0u: goto label_801110D0;
    case 0x801110D4u: goto label_801110D4;
    case 0x801110D8u: goto label_801110D8;
    case 0x801110DCu: goto label_801110DC;
    case 0x801110E0u: goto label_801110E0;
    case 0x801110E4u: goto label_801110E4;
    case 0x801110E8u: goto label_801110E8;
    case 0x801110ECu: goto label_801110EC;
    case 0x801110F0u: goto label_801110F0;
    case 0x801110F4u: goto label_801110F4;
    case 0x801110F8u: goto label_801110F8;
    case 0x801110FCu: goto label_801110FC;
    case 0x80111100u: goto label_80111100;
    case 0x80111104u: goto label_80111104;
    case 0x80111108u: goto label_80111108;
    case 0x8011110Cu: goto label_8011110C;
    case 0x80111110u: goto label_80111110;
    case 0x80111114u: goto label_80111114;
    case 0x80111118u: goto label_80111118;
    case 0x8011111Cu: goto label_8011111C;
    case 0x80111120u: goto label_80111120;
    case 0x80111124u: goto label_80111124;
    case 0x80111128u: goto label_80111128;
    case 0x8011112Cu: goto label_8011112C;
    case 0x80111130u: goto label_80111130;
    case 0x80111134u: goto label_80111134;
    case 0x80111138u: goto label_80111138;
    case 0x8011113Cu: goto label_8011113C;
    case 0x80111140u: goto label_80111140;
    case 0x80111144u: goto label_80111144;
    case 0x80111148u: goto label_80111148;
    case 0x8011114Cu: goto label_8011114C;
    case 0x80111150u: goto label_80111150;
    case 0x80111154u: goto label_80111154;
    case 0x80111158u: goto label_80111158;
    case 0x8011115Cu: goto label_8011115C;
    case 0x80111160u: goto label_80111160;
    case 0x80111164u: goto label_80111164;
    case 0x80111168u: goto label_80111168;
    case 0x8011116Cu: goto label_8011116C;
    case 0x80111170u: goto label_80111170;
    case 0x80111174u: goto label_80111174;
    case 0x80111178u: goto label_80111178;
    case 0x8011117Cu: goto label_8011117C;
    case 0x80111180u: goto label_80111180;
    case 0x80111184u: goto label_80111184;
    case 0x80111188u: goto label_80111188;
    case 0x8011118Cu: goto label_8011118C;
    case 0x80111190u: goto label_80111190;
    case 0x80111194u: goto label_80111194;
    case 0x80111198u: goto label_80111198;
    case 0x8011119Cu: goto label_8011119C;
    case 0x801111A0u: goto label_801111A0;
    case 0x801111A4u: goto label_801111A4;
    case 0x801111A8u: goto label_801111A8;
    case 0x801111ACu: goto label_801111AC;
    case 0x801111B0u: goto label_801111B0;
    case 0x801111B4u: goto label_801111B4;
    case 0x801111B8u: goto label_801111B8;
    case 0x801111BCu: goto label_801111BC;
    case 0x801111C0u: goto label_801111C0;
    case 0x801111C4u: goto label_801111C4;
    case 0x801111C8u: goto label_801111C8;
    case 0x801111CCu: goto label_801111CC;
    case 0x801111D0u: goto label_801111D0;
    case 0x801111D4u: goto label_801111D4;
    case 0x801111D8u: goto label_801111D8;
    case 0x801111DCu: goto label_801111DC;
    case 0x801111E0u: goto label_801111E0;
    case 0x801111E4u: goto label_801111E4;
    case 0x801111E8u: goto label_801111E8;
    case 0x801111ECu: goto label_801111EC;
    case 0x801111F0u: goto label_801111F0;
    case 0x801111F4u: goto label_801111F4;
    case 0x801111F8u: goto label_801111F8;
    case 0x801111FCu: goto label_801111FC;
    case 0x80111200u: goto label_80111200;
    case 0x80111204u: goto label_80111204;
    case 0x80111208u: goto label_80111208;
    case 0x8011120Cu: goto label_8011120C;
    case 0x80111210u: goto label_80111210;
    case 0x80111214u: goto label_80111214;
    case 0x80111218u: goto label_80111218;
    case 0x8011121Cu: goto label_8011121C;
    case 0x80111220u: goto label_80111220;
    case 0x80111224u: goto label_80111224;
    case 0x80111228u: goto label_80111228;
    case 0x8011122Cu: goto label_8011122C;
    case 0x80111230u: goto label_80111230;
    case 0x80111234u: goto label_80111234;
    case 0x80111238u: goto label_80111238;
    case 0x8011123Cu: goto label_8011123C;
    case 0x80111240u: goto label_80111240;
    case 0x80111244u: goto label_80111244;
    case 0x80111248u: goto label_80111248;
    case 0x8011124Cu: goto label_8011124C;
    case 0x80111250u: goto label_80111250;
    case 0x80111254u: goto label_80111254;
    case 0x80111258u: goto label_80111258;
    case 0x8011125Cu: goto label_8011125C;
    case 0x80111260u: goto label_80111260;
    case 0x80111264u: goto label_80111264;
    case 0x80111268u: goto label_80111268;
    case 0x8011126Cu: goto label_8011126C;
    case 0x80111270u: goto label_80111270;
    case 0x80111274u: goto label_80111274;
    case 0x80111278u: goto label_80111278;
    case 0x8011127Cu: goto label_8011127C;
    case 0x80111280u: goto label_80111280;
    case 0x80111284u: goto label_80111284;
    case 0x80111288u: goto label_80111288;
    case 0x8011128Cu: goto label_8011128C;
    case 0x80111290u: goto label_80111290;
    case 0x80111294u: goto label_80111294;
    case 0x80111298u: goto label_80111298;
    case 0x8011129Cu: goto label_8011129C;
    case 0x801112A0u: goto label_801112A0;
    case 0x801112A4u: goto label_801112A4;
    case 0x801112A8u: goto label_801112A8;
    case 0x801112ACu: goto label_801112AC;
    case 0x801112B0u: goto label_801112B0;
    case 0x801112B4u: goto label_801112B4;
    case 0x801112B8u: goto label_801112B8;
    case 0x801112BCu: goto label_801112BC;
    case 0x801112C0u: goto label_801112C0;
    case 0x801112C4u: goto label_801112C4;
    case 0x801112C8u: goto label_801112C8;
    case 0x801112CCu: goto label_801112CC;
    case 0x801112D0u: goto label_801112D0;
    case 0x801112D4u: goto label_801112D4;
    case 0x801112D8u: goto label_801112D8;
    case 0x801112DCu: goto label_801112DC;
    case 0x801112E0u: goto label_801112E0;
    case 0x801112E4u: goto label_801112E4;
    case 0x801112E8u: goto label_801112E8;
    case 0x801112ECu: goto label_801112EC;
    case 0x801112F0u: goto label_801112F0;
    case 0x801112F4u: goto label_801112F4;
    case 0x801112F8u: goto label_801112F8;
    case 0x801112FCu: goto label_801112FC;
    case 0x80111300u: goto label_80111300;
    case 0x80111304u: goto label_80111304;
    case 0x80111308u: goto label_80111308;
    case 0x8011130Cu: goto label_8011130C;
    case 0x80111310u: goto label_80111310;
    case 0x80111314u: goto label_80111314;
    case 0x80111318u: goto label_80111318;
    case 0x8011131Cu: goto label_8011131C;
    case 0x80111320u: goto label_80111320;
    case 0x80111324u: goto label_80111324;
    case 0x80111328u: goto label_80111328;
    case 0x8011132Cu: goto label_8011132C;
    case 0x80111330u: goto label_80111330;
    case 0x80111334u: goto label_80111334;
    case 0x80111338u: goto label_80111338;
    case 0x8011133Cu: goto label_8011133C;
    case 0x80111340u: goto label_80111340;
    case 0x80111344u: goto label_80111344;
    case 0x80111348u: goto label_80111348;
    case 0x8011134Cu: goto label_8011134C;
    case 0x80111350u: goto label_80111350;
    case 0x80111354u: goto label_80111354;
    case 0x80111358u: goto label_80111358;
    case 0x8011135Cu: goto label_8011135C;
    case 0x80111360u: goto label_80111360;
    case 0x80111364u: goto label_80111364;
    case 0x80111368u: goto label_80111368;
    case 0x8011136Cu: goto label_8011136C;
    case 0x80111370u: goto label_80111370;
    case 0x80111374u: goto label_80111374;
    case 0x80111378u: goto label_80111378;
    case 0x8011137Cu: goto label_8011137C;
    case 0x80111380u: goto label_80111380;
    case 0x80111384u: goto label_80111384;
    case 0x80111388u: goto label_80111388;
    case 0x8011138Cu: goto label_8011138C;
    case 0x80111390u: goto label_80111390;
    case 0x80111394u: goto label_80111394;
    case 0x80111398u: goto label_80111398;
    case 0x8011139Cu: goto label_8011139C;
    case 0x801113A0u: goto label_801113A0;
    case 0x801113A4u: goto label_801113A4;
    case 0x801113A8u: goto label_801113A8;
    case 0x801113ACu: goto label_801113AC;
    case 0x801113B0u: goto label_801113B0;
    case 0x801113B4u: goto label_801113B4;
    case 0x801113B8u: goto label_801113B8;
    case 0x801113BCu: goto label_801113BC;
    case 0x801113C0u: goto label_801113C0;
    case 0x801113C4u: goto label_801113C4;
    case 0x801113C8u: goto label_801113C8;
    case 0x801113CCu: goto label_801113CC;
    case 0x801113D0u: goto label_801113D0;
    case 0x801113D4u: goto label_801113D4;
    case 0x801113D8u: goto label_801113D8;
    case 0x801113DCu: goto label_801113DC;
    case 0x801113E0u: goto label_801113E0;
    case 0x801113E4u: goto label_801113E4;
    case 0x801113E8u: goto label_801113E8;
    case 0x801113ECu: goto label_801113EC;
    case 0x801113F0u: goto label_801113F0;
    case 0x801113F4u: goto label_801113F4;
    case 0x801113F8u: goto label_801113F8;
    case 0x801113FCu: goto label_801113FC;
    case 0x80111400u: goto label_80111400;
    case 0x80111404u: goto label_80111404;
    case 0x80111408u: goto label_80111408;
    case 0x8011140Cu: goto label_8011140C;
    case 0x80111410u: goto label_80111410;
    case 0x80111414u: goto label_80111414;
    case 0x80111418u: goto label_80111418;
    case 0x8011141Cu: goto label_8011141C;
    case 0x80111420u: goto label_80111420;
    case 0x80111424u: goto label_80111424;
    case 0x80111428u: goto label_80111428;
    case 0x8011142Cu: goto label_8011142C;
    case 0x80111430u: goto label_80111430;
    case 0x80111434u: goto label_80111434;
    case 0x80111438u: goto label_80111438;
    case 0x8011143Cu: goto label_8011143C;
    case 0x80111440u: goto label_80111440;
    case 0x80111444u: goto label_80111444;
    case 0x80111448u: goto label_80111448;
    case 0x8011144Cu: goto label_8011144C;
    case 0x80111450u: goto label_80111450;
    case 0x80111454u: goto label_80111454;
    case 0x80111458u: goto label_80111458;
    case 0x8011145Cu: goto label_8011145C;
    case 0x80111460u: goto label_80111460;
    case 0x80111464u: goto label_80111464;
    case 0x80111468u: goto label_80111468;
    case 0x8011146Cu: goto label_8011146C;
    case 0x80111470u: goto label_80111470;
    case 0x80111474u: goto label_80111474;
    case 0x80111478u: goto label_80111478;
    case 0x8011147Cu: goto label_8011147C;
    case 0x80111480u: goto label_80111480;
    case 0x80111484u: goto label_80111484;
    case 0x80111488u: goto label_80111488;
    case 0x8011148Cu: goto label_8011148C;
    case 0x80111490u: goto label_80111490;
    case 0x80111494u: goto label_80111494;
    case 0x80111498u: goto label_80111498;
    case 0x8011149Cu: goto label_8011149C;
    case 0x801114A0u: goto label_801114A0;
    case 0x801114A4u: goto label_801114A4;
    case 0x801114A8u: goto label_801114A8;
    case 0x801114ACu: goto label_801114AC;
    case 0x801114B0u: goto label_801114B0;
    case 0x801114B4u: goto label_801114B4;
    case 0x801114B8u: goto label_801114B8;
    case 0x801114BCu: goto label_801114BC;
    case 0x801114C0u: goto label_801114C0;
    case 0x801114C4u: goto label_801114C4;
    case 0x801114C8u: goto label_801114C8;
    case 0x801114CCu: goto label_801114CC;
    case 0x801114D0u: goto label_801114D0;
    case 0x801114D4u: goto label_801114D4;
    case 0x801114D8u: goto label_801114D8;
    case 0x801114DCu: goto label_801114DC;
    case 0x801114E0u: goto label_801114E0;
    case 0x801114E4u: goto label_801114E4;
    case 0x801114E8u: goto label_801114E8;
    case 0x801114ECu: goto label_801114EC;
    case 0x801114F0u: goto label_801114F0;
    case 0x801114F4u: goto label_801114F4;
    case 0x801114F8u: goto label_801114F8;
    case 0x801114FCu: goto label_801114FC;
    case 0x80111500u: goto label_80111500;
    case 0x80111504u: goto label_80111504;
    case 0x80111508u: goto label_80111508;
    case 0x8011150Cu: goto label_8011150C;
    case 0x80111510u: goto label_80111510;
    case 0x80111514u: goto label_80111514;
    case 0x80111518u: goto label_80111518;
    case 0x8011151Cu: goto label_8011151C;
    case 0x80111520u: goto label_80111520;
    case 0x80111524u: goto label_80111524;
    case 0x80111528u: goto label_80111528;
    case 0x8011152Cu: goto label_8011152C;
    case 0x80111530u: goto label_80111530;
    case 0x80111534u: goto label_80111534;
    case 0x80111538u: goto label_80111538;
    case 0x8011153Cu: goto label_8011153C;
    case 0x80111540u: goto label_80111540;
    case 0x80111544u: goto label_80111544;
    case 0x80111548u: goto label_80111548;
    case 0x8011154Cu: goto label_8011154C;
    case 0x80111550u: goto label_80111550;
    case 0x80111554u: goto label_80111554;
    case 0x80111558u: goto label_80111558;
    case 0x8011155Cu: goto label_8011155C;
    case 0x80111560u: goto label_80111560;
    case 0x80111564u: goto label_80111564;
    case 0x80111568u: goto label_80111568;
    case 0x8011156Cu: goto label_8011156C;
    case 0x80111570u: goto label_80111570;
    case 0x80111574u: goto label_80111574;
    case 0x80111578u: goto label_80111578;
    case 0x8011157Cu: goto label_8011157C;
    case 0x80111580u: goto label_80111580;
    case 0x80111584u: goto label_80111584;
    case 0x80111588u: goto label_80111588;
    case 0x8011158Cu: goto label_8011158C;
    case 0x80111590u: goto label_80111590;
    case 0x80111594u: goto label_80111594;
    case 0x80111598u: goto label_80111598;
    case 0x8011159Cu: goto label_8011159C;
    case 0x801115A0u: goto label_801115A0;
    case 0x801115A4u: goto label_801115A4;
    case 0x801115A8u: goto label_801115A8;
    case 0x801115ACu: goto label_801115AC;
    case 0x801115B0u: goto label_801115B0;
    case 0x801115B4u: goto label_801115B4;
    case 0x801115B8u: goto label_801115B8;
    case 0x801115BCu: goto label_801115BC;
    case 0x801115C0u: goto label_801115C0;
    case 0x801115C4u: goto label_801115C4;
    case 0x801115C8u: goto label_801115C8;
    case 0x801115CCu: goto label_801115CC;
    case 0x801115D0u: goto label_801115D0;
    case 0x801115D4u: goto label_801115D4;
    case 0x801115D8u: goto label_801115D8;
    case 0x801115DCu: goto label_801115DC;
    case 0x801115E0u: goto label_801115E0;
    case 0x801115E4u: goto label_801115E4;
    case 0x801115E8u: goto label_801115E8;
    case 0x801115ECu: goto label_801115EC;
    case 0x801115F0u: goto label_801115F0;
    case 0x801115F4u: goto label_801115F4;
    case 0x801115F8u: goto label_801115F8;
    case 0x801115FCu: goto label_801115FC;
    case 0x80111600u: goto label_80111600;
    case 0x80111604u: goto label_80111604;
    case 0x80111608u: goto label_80111608;
    case 0x8011160Cu: goto label_8011160C;
    case 0x80111610u: goto label_80111610;
    case 0x80111614u: goto label_80111614;
    case 0x80111618u: goto label_80111618;
    case 0x8011161Cu: goto label_8011161C;
    case 0x80111620u: goto label_80111620;
    case 0x80111624u: goto label_80111624;
    case 0x80111628u: goto label_80111628;
    case 0x8011162Cu: goto label_8011162C;
    case 0x80111630u: goto label_80111630;
    case 0x80111634u: goto label_80111634;
    case 0x80111638u: goto label_80111638;
    case 0x8011163Cu: goto label_8011163C;
    case 0x80111640u: goto label_80111640;
    case 0x80111644u: goto label_80111644;
    case 0x80111648u: goto label_80111648;
    case 0x8011164Cu: goto label_8011164C;
    case 0x80111650u: goto label_80111650;
    case 0x80111654u: goto label_80111654;
    case 0x80111658u: goto label_80111658;
    case 0x8011165Cu: goto label_8011165C;
    case 0x80111660u: goto label_80111660;
    case 0x80111664u: goto label_80111664;
    case 0x80111668u: goto label_80111668;
    case 0x8011166Cu: goto label_8011166C;
    case 0x80111670u: goto label_80111670;
    case 0x80111674u: goto label_80111674;
    case 0x80111678u: goto label_80111678;
    case 0x8011167Cu: goto label_8011167C;
    case 0x80111680u: goto label_80111680;
    case 0x80111684u: goto label_80111684;
    case 0x80111688u: goto label_80111688;
    case 0x8011168Cu: goto label_8011168C;
    case 0x80111690u: goto label_80111690;
    case 0x80111694u: goto label_80111694;
    case 0x80111698u: goto label_80111698;
    case 0x8011169Cu: goto label_8011169C;
    case 0x801116A0u: goto label_801116A0;
    case 0x801116A4u: goto label_801116A4;
    case 0x801116A8u: goto label_801116A8;
    case 0x801116ACu: goto label_801116AC;
    case 0x801116B0u: goto label_801116B0;
    case 0x801116B4u: goto label_801116B4;
    case 0x801116B8u: goto label_801116B8;
    case 0x801116BCu: goto label_801116BC;
    case 0x801116C0u: goto label_801116C0;
    case 0x801116C4u: goto label_801116C4;
    case 0x801116C8u: goto label_801116C8;
    case 0x801116CCu: goto label_801116CC;
    case 0x801116D0u: goto label_801116D0;
    case 0x801116D4u: goto label_801116D4;
    case 0x801116D8u: goto label_801116D8;
    case 0x801116DCu: goto label_801116DC;
    case 0x801116E0u: goto label_801116E0;
    case 0x801116E4u: goto label_801116E4;
    case 0x801116E8u: goto label_801116E8;
    case 0x801116ECu: goto label_801116EC;
    case 0x801116F0u: goto label_801116F0;
    case 0x801116F4u: goto label_801116F4;
    case 0x801116F8u: goto label_801116F8;
    case 0x801116FCu: goto label_801116FC;
    case 0x80111700u: goto label_80111700;
    case 0x80111704u: goto label_80111704;
    case 0x80111708u: goto label_80111708;
    case 0x8011170Cu: goto label_8011170C;
    case 0x80111710u: goto label_80111710;
    case 0x80111714u: goto label_80111714;
    case 0x80111718u: goto label_80111718;
    case 0x8011171Cu: goto label_8011171C;
    case 0x80111720u: goto label_80111720;
    case 0x80111724u: goto label_80111724;
    case 0x80111728u: goto label_80111728;
    case 0x8011172Cu: goto label_8011172C;
    case 0x80111730u: goto label_80111730;
    case 0x80111734u: goto label_80111734;
    case 0x80111738u: goto label_80111738;
    case 0x8011173Cu: goto label_8011173C;
    case 0x80111740u: goto label_80111740;
    case 0x80111744u: goto label_80111744;
    case 0x80111748u: goto label_80111748;
    case 0x8011174Cu: goto label_8011174C;
    case 0x80111750u: goto label_80111750;
    case 0x80111754u: goto label_80111754;
    case 0x80111758u: goto label_80111758;
    case 0x8011175Cu: goto label_8011175C;
    case 0x80111760u: goto label_80111760;
    case 0x80111764u: goto label_80111764;
    case 0x80111768u: goto label_80111768;
    case 0x8011176Cu: goto label_8011176C;
    case 0x80111770u: goto label_80111770;
    case 0x80111774u: goto label_80111774;
    case 0x80111778u: goto label_80111778;
    case 0x8011177Cu: goto label_8011177C;
    case 0x80111780u: goto label_80111780;
    case 0x80111784u: goto label_80111784;
    case 0x80111788u: goto label_80111788;
    case 0x8011178Cu: goto label_8011178C;
    case 0x80111790u: goto label_80111790;
    case 0x80111794u: goto label_80111794;
    case 0x80111798u: goto label_80111798;
    case 0x8011179Cu: goto label_8011179C;
    case 0x801117A0u: goto label_801117A0;
    case 0x801117A4u: goto label_801117A4;
    case 0x801117A8u: goto label_801117A8;
    case 0x801117ACu: goto label_801117AC;
    case 0x801117B0u: goto label_801117B0;
    case 0x801117B4u: goto label_801117B4;
    case 0x801117B8u: goto label_801117B8;
    case 0x801117BCu: goto label_801117BC;
    case 0x801117C0u: goto label_801117C0;
    case 0x801117C4u: goto label_801117C4;
    case 0x801117C8u: goto label_801117C8;
    case 0x801117CCu: goto label_801117CC;
    case 0x801117D0u: goto label_801117D0;
    case 0x801117D4u: goto label_801117D4;
    case 0x801117D8u: goto label_801117D8;
    case 0x801117DCu: goto label_801117DC;
    case 0x801117E0u: goto label_801117E0;
    case 0x801117E4u: goto label_801117E4;
    case 0x801117E8u: goto label_801117E8;
    case 0x801117ECu: goto label_801117EC;
    case 0x801117F0u: goto label_801117F0;
    case 0x801117F4u: goto label_801117F4;
    case 0x801117F8u: goto label_801117F8;
    case 0x801117FCu: goto label_801117FC;
    case 0x80111800u: goto label_80111800;
    case 0x80111804u: goto label_80111804;
    case 0x80111808u: goto label_80111808;
    case 0x8011180Cu: goto label_8011180C;
    case 0x80111810u: goto label_80111810;
    case 0x80111814u: goto label_80111814;
    case 0x80111818u: goto label_80111818;
    case 0x8011181Cu: goto label_8011181C;
    case 0x80111820u: goto label_80111820;
    case 0x80111824u: goto label_80111824;
    case 0x80111828u: goto label_80111828;
    case 0x8011182Cu: goto label_8011182C;
    case 0x80111830u: goto label_80111830;
    case 0x80111834u: goto label_80111834;
    case 0x80111838u: goto label_80111838;
    case 0x8011183Cu: goto label_8011183C;
    case 0x80111840u: goto label_80111840;
    case 0x80111844u: goto label_80111844;
    case 0x80111848u: goto label_80111848;
    case 0x8011184Cu: goto label_8011184C;
    case 0x80111850u: goto label_80111850;
    case 0x80111854u: goto label_80111854;
    case 0x80111858u: goto label_80111858;
    case 0x8011185Cu: goto label_8011185C;
    case 0x80111860u: goto label_80111860;
    case 0x80111864u: goto label_80111864;
    case 0x80111868u: goto label_80111868;
    case 0x8011186Cu: goto label_8011186C;
    case 0x80111870u: goto label_80111870;
    case 0x80111874u: goto label_80111874;
    case 0x80111878u: goto label_80111878;
    case 0x8011187Cu: goto label_8011187C;
    case 0x80111880u: goto label_80111880;
    case 0x80111884u: goto label_80111884;
    case 0x80111888u: goto label_80111888;
    case 0x8011188Cu: goto label_8011188C;
    case 0x80111890u: goto label_80111890;
    case 0x80111894u: goto label_80111894;
    case 0x80111898u: goto label_80111898;
    case 0x8011189Cu: goto label_8011189C;
    case 0x801118A0u: goto label_801118A0;
    case 0x801118A4u: goto label_801118A4;
    case 0x801118A8u: goto label_801118A8;
    case 0x801118ACu: goto label_801118AC;
    case 0x801118B0u: goto label_801118B0;
    case 0x801118B4u: goto label_801118B4;
    case 0x801118B8u: goto label_801118B8;
    case 0x801118BCu: goto label_801118BC;
    case 0x801118C0u: goto label_801118C0;
    case 0x801118C4u: goto label_801118C4;
    case 0x801118C8u: goto label_801118C8;
    case 0x801118CCu: goto label_801118CC;
    case 0x801118D0u: goto label_801118D0;
    case 0x801118D4u: goto label_801118D4;
    case 0x801118D8u: goto label_801118D8;
    case 0x801118DCu: goto label_801118DC;
    case 0x801118E0u: goto label_801118E0;
    case 0x801118E4u: goto label_801118E4;
    case 0x801118E8u: goto label_801118E8;
    case 0x801118ECu: goto label_801118EC;
    case 0x801118F0u: goto label_801118F0;
    case 0x801118F4u: goto label_801118F4;
    case 0x801118F8u: goto label_801118F8;
    case 0x801118FCu: goto label_801118FC;
    case 0x80111900u: goto label_80111900;
    case 0x80111904u: goto label_80111904;
    case 0x80111908u: goto label_80111908;
    case 0x8011190Cu: goto label_8011190C;
    case 0x80111910u: goto label_80111910;
    case 0x80111914u: goto label_80111914;
    case 0x80111918u: goto label_80111918;
    case 0x8011191Cu: goto label_8011191C;
    case 0x80111920u: goto label_80111920;
    case 0x80111924u: goto label_80111924;
    case 0x80111928u: goto label_80111928;
    case 0x8011192Cu: goto label_8011192C;
    case 0x80111930u: goto label_80111930;
    case 0x80111934u: goto label_80111934;
    case 0x80111938u: goto label_80111938;
    case 0x8011193Cu: goto label_8011193C;
    case 0x80111940u: goto label_80111940;
    case 0x80111944u: goto label_80111944;
    case 0x80111948u: goto label_80111948;
    case 0x8011194Cu: goto label_8011194C;
    case 0x80111950u: goto label_80111950;
    case 0x80111954u: goto label_80111954;
    case 0x80111958u: goto label_80111958;
    case 0x8011195Cu: goto label_8011195C;
    case 0x80111960u: goto label_80111960;
    case 0x80111964u: goto label_80111964;
    case 0x80111968u: goto label_80111968;
    case 0x8011196Cu: goto label_8011196C;
    case 0x80111970u: goto label_80111970;
    case 0x80111974u: goto label_80111974;
    case 0x80111978u: goto label_80111978;
    case 0x8011197Cu: goto label_8011197C;
    case 0x80111980u: goto label_80111980;
    case 0x80111984u: goto label_80111984;
    case 0x80111988u: goto label_80111988;
    case 0x8011198Cu: goto label_8011198C;
    case 0x80111990u: goto label_80111990;
    case 0x80111994u: goto label_80111994;
    case 0x80111998u: goto label_80111998;
    case 0x8011199Cu: goto label_8011199C;
    case 0x801119A0u: goto label_801119A0;
    case 0x801119A4u: goto label_801119A4;
    case 0x801119A8u: goto label_801119A8;
    case 0x801119ACu: goto label_801119AC;
    case 0x801119B0u: goto label_801119B0;
    case 0x801119B4u: goto label_801119B4;
    case 0x801119B8u: goto label_801119B8;
    case 0x801119BCu: goto label_801119BC;
    case 0x801119C0u: goto label_801119C0;
    case 0x801119C4u: goto label_801119C4;
    case 0x801119C8u: goto label_801119C8;
    case 0x801119CCu: goto label_801119CC;
    case 0x801119D0u: goto label_801119D0;
    case 0x801119D4u: goto label_801119D4;
    case 0x801119D8u: goto label_801119D8;
    case 0x801119DCu: goto label_801119DC;
    case 0x801119E0u: goto label_801119E0;
    case 0x801119E4u: goto label_801119E4;
    case 0x801119E8u: goto label_801119E8;
    case 0x801119ECu: goto label_801119EC;
    case 0x801119F0u: goto label_801119F0;
    case 0x801119F4u: goto label_801119F4;
    case 0x801119F8u: goto label_801119F8;
    case 0x801119FCu: goto label_801119FC;
    case 0x80111A00u: goto label_80111A00;
    case 0x80111A04u: goto label_80111A04;
    case 0x80111A08u: goto label_80111A08;
    case 0x80111A0Cu: goto label_80111A0C;
    case 0x80111A10u: goto label_80111A10;
    case 0x80111A14u: goto label_80111A14;
    case 0x80111A18u: goto label_80111A18;
    case 0x80111A1Cu: goto label_80111A1C;
    case 0x80111A20u: goto label_80111A20;
    case 0x80111A24u: goto label_80111A24;
    case 0x80111A28u: goto label_80111A28;
    case 0x80111A2Cu: goto label_80111A2C;
    case 0x80111A30u: goto label_80111A30;
    case 0x80111A34u: goto label_80111A34;
    case 0x80111A38u: goto label_80111A38;
    case 0x80111A3Cu: goto label_80111A3C;
    case 0x80111A40u: goto label_80111A40;
    case 0x80111A44u: goto label_80111A44;
    case 0x80111A48u: goto label_80111A48;
    case 0x80111A4Cu: goto label_80111A4C;
    case 0x80111A50u: goto label_80111A50;
    case 0x80111A54u: goto label_80111A54;
    case 0x80111A58u: goto label_80111A58;
    case 0x80111A5Cu: goto label_80111A5C;
    case 0x80111A60u: goto label_80111A60;
    case 0x80111A64u: goto label_80111A64;
    case 0x80111A68u: goto label_80111A68;
    case 0x80111A6Cu: goto label_80111A6C;
    case 0x80111A70u: goto label_80111A70;
    case 0x80111A74u: goto label_80111A74;
    case 0x80111A78u: goto label_80111A78;
    case 0x80111A7Cu: goto label_80111A7C;
    case 0x80111A80u: goto label_80111A80;
    case 0x80111A84u: goto label_80111A84;
    case 0x80111A88u: goto label_80111A88;
    case 0x80111A8Cu: goto label_80111A8C;
    case 0x80111A90u: goto label_80111A90;
    case 0x80111A94u: goto label_80111A94;
    case 0x80111A98u: goto label_80111A98;
    case 0x80111A9Cu: goto label_80111A9C;
    case 0x80111AA0u: goto label_80111AA0;
    case 0x80111AA4u: goto label_80111AA4;
    case 0x80111AA8u: goto label_80111AA8;
    case 0x80111AACu: goto label_80111AAC;
    case 0x80111AB0u: goto label_80111AB0;
    case 0x80111AB4u: goto label_80111AB4;
    case 0x80111AB8u: goto label_80111AB8;
    case 0x80111ABCu: goto label_80111ABC;
    case 0x80111AC0u: goto label_80111AC0;
    case 0x80111AC4u: goto label_80111AC4;
    case 0x80111AC8u: goto label_80111AC8;
    case 0x80111ACCu: goto label_80111ACC;
    case 0x80111AD0u: goto label_80111AD0;
    case 0x80111AD4u: goto label_80111AD4;
    case 0x80111AD8u: goto label_80111AD8;
    case 0x80111ADCu: goto label_80111ADC;
    case 0x80111AE0u: goto label_80111AE0;
    case 0x80111AE4u: goto label_80111AE4;
    case 0x80111AE8u: goto label_80111AE8;
    case 0x80111AECu: goto label_80111AEC;
    case 0x80111AF0u: goto label_80111AF0;
    case 0x80111AF4u: goto label_80111AF4;
    case 0x80111AF8u: goto label_80111AF8;
    case 0x80111AFCu: goto label_80111AFC;
    case 0x80111B00u: goto label_80111B00;
    case 0x80111B04u: goto label_80111B04;
    case 0x80111B08u: goto label_80111B08;
    case 0x80111B0Cu: goto label_80111B0C;
    case 0x80111B10u: goto label_80111B10;
    case 0x80111B14u: goto label_80111B14;
    case 0x80111B18u: goto label_80111B18;
    case 0x80111B1Cu: goto label_80111B1C;
    case 0x80111B20u: goto label_80111B20;
    case 0x80111B24u: goto label_80111B24;
    case 0x80111B28u: goto label_80111B28;
    case 0x80111B2Cu: goto label_80111B2C;
    case 0x80111B30u: goto label_80111B30;
    case 0x80111B34u: goto label_80111B34;
    case 0x80111B38u: goto label_80111B38;
    case 0x80111B3Cu: goto label_80111B3C;
    case 0x80111B40u: goto label_80111B40;
    case 0x80111B44u: goto label_80111B44;
    case 0x80111B48u: goto label_80111B48;
    case 0x80111B4Cu: goto label_80111B4C;
    case 0x80111B50u: goto label_80111B50;
    case 0x80111B54u: goto label_80111B54;
    case 0x80111B58u: goto label_80111B58;
    case 0x80111B5Cu: goto label_80111B5C;
    case 0x80111B60u: goto label_80111B60;
    case 0x80111B64u: goto label_80111B64;
    case 0x80111B68u: goto label_80111B68;
    case 0x80111B6Cu: goto label_80111B6C;
    case 0x80111B70u: goto label_80111B70;
    case 0x80111B74u: goto label_80111B74;
    case 0x80111B78u: goto label_80111B78;
    case 0x80111B7Cu: goto label_80111B7C;
    case 0x80111B80u: goto label_80111B80;
    case 0x80111B84u: goto label_80111B84;
    case 0x80111B88u: goto label_80111B88;
    case 0x80111B8Cu: goto label_80111B8C;
    case 0x80111B90u: goto label_80111B90;
    case 0x80111B94u: goto label_80111B94;
    case 0x80111B98u: goto label_80111B98;
    case 0x80111B9Cu: goto label_80111B9C;
    case 0x80111BA0u: goto label_80111BA0;
    case 0x80111BA4u: goto label_80111BA4;
    case 0x80111BA8u: goto label_80111BA8;
    case 0x80111BACu: goto label_80111BAC;
    case 0x80111BB0u: goto label_80111BB0;
    case 0x80111BB4u: goto label_80111BB4;
    case 0x80111BB8u: goto label_80111BB8;
    case 0x80111BBCu: goto label_80111BBC;
    case 0x80111BC0u: goto label_80111BC0;
    case 0x80111BC4u: goto label_80111BC4;
    case 0x80111BC8u: goto label_80111BC8;
    case 0x80111BCCu: goto label_80111BCC;
    case 0x80111BD0u: goto label_80111BD0;
    case 0x80111BD4u: goto label_80111BD4;
    case 0x80111BD8u: goto label_80111BD8;
    case 0x80111BDCu: goto label_80111BDC;
    case 0x80111BE0u: goto label_80111BE0;
    case 0x80111BE4u: goto label_80111BE4;
    case 0x80111BE8u: goto label_80111BE8;
    case 0x80111BECu: goto label_80111BEC;
    case 0x80111BF0u: goto label_80111BF0;
    case 0x80111BF4u: goto label_80111BF4;
    case 0x80111BF8u: goto label_80111BF8;
    case 0x80111BFCu: goto label_80111BFC;
    case 0x80111C00u: goto label_80111C00;
    case 0x80111C04u: goto label_80111C04;
    case 0x80111C08u: goto label_80111C08;
    case 0x80111C0Cu: goto label_80111C0C;
    case 0x80111C10u: goto label_80111C10;
    case 0x80111C14u: goto label_80111C14;
    case 0x80111C18u: goto label_80111C18;
    case 0x80111C1Cu: goto label_80111C1C;
    case 0x80111C20u: goto label_80111C20;
    case 0x80111C24u: goto label_80111C24;
    case 0x80111C28u: goto label_80111C28;
    case 0x80111C2Cu: goto label_80111C2C;
    case 0x80111C30u: goto label_80111C30;
    case 0x80111C34u: goto label_80111C34;
    case 0x80111C38u: goto label_80111C38;
    case 0x80111C3Cu: goto label_80111C3C;
    case 0x80111C40u: goto label_80111C40;
    case 0x80111C44u: goto label_80111C44;
    case 0x80111C48u: goto label_80111C48;
    case 0x80111C4Cu: goto label_80111C4C;
    case 0x80111C50u: goto label_80111C50;
    case 0x80111C54u: goto label_80111C54;
    case 0x80111C58u: goto label_80111C58;
    case 0x80111C5Cu: goto label_80111C5C;
    case 0x80111C60u: goto label_80111C60;
    case 0x80111C64u: goto label_80111C64;
    case 0x80111C68u: goto label_80111C68;
    case 0x80111C6Cu: goto label_80111C6C;
    case 0x80111C70u: goto label_80111C70;
    case 0x80111C74u: goto label_80111C74;
    case 0x80111C78u: goto label_80111C78;
    case 0x80111C7Cu: goto label_80111C7C;
    case 0x80111C80u: goto label_80111C80;
    case 0x80111C84u: goto label_80111C84;
    case 0x80111C88u: goto label_80111C88;
    case 0x80111C8Cu: goto label_80111C8C;
    case 0x80111C90u: goto label_80111C90;
    case 0x80111C94u: goto label_80111C94;
    case 0x80111C98u: goto label_80111C98;
    case 0x80111C9Cu: goto label_80111C9C;
    case 0x80111CA0u: goto label_80111CA0;
    case 0x80111CA4u: goto label_80111CA4;
    case 0x80111CA8u: goto label_80111CA8;
    case 0x80111CACu: goto label_80111CAC;
    case 0x80111CB0u: goto label_80111CB0;
    case 0x80111CB4u: goto label_80111CB4;
    case 0x80111CB8u: goto label_80111CB8;
    case 0x80111CBCu: goto label_80111CBC;
    case 0x80111CC0u: goto label_80111CC0;
    case 0x80111CC4u: goto label_80111CC4;
    case 0x80111CC8u: goto label_80111CC8;
    case 0x80111CCCu: goto label_80111CCC;
    case 0x80111CD0u: goto label_80111CD0;
    case 0x80111CD4u: goto label_80111CD4;
    case 0x80111CD8u: goto label_80111CD8;
    case 0x80111CDCu: goto label_80111CDC;
    case 0x80111CE0u: goto label_80111CE0;
    case 0x80111CE4u: goto label_80111CE4;
    case 0x80111CE8u: goto label_80111CE8;
    case 0x80111CECu: goto label_80111CEC;
    case 0x80111CF0u: goto label_80111CF0;
    case 0x80111CF4u: goto label_80111CF4;
    case 0x80111CF8u: goto label_80111CF8;
    case 0x80111CFCu: goto label_80111CFC;
    case 0x80111D00u: goto label_80111D00;
    case 0x80111D04u: goto label_80111D04;
    case 0x80111D08u: goto label_80111D08;
    case 0x80111D0Cu: goto label_80111D0C;
    case 0x80111D10u: goto label_80111D10;
    case 0x80111D14u: goto label_80111D14;
    case 0x80111D18u: goto label_80111D18;
    case 0x80111D1Cu: goto label_80111D1C;
    case 0x80111D20u: goto label_80111D20;
    case 0x80111D24u: goto label_80111D24;
    case 0x80111D28u: goto label_80111D28;
    case 0x80111D2Cu: goto label_80111D2C;
    case 0x80111D30u: goto label_80111D30;
    case 0x80111D34u: goto label_80111D34;
    case 0x80111D38u: goto label_80111D38;
    case 0x80111D3Cu: goto label_80111D3C;
    case 0x80111D40u: goto label_80111D40;
    case 0x80111D44u: goto label_80111D44;
    case 0x80111D48u: goto label_80111D48;
    case 0x80111D4Cu: goto label_80111D4C;
    case 0x80111D50u: goto label_80111D50;
    case 0x80111D54u: goto label_80111D54;
    case 0x80111D58u: goto label_80111D58;
    case 0x80111D5Cu: goto label_80111D5C;
    case 0x80111D60u: goto label_80111D60;
    case 0x80111D64u: goto label_80111D64;
    case 0x80111D68u: goto label_80111D68;
    case 0x80111D6Cu: goto label_80111D6C;
    case 0x80111D70u: goto label_80111D70;
    case 0x80111D74u: goto label_80111D74;
    case 0x80111D78u: goto label_80111D78;
    case 0x80111D7Cu: goto label_80111D7C;
    case 0x80111D80u: goto label_80111D80;
    case 0x80111D84u: goto label_80111D84;
    case 0x80111D88u: goto label_80111D88;
    case 0x80111D8Cu: goto label_80111D8C;
    case 0x80111D90u: goto label_80111D90;
    case 0x80111D94u: goto label_80111D94;
    case 0x80111D98u: goto label_80111D98;
    case 0x80111D9Cu: goto label_80111D9C;
    case 0x80111DA0u: goto label_80111DA0;
    case 0x80111DA4u: goto label_80111DA4;
    case 0x80111DA8u: goto label_80111DA8;
    case 0x80111DACu: goto label_80111DAC;
    case 0x80111DB0u: goto label_80111DB0;
    case 0x80111DB4u: goto label_80111DB4;
    case 0x80111DB8u: goto label_80111DB8;
    case 0x80111DBCu: goto label_80111DBC;
    case 0x80111DC0u: goto label_80111DC0;
    case 0x80111DC4u: goto label_80111DC4;
    case 0x80111DC8u: goto label_80111DC8;
    case 0x80111DCCu: goto label_80111DCC;
    case 0x80111DD0u: goto label_80111DD0;
    case 0x80111DD4u: goto label_80111DD4;
    case 0x80111DD8u: goto label_80111DD8;
    case 0x80111DDCu: goto label_80111DDC;
    case 0x80111DE0u: goto label_80111DE0;
    case 0x80111DE4u: goto label_80111DE4;
    case 0x80111DE8u: goto label_80111DE8;
    case 0x80111DECu: goto label_80111DEC;
    case 0x80111DF0u: goto label_80111DF0;
    case 0x80111DF4u: goto label_80111DF4;
    case 0x80111DF8u: goto label_80111DF8;
    case 0x80111DFCu: goto label_80111DFC;
    case 0x80111E00u: goto label_80111E00;
    case 0x80111E04u: goto label_80111E04;
    case 0x80111E08u: goto label_80111E08;
    case 0x80111E0Cu: goto label_80111E0C;
    case 0x80111E10u: goto label_80111E10;
    case 0x80111E14u: goto label_80111E14;
    case 0x80111E18u: goto label_80111E18;
    case 0x80111E1Cu: goto label_80111E1C;
    case 0x80111E20u: goto label_80111E20;
    case 0x80111E24u: goto label_80111E24;
    case 0x80111E28u: goto label_80111E28;
    case 0x80111E2Cu: goto label_80111E2C;
    case 0x80111E30u: goto label_80111E30;
    case 0x80111E34u: goto label_80111E34;
    case 0x80111E38u: goto label_80111E38;
    case 0x80111E3Cu: goto label_80111E3C;
    case 0x80111E40u: goto label_80111E40;
    case 0x80111E44u: goto label_80111E44;
    case 0x80111E48u: goto label_80111E48;
    case 0x80111E4Cu: goto label_80111E4C;
    case 0x80111E50u: goto label_80111E50;
    case 0x80111E54u: goto label_80111E54;
    case 0x80111E58u: goto label_80111E58;
    case 0x80111E5Cu: goto label_80111E5C;
    case 0x80111E60u: goto label_80111E60;
    case 0x80111E64u: goto label_80111E64;
    case 0x80111E68u: goto label_80111E68;
    case 0x80111E6Cu: goto label_80111E6C;
    case 0x80111E70u: goto label_80111E70;
    case 0x80111E74u: goto label_80111E74;
    case 0x80111E78u: goto label_80111E78;
    case 0x80111E7Cu: goto label_80111E7C;
    case 0x80111E80u: goto label_80111E80;
    case 0x80111E84u: goto label_80111E84;
    case 0x80111E88u: goto label_80111E88;
    case 0x80111E8Cu: goto label_80111E8C;
    case 0x80111E90u: goto label_80111E90;
    case 0x80111E94u: goto label_80111E94;
    case 0x80111E98u: goto label_80111E98;
    case 0x80111E9Cu: goto label_80111E9C;
    case 0x80111EA0u: goto label_80111EA0;
    case 0x80111EA4u: goto label_80111EA4;
    case 0x80111EA8u: goto label_80111EA8;
    case 0x80111EACu: goto label_80111EAC;
    case 0x80111EB0u: goto label_80111EB0;
    case 0x80111EB4u: goto label_80111EB4;
    case 0x80111EB8u: goto label_80111EB8;
    case 0x80111EBCu: goto label_80111EBC;
    case 0x80111EC0u: goto label_80111EC0;
    case 0x80111EC4u: goto label_80111EC4;
    case 0x80111EC8u: goto label_80111EC8;
    case 0x80111ECCu: goto label_80111ECC;
    case 0x80111ED0u: goto label_80111ED0;
    case 0x80111ED4u: goto label_80111ED4;
    case 0x80111ED8u: goto label_80111ED8;
    case 0x80111EDCu: goto label_80111EDC;
    case 0x80111EE0u: goto label_80111EE0;
    case 0x80111EE4u: goto label_80111EE4;
    case 0x80111EE8u: goto label_80111EE8;
    case 0x80111EECu: goto label_80111EEC;
    case 0x80111EF0u: goto label_80111EF0;
    case 0x80111EF4u: goto label_80111EF4;
    case 0x80111EF8u: goto label_80111EF8;
    case 0x80111EFCu: goto label_80111EFC;
    case 0x80111F00u: goto label_80111F00;
    case 0x80111F04u: goto label_80111F04;
    case 0x80111F08u: goto label_80111F08;
    case 0x80111F0Cu: goto label_80111F0C;
    case 0x80111F10u: goto label_80111F10;
    case 0x80111F14u: goto label_80111F14;
    case 0x80111F18u: goto label_80111F18;
    case 0x80111F1Cu: goto label_80111F1C;
    case 0x80111F20u: goto label_80111F20;
    case 0x80111F24u: goto label_80111F24;
    case 0x80111F28u: goto label_80111F28;
    case 0x80111F2Cu: goto label_80111F2C;
    case 0x80111F30u: goto label_80111F30;
    case 0x80111F34u: goto label_80111F34;
    case 0x80111F38u: goto label_80111F38;
    case 0x80111F3Cu: goto label_80111F3C;
    case 0x80111F40u: goto label_80111F40;
    case 0x80111F44u: goto label_80111F44;
    case 0x80111F48u: goto label_80111F48;
    case 0x80111F4Cu: goto label_80111F4C;
    case 0x80111F50u: goto label_80111F50;
    case 0x80111F54u: goto label_80111F54;
    case 0x80111F58u: goto label_80111F58;
    case 0x80111F5Cu: goto label_80111F5C;
    case 0x80111F60u: goto label_80111F60;
    case 0x80111F64u: goto label_80111F64;
    case 0x80111F68u: goto label_80111F68;
    case 0x80111F6Cu: goto label_80111F6C;
    case 0x80111F70u: goto label_80111F70;
    case 0x80111F74u: goto label_80111F74;
    case 0x80111F78u: goto label_80111F78;
    case 0x80111F7Cu: goto label_80111F7C;
    case 0x80111F80u: goto label_80111F80;
    case 0x80111F84u: goto label_80111F84;
    case 0x80111F88u: goto label_80111F88;
    case 0x80111F8Cu: goto label_80111F8C;
    case 0x80111F90u: goto label_80111F90;
    case 0x80111F94u: goto label_80111F94;
    case 0x80111F98u: goto label_80111F98;
    case 0x80111F9Cu: goto label_80111F9C;
    case 0x80111FA0u: goto label_80111FA0;
    case 0x80111FA4u: goto label_80111FA4;
    case 0x80111FA8u: goto label_80111FA8;
    case 0x80111FACu: goto label_80111FAC;
    case 0x80111FB0u: goto label_80111FB0;
    case 0x80111FB4u: goto label_80111FB4;
    case 0x80111FB8u: goto label_80111FB8;
    case 0x80111FBCu: goto label_80111FBC;
    case 0x80111FC0u: goto label_80111FC0;
    case 0x80111FC4u: goto label_80111FC4;
    case 0x80111FC8u: goto label_80111FC8;
    case 0x80111FCCu: goto label_80111FCC;
    case 0x80111FD0u: goto label_80111FD0;
    case 0x80111FD4u: goto label_80111FD4;
    case 0x80111FD8u: goto label_80111FD8;
    case 0x80111FDCu: goto label_80111FDC;
    case 0x80111FE0u: goto label_80111FE0;
    case 0x80111FE4u: goto label_80111FE4;
    case 0x80111FE8u: goto label_80111FE8;
    case 0x80111FECu: goto label_80111FEC;
    case 0x80111FF0u: goto label_80111FF0;
    case 0x80111FF4u: goto label_80111FF4;
    case 0x80111FF8u: goto label_80111FF8;
    case 0x80111FFCu: goto label_80111FFC;
    case 0x80112000u: goto label_80112000;
    case 0x80112004u: goto label_80112004;
    case 0x80112008u: goto label_80112008;
    case 0x8011200Cu: goto label_8011200C;
    case 0x80112010u: goto label_80112010;
    case 0x80112014u: goto label_80112014;
    case 0x80112018u: goto label_80112018;
    case 0x8011201Cu: goto label_8011201C;
    case 0x80112020u: goto label_80112020;
    case 0x80112024u: goto label_80112024;
    case 0x80112028u: goto label_80112028;
    case 0x8011202Cu: goto label_8011202C;
    case 0x80112030u: goto label_80112030;
    case 0x80112034u: goto label_80112034;
    case 0x80112038u: goto label_80112038;
    case 0x8011203Cu: goto label_8011203C;
    case 0x80112040u: goto label_80112040;
    case 0x80112044u: goto label_80112044;
    case 0x80112048u: goto label_80112048;
    case 0x8011204Cu: goto label_8011204C;
    case 0x80112050u: goto label_80112050;
    case 0x80112054u: goto label_80112054;
    case 0x80112058u: goto label_80112058;
    case 0x8011205Cu: goto label_8011205C;
    case 0x80112060u: goto label_80112060;
    case 0x80112064u: goto label_80112064;
    case 0x80112068u: goto label_80112068;
    case 0x8011206Cu: goto label_8011206C;
    case 0x80112070u: goto label_80112070;
    case 0x80112074u: goto label_80112074;
    case 0x80112078u: goto label_80112078;
    case 0x8011207Cu: goto label_8011207C;
    case 0x80112080u: goto label_80112080;
    case 0x80112084u: goto label_80112084;
    case 0x80112088u: goto label_80112088;
    case 0x8011208Cu: goto label_8011208C;
    case 0x80112090u: goto label_80112090;
    case 0x80112094u: goto label_80112094;
    case 0x80112098u: goto label_80112098;
    case 0x8011209Cu: goto label_8011209C;
    case 0x801120A0u: goto label_801120A0;
    case 0x801120A4u: goto label_801120A4;
    case 0x801120A8u: goto label_801120A8;
    case 0x801120ACu: goto label_801120AC;
    case 0x801120B0u: goto label_801120B0;
    case 0x801120B4u: goto label_801120B4;
    case 0x801120B8u: goto label_801120B8;
    case 0x801120BCu: goto label_801120BC;
    case 0x801120C0u: goto label_801120C0;
    case 0x801120C4u: goto label_801120C4;
    case 0x801120C8u: goto label_801120C8;
    case 0x801120CCu: goto label_801120CC;
    case 0x801120D0u: goto label_801120D0;
    case 0x801120D4u: goto label_801120D4;
    case 0x801120D8u: goto label_801120D8;
    case 0x801120DCu: goto label_801120DC;
    case 0x801120E0u: goto label_801120E0;
    case 0x801120E4u: goto label_801120E4;
    case 0x801120E8u: goto label_801120E8;
    case 0x801120ECu: goto label_801120EC;
    case 0x801120F0u: goto label_801120F0;
    case 0x801120F4u: goto label_801120F4;
    case 0x801120F8u: goto label_801120F8;
    case 0x801120FCu: goto label_801120FC;
    case 0x80112100u: goto label_80112100;
    case 0x80112104u: goto label_80112104;
    case 0x80112108u: goto label_80112108;
    case 0x8011210Cu: goto label_8011210C;
    case 0x80112110u: goto label_80112110;
    case 0x80112114u: goto label_80112114;
    case 0x80112118u: goto label_80112118;
    case 0x8011211Cu: goto label_8011211C;
    case 0x80112120u: goto label_80112120;
    case 0x80112124u: goto label_80112124;
    case 0x80112128u: goto label_80112128;
    case 0x8011212Cu: goto label_8011212C;
    case 0x80112130u: goto label_80112130;
    case 0x80112134u: goto label_80112134;
    case 0x80112138u: goto label_80112138;
    case 0x8011213Cu: goto label_8011213C;
    case 0x80112140u: goto label_80112140;
    case 0x80112144u: goto label_80112144;
    case 0x80112148u: goto label_80112148;
    case 0x8011214Cu: goto label_8011214C;
    case 0x80112150u: goto label_80112150;
    case 0x80112154u: goto label_80112154;
    case 0x80112158u: goto label_80112158;
    case 0x8011215Cu: goto label_8011215C;
    case 0x80112160u: goto label_80112160;
    case 0x80112164u: goto label_80112164;
    case 0x80112168u: goto label_80112168;
    case 0x8011216Cu: goto label_8011216C;
    case 0x80112170u: goto label_80112170;
    case 0x80112174u: goto label_80112174;
    case 0x80112178u: goto label_80112178;
    case 0x8011217Cu: goto label_8011217C;
    case 0x80112180u: goto label_80112180;
    case 0x80112184u: goto label_80112184;
    case 0x80112188u: goto label_80112188;
    case 0x8011218Cu: goto label_8011218C;
    case 0x80112190u: goto label_80112190;
    case 0x80112194u: goto label_80112194;
    case 0x80112198u: goto label_80112198;
    case 0x8011219Cu: goto label_8011219C;
    case 0x801121A0u: goto label_801121A0;
    case 0x801121A4u: goto label_801121A4;
    case 0x801121A8u: goto label_801121A8;
    case 0x801121ACu: goto label_801121AC;
    case 0x801121B0u: goto label_801121B0;
    case 0x801121B4u: goto label_801121B4;
    case 0x801121B8u: goto label_801121B8;
    case 0x801121BCu: goto label_801121BC;
    case 0x801121C0u: goto label_801121C0;
    case 0x801121C4u: goto label_801121C4;
    case 0x801121C8u: goto label_801121C8;
    case 0x801121CCu: goto label_801121CC;
    case 0x801121D0u: goto label_801121D0;
    case 0x801121D4u: goto label_801121D4;
    case 0x801121D8u: goto label_801121D8;
    case 0x801121DCu: goto label_801121DC;
    case 0x801121E0u: goto label_801121E0;
    case 0x801121E4u: goto label_801121E4;
    case 0x801121E8u: goto label_801121E8;
    case 0x801121ECu: goto label_801121EC;
    case 0x801121F0u: goto label_801121F0;
    case 0x801121F4u: goto label_801121F4;
    case 0x801121F8u: goto label_801121F8;
    case 0x801121FCu: goto label_801121FC;
    case 0x80112200u: goto label_80112200;
    case 0x80112204u: goto label_80112204;
    case 0x80112208u: goto label_80112208;
    case 0x8011220Cu: goto label_8011220C;
    case 0x80112210u: goto label_80112210;
    case 0x80112214u: goto label_80112214;
    case 0x80112218u: goto label_80112218;
    case 0x8011221Cu: goto label_8011221C;
    case 0x80112220u: goto label_80112220;
    case 0x80112224u: goto label_80112224;
    case 0x80112228u: goto label_80112228;
    case 0x8011222Cu: goto label_8011222C;
    case 0x80112230u: goto label_80112230;
    case 0x80112234u: goto label_80112234;
    case 0x80112238u: goto label_80112238;
    case 0x8011223Cu: goto label_8011223C;
    case 0x80112240u: goto label_80112240;
    case 0x80112244u: goto label_80112244;
    case 0x80112248u: goto label_80112248;
    case 0x8011224Cu: goto label_8011224C;
    case 0x80112250u: goto label_80112250;
    case 0x80112254u: goto label_80112254;
    case 0x80112258u: goto label_80112258;
    case 0x8011225Cu: goto label_8011225C;
    case 0x80112260u: goto label_80112260;
    case 0x80112264u: goto label_80112264;
    case 0x80112268u: goto label_80112268;
    case 0x8011226Cu: goto label_8011226C;
    case 0x80112270u: goto label_80112270;
    case 0x80112274u: goto label_80112274;
    case 0x80112278u: goto label_80112278;
    case 0x8011227Cu: goto label_8011227C;
    case 0x80112280u: goto label_80112280;
    case 0x80112284u: goto label_80112284;
    case 0x80112288u: goto label_80112288;
    case 0x8011228Cu: goto label_8011228C;
    case 0x80112290u: goto label_80112290;
    case 0x80112294u: goto label_80112294;
    case 0x80112298u: goto label_80112298;
    case 0x8011229Cu: goto label_8011229C;
    case 0x801122A0u: goto label_801122A0;
    case 0x801122A4u: goto label_801122A4;
    case 0x801122A8u: goto label_801122A8;
    case 0x801122ACu: goto label_801122AC;
    case 0x801122B0u: goto label_801122B0;
    case 0x801122B4u: goto label_801122B4;
    case 0x801122B8u: goto label_801122B8;
    case 0x801122BCu: goto label_801122BC;
    case 0x801122C0u: goto label_801122C0;
    case 0x801122C4u: goto label_801122C4;
    case 0x801122C8u: goto label_801122C8;
    case 0x801122CCu: goto label_801122CC;
    case 0x801122D0u: goto label_801122D0;
    case 0x801122D4u: goto label_801122D4;
    case 0x801122D8u: goto label_801122D8;
    case 0x801122DCu: goto label_801122DC;
    case 0x801122E0u: goto label_801122E0;
    case 0x801122E4u: goto label_801122E4;
    case 0x801122E8u: goto label_801122E8;
    case 0x801122ECu: goto label_801122EC;
    case 0x801122F0u: goto label_801122F0;
    case 0x801122F4u: goto label_801122F4;
    case 0x801122F8u: goto label_801122F8;
    case 0x801122FCu: goto label_801122FC;
    case 0x80112300u: goto label_80112300;
    case 0x80112304u: goto label_80112304;
    case 0x80112308u: goto label_80112308;
    case 0x8011230Cu: goto label_8011230C;
    case 0x80112310u: goto label_80112310;
    case 0x80112314u: goto label_80112314;
    case 0x80112318u: goto label_80112318;
    case 0x8011231Cu: goto label_8011231C;
    case 0x80112320u: goto label_80112320;
    case 0x80112324u: goto label_80112324;
    case 0x80112328u: goto label_80112328;
    case 0x8011232Cu: goto label_8011232C;
    case 0x80112330u: goto label_80112330;
    case 0x80112334u: goto label_80112334;
    case 0x80112338u: goto label_80112338;
    case 0x8011233Cu: goto label_8011233C;
    case 0x80112340u: goto label_80112340;
    case 0x80112344u: goto label_80112344;
    case 0x80112348u: goto label_80112348;
    case 0x8011234Cu: goto label_8011234C;
    case 0x80112350u: goto label_80112350;
    case 0x80112354u: goto label_80112354;
    case 0x80112358u: goto label_80112358;
    case 0x8011235Cu: goto label_8011235C;
    case 0x80112360u: goto label_80112360;
    case 0x80112364u: goto label_80112364;
    case 0x80112368u: goto label_80112368;
    case 0x8011236Cu: goto label_8011236C;
    case 0x80112370u: goto label_80112370;
    case 0x80112374u: goto label_80112374;
    case 0x80112378u: goto label_80112378;
    case 0x8011237Cu: goto label_8011237C;
    case 0x80112380u: goto label_80112380;
    case 0x80112384u: goto label_80112384;
    case 0x80112388u: goto label_80112388;
    case 0x8011238Cu: goto label_8011238C;
    case 0x80112390u: goto label_80112390;
    case 0x80112394u: goto label_80112394;
    case 0x80112398u: goto label_80112398;
    case 0x8011239Cu: goto label_8011239C;
    case 0x801123A0u: goto label_801123A0;
    case 0x801123A4u: goto label_801123A4;
    case 0x801123A8u: goto label_801123A8;
    case 0x801123ACu: goto label_801123AC;
    case 0x801123B0u: goto label_801123B0;
    case 0x801123B4u: goto label_801123B4;
    case 0x801123B8u: goto label_801123B8;
    case 0x801123BCu: goto label_801123BC;
    case 0x801123C0u: goto label_801123C0;
    case 0x801123C4u: goto label_801123C4;
    case 0x801123C8u: goto label_801123C8;
    case 0x801123CCu: goto label_801123CC;
    case 0x801123D0u: goto label_801123D0;
    case 0x801123D4u: goto label_801123D4;
    case 0x801123D8u: goto label_801123D8;
    case 0x801123DCu: goto label_801123DC;
    case 0x801123E0u: goto label_801123E0;
    case 0x801123E4u: goto label_801123E4;
    case 0x801123E8u: goto label_801123E8;
    case 0x801123ECu: goto label_801123EC;
    case 0x801123F0u: goto label_801123F0;
    case 0x801123F4u: goto label_801123F4;
    case 0x801123F8u: goto label_801123F8;
    case 0x801123FCu: goto label_801123FC;
    case 0x80112400u: goto label_80112400;
    case 0x80112404u: goto label_80112404;
    case 0x80112408u: goto label_80112408;
    case 0x8011240Cu: goto label_8011240C;
    case 0x80112410u: goto label_80112410;
    case 0x80112414u: goto label_80112414;
    case 0x80112418u: goto label_80112418;
    case 0x8011241Cu: goto label_8011241C;
    case 0x80112420u: goto label_80112420;
    case 0x80112424u: goto label_80112424;
    case 0x80112428u: goto label_80112428;
    case 0x8011242Cu: goto label_8011242C;
    case 0x80112430u: goto label_80112430;
    case 0x80112434u: goto label_80112434;
    case 0x80112438u: goto label_80112438;
    case 0x8011243Cu: goto label_8011243C;
    case 0x80112440u: goto label_80112440;
    case 0x80112444u: goto label_80112444;
    case 0x80112448u: goto label_80112448;
    case 0x8011244Cu: goto label_8011244C;
    case 0x80112450u: goto label_80112450;
    case 0x80112454u: goto label_80112454;
    case 0x80112458u: goto label_80112458;
    case 0x8011245Cu: goto label_8011245C;
    case 0x80112460u: goto label_80112460;
    case 0x80112464u: goto label_80112464;
    case 0x80112468u: goto label_80112468;
    case 0x8011246Cu: goto label_8011246C;
    case 0x80112470u: goto label_80112470;
    case 0x80112474u: goto label_80112474;
    case 0x80112478u: goto label_80112478;
    case 0x8011247Cu: goto label_8011247C;
    case 0x80112480u: goto label_80112480;
    case 0x80112484u: goto label_80112484;
    case 0x80112488u: goto label_80112488;
    case 0x8011248Cu: goto label_8011248C;
    case 0x80112490u: goto label_80112490;
    case 0x80112494u: goto label_80112494;
    case 0x80112498u: goto label_80112498;
    case 0x8011249Cu: goto label_8011249C;
    case 0x801124A0u: goto label_801124A0;
    case 0x801124A4u: goto label_801124A4;
    case 0x801124A8u: goto label_801124A8;
    case 0x801124ACu: goto label_801124AC;
    case 0x801124B0u: goto label_801124B0;
    case 0x801124B4u: goto label_801124B4;
    case 0x801124B8u: goto label_801124B8;
    case 0x801124BCu: goto label_801124BC;
    case 0x801124C0u: goto label_801124C0;
    case 0x801124C4u: goto label_801124C4;
    case 0x801124C8u: goto label_801124C8;
    case 0x801124CCu: goto label_801124CC;
    case 0x801124D0u: goto label_801124D0;
    case 0x801124D4u: goto label_801124D4;
    case 0x801124D8u: goto label_801124D8;
    case 0x801124DCu: goto label_801124DC;
    case 0x801124E0u: goto label_801124E0;
    case 0x801124E4u: goto label_801124E4;
    case 0x801124E8u: goto label_801124E8;
    case 0x801124ECu: goto label_801124EC;
    case 0x801124F0u: goto label_801124F0;
    case 0x801124F4u: goto label_801124F4;
    case 0x801124F8u: goto label_801124F8;
    case 0x801124FCu: goto label_801124FC;
    case 0x80112500u: goto label_80112500;
    case 0x80112504u: goto label_80112504;
    case 0x80112508u: goto label_80112508;
    case 0x8011250Cu: goto label_8011250C;
    case 0x80112510u: goto label_80112510;
    case 0x80112514u: goto label_80112514;
    case 0x80112518u: goto label_80112518;
    case 0x8011251Cu: goto label_8011251C;
    case 0x80112520u: goto label_80112520;
    case 0x80112524u: goto label_80112524;
    case 0x80112528u: goto label_80112528;
    case 0x8011252Cu: goto label_8011252C;
    case 0x80112530u: goto label_80112530;
    case 0x80112534u: goto label_80112534;
    case 0x80112538u: goto label_80112538;
    case 0x8011253Cu: goto label_8011253C;
    case 0x80112540u: goto label_80112540;
    case 0x80112544u: goto label_80112544;
    case 0x80112548u: goto label_80112548;
    case 0x8011254Cu: goto label_8011254C;
    case 0x80112550u: goto label_80112550;
    case 0x80112554u: goto label_80112554;
    case 0x80112558u: goto label_80112558;
    case 0x8011255Cu: goto label_8011255C;
    case 0x80112560u: goto label_80112560;
    case 0x80112564u: goto label_80112564;
    case 0x80112568u: goto label_80112568;
    case 0x8011256Cu: goto label_8011256C;
    case 0x80112570u: goto label_80112570;
    case 0x80112574u: goto label_80112574;
    case 0x80112578u: goto label_80112578;
    case 0x8011257Cu: goto label_8011257C;
    case 0x80112580u: goto label_80112580;
    case 0x80112584u: goto label_80112584;
    case 0x80112588u: goto label_80112588;
    case 0x8011258Cu: goto label_8011258C;
    case 0x80112590u: goto label_80112590;
    case 0x80112594u: goto label_80112594;
    case 0x80112598u: goto label_80112598;
    case 0x8011259Cu: goto label_8011259C;
    case 0x801125A0u: goto label_801125A0;
    case 0x801125A4u: goto label_801125A4;
    case 0x801125A8u: goto label_801125A8;
    case 0x801125ACu: goto label_801125AC;
    case 0x801125B0u: goto label_801125B0;
    case 0x801125B4u: goto label_801125B4;
    case 0x801125B8u: goto label_801125B8;
    case 0x801125BCu: goto label_801125BC;
    case 0x801125C0u: goto label_801125C0;
    case 0x801125C4u: goto label_801125C4;
    case 0x801125C8u: goto label_801125C8;
    case 0x801125CCu: goto label_801125CC;
    case 0x801125D0u: goto label_801125D0;
    case 0x801125D4u: goto label_801125D4;
    case 0x801125D8u: goto label_801125D8;
    case 0x801125DCu: goto label_801125DC;
    case 0x801125E0u: goto label_801125E0;
    case 0x801125E4u: goto label_801125E4;
    case 0x801125E8u: goto label_801125E8;
    case 0x801125ECu: goto label_801125EC;
    case 0x801125F0u: goto label_801125F0;
    case 0x801125F4u: goto label_801125F4;
    case 0x801125F8u: goto label_801125F8;
    case 0x801125FCu: goto label_801125FC;
    case 0x80112600u: goto label_80112600;
    case 0x80112604u: goto label_80112604;
    case 0x80112608u: goto label_80112608;
    case 0x8011260Cu: goto label_8011260C;
    case 0x80112610u: goto label_80112610;
    case 0x80112614u: goto label_80112614;
    case 0x80112618u: goto label_80112618;
    case 0x8011261Cu: goto label_8011261C;
    case 0x80112620u: goto label_80112620;
    case 0x80112624u: goto label_80112624;
    case 0x80112628u: goto label_80112628;
    case 0x8011262Cu: goto label_8011262C;
    case 0x80112630u: goto label_80112630;
    case 0x80112634u: goto label_80112634;
    case 0x80112638u: goto label_80112638;
    case 0x8011263Cu: goto label_8011263C;
    case 0x80112640u: goto label_80112640;
    case 0x80112644u: goto label_80112644;
    case 0x80112648u: goto label_80112648;
    case 0x8011264Cu: goto label_8011264C;
    case 0x80112650u: goto label_80112650;
    case 0x80112654u: goto label_80112654;
    case 0x80112658u: goto label_80112658;
    case 0x8011265Cu: goto label_8011265C;
    case 0x80112660u: goto label_80112660;
    case 0x80112664u: goto label_80112664;
    case 0x80112668u: goto label_80112668;
    case 0x8011266Cu: goto label_8011266C;
    case 0x80112670u: goto label_80112670;
    case 0x80112674u: goto label_80112674;
    case 0x80112678u: goto label_80112678;
    case 0x8011267Cu: goto label_8011267C;
    case 0x80112680u: goto label_80112680;
    case 0x80112684u: goto label_80112684;
    case 0x80112688u: goto label_80112688;
    case 0x8011268Cu: goto label_8011268C;
    case 0x80112690u: goto label_80112690;
    case 0x80112694u: goto label_80112694;
    case 0x80112698u: goto label_80112698;
    case 0x8011269Cu: goto label_8011269C;
    case 0x801126A0u: goto label_801126A0;
    case 0x801126A4u: goto label_801126A4;
    case 0x801126A8u: goto label_801126A8;
    case 0x801126ACu: goto label_801126AC;
    case 0x801126B0u: goto label_801126B0;
    case 0x801126B4u: goto label_801126B4;
    case 0x801126B8u: goto label_801126B8;
    case 0x801126BCu: goto label_801126BC;
    case 0x801126C0u: goto label_801126C0;
    case 0x801126C4u: goto label_801126C4;
    case 0x801126C8u: goto label_801126C8;
    case 0x801126CCu: goto label_801126CC;
    case 0x801126D0u: goto label_801126D0;
    case 0x801126D4u: goto label_801126D4;
    case 0x801126D8u: goto label_801126D8;
    case 0x801126DCu: goto label_801126DC;
    case 0x801126E0u: goto label_801126E0;
    case 0x801126E4u: goto label_801126E4;
    case 0x801126E8u: goto label_801126E8;
    case 0x801126ECu: goto label_801126EC;
    case 0x801126F0u: goto label_801126F0;
    case 0x801126F4u: goto label_801126F4;
    case 0x801126F8u: goto label_801126F8;
    case 0x801126FCu: goto label_801126FC;
    case 0x80112700u: goto label_80112700;
    case 0x80112704u: goto label_80112704;
    case 0x80112708u: goto label_80112708;
    case 0x8011270Cu: goto label_8011270C;
    case 0x80112710u: goto label_80112710;
    case 0x80112714u: goto label_80112714;
    case 0x80112718u: goto label_80112718;
    case 0x8011271Cu: goto label_8011271C;
    case 0x80112720u: goto label_80112720;
    case 0x80112724u: goto label_80112724;
    case 0x80112728u: goto label_80112728;
    case 0x8011272Cu: goto label_8011272C;
    case 0x80112730u: goto label_80112730;
    case 0x80112734u: goto label_80112734;
    case 0x80112738u: goto label_80112738;
    case 0x8011273Cu: goto label_8011273C;
    case 0x80112740u: goto label_80112740;
    case 0x80112744u: goto label_80112744;
    case 0x80112748u: goto label_80112748;
    case 0x8011274Cu: goto label_8011274C;
    case 0x80112750u: goto label_80112750;
    case 0x80112754u: goto label_80112754;
    case 0x80112758u: goto label_80112758;
    case 0x8011275Cu: goto label_8011275C;
    case 0x80112760u: goto label_80112760;
    case 0x80112764u: goto label_80112764;
    case 0x80112768u: goto label_80112768;
    case 0x8011276Cu: goto label_8011276C;
    case 0x80112770u: goto label_80112770;
    case 0x80112774u: goto label_80112774;
    case 0x80112778u: goto label_80112778;
    case 0x8011277Cu: goto label_8011277C;
    case 0x80112780u: goto label_80112780;
    case 0x80112784u: goto label_80112784;
    case 0x80112788u: goto label_80112788;
    case 0x8011278Cu: goto label_8011278C;
    case 0x80112790u: goto label_80112790;
    case 0x80112794u: goto label_80112794;
    case 0x80112798u: goto label_80112798;
    case 0x8011279Cu: goto label_8011279C;
    case 0x801127A0u: goto label_801127A0;
    case 0x801127A4u: goto label_801127A4;
    case 0x801127A8u: goto label_801127A8;
    case 0x801127ACu: goto label_801127AC;
    case 0x801127B0u: goto label_801127B0;
    case 0x801127B4u: goto label_801127B4;
    case 0x801127B8u: goto label_801127B8;
    case 0x801127BCu: goto label_801127BC;
    case 0x801127C0u: goto label_801127C0;
    case 0x801127C4u: goto label_801127C4;
    case 0x801127C8u: goto label_801127C8;
    case 0x801127CCu: goto label_801127CC;
    case 0x801127D0u: goto label_801127D0;
    case 0x801127D4u: goto label_801127D4;
    case 0x801127D8u: goto label_801127D8;
    case 0x801127DCu: goto label_801127DC;
    case 0x801127E0u: goto label_801127E0;
    case 0x801127E4u: goto label_801127E4;
    case 0x801127E8u: goto label_801127E8;
    case 0x801127ECu: goto label_801127EC;
    case 0x801127F0u: goto label_801127F0;
    case 0x801127F4u: goto label_801127F4;
    case 0x801127F8u: goto label_801127F8;
    case 0x801127FCu: goto label_801127FC;
    case 0x80112800u: goto label_80112800;
    case 0x80112804u: goto label_80112804;
    case 0x80112808u: goto label_80112808;
    case 0x8011280Cu: goto label_8011280C;
    case 0x80112810u: goto label_80112810;
    case 0x80112814u: goto label_80112814;
    case 0x80112818u: goto label_80112818;
    case 0x8011281Cu: goto label_8011281C;
    case 0x80112820u: goto label_80112820;
    case 0x80112824u: goto label_80112824;
    case 0x80112828u: goto label_80112828;
    case 0x8011282Cu: goto label_8011282C;
    case 0x80112830u: goto label_80112830;
    case 0x80112834u: goto label_80112834;
    case 0x80112838u: goto label_80112838;
    case 0x8011283Cu: goto label_8011283C;
    case 0x80112840u: goto label_80112840;
    case 0x80112844u: goto label_80112844;
    case 0x80112848u: goto label_80112848;
    case 0x8011284Cu: goto label_8011284C;
    case 0x80112850u: goto label_80112850;
    case 0x80112854u: goto label_80112854;
    case 0x80112858u: goto label_80112858;
    case 0x8011285Cu: goto label_8011285C;
    case 0x80112860u: goto label_80112860;
    case 0x80112864u: goto label_80112864;
    case 0x80112868u: goto label_80112868;
    case 0x8011286Cu: goto label_8011286C;
    case 0x80112870u: goto label_80112870;
    case 0x80112874u: goto label_80112874;
    case 0x80112878u: goto label_80112878;
    case 0x8011287Cu: goto label_8011287C;
    case 0x80112880u: goto label_80112880;
    case 0x80112884u: goto label_80112884;
    case 0x80112888u: goto label_80112888;
    case 0x8011288Cu: goto label_8011288C;
    case 0x80112890u: goto label_80112890;
    case 0x80112894u: goto label_80112894;
    case 0x80112898u: goto label_80112898;
    case 0x8011289Cu: goto label_8011289C;
    case 0x801128A0u: goto label_801128A0;
    case 0x801128A4u: goto label_801128A4;
    case 0x801128A8u: goto label_801128A8;
    case 0x801128ACu: goto label_801128AC;
    case 0x801128B0u: goto label_801128B0;
    case 0x801128B4u: goto label_801128B4;
    case 0x801128B8u: goto label_801128B8;
    case 0x801128BCu: goto label_801128BC;
    case 0x801128C0u: goto label_801128C0;
    case 0x801128C4u: goto label_801128C4;
    case 0x801128C8u: goto label_801128C8;
    case 0x801128CCu: goto label_801128CC;
    case 0x801128D0u: goto label_801128D0;
    case 0x801128D4u: goto label_801128D4;
    case 0x801128D8u: goto label_801128D8;
    case 0x801128DCu: goto label_801128DC;
    case 0x801128E0u: goto label_801128E0;
    case 0x801128E4u: goto label_801128E4;
    case 0x801128E8u: goto label_801128E8;
    case 0x801128ECu: goto label_801128EC;
    case 0x801128F0u: goto label_801128F0;
    case 0x801128F4u: goto label_801128F4;
    case 0x801128F8u: goto label_801128F8;
    case 0x801128FCu: goto label_801128FC;
    case 0x80112900u: goto label_80112900;
    case 0x80112904u: goto label_80112904;
    case 0x80112908u: goto label_80112908;
    case 0x8011290Cu: goto label_8011290C;
    case 0x80112910u: goto label_80112910;
    case 0x80112914u: goto label_80112914;
    case 0x80112918u: goto label_80112918;
    case 0x8011291Cu: goto label_8011291C;
    case 0x80112920u: goto label_80112920;
    case 0x80112924u: goto label_80112924;
    case 0x80112928u: goto label_80112928;
    case 0x8011292Cu: goto label_8011292C;
    case 0x80112930u: goto label_80112930;
    case 0x80112934u: goto label_80112934;
    case 0x80112938u: goto label_80112938;
    case 0x8011293Cu: goto label_8011293C;
    case 0x80112940u: goto label_80112940;
    case 0x80112944u: goto label_80112944;
    case 0x80112948u: goto label_80112948;
    case 0x8011294Cu: goto label_8011294C;
    case 0x80112950u: goto label_80112950;
    case 0x80112954u: goto label_80112954;
    case 0x80112958u: goto label_80112958;
    case 0x8011295Cu: goto label_8011295C;
    case 0x80112960u: goto label_80112960;
    case 0x80112964u: goto label_80112964;
    case 0x80112968u: goto label_80112968;
    case 0x8011296Cu: goto label_8011296C;
    case 0x80112970u: goto label_80112970;
    case 0x80112974u: goto label_80112974;
    case 0x80112978u: goto label_80112978;
    case 0x8011297Cu: goto label_8011297C;
    case 0x80112980u: goto label_80112980;
    case 0x80112984u: goto label_80112984;
    case 0x80112988u: goto label_80112988;
    case 0x8011298Cu: goto label_8011298C;
    case 0x80112990u: goto label_80112990;
    case 0x80112994u: goto label_80112994;
    case 0x80112998u: goto label_80112998;
    case 0x8011299Cu: goto label_8011299C;
    case 0x801129A0u: goto label_801129A0;
    case 0x801129A4u: goto label_801129A4;
    case 0x801129A8u: goto label_801129A8;
    case 0x801129ACu: goto label_801129AC;
    case 0x801129B0u: goto label_801129B0;
    case 0x801129B4u: goto label_801129B4;
    case 0x801129B8u: goto label_801129B8;
    case 0x801129BCu: goto label_801129BC;
    case 0x801129C0u: goto label_801129C0;
    case 0x801129C4u: goto label_801129C4;
    case 0x801129C8u: goto label_801129C8;
    case 0x801129CCu: goto label_801129CC;
    case 0x801129D0u: goto label_801129D0;
    case 0x801129D4u: goto label_801129D4;
    case 0x801129D8u: goto label_801129D8;
    case 0x801129DCu: goto label_801129DC;
    case 0x801129E0u: goto label_801129E0;
    case 0x801129E4u: goto label_801129E4;
    case 0x801129E8u: goto label_801129E8;
    case 0x801129ECu: goto label_801129EC;
    case 0x801129F0u: goto label_801129F0;
    case 0x801129F4u: goto label_801129F4;
    case 0x801129F8u: goto label_801129F8;
    case 0x801129FCu: goto label_801129FC;
    case 0x80112A00u: goto label_80112A00;
    case 0x80112A04u: goto label_80112A04;
    case 0x80112A08u: goto label_80112A08;
    case 0x80112A0Cu: goto label_80112A0C;
    case 0x80112A10u: goto label_80112A10;
    case 0x80112A14u: goto label_80112A14;
    case 0x80112A18u: goto label_80112A18;
    case 0x80112A1Cu: goto label_80112A1C;
    case 0x80112A20u: goto label_80112A20;
    case 0x80112A24u: goto label_80112A24;
    case 0x80112A28u: goto label_80112A28;
    case 0x80112A2Cu: goto label_80112A2C;
    case 0x80112A30u: goto label_80112A30;
    case 0x80112A34u: goto label_80112A34;
    case 0x80112A38u: goto label_80112A38;
    case 0x80112A3Cu: goto label_80112A3C;
    case 0x80112A40u: goto label_80112A40;
    case 0x80112A44u: goto label_80112A44;
    case 0x80112A48u: goto label_80112A48;
    case 0x80112A4Cu: goto label_80112A4C;
    case 0x80112A50u: goto label_80112A50;
    case 0x80112A54u: goto label_80112A54;
    case 0x80112A58u: goto label_80112A58;
    case 0x80112A5Cu: goto label_80112A5C;
    case 0x80112A60u: goto label_80112A60;
    case 0x80112A64u: goto label_80112A64;
    case 0x80112A68u: goto label_80112A68;
    case 0x80112A6Cu: goto label_80112A6C;
    case 0x80112A70u: goto label_80112A70;
    case 0x80112A74u: goto label_80112A74;
    case 0x80112A78u: goto label_80112A78;
    case 0x80112A7Cu: goto label_80112A7C;
    case 0x80112A80u: goto label_80112A80;
    case 0x80112A84u: goto label_80112A84;
    case 0x80112A88u: goto label_80112A88;
    case 0x80112A8Cu: goto label_80112A8C;
    case 0x80112A90u: goto label_80112A90;
    case 0x80112A94u: goto label_80112A94;
    case 0x80112A98u: goto label_80112A98;
    case 0x80112A9Cu: goto label_80112A9C;
    case 0x80112AA0u: goto label_80112AA0;
    case 0x80112AA4u: goto label_80112AA4;
    case 0x80112AA8u: goto label_80112AA8;
    case 0x80112AACu: goto label_80112AAC;
    case 0x80112AB0u: goto label_80112AB0;
    case 0x80112AB4u: goto label_80112AB4;
    case 0x80112AB8u: goto label_80112AB8;
    case 0x80112ABCu: goto label_80112ABC;
    case 0x80112AC0u: goto label_80112AC0;
    case 0x80112AC4u: goto label_80112AC4;
    case 0x80112AC8u: goto label_80112AC8;
    case 0x80112ACCu: goto label_80112ACC;
    case 0x80112AD0u: goto label_80112AD0;
    case 0x80112AD4u: goto label_80112AD4;
    case 0x80112AD8u: goto label_80112AD8;
    case 0x80112ADCu: goto label_80112ADC;
    case 0x80112AE0u: goto label_80112AE0;
    case 0x80112AE4u: goto label_80112AE4;
    case 0x80112AE8u: goto label_80112AE8;
    case 0x80112AECu: goto label_80112AEC;
    case 0x80112AF0u: goto label_80112AF0;
    case 0x80112AF4u: goto label_80112AF4;
    case 0x80112AF8u: goto label_80112AF8;
    case 0x80112AFCu: goto label_80112AFC;
    case 0x80112B00u: goto label_80112B00;
    case 0x80112B04u: goto label_80112B04;
    case 0x80112B08u: goto label_80112B08;
    case 0x80112B0Cu: goto label_80112B0C;
    case 0x80112B10u: goto label_80112B10;
    case 0x80112B14u: goto label_80112B14;
    case 0x80112B18u: goto label_80112B18;
    case 0x80112B1Cu: goto label_80112B1C;
    case 0x80112B20u: goto label_80112B20;
    case 0x80112B24u: goto label_80112B24;
    case 0x80112B28u: goto label_80112B28;
    case 0x80112B2Cu: goto label_80112B2C;
    case 0x80112B30u: goto label_80112B30;
    case 0x80112B34u: goto label_80112B34;
    case 0x80112B38u: goto label_80112B38;
    case 0x80112B3Cu: goto label_80112B3C;
    case 0x80112B40u: goto label_80112B40;
    case 0x80112B44u: goto label_80112B44;
    case 0x80112B48u: goto label_80112B48;
    case 0x80112B4Cu: goto label_80112B4C;
    case 0x80112B50u: goto label_80112B50;
    case 0x80112B54u: goto label_80112B54;
    case 0x80112B58u: goto label_80112B58;
    case 0x80112B5Cu: goto label_80112B5C;
    case 0x80112B60u: goto label_80112B60;
    case 0x80112B64u: goto label_80112B64;
    case 0x80112B68u: goto label_80112B68;
    case 0x80112B6Cu: goto label_80112B6C;
    case 0x80112B70u: goto label_80112B70;
    case 0x80112B74u: goto label_80112B74;
    case 0x80112B78u: goto label_80112B78;
    case 0x80112B7Cu: goto label_80112B7C;
    case 0x80112B80u: goto label_80112B80;
    case 0x80112B84u: goto label_80112B84;
    case 0x80112B88u: goto label_80112B88;
    case 0x80112B8Cu: goto label_80112B8C;
    case 0x80112B90u: goto label_80112B90;
    case 0x80112B94u: goto label_80112B94;
    case 0x80112B98u: goto label_80112B98;
    case 0x80112B9Cu: goto label_80112B9C;
    case 0x80112BA0u: goto label_80112BA0;
    case 0x80112BA4u: goto label_80112BA4;
    case 0x80112BA8u: goto label_80112BA8;
    case 0x80112BACu: goto label_80112BAC;
    case 0x80112BB0u: goto label_80112BB0;
    case 0x80112BB4u: goto label_80112BB4;
    case 0x80112BB8u: goto label_80112BB8;
    case 0x80112BBCu: goto label_80112BBC;
    case 0x80112BC0u: goto label_80112BC0;
    case 0x80112BC4u: goto label_80112BC4;
    case 0x80112BC8u: goto label_80112BC8;
    case 0x80112BCCu: goto label_80112BCC;
    case 0x80112BD0u: goto label_80112BD0;
    case 0x80112BD4u: goto label_80112BD4;
    case 0x80112BD8u: goto label_80112BD8;
    case 0x80112BDCu: goto label_80112BDC;
    case 0x80112BE0u: goto label_80112BE0;
    case 0x80112BE4u: goto label_80112BE4;
    case 0x80112BE8u: goto label_80112BE8;
    case 0x80112BECu: goto label_80112BEC;
    case 0x80112BF0u: goto label_80112BF0;
    case 0x80112BF4u: goto label_80112BF4;
    case 0x80112BF8u: goto label_80112BF8;
    case 0x80112BFCu: goto label_80112BFC;
    case 0x80112C00u: goto label_80112C00;
    case 0x80112C04u: goto label_80112C04;
    case 0x80112C08u: goto label_80112C08;
    case 0x80112C0Cu: goto label_80112C0C;
    case 0x80112C10u: goto label_80112C10;
    case 0x80112C14u: goto label_80112C14;
    case 0x80112C18u: goto label_80112C18;
    case 0x80112C1Cu: goto label_80112C1C;
    case 0x80112C20u: goto label_80112C20;
    case 0x80112C24u: goto label_80112C24;
    case 0x80112C28u: goto label_80112C28;
    case 0x80112C2Cu: goto label_80112C2C;
    case 0x80112C30u: goto label_80112C30;
    case 0x80112C34u: goto label_80112C34;
    case 0x80112C38u: goto label_80112C38;
    case 0x80112C3Cu: goto label_80112C3C;
    case 0x80112C40u: goto label_80112C40;
    case 0x80112C44u: goto label_80112C44;
    case 0x80112C48u: goto label_80112C48;
    case 0x80112C4Cu: goto label_80112C4C;
    case 0x80112C50u: goto label_80112C50;
    case 0x80112C54u: goto label_80112C54;
    case 0x80112C58u: goto label_80112C58;
    case 0x80112C5Cu: goto label_80112C5C;
    case 0x80112C60u: goto label_80112C60;
    case 0x80112C64u: goto label_80112C64;
    case 0x80112C68u: goto label_80112C68;
    case 0x80112C6Cu: goto label_80112C6C;
    case 0x80112C70u: goto label_80112C70;
    case 0x80112C74u: goto label_80112C74;
    case 0x80112C78u: goto label_80112C78;
    case 0x80112C7Cu: goto label_80112C7C;
    case 0x80112C80u: goto label_80112C80;
    case 0x80112C84u: goto label_80112C84;
    case 0x80112C88u: goto label_80112C88;
    case 0x80112C8Cu: goto label_80112C8C;
    case 0x80112C90u: goto label_80112C90;
    case 0x80112C94u: goto label_80112C94;
    case 0x80112C98u: goto label_80112C98;
    case 0x80112C9Cu: goto label_80112C9C;
    case 0x80112CA0u: goto label_80112CA0;
    case 0x80112CA4u: goto label_80112CA4;
    case 0x80112CA8u: goto label_80112CA8;
    case 0x80112CACu: goto label_80112CAC;
    case 0x80112CB0u: goto label_80112CB0;
    case 0x80112CB4u: goto label_80112CB4;
    case 0x80112CB8u: goto label_80112CB8;
    case 0x80112CBCu: goto label_80112CBC;
    case 0x80112CC0u: goto label_80112CC0;
    case 0x80112CC4u: goto label_80112CC4;
    case 0x80112CC8u: goto label_80112CC8;
    case 0x80112CCCu: goto label_80112CCC;
    case 0x80112CD0u: goto label_80112CD0;
    case 0x80112CD4u: goto label_80112CD4;
    case 0x80112CD8u: goto label_80112CD8;
    case 0x80112CDCu: goto label_80112CDC;
    case 0x80112CE0u: goto label_80112CE0;
    case 0x80112CE4u: goto label_80112CE4;
    case 0x80112CE8u: goto label_80112CE8;
    case 0x80112CECu: goto label_80112CEC;
    case 0x80112CF0u: goto label_80112CF0;
    case 0x80112CF4u: goto label_80112CF4;
    case 0x80112CF8u: goto label_80112CF8;
    case 0x80112CFCu: goto label_80112CFC;
    case 0x80112D00u: goto label_80112D00;
    case 0x80112D04u: goto label_80112D04;
    case 0x80112D08u: goto label_80112D08;
    case 0x80112D0Cu: goto label_80112D0C;
    case 0x80112D10u: goto label_80112D10;
    case 0x80112D14u: goto label_80112D14;
    case 0x80112D18u: goto label_80112D18;
    case 0x80112D1Cu: goto label_80112D1C;
    case 0x80112D20u: goto label_80112D20;
    case 0x80112D24u: goto label_80112D24;
    case 0x80112D28u: goto label_80112D28;
    case 0x80112D2Cu: goto label_80112D2C;
    case 0x80112D30u: goto label_80112D30;
    case 0x80112D34u: goto label_80112D34;
    case 0x80112D38u: goto label_80112D38;
    case 0x80112D3Cu: goto label_80112D3C;
    case 0x80112D40u: goto label_80112D40;
    case 0x80112D44u: goto label_80112D44;
    case 0x80112D48u: goto label_80112D48;
    case 0x80112D4Cu: goto label_80112D4C;
    case 0x80112D50u: goto label_80112D50;
    case 0x80112D54u: goto label_80112D54;
    case 0x80112D58u: goto label_80112D58;
    case 0x80112D5Cu: goto label_80112D5C;
    case 0x80112D60u: goto label_80112D60;
    case 0x80112D64u: goto label_80112D64;
    case 0x80112D68u: goto label_80112D68;
    case 0x80112D6Cu: goto label_80112D6C;
    case 0x80112D70u: goto label_80112D70;
    case 0x80112D74u: goto label_80112D74;
    case 0x80112D78u: goto label_80112D78;
    case 0x80112D7Cu: goto label_80112D7C;
    case 0x80112D80u: goto label_80112D80;
    case 0x80112D84u: goto label_80112D84;
    case 0x80112D88u: goto label_80112D88;
    case 0x80112D8Cu: goto label_80112D8C;
    case 0x80112D90u: goto label_80112D90;
    case 0x80112D94u: goto label_80112D94;
    case 0x80112D98u: goto label_80112D98;
    case 0x80112D9Cu: goto label_80112D9C;
    case 0x80112DA0u: goto label_80112DA0;
    case 0x80112DA4u: goto label_80112DA4;
    case 0x80112DA8u: goto label_80112DA8;
    case 0x80112DACu: goto label_80112DAC;
    case 0x80112DB0u: goto label_80112DB0;
    case 0x80112DB4u: goto label_80112DB4;
    case 0x80112DB8u: goto label_80112DB8;
    case 0x80112DBCu: goto label_80112DBC;
    case 0x80112DC0u: goto label_80112DC0;
    case 0x80112DC4u: goto label_80112DC4;
    case 0x80112DC8u: goto label_80112DC8;
    case 0x80112DCCu: goto label_80112DCC;
    case 0x80112DD0u: goto label_80112DD0;
    case 0x80112DD4u: goto label_80112DD4;
    case 0x80112DD8u: goto label_80112DD8;
    case 0x80112DDCu: goto label_80112DDC;
    case 0x80112DE0u: goto label_80112DE0;
    case 0x80112DE4u: goto label_80112DE4;
    case 0x80112DE8u: goto label_80112DE8;
    case 0x80112DECu: goto label_80112DEC;
    case 0x80112DF0u: goto label_80112DF0;
    case 0x80112DF4u: goto label_80112DF4;
    case 0x80112DF8u: goto label_80112DF8;
    case 0x80112DFCu: goto label_80112DFC;
    case 0x80112E00u: goto label_80112E00;
    case 0x80112E04u: goto label_80112E04;
    case 0x80112E08u: goto label_80112E08;
    case 0x80112E0Cu: goto label_80112E0C;
    case 0x80112E10u: goto label_80112E10;
    case 0x80112E14u: goto label_80112E14;
    case 0x80112E18u: goto label_80112E18;
    case 0x80112E1Cu: goto label_80112E1C;
    case 0x80112E20u: goto label_80112E20;
    case 0x80112E24u: goto label_80112E24;
    case 0x80112E28u: goto label_80112E28;
    case 0x80112E2Cu: goto label_80112E2C;
    case 0x80112E30u: goto label_80112E30;
    case 0x80112E34u: goto label_80112E34;
    case 0x80112E38u: goto label_80112E38;
    case 0x80112E3Cu: goto label_80112E3C;
    case 0x80112E40u: goto label_80112E40;
    case 0x80112E44u: goto label_80112E44;
    case 0x80112E48u: goto label_80112E48;
    case 0x80112E4Cu: goto label_80112E4C;
    case 0x80112E50u: goto label_80112E50;
    case 0x80112E54u: goto label_80112E54;
    case 0x80112E58u: goto label_80112E58;
    case 0x80112E5Cu: goto label_80112E5C;
    case 0x80112E60u: goto label_80112E60;
    case 0x80112E64u: goto label_80112E64;
    case 0x80112E68u: goto label_80112E68;
    case 0x80112E6Cu: goto label_80112E6C;
    case 0x80112E70u: goto label_80112E70;
    case 0x80112E74u: goto label_80112E74;
    case 0x80112E78u: goto label_80112E78;
    case 0x80112E7Cu: goto label_80112E7C;
    case 0x80112E80u: goto label_80112E80;
    case 0x80112E84u: goto label_80112E84;
    case 0x80112E88u: goto label_80112E88;
    case 0x80112E8Cu: goto label_80112E8C;
    case 0x80112E90u: goto label_80112E90;
    case 0x80112E94u: goto label_80112E94;
    case 0x80112E98u: goto label_80112E98;
    case 0x80112E9Cu: goto label_80112E9C;
    case 0x80112EA0u: goto label_80112EA0;
    case 0x80112EA4u: goto label_80112EA4;
    case 0x80112EA8u: goto label_80112EA8;
    case 0x80112EACu: goto label_80112EAC;
    case 0x80112EB0u: goto label_80112EB0;
    case 0x80112EB4u: goto label_80112EB4;
    case 0x80112EB8u: goto label_80112EB8;
    case 0x80112EBCu: goto label_80112EBC;
    case 0x80112EC0u: goto label_80112EC0;
    case 0x80112EC4u: goto label_80112EC4;
    case 0x80112EC8u: goto label_80112EC8;
    case 0x80112ECCu: goto label_80112ECC;
    case 0x80112ED0u: goto label_80112ED0;
    case 0x80112ED4u: goto label_80112ED4;
    case 0x80112ED8u: goto label_80112ED8;
    case 0x80112EDCu: goto label_80112EDC;
    case 0x80112EE0u: goto label_80112EE0;
    case 0x80112EE4u: goto label_80112EE4;
    case 0x80112EE8u: goto label_80112EE8;
    case 0x80112EECu: goto label_80112EEC;
    case 0x80112EF0u: goto label_80112EF0;
    case 0x80112EF4u: goto label_80112EF4;
    case 0x80112EF8u: goto label_80112EF8;
    case 0x80112EFCu: goto label_80112EFC;
    case 0x80112F00u: goto label_80112F00;
    case 0x80112F04u: goto label_80112F04;
    case 0x80112F08u: goto label_80112F08;
    case 0x80112F0Cu: goto label_80112F0C;
    case 0x80112F10u: goto label_80112F10;
    case 0x80112F14u: goto label_80112F14;
    case 0x80112F18u: goto label_80112F18;
    case 0x80112F1Cu: goto label_80112F1C;
    case 0x80112F20u: goto label_80112F20;
    case 0x80112F24u: goto label_80112F24;
    case 0x80112F28u: goto label_80112F28;
    case 0x80112F2Cu: goto label_80112F2C;
    case 0x80112F30u: goto label_80112F30;
    case 0x80112F34u: goto label_80112F34;
    case 0x80112F38u: goto label_80112F38;
    case 0x80112F3Cu: goto label_80112F3C;
    case 0x80112F40u: goto label_80112F40;
    case 0x80112F44u: goto label_80112F44;
    case 0x80112F48u: goto label_80112F48;
    case 0x80112F4Cu: goto label_80112F4C;
    case 0x80112F50u: goto label_80112F50;
    case 0x80112F54u: goto label_80112F54;
    case 0x80112F58u: goto label_80112F58;
    case 0x80112F5Cu: goto label_80112F5C;
    case 0x80112F60u: goto label_80112F60;
    case 0x80112F64u: goto label_80112F64;
    case 0x80112F68u: goto label_80112F68;
    case 0x80112F6Cu: goto label_80112F6C;
    case 0x80112F70u: goto label_80112F70;
    case 0x80112F74u: goto label_80112F74;
    case 0x80112F78u: goto label_80112F78;
    case 0x80112F7Cu: goto label_80112F7C;
    case 0x80112F80u: goto label_80112F80;
    case 0x80112F84u: goto label_80112F84;
    case 0x80112F88u: goto label_80112F88;
    case 0x80112F8Cu: goto label_80112F8C;
    case 0x80112F90u: goto label_80112F90;
    case 0x80112F94u: goto label_80112F94;
    case 0x80112F98u: goto label_80112F98;
    case 0x80112F9Cu: goto label_80112F9C;
    case 0x80112FA0u: goto label_80112FA0;
    case 0x80112FA4u: goto label_80112FA4;
    case 0x80112FA8u: goto label_80112FA8;
    case 0x80112FACu: goto label_80112FAC;
    case 0x80112FB0u: goto label_80112FB0;
    case 0x80112FB4u: goto label_80112FB4;
    case 0x80112FB8u: goto label_80112FB8;
    case 0x80112FBCu: goto label_80112FBC;
    case 0x80112FC0u: goto label_80112FC0;
    case 0x80112FC4u: goto label_80112FC4;
    case 0x80112FC8u: goto label_80112FC8;
    case 0x80112FCCu: goto label_80112FCC;
    case 0x80112FD0u: goto label_80112FD0;
    case 0x80112FD4u: goto label_80112FD4;
    case 0x80112FD8u: goto label_80112FD8;
    case 0x80112FDCu: goto label_80112FDC;
    case 0x80112FE0u: goto label_80112FE0;
    case 0x80112FE4u: goto label_80112FE4;
    case 0x80112FE8u: goto label_80112FE8;
    case 0x80112FECu: goto label_80112FEC;
    case 0x80112FF0u: goto label_80112FF0;
    case 0x80112FF4u: goto label_80112FF4;
    case 0x80112FF8u: goto label_80112FF8;
    case 0x80112FFCu: goto label_80112FFC;
    case 0x80113000u: goto label_80113000;
    case 0x80113004u: goto label_80113004;
    case 0x80113008u: goto label_80113008;
    case 0x8011300Cu: goto label_8011300C;
    case 0x80113010u: goto label_80113010;
    case 0x80113014u: goto label_80113014;
    case 0x80113018u: goto label_80113018;
    case 0x8011301Cu: goto label_8011301C;
    case 0x80113020u: goto label_80113020;
    case 0x80113024u: goto label_80113024;
    case 0x80113028u: goto label_80113028;
    case 0x8011302Cu: goto label_8011302C;
    case 0x80113030u: goto label_80113030;
    case 0x80113034u: goto label_80113034;
    case 0x80113038u: goto label_80113038;
    case 0x8011303Cu: goto label_8011303C;
    case 0x80113040u: goto label_80113040;
    case 0x80113044u: goto label_80113044;
    case 0x80113048u: goto label_80113048;
    case 0x8011304Cu: goto label_8011304C;
    case 0x80113050u: goto label_80113050;
    case 0x80113054u: goto label_80113054;
    case 0x80113058u: goto label_80113058;
    case 0x8011305Cu: goto label_8011305C;
    case 0x80113060u: goto label_80113060;
    case 0x80113064u: goto label_80113064;
    case 0x80113068u: goto label_80113068;
    case 0x8011306Cu: goto label_8011306C;
    case 0x80113070u: goto label_80113070;
    case 0x80113074u: goto label_80113074;
    case 0x80113078u: goto label_80113078;
    case 0x8011307Cu: goto label_8011307C;
    case 0x80113080u: goto label_80113080;
    case 0x80113084u: goto label_80113084;
    case 0x80113088u: goto label_80113088;
    case 0x8011308Cu: goto label_8011308C;
    case 0x80113090u: goto label_80113090;
    case 0x80113094u: goto label_80113094;
    case 0x80113098u: goto label_80113098;
    case 0x8011309Cu: goto label_8011309C;
    case 0x801130A0u: goto label_801130A0;
    case 0x801130A4u: goto label_801130A4;
    case 0x801130A8u: goto label_801130A8;
    case 0x801130ACu: goto label_801130AC;
    case 0x801130B0u: goto label_801130B0;
    case 0x801130B4u: goto label_801130B4;
    case 0x801130B8u: goto label_801130B8;
    case 0x801130BCu: goto label_801130BC;
    case 0x801130C0u: goto label_801130C0;
    case 0x801130C4u: goto label_801130C4;
    case 0x801130C8u: goto label_801130C8;
    case 0x801130CCu: goto label_801130CC;
    case 0x801130D0u: goto label_801130D0;
    case 0x801130D4u: goto label_801130D4;
    case 0x801130D8u: goto label_801130D8;
    case 0x801130DCu: goto label_801130DC;
    case 0x801130E0u: goto label_801130E0;
    case 0x801130E4u: goto label_801130E4;
    case 0x801130E8u: goto label_801130E8;
    case 0x801130ECu: goto label_801130EC;
    case 0x801130F0u: goto label_801130F0;
    case 0x801130F4u: goto label_801130F4;
    case 0x801130F8u: goto label_801130F8;
    case 0x801130FCu: goto label_801130FC;
    case 0x80113100u: goto label_80113100;
    case 0x80113104u: goto label_80113104;
    case 0x80113108u: goto label_80113108;
    case 0x8011310Cu: goto label_8011310C;
    case 0x80113110u: goto label_80113110;
    case 0x80113114u: goto label_80113114;
    case 0x80113118u: goto label_80113118;
    case 0x8011311Cu: goto label_8011311C;
    case 0x80113120u: goto label_80113120;
    case 0x80113124u: goto label_80113124;
    case 0x80113128u: goto label_80113128;
    case 0x8011312Cu: goto label_8011312C;
    case 0x80113130u: goto label_80113130;
    case 0x80113134u: goto label_80113134;
    case 0x80113138u: goto label_80113138;
    case 0x8011313Cu: goto label_8011313C;
    case 0x80113140u: goto label_80113140;
    case 0x80113144u: goto label_80113144;
    case 0x80113148u: goto label_80113148;
    case 0x8011314Cu: goto label_8011314C;
    case 0x80113150u: goto label_80113150;
    case 0x80113154u: goto label_80113154;
    case 0x80113158u: goto label_80113158;
    case 0x8011315Cu: goto label_8011315C;
    case 0x80113160u: goto label_80113160;
    case 0x80113164u: goto label_80113164;
    case 0x80113168u: goto label_80113168;
    case 0x8011316Cu: goto label_8011316C;
    case 0x80113170u: goto label_80113170;
    case 0x80113174u: goto label_80113174;
    case 0x80113178u: goto label_80113178;
    case 0x8011317Cu: goto label_8011317C;
    case 0x80113180u: goto label_80113180;
    case 0x80113184u: goto label_80113184;
    case 0x80113188u: goto label_80113188;
    case 0x8011318Cu: goto label_8011318C;
    case 0x80113190u: goto label_80113190;
    case 0x80113194u: goto label_80113194;
    case 0x80113198u: goto label_80113198;
    case 0x8011319Cu: goto label_8011319C;
    case 0x801131A0u: goto label_801131A0;
    case 0x801131A4u: goto label_801131A4;
    case 0x801131A8u: goto label_801131A8;
    case 0x801131ACu: goto label_801131AC;
    case 0x801131B0u: goto label_801131B0;
    case 0x801131B4u: goto label_801131B4;
    case 0x801131B8u: goto label_801131B8;
    case 0x801131BCu: goto label_801131BC;
    case 0x801131C0u: goto label_801131C0;
    case 0x801131C4u: goto label_801131C4;
    case 0x801131C8u: goto label_801131C8;
    case 0x801131CCu: goto label_801131CC;
    case 0x801131D0u: goto label_801131D0;
    case 0x801131D4u: goto label_801131D4;
    case 0x801131D8u: goto label_801131D8;
    case 0x801131DCu: goto label_801131DC;
    case 0x801131E0u: goto label_801131E0;
    case 0x801131E4u: goto label_801131E4;
    case 0x801131E8u: goto label_801131E8;
    case 0x801131ECu: goto label_801131EC;
    case 0x801131F0u: goto label_801131F0;
    case 0x801131F4u: goto label_801131F4;
    case 0x801131F8u: goto label_801131F8;
    case 0x801131FCu: goto label_801131FC;
    case 0x80113200u: goto label_80113200;
    case 0x80113204u: goto label_80113204;
    case 0x80113208u: goto label_80113208;
    case 0x8011320Cu: goto label_8011320C;
    case 0x80113210u: goto label_80113210;
    case 0x80113214u: goto label_80113214;
    case 0x80113218u: goto label_80113218;
    case 0x8011321Cu: goto label_8011321C;
    case 0x80113220u: goto label_80113220;
    case 0x80113224u: goto label_80113224;
    case 0x80113228u: goto label_80113228;
    case 0x8011322Cu: goto label_8011322C;
    case 0x80113230u: goto label_80113230;
    case 0x80113234u: goto label_80113234;
    case 0x80113238u: goto label_80113238;
    case 0x8011323Cu: goto label_8011323C;
    case 0x80113240u: goto label_80113240;
    case 0x80113244u: goto label_80113244;
    case 0x80113248u: goto label_80113248;
    case 0x8011324Cu: goto label_8011324C;
    case 0x80113250u: goto label_80113250;
    case 0x80113254u: goto label_80113254;
    case 0x80113258u: goto label_80113258;
    case 0x8011325Cu: goto label_8011325C;
    case 0x80113260u: goto label_80113260;
    case 0x80113264u: goto label_80113264;
    case 0x80113268u: goto label_80113268;
    case 0x8011326Cu: goto label_8011326C;
    case 0x80113270u: goto label_80113270;
    case 0x80113274u: goto label_80113274;
    case 0x80113278u: goto label_80113278;
    case 0x8011327Cu: goto label_8011327C;
    case 0x80113280u: goto label_80113280;
    case 0x80113284u: goto label_80113284;
    case 0x80113288u: goto label_80113288;
    case 0x8011328Cu: goto label_8011328C;
    case 0x80113290u: goto label_80113290;
    case 0x80113294u: goto label_80113294;
    case 0x80113298u: goto label_80113298;
    case 0x8011329Cu: goto label_8011329C;
    case 0x801132A0u: goto label_801132A0;
    case 0x801132A4u: goto label_801132A4;
    case 0x801132A8u: goto label_801132A8;
    case 0x801132ACu: goto label_801132AC;
    case 0x801132B0u: goto label_801132B0;
    case 0x801132B4u: goto label_801132B4;
    case 0x801132B8u: goto label_801132B8;
    case 0x801132BCu: goto label_801132BC;
    case 0x801132C0u: goto label_801132C0;
    case 0x801132C4u: goto label_801132C4;
    case 0x801132C8u: goto label_801132C8;
    case 0x801132CCu: goto label_801132CC;
    case 0x801132D0u: goto label_801132D0;
    case 0x801132D4u: goto label_801132D4;
    case 0x801132D8u: goto label_801132D8;
    case 0x801132DCu: goto label_801132DC;
    case 0x801132E0u: goto label_801132E0;
    case 0x801132E4u: goto label_801132E4;
    case 0x801132E8u: goto label_801132E8;
    case 0x801132ECu: goto label_801132EC;
    case 0x801132F0u: goto label_801132F0;
    case 0x801132F4u: goto label_801132F4;
    case 0x801132F8u: goto label_801132F8;
    case 0x801132FCu: goto label_801132FC;
    case 0x80113300u: goto label_80113300;
    case 0x80113304u: goto label_80113304;
    case 0x80113308u: goto label_80113308;
    case 0x8011330Cu: goto label_8011330C;
    case 0x80113310u: goto label_80113310;
    case 0x80113314u: goto label_80113314;
    case 0x80113318u: goto label_80113318;
    case 0x8011331Cu: goto label_8011331C;
    case 0x80113320u: goto label_80113320;
    case 0x80113324u: goto label_80113324;
    case 0x80113328u: goto label_80113328;
    case 0x8011332Cu: goto label_8011332C;
    case 0x80113330u: goto label_80113330;
    case 0x80113334u: goto label_80113334;
    case 0x80113338u: goto label_80113338;
    case 0x8011333Cu: goto label_8011333C;
    case 0x80113340u: goto label_80113340;
    case 0x80113344u: goto label_80113344;
    case 0x80113348u: goto label_80113348;
    case 0x8011334Cu: goto label_8011334C;
    case 0x80113350u: goto label_80113350;
    case 0x80113354u: goto label_80113354;
    case 0x80113358u: goto label_80113358;
    case 0x8011335Cu: goto label_8011335C;
    case 0x80113360u: goto label_80113360;
    case 0x80113364u: goto label_80113364;
    case 0x80113368u: goto label_80113368;
    case 0x8011336Cu: goto label_8011336C;
    case 0x80113370u: goto label_80113370;
    case 0x80113374u: goto label_80113374;
    case 0x80113378u: goto label_80113378;
    case 0x8011337Cu: goto label_8011337C;
    case 0x80113380u: goto label_80113380;
    case 0x80113384u: goto label_80113384;
    case 0x80113388u: goto label_80113388;
    case 0x8011338Cu: goto label_8011338C;
    case 0x80113390u: goto label_80113390;
    case 0x80113394u: goto label_80113394;
    case 0x80113398u: goto label_80113398;
    case 0x8011339Cu: goto label_8011339C;
    case 0x801133A0u: goto label_801133A0;
    case 0x801133A4u: goto label_801133A4;
    case 0x801133A8u: goto label_801133A8;
    case 0x801133ACu: goto label_801133AC;
    case 0x801133B0u: goto label_801133B0;
    case 0x801133B4u: goto label_801133B4;
    case 0x801133B8u: goto label_801133B8;
    case 0x801133BCu: goto label_801133BC;
    case 0x801133C0u: goto label_801133C0;
    case 0x801133C4u: goto label_801133C4;
    case 0x801133C8u: goto label_801133C8;
    case 0x801133CCu: goto label_801133CC;
    case 0x801133D0u: goto label_801133D0;
    case 0x801133D4u: goto label_801133D4;
    case 0x801133D8u: goto label_801133D8;
    case 0x801133DCu: goto label_801133DC;
    case 0x801133E0u: goto label_801133E0;
    case 0x801133E4u: goto label_801133E4;
    case 0x801133E8u: goto label_801133E8;
    case 0x801133ECu: goto label_801133EC;
    case 0x801133F0u: goto label_801133F0;
    case 0x801133F4u: goto label_801133F4;
    case 0x801133F8u: goto label_801133F8;
    case 0x801133FCu: goto label_801133FC;
    case 0x80113400u: goto label_80113400;
    case 0x80113404u: goto label_80113404;
    case 0x80113408u: goto label_80113408;
    case 0x8011340Cu: goto label_8011340C;
    case 0x80113410u: goto label_80113410;
    case 0x80113414u: goto label_80113414;
    case 0x80113418u: goto label_80113418;
    case 0x8011341Cu: goto label_8011341C;
    case 0x80113420u: goto label_80113420;
    case 0x80113424u: goto label_80113424;
    case 0x80113428u: goto label_80113428;
    case 0x8011342Cu: goto label_8011342C;
    case 0x80113430u: goto label_80113430;
    case 0x80113434u: goto label_80113434;
    case 0x80113438u: goto label_80113438;
    case 0x8011343Cu: goto label_8011343C;
    case 0x80113440u: goto label_80113440;
    case 0x80113444u: goto label_80113444;
    case 0x80113448u: goto label_80113448;
    case 0x8011344Cu: goto label_8011344C;
    case 0x80113450u: goto label_80113450;
    case 0x80113454u: goto label_80113454;
    case 0x80113458u: goto label_80113458;
    case 0x8011345Cu: goto label_8011345C;
    case 0x80113460u: goto label_80113460;
    case 0x80113464u: goto label_80113464;
    case 0x80113468u: goto label_80113468;
    case 0x8011346Cu: goto label_8011346C;
    case 0x80113470u: goto label_80113470;
    case 0x80113474u: goto label_80113474;
    case 0x80113478u: goto label_80113478;
    case 0x8011347Cu: goto label_8011347C;
    case 0x80113480u: goto label_80113480;
    case 0x80113484u: goto label_80113484;
    case 0x80113488u: goto label_80113488;
    case 0x8011348Cu: goto label_8011348C;
    case 0x80113490u: goto label_80113490;
    case 0x80113494u: goto label_80113494;
    case 0x80113498u: goto label_80113498;
    case 0x8011349Cu: goto label_8011349C;
    case 0x801134A0u: goto label_801134A0;
    case 0x801134A4u: goto label_801134A4;
    case 0x801134A8u: goto label_801134A8;
    case 0x801134ACu: goto label_801134AC;
    case 0x801134B0u: goto label_801134B0;
    case 0x801134B4u: goto label_801134B4;
    case 0x801134B8u: goto label_801134B8;
    case 0x801134BCu: goto label_801134BC;
    default: return;
    }
label_8010F4C0:
    ctx->pc = 0x8010F4C0u;
    ctx->downcount -= 7;
    // 8010F4C0: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F4C4:
    ctx->pc = 0x8010F4C4u;
    // 8010F4C4: lwz     r0, 108(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F4C8:
    ctx->pc = 0x8010F4C8u;
    // 8010F4C8: lha     r3, 104(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(104);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8010F4CC:
    ctx->pc = 0x8010F4CCu;
    // 8010F4CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010F4D0:
    ctx->pc = 0x8010F4D0u;
    // 8010F4D0: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8010F4D4:
    ctx->pc = 0x8010F4D4u;
    // 8010F4D4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8010F4D8u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F4D8:
    ctx->pc = 0x8010F4D8u;
    ctx->downcount -= 9;
    // 8010F4D8: lwz     r11, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F4DC:
    ctx->pc = 0x8010F4DCu;
    // 8010F4DC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010F4E0:
    ctx->pc = 0x8010F4E0u;
    // 8010F4E0: lfs     f1, 4220(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010F4E0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4220);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8010F4E4:
    ctx->pc = 0x8010F4E4u;
    // 8010F4E4: lha     r0, 240(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(240);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8010F4E8:
    ctx->pc = 0x8010F4E8u;
    // 8010F4E8: lwz     r9, 244(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(244);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F4EC:
    ctx->pc = 0x8010F4ECu;
    // 8010F4EC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8010F4F0:
    ctx->pc = 0x8010F4F0u;
    // 8010F4F0: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_8010F4F4:
    ctx->pc = 0x8010F4F4u;
    // 8010F4F4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8010F4F8u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F4F8:
    ctx->pc = 0x8010F4F8u;
    ctx->downcount -= 3;
    // 8010F4F8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010F4FC:
    ctx->pc = 0x8010F4FCu;
    // 8010F4FC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8010F500:
    ctx->pc = 0x8010F500u;
    // 8010F500: bl      0x8010FE9C
    {
            ctx->lr = 0x8010F504u;
            goto label_8010FE9C;
    }

label_8010F504:
    ctx->pc = 0x8010F504u;
    ctx->downcount -= 1;
    // 8010F504: b       0x8010F550
    {
            goto label_8010F550;
    }

label_8010F508:
    ctx->pc = 0x8010F508u;
    ctx->downcount -= 2;
    // 8010F508: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010F50C:
    ctx->pc = 0x8010F50Cu;
    // 8010F50C: bl      0x80116250
    {
            ctx->lr = 0x8010F510u;
            ctx->pc = 0x80116250u;
            return;
    }

label_8010F510:
    ctx->pc = 0x8010F510u;
    ctx->downcount -= 1;
    // 8010F510: b       0x8010F550
    {
            goto label_8010F550;
    }

label_8010F514:
    ctx->pc = 0x8010F514u;
    ctx->downcount -= 8;
    // 8010F514: lwz     r11, 1256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1256);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F518:
    ctx->pc = 0x8010F518u;
    // 8010F518: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F51C:
    ctx->pc = 0x8010F51Cu;
    // 8010F51C: lwz     r0, 108(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F520:
    ctx->pc = 0x8010F520u;
    // 8010F520: lha     r3, 104(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(104);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8010F524:
    ctx->pc = 0x8010F524u;
    // 8010F524: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010F528:
    ctx->pc = 0x8010F528u;
    // 8010F528: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8010F52C:
    ctx->pc = 0x8010F52Cu;
    // 8010F52C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8010F530u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F530:
    ctx->pc = 0x8010F530u;
    ctx->downcount -= 9;
    // 8010F530: lwz     r11, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F534:
    ctx->pc = 0x8010F534u;
    // 8010F534: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010F538:
    ctx->pc = 0x8010F538u;
    // 8010F538: lfs     f1, 4208(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010F538u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4208);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8010F53C:
    ctx->pc = 0x8010F53Cu;
    // 8010F53C: lha     r0, 240(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(240);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8010F540:
    ctx->pc = 0x8010F540u;
    // 8010F540: lwz     r9, 244(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(244);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F544:
    ctx->pc = 0x8010F544u;
    // 8010F544: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8010F548:
    ctx->pc = 0x8010F548u;
    // 8010F548: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_8010F54C:
    ctx->pc = 0x8010F54Cu;
    // 8010F54C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8010F550u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F550:
    ctx->pc = 0x8010F550u;
    ctx->downcount -= 19;
    // 8010F550: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8010F554:
    ctx->pc = 0x8010F554u;
    // 8010F554: lwz     r0, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F558:
    ctx->pc = 0x8010F558u;
    // 8010F558: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010F55C:
    ctx->pc = 0x8010F55Cu;
    // 8010F55C: lmw     r21, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        for (u32 r = 21; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8010F560:
    ctx->pc = 0x8010F560u;
    // 8010F560: lfd     f30, 152(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F560u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8010F564:
    ctx->pc = 0x8010F564u;
    // 8010F564: lfd     f31, 160(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F564u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8010F568:
    ctx->pc = 0x8010F568u;
    // 8010F568: addi    r1, r1, 168
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(168);

label_8010F56C:
    ctx->pc = 0x8010F56Cu;
    // 8010F56C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F570:
    ctx->pc = 0x8010F570u;
    ctx->downcount -= 18;
    // 8010F570: stwu     r1, -128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-128);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010F574:
    ctx->pc = 0x8010F574u;
    // 8010F574: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010F578:
    ctx->pc = 0x8010F578u;
    // 8010F578: stfd     f31, 120(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F578u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8010F57C:
    ctx->pc = 0x8010F57Cu;
    // 8010F57C: stmw     r28, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8010F580:
    ctx->pc = 0x8010F580u;
    // 8010F580: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F584:
    ctx->pc = 0x8010F584u;
    // 8010F584: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010F588:
    ctx->pc = 0x8010F588u;
    // 8010F588: li      r3, 512
    ctx->gpr[3] = (u32)(s32)(512);

label_8010F58C:
    ctx->pc = 0x8010F58Cu;
    // 8010F58C: bl      0x80281C60
    {
            ctx->lr = 0x8010F590u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8010F590:
    ctx->pc = 0x8010F590u;
    ctx->downcount -= 3;
    // 8010F590: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8010F594:
    ctx->pc = 0x8010F594u;
    // 8010F594: addi    r30, r1, 72
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(72);

label_8010F598:
    ctx->pc = 0x8010F598u;
    // 8010F598: bl      0x8010713C
    {
            ctx->lr = 0x8010F59Cu;
            ctx->pc = 0x8010713Cu;
            return;
    }

label_8010F59C:
    ctx->pc = 0x8010F59Cu;
    ctx->downcount -= 4;
    // 8010F59C: stw     r3, 1256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1256);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8010F5A0:
    ctx->pc = 0x8010F5A0u;
    // 8010F5A0: stw     r28, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8010F5A4:
    ctx->pc = 0x8010F5A4u;
    // 8010F5A4: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8010F5A8:
    ctx->pc = 0x8010F5A8u;
    // 8010F5A8: bl      0x80119DF4
    {
            ctx->lr = 0x8010F5ACu;
            ctx->pc = 0x80119DF4u;
            return;
    }

label_8010F5AC:
    ctx->pc = 0x8010F5ACu;
    ctx->downcount -= 3;
    // 8010F5AC: lwz     r3, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010F5B0:
    ctx->pc = 0x8010F5B0u;
    // 8010F5B0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8010F5B4:
    ctx->pc = 0x8010F5B4u;
    // 8010F5B4: bl      0x802198F4
    {
            ctx->lr = 0x8010F5B8u;
            ctx->pc = 0x802198F4u;
            return;
    }

label_8010F5B8:
    ctx->pc = 0x8010F5B8u;
    ctx->downcount -= 28;
    // 8010F5B8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010F5BC:
    ctx->pc = 0x8010F5BCu;
    // 8010F5BC: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_8010F5C0:
    ctx->pc = 0x8010F5C0u;
    // 8010F5C0: lfs     f31, 4240(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010F5C0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4240);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8010F5C4:
    ctx->pc = 0x8010F5C4u;
    // 8010F5C4: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_8010F5C8:
    ctx->pc = 0x8010F5C8u;
    // 8010F5C8: lfs     f0, 4244(r11)
    if (!ppc_fp_available_inline(ctx, 0x8010F5C8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4244);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010F5CC:
    ctx->pc = 0x8010F5CCu;
    // 8010F5CC: stfs     f31, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F5CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8010F5D0:
    ctx->pc = 0x8010F5D0u;
    // 8010F5D0: stw     r3, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8010F5D4:
    ctx->pc = 0x8010F5D4u;
    // 8010F5D4: stfs     f0, 12(r30)
    if (!ppc_fp_available_inline(ctx, 0x8010F5D4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010F5D8:
    ctx->pc = 0x8010F5D8u;
    // 8010F5D8: addi    r3, r10, 4224
    ctx->gpr[3] = ctx->gpr[10] + (u32)(s32)(4224);

label_8010F5DC:
    ctx->pc = 0x8010F5DCu;
    // 8010F5DC: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x8010F5DCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8010F5E0:
    ctx->pc = 0x8010F5E0u;
    // 8010F5E0: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x8010F5E0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8010F5E4:
    ctx->pc = 0x8010F5E4u;
    // 8010F5E4: stw     r28, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8010F5E8:
    ctx->pc = 0x8010F5E8u;
    // 8010F5E8: lfs     f13, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F5E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8010F5EC:
    ctx->pc = 0x8010F5ECu;
    // 8010F5EC: lfs     f0, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F5ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010F5F0:
    ctx->pc = 0x8010F5F0u;
    // 8010F5F0: lfs     f11, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F5F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8010F5F4:
    ctx->pc = 0x8010F5F4u;
    // 8010F5F4: fneg    f13, f13
    if (!ppc_fp_available_inline(ctx, 0x8010F5F4u)) return;
    ctx->fpr[13] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[13]) ^ 0x8000000000000000ull);

label_8010F5F8:
    ctx->pc = 0x8010F5F8u;
    // 8010F5F8: lfs     f12, 84(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F5F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8010F5FC:
    ctx->pc = 0x8010F5FCu;
    // 8010F5FC: fneg    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8010F5FCu)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8010F600:
    ctx->pc = 0x8010F600u;
    // 8010F600: stfs     f11, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F600u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_8010F604:
    ctx->pc = 0x8010F604u;
    // 8010F604: stfs     f12, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F604u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_8010F608:
    ctx->pc = 0x8010F608u;
    // 8010F608: stfs     f0, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F608u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010F60C:
    ctx->pc = 0x8010F60Cu;
    // 8010F60C: stfs     f13, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F60Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8010F610:
    ctx->pc = 0x8010F610u;
    // 8010F610: stfs     f12, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F610u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_8010F614:
    ctx->pc = 0x8010F614u;
    // 8010F614: stfs     f11, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F614u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_8010F618:
    ctx->pc = 0x8010F618u;
    // 8010F618: stfs     f0, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F618u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010F61C:
    ctx->pc = 0x8010F61Cu;
    // 8010F61C: stfs     f13, 84(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F61Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8010F620:
    ctx->pc = 0x8010F620u;
    // 8010F620: stw     r28, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8010F624:
    ctx->pc = 0x8010F624u;
    // 8010F624: bl      0x8011A0C8
    {
            ctx->lr = 0x8010F628u;
            ctx->pc = 0x8011A0C8u;
            return;
    }

label_8010F628:
    ctx->pc = 0x8010F628u;
    ctx->downcount -= 31;
    // 8010F628: lwz     r0, 1256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1256);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F62C:
    ctx->pc = 0x8010F62Cu;
    // 8010F62C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010F630:
    ctx->pc = 0x8010F630u;
    // 8010F630: addi    r9, r9, 4076
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4076);

label_8010F634:
    ctx->pc = 0x8010F634u;
    // 8010F634: stfs     f31, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F634u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8010F638:
    ctx->pc = 0x8010F638u;
    // 8010F638: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F63C:
    ctx->pc = 0x8010F63Cu;
    // 8010F63C: addi    r10, r1, 28
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(28);

label_8010F640:
    ctx->pc = 0x8010F640u;
    // 8010F640: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8010F644:
    ctx->pc = 0x8010F644u;
    // 8010F644: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8010F648:
    ctx->pc = 0x8010F648u;
    // 8010F648: stw     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010F64C:
    ctx->pc = 0x8010F64Cu;
    // 8010F64C: addi    r5, r1, 88
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(88);

label_8010F650:
    ctx->pc = 0x8010F650u;
    // 8010F650: stfs     f31, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x8010F650u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8010F654:
    ctx->pc = 0x8010F654u;
    // 8010F654: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8010F658:
    ctx->pc = 0x8010F658u;
    // 8010F658: stfs     f31, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x8010F658u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8010F65C:
    ctx->pc = 0x8010F65Cu;
    // 8010F65C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010F660:
    ctx->pc = 0x8010F660u;
    // 8010F660: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F664:
    ctx->pc = 0x8010F664u;
    // 8010F664: lwz     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F668:
    ctx->pc = 0x8010F668u;
    // 8010F668: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F66C:
    ctx->pc = 0x8010F66Cu;
    // 8010F66C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F670:
    ctx->pc = 0x8010F670u;
    // 8010F670: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010F674:
    ctx->pc = 0x8010F674u;
    // 8010F674: stw     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8010F678:
    ctx->pc = 0x8010F678u;
    // 8010F678: lwz     r30, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8010F67C:
    ctx->pc = 0x8010F67Cu;
    // 8010F67C: lwz     r11, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F680:
    ctx->pc = 0x8010F680u;
    // 8010F680: lwz     r10, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8010F684:
    ctx->pc = 0x8010F684u;
    // 8010F684: lwz     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F688:
    ctx->pc = 0x8010F688u;
    // 8010F688: addi    r9, r11, 32
    ctx->gpr[9] = ctx->gpr[11] + (u32)(s32)(32);

label_8010F68C:
    ctx->pc = 0x8010F68Cu;
    // 8010F68C: lwz     r8, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8010F690:
    ctx->pc = 0x8010F690u;
    // 8010F690: stw     r10, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8010F694:
    ctx->pc = 0x8010F694u;
    // 8010F694: stw     r8, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8010F698:
    ctx->pc = 0x8010F698u;
    // 8010F698: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F69C:
    ctx->pc = 0x8010F69Cu;
    // 8010F69C: lwz     r7, 100(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(100);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8010F6A0:
    ctx->pc = 0x8010F6A0u;
    // 8010F6A0: bl      0x80113A50
    {
            ctx->lr = 0x8010F6A4u;
            ctx->pc = 0x80113A50u;
            return;
    }

label_8010F6A4:
    ctx->pc = 0x8010F6A4u;
    ctx->downcount -= 9;
    // 8010F6A4: lwz     r11, 1256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1256);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F6A8:
    ctx->pc = 0x8010F6A8u;
    // 8010F6A8: stw     r3, 1260(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1260);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8010F6AC:
    ctx->pc = 0x8010F6ACu;
    // 8010F6AC: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F6B0:
    ctx->pc = 0x8010F6B0u;
    // 8010F6B0: lwz     r0, 108(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F6B4:
    ctx->pc = 0x8010F6B4u;
    // 8010F6B4: lha     r3, 104(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(104);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8010F6B8:
    ctx->pc = 0x8010F6B8u;
    // 8010F6B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010F6BC:
    ctx->pc = 0x8010F6BCu;
    // 8010F6BC: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8010F6C0:
    ctx->pc = 0x8010F6C0u;
    // 8010F6C0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8010F6C4u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F6C4:
    ctx->pc = 0x8010F6C4u;
    ctx->downcount -= 8;
    // 8010F6C4: lwz     r9, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F6C8:
    ctx->pc = 0x8010F6C8u;
    // 8010F6C8: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8010F6C8u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8010F6CC:
    ctx->pc = 0x8010F6CCu;
    // 8010F6CC: lha     r0, 240(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(240);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8010F6D0:
    ctx->pc = 0x8010F6D0u;
    // 8010F6D0: lwz     r9, 244(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(244);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F6D4:
    ctx->pc = 0x8010F6D4u;
    // 8010F6D4: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8010F6D8:
    ctx->pc = 0x8010F6D8u;
    // 8010F6D8: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_8010F6DC:
    ctx->pc = 0x8010F6DCu;
    // 8010F6DC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8010F6E0u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F6E0:
    ctx->pc = 0x8010F6E0u;
    ctx->downcount -= 3;
    // 8010F6E0: lwz     r3, 1256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1256);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010F6E4:
    ctx->pc = 0x8010F6E4u;
    // 8010F6E4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8010F6E8:
    ctx->pc = 0x8010F6E8u;
    // 8010F6E8: bl      0x8010BDA4
    {
            ctx->lr = 0x8010F6ECu;
            ctx->pc = 0x8010BDA4u;
            return;
    }

label_8010F6EC:
    ctx->pc = 0x8010F6ECu;
    ctx->downcount -= 2;
    // 8010F6EC: lwz     r3, 1256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1256);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010F6F0:
    ctx->pc = 0x8010F6F0u;
    // 8010F6F0: bl      0x8010BDEC
    {
            ctx->lr = 0x8010F6F4u;
            ctx->pc = 0x8010BDECu;
            return;
    }

label_8010F6F4:
    ctx->pc = 0x8010F6F4u;
    ctx->downcount -= 3;
    // 8010F6F4: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8010F6F8:
    ctx->pc = 0x8010F6F8u;
    // 8010F6F8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8010F6FC:
    ctx->pc = 0x8010F6FCu;
    // 8010F6FC: bl      0x80119E50
    {
            ctx->lr = 0x8010F700u;
            ctx->pc = 0x80119E50u;
            return;
    }

label_8010F700:
    ctx->pc = 0x8010F700u;
    ctx->downcount -= 17;
    // 8010F700: lwz     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F704:
    ctx->pc = 0x8010F704u;
    // 8010F704: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010F708:
    ctx->pc = 0x8010F708u;
    // 8010F708: lmw     r28, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8010F70C:
    ctx->pc = 0x8010F70Cu;
    // 8010F70C: lfd     f31, 120(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010F70Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8010F710:
    ctx->pc = 0x8010F710u;
    // 8010F710: addi    r1, r1, 128
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(128);

label_8010F714:
    ctx->pc = 0x8010F714u;
    // 8010F714: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F718:
    ctx->pc = 0x8010F718u;
    ctx->downcount -= 22;
    // 8010F718: stwu     r1, -296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-296);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010F71C:
    ctx->pc = 0x8010F71Cu;
    // 8010F71C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010F720:
    ctx->pc = 0x8010F720u;
    // 8010F720: stmw     r27, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8010F724:
    ctx->pc = 0x8010F724u;
    // 8010F724: stw     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F728:
    ctx->pc = 0x8010F728u;
    // 8010F728: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8010F72C:
    ctx->pc = 0x8010F72Cu;
    // 8010F72C: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8010F730:
    ctx->pc = 0x8010F730u;
    // 8010F730: addi    r30, r9, -25052
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-25052);

label_8010F734:
    ctx->pc = 0x8010F734u;
    // 8010F734: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010F738:
    ctx->pc = 0x8010F738u;
    // 8010F738: lwz     r0, 3364(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3364);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F73C:
    ctx->pc = 0x8010F73Cu;
    // 8010F73C: stb     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

label_8010F740:
    ctx->pc = 0x8010F740u;
    // 8010F740: cmpwi   r0, 0
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

label_8010F744:
    ctx->pc = 0x8010F744u;
    // 8010F744: bc    12, 2, 0x8010F838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F838;
        }
    }

label_8010F748:
    ctx->pc = 0x8010F748u;
    ctx->downcount -= 9;
    // 8010F748: lwz     r9, 668(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(668);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F74C:
    ctx->pc = 0x8010F74Cu;
    // 8010F74C: lwz     r10, 304(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(304);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8010F750:
    ctx->pc = 0x8010F750u;
    // 8010F750: lwz     r11, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F754:
    ctx->pc = 0x8010F754u;
    // 8010F754: lwz     r0, 276(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(276);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F758:
    ctx->pc = 0x8010F758u;
    // 8010F758: lha     r3, 272(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(272);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8010F75C:
    ctx->pc = 0x8010F75Cu;
    // 8010F75C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010F760:
    ctx->pc = 0x8010F760u;
    // 8010F760: add   r3, r10, r3
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8010F764:
    ctx->pc = 0x8010F764u;
    // 8010F764: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8010F768u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F768:
    ctx->pc = 0x8010F768u;
    ctx->downcount -= 3;
    // 8010F768: lwz     r0, 3592(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(3592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F76C:
    ctx->pc = 0x8010F76Cu;
    // 8010F76C: cmpw    r3, r0
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

label_8010F770:
    ctx->pc = 0x8010F770u;
    // 8010F770: bc    12, 2, 0x8010F838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F838;
        }
    }

label_8010F774:
    ctx->pc = 0x8010F774u;
    ctx->downcount -= 5;
    // 8010F774: lwz     r30, 424(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(424);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8010F778:
    ctx->pc = 0x8010F778u;
    // 8010F778: addi    r29, r31, 424
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(424);

label_8010F77C:
    ctx->pc = 0x8010F77Cu;
    // 8010F77C: addi    r31, r31, 936
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(936);

label_8010F780:
    ctx->pc = 0x8010F780u;
    // 8010F780: addi    r27, r1, 8
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(8);

label_8010F784:
    ctx->pc = 0x8010F784u;
    // 8010F784: b       0x8010F78C
    {
            goto label_8010F78C;
    }

label_8010F788:
    ctx->downcount -= 1;
    // 8010F788: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_8010F78C:
    ctx->pc = 0x8010F78Cu;
    ctx->downcount -= 3;
    // 8010F78C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F790:
    // 8010F790: cmpw    r30, r0
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

label_8010F794:
    // 8010F794: bc    12, 2, 0x8010F7C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F7C8;
        }
    }

label_8010F798:
    ctx->pc = 0x8010F798u;
    ctx->downcount -= 9;
    // 8010F798: lwz     r28, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8010F79C:
    ctx->pc = 0x8010F79Cu;
    // 8010F79C: lwz     r11, 304(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(304);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F7A0:
    ctx->pc = 0x8010F7A0u;
    // 8010F7A0: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F7A4:
    ctx->pc = 0x8010F7A4u;
    // 8010F7A4: lwz     r0, 276(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(276);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F7A8:
    ctx->pc = 0x8010F7A8u;
    // 8010F7A8: lha     r3, 272(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(272);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8010F7AC:
    ctx->pc = 0x8010F7ACu;
    // 8010F7AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010F7B0:
    // 8010F7B0: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8010F7B4:
    ctx->pc = 0x8010F7B4u;
    // 8010F7B4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8010F7B8u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F7B8:
    ctx->downcount -= 4;
    // 8010F7B8: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8010F7BC:
    ctx->pc = 0x8010F7BCu;
    // 8010F7BC: lwz     r0, -21460(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21460);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F7C0:
    // 8010F7C0: cmpw    r3, r0
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

label_8010F7C4:
    // 8010F7C4: bc    4, 2, 0x8010F788
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010F788u;
                return;
            }
            goto label_8010F788;
        }
    }

label_8010F7C8:
    ctx->pc = 0x8010F7C8u;
    ctx->downcount -= 3;
    // 8010F7C8: lwz     r29, 296(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(296);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8010F7CC:
    ctx->pc = 0x8010F7CCu;
    // 8010F7CC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8010F7D0:
    ctx->pc = 0x8010F7D0u;
    // 8010F7D0: bl      0x8018CFAC
    {
            ctx->lr = 0x8010F7D4u;
            ctx->pc = 0x8018CFACu;
            return;
    }

label_8010F7D4:
    ctx->pc = 0x8010F7D4u;
    ctx->downcount -= 2;
    // 8010F7D4: cmpwi   r3, 0
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

label_8010F7D8:
    ctx->pc = 0x8010F7D8u;
    // 8010F7D8: bc    12, 2, 0x8010F7E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F7E4;
        }
    }

label_8010F7DC:
    ctx->pc = 0x8010F7DCu;
    ctx->downcount -= 2;
    // 8010F7DC: lwz     r9, 304(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(304);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F7E0:
    ctx->pc = 0x8010F7E0u;
    // 8010F7E0: lwz     r29, 828(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(828);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8010F7E4:
    ctx->pc = 0x8010F7E4u;
    ctx->downcount -= 4;
    // 8010F7E4: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_8010F7E8:
    ctx->pc = 0x8010F7E8u;
    // 8010F7E8: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_8010F7EC:
    ctx->pc = 0x8010F7ECu;
    // 8010F7EC: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8010F7F0:
    ctx->pc = 0x8010F7F0u;
    // 8010F7F0: bl      0x80100A40
    {
            ctx->lr = 0x8010F7F4u;
            ctx->pc = 0x80100A40u;
            return;
    }

label_8010F7F4:
    ctx->pc = 0x8010F7F4u;
    ctx->downcount -= 3;
    // 8010F7F4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010F7F8:
    ctx->pc = 0x8010F7F8u;
    // 8010F7F8: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8010F7FC:
    ctx->pc = 0x8010F7FCu;
    // 8010F7FC: bl      0x80100368
    {
            ctx->lr = 0x8010F800u;
            ctx->pc = 0x80100368u;
            return;
    }

label_8010F800:
    ctx->pc = 0x8010F800u;
    ctx->downcount -= 7;
    // 8010F800: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010F804:
    ctx->pc = 0x8010F804u;
    // 8010F804: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8010F808:
    ctx->pc = 0x8010F808u;
    // 8010F808: addi    r4, r4, 4248
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4248);

label_8010F80C:
    ctx->pc = 0x8010F80Cu;
    // 8010F80C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8010F810:
    ctx->pc = 0x8010F810u;
    // 8010F810: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010F814:
    ctx->pc = 0x8010F814u;
    // 8010F814: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8010F818:
    ctx->pc = 0x8010F818u;
    // 8010F818: bl      0x8009258C
    {
            ctx->lr = 0x8010F81Cu;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8010F81C:
    ctx->pc = 0x8010F81Cu;
    ctx->downcount -= 6;
    // 8010F81C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8010F820:
    ctx->pc = 0x8010F820u;
    // 8010F820: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8010F824:
    ctx->pc = 0x8010F824u;
    // 8010F824: addi    r4, r4, 4292
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4292);

label_8010F828:
    ctx->pc = 0x8010F828u;
    // 8010F828: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010F82C:
    ctx->pc = 0x8010F82Cu;
    // 8010F82C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8010F830:
    ctx->pc = 0x8010F830u;
    // 8010F830: bl      0x8009258C
    {
            ctx->lr = 0x8010F834u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8010F834:
    ctx->pc = 0x8010F834u;
    ctx->downcount -= 1;
    // 8010F834: b       0x8010F8B0
    {
            goto label_8010F8B0;
    }

label_8010F838:
    ctx->pc = 0x8010F838u;
    ctx->downcount -= 4;
    // 8010F838: lwz     r9, 668(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(668);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F83C:
    ctx->pc = 0x8010F83Cu;
    // 8010F83C: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8010F840:
    ctx->pc = 0x8010F840u;
    // 8010F840: lwz     r29, 296(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(296);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8010F844:
    ctx->pc = 0x8010F844u;
    // 8010F844: bl      0x8018CFAC
    {
            ctx->lr = 0x8010F848u;
            ctx->pc = 0x8018CFACu;
            return;
    }

label_8010F848:
    ctx->pc = 0x8010F848u;
    ctx->downcount -= 2;
    // 8010F848: cmpwi   r3, 0
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

label_8010F84C:
    ctx->pc = 0x8010F84Cu;
    // 8010F84C: bc    12, 2, 0x8010F85C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F85C;
        }
    }

label_8010F850:
    ctx->pc = 0x8010F850u;
    ctx->downcount -= 3;
    // 8010F850: lwz     r9, 668(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(668);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F854:
    ctx->pc = 0x8010F854u;
    // 8010F854: lwz     r11, 304(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(304);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F858:
    ctx->pc = 0x8010F858u;
    // 8010F858: lwz     r29, 828(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(828);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8010F85C:
    ctx->pc = 0x8010F85Cu;
    ctx->downcount -= 4;
    // 8010F85C: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_8010F860:
    ctx->pc = 0x8010F860u;
    // 8010F860: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_8010F864:
    ctx->pc = 0x8010F864u;
    // 8010F864: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8010F868:
    ctx->pc = 0x8010F868u;
    // 8010F868: bl      0x80100A40
    {
            ctx->lr = 0x8010F86Cu;
            ctx->pc = 0x80100A40u;
            return;
    }

label_8010F86C:
    ctx->pc = 0x8010F86Cu;
    ctx->downcount -= 4;
    // 8010F86C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010F870:
    ctx->pc = 0x8010F870u;
    // 8010F870: addi    r27, r1, 8
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(8);

label_8010F874:
    ctx->pc = 0x8010F874u;
    // 8010F874: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_8010F878:
    ctx->pc = 0x8010F878u;
    // 8010F878: bl      0x80100368
    {
            ctx->lr = 0x8010F87Cu;
            ctx->pc = 0x80100368u;
            return;
    }

label_8010F87C:
    ctx->pc = 0x8010F87Cu;
    ctx->downcount -= 7;
    // 8010F87C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010F880:
    ctx->pc = 0x8010F880u;
    // 8010F880: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8010F884:
    ctx->pc = 0x8010F884u;
    // 8010F884: addi    r4, r4, 4336
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4336);

label_8010F888:
    ctx->pc = 0x8010F888u;
    // 8010F888: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010F88C:
    ctx->pc = 0x8010F88Cu;
    // 8010F88C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8010F890:
    ctx->pc = 0x8010F890u;
    // 8010F890: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8010F894:
    ctx->pc = 0x8010F894u;
    // 8010F894: bl      0x8009258C
    {
            ctx->lr = 0x8010F898u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8010F898:
    ctx->pc = 0x8010F898u;
    ctx->downcount -= 6;
    // 8010F898: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8010F89C:
    ctx->pc = 0x8010F89Cu;
    // 8010F89C: addi    r3, r31, 936
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(936);

label_8010F8A0:
    ctx->pc = 0x8010F8A0u;
    // 8010F8A0: addi    r4, r4, 4380
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4380);

label_8010F8A4:
    ctx->pc = 0x8010F8A4u;
    // 8010F8A4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010F8A8:
    ctx->pc = 0x8010F8A8u;
    // 8010F8A8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8010F8AC:
    ctx->pc = 0x8010F8ACu;
    // 8010F8AC: bl      0x8009258C
    {
            ctx->lr = 0x8010F8B0u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8010F8B0:
    ctx->pc = 0x8010F8B0u;
    ctx->downcount -= 1;
    // 8010F8B0: bl      0x8019D2B0
    {
            ctx->lr = 0x8010F8B4u;
            ctx->pc = 0x8019D2B0u;
            return;
    }

label_8010F8B4:
    ctx->pc = 0x8010F8B4u;
    ctx->downcount -= 2;
    // 8010F8B4: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8010F8B8:
    ctx->pc = 0x8010F8B8u;
    // 8010F8B8: bl      0x8019C388
    {
            ctx->lr = 0x8010F8BCu;
            ctx->pc = 0x8019C388u;
            return;
    }

label_8010F8BC:
    ctx->pc = 0x8010F8BCu;
    ctx->downcount -= 16;
    // 8010F8BC: lwz     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F8C0:
    ctx->pc = 0x8010F8C0u;
    // 8010F8C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010F8C4:
    ctx->pc = 0x8010F8C4u;
    // 8010F8C4: lmw     r27, 276(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(276);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8010F8C8:
    ctx->pc = 0x8010F8C8u;
    // 8010F8C8: addi    r1, r1, 296
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(296);

label_8010F8CC:
    ctx->pc = 0x8010F8CCu;
    // 8010F8CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010F8D0:
    ctx->pc = 0x8010F8D0u;
    ctx->downcount -= 16;
    // 8010F8D0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010F8D4:
    ctx->pc = 0x8010F8D4u;
    // 8010F8D4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010F8D8:
    ctx->pc = 0x8010F8D8u;
    // 8010F8D8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8010F8DC:
    ctx->pc = 0x8010F8DCu;
    // 8010F8DC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F8E0:
    ctx->pc = 0x8010F8E0u;
    // 8010F8E0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010F8E4:
    ctx->pc = 0x8010F8E4u;
    // 8010F8E4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8010F8E8:
    ctx->pc = 0x8010F8E8u;
    ctx->downcount -= 11;
    // 8010F8E8: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F8EC:
    ctx->pc = 0x8010F8ECu;
    // 8010F8EC: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F8F0:
    // 8010F8F0: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_8010F8F4:
    ctx->pc = 0x8010F8F4u;
    // 8010F8F4: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010F8F8:
    // 8010F8F8: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_8010F8FC:
    // 8010F8FC: cmplw   r10, r11
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

label_8010F900:
    // 8010F900: bc    12, 0, 0x8010F928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F928;
        }
    }

label_8010F904:
    ctx->downcount -= 3;
    // 8010F904: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8010F908:
    ctx->pc = 0x8010F908u;
    // 8010F908: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F90C:
    // 8010F90C: b       0x8010FA00
    {
            goto label_8010FA00;
    }

label_8010F910:
    ctx->pc = 0x8010F910u;
    ctx->downcount -= 6;
    // 8010F910: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F914:
    // 8010F914: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8010F918:
    ctx->pc = 0x8010F918u;
    // 8010F918: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F91C:
    ctx->pc = 0x8010F91Cu;
    // 8010F91C: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010F920:
    ctx->pc = 0x8010F920u;
    // 8010F920: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8010F924:
    // 8010F924: b       0x8010F8E8
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010F8E8u;
                return;
            }
            goto label_8010F8E8;
    }

label_8010F928:
    ctx->downcount -= 2;
    // 8010F928: cmplw   r10, r30
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

label_8010F92C:
    // 8010F92C: bc    12, 0, 0x8010F94C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F94C;
        }
    }

label_8010F930:
    ctx->downcount -= 50;
    // 8010F930: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_8010F934:
    ctx->pc = 0x8010F934u;
    // 8010F934: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F938:
    // 8010F938: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_8010F93C:
    ctx->pc = 0x8010F93Cu;
    // 8010F93C: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010F940:
    // 8010F940: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8010F944:
    ctx->pc = 0x8010F944u;
    // 8010F944: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F948:
    // 8010F948: b       0x8010FA00
    {
            goto label_8010FA00;
    }

label_8010F94C:
    ctx->pc = 0x8010F94Cu;
    ctx->downcount -= 8;
    // 8010F94C: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F950:
    // 8010F950: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8010F954:
    // 8010F954: cmpwi   r10, 0
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

label_8010F958:
    // 8010F958: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_8010F95C:
    // 8010F95C: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_8010F960:
    // 8010F960: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_8010F964:
    // 8010F964: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_8010F968:
    // 8010F968: bc    12, 2, 0x8010F988
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F988;
        }
    }

label_8010F96C:
    ctx->downcount -= 7;
    // 8010F96C: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_8010F970:
    // 8010F970: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_8010F974:
    // 8010F974: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8010F978:
    // 8010F978: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8010F97C:
    ctx->pc = 0x8010F97Cu;
    // 8010F97C: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010F980:
    ctx->pc = 0x8010F980u;
    // 8010F980: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8010F984:
    ctx->pc = 0x8010F984u;
    // 8010F984: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8010F988:
    ctx->downcount -= 2;
    // 8010F988: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8010F98C:
    // 8010F98C: bl      0x80281C60
    {
            ctx->lr = 0x8010F990u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8010F990:
    ctx->downcount -= 3;
    // 8010F990: cmpwi   r3, 0
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

label_8010F994:
    ctx->pc = 0x8010F994u;
    // 8010F994: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8010F998:
    // 8010F998: bc    4, 2, 0x8010F9E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8010F9E4;
        }
    }

label_8010F99C:
    ctx->downcount -= 3;
    // 8010F99C: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8010F9A0:
    // 8010F9A0: cmplwi  r11, 0x0080
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

label_8010F9A4:
    // 8010F9A4: bc    12, 1, 0x8010F9D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010F9D0;
        }
    }

label_8010F9A8:
    ctx->downcount -= 2;
    // 8010F9A8: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_8010F9AC:
    // 8010F9AC: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8010F9B0:
    ctx->downcount -= 5;
    // 8010F9B0: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_8010F9B4:
    // 8010F9B4: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8010F9B8:
    ctx->pc = 0x8010F9B8u;
    // 8010F9B8: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8010F9BC:
    // 8010F9BC: cmpwi   r10, 0
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

label_8010F9C0:
    // 8010F9C0: bc    4, 2, 0x8010F910
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010F910u;
                return;
            }
            goto label_8010F910;
        }
    }

label_8010F9C4:
    ctx->downcount -= 3;
    // 8010F9C4: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_8010F9C8:
    // 8010F9C8: cmplwi  r11, 0x0080
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

label_8010F9CC:
    // 8010F9CC: bc    4, 1, 0x8010F9B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010F9B0u;
                return;
            }
            goto label_8010F9B0;
        }
    }

label_8010F9D0:
    ctx->downcount -= 4;
    // 8010F9D0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8010F9D4:
    // 8010F9D4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8010F9D8:
    ctx->pc = 0x8010F9D8u;
    // 8010F9D8: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F9DC:
    // 8010F9DC: bl      0x80281C60
    {
            ctx->lr = 0x8010F9E0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8010F9E0:
    ctx->pc = 0x8010F9E0u;
    ctx->downcount -= 1;
    // 8010F9E0: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8010F9E4:
    ctx->pc = 0x8010F9E4u;
    ctx->downcount -= 7;
    // 8010F9E4: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010F9E8:
    ctx->pc = 0x8010F9E8u;
    // 8010F9E8: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010F9EC:
    // 8010F9EC: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8010F9F0:
    // 8010F9F0: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8010F9F4:
    ctx->pc = 0x8010F9F4u;
    // 8010F9F4: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010F9F8:
    ctx->pc = 0x8010F9F8u;
    // 8010F9F8: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010F9FC:
    // 8010F9FC: b       0x8010F8E8
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010F8E8u;
                return;
            }
            goto label_8010F8E8;
    }

label_8010FA00:
    ctx->pc = 0x8010FA00u;
    ctx->downcount -= 16;
    // 8010FA00: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FA04:
    ctx->pc = 0x8010FA04u;
    // 8010FA04: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010FA08:
    ctx->pc = 0x8010FA08u;
    // 8010FA08: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8010FA0C:
    ctx->pc = 0x8010FA0Cu;
    // 8010FA0C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8010FA10:
    ctx->pc = 0x8010FA10u;
    // 8010FA10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FA14:
    ctx->pc = 0x8010FA14u;
    ctx->downcount -= 21;
    // 8010FA14: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FA18:
    ctx->pc = 0x8010FA18u;
    // 8010FA18: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010FA1C:
    ctx->pc = 0x8010FA1Cu;
    // 8010FA1C: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8010FA20:
    ctx->pc = 0x8010FA20u;
    // 8010FA20: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FA24:
    ctx->pc = 0x8010FA24u;
    // 8010FA24: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_8010FA28:
    ctx->pc = 0x8010FA28u;
    // 8010FA28: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_8010FA2C:
    ctx->pc = 0x8010FA2Cu;
    // 8010FA2C: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8010FA30:
    ctx->pc = 0x8010FA30u;
    // 8010FA30: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8010FA34:
    ctx->pc = 0x8010FA34u;
    // 8010FA34: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8010FA38:
    ctx->pc = 0x8010FA38u;
    // 8010FA38: cmpwi   r30, 0
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

label_8010FA3C:
    ctx->pc = 0x8010FA3Cu;
    // 8010FA3C: bc    12, 2, 0x8010FA4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FA4C;
        }
    }

label_8010FA40:
    ctx->pc = 0x8010FA40u;
    ctx->downcount -= 3;
    // 8010FA40: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FA44:
    ctx->pc = 0x8010FA44u;
    // 8010FA44: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FA48:
    ctx->pc = 0x8010FA48u;
    // 8010FA48: b       0x8010FACC
    {
            goto label_8010FACC;
    }

label_8010FA4C:
    ctx->pc = 0x8010FA4Cu;
    ctx->downcount -= 7;
    // 8010FA4C: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_8010FA50:
    ctx->pc = 0x8010FA50u;
    // 8010FA50: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_8010FA54:
    ctx->pc = 0x8010FA54u;
    // 8010FA54: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_8010FA58:
    ctx->pc = 0x8010FA58u;
    // 8010FA58: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010FA5C:
    ctx->pc = 0x8010FA5Cu;
    // 8010FA5C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8010FA60:
    ctx->pc = 0x8010FA60u;
    // 8010FA60: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_8010FA64:
    ctx->pc = 0x8010FA64u;
    // 8010FA64: bl      0x80003EE0
    {
            ctx->lr = 0x8010FA68u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_8010FA68:
    ctx->pc = 0x8010FA68u;
    ctx->downcount -= 3;
    // 8010FA68: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010FA6C:
    ctx->pc = 0x8010FA6Cu;
    // 8010FA6C: cmpwi   r9, 1
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

label_8010FA70:
    ctx->pc = 0x8010FA70u;
    // 8010FA70: bc    12, 2, 0x8010FAC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FAC8;
        }
    }

label_8010FA74:
    ctx->pc = 0x8010FA74u;
    ctx->downcount -= 9;
    // 8010FA74: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_8010FA78:
    ctx->pc = 0x8010FA78u;
    // 8010FA78: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8010FA7C:
    ctx->pc = 0x8010FA7Cu;
    // 8010FA7C: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_8010FA80:
    ctx->pc = 0x8010FA80u;
    // 8010FA80: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8010FA84:
    ctx->pc = 0x8010FA84u;
    // 8010FA84: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8010FA88:
    ctx->pc = 0x8010FA88u;
    // 8010FA88: cmpwi   r9, 2
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

label_8010FA8C:
    ctx->pc = 0x8010FA8Cu;
    // 8010FA8C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8010FA90:
    ctx->pc = 0x8010FA90u;
    // 8010FA90: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8010FA94:
    ctx->pc = 0x8010FA94u;
    // 8010FA94: bc    4, 2, 0x8010FAA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8010FAA0;
        }
    }

label_8010FA98:
    ctx->pc = 0x8010FA98u;
    ctx->downcount -= 2;
    // 8010FA98: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8010FA9C:
    ctx->pc = 0x8010FA9Cu;
    // 8010FA9C: b       0x8010FAC8
    {
            goto label_8010FAC8;
    }

label_8010FAA0:
    loop_8010FAA0(ctx);
    if (ctx->pc == 0x8010FAC0u) goto label_8010FAC0;
    return;
label_8010FAA4:
    // 8010FAA4: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_8010FAA8:
    // 8010FAA8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8010FAAC:
    ctx->pc = 0x8010FAACu;
    // 8010FAAC: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010FAB0:
    // 8010FAB0: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8010FAB4:
    // 8010FAB4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_8010FAB8:
    // 8010FAB8: cmpw    r9, r8
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

label_8010FABC:
    // 8010FABC: bc    4, 2, 0x8010FAA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010FAA0u;
                return;
            }
            goto label_8010FAA0;
        }
    }

label_8010FAC0:
    ctx->pc = 0x8010FAC0u;
    ctx->downcount -= 2;
    // 8010FAC0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8010FAC4:
    ctx->pc = 0x8010FAC4u;
    // 8010FAC4: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FAC8:
    ctx->pc = 0x8010FAC8u;
    ctx->downcount -= 1;
    // 8010FAC8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010FACC:
    ctx->pc = 0x8010FACCu;
    ctx->downcount -= 17;
    // 8010FACC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8010FAD0:
    ctx->pc = 0x8010FAD0u;
    // 8010FAD0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FAD4:
    ctx->pc = 0x8010FAD4u;
    // 8010FAD4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010FAD8:
    ctx->pc = 0x8010FAD8u;
    // 8010FAD8: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8010FADC:
    ctx->pc = 0x8010FADCu;
    // 8010FADC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8010FAE0:
    ctx->pc = 0x8010FAE0u;
    // 8010FAE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FAE4:
    ctx->pc = 0x8010FAE4u;
    ctx->downcount -= 7;
    // 8010FAE4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FAE8:
    ctx->pc = 0x8010FAE8u;
    // 8010FAE8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010FAEC:
    ctx->pc = 0x8010FAECu;
    // 8010FAEC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FAF0:
    ctx->pc = 0x8010FAF0u;
    // 8010FAF0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8010FAF4:
    ctx->pc = 0x8010FAF4u;
    // 8010FAF4: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_8010FAF8:
    ctx->pc = 0x8010FAF8u;
    // 8010FAF8: cmpw    r4, r0
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

label_8010FAFC:
    ctx->pc = 0x8010FAFCu;
    // 8010FAFC: bc    4, 2, 0x8010FC24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8010FC24;
        }
    }

label_8010FB00:
    ctx->pc = 0x8010FB00u;
    ctx->downcount -= 2;
    // 8010FB00: cmpwi   r3, 0
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

label_8010FB04:
    ctx->pc = 0x8010FB04u;
    // 8010FB04: bc    12, 2, 0x8010FC24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FC24;
        }
    }

label_8010FB08:
    ctx->pc = 0x8010FB08u;
    ctx->downcount -= 5;
    // 8010FB08: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_8010FB0C:
    ctx->pc = 0x8010FB0Cu;
    // 8010FB0C: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_8010FB10:
    ctx->pc = 0x8010FB10u;
    // 8010FB10: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_8010FB14:
    ctx->pc = 0x8010FB14u;
    // 8010FB14: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_8010FB18:
    ctx->pc = 0x8010FB18u;
    // 8010FB18: bl      0x80252AF0
    {
            ctx->lr = 0x8010FB1Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FB1C:
    ctx->pc = 0x8010FB1Cu;
    ctx->downcount -= 5;
    // 8010FB1C: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_8010FB20:
    ctx->pc = 0x8010FB20u;
    // 8010FB20: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_8010FB24:
    ctx->pc = 0x8010FB24u;
    // 8010FB24: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_8010FB28:
    ctx->pc = 0x8010FB28u;
    // 8010FB28: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FB2C:
    ctx->pc = 0x8010FB2Cu;
    // 8010FB2C: bl      0x80252AF0
    {
            ctx->lr = 0x8010FB30u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FB30:
    ctx->pc = 0x8010FB30u;
    ctx->downcount -= 5;
    // 8010FB30: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_8010FB34:
    ctx->pc = 0x8010FB34u;
    // 8010FB34: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8010FB38:
    ctx->pc = 0x8010FB38u;
    // 8010FB38: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_8010FB3C:
    ctx->pc = 0x8010FB3Cu;
    // 8010FB3C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FB40:
    ctx->pc = 0x8010FB40u;
    // 8010FB40: bl      0x80252AF0
    {
            ctx->lr = 0x8010FB44u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FB44:
    ctx->pc = 0x8010FB44u;
    ctx->downcount -= 5;
    // 8010FB44: lis     r3, 25197
    ctx->gpr[3] = ((u32)(s32)(25197) << 16);

label_8010FB48:
    ctx->pc = 0x8010FB48u;
    // 8010FB48: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_8010FB4C:
    ctx->pc = 0x8010FB4Cu;
    // 8010FB4C: ori     r3, r3, 0x7368
    ctx->gpr[3] = ctx->gpr[3] | 0x7368u;

label_8010FB50:
    ctx->pc = 0x8010FB50u;
    // 8010FB50: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FB54:
    ctx->pc = 0x8010FB54u;
    // 8010FB54: bl      0x80252AF0
    {
            ctx->lr = 0x8010FB58u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FB58:
    ctx->pc = 0x8010FB58u;
    ctx->downcount -= 5;
    // 8010FB58: lis     r3, 25199
    ctx->gpr[3] = ((u32)(s32)(25199) << 16);

label_8010FB5C:
    ctx->pc = 0x8010FB5Cu;
    // 8010FB5C: li      r4, 63
    ctx->gpr[4] = (u32)(s32)(63);

label_8010FB60:
    ctx->pc = 0x8010FB60u;
    // 8010FB60: ori     r3, r3, 0x6479
    ctx->gpr[3] = ctx->gpr[3] | 0x6479u;

label_8010FB64:
    ctx->pc = 0x8010FB64u;
    // 8010FB64: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FB68:
    ctx->pc = 0x8010FB68u;
    // 8010FB68: bl      0x80252AF0
    {
            ctx->lr = 0x8010FB6Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FB6C:
    ctx->pc = 0x8010FB6Cu;
    ctx->downcount -= 5;
    // 8010FB6C: lis     r3, 25185
    ctx->gpr[3] = ((u32)(s32)(25185) << 16);

label_8010FB70:
    ctx->pc = 0x8010FB70u;
    // 8010FB70: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8010FB74:
    ctx->pc = 0x8010FB74u;
    // 8010FB74: ori     r3, r3, 0x6E6D
    ctx->gpr[3] = ctx->gpr[3] | 0x6E6Du;

label_8010FB78:
    ctx->pc = 0x8010FB78u;
    // 8010FB78: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FB7C:
    ctx->pc = 0x8010FB7Cu;
    // 8010FB7C: bl      0x80252AF0
    {
            ctx->lr = 0x8010FB80u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FB80:
    ctx->pc = 0x8010FB80u;
    ctx->downcount -= 5;
    // 8010FB80: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_8010FB84:
    ctx->pc = 0x8010FB84u;
    // 8010FB84: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8010FB88:
    ctx->pc = 0x8010FB88u;
    // 8010FB88: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_8010FB8C:
    ctx->pc = 0x8010FB8Cu;
    // 8010FB8C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FB90:
    ctx->pc = 0x8010FB90u;
    // 8010FB90: bl      0x80252AF0
    {
            ctx->lr = 0x8010FB94u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FB94:
    ctx->pc = 0x8010FB94u;
    ctx->downcount -= 5;
    // 8010FB94: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_8010FB98:
    ctx->pc = 0x8010FB98u;
    // 8010FB98: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8010FB9C:
    ctx->pc = 0x8010FB9Cu;
    // 8010FB9C: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_8010FBA0:
    ctx->pc = 0x8010FBA0u;
    // 8010FBA0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FBA4:
    ctx->pc = 0x8010FBA4u;
    // 8010FBA4: bl      0x80252AF0
    {
            ctx->lr = 0x8010FBA8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FBA8:
    ctx->pc = 0x8010FBA8u;
    ctx->downcount -= 5;
    // 8010FBA8: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_8010FBAC:
    ctx->pc = 0x8010FBACu;
    // 8010FBAC: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_8010FBB0:
    ctx->pc = 0x8010FBB0u;
    // 8010FBB0: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_8010FBB4:
    ctx->pc = 0x8010FBB4u;
    // 8010FBB4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FBB8:
    ctx->pc = 0x8010FBB8u;
    // 8010FBB8: bl      0x80252AF0
    {
            ctx->lr = 0x8010FBBCu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FBBC:
    ctx->pc = 0x8010FBBCu;
    ctx->downcount -= 5;
    // 8010FBBC: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_8010FBC0:
    ctx->pc = 0x8010FBC0u;
    // 8010FBC0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8010FBC4:
    ctx->pc = 0x8010FBC4u;
    // 8010FBC4: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_8010FBC8:
    ctx->pc = 0x8010FBC8u;
    // 8010FBC8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FBCC:
    ctx->pc = 0x8010FBCCu;
    // 8010FBCC: bl      0x80252AF0
    {
            ctx->lr = 0x8010FBD0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FBD0:
    ctx->pc = 0x8010FBD0u;
    ctx->downcount -= 5;
    // 8010FBD0: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_8010FBD4:
    ctx->pc = 0x8010FBD4u;
    // 8010FBD4: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_8010FBD8:
    ctx->pc = 0x8010FBD8u;
    // 8010FBD8: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_8010FBDC:
    ctx->pc = 0x8010FBDCu;
    // 8010FBDC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FBE0:
    ctx->pc = 0x8010FBE0u;
    // 8010FBE0: bl      0x80252AF0
    {
            ctx->lr = 0x8010FBE4u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FBE4:
    ctx->pc = 0x8010FBE4u;
    ctx->downcount -= 5;
    // 8010FBE4: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_8010FBE8:
    ctx->pc = 0x8010FBE8u;
    // 8010FBE8: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_8010FBEC:
    ctx->pc = 0x8010FBECu;
    // 8010FBEC: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_8010FBF0:
    ctx->pc = 0x8010FBF0u;
    // 8010FBF0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8010FBF4:
    ctx->pc = 0x8010FBF4u;
    // 8010FBF4: bl      0x80252AF0
    {
            ctx->lr = 0x8010FBF8u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8010FBF8:
    ctx->pc = 0x8010FBF8u;
    ctx->downcount -= 11;
    // 8010FBF8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FBFC:
    ctx->pc = 0x8010FBFCu;
    // 8010FBFC: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_8010FC00:
    ctx->pc = 0x8010FC00u;
    // 8010FC00: lfs     f13, 4808(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FC00u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4808);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8010FC04:
    ctx->pc = 0x8010FC04u;
    // 8010FC04: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_8010FC08:
    ctx->pc = 0x8010FC08u;
    // 8010FC08: lfs     f12, 4812(r11)
    if (!ppc_fp_available_inline(ctx, 0x8010FC08u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4812);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8010FC0C:
    ctx->pc = 0x8010FC0Cu;
    // 8010FC0C: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8010FC10:
    ctx->pc = 0x8010FC10u;
    // 8010FC10: lfs     f0, 4816(r10)
    if (!ppc_fp_available_inline(ctx, 0x8010FC10u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4816);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FC14:
    ctx->pc = 0x8010FC14u;
    // 8010FC14: addi    r11, r9, -21312
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-21312);

label_8010FC18:
    ctx->pc = 0x8010FC18u;
    // 8010FC18: stfs     f13, -21312(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FC18u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21312);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8010FC1C:
    ctx->pc = 0x8010FC1Cu;
    // 8010FC1C: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x8010FC1Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010FC20:
    ctx->pc = 0x8010FC20u;
    // 8010FC20: stfs     f12, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8010FC20u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_8010FC24:
    ctx->pc = 0x8010FC24u;
    ctx->downcount -= 5;
    // 8010FC24: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FC28:
    ctx->pc = 0x8010FC28u;
    // 8010FC28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010FC2C:
    ctx->pc = 0x8010FC2Cu;
    // 8010FC2C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8010FC30:
    ctx->pc = 0x8010FC30u;
    // 8010FC30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FC34:
    ctx->pc = 0x8010FC34u;
    ctx->downcount -= 20;
    // 8010FC34: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FC38:
    ctx->pc = 0x8010FC38u;
    // 8010FC38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010FC3C:
    ctx->pc = 0x8010FC3Cu;
    // 8010FC3C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8010FC40:
    ctx->pc = 0x8010FC40u;
    // 8010FC40: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FC44:
    ctx->pc = 0x8010FC44u;
    // 8010FC44: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8010FC48:
    ctx->pc = 0x8010FC48u;
    // 8010FC48: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010FC4C:
    ctx->pc = 0x8010FC4Cu;
    // 8010FC4C: addi    r9, r9, 2888
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2888);

label_8010FC50:
    ctx->pc = 0x8010FC50u;
    // 8010FC50: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8010FC54:
    ctx->pc = 0x8010FC54u;
    // 8010FC54: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010FC58:
    ctx->pc = 0x8010FC58u;
    // 8010FC58: bl      0x8028C37C
    {
            ctx->lr = 0x8010FC5Cu;
            ctx->pc = 0x8028C37Cu;
            return;
    }

label_8010FC5C:
    ctx->pc = 0x8010FC5Cu;
    ctx->downcount -= 2;
    // 8010FC5C: andi.   r0, r30, 0x0001
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

label_8010FC60:
    ctx->pc = 0x8010FC60u;
    // 8010FC60: bc    12, 2, 0x8010FC6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FC6C;
        }
    }

label_8010FC64:
    ctx->pc = 0x8010FC64u;
    ctx->downcount -= 2;
    // 8010FC64: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8010FC68:
    ctx->pc = 0x8010FC68u;
    // 8010FC68: bl      0x80281D80
    {
            ctx->lr = 0x8010FC6Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8010FC6C:
    ctx->pc = 0x8010FC6Cu;
    ctx->downcount -= 16;
    // 8010FC6C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FC70:
    ctx->pc = 0x8010FC70u;
    // 8010FC70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010FC74:
    ctx->pc = 0x8010FC74u;
    // 8010FC74: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8010FC78:
    ctx->pc = 0x8010FC78u;
    // 8010FC78: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8010FC7C:
    ctx->pc = 0x8010FC7Cu;
    // 8010FC7C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FC80:
    ctx->pc = 0x8010FC80u;
    ctx->downcount -= 2;
    // 8010FC80: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_8010FC84:
    ctx->pc = 0x8010FC84u;
    // 8010FC84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FC88:
    ctx->pc = 0x8010FC88u;
    ctx->downcount -= 21;
    // 8010FC88: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FC8C:
    ctx->pc = 0x8010FC8Cu;
    // 8010FC8C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010FC90:
    ctx->pc = 0x8010FC90u;
    // 8010FC90: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8010FC94:
    ctx->pc = 0x8010FC94u;
    // 8010FC94: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FC98:
    ctx->pc = 0x8010FC98u;
    // 8010FC98: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FC9C:
    ctx->pc = 0x8010FC9Cu;
    // 8010FC9C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010FCA0:
    ctx->pc = 0x8010FCA0u;
    // 8010FCA0: addi    r9, r9, 4696
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4696);

label_8010FCA4:
    ctx->pc = 0x8010FCA4u;
    // 8010FCA4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8010FCA8:
    ctx->pc = 0x8010FCA8u;
    // 8010FCA8: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FCAC:
    ctx->pc = 0x8010FCACu;
    // 8010FCAC: stw     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010FCB0:
    ctx->pc = 0x8010FCB0u;
    // 8010FCB0: bl      0x8010FCCC
    {
            ctx->lr = 0x8010FCB4u;
            goto label_8010FCCC;
    }

label_8010FCB4:
    ctx->pc = 0x8010FCB4u;
    ctx->downcount -= 17;
    // 8010FCB4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8010FCB8:
    ctx->pc = 0x8010FCB8u;
    // 8010FCB8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FCBC:
    ctx->pc = 0x8010FCBCu;
    // 8010FCBC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010FCC0:
    ctx->pc = 0x8010FCC0u;
    // 8010FCC0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8010FCC4:
    ctx->pc = 0x8010FCC4u;
    // 8010FCC4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8010FCC8:
    ctx->pc = 0x8010FCC8u;
    // 8010FCC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FCCC:
    ctx->pc = 0x8010FCCCu;
    ctx->downcount -= 6;
    // 8010FCCC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8010FCD0:
    ctx->pc = 0x8010FCD0u;
    // 8010FCD0: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FCD4:
    ctx->pc = 0x8010FCD4u;
    // 8010FCD4: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FCD8:
    ctx->pc = 0x8010FCD8u;
    // 8010FCD8: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FCDC:
    ctx->pc = 0x8010FCDCu;
    // 8010FCDC: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FCE0:
    ctx->pc = 0x8010FCE0u;
    // 8010FCE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FCE4:
    ctx->pc = 0x8010FCE4u;
    ctx->downcount -= 4;
    // 8010FCE4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8010FCE8:
    ctx->pc = 0x8010FCE8u;
    // 8010FCE8: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FCEC:
    ctx->pc = 0x8010FCECu;
    // 8010FCEC: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FCF0:
    ctx->pc = 0x8010FCF0u;
    // 8010FCF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FCF4:
    ctx->pc = 0x8010FCF4u;
    ctx->downcount -= 4;
    // 8010FCF4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8010FCF8:
    ctx->pc = 0x8010FCF8u;
    // 8010FCF8: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FCFC:
    ctx->pc = 0x8010FCFCu;
    // 8010FCFC: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FD00:
    ctx->pc = 0x8010FD00u;
    // 8010FD00: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FD04:
    ctx->pc = 0x8010FD04u;
    ctx->downcount -= 4;
    // 8010FD04: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8010FD08:
    ctx->pc = 0x8010FD08u;
    // 8010FD08: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FD0C:
    ctx->pc = 0x8010FD0Cu;
    // 8010FD0C: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FD10:
    ctx->pc = 0x8010FD10u;
    // 8010FD10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FD14:
    ctx->pc = 0x8010FD14u;
    ctx->downcount -= 5;
    // 8010FD14: lwz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010FD18:
    ctx->pc = 0x8010FD18u;
    // 8010FD18: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_8010FD1C:
    ctx->pc = 0x8010FD1Cu;
    // 8010FD1C: cmpwi   r9, 0
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

label_8010FD20:
    ctx->pc = 0x8010FD20u;
    // 8010FD20: stw     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010FD24:
    ctx->pc = 0x8010FD24u;
    // 8010FD24: bclr  12, 1
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FD28:
    ctx->pc = 0x8010FD28u;
    ctx->downcount -= 6;
    // 8010FD28: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8010FD2C:
    ctx->pc = 0x8010FD2Cu;
    // 8010FD2C: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FD30:
    ctx->pc = 0x8010FD30u;
    // 8010FD30: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FD34:
    ctx->pc = 0x8010FD34u;
    // 8010FD34: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FD38:
    ctx->pc = 0x8010FD38u;
    // 8010FD38: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FD3C:
    ctx->pc = 0x8010FD3Cu;
    // 8010FD3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FD40:
    ctx->pc = 0x8010FD40u;
    ctx->downcount -= 3;
    // 8010FD40: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FD44:
    ctx->pc = 0x8010FD44u;
    // 8010FD44: cmpwi   r0, 0
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

label_8010FD48:
    ctx->pc = 0x8010FD48u;
    // 8010FD48: bc    12, 2, 0x8010FD58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FD58;
        }
    }

label_8010FD4C:
    ctx->pc = 0x8010FD4Cu;
    ctx->downcount -= 3;
    // 8010FD4C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FD50:
    ctx->pc = 0x8010FD50u;
    // 8010FD50: lfs     f0, 4820(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FD50u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FD54:
    ctx->pc = 0x8010FD54u;
    // 8010FD54: b       0x8010FD60
    {
            goto label_8010FD60;
    }

label_8010FD58:
    ctx->pc = 0x8010FD58u;
    ctx->downcount -= 2;
    // 8010FD58: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FD5C:
    ctx->pc = 0x8010FD5Cu;
    // 8010FD5C: lfs     f0, 4824(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FD5Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FD60:
    ctx->pc = 0x8010FD60u;
    ctx->downcount -= 4;
    // 8010FD60: stfs     f0, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x8010FD60u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010FD64:
    ctx->pc = 0x8010FD64u;
    // 8010FD64: lwz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FD68:
    ctx->pc = 0x8010FD68u;
    // 8010FD68: cmpwi   r0, 0
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

label_8010FD6C:
    ctx->pc = 0x8010FD6Cu;
    // 8010FD6C: bc    12, 2, 0x8010FD7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FD7C;
        }
    }

label_8010FD70:
    ctx->pc = 0x8010FD70u;
    ctx->downcount -= 3;
    // 8010FD70: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FD74:
    ctx->pc = 0x8010FD74u;
    // 8010FD74: lfs     f0, 4820(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FD74u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FD78:
    ctx->pc = 0x8010FD78u;
    // 8010FD78: b       0x8010FD84
    {
            goto label_8010FD84;
    }

label_8010FD7C:
    ctx->pc = 0x8010FD7Cu;
    ctx->downcount -= 2;
    // 8010FD7C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FD80:
    ctx->pc = 0x8010FD80u;
    // 8010FD80: lfs     f0, 4824(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FD80u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FD84:
    ctx->pc = 0x8010FD84u;
    ctx->downcount -= 4;
    // 8010FD84: stfs     f0, 4(r4)
    if (!ppc_fp_available_inline(ctx, 0x8010FD84u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010FD88:
    ctx->pc = 0x8010FD88u;
    // 8010FD88: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FD8C:
    ctx->pc = 0x8010FD8Cu;
    // 8010FD8C: cmpwi   r0, 0
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

label_8010FD90:
    ctx->pc = 0x8010FD90u;
    // 8010FD90: bc    12, 2, 0x8010FDA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FDA0;
        }
    }

label_8010FD94:
    ctx->pc = 0x8010FD94u;
    ctx->downcount -= 3;
    // 8010FD94: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FD98:
    ctx->pc = 0x8010FD98u;
    // 8010FD98: lfs     f0, 4820(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FD98u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FD9C:
    ctx->pc = 0x8010FD9Cu;
    // 8010FD9C: b       0x8010FDA8
    {
            goto label_8010FDA8;
    }

label_8010FDA0:
    ctx->pc = 0x8010FDA0u;
    ctx->downcount -= 2;
    // 8010FDA0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FDA4:
    ctx->pc = 0x8010FDA4u;
    // 8010FDA4: lfs     f0, 4824(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FDA4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FDA8:
    ctx->pc = 0x8010FDA8u;
    ctx->downcount -= 2;
    // 8010FDA8: stfs     f0, 8(r4)
    if (!ppc_fp_available_inline(ctx, 0x8010FDA8u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010FDAC:
    ctx->pc = 0x8010FDACu;
    // 8010FDAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FDB0:
    ctx->pc = 0x8010FDB0u;
    ctx->downcount -= 1;
    // 8010FDB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FDB4:
    ctx->pc = 0x8010FDB4u;
    ctx->downcount -= 1;
    // 8010FDB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FDB8:
    ctx->pc = 0x8010FDB8u;
    ctx->downcount -= 22;
    // 8010FDB8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FDBC:
    ctx->pc = 0x8010FDBCu;
    // 8010FDBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010FDC0:
    ctx->pc = 0x8010FDC0u;
    // 8010FDC0: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8010FDC4:
    ctx->pc = 0x8010FDC4u;
    // 8010FDC4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FDC8:
    ctx->pc = 0x8010FDC8u;
    // 8010FDC8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010FDCC:
    ctx->pc = 0x8010FDCCu;
    // 8010FDCC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FDD0:
    ctx->pc = 0x8010FDD0u;
    // 8010FDD0: addi    r9, r9, 4472
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4472);

label_8010FDD4:
    ctx->pc = 0x8010FDD4u;
    // 8010FDD4: addi    r29, r30, 1264
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(1264);

label_8010FDD8:
    ctx->pc = 0x8010FDD8u;
    // 8010FDD8: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8010FDDC:
    ctx->pc = 0x8010FDDCu;
    // 8010FDDC: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010FDE0:
    ctx->pc = 0x8010FDE0u;
    // 8010FDE0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010FDE4:
    ctx->pc = 0x8010FDE4u;
    // 8010FDE4: bl      0x801D2F74
    {
            ctx->lr = 0x8010FDE8u;
            ctx->pc = 0x801D2F74u;
            return;
    }

label_8010FDE8:
    ctx->pc = 0x8010FDE8u;
    ctx->downcount -= 6;
    // 8010FDE8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8010FDEC:
    ctx->pc = 0x8010FDECu;
    // 8010FDEC: addi    r11, r30, 1276
    ctx->gpr[11] = ctx->gpr[30] + (u32)(s32)(1276);

label_8010FDF0:
    ctx->pc = 0x8010FDF0u;
    // 8010FDF0: addi    r9, r9, 2888
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2888);

label_8010FDF4:
    ctx->pc = 0x8010FDF4u;
    // 8010FDF4: or   r3, r11, r11
    {
        ctx->gpr[3] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8010FDF8:
    ctx->pc = 0x8010FDF8u;
    // 8010FDF8: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010FDFC:
    ctx->pc = 0x8010FDFCu;
    // 8010FDFC: bl      0x8028C37C
    {
            ctx->lr = 0x8010FE00u;
            ctx->pc = 0x8028C37Cu;
            return;
    }

label_8010FE00:
    ctx->pc = 0x8010FE00u;
    ctx->downcount -= 3;
    // 8010FE00: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8010FE04:
    ctx->pc = 0x8010FE04u;
    // 8010FE04: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8010FE08:
    ctx->pc = 0x8010FE08u;
    // 8010FE08: bl      0x801D3364
    {
            ctx->lr = 0x8010FE0Cu;
            ctx->pc = 0x801D3364u;
            return;
    }

label_8010FE0C:
    ctx->pc = 0x8010FE0Cu;
    ctx->downcount -= 3;
    // 8010FE0C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8010FE10:
    ctx->pc = 0x8010FE10u;
    // 8010FE10: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8010FE14:
    ctx->pc = 0x8010FE14u;
    // 8010FE14: bl      0x80112BF0
    {
            ctx->lr = 0x8010FE18u;
            goto label_80112BF0;
    }

label_8010FE18:
    ctx->pc = 0x8010FE18u;
    ctx->downcount -= 16;
    // 8010FE18: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FE1C:
    ctx->pc = 0x8010FE1Cu;
    // 8010FE1C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010FE20:
    ctx->pc = 0x8010FE20u;
    // 8010FE20: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8010FE24:
    ctx->pc = 0x8010FE24u;
    // 8010FE24: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8010FE28:
    ctx->pc = 0x8010FE28u;
    // 8010FE28: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FE2C:
    ctx->pc = 0x8010FE2Cu;
    ctx->downcount -= 6;
    // 8010FE2C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FE30:
    ctx->pc = 0x8010FE30u;
    // 8010FE30: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010FE34:
    ctx->pc = 0x8010FE34u;
    // 8010FE34: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8010FE38:
    ctx->pc = 0x8010FE38u;
    // 8010FE38: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FE3C:
    ctx->pc = 0x8010FE3Cu;
    // 8010FE3C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010FE40:
    ctx->pc = 0x8010FE40u;
    // 8010FE40: bl      0x801130B8
    {
            ctx->lr = 0x8010FE44u;
            goto label_801130B8;
    }

label_8010FE44:
    ctx->pc = 0x8010FE44u;
    ctx->downcount -= 6;
    // 8010FE44: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8010FE48:
    ctx->pc = 0x8010FE48u;
    // 8010FE48: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FE4C:
    ctx->pc = 0x8010FE4Cu;
    // 8010FE4C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8010FE50:
    ctx->pc = 0x8010FE50u;
    // 8010FE50: lfs     f0, 4828(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FE50u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FE54:
    ctx->pc = 0x8010FE54u;
    // 8010FE54: addi    r11, r31, 1236
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(1236);

label_8010FE58:
    ctx->pc = 0x8010FE58u;
    ctx->downcount -= 3;
    // 8010FE58: stfs     f0, 0(r11)
    if (!ppc_fp_available_inline(ctx, 0x8010FE58u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010FE5C:
    // 8010FE5C: addi    r11, r11, -4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-4);

label_8010FE60:
    // 8010FE60: bc    16, 0, 0x8010FE58
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010FE58u;
                return;
            }
            goto label_8010FE58;
        }
    }

label_8010FE64:
    ctx->pc = 0x8010FE64u;
    ctx->downcount -= 3;
    // 8010FE64: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_8010FE68:
    ctx->pc = 0x8010FE68u;
    // 8010FE68: addi    r3, r3, -25052
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-25052);

label_8010FE6C:
    ctx->pc = 0x8010FE6Cu;
    // 8010FE6C: bl      0x8010021C
    {
            ctx->lr = 0x8010FE70u;
            ctx->pc = 0x8010021Cu;
            return;
    }

label_8010FE70:
    ctx->pc = 0x8010FE70u;
    ctx->downcount -= 12;
    // 8010FE70: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FE74:
    ctx->pc = 0x8010FE74u;
    // 8010FE74: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8010FE78:
    ctx->pc = 0x8010FE78u;
    // 8010FE78: lfs     f0, 4832(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FE78u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4832);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8010FE7C:
    ctx->pc = 0x8010FE7Cu;
    // 8010FE7C: stw     r3, 1252(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1252);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8010FE80:
    ctx->pc = 0x8010FE80u;
    // 8010FE80: stfs     f0, 1248(r31)
    if (!ppc_fp_available_inline(ctx, 0x8010FE80u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1248);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8010FE84:
    ctx->pc = 0x8010FE84u;
    // 8010FE84: stw     r0, 1240(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1240);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FE88:
    ctx->pc = 0x8010FE88u;
    // 8010FE88: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FE8C:
    ctx->pc = 0x8010FE8Cu;
    // 8010FE8C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010FE90:
    ctx->pc = 0x8010FE90u;
    // 8010FE90: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8010FE94:
    ctx->pc = 0x8010FE94u;
    // 8010FE94: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8010FE98:
    ctx->pc = 0x8010FE98u;
    // 8010FE98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FE9C:
    ctx->pc = 0x8010FE9Cu;
    ctx->downcount -= 8;
    // 8010FE9C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FEA0:
    ctx->pc = 0x8010FEA0u;
    // 8010FEA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010FEA4:
    ctx->pc = 0x8010FEA4u;
    // 8010FEA4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8010FEA8:
    ctx->pc = 0x8010FEA8u;
    // 8010FEA8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FEAC:
    ctx->pc = 0x8010FEACu;
    // 8010FEAC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010FEB0:
    ctx->pc = 0x8010FEB0u;
    // 8010FEB0: lwz     r3, 1256(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1256);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010FEB4:
    ctx->pc = 0x8010FEB4u;
    // 8010FEB4: cmpwi   r3, 0
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

label_8010FEB8:
    ctx->pc = 0x8010FEB8u;
    // 8010FEB8: bc    12, 2, 0x8010FED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FED8;
        }
    }

label_8010FEBC:
    ctx->pc = 0x8010FEBCu;
    ctx->downcount -= 2;
    // 8010FEBC: lfs     f1, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x8010FEBCu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8010FEC0:
    ctx->pc = 0x8010FEC0u;
    // 8010FEC0: bl      0x80108BE0
    {
            ctx->lr = 0x8010FEC4u;
            ctx->pc = 0x80108BE0u;
            return;
    }

label_8010FEC4:
    ctx->pc = 0x8010FEC4u;
    ctx->downcount -= 3;
    // 8010FEC4: lwz     r3, 1256(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1256);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010FEC8:
    ctx->pc = 0x8010FEC8u;
    // 8010FEC8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8010FECC:
    ctx->pc = 0x8010FECCu;
    // 8010FECC: bl      0x8010BDC8
    {
            ctx->lr = 0x8010FED0u;
            ctx->pc = 0x8010BDC8u;
            return;
    }

label_8010FED0:
    ctx->pc = 0x8010FED0u;
    ctx->downcount -= 2;
    // 8010FED0: lwz     r3, 1256(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1256);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010FED4:
    ctx->pc = 0x8010FED4u;
    // 8010FED4: bl      0x8010BDEC
    {
            ctx->lr = 0x8010FED8u;
            ctx->pc = 0x8010BDECu;
            return;
    }

label_8010FED8:
    ctx->pc = 0x8010FED8u;
    ctx->downcount -= 6;
    // 8010FED8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FEDC:
    ctx->pc = 0x8010FEDCu;
    // 8010FEDC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8010FEE0:
    ctx->pc = 0x8010FEE0u;
    // 8010FEE0: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8010FEE4:
    ctx->pc = 0x8010FEE4u;
    // 8010FEE4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8010FEE8:
    ctx->pc = 0x8010FEE8u;
    // 8010FEE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FEEC:
    ctx->pc = 0x8010FEECu;
    ctx->downcount -= 5;
    // 8010FEEC: lwz     r0, 424(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(424);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FEF0:
    ctx->pc = 0x8010FEF0u;
    // 8010FEF0: lwz     r3, 428(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(428);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8010FEF4:
    ctx->pc = 0x8010FEF4u;
    // 8010FEF4: subf   r3, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_8010FEF8:
    ctx->pc = 0x8010FEF8u;
    // 8010FEF8: srawi r3, r3, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[3];
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

label_8010FEFC:
    ctx->pc = 0x8010FEFCu;
    // 8010FEFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FF00:
    ctx->pc = 0x8010FF00u;
    ctx->downcount -= 3;
    // 8010FF00: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FF04:
    ctx->pc = 0x8010FF04u;
    // 8010FF04: or.   r4, r4, r4
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[4];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8010FF08:
    ctx->pc = 0x8010FF08u;
    // 8010FF08: bc    12, 2, 0x8010FF40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8010FF40;
        }
    }

label_8010FF0C:
    ctx->pc = 0x8010FF0Cu;
    ctx->downcount -= 13;
    // 8010FF0C: lwz     r8, 304(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(304);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8010FF10:
    ctx->pc = 0x8010FF10u;
    // 8010FF10: lis     r7, 17200
    ctx->gpr[7] = ((u32)(s32)(17200) << 16);

label_8010FF14:
    ctx->pc = 0x8010FF14u;
    // 8010FF14: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FF18:
    ctx->pc = 0x8010FF18u;
    // 8010FF18: lwz     r11, 860(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(860);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010FF1C:
    ctx->pc = 0x8010FF1Cu;
    // 8010FF1C: lfd     f0, 4840(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FF1Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4840);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8010FF20:
    ctx->pc = 0x8010FF20u;
    // 8010FF20: lwz     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FF24:
    ctx->pc = 0x8010FF24u;
    // 8010FF24: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8010FF28:
    ctx->pc = 0x8010FF28u;
    // 8010FF28: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FF2C:
    ctx->pc = 0x8010FF2Cu;
    // 8010FF2C: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8010FF30:
    ctx->pc = 0x8010FF30u;
    // 8010FF30: lfd     f1, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FF30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8010FF34:
    ctx->pc = 0x8010FF34u;
    // 8010FF34: fsub   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8010FF34u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_8010FF38:
    ctx->pc = 0x8010FF38u;
    // 8010FF38: frsp    f1, f1
    if (!ppc_fp_available_inline(ctx, 0x8010FF38u)) return;
    ppc_frsp(ctx, 1, 1);

label_8010FF3C:
    ctx->pc = 0x8010FF3Cu;
    // 8010FF3C: b       0x8010FF48
    {
            goto label_8010FF48;
    }

label_8010FF40:
    ctx->pc = 0x8010FF40u;
    ctx->downcount -= 2;
    // 8010FF40: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8010FF44:
    ctx->pc = 0x8010FF44u;
    // 8010FF44: lfs     f1, 4836(r9)
    if (!ppc_fp_available_inline(ctx, 0x8010FF44u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4836);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8010FF48:
    ctx->pc = 0x8010FF48u;
    ctx->downcount -= 2;
    // 8010FF48: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8010FF4C:
    ctx->pc = 0x8010FF4Cu;
    // 8010FF4C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FF50:
    ctx->pc = 0x8010FF50u;
    ctx->downcount -= 9;
    // 8010FF50: addi    r3, r3, 1276
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1276);

label_8010FF54:
    ctx->pc = 0x8010FF54u;
    // 8010FF54: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8010FF58:
    ctx->pc = 0x8010FF58u;
    // 8010FF58: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FF5C:
    ctx->pc = 0x8010FF5Cu;
    // 8010FF5C: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FF60:
    ctx->pc = 0x8010FF60u;
    // 8010FF60: lwz     r11, 860(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(860);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8010FF64:
    ctx->pc = 0x8010FF64u;
    // 8010FF64: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8010FF68:
    ctx->pc = 0x8010FF68u;
    // 8010FF68: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_8010FF6C:
    ctx->pc = 0x8010FF6Cu;
    // 8010FF6C: stw     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010FF70:
    ctx->pc = 0x8010FF70u;
    // 8010FF70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8010FF74:
    ctx->pc = 0x8010FF74u;
    ctx->downcount -= 18;
    // 8010FF74: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8010FF78:
    ctx->pc = 0x8010FF78u;
    // 8010FF78: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8010FF7C:
    ctx->pc = 0x8010FF7Cu;
    // 8010FF7C: stw     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8010FF80:
    ctx->pc = 0x8010FF80u;
    // 8010FF80: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FF84:
    ctx->pc = 0x8010FF84u;
    // 8010FF84: lis     r12, 512
    ctx->gpr[12] = ((u32)(s32)(512) << 16);

label_8010FF88:
    ctx->pc = 0x8010FF88u;
    // 8010FF88: addi    r0, r1, 160
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(160);

label_8010FF8C:
    ctx->pc = 0x8010FF8Cu;
    // 8010FF8C: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_8010FF90:
    ctx->pc = 0x8010FF90u;
    // 8010FF90: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8010FF94:
    ctx->pc = 0x8010FF94u;
    // 8010FF94: stw     r11, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8010FF98:
    ctx->pc = 0x8010FF98u;
    // 8010FF98: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8010FF9C:
    ctx->pc = 0x8010FF9Cu;
    // 8010FF9C: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8010FFA0:
    ctx->pc = 0x8010FFA0u;
    // 8010FFA0: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8010FFA4:
    ctx->pc = 0x8010FFA4u;
    // 8010FFA4: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8010FFA8:
    ctx->pc = 0x8010FFA8u;
    // 8010FFA8: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8010FFAC:
    ctx->pc = 0x8010FFACu;
    // 8010FFAC: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8010FFB0:
    ctx->pc = 0x8010FFB0u;
    // 8010FFB0: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8010FFB4:
    ctx->pc = 0x8010FFB4u;
    // 8010FFB4: stw     r12, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8010FFB8:
    ctx->pc = 0x8010FFB8u;
    // 8010FFB8: bc    4, 6, 0x8010FFDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8010FFDC;
        }
    }

label_8010FFBC:
    ctx->pc = 0x8010FFBCu;
    ctx->downcount -= 8;
    // 8010FFBC: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FFBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_8010FFC0:
    ctx->pc = 0x8010FFC0u;
    // 8010FFC0: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FFC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_8010FFC4:
    ctx->pc = 0x8010FFC4u;
    // 8010FFC4: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FFC4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_8010FFC8:
    ctx->pc = 0x8010FFC8u;
    // 8010FFC8: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FFC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_8010FFCC:
    ctx->pc = 0x8010FFCCu;
    // 8010FFCC: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FFCCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_8010FFD0:
    ctx->pc = 0x8010FFD0u;
    // 8010FFD0: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FFD0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_8010FFD4:
    ctx->pc = 0x8010FFD4u;
    // 8010FFD4: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FFD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_8010FFD8:
    ctx->pc = 0x8010FFD8u;
    // 8010FFD8: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8010FFD8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_8010FFDC:
    ctx->pc = 0x8010FFDCu;
    ctx->downcount -= 12;
    // 8010FFDC: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_8010FFE0:
    ctx->pc = 0x8010FFE0u;
    // 8010FFE0: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_8010FFE4:
    ctx->pc = 0x8010FFE4u;
    // 8010FFE4: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8010FFE8:
    ctx->pc = 0x8010FFE8u;
    // 8010FFE8: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8010FFEC:
    ctx->pc = 0x8010FFECu;
    // 8010FFEC: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8010FFF0:
    ctx->pc = 0x8010FFF0u;
    // 8010FFF0: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8010FFF4:
    ctx->pc = 0x8010FFF4u;
    // 8010FFF4: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8010FFF8:
    ctx->pc = 0x8010FFF8u;
    // 8010FFF8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8010FFFC:
    ctx->pc = 0x8010FFFCu;
    // 8010FFFC: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110000:
    ctx->pc = 0x80110000u;
    // 80110000: li      r4, 260
    ctx->gpr[4] = (u32)(s32)(260);

label_80110004:
    ctx->pc = 0x80110004u;
    // 80110004: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80110008:
    ctx->pc = 0x80110008u;
    // 80110008: bl      0x80296720
    {
            ctx->lr = 0x8011000Cu;
            ctx->pc = 0x80296720u;
            return;
    }

label_8011000C:
    ctx->pc = 0x8011000Cu;
    ctx->downcount -= 8;
    // 8011000C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80110010:
    ctx->pc = 0x80110010u;
    // 80110010: stb     r0, 259(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(259);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80110014:
    ctx->pc = 0x80110014u;
    // 80110014: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110018:
    ctx->pc = 0x80110018u;
    // 80110018: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8011001C:
    ctx->pc = 0x8011001Cu;
    // 8011001C: lwz     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80110020:
    ctx->pc = 0x80110020u;
    // 80110020: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_80110024:
    ctx->pc = 0x80110024u;
    // 80110024: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110028:
    ctx->pc = 0x80110028u;
    ctx->downcount -= 7;
    // 80110028: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8011002C:
    ctx->pc = 0x8011002Cu;
    // 8011002C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80110030:
    ctx->pc = 0x80110030u;
    // 80110030: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110034:
    ctx->pc = 0x80110034u;
    // 80110034: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80110038:
    ctx->pc = 0x80110038u;
    // 80110038: lis     r4, 28271
    ctx->gpr[4] = ((u32)(s32)(28271) << 16);

label_8011003C:
    ctx->pc = 0x8011003Cu;
    // 8011003C: ori     r4, r4, 0x6465
    ctx->gpr[4] = ctx->gpr[4] | 0x6465u;

label_80110040:
    ctx->pc = 0x80110040u;
    // 80110040: bl      0x80213200
    {
            ctx->lr = 0x80110044u;
            ctx->pc = 0x80213200u;
            return;
    }

label_80110044:
    ctx->pc = 0x80110044u;
    ctx->downcount -= 5;
    // 80110044: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110048:
    ctx->pc = 0x80110048u;
    // 80110048: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8011004C:
    ctx->pc = 0x8011004Cu;
    // 8011004C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80110050:
    ctx->pc = 0x80110050u;
    // 80110050: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110054:
    ctx->pc = 0x80110054u;
    ctx->downcount -= 7;
    // 80110054: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80110058:
    ctx->pc = 0x80110058u;
    // 80110058: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8011005C:
    ctx->pc = 0x8011005Cu;
    // 8011005C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110060:
    ctx->pc = 0x80110060u;
    // 80110060: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80110064:
    ctx->pc = 0x80110064u;
    // 80110064: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80110068:
    ctx->pc = 0x80110068u;
    // 80110068: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_8011006C:
    ctx->pc = 0x8011006Cu;
    // 8011006C: bl      0x8010FAE4
    {
            ctx->lr = 0x80110070u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8010FAE4u;
                return;
            }
            goto label_8010FAE4;
    }

label_80110070:
    ctx->pc = 0x80110070u;
    ctx->downcount -= 5;
    // 80110070: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110074:
    ctx->pc = 0x80110074u;
    // 80110074: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80110078:
    ctx->pc = 0x80110078u;
    // 80110078: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8011007C:
    ctx->pc = 0x8011007Cu;
    // 8011007C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110080:
    ctx->pc = 0x80110080u;
    ctx->downcount -= 20;
    // 80110080: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80110084:
    ctx->pc = 0x80110084u;
    // 80110084: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80110088:
    ctx->pc = 0x80110088u;
    // 80110088: stfd     f31, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110088u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8011008C:
    ctx->pc = 0x8011008Cu;
    // 8011008C: stmw     r26, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80110090:
    ctx->pc = 0x80110090u;
    // 80110090: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110094:
    ctx->pc = 0x80110094u;
    // 80110094: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110098:
    ctx->pc = 0x80110098u;
    // 80110098: fmr    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80110098u)) return;
    ctx->fpr[0] = ctx->fpr[1];

label_8011009C:
    ctx->pc = 0x8011009Cu;
    // 8011009C: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801100A0:
    ctx->pc = 0x801100A0u;
    // 801100A0: cmpwi   r0, 0
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

label_801100A4:
    ctx->pc = 0x801100A4u;
    // 801100A4: bc    12, 2, 0x801101F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801101F4;
        }
    }

label_801100A8:
    ctx->pc = 0x801100A8u;
    ctx->downcount -= 5;
    // 801100A8: lfs     f1, 0(r27)
    if (!ppc_fp_available_inline(ctx, 0x801100A8u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801100AC:
    ctx->pc = 0x801100ACu;
    // 801100AC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801100B0:
    ctx->pc = 0x801100B0u;
    // 801100B0: lfs     f2, 4872(r9)
    if (!ppc_fp_available_inline(ctx, 0x801100B0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4872);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_801100B4:
    ctx->pc = 0x801100B4u;
    // 801100B4: fadds   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x801100B4u)) return;
    ppc_fadds(ctx, 1, 1, 0);

label_801100B8:
    ctx->pc = 0x801100B8u;
    // 801100B8: bl      0x8029E2D4
    {
            ctx->lr = 0x801100BCu;
            ctx->pc = 0x8029E2D4u;
            return;
    }

label_801100BC:
    ctx->pc = 0x801100BCu;
    ctx->downcount -= 4;
    // 801100BC: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801100C0:
    ctx->pc = 0x801100C0u;
    // 801100C0: stfs     f1, 0(r27)
    if (!ppc_fp_available_inline(ctx, 0x801100C0u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801100C4:
    ctx->pc = 0x801100C4u;
    // 801100C4: cmpwi   r0, 0
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

label_801100C8:
    ctx->pc = 0x801100C8u;
    // 801100C8: bc    12, 2, 0x801100E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801100E8;
        }
    }

label_801100CC:
    ctx->pc = 0x801100CCu;
    ctx->downcount -= 4;
    // 801100CC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801100D0:
    ctx->pc = 0x801100D0u;
    // 801100D0: lfs     f13, 4876(r9)
    if (!ppc_fp_available_inline(ctx, 0x801100D0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4876);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801100D4:
    ctx->pc = 0x801100D4u;
    // 801100D4: fcmpu   cr0, f1, f13
    if (!ppc_fp_available_inline(ctx, 0x801100D4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[13], false);

label_801100D8:
    ctx->pc = 0x801100D8u;
    // 801100D8: bc    12, 0, 0x801100F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801100F0;
        }
    }

label_801100DC:
    ctx->pc = 0x801100DCu;
    ctx->downcount -= 3;
    // 801100DC: fsubs   f0, f1, f13
    if (!ppc_fp_available_inline(ctx, 0x801100DCu)) return;
    ppc_fsubs(ctx, 0, 1, 13);

label_801100E0:
    ctx->pc = 0x801100E0u;
    // 801100E0: fsubs   f1, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x801100E0u)) return;
    ppc_fsubs(ctx, 1, 13, 0);

label_801100E4:
    ctx->pc = 0x801100E4u;
    // 801100E4: b       0x801100F0
    {
            goto label_801100F0;
    }

label_801100E8:
    ctx->pc = 0x801100E8u;
    ctx->downcount -= 2;
    // 801100E8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801100EC:
    ctx->pc = 0x801100ECu;
    // 801100EC: lfs     f1, 4876(r9)
    if (!ppc_fp_available_inline(ctx, 0x801100ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4876);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801100F0:
    ctx->pc = 0x801100F0u;
    ctx->downcount -= 11;
    // 801100F0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801100F4:
    ctx->pc = 0x801100F4u;
    // 801100F4: lwz     r26, -27512(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27512);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_801100F8:
    ctx->pc = 0x801100F8u;
    // 801100F8: lfs     f31, 4876(r9)
    if (!ppc_fp_available_inline(ctx, 0x801100F8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4876);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_801100FC:
    ctx->pc = 0x801100FCu;
    // 801100FC: addi    r31, r1, 8
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(8);

label_80110100:
    ctx->pc = 0x80110100u;
    // 80110100: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80110104:
    ctx->pc = 0x80110104u;
    // 80110104: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80110108:
    ctx->pc = 0x80110108u;
    // 80110108: stfs     f31, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110108u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8011010C:
    ctx->pc = 0x8011010Cu;
    // 8011010C: stfs     f1, 12(r31)
    if (!ppc_fp_available_inline(ctx, 0x8011010Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80110110:
    ctx->pc = 0x80110110u;
    // 80110110: stfs     f31, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x80110110u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80110114:
    ctx->pc = 0x80110114u;
    // 80110114: stfs     f31, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x80110114u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80110118:
    ctx->pc = 0x80110118u;
    // 80110118: bl      0x801D54C0
    {
            ctx->lr = 0x8011011Cu;
            ctx->pc = 0x801D54C0u;
            return;
    }

label_8011011C:
    ctx->pc = 0x8011011Cu;
    ctx->downcount -= 6;
    // 8011011C: lis     r30, -32709
    ctx->gpr[30] = ((u32)(s32)(-32709) << 16);

label_80110120:
    ctx->pc = 0x80110120u;
    // 80110120: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80110124:
    ctx->pc = 0x80110124u;
    // 80110124: addi    r30, r30, 19088
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(19088);

label_80110128:
    ctx->pc = 0x80110128u;
    // 80110128: lwz     r28, -27508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27508);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8011012C:
    ctx->pc = 0x8011012Cu;
    // 8011012C: addi    r3, r3, -25052
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-25052);

label_80110130:
    ctx->pc = 0x80110130u;
    // 80110130: bl      0x80100A40
    {
            ctx->lr = 0x80110134u;
            ctx->pc = 0x80100A40u;
            return;
    }

label_80110134:
    ctx->pc = 0x80110134u;
    ctx->downcount -= 6;
    // 80110134: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80110138:
    ctx->pc = 0x80110138u;
    // 80110138: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8011013C:
    ctx->pc = 0x8011013Cu;
    // 8011013C: lwzx    r29, r30, r3
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[3];
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80110140:
    ctx->pc = 0x80110140u;
    // 80110140: addi    r4, r4, 4864
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4864);

label_80110144:
    ctx->pc = 0x80110144u;
    // 80110144: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80110148:
    ctx->pc = 0x80110148u;
    // 80110148: bl      0x80254680
    {
            ctx->lr = 0x8011014Cu;
            ctx->pc = 0x80254680u;
            return;
    }

label_8011014C:
    ctx->pc = 0x8011014Cu;
    ctx->downcount -= 5;
    // 8011014C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110150:
    ctx->pc = 0x80110150u;
    // 80110150: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80110154:
    ctx->pc = 0x80110154u;
    // 80110154: addi    r6, r13, -7228
    ctx->gpr[6] = ctx->gpr[13] + (u32)(s32)(-7228);

label_80110158:
    ctx->pc = 0x80110158u;
    // 80110158: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8011015C:
    ctx->pc = 0x8011015Cu;
    // 8011015C: bl      0x80254540
    {
            ctx->lr = 0x80110160u;
            ctx->pc = 0x80254540u;
            return;
    }

label_80110160:
    ctx->pc = 0x80110160u;
    ctx->downcount -= 4;
    // 80110160: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110164:
    ctx->pc = 0x80110164u;
    // 80110164: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80110168:
    ctx->pc = 0x80110168u;
    // 80110168: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8011016C:
    ctx->pc = 0x8011016Cu;
    // 8011016C: bl      0x801D4DA4
    {
            ctx->lr = 0x80110170u;
            ctx->pc = 0x801D4DA4u;
            return;
    }

label_80110170:
    ctx->pc = 0x80110170u;
    ctx->downcount -= 3;
    // 80110170: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110174:
    ctx->pc = 0x80110174u;
    // 80110174: cmpwi   r0, 0
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

label_80110178:
    ctx->pc = 0x80110178u;
    // 80110178: bc    12, 2, 0x801101B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801101B8;
        }
    }

label_8011017C:
    ctx->pc = 0x8011017Cu;
    ctx->downcount -= 14;
    // 8011017C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80110180:
    ctx->pc = 0x80110180u;
    // 80110180: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80110184:
    ctx->pc = 0x80110184u;
    // 80110184: lfs     f0, 4880(r9)
    if (!ppc_fp_available_inline(ctx, 0x80110184u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4880);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80110188:
    ctx->pc = 0x80110188u;
    // 80110188: addi    r10, r1, 16
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(16);

label_8011018C:
    ctx->pc = 0x8011018Cu;
    // 8011018C: lfs     f13, 4884(r11)
    if (!ppc_fp_available_inline(ctx, 0x8011018Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4884);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80110190:
    ctx->pc = 0x80110190u;
    // 80110190: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80110194:
    ctx->pc = 0x80110194u;
    // 80110194: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x80110194u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_80110198:
    ctx->pc = 0x80110198u;
    // 80110198: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8011019C:
    ctx->pc = 0x8011019Cu;
    // 8011019C: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011019Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801101A0:
    ctx->pc = 0x801101A0u;
    // 801101A0: or   r5, r10, r10
    {
        ctx->gpr[5] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801101A4:
    ctx->pc = 0x801101A4u;
    // 801101A4: stfs     f13, 4(r10)
    if (!ppc_fp_available_inline(ctx, 0x801101A4u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801101A8:
    ctx->pc = 0x801101A8u;
    // 801101A8: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801101AC:
    ctx->pc = 0x801101ACu;
    // 801101AC: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801101ACu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801101B0:
    ctx->pc = 0x801101B0u;
    // 801101B0: bl      0x80092040
    {
            ctx->lr = 0x801101B4u;
            ctx->pc = 0x80092040u;
            return;
    }

label_801101B4:
    ctx->pc = 0x801101B4u;
    ctx->downcount -= 1;
    // 801101B4: b       0x801101F0
    {
            goto label_801101F0;
    }

label_801101B8:
    ctx->pc = 0x801101B8u;
    ctx->downcount -= 14;
    // 801101B8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801101BC:
    ctx->pc = 0x801101BCu;
    // 801101BC: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801101C0:
    ctx->pc = 0x801101C0u;
    // 801101C0: lfs     f0, 4880(r9)
    if (!ppc_fp_available_inline(ctx, 0x801101C0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4880);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801101C4:
    ctx->pc = 0x801101C4u;
    // 801101C4: addi    r10, r1, 16
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(16);

label_801101C8:
    ctx->pc = 0x801101C8u;
    // 801101C8: lfs     f13, 4888(r11)
    if (!ppc_fp_available_inline(ctx, 0x801101C8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4888);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801101CC:
    ctx->pc = 0x801101CCu;
    // 801101CC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801101D0:
    ctx->pc = 0x801101D0u;
    // 801101D0: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x801101D0u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_801101D4:
    ctx->pc = 0x801101D4u;
    // 801101D4: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801101D8:
    ctx->pc = 0x801101D8u;
    // 801101D8: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x801101D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801101DC:
    ctx->pc = 0x801101DCu;
    // 801101DC: or   r5, r10, r10
    {
        ctx->gpr[5] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801101E0:
    ctx->pc = 0x801101E0u;
    // 801101E0: stfs     f13, 4(r10)
    if (!ppc_fp_available_inline(ctx, 0x801101E0u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801101E4:
    ctx->pc = 0x801101E4u;
    // 801101E4: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801101E8:
    ctx->pc = 0x801101E8u;
    // 801101E8: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801101E8u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801101EC:
    ctx->pc = 0x801101ECu;
    // 801101EC: bl      0x80092040
    {
            ctx->lr = 0x801101F0u;
            ctx->pc = 0x80092040u;
            return;
    }

label_801101F0:
    ctx->pc = 0x801101F0u;
    ctx->downcount -= 1;
    // 801101F0: bl      0x8023A8A4
    {
            ctx->lr = 0x801101F4u;
            ctx->pc = 0x8023A8A4u;
            return;
    }

label_801101F4:
    ctx->pc = 0x801101F4u;
    ctx->downcount -= 17;
    // 801101F4: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801101F8:
    ctx->pc = 0x801101F8u;
    // 801101F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801101FC:
    ctx->pc = 0x801101FCu;
    // 801101FC: lmw     r26, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80110200:
    ctx->pc = 0x80110200u;
    // 80110200: lfd     f31, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110200u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80110204:
    ctx->pc = 0x80110204u;
    // 80110204: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_80110208:
    ctx->pc = 0x80110208u;
    // 80110208: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8011020C:
    ctx->pc = 0x8011020Cu;
    ctx->downcount -= 16;
    // 8011020C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80110210:
    ctx->pc = 0x80110210u;
    // 80110210: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80110214:
    ctx->pc = 0x80110214u;
    // 80110214: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80110218:
    ctx->pc = 0x80110218u;
    // 80110218: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8011021C:
    ctx->pc = 0x8011021Cu;
    // 8011021C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110220:
    ctx->pc = 0x80110220u;
    // 80110220: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80110224:
    ctx->pc = 0x80110224u;
    ctx->downcount -= 11;
    // 80110224: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110228:
    ctx->pc = 0x80110228u;
    // 80110228: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8011022C:
    // 8011022C: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80110230:
    ctx->pc = 0x80110230u;
    // 80110230: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110234:
    // 80110234: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_80110238:
    // 80110238: cmplw   r10, r11
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

label_8011023C:
    // 8011023C: bc    12, 0, 0x80110264
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80110264;
        }
    }

label_80110240:
    ctx->downcount -= 3;
    // 80110240: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80110244:
    ctx->pc = 0x80110244u;
    // 80110244: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110248:
    // 80110248: b       0x8011033C
    {
            goto label_8011033C;
    }

label_8011024C:
    ctx->pc = 0x8011024Cu;
    ctx->downcount -= 6;
    // 8011024C: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110250:
    // 80110250: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80110254:
    ctx->pc = 0x80110254u;
    // 80110254: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110258:
    ctx->pc = 0x80110258u;
    // 80110258: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8011025C:
    ctx->pc = 0x8011025Cu;
    // 8011025C: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80110260:
    // 80110260: b       0x80110224
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80110224u;
                return;
            }
            goto label_80110224;
    }

label_80110264:
    ctx->downcount -= 2;
    // 80110264: cmplw   r10, r30
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

label_80110268:
    // 80110268: bc    12, 0, 0x80110288
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80110288;
        }
    }

label_8011026C:
    ctx->downcount -= 50;
    // 8011026C: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_80110270:
    ctx->pc = 0x80110270u;
    // 80110270: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110274:
    // 80110274: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80110278:
    ctx->pc = 0x80110278u;
    // 80110278: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8011027C:
    // 8011027C: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80110280:
    ctx->pc = 0x80110280u;
    // 80110280: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110284:
    // 80110284: b       0x8011033C
    {
            goto label_8011033C;
    }

label_80110288:
    ctx->pc = 0x80110288u;
    ctx->downcount -= 8;
    // 80110288: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8011028C:
    // 8011028C: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80110290:
    // 80110290: cmpwi   r10, 0
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

label_80110294:
    // 80110294: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_80110298:
    // 80110298: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_8011029C:
    // 8011029C: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_801102A0:
    // 801102A0: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_801102A4:
    // 801102A4: bc    12, 2, 0x801102C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801102C4;
        }
    }

label_801102A8:
    ctx->downcount -= 7;
    // 801102A8: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_801102AC:
    // 801102AC: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801102B0:
    // 801102B0: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801102B4:
    // 801102B4: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801102B8:
    ctx->pc = 0x801102B8u;
    // 801102B8: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801102BC:
    ctx->pc = 0x801102BCu;
    // 801102BC: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801102C0:
    ctx->pc = 0x801102C0u;
    // 801102C0: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801102C4:
    ctx->downcount -= 2;
    // 801102C4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801102C8:
    // 801102C8: bl      0x80281C60
    {
            ctx->lr = 0x801102CCu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801102CC:
    ctx->downcount -= 3;
    // 801102CC: cmpwi   r3, 0
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

label_801102D0:
    ctx->pc = 0x801102D0u;
    // 801102D0: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801102D4:
    // 801102D4: bc    4, 2, 0x80110320
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110320;
        }
    }

label_801102D8:
    ctx->downcount -= 3;
    // 801102D8: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801102DC:
    // 801102DC: cmplwi  r11, 0x0080
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

label_801102E0:
    // 801102E0: bc    12, 1, 0x8011030C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011030C;
        }
    }

label_801102E4:
    ctx->downcount -= 2;
    // 801102E4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_801102E8:
    // 801102E8: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_801102EC:
    ctx->downcount -= 5;
    // 801102EC: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_801102F0:
    // 801102F0: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801102F4:
    ctx->pc = 0x801102F4u;
    // 801102F4: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801102F8:
    // 801102F8: cmpwi   r10, 0
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

label_801102FC:
    // 801102FC: bc    4, 2, 0x8011024C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8011024Cu;
                return;
            }
            goto label_8011024C;
        }
    }

label_80110300:
    ctx->downcount -= 3;
    // 80110300: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_80110304:
    // 80110304: cmplwi  r11, 0x0080
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

label_80110308:
    // 80110308: bc    4, 1, 0x801102EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801102ECu;
                return;
            }
            goto label_801102EC;
        }
    }

label_8011030C:
    ctx->downcount -= 4;
    // 8011030C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80110310:
    // 80110310: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80110314:
    ctx->pc = 0x80110314u;
    // 80110314: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110318:
    // 80110318: bl      0x80281C60
    {
            ctx->lr = 0x8011031Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8011031C:
    ctx->pc = 0x8011031Cu;
    ctx->downcount -= 1;
    // 8011031C: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80110320:
    ctx->pc = 0x80110320u;
    ctx->downcount -= 7;
    // 80110320: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110324:
    ctx->pc = 0x80110324u;
    // 80110324: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110328:
    // 80110328: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8011032C:
    // 8011032C: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80110330:
    ctx->pc = 0x80110330u;
    // 80110330: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110334:
    ctx->pc = 0x80110334u;
    // 80110334: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110338:
    // 80110338: b       0x80110224
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80110224u;
                return;
            }
            goto label_80110224;
    }

label_8011033C:
    ctx->pc = 0x8011033Cu;
    ctx->downcount -= 16;
    // 8011033C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110340:
    ctx->pc = 0x80110340u;
    // 80110340: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80110344:
    ctx->pc = 0x80110344u;
    // 80110344: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80110348:
    ctx->pc = 0x80110348u;
    // 80110348: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8011034C:
    ctx->pc = 0x8011034Cu;
    // 8011034C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110350:
    ctx->pc = 0x80110350u;
    ctx->downcount -= 21;
    // 80110350: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80110354:
    ctx->pc = 0x80110354u;
    // 80110354: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80110358:
    ctx->pc = 0x80110358u;
    // 80110358: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8011035C:
    ctx->pc = 0x8011035Cu;
    // 8011035C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110360:
    ctx->pc = 0x80110360u;
    // 80110360: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80110364:
    ctx->pc = 0x80110364u;
    // 80110364: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_80110368:
    ctx->pc = 0x80110368u;
    // 80110368: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_8011036C:
    ctx->pc = 0x8011036Cu;
    // 8011036C: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80110370:
    ctx->pc = 0x80110370u;
    // 80110370: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80110374:
    ctx->pc = 0x80110374u;
    // 80110374: cmpwi   r30, 0
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

label_80110378:
    ctx->pc = 0x80110378u;
    // 80110378: bc    12, 2, 0x80110388
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80110388;
        }
    }

label_8011037C:
    ctx->pc = 0x8011037Cu;
    ctx->downcount -= 3;
    // 8011037C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110380:
    ctx->pc = 0x80110380u;
    // 80110380: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110384:
    ctx->pc = 0x80110384u;
    // 80110384: b       0x80110408
    {
            goto label_80110408;
    }

label_80110388:
    ctx->pc = 0x80110388u;
    ctx->downcount -= 7;
    // 80110388: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_8011038C:
    ctx->pc = 0x8011038Cu;
    // 8011038C: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_80110390:
    ctx->pc = 0x80110390u;
    // 80110390: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_80110394:
    ctx->pc = 0x80110394u;
    // 80110394: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110398:
    ctx->pc = 0x80110398u;
    // 80110398: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8011039C:
    ctx->pc = 0x8011039Cu;
    // 8011039C: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_801103A0:
    ctx->pc = 0x801103A0u;
    // 801103A0: bl      0x80003EE0
    {
            ctx->lr = 0x801103A4u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_801103A4:
    ctx->pc = 0x801103A4u;
    ctx->downcount -= 3;
    // 801103A4: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801103A8:
    ctx->pc = 0x801103A8u;
    // 801103A8: cmpwi   r9, 1
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

label_801103AC:
    ctx->pc = 0x801103ACu;
    // 801103AC: bc    12, 2, 0x80110404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80110404;
        }
    }

label_801103B0:
    ctx->pc = 0x801103B0u;
    ctx->downcount -= 9;
    // 801103B0: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_801103B4:
    ctx->pc = 0x801103B4u;
    // 801103B4: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801103B8:
    ctx->pc = 0x801103B8u;
    // 801103B8: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_801103BC:
    ctx->pc = 0x801103BCu;
    // 801103BC: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801103C0:
    ctx->pc = 0x801103C0u;
    // 801103C0: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801103C4:
    ctx->pc = 0x801103C4u;
    // 801103C4: cmpwi   r9, 2
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

label_801103C8:
    ctx->pc = 0x801103C8u;
    // 801103C8: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_801103CC:
    ctx->pc = 0x801103CCu;
    // 801103CC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801103D0:
    ctx->pc = 0x801103D0u;
    // 801103D0: bc    4, 2, 0x801103DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801103DC;
        }
    }

label_801103D4:
    ctx->pc = 0x801103D4u;
    ctx->downcount -= 2;
    // 801103D4: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801103D8:
    ctx->pc = 0x801103D8u;
    // 801103D8: b       0x80110404
    {
            goto label_80110404;
    }

label_801103DC:
    loop_801103DC(ctx);
    if (ctx->pc == 0x801103FCu) goto label_801103FC;
    return;
label_801103E0:
    // 801103E0: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_801103E4:
    // 801103E4: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801103E8:
    ctx->pc = 0x801103E8u;
    // 801103E8: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801103EC:
    // 801103EC: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801103F0:
    // 801103F0: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801103F4:
    // 801103F4: cmpw    r9, r8
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

label_801103F8:
    // 801103F8: bc    4, 2, 0x801103DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801103DCu;
                return;
            }
            goto label_801103DC;
        }
    }

label_801103FC:
    ctx->pc = 0x801103FCu;
    ctx->downcount -= 2;
    // 801103FC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80110400:
    ctx->pc = 0x80110400u;
    // 80110400: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110404:
    ctx->pc = 0x80110404u;
    ctx->downcount -= 1;
    // 80110404: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110408:
    ctx->pc = 0x80110408u;
    ctx->downcount -= 17;
    // 80110408: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8011040C:
    ctx->pc = 0x8011040Cu;
    // 8011040C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110410:
    ctx->pc = 0x80110410u;
    // 80110410: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80110414:
    ctx->pc = 0x80110414u;
    // 80110414: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80110418:
    ctx->pc = 0x80110418u;
    // 80110418: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8011041C:
    ctx->pc = 0x8011041Cu;
    // 8011041C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110420:
    ctx->pc = 0x80110420u;
    ctx->downcount -= 41;
    // 80110420: stwu     r1, -144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-144);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80110424:
    ctx->pc = 0x80110424u;
    // 80110424: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80110428:
    ctx->pc = 0x80110428u;
    // 80110428: stfd     f30, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110428u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8011042C:
    ctx->pc = 0x8011042Cu;
    // 8011042C: stfd     f31, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011042Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80110430:
    ctx->pc = 0x80110430u;
    // 80110430: stmw     r25, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80110434:
    ctx->pc = 0x80110434u;
    // 80110434: stw     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110438:
    ctx->pc = 0x80110438u;
    // 80110438: lfs     f12, 0(r5)
    if (!ppc_fp_available_inline(ctx, 0x80110438u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8011043C:
    ctx->pc = 0x8011043Cu;
    // 8011043C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80110440:
    ctx->pc = 0x80110440u;
    // 80110440: lfs     f13, 4(r5)
    if (!ppc_fp_available_inline(ctx, 0x80110440u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80110444:
    ctx->pc = 0x80110444u;
    // 80110444: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_80110448:
    ctx->pc = 0x80110448u;
    // 80110448: lfs     f0, 4892(r9)
    if (!ppc_fp_available_inline(ctx, 0x80110448u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4892);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8011044C:
    ctx->pc = 0x8011044Cu;
    // 8011044C: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x8011044Cu)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_80110450:
    ctx->pc = 0x80110450u;
    // 80110450: stfs     f12, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110450u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80110454:
    ctx->pc = 0x80110454u;
    // 80110454: addi    r10, r1, 24
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(24);

label_80110458:
    ctx->pc = 0x80110458u;
    // 80110458: stfs     f13, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x80110458u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8011045C:
    ctx->pc = 0x8011045Cu;
    // 8011045C: addi    r9, r1, 40
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(40);

label_80110460:
    ctx->pc = 0x80110460u;
    // 80110460: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x80110460u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80110464:
    ctx->pc = 0x80110464u;
    // 80110464: or   r31, r6, r6
    {
        ctx->gpr[31] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80110468:
    ctx->pc = 0x80110468u;
    // 80110468: stfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110468u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8011046C:
    ctx->pc = 0x8011046Cu;
    // 8011046C: or   r25, r10, r10
    {
        ctx->gpr[25] = ctx->gpr[10] | ctx->gpr[10];
    }

label_80110470:
    ctx->pc = 0x80110470u;
    // 80110470: stfs     f31, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110470u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80110474:
    ctx->pc = 0x80110474u;
    // 80110474: or   r26, r9, r9
    {
        ctx->gpr[26] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80110478:
    ctx->pc = 0x80110478u;
    // 80110478: stfs     f0, 8(r10)
    if (!ppc_fp_available_inline(ctx, 0x80110478u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8011047C:
    ctx->pc = 0x8011047Cu;
    // 8011047C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110480:
    ctx->pc = 0x80110480u;
    // 80110480: stfs     f31, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110480u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80110484:
    ctx->pc = 0x80110484u;
    // 80110484: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80110488:
    ctx->pc = 0x80110488u;
    // 80110488: stfs     f0, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x80110488u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8011048C:
    ctx->pc = 0x8011048Cu;
    // 8011048C: stfs     f0, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x8011048Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80110490:
    ctx->pc = 0x80110490u;
    // 80110490: lbz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80110494:
    ctx->pc = 0x80110494u;
    // 80110494: cmpwi   r0, 0
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

label_80110498:
    ctx->pc = 0x80110498u;
    // 80110498: bc    12, 2, 0x8011050C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011050C;
        }
    }

label_8011049C:
    ctx->pc = 0x8011049Cu;
    ctx->downcount -= 3;
    // 8011049C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801104A0:
    ctx->pc = 0x801104A0u;
    // 801104A0: lis     r27, 17200
    ctx->gpr[27] = ((u32)(s32)(17200) << 16);

label_801104A4:
    ctx->pc = 0x801104A4u;
    // 801104A4: lfd     f30, 4896(r9)
    if (!ppc_fp_available_inline(ctx, 0x801104A4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4896);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801104A8:
    ctx->downcount -= 3;
    // 801104A8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801104AC:
    // 801104AC: addi    r3, r1, 56
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(56);

label_801104B0:
    // 801104B0: bl      0x801D5454
    {
            ctx->lr = 0x801104B4u;
            ctx->pc = 0x801D5454u;
            return;
    }

label_801104B4:
    ctx->pc = 0x801104B4u;
    ctx->downcount -= 4;
    // 801104B4: lwz     r4, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801104B8:
    // 801104B8: add   r31, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_801104BC:
    // 801104BC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801104C0:
    // 801104C0: bl      0x801D5510
    {
            ctx->lr = 0x801104C4u;
            ctx->pc = 0x801D5510u;
            return;
    }

label_801104C4:
    ctx->downcount -= 5;
    // 801104C4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801104C8:
    // 801104C8: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_801104CC:
    // 801104CC: or   r5, r25, r25
    {
        ctx->gpr[5] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801104D0:
    // 801104D0: or   r6, r26, r26
    {
        ctx->gpr[6] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801104D4:
    // 801104D4: bl      0x801D51D8
    {
            ctx->lr = 0x801104D8u;
            ctx->pc = 0x801D51D8u;
            return;
    }

label_801104D8:
    ctx->pc = 0x801104D8u;
    ctx->downcount -= 13;
    // 801104D8: lha     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801104DC:
    ctx->pc = 0x801104DCu;
    // 801104DC: lfs     f13, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801104DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801104E0:
    // 801104E0: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_801104E4:
    ctx->pc = 0x801104E4u;
    // 801104E4: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801104E8:
    ctx->pc = 0x801104E8u;
    // 801104E8: stw     r27, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_801104EC:
    ctx->pc = 0x801104ECu;
    // 801104EC: lfd     f0, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x801104ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801104F0:
    ctx->pc = 0x801104F0u;
    // 801104F0: fsub   f0, f0, f30
    if (!ppc_fp_available_inline(ctx, 0x801104F0u)) return;
    ppc_fsub(ctx, 0, 0, 30);

label_801104F4:
    ctx->pc = 0x801104F4u;
    // 801104F4: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x801104F4u)) return;
    ppc_frsp(ctx, 0, 0);

label_801104F8:
    ctx->pc = 0x801104F8u;
    // 801104F8: fmadds f0, f31, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x801104F8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[31], ctx->fpr[0], ctx->fpr[13], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_801104FC:
    ctx->pc = 0x801104FCu;
    // 801104FC: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801104FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80110500:
    ctx->pc = 0x80110500u;
    // 80110500: lbz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80110504:
    // 80110504: cmpwi   r0, 0
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

label_80110508:
    // 80110508: bc    4, 2, 0x801104A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801104A8u;
                return;
            }
            goto label_801104A8;
        }
    }

label_8011050C:
    ctx->pc = 0x8011050Cu;
    ctx->downcount -= 23;
    // 8011050C: lfs     f13, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011050Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80110510:
    ctx->pc = 0x80110510u;
    // 80110510: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80110514:
    ctx->pc = 0x80110514u;
    // 80110514: lfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110514u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80110518:
    ctx->pc = 0x80110518u;
    // 80110518: stfs     f13, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x80110518u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8011051C:
    ctx->pc = 0x8011051Cu;
    // 8011051C: stfs     f0, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x8011051Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80110520:
    ctx->pc = 0x80110520u;
    // 80110520: lwz     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110524:
    ctx->pc = 0x80110524u;
    // 80110524: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80110528:
    ctx->pc = 0x80110528u;
    // 80110528: lmw     r25, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8011052C:
    ctx->pc = 0x8011052Cu;
    // 8011052C: lfd     f30, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011052Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80110530:
    ctx->pc = 0x80110530u;
    // 80110530: lfd     f31, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110530u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80110534:
    ctx->pc = 0x80110534u;
    // 80110534: addi    r1, r1, 144
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(144);

label_80110538:
    ctx->pc = 0x80110538u;
    // 80110538: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8011053C:
    ctx->pc = 0x8011053Cu;
    ctx->downcount -= 7;
    // 8011053C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80110540:
    ctx->pc = 0x80110540u;
    // 80110540: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80110544:
    ctx->pc = 0x80110544u;
    // 80110544: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110548:
    ctx->pc = 0x80110548u;
    // 80110548: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8011054C:
    ctx->pc = 0x8011054Cu;
    // 8011054C: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80110550:
    ctx->pc = 0x80110550u;
    // 80110550: cmpw    r4, r0
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

label_80110554:
    ctx->pc = 0x80110554u;
    // 80110554: bc    4, 2, 0x801105F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801105F4;
        }
    }

label_80110558:
    ctx->pc = 0x80110558u;
    ctx->downcount -= 2;
    // 80110558: cmpwi   r3, 0
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

label_8011055C:
    ctx->pc = 0x8011055Cu;
    // 8011055C: bc    12, 2, 0x801105E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801105E4;
        }
    }

label_80110560:
    ctx->pc = 0x80110560u;
    ctx->downcount -= 5;
    // 80110560: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80110564:
    ctx->pc = 0x80110564u;
    // 80110564: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_80110568:
    ctx->pc = 0x80110568u;
    // 80110568: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_8011056C:
    ctx->pc = 0x8011056Cu;
    // 8011056C: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_80110570:
    ctx->pc = 0x80110570u;
    // 80110570: bl      0x80252AF0
    {
            ctx->lr = 0x80110574u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80110574:
    ctx->pc = 0x80110574u;
    ctx->downcount -= 5;
    // 80110574: lis     r3, 26223
    ctx->gpr[3] = ((u32)(s32)(26223) << 16);

label_80110578:
    ctx->pc = 0x80110578u;
    // 80110578: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8011057C:
    ctx->pc = 0x8011057Cu;
    // 8011057C: ori     r3, r3, 0x6E74
    ctx->gpr[3] = ctx->gpr[3] | 0x6E74u;

label_80110580:
    ctx->pc = 0x80110580u;
    // 80110580: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80110584:
    ctx->pc = 0x80110584u;
    // 80110584: bl      0x80252AF0
    {
            ctx->lr = 0x80110588u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80110588:
    ctx->pc = 0x80110588u;
    ctx->downcount -= 5;
    // 80110588: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_8011058C:
    ctx->pc = 0x8011058Cu;
    // 8011058C: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80110590:
    ctx->pc = 0x80110590u;
    // 80110590: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_80110594:
    ctx->pc = 0x80110594u;
    // 80110594: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80110598:
    ctx->pc = 0x80110598u;
    // 80110598: bl      0x80252AF0
    {
            ctx->lr = 0x8011059Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8011059C:
    ctx->pc = 0x8011059Cu;
    ctx->downcount -= 5;
    // 8011059C: lis     r3, 29793
    ctx->gpr[3] = ((u32)(s32)(29793) << 16);

label_801105A0:
    ctx->pc = 0x801105A0u;
    // 801105A0: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_801105A4:
    ctx->pc = 0x801105A4u;
    // 801105A4: ori     r3, r3, 0x626C
    ctx->gpr[3] = ctx->gpr[3] | 0x626Cu;

label_801105A8:
    ctx->pc = 0x801105A8u;
    // 801105A8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801105AC:
    ctx->pc = 0x801105ACu;
    // 801105AC: bl      0x80252AF0
    {
            ctx->lr = 0x801105B0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801105B0:
    ctx->pc = 0x801105B0u;
    ctx->downcount -= 13;
    // 801105B0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801105B4:
    ctx->pc = 0x801105B4u;
    // 801105B4: lis     r10, -32714
    ctx->gpr[10] = ((u32)(s32)(-32714) << 16);

label_801105B8:
    ctx->pc = 0x801105B8u;
    // 801105B8: lfs     f0, 4904(r9)
    if (!ppc_fp_available_inline(ctx, 0x801105B8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4904);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801105BC:
    ctx->pc = 0x801105BCu;
    // 801105BC: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801105C0:
    ctx->pc = 0x801105C0u;
    // 801105C0: addi    r9, r10, -21296
    ctx->gpr[9] = ctx->gpr[10] + (u32)(s32)(-21296);

label_801105C4:
    ctx->pc = 0x801105C4u;
    // 801105C4: addi    r11, r11, 4920
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4920);

label_801105C8:
    ctx->pc = 0x801105C8u;
    // 801105C8: stfs     f0, -21296(r10)
    if (!ppc_fp_available_inline(ctx, 0x801105C8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-21296);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801105CC:
    ctx->pc = 0x801105CCu;
    // 801105CC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801105D0:
    ctx->pc = 0x801105D0u;
    // 801105D0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801105D4:
    ctx->pc = 0x801105D4u;
    // 801105D4: stw     r11, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801105D8:
    ctx->pc = 0x801105D8u;
    // 801105D8: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801105DC:
    ctx->pc = 0x801105DCu;
    // 801105DC: stw     r8, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801105E0:
    ctx->pc = 0x801105E0u;
    // 801105E0: b       0x801105F4
    {
            goto label_801105F4;
    }

label_801105E4:
    ctx->pc = 0x801105E4u;
    ctx->downcount -= 4;
    // 801105E4: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801105E8:
    ctx->pc = 0x801105E8u;
    // 801105E8: lis     r11, -32714
    ctx->gpr[11] = ((u32)(s32)(-32714) << 16);

label_801105EC:
    ctx->pc = 0x801105ECu;
    // 801105EC: addi    r9, r9, 4920
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4920);

label_801105F0:
    ctx->pc = 0x801105F0u;
    // 801105F0: stw     r9, -21284(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-21284);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801105F4:
    ctx->pc = 0x801105F4u;
    ctx->downcount -= 5;
    // 801105F4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801105F8:
    ctx->pc = 0x801105F8u;
    // 801105F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801105FC:
    ctx->pc = 0x801105FCu;
    // 801105FC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80110600:
    ctx->pc = 0x80110600u;
    // 80110600: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110604:
    ctx->pc = 0x80110604u;
    ctx->downcount -= 12;
    // 80110604: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_80110608:
    ctx->pc = 0x80110608u;
    // 80110608: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_8011060C:
    ctx->pc = 0x8011060Cu;
    // 8011060C: lfs     f0, 4908(r10)
    if (!ppc_fp_available_inline(ctx, 0x8011060Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4908);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80110610:
    ctx->pc = 0x80110610u;
    // 80110610: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110614:
    ctx->pc = 0x80110614u;
    // 80110614: addi    r11, r11, 4920
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4920);

label_80110618:
    ctx->pc = 0x80110618u;
    // 80110618: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8011061C:
    ctx->pc = 0x8011061Cu;
    // 8011061C: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_80110620:
    ctx->pc = 0x80110620u;
    // 80110620: stw     r11, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80110624:
    ctx->pc = 0x80110624u;
    // 80110624: stfs     f0, 0(r9)
    if (!ppc_fp_available_inline(ctx, 0x80110624u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80110628:
    ctx->pc = 0x80110628u;
    // 80110628: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8011062C:
    ctx->pc = 0x8011062Cu;
    // 8011062C: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80110630:
    ctx->pc = 0x80110630u;
    // 80110630: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110634:
    ctx->pc = 0x80110634u;
    ctx->downcount -= 3;
    // 80110634: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110638:
    ctx->pc = 0x80110638u;
    // 80110638: cmpwi   r0, 0
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

label_8011063C:
    ctx->pc = 0x8011063Cu;
    // 8011063C: bclr  4, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110640:
    ctx->pc = 0x80110640u;
    ctx->downcount -= 7;
    // 80110640: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80110644:
    ctx->pc = 0x80110644u;
    // 80110644: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80110648:
    ctx->pc = 0x80110648u;
    // 80110648: lfs     f0, 4912(r9)
    if (!ppc_fp_available_inline(ctx, 0x80110648u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4912);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8011064C:
    ctx->pc = 0x8011064Cu;
    // 8011064C: stw     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110650:
    ctx->pc = 0x80110650u;
    // 80110650: stw     r4, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80110654:
    ctx->pc = 0x80110654u;
    // 80110654: stfs     f0, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x80110654u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80110658:
    ctx->pc = 0x80110658u;
    // 80110658: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8011065C:
    ctx->pc = 0x8011065Cu;
    ctx->downcount -= 3;
    // 8011065C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80110660:
    ctx->pc = 0x80110660u;
    // 80110660: stw     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110664:
    ctx->pc = 0x80110664u;
    // 80110664: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110668:
    ctx->pc = 0x80110668u;
    ctx->downcount -= 8;
    // 80110668: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8011066C:
    ctx->pc = 0x8011066Cu;
    // 8011066C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80110670:
    ctx->pc = 0x80110670u;
    // 80110670: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110674:
    ctx->pc = 0x80110674u;
    // 80110674: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80110678:
    ctx->pc = 0x80110678u;
    // 80110678: andi.   r0, r4, 0x0001
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

label_8011067C:
    ctx->pc = 0x8011067Cu;
    // 8011067C: addi    r9, r9, 4920
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4920);

label_80110680:
    ctx->pc = 0x80110680u;
    // 80110680: stw     r9, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110684:
    ctx->pc = 0x80110684u;
    // 80110684: bc    12, 2, 0x8011068C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011068C;
        }
    }

label_80110688:
    ctx->pc = 0x80110688u;
    ctx->downcount -= 1;
    // 80110688: bl      0x80281D80
    {
            ctx->lr = 0x8011068Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8011068C:
    ctx->pc = 0x8011068Cu;
    ctx->downcount -= 5;
    // 8011068C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110690:
    ctx->pc = 0x80110690u;
    // 80110690: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80110694:
    ctx->pc = 0x80110694u;
    // 80110694: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80110698:
    ctx->pc = 0x80110698u;
    // 80110698: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_8011069C:
    ctx->pc = 0x8011069Cu;
    ctx->downcount -= 7;
    // 8011069C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801106A0:
    ctx->pc = 0x801106A0u;
    // 801106A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801106A4:
    ctx->pc = 0x801106A4u;
    // 801106A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801106A8:
    ctx->pc = 0x801106A8u;
    // 801106A8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801106AC:
    ctx->pc = 0x801106ACu;
    // 801106AC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801106B0:
    ctx->pc = 0x801106B0u;
    // 801106B0: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801106B4:
    ctx->pc = 0x801106B4u;
    // 801106B4: bl      0x8011053C
    {
            ctx->lr = 0x801106B8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8011053Cu;
                return;
            }
            goto label_8011053C;
    }

label_801106B8:
    ctx->pc = 0x801106B8u;
    ctx->downcount -= 5;
    // 801106B8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801106BC:
    ctx->pc = 0x801106BCu;
    // 801106BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801106C0:
    ctx->pc = 0x801106C0u;
    // 801106C0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801106C4:
    ctx->pc = 0x801106C4u;
    // 801106C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_801106C8:
    ctx->pc = 0x801106C8u;
    ctx->downcount -= 7;
    // 801106C8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801106CC:
    ctx->pc = 0x801106CCu;
    // 801106CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801106D0:
    ctx->pc = 0x801106D0u;
    // 801106D0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801106D4:
    ctx->pc = 0x801106D4u;
    // 801106D4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801106D8:
    ctx->pc = 0x801106D8u;
    // 801106D8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801106DC:
    ctx->pc = 0x801106DCu;
    // 801106DC: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801106E0:
    ctx->pc = 0x801106E0u;
    // 801106E0: bl      0x8011053C
    {
            ctx->lr = 0x801106E4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8011053Cu;
                return;
            }
            goto label_8011053C;
    }

label_801106E4:
    ctx->pc = 0x801106E4u;
    ctx->downcount -= 5;
    // 801106E4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801106E8:
    ctx->pc = 0x801106E8u;
    // 801106E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801106EC:
    ctx->pc = 0x801106ECu;
    // 801106EC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801106F0:
    ctx->pc = 0x801106F0u;
    // 801106F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_801106F4:
    ctx->pc = 0x801106F4u;
    ctx->downcount -= 9;
    // 801106F4: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801106F8:
    ctx->pc = 0x801106F8u;
    // 801106F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801106FC:
    ctx->pc = 0x801106FCu;
    // 801106FC: stfd     f31, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x801106FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80110700:
    ctx->pc = 0x80110700u;
    // 80110700: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80110704:
    ctx->pc = 0x80110704u;
    // 80110704: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110708:
    ctx->pc = 0x80110708u;
    // 80110708: lwz     r9, -27088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27088);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8011070C:
    ctx->pc = 0x8011070Cu;
    // 8011070C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110710:
    ctx->pc = 0x80110710u;
    // 80110710: cmpwi   r0, 0
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

label_80110714:
    ctx->pc = 0x80110714u;
    // 80110714: bc    12, 2, 0x80110720
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80110720;
        }
    }

label_80110718:
    ctx->pc = 0x80110718u;
    ctx->downcount -= 2;
    // 80110718: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8011071C:
    ctx->pc = 0x8011071Cu;
    // 8011071C: b       0x80110800
    {
            goto label_80110800;
    }

label_80110720:
    ctx->pc = 0x80110720u;
    ctx->downcount -= 3;
    // 80110720: lwz     r0, -27304(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27304);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110724:
    ctx->pc = 0x80110724u;
    // 80110724: cmpwi   r0, 0
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

label_80110728:
    ctx->pc = 0x80110728u;
    // 80110728: bc    4, 2, 0x80110740
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110740;
        }
    }

label_8011072C:
    ctx->pc = 0x8011072Cu;
    ctx->downcount -= 1;
    // 8011072C: bl      0x802C927C
    {
            ctx->lr = 0x80110730u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_80110730:
    ctx->pc = 0x80110730u;
    ctx->downcount -= 4;
    // 80110730: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80110734:
    ctx->pc = 0x80110734u;
    // 80110734: stw     r3, -27312(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27312);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80110738:
    ctx->pc = 0x80110738u;
    // 80110738: stw     r4, -27308(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27308);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8011073C:
    ctx->pc = 0x8011073Cu;
    // 8011073C: stw     r0, -27304(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27304);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110740:
    ctx->pc = 0x80110740u;
    ctx->downcount -= 2;
    // 80110740: addi    r3, r13, -27312
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27312);

label_80110744:
    ctx->pc = 0x80110744u;
    // 80110744: bl      0x80289814
    {
            ctx->lr = 0x80110748u;
            ctx->pc = 0x80289814u;
            return;
    }

label_80110748:
    ctx->pc = 0x80110748u;
    ctx->downcount -= 3;
    // 80110748: lfs     f0, -31940(r13)
    if (!ppc_fp_available_inline(ctx, 0x80110748u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31940);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8011074C:
    ctx->pc = 0x8011074Cu;
    // 8011074C: fadds   f31, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8011074Cu)) return;
    ppc_fadds(ctx, 31, 1, 0);

label_80110750:
    ctx->pc = 0x80110750u;
    // 80110750: bl      0x802C927C
    {
            ctx->lr = 0x80110754u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_80110754:
    ctx->pc = 0x80110754u;
    ctx->downcount -= 3;
    // 80110754: stw     r3, -27312(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27312);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80110758:
    ctx->pc = 0x80110758u;
    // 80110758: stw     r4, -27308(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27308);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8011075C:
    ctx->pc = 0x8011075Cu;
    // 8011075C: bl      0x802490A8
    {
            ctx->lr = 0x80110760u;
            ctx->pc = 0x802490A8u;
            return;
    }

label_80110760:
    ctx->pc = 0x80110760u;
    ctx->downcount -= 2;
    // 80110760: fmuls   f1, f31, f1
    if (!ppc_fp_available_inline(ctx, 0x80110760u)) return;
    ppc_fmuls(ctx, 1, 31, 1);

label_80110764:
    ctx->pc = 0x80110764u;
    // 80110764: bl      0x8029D888
    {
            ctx->lr = 0x80110768u;
            ctx->pc = 0x8029D888u;
            return;
    }

label_80110768:
    ctx->pc = 0x80110768u;
    ctx->downcount -= 5;
    // 80110768: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80110768u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8011076C:
    ctx->pc = 0x8011076Cu;
    // 8011076C: stfd     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011076Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80110770:
    ctx->pc = 0x80110770u;
    // 80110770: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110774:
    ctx->pc = 0x80110774u;
    // 80110774: cmpwi   r0, 1
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

label_80110778:
    ctx->pc = 0x80110778u;
    // 80110778: bc    4, 1, 0x80110790
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110790;
        }
    }

label_8011077C:
    ctx->pc = 0x8011077Cu;
    ctx->downcount -= 3;
    // 8011077C: li      r31, 2
    ctx->gpr[31] = (u32)(s32)(2);

label_80110780:
    ctx->pc = 0x80110780u;
    // 80110780: cmpw    r31, r0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80110784:
    ctx->pc = 0x80110784u;
    // 80110784: bc    4, 1, 0x80110794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110794;
        }
    }

label_80110788:
    ctx->pc = 0x80110788u;
    ctx->downcount -= 2;
    // 80110788: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8011078C:
    ctx->pc = 0x8011078Cu;
    // 8011078C: b       0x80110794
    {
            goto label_80110794;
    }

label_80110790:
    ctx->pc = 0x80110790u;
    ctx->downcount -= 1;
    // 80110790: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_80110794:
    ctx->pc = 0x80110794u;
    ctx->downcount -= 1;
    // 80110794: bl      0x802490B4
    {
            ctx->lr = 0x80110798u;
            ctx->pc = 0x802490B4u;
            return;
    }

label_80110798:
    ctx->pc = 0x80110798u;
    ctx->downcount -= 13;
    // 80110798: xoris   r0, r31, 0x8000
    ctx->gpr[0] = ctx->gpr[31] ^ (0x8000u << 16);

label_8011079C:
    ctx->pc = 0x8011079Cu;
    // 8011079C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801107A0:
    ctx->pc = 0x801107A0u;
    // 801107A0: lis     r11, 17200
    ctx->gpr[11] = ((u32)(s32)(17200) << 16);

label_801107A4:
    ctx->pc = 0x801107A4u;
    // 801107A4: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_801107A8:
    ctx->pc = 0x801107A8u;
    // 801107A8: stw     r11, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801107AC:
    ctx->pc = 0x801107ACu;
    // 801107AC: lfd     f13, 4968(r10)
    if (!ppc_fp_available_inline(ctx, 0x801107ACu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4968);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801107B0:
    ctx->pc = 0x801107B0u;
    // 801107B0: lfd     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x801107B0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801107B4:
    ctx->pc = 0x801107B4u;
    // 801107B4: fsub   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x801107B4u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_801107B8:
    ctx->pc = 0x801107B8u;
    // 801107B8: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x801107B8u)) return;
    ppc_frsp(ctx, 0, 0);

label_801107BC:
    ctx->pc = 0x801107BCu;
    // 801107BC: fmuls   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801107BCu)) return;
    ppc_fmuls(ctx, 0, 0, 1);

label_801107C0:
    ctx->pc = 0x801107C0u;
    // 801107C0: fsubs   f0, f31, f0
    if (!ppc_fp_available_inline(ctx, 0x801107C0u)) return;
    ppc_fsubs(ctx, 0, 31, 0);

label_801107C4:
    ctx->pc = 0x801107C4u;
    // 801107C4: stfs     f0, -31940(r13)
    if (!ppc_fp_available_inline(ctx, 0x801107C4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31940);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801107C8:
    ctx->pc = 0x801107C8u;
    // 801107C8: bl      0x802490B4
    {
            ctx->lr = 0x801107CCu;
            ctx->pc = 0x802490B4u;
            return;
    }

label_801107CC:
    ctx->pc = 0x801107CCu;
    ctx->downcount -= 2;
    // 801107CC: fneg    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x801107CCu)) return;
    ctx->fpr[31] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_801107D0:
    ctx->pc = 0x801107D0u;
    // 801107D0: bl      0x802490B4
    {
            ctx->lr = 0x801107D4u;
            ctx->pc = 0x802490B4u;
            return;
    }

label_801107D4:
    ctx->pc = 0x801107D4u;
    ctx->downcount -= 4;
    // 801107D4: lfs     f0, -31940(r13)
    if (!ppc_fp_available_inline(ctx, 0x801107D4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31940);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801107D8:
    ctx->pc = 0x801107D8u;
    // 801107D8: fmr    f13, f1
    if (!ppc_fp_available_inline(ctx, 0x801107D8u)) return;
    ctx->fpr[13] = ctx->fpr[1];

label_801107DC:
    ctx->pc = 0x801107DCu;
    // 801107DC: fcmpu   cr0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x801107DCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[31], false);

label_801107E0:
    ctx->pc = 0x801107E0u;
    // 801107E0: bc    4, 1, 0x801107F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801107F4;
        }
    }

label_801107E4:
    ctx->pc = 0x801107E4u;
    ctx->downcount -= 2;
    // 801107E4: fcmpu   cr0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x801107E4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_801107E8:
    ctx->pc = 0x801107E8u;
    // 801107E8: bc    4, 0, 0x801107F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801107F8;
        }
    }

label_801107EC:
    ctx->pc = 0x801107ECu;
    ctx->downcount -= 2;
    // 801107EC: fmr    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x801107ECu)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_801107F0:
    ctx->pc = 0x801107F0u;
    // 801107F0: b       0x801107F8
    {
            goto label_801107F8;
    }

label_801107F4:
    ctx->pc = 0x801107F4u;
    ctx->downcount -= 1;
    // 801107F4: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801107F4u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801107F8:
    ctx->pc = 0x801107F8u;
    ctx->downcount -= 2;
    // 801107F8: stfs     f1, -31940(r13)
    if (!ppc_fp_available_inline(ctx, 0x801107F8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31940);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801107FC:
    ctx->pc = 0x801107FCu;
    // 801107FC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80110800:
    ctx->pc = 0x80110800u;
    ctx->downcount -= 7;
    // 80110800: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110804:
    ctx->pc = 0x80110804u;
    // 80110804: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80110808:
    ctx->pc = 0x80110808u;
    // 80110808: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8011080C:
    ctx->pc = 0x8011080Cu;
    // 8011080C: lfd     f31, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011080Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80110810:
    ctx->pc = 0x80110810u;
    // 80110810: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80110814:
    ctx->pc = 0x80110814u;
    // 80110814: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80110818:
    ctx->pc = 0x80110818u;
    ctx->downcount -= 23;
    // 80110818: stwu     r1, -312(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-312);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8011081C:
    ctx->pc = 0x8011081Cu;
    // 8011081C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80110820:
    ctx->pc = 0x80110820u;
    // 80110820: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_80110824:
    ctx->pc = 0x80110824u;
    // 80110824: stfd     f28, 280(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110824u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[28]));
    }

label_80110828:
    ctx->pc = 0x80110828u;
    // 80110828: stfd     f29, 288(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110828u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_8011082C:
    ctx->pc = 0x8011082Cu;
    // 8011082C: stfd     f30, 296(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011082Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80110830:
    ctx->pc = 0x80110830u;
    // 80110830: stfd     f31, 304(r1)
    if (!ppc_fp_available_inline(ctx, 0x80110830u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(304);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80110834:
    ctx->pc = 0x80110834u;
    // 80110834: stmw     r19, 228(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(228);
        for (u32 r = 19; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80110838:
    ctx->pc = 0x80110838u;
    // 80110838: stw     r0, 316(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(316);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8011083C:
    ctx->pc = 0x8011083Cu;
    // 8011083C: stw     r12, 224(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80110840:
    ctx->pc = 0x80110840u;
    // 80110840: stw     r3, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80110844:
    ctx->pc = 0x80110844u;
    // 80110844: stw     r4, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80110848:
    ctx->pc = 0x80110848u;
    // 80110848: bl      0x802931B0
    {
            ctx->lr = 0x8011084Cu;
            ctx->pc = 0x802931B0u;
            return;
    }

label_8011084C:
    ctx->pc = 0x8011084Cu;
    ctx->downcount -= 4;
    // 8011084C: addi    r3, r1, 168
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(168);

label_80110850:
    ctx->pc = 0x80110850u;
    // 80110850: addi    r4, r1, 172
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(172);

label_80110854:
    ctx->pc = 0x80110854u;
    // 80110854: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80110858:
    ctx->pc = 0x80110858u;
    // 80110858: bl      0x8028D9A4
    {
            ctx->lr = 0x8011085Cu;
            ctx->pc = 0x8028D9A4u;
            return;
    }

label_8011085C:
    ctx->pc = 0x8011085Cu;
    ctx->downcount -= 6;
    // 8011085C: li      r23, 0
    ctx->gpr[23] = (u32)(s32)(0);

label_80110860:
    ctx->pc = 0x80110860u;
    // 80110860: lwz     r3, -26904(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26904);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110864:
    ctx->pc = 0x80110864u;
    // 80110864: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80110868:
    ctx->pc = 0x80110868u;
    // 80110868: li      r21, 0
    ctx->gpr[21] = (u32)(s32)(0);

label_8011086C:
    ctx->pc = 0x8011086Cu;
    // 8011086C: lis     r28, -32714
    ctx->gpr[28] = ((u32)(s32)(-32714) << 16);

label_80110870:
    ctx->pc = 0x80110870u;
    // 80110870: bl      0x8027B08C
    {
            ctx->lr = 0x80110874u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110874:
    ctx->pc = 0x80110874u;
    ctx->downcount -= 22;
    // 80110874: lis     r11, -32714
    ctx->gpr[11] = ((u32)(s32)(-32714) << 16);

label_80110878:
    ctx->pc = 0x80110878u;
    // 80110878: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_8011087C:
    ctx->pc = 0x8011087Cu;
    // 8011087C: addi    r8, r11, -25052
    ctx->gpr[8] = ctx->gpr[11] + (u32)(s32)(-25052);

label_80110880:
    ctx->pc = 0x80110880u;
    // 80110880: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80110884:
    ctx->pc = 0x80110884u;
    // 80110884: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80110888:
    ctx->pc = 0x80110888u;
    // 80110888: addi    r10, r10, 4976
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(4976);

label_8011088C:
    ctx->pc = 0x8011088Cu;
    // 8011088C: addi    r4, r11, 4964
    ctx->gpr[4] = ctx->gpr[11] + (u32)(s32)(4964);

label_80110890:
    ctx->pc = 0x80110890u;
    // 80110890: addi    r9, r9, 5004
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(5004);

label_80110894:
    ctx->pc = 0x80110894u;
    // 80110894: addi    r3, r8, 3244
    ctx->gpr[3] = ctx->gpr[8] + (u32)(s32)(3244);

label_80110898:
    ctx->pc = 0x80110898u;
    // 80110898: stw     r10, 20(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8011089C:
    ctx->pc = 0x8011089Cu;
    // 8011089C: stw     r9, 3020(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3020);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801108A0:
    ctx->pc = 0x801108A0u;
    // 801108A0: cmpwi   r4, 0
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

label_801108A4:
    ctx->pc = 0x801108A4u;
    // 801108A4: stw     r26, 3240(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3240);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801108A8:
    ctx->pc = 0x801108A8u;
    // 801108A8: stw     r4, 3068(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3068);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801108AC:
    ctx->pc = 0x801108ACu;
    // 801108AC: stw     r4, 3116(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3116);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801108B0:
    ctx->pc = 0x801108B0u;
    // 801108B0: stw     r4, 3164(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3164);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801108B4:
    ctx->pc = 0x801108B4u;
    // 801108B4: stw     r26, 3016(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3016);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801108B8:
    ctx->pc = 0x801108B8u;
    // 801108B8: stw     r26, 3064(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3064);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801108BC:
    ctx->pc = 0x801108BCu;
    // 801108BC: stw     r26, 3112(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3112);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801108C0:
    ctx->pc = 0x801108C0u;
    // 801108C0: stw     r26, 3160(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3160);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801108C4:
    ctx->pc = 0x801108C4u;
    // 801108C4: stw     r26, 3012(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3012);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801108C8:
    ctx->pc = 0x801108C8u;
    // 801108C8: bc    12, 2, 0x801108D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801108D8;
        }
    }

label_801108CC:
    ctx->pc = 0x801108CCu;
    ctx->downcount -= 2;
    // 801108CC: li      r5, 80
    ctx->gpr[5] = (u32)(s32)(80);

label_801108D0:
    ctx->pc = 0x801108D0u;
    // 801108D0: bl      0x80287F10
    {
            ctx->lr = 0x801108D4u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_801108D4:
    ctx->pc = 0x801108D4u;
    ctx->downcount -= 1;
    // 801108D4: b       0x801108DC
    {
            goto label_801108DC;
    }

label_801108D8:
    ctx->pc = 0x801108D8u;
    ctx->downcount -= 1;
    // 801108D8: stb     r26, 3244(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(3244);
        mem_write8(ctx, ea, (u8)ctx->gpr[26]);
    }

label_801108DC:
    ctx->pc = 0x801108DCu;
    ctx->downcount -= 20;
    // 801108DC: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801108E0:
    ctx->pc = 0x801108E0u;
    // 801108E0: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_801108E4:
    ctx->pc = 0x801108E4u;
    // 801108E4: lfs     f13, 5508(r11)
    if (!ppc_fp_available_inline(ctx, 0x801108E4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5508);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801108E8:
    ctx->pc = 0x801108E8u;
    // 801108E8: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_801108EC:
    ctx->pc = 0x801108ECu;
    // 801108EC: lfs     f0, 5512(r10)
    if (!ppc_fp_available_inline(ctx, 0x801108ECu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(5512);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801108F0:
    ctx->pc = 0x801108F0u;
    // 801108F0: addi    r31, r9, -25052
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-25052);

label_801108F4:
    ctx->pc = 0x801108F4u;
    // 801108F4: li      r0, 19
    ctx->gpr[0] = (u32)(s32)(19);

label_801108F8:
    ctx->pc = 0x801108F8u;
    // 801108F8: lwz     r3, -26852(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26852);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801108FC:
    ctx->pc = 0x801108FCu;
    // 801108FC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80110900:
    ctx->pc = 0x80110900u;
    // 80110900: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_80110904:
    ctx->pc = 0x80110904u;
    // 80110904: stw     r0, 3356(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110908:
    ctx->pc = 0x80110908u;
    // 80110908: addi    r20, r1, 88
    ctx->gpr[20] = ctx->gpr[1] + (u32)(s32)(88);

label_8011090C:
    ctx->pc = 0x8011090Cu;
    // 8011090C: stfs     f13, 3368(r31)
    if (!ppc_fp_available_inline(ctx, 0x8011090Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3368);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80110910:
    ctx->pc = 0x80110910u;
    // 80110910: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80110914:
    ctx->pc = 0x80110914u;
    // 80110914: stfs     f0, 3576(r31)
    if (!ppc_fp_available_inline(ctx, 0x80110914u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3576);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80110918:
    ctx->pc = 0x80110918u;
    // 80110918: lis     r19, -32721
    ctx->gpr[19] = ((u32)(s32)(-32721) << 16);

label_8011091C:
    ctx->pc = 0x8011091Cu;
    // 8011091C: stw     r29, 3328(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3328);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80110920:
    ctx->pc = 0x80110920u;
    // 80110920: stw     r30, 3352(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80110924:
    ctx->pc = 0x80110924u;
    // 80110924: stw     r29, 3360(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3360);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80110928:
    ctx->pc = 0x80110928u;
    // 80110928: bl      0x8027B08C
    {
            ctx->lr = 0x8011092Cu;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_8011092C:
    ctx->pc = 0x8011092Cu;
    ctx->downcount -= 3;
    // 8011092C: lwz     r3, -26848(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26848);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110930:
    ctx->pc = 0x80110930u;
    // 80110930: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80110934:
    ctx->pc = 0x80110934u;
    // 80110934: bl      0x8027B08C
    {
            ctx->lr = 0x80110938u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110938:
    ctx->pc = 0x80110938u;
    ctx->downcount -= 3;
    // 80110938: lwz     r3, -26844(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26844);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8011093C:
    ctx->pc = 0x8011093Cu;
    // 8011093C: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_80110940:
    ctx->pc = 0x80110940u;
    // 80110940: bl      0x8027B08C
    {
            ctx->lr = 0x80110944u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110944:
    ctx->pc = 0x80110944u;
    ctx->downcount -= 3;
    // 80110944: lwz     r3, -26840(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26840);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110948:
    ctx->pc = 0x80110948u;
    // 80110948: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8011094C:
    ctx->pc = 0x8011094Cu;
    // 8011094C: bl      0x8027B08C
    {
            ctx->lr = 0x80110950u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110950:
    ctx->pc = 0x80110950u;
    ctx->downcount -= 3;
    // 80110950: lwz     r3, -26984(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26984);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110954:
    ctx->pc = 0x80110954u;
    // 80110954: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80110958:
    ctx->pc = 0x80110958u;
    // 80110958: bl      0x8027B08C
    {
            ctx->lr = 0x8011095Cu;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_8011095C:
    ctx->pc = 0x8011095Cu;
    ctx->downcount -= 12;
    // 8011095C: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80110960:
    ctx->pc = 0x80110960u;
    // 80110960: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80110964:
    ctx->pc = 0x80110964u;
    // 80110964: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_80110968:
    ctx->pc = 0x80110968u;
    // 80110968: lfs     f13, 5516(r9)
    if (!ppc_fp_available_inline(ctx, 0x80110968u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8011096C:
    ctx->pc = 0x8011096Cu;
    // 8011096C: lfs     f12, 5520(r11)
    if (!ppc_fp_available_inline(ctx, 0x8011096Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80110970:
    ctx->pc = 0x80110970u;
    // 80110970: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80110974:
    ctx->pc = 0x80110974u;
    // 80110974: lfs     f0, 5524(r10)
    if (!ppc_fp_available_inline(ctx, 0x80110974u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(5524);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80110978:
    ctx->pc = 0x80110978u;
    // 80110978: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8011097C:
    ctx->pc = 0x8011097Cu;
    // 8011097C: stfs     f13, 3340(r31)
    if (!ppc_fp_available_inline(ctx, 0x8011097Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3340);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80110980:
    ctx->pc = 0x80110980u;
    // 80110980: stfs     f12, 3336(r31)
    if (!ppc_fp_available_inline(ctx, 0x80110980u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3336);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80110984:
    ctx->pc = 0x80110984u;
    // 80110984: stfs     f0, 3344(r31)
    if (!ppc_fp_available_inline(ctx, 0x80110984u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3344);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80110988:
    ctx->pc = 0x80110988u;
    // 80110988: bl      0x80100A48
    {
            ctx->lr = 0x8011098Cu;
            ctx->pc = 0x80100A48u;
            return;
    }

label_8011098C:
    ctx->pc = 0x8011098Cu;
    ctx->downcount -= 2;
    // 8011098C: lis     r3, 1
    ctx->gpr[3] = ((u32)(s32)(1) << 16);

label_80110990:
    ctx->pc = 0x80110990u;
    // 80110990: bl      0x80281D20
    {
            ctx->lr = 0x80110994u;
            ctx->pc = 0x80281D20u;
            return;
    }

label_80110994:
    ctx->pc = 0x80110994u;
    ctx->downcount -= 3;
    // 80110994: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110998:
    ctx->pc = 0x80110998u;
    // 80110998: lis     r4, 1
    ctx->gpr[4] = ((u32)(s32)(1) << 16);

label_8011099C:
    ctx->pc = 0x8011099Cu;
    // 8011099C: bl      0x80287D6C
    {
            ctx->lr = 0x801109A0u;
            ctx->pc = 0x80287D6Cu;
            return;
    }

label_801109A0:
    ctx->pc = 0x801109A0u;
    ctx->downcount -= 11;
    // 801109A0: addi    r9, r1, 8
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(8);

label_801109A4:
    ctx->pc = 0x801109A4u;
    // 801109A4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801109A8:
    ctx->pc = 0x801109A8u;
    // 801109A8: stw     r30, 72(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801109AC:
    ctx->pc = 0x801109ACu;
    // 801109AC: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801109B0:
    ctx->pc = 0x801109B0u;
    // 801109B0: stw     r30, 52(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801109B4:
    ctx->pc = 0x801109B4u;
    // 801109B4: stw     r30, 56(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801109B8:
    ctx->pc = 0x801109B8u;
    // 801109B8: stw     r29, 60(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801109BC:
    ctx->pc = 0x801109BCu;
    // 801109BC: stw     r30, 64(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801109C0:
    ctx->pc = 0x801109C0u;
    // 801109C0: stw     r30, 68(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801109C4:
    ctx->pc = 0x801109C4u;
    // 801109C4: stw     r29, 76(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801109C8:
    ctx->pc = 0x801109C8u;
    // 801109C8: bl      0x80239E78
    {
            ctx->lr = 0x801109CCu;
            ctx->pc = 0x80239E78u;
            return;
    }

label_801109CC:
    ctx->pc = 0x801109CCu;
    ctx->downcount -= 5;
    // 801109CC: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801109D0:
    ctx->pc = 0x801109D0u;
    // 801109D0: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_801109D4:
    ctx->pc = 0x801109D4u;
    // 801109D4: stw     r29, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801109D8:
    ctx->pc = 0x801109D8u;
    // 801109D8: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801109DC:
    ctx->pc = 0x801109DCu;
    // 801109DC: bc    4, 0, 0x801116A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801116A8;
        }
    }

label_801109E0:
    ctx->pc = 0x801109E0u;
    ctx->downcount -= 5;
    // 801109E0: or   r29, r31, r31
    {
        ctx->gpr[29] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801109E4:
    ctx->pc = 0x801109E4u;
    // 801109E4: li      r25, 1
    ctx->gpr[25] = (u32)(s32)(1);

label_801109E8:
    ctx->pc = 0x801109E8u;
    // 801109E8: addi    r22, r29, 3020
    ctx->gpr[22] = ctx->gpr[29] + (u32)(s32)(3020);

label_801109EC:
    ctx->pc = 0x801109ECu;
    // 801109EC: li      r31, 6
    ctx->gpr[31] = (u32)(s32)(6);

label_801109F0:
    ctx->pc = 0x801109F0u;
    // 801109F0: li      r27, 11
    ctx->gpr[27] = (u32)(s32)(11);

label_801109F4:
    ctx->pc = 0x801109F4u;
    ctx->downcount -= 7;
    // 801109F4: lwz     r9, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801109F8:
    // 801109F8: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_801109FC:
    // 801109FC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110A00:
    ctx->pc = 0x80110A00u;
    // 80110A00: lwzx    r30, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80110A04:
    // 80110A04: addi    r4, r4, 5012
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5012);

label_80110A08:
    // 80110A08: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110A0C:
    // 80110A0C: bl      0x80297FBC
    {
            ctx->lr = 0x80110A10u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110A10:
    ctx->downcount -= 2;
    // 80110A10: cmpwi   r3, 0
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

label_80110A14:
    // 80110A14: bc    4, 2, 0x80110A20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110A20;
        }
    }

label_80110A18:
    ctx->downcount -= 2;
    // 80110A18: li      r26, 1
    ctx->gpr[26] = (u32)(s32)(1);

label_80110A1C:
    // 80110A1C: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110A20:
    ctx->downcount -= 4;
    // 80110A20: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110A24:
    // 80110A24: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110A28:
    // 80110A28: addi    r4, r4, 5024
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5024);

label_80110A2C:
    // 80110A2C: bl      0x80297FBC
    {
            ctx->lr = 0x80110A30u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110A30:
    ctx->downcount -= 2;
    // 80110A30: cmpwi   r3, 0
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

label_80110A34:
    // 80110A34: bc    4, 2, 0x80110A40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110A40;
        }
    }

label_80110A38:
    ctx->pc = 0x80110A38u;
    ctx->downcount -= 2;
    // 80110A38: stw     r25, 3240(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3240);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80110A3C:
    // 80110A3C: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110A40:
    ctx->downcount -= 4;
    // 80110A40: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110A44:
    // 80110A44: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110A48:
    // 80110A48: addi    r4, r4, 5036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5036);

label_80110A4C:
    // 80110A4C: bl      0x80297FBC
    {
            ctx->lr = 0x80110A50u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110A50:
    ctx->downcount -= 2;
    // 80110A50: cmpwi   r3, 0
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

label_80110A54:
    // 80110A54: bc    4, 2, 0x80110A60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110A60;
        }
    }

label_80110A58:
    ctx->pc = 0x80110A58u;
    ctx->downcount -= 2;
    // 80110A58: lwz     r3, -27648(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27648);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110A5C:
    // 80110A5C: b       0x80110CCC
    {
            goto label_80110CCC;
    }

label_80110A60:
    ctx->downcount -= 4;
    // 80110A60: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110A64:
    // 80110A64: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110A68:
    // 80110A68: addi    r4, r4, 5048
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5048);

label_80110A6C:
    // 80110A6C: bl      0x80297FBC
    {
            ctx->lr = 0x80110A70u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110A70:
    ctx->downcount -= 2;
    // 80110A70: cmpwi   r3, 0
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

label_80110A74:
    // 80110A74: bc    4, 2, 0x80110A8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110A8C;
        }
    }

label_80110A78:
    ctx->downcount -= 4;
    // 80110A78: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80110A7C:
    // 80110A7C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80110A80:
    ctx->pc = 0x80110A80u;
    // 80110A80: lwz     r3, -21720(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21720);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110A84:
    // 80110A84: bl      0x8027B08C
    {
            ctx->lr = 0x80110A88u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110A88:
    ctx->downcount -= 1;
    // 80110A88: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110A8C:
    ctx->downcount -= 4;
    // 80110A8C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110A90:
    // 80110A90: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110A94:
    // 80110A94: addi    r4, r4, 5064
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5064);

label_80110A98:
    // 80110A98: bl      0x80297FBC
    {
            ctx->lr = 0x80110A9Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110A9C:
    ctx->downcount -= 2;
    // 80110A9C: cmpwi   r3, 0
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

label_80110AA0:
    // 80110AA0: bc    4, 2, 0x80110AD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110AD4;
        }
    }

label_80110AA4:
    ctx->pc = 0x80110AA4u;
    ctx->downcount -= 6;
    // 80110AA4: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110AA8:
    ctx->pc = 0x80110AA8u;
    // 80110AA8: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110AAC:
    // 80110AAC: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110AB0:
    // 80110AB0: cmpw    r9, r0
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

label_80110AB4:
    ctx->pc = 0x80110AB4u;
    // 80110AB4: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110AB8:
    // 80110AB8: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110ABC:
    ctx->pc = 0x80110ABCu;
    ctx->downcount -= 4;
    // 80110ABC: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110AC0:
    // 80110AC0: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110AC4:
    ctx->pc = 0x80110AC4u;
    // 80110AC4: lwzx    r3, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110AC8:
    // 80110AC8: bl      0x8029692C
    {
            ctx->lr = 0x80110ACCu;
            ctx->pc = 0x8029692Cu;
            return;
    }

label_80110ACC:
    ctx->pc = 0x80110ACCu;
    ctx->downcount -= 2;
    // 80110ACC: stfs     f1, 3368(r29)
    if (!ppc_fp_available_inline(ctx, 0x80110ACCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3368);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80110AD0:
    // 80110AD0: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110AD4:
    ctx->downcount -= 4;
    // 80110AD4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110AD8:
    // 80110AD8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110ADC:
    // 80110ADC: addi    r4, r4, 5076
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5076);

label_80110AE0:
    // 80110AE0: bl      0x80297FBC
    {
            ctx->lr = 0x80110AE4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110AE4:
    ctx->downcount -= 2;
    // 80110AE4: cmpwi   r3, 0
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

label_80110AE8:
    // 80110AE8: bc    4, 2, 0x80110AF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110AF4;
        }
    }

label_80110AEC:
    ctx->pc = 0x80110AECu;
    ctx->downcount -= 2;
    // 80110AEC: lwz     r3, -27288(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27288);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110AF0:
    // 80110AF0: b       0x80110F24
    {
            goto label_80110F24;
    }

label_80110AF4:
    ctx->downcount -= 4;
    // 80110AF4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110AF8:
    // 80110AF8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110AFC:
    // 80110AFC: addi    r4, r4, 5084
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5084);

label_80110B00:
    // 80110B00: bl      0x80297FBC
    {
            ctx->lr = 0x80110B04u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110B04:
    ctx->downcount -= 2;
    // 80110B04: cmpwi   r3, 0
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

label_80110B08:
    // 80110B08: bc    4, 2, 0x80110B3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110B3C;
        }
    }

label_80110B0C:
    ctx->pc = 0x80110B0Cu;
    ctx->downcount -= 6;
    // 80110B0C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110B10:
    ctx->pc = 0x80110B10u;
    // 80110B10: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110B14:
    // 80110B14: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110B18:
    // 80110B18: cmpw    r9, r0
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

label_80110B1C:
    ctx->pc = 0x80110B1Cu;
    // 80110B1C: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110B20:
    // 80110B20: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110B24:
    ctx->pc = 0x80110B24u;
    ctx->downcount -= 4;
    // 80110B24: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110B28:
    // 80110B28: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110B2C:
    ctx->pc = 0x80110B2Cu;
    // 80110B2C: lwzx    r3, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110B30:
    // 80110B30: bl      0x80296950
    {
            ctx->lr = 0x80110B34u;
            ctx->pc = 0x80296950u;
            return;
    }

label_80110B34:
    ctx->pc = 0x80110B34u;
    ctx->downcount -= 2;
    // 80110B34: stw     r3, -30328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30328);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80110B38:
    // 80110B38: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110B3C:
    ctx->downcount -= 4;
    // 80110B3C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110B40:
    // 80110B40: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110B44:
    // 80110B44: addi    r4, r4, 5100
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5100);

label_80110B48:
    // 80110B48: bl      0x80297FBC
    {
            ctx->lr = 0x80110B4Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110B4C:
    ctx->downcount -= 2;
    // 80110B4C: cmpwi   r3, 0
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

label_80110B50:
    // 80110B50: bc    4, 2, 0x80110B84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110B84;
        }
    }

label_80110B54:
    ctx->pc = 0x80110B54u;
    ctx->downcount -= 6;
    // 80110B54: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110B58:
    ctx->pc = 0x80110B58u;
    // 80110B58: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110B5C:
    // 80110B5C: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110B60:
    // 80110B60: cmpw    r9, r0
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

label_80110B64:
    ctx->pc = 0x80110B64u;
    // 80110B64: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110B68:
    // 80110B68: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110B6C:
    ctx->pc = 0x80110B6Cu;
    ctx->downcount -= 4;
    // 80110B6C: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110B70:
    // 80110B70: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110B74:
    ctx->pc = 0x80110B74u;
    // 80110B74: lwzx    r3, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110B78:
    // 80110B78: bl      0x8029692C
    {
            ctx->lr = 0x80110B7Cu;
            ctx->pc = 0x8029692Cu;
            return;
    }

label_80110B7C:
    ctx->pc = 0x80110B7Cu;
    ctx->downcount -= 2;
    // 80110B7C: stfs     f1, -31952(r13)
    if (!ppc_fp_available_inline(ctx, 0x80110B7Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31952);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80110B80:
    // 80110B80: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110B84:
    ctx->downcount -= 4;
    // 80110B84: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110B88:
    // 80110B88: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110B8C:
    // 80110B8C: addi    r4, r4, 5112
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5112);

label_80110B90:
    // 80110B90: bl      0x80297FBC
    {
            ctx->lr = 0x80110B94u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110B94:
    ctx->downcount -= 2;
    // 80110B94: cmpwi   r3, 0
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

label_80110B98:
    // 80110B98: bc    4, 2, 0x80110BDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110BDC;
        }
    }

label_80110B9C:
    ctx->pc = 0x80110B9Cu;
    ctx->downcount -= 6;
    // 80110B9C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110BA0:
    ctx->pc = 0x80110BA0u;
    // 80110BA0: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110BA4:
    // 80110BA4: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110BA8:
    // 80110BA8: cmpw    r9, r0
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

label_80110BAC:
    ctx->pc = 0x80110BACu;
    // 80110BAC: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110BB0:
    // 80110BB0: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110BB4:
    ctx->pc = 0x80110BB4u;
    ctx->downcount -= 12;
    // 80110BB4: lwz     r11, 3012(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3012);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110BB8:
    // 80110BB8: rlwinm r10, r9, 2, 0, 29
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110BBC:
    ctx->pc = 0x80110BBCu;
    // 80110BBC: lwz     r9, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110BC0:
    // 80110BC0: mulli   r11, r11, 48
    ctx->gpr[11] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)48);

label_80110BC4:
    ctx->pc = 0x80110BC4u;
    // 80110BC4: lwzx    r0, r10, r9
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110BC8:
    ctx->pc = 0x80110BC8u;
    // 80110BC8: stwx    r0, r22, r11
    {
        u32 ea = ctx->gpr[22] + ctx->gpr[11];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110BCC:
    ctx->pc = 0x80110BCCu;
    // 80110BCC: lwz     r9, 3012(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3012);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110BD0:
    // 80110BD0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110BD4:
    ctx->pc = 0x80110BD4u;
    // 80110BD4: stw     r9, 3012(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3012);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110BD8:
    // 80110BD8: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110BDC:
    ctx->downcount -= 4;
    // 80110BDC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110BE0:
    // 80110BE0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110BE4:
    // 80110BE4: addi    r4, r4, 5120
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5120);

label_80110BE8:
    // 80110BE8: bl      0x80297FBC
    {
            ctx->lr = 0x80110BECu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110BEC:
    ctx->downcount -= 2;
    // 80110BEC: cmpwi   r3, 0
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

label_80110BF0:
    // 80110BF0: bc    4, 2, 0x80110C58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110C58;
        }
    }

label_80110BF4:
    ctx->pc = 0x80110BF4u;
    ctx->downcount -= 6;
    // 80110BF4: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110BF8:
    ctx->pc = 0x80110BF8u;
    // 80110BF8: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110BFC:
    // 80110BFC: addi    r8, r9, 1
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(1);

label_80110C00:
    // 80110C00: cmpw    r8, r0
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80110C04:
    ctx->pc = 0x80110C04u;
    // 80110C04: stw     r8, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80110C08:
    // 80110C08: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110C0C:
    ctx->pc = 0x80110C0Cu;
    ctx->downcount -= 25;
    // 80110C0C: lwz     r11, 3012(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3012);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110C10:
    // 80110C10: rlwinm r8, r8, 2, 0, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 2u) & 0xFFFFFFFCu;
    }

label_80110C14:
    ctx->pc = 0x80110C14u;
    // 80110C14: lwz     r10, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80110C18:
    // 80110C18: addi    r6, r29, 3016
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(3016);

label_80110C1C:
    // 80110C1C: mulli   r11, r11, 48
    ctx->gpr[11] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)48);

label_80110C20:
    // 80110C20: addi    r5, r29, 3024
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(3024);

label_80110C24:
    ctx->pc = 0x80110C24u;
    // 80110C24: lwzx    r9, r8, r10
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[10];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110C28:
    // 80110C28: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_80110C2C:
    ctx->pc = 0x80110C2Cu;
    // 80110C2C: stwx    r9, r22, r11
    {
        u32 ea = ctx->gpr[22] + ctx->gpr[11];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110C30:
    ctx->pc = 0x80110C30u;
    // 80110C30: lwz     r0, 3012(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3012);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110C34:
    // 80110C34: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80110C38:
    ctx->pc = 0x80110C38u;
    // 80110C38: stwx    r25, r6, r0
    {
        u32 ea = ctx->gpr[6] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80110C3C:
    ctx->pc = 0x80110C3Cu;
    // 80110C3C: lwz     r9, 3012(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3012);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110C40:
    // 80110C40: mulli   r9, r9, 48
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)48);

label_80110C44:
    ctx->pc = 0x80110C44u;
    // 80110C44: stwx    r7, r5, r9
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80110C48:
    ctx->pc = 0x80110C48u;
    // 80110C48: lwz     r11, 3012(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3012);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110C4C:
    // 80110C4C: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_80110C50:
    ctx->pc = 0x80110C50u;
    // 80110C50: stw     r11, 3012(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3012);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80110C54:
    // 80110C54: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110C58:
    ctx->downcount -= 4;
    // 80110C58: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110C5C:
    // 80110C5C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110C60:
    // 80110C60: addi    r4, r4, 5132
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5132);

label_80110C64:
    // 80110C64: bl      0x80297FBC
    {
            ctx->lr = 0x80110C68u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110C68:
    ctx->downcount -= 2;
    // 80110C68: cmpwi   r3, 0
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

label_80110C6C:
    // 80110C6C: bc    4, 2, 0x80110CB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110CB0;
        }
    }

label_80110C70:
    ctx->pc = 0x80110C70u;
    ctx->downcount -= 6;
    // 80110C70: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110C74:
    ctx->pc = 0x80110C74u;
    // 80110C74: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110C78:
    // 80110C78: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110C7C:
    // 80110C7C: cmpw    r9, r0
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

label_80110C80:
    ctx->pc = 0x80110C80u;
    // 80110C80: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110C84:
    // 80110C84: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110C88:
    ctx->pc = 0x80110C88u;
    ctx->downcount -= 6;
    // 80110C88: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110C8C:
    // 80110C8C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110C90:
    // 80110C90: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80110C94:
    ctx->pc = 0x80110C94u;
    // 80110C94: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80110C98:
    // 80110C98: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80110C9C:
    // 80110C9C: bl      0x8010037C
    {
            ctx->lr = 0x80110CA0u;
            ctx->pc = 0x8010037Cu;
            return;
    }

label_80110CA0:
    ctx->downcount -= 3;
    // 80110CA0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80110CA4:
    // 80110CA4: addi    r3, r30, -25052
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-25052);

label_80110CA8:
    // 80110CA8: bl      0x80100A48
    {
            ctx->lr = 0x80110CACu;
            ctx->pc = 0x80100A48u;
            return;
    }

label_80110CAC:
    ctx->downcount -= 1;
    // 80110CAC: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110CB0:
    ctx->downcount -= 4;
    // 80110CB0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110CB4:
    // 80110CB4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110CB8:
    // 80110CB8: addi    r4, r4, 5144
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5144);

label_80110CBC:
    // 80110CBC: bl      0x80297FBC
    {
            ctx->lr = 0x80110CC0u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110CC0:
    ctx->downcount -= 2;
    // 80110CC0: cmpwi   r3, 0
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

label_80110CC4:
    // 80110CC4: bc    4, 2, 0x80110CD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110CD8;
        }
    }

label_80110CC8:
    ctx->pc = 0x80110CC8u;
    ctx->downcount -= 1;
    // 80110CC8: lwz     r3, -27340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27340);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110CCC:
    ctx->downcount -= 2;
    // 80110CCC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80110CD0:
    // 80110CD0: bl      0x8027B08C
    {
            ctx->lr = 0x80110CD4u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110CD4:
    ctx->downcount -= 1;
    // 80110CD4: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110CD8:
    ctx->downcount -= 4;
    // 80110CD8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110CDC:
    // 80110CDC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110CE0:
    // 80110CE0: addi    r4, r4, 5156
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5156);

label_80110CE4:
    // 80110CE4: bl      0x80297FBC
    {
            ctx->lr = 0x80110CE8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110CE8:
    ctx->downcount -= 2;
    // 80110CE8: cmpwi   r3, 0
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

label_80110CEC:
    // 80110CEC: bc    4, 2, 0x80110CF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110CF8;
        }
    }

label_80110CF0:
    ctx->downcount -= 2;
    // 80110CF0: li      r21, 1
    ctx->gpr[21] = (u32)(s32)(1);

label_80110CF4:
    // 80110CF4: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110CF8:
    ctx->downcount -= 4;
    // 80110CF8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110CFC:
    // 80110CFC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110D00:
    // 80110D00: addi    r4, r4, 5172
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5172);

label_80110D04:
    // 80110D04: bl      0x80297FBC
    {
            ctx->lr = 0x80110D08u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110D08:
    ctx->downcount -= 2;
    // 80110D08: cmpwi   r3, 0
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

label_80110D0C:
    // 80110D0C: bc    4, 2, 0x80110D18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110D18;
        }
    }

label_80110D10:
    ctx->pc = 0x80110D10u;
    ctx->downcount -= 2;
    // 80110D10: lwz     r3, -27228(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27228);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110D14:
    // 80110D14: b       0x80110F24
    {
            goto label_80110F24;
    }

label_80110D18:
    ctx->downcount -= 4;
    // 80110D18: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110D1C:
    // 80110D1C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110D20:
    // 80110D20: addi    r4, r4, 5184
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5184);

label_80110D24:
    // 80110D24: bl      0x80297FBC
    {
            ctx->lr = 0x80110D28u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110D28:
    ctx->downcount -= 2;
    // 80110D28: cmpwi   r3, 0
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

label_80110D2C:
    // 80110D2C: bc    4, 2, 0x80110D38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110D38;
        }
    }

label_80110D30:
    ctx->pc = 0x80110D30u;
    ctx->downcount -= 2;
    // 80110D30: lwz     r3, -27744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110D34:
    // 80110D34: b       0x80110F24
    {
            goto label_80110F24;
    }

label_80110D38:
    ctx->downcount -= 4;
    // 80110D38: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110D3C:
    // 80110D3C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110D40:
    // 80110D40: addi    r4, r4, 5196
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5196);

label_80110D44:
    // 80110D44: bl      0x80297FBC
    {
            ctx->lr = 0x80110D48u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110D48:
    ctx->downcount -= 2;
    // 80110D48: cmpwi   r3, 0
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

label_80110D4C:
    // 80110D4C: bc    4, 2, 0x80110D80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110D80;
        }
    }

label_80110D50:
    ctx->pc = 0x80110D50u;
    ctx->downcount -= 6;
    // 80110D50: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110D54:
    ctx->pc = 0x80110D54u;
    // 80110D54: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110D58:
    // 80110D58: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110D5C:
    // 80110D5C: cmpw    r9, r0
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

label_80110D60:
    ctx->pc = 0x80110D60u;
    // 80110D60: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110D64:
    // 80110D64: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110D68:
    ctx->pc = 0x80110D68u;
    ctx->downcount -= 4;
    // 80110D68: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110D6C:
    // 80110D6C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110D70:
    ctx->pc = 0x80110D70u;
    // 80110D70: lwzx    r3, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110D74:
    // 80110D74: bl      0x8029692C
    {
            ctx->lr = 0x80110D78u;
            ctx->pc = 0x8029692Cu;
            return;
    }

label_80110D78:
    ctx->pc = 0x80110D78u;
    ctx->downcount -= 2;
    // 80110D78: stfs     f1, 3336(r29)
    if (!ppc_fp_available_inline(ctx, 0x80110D78u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3336);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80110D7C:
    // 80110D7C: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110D80:
    ctx->downcount -= 4;
    // 80110D80: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110D84:
    // 80110D84: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110D88:
    // 80110D88: addi    r4, r4, 5212
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5212);

label_80110D8C:
    // 80110D8C: bl      0x80297FBC
    {
            ctx->lr = 0x80110D90u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110D90:
    ctx->downcount -= 2;
    // 80110D90: cmpwi   r3, 0
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

label_80110D94:
    // 80110D94: bc    4, 2, 0x80110DC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110DC8;
        }
    }

label_80110D98:
    ctx->pc = 0x80110D98u;
    ctx->downcount -= 6;
    // 80110D98: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110D9C:
    ctx->pc = 0x80110D9Cu;
    // 80110D9C: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110DA0:
    // 80110DA0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110DA4:
    // 80110DA4: cmpw    r9, r0
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

label_80110DA8:
    ctx->pc = 0x80110DA8u;
    // 80110DA8: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110DAC:
    // 80110DAC: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110DB0:
    ctx->pc = 0x80110DB0u;
    ctx->downcount -= 4;
    // 80110DB0: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110DB4:
    // 80110DB4: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110DB8:
    ctx->pc = 0x80110DB8u;
    // 80110DB8: lwzx    r3, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110DBC:
    // 80110DBC: bl      0x8029692C
    {
            ctx->lr = 0x80110DC0u;
            ctx->pc = 0x8029692Cu;
            return;
    }

label_80110DC0:
    ctx->pc = 0x80110DC0u;
    ctx->downcount -= 2;
    // 80110DC0: stfs     f1, -30960(r13)
    if (!ppc_fp_available_inline(ctx, 0x80110DC0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30960);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80110DC4:
    // 80110DC4: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110DC8:
    ctx->downcount -= 4;
    // 80110DC8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110DCC:
    // 80110DCC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110DD0:
    // 80110DD0: addi    r4, r4, 5224
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5224);

label_80110DD4:
    // 80110DD4: bl      0x80297FBC
    {
            ctx->lr = 0x80110DD8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110DD8:
    ctx->downcount -= 2;
    // 80110DD8: cmpwi   r3, 0
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

label_80110DDC:
    // 80110DDC: bc    4, 2, 0x80110E10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110E10;
        }
    }

label_80110DE0:
    ctx->pc = 0x80110DE0u;
    ctx->downcount -= 6;
    // 80110DE0: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110DE4:
    ctx->pc = 0x80110DE4u;
    // 80110DE4: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110DE8:
    // 80110DE8: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110DEC:
    // 80110DEC: cmpw    r9, r0
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

label_80110DF0:
    ctx->pc = 0x80110DF0u;
    // 80110DF0: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110DF4:
    // 80110DF4: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110DF8:
    ctx->pc = 0x80110DF8u;
    ctx->downcount -= 4;
    // 80110DF8: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110DFC:
    // 80110DFC: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110E00:
    ctx->pc = 0x80110E00u;
    // 80110E00: lwzx    r3, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110E04:
    // 80110E04: bl      0x8029692C
    {
            ctx->lr = 0x80110E08u;
            ctx->pc = 0x8029692Cu;
            return;
    }

label_80110E08:
    ctx->pc = 0x80110E08u;
    ctx->downcount -= 2;
    // 80110E08: stfs     f1, 3340(r29)
    if (!ppc_fp_available_inline(ctx, 0x80110E08u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3340);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80110E0C:
    // 80110E0C: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110E10:
    ctx->downcount -= 4;
    // 80110E10: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110E14:
    // 80110E14: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110E18:
    // 80110E18: addi    r4, r4, 5236
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5236);

label_80110E1C:
    // 80110E1C: bl      0x80297FBC
    {
            ctx->lr = 0x80110E20u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110E20:
    ctx->downcount -= 2;
    // 80110E20: cmpwi   r3, 0
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

label_80110E24:
    // 80110E24: bc    4, 2, 0x80110E58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110E58;
        }
    }

label_80110E28:
    ctx->pc = 0x80110E28u;
    ctx->downcount -= 6;
    // 80110E28: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110E2C:
    ctx->pc = 0x80110E2Cu;
    // 80110E2C: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110E30:
    // 80110E30: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80110E34:
    // 80110E34: cmpw    r9, r0
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

label_80110E38:
    ctx->pc = 0x80110E38u;
    // 80110E38: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80110E3C:
    // 80110E3C: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110E40:
    ctx->pc = 0x80110E40u;
    ctx->downcount -= 4;
    // 80110E40: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110E44:
    // 80110E44: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110E48:
    ctx->pc = 0x80110E48u;
    // 80110E48: lwzx    r3, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110E4C:
    // 80110E4C: bl      0x8029692C
    {
            ctx->lr = 0x80110E50u;
            ctx->pc = 0x8029692Cu;
            return;
    }

label_80110E50:
    ctx->pc = 0x80110E50u;
    ctx->downcount -= 2;
    // 80110E50: stfs     f1, 3344(r29)
    if (!ppc_fp_available_inline(ctx, 0x80110E50u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3344);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80110E54:
    // 80110E54: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110E58:
    ctx->downcount -= 4;
    // 80110E58: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110E5C:
    // 80110E5C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110E60:
    // 80110E60: addi    r4, r4, 5248
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5248);

label_80110E64:
    // 80110E64: bl      0x80297FBC
    {
            ctx->lr = 0x80110E68u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110E68:
    ctx->downcount -= 2;
    // 80110E68: cmpwi   r3, 0
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

label_80110E6C:
    // 80110E6C: bc    4, 2, 0x80110E84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110E84;
        }
    }

label_80110E70:
    ctx->downcount -= 4;
    // 80110E70: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80110E74:
    // 80110E74: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80110E78:
    ctx->pc = 0x80110E78u;
    // 80110E78: lwz     r3, -20012(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20012);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110E7C:
    // 80110E7C: bl      0x8027B08C
    {
            ctx->lr = 0x80110E80u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110E80:
    ctx->downcount -= 1;
    // 80110E80: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110E84:
    ctx->downcount -= 4;
    // 80110E84: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110E88:
    // 80110E88: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110E8C:
    // 80110E8C: addi    r4, r4, 5256
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5256);

label_80110E90:
    // 80110E90: bl      0x80297FBC
    {
            ctx->lr = 0x80110E94u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110E94:
    ctx->downcount -= 2;
    // 80110E94: cmpwi   r3, 0
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

label_80110E98:
    // 80110E98: bc    4, 2, 0x80110EB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110EB0;
        }
    }

label_80110E9C:
    ctx->downcount -= 4;
    // 80110E9C: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80110EA0:
    // 80110EA0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80110EA4:
    ctx->pc = 0x80110EA4u;
    // 80110EA4: lwz     r3, -20008(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20008);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110EA8:
    // 80110EA8: bl      0x8027B08C
    {
            ctx->lr = 0x80110EACu;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110EAC:
    ctx->downcount -= 1;
    // 80110EAC: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110EB0:
    ctx->downcount -= 4;
    // 80110EB0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110EB4:
    // 80110EB4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110EB8:
    // 80110EB8: addi    r4, r4, 5264
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5264);

label_80110EBC:
    // 80110EBC: bl      0x80297FBC
    {
            ctx->lr = 0x80110EC0u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110EC0:
    ctx->downcount -= 2;
    // 80110EC0: cmpwi   r3, 0
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

label_80110EC4:
    // 80110EC4: bc    4, 2, 0x80110EDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110EDC;
        }
    }

label_80110EC8:
    ctx->downcount -= 4;
    // 80110EC8: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80110ECC:
    // 80110ECC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80110ED0:
    ctx->pc = 0x80110ED0u;
    // 80110ED0: lwz     r3, -20004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20004);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110ED4:
    // 80110ED4: bl      0x8027B08C
    {
            ctx->lr = 0x80110ED8u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110ED8:
    ctx->downcount -= 1;
    // 80110ED8: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110EDC:
    ctx->downcount -= 4;
    // 80110EDC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110EE0:
    // 80110EE0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110EE4:
    // 80110EE4: addi    r4, r4, 5272
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5272);

label_80110EE8:
    // 80110EE8: bl      0x80297FBC
    {
            ctx->lr = 0x80110EECu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110EEC:
    ctx->downcount -= 2;
    // 80110EEC: cmpwi   r3, 0
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

label_80110EF0:
    // 80110EF0: bc    4, 2, 0x80110F08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110F08;
        }
    }

label_80110EF4:
    ctx->downcount -= 4;
    // 80110EF4: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80110EF8:
    // 80110EF8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80110EFC:
    ctx->pc = 0x80110EFCu;
    // 80110EFC: lwz     r3, -20000(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20000);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110F00:
    // 80110F00: bl      0x8027B08C
    {
            ctx->lr = 0x80110F04u;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110F04:
    ctx->downcount -= 1;
    // 80110F04: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110F08:
    ctx->downcount -= 4;
    // 80110F08: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110F0C:
    // 80110F0C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110F10:
    // 80110F10: addi    r4, r4, 5280
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5280);

label_80110F14:
    // 80110F14: bl      0x80297FBC
    {
            ctx->lr = 0x80110F18u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110F18:
    ctx->downcount -= 2;
    // 80110F18: cmpwi   r3, 0
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

label_80110F1C:
    // 80110F1C: bc    4, 2, 0x80110F30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110F30;
        }
    }

label_80110F20:
    ctx->pc = 0x80110F20u;
    ctx->downcount -= 1;
    // 80110F20: lwz     r3, -27268(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27268);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80110F24:
    ctx->downcount -= 2;
    // 80110F24: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80110F28:
    // 80110F28: bl      0x8027B08C
    {
            ctx->lr = 0x80110F2Cu;
            ctx->pc = 0x8027B08Cu;
            return;
    }

label_80110F2C:
    ctx->downcount -= 1;
    // 80110F2C: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110F30:
    ctx->downcount -= 4;
    // 80110F30: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80110F34:
    // 80110F34: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80110F38:
    // 80110F38: addi    r4, r4, 5292
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5292);

label_80110F3C:
    // 80110F3C: bl      0x80297FBC
    {
            ctx->lr = 0x80110F40u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110F40:
    ctx->downcount -= 2;
    // 80110F40: cmpwi   r3, 0
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

label_80110F44:
    // 80110F44: bc    4, 2, 0x80111074
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111074;
        }
    }

label_80110F48:
    ctx->pc = 0x80110F48u;
    ctx->downcount -= 6;
    // 80110F48: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110F4C:
    ctx->pc = 0x80110F4Cu;
    // 80110F4C: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80110F50:
    // 80110F50: addi    r11, r9, 1
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(1);

label_80110F54:
    // 80110F54: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80110F58:
    ctx->pc = 0x80110F58u;
    // 80110F58: stw     r11, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80110F5C:
    // 80110F5C: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80110F60:
    ctx->pc = 0x80110F60u;
    ctx->downcount -= 6;
    // 80110F60: lwz     r9, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110F64:
    // 80110F64: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_80110F68:
    // 80110F68: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80110F6C:
    ctx->pc = 0x80110F6Cu;
    // 80110F6C: lwzx    r4, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80110F70:
    // 80110F70: addi    r3, r3, 5300
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5300);

label_80110F74:
    // 80110F74: bl      0x80297FBC
    {
            ctx->lr = 0x80110F78u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110F78:
    ctx->downcount -= 2;
    // 80110F78: or.   r3, r3, r3
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

label_80110F7C:
    // 80110F7C: bc    4, 2, 0x80110F88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110F88;
        }
    }

label_80110F80:
    ctx->pc = 0x80110F80u;
    ctx->downcount -= 2;
    // 80110F80: stw     r3, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80110F84:
    // 80110F84: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110F88:
    ctx->pc = 0x80110F88u;
    ctx->downcount -= 7;
    // 80110F88: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110F8C:
    // 80110F8C: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80110F90:
    ctx->pc = 0x80110F90u;
    // 80110F90: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110F94:
    // 80110F94: addi    r3, r3, 5304
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5304);

label_80110F98:
    // 80110F98: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110F9C:
    ctx->pc = 0x80110F9Cu;
    // 80110F9C: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80110FA0:
    // 80110FA0: bl      0x80297FBC
    {
            ctx->lr = 0x80110FA4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110FA4:
    ctx->downcount -= 2;
    // 80110FA4: cmpwi   r3, 0
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

label_80110FA8:
    // 80110FA8: bc    4, 2, 0x80110FB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110FB4;
        }
    }

label_80110FAC:
    ctx->pc = 0x80110FACu;
    ctx->downcount -= 2;
    // 80110FAC: stw     r25, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80110FB0:
    // 80110FB0: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110FB4:
    ctx->pc = 0x80110FB4u;
    ctx->downcount -= 7;
    // 80110FB4: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110FB8:
    // 80110FB8: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80110FBC:
    ctx->pc = 0x80110FBCu;
    // 80110FBC: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110FC0:
    // 80110FC0: addi    r3, r3, 5308
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5308);

label_80110FC4:
    // 80110FC4: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110FC8:
    ctx->pc = 0x80110FC8u;
    // 80110FC8: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80110FCC:
    // 80110FCC: bl      0x80297FBC
    {
            ctx->lr = 0x80110FD0u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80110FD0:
    ctx->downcount -= 2;
    // 80110FD0: cmpwi   r3, 0
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

label_80110FD4:
    // 80110FD4: bc    4, 2, 0x80110FE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80110FE4;
        }
    }

label_80110FD8:
    ctx->downcount -= 3;
    // 80110FD8: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80110FDC:
    ctx->pc = 0x80110FDCu;
    // 80110FDC: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80110FE0:
    // 80110FE0: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80110FE4:
    ctx->pc = 0x80110FE4u;
    ctx->downcount -= 7;
    // 80110FE4: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80110FE8:
    // 80110FE8: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80110FEC:
    ctx->pc = 0x80110FECu;
    // 80110FEC: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80110FF0:
    // 80110FF0: addi    r3, r3, 5312
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5312);

label_80110FF4:
    // 80110FF4: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80110FF8:
    ctx->pc = 0x80110FF8u;
    // 80110FF8: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80110FFC:
    // 80110FFC: bl      0x80297FBC
    {
            ctx->lr = 0x80111000u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111000:
    ctx->downcount -= 2;
    // 80111000: cmpwi   r3, 0
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

label_80111004:
    // 80111004: bc    4, 2, 0x80111014
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111014;
        }
    }

label_80111008:
    ctx->downcount -= 3;
    // 80111008: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8011100C:
    ctx->pc = 0x8011100Cu;
    // 8011100C: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111010:
    // 80111010: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111014:
    ctx->pc = 0x80111014u;
    ctx->downcount -= 7;
    // 80111014: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111018:
    // 80111018: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_8011101C:
    ctx->pc = 0x8011101Cu;
    // 8011101C: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111020:
    // 80111020: addi    r3, r3, 5316
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5316);

label_80111024:
    // 80111024: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111028:
    ctx->pc = 0x80111028u;
    // 80111028: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8011102C:
    // 8011102C: bl      0x80297FBC
    {
            ctx->lr = 0x80111030u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111030:
    ctx->downcount -= 2;
    // 80111030: cmpwi   r3, 0
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

label_80111034:
    // 80111034: bc    4, 2, 0x80111044
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111044;
        }
    }

label_80111038:
    ctx->downcount -= 3;
    // 80111038: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8011103C:
    ctx->pc = 0x8011103Cu;
    // 8011103C: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111040:
    // 80111040: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111044:
    ctx->pc = 0x80111044u;
    ctx->downcount -= 7;
    // 80111044: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111048:
    // 80111048: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_8011104C:
    ctx->pc = 0x8011104Cu;
    // 8011104C: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111050:
    // 80111050: addi    r3, r3, 5320
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5320);

label_80111054:
    // 80111054: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111058:
    ctx->pc = 0x80111058u;
    // 80111058: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8011105C:
    // 8011105C: bl      0x80297FBC
    {
            ctx->lr = 0x80111060u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111060:
    ctx->downcount -= 2;
    // 80111060: cmpwi   r3, 0
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

label_80111064:
    // 80111064: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111068:
    ctx->downcount -= 3;
    // 80111068: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8011106C:
    ctx->pc = 0x8011106Cu;
    // 8011106C: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111070:
    // 80111070: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111074:
    ctx->downcount -= 4;
    // 80111074: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80111078:
    // 80111078: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8011107C:
    // 8011107C: addi    r4, r4, 5324
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5324);

label_80111080:
    // 80111080: bl      0x80297FBC
    {
            ctx->lr = 0x80111084u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111084:
    ctx->downcount -= 2;
    // 80111084: cmpwi   r3, 0
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

label_80111088:
    // 80111088: bc    4, 2, 0x8011118C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011118C;
        }
    }

label_8011108C:
    ctx->pc = 0x8011108Cu;
    ctx->downcount -= 6;
    // 8011108C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111090:
    ctx->pc = 0x80111090u;
    // 80111090: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111094:
    // 80111094: addi    r11, r9, 1
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(1);

label_80111098:
    // 80111098: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8011109C:
    ctx->pc = 0x8011109Cu;
    // 8011109C: stw     r11, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801110A0:
    // 801110A0: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_801110A4:
    ctx->pc = 0x801110A4u;
    ctx->downcount -= 6;
    // 801110A4: lwz     r9, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801110A8:
    // 801110A8: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_801110AC:
    // 801110AC: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801110B0:
    ctx->pc = 0x801110B0u;
    // 801110B0: lwzx    r4, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801110B4:
    // 801110B4: addi    r3, r3, 5300
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5300);

label_801110B8:
    // 801110B8: bl      0x80297FBC
    {
            ctx->lr = 0x801110BCu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801110BC:
    ctx->downcount -= 2;
    // 801110BC: cmpwi   r3, 0
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

label_801110C0:
    // 801110C0: bc    4, 2, 0x801110CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801110CC;
        }
    }

label_801110C4:
    ctx->pc = 0x801110C4u;
    ctx->downcount -= 2;
    // 801110C4: stw     r31, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801110C8:
    // 801110C8: b       0x8011168C
    {
            goto label_8011168C;
    }

label_801110CC:
    ctx->pc = 0x801110CCu;
    ctx->downcount -= 7;
    // 801110CC: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801110D0:
    // 801110D0: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801110D4:
    ctx->pc = 0x801110D4u;
    // 801110D4: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801110D8:
    // 801110D8: addi    r3, r3, 5332
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5332);

label_801110DC:
    // 801110DC: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801110E0:
    ctx->pc = 0x801110E0u;
    // 801110E0: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801110E4:
    // 801110E4: bl      0x80297FBC
    {
            ctx->lr = 0x801110E8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801110E8:
    ctx->downcount -= 2;
    // 801110E8: cmpwi   r3, 0
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

label_801110EC:
    // 801110EC: bc    4, 2, 0x801110FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801110FC;
        }
    }

label_801110F0:
    ctx->downcount -= 3;
    // 801110F0: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_801110F4:
    ctx->pc = 0x801110F4u;
    // 801110F4: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801110F8:
    // 801110F8: b       0x8011168C
    {
            goto label_8011168C;
    }

label_801110FC:
    ctx->pc = 0x801110FCu;
    ctx->downcount -= 7;
    // 801110FC: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111100:
    // 80111100: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111104:
    ctx->pc = 0x80111104u;
    // 80111104: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111108:
    // 80111108: addi    r3, r3, 5304
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5304);

label_8011110C:
    // 8011110C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111110:
    ctx->pc = 0x80111110u;
    // 80111110: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111114:
    // 80111114: bl      0x80297FBC
    {
            ctx->lr = 0x80111118u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111118:
    ctx->downcount -= 2;
    // 80111118: cmpwi   r3, 0
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

label_8011111C:
    // 8011111C: bc    4, 2, 0x8011112C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011112C;
        }
    }

label_80111120:
    ctx->downcount -= 3;
    // 80111120: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_80111124:
    ctx->pc = 0x80111124u;
    // 80111124: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111128:
    // 80111128: b       0x8011168C
    {
            goto label_8011168C;
    }

label_8011112C:
    ctx->pc = 0x8011112Cu;
    ctx->downcount -= 7;
    // 8011112C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111130:
    // 80111130: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111134:
    ctx->pc = 0x80111134u;
    // 80111134: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111138:
    // 80111138: addi    r3, r3, 5336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5336);

label_8011113C:
    // 8011113C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111140:
    ctx->pc = 0x80111140u;
    // 80111140: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111144:
    // 80111144: bl      0x80297FBC
    {
            ctx->lr = 0x80111148u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111148:
    ctx->downcount -= 2;
    // 80111148: cmpwi   r3, 0
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

label_8011114C:
    // 8011114C: bc    4, 2, 0x8011115C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011115C;
        }
    }

label_80111150:
    ctx->downcount -= 3;
    // 80111150: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_80111154:
    ctx->pc = 0x80111154u;
    // 80111154: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111158:
    // 80111158: b       0x8011168C
    {
            goto label_8011168C;
    }

label_8011115C:
    ctx->pc = 0x8011115Cu;
    ctx->downcount -= 7;
    // 8011115C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111160:
    // 80111160: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111164:
    ctx->pc = 0x80111164u;
    // 80111164: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111168:
    // 80111168: addi    r3, r3, 5308
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5308);

label_8011116C:
    // 8011116C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111170:
    ctx->pc = 0x80111170u;
    // 80111170: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111174:
    // 80111174: bl      0x80297FBC
    {
            ctx->lr = 0x80111178u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111178:
    ctx->downcount -= 2;
    // 80111178: cmpwi   r3, 0
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

label_8011117C:
    // 8011117C: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111180:
    ctx->downcount -= 3;
    // 80111180: li      r0, 10
    ctx->gpr[0] = (u32)(s32)(10);

label_80111184:
    ctx->pc = 0x80111184u;
    // 80111184: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111188:
    // 80111188: b       0x8011168C
    {
            goto label_8011168C;
    }

label_8011118C:
    ctx->downcount -= 4;
    // 8011118C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80111190:
    // 80111190: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80111194:
    // 80111194: addi    r4, r4, 5340
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5340);

label_80111198:
    // 80111198: bl      0x80297FBC
    {
            ctx->lr = 0x8011119Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_8011119C:
    ctx->downcount -= 2;
    // 8011119C: cmpwi   r3, 0
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

label_801111A0:
    // 801111A0: bc    4, 2, 0x80111334
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111334;
        }
    }

label_801111A4:
    ctx->pc = 0x801111A4u;
    ctx->downcount -= 6;
    // 801111A4: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801111A8:
    ctx->pc = 0x801111A8u;
    // 801111A8: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801111AC:
    // 801111AC: addi    r11, r9, 1
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(1);

label_801111B0:
    // 801111B0: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801111B4:
    ctx->pc = 0x801111B4u;
    // 801111B4: stw     r11, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801111B8:
    // 801111B8: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_801111BC:
    ctx->pc = 0x801111BCu;
    ctx->downcount -= 6;
    // 801111BC: lwz     r9, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801111C0:
    // 801111C0: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_801111C4:
    // 801111C4: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801111C8:
    ctx->pc = 0x801111C8u;
    // 801111C8: lwzx    r4, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801111CC:
    // 801111CC: addi    r3, r3, 5348
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5348);

label_801111D0:
    // 801111D0: bl      0x80297FBC
    {
            ctx->lr = 0x801111D4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801111D4:
    ctx->downcount -= 2;
    // 801111D4: cmpwi   r3, 0
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

label_801111D8:
    // 801111D8: bc    4, 2, 0x801111E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801111E8;
        }
    }

label_801111DC:
    ctx->downcount -= 3;
    // 801111DC: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_801111E0:
    ctx->pc = 0x801111E0u;
    // 801111E0: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801111E4:
    // 801111E4: b       0x8011168C
    {
            goto label_8011168C;
    }

label_801111E8:
    ctx->pc = 0x801111E8u;
    ctx->downcount -= 7;
    // 801111E8: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801111EC:
    // 801111EC: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801111F0:
    ctx->pc = 0x801111F0u;
    // 801111F0: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801111F4:
    // 801111F4: addi    r3, r3, 5352
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5352);

label_801111F8:
    // 801111F8: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801111FC:
    ctx->pc = 0x801111FCu;
    // 801111FC: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111200:
    // 80111200: bl      0x80297FBC
    {
            ctx->lr = 0x80111204u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111204:
    ctx->downcount -= 2;
    // 80111204: cmpwi   r3, 0
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

label_80111208:
    // 80111208: bc    4, 2, 0x80111218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111218;
        }
    }

label_8011120C:
    ctx->downcount -= 3;
    // 8011120C: li      r0, 15
    ctx->gpr[0] = (u32)(s32)(15);

label_80111210:
    ctx->pc = 0x80111210u;
    // 80111210: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111214:
    // 80111214: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111218:
    ctx->pc = 0x80111218u;
    ctx->downcount -= 7;
    // 80111218: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8011121C:
    // 8011121C: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111220:
    ctx->pc = 0x80111220u;
    // 80111220: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111224:
    // 80111224: addi    r3, r3, 5300
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5300);

label_80111228:
    // 80111228: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8011122C:
    ctx->pc = 0x8011122Cu;
    // 8011122C: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111230:
    // 80111230: bl      0x80297FBC
    {
            ctx->lr = 0x80111234u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111234:
    ctx->downcount -= 2;
    // 80111234: cmpwi   r3, 0
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

label_80111238:
    // 80111238: bc    4, 2, 0x80111248
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111248;
        }
    }

label_8011123C:
    ctx->downcount -= 3;
    // 8011123C: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_80111240:
    ctx->pc = 0x80111240u;
    // 80111240: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111244:
    // 80111244: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111248:
    ctx->pc = 0x80111248u;
    ctx->downcount -= 7;
    // 80111248: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8011124C:
    // 8011124C: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111250:
    ctx->pc = 0x80111250u;
    // 80111250: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111254:
    // 80111254: addi    r3, r3, 5332
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5332);

label_80111258:
    // 80111258: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8011125C:
    ctx->pc = 0x8011125Cu;
    // 8011125C: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111260:
    // 80111260: bl      0x80297FBC
    {
            ctx->lr = 0x80111264u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111264:
    ctx->downcount -= 2;
    // 80111264: cmpwi   r3, 0
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

label_80111268:
    // 80111268: bc    4, 2, 0x80111278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111278;
        }
    }

label_8011126C:
    ctx->downcount -= 3;
    // 8011126C: li      r0, 17
    ctx->gpr[0] = (u32)(s32)(17);

label_80111270:
    ctx->pc = 0x80111270u;
    // 80111270: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111274:
    // 80111274: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111278:
    ctx->pc = 0x80111278u;
    ctx->downcount -= 7;
    // 80111278: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8011127C:
    // 8011127C: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111280:
    ctx->pc = 0x80111280u;
    // 80111280: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111284:
    // 80111284: addi    r3, r3, 5304
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5304);

label_80111288:
    // 80111288: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8011128C:
    ctx->pc = 0x8011128Cu;
    // 8011128C: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111290:
    // 80111290: bl      0x80297FBC
    {
            ctx->lr = 0x80111294u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111294:
    ctx->downcount -= 2;
    // 80111294: cmpwi   r3, 0
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

label_80111298:
    // 80111298: bc    4, 2, 0x801112A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801112A8;
        }
    }

label_8011129C:
    ctx->downcount -= 3;
    // 8011129C: li      r0, 18
    ctx->gpr[0] = (u32)(s32)(18);

label_801112A0:
    ctx->pc = 0x801112A0u;
    // 801112A0: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801112A4:
    // 801112A4: b       0x8011168C
    {
            goto label_8011168C;
    }

label_801112A8:
    ctx->pc = 0x801112A8u;
    ctx->downcount -= 7;
    // 801112A8: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801112AC:
    // 801112AC: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801112B0:
    ctx->pc = 0x801112B0u;
    // 801112B0: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801112B4:
    // 801112B4: addi    r3, r3, 5320
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5320);

label_801112B8:
    // 801112B8: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801112BC:
    ctx->pc = 0x801112BCu;
    // 801112BC: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801112C0:
    // 801112C0: bl      0x80297FBC
    {
            ctx->lr = 0x801112C4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801112C4:
    ctx->downcount -= 2;
    // 801112C4: cmpwi   r3, 0
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

label_801112C8:
    // 801112C8: bc    4, 2, 0x801112D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801112D4;
        }
    }

label_801112CC:
    ctx->pc = 0x801112CCu;
    ctx->downcount -= 2;
    // 801112CC: stw     r27, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_801112D0:
    // 801112D0: b       0x8011168C
    {
            goto label_8011168C;
    }

label_801112D4:
    ctx->pc = 0x801112D4u;
    ctx->downcount -= 7;
    // 801112D4: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801112D8:
    // 801112D8: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801112DC:
    ctx->pc = 0x801112DCu;
    // 801112DC: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801112E0:
    // 801112E0: addi    r3, r3, 5356
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5356);

label_801112E4:
    // 801112E4: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801112E8:
    ctx->pc = 0x801112E8u;
    // 801112E8: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801112EC:
    // 801112EC: bl      0x80297FBC
    {
            ctx->lr = 0x801112F0u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801112F0:
    ctx->downcount -= 2;
    // 801112F0: cmpwi   r3, 0
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

label_801112F4:
    // 801112F4: bc    4, 2, 0x80111304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111304;
        }
    }

label_801112F8:
    ctx->downcount -= 3;
    // 801112F8: li      r0, 12
    ctx->gpr[0] = (u32)(s32)(12);

label_801112FC:
    ctx->pc = 0x801112FCu;
    // 801112FC: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111300:
    // 80111300: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111304:
    ctx->pc = 0x80111304u;
    ctx->downcount -= 7;
    // 80111304: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111308:
    // 80111308: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_8011130C:
    ctx->pc = 0x8011130Cu;
    // 8011130C: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111310:
    // 80111310: addi    r3, r3, 5360
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5360);

label_80111314:
    // 80111314: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111318:
    ctx->pc = 0x80111318u;
    // 80111318: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8011131C:
    // 8011131C: bl      0x80297FBC
    {
            ctx->lr = 0x80111320u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111320:
    ctx->downcount -= 2;
    // 80111320: cmpwi   r3, 0
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

label_80111324:
    // 80111324: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111328:
    ctx->downcount -= 3;
    // 80111328: li      r0, 13
    ctx->gpr[0] = (u32)(s32)(13);

label_8011132C:
    ctx->pc = 0x8011132Cu;
    // 8011132C: stw     r0, 3356(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111330:
    // 80111330: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111334:
    ctx->downcount -= 4;
    // 80111334: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80111338:
    // 80111338: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8011133C:
    // 8011133C: addi    r4, r4, 5364
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5364);

label_80111340:
    // 80111340: bl      0x80297FBC
    {
            ctx->lr = 0x80111344u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111344:
    ctx->downcount -= 2;
    // 80111344: cmpwi   r3, 0
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

label_80111348:
    // 80111348: bc    4, 2, 0x80111628
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111628;
        }
    }

label_8011134C:
    ctx->pc = 0x8011134Cu;
    ctx->downcount -= 6;
    // 8011134C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111350:
    ctx->pc = 0x80111350u;
    // 80111350: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111354:
    // 80111354: addi    r11, r9, 1
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(1);

label_80111358:
    // 80111358: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8011135C:
    ctx->pc = 0x8011135Cu;
    // 8011135C: stw     r11, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111360:
    // 80111360: bc    4, 0, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111364:
    ctx->pc = 0x80111364u;
    ctx->downcount -= 6;
    // 80111364: lwz     r9, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111368:
    // 80111368: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_8011136C:
    // 8011136C: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111370:
    ctx->pc = 0x80111370u;
    // 80111370: lwzx    r4, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111374:
    // 80111374: addi    r3, r3, 5372
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5372);

label_80111378:
    // 80111378: bl      0x80297FBC
    {
            ctx->lr = 0x8011137Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_8011137C:
    ctx->downcount -= 2;
    // 8011137C: or.   r3, r3, r3
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

label_80111380:
    // 80111380: bc    4, 2, 0x80111394
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111394;
        }
    }

label_80111384:
    ctx->downcount -= 4;
    // 80111384: addi    r9, r28, -25052
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(-25052);

label_80111388:
    ctx->pc = 0x80111388u;
    // 80111388: lwz     r0, 3356(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011138C:
    ctx->pc = 0x8011138Cu;
    // 8011138C: stw     r3, 3352(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80111390:
    // 80111390: b       0x80111618
    {
            goto label_80111618;
    }

label_80111394:
    ctx->pc = 0x80111394u;
    ctx->downcount -= 7;
    // 80111394: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111398:
    // 80111398: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_8011139C:
    ctx->pc = 0x8011139Cu;
    // 8011139C: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801113A0:
    // 801113A0: addi    r3, r3, 5380
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5380);

label_801113A4:
    // 801113A4: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801113A8:
    ctx->pc = 0x801113A8u;
    // 801113A8: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801113AC:
    // 801113AC: bl      0x80297FBC
    {
            ctx->lr = 0x801113B0u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801113B0:
    ctx->downcount -= 2;
    // 801113B0: cmpwi   r3, 0
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

label_801113B4:
    // 801113B4: bc    4, 2, 0x801113D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801113D4;
        }
    }

label_801113B8:
    ctx->downcount -= 5;
    // 801113B8: addi    r9, r28, -25052
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(-25052);

label_801113BC:
    ctx->pc = 0x801113BCu;
    // 801113BC: lwz     r0, 3356(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801113C0:
    ctx->pc = 0x801113C0u;
    // 801113C0: stw     r25, 3352(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_801113C4:
    // 801113C4: cmpwi   r0, 19
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801113C8:
    // 801113C8: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_801113CC:
    ctx->pc = 0x801113CCu;
    ctx->downcount -= 2;
    // 801113CC: stw     r31, 3356(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801113D0:
    // 801113D0: b       0x8011168C
    {
            goto label_8011168C;
    }

label_801113D4:
    ctx->pc = 0x801113D4u;
    ctx->downcount -= 7;
    // 801113D4: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801113D8:
    // 801113D8: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801113DC:
    ctx->pc = 0x801113DCu;
    // 801113DC: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801113E0:
    // 801113E0: addi    r3, r3, 5384
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5384);

label_801113E4:
    // 801113E4: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801113E8:
    ctx->pc = 0x801113E8u;
    // 801113E8: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801113EC:
    // 801113EC: bl      0x80297FBC
    {
            ctx->lr = 0x801113F0u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801113F0:
    ctx->downcount -= 2;
    // 801113F0: cmpwi   r3, 0
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

label_801113F4:
    // 801113F4: bc    4, 2, 0x8011141C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011141C;
        }
    }

label_801113F8:
    ctx->downcount -= 6;
    // 801113F8: addi    r11, r28, -25052
    ctx->gpr[11] = ctx->gpr[28] + (u32)(s32)(-25052);

label_801113FC:
    // 801113FC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80111400:
    ctx->pc = 0x80111400u;
    // 80111400: lwz     r9, 3356(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3356);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111404:
    ctx->pc = 0x80111404u;
    // 80111404: stw     r0, 3352(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111408:
    // 80111408: cmpwi   r9, 19
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8011140C:
    // 8011140C: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111410:
    ctx->downcount -= 3;
    // 80111410: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_80111414:
    ctx->pc = 0x80111414u;
    // 80111414: stw     r0, 3356(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111418:
    // 80111418: b       0x8011168C
    {
            goto label_8011168C;
    }

label_8011141C:
    ctx->pc = 0x8011141Cu;
    ctx->downcount -= 7;
    // 8011141C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111420:
    // 80111420: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111424:
    ctx->pc = 0x80111424u;
    // 80111424: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111428:
    // 80111428: addi    r3, r3, 5396
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5396);

label_8011142C:
    // 8011142C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111430:
    ctx->pc = 0x80111430u;
    // 80111430: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111434:
    // 80111434: bl      0x80297FBC
    {
            ctx->lr = 0x80111438u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111438:
    ctx->downcount -= 2;
    // 80111438: cmpwi   r3, 0
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

label_8011143C:
    // 8011143C: bc    4, 2, 0x8011144C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011144C;
        }
    }

label_80111440:
    ctx->downcount -= 3;
    // 80111440: addi    r11, r28, -25052
    ctx->gpr[11] = ctx->gpr[28] + (u32)(s32)(-25052);

label_80111444:
    // 80111444: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80111448:
    // 80111448: b       0x80111518
    {
            goto label_80111518;
    }

label_8011144C:
    ctx->pc = 0x8011144Cu;
    ctx->downcount -= 7;
    // 8011144C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111450:
    // 80111450: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111454:
    ctx->pc = 0x80111454u;
    // 80111454: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111458:
    // 80111458: addi    r3, r3, 5408
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5408);

label_8011145C:
    // 8011145C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111460:
    ctx->pc = 0x80111460u;
    // 80111460: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111464:
    // 80111464: bl      0x80297FBC
    {
            ctx->lr = 0x80111468u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111468:
    ctx->downcount -= 2;
    // 80111468: cmpwi   r3, 0
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

label_8011146C:
    // 8011146C: bc    4, 2, 0x8011147C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011147C;
        }
    }

label_80111470:
    ctx->downcount -= 3;
    // 80111470: addi    r11, r28, -25052
    ctx->gpr[11] = ctx->gpr[28] + (u32)(s32)(-25052);

label_80111474:
    // 80111474: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_80111478:
    // 80111478: b       0x80111518
    {
            goto label_80111518;
    }

label_8011147C:
    ctx->pc = 0x8011147Cu;
    ctx->downcount -= 7;
    // 8011147C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111480:
    // 80111480: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111484:
    ctx->pc = 0x80111484u;
    // 80111484: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111488:
    // 80111488: addi    r3, r3, 5420
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5420);

label_8011148C:
    // 8011148C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111490:
    ctx->pc = 0x80111490u;
    // 80111490: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111494:
    // 80111494: bl      0x80297FBC
    {
            ctx->lr = 0x80111498u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111498:
    ctx->downcount -= 2;
    // 80111498: cmpwi   r3, 0
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

label_8011149C:
    // 8011149C: bc    4, 2, 0x801114AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801114AC;
        }
    }

label_801114A0:
    ctx->downcount -= 3;
    // 801114A0: addi    r11, r28, -25052
    ctx->gpr[11] = ctx->gpr[28] + (u32)(s32)(-25052);

label_801114A4:
    // 801114A4: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_801114A8:
    // 801114A8: b       0x8011155C
    {
            goto label_8011155C;
    }

label_801114AC:
    ctx->pc = 0x801114ACu;
    ctx->downcount -= 7;
    // 801114AC: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801114B0:
    // 801114B0: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801114B4:
    ctx->pc = 0x801114B4u;
    // 801114B4: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801114B8:
    // 801114B8: addi    r3, r3, 5428
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5428);

label_801114BC:
    // 801114BC: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801114C0:
    ctx->pc = 0x801114C0u;
    // 801114C0: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801114C4:
    // 801114C4: bl      0x80297FBC
    {
            ctx->lr = 0x801114C8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801114C8:
    ctx->downcount -= 2;
    // 801114C8: cmpwi   r3, 0
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

label_801114CC:
    // 801114CC: bc    4, 2, 0x801114EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801114EC;
        }
    }

label_801114D0:
    ctx->downcount -= 5;
    // 801114D0: addi    r9, r28, -25052
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(-25052);

label_801114D4:
    ctx->pc = 0x801114D4u;
    // 801114D4: lwz     r0, 3356(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801114D8:
    ctx->pc = 0x801114D8u;
    // 801114D8: stw     r31, 3352(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801114DC:
    // 801114DC: cmpwi   r0, 19
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801114E0:
    // 801114E0: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_801114E4:
    ctx->pc = 0x801114E4u;
    ctx->downcount -= 2;
    // 801114E4: stw     r27, 3356(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_801114E8:
    // 801114E8: b       0x8011168C
    {
            goto label_8011168C;
    }

label_801114EC:
    ctx->pc = 0x801114ECu;
    ctx->downcount -= 7;
    // 801114EC: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801114F0:
    // 801114F0: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801114F4:
    ctx->pc = 0x801114F4u;
    // 801114F4: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801114F8:
    // 801114F8: addi    r3, r3, 5440
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5440);

label_801114FC:
    // 801114FC: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111500:
    ctx->pc = 0x80111500u;
    // 80111500: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111504:
    // 80111504: bl      0x80297FBC
    {
            ctx->lr = 0x80111508u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111508:
    ctx->downcount -= 2;
    // 80111508: cmpwi   r3, 0
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

label_8011150C:
    // 8011150C: bc    4, 2, 0x80111530
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111530;
        }
    }

label_80111510:
    ctx->downcount -= 2;
    // 80111510: addi    r11, r28, -25052
    ctx->gpr[11] = ctx->gpr[28] + (u32)(s32)(-25052);

label_80111514:
    // 80111514: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_80111518:
    ctx->pc = 0x80111518u;
    ctx->downcount -= 4;
    // 80111518: lwz     r9, 3356(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3356);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8011151C:
    ctx->pc = 0x8011151Cu;
    // 8011151C: stw     r0, 3352(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111520:
    // 80111520: cmpwi   r9, 19
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80111524:
    // 80111524: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111528:
    ctx->pc = 0x80111528u;
    ctx->downcount -= 2;
    // 80111528: stw     r27, 3356(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8011152C:
    // 8011152C: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111530:
    ctx->pc = 0x80111530u;
    ctx->downcount -= 7;
    // 80111530: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111534:
    // 80111534: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80111538:
    ctx->pc = 0x80111538u;
    // 80111538: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8011153C:
    // 8011153C: addi    r3, r3, 5452
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5452);

label_80111540:
    // 80111540: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111544:
    ctx->pc = 0x80111544u;
    // 80111544: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111548:
    // 80111548: bl      0x80297FBC
    {
            ctx->lr = 0x8011154Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_8011154C:
    ctx->downcount -= 2;
    // 8011154C: cmpwi   r3, 0
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

label_80111550:
    // 80111550: bc    4, 2, 0x80111574
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111574;
        }
    }

label_80111554:
    ctx->downcount -= 2;
    // 80111554: addi    r11, r28, -25052
    ctx->gpr[11] = ctx->gpr[28] + (u32)(s32)(-25052);

label_80111558:
    // 80111558: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_8011155C:
    ctx->pc = 0x8011155Cu;
    ctx->downcount -= 4;
    // 8011155C: lwz     r9, 3356(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3356);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111560:
    ctx->pc = 0x80111560u;
    // 80111560: stw     r0, 3352(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111564:
    // 80111564: cmpwi   r9, 19
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80111568:
    // 80111568: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_8011156C:
    ctx->pc = 0x8011156Cu;
    ctx->downcount -= 2;
    // 8011156C: stw     r31, 3356(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80111570:
    // 80111570: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111574:
    ctx->pc = 0x80111574u;
    ctx->downcount -= 7;
    // 80111574: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111578:
    // 80111578: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_8011157C:
    ctx->pc = 0x8011157Cu;
    // 8011157C: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111580:
    // 80111580: addi    r3, r3, 5472
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5472);

label_80111584:
    // 80111584: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80111588:
    ctx->pc = 0x80111588u;
    // 80111588: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8011158C:
    // 8011158C: bl      0x80297FBC
    {
            ctx->lr = 0x80111590u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111590:
    ctx->downcount -= 2;
    // 80111590: or.   r3, r3, r3
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

label_80111594:
    // 80111594: bc    4, 2, 0x801115A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801115A4;
        }
    }

label_80111598:
    ctx->downcount -= 3;
    // 80111598: addi    r11, r28, -25052
    ctx->gpr[11] = ctx->gpr[28] + (u32)(s32)(-25052);

label_8011159C:
    // 8011159C: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_801115A0:
    // 801115A0: b       0x801115D0
    {
            goto label_801115D0;
    }

label_801115A4:
    ctx->pc = 0x801115A4u;
    ctx->downcount -= 7;
    // 801115A4: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801115A8:
    // 801115A8: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801115AC:
    ctx->pc = 0x801115ACu;
    // 801115AC: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801115B0:
    // 801115B0: addi    r3, r3, 5480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5480);

label_801115B4:
    // 801115B4: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801115B8:
    ctx->pc = 0x801115B8u;
    // 801115B8: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801115BC:
    // 801115BC: bl      0x80297FBC
    {
            ctx->lr = 0x801115C0u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801115C0:
    ctx->downcount -= 2;
    // 801115C0: or.   r3, r3, r3
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

label_801115C4:
    // 801115C4: bc    4, 2, 0x801115E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801115E8;
        }
    }

label_801115C8:
    ctx->downcount -= 2;
    // 801115C8: addi    r11, r28, -25052
    ctx->gpr[11] = ctx->gpr[28] + (u32)(s32)(-25052);

label_801115CC:
    // 801115CC: li      r0, 10
    ctx->gpr[0] = (u32)(s32)(10);

label_801115D0:
    ctx->pc = 0x801115D0u;
    ctx->downcount -= 4;
    // 801115D0: lwz     r9, 3356(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3356);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801115D4:
    ctx->pc = 0x801115D4u;
    // 801115D4: stw     r0, 3352(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801115D8:
    // 801115D8: cmpwi   r9, 19
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801115DC:
    // 801115DC: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_801115E0:
    ctx->pc = 0x801115E0u;
    ctx->downcount -= 2;
    // 801115E0: stw     r3, 3356(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801115E4:
    // 801115E4: b       0x8011168C
    {
            goto label_8011168C;
    }

label_801115E8:
    ctx->pc = 0x801115E8u;
    ctx->downcount -= 7;
    // 801115E8: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801115EC:
    // 801115EC: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801115F0:
    ctx->pc = 0x801115F0u;
    // 801115F0: lwz     r11, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801115F4:
    // 801115F4: addi    r3, r3, 5492
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5492);

label_801115F8:
    // 801115F8: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_801115FC:
    ctx->pc = 0x801115FCu;
    // 801115FC: lwzx    r4, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111600:
    // 80111600: bl      0x80297FBC
    {
            ctx->lr = 0x80111604u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80111604:
    ctx->downcount -= 2;
    // 80111604: or.   r3, r3, r3
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

label_80111608:
    // 80111608: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_8011160C:
    ctx->downcount -= 3;
    // 8011160C: addi    r9, r28, -25052
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(-25052);

label_80111610:
    ctx->pc = 0x80111610u;
    // 80111610: lwz     r0, 3356(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3356);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111614:
    ctx->pc = 0x80111614u;
    // 80111614: stw     r27, 3352(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3352);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80111618:
    ctx->downcount -= 2;
    // 80111618: cmpwi   r0, 19
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8011161C:
    // 8011161C: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111620:
    ctx->pc = 0x80111620u;
    ctx->downcount -= 2;
    // 80111620: stw     r3, 3356(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(3356);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80111624:
    // 80111624: b       0x8011168C
    {
            goto label_8011168C;
    }

label_80111628:
    ctx->pc = 0x80111628u;
    ctx->downcount -= 5;
    // 80111628: lwz     r4, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8011162C:
    // 8011162C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80111630:
    ctx->pc = 0x80111630u;
    // 80111630: lwz     r5, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80111634:
    // 80111634: addi    r6, r1, 176
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(176);

label_80111638:
    // 80111638: bl      0x8023A460
    {
            ctx->lr = 0x8011163Cu;
            ctx->pc = 0x8023A460u;
            return;
    }

label_8011163C:
    ctx->downcount -= 2;
    // 8011163C: cmpwi   r3, 0
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

label_80111640:
    // 80111640: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111644:
    ctx->pc = 0x80111644u;
    ctx->downcount -= 3;
    // 80111644: lbz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80111648:
    // 80111648: cmpwi   r0, 45
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(45);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8011164C:
    // 8011164C: bc    4, 2, 0x8011165C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011165C;
        }
    }

label_80111650:
    ctx->downcount -= 1;
    // 80111650: bl      0x8023A45C
    {
            ctx->lr = 0x80111654u;
            ctx->pc = 0x8023A45Cu;
            return;
    }

label_80111654:
    ctx->downcount -= 2;
    // 80111654: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80111658:
    // 80111658: bl      0x802969D0
    {
            ctx->lr = 0x8011165Cu;
            ctx->pc = 0x802969D0u;
            return;
    }

label_8011165C:
    ctx->downcount -= 2;
    // 8011165C: cmpwi   r23, 0
    {
        s32 val_a = (s32)(ctx->gpr[23]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80111660:
    // 80111660: bc    4, 2, 0x8011168C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011168C;
        }
    }

label_80111664:
    ctx->downcount -= 4;
    // 80111664: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_80111668:
    // 80111668: cmpwi   r30, 0
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

label_8011166C:
    // 8011166C: addi    r3, r9, -21808
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(-21808);

label_80111670:
    // 80111670: bc    12, 2, 0x80111684
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111684;
        }
    }

label_80111674:
    ctx->downcount -= 3;
    // 80111674: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80111678:
    // 80111678: li      r5, 80
    ctx->gpr[5] = (u32)(s32)(80);

label_8011167C:
    // 8011167C: bl      0x80287F10
    {
            ctx->lr = 0x80111680u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_80111680:
    ctx->downcount -= 1;
    // 80111680: b       0x80111688
    {
            goto label_80111688;
    }

label_80111684:
    ctx->pc = 0x80111684u;
    ctx->downcount -= 1;
    // 80111684: stb     r23, -21808(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21808);
        mem_write8(ctx, ea, (u8)ctx->gpr[23]);
    }

label_80111688:
    ctx->downcount -= 1;
    // 80111688: li      r23, 1
    ctx->gpr[23] = (u32)(s32)(1);

label_8011168C:
    ctx->pc = 0x8011168Cu;
    ctx->downcount -= 7;
    // 8011168C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111690:
    ctx->pc = 0x80111690u;
    // 80111690: lwz     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111694:
    // 80111694: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80111698:
    // 80111698: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8011169C:
    ctx->pc = 0x8011169Cu;
    // 8011169C: stw     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801116A0:
    // 801116A0: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801116A4:
    // 801116A4: bc    12, 0, 0x801109F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801109F4u;
                return;
            }
            goto label_801109F4;
        }
    }

label_801116A8:
    ctx->pc = 0x801116A8u;
    ctx->downcount -= 2;
    // 801116A8: cmpwi   r21, 0
    {
        s32 val_a = (s32)(ctx->gpr[21]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801116AC:
    ctx->pc = 0x801116ACu;
    // 801116AC: bc    12, 2, 0x801116D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801116D4;
        }
    }

label_801116B0:
    ctx->pc = 0x801116B0u;
    ctx->downcount -= 2;
    // 801116B0: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801116B4:
    ctx->pc = 0x801116B4u;
    // 801116B4: b       0x801116BC
    {
            goto label_801116BC;
    }

label_801116B8:
    ctx->downcount -= 1;
    // 801116B8: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_801116BC:
    ctx->downcount -= 2;
    // 801116BC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801116C0:
    // 801116C0: bl      0x8025421C
    {
            ctx->lr = 0x801116C4u;
            ctx->pc = 0x8025421Cu;
            return;
    }

label_801116C4:
    ctx->downcount -= 2;
    // 801116C4: cmpwi   r3, 0
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

label_801116C8:
    // 801116C8: bc    4, 2, 0x801116B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801116B8u;
                return;
            }
            goto label_801116B8;
        }
    }

label_801116CC:
    ctx->pc = 0x801116CCu;
    ctx->downcount -= 2;
    // 801116CC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801116D0:
    ctx->pc = 0x801116D0u;
    // 801116D0: bl      0x802969D0
    {
            ctx->lr = 0x801116D4u;
            ctx->pc = 0x802969D0u;
            return;
    }

label_801116D4:
    ctx->pc = 0x801116D4u;
    ctx->downcount -= 1;
    // 801116D4: bl      0x802C927C
    {
            ctx->lr = 0x801116D8u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_801116D8:
    ctx->pc = 0x801116D8u;
    ctx->downcount -= 4;
    // 801116D8: lis     r30, -32721
    ctx->gpr[30] = ((u32)(s32)(-32721) << 16);

label_801116DC:
    ctx->pc = 0x801116DCu;
    // 801116DC: lis     r3, 5
    ctx->gpr[3] = ((u32)(s32)(5) << 16);

label_801116E0:
    ctx->pc = 0x801116E0u;
    // 801116E0: ori     r3, r3, 0x7800
    ctx->gpr[3] = ctx->gpr[3] | 0x7800u;

label_801116E4:
    ctx->pc = 0x801116E4u;
    // 801116E4: bl      0x80248EA8
    {
            ctx->lr = 0x801116E8u;
            ctx->pc = 0x80248EA8u;
            return;
    }

label_801116E8:
    ctx->pc = 0x801116E8u;
    ctx->downcount -= 3;
    // 801116E8: lis     r3, 7
    ctx->gpr[3] = ((u32)(s32)(7) << 16);

label_801116EC:
    ctx->pc = 0x801116ECu;
    // 801116EC: ori     r3, r3, 0xD000
    ctx->gpr[3] = ctx->gpr[3] | 0xD000u;

label_801116F0:
    ctx->pc = 0x801116F0u;
    // 801116F0: bl      0x80248EA0
    {
            ctx->lr = 0x801116F4u;
            ctx->pc = 0x80248EA0u;
            return;
    }

label_801116F4:
    ctx->pc = 0x801116F4u;
    ctx->downcount -= 4;
    // 801116F4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801116F8:
    ctx->pc = 0x801116F8u;
    // 801116F8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801116FC:
    ctx->pc = 0x801116FCu;
    // 801116FC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80111700:
    ctx->pc = 0x80111700u;
    // 80111700: bl      0x80248C08
    {
            ctx->lr = 0x80111704u;
            ctx->pc = 0x80248C08u;
            return;
    }

label_80111704:
    ctx->pc = 0x80111704u;
    ctx->downcount -= 3;
    // 80111704: lfs     f1, 5520(r30)
    if (!ppc_fp_available_inline(ctx, 0x80111704u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(5520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80111708:
    ctx->pc = 0x80111708u;
    // 80111708: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8011170C:
    ctx->pc = 0x8011170Cu;
    // 8011170C: bl      0x80242B0C
    {
            ctx->lr = 0x80111710u;
            ctx->pc = 0x80242B0Cu;
            return;
    }

label_80111710:
    ctx->pc = 0x80111710u;
    ctx->downcount -= 1;
    // 80111710: bl      0x80248E2C
    {
            ctx->lr = 0x80111714u;
            ctx->pc = 0x80248E2Cu;
            return;
    }

label_80111714:
    ctx->pc = 0x80111714u;
    ctx->downcount -= 42;
    // 80111714: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80111718:
    ctx->pc = 0x80111718u;
    // 80111718: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8011171C:
    ctx->pc = 0x8011171Cu;
    // 8011171C: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111720:
    ctx->pc = 0x80111720u;
    // 80111720: addi    r3, r1, 88
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(88);

label_80111724:
    ctx->pc = 0x80111724u;
    // 80111724: stw     r11, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111728:
    ctx->pc = 0x80111728u;
    // 80111728: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011172C:
    ctx->pc = 0x8011172Cu;
    // 8011172C: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111730:
    ctx->pc = 0x80111730u;
    // 80111730: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111734:
    ctx->pc = 0x80111734u;
    // 80111734: stw     r11, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111738:
    ctx->pc = 0x80111738u;
    // 80111738: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011173C:
    ctx->pc = 0x8011173Cu;
    // 8011173C: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111740:
    ctx->pc = 0x80111740u;
    // 80111740: lwz     r11, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111744:
    ctx->pc = 0x80111744u;
    // 80111744: stw     r11, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111748:
    ctx->pc = 0x80111748u;
    // 80111748: lwz     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011174C:
    ctx->pc = 0x8011174Cu;
    // 8011174C: stw     r0, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111750:
    ctx->pc = 0x80111750u;
    // 80111750: lwz     r11, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111754:
    ctx->pc = 0x80111754u;
    // 80111754: stw     r11, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111758:
    ctx->pc = 0x80111758u;
    // 80111758: lfs     f0, 28(r9)
    if (!ppc_fp_available_inline(ctx, 0x80111758u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8011175C:
    ctx->pc = 0x8011175Cu;
    // 8011175C: stfs     f0, 116(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011175Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111760:
    ctx->pc = 0x80111760u;
    // 80111760: lfs     f13, 32(r9)
    if (!ppc_fp_available_inline(ctx, 0x80111760u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80111764:
    ctx->pc = 0x80111764u;
    // 80111764: stfs     f13, 120(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111764u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80111768:
    ctx->pc = 0x80111768u;
    // 80111768: lwz     r0, 36(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011176C:
    ctx->pc = 0x8011176Cu;
    // 8011176C: stw     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111770:
    ctx->pc = 0x80111770u;
    // 80111770: lwz     r11, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111774:
    ctx->pc = 0x80111774u;
    // 80111774: stw     r11, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111778:
    ctx->pc = 0x80111778u;
    // 80111778: lwz     r0, 48(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011177C:
    ctx->pc = 0x8011177Cu;
    // 8011177C: stw     r0, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111780:
    ctx->pc = 0x80111780u;
    // 80111780: lwz     r11, 52(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111784:
    ctx->pc = 0x80111784u;
    // 80111784: stw     r11, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111788:
    ctx->pc = 0x80111788u;
    // 80111788: lwz     r0, 56(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(56);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011178C:
    ctx->pc = 0x8011178Cu;
    // 8011178C: stw     r0, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111790:
    ctx->pc = 0x80111790u;
    // 80111790: lwz     r11, 60(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(60);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111794:
    ctx->pc = 0x80111794u;
    // 80111794: stw     r11, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111798:
    ctx->pc = 0x80111798u;
    // 80111798: lwz     r0, 64(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(64);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011179C:
    ctx->pc = 0x8011179Cu;
    // 8011179C: stw     r0, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801117A0:
    ctx->pc = 0x801117A0u;
    // 801117A0: lwz     r11, 68(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(68);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801117A4:
    ctx->pc = 0x801117A4u;
    // 801117A4: stw     r11, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801117A8:
    ctx->pc = 0x801117A8u;
    // 801117A8: lwz     r0, 72(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801117AC:
    ctx->pc = 0x801117ACu;
    // 801117AC: stw     r0, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801117B0:
    ctx->pc = 0x801117B0u;
    // 801117B0: lwz     r11, 76(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(76);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801117B4:
    ctx->pc = 0x801117B4u;
    // 801117B4: stw     r11, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801117B8:
    ctx->pc = 0x801117B8u;
    // 801117B8: bl      0x8023A20C
    {
            ctx->lr = 0x801117BCu;
            ctx->pc = 0x8023A20Cu;
            return;
    }

label_801117BC:
    ctx->pc = 0x801117BCu;
    ctx->downcount -= 2;
    // 801117BC: cmpwi   r3, 0
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

label_801117C0:
    ctx->pc = 0x801117C0u;
    // 801117C0: bc    12, 2, 0x801117D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801117D0;
        }
    }

label_801117C4:
    ctx->pc = 0x801117C4u;
    ctx->downcount -= 3;
    // 801117C4: addi    r3, r1, 88
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(88);

label_801117C8:
    ctx->pc = 0x801117C8u;
    // 801117C8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801117CC:
    ctx->pc = 0x801117CCu;
    // 801117CC: bl      0x8023A258
    {
            ctx->lr = 0x801117D0u;
            ctx->pc = 0x8023A258u;
            return;
    }

label_801117D0:
    ctx->pc = 0x801117D0u;
    ctx->downcount -= 2;
    // 801117D0: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_801117D4:
    ctx->pc = 0x801117D4u;
    // 801117D4: bl      0x80248DBC
    {
            ctx->lr = 0x801117D8u;
            ctx->pc = 0x80248DBCu;
            return;
    }

label_801117D8:
    ctx->pc = 0x801117D8u;
    ctx->downcount -= 2;
    // 801117D8: cmpwi   r26, 0
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

label_801117DC:
    ctx->pc = 0x801117DCu;
    // 801117DC: bc    4, 2, 0x801117EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801117EC;
        }
    }

label_801117E0:
    ctx->pc = 0x801117E0u;
    ctx->downcount -= 3;
    // 801117E0: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_801117E4:
    ctx->pc = 0x801117E4u;
    // 801117E4: lwz     r3, -25032(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-25032);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801117E8:
    ctx->pc = 0x801117E8u;
    // 801117E8: bl      0x80226E74
    {
            ctx->lr = 0x801117ECu;
            ctx->pc = 0x80226E74u;
            return;
    }

label_801117EC:
    ctx->pc = 0x801117ECu;
    ctx->downcount -= 1;
    // 801117EC: bl      0x8028C3DC
    {
            ctx->lr = 0x801117F0u;
            ctx->pc = 0x8028C3DCu;
            return;
    }

label_801117F0:
    ctx->pc = 0x801117F0u;
    ctx->downcount -= 2;
    // 801117F0: cmpwi   cr4, r24, 0
    {
        s32 val_a = (s32)(ctx->gpr[24]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801117F4:
    ctx->pc = 0x801117F4u;
    // 801117F4: bl      0x801DBFB8
    {
            ctx->lr = 0x801117F8u;
            ctx->pc = 0x801DBFB8u;
            return;
    }

label_801117F8:
    ctx->pc = 0x801117F8u;
    ctx->downcount -= 2;
    // 801117F8: lis     r27, -32714
    ctx->gpr[27] = ((u32)(s32)(-32714) << 16);

label_801117FC:
    ctx->pc = 0x801117FCu;
    // 801117FC: bl      0x800E4C10
    {
            ctx->lr = 0x80111800u;
            ctx->pc = 0x800E4C10u;
            return;
    }

label_80111800:
    ctx->pc = 0x80111800u;
    ctx->downcount -= 3;
    // 80111800: lis     r26, 17200
    ctx->gpr[26] = ((u32)(s32)(17200) << 16);

label_80111804:
    ctx->pc = 0x80111804u;
    // 80111804: li      r3, 152
    ctx->gpr[3] = (u32)(s32)(152);

label_80111808:
    ctx->pc = 0x80111808u;
    // 80111808: bl      0x80281C60
    {
            ctx->lr = 0x8011180Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8011180C:
    ctx->pc = 0x8011180Cu;
    ctx->downcount -= 1;
    // 8011180C: bl      0x801AB6D0
    {
            ctx->lr = 0x80111810u;
            ctx->pc = 0x801AB6D0u;
            return;
    }

label_80111810:
    ctx->pc = 0x80111810u;
    ctx->downcount -= 6;
    // 80111810: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80111814:
    ctx->pc = 0x80111814u;
    // 80111814: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80111818:
    ctx->pc = 0x80111818u;
    // 80111818: lfs     f30, 5520(r30)
    if (!ppc_fp_available_inline(ctx, 0x80111818u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(5520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_8011181C:
    ctx->pc = 0x8011181Cu;
    // 8011181C: lfs     f28, 5532(r9)
    if (!ppc_fp_available_inline(ctx, 0x8011181Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5532);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[28] = value;
        ctx->ps1[28] = value;
    }

label_80111820:
    ctx->pc = 0x80111820u;
    // 80111820: lfd     f29, 5536(r11)
    if (!ppc_fp_available_inline(ctx, 0x80111820u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5536);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80111824:
    ctx->pc = 0x80111824u;
    // 80111824: stw     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80111828:
    ctx->downcount -= 1;
    // 80111828: bl      0x801106F4
    {
            ctx->lr = 0x8011182Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801106F4u;
                return;
            }
            goto label_801106F4;
    }

label_8011182C:
    ctx->downcount -= 2;
    // 8011182C: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80111830:
    // 80111830: bl      0x802490B4
    {
            ctx->lr = 0x80111834u;
            ctx->pc = 0x802490B4u;
            return;
    }

label_80111834:
    ctx->downcount -= 3;
    // 80111834: or   r31, r28, r28
    {
        ctx->gpr[31] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80111838:
    ctx->pc = 0x80111838u;
    // 80111838: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x80111838u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_8011183C:
    // 8011183C: bl      0x802490A8
    {
            ctx->lr = 0x80111840u;
            ctx->pc = 0x802490A8u;
            return;
    }

label_80111840:
    ctx->pc = 0x80111840u;
    ctx->downcount -= 3;
    // 80111840: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x80111840u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80111844:
    ctx->pc = 0x80111844u;
    // 80111844: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80111844u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80111848:
    // 80111848: bl      0x80219678
    {
            ctx->lr = 0x8011184Cu;
            ctx->pc = 0x80219678u;
            return;
    }

label_8011184C:
    ctx->downcount -= 1;
    // 8011184C: bl      0x80289138
    {
            ctx->lr = 0x80111850u;
            ctx->pc = 0x80289138u;
            return;
    }

label_80111850:
    ctx->pc = 0x80111850u;
    ctx->downcount -= 5;
    // 80111850: lfs     f13, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x80111850u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80111854:
    ctx->pc = 0x80111854u;
    // 80111854: lfs     f0, -30168(r13)
    if (!ppc_fp_available_inline(ctx, 0x80111854u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111858:
    ctx->pc = 0x80111858u;
    // 80111858: stfs     f13, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x80111858u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8011185C:
    ctx->pc = 0x8011185Cu;
    // 8011185C: stfs     f0, 24(r3)
    if (!ppc_fp_available_inline(ctx, 0x8011185Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111860:
    // 80111860: bl      0x80289138
    {
            ctx->lr = 0x80111864u;
            ctx->pc = 0x80289138u;
            return;
    }

label_80111864:
    ctx->pc = 0x80111864u;
    ctx->downcount -= 4;
    // 80111864: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80111868:
    ctx->pc = 0x80111868u;
    // 80111868: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x80111868u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8011186C:
    // 8011186C: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_80111870:
    // 80111870: bl      0x80287610
    {
            ctx->lr = 0x80111874u;
            ctx->pc = 0x80287610u;
            return;
    }

label_80111874:
    ctx->downcount -= 1;
    // 80111874: bl      0x802C927C
    {
            ctx->lr = 0x80111878u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_80111878:
    ctx->pc = 0x80111878u;
    ctx->downcount -= 4;
    // 80111878: lwz     r9, -27288(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27288);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8011187C:
    ctx->pc = 0x8011187Cu;
    // 8011187C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111880:
    // 80111880: cmpwi   r0, 0
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

label_80111884:
    // 80111884: bc    12, 2, 0x8011188C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011188C;
        }
    }

label_80111888:
    ctx->downcount -= 1;
    // 80111888: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_8011188C:
    ctx->downcount -= 1;
    // 8011188C: bl      0x802C927C
    {
            ctx->lr = 0x80111890u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_80111890:
    ctx->pc = 0x80111890u;
    ctx->downcount -= 4;
    // 80111890: lwz     r0, -27300(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111894:
    ctx->pc = 0x80111894u;
    // 80111894: lfs     f31, 5528(r19)
    if (!ppc_fp_available_inline(ctx, 0x80111894u)) return;
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(5528);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80111898:
    // 80111898: cmpwi   r0, 0
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

label_8011189C:
    // 8011189C: bc    4, 2, 0x801118CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801118CC;
        }
    }

label_801118A0:
    ctx->pc = 0x801118A0u;
    ctx->downcount -= 11;
    // 801118A0: stfs     f31, -21280(r27)
    if (!ppc_fp_available_inline(ctx, 0x801118A0u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-21280);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801118A4:
    // 801118A4: addi    r9, r27, -21280
    ctx->gpr[9] = ctx->gpr[27] + (u32)(s32)(-21280);

label_801118A8:
    ctx->pc = 0x801118A8u;
    // 801118A8: stfs     f31, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x801118A8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801118AC:
    // 801118AC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801118B0:
    ctx->pc = 0x801118B0u;
    // 801118B0: stfs     f28, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x801118B0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_801118B4:
    ctx->pc = 0x801118B4u;
    // 801118B4: stfs     f30, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x801118B4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_801118B8:
    ctx->pc = 0x801118B8u;
    // 801118B8: stfsu     f31, 16(r9)
    if (!ppc_fp_available_inline(ctx, 0x801118B8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
        ctx->gpr[9] = ea;
    }

label_801118BC:
    ctx->pc = 0x801118BCu;
    // 801118BC: stw     r0, -27300(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27300);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801118C0:
    ctx->pc = 0x801118C0u;
    // 801118C0: stfs     f30, 12(r9)
    if (!ppc_fp_available_inline(ctx, 0x801118C0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_801118C4:
    ctx->pc = 0x801118C4u;
    // 801118C4: stfs     f31, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x801118C4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801118C8:
    ctx->pc = 0x801118C8u;
    // 801118C8: stfs     f30, 8(r9)
    if (!ppc_fp_available_inline(ctx, 0x801118C8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_801118CC:
    ctx->downcount -= 3;
    // 801118CC: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801118D0:
    // 801118D0: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801118D4:
    // 801118D4: b       0x801118DC
    {
            goto label_801118DC;
    }

label_801118D8:
    ctx->downcount -= 1;
    // 801118D8: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_801118DC:
    ctx->downcount -= 2;
    // 801118DC: cmpw    r30, r31
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

label_801118E0:
    // 801118E0: bc    4, 0, 0x80111904
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111904;
        }
    }

label_801118E4:
    ctx->pc = 0x801118E4u;
    ctx->downcount -= 5;
    // 801118E4: lfs     f0, -30164(r13)
    if (!ppc_fp_available_inline(ctx, 0x801118E4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801118E8:
    ctx->pc = 0x801118E8u;
    // 801118E8: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801118EC:
    ctx->pc = 0x801118ECu;
    // 801118EC: fmr    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x801118ECu)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_801118F0:
    ctx->pc = 0x801118F0u;
    // 801118F0: fadds   f31, f31, f0
    if (!ppc_fp_available_inline(ctx, 0x801118F0u)) return;
    ppc_fadds(ctx, 31, 31, 0);

label_801118F4:
    // 801118F4: bl      0x801AC614
    {
            ctx->lr = 0x801118F8u;
            ctx->pc = 0x801AC614u;
            return;
    }

label_801118F8:
    ctx->downcount -= 2;
    // 801118F8: cmpwi   r3, 0
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

label_801118FC:
    // 801118FC: bc    12, 2, 0x801118D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801118D8u;
                return;
            }
            goto label_801118D8;
        }
    }

label_80111900:
    ctx->downcount -= 1;
    // 80111900: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_80111904:
    ctx->downcount -= 2;
    // 80111904: cmpwi   r29, 0
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

label_80111908:
    // 80111908: bc    4, 2, 0x8011195C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8011195C;
        }
    }

label_8011190C:
    ctx->pc = 0x8011190Cu;
    ctx->downcount -= 4;
    // 8011190C: lwz     r9, -27296(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27296);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111910:
    ctx->pc = 0x80111910u;
    // 80111910: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111914:
    // 80111914: cmpwi   r0, 0
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

label_80111918:
    // 80111918: bc    12, 2, 0x80111920
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111920;
        }
    }

label_8011191C:
    ctx->downcount -= 1;
    // 8011191C: bl      0x801119B0
    {
            ctx->lr = 0x80111920u;
            goto label_801119B0;
    }

label_80111920:
    ctx->downcount -= 1;
    // 80111920: bl      0x8021968C
    {
            ctx->lr = 0x80111924u;
            ctx->pc = 0x8021968Cu;
            return;
    }

label_80111924:
    ctx->downcount -= 1;
    // 80111924: bl      0x802C927C
    {
            ctx->lr = 0x80111928u;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_80111928:
    ctx->pc = 0x80111928u;
    ctx->downcount -= 3;
    // 80111928: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8011192C:
    ctx->pc = 0x8011192Cu;
    // 8011192C: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8011192Cu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80111930:
    // 80111930: bl      0x801ACB04
    {
            ctx->lr = 0x80111934u;
            ctx->pc = 0x801ACB04u;
            return;
    }

label_80111934:
    ctx->downcount -= 1;
    // 80111934: bl      0x802490A8
    {
            ctx->lr = 0x80111938u;
            ctx->pc = 0x802490A8u;
            return;
    }

label_80111938:
    ctx->downcount -= 25;
    // 80111938: xoris   r0, r28, 0x8000
    ctx->gpr[0] = ctx->gpr[28] ^ (0x8000u << 16);

label_8011193C:
    ctx->pc = 0x8011193Cu;
    // 8011193C: stw     r0, 220(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111940:
    ctx->pc = 0x80111940u;
    // 80111940: stw     r26, 216(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80111944:
    ctx->pc = 0x80111944u;
    // 80111944: lfd     f0, 216(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111944u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80111948:
    ctx->pc = 0x80111948u;
    // 80111948: fsub   f0, f0, f29
    if (!ppc_fp_available_inline(ctx, 0x80111948u)) return;
    ppc_fsub(ctx, 0, 0, 29);

label_8011194C:
    ctx->pc = 0x8011194Cu;
    // 8011194C: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8011194Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_80111950:
    ctx->pc = 0x80111950u;
    // 80111950: fdivs   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x80111950u)) return;
    ppc_fdivs(ctx, 1, 1, 0);

label_80111954:
    ctx->pc = 0x80111954u;
    // 80111954: stfs     f1, -31956(r13)
    if (!ppc_fp_available_inline(ctx, 0x80111954u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31956);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80111958:
    // 80111958: b       0x80111828
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111828u;
                return;
            }
            goto label_80111828;
    }

label_8011195C:
    ctx->pc = 0x8011195Cu;
    ctx->downcount -= 3;
    // 8011195C: lwz     r3, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80111960:
    ctx->pc = 0x80111960u;
    // 80111960: cmpwi   r3, 0
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

label_80111964:
    ctx->pc = 0x80111964u;
    // 80111964: bc    12, 2, 0x80111970
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111970;
        }
    }

label_80111968:
    ctx->pc = 0x80111968u;
    ctx->downcount -= 2;
    // 80111968: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8011196C:
    ctx->pc = 0x8011196Cu;
    // 8011196C: bl      0x801ABEE4
    {
            ctx->lr = 0x80111970u;
            ctx->pc = 0x801ABEE4u;
            return;
    }

label_80111970:
    ctx->pc = 0x80111970u;
    ctx->downcount -= 1;
    // 80111970: bc    12, 18, 0x8011197C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011197C;
        }
    }

label_80111974:
    ctx->pc = 0x80111974u;
    ctx->downcount -= 2;
    // 80111974: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80111978:
    ctx->pc = 0x80111978u;
    // 80111978: bl      0x80281DD0
    {
            ctx->lr = 0x8011197Cu;
            ctx->pc = 0x80281DD0u;
            return;
    }

label_8011197C:
    ctx->pc = 0x8011197Cu;
    ctx->downcount -= 1;
    // 8011197C: bl      0x80248EB0
    {
            ctx->lr = 0x80111980u;
            ctx->pc = 0x80248EB0u;
            return;
    }

label_80111980:
    ctx->pc = 0x80111980u;
    ctx->downcount -= 23;
    // 80111980: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80111984:
    ctx->pc = 0x80111984u;
    // 80111984: lwz     r0, 316(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(316);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111988:
    ctx->pc = 0x80111988u;
    // 80111988: lwz     r12, 224(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8011198C:
    ctx->pc = 0x8011198Cu;
    // 8011198C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80111990:
    ctx->pc = 0x80111990u;
    // 80111990: lmw     r19, 228(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(228);
        for (u32 r = 19; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80111994:
    ctx->pc = 0x80111994u;
    // 80111994: lfd     f28, 280(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111994u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80111998:
    ctx->pc = 0x80111998u;
    // 80111998: lfd     f29, 288(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111998u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8011199C:
    ctx->pc = 0x8011199Cu;
    // 8011199C: lfd     f30, 296(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011199Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801119A0:
    ctx->pc = 0x801119A0u;
    // 801119A0: lfd     f31, 304(r1)
    if (!ppc_fp_available_inline(ctx, 0x801119A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(304);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801119A4:
    ctx->pc = 0x801119A4u;
    // 801119A4: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801119A8:
    ctx->pc = 0x801119A8u;
    // 801119A8: addi    r1, r1, 312
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(312);

label_801119AC:
    ctx->pc = 0x801119ACu;
    // 801119AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_801119B0:
    ctx->pc = 0x801119B0u;
    ctx->downcount -= 19;
    // 801119B0: stwu     r1, -392(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-392);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801119B4:
    ctx->pc = 0x801119B4u;
    // 801119B4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801119B8:
    ctx->pc = 0x801119B8u;
    // 801119B8: stfd     f30, 376(r1)
    if (!ppc_fp_available_inline(ctx, 0x801119B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(376);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_801119BC:
    ctx->pc = 0x801119BCu;
    // 801119BC: stfd     f31, 384(r1)
    if (!ppc_fp_available_inline(ctx, 0x801119BCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_801119C0:
    ctx->pc = 0x801119C0u;
    // 801119C0: stmw     r25, 348(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(348);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801119C4:
    ctx->pc = 0x801119C4u;
    // 801119C4: stw     r0, 396(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(396);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801119C8:
    ctx->pc = 0x801119C8u;
    // 801119C8: lwz     r9, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801119CC:
    ctx->pc = 0x801119CCu;
    // 801119CC: lwz     r3, 180(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(180);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801119D0:
    ctx->pc = 0x801119D0u;
    // 801119D0: bl      0x801CB1D8
    {
            ctx->lr = 0x801119D4u;
            ctx->pc = 0x801CB1D8u;
            return;
    }

label_801119D4:
    ctx->pc = 0x801119D4u;
    ctx->downcount -= 2;
    // 801119D4: or.   r31, r3, r3
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

label_801119D8:
    ctx->pc = 0x801119D8u;
    // 801119D8: bc    12, 2, 0x80111D84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111D84;
        }
    }

label_801119DC:
    ctx->pc = 0x801119DCu;
    ctx->downcount -= 20;
    // 801119DC: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801119E0:
    ctx->pc = 0x801119E0u;
    // 801119E0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801119E4:
    ctx->pc = 0x801119E4u;
    // 801119E4: lfs     f13, 5552(r11)
    if (!ppc_fp_available_inline(ctx, 0x801119E4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5552);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801119E8:
    ctx->pc = 0x801119E8u;
    // 801119E8: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801119EC:
    ctx->pc = 0x801119ECu;
    // 801119EC: lfs     f0, 5548(r9)
    if (!ppc_fp_available_inline(ctx, 0x801119ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5548);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801119F0:
    ctx->pc = 0x801119F0u;
    // 801119F0: addi    r30, r1, 48
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(48);

label_801119F4:
    ctx->pc = 0x801119F4u;
    // 801119F4: stfs     f13, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x801119F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801119F8:
    ctx->pc = 0x801119F8u;
    // 801119F8: addi    r28, r1, 136
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(136);

label_801119FC:
    ctx->pc = 0x801119FCu;
    // 801119FC: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x801119FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111A00:
    ctx->pc = 0x80111A00u;
    // 80111A00: addi    r25, r1, 248
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(248);

label_80111A04:
    ctx->pc = 0x80111A04u;
    // 80111A04: addi    r29, r1, 152
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(152);

label_80111A08:
    ctx->pc = 0x80111A08u;
    // 80111A08: or   r26, r30, r30
    {
        ctx->gpr[26] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80111A0C:
    ctx->pc = 0x80111A0Cu;
    // 80111A0C: lwz     r9, 108(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111A10:
    ctx->pc = 0x80111A10u;
    // 80111A10: li      r27, 48
    ctx->gpr[27] = (u32)(s32)(48);

label_80111A14:
    ctx->pc = 0x80111A14u;
    // 80111A14: lwz     r0, 68(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111A18:
    ctx->pc = 0x80111A18u;
    // 80111A18: lha     r4, 64(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(64);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80111A1C:
    ctx->pc = 0x80111A1Cu;
    // 80111A1C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80111A20:
    ctx->pc = 0x80111A20u;
    // 80111A20: add   r4, r31, r4
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80111A24:
    ctx->pc = 0x80111A24u;
    // 80111A24: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80111A28u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80111A28:
    ctx->pc = 0x80111A28u;
    ctx->downcount -= 8;
    // 80111A28: lwz     r9, 108(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111A2C:
    ctx->pc = 0x80111A2Cu;
    // 80111A2C: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_80111A30:
    ctx->pc = 0x80111A30u;
    // 80111A30: lwz     r0, 76(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111A34:
    ctx->pc = 0x80111A34u;
    // 80111A34: lha     r4, 72(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(72);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80111A38:
    ctx->pc = 0x80111A38u;
    // 80111A38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80111A3C:
    ctx->pc = 0x80111A3Cu;
    // 80111A3C: add   r4, r31, r4
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80111A40:
    ctx->pc = 0x80111A40u;
    // 80111A40: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80111A44u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80111A44:
    ctx->pc = 0x80111A44u;
    ctx->downcount -= 6;
    // 80111A44: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80111A48:
    ctx->pc = 0x80111A48u;
    // 80111A48: lfs     f0, 5556(r9)
    if (!ppc_fp_available_inline(ctx, 0x80111A48u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5556);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111A4C:
    ctx->pc = 0x80111A4Cu;
    // 80111A4C: stfs     f0, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111A4Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111A50:
    ctx->pc = 0x80111A50u;
    // 80111A50: stfs     f0, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80111A50u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111A54:
    ctx->pc = 0x80111A54u;
    // 80111A54: stfs     f0, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80111A54u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111A58:
    ctx->pc = 0x80111A58u;
    // 80111A58: bl      0x80248F20
    {
            ctx->lr = 0x80111A5Cu;
            ctx->pc = 0x80248F20u;
            return;
    }

label_80111A5C:
    ctx->pc = 0x80111A5Cu;
    ctx->downcount -= 20;
    // 80111A5C: lfs     f0, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x80111A5Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111A60:
    ctx->pc = 0x80111A60u;
    // 80111A60: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80111A64:
    ctx->pc = 0x80111A64u;
    // 80111A64: lfs     f8, 5560(r11)
    if (!ppc_fp_available_inline(ctx, 0x80111A64u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_80111A68:
    ctx->pc = 0x80111A68u;
    // 80111A68: lis     r9, -32712
    ctx->gpr[9] = ((u32)(s32)(-32712) << 16);

label_80111A6C:
    ctx->pc = 0x80111A6Cu;
    // 80111A6C: stfs     f0, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111A6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111A70:
    ctx->pc = 0x80111A70u;
    // 80111A70: addi    r9, r9, -2648
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2648);

label_80111A74:
    ctx->pc = 0x80111A74u;
    // 80111A74: lfs     f0, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111A74u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111A78:
    ctx->pc = 0x80111A78u;
    // 80111A78: addi    r11, r1, 72
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(72);

label_80111A7C:
    ctx->pc = 0x80111A7Cu;
    // 80111A7C: lfs     f13, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111A7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80111A80:
    ctx->pc = 0x80111A80u;
    // 80111A80: lfs     f12, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111A80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80111A84:
    ctx->pc = 0x80111A84u;
    // 80111A84: lfs     f11, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111A84u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_80111A88:
    ctx->pc = 0x80111A88u;
    // 80111A88: lfs     f10, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111A88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_80111A8C:
    ctx->pc = 0x80111A8Cu;
    // 80111A8C: fadds   f12, f12, f8
    if (!ppc_fp_available_inline(ctx, 0x80111A8Cu)) return;
    ppc_fadds(ctx, 12, 12, 8);

label_80111A90:
    ctx->pc = 0x80111A90u;
    // 80111A90: lfs     f9, 4(r3)
    if (!ppc_fp_available_inline(ctx, 0x80111A90u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_80111A94:
    ctx->pc = 0x80111A94u;
    // 80111A94: fadds   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x80111A94u)) return;
    ppc_fadds(ctx, 0, 0, 11);

label_80111A98:
    ctx->pc = 0x80111A98u;
    // 80111A98: fadds   f13, f13, f10
    if (!ppc_fp_available_inline(ctx, 0x80111A98u)) return;
    ppc_fadds(ctx, 13, 13, 10);

label_80111A9C:
    ctx->pc = 0x80111A9Cu;
    // 80111A9C: stfs     f0, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111A9Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111AA0:
    ctx->pc = 0x80111AA0u;
    // 80111AA0: stfs     f9, 68(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111AA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_80111AA4:
    ctx->pc = 0x80111AA4u;
    // 80111AA4: stfs     f13, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111AA4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80111AA8:
    ctx->pc = 0x80111AA8u;
    // 80111AA8: stfs     f12, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111AA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80111AAC:
    loop_80111AAC(ctx);
    if (ctx->pc == 0x80111AECu) goto label_80111AEC;
    return;
label_80111AB0:
    // 80111AB0: addic.  r27, r27, -24
    {
        u64 a = ctx->gpr[27];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[27] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[27];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80111AB4:
    ctx->pc = 0x80111AB4u;
    // 80111AB4: stw     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111AB8:
    ctx->pc = 0x80111AB8u;
    // 80111AB8: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111ABC:
    ctx->pc = 0x80111ABCu;
    // 80111ABC: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111AC0:
    ctx->pc = 0x80111AC0u;
    // 80111AC0: lwz     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111AC4:
    ctx->pc = 0x80111AC4u;
    // 80111AC4: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111AC8:
    ctx->pc = 0x80111AC8u;
    // 80111AC8: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111ACC:
    ctx->pc = 0x80111ACCu;
    // 80111ACC: stw     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111AD0:
    ctx->pc = 0x80111AD0u;
    // 80111AD0: lwz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111AD4:
    ctx->pc = 0x80111AD4u;
    // 80111AD4: stw     r0, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111AD8:
    ctx->pc = 0x80111AD8u;
    // 80111AD8: lwz     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111ADC:
    // 80111ADC: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

label_80111AE0:
    ctx->pc = 0x80111AE0u;
    // 80111AE0: stw     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111AE4:
    // 80111AE4: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

label_80111AE8:
    // 80111AE8: bc    4, 2, 0x80111AAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111AACu;
                return;
            }
            goto label_80111AAC;
        }
    }

label_80111AEC:
    ctx->pc = 0x80111AECu;
    ctx->downcount -= 12;
    // 80111AEC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111AF0:
    ctx->pc = 0x80111AF0u;
    // 80111AF0: addi    r3, r1, 72
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(72);

label_80111AF4:
    ctx->pc = 0x80111AF4u;
    // 80111AF4: addi    r5, r1, 152
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(152);

label_80111AF8:
    ctx->pc = 0x80111AF8u;
    // 80111AF8: addi    r4, r1, 48
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(48);

label_80111AFC:
    ctx->pc = 0x80111AFCu;
    // 80111AFC: stw     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111B00:
    ctx->pc = 0x80111B00u;
    // 80111B00: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111B04:
    ctx->pc = 0x80111B04u;
    // 80111B04: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111B08:
    ctx->pc = 0x80111B08u;
    // 80111B08: lwz     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111B0C:
    ctx->pc = 0x80111B0Cu;
    // 80111B0C: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111B10:
    ctx->pc = 0x80111B10u;
    // 80111B10: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111B14:
    ctx->pc = 0x80111B14u;
    // 80111B14: stw     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111B18:
    ctx->pc = 0x80111B18u;
    // 80111B18: bl      0x8028BEDC
    {
            ctx->lr = 0x80111B1Cu;
            ctx->pc = 0x8028BEDCu;
            return;
    }

label_80111B1C:
    ctx->pc = 0x80111B1Cu;
    ctx->downcount -= 19;
    // 80111B1C: lfs     f0, 152(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111B20:
    ctx->pc = 0x80111B20u;
    // 80111B20: lfs     f13, 156(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B20u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80111B24:
    ctx->pc = 0x80111B24u;
    // 80111B24: lfs     f12, 160(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80111B28:
    ctx->pc = 0x80111B28u;
    // 80111B28: stfs     f0, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111B2C:
    ctx->pc = 0x80111B2Cu;
    // 80111B2C: stfs     f13, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80111B30:
    ctx->pc = 0x80111B30u;
    // 80111B30: stfs     f12, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80111B34:
    ctx->pc = 0x80111B34u;
    // 80111B34: lwz     r9, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111B38:
    ctx->pc = 0x80111B38u;
    // 80111B38: lwz     r11, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111B3C:
    ctx->pc = 0x80111B3Cu;
    // 80111B3C: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111B40:
    ctx->pc = 0x80111B40u;
    // 80111B40: stw     r9, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80111B44:
    ctx->pc = 0x80111B44u;
    // 80111B44: stw     r11, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111B48:
    ctx->pc = 0x80111B48u;
    // 80111B48: stw     r0, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111B4C:
    ctx->pc = 0x80111B4Cu;
    // 80111B4C: lwz     r9, 108(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111B50:
    ctx->pc = 0x80111B50u;
    // 80111B50: lwz     r0, 180(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(180);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111B54:
    ctx->pc = 0x80111B54u;
    // 80111B54: lha     r3, 176(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(176);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80111B58:
    ctx->pc = 0x80111B58u;
    // 80111B58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80111B5C:
    ctx->pc = 0x80111B5Cu;
    // 80111B5C: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80111B60:
    ctx->pc = 0x80111B60u;
    // 80111B60: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80111B64u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80111B64:
    ctx->pc = 0x80111B64u;
    ctx->downcount -= 7;
    // 80111B64: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80111B68:
    ctx->pc = 0x80111B68u;
    // 80111B68: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80111B6C:
    ctx->pc = 0x80111B6Cu;
    // 80111B6C: lfs     f31, 5564(r9)
    if (!ppc_fp_available_inline(ctx, 0x80111B6Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5564);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80111B70:
    ctx->pc = 0x80111B70u;
    // 80111B70: lfs     f0, 5568(r11)
    if (!ppc_fp_available_inline(ctx, 0x80111B70u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5568);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111B74:
    ctx->pc = 0x80111B74u;
    // 80111B74: fmuls   f1, f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80111B74u)) return;
    ppc_fmuls(ctx, 1, 1, 31);

label_80111B78:
    ctx->pc = 0x80111B78u;
    // 80111B78: fmuls   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x80111B78u)) return;
    ppc_fmuls(ctx, 1, 1, 0);

label_80111B7C:
    ctx->pc = 0x80111B7Cu;
    // 80111B7C: bl      0x8029F4D8
    {
            ctx->lr = 0x80111B80u;
            ctx->pc = 0x8029F4D8u;
            return;
    }

label_80111B80:
    ctx->pc = 0x80111B80u;
    ctx->downcount -= 10;
    // 80111B80: lfs     f12, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80111B84:
    ctx->pc = 0x80111B84u;
    // 80111B84: fmuls   f30, f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80111B84u)) return;
    ppc_fmuls(ctx, 30, 1, 31);

label_80111B88:
    ctx->pc = 0x80111B88u;
    // 80111B88: lfs     f13, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80111B8C:
    ctx->pc = 0x80111B8Cu;
    // 80111B8C: addi    r3, r1, 200
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(200);

label_80111B90:
    ctx->pc = 0x80111B90u;
    // 80111B90: lfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111B94:
    ctx->pc = 0x80111B94u;
    // 80111B94: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_80111B98:
    ctx->pc = 0x80111B98u;
    // 80111B98: stfs     f12, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B98u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80111B9C:
    ctx->pc = 0x80111B9Cu;
    // 80111B9C: stfs     f13, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111B9Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80111BA0:
    ctx->pc = 0x80111BA0u;
    // 80111BA0: stfs     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111BA4:
    ctx->pc = 0x80111BA4u;
    // 80111BA4: bl      0x80285458
    {
            ctx->lr = 0x80111BA8u;
            ctx->pc = 0x80285458u;
            return;
    }

label_80111BA8:
    ctx->pc = 0x80111BA8u;
    ctx->downcount -= 34;
    // 80111BA8: lfs     f0, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111BAC:
    ctx->pc = 0x80111BACu;
    // 80111BAC: addi    r3, r1, 184
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(184);

label_80111BB0:
    ctx->pc = 0x80111BB0u;
    // 80111BB0: lfs     f11, 200(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(200);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_80111BB4:
    ctx->pc = 0x80111BB4u;
    // 80111BB4: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_80111BB8:
    ctx->pc = 0x80111BB8u;
    // 80111BB8: lfs     f10, 204(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BB8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(204);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_80111BBC:
    ctx->pc = 0x80111BBCu;
    // 80111BBC: lfs     f9, 208(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_80111BC0:
    ctx->pc = 0x80111BC0u;
    // 80111BC0: fmuls   f11, f11, f0
    if (!ppc_fp_available_inline(ctx, 0x80111BC0u)) return;
    ppc_fmuls(ctx, 11, 11, 0);

label_80111BC4:
    ctx->pc = 0x80111BC4u;
    // 80111BC4: fmuls   f10, f10, f0
    if (!ppc_fp_available_inline(ctx, 0x80111BC4u)) return;
    ppc_fmuls(ctx, 10, 10, 0);

label_80111BC8:
    ctx->pc = 0x80111BC8u;
    // 80111BC8: lfs     f7, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_80111BCC:
    ctx->pc = 0x80111BCCu;
    // 80111BCC: fmuls   f9, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x80111BCCu)) return;
    ppc_fmuls(ctx, 9, 9, 0);

label_80111BD0:
    ctx->pc = 0x80111BD0u;
    // 80111BD0: lfs     f6, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BD0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_80111BD4:
    ctx->pc = 0x80111BD4u;
    // 80111BD4: lfs     f8, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_80111BD8:
    ctx->pc = 0x80111BD8u;
    // 80111BD8: fmuls   f0, f11, f30
    if (!ppc_fp_available_inline(ctx, 0x80111BD8u)) return;
    ppc_fmuls(ctx, 0, 11, 30);

label_80111BDC:
    ctx->pc = 0x80111BDCu;
    // 80111BDC: stfs     f11, 184(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(184);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_80111BE0:
    ctx->pc = 0x80111BE0u;
    // 80111BE0: fmuls   f12, f9, f30
    if (!ppc_fp_available_inline(ctx, 0x80111BE0u)) return;
    ppc_fmuls(ctx, 12, 9, 30);

label_80111BE4:
    ctx->pc = 0x80111BE4u;
    // 80111BE4: stfs     f10, 188(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_80111BE8:
    ctx->pc = 0x80111BE8u;
    // 80111BE8: fmuls   f13, f10, f30
    if (!ppc_fp_available_inline(ctx, 0x80111BE8u)) return;
    ppc_fmuls(ctx, 13, 10, 30);

label_80111BEC:
    ctx->pc = 0x80111BECu;
    // 80111BEC: fadds   f5, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x80111BECu)) return;
    ppc_fadds(ctx, 5, 0, 0);

label_80111BF0:
    ctx->pc = 0x80111BF0u;
    // 80111BF0: stfs     f9, 192(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_80111BF4:
    ctx->pc = 0x80111BF4u;
    // 80111BF4: fadds   f10, f13, f13
    if (!ppc_fp_available_inline(ctx, 0x80111BF4u)) return;
    ppc_fadds(ctx, 10, 13, 13);

label_80111BF8:
    ctx->pc = 0x80111BF8u;
    // 80111BF8: stfs     f0, 168(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111BF8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111BFC:
    ctx->pc = 0x80111BFCu;
    // 80111BFC: fadds   f11, f12, f12
    if (!ppc_fp_available_inline(ctx, 0x80111BFCu)) return;
    ppc_fadds(ctx, 11, 12, 12);

label_80111C00:
    ctx->pc = 0x80111C00u;
    // 80111C00: stfs     f13, 172(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C00u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80111C04:
    ctx->pc = 0x80111C04u;
    // 80111C04: fadds   f7, f7, f5
    if (!ppc_fp_available_inline(ctx, 0x80111C04u)) return;
    ppc_fadds(ctx, 7, 7, 5);

label_80111C08:
    ctx->pc = 0x80111C08u;
    // 80111C08: stfs     f12, 176(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C08u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80111C0C:
    ctx->pc = 0x80111C0Cu;
    // 80111C0C: fadds   f6, f6, f10
    if (!ppc_fp_available_inline(ctx, 0x80111C0Cu)) return;
    ppc_fadds(ctx, 6, 6, 10);

label_80111C10:
    ctx->pc = 0x80111C10u;
    // 80111C10: stfs     f7, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[7]));
    }

label_80111C14:
    ctx->pc = 0x80111C14u;
    // 80111C14: fadds   f8, f8, f11
    if (!ppc_fp_available_inline(ctx, 0x80111C14u)) return;
    ppc_fadds(ctx, 8, 8, 11);

label_80111C18:
    ctx->pc = 0x80111C18u;
    // 80111C18: stfs     f6, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_80111C1C:
    ctx->pc = 0x80111C1Cu;
    // 80111C1C: stfs     f8, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[8]));
    }

label_80111C20:
    ctx->pc = 0x80111C20u;
    // 80111C20: stfs     f5, 152(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C20u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_80111C24:
    ctx->pc = 0x80111C24u;
    // 80111C24: stfs     f10, 156(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_80111C28:
    ctx->pc = 0x80111C28u;
    // 80111C28: stfs     f11, 160(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_80111C2C:
    ctx->pc = 0x80111C2Cu;
    // 80111C2C: bl      0x802854F8
    {
            ctx->lr = 0x80111C30u;
            ctx->pc = 0x802854F8u;
            return;
    }

label_80111C30:
    ctx->pc = 0x80111C30u;
    ctx->downcount -= 28;
    // 80111C30: lfs     f0, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111C34:
    ctx->pc = 0x80111C34u;
    // 80111C34: addi    r3, r1, 168
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(168);

label_80111C38:
    ctx->pc = 0x80111C38u;
    // 80111C38: lfs     f13, 184(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(184);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80111C3C:
    ctx->pc = 0x80111C3Cu;
    // 80111C3C: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_80111C40:
    ctx->pc = 0x80111C40u;
    // 80111C40: lfs     f12, 188(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C40u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80111C44:
    ctx->pc = 0x80111C44u;
    // 80111C44: lfs     f11, 192(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C44u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_80111C48:
    ctx->pc = 0x80111C48u;
    // 80111C48: fmuls   f13, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x80111C48u)) return;
    ppc_fmuls(ctx, 13, 13, 0);

label_80111C4C:
    ctx->pc = 0x80111C4Cu;
    // 80111C4C: fmuls   f12, f12, f0
    if (!ppc_fp_available_inline(ctx, 0x80111C4Cu)) return;
    ppc_fmuls(ctx, 12, 12, 0);

label_80111C50:
    ctx->pc = 0x80111C50u;
    // 80111C50: lfs     f10, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_80111C54:
    ctx->pc = 0x80111C54u;
    // 80111C54: fmuls   f11, f11, f0
    if (!ppc_fp_available_inline(ctx, 0x80111C54u)) return;
    ppc_fmuls(ctx, 11, 11, 0);

label_80111C58:
    ctx->pc = 0x80111C58u;
    // 80111C58: lfs     f9, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_80111C5C:
    ctx->pc = 0x80111C5Cu;
    // 80111C5C: lfs     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C5Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111C60:
    ctx->pc = 0x80111C60u;
    // 80111C60: fmuls   f7, f13, f30
    if (!ppc_fp_available_inline(ctx, 0x80111C60u)) return;
    ppc_fmuls(ctx, 7, 13, 30);

label_80111C64:
    ctx->pc = 0x80111C64u;
    // 80111C64: fmuls   f6, f12, f30
    if (!ppc_fp_available_inline(ctx, 0x80111C64u)) return;
    ppc_fmuls(ctx, 6, 12, 30);

label_80111C68:
    ctx->pc = 0x80111C68u;
    // 80111C68: stfs     f13, 168(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80111C6C:
    ctx->pc = 0x80111C6Cu;
    // 80111C6C: fmuls   f8, f11, f30
    if (!ppc_fp_available_inline(ctx, 0x80111C6Cu)) return;
    ppc_fmuls(ctx, 8, 11, 30);

label_80111C70:
    ctx->pc = 0x80111C70u;
    // 80111C70: stfs     f12, 172(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80111C74:
    ctx->pc = 0x80111C74u;
    // 80111C74: fadds   f10, f10, f7
    if (!ppc_fp_available_inline(ctx, 0x80111C74u)) return;
    ppc_fadds(ctx, 10, 10, 7);

label_80111C78:
    ctx->pc = 0x80111C78u;
    // 80111C78: stfs     f11, 176(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_80111C7C:
    ctx->pc = 0x80111C7Cu;
    // 80111C7C: fadds   f9, f9, f6
    if (!ppc_fp_available_inline(ctx, 0x80111C7Cu)) return;
    ppc_fadds(ctx, 9, 9, 6);

label_80111C80:
    ctx->pc = 0x80111C80u;
    // 80111C80: stfs     f10, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_80111C84:
    ctx->pc = 0x80111C84u;
    // 80111C84: fadds   f0, f0, f8
    if (!ppc_fp_available_inline(ctx, 0x80111C84u)) return;
    ppc_fadds(ctx, 0, 0, 8);

label_80111C88:
    ctx->pc = 0x80111C88u;
    // 80111C88: stfs     f9, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_80111C8C:
    ctx->pc = 0x80111C8Cu;
    // 80111C8C: stfs     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111C90:
    ctx->pc = 0x80111C90u;
    // 80111C90: stfs     f7, 152(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[7]));
    }

label_80111C94:
    ctx->pc = 0x80111C94u;
    // 80111C94: stfs     f6, 156(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C94u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_80111C98:
    ctx->pc = 0x80111C98u;
    // 80111C98: stfs     f8, 160(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111C98u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[8]));
    }

label_80111C9C:
    ctx->pc = 0x80111C9Cu;
    // 80111C9C: bl      0x802854A8
    {
            ctx->lr = 0x80111CA0u;
            ctx->pc = 0x802854A8u;
            return;
    }

label_80111CA0:
    ctx->pc = 0x80111CA0u;
    ctx->downcount -= 3;
    // 80111CA0: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_80111CA4:
    ctx->pc = 0x80111CA4u;
    // 80111CA4: addi    r3, r1, 232
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(232);

label_80111CA8:
    ctx->pc = 0x80111CA8u;
    // 80111CA8: bl      0x802854A8
    {
            ctx->lr = 0x80111CACu;
            ctx->pc = 0x802854A8u;
            return;
    }

label_80111CAC:
    ctx->pc = 0x80111CACu;
    ctx->downcount -= 36;
    // 80111CAC: lfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111CB0:
    ctx->pc = 0x80111CB0u;
    // 80111CB0: lfs     f11, 232(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_80111CB4:
    ctx->pc = 0x80111CB4u;
    // 80111CB4: lfs     f9, 240(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CB4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_80111CB8:
    ctx->pc = 0x80111CB8u;
    // 80111CB8: lfs     f10, 236(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CB8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(236);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_80111CBC:
    ctx->pc = 0x80111CBCu;
    // 80111CBC: fmuls   f11, f11, f0
    if (!ppc_fp_available_inline(ctx, 0x80111CBCu)) return;
    ppc_fmuls(ctx, 11, 11, 0);

label_80111CC0:
    ctx->pc = 0x80111CC0u;
    // 80111CC0: fmuls   f9, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x80111CC0u)) return;
    ppc_fmuls(ctx, 9, 9, 0);

label_80111CC4:
    ctx->pc = 0x80111CC4u;
    // 80111CC4: lfs     f6, 168(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CC4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_80111CC8:
    ctx->pc = 0x80111CC8u;
    // 80111CC8: fmuls   f10, f10, f0
    if (!ppc_fp_available_inline(ctx, 0x80111CC8u)) return;
    ppc_fmuls(ctx, 10, 10, 0);

label_80111CCC:
    ctx->pc = 0x80111CCCu;
    // 80111CCC: lfs     f8, 172(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CCCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_80111CD0:
    ctx->pc = 0x80111CD0u;
    // 80111CD0: fmuls   f4, f9, f30
    if (!ppc_fp_available_inline(ctx, 0x80111CD0u)) return;
    ppc_fmuls(ctx, 4, 9, 30);

label_80111CD4:
    ctx->pc = 0x80111CD4u;
    // 80111CD4: lfs     f7, 176(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_80111CD8:
    ctx->pc = 0x80111CD8u;
    // 80111CD8: fmuls   f5, f11, f30
    if (!ppc_fp_available_inline(ctx, 0x80111CD8u)) return;
    ppc_fmuls(ctx, 5, 11, 30);

label_80111CDC:
    ctx->pc = 0x80111CDCu;
    // 80111CDC: lfs     f0, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111CE0:
    ctx->pc = 0x80111CE0u;
    // 80111CE0: fmuls   f30, f10, f30
    if (!ppc_fp_available_inline(ctx, 0x80111CE0u)) return;
    ppc_fmuls(ctx, 30, 10, 30);

label_80111CE4:
    ctx->pc = 0x80111CE4u;
    // 80111CE4: lfs     f13, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80111CE8:
    ctx->pc = 0x80111CE8u;
    // 80111CE8: lfs     f12, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CE8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80111CEC:
    ctx->pc = 0x80111CECu;
    // 80111CEC: fadds   f6, f6, f5
    if (!ppc_fp_available_inline(ctx, 0x80111CECu)) return;
    ppc_fadds(ctx, 6, 6, 5);

label_80111CF0:
    ctx->pc = 0x80111CF0u;
    // 80111CF0: fadds   f8, f8, f30
    if (!ppc_fp_available_inline(ctx, 0x80111CF0u)) return;
    ppc_fadds(ctx, 8, 8, 30);

label_80111CF4:
    ctx->pc = 0x80111CF4u;
    // 80111CF4: stb     r27, 248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        mem_write8(ctx, ea, (u8)ctx->gpr[27]);
    }

label_80111CF8:
    ctx->pc = 0x80111CF8u;
    // 80111CF8: fadds   f7, f7, f4
    if (!ppc_fp_available_inline(ctx, 0x80111CF8u)) return;
    ppc_fadds(ctx, 7, 7, 4);

label_80111CFC:
    ctx->pc = 0x80111CFCu;
    // 80111CFC: stfs     f11, 216(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111CFCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_80111D00:
    ctx->pc = 0x80111D00u;
    // 80111D00: fadds   f0, f0, f6
    if (!ppc_fp_available_inline(ctx, 0x80111D00u)) return;
    ppc_fadds(ctx, 0, 0, 6);

label_80111D04:
    ctx->pc = 0x80111D04u;
    // 80111D04: stfs     f10, 220(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D04u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_80111D08:
    ctx->pc = 0x80111D08u;
    // 80111D08: fadds   f13, f13, f8
    if (!ppc_fp_available_inline(ctx, 0x80111D08u)) return;
    ppc_fadds(ctx, 13, 13, 8);

label_80111D0C:
    ctx->pc = 0x80111D0Cu;
    // 80111D0C: stfs     f0, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D0Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111D10:
    ctx->pc = 0x80111D10u;
    // 80111D10: fadds   f12, f12, f7
    if (!ppc_fp_available_inline(ctx, 0x80111D10u)) return;
    ppc_fadds(ctx, 12, 12, 7);

label_80111D14:
    ctx->pc = 0x80111D14u;
    // 80111D14: stfs     f13, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80111D18:
    ctx->pc = 0x80111D18u;
    // 80111D18: stfs     f12, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80111D1C:
    ctx->pc = 0x80111D1Cu;
    // 80111D1C: stfs     f9, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[9]));
    }

label_80111D20:
    ctx->pc = 0x80111D20u;
    // 80111D20: stfs     f5, 184(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D20u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(184);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_80111D24:
    ctx->pc = 0x80111D24u;
    // 80111D24: stfs     f30, 188(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80111D28:
    ctx->pc = 0x80111D28u;
    // 80111D28: stfs     f4, 192(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_80111D2C:
    ctx->pc = 0x80111D2Cu;
    // 80111D2C: stfs     f6, 152(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_80111D30:
    ctx->pc = 0x80111D30u;
    // 80111D30: stfs     f8, 156(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[8]));
    }

label_80111D34:
    ctx->pc = 0x80111D34u;
    // 80111D34: stfs     f7, 160(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[7]));
    }

label_80111D38:
    ctx->pc = 0x80111D38u;
    // 80111D38: bl      0x8028F124
    {
            ctx->lr = 0x80111D3Cu;
            ctx->pc = 0x8028F124u;
            return;
    }

label_80111D3C:
    ctx->pc = 0x80111D3Cu;
    ctx->downcount -= 6;
    // 80111D3C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80111D40:
    ctx->pc = 0x80111D40u;
    // 80111D40: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80111D44:
    ctx->pc = 0x80111D44u;
    // 80111D44: addi    r4, r4, 5544
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5544);

label_80111D48:
    ctx->pc = 0x80111D48u;
    // 80111D48: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80111D4C:
    ctx->pc = 0x80111D4Cu;
    // 80111D4C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80111D50:
    ctx->pc = 0x80111D50u;
    // 80111D50: bl      0x800E48B0
    {
            ctx->lr = 0x80111D54u;
            ctx->pc = 0x800E48B0u;
            return;
    }

label_80111D54:
    ctx->pc = 0x80111D54u;
    ctx->downcount -= 12;
    // 80111D54: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80111D58:
    ctx->pc = 0x80111D58u;
    // 80111D58: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80111D5C:
    ctx->pc = 0x80111D5Cu;
    // 80111D5C: lfs     f13, 5572(r9)
    if (!ppc_fp_available_inline(ctx, 0x80111D5Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5572);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80111D60:
    ctx->pc = 0x80111D60u;
    // 80111D60: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80111D64:
    ctx->pc = 0x80111D64u;
    // 80111D64: lfs     f0, 5576(r11)
    if (!ppc_fp_available_inline(ctx, 0x80111D64u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5576);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80111D68:
    ctx->pc = 0x80111D68u;
    // 80111D68: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80111D6C:
    ctx->pc = 0x80111D6Cu;
    // 80111D6C: stfs     f13, 152(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80111D70:
    ctx->pc = 0x80111D70u;
    // 80111D70: or   r5, r25, r25
    {
        ctx->gpr[5] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80111D74:
    ctx->pc = 0x80111D74u;
    // 80111D74: stfs     f0, 12(r29)
    if (!ppc_fp_available_inline(ctx, 0x80111D74u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111D78:
    ctx->pc = 0x80111D78u;
    // 80111D78: stfs     f0, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x80111D78u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111D7C:
    ctx->pc = 0x80111D7Cu;
    // 80111D7C: stfs     f0, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x80111D7Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80111D80:
    ctx->pc = 0x80111D80u;
    // 80111D80: bl      0x80239CEC
    {
            ctx->lr = 0x80111D84u;
            ctx->pc = 0x80239CECu;
            return;
    }

label_80111D84:
    ctx->pc = 0x80111D84u;
    ctx->downcount -= 18;
    // 80111D84: lwz     r0, 396(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(396);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111D88:
    ctx->pc = 0x80111D88u;
    // 80111D88: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80111D8C:
    ctx->pc = 0x80111D8Cu;
    // 80111D8C: lmw     r25, 348(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(348);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80111D90:
    ctx->pc = 0x80111D90u;
    // 80111D90: lfd     f30, 376(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(376);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80111D94:
    ctx->pc = 0x80111D94u;
    // 80111D94: lfd     f31, 384(r1)
    if (!ppc_fp_available_inline(ctx, 0x80111D94u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80111D98:
    ctx->pc = 0x80111D98u;
    // 80111D98: addi    r1, r1, 392
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(392);

label_80111D9C:
    ctx->pc = 0x80111D9Cu;
    // 80111D9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80111DA0:
    ctx->pc = 0x80111DA0u;
    ctx->downcount -= 16;
    // 80111DA0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80111DA4:
    ctx->pc = 0x80111DA4u;
    // 80111DA4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80111DA8:
    ctx->pc = 0x80111DA8u;
    // 80111DA8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80111DAC:
    ctx->pc = 0x80111DACu;
    // 80111DAC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111DB0:
    ctx->pc = 0x80111DB0u;
    // 80111DB0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80111DB4:
    ctx->pc = 0x80111DB4u;
    // 80111DB4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80111DB8:
    ctx->pc = 0x80111DB8u;
    ctx->downcount -= 11;
    // 80111DB8: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111DBC:
    ctx->pc = 0x80111DBCu;
    // 80111DBC: lwz     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111DC0:
    // 80111DC0: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80111DC4:
    ctx->pc = 0x80111DC4u;
    // 80111DC4: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80111DC8:
    // 80111DC8: subf   r10, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_80111DCC:
    // 80111DCC: cmplw   r10, r11
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

label_80111DD0:
    // 80111DD0: bc    12, 0, 0x80111DF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111DF8;
        }
    }

label_80111DD4:
    ctx->downcount -= 3;
    // 80111DD4: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80111DD8:
    ctx->pc = 0x80111DD8u;
    // 80111DD8: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111DDC:
    // 80111DDC: b       0x80111ED0
    {
            goto label_80111ED0;
    }

label_80111DE0:
    ctx->pc = 0x80111DE0u;
    ctx->downcount -= 6;
    // 80111DE0: lwz     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111DE4:
    // 80111DE4: add   r0, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80111DE8:
    ctx->pc = 0x80111DE8u;
    // 80111DE8: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111DEC:
    ctx->pc = 0x80111DECu;
    // 80111DEC: stwx    r9, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80111DF0:
    ctx->pc = 0x80111DF0u;
    // 80111DF0: stw     r10, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80111DF4:
    // 80111DF4: b       0x80111DB8
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111DB8u;
                return;
            }
            goto label_80111DB8;
    }

label_80111DF8:
    ctx->downcount -= 2;
    // 80111DF8: cmplw   r10, r30
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

label_80111DFC:
    // 80111DFC: bc    12, 0, 0x80111E1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111E1C;
        }
    }

label_80111E00:
    ctx->downcount -= 50;
    // 80111E00: divwu   r0, r10, r30
    {
        u32 divisor = ctx->gpr[30];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[10] / divisor;
    }

label_80111E04:
    ctx->pc = 0x80111E04u;
    // 80111E04: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111E08:
    // 80111E08: mullw   r11, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80111E0C:
    ctx->pc = 0x80111E0Cu;
    // 80111E0C: lwz     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80111E10:
    // 80111E10: add   r0, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80111E14:
    ctx->pc = 0x80111E14u;
    // 80111E14: stw     r0, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111E18:
    // 80111E18: b       0x80111ED0
    {
            goto label_80111ED0;
    }

label_80111E1C:
    ctx->pc = 0x80111E1Cu;
    ctx->downcount -= 8;
    // 80111E1C: lwz     r9, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111E20:
    // 80111E20: add   r0, r11, r11
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80111E24:
    // 80111E24: cmpwi   r10, 0
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

label_80111E28:
    // 80111E28: rlwinm r9, r9, 28, 4, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x0FFFFFFFu;
    }

label_80111E2C:
    // 80111E2C: addi    r9, r9, 7
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7);

label_80111E30:
    // 80111E30: rlwinm r9, r9, 0, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF8u;
    }

label_80111E34:
    // 80111E34: add   r31, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_80111E38:
    // 80111E38: bc    12, 2, 0x80111E58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111E58;
        }
    }

label_80111E3C:
    ctx->downcount -= 7;
    // 80111E3C: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_80111E40:
    // 80111E40: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80111E44:
    // 80111E44: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80111E48:
    // 80111E48: addi    r9, r9, -14336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80111E4C:
    ctx->pc = 0x80111E4Cu;
    // 80111E4C: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80111E50:
    ctx->pc = 0x80111E50u;
    // 80111E50: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111E54:
    ctx->pc = 0x80111E54u;
    // 80111E54: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80111E58:
    ctx->downcount -= 2;
    // 80111E58: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80111E5C:
    // 80111E5C: bl      0x80281C60
    {
            ctx->lr = 0x80111E60u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80111E60:
    ctx->downcount -= 3;
    // 80111E60: cmpwi   r3, 0
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

label_80111E64:
    ctx->pc = 0x80111E64u;
    // 80111E64: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80111E68:
    // 80111E68: bc    4, 2, 0x80111EB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111EB4;
        }
    }

label_80111E6C:
    ctx->downcount -= 3;
    // 80111E6C: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80111E70:
    // 80111E70: cmplwi  r11, 0x0080
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

label_80111E74:
    // 80111E74: bc    12, 1, 0x80111EA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111EA0;
        }
    }

label_80111E78:
    ctx->downcount -= 2;
    // 80111E78: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80111E7C:
    // 80111E7C: addi    r7, r9, -14336
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80111E80:
    ctx->downcount -= 5;
    // 80111E80: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_80111E84:
    // 80111E84: rlwinm r8, r0, 31, 1, 29
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80111E88:
    ctx->pc = 0x80111E88u;
    // 80111E88: lwzx    r10, r8, r7
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[7];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80111E8C:
    // 80111E8C: cmpwi   r10, 0
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

label_80111E90:
    // 80111E90: bc    4, 2, 0x80111DE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111DE0u;
                return;
            }
            goto label_80111DE0;
        }
    }

label_80111E94:
    ctx->downcount -= 3;
    // 80111E94: addi    r11, r11, 8
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(8);

label_80111E98:
    // 80111E98: cmplwi  r11, 0x0080
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

label_80111E9C:
    // 80111E9C: bc    4, 1, 0x80111E80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111E80u;
                return;
            }
            goto label_80111E80;
        }
    }

label_80111EA0:
    ctx->downcount -= 4;
    // 80111EA0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80111EA4:
    // 80111EA4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80111EA8:
    ctx->pc = 0x80111EA8u;
    // 80111EA8: stw     r0, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111EAC:
    // 80111EAC: bl      0x80281C60
    {
            ctx->lr = 0x80111EB0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80111EB0:
    ctx->pc = 0x80111EB0u;
    ctx->downcount -= 1;
    // 80111EB0: stw     r3, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80111EB4:
    ctx->pc = 0x80111EB4u;
    ctx->downcount -= 7;
    // 80111EB4: lwz     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111EB8:
    ctx->pc = 0x80111EB8u;
    // 80111EB8: lwz     r9, -32764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32764);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111EBC:
    // 80111EBC: add   r0, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80111EC0:
    // 80111EC0: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80111EC4:
    ctx->pc = 0x80111EC4u;
    // 80111EC4: stw     r0, -32756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32756);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111EC8:
    ctx->pc = 0x80111EC8u;
    // 80111EC8: stw     r9, -32760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32760);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80111ECC:
    // 80111ECC: b       0x80111DB8
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111DB8u;
                return;
            }
            goto label_80111DB8;
    }

label_80111ED0:
    ctx->pc = 0x80111ED0u;
    ctx->downcount -= 16;
    // 80111ED0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111ED4:
    ctx->pc = 0x80111ED4u;
    // 80111ED4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80111ED8:
    ctx->pc = 0x80111ED8u;
    // 80111ED8: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80111EDC:
    ctx->pc = 0x80111EDCu;
    // 80111EDC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80111EE0:
    ctx->pc = 0x80111EE0u;
    // 80111EE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80111EE4:
    ctx->pc = 0x80111EE4u;
    ctx->downcount -= 21;
    // 80111EE4: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80111EE8:
    ctx->pc = 0x80111EE8u;
    // 80111EE8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80111EEC:
    ctx->pc = 0x80111EECu;
    // 80111EEC: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80111EF0:
    ctx->pc = 0x80111EF0u;
    // 80111EF0: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111EF4:
    ctx->pc = 0x80111EF4u;
    // 80111EF4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80111EF8:
    ctx->pc = 0x80111EF8u;
    // 80111EF8: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_80111EFC:
    ctx->pc = 0x80111EFCu;
    // 80111EFC: addi    r29, r9, -14336
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-14336);

label_80111F00:
    ctx->pc = 0x80111F00u;
    // 80111F00: rlwinm r9, r0, 31, 1, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80111F04:
    ctx->pc = 0x80111F04u;
    // 80111F04: lwzx    r30, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80111F08:
    ctx->pc = 0x80111F08u;
    // 80111F08: cmpwi   r30, 0
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

label_80111F0C:
    ctx->pc = 0x80111F0Cu;
    // 80111F0C: bc    12, 2, 0x80111F1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111F1C;
        }
    }

label_80111F10:
    ctx->pc = 0x80111F10u;
    ctx->downcount -= 3;
    // 80111F10: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111F14:
    ctx->pc = 0x80111F14u;
    // 80111F14: stwx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111F18:
    ctx->pc = 0x80111F18u;
    // 80111F18: b       0x80111F9C
    {
            goto label_80111F9C;
    }

label_80111F1C:
    ctx->pc = 0x80111F1Cu;
    ctx->downcount -= 7;
    // 80111F1C: addi    r0, r3, 7
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(7);

label_80111F20:
    ctx->pc = 0x80111F20u;
    // 80111F20: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_80111F24:
    ctx->pc = 0x80111F24u;
    // 80111F24: rlwinm r31, r0, 0, 0, 28
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF8u;
    }

label_80111F28:
    ctx->pc = 0x80111F28u;
    // 80111F28: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80111F2C:
    ctx->pc = 0x80111F2Cu;
    // 80111F2C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80111F30:
    ctx->pc = 0x80111F30u;
    // 80111F30: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_80111F34:
    ctx->pc = 0x80111F34u;
    // 80111F34: bl      0x80003EE0
    {
            ctx->lr = 0x80111F38u;
            ctx->pc = 0x80003EE0u;
            return;
    }

label_80111F38:
    ctx->pc = 0x80111F38u;
    ctx->downcount -= 3;
    // 80111F38: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111F3C:
    ctx->pc = 0x80111F3Cu;
    // 80111F3C: cmpwi   r9, 1
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

label_80111F40:
    ctx->pc = 0x80111F40u;
    // 80111F40: bc    12, 2, 0x80111F98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80111F98;
        }
    }

label_80111F44:
    ctx->pc = 0x80111F44u;
    ctx->downcount -= 9;
    // 80111F44: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_80111F48:
    ctx->pc = 0x80111F48u;
    // 80111F48: add   r11, r3, r31
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80111F4C:
    ctx->pc = 0x80111F4Cu;
    // 80111F4C: rlwinm r0, r0, 31, 1, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x7FFFFFFCu;
    }

label_80111F50:
    ctx->pc = 0x80111F50u;
    // 80111F50: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80111F54:
    ctx->pc = 0x80111F54u;
    // 80111F54: stwx    r11, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80111F58:
    ctx->pc = 0x80111F58u;
    // 80111F58: cmpwi   r9, 2
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

label_80111F5C:
    ctx->pc = 0x80111F5Cu;
    // 80111F5C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80111F60:
    ctx->pc = 0x80111F60u;
    // 80111F60: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80111F64:
    ctx->pc = 0x80111F64u;
    // 80111F64: bc    4, 2, 0x80111F70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80111F70;
        }
    }

label_80111F68:
    ctx->pc = 0x80111F68u;
    ctx->downcount -= 2;
    // 80111F68: stwx    r30, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80111F6C:
    ctx->pc = 0x80111F6Cu;
    // 80111F6C: b       0x80111F98
    {
            goto label_80111F98;
    }

label_80111F70:
    loop_80111F70(ctx);
    if (ctx->pc == 0x80111F90u) goto label_80111F90;
    return;
label_80111F74:
    // 80111F74: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_80111F78:
    // 80111F78: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80111F7C:
    ctx->pc = 0x80111F7Cu;
    // 80111F7C: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80111F80:
    // 80111F80: add   r11, r10, r31
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80111F84:
    // 80111F84: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80111F88:
    // 80111F88: cmpw    r9, r8
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

label_80111F8C:
    // 80111F8C: bc    4, 2, 0x80111F70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111F70u;
                return;
            }
            goto label_80111F70;
        }
    }

label_80111F90:
    ctx->pc = 0x80111F90u;
    ctx->downcount -= 2;
    // 80111F90: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80111F94:
    ctx->pc = 0x80111F94u;
    // 80111F94: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111F98:
    ctx->pc = 0x80111F98u;
    ctx->downcount -= 1;
    // 80111F98: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80111F9C:
    ctx->pc = 0x80111F9Cu;
    ctx->downcount -= 17;
    // 80111F9C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80111FA0:
    ctx->pc = 0x80111FA0u;
    // 80111FA0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80111FA4:
    ctx->pc = 0x80111FA4u;
    // 80111FA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80111FA8:
    ctx->pc = 0x80111FA8u;
    // 80111FA8: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80111FAC:
    ctx->pc = 0x80111FACu;
    // 80111FAC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80111FB0:
    ctx->pc = 0x80111FB0u;
    // 80111FB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80111FB4:
    ctx->pc = 0x80111FB4u;
    ctx->downcount -= 7;
    // 80111FB4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80111FB8:
    ctx->pc = 0x80111FB8u;
    // 80111FB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80111FBC:
    ctx->pc = 0x80111FBCu;
    // 80111FBC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80111FC0:
    ctx->pc = 0x80111FC0u;
    // 80111FC0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80111FC4:
    ctx->pc = 0x80111FC4u;
    // 80111FC4: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80111FC8:
    ctx->pc = 0x80111FC8u;
    // 80111FC8: cmpw    r4, r0
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

label_80111FCC:
    ctx->pc = 0x80111FCCu;
    // 80111FCC: bc    4, 2, 0x80112100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80112100;
        }
    }

label_80111FD0:
    ctx->pc = 0x80111FD0u;
    ctx->downcount -= 2;
    // 80111FD0: cmpwi   r3, 0
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

label_80111FD4:
    ctx->pc = 0x80111FD4u;
    // 80111FD4: bc    12, 2, 0x80112100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112100;
        }
    }

label_80111FD8:
    ctx->pc = 0x80111FD8u;
    ctx->downcount -= 5;
    // 80111FD8: lis     r3, 29557
    ctx->gpr[3] = ((u32)(s32)(29557) << 16);

label_80111FDC:
    ctx->pc = 0x80111FDCu;
    // 80111FDC: li      r4, 34
    ctx->gpr[4] = (u32)(s32)(34);

label_80111FE0:
    ctx->pc = 0x80111FE0u;
    // 80111FE0: ori     r3, r3, 0x7266
    ctx->gpr[3] = ctx->gpr[3] | 0x7266u;

label_80111FE4:
    ctx->pc = 0x80111FE4u;
    // 80111FE4: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_80111FE8:
    ctx->pc = 0x80111FE8u;
    // 80111FE8: bl      0x80252AF0
    {
            ctx->lr = 0x80111FECu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80111FEC:
    ctx->pc = 0x80111FECu;
    ctx->downcount -= 5;
    // 80111FEC: lis     r3, 26483
    ctx->gpr[3] = ((u32)(s32)(26483) << 16);

label_80111FF0:
    ctx->pc = 0x80111FF0u;
    // 80111FF0: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80111FF4:
    ctx->pc = 0x80111FF4u;
    // 80111FF4: ori     r3, r3, 0x6864
    ctx->gpr[3] = ctx->gpr[3] | 0x6864u;

label_80111FF8:
    ctx->pc = 0x80111FF8u;
    // 80111FF8: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80111FFC:
    ctx->pc = 0x80111FFCu;
    // 80111FFC: bl      0x80252AF0
    {
            ctx->lr = 0x80112000u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80112000:
    ctx->pc = 0x80112000u;
    ctx->downcount -= 5;
    // 80112000: lis     r3, 30561
    ctx->gpr[3] = ((u32)(s32)(30561) << 16);

label_80112004:
    ctx->pc = 0x80112004u;
    // 80112004: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_80112008:
    ctx->pc = 0x80112008u;
    // 80112008: ori     r3, r3, 0x7665
    ctx->gpr[3] = ctx->gpr[3] | 0x7665u;

label_8011200C:
    ctx->pc = 0x8011200Cu;
    // 8011200C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80112010:
    ctx->pc = 0x80112010u;
    // 80112010: bl      0x80252AF0
    {
            ctx->lr = 0x80112014u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80112014:
    ctx->pc = 0x80112014u;
    ctx->downcount -= 5;
    // 80112014: lis     r3, 29540
    ctx->gpr[3] = ((u32)(s32)(29540) << 16);

label_80112018:
    ctx->pc = 0x80112018u;
    // 80112018: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8011201C:
    ctx->pc = 0x8011201Cu;
    // 8011201C: ori     r3, r3, 0x7461
    ctx->gpr[3] = ctx->gpr[3] | 0x7461u;

label_80112020:
    ctx->pc = 0x80112020u;
    // 80112020: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80112024:
    ctx->pc = 0x80112024u;
    // 80112024: bl      0x80252AF0
    {
            ctx->lr = 0x80112028u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80112028:
    ctx->pc = 0x80112028u;
    ctx->downcount -= 5;
    // 80112028: lis     r3, 29284
    ctx->gpr[3] = ((u32)(s32)(29284) << 16);

label_8011202C:
    ctx->pc = 0x8011202Cu;
    // 8011202C: li      r4, 49
    ctx->gpr[4] = (u32)(s32)(49);

label_80112030:
    ctx->pc = 0x80112030u;
    // 80112030: ori     r3, r3, 0x6D73
    ctx->gpr[3] = ctx->gpr[3] | 0x6D73u;

label_80112034:
    ctx->pc = 0x80112034u;
    // 80112034: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80112038:
    ctx->pc = 0x80112038u;
    // 80112038: bl      0x80252AF0
    {
            ctx->lr = 0x8011203Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8011203C:
    ctx->pc = 0x8011203Cu;
    ctx->downcount -= 5;
    // 8011203C: lis     r3, 29797
    ctx->gpr[3] = ((u32)(s32)(29797) << 16);

label_80112040:
    ctx->pc = 0x80112040u;
    // 80112040: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80112044:
    ctx->pc = 0x80112044u;
    // 80112044: ori     r3, r3, 0x726E
    ctx->gpr[3] = ctx->gpr[3] | 0x726Eu;

label_80112048:
    ctx->pc = 0x80112048u;
    // 80112048: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8011204C:
    ctx->pc = 0x8011204Cu;
    // 8011204C: bl      0x80252AF0
    {
            ctx->lr = 0x80112050u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80112050:
    ctx->pc = 0x80112050u;
    ctx->downcount -= 5;
    // 80112050: lis     r3, 28260
    ctx->gpr[3] = ((u32)(s32)(28260) << 16);

label_80112054:
    ctx->pc = 0x80112054u;
    // 80112054: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80112058:
    ctx->pc = 0x80112058u;
    // 80112058: ori     r3, r3, 0x6267
    ctx->gpr[3] = ctx->gpr[3] | 0x6267u;

label_8011205C:
    ctx->pc = 0x8011205Cu;
    // 8011205C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80112060:
    ctx->pc = 0x80112060u;
    // 80112060: bl      0x80252AF0
    {
            ctx->lr = 0x80112064u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80112064:
    ctx->pc = 0x80112064u;
    ctx->downcount -= 5;
    // 80112064: lis     r3, 28271
    ctx->gpr[3] = ((u32)(s32)(28271) << 16);

label_80112068:
    ctx->pc = 0x80112068u;
    // 80112068: li      r4, 184
    ctx->gpr[4] = (u32)(s32)(184);

label_8011206C:
    ctx->pc = 0x8011206Cu;
    // 8011206C: ori     r3, r3, 0x6465
    ctx->gpr[3] = ctx->gpr[3] | 0x6465u;

label_80112070:
    ctx->pc = 0x80112070u;
    // 80112070: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80112074:
    ctx->pc = 0x80112074u;
    // 80112074: bl      0x80252AF0
    {
            ctx->lr = 0x80112078u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_80112078:
    ctx->pc = 0x80112078u;
    ctx->downcount -= 5;
    // 80112078: lis     r3, 27749
    ctx->gpr[3] = ((u32)(s32)(27749) << 16);

label_8011207C:
    ctx->pc = 0x8011207Cu;
    // 8011207C: li      r4, 86
    ctx->gpr[4] = (u32)(s32)(86);

label_80112080:
    ctx->pc = 0x80112080u;
    // 80112080: ori     r3, r3, 0x766C
    ctx->gpr[3] = ctx->gpr[3] | 0x766Cu;

label_80112084:
    ctx->pc = 0x80112084u;
    // 80112084: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80112088:
    ctx->pc = 0x80112088u;
    // 80112088: bl      0x80252AF0
    {
            ctx->lr = 0x8011208Cu;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_8011208C:
    ctx->pc = 0x8011208Cu;
    ctx->downcount -= 5;
    // 8011208C: lis     r3, 26223
    ctx->gpr[3] = ((u32)(s32)(26223) << 16);

label_80112090:
    ctx->pc = 0x80112090u;
    // 80112090: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80112094:
    ctx->pc = 0x80112094u;
    // 80112094: ori     r3, r3, 0x6E74
    ctx->gpr[3] = ctx->gpr[3] | 0x6E74u;

label_80112098:
    ctx->pc = 0x80112098u;
    // 80112098: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8011209C:
    ctx->pc = 0x8011209Cu;
    // 8011209C: bl      0x80252AF0
    {
            ctx->lr = 0x801120A0u;
            ctx->pc = 0x80252AF0u;
            return;
    }

label_801120A0:
    ctx->pc = 0x801120A0u;
    ctx->downcount -= 8;
    // 801120A0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801120A4:
    ctx->pc = 0x801120A4u;
    // 801120A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801120A8:
    ctx->pc = 0x801120A8u;
    // 801120A8: addi    r4, r4, 5632
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5632);

label_801120AC:
    ctx->pc = 0x801120ACu;
    // 801120AC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801120B0:
    ctx->pc = 0x801120B0u;
    // 801120B0: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_801120B4:
    ctx->pc = 0x801120B4u;
    // 801120B4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801120B8:
    ctx->pc = 0x801120B8u;
    // 801120B8: addi    r3, r13, -27296
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27296);

label_801120BC:
    ctx->pc = 0x801120BCu;
    // 801120BC: bl      0x8027A270
    {
            ctx->lr = 0x801120C0u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_801120C0:
    ctx->pc = 0x801120C0u;
    ctx->downcount -= 8;
    // 801120C0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801120C4:
    ctx->pc = 0x801120C4u;
    // 801120C4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801120C8:
    ctx->pc = 0x801120C8u;
    // 801120C8: addi    r4, r4, 5652
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5652);

label_801120CC:
    ctx->pc = 0x801120CCu;
    // 801120CC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801120D0:
    ctx->pc = 0x801120D0u;
    // 801120D0: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_801120D4:
    ctx->pc = 0x801120D4u;
    // 801120D4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801120D8:
    ctx->pc = 0x801120D8u;
    // 801120D8: addi    r3, r13, -27292
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27292);

label_801120DC:
    ctx->pc = 0x801120DCu;
    // 801120DC: bl      0x8027A270
    {
            ctx->lr = 0x801120E0u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_801120E0:
    ctx->pc = 0x801120E0u;
    ctx->downcount -= 8;
    // 801120E0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801120E4:
    ctx->pc = 0x801120E4u;
    // 801120E4: addi    r3, r13, -27288
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27288);

label_801120E8:
    ctx->pc = 0x801120E8u;
    // 801120E8: addi    r4, r4, 5668
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5668);

label_801120EC:
    ctx->pc = 0x801120ECu;
    // 801120EC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801120F0:
    ctx->pc = 0x801120F0u;
    // 801120F0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801120F4:
    ctx->pc = 0x801120F4u;
    // 801120F4: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_801120F8:
    ctx->pc = 0x801120F8u;
    // 801120F8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801120FC:
    ctx->pc = 0x801120FCu;
    // 801120FC: bl      0x8027A270
    {
            ctx->lr = 0x80112100u;
            ctx->pc = 0x8027A270u;
            return;
    }

label_80112100:
    ctx->pc = 0x80112100u;
    ctx->downcount -= 5;
    // 80112100: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112104:
    ctx->pc = 0x80112104u;
    // 80112104: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112108:
    ctx->pc = 0x80112108u;
    // 80112108: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8011210C:
    ctx->pc = 0x8011210Cu;
    // 8011210C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112110:
    ctx->pc = 0x80112110u;
    ctx->downcount -= 18;
    // 80112110: stwu     r1, -152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-152);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80112114:
    ctx->pc = 0x80112114u;
    // 80112114: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80112118:
    ctx->pc = 0x80112118u;
    // 80112118: stw     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8011211C:
    ctx->pc = 0x8011211Cu;
    // 8011211C: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112120:
    ctx->pc = 0x80112120u;
    // 80112120: lis     r12, 512
    ctx->gpr[12] = ((u32)(s32)(512) << 16);

label_80112124:
    ctx->pc = 0x80112124u;
    // 80112124: addi    r0, r1, 160
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(160);

label_80112128:
    ctx->pc = 0x80112128u;
    // 80112128: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_8011212C:
    ctx->pc = 0x8011212Cu;
    // 8011212C: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112130:
    ctx->pc = 0x80112130u;
    // 80112130: stw     r11, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80112134:
    ctx->pc = 0x80112134u;
    // 80112134: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80112138:
    ctx->pc = 0x80112138u;
    // 80112138: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8011213C:
    ctx->pc = 0x8011213Cu;
    // 8011213C: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80112140:
    ctx->pc = 0x80112140u;
    // 80112140: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80112144:
    ctx->pc = 0x80112144u;
    // 80112144: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80112148:
    ctx->pc = 0x80112148u;
    // 80112148: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8011214C:
    ctx->pc = 0x8011214Cu;
    // 8011214C: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80112150:
    ctx->pc = 0x80112150u;
    // 80112150: stw     r12, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80112154:
    ctx->pc = 0x80112154u;
    // 80112154: bc    4, 6, 0x80112178
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80112178;
        }
    }

label_80112158:
    ctx->pc = 0x80112158u;
    ctx->downcount -= 8;
    // 80112158: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112158u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_8011215C:
    ctx->pc = 0x8011215Cu;
    // 8011215C: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011215Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_80112160:
    ctx->pc = 0x80112160u;
    // 80112160: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112160u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_80112164:
    ctx->pc = 0x80112164u;
    // 80112164: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112164u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_80112168:
    ctx->pc = 0x80112168u;
    // 80112168: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112168u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_8011216C:
    ctx->pc = 0x8011216Cu;
    // 8011216C: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011216Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_80112170:
    ctx->pc = 0x80112170u;
    // 80112170: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112170u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_80112174:
    ctx->pc = 0x80112174u;
    // 80112174: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112174u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_80112178:
    ctx->pc = 0x80112178u;
    ctx->downcount -= 12;
    // 80112178: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_8011217C:
    ctx->pc = 0x8011217Cu;
    // 8011217C: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_80112180:
    ctx->pc = 0x80112180u;
    // 80112180: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112184:
    ctx->pc = 0x80112184u;
    // 80112184: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80112188:
    ctx->pc = 0x80112188u;
    // 80112188: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8011218C:
    ctx->pc = 0x8011218Cu;
    // 8011218C: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80112190:
    ctx->pc = 0x80112190u;
    // 80112190: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80112194:
    ctx->pc = 0x80112194u;
    // 80112194: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80112198:
    ctx->pc = 0x80112198u;
    // 80112198: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8011219C:
    ctx->pc = 0x8011219Cu;
    // 8011219C: li      r4, 80
    ctx->gpr[4] = (u32)(s32)(80);

label_801121A0:
    ctx->pc = 0x801121A0u;
    // 801121A0: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801121A4:
    ctx->pc = 0x801121A4u;
    // 801121A4: bl      0x80296720
    {
            ctx->lr = 0x801121A8u;
            ctx->pc = 0x80296720u;
            return;
    }

label_801121A8:
    ctx->pc = 0x801121A8u;
    ctx->downcount -= 8;
    // 801121A8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801121AC:
    ctx->pc = 0x801121ACu;
    // 801121AC: stb     r0, 79(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(79);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801121B0:
    ctx->pc = 0x801121B0u;
    // 801121B0: lwz     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801121B4:
    ctx->pc = 0x801121B4u;
    // 801121B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801121B8:
    ctx->pc = 0x801121B8u;
    // 801121B8: lwz     r31, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801121BC:
    ctx->pc = 0x801121BCu;
    // 801121BC: addi    r1, r1, 152
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(152);

label_801121C0:
    ctx->pc = 0x801121C0u;
    // 801121C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_801121C4:
    ctx->pc = 0x801121C4u;
    ctx->downcount -= 7;
    // 801121C4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801121C8:
    ctx->pc = 0x801121C8u;
    // 801121C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801121CC:
    ctx->pc = 0x801121CCu;
    // 801121CC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801121D0:
    ctx->pc = 0x801121D0u;
    // 801121D0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801121D4:
    ctx->pc = 0x801121D4u;
    // 801121D4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801121D8:
    ctx->pc = 0x801121D8u;
    // 801121D8: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_801121DC:
    ctx->pc = 0x801121DCu;
    // 801121DC: bl      0x80111FB4
    {
            ctx->lr = 0x801121E0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80111FB4u;
                return;
            }
            goto label_80111FB4;
    }

label_801121E0:
    ctx->pc = 0x801121E0u;
    ctx->downcount -= 5;
    // 801121E0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801121E4:
    ctx->pc = 0x801121E4u;
    // 801121E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801121E8:
    ctx->pc = 0x801121E8u;
    // 801121E8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801121EC:
    ctx->pc = 0x801121ECu;
    // 801121EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_801121F0:
    ctx->pc = 0x801121F0u;
    ctx->downcount -= 32;
    // 801121F0: stwu     r1, -808(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-808);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801121F4:
    ctx->pc = 0x801121F4u;
    // 801121F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801121F8:
    ctx->pc = 0x801121F8u;
    // 801121F8: stfd     f28, 776(r1)
    if (!ppc_fp_available_inline(ctx, 0x801121F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(776);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[28]));
    }

label_801121FC:
    ctx->pc = 0x801121FCu;
    // 801121FC: stfd     f29, 784(r1)
    if (!ppc_fp_available_inline(ctx, 0x801121FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(784);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_80112200:
    ctx->pc = 0x80112200u;
    // 80112200: stfd     f30, 792(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112200u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(792);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80112204:
    ctx->pc = 0x80112204u;
    // 80112204: stfd     f31, 800(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112204u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(800);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80112208:
    ctx->pc = 0x80112208u;
    // 80112208: stmw     r16, 712(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(712);
        for (u32 r = 16; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8011220C:
    ctx->pc = 0x8011220Cu;
    // 8011220C: stw     r0, 812(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(812);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112210:
    ctx->pc = 0x80112210u;
    // 80112210: lwz     r26, -13528(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-13528);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_80112214:
    ctx->pc = 0x80112214u;
    // 80112214: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80112218:
    ctx->pc = 0x80112218u;
    // 80112218: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8011221C:
    ctx->pc = 0x8011221Cu;
    // 8011221C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112220:
    ctx->pc = 0x80112220u;
    // 80112220: addi    r9, r9, 8120
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8120);

label_80112224:
    ctx->pc = 0x80112224u;
    // 80112224: stw     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80112228:
    ctx->pc = 0x80112228u;
    // 80112228: stw     r26, 312(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_8011222C:
    ctx->pc = 0x8011222Cu;
    // 8011222C: addi    r3, r31, 328
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(328);

label_80112230:
    ctx->pc = 0x80112230u;
    // 80112230: stw     r30, 320(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(320);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80112234:
    ctx->pc = 0x80112234u;
    // 80112234: addi    r29, r31, 440
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(440);

label_80112238:
    ctx->pc = 0x80112238u;
    // 80112238: stw     r30, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8011223C:
    ctx->pc = 0x8011223Cu;
    // 8011223C: li      r28, 1
    ctx->gpr[28] = (u32)(s32)(1);

label_80112240:
    ctx->pc = 0x80112240u;
    // 80112240: stw     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80112244:
    ctx->pc = 0x80112244u;
    // 80112244: bl      0x802871CC
    {
            ctx->lr = 0x80112248u;
            ctx->pc = 0x802871CCu;
            return;
    }

label_80112248:
    ctx->pc = 0x80112248u;
    ctx->downcount -= 2;
    // 80112248: addi    r3, r31, 368
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(368);

label_8011224C:
    ctx->pc = 0x8011224Cu;
    // 8011224C: bl      0x801D334C
    {
            ctx->lr = 0x80112250u;
            ctx->pc = 0x801D334Cu;
            return;
    }

label_80112250:
    ctx->pc = 0x80112250u;
    ctx->downcount -= 13;
    // 80112250: stw     r30, 408(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(408);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80112254:
    ctx->pc = 0x80112254u;
    // 80112254: addi    r9, r31, 408
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(408);

label_80112258:
    ctx->pc = 0x80112258u;
    // 80112258: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8011225C:
    ctx->pc = 0x8011225Cu;
    // 8011225C: addi    r11, r31, 416
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(416);

label_80112260:
    ctx->pc = 0x80112260u;
    // 80112260: stw     r30, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80112264:
    ctx->pc = 0x80112264u;
    // 80112264: addi    r9, r31, 424
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(424);

label_80112268:
    ctx->pc = 0x80112268u;
    // 80112268: stw     r30, 424(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(424);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8011226C:
    ctx->pc = 0x8011226Cu;
    // 8011226C: addi    r11, r31, 432
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(432);

label_80112270:
    ctx->pc = 0x80112270u;
    // 80112270: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80112274:
    ctx->pc = 0x80112274u;
    // 80112274: li      r3, 12
    ctx->gpr[3] = (u32)(s32)(12);

label_80112278:
    ctx->pc = 0x80112278u;
    // 80112278: stw     r30, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8011227C:
    ctx->pc = 0x8011227Cu;
    // 8011227C: stw     r30, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80112280:
    ctx->pc = 0x80112280u;
    // 80112280: bl      0x80004024
    {
            ctx->lr = 0x80112284u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80112284:
    ctx->pc = 0x80112284u;
    ctx->downcount -= 30;
    // 80112284: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80112288:
    ctx->pc = 0x80112288u;
    // 80112288: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8011228C:
    ctx->pc = 0x8011228Cu;
    // 8011228C: stw     r11, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80112290:
    ctx->pc = 0x80112290u;
    // 80112290: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_80112294:
    ctx->pc = 0x80112294u;
    // 80112294: stw     r11, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80112298:
    ctx->pc = 0x80112298u;
    // 80112298: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8011229C:
    ctx->pc = 0x8011229Cu;
    // 8011229C: lfs     f31, 6476(r9)
    if (!ppc_fp_available_inline(ctx, 0x8011229Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_801122A0:
    ctx->pc = 0x801122A0u;
    // 801122A0: addi    r3, r31, 1200
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(1200);

label_801122A4:
    ctx->pc = 0x801122A4u;
    // 801122A4: stw     r11, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801122A8:
    ctx->pc = 0x801122A8u;
    // 801122A8: lfs     f0, 6472(r10)
    if (!ppc_fp_available_inline(ctx, 0x801122A8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6472);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801122AC:
    ctx->pc = 0x801122ACu;
    // 801122AC: stw     r28, 488(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_801122B0:
    ctx->pc = 0x801122B0u;
    // 801122B0: stw     r30, 448(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(448);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122B4:
    ctx->pc = 0x801122B4u;
    // 801122B4: stw     r30, 456(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(456);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122B8:
    ctx->pc = 0x801122B8u;
    // 801122B8: stw     r30, 460(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(460);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122BC:
    ctx->pc = 0x801122BCu;
    // 801122BC: stw     r30, 464(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(464);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122C0:
    ctx->pc = 0x801122C0u;
    // 801122C0: stw     r30, 468(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(468);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122C4:
    ctx->pc = 0x801122C4u;
    // 801122C4: stfs     f31, 496(r31)
    if (!ppc_fp_available_inline(ctx, 0x801122C4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(496);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801122C8:
    ctx->pc = 0x801122C8u;
    // 801122C8: stw     r26, 500(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(500);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801122CC:
    ctx->pc = 0x801122CCu;
    // 801122CC: stw     r26, 504(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801122D0:
    ctx->pc = 0x801122D0u;
    // 801122D0: stw     r26, 508(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801122D4:
    ctx->pc = 0x801122D4u;
    // 801122D4: stw     r26, 512(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(512);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_801122D8:
    ctx->pc = 0x801122D8u;
    // 801122D8: stw     r30, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122DC:
    ctx->pc = 0x801122DCu;
    // 801122DC: stw     r30, 664(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(664);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122E0:
    ctx->pc = 0x801122E0u;
    // 801122E0: stw     r30, 668(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(668);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122E4:
    ctx->pc = 0x801122E4u;
    // 801122E4: stw     r30, 672(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(672);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801122E8:
    ctx->pc = 0x801122E8u;
    // 801122E8: stb     r30, 676(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(676);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_801122EC:
    ctx->pc = 0x801122ECu;
    // 801122EC: stb     r30, 936(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(936);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_801122F0:
    ctx->pc = 0x801122F0u;
    // 801122F0: stfs     f0, 452(r31)
    if (!ppc_fp_available_inline(ctx, 0x801122F0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(452);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801122F4:
    ctx->pc = 0x801122F4u;
    // 801122F4: stw     r0, 516(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(516);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801122F8:
    ctx->pc = 0x801122F8u;
    // 801122F8: bl      0x800DEC54
    {
            ctx->lr = 0x801122FCu;
            ctx->pc = 0x800DEC54u;
            return;
    }

label_801122FC:
    ctx->pc = 0x801122FCu;
    ctx->downcount -= 8;
    // 801122FC: stw     r30, 656(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(656);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80112300:
    ctx->pc = 0x80112300u;
    // 80112300: addi    r3, r13, -27416
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27416);

label_80112304:
    ctx->pc = 0x80112304u;
    // 80112304: lis     r25, -32721
    ctx->gpr[25] = ((u32)(s32)(-32721) << 16);

label_80112308:
    ctx->pc = 0x80112308u;
    // 80112308: stw     r30, 660(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(660);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8011230C:
    ctx->pc = 0x8011230Cu;
    // 8011230C: addi    r29, r1, 56
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(56);

label_80112310:
    ctx->pc = 0x80112310u;
    // 80112310: addi    r28, r1, 64
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(64);

label_80112314:
    ctx->pc = 0x80112314u;
    // 80112314: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80112314u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80112318:
    ctx->pc = 0x80112318u;
    // 80112318: bl      0x801DBF68
    {
            ctx->lr = 0x8011231Cu;
            ctx->pc = 0x801DBF68u;
            return;
    }

label_8011231C:
    ctx->pc = 0x8011231Cu;
    ctx->downcount -= 6;
    // 8011231C: or   r22, r29, r29
    {
        ctx->gpr[22] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80112320:
    ctx->pc = 0x80112320u;
    // 80112320: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80112324:
    ctx->pc = 0x80112324u;
    // 80112324: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80112328:
    ctx->pc = 0x80112328u;
    // 80112328: addi    r3, r3, 5728
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5728);

label_8011232C:
    ctx->pc = 0x8011232Cu;
    // 8011232C: or   r24, r28, r28
    {
        ctx->gpr[24] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80112330:
    ctx->pc = 0x80112330u;
    // 80112330: bl      0x801037A4
    {
            ctx->lr = 0x80112334u;
            ctx->pc = 0x801037A4u;
            return;
    }

label_80112334:
    ctx->pc = 0x80112334u;
    ctx->downcount -= 5;
    // 80112334: lis     r23, -32721
    ctx->gpr[23] = ((u32)(s32)(-32721) << 16);

label_80112338:
    ctx->pc = 0x80112338u;
    // 80112338: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8011233C:
    ctx->pc = 0x8011233Cu;
    // 8011233C: addi    r17, r1, 336
    ctx->gpr[17] = ctx->gpr[1] + (u32)(s32)(336);

label_80112340:
    ctx->pc = 0x80112340u;
    // 80112340: li      r3, 132
    ctx->gpr[3] = (u32)(s32)(132);

label_80112344:
    ctx->pc = 0x80112344u;
    // 80112344: bl      0x80281C60
    {
            ctx->lr = 0x80112348u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80112348:
    ctx->pc = 0x80112348u;
    ctx->downcount -= 29;
    // 80112348: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_8011234C:
    ctx->pc = 0x8011234Cu;
    // 8011234C: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80112350:
    ctx->pc = 0x80112350u;
    // 80112350: lfs     f0, 6480(r9)
    if (!ppc_fp_available_inline(ctx, 0x80112350u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6480);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80112354:
    ctx->pc = 0x80112354u;
    // 80112354: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_80112358:
    ctx->pc = 0x80112358u;
    // 80112358: lfs     f13, 6484(r11)
    if (!ppc_fp_available_inline(ctx, 0x80112358u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(6484);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8011235C:
    ctx->pc = 0x8011235Cu;
    // 8011235C: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112360:
    ctx->pc = 0x80112360u;
    // 80112360: stfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112360u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80112364:
    ctx->pc = 0x80112364u;
    // 80112364: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_80112368:
    ctx->pc = 0x80112368u;
    // 80112368: lfs     f0, 6488(r10)
    if (!ppc_fp_available_inline(ctx, 0x80112368u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6488);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8011236C:
    ctx->pc = 0x8011236Cu;
    // 8011236C: li      r11, 5
    ctx->gpr[11] = (u32)(s32)(5);

label_80112370:
    ctx->pc = 0x80112370u;
    // 80112370: lfs     f2, 6496(r9)
    if (!ppc_fp_available_inline(ctx, 0x80112370u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6496);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80112374:
    ctx->pc = 0x80112374u;
    // 80112374: lis     r8, -32721
    ctx->gpr[8] = ((u32)(s32)(-32721) << 16);

label_80112378:
    ctx->pc = 0x80112378u;
    // 80112378: stfs     f13, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x80112378u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8011237C:
    ctx->pc = 0x8011237Cu;
    // 8011237C: li      r9, 180
    ctx->gpr[9] = (u32)(s32)(180);

label_80112380:
    ctx->pc = 0x80112380u;
    // 80112380: stfs     f0, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112380u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80112384:
    ctx->pc = 0x80112384u;
    // 80112384: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80112388:
    ctx->pc = 0x80112388u;
    // 80112388: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8011238C:
    ctx->pc = 0x8011238Cu;
    // 8011238C: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_80112390:
    ctx->pc = 0x80112390u;
    // 80112390: stw     r11, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80112394:
    ctx->pc = 0x80112394u;
    // 80112394: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80112398:
    ctx->pc = 0x80112398u;
    // 80112398: stw     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8011239C:
    ctx->pc = 0x8011239Cu;
    // 8011239C: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_801123A0:
    ctx->pc = 0x801123A0u;
    // 801123A0: stw     r30, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801123A4:
    ctx->pc = 0x801123A4u;
    // 801123A4: or   r9, r28, r28
    {
        ctx->gpr[9] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801123A8:
    ctx->pc = 0x801123A8u;
    // 801123A8: lfs     f1, 6492(r8)
    if (!ppc_fp_available_inline(ctx, 0x801123A8u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(6492);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801123AC:
    ctx->pc = 0x801123ACu;
    // 801123AC: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_801123B0:
    ctx->pc = 0x801123B0u;
    // 801123B0: stfs     f0, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x801123B0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801123B4:
    ctx->pc = 0x801123B4u;
    // 801123B4: or   r8, r29, r29
    {
        ctx->gpr[8] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801123B8:
    ctx->pc = 0x801123B8u;
    // 801123B8: bl      0x800EC45C
    {
            ctx->lr = 0x801123BCu;
            ctx->pc = 0x800EC45Cu;
            return;
    }

label_801123BC:
    ctx->pc = 0x801123BCu;
    ctx->downcount -= 26;
    // 801123BC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801123C0:
    ctx->pc = 0x801123C0u;
    // 801123C0: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801123C4:
    ctx->pc = 0x801123C4u;
    // 801123C4: lfs     f30, 6500(r9)
    if (!ppc_fp_available_inline(ctx, 0x801123C4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6500);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_801123C8:
    ctx->pc = 0x801123C8u;
    // 801123C8: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_801123CC:
    ctx->pc = 0x801123CCu;
    // 801123CC: lfs     f31, 6504(r11)
    if (!ppc_fp_available_inline(ctx, 0x801123CCu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(6504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_801123D0:
    ctx->pc = 0x801123D0u;
    // 801123D0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801123D4:
    ctx->pc = 0x801123D4u;
    // 801123D4: stfs     f30, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x801123D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_801123D8:
    ctx->pc = 0x801123D8u;
    // 801123D8: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_801123DC:
    ctx->pc = 0x801123DCu;
    // 801123DC: lfs     f29, 6508(r10)
    if (!ppc_fp_available_inline(ctx, 0x801123DCu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6508);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[29] = value;
        ctx->ps1[29] = value;
    }

label_801123E0:
    ctx->pc = 0x801123E0u;
    // 801123E0: addi    r30, r30, -19596
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-19596);

label_801123E4:
    ctx->pc = 0x801123E4u;
    // 801123E4: stfs     f31, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x801123E4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801123E8:
    ctx->pc = 0x801123E8u;
    // 801123E8: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801123EC:
    ctx->pc = 0x801123ECu;
    // 801123EC: lfs     f28, 6512(r9)
    if (!ppc_fp_available_inline(ctx, 0x801123ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6512);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[28] = value;
        ctx->ps1[28] = value;
    }

label_801123F0:
    ctx->pc = 0x801123F0u;
    // 801123F0: addi    r4, r4, 5760
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5760);

label_801123F4:
    ctx->pc = 0x801123F4u;
    // 801123F4: stw     r3, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801123F8:
    ctx->pc = 0x801123F8u;
    // 801123F8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801123FC:
    ctx->pc = 0x801123FCu;
    // 801123FC: stfs     f29, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x801123FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112400:
    ctx->pc = 0x80112400u;
    // 80112400: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80112404:
    ctx->pc = 0x80112404u;
    // 80112404: lfs     f1, 6516(r25)
    if (!ppc_fp_available_inline(ctx, 0x80112404u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112408:
    ctx->pc = 0x80112408u;
    // 80112408: or   r7, r28, r28
    {
        ctx->gpr[7] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8011240C:
    ctx->pc = 0x8011240Cu;
    // 8011240C: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112410:
    ctx->pc = 0x80112410u;
    // 80112410: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80112414:
    ctx->pc = 0x80112414u;
    // 80112414: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112418:
    ctx->pc = 0x80112418u;
    // 80112418: stfs     f28, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x80112418u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_8011241C:
    ctx->pc = 0x8011241Cu;
    // 8011241C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112420:
    ctx->pc = 0x80112420u;
    // 80112420: bl      0x801A7DA0
    {
            ctx->lr = 0x80112424u;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_80112424:
    ctx->pc = 0x80112424u;
    ctx->downcount -= 16;
    // 80112424: stfs     f30, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112424u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112428:
    ctx->pc = 0x80112428u;
    // 80112428: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8011242C:
    ctx->pc = 0x8011242Cu;
    // 8011242C: stfs     f31, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x8011242Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112430:
    ctx->pc = 0x80112430u;
    // 80112430: addi    r4, r4, 5788
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5788);

label_80112434:
    ctx->pc = 0x80112434u;
    // 80112434: stw     r3, 500(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(500);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112438:
    ctx->pc = 0x80112438u;
    // 80112438: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8011243C:
    ctx->pc = 0x8011243Cu;
    // 8011243C: stfs     f29, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011243Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112440:
    ctx->pc = 0x80112440u;
    // 80112440: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112444:
    ctx->pc = 0x80112444u;
    // 80112444: lfs     f1, 6516(r25)
    if (!ppc_fp_available_inline(ctx, 0x80112444u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112448:
    ctx->pc = 0x80112448u;
    // 80112448: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8011244C:
    ctx->pc = 0x8011244Cu;
    // 8011244C: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80112450:
    ctx->pc = 0x80112450u;
    // 80112450: or   r7, r28, r28
    {
        ctx->gpr[7] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80112454:
    ctx->pc = 0x80112454u;
    // 80112454: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112458:
    ctx->pc = 0x80112458u;
    // 80112458: stfs     f28, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x80112458u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_8011245C:
    ctx->pc = 0x8011245Cu;
    // 8011245C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112460:
    ctx->pc = 0x80112460u;
    // 80112460: bl      0x801A7DA0
    {
            ctx->lr = 0x80112464u;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_80112464:
    ctx->pc = 0x80112464u;
    ctx->downcount -= 22;
    // 80112464: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112468:
    ctx->pc = 0x80112468u;
    // 80112468: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_8011246C:
    ctx->pc = 0x8011246Cu;
    // 8011246C: lfs     f0, 6520(r9)
    if (!ppc_fp_available_inline(ctx, 0x8011246Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80112470:
    ctx->pc = 0x80112470u;
    // 80112470: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_80112474:
    ctx->pc = 0x80112474u;
    // 80112474: lfs     f13, 6524(r11)
    if (!ppc_fp_available_inline(ctx, 0x80112474u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(6524);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80112478:
    ctx->pc = 0x80112478u;
    // 80112478: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8011247C:
    ctx->pc = 0x8011247Cu;
    // 8011247C: stfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011247Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80112480:
    ctx->pc = 0x80112480u;
    // 80112480: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80112484:
    ctx->pc = 0x80112484u;
    // 80112484: stfs     f31, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x80112484u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112488:
    ctx->pc = 0x80112488u;
    // 80112488: addi    r4, r4, 5820
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5820);

label_8011248C:
    ctx->pc = 0x8011248Cu;
    // 8011248C: stw     r3, 504(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112490:
    ctx->pc = 0x80112490u;
    // 80112490: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80112494:
    ctx->pc = 0x80112494u;
    // 80112494: lfs     f0, 6528(r10)
    if (!ppc_fp_available_inline(ctx, 0x80112494u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6528);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80112498:
    ctx->pc = 0x80112498u;
    // 80112498: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8011249C:
    ctx->pc = 0x8011249Cu;
    // 8011249C: stfs     f13, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8011249Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801124A0:
    ctx->pc = 0x801124A0u;
    // 801124A0: or   r7, r28, r28
    {
        ctx->gpr[7] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801124A4:
    ctx->pc = 0x801124A4u;
    // 801124A4: lfs     f1, 6516(r25)
    if (!ppc_fp_available_inline(ctx, 0x801124A4u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801124A8:
    ctx->pc = 0x801124A8u;
    // 801124A8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801124AC:
    ctx->pc = 0x801124ACu;
    // 801124AC: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_801124B0:
    ctx->pc = 0x801124B0u;
    // 801124B0: stfs     f0, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x801124B0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801124B4:
    ctx->pc = 0x801124B4u;
    // 801124B4: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801124B8:
    ctx->pc = 0x801124B8u;
    // 801124B8: bl      0x801A7DA0
    {
            ctx->lr = 0x801124BCu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_801124BC:
    ctx->pc = 0x801124BCu;
    ctx->downcount -= 5;
    // 801124BC: li      r0, 25
    ctx->gpr[0] = (u32)(s32)(25);

label_801124C0:
    ctx->pc = 0x801124C0u;
    // 801124C0: stw     r3, 512(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(512);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801124C4:
    ctx->pc = 0x801124C4u;
    // 801124C4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_801124C8:
    ctx->pc = 0x801124C8u;
    // 801124C8: addi    r9, r31, 308
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(308);

label_801124CC:
    loop_801124CC(ctx);
    if (ctx->pc == 0x801124D8u) goto label_801124D8;
    return;
label_801124D0:
    // 801124D0: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_801124D4:
    // 801124D4: bc    16, 0, 0x801124CC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801124CCu;
                return;
            }
            goto label_801124CC;
        }
    }

label_801124D8:
    ctx->pc = 0x801124D8u;
    ctx->downcount -= 27;
    // 801124D8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801124DC:
    ctx->pc = 0x801124DCu;
    // 801124DC: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801124E0:
    ctx->pc = 0x801124E0u;
    // 801124E0: lfs     f28, 6500(r9)
    if (!ppc_fp_available_inline(ctx, 0x801124E0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6500);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[28] = value;
        ctx->ps1[28] = value;
    }

label_801124E4:
    ctx->pc = 0x801124E4u;
    // 801124E4: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_801124E8:
    ctx->pc = 0x801124E8u;
    // 801124E8: lfs     f31, 6504(r11)
    if (!ppc_fp_available_inline(ctx, 0x801124E8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(6504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_801124EC:
    ctx->pc = 0x801124ECu;
    // 801124EC: lis     r8, -32721
    ctx->gpr[8] = ((u32)(s32)(-32721) << 16);

label_801124F0:
    ctx->pc = 0x801124F0u;
    // 801124F0: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x801124F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_801124F4:
    ctx->pc = 0x801124F4u;
    // 801124F4: lis     r29, -32721
    ctx->gpr[29] = ((u32)(s32)(-32721) << 16);

label_801124F8:
    ctx->pc = 0x801124F8u;
    // 801124F8: lfs     f30, 6508(r10)
    if (!ppc_fp_available_inline(ctx, 0x801124F8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6508);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_801124FC:
    ctx->pc = 0x801124FCu;
    // 801124FC: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80112500:
    ctx->pc = 0x80112500u;
    // 80112500: lfs     f29, 6512(r8)
    if (!ppc_fp_available_inline(ctx, 0x80112500u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(6512);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[29] = value;
        ctx->ps1[29] = value;
    }

label_80112504:
    ctx->pc = 0x80112504u;
    // 80112504: addi    r30, r30, -19596
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-19596);

label_80112508:
    ctx->pc = 0x80112508u;
    // 80112508: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x80112508u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8011250C:
    ctx->pc = 0x8011250Cu;
    // 8011250C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80112510:
    ctx->pc = 0x80112510u;
    // 80112510: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112510u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112514:
    ctx->pc = 0x80112514u;
    // 80112514: addi    r4, r4, 5856
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5856);

label_80112518:
    ctx->pc = 0x80112518u;
    // 80112518: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x80112518u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8011251C:
    ctx->pc = 0x8011251Cu;
    // 8011251C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80112520:
    ctx->pc = 0x80112520u;
    // 80112520: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80112524:
    ctx->pc = 0x80112524u;
    // 80112524: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112528:
    ctx->pc = 0x80112528u;
    // 80112528: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_8011252C:
    ctx->pc = 0x8011252Cu;
    // 8011252C: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80112530:
    ctx->pc = 0x80112530u;
    // 80112530: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112534:
    ctx->pc = 0x80112534u;
    // 80112534: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112538:
    ctx->pc = 0x80112538u;
    // 80112538: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112538u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_8011253C:
    ctx->pc = 0x8011253Cu;
    // 8011253C: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80112540:
    ctx->pc = 0x80112540u;
    // 80112540: bl      0x801A7DA0
    {
            ctx->lr = 0x80112544u;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_80112544:
    ctx->pc = 0x80112544u;
    ctx->downcount -= 18;
    // 80112544: addi    r19, r31, 1200
    ctx->gpr[19] = ctx->gpr[31] + (u32)(s32)(1200);

label_80112548:
    ctx->pc = 0x80112548u;
    // 80112548: stw     r3, 276(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(276);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8011254C:
    ctx->pc = 0x8011254Cu;
    // 8011254C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80112550:
    ctx->pc = 0x80112550u;
    // 80112550: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112550u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_80112554:
    ctx->pc = 0x80112554u;
    // 80112554: addi    r4, r4, 5904
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5904);

label_80112558:
    ctx->pc = 0x80112558u;
    // 80112558: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x80112558u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8011255C:
    ctx->pc = 0x8011255Cu;
    // 8011255C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80112560:
    ctx->pc = 0x80112560u;
    // 80112560: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112560u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112564:
    ctx->pc = 0x80112564u;
    // 80112564: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80112568:
    ctx->pc = 0x80112568u;
    // 80112568: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x80112568u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8011256C:
    ctx->pc = 0x8011256Cu;
    // 8011256C: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112570:
    ctx->pc = 0x80112570u;
    // 80112570: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112574:
    ctx->pc = 0x80112574u;
    // 80112574: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80112578:
    ctx->pc = 0x80112578u;
    // 80112578: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8011257C:
    ctx->pc = 0x8011257Cu;
    // 8011257C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112580:
    ctx->pc = 0x80112580u;
    // 80112580: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112580u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112584:
    ctx->pc = 0x80112584u;
    // 80112584: addi    r18, r31, 16
    ctx->gpr[18] = ctx->gpr[31] + (u32)(s32)(16);

label_80112588:
    ctx->pc = 0x80112588u;
    // 80112588: bl      0x801A7DA0
    {
            ctx->lr = 0x8011258Cu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_8011258C:
    ctx->pc = 0x8011258Cu;
    ctx->downcount -= 18;
    // 8011258C: addi    r16, r31, 1212
    ctx->gpr[16] = ctx->gpr[31] + (u32)(s32)(1212);

label_80112590:
    ctx->pc = 0x80112590u;
    // 80112590: stw     r3, 280(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(280);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112594:
    ctx->pc = 0x80112594u;
    // 80112594: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80112598:
    ctx->pc = 0x80112598u;
    // 80112598: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112598u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_8011259C:
    ctx->pc = 0x8011259Cu;
    // 8011259C: addi    r4, r4, 5948
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5948);

label_801125A0:
    ctx->pc = 0x801125A0u;
    // 801125A0: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x801125A0u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801125A4:
    ctx->pc = 0x801125A4u;
    // 801125A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801125A8:
    ctx->pc = 0x801125A8u;
    // 801125A8: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x801125A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_801125AC:
    ctx->pc = 0x801125ACu;
    // 801125AC: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_801125B0:
    ctx->pc = 0x801125B0u;
    // 801125B0: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x801125B0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801125B4:
    ctx->pc = 0x801125B4u;
    // 801125B4: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801125B8:
    ctx->pc = 0x801125B8u;
    // 801125B8: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_801125BC:
    ctx->pc = 0x801125BCu;
    // 801125BC: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801125C0:
    ctx->pc = 0x801125C0u;
    // 801125C0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801125C4:
    ctx->pc = 0x801125C4u;
    // 801125C4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801125C8:
    ctx->pc = 0x801125C8u;
    // 801125C8: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x801125C8u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_801125CC:
    ctx->pc = 0x801125CCu;
    // 801125CC: or   r26, r17, r17
    {
        ctx->gpr[26] = ctx->gpr[17] | ctx->gpr[17];
    }

label_801125D0:
    ctx->pc = 0x801125D0u;
    // 801125D0: bl      0x801A7DA0
    {
            ctx->lr = 0x801125D4u;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_801125D4:
    ctx->pc = 0x801125D4u;
    ctx->downcount -= 18;
    // 801125D4: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_801125D8:
    ctx->pc = 0x801125D8u;
    // 801125D8: stw     r3, 284(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801125DC:
    ctx->pc = 0x801125DCu;
    // 801125DC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801125E0:
    ctx->pc = 0x801125E0u;
    // 801125E0: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x801125E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_801125E4:
    ctx->pc = 0x801125E4u;
    // 801125E4: addi    r4, r4, 5988
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5988);

label_801125E8:
    ctx->pc = 0x801125E8u;
    // 801125E8: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x801125E8u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801125EC:
    ctx->pc = 0x801125ECu;
    // 801125EC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801125F0:
    ctx->pc = 0x801125F0u;
    // 801125F0: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x801125F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_801125F4:
    ctx->pc = 0x801125F4u;
    // 801125F4: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_801125F8:
    ctx->pc = 0x801125F8u;
    // 801125F8: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x801125F8u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801125FC:
    ctx->pc = 0x801125FCu;
    // 801125FC: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112600:
    ctx->pc = 0x80112600u;
    // 80112600: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112604:
    ctx->pc = 0x80112604u;
    // 80112604: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80112608:
    ctx->pc = 0x80112608u;
    // 80112608: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8011260C:
    ctx->pc = 0x8011260Cu;
    // 8011260C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112610:
    ctx->pc = 0x80112610u;
    // 80112610: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112610u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112614:
    ctx->pc = 0x80112614u;
    // 80112614: addi    r28, r31, 380
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(380);

label_80112618:
    ctx->pc = 0x80112618u;
    // 80112618: bl      0x801A7DA0
    {
            ctx->lr = 0x8011261Cu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_8011261C:
    ctx->pc = 0x8011261Cu;
    ctx->downcount -= 16;
    // 8011261C: stw     r3, 288(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(288);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112620:
    ctx->pc = 0x80112620u;
    // 80112620: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80112624:
    ctx->pc = 0x80112624u;
    // 80112624: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112624u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_80112628:
    ctx->pc = 0x80112628u;
    // 80112628: addi    r4, r4, 6036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6036);

label_8011262C:
    ctx->pc = 0x8011262Cu;
    // 8011262C: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x8011262Cu)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112630:
    ctx->pc = 0x80112630u;
    // 80112630: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80112634:
    ctx->pc = 0x80112634u;
    // 80112634: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112634u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112638:
    ctx->pc = 0x80112638u;
    // 80112638: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_8011263C:
    ctx->pc = 0x8011263Cu;
    // 8011263C: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x8011263Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112640:
    ctx->pc = 0x80112640u;
    // 80112640: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112644:
    ctx->pc = 0x80112644u;
    // 80112644: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112648:
    ctx->pc = 0x80112648u;
    // 80112648: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8011264C:
    ctx->pc = 0x8011264Cu;
    // 8011264C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112650:
    ctx->pc = 0x80112650u;
    // 80112650: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112654:
    ctx->pc = 0x80112654u;
    // 80112654: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112654u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112658:
    ctx->pc = 0x80112658u;
    // 80112658: bl      0x801A7DA0
    {
            ctx->lr = 0x8011265Cu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_8011265C:
    ctx->pc = 0x8011265Cu;
    ctx->downcount -= 16;
    // 8011265C: stw     r3, 292(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(292);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112660:
    ctx->pc = 0x80112660u;
    // 80112660: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80112664:
    ctx->pc = 0x80112664u;
    // 80112664: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112664u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_80112668:
    ctx->pc = 0x80112668u;
    // 80112668: addi    r4, r4, 6076
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6076);

label_8011266C:
    ctx->pc = 0x8011266Cu;
    // 8011266C: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x8011266Cu)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112670:
    ctx->pc = 0x80112670u;
    // 80112670: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80112674:
    ctx->pc = 0x80112674u;
    // 80112674: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112674u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112678:
    ctx->pc = 0x80112678u;
    // 80112678: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_8011267C:
    ctx->pc = 0x8011267Cu;
    // 8011267C: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x8011267Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112680:
    ctx->pc = 0x80112680u;
    // 80112680: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112684:
    ctx->pc = 0x80112684u;
    // 80112684: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112688:
    ctx->pc = 0x80112688u;
    // 80112688: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8011268C:
    ctx->pc = 0x8011268Cu;
    // 8011268C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112690:
    ctx->pc = 0x80112690u;
    // 80112690: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112694:
    ctx->pc = 0x80112694u;
    // 80112694: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112694u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112698:
    ctx->pc = 0x80112698u;
    // 80112698: bl      0x801A7DA0
    {
            ctx->lr = 0x8011269Cu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_8011269C:
    ctx->pc = 0x8011269Cu;
    ctx->downcount -= 16;
    // 8011269C: stw     r3, 296(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(296);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801126A0:
    ctx->pc = 0x801126A0u;
    // 801126A0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801126A4:
    ctx->pc = 0x801126A4u;
    // 801126A4: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x801126A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_801126A8:
    ctx->pc = 0x801126A8u;
    // 801126A8: addi    r4, r4, 6120
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6120);

label_801126AC:
    ctx->pc = 0x801126ACu;
    // 801126AC: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x801126ACu)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801126B0:
    ctx->pc = 0x801126B0u;
    // 801126B0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801126B4:
    ctx->pc = 0x801126B4u;
    // 801126B4: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x801126B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_801126B8:
    ctx->pc = 0x801126B8u;
    // 801126B8: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_801126BC:
    ctx->pc = 0x801126BCu;
    // 801126BC: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x801126BCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801126C0:
    ctx->pc = 0x801126C0u;
    // 801126C0: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801126C4:
    ctx->pc = 0x801126C4u;
    // 801126C4: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_801126C8:
    ctx->pc = 0x801126C8u;
    // 801126C8: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801126CC:
    ctx->pc = 0x801126CCu;
    // 801126CC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801126D0:
    ctx->pc = 0x801126D0u;
    // 801126D0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801126D4:
    ctx->pc = 0x801126D4u;
    // 801126D4: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x801126D4u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_801126D8:
    ctx->pc = 0x801126D8u;
    // 801126D8: bl      0x801A7DA0
    {
            ctx->lr = 0x801126DCu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_801126DC:
    ctx->pc = 0x801126DCu;
    ctx->downcount -= 16;
    // 801126DC: stw     r3, 300(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(300);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801126E0:
    ctx->pc = 0x801126E0u;
    // 801126E0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801126E4:
    ctx->pc = 0x801126E4u;
    // 801126E4: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x801126E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_801126E8:
    ctx->pc = 0x801126E8u;
    // 801126E8: addi    r4, r4, 6168
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6168);

label_801126EC:
    ctx->pc = 0x801126ECu;
    // 801126EC: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x801126ECu)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_801126F0:
    ctx->pc = 0x801126F0u;
    // 801126F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801126F4:
    ctx->pc = 0x801126F4u;
    // 801126F4: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x801126F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_801126F8:
    ctx->pc = 0x801126F8u;
    // 801126F8: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_801126FC:
    ctx->pc = 0x801126FCu;
    // 801126FC: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x801126FCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112700:
    ctx->pc = 0x80112700u;
    // 80112700: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112704:
    ctx->pc = 0x80112704u;
    // 80112704: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112708:
    ctx->pc = 0x80112708u;
    // 80112708: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8011270C:
    ctx->pc = 0x8011270Cu;
    // 8011270C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112710:
    ctx->pc = 0x80112710u;
    // 80112710: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112714:
    ctx->pc = 0x80112714u;
    // 80112714: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112714u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112718:
    ctx->pc = 0x80112718u;
    // 80112718: bl      0x801A7DA0
    {
            ctx->lr = 0x8011271Cu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_8011271C:
    ctx->pc = 0x8011271Cu;
    ctx->downcount -= 16;
    // 8011271C: stw     r3, 304(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(304);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112720:
    ctx->pc = 0x80112720u;
    // 80112720: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80112724:
    ctx->pc = 0x80112724u;
    // 80112724: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112724u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_80112728:
    ctx->pc = 0x80112728u;
    // 80112728: addi    r4, r4, 6208
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6208);

label_8011272C:
    ctx->pc = 0x8011272Cu;
    // 8011272C: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x8011272Cu)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112730:
    ctx->pc = 0x80112730u;
    // 80112730: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80112734:
    ctx->pc = 0x80112734u;
    // 80112734: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112734u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112738:
    ctx->pc = 0x80112738u;
    // 80112738: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_8011273C:
    ctx->pc = 0x8011273Cu;
    // 8011273C: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x8011273Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112740:
    ctx->pc = 0x80112740u;
    // 80112740: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112744:
    ctx->pc = 0x80112744u;
    // 80112744: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112748:
    ctx->pc = 0x80112748u;
    // 80112748: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8011274C:
    ctx->pc = 0x8011274Cu;
    // 8011274C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112750:
    ctx->pc = 0x80112750u;
    // 80112750: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112754:
    ctx->pc = 0x80112754u;
    // 80112754: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112754u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112758:
    ctx->pc = 0x80112758u;
    // 80112758: bl      0x801A7DA0
    {
            ctx->lr = 0x8011275Cu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_8011275C:
    ctx->pc = 0x8011275Cu;
    ctx->downcount -= 16;
    // 8011275C: stw     r3, 308(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(308);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112760:
    ctx->pc = 0x80112760u;
    // 80112760: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80112764:
    ctx->pc = 0x80112764u;
    // 80112764: stfs     f28, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112764u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[28]));
    }

label_80112768:
    ctx->pc = 0x80112768u;
    // 80112768: addi    r4, r4, 6256
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6256);

label_8011276C:
    ctx->pc = 0x8011276Cu;
    // 8011276C: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x8011276Cu)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112770:
    ctx->pc = 0x80112770u;
    // 80112770: or   r7, r24, r24
    {
        ctx->gpr[7] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112774:
    ctx->pc = 0x80112774u;
    // 80112774: stfs     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112774u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112778:
    ctx->pc = 0x80112778u;
    // 80112778: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8011277C:
    ctx->pc = 0x8011277Cu;
    // 8011277C: lfs     f1, 6516(r29)
    if (!ppc_fp_available_inline(ctx, 0x8011277Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112780:
    ctx->pc = 0x80112780u;
    // 80112780: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80112784:
    ctx->pc = 0x80112784u;
    // 80112784: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_80112788:
    ctx->pc = 0x80112788u;
    // 80112788: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8011278C:
    ctx->pc = 0x8011278Cu;
    // 8011278C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112790:
    ctx->pc = 0x80112790u;
    // 80112790: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112794:
    ctx->pc = 0x80112794u;
    // 80112794: stfs     f29, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112794u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_80112798:
    ctx->pc = 0x80112798u;
    // 80112798: bl      0x801A7DA0
    {
            ctx->lr = 0x8011279Cu;
            ctx->pc = 0x801A7DA0u;
            return;
    }

label_8011279C:
    ctx->pc = 0x8011279Cu;
    ctx->downcount -= 4;
    // 8011279C: stw     r3, 316(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(316);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801127A0:
    ctx->pc = 0x801127A0u;
    // 801127A0: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_801127A4:
    ctx->pc = 0x801127A4u;
    // 801127A4: addi    r3, r3, -21492
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-21492);

label_801127A8:
    ctx->pc = 0x801127A8u;
    // 801127A8: bl      0x801000DC
    {
            ctx->lr = 0x801127ACu;
            ctx->pc = 0x801000DCu;
            return;
    }

label_801127AC:
    ctx->pc = 0x801127ACu;
    ctx->downcount -= 2;
    // 801127AC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801127B0:
    ctx->pc = 0x801127B0u;
    // 801127B0: stb     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801127B4:
    ctx->pc = 0x801127B4u;
    ctx->downcount -= 3;
    // 801127B4: stb     r25, 336(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(336);
        mem_write8(ctx, ea, (u8)ctx->gpr[25]);
    }

label_801127B8:
    // 801127B8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801127BC:
    // 801127BC: bl      0x8008F238
    {
            ctx->lr = 0x801127C0u;
            ctx->pc = 0x8008F238u;
            return;
    }

label_801127C0:
    ctx->downcount -= 5;
    // 801127C0: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801127C4:
    // 801127C4: addi    r4, r23, 6296
    ctx->gpr[4] = ctx->gpr[23] + (u32)(s32)(6296);

label_801127C8:
    // 801127C8: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801127CC:
    // 801127CC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801127D0:
    // 801127D0: bl      0x800E48B0
    {
            ctx->lr = 0x801127D4u;
            ctx->pc = 0x800E48B0u;
            return;
    }

label_801127D4:
    ctx->downcount -= 3;
    // 801127D4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801127D8:
    // 801127D8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801127DC:
    // 801127DC: bl      0x80098CD0
    {
            ctx->lr = 0x801127E0u;
            ctx->pc = 0x80098CD0u;
            return;
    }

label_801127E0:
    ctx->pc = 0x801127E0u;
    ctx->downcount -= 5;
    // 801127E0: stw     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801127E4:
    // 801127E4: cmpwi   r27, 6
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801127E8:
    // 801127E8: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_801127EC:
    // 801127EC: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_801127F0:
    // 801127F0: bc    4, 2, 0x801127B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801127B4u;
                return;
            }
            goto label_801127B4;
        }
    }

label_801127F4:
    ctx->pc = 0x801127F4u;
    ctx->downcount -= 4;
    // 801127F4: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_801127F8:
    ctx->pc = 0x801127F8u;
    // 801127F8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801127FC:
    ctx->pc = 0x801127FCu;
    // 801127FC: addi    r3, r3, 6320
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6320);

label_80112800:
    ctx->pc = 0x80112800u;
    // 80112800: bl      0x80098CD0
    {
            ctx->lr = 0x80112804u;
            ctx->pc = 0x80098CD0u;
            return;
    }

label_80112804:
    ctx->pc = 0x80112804u;
    ctx->downcount -= 5;
    // 80112804: stw     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112808:
    ctx->pc = 0x80112808u;
    // 80112808: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8011280C:
    ctx->pc = 0x8011280Cu;
    // 8011280C: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80112810:
    ctx->pc = 0x80112810u;
    // 80112810: addi    r3, r3, 6348
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6348);

label_80112814:
    ctx->pc = 0x80112814u;
    // 80112814: bl      0x80098CD0
    {
            ctx->lr = 0x80112818u;
            ctx->pc = 0x80098CD0u;
            return;
    }

label_80112818:
    ctx->pc = 0x80112818u;
    ctx->downcount -= 5;
    // 80112818: stw     r3, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8011281C:
    ctx->pc = 0x8011281Cu;
    // 8011281C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80112820:
    ctx->pc = 0x80112820u;
    // 80112820: lis     r3, -32721
    ctx->gpr[3] = ((u32)(s32)(-32721) << 16);

label_80112824:
    ctx->pc = 0x80112824u;
    // 80112824: addi    r3, r3, 6384
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6384);

label_80112828:
    ctx->pc = 0x80112828u;
    // 80112828: bl      0x800994E4
    {
            ctx->lr = 0x8011282Cu;
            ctx->pc = 0x800994E4u;
            return;
    }

label_8011282C:
    ctx->pc = 0x8011282Cu;
    ctx->downcount -= 9;
    // 8011282C: stw     r3, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112830:
    ctx->pc = 0x80112830u;
    // 80112830: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80112834:
    ctx->pc = 0x80112834u;
    // 80112834: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112838:
    ctx->pc = 0x80112838u;
    // 80112838: or   r8, r18, r18
    {
        ctx->gpr[8] = ctx->gpr[18] | ctx->gpr[18];
    }

label_8011283C:
    ctx->pc = 0x8011283Cu;
    // 8011283C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112840:
    ctx->pc = 0x80112840u;
    // 80112840: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80112844:
    ctx->pc = 0x80112844u;
    // 80112844: lwz     r27, 104(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(104);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_80112848:
    ctx->pc = 0x80112848u;
    // 80112848: stb     r0, 416(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(416);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8011284C:
    ctx->pc = 0x8011284Cu;
    // 8011284C: cmpwi   cr7, r27, 0
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_80112850:
    ctx->downcount -= 9;
    // 80112850: mulli   r9, r11, 28
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)28);

label_80112854:
    // 80112854: addi    r0, r11, 1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(1);

label_80112858:
    // 80112858: li      r11, 7
    ctx->gpr[11] = (u32)(s32)(7);

label_8011285C:
    ctx->pc = 0x8011285Cu;
    // 8011285C: mtctr    r11
    ctx->ctr = ctx->gpr[11];

label_80112860:
    // 80112860: add   r9, r9, r8
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80112864:
    // 80112864: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

label_80112868:
    loop_80112868(ctx);
    if (ctx->pc == 0x80112874u) goto label_80112874;
    return;
label_8011286C:
    // 8011286C: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_80112870:
    // 80112870: bc    16, 0, 0x80112868
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112868u;
                return;
            }
            goto label_80112868;
        }
    }

label_80112874:
    ctx->downcount -= 3;
    // 80112874: or   r11, r0, r0
    {
        ctx->gpr[11] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80112878:
    // 80112878: cmpwi   r11, 6
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8011287C:
    // 8011287C: bc    4, 1, 0x80112850
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112850u;
                return;
            }
            goto label_80112850;
        }
    }

label_80112880:
    ctx->pc = 0x80112880u;
    ctx->downcount -= 1;
    // 80112880: bc    12, 30, 0x80112970
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112970;
        }
    }

label_80112884:
    ctx->pc = 0x80112884u;
    ctx->downcount -= 4;
    // 80112884: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_80112888:
    ctx->pc = 0x80112888u;
    // 80112888: lis     r20, -32721
    ctx->gpr[20] = ((u32)(s32)(-32721) << 16);

label_8011288C:
    ctx->pc = 0x8011288Cu;
    // 8011288C: addi    r24, r1, 72
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(72);

label_80112890:
    ctx->pc = 0x80112890u;
    // 80112890: lis     r21, -32721
    ctx->gpr[21] = ((u32)(s32)(-32721) << 16);

label_80112894:
    ctx->downcount -= 6;
    // 80112894: mulli   r0, r25, 28
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[25] * (s64)(s32)28);

label_80112898:
    // 80112898: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_8011289C:
    // 8011289C: addi    r23, r25, 1
    ctx->gpr[23] = ctx->gpr[25] + (u32)(s32)(1);

label_801128A0:
    // 801128A0: add   r29, r0, r18
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[18];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_801128A4:
    ctx->downcount -= 2;
    // 801128A4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801128A8:
    // 801128A8: bl      0x8008F238
    {
            ctx->lr = 0x801128ACu;
            ctx->pc = 0x8008F238u;
            return;
    }

label_801128AC:
    ctx->downcount -= 3;
    // 801128AC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801128B0:
    // 801128B0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801128B4:
    // 801128B4: bl      0x80254680
    {
            ctx->lr = 0x801128B8u;
            ctx->pc = 0x80254680u;
            return;
    }

label_801128B8:
    ctx->downcount -= 3;
    // 801128B8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801128BC:
    // 801128BC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801128C0:
    // 801128C0: bl      0x8008F238
    {
            ctx->lr = 0x801128C4u;
            ctx->pc = 0x8008F238u;
            return;
    }

label_801128C4:
    ctx->downcount -= 3;
    // 801128C4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801128C8:
    // 801128C8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801128CC:
    // 801128CC: bl      0x80254710
    {
            ctx->lr = 0x801128D0u;
            ctx->pc = 0x80254710u;
            return;
    }

label_801128D0:
    ctx->downcount -= 2;
    // 801128D0: cmpwi   r30, -1
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

label_801128D4:
    // 801128D4: bc    12, 2, 0x80112954
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112954;
        }
    }

label_801128D8:
    ctx->downcount -= 2;
    // 801128D8: cmpwi   r3, -1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801128DC:
    // 801128DC: bc    12, 2, 0x80112954
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112954;
        }
    }

label_801128E0:
    ctx->downcount -= 5;
    // 801128E0: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801128E4:
    // 801128E4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801128E8:
    // 801128E8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801128EC:
    // 801128EC: addi    r6, r20, 5692
    ctx->gpr[6] = ctx->gpr[20] + (u32)(s32)(5692);

label_801128F0:
    // 801128F0: bl      0x80254540
    {
            ctx->lr = 0x801128F4u;
            ctx->pc = 0x80254540u;
            return;
    }

label_801128F4:
    ctx->downcount -= 4;
    // 801128F4: lis     r28, -32721
    ctx->gpr[28] = ((u32)(s32)(-32721) << 16);

label_801128F8:
    // 801128F8: or.   r3, r3, r3
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

label_801128FC:
    // 801128FC: addi    r30, r1, 416
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(416);

label_80112900:
    // 80112900: bc    12, 2, 0x80112918
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112918;
        }
    }

label_80112904:
    ctx->downcount -= 4;
    // 80112904: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80112908:
    // 80112908: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_8011290C:
    // 8011290C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112910:
    // 80112910: bl      0x80287F10
    {
            ctx->lr = 0x80112914u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_80112914:
    ctx->downcount -= 1;
    // 80112914: b       0x8011291C
    {
            goto label_8011291C;
    }

label_80112918:
    ctx->pc = 0x80112918u;
    ctx->downcount -= 1;
    // 80112918: stb     r3, 416(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(416);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8011291C:
    ctx->downcount -= 3;
    // 8011291C: addi    r4, r28, 5692
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(5692);

label_80112920:
    // 80112920: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112924:
    // 80112924: bl      0x8029817C
    {
            ctx->lr = 0x80112928u;
            ctx->pc = 0x8029817Cu;
            return;
    }

label_80112928:
    ctx->downcount -= 2;
    // 80112928: or.   r3, r3, r3
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

label_8011292C:
    // 8011292C: bc    12, 2, 0x80112950
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112950;
        }
    }

label_80112930:
    ctx->downcount -= 5;
    // 80112930: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112934:
    // 80112934: addi    r4, r21, 6424
    ctx->gpr[4] = ctx->gpr[21] + (u32)(s32)(6424);

label_80112938:
    // 80112938: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8011293C:
    // 8011293C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80112940:
    // 80112940: bl      0x8009258C
    {
            ctx->lr = 0x80112944u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_80112944:
    ctx->downcount -= 3;
    // 80112944: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80112948:
    // 80112948: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8011294C:
    // 8011294C: bl      0x80098CD0
    {
            ctx->lr = 0x80112950u;
            ctx->pc = 0x80098CD0u;
            return;
    }

label_80112950:
    ctx->pc = 0x80112950u;
    ctx->downcount -= 1;
    // 80112950: stw     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80112954:
    ctx->downcount -= 4;
    // 80112954: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_80112958:
    // 80112958: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_8011295C:
    // 8011295C: cmpwi   r26, 6
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80112960:
    // 80112960: bc    4, 1, 0x801128A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801128A4u;
                return;
            }
            goto label_801128A4;
        }
    }

label_80112964:
    ctx->downcount -= 3;
    // 80112964: or   r25, r23, r23
    {
        ctx->gpr[25] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80112968:
    // 80112968: cmpwi   r25, 6
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8011296C:
    // 8011296C: bc    4, 1, 0x80112894
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112894u;
                return;
            }
            goto label_80112894;
        }
    }

label_80112970:
    ctx->pc = 0x80112970u;
    ctx->downcount -= 3;
    // 80112970: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112974:
    ctx->pc = 0x80112974u;
    // 80112974: li      r3, 30
    ctx->gpr[3] = (u32)(s32)(30);

label_80112978:
    ctx->pc = 0x80112978u;
    // 80112978: bl      0x800E7198
    {
            ctx->lr = 0x8011297Cu;
            ctx->pc = 0x800E7198u;
            return;
    }

label_8011297C:
    ctx->pc = 0x8011297Cu;
    ctx->downcount -= 5;
    // 8011297C: lwz     r9, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112980:
    ctx->pc = 0x80112980u;
    // 80112980: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80112984:
    ctx->pc = 0x80112984u;
    // 80112984: addi    r4, r4, 6448
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6448);

label_80112988:
    ctx->pc = 0x80112988u;
    // 80112988: lwz     r3, 224(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(224);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8011298C:
    ctx->pc = 0x8011298Cu;
    // 8011298C: bl      0x801E7DAC
    {
            ctx->lr = 0x80112990u;
            ctx->pc = 0x801E7DACu;
            return;
    }

label_80112990:
    ctx->pc = 0x80112990u;
    ctx->downcount -= 6;
    // 80112990: lwz     r9, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112994:
    ctx->pc = 0x80112994u;
    // 80112994: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80112998:
    ctx->pc = 0x80112998u;
    // 80112998: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8011299C:
    ctx->pc = 0x8011299Cu;
    // 8011299C: lwz     r3, 224(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(224);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801129A0:
    ctx->pc = 0x801129A0u;
    // 801129A0: addi    r4, r4, 6460
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6460);

label_801129A4:
    ctx->pc = 0x801129A4u;
    // 801129A4: bl      0x801E7DAC
    {
            ctx->lr = 0x801129A8u;
            ctx->pc = 0x801E7DACu;
            return;
    }

label_801129A8:
    ctx->pc = 0x801129A8u;
    ctx->downcount -= 13;
    // 801129A8: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_801129AC:
    ctx->pc = 0x801129ACu;
    // 801129AC: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_801129B0:
    ctx->pc = 0x801129B0u;
    // 801129B0: lfs     f13, 6532(r9)
    if (!ppc_fp_available_inline(ctx, 0x801129B0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6532);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801129B4:
    ctx->pc = 0x801129B4u;
    // 801129B4: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801129B8:
    ctx->pc = 0x801129B8u;
    // 801129B8: cmpwi   r30, 0
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

label_801129BC:
    ctx->pc = 0x801129BCu;
    // 801129BC: stfs     f13, 1200(r31)
    if (!ppc_fp_available_inline(ctx, 0x801129BCu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1200);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801129C0:
    ctx->pc = 0x801129C0u;
    // 801129C0: stfs     f13, 8(r19)
    if (!ppc_fp_available_inline(ctx, 0x801129C0u)) return;
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801129C4:
    ctx->pc = 0x801129C4u;
    // 801129C4: stfs     f13, 4(r19)
    if (!ppc_fp_available_inline(ctx, 0x801129C4u)) return;
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801129C8:
    ctx->pc = 0x801129C8u;
    // 801129C8: lfs     f0, 6536(r11)
    if (!ppc_fp_available_inline(ctx, 0x801129C8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(6536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801129CC:
    ctx->pc = 0x801129CCu;
    // 801129CC: stfs     f0, 1212(r31)
    if (!ppc_fp_available_inline(ctx, 0x801129CCu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1212);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801129D0:
    ctx->pc = 0x801129D0u;
    // 801129D0: stfs     f0, 8(r16)
    if (!ppc_fp_available_inline(ctx, 0x801129D0u)) return;
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801129D4:
    ctx->pc = 0x801129D4u;
    // 801129D4: stfs     f0, 4(r16)
    if (!ppc_fp_available_inline(ctx, 0x801129D4u)) return;
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801129D8:
    ctx->pc = 0x801129D8u;
    // 801129D8: bc    12, 2, 0x80112B64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112B64;
        }
    }

label_801129DC:
    ctx->pc = 0x801129DCu;
    ctx->downcount -= 2;
    // 801129DC: cmpwi   r29, 0
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

label_801129E0:
    ctx->pc = 0x801129E0u;
    // 801129E0: bc    12, 2, 0x80112B64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112B64;
        }
    }

label_801129E4:
    ctx->pc = 0x801129E4u;
    ctx->downcount -= 8;
    // 801129E4: lwz     r9, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801129E8:
    ctx->pc = 0x801129E8u;
    // 801129E8: addi    r28, r1, 400
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(400);

label_801129EC:
    ctx->pc = 0x801129ECu;
    // 801129EC: lha     r3, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801129F0:
    ctx->pc = 0x801129F0u;
    // 801129F0: lwz     r0, 92(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801129F4:
    ctx->pc = 0x801129F4u;
    // 801129F4: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801129F8:
    ctx->pc = 0x801129F8u;
    // 801129F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801129FC:
    ctx->pc = 0x801129FCu;
    // 801129FC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80112A00u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112A00:
    ctx->pc = 0x80112A00u;
    ctx->downcount -= 3;
    // 80112A00: addi    r10, r3, 36
    ctx->gpr[10] = ctx->gpr[3] + (u32)(s32)(36);

label_80112A04:
    ctx->pc = 0x80112A04u;
    // 80112A04: or   r11, r17, r17
    {
        ctx->gpr[11] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80112A08:
    ctx->pc = 0x80112A08u;
    // 80112A08: li      r9, 48
    ctx->gpr[9] = (u32)(s32)(48);

label_80112A0C:
    loop_80112A0C(ctx);
    if (ctx->pc == 0x80112A4Cu) goto label_80112A4C;
    return;
label_80112A10:
    // 80112A10: addic.  r9, r9, -24
    {
        u64 a = ctx->gpr[9];
        u64 b = (u32)(s32)(-24);
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

label_80112A14:
    ctx->pc = 0x80112A14u;
    // 80112A14: stw     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A18:
    ctx->pc = 0x80112A18u;
    // 80112A18: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A1C:
    ctx->pc = 0x80112A1Cu;
    // 80112A1C: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A20:
    ctx->pc = 0x80112A20u;
    // 80112A20: lwz     r0, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A24:
    ctx->pc = 0x80112A24u;
    // 80112A24: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A28:
    ctx->pc = 0x80112A28u;
    // 80112A28: lwz     r0, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A2C:
    ctx->pc = 0x80112A2Cu;
    // 80112A2C: stw     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A30:
    ctx->pc = 0x80112A30u;
    // 80112A30: lwz     r0, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A34:
    ctx->pc = 0x80112A34u;
    // 80112A34: stw     r0, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A38:
    ctx->pc = 0x80112A38u;
    // 80112A38: lwz     r0, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A3C:
    // 80112A3C: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

label_80112A40:
    ctx->pc = 0x80112A40u;
    // 80112A40: stw     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A44:
    // 80112A44: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

label_80112A48:
    // 80112A48: bc    4, 2, 0x80112A0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112A0Cu;
                return;
            }
            goto label_80112A0C;
        }
    }

label_80112A4C:
    ctx->pc = 0x80112A4Cu;
    ctx->downcount -= 18;
    // 80112A4C: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A50:
    ctx->pc = 0x80112A50u;
    // 80112A50: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112A54:
    ctx->pc = 0x80112A54u;
    // 80112A54: lfs     f13, 6540(r9)
    if (!ppc_fp_available_inline(ctx, 0x80112A54u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6540);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80112A58:
    ctx->pc = 0x80112A58u;
    // 80112A58: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80112A5C:
    ctx->pc = 0x80112A5Cu;
    // 80112A5C: stw     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A60:
    ctx->pc = 0x80112A60u;
    // 80112A60: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80112A64:
    ctx->pc = 0x80112A64u;
    // 80112A64: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A68:
    ctx->pc = 0x80112A68u;
    // 80112A68: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A6C:
    ctx->pc = 0x80112A6Cu;
    // 80112A6C: lwz     r0, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A70:
    ctx->pc = 0x80112A70u;
    // 80112A70: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A74:
    ctx->pc = 0x80112A74u;
    // 80112A74: lwz     r0, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112A78:
    ctx->pc = 0x80112A78u;
    // 80112A78: stw     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112A7C:
    ctx->pc = 0x80112A7Cu;
    // 80112A7C: stfs     f13, 400(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112A7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80112A80:
    ctx->pc = 0x80112A80u;
    // 80112A80: lfs     f0, 388(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112A80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(388);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80112A84:
    ctx->pc = 0x80112A84u;
    // 80112A84: lfs     f13, 392(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112A84u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80112A88:
    ctx->pc = 0x80112A88u;
    // 80112A88: stfs     f0, 404(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112A88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(404);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80112A8C:
    ctx->pc = 0x80112A8Cu;
    // 80112A8C: stfs     f13, 408(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112A8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(408);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80112A90:
    ctx->pc = 0x80112A90u;
    // 80112A90: bl      0x80276CC0
    {
            ctx->lr = 0x80112A94u;
            ctx->pc = 0x80276CC0u;
            return;
    }

label_80112A94:
    ctx->pc = 0x80112A94u;
    ctx->downcount -= 7;
    // 80112A94: lwz     r9, 24(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112A98:
    ctx->pc = 0x80112A98u;
    // 80112A98: lha     r3, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80112A9C:
    ctx->pc = 0x80112A9Cu;
    // 80112A9C: lwz     r0, 92(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112AA0:
    ctx->pc = 0x80112AA0u;
    // 80112AA0: add   r3, r29, r3
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80112AA4:
    ctx->pc = 0x80112AA4u;
    // 80112AA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112AA8:
    ctx->pc = 0x80112AA8u;
    // 80112AA8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80112AACu;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112AAC:
    ctx->pc = 0x80112AACu;
    ctx->downcount -= 3;
    // 80112AAC: or   r10, r17, r17
    {
        ctx->gpr[10] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80112AB0:
    ctx->pc = 0x80112AB0u;
    // 80112AB0: addi    r11, r3, 36
    ctx->gpr[11] = ctx->gpr[3] + (u32)(s32)(36);

label_80112AB4:
    ctx->pc = 0x80112AB4u;
    // 80112AB4: li      r9, 48
    ctx->gpr[9] = (u32)(s32)(48);

label_80112AB8:
    loop_80112AB8(ctx);
    if (ctx->pc == 0x80112AF8u) goto label_80112AF8;
    return;
label_80112ABC:
    // 80112ABC: addic.  r9, r9, -24
    {
        u64 a = ctx->gpr[9];
        u64 b = (u32)(s32)(-24);
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

label_80112AC0:
    ctx->pc = 0x80112AC0u;
    // 80112AC0: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112AC4:
    ctx->pc = 0x80112AC4u;
    // 80112AC4: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112AC8:
    ctx->pc = 0x80112AC8u;
    // 80112AC8: stw     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112ACC:
    ctx->pc = 0x80112ACCu;
    // 80112ACC: lwz     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112AD0:
    ctx->pc = 0x80112AD0u;
    // 80112AD0: stw     r0, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112AD4:
    ctx->pc = 0x80112AD4u;
    // 80112AD4: lwz     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112AD8:
    ctx->pc = 0x80112AD8u;
    // 80112AD8: stw     r0, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112ADC:
    ctx->pc = 0x80112ADCu;
    // 80112ADC: lwz     r0, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112AE0:
    ctx->pc = 0x80112AE0u;
    // 80112AE0: stw     r0, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112AE4:
    ctx->pc = 0x80112AE4u;
    // 80112AE4: lwz     r0, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112AE8:
    // 80112AE8: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

label_80112AEC:
    ctx->pc = 0x80112AECu;
    // 80112AEC: stw     r0, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112AF0:
    // 80112AF0: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

label_80112AF4:
    // 80112AF4: bc    4, 2, 0x80112AB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112AB8u;
                return;
            }
            goto label_80112AB8;
        }
    }

label_80112AF8:
    ctx->pc = 0x80112AF8u;
    ctx->downcount -= 26;
    // 80112AF8: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112AFC:
    ctx->pc = 0x80112AFCu;
    // 80112AFC: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112B00:
    ctx->pc = 0x80112B00u;
    // 80112B00: lfs     f11, 6544(r9)
    if (!ppc_fp_available_inline(ctx, 0x80112B00u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6544);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_80112B04:
    ctx->pc = 0x80112B04u;
    // 80112B04: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80112B08:
    ctx->pc = 0x80112B08u;
    // 80112B08: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112B0C:
    ctx->pc = 0x80112B0Cu;
    // 80112B0C: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80112B10:
    ctx->pc = 0x80112B10u;
    // 80112B10: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112B14:
    ctx->pc = 0x80112B14u;
    // 80112B14: stw     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112B18:
    ctx->pc = 0x80112B18u;
    // 80112B18: lwz     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112B1C:
    ctx->pc = 0x80112B1Cu;
    // 80112B1C: stw     r0, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112B20:
    ctx->pc = 0x80112B20u;
    // 80112B20: lwz     r0, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112B24:
    ctx->pc = 0x80112B24u;
    // 80112B24: stw     r0, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112B28:
    ctx->pc = 0x80112B28u;
    // 80112B28: lfs     f0, 384(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112B28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80112B2C:
    ctx->pc = 0x80112B2Cu;
    // 80112B2C: lfs     f13, 388(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112B2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(388);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80112B30:
    ctx->pc = 0x80112B30u;
    // 80112B30: lfs     f12, 392(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112B30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80112B34:
    ctx->pc = 0x80112B34u;
    // 80112B34: stfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112B34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80112B38:
    ctx->pc = 0x80112B38u;
    // 80112B38: stfs     f13, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112B38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80112B3C:
    ctx->pc = 0x80112B3Cu;
    // 80112B3C: stfs     f12, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112B3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_80112B40:
    ctx->pc = 0x80112B40u;
    // 80112B40: lwz     r9, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112B44:
    ctx->pc = 0x80112B44u;
    // 80112B44: lwz     r11, 8(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80112B48:
    ctx->pc = 0x80112B48u;
    // 80112B48: lwz     r0, 4(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112B4C:
    ctx->pc = 0x80112B4Cu;
    // 80112B4C: stw     r9, 400(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80112B50:
    ctx->pc = 0x80112B50u;
    // 80112B50: stw     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112B54:
    ctx->pc = 0x80112B54u;
    // 80112B54: stw     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80112B58:
    ctx->pc = 0x80112B58u;
    // 80112B58: stfs     f11, 400(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112B58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_80112B5C:
    ctx->pc = 0x80112B5Cu;
    // 80112B5C: bl      0x80276CC0
    {
            ctx->lr = 0x80112B60u;
            ctx->pc = 0x80276CC0u;
            return;
    }

label_80112B60:
    ctx->pc = 0x80112B60u;
    ctx->downcount -= 1;
    // 80112B60: b       0x80112BB4
    {
            goto label_80112BB4;
    }

label_80112B64:
    ctx->pc = 0x80112B64u;
    ctx->downcount -= 12;
    // 80112B64: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112B68:
    ctx->pc = 0x80112B68u;
    // 80112B68: lis     r10, -32721
    ctx->gpr[10] = ((u32)(s32)(-32721) << 16);

label_80112B6C:
    ctx->pc = 0x80112B6Cu;
    // 80112B6C: lfs     f30, 6552(r9)
    if (!ppc_fp_available_inline(ctx, 0x80112B6Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6552);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_80112B70:
    ctx->pc = 0x80112B70u;
    // 80112B70: lis     r11, -32721
    ctx->gpr[11] = ((u32)(s32)(-32721) << 16);

label_80112B74:
    ctx->pc = 0x80112B74u;
    // 80112B74: lfs     f0, 6548(r10)
    if (!ppc_fp_available_inline(ctx, 0x80112B74u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6548);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80112B78:
    ctx->pc = 0x80112B78u;
    // 80112B78: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80112B7C:
    ctx->pc = 0x80112B7Cu;
    // 80112B7C: lfs     f31, 6556(r11)
    if (!ppc_fp_available_inline(ctx, 0x80112B7Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(6556);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80112B80:
    ctx->pc = 0x80112B80u;
    // 80112B80: or   r4, r22, r22
    {
        ctx->gpr[4] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80112B84:
    ctx->pc = 0x80112B84u;
    // 80112B84: stfs     f30, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x80112B84u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112B88:
    ctx->pc = 0x80112B88u;
    // 80112B88: stfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112B88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80112B8C:
    ctx->pc = 0x80112B8Cu;
    // 80112B8C: stfs     f31, 8(r22)
    if (!ppc_fp_available_inline(ctx, 0x80112B8Cu)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112B90:
    ctx->pc = 0x80112B90u;
    // 80112B90: bl      0x80276CC0
    {
            ctx->lr = 0x80112B94u;
            ctx->pc = 0x80276CC0u;
            return;
    }

label_80112B94:
    ctx->pc = 0x80112B94u;
    ctx->downcount -= 8;
    // 80112B94: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112B98:
    ctx->pc = 0x80112B98u;
    // 80112B98: stfs     f31, 4(r22)
    if (!ppc_fp_available_inline(ctx, 0x80112B98u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112B9C:
    ctx->pc = 0x80112B9Cu;
    // 80112B9C: lfs     f0, 6504(r9)
    if (!ppc_fp_available_inline(ctx, 0x80112B9Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80112BA0:
    ctx->pc = 0x80112BA0u;
    // 80112BA0: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80112BA4:
    ctx->pc = 0x80112BA4u;
    // 80112BA4: stfs     f30, 8(r22)
    if (!ppc_fp_available_inline(ctx, 0x80112BA4u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112BA8:
    ctx->pc = 0x80112BA8u;
    // 80112BA8: or   r4, r22, r22
    {
        ctx->gpr[4] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80112BAC:
    ctx->pc = 0x80112BACu;
    // 80112BAC: stfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112BACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80112BB0:
    ctx->pc = 0x80112BB0u;
    // 80112BB0: bl      0x80276CC0
    {
            ctx->lr = 0x80112BB4u;
            ctx->pc = 0x80276CC0u;
            return;
    }

label_80112BB4:
    ctx->pc = 0x80112BB4u;
    ctx->downcount -= 1;
    // 80112BB4: bl      0x8011BA40
    {
            ctx->lr = 0x80112BB8u;
            ctx->pc = 0x8011BA40u;
            return;
    }

label_80112BB8:
    ctx->pc = 0x80112BB8u;
    ctx->downcount -= 4;
    // 80112BB8: lwz     r4, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112BBC:
    ctx->pc = 0x80112BBCu;
    // 80112BBC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80112BC0:
    ctx->pc = 0x80112BC0u;
    // 80112BC0: addi    r4, r4, 12
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(12);

label_80112BC4:
    ctx->pc = 0x80112BC4u;
    // 80112BC4: bl      0x8011B888
    {
            ctx->lr = 0x80112BC8u;
            ctx->pc = 0x8011B888u;
            return;
    }

label_80112BC8:
    ctx->pc = 0x80112BC8u;
    ctx->downcount -= 21;
    // 80112BC8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80112BCC:
    ctx->pc = 0x80112BCCu;
    // 80112BCC: lwz     r0, 812(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(812);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112BD0:
    ctx->pc = 0x80112BD0u;
    // 80112BD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112BD4:
    ctx->pc = 0x80112BD4u;
    // 80112BD4: lmw     r16, 712(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(712);
        for (u32 r = 16; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80112BD8:
    ctx->pc = 0x80112BD8u;
    // 80112BD8: lfd     f28, 776(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112BD8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(776);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80112BDC:
    ctx->pc = 0x80112BDCu;
    // 80112BDC: lfd     f29, 784(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112BDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(784);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80112BE0:
    ctx->pc = 0x80112BE0u;
    // 80112BE0: lfd     f30, 792(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112BE0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(792);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80112BE4:
    ctx->pc = 0x80112BE4u;
    // 80112BE4: lfd     f31, 800(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112BE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(800);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80112BE8:
    ctx->pc = 0x80112BE8u;
    // 80112BE8: addi    r1, r1, 808
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(808);

label_80112BEC:
    ctx->pc = 0x80112BECu;
    // 80112BEC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112BF0:
    ctx->pc = 0x80112BF0u;
    ctx->downcount -= 21;
    // 80112BF0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80112BF4:
    ctx->pc = 0x80112BF4u;
    // 80112BF4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80112BF8:
    ctx->pc = 0x80112BF8u;
    // 80112BF8: stmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80112BFC:
    ctx->pc = 0x80112BFCu;
    // 80112BFC: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112C00:
    ctx->pc = 0x80112C00u;
    // 80112C00: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112C04:
    ctx->pc = 0x80112C04u;
    // 80112C04: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80112C08:
    ctx->pc = 0x80112C08u;
    // 80112C08: addi    r9, r9, 8120
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8120);

label_80112C0C:
    ctx->pc = 0x80112C0Cu;
    // 80112C0C: or   r26, r4, r4
    {
        ctx->gpr[26] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80112C10:
    ctx->pc = 0x80112C10u;
    // 80112C10: stw     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80112C14:
    ctx->pc = 0x80112C14u;
    // 80112C14: lis     r27, -32714
    ctx->gpr[27] = ((u32)(s32)(-32714) << 16);

label_80112C18:
    ctx->pc = 0x80112C18u;
    // 80112C18: bl      0x801B5358
    {
            ctx->lr = 0x80112C1Cu;
            ctx->pc = 0x801B5358u;
            return;
    }

label_80112C1C:
    ctx->pc = 0x80112C1Cu;
    ctx->downcount -= 2;
    // 80112C1C: addi    r29, r31, 212
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(212);

label_80112C20:
    ctx->pc = 0x80112C20u;
    // 80112C20: bl      0x801B5578
    {
            ctx->lr = 0x80112C24u;
            ctx->pc = 0x801B5578u;
            return;
    }

label_80112C24:
    ctx->pc = 0x80112C24u;
    ctx->downcount -= 6;
    // 80112C24: li      r28, 25
    ctx->gpr[28] = (u32)(s32)(25);

label_80112C28:
    ctx->pc = 0x80112C28u;
    // 80112C28: lis     r30, -32714
    ctx->gpr[30] = ((u32)(s32)(-32714) << 16);

label_80112C2C:
    ctx->pc = 0x80112C2Cu;
    // 80112C2C: lwz     r4, 500(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(500);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112C30:
    ctx->pc = 0x80112C30u;
    // 80112C30: addi    r30, r30, -19596
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-19596);

label_80112C34:
    ctx->pc = 0x80112C34u;
    // 80112C34: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112C38:
    ctx->pc = 0x80112C38u;
    // 80112C38: bl      0x801A70FC
    {
            ctx->lr = 0x80112C3Cu;
            ctx->pc = 0x801A70FCu;
            return;
    }

label_80112C3C:
    ctx->pc = 0x80112C3Cu;
    ctx->downcount -= 3;
    // 80112C3C: lwz     r4, 504(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(504);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112C40:
    ctx->pc = 0x80112C40u;
    // 80112C40: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112C44:
    ctx->pc = 0x80112C44u;
    // 80112C44: bl      0x801A70FC
    {
            ctx->lr = 0x80112C48u;
            ctx->pc = 0x801A70FCu;
            return;
    }

label_80112C48:
    ctx->pc = 0x80112C48u;
    ctx->downcount -= 3;
    // 80112C48: lwz     r4, 508(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(508);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112C4C:
    ctx->pc = 0x80112C4Cu;
    // 80112C4C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112C50:
    ctx->pc = 0x80112C50u;
    // 80112C50: bl      0x801A70FC
    {
            ctx->lr = 0x80112C54u;
            ctx->pc = 0x801A70FCu;
            return;
    }

label_80112C54:
    ctx->pc = 0x80112C54u;
    ctx->downcount -= 3;
    // 80112C54: lwz     r4, 512(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(512);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112C58:
    ctx->pc = 0x80112C58u;
    // 80112C58: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112C5C:
    ctx->pc = 0x80112C5Cu;
    // 80112C5C: bl      0x801A70FC
    {
            ctx->lr = 0x80112C60u;
            ctx->pc = 0x801A70FCu;
            return;
    }

label_80112C60:
    ctx->pc = 0x80112C60u;
    ctx->downcount -= 3;
    // 80112C60: lwz     r4, 316(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(316);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112C64:
    ctx->pc = 0x80112C64u;
    // 80112C64: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112C68:
    ctx->pc = 0x80112C68u;
    // 80112C68: bl      0x801A70FC
    {
            ctx->lr = 0x80112C6Cu;
            ctx->pc = 0x801A70FCu;
            return;
    }

label_80112C6C:
    ctx->pc = 0x80112C6Cu;
    ctx->downcount -= 4;
    // 80112C6C: lwz     r4, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112C70:
    // 80112C70: addi    r3, r27, -19596
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(-19596);

label_80112C74:
    // 80112C74: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_80112C78:
    // 80112C78: bl      0x801A70FC
    {
            ctx->lr = 0x80112C7Cu;
            ctx->pc = 0x801A70FCu;
            return;
    }

label_80112C7C:
    ctx->downcount -= 2;
    // 80112C7C: addic.  r28, r28, -1
    {
        u64 a = ctx->gpr[28];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[28] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[28];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80112C80:
    // 80112C80: bc    4, 2, 0x80112C6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112C6Cu;
                return;
            }
            goto label_80112C6C;
        }
    }

label_80112C84:
    ctx->pc = 0x80112C84u;
    ctx->downcount -= 3;
    // 80112C84: lwz     r11, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80112C88:
    ctx->pc = 0x80112C88u;
    // 80112C88: cmpwi   r11, 0
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

label_80112C8C:
    ctx->pc = 0x80112C8Cu;
    // 80112C8C: bc    12, 2, 0x80112CAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112CAC;
        }
    }

label_80112C90:
    ctx->pc = 0x80112C90u;
    ctx->downcount -= 8;
    // 80112C90: lwz     r9, 128(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(128);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112C94:
    ctx->pc = 0x80112C94u;
    // 80112C94: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80112C98:
    ctx->pc = 0x80112C98u;
    // 80112C98: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80112C9C:
    ctx->pc = 0x80112C9Cu;
    // 80112C9C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112CA0:
    ctx->pc = 0x80112CA0u;
    // 80112CA0: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80112CA4:
    ctx->pc = 0x80112CA4u;
    // 80112CA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112CA8:
    ctx->pc = 0x80112CA8u;
    // 80112CA8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80112CACu;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112CAC:
    ctx->pc = 0x80112CACu;
    ctx->downcount -= 3;
    // 80112CAC: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80112CB0:
    ctx->pc = 0x80112CB0u;
    // 80112CB0: addi    r3, r3, -25224
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-25224);

label_80112CB4:
    ctx->pc = 0x80112CB4u;
    // 80112CB4: bl      0x80052C1C
    {
            ctx->lr = 0x80112CB8u;
            ctx->pc = 0x80052C1Cu;
            return;
    }

label_80112CB8:
    ctx->pc = 0x80112CB8u;
    ctx->downcount -= 3;
    // 80112CB8: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_80112CBC:
    ctx->pc = 0x80112CBCu;
    // 80112CBC: addi    r3, r3, -27676
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27676);

label_80112CC0:
    ctx->pc = 0x80112CC0u;
    // 80112CC0: bl      0x8005BA28
    {
            ctx->lr = 0x80112CC4u;
            ctx->pc = 0x8005BA28u;
            return;
    }

label_80112CC4:
    ctx->pc = 0x80112CC4u;
    ctx->downcount -= 3;
    // 80112CC4: lwz     r11, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80112CC8:
    ctx->pc = 0x80112CC8u;
    // 80112CC8: cmpwi   r11, 0
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

label_80112CCC:
    ctx->pc = 0x80112CCCu;
    // 80112CCC: bc    12, 2, 0x80112CEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112CEC;
        }
    }

label_80112CD0:
    ctx->pc = 0x80112CD0u;
    ctx->downcount -= 8;
    // 80112CD0: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112CD4:
    ctx->pc = 0x80112CD4u;
    // 80112CD4: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80112CD8:
    ctx->pc = 0x80112CD8u;
    // 80112CD8: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80112CDC:
    ctx->pc = 0x80112CDCu;
    // 80112CDC: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112CE0:
    ctx->pc = 0x80112CE0u;
    // 80112CE0: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80112CE4:
    ctx->pc = 0x80112CE4u;
    // 80112CE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112CE8:
    ctx->pc = 0x80112CE8u;
    // 80112CE8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80112CECu;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112CEC:
    ctx->pc = 0x80112CECu;
    ctx->downcount -= 3;
    // 80112CEC: addi    r30, r31, 440
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(440);

label_80112CF0:
    ctx->pc = 0x80112CF0u;
    // 80112CF0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112CF4:
    ctx->pc = 0x80112CF4u;
    // 80112CF4: bl      0x8007769C
    {
            ctx->lr = 0x80112CF8u;
            ctx->pc = 0x8007769Cu;
            return;
    }

label_80112CF8:
    ctx->pc = 0x80112CF8u;
    ctx->downcount -= 3;
    // 80112CF8: lwz     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80112CFC:
    ctx->pc = 0x80112CFCu;
    // 80112CFC: cmpwi   r3, 0
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

label_80112D00:
    ctx->pc = 0x80112D00u;
    // 80112D00: bc    12, 2, 0x80112D0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112D0C;
        }
    }

label_80112D04:
    ctx->pc = 0x80112D04u;
    ctx->downcount -= 2;
    // 80112D04: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_80112D08:
    ctx->pc = 0x80112D08u;
    // 80112D08: bl      0x8001D934
    {
            ctx->lr = 0x80112D0Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80112D0C:
    ctx->pc = 0x80112D0Cu;
    ctx->downcount -= 4;
    // 80112D0C: lwz     r3, 424(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(424);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80112D10:
    ctx->pc = 0x80112D10u;
    // 80112D10: addi    r9, r31, 424
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(424);

label_80112D14:
    ctx->pc = 0x80112D14u;
    // 80112D14: cmpwi   r3, 0
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

label_80112D18:
    ctx->pc = 0x80112D18u;
    // 80112D18: bc    12, 2, 0x80112D3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112D3C;
        }
    }

label_80112D1C:
    ctx->pc = 0x80112D1Cu;
    ctx->downcount -= 5;
    // 80112D1C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112D20:
    ctx->pc = 0x80112D20u;
    // 80112D20: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80112D24:
    ctx->pc = 0x80112D24u;
    // 80112D24: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80112D28:
    ctx->pc = 0x80112D28u;
    // 80112D28: cmplwi  r4, 0x0080
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

label_80112D2C:
    ctx->pc = 0x80112D2Cu;
    // 80112D2C: bc    4, 1, 0x80112D38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80112D38;
        }
    }

label_80112D30:
    ctx->pc = 0x80112D30u;
    ctx->downcount -= 1;
    // 80112D30: bl      0x80281D80
    {
            ctx->lr = 0x80112D34u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80112D34:
    ctx->pc = 0x80112D34u;
    ctx->downcount -= 1;
    // 80112D34: b       0x80112D3C
    {
            goto label_80112D3C;
    }

label_80112D38:
    ctx->pc = 0x80112D38u;
    ctx->downcount -= 1;
    // 80112D38: bl      0x8001D934
    {
            ctx->lr = 0x80112D3Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80112D3C:
    ctx->pc = 0x80112D3Cu;
    ctx->downcount -= 4;
    // 80112D3C: lwz     r3, 408(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(408);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80112D40:
    ctx->pc = 0x80112D40u;
    // 80112D40: addi    r9, r31, 408
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(408);

label_80112D44:
    ctx->pc = 0x80112D44u;
    // 80112D44: cmpwi   r3, 0
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

label_80112D48:
    ctx->pc = 0x80112D48u;
    // 80112D48: bc    12, 2, 0x80112D6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112D6C;
        }
    }

label_80112D4C:
    ctx->pc = 0x80112D4Cu;
    ctx->downcount -= 5;
    // 80112D4C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112D50:
    ctx->pc = 0x80112D50u;
    // 80112D50: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80112D54:
    ctx->pc = 0x80112D54u;
    // 80112D54: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80112D58:
    ctx->pc = 0x80112D58u;
    // 80112D58: cmplwi  r4, 0x0080
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

label_80112D5C:
    ctx->pc = 0x80112D5Cu;
    // 80112D5C: bc    4, 1, 0x80112D68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80112D68;
        }
    }

label_80112D60:
    ctx->pc = 0x80112D60u;
    ctx->downcount -= 1;
    // 80112D60: bl      0x80281D80
    {
            ctx->lr = 0x80112D64u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80112D64:
    ctx->pc = 0x80112D64u;
    ctx->downcount -= 1;
    // 80112D64: b       0x80112D6C
    {
            goto label_80112D6C;
    }

label_80112D68:
    ctx->pc = 0x80112D68u;
    ctx->downcount -= 1;
    // 80112D68: bl      0x8001D934
    {
            ctx->lr = 0x80112D6Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80112D6C:
    ctx->pc = 0x80112D6Cu;
    ctx->downcount -= 3;
    // 80112D6C: addi    r3, r31, 368
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(368);

label_80112D70:
    ctx->pc = 0x80112D70u;
    // 80112D70: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80112D74:
    ctx->pc = 0x80112D74u;
    // 80112D74: bl      0x801D3364
    {
            ctx->lr = 0x80112D78u;
            ctx->pc = 0x801D3364u;
            return;
    }

label_80112D78:
    ctx->pc = 0x80112D78u;
    ctx->downcount -= 3;
    // 80112D78: addi    r3, r31, 328
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(328);

label_80112D7C:
    ctx->pc = 0x80112D7Cu;
    // 80112D7C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80112D80:
    ctx->pc = 0x80112D80u;
    // 80112D80: bl      0x80285E80
    {
            ctx->lr = 0x80112D84u;
            ctx->pc = 0x80285E80u;
            return;
    }

label_80112D84:
    ctx->pc = 0x80112D84u;
    ctx->downcount -= 2;
    // 80112D84: andi.   r0, r26, 0x0001
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

label_80112D88:
    ctx->pc = 0x80112D88u;
    // 80112D88: bc    12, 2, 0x80112D94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112D94;
        }
    }

label_80112D8C:
    ctx->pc = 0x80112D8Cu;
    ctx->downcount -= 2;
    // 80112D8C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80112D90:
    ctx->pc = 0x80112D90u;
    // 80112D90: bl      0x80281D80
    {
            ctx->lr = 0x80112D94u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80112D94:
    ctx->pc = 0x80112D94u;
    ctx->downcount -= 16;
    // 80112D94: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112D98:
    ctx->pc = 0x80112D98u;
    // 80112D98: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112D9C:
    ctx->pc = 0x80112D9Cu;
    // 80112D9C: lmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80112DA0:
    ctx->pc = 0x80112DA0u;
    // 80112DA0: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80112DA4:
    ctx->pc = 0x80112DA4u;
    // 80112DA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112DA8:
    ctx->pc = 0x80112DA8u;
    ctx->downcount -= 23;
    // 80112DA8: stwu     r1, -112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-112);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80112DAC:
    ctx->pc = 0x80112DACu;
    // 80112DAC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80112DB0:
    ctx->pc = 0x80112DB0u;
    // 80112DB0: stfd     f30, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112DB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80112DB4:
    ctx->pc = 0x80112DB4u;
    // 80112DB4: stfd     f31, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112DB4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80112DB8:
    ctx->pc = 0x80112DB8u;
    // 80112DB8: stmw     r23, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        for (u32 r = 23; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80112DBC:
    ctx->pc = 0x80112DBCu;
    // 80112DBC: stw     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112DC0:
    ctx->pc = 0x80112DC0u;
    // 80112DC0: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80112DC4:
    ctx->pc = 0x80112DC4u;
    // 80112DC4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80112DC8:
    ctx->pc = 0x80112DC8u;
    // 80112DC8: lwz     r28, 408(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(408);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80112DCC:
    ctx->pc = 0x80112DCCu;
    // 80112DCC: lwz     r0, 412(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(412);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112DD0:
    ctx->pc = 0x80112DD0u;
    // 80112DD0: stw     r9, 488(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80112DD4:
    ctx->pc = 0x80112DD4u;
    // 80112DD4: cmpw    r28, r0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80112DD8:
    ctx->pc = 0x80112DD8u;
    // 80112DD8: bc    12, 2, 0x8011309C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011309C;
        }
    }

label_80112DDC:
    ctx->pc = 0x80112DDCu;
    ctx->downcount -= 6;
    // 80112DDC: lis     r23, -32721
    ctx->gpr[23] = ((u32)(s32)(-32721) << 16);

label_80112DE0:
    ctx->pc = 0x80112DE0u;
    // 80112DE0: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80112DE4:
    ctx->pc = 0x80112DE4u;
    // 80112DE4: lfs     f30, 6564(r9)
    if (!ppc_fp_available_inline(ctx, 0x80112DE4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6564);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_80112DE8:
    ctx->pc = 0x80112DE8u;
    // 80112DE8: addi    r24, r1, 8
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(8);

label_80112DEC:
    ctx->pc = 0x80112DECu;
    // 80112DEC: lfs     f31, 6560(r23)
    if (!ppc_fp_available_inline(ctx, 0x80112DECu)) return;
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(6560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80112DF0:
    ctx->pc = 0x80112DF0u;
    // 80112DF0: addi    r25, r1, 24
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(24);

label_80112DF4:
    ctx->pc = 0x80112DF4u;
    ctx->downcount -= 8;
    // 80112DF4: lwz     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80112DF8:
    ctx->pc = 0x80112DF8u;
    // 80112DF8: lwz     r9, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112DFC:
    ctx->pc = 0x80112DFCu;
    // 80112DFC: lha     r0, 256(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(256);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80112E00:
    ctx->pc = 0x80112E00u;
    // 80112E00: lwz     r9, 260(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(260);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112E04:
    // 80112E04: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80112E08:
    ctx->pc = 0x80112E08u;
    // 80112E08: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_80112E0C:
    ctx->pc = 0x80112E0Cu;
    // 80112E0C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80112E10u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112E10:
    ctx->downcount -= 2;
    // 80112E10: cmpwi   r3, 0
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

label_80112E14:
    // 80112E14: bc    12, 2, 0x8011303C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011303C;
        }
    }

label_80112E18:
    ctx->pc = 0x80112E18u;
    ctx->downcount -= 5;
    // 80112E18: lwz     r29, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80112E1C:
    // 80112E1C: addi    r27, r1, 24
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(24);

label_80112E20:
    ctx->pc = 0x80112E20u;
    // 80112E20: lwz     r31, 304(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(304);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80112E24:
    // 80112E24: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80112E28:
    // 80112E28: bl      0x80189B80
    {
            ctx->lr = 0x80112E2Cu;
            ctx->pc = 0x80189B80u;
            return;
    }

label_80112E2C:
    ctx->pc = 0x80112E2Cu;
    ctx->downcount -= 12;
    // 80112E2C: stfs     f31, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112E2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112E30:
    // 80112E30: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80112E34:
    ctx->pc = 0x80112E34u;
    // 80112E34: stfs     f31, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112E34u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112E38:
    ctx->pc = 0x80112E38u;
    // 80112E38: stfs     f31, 8(r24)
    if (!ppc_fp_available_inline(ctx, 0x80112E38u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112E3C:
    ctx->pc = 0x80112E3Cu;
    // 80112E3C: stfs     f31, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x80112E3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112E40:
    ctx->pc = 0x80112E40u;
    // 80112E40: stfs     f31, 4(r25)
    if (!ppc_fp_available_inline(ctx, 0x80112E40u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112E44:
    ctx->pc = 0x80112E44u;
    // 80112E44: stfs     f31, 8(r25)
    if (!ppc_fp_available_inline(ctx, 0x80112E44u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80112E48:
    ctx->pc = 0x80112E48u;
    // 80112E48: stfs     f30, 12(r25)
    if (!ppc_fp_available_inline(ctx, 0x80112E48u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_80112E4C:
    ctx->pc = 0x80112E4Cu;
    // 80112E4C: lfs     f0, 832(r31)
    if (!ppc_fp_available_inline(ctx, 0x80112E4Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(832);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80112E50:
    ctx->pc = 0x80112E50u;
    // 80112E50: lwz     r4, 296(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(296);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112E54:
    ctx->pc = 0x80112E54u;
    // 80112E54: fcmpu   cr0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80112E54u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[31], false);

label_80112E58:
    // 80112E58: bc    4, 1, 0x80112E70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80112E70;
        }
    }

label_80112E5C:
    ctx->pc = 0x80112E5Cu;
    ctx->downcount -= 5;
    // 80112E5C: lwz     r0, 784(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(784);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112E60:
    // 80112E60: xori    r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] ^ 0x0006u;

label_80112E64:
    // 80112E64: subfic  r9, r0, 0
    {
        u64 res = (u64)(u32)(s32)(0) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[9] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80112E68:
    // 80112E68: adde   r0, r9, r0
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80112E6C:
    // 80112E6C: xori    r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] ^ 0x0001u;

label_80112E70:
    ctx->downcount -= 2;
    // 80112E70: cmpwi   r0, 0
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

label_80112E74:
    // 80112E74: bc    4, 2, 0x80112E88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80112E88;
        }
    }

label_80112E78:
    ctx->pc = 0x80112E78u;
    ctx->downcount -= 4;
    // 80112E78: lwz     r9, -32104(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32104);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112E7C:
    ctx->pc = 0x80112E7Cu;
    // 80112E7C: lwz     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112E80:
    // 80112E80: cmpw    r0, r9
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

label_80112E84:
    // 80112E84: bc    4, 2, 0x80112E90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80112E90;
        }
    }

label_80112E88:
    ctx->pc = 0x80112E88u;
    ctx->downcount -= 2;
    // 80112E88: lwz     r4, 828(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(828);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112E8C:
    // 80112E8C: b       0x80112E94
    {
            goto label_80112E94;
    }

label_80112E90:
    ctx->pc = 0x80112E90u;
    ctx->downcount -= 1;
    // 80112E90: lwz     r4, 1512(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1512);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112E94:
    ctx->downcount -= 2;
    // 80112E94: cmpwi   r4, 0
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

label_80112E98:
    // 80112E98: bc    12, 2, 0x80112ED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112ED8;
        }
    }

label_80112E9C:
    ctx->pc = 0x80112E9Cu;
    ctx->downcount -= 3;
    // 80112E9C: lwz     r0, 1512(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1512);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112EA0:
    // 80112EA0: cmpwi   r0, 0
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

label_80112EA4:
    // 80112EA4: bc    12, 2, 0x80112EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112EBC;
        }
    }

label_80112EA8:
    ctx->downcount -= 4;
    // 80112EA8: or   r4, r0, r0
    {
        ctx->gpr[4] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80112EAC:
    ctx->pc = 0x80112EACu;
    // 80112EAC: lwz     r0, 1512(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1512);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112EB0:
    // 80112EB0: cmpwi   r0, 0
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

label_80112EB4:
    // 80112EB4: bc    12, 2, 0x80112EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112EBC;
        }
    }

label_80112EB8:
    ctx->downcount -= 1;
    // 80112EB8: or   r4, r0, r0
    {
        ctx->gpr[4] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80112EBC:
    ctx->downcount -= 2;
    // 80112EBC: cmpwi   r4, 0
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

label_80112EC0:
    // 80112EC0: bc    12, 2, 0x80112ED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112ED8;
        }
    }

label_80112EC4:
    ctx->pc = 0x80112EC4u;
    ctx->downcount -= 3;
    // 80112EC4: lwz     r0, 296(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(296);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112EC8:
    // 80112EC8: cmpw    r4, r0
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

label_80112ECC:
    // 80112ECC: bc    12, 2, 0x80112ED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112ED8;
        }
    }

label_80112ED0:
    ctx->downcount -= 2;
    // 80112ED0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80112ED4:
    // 80112ED4: bl      0x80180028
    {
            ctx->lr = 0x80112ED8u;
            ctx->pc = 0x80180028u;
            return;
    }

label_80112ED8:
    ctx->downcount -= 5;
    // 80112ED8: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80112EDC:
    // 80112EDC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80112EE0:
    // 80112EE0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80112EE4:
    // 80112EE4: addi    r30, r29, 88
    ctx->gpr[30] = ctx->gpr[29] + (u32)(s32)(88);

label_80112EE8:
    // 80112EE8: bl      0x800DEF04
    {
            ctx->lr = 0x80112EECu;
            ctx->pc = 0x800DEF04u;
            return;
    }

label_80112EEC:
    ctx->pc = 0x80112EECu;
    ctx->downcount -= 4;
    // 80112EEC: lfs     f1, 6560(r23)
    if (!ppc_fp_available_inline(ctx, 0x80112EECu)) return;
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(6560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112EF0:
    // 80112EF0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80112EF4:
    // 80112EF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80112EF8:
    // 80112EF8: bl      0x8018BF90
    {
            ctx->lr = 0x80112EFCu;
            ctx->pc = 0x8018BF90u;
            return;
    }

label_80112EFC:
    ctx->downcount -= 4;
    // 80112EFC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80112F00:
    // 80112F00: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80112F04:
    // 80112F04: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80112F08:
    // 80112F08: bl      0x8018120C
    {
            ctx->lr = 0x80112F0Cu;
            ctx->pc = 0x8018120Cu;
            return;
    }

label_80112F0C:
    ctx->pc = 0x80112F0Cu;
    ctx->downcount -= 7;
    // 80112F0C: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112F10:
    ctx->pc = 0x80112F10u;
    // 80112F10: lwz     r0, 276(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(276);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112F14:
    ctx->pc = 0x80112F14u;
    // 80112F14: lha     r3, 272(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(272);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80112F18:
    ctx->pc = 0x80112F18u;
    // 80112F18: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112F1C:
    // 80112F1C: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80112F20:
    ctx->pc = 0x80112F20u;
    // 80112F20: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80112F24u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112F24:
    ctx->downcount -= 5;
    // 80112F24: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80112F28:
    // 80112F28: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80112F2C:
    // 80112F2C: or   r6, r27, r27
    {
        ctx->gpr[6] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80112F30:
    // 80112F30: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80112F34:
    // 80112F34: bl      0x80116574
    {
            ctx->lr = 0x80112F38u;
            ctx->pc = 0x80116574u;
            return;
    }

label_80112F38:
    ctx->pc = 0x80112F38u;
    ctx->downcount -= 2;
    // 80112F38: lwz     r3, 860(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(860);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80112F3C:
    // 80112F3C: bl      0x801A8648
    {
            ctx->lr = 0x80112F40u;
            ctx->pc = 0x801A8648u;
            return;
    }

label_80112F40:
    ctx->pc = 0x80112F40u;
    ctx->downcount -= 8;
    // 80112F40: lwz     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112F44:
    // 80112F44: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80112F48:
    ctx->pc = 0x80112F48u;
    // 80112F48: lwz     r0, 268(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112F4C:
    ctx->pc = 0x80112F4Cu;
    // 80112F4C: lha     r3, 264(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(264);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80112F50:
    ctx->pc = 0x80112F50u;
    // 80112F50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112F54:
    // 80112F54: add   r3, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80112F58:
    ctx->pc = 0x80112F58u;
    // 80112F58: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80112F5Cu;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112F5C:
    ctx->pc = 0x80112F5Cu;
    ctx->downcount -= 8;
    // 80112F5C: lfs     f1, 6560(r23)
    if (!ppc_fp_available_inline(ctx, 0x80112F5Cu)) return;
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(6560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80112F60:
    // 80112F60: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80112F64:
    // 80112F64: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80112F68:
    // 80112F68: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80112F6C:
    // 80112F6C: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80112F70:
    // 80112F70: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80112F74:
    // 80112F74: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80112F78:
    // 80112F78: bl      0x801722AC
    {
            ctx->lr = 0x80112F7Cu;
            ctx->pc = 0x801722ACu;
            return;
    }

label_80112F7C:
    ctx->downcount -= 3;
    // 80112F7C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80112F80:
    // 80112F80: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80112F84:
    // 80112F84: bl      0x8018BD78
    {
            ctx->lr = 0x80112F88u;
            ctx->pc = 0x8018BD78u;
            return;
    }

label_80112F88:
    ctx->pc = 0x80112F88u;
    ctx->downcount -= 8;
    // 80112F88: lwz     r11, 304(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(304);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80112F8C:
    ctx->pc = 0x80112F8Cu;
    // 80112F8C: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112F90:
    ctx->pc = 0x80112F90u;
    // 80112F90: lwz     r0, 276(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(276);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112F94:
    ctx->pc = 0x80112F94u;
    // 80112F94: lha     r3, 272(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(272);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80112F98:
    ctx->pc = 0x80112F98u;
    // 80112F98: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80112F9C:
    // 80112F9C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80112FA0:
    ctx->pc = 0x80112FA0u;
    // 80112FA0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80112FA4u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80112FA4:
    ctx->pc = 0x80112FA4u;
    ctx->downcount -= 8;
    // 80112FA4: lwz     r9, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112FA8:
    // 80112FA8: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80112FAC:
    ctx->pc = 0x80112FACu;
    // 80112FAC: lwz     r11, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80112FB0:
    // 80112FB0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80112FB4:
    // 80112FB4: addi    r9, r9, 80
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(80);

label_80112FB8:
    // 80112FB8: cmpwi   r11, 0
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

label_80112FBC:
    ctx->pc = 0x80112FBCu;
    // 80112FBC: lwzx    r4, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80112FC0:
    // 80112FC0: bc    4, 2, 0x80112FC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80112FC8;
        }
    }

label_80112FC4:
    ctx->downcount -= 1;
    // 80112FC4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80112FC8:
    ctx->downcount -= 2;
    // 80112FC8: cmpwi   r0, 0
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

label_80112FCC:
    // 80112FCC: bc    12, 2, 0x80112FF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80112FF0;
        }
    }

label_80112FD0:
    ctx->pc = 0x80112FD0u;
    ctx->downcount -= 8;
    // 80112FD0: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80112FD4:
    // 80112FD4: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80112FD8:
    ctx->pc = 0x80112FD8u;
    // 80112FD8: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80112FDC:
    ctx->pc = 0x80112FDCu;
    // 80112FDC: lwz     r11, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80112FE0:
    ctx->pc = 0x80112FE0u;
    // 80112FE0: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80112FE4:
    ctx->pc = 0x80112FE4u;
    // 80112FE4: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80112FE8:
    ctx->pc = 0x80112FE8u;
    // 80112FE8: stw     r10, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80112FEC:
    ctx->pc = 0x80112FECu;
    // 80112FEC: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80112FF0:
    ctx->downcount -= 3;
    // 80112FF0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80112FF4:
    // 80112FF4: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_80112FF8:
    // 80112FF8: bl      0x80287994
    {
            ctx->lr = 0x80112FFCu;
            ctx->pc = 0x80287994u;
            return;
    }

label_80112FFC:
    ctx->downcount -= 18;
    // 80112FFC: addi    r27, r26, 408
    ctx->gpr[27] = ctx->gpr[26] + (u32)(s32)(408);

label_80113000:
    ctx->pc = 0x80113000u;
    // 80113000: lwz     r10, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80113004:
    ctx->pc = 0x80113004u;
    // 80113004: lwz     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80113008:
    // 80113008: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_8011300C:
    // 8011300C: rlwinm r9, r11, 0, 26, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x0000003Fu;
    }

label_80113010:
    ctx->pc = 0x80113010u;
    // 80113010: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80113014:
    // 80113014: mulli   r9, r9, 24
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)24);

label_80113018:
    // 80113018: add   r9, r9, r10
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8011301C:
    // 8011301C: addi    r9, r9, 804
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(804);

label_80113020:
    ctx->pc = 0x80113020u;
    // 80113020: stw     r9, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80113024:
    ctx->pc = 0x80113024u;
    // 80113024: lwz     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80113028:
    ctx->pc = 0x80113028u;
    // 80113028: stw     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8011302C:
    ctx->pc = 0x8011302Cu;
    // 8011302C: stw     r30, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80113030:
    ctx->pc = 0x80113030u;
    // 80113030: lwz     r9, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80113034:
    ctx->pc = 0x80113034u;
    // 80113034: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80113038:
    // 80113038: b       0x80113090
    {
            goto label_80113090;
    }

label_8011303C:
    ctx->downcount -= 7;
    // 8011303C: addi    r31, r26, 408
    ctx->gpr[31] = ctx->gpr[26] + (u32)(s32)(408);

label_80113040:
    // 80113040: addi    r4, r28, 4
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(4);

label_80113044:
    ctx->pc = 0x80113044u;
    // 80113044: lwz     r5, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80113048:
    // 80113048: or   r27, r31, r31
    {
        ctx->gpr[27] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8011304C:
    ctx->pc = 0x8011304Cu;
    // 8011304C: lwz     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80113050:
    // 80113050: cmpw    r4, r5
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80113054:
    // 80113054: bc    12, 2, 0x8011306C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011306C;
        }
    }

label_80113058:
    ctx->downcount -= 2;
    // 80113058: cmpw    r5, r4
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

label_8011305C:
    // 8011305C: bc    12, 2, 0x8011306C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8011306C;
        }
    }

label_80113060:
    ctx->downcount -= 3;
    // 80113060: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80113064:
    // 80113064: subf   r5, r4, r5
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80113068:
    // 80113068: bl      0x80297E3C
    {
            ctx->lr = 0x8011306Cu;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_8011306C:
    ctx->pc = 0x8011306Cu;
    ctx->downcount -= 10;
    // 8011306C: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80113070:
    // 80113070: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_80113074:
    ctx->pc = 0x80113074u;
    // 80113074: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80113078:
    ctx->pc = 0x80113078u;
    // 80113078: lwz     r11, 108(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8011307C:
    ctx->pc = 0x8011307Cu;
    // 8011307C: lha     r3, 168(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(168);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80113080:
    ctx->pc = 0x80113080u;
    // 80113080: lwz     r0, 172(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80113084:
    // 80113084: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80113088:
    ctx->pc = 0x80113088u;
    // 80113088: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8011308C:
    ctx->pc = 0x8011308Cu;
    // 8011308C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80113090u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_80113090:
    ctx->pc = 0x80113090u;
    ctx->downcount -= 3;
    // 80113090: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80113094:
    // 80113094: cmpw    r28, r0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80113098:
    // 80113098: bc    4, 2, 0x80112DF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80112DF4u;
                return;
            }
            goto label_80112DF4;
        }
    }

label_8011309C:
    ctx->pc = 0x8011309Cu;
    ctx->downcount -= 18;
    // 8011309C: lwz     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801130A0:
    ctx->pc = 0x801130A0u;
    // 801130A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801130A4:
    ctx->pc = 0x801130A4u;
    // 801130A4: lmw     r23, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        for (u32 r = 23; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801130A8:
    ctx->pc = 0x801130A8u;
    // 801130A8: lfd     f30, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x801130A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801130AC:
    ctx->pc = 0x801130ACu;
    // 801130AC: lfd     f31, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x801130ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801130B0:
    ctx->pc = 0x801130B0u;
    // 801130B0: addi    r1, r1, 112
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(112);

label_801130B4:
    ctx->pc = 0x801130B4u;
    // 801130B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_801130B8:
    ctx->pc = 0x801130B8u;
    ctx->downcount -= 20;
    // 801130B8: stwu     r1, -1280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-1280);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801130BC:
    ctx->pc = 0x801130BCu;
    // 801130BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801130C0:
    ctx->pc = 0x801130C0u;
    // 801130C0: stmw     r24, 1248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1248);
        for (u32 r = 24; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801130C4:
    ctx->pc = 0x801130C4u;
    // 801130C4: stw     r0, 1284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801130C8:
    ctx->pc = 0x801130C8u;
    // 801130C8: lwz     r11, -31944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31944);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801130CC:
    ctx->pc = 0x801130CCu;
    // 801130CC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801130D0:
    ctx->pc = 0x801130D0u;
    // 801130D0: lwz     r9, -26792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26792);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801130D4:
    ctx->pc = 0x801130D4u;
    // 801130D4: lwz     r0, 96(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(96);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801130D8:
    ctx->pc = 0x801130D8u;
    // 801130D8: stw     r0, 176(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801130DC:
    ctx->pc = 0x801130DCu;
    // 801130DC: bl      0x801A078C
    {
            ctx->lr = 0x801130E0u;
            ctx->pc = 0x801A078Cu;
            return;
    }

label_801130E0:
    ctx->pc = 0x801130E0u;
    ctx->downcount -= 3;
    // 801130E0: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801130E4:
    ctx->pc = 0x801130E4u;
    // 801130E4: cmpwi   r0, 0
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

label_801130E8:
    ctx->pc = 0x801130E8u;
    // 801130E8: bc    12, 2, 0x801130F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801130F4;
        }
    }

label_801130EC:
    ctx->pc = 0x801130ECu;
    ctx->downcount -= 1;
    // 801130EC: bl      0x801A078C
    {
            ctx->lr = 0x801130F0u;
            ctx->pc = 0x801A078Cu;
            return;
    }

label_801130F0:
    ctx->pc = 0x801130F0u;
    ctx->downcount -= 1;
    // 801130F0: bl      0x8019E004
    {
            ctx->lr = 0x801130F4u;
            ctx->pc = 0x8019E004u;
            return;
    }

label_801130F4:
    ctx->pc = 0x801130F4u;
    ctx->downcount -= 8;
    // 801130F4: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801130F8:
    ctx->pc = 0x801130F8u;
    // 801130F8: lis     r29, -32714
    ctx->gpr[29] = ((u32)(s32)(-32714) << 16);

label_801130FC:
    ctx->pc = 0x801130FCu;
    // 801130FC: stw     r30, 668(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(668);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80113100:
    ctx->pc = 0x80113100u;
    // 80113100: addi    r3, r29, -25052
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-25052);

label_80113104:
    ctx->pc = 0x80113104u;
    // 80113104: stw     r30, 448(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(448);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80113108:
    ctx->pc = 0x80113108u;
    // 80113108: stw     r30, 460(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(460);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8011310C:
    ctx->pc = 0x8011310Cu;
    // 8011310C: stw     r30, 464(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(464);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80113110:
    ctx->pc = 0x80113110u;
    // 80113110: bl      0x80100114
    {
            ctx->lr = 0x80113114u;
            ctx->pc = 0x80100114u;
            return;
    }

label_80113114:
    ctx->pc = 0x80113114u;
    ctx->downcount -= 11;
    // 80113114: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80113118:
    ctx->pc = 0x80113118u;
    // 80113118: stfs     f1, 496(r31)
    if (!ppc_fp_available_inline(ctx, 0x80113118u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(496);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8011311C:
    ctx->pc = 0x8011311Cu;
    // 8011311C: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80113120:
    ctx->pc = 0x80113120u;
    // 80113120: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_80113124:
    ctx->pc = 0x80113124u;
    // 80113124: lfs     f1, 7056(r9)
    if (!ppc_fp_available_inline(ctx, 0x80113124u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(7056);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80113128:
    ctx->pc = 0x80113128u;
    // 80113128: addi    r3, r13, -27412
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-27412);

label_8011312C:
    ctx->pc = 0x8011312Cu;
    // 8011312C: stw     r30, 664(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(664);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80113130:
    ctx->pc = 0x80113130u;
    // 80113130: stw     r30, 468(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(468);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80113134:
    ctx->pc = 0x80113134u;
    // 80113134: stw     r0, 516(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(516);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80113138:
    ctx->pc = 0x80113138u;
    // 80113138: stw     r11, 488(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8011313C:
    ctx->pc = 0x8011313Cu;
    // 8011313C: bl      0x801DBF68
    {
            ctx->lr = 0x80113140u;
            ctx->pc = 0x801DBF68u;
            return;
    }

label_80113140:
    ctx->pc = 0x80113140u;
    ctx->downcount -= 7;
    // 80113140: lis     r9, -32721
    ctx->gpr[9] = ((u32)(s32)(-32721) << 16);

label_80113144:
    ctx->pc = 0x80113144u;
    // 80113144: addi    r29, r29, -25052
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-25052);

label_80113148:
    ctx->pc = 0x80113148u;
    // 80113148: lfs     f0, 7060(r9)
    if (!ppc_fp_available_inline(ctx, 0x80113148u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(7060);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8011314C:
    ctx->pc = 0x8011314Cu;
    // 8011314C: stfs     f0, 452(r31)
    if (!ppc_fp_available_inline(ctx, 0x8011314Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(452);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80113150:
    ctx->pc = 0x80113150u;
    // 80113150: lwz     r0, 3328(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3328);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80113154:
    ctx->pc = 0x80113154u;
    // 80113154: cmpwi   r0, 0
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

label_80113158:
    ctx->pc = 0x80113158u;
    // 80113158: bc    4, 2, 0x80113168
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80113168;
        }
    }

label_8011315C:
    ctx->pc = 0x8011315Cu;
    ctx->downcount -= 2;
    // 8011315C: lwz     r3, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113160:
    ctx->pc = 0x80113160u;
    // 80113160: bl      0x800ED368
    {
            ctx->lr = 0x80113164u;
            ctx->pc = 0x800ED368u;
            return;
    }

label_80113164:
    ctx->pc = 0x80113164u;
    ctx->downcount -= 1;
    // 80113164: b       0x80113180
    {
            goto label_80113180;
    }

label_80113168:
    ctx->pc = 0x80113168u;
    ctx->downcount -= 6;
    // 80113168: lfs     f0, 496(r31)
    if (!ppc_fp_available_inline(ctx, 0x80113168u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(496);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8011316C:
    ctx->pc = 0x8011316Cu;
    // 8011316C: lwz     r3, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113170:
    ctx->pc = 0x80113170u;
    // 80113170: fctiwz    f13, f0
    if (!ppc_fp_available_inline(ctx, 0x80113170u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80113174:
    ctx->pc = 0x80113174u;
    // 80113174: stfd     f13, 1240(r1)
    if (!ppc_fp_available_inline(ctx, 0x80113174u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1240);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80113178:
    ctx->pc = 0x80113178u;
    // 80113178: lwz     r4, 1244(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1244);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8011317C:
    ctx->pc = 0x8011317Cu;
    // 8011317C: bl      0x800EC7D0
    {
            ctx->lr = 0x80113180u;
            ctx->pc = 0x800EC7D0u;
            return;
    }

label_80113180:
    ctx->pc = 0x80113180u;
    ctx->downcount -= 3;
    // 80113180: lwz     r11, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80113184:
    ctx->pc = 0x80113184u;
    // 80113184: cmpwi   r11, 0
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

label_80113188:
    ctx->pc = 0x80113188u;
    // 80113188: bc    12, 2, 0x801131A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801131A8;
        }
    }

label_8011318C:
    ctx->pc = 0x8011318Cu;
    ctx->downcount -= 8;
    // 8011318C: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80113190:
    ctx->pc = 0x80113190u;
    // 80113190: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80113194:
    ctx->pc = 0x80113194u;
    // 80113194: lha     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80113198:
    ctx->pc = 0x80113198u;
    // 80113198: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8011319C:
    ctx->pc = 0x8011319Cu;
    // 8011319C: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801131A0:
    ctx->pc = 0x801131A0u;
    // 801131A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801131A4:
    ctx->pc = 0x801131A4u;
    // 801131A4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801131A8u;
            ctx->pc = target;
            goto return_dispatch_8010F4C0;
        }
    }

label_801131A8:
    ctx->pc = 0x801131A8u;
    ctx->downcount -= 3;
    // 801131A8: li      r3, 24
    ctx->gpr[3] = (u32)(s32)(24);

label_801131AC:
    ctx->pc = 0x801131ACu;
    // 801131AC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801131B0:
    ctx->pc = 0x801131B0u;
    // 801131B0: bl      0x80281C60
    {
            ctx->lr = 0x801131B4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_801131B4:
    ctx->pc = 0x801131B4u;
    ctx->downcount -= 5;
    // 801131B4: addi    r29, r1, 16
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(16);

label_801131B8:
    ctx->pc = 0x801131B8u;
    // 801131B8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801131BC:
    ctx->pc = 0x801131BCu;
    // 801131BC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801131C0:
    ctx->pc = 0x801131C0u;
    // 801131C0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801131C4:
    ctx->pc = 0x801131C4u;
    // 801131C4: bl      0x801B1ED0
    {
            ctx->lr = 0x801131C8u;
            ctx->pc = 0x801B1ED0u;
            return;
    }

label_801131C8:
    ctx->pc = 0x801131C8u;
    ctx->downcount -= 6;
    // 801131C8: stw     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801131CC:
    ctx->pc = 0x801131CCu;
    // 801131CC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801131D0:
    ctx->pc = 0x801131D0u;
    // 801131D0: addi    r28, r1, 96
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(96);

label_801131D4:
    ctx->pc = 0x801131D4u;
    // 801131D4: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_801131D8:
    ctx->pc = 0x801131D8u;
    // 801131D8: addi    r4, r4, 6568
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6568);

label_801131DC:
    ctx->pc = 0x801131DCu;
    // 801131DC: bl      0x801CFE08
    {
            ctx->lr = 0x801131E0u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801131E0:
    ctx->pc = 0x801131E0u;
    ctx->downcount -= 21;
    // 801131E0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801131E4:
    ctx->pc = 0x801131E4u;
    // 801131E4: addi    r27, r1, 176
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(176);

label_801131E8:
    ctx->pc = 0x801131E8u;
    // 801131E8: addi    r25, r1, 256
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(256);

label_801131EC:
    ctx->pc = 0x801131ECu;
    // 801131EC: addi    r26, r1, 816
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(816);

label_801131F0:
    ctx->pc = 0x801131F0u;
    // 801131F0: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_801131F4:
    ctx->pc = 0x801131F4u;
    // 801131F4: stb     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_801131F8:
    ctx->pc = 0x801131F8u;
    // 801131F8: stb     r30, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_801131FC:
    ctx->pc = 0x801131FCu;
    // 801131FC: addi    r24, r1, 896
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(896);

label_80113200:
    ctx->pc = 0x80113200u;
    // 80113200: stb     r30, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_80113204:
    ctx->pc = 0x80113204u;
    // 80113204: addi    r4, r4, 6576
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6576);

label_80113208:
    ctx->pc = 0x80113208u;
    // 80113208: stb     r30, 256(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(256);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_8011320C:
    ctx->pc = 0x8011320Cu;
    // 8011320C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80113210:
    ctx->pc = 0x80113210u;
    // 80113210: stb     r30, 336(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(336);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_80113214:
    ctx->pc = 0x80113214u;
    // 80113214: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113218:
    ctx->pc = 0x80113218u;
    // 80113218: stb     r30, 416(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(416);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_8011321C:
    ctx->pc = 0x8011321Cu;
    // 8011321C: stb     r30, 496(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(496);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_80113220:
    ctx->pc = 0x80113220u;
    // 80113220: stb     r30, 576(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(576);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_80113224:
    ctx->pc = 0x80113224u;
    // 80113224: stb     r30, 656(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(656);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_80113228:
    ctx->pc = 0x80113228u;
    // 80113228: stb     r30, 736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(736);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_8011322C:
    ctx->pc = 0x8011322Cu;
    // 8011322C: stb     r30, 816(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(816);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_80113230:
    ctx->pc = 0x80113230u;
    // 80113230: bl      0x801B3618
    {
            ctx->lr = 0x80113234u;
            ctx->pc = 0x801B3618u;
            return;
    }

label_80113234:
    ctx->pc = 0x80113234u;
    ctx->downcount -= 6;
    // 80113234: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80113238:
    ctx->pc = 0x80113238u;
    // 80113238: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8011323C:
    ctx->pc = 0x8011323Cu;
    // 8011323C: addi    r4, r4, 6588
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6588);

label_80113240:
    ctx->pc = 0x80113240u;
    // 80113240: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80113244:
    ctx->pc = 0x80113244u;
    // 80113244: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113248:
    ctx->pc = 0x80113248u;
    // 80113248: bl      0x801B3618
    {
            ctx->lr = 0x8011324Cu;
            ctx->pc = 0x801B3618u;
            return;
    }

label_8011324C:
    ctx->pc = 0x8011324Cu;
    ctx->downcount -= 6;
    // 8011324C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80113250:
    ctx->pc = 0x80113250u;
    // 80113250: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80113254:
    ctx->pc = 0x80113254u;
    // 80113254: addi    r4, r4, 6596
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6596);

label_80113258:
    ctx->pc = 0x80113258u;
    // 80113258: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8011325C:
    ctx->pc = 0x8011325Cu;
    // 8011325C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113260:
    ctx->pc = 0x80113260u;
    // 80113260: bl      0x801B3618
    {
            ctx->lr = 0x80113264u;
            ctx->pc = 0x801B3618u;
            return;
    }

label_80113264:
    ctx->pc = 0x80113264u;
    ctx->downcount -= 6;
    // 80113264: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80113268:
    ctx->pc = 0x80113268u;
    // 80113268: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8011326C:
    ctx->pc = 0x8011326Cu;
    // 8011326C: addi    r4, r4, 6604
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6604);

label_80113270:
    ctx->pc = 0x80113270u;
    // 80113270: or   r5, r25, r25
    {
        ctx->gpr[5] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80113274:
    ctx->pc = 0x80113274u;
    // 80113274: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113278:
    ctx->pc = 0x80113278u;
    // 80113278: bl      0x801B3618
    {
            ctx->lr = 0x8011327Cu;
            ctx->pc = 0x801B3618u;
            return;
    }

label_8011327C:
    ctx->pc = 0x8011327Cu;
    ctx->downcount -= 6;
    // 8011327C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80113280:
    ctx->pc = 0x80113280u;
    // 80113280: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80113284:
    ctx->pc = 0x80113284u;
    // 80113284: addi    r4, r4, 6612
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6612);

label_80113288:
    ctx->pc = 0x80113288u;
    // 80113288: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8011328C:
    ctx->pc = 0x8011328Cu;
    // 8011328C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113290:
    ctx->pc = 0x80113290u;
    // 80113290: bl      0x801B3618
    {
            ctx->lr = 0x80113294u;
            ctx->pc = 0x801B3618u;
            return;
    }

label_80113294:
    ctx->pc = 0x80113294u;
    ctx->downcount -= 9;
    // 80113294: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113298:
    ctx->pc = 0x80113298u;
    // 80113298: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8011329C:
    ctx->pc = 0x8011329Cu;
    // 8011329C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801132A0:
    ctx->pc = 0x801132A0u;
    // 801132A0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801132A4:
    ctx->pc = 0x801132A4u;
    // 801132A4: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_801132A8:
    ctx->pc = 0x801132A8u;
    // 801132A8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801132AC:
    ctx->pc = 0x801132ACu;
    // 801132AC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801132B0:
    ctx->pc = 0x801132B0u;
    // 801132B0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801132B4:
    ctx->pc = 0x801132B4u;
    // 801132B4: bl      0x801B2180
    {
            ctx->lr = 0x801132B8u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_801132B8:
    ctx->pc = 0x801132B8u;
    ctx->downcount -= 10;
    // 801132B8: stw     r3, 532(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(532);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801132BC:
    ctx->pc = 0x801132BCu;
    // 801132BC: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801132C0:
    ctx->pc = 0x801132C0u;
    // 801132C0: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801132C4:
    ctx->pc = 0x801132C4u;
    // 801132C4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801132C8:
    ctx->pc = 0x801132C8u;
    // 801132C8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801132CC:
    ctx->pc = 0x801132CCu;
    // 801132CC: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_801132D0:
    ctx->pc = 0x801132D0u;
    // 801132D0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801132D4:
    ctx->pc = 0x801132D4u;
    // 801132D4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801132D8:
    ctx->pc = 0x801132D8u;
    // 801132D8: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801132DC:
    ctx->pc = 0x801132DCu;
    // 801132DC: bl      0x801B2180
    {
            ctx->lr = 0x801132E0u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_801132E0:
    ctx->pc = 0x801132E0u;
    ctx->downcount -= 10;
    // 801132E0: stw     r3, 536(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(536);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801132E4:
    ctx->pc = 0x801132E4u;
    // 801132E4: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801132E8:
    ctx->pc = 0x801132E8u;
    // 801132E8: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801132EC:
    ctx->pc = 0x801132ECu;
    // 801132EC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801132F0:
    ctx->pc = 0x801132F0u;
    // 801132F0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801132F4:
    ctx->pc = 0x801132F4u;
    // 801132F4: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_801132F8:
    ctx->pc = 0x801132F8u;
    // 801132F8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801132FC:
    ctx->pc = 0x801132FCu;
    // 801132FC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80113300:
    ctx->pc = 0x80113300u;
    // 80113300: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80113304:
    ctx->pc = 0x80113304u;
    // 80113304: bl      0x801B2180
    {
            ctx->lr = 0x80113308u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_80113308:
    ctx->pc = 0x80113308u;
    ctx->downcount -= 10;
    // 80113308: stw     r3, 540(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(540);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8011330C:
    ctx->pc = 0x8011330Cu;
    // 8011330C: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80113310:
    ctx->pc = 0x80113310u;
    // 80113310: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113314:
    ctx->pc = 0x80113314u;
    // 80113314: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80113318:
    ctx->pc = 0x80113318u;
    // 80113318: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8011331C:
    ctx->pc = 0x8011331Cu;
    // 8011331C: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_80113320:
    ctx->pc = 0x80113320u;
    // 80113320: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80113324:
    ctx->pc = 0x80113324u;
    // 80113324: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80113328:
    ctx->pc = 0x80113328u;
    // 80113328: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8011332C:
    ctx->pc = 0x8011332Cu;
    // 8011332C: bl      0x801B2180
    {
            ctx->lr = 0x80113330u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_80113330:
    ctx->pc = 0x80113330u;
    ctx->downcount -= 10;
    // 80113330: stw     r3, 544(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(544);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80113334:
    ctx->pc = 0x80113334u;
    // 80113334: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80113338:
    ctx->pc = 0x80113338u;
    // 80113338: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8011333C:
    ctx->pc = 0x8011333Cu;
    // 8011333C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80113340:
    ctx->pc = 0x80113340u;
    // 80113340: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113344:
    ctx->pc = 0x80113344u;
    // 80113344: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_80113348:
    ctx->pc = 0x80113348u;
    // 80113348: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8011334C:
    ctx->pc = 0x8011334Cu;
    // 8011334C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80113350:
    ctx->pc = 0x80113350u;
    // 80113350: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80113354:
    ctx->pc = 0x80113354u;
    // 80113354: bl      0x801B2180
    {
            ctx->lr = 0x80113358u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_80113358:
    ctx->pc = 0x80113358u;
    ctx->downcount -= 11;
    // 80113358: stw     r3, 548(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(548);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8011335C:
    ctx->pc = 0x8011335Cu;
    // 8011335C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80113360:
    ctx->pc = 0x80113360u;
    // 80113360: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113364:
    ctx->pc = 0x80113364u;
    // 80113364: addi    r4, r4, 6624
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6624);

label_80113368:
    ctx->pc = 0x80113368u;
    // 80113368: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8011336C:
    ctx->pc = 0x8011336Cu;
    // 8011336C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113370:
    ctx->pc = 0x80113370u;
    // 80113370: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_80113374:
    ctx->pc = 0x80113374u;
    // 80113374: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80113378:
    ctx->pc = 0x80113378u;
    // 80113378: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8011337C:
    ctx->pc = 0x8011337Cu;
    // 8011337C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80113380:
    ctx->pc = 0x80113380u;
    // 80113380: bl      0x801B2180
    {
            ctx->lr = 0x80113384u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_80113384:
    ctx->pc = 0x80113384u;
    ctx->downcount -= 11;
    // 80113384: stw     r3, 552(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(552);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80113388:
    ctx->pc = 0x80113388u;
    // 80113388: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8011338C:
    ctx->pc = 0x8011338Cu;
    // 8011338C: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113390:
    ctx->pc = 0x80113390u;
    // 80113390: addi    r4, r4, 6632
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6632);

label_80113394:
    ctx->pc = 0x80113394u;
    // 80113394: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80113398:
    ctx->pc = 0x80113398u;
    // 80113398: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8011339C:
    ctx->pc = 0x8011339Cu;
    // 8011339C: li      r7, 9
    ctx->gpr[7] = (u32)(s32)(9);

label_801133A0:
    ctx->pc = 0x801133A0u;
    // 801133A0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801133A4:
    ctx->pc = 0x801133A4u;
    // 801133A4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801133A8:
    ctx->pc = 0x801133A8u;
    // 801133A8: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801133AC:
    ctx->pc = 0x801133ACu;
    // 801133AC: bl      0x801B2180
    {
            ctx->lr = 0x801133B0u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_801133B0:
    ctx->pc = 0x801133B0u;
    ctx->downcount -= 11;
    // 801133B0: stw     r3, 620(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(620);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801133B4:
    ctx->pc = 0x801133B4u;
    // 801133B4: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801133B8:
    ctx->pc = 0x801133B8u;
    // 801133B8: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801133BC:
    ctx->pc = 0x801133BCu;
    // 801133BC: addi    r4, r4, 6640
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6640);

label_801133C0:
    ctx->pc = 0x801133C0u;
    // 801133C0: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801133C4:
    ctx->pc = 0x801133C4u;
    // 801133C4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801133C8:
    ctx->pc = 0x801133C8u;
    // 801133C8: li      r7, 9
    ctx->gpr[7] = (u32)(s32)(9);

label_801133CC:
    ctx->pc = 0x801133CCu;
    // 801133CC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801133D0:
    ctx->pc = 0x801133D0u;
    // 801133D0: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801133D4:
    ctx->pc = 0x801133D4u;
    // 801133D4: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801133D8:
    ctx->pc = 0x801133D8u;
    // 801133D8: bl      0x801B2180
    {
            ctx->lr = 0x801133DCu;
            ctx->pc = 0x801B2180u;
            return;
    }

label_801133DC:
    ctx->pc = 0x801133DCu;
    ctx->downcount -= 11;
    // 801133DC: stw     r3, 624(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(624);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801133E0:
    ctx->pc = 0x801133E0u;
    // 801133E0: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_801133E4:
    ctx->pc = 0x801133E4u;
    // 801133E4: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801133E8:
    ctx->pc = 0x801133E8u;
    // 801133E8: addi    r4, r4, 6652
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6652);

label_801133EC:
    ctx->pc = 0x801133ECu;
    // 801133EC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801133F0:
    ctx->pc = 0x801133F0u;
    // 801133F0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801133F4:
    ctx->pc = 0x801133F4u;
    // 801133F4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_801133F8:
    ctx->pc = 0x801133F8u;
    // 801133F8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801133FC:
    ctx->pc = 0x801133FCu;
    // 801133FC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80113400:
    ctx->pc = 0x80113400u;
    // 80113400: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80113404:
    ctx->pc = 0x80113404u;
    // 80113404: bl      0x801B2180
    {
            ctx->lr = 0x80113408u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_80113408:
    ctx->pc = 0x80113408u;
    ctx->downcount -= 11;
    // 80113408: stw     r3, 628(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(628);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8011340C:
    ctx->pc = 0x8011340Cu;
    // 8011340C: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80113410:
    ctx->pc = 0x80113410u;
    // 80113410: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113414:
    ctx->pc = 0x80113414u;
    // 80113414: addi    r4, r4, 6664
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6664);

label_80113418:
    ctx->pc = 0x80113418u;
    // 80113418: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8011341C:
    ctx->pc = 0x8011341Cu;
    // 8011341C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113420:
    ctx->pc = 0x80113420u;
    // 80113420: li      r7, 9
    ctx->gpr[7] = (u32)(s32)(9);

label_80113424:
    ctx->pc = 0x80113424u;
    // 80113424: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80113428:
    ctx->pc = 0x80113428u;
    // 80113428: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8011342C:
    ctx->pc = 0x8011342Cu;
    // 8011342C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80113430:
    ctx->pc = 0x80113430u;
    // 80113430: bl      0x801B2180
    {
            ctx->lr = 0x80113434u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_80113434:
    ctx->pc = 0x80113434u;
    ctx->downcount -= 11;
    // 80113434: stw     r3, 632(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(632);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80113438:
    ctx->pc = 0x80113438u;
    // 80113438: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_8011343C:
    ctx->pc = 0x8011343Cu;
    // 8011343C: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113440:
    ctx->pc = 0x80113440u;
    // 80113440: addi    r4, r4, 6680
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6680);

label_80113444:
    ctx->pc = 0x80113444u;
    // 80113444: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80113448:
    ctx->pc = 0x80113448u;
    // 80113448: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8011344C:
    ctx->pc = 0x8011344Cu;
    // 8011344C: li      r7, 9
    ctx->gpr[7] = (u32)(s32)(9);

label_80113450:
    ctx->pc = 0x80113450u;
    // 80113450: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80113454:
    ctx->pc = 0x80113454u;
    // 80113454: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80113458:
    ctx->pc = 0x80113458u;
    // 80113458: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8011345C:
    ctx->pc = 0x8011345Cu;
    // 8011345C: bl      0x801B2180
    {
            ctx->lr = 0x80113460u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_80113460:
    ctx->pc = 0x80113460u;
    ctx->downcount -= 11;
    // 80113460: stw     r3, 636(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(636);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80113464:
    ctx->pc = 0x80113464u;
    // 80113464: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80113468:
    ctx->pc = 0x80113468u;
    // 80113468: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8011346C:
    ctx->pc = 0x8011346Cu;
    // 8011346C: addi    r4, r4, 6688
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6688);

label_80113470:
    ctx->pc = 0x80113470u;
    // 80113470: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80113474:
    ctx->pc = 0x80113474u;
    // 80113474: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80113478:
    ctx->pc = 0x80113478u;
    // 80113478: li      r7, 9
    ctx->gpr[7] = (u32)(s32)(9);

label_8011347C:
    ctx->pc = 0x8011347Cu;
    // 8011347C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80113480:
    ctx->pc = 0x80113480u;
    // 80113480: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80113484:
    ctx->pc = 0x80113484u;
    // 80113484: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80113488:
    ctx->pc = 0x80113488u;
    // 80113488: bl      0x801B2180
    {
            ctx->lr = 0x8011348Cu;
            ctx->pc = 0x801B2180u;
            return;
    }

label_8011348C:
    ctx->pc = 0x8011348Cu;
    ctx->downcount -= 11;
    // 8011348C: stw     r3, 640(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(640);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80113490:
    ctx->pc = 0x80113490u;
    // 80113490: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

label_80113494:
    ctx->pc = 0x80113494u;
    // 80113494: lwz     r3, 520(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(520);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80113498:
    ctx->pc = 0x80113498u;
    // 80113498: addi    r4, r4, 6700
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6700);

label_8011349C:
    ctx->pc = 0x8011349Cu;
    // 8011349C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801134A0:
    ctx->pc = 0x801134A0u;
    // 801134A0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801134A4:
    ctx->pc = 0x801134A4u;
    // 801134A4: li      r7, 9
    ctx->gpr[7] = (u32)(s32)(9);

label_801134A8:
    ctx->pc = 0x801134A8u;
    // 801134A8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801134AC:
    ctx->pc = 0x801134ACu;
    // 801134AC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801134B0:
    ctx->pc = 0x801134B0u;
    // 801134B0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801134B4:
    ctx->pc = 0x801134B4u;
    // 801134B4: bl      0x801B2180
    {
            ctx->lr = 0x801134B8u;
            ctx->pc = 0x801B2180u;
            return;
    }

label_801134B8:
    ctx->pc = 0x801134B8u;
    ctx->downcount -= 2;
    // 801134B8: stw     r3, 644(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(644);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801134BC:
    ctx->pc = 0x801134BCu;
    // 801134BC: lis     r4, -32721
    ctx->gpr[4] = ((u32)(s32)(-32721) << 16);

    ctx->pc = 0x801134C0u;
    return;
return_dispatch_8010F4C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8010F4D8u: goto label_8010F4D8;
    case 0x8010F4F8u: goto label_8010F4F8;
    case 0x8010F504u: goto label_8010F504;
    case 0x8010F510u: goto label_8010F510;
    case 0x8010F530u: goto label_8010F530;
    case 0x8010F550u: goto label_8010F550;
    case 0x8010F590u: goto label_8010F590;
    case 0x8010F59Cu: goto label_8010F59C;
    case 0x8010F5ACu: goto label_8010F5AC;
    case 0x8010F5B8u: goto label_8010F5B8;
    case 0x8010F628u: goto label_8010F628;
    case 0x8010F6A4u: goto label_8010F6A4;
    case 0x8010F6C4u: goto label_8010F6C4;
    case 0x8010F6E0u: goto label_8010F6E0;
    case 0x8010F6ECu: goto label_8010F6EC;
    case 0x8010F6F4u: goto label_8010F6F4;
    case 0x8010F700u: goto label_8010F700;
    case 0x8010F768u: goto label_8010F768;
    case 0x8010F7B8u: goto label_8010F7B8;
    case 0x8010F7D4u: goto label_8010F7D4;
    case 0x8010F7F4u: goto label_8010F7F4;
    case 0x8010F800u: goto label_8010F800;
    case 0x8010F81Cu: goto label_8010F81C;
    case 0x8010F834u: goto label_8010F834;
    case 0x8010F848u: goto label_8010F848;
    case 0x8010F86Cu: goto label_8010F86C;
    case 0x8010F87Cu: goto label_8010F87C;
    case 0x8010F898u: goto label_8010F898;
    case 0x8010F8B0u: goto label_8010F8B0;
    case 0x8010F8B4u: goto label_8010F8B4;
    case 0x8010F8BCu: goto label_8010F8BC;
    case 0x8010F990u: goto label_8010F990;
    case 0x8010F9E0u: goto label_8010F9E0;
    case 0x8010FA68u: goto label_8010FA68;
    case 0x8010FB1Cu: goto label_8010FB1C;
    case 0x8010FB30u: goto label_8010FB30;
    case 0x8010FB44u: goto label_8010FB44;
    case 0x8010FB58u: goto label_8010FB58;
    case 0x8010FB6Cu: goto label_8010FB6C;
    case 0x8010FB80u: goto label_8010FB80;
    case 0x8010FB94u: goto label_8010FB94;
    case 0x8010FBA8u: goto label_8010FBA8;
    case 0x8010FBBCu: goto label_8010FBBC;
    case 0x8010FBD0u: goto label_8010FBD0;
    case 0x8010FBE4u: goto label_8010FBE4;
    case 0x8010FBF8u: goto label_8010FBF8;
    case 0x8010FC5Cu: goto label_8010FC5C;
    case 0x8010FC6Cu: goto label_8010FC6C;
    case 0x8010FCB4u: goto label_8010FCB4;
    case 0x8010FDE8u: goto label_8010FDE8;
    case 0x8010FE00u: goto label_8010FE00;
    case 0x8010FE0Cu: goto label_8010FE0C;
    case 0x8010FE18u: goto label_8010FE18;
    case 0x8010FE44u: goto label_8010FE44;
    case 0x8010FE70u: goto label_8010FE70;
    case 0x8010FEC4u: goto label_8010FEC4;
    case 0x8010FED0u: goto label_8010FED0;
    case 0x8010FED8u: goto label_8010FED8;
    case 0x8011000Cu: goto label_8011000C;
    case 0x80110044u: goto label_80110044;
    case 0x80110070u: goto label_80110070;
    case 0x801100BCu: goto label_801100BC;
    case 0x8011011Cu: goto label_8011011C;
    case 0x80110134u: goto label_80110134;
    case 0x8011014Cu: goto label_8011014C;
    case 0x80110160u: goto label_80110160;
    case 0x80110170u: goto label_80110170;
    case 0x801101B4u: goto label_801101B4;
    case 0x801101F0u: goto label_801101F0;
    case 0x801101F4u: goto label_801101F4;
    case 0x801102CCu: goto label_801102CC;
    case 0x8011031Cu: goto label_8011031C;
    case 0x801103A4u: goto label_801103A4;
    case 0x801104B4u: goto label_801104B4;
    case 0x801104C4u: goto label_801104C4;
    case 0x801104D8u: goto label_801104D8;
    case 0x80110574u: goto label_80110574;
    case 0x80110588u: goto label_80110588;
    case 0x8011059Cu: goto label_8011059C;
    case 0x801105B0u: goto label_801105B0;
    case 0x8011068Cu: goto label_8011068C;
    case 0x801106B8u: goto label_801106B8;
    case 0x801106E4u: goto label_801106E4;
    case 0x80110730u: goto label_80110730;
    case 0x80110748u: goto label_80110748;
    case 0x80110754u: goto label_80110754;
    case 0x80110760u: goto label_80110760;
    case 0x80110768u: goto label_80110768;
    case 0x80110798u: goto label_80110798;
    case 0x801107CCu: goto label_801107CC;
    case 0x801107D4u: goto label_801107D4;
    case 0x8011084Cu: goto label_8011084C;
    case 0x8011085Cu: goto label_8011085C;
    case 0x80110874u: goto label_80110874;
    case 0x801108D4u: goto label_801108D4;
    case 0x8011092Cu: goto label_8011092C;
    case 0x80110938u: goto label_80110938;
    case 0x80110944u: goto label_80110944;
    case 0x80110950u: goto label_80110950;
    case 0x8011095Cu: goto label_8011095C;
    case 0x8011098Cu: goto label_8011098C;
    case 0x80110994u: goto label_80110994;
    case 0x801109A0u: goto label_801109A0;
    case 0x801109CCu: goto label_801109CC;
    case 0x80110A10u: goto label_80110A10;
    case 0x80110A30u: goto label_80110A30;
    case 0x80110A50u: goto label_80110A50;
    case 0x80110A70u: goto label_80110A70;
    case 0x80110A88u: goto label_80110A88;
    case 0x80110A9Cu: goto label_80110A9C;
    case 0x80110ACCu: goto label_80110ACC;
    case 0x80110AE4u: goto label_80110AE4;
    case 0x80110B04u: goto label_80110B04;
    case 0x80110B34u: goto label_80110B34;
    case 0x80110B4Cu: goto label_80110B4C;
    case 0x80110B7Cu: goto label_80110B7C;
    case 0x80110B94u: goto label_80110B94;
    case 0x80110BECu: goto label_80110BEC;
    case 0x80110C68u: goto label_80110C68;
    case 0x80110CA0u: goto label_80110CA0;
    case 0x80110CACu: goto label_80110CAC;
    case 0x80110CC0u: goto label_80110CC0;
    case 0x80110CD4u: goto label_80110CD4;
    case 0x80110CE8u: goto label_80110CE8;
    case 0x80110D08u: goto label_80110D08;
    case 0x80110D28u: goto label_80110D28;
    case 0x80110D48u: goto label_80110D48;
    case 0x80110D78u: goto label_80110D78;
    case 0x80110D90u: goto label_80110D90;
    case 0x80110DC0u: goto label_80110DC0;
    case 0x80110DD8u: goto label_80110DD8;
    case 0x80110E08u: goto label_80110E08;
    case 0x80110E20u: goto label_80110E20;
    case 0x80110E50u: goto label_80110E50;
    case 0x80110E68u: goto label_80110E68;
    case 0x80110E80u: goto label_80110E80;
    case 0x80110E94u: goto label_80110E94;
    case 0x80110EACu: goto label_80110EAC;
    case 0x80110EC0u: goto label_80110EC0;
    case 0x80110ED8u: goto label_80110ED8;
    case 0x80110EECu: goto label_80110EEC;
    case 0x80110F04u: goto label_80110F04;
    case 0x80110F18u: goto label_80110F18;
    case 0x80110F2Cu: goto label_80110F2C;
    case 0x80110F40u: goto label_80110F40;
    case 0x80110F78u: goto label_80110F78;
    case 0x80110FA4u: goto label_80110FA4;
    case 0x80110FD0u: goto label_80110FD0;
    case 0x80111000u: goto label_80111000;
    case 0x80111030u: goto label_80111030;
    case 0x80111060u: goto label_80111060;
    case 0x80111084u: goto label_80111084;
    case 0x801110BCu: goto label_801110BC;
    case 0x801110E8u: goto label_801110E8;
    case 0x80111118u: goto label_80111118;
    case 0x80111148u: goto label_80111148;
    case 0x80111178u: goto label_80111178;
    case 0x8011119Cu: goto label_8011119C;
    case 0x801111D4u: goto label_801111D4;
    case 0x80111204u: goto label_80111204;
    case 0x80111234u: goto label_80111234;
    case 0x80111264u: goto label_80111264;
    case 0x80111294u: goto label_80111294;
    case 0x801112C4u: goto label_801112C4;
    case 0x801112F0u: goto label_801112F0;
    case 0x80111320u: goto label_80111320;
    case 0x80111344u: goto label_80111344;
    case 0x8011137Cu: goto label_8011137C;
    case 0x801113B0u: goto label_801113B0;
    case 0x801113F0u: goto label_801113F0;
    case 0x80111438u: goto label_80111438;
    case 0x80111468u: goto label_80111468;
    case 0x80111498u: goto label_80111498;
    case 0x801114C8u: goto label_801114C8;
    case 0x80111508u: goto label_80111508;
    case 0x8011154Cu: goto label_8011154C;
    case 0x80111590u: goto label_80111590;
    case 0x801115C0u: goto label_801115C0;
    case 0x80111604u: goto label_80111604;
    case 0x8011163Cu: goto label_8011163C;
    case 0x80111654u: goto label_80111654;
    case 0x8011165Cu: goto label_8011165C;
    case 0x80111680u: goto label_80111680;
    case 0x801116C4u: goto label_801116C4;
    case 0x801116D4u: goto label_801116D4;
    case 0x801116D8u: goto label_801116D8;
    case 0x801116E8u: goto label_801116E8;
    case 0x801116F4u: goto label_801116F4;
    case 0x80111704u: goto label_80111704;
    case 0x80111710u: goto label_80111710;
    case 0x80111714u: goto label_80111714;
    case 0x801117BCu: goto label_801117BC;
    case 0x801117D0u: goto label_801117D0;
    case 0x801117D8u: goto label_801117D8;
    case 0x801117ECu: goto label_801117EC;
    case 0x801117F0u: goto label_801117F0;
    case 0x801117F8u: goto label_801117F8;
    case 0x80111800u: goto label_80111800;
    case 0x8011180Cu: goto label_8011180C;
    case 0x80111810u: goto label_80111810;
    case 0x8011182Cu: goto label_8011182C;
    case 0x80111834u: goto label_80111834;
    case 0x80111840u: goto label_80111840;
    case 0x8011184Cu: goto label_8011184C;
    case 0x80111850u: goto label_80111850;
    case 0x80111864u: goto label_80111864;
    case 0x80111874u: goto label_80111874;
    case 0x80111878u: goto label_80111878;
    case 0x80111890u: goto label_80111890;
    case 0x801118F8u: goto label_801118F8;
    case 0x80111920u: goto label_80111920;
    case 0x80111924u: goto label_80111924;
    case 0x80111928u: goto label_80111928;
    case 0x80111934u: goto label_80111934;
    case 0x80111938u: goto label_80111938;
    case 0x80111970u: goto label_80111970;
    case 0x8011197Cu: goto label_8011197C;
    case 0x80111980u: goto label_80111980;
    case 0x801119D4u: goto label_801119D4;
    case 0x80111A28u: goto label_80111A28;
    case 0x80111A44u: goto label_80111A44;
    case 0x80111A5Cu: goto label_80111A5C;
    case 0x80111B1Cu: goto label_80111B1C;
    case 0x80111B64u: goto label_80111B64;
    case 0x80111B80u: goto label_80111B80;
    case 0x80111BA8u: goto label_80111BA8;
    case 0x80111C30u: goto label_80111C30;
    case 0x80111CA0u: goto label_80111CA0;
    case 0x80111CACu: goto label_80111CAC;
    case 0x80111D3Cu: goto label_80111D3C;
    case 0x80111D54u: goto label_80111D54;
    case 0x80111D84u: goto label_80111D84;
    case 0x80111E60u: goto label_80111E60;
    case 0x80111EB0u: goto label_80111EB0;
    case 0x80111F38u: goto label_80111F38;
    case 0x80111FECu: goto label_80111FEC;
    case 0x80112000u: goto label_80112000;
    case 0x80112014u: goto label_80112014;
    case 0x80112028u: goto label_80112028;
    case 0x8011203Cu: goto label_8011203C;
    case 0x80112050u: goto label_80112050;
    case 0x80112064u: goto label_80112064;
    case 0x80112078u: goto label_80112078;
    case 0x8011208Cu: goto label_8011208C;
    case 0x801120A0u: goto label_801120A0;
    case 0x801120C0u: goto label_801120C0;
    case 0x801120E0u: goto label_801120E0;
    case 0x80112100u: goto label_80112100;
    case 0x801121A8u: goto label_801121A8;
    case 0x801121E0u: goto label_801121E0;
    case 0x80112248u: goto label_80112248;
    case 0x80112250u: goto label_80112250;
    case 0x80112284u: goto label_80112284;
    case 0x801122FCu: goto label_801122FC;
    case 0x8011231Cu: goto label_8011231C;
    case 0x80112334u: goto label_80112334;
    case 0x80112348u: goto label_80112348;
    case 0x801123BCu: goto label_801123BC;
    case 0x80112424u: goto label_80112424;
    case 0x80112464u: goto label_80112464;
    case 0x801124BCu: goto label_801124BC;
    case 0x80112544u: goto label_80112544;
    case 0x8011258Cu: goto label_8011258C;
    case 0x801125D4u: goto label_801125D4;
    case 0x8011261Cu: goto label_8011261C;
    case 0x8011265Cu: goto label_8011265C;
    case 0x8011269Cu: goto label_8011269C;
    case 0x801126DCu: goto label_801126DC;
    case 0x8011271Cu: goto label_8011271C;
    case 0x8011275Cu: goto label_8011275C;
    case 0x8011279Cu: goto label_8011279C;
    case 0x801127ACu: goto label_801127AC;
    case 0x801127C0u: goto label_801127C0;
    case 0x801127D4u: goto label_801127D4;
    case 0x801127E0u: goto label_801127E0;
    case 0x80112804u: goto label_80112804;
    case 0x80112818u: goto label_80112818;
    case 0x8011282Cu: goto label_8011282C;
    case 0x801128ACu: goto label_801128AC;
    case 0x801128B8u: goto label_801128B8;
    case 0x801128C4u: goto label_801128C4;
    case 0x801128D0u: goto label_801128D0;
    case 0x801128F4u: goto label_801128F4;
    case 0x80112914u: goto label_80112914;
    case 0x80112928u: goto label_80112928;
    case 0x80112944u: goto label_80112944;
    case 0x80112950u: goto label_80112950;
    case 0x8011297Cu: goto label_8011297C;
    case 0x80112990u: goto label_80112990;
    case 0x801129A8u: goto label_801129A8;
    case 0x80112A00u: goto label_80112A00;
    case 0x80112A94u: goto label_80112A94;
    case 0x80112AACu: goto label_80112AAC;
    case 0x80112B60u: goto label_80112B60;
    case 0x80112B94u: goto label_80112B94;
    case 0x80112BB4u: goto label_80112BB4;
    case 0x80112BB8u: goto label_80112BB8;
    case 0x80112BC8u: goto label_80112BC8;
    case 0x80112C1Cu: goto label_80112C1C;
    case 0x80112C24u: goto label_80112C24;
    case 0x80112C3Cu: goto label_80112C3C;
    case 0x80112C48u: goto label_80112C48;
    case 0x80112C54u: goto label_80112C54;
    case 0x80112C60u: goto label_80112C60;
    case 0x80112C6Cu: goto label_80112C6C;
    case 0x80112C7Cu: goto label_80112C7C;
    case 0x80112CACu: goto label_80112CAC;
    case 0x80112CB8u: goto label_80112CB8;
    case 0x80112CC4u: goto label_80112CC4;
    case 0x80112CECu: goto label_80112CEC;
    case 0x80112CF8u: goto label_80112CF8;
    case 0x80112D0Cu: goto label_80112D0C;
    case 0x80112D34u: goto label_80112D34;
    case 0x80112D3Cu: goto label_80112D3C;
    case 0x80112D64u: goto label_80112D64;
    case 0x80112D6Cu: goto label_80112D6C;
    case 0x80112D78u: goto label_80112D78;
    case 0x80112D84u: goto label_80112D84;
    case 0x80112D94u: goto label_80112D94;
    case 0x80112E10u: goto label_80112E10;
    case 0x80112E2Cu: goto label_80112E2C;
    case 0x80112ED8u: goto label_80112ED8;
    case 0x80112EECu: goto label_80112EEC;
    case 0x80112EFCu: goto label_80112EFC;
    case 0x80112F0Cu: goto label_80112F0C;
    case 0x80112F24u: goto label_80112F24;
    case 0x80112F38u: goto label_80112F38;
    case 0x80112F40u: goto label_80112F40;
    case 0x80112F5Cu: goto label_80112F5C;
    case 0x80112F7Cu: goto label_80112F7C;
    case 0x80112F88u: goto label_80112F88;
    case 0x80112FA4u: goto label_80112FA4;
    case 0x80112FFCu: goto label_80112FFC;
    case 0x8011306Cu: goto label_8011306C;
    case 0x80113090u: goto label_80113090;
    case 0x801130E0u: goto label_801130E0;
    case 0x801130F0u: goto label_801130F0;
    case 0x801130F4u: goto label_801130F4;
    case 0x80113114u: goto label_80113114;
    case 0x80113140u: goto label_80113140;
    case 0x80113164u: goto label_80113164;
    case 0x80113180u: goto label_80113180;
    case 0x801131A8u: goto label_801131A8;
    case 0x801131B4u: goto label_801131B4;
    case 0x801131C8u: goto label_801131C8;
    case 0x801131E0u: goto label_801131E0;
    case 0x80113234u: goto label_80113234;
    case 0x8011324Cu: goto label_8011324C;
    case 0x80113264u: goto label_80113264;
    case 0x8011327Cu: goto label_8011327C;
    case 0x80113294u: goto label_80113294;
    case 0x801132B8u: goto label_801132B8;
    case 0x801132E0u: goto label_801132E0;
    case 0x80113308u: goto label_80113308;
    case 0x80113330u: goto label_80113330;
    case 0x80113358u: goto label_80113358;
    case 0x80113384u: goto label_80113384;
    case 0x801133B0u: goto label_801133B0;
    case 0x801133DCu: goto label_801133DC;
    case 0x80113408u: goto label_80113408;
    case 0x80113434u: goto label_80113434;
    case 0x80113460u: goto label_80113460;
    case 0x8011348Cu: goto label_8011348C;
    case 0x801134B8u: goto label_801134B8;
    default: return;
    }
}

