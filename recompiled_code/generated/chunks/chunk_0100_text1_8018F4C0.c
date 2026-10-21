// DolRecomp output
#include "../generated.h"

static void loop_8018FE38(CPUState* ctx) {
label_8018FE38:
    ctx->downcount -= 3;
    // 8018FE38: addi    r9, r9, 260
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(260);

    // 8018FE3C: cmpw    r9, r11
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

    // 8018FE40: bc    4, 2, 0x8018FE38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FE38u;
                return;
            }
            goto label_8018FE38;
        }
    }

    ctx->pc = 0x8018FE44u;
}

static void loop_8018FFF4(CPUState* ctx) {
label_8018FFF4:
    ctx->downcount -= 16;
    ctx->pc = 0x8018FFF4u;
    // 8018FFF4: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 8018FFF8: addic.  r8, r8, -24
    {
        u64 a = ctx->gpr[8];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    ctx->pc = 0x8018FFFCu;
    // 8018FFFC: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190000u;
    // 80190000: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80190004u;
    // 80190004: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190008u;
    // 80190008: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8019000Cu;
    // 8019000C: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190010u;
    // 80190010: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80190014u;
    // 80190014: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190018u;
    // 80190018: lwz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8019001Cu;
    // 8019001C: stw     r9, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190020u;
    // 80190020: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80190024: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

    ctx->pc = 0x80190028u;
    // 80190028: stw     r9, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    // 8019002C: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

    // 80190030: bc    4, 2, 0x8018FFF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FFF4u;
                return;
            }
            goto label_8018FFF4;
        }
    }

    ctx->pc = 0x80190034u;
}

static void loop_8019010C(CPUState* ctx) {
label_8019010C:
    ctx->downcount -= 16;
    ctx->pc = 0x8019010Cu;
    // 8019010C: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80190110: addic.  r8, r8, -24
    {
        u64 a = ctx->gpr[8];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    ctx->pc = 0x80190114u;
    // 80190114: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190118u;
    // 80190118: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8019011Cu;
    // 8019011C: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190120u;
    // 80190120: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80190124u;
    // 80190124: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190128u;
    // 80190128: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8019012Cu;
    // 8019012C: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190130u;
    // 80190130: lwz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80190134u;
    // 80190134: stw     r9, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190138u;
    // 80190138: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 8019013C: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

    ctx->pc = 0x80190140u;
    // 80190140: stw     r9, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    // 80190144: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

    // 80190148: bc    4, 2, 0x8019010C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019010Cu;
                return;
            }
            goto label_8019010C;
        }
    }

    ctx->pc = 0x8019014Cu;
}

static void loop_801901F4(CPUState* ctx) {
label_801901F4:
    ctx->downcount -= 16;
    ctx->pc = 0x801901F4u;
    // 801901F4: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 801901F8: addic.  r8, r8, -24
    {
        u64 a = ctx->gpr[8];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    ctx->pc = 0x801901FCu;
    // 801901FC: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190200u;
    // 80190200: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80190204u;
    // 80190204: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190208u;
    // 80190208: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8019020Cu;
    // 8019020C: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190210u;
    // 80190210: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80190214u;
    // 80190214: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190218u;
    // 80190218: lwz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8019021Cu;
    // 8019021C: stw     r9, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190220u;
    // 80190220: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80190224: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

    ctx->pc = 0x80190228u;
    // 80190228: stw     r9, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    // 8019022C: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

    // 80190230: bc    4, 2, 0x801901F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801901F4u;
                return;
            }
            goto label_801901F4;
        }
    }

    ctx->pc = 0x80190234u;
}

static void loop_801903A8(CPUState* ctx) {
label_801903A8:
    ctx->downcount -= 3;
    // 801903A8: addi    r9, r9, 136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(136);

    // 801903AC: cmpw    r9, r0
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

    // 801903B0: bc    4, 2, 0x801903A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801903A8u;
                return;
            }
            goto label_801903A8;
        }
    }

    ctx->pc = 0x801903B4u;
}

static void loop_80190400(CPUState* ctx) {
label_80190400:
    ctx->downcount -= 3;
    // 80190400: addi    r9, r9, 136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(136);

    // 80190404: cmpw    r9, r0
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

    // 80190408: bc    4, 2, 0x80190400
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190400u;
                return;
            }
            goto label_80190400;
        }
    }

    ctx->pc = 0x8019040Cu;
}

static void loop_80190458(CPUState* ctx) {
label_80190458:
    ctx->downcount -= 3;
    // 80190458: addi    r9, r9, 136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(136);

    // 8019045C: cmpw    r9, r0
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

    // 80190460: bc    4, 2, 0x80190458
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190458u;
                return;
            }
            goto label_80190458;
        }
    }

    ctx->pc = 0x80190464u;
}

static void loop_801904B0(CPUState* ctx) {
label_801904B0:
    ctx->downcount -= 3;
    // 801904B0: addi    r9, r9, 884
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(884);

    // 801904B4: cmpw    r9, r0
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

    // 801904B8: bc    4, 2, 0x801904B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801904B0u;
                return;
            }
            goto label_801904B0;
        }
    }

    ctx->pc = 0x801904BCu;
}

static void loop_80190600(CPUState* ctx) {
label_80190600:
    ctx->downcount -= 3;
    // 80190600: addi    r9, r9, 260
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(260);

    // 80190604: cmpw    r9, r0
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

    // 80190608: bc    4, 2, 0x80190600
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190600u;
                return;
            }
            goto label_80190600;
        }
    }

    ctx->pc = 0x8019060Cu;
}

static void loop_801906EC(CPUState* ctx) {
label_801906EC:
    ctx->downcount -= 16;
    ctx->pc = 0x801906ECu;
    // 801906EC: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 801906F0: addic.  r8, r8, -24
    {
        u64 a = ctx->gpr[8];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    ctx->pc = 0x801906F4u;
    // 801906F4: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x801906F8u;
    // 801906F8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x801906FCu;
    // 801906FC: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190700u;
    // 80190700: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80190704u;
    // 80190704: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190708u;
    // 80190708: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8019070Cu;
    // 8019070C: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190710u;
    // 80190710: lwz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80190714u;
    // 80190714: stw     r9, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x80190718u;
    // 80190718: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 8019071C: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

    ctx->pc = 0x80190720u;
    // 80190720: stw     r9, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    // 80190724: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

    // 80190728: bc    4, 2, 0x801906EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801906ECu;
                return;
            }
            goto label_801906EC;
        }
    }

    ctx->pc = 0x8019072Cu;
}

static void loop_8019078C(CPUState* ctx) {
label_8019078C:
    ctx->downcount -= 3;
    // 8019078C: addi    r9, r9, 136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(136);

    // 80190790: cmpw    r9, r0
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

    // 80190794: bc    4, 2, 0x8019078C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019078Cu;
                return;
            }
            goto label_8019078C;
        }
    }

    ctx->pc = 0x80190798u;
}

static void loop_80190898(CPUState* ctx) {
label_80190898:
    ctx->downcount -= 3;
    // 80190898: addi    r9, r9, 884
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(884);

    // 8019089C: cmpw    r9, r0
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

    // 801908A0: bc    4, 2, 0x80190898
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190898u;
                return;
            }
            goto label_80190898;
        }
    }

    ctx->pc = 0x801908A4u;
}

static void loop_80190E74(CPUState* ctx) {
label_80190E74:
    ctx->downcount -= 3;
    // 80190E74: addi    r11, r11, 136
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(136);

    // 80190E78: cmpw    r11, r0
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

    // 80190E7C: bc    4, 2, 0x80190E74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190E74u;
                return;
            }
            goto label_80190E74;
        }
    }

    ctx->pc = 0x80190E80u;
}

static void loop_80191D54(CPUState* ctx) {
label_80191D54:
    ctx->downcount -= 3;
    // 80191D54: addi    r11, r11, 884
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(884);

    // 80191D58: cmpw    r11, r0
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

    // 80191D5C: bc    4, 2, 0x80191D54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80191D54u;
                return;
            }
            goto label_80191D54;
        }
    }

    ctx->pc = 0x80191D60u;
}

static void loop_80192048(CPUState* ctx) {
label_80192048:
    ctx->downcount -= 3;
    // 80192048: addi    r11, r11, 884
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(884);

    // 8019204C: cmpw    r11, r0
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

    // 80192050: bc    4, 2, 0x80192048
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80192048u;
                return;
            }
            goto label_80192048;
        }
    }

    ctx->pc = 0x80192054u;
}

void func_8018F4C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8018F4C0u: goto label_8018F4C0;
    case 0x8018F4C4u: goto label_8018F4C4;
    case 0x8018F4C8u: goto label_8018F4C8;
    case 0x8018F4CCu: goto label_8018F4CC;
    case 0x8018F4D0u: goto label_8018F4D0;
    case 0x8018F4D4u: goto label_8018F4D4;
    case 0x8018F4D8u: goto label_8018F4D8;
    case 0x8018F4DCu: goto label_8018F4DC;
    case 0x8018F4E0u: goto label_8018F4E0;
    case 0x8018F4E4u: goto label_8018F4E4;
    case 0x8018F4E8u: goto label_8018F4E8;
    case 0x8018F4ECu: goto label_8018F4EC;
    case 0x8018F4F0u: goto label_8018F4F0;
    case 0x8018F4F4u: goto label_8018F4F4;
    case 0x8018F4F8u: goto label_8018F4F8;
    case 0x8018F4FCu: goto label_8018F4FC;
    case 0x8018F500u: goto label_8018F500;
    case 0x8018F504u: goto label_8018F504;
    case 0x8018F508u: goto label_8018F508;
    case 0x8018F50Cu: goto label_8018F50C;
    case 0x8018F510u: goto label_8018F510;
    case 0x8018F514u: goto label_8018F514;
    case 0x8018F518u: goto label_8018F518;
    case 0x8018F51Cu: goto label_8018F51C;
    case 0x8018F520u: goto label_8018F520;
    case 0x8018F524u: goto label_8018F524;
    case 0x8018F528u: goto label_8018F528;
    case 0x8018F52Cu: goto label_8018F52C;
    case 0x8018F530u: goto label_8018F530;
    case 0x8018F534u: goto label_8018F534;
    case 0x8018F538u: goto label_8018F538;
    case 0x8018F53Cu: goto label_8018F53C;
    case 0x8018F540u: goto label_8018F540;
    case 0x8018F544u: goto label_8018F544;
    case 0x8018F548u: goto label_8018F548;
    case 0x8018F54Cu: goto label_8018F54C;
    case 0x8018F550u: goto label_8018F550;
    case 0x8018F554u: goto label_8018F554;
    case 0x8018F558u: goto label_8018F558;
    case 0x8018F55Cu: goto label_8018F55C;
    case 0x8018F560u: goto label_8018F560;
    case 0x8018F564u: goto label_8018F564;
    case 0x8018F568u: goto label_8018F568;
    case 0x8018F56Cu: goto label_8018F56C;
    case 0x8018F570u: goto label_8018F570;
    case 0x8018F574u: goto label_8018F574;
    case 0x8018F578u: goto label_8018F578;
    case 0x8018F57Cu: goto label_8018F57C;
    case 0x8018F580u: goto label_8018F580;
    case 0x8018F584u: goto label_8018F584;
    case 0x8018F588u: goto label_8018F588;
    case 0x8018F58Cu: goto label_8018F58C;
    case 0x8018F590u: goto label_8018F590;
    case 0x8018F594u: goto label_8018F594;
    case 0x8018F598u: goto label_8018F598;
    case 0x8018F59Cu: goto label_8018F59C;
    case 0x8018F5A0u: goto label_8018F5A0;
    case 0x8018F5A4u: goto label_8018F5A4;
    case 0x8018F5A8u: goto label_8018F5A8;
    case 0x8018F5ACu: goto label_8018F5AC;
    case 0x8018F5B0u: goto label_8018F5B0;
    case 0x8018F5B4u: goto label_8018F5B4;
    case 0x8018F5B8u: goto label_8018F5B8;
    case 0x8018F5BCu: goto label_8018F5BC;
    case 0x8018F5C0u: goto label_8018F5C0;
    case 0x8018F5C4u: goto label_8018F5C4;
    case 0x8018F5C8u: goto label_8018F5C8;
    case 0x8018F5CCu: goto label_8018F5CC;
    case 0x8018F5D0u: goto label_8018F5D0;
    case 0x8018F5D4u: goto label_8018F5D4;
    case 0x8018F5D8u: goto label_8018F5D8;
    case 0x8018F5DCu: goto label_8018F5DC;
    case 0x8018F5E0u: goto label_8018F5E0;
    case 0x8018F5E4u: goto label_8018F5E4;
    case 0x8018F5E8u: goto label_8018F5E8;
    case 0x8018F5ECu: goto label_8018F5EC;
    case 0x8018F5F0u: goto label_8018F5F0;
    case 0x8018F5F4u: goto label_8018F5F4;
    case 0x8018F5F8u: goto label_8018F5F8;
    case 0x8018F5FCu: goto label_8018F5FC;
    case 0x8018F600u: goto label_8018F600;
    case 0x8018F604u: goto label_8018F604;
    case 0x8018F608u: goto label_8018F608;
    case 0x8018F60Cu: goto label_8018F60C;
    case 0x8018F610u: goto label_8018F610;
    case 0x8018F614u: goto label_8018F614;
    case 0x8018F618u: goto label_8018F618;
    case 0x8018F61Cu: goto label_8018F61C;
    case 0x8018F620u: goto label_8018F620;
    case 0x8018F624u: goto label_8018F624;
    case 0x8018F628u: goto label_8018F628;
    case 0x8018F62Cu: goto label_8018F62C;
    case 0x8018F630u: goto label_8018F630;
    case 0x8018F634u: goto label_8018F634;
    case 0x8018F638u: goto label_8018F638;
    case 0x8018F63Cu: goto label_8018F63C;
    case 0x8018F640u: goto label_8018F640;
    case 0x8018F644u: goto label_8018F644;
    case 0x8018F648u: goto label_8018F648;
    case 0x8018F64Cu: goto label_8018F64C;
    case 0x8018F650u: goto label_8018F650;
    case 0x8018F654u: goto label_8018F654;
    case 0x8018F658u: goto label_8018F658;
    case 0x8018F65Cu: goto label_8018F65C;
    case 0x8018F660u: goto label_8018F660;
    case 0x8018F664u: goto label_8018F664;
    case 0x8018F668u: goto label_8018F668;
    case 0x8018F66Cu: goto label_8018F66C;
    case 0x8018F670u: goto label_8018F670;
    case 0x8018F674u: goto label_8018F674;
    case 0x8018F678u: goto label_8018F678;
    case 0x8018F67Cu: goto label_8018F67C;
    case 0x8018F680u: goto label_8018F680;
    case 0x8018F684u: goto label_8018F684;
    case 0x8018F688u: goto label_8018F688;
    case 0x8018F68Cu: goto label_8018F68C;
    case 0x8018F690u: goto label_8018F690;
    case 0x8018F694u: goto label_8018F694;
    case 0x8018F698u: goto label_8018F698;
    case 0x8018F69Cu: goto label_8018F69C;
    case 0x8018F6A0u: goto label_8018F6A0;
    case 0x8018F6A4u: goto label_8018F6A4;
    case 0x8018F6A8u: goto label_8018F6A8;
    case 0x8018F6ACu: goto label_8018F6AC;
    case 0x8018F6B0u: goto label_8018F6B0;
    case 0x8018F6B4u: goto label_8018F6B4;
    case 0x8018F6B8u: goto label_8018F6B8;
    case 0x8018F6BCu: goto label_8018F6BC;
    case 0x8018F6C0u: goto label_8018F6C0;
    case 0x8018F6C4u: goto label_8018F6C4;
    case 0x8018F6C8u: goto label_8018F6C8;
    case 0x8018F6CCu: goto label_8018F6CC;
    case 0x8018F6D0u: goto label_8018F6D0;
    case 0x8018F6D4u: goto label_8018F6D4;
    case 0x8018F6D8u: goto label_8018F6D8;
    case 0x8018F6DCu: goto label_8018F6DC;
    case 0x8018F6E0u: goto label_8018F6E0;
    case 0x8018F6E4u: goto label_8018F6E4;
    case 0x8018F6E8u: goto label_8018F6E8;
    case 0x8018F6ECu: goto label_8018F6EC;
    case 0x8018F6F0u: goto label_8018F6F0;
    case 0x8018F6F4u: goto label_8018F6F4;
    case 0x8018F6F8u: goto label_8018F6F8;
    case 0x8018F6FCu: goto label_8018F6FC;
    case 0x8018F700u: goto label_8018F700;
    case 0x8018F704u: goto label_8018F704;
    case 0x8018F708u: goto label_8018F708;
    case 0x8018F70Cu: goto label_8018F70C;
    case 0x8018F710u: goto label_8018F710;
    case 0x8018F714u: goto label_8018F714;
    case 0x8018F718u: goto label_8018F718;
    case 0x8018F71Cu: goto label_8018F71C;
    case 0x8018F720u: goto label_8018F720;
    case 0x8018F724u: goto label_8018F724;
    case 0x8018F728u: goto label_8018F728;
    case 0x8018F72Cu: goto label_8018F72C;
    case 0x8018F730u: goto label_8018F730;
    case 0x8018F734u: goto label_8018F734;
    case 0x8018F738u: goto label_8018F738;
    case 0x8018F73Cu: goto label_8018F73C;
    case 0x8018F740u: goto label_8018F740;
    case 0x8018F744u: goto label_8018F744;
    case 0x8018F748u: goto label_8018F748;
    case 0x8018F74Cu: goto label_8018F74C;
    case 0x8018F750u: goto label_8018F750;
    case 0x8018F754u: goto label_8018F754;
    case 0x8018F758u: goto label_8018F758;
    case 0x8018F75Cu: goto label_8018F75C;
    case 0x8018F760u: goto label_8018F760;
    case 0x8018F764u: goto label_8018F764;
    case 0x8018F768u: goto label_8018F768;
    case 0x8018F76Cu: goto label_8018F76C;
    case 0x8018F770u: goto label_8018F770;
    case 0x8018F774u: goto label_8018F774;
    case 0x8018F778u: goto label_8018F778;
    case 0x8018F77Cu: goto label_8018F77C;
    case 0x8018F780u: goto label_8018F780;
    case 0x8018F784u: goto label_8018F784;
    case 0x8018F788u: goto label_8018F788;
    case 0x8018F78Cu: goto label_8018F78C;
    case 0x8018F790u: goto label_8018F790;
    case 0x8018F794u: goto label_8018F794;
    case 0x8018F798u: goto label_8018F798;
    case 0x8018F79Cu: goto label_8018F79C;
    case 0x8018F7A0u: goto label_8018F7A0;
    case 0x8018F7A4u: goto label_8018F7A4;
    case 0x8018F7A8u: goto label_8018F7A8;
    case 0x8018F7ACu: goto label_8018F7AC;
    case 0x8018F7B0u: goto label_8018F7B0;
    case 0x8018F7B4u: goto label_8018F7B4;
    case 0x8018F7B8u: goto label_8018F7B8;
    case 0x8018F7BCu: goto label_8018F7BC;
    case 0x8018F7C0u: goto label_8018F7C0;
    case 0x8018F7C4u: goto label_8018F7C4;
    case 0x8018F7C8u: goto label_8018F7C8;
    case 0x8018F7CCu: goto label_8018F7CC;
    case 0x8018F7D0u: goto label_8018F7D0;
    case 0x8018F7D4u: goto label_8018F7D4;
    case 0x8018F7D8u: goto label_8018F7D8;
    case 0x8018F7DCu: goto label_8018F7DC;
    case 0x8018F7E0u: goto label_8018F7E0;
    case 0x8018F7E4u: goto label_8018F7E4;
    case 0x8018F7E8u: goto label_8018F7E8;
    case 0x8018F7ECu: goto label_8018F7EC;
    case 0x8018F7F0u: goto label_8018F7F0;
    case 0x8018F7F4u: goto label_8018F7F4;
    case 0x8018F7F8u: goto label_8018F7F8;
    case 0x8018F7FCu: goto label_8018F7FC;
    case 0x8018F800u: goto label_8018F800;
    case 0x8018F804u: goto label_8018F804;
    case 0x8018F808u: goto label_8018F808;
    case 0x8018F80Cu: goto label_8018F80C;
    case 0x8018F810u: goto label_8018F810;
    case 0x8018F814u: goto label_8018F814;
    case 0x8018F818u: goto label_8018F818;
    case 0x8018F81Cu: goto label_8018F81C;
    case 0x8018F820u: goto label_8018F820;
    case 0x8018F824u: goto label_8018F824;
    case 0x8018F828u: goto label_8018F828;
    case 0x8018F82Cu: goto label_8018F82C;
    case 0x8018F830u: goto label_8018F830;
    case 0x8018F834u: goto label_8018F834;
    case 0x8018F838u: goto label_8018F838;
    case 0x8018F83Cu: goto label_8018F83C;
    case 0x8018F840u: goto label_8018F840;
    case 0x8018F844u: goto label_8018F844;
    case 0x8018F848u: goto label_8018F848;
    case 0x8018F84Cu: goto label_8018F84C;
    case 0x8018F850u: goto label_8018F850;
    case 0x8018F854u: goto label_8018F854;
    case 0x8018F858u: goto label_8018F858;
    case 0x8018F85Cu: goto label_8018F85C;
    case 0x8018F860u: goto label_8018F860;
    case 0x8018F864u: goto label_8018F864;
    case 0x8018F868u: goto label_8018F868;
    case 0x8018F86Cu: goto label_8018F86C;
    case 0x8018F870u: goto label_8018F870;
    case 0x8018F874u: goto label_8018F874;
    case 0x8018F878u: goto label_8018F878;
    case 0x8018F87Cu: goto label_8018F87C;
    case 0x8018F880u: goto label_8018F880;
    case 0x8018F884u: goto label_8018F884;
    case 0x8018F888u: goto label_8018F888;
    case 0x8018F88Cu: goto label_8018F88C;
    case 0x8018F890u: goto label_8018F890;
    case 0x8018F894u: goto label_8018F894;
    case 0x8018F898u: goto label_8018F898;
    case 0x8018F89Cu: goto label_8018F89C;
    case 0x8018F8A0u: goto label_8018F8A0;
    case 0x8018F8A4u: goto label_8018F8A4;
    case 0x8018F8A8u: goto label_8018F8A8;
    case 0x8018F8ACu: goto label_8018F8AC;
    case 0x8018F8B0u: goto label_8018F8B0;
    case 0x8018F8B4u: goto label_8018F8B4;
    case 0x8018F8B8u: goto label_8018F8B8;
    case 0x8018F8BCu: goto label_8018F8BC;
    case 0x8018F8C0u: goto label_8018F8C0;
    case 0x8018F8C4u: goto label_8018F8C4;
    case 0x8018F8C8u: goto label_8018F8C8;
    case 0x8018F8CCu: goto label_8018F8CC;
    case 0x8018F8D0u: goto label_8018F8D0;
    case 0x8018F8D4u: goto label_8018F8D4;
    case 0x8018F8D8u: goto label_8018F8D8;
    case 0x8018F8DCu: goto label_8018F8DC;
    case 0x8018F8E0u: goto label_8018F8E0;
    case 0x8018F8E4u: goto label_8018F8E4;
    case 0x8018F8E8u: goto label_8018F8E8;
    case 0x8018F8ECu: goto label_8018F8EC;
    case 0x8018F8F0u: goto label_8018F8F0;
    case 0x8018F8F4u: goto label_8018F8F4;
    case 0x8018F8F8u: goto label_8018F8F8;
    case 0x8018F8FCu: goto label_8018F8FC;
    case 0x8018F900u: goto label_8018F900;
    case 0x8018F904u: goto label_8018F904;
    case 0x8018F908u: goto label_8018F908;
    case 0x8018F90Cu: goto label_8018F90C;
    case 0x8018F910u: goto label_8018F910;
    case 0x8018F914u: goto label_8018F914;
    case 0x8018F918u: goto label_8018F918;
    case 0x8018F91Cu: goto label_8018F91C;
    case 0x8018F920u: goto label_8018F920;
    case 0x8018F924u: goto label_8018F924;
    case 0x8018F928u: goto label_8018F928;
    case 0x8018F92Cu: goto label_8018F92C;
    case 0x8018F930u: goto label_8018F930;
    case 0x8018F934u: goto label_8018F934;
    case 0x8018F938u: goto label_8018F938;
    case 0x8018F93Cu: goto label_8018F93C;
    case 0x8018F940u: goto label_8018F940;
    case 0x8018F944u: goto label_8018F944;
    case 0x8018F948u: goto label_8018F948;
    case 0x8018F94Cu: goto label_8018F94C;
    case 0x8018F950u: goto label_8018F950;
    case 0x8018F954u: goto label_8018F954;
    case 0x8018F958u: goto label_8018F958;
    case 0x8018F95Cu: goto label_8018F95C;
    case 0x8018F960u: goto label_8018F960;
    case 0x8018F964u: goto label_8018F964;
    case 0x8018F968u: goto label_8018F968;
    case 0x8018F96Cu: goto label_8018F96C;
    case 0x8018F970u: goto label_8018F970;
    case 0x8018F974u: goto label_8018F974;
    case 0x8018F978u: goto label_8018F978;
    case 0x8018F97Cu: goto label_8018F97C;
    case 0x8018F980u: goto label_8018F980;
    case 0x8018F984u: goto label_8018F984;
    case 0x8018F988u: goto label_8018F988;
    case 0x8018F98Cu: goto label_8018F98C;
    case 0x8018F990u: goto label_8018F990;
    case 0x8018F994u: goto label_8018F994;
    case 0x8018F998u: goto label_8018F998;
    case 0x8018F99Cu: goto label_8018F99C;
    case 0x8018F9A0u: goto label_8018F9A0;
    case 0x8018F9A4u: goto label_8018F9A4;
    case 0x8018F9A8u: goto label_8018F9A8;
    case 0x8018F9ACu: goto label_8018F9AC;
    case 0x8018F9B0u: goto label_8018F9B0;
    case 0x8018F9B4u: goto label_8018F9B4;
    case 0x8018F9B8u: goto label_8018F9B8;
    case 0x8018F9BCu: goto label_8018F9BC;
    case 0x8018F9C0u: goto label_8018F9C0;
    case 0x8018F9C4u: goto label_8018F9C4;
    case 0x8018F9C8u: goto label_8018F9C8;
    case 0x8018F9CCu: goto label_8018F9CC;
    case 0x8018F9D0u: goto label_8018F9D0;
    case 0x8018F9D4u: goto label_8018F9D4;
    case 0x8018F9D8u: goto label_8018F9D8;
    case 0x8018F9DCu: goto label_8018F9DC;
    case 0x8018F9E0u: goto label_8018F9E0;
    case 0x8018F9E4u: goto label_8018F9E4;
    case 0x8018F9E8u: goto label_8018F9E8;
    case 0x8018F9ECu: goto label_8018F9EC;
    case 0x8018F9F0u: goto label_8018F9F0;
    case 0x8018F9F4u: goto label_8018F9F4;
    case 0x8018F9F8u: goto label_8018F9F8;
    case 0x8018F9FCu: goto label_8018F9FC;
    case 0x8018FA00u: goto label_8018FA00;
    case 0x8018FA04u: goto label_8018FA04;
    case 0x8018FA08u: goto label_8018FA08;
    case 0x8018FA0Cu: goto label_8018FA0C;
    case 0x8018FA10u: goto label_8018FA10;
    case 0x8018FA14u: goto label_8018FA14;
    case 0x8018FA18u: goto label_8018FA18;
    case 0x8018FA1Cu: goto label_8018FA1C;
    case 0x8018FA20u: goto label_8018FA20;
    case 0x8018FA24u: goto label_8018FA24;
    case 0x8018FA28u: goto label_8018FA28;
    case 0x8018FA2Cu: goto label_8018FA2C;
    case 0x8018FA30u: goto label_8018FA30;
    case 0x8018FA34u: goto label_8018FA34;
    case 0x8018FA38u: goto label_8018FA38;
    case 0x8018FA3Cu: goto label_8018FA3C;
    case 0x8018FA40u: goto label_8018FA40;
    case 0x8018FA44u: goto label_8018FA44;
    case 0x8018FA48u: goto label_8018FA48;
    case 0x8018FA4Cu: goto label_8018FA4C;
    case 0x8018FA50u: goto label_8018FA50;
    case 0x8018FA54u: goto label_8018FA54;
    case 0x8018FA58u: goto label_8018FA58;
    case 0x8018FA5Cu: goto label_8018FA5C;
    case 0x8018FA60u: goto label_8018FA60;
    case 0x8018FA64u: goto label_8018FA64;
    case 0x8018FA68u: goto label_8018FA68;
    case 0x8018FA6Cu: goto label_8018FA6C;
    case 0x8018FA70u: goto label_8018FA70;
    case 0x8018FA74u: goto label_8018FA74;
    case 0x8018FA78u: goto label_8018FA78;
    case 0x8018FA7Cu: goto label_8018FA7C;
    case 0x8018FA80u: goto label_8018FA80;
    case 0x8018FA84u: goto label_8018FA84;
    case 0x8018FA88u: goto label_8018FA88;
    case 0x8018FA8Cu: goto label_8018FA8C;
    case 0x8018FA90u: goto label_8018FA90;
    case 0x8018FA94u: goto label_8018FA94;
    case 0x8018FA98u: goto label_8018FA98;
    case 0x8018FA9Cu: goto label_8018FA9C;
    case 0x8018FAA0u: goto label_8018FAA0;
    case 0x8018FAA4u: goto label_8018FAA4;
    case 0x8018FAA8u: goto label_8018FAA8;
    case 0x8018FAACu: goto label_8018FAAC;
    case 0x8018FAB0u: goto label_8018FAB0;
    case 0x8018FAB4u: goto label_8018FAB4;
    case 0x8018FAB8u: goto label_8018FAB8;
    case 0x8018FABCu: goto label_8018FABC;
    case 0x8018FAC0u: goto label_8018FAC0;
    case 0x8018FAC4u: goto label_8018FAC4;
    case 0x8018FAC8u: goto label_8018FAC8;
    case 0x8018FACCu: goto label_8018FACC;
    case 0x8018FAD0u: goto label_8018FAD0;
    case 0x8018FAD4u: goto label_8018FAD4;
    case 0x8018FAD8u: goto label_8018FAD8;
    case 0x8018FADCu: goto label_8018FADC;
    case 0x8018FAE0u: goto label_8018FAE0;
    case 0x8018FAE4u: goto label_8018FAE4;
    case 0x8018FAE8u: goto label_8018FAE8;
    case 0x8018FAECu: goto label_8018FAEC;
    case 0x8018FAF0u: goto label_8018FAF0;
    case 0x8018FAF4u: goto label_8018FAF4;
    case 0x8018FAF8u: goto label_8018FAF8;
    case 0x8018FAFCu: goto label_8018FAFC;
    case 0x8018FB00u: goto label_8018FB00;
    case 0x8018FB04u: goto label_8018FB04;
    case 0x8018FB08u: goto label_8018FB08;
    case 0x8018FB0Cu: goto label_8018FB0C;
    case 0x8018FB10u: goto label_8018FB10;
    case 0x8018FB14u: goto label_8018FB14;
    case 0x8018FB18u: goto label_8018FB18;
    case 0x8018FB1Cu: goto label_8018FB1C;
    case 0x8018FB20u: goto label_8018FB20;
    case 0x8018FB24u: goto label_8018FB24;
    case 0x8018FB28u: goto label_8018FB28;
    case 0x8018FB2Cu: goto label_8018FB2C;
    case 0x8018FB30u: goto label_8018FB30;
    case 0x8018FB34u: goto label_8018FB34;
    case 0x8018FB38u: goto label_8018FB38;
    case 0x8018FB3Cu: goto label_8018FB3C;
    case 0x8018FB40u: goto label_8018FB40;
    case 0x8018FB44u: goto label_8018FB44;
    case 0x8018FB48u: goto label_8018FB48;
    case 0x8018FB4Cu: goto label_8018FB4C;
    case 0x8018FB50u: goto label_8018FB50;
    case 0x8018FB54u: goto label_8018FB54;
    case 0x8018FB58u: goto label_8018FB58;
    case 0x8018FB5Cu: goto label_8018FB5C;
    case 0x8018FB60u: goto label_8018FB60;
    case 0x8018FB64u: goto label_8018FB64;
    case 0x8018FB68u: goto label_8018FB68;
    case 0x8018FB6Cu: goto label_8018FB6C;
    case 0x8018FB70u: goto label_8018FB70;
    case 0x8018FB74u: goto label_8018FB74;
    case 0x8018FB78u: goto label_8018FB78;
    case 0x8018FB7Cu: goto label_8018FB7C;
    case 0x8018FB80u: goto label_8018FB80;
    case 0x8018FB84u: goto label_8018FB84;
    case 0x8018FB88u: goto label_8018FB88;
    case 0x8018FB8Cu: goto label_8018FB8C;
    case 0x8018FB90u: goto label_8018FB90;
    case 0x8018FB94u: goto label_8018FB94;
    case 0x8018FB98u: goto label_8018FB98;
    case 0x8018FB9Cu: goto label_8018FB9C;
    case 0x8018FBA0u: goto label_8018FBA0;
    case 0x8018FBA4u: goto label_8018FBA4;
    case 0x8018FBA8u: goto label_8018FBA8;
    case 0x8018FBACu: goto label_8018FBAC;
    case 0x8018FBB0u: goto label_8018FBB0;
    case 0x8018FBB4u: goto label_8018FBB4;
    case 0x8018FBB8u: goto label_8018FBB8;
    case 0x8018FBBCu: goto label_8018FBBC;
    case 0x8018FBC0u: goto label_8018FBC0;
    case 0x8018FBC4u: goto label_8018FBC4;
    case 0x8018FBC8u: goto label_8018FBC8;
    case 0x8018FBCCu: goto label_8018FBCC;
    case 0x8018FBD0u: goto label_8018FBD0;
    case 0x8018FBD4u: goto label_8018FBD4;
    case 0x8018FBD8u: goto label_8018FBD8;
    case 0x8018FBDCu: goto label_8018FBDC;
    case 0x8018FBE0u: goto label_8018FBE0;
    case 0x8018FBE4u: goto label_8018FBE4;
    case 0x8018FBE8u: goto label_8018FBE8;
    case 0x8018FBECu: goto label_8018FBEC;
    case 0x8018FBF0u: goto label_8018FBF0;
    case 0x8018FBF4u: goto label_8018FBF4;
    case 0x8018FBF8u: goto label_8018FBF8;
    case 0x8018FBFCu: goto label_8018FBFC;
    case 0x8018FC00u: goto label_8018FC00;
    case 0x8018FC04u: goto label_8018FC04;
    case 0x8018FC08u: goto label_8018FC08;
    case 0x8018FC0Cu: goto label_8018FC0C;
    case 0x8018FC10u: goto label_8018FC10;
    case 0x8018FC14u: goto label_8018FC14;
    case 0x8018FC18u: goto label_8018FC18;
    case 0x8018FC1Cu: goto label_8018FC1C;
    case 0x8018FC20u: goto label_8018FC20;
    case 0x8018FC24u: goto label_8018FC24;
    case 0x8018FC28u: goto label_8018FC28;
    case 0x8018FC2Cu: goto label_8018FC2C;
    case 0x8018FC30u: goto label_8018FC30;
    case 0x8018FC34u: goto label_8018FC34;
    case 0x8018FC38u: goto label_8018FC38;
    case 0x8018FC3Cu: goto label_8018FC3C;
    case 0x8018FC40u: goto label_8018FC40;
    case 0x8018FC44u: goto label_8018FC44;
    case 0x8018FC48u: goto label_8018FC48;
    case 0x8018FC4Cu: goto label_8018FC4C;
    case 0x8018FC50u: goto label_8018FC50;
    case 0x8018FC54u: goto label_8018FC54;
    case 0x8018FC58u: goto label_8018FC58;
    case 0x8018FC5Cu: goto label_8018FC5C;
    case 0x8018FC60u: goto label_8018FC60;
    case 0x8018FC64u: goto label_8018FC64;
    case 0x8018FC68u: goto label_8018FC68;
    case 0x8018FC6Cu: goto label_8018FC6C;
    case 0x8018FC70u: goto label_8018FC70;
    case 0x8018FC74u: goto label_8018FC74;
    case 0x8018FC78u: goto label_8018FC78;
    case 0x8018FC7Cu: goto label_8018FC7C;
    case 0x8018FC80u: goto label_8018FC80;
    case 0x8018FC84u: goto label_8018FC84;
    case 0x8018FC88u: goto label_8018FC88;
    case 0x8018FC8Cu: goto label_8018FC8C;
    case 0x8018FC90u: goto label_8018FC90;
    case 0x8018FC94u: goto label_8018FC94;
    case 0x8018FC98u: goto label_8018FC98;
    case 0x8018FC9Cu: goto label_8018FC9C;
    case 0x8018FCA0u: goto label_8018FCA0;
    case 0x8018FCA4u: goto label_8018FCA4;
    case 0x8018FCA8u: goto label_8018FCA8;
    case 0x8018FCACu: goto label_8018FCAC;
    case 0x8018FCB0u: goto label_8018FCB0;
    case 0x8018FCB4u: goto label_8018FCB4;
    case 0x8018FCB8u: goto label_8018FCB8;
    case 0x8018FCBCu: goto label_8018FCBC;
    case 0x8018FCC0u: goto label_8018FCC0;
    case 0x8018FCC4u: goto label_8018FCC4;
    case 0x8018FCC8u: goto label_8018FCC8;
    case 0x8018FCCCu: goto label_8018FCCC;
    case 0x8018FCD0u: goto label_8018FCD0;
    case 0x8018FCD4u: goto label_8018FCD4;
    case 0x8018FCD8u: goto label_8018FCD8;
    case 0x8018FCDCu: goto label_8018FCDC;
    case 0x8018FCE0u: goto label_8018FCE0;
    case 0x8018FCE4u: goto label_8018FCE4;
    case 0x8018FCE8u: goto label_8018FCE8;
    case 0x8018FCECu: goto label_8018FCEC;
    case 0x8018FCF0u: goto label_8018FCF0;
    case 0x8018FCF4u: goto label_8018FCF4;
    case 0x8018FCF8u: goto label_8018FCF8;
    case 0x8018FCFCu: goto label_8018FCFC;
    case 0x8018FD00u: goto label_8018FD00;
    case 0x8018FD04u: goto label_8018FD04;
    case 0x8018FD08u: goto label_8018FD08;
    case 0x8018FD0Cu: goto label_8018FD0C;
    case 0x8018FD10u: goto label_8018FD10;
    case 0x8018FD14u: goto label_8018FD14;
    case 0x8018FD18u: goto label_8018FD18;
    case 0x8018FD1Cu: goto label_8018FD1C;
    case 0x8018FD20u: goto label_8018FD20;
    case 0x8018FD24u: goto label_8018FD24;
    case 0x8018FD28u: goto label_8018FD28;
    case 0x8018FD2Cu: goto label_8018FD2C;
    case 0x8018FD30u: goto label_8018FD30;
    case 0x8018FD34u: goto label_8018FD34;
    case 0x8018FD38u: goto label_8018FD38;
    case 0x8018FD3Cu: goto label_8018FD3C;
    case 0x8018FD40u: goto label_8018FD40;
    case 0x8018FD44u: goto label_8018FD44;
    case 0x8018FD48u: goto label_8018FD48;
    case 0x8018FD4Cu: goto label_8018FD4C;
    case 0x8018FD50u: goto label_8018FD50;
    case 0x8018FD54u: goto label_8018FD54;
    case 0x8018FD58u: goto label_8018FD58;
    case 0x8018FD5Cu: goto label_8018FD5C;
    case 0x8018FD60u: goto label_8018FD60;
    case 0x8018FD64u: goto label_8018FD64;
    case 0x8018FD68u: goto label_8018FD68;
    case 0x8018FD6Cu: goto label_8018FD6C;
    case 0x8018FD70u: goto label_8018FD70;
    case 0x8018FD74u: goto label_8018FD74;
    case 0x8018FD78u: goto label_8018FD78;
    case 0x8018FD7Cu: goto label_8018FD7C;
    case 0x8018FD80u: goto label_8018FD80;
    case 0x8018FD84u: goto label_8018FD84;
    case 0x8018FD88u: goto label_8018FD88;
    case 0x8018FD8Cu: goto label_8018FD8C;
    case 0x8018FD90u: goto label_8018FD90;
    case 0x8018FD94u: goto label_8018FD94;
    case 0x8018FD98u: goto label_8018FD98;
    case 0x8018FD9Cu: goto label_8018FD9C;
    case 0x8018FDA0u: goto label_8018FDA0;
    case 0x8018FDA4u: goto label_8018FDA4;
    case 0x8018FDA8u: goto label_8018FDA8;
    case 0x8018FDACu: goto label_8018FDAC;
    case 0x8018FDB0u: goto label_8018FDB0;
    case 0x8018FDB4u: goto label_8018FDB4;
    case 0x8018FDB8u: goto label_8018FDB8;
    case 0x8018FDBCu: goto label_8018FDBC;
    case 0x8018FDC0u: goto label_8018FDC0;
    case 0x8018FDC4u: goto label_8018FDC4;
    case 0x8018FDC8u: goto label_8018FDC8;
    case 0x8018FDCCu: goto label_8018FDCC;
    case 0x8018FDD0u: goto label_8018FDD0;
    case 0x8018FDD4u: goto label_8018FDD4;
    case 0x8018FDD8u: goto label_8018FDD8;
    case 0x8018FDDCu: goto label_8018FDDC;
    case 0x8018FDE0u: goto label_8018FDE0;
    case 0x8018FDE4u: goto label_8018FDE4;
    case 0x8018FDE8u: goto label_8018FDE8;
    case 0x8018FDECu: goto label_8018FDEC;
    case 0x8018FDF0u: goto label_8018FDF0;
    case 0x8018FDF4u: goto label_8018FDF4;
    case 0x8018FDF8u: goto label_8018FDF8;
    case 0x8018FDFCu: goto label_8018FDFC;
    case 0x8018FE00u: goto label_8018FE00;
    case 0x8018FE04u: goto label_8018FE04;
    case 0x8018FE08u: goto label_8018FE08;
    case 0x8018FE0Cu: goto label_8018FE0C;
    case 0x8018FE10u: goto label_8018FE10;
    case 0x8018FE14u: goto label_8018FE14;
    case 0x8018FE18u: goto label_8018FE18;
    case 0x8018FE1Cu: goto label_8018FE1C;
    case 0x8018FE20u: goto label_8018FE20;
    case 0x8018FE24u: goto label_8018FE24;
    case 0x8018FE28u: goto label_8018FE28;
    case 0x8018FE2Cu: goto label_8018FE2C;
    case 0x8018FE30u: goto label_8018FE30;
    case 0x8018FE34u: goto label_8018FE34;
    case 0x8018FE38u: goto label_8018FE38;
    case 0x8018FE3Cu: goto label_8018FE3C;
    case 0x8018FE40u: goto label_8018FE40;
    case 0x8018FE44u: goto label_8018FE44;
    case 0x8018FE48u: goto label_8018FE48;
    case 0x8018FE4Cu: goto label_8018FE4C;
    case 0x8018FE50u: goto label_8018FE50;
    case 0x8018FE54u: goto label_8018FE54;
    case 0x8018FE58u: goto label_8018FE58;
    case 0x8018FE5Cu: goto label_8018FE5C;
    case 0x8018FE60u: goto label_8018FE60;
    case 0x8018FE64u: goto label_8018FE64;
    case 0x8018FE68u: goto label_8018FE68;
    case 0x8018FE6Cu: goto label_8018FE6C;
    case 0x8018FE70u: goto label_8018FE70;
    case 0x8018FE74u: goto label_8018FE74;
    case 0x8018FE78u: goto label_8018FE78;
    case 0x8018FE7Cu: goto label_8018FE7C;
    case 0x8018FE80u: goto label_8018FE80;
    case 0x8018FE84u: goto label_8018FE84;
    case 0x8018FE88u: goto label_8018FE88;
    case 0x8018FE8Cu: goto label_8018FE8C;
    case 0x8018FE90u: goto label_8018FE90;
    case 0x8018FE94u: goto label_8018FE94;
    case 0x8018FE98u: goto label_8018FE98;
    case 0x8018FE9Cu: goto label_8018FE9C;
    case 0x8018FEA0u: goto label_8018FEA0;
    case 0x8018FEA4u: goto label_8018FEA4;
    case 0x8018FEA8u: goto label_8018FEA8;
    case 0x8018FEACu: goto label_8018FEAC;
    case 0x8018FEB0u: goto label_8018FEB0;
    case 0x8018FEB4u: goto label_8018FEB4;
    case 0x8018FEB8u: goto label_8018FEB8;
    case 0x8018FEBCu: goto label_8018FEBC;
    case 0x8018FEC0u: goto label_8018FEC0;
    case 0x8018FEC4u: goto label_8018FEC4;
    case 0x8018FEC8u: goto label_8018FEC8;
    case 0x8018FECCu: goto label_8018FECC;
    case 0x8018FED0u: goto label_8018FED0;
    case 0x8018FED4u: goto label_8018FED4;
    case 0x8018FED8u: goto label_8018FED8;
    case 0x8018FEDCu: goto label_8018FEDC;
    case 0x8018FEE0u: goto label_8018FEE0;
    case 0x8018FEE4u: goto label_8018FEE4;
    case 0x8018FEE8u: goto label_8018FEE8;
    case 0x8018FEECu: goto label_8018FEEC;
    case 0x8018FEF0u: goto label_8018FEF0;
    case 0x8018FEF4u: goto label_8018FEF4;
    case 0x8018FEF8u: goto label_8018FEF8;
    case 0x8018FEFCu: goto label_8018FEFC;
    case 0x8018FF00u: goto label_8018FF00;
    case 0x8018FF04u: goto label_8018FF04;
    case 0x8018FF08u: goto label_8018FF08;
    case 0x8018FF0Cu: goto label_8018FF0C;
    case 0x8018FF10u: goto label_8018FF10;
    case 0x8018FF14u: goto label_8018FF14;
    case 0x8018FF18u: goto label_8018FF18;
    case 0x8018FF1Cu: goto label_8018FF1C;
    case 0x8018FF20u: goto label_8018FF20;
    case 0x8018FF24u: goto label_8018FF24;
    case 0x8018FF28u: goto label_8018FF28;
    case 0x8018FF2Cu: goto label_8018FF2C;
    case 0x8018FF30u: goto label_8018FF30;
    case 0x8018FF34u: goto label_8018FF34;
    case 0x8018FF38u: goto label_8018FF38;
    case 0x8018FF3Cu: goto label_8018FF3C;
    case 0x8018FF40u: goto label_8018FF40;
    case 0x8018FF44u: goto label_8018FF44;
    case 0x8018FF48u: goto label_8018FF48;
    case 0x8018FF4Cu: goto label_8018FF4C;
    case 0x8018FF50u: goto label_8018FF50;
    case 0x8018FF54u: goto label_8018FF54;
    case 0x8018FF58u: goto label_8018FF58;
    case 0x8018FF5Cu: goto label_8018FF5C;
    case 0x8018FF60u: goto label_8018FF60;
    case 0x8018FF64u: goto label_8018FF64;
    case 0x8018FF68u: goto label_8018FF68;
    case 0x8018FF6Cu: goto label_8018FF6C;
    case 0x8018FF70u: goto label_8018FF70;
    case 0x8018FF74u: goto label_8018FF74;
    case 0x8018FF78u: goto label_8018FF78;
    case 0x8018FF7Cu: goto label_8018FF7C;
    case 0x8018FF80u: goto label_8018FF80;
    case 0x8018FF84u: goto label_8018FF84;
    case 0x8018FF88u: goto label_8018FF88;
    case 0x8018FF8Cu: goto label_8018FF8C;
    case 0x8018FF90u: goto label_8018FF90;
    case 0x8018FF94u: goto label_8018FF94;
    case 0x8018FF98u: goto label_8018FF98;
    case 0x8018FF9Cu: goto label_8018FF9C;
    case 0x8018FFA0u: goto label_8018FFA0;
    case 0x8018FFA4u: goto label_8018FFA4;
    case 0x8018FFA8u: goto label_8018FFA8;
    case 0x8018FFACu: goto label_8018FFAC;
    case 0x8018FFB0u: goto label_8018FFB0;
    case 0x8018FFB4u: goto label_8018FFB4;
    case 0x8018FFB8u: goto label_8018FFB8;
    case 0x8018FFBCu: goto label_8018FFBC;
    case 0x8018FFC0u: goto label_8018FFC0;
    case 0x8018FFC4u: goto label_8018FFC4;
    case 0x8018FFC8u: goto label_8018FFC8;
    case 0x8018FFCCu: goto label_8018FFCC;
    case 0x8018FFD0u: goto label_8018FFD0;
    case 0x8018FFD4u: goto label_8018FFD4;
    case 0x8018FFD8u: goto label_8018FFD8;
    case 0x8018FFDCu: goto label_8018FFDC;
    case 0x8018FFE0u: goto label_8018FFE0;
    case 0x8018FFE4u: goto label_8018FFE4;
    case 0x8018FFE8u: goto label_8018FFE8;
    case 0x8018FFECu: goto label_8018FFEC;
    case 0x8018FFF0u: goto label_8018FFF0;
    case 0x8018FFF4u: goto label_8018FFF4;
    case 0x8018FFF8u: goto label_8018FFF8;
    case 0x8018FFFCu: goto label_8018FFFC;
    case 0x80190000u: goto label_80190000;
    case 0x80190004u: goto label_80190004;
    case 0x80190008u: goto label_80190008;
    case 0x8019000Cu: goto label_8019000C;
    case 0x80190010u: goto label_80190010;
    case 0x80190014u: goto label_80190014;
    case 0x80190018u: goto label_80190018;
    case 0x8019001Cu: goto label_8019001C;
    case 0x80190020u: goto label_80190020;
    case 0x80190024u: goto label_80190024;
    case 0x80190028u: goto label_80190028;
    case 0x8019002Cu: goto label_8019002C;
    case 0x80190030u: goto label_80190030;
    case 0x80190034u: goto label_80190034;
    case 0x80190038u: goto label_80190038;
    case 0x8019003Cu: goto label_8019003C;
    case 0x80190040u: goto label_80190040;
    case 0x80190044u: goto label_80190044;
    case 0x80190048u: goto label_80190048;
    case 0x8019004Cu: goto label_8019004C;
    case 0x80190050u: goto label_80190050;
    case 0x80190054u: goto label_80190054;
    case 0x80190058u: goto label_80190058;
    case 0x8019005Cu: goto label_8019005C;
    case 0x80190060u: goto label_80190060;
    case 0x80190064u: goto label_80190064;
    case 0x80190068u: goto label_80190068;
    case 0x8019006Cu: goto label_8019006C;
    case 0x80190070u: goto label_80190070;
    case 0x80190074u: goto label_80190074;
    case 0x80190078u: goto label_80190078;
    case 0x8019007Cu: goto label_8019007C;
    case 0x80190080u: goto label_80190080;
    case 0x80190084u: goto label_80190084;
    case 0x80190088u: goto label_80190088;
    case 0x8019008Cu: goto label_8019008C;
    case 0x80190090u: goto label_80190090;
    case 0x80190094u: goto label_80190094;
    case 0x80190098u: goto label_80190098;
    case 0x8019009Cu: goto label_8019009C;
    case 0x801900A0u: goto label_801900A0;
    case 0x801900A4u: goto label_801900A4;
    case 0x801900A8u: goto label_801900A8;
    case 0x801900ACu: goto label_801900AC;
    case 0x801900B0u: goto label_801900B0;
    case 0x801900B4u: goto label_801900B4;
    case 0x801900B8u: goto label_801900B8;
    case 0x801900BCu: goto label_801900BC;
    case 0x801900C0u: goto label_801900C0;
    case 0x801900C4u: goto label_801900C4;
    case 0x801900C8u: goto label_801900C8;
    case 0x801900CCu: goto label_801900CC;
    case 0x801900D0u: goto label_801900D0;
    case 0x801900D4u: goto label_801900D4;
    case 0x801900D8u: goto label_801900D8;
    case 0x801900DCu: goto label_801900DC;
    case 0x801900E0u: goto label_801900E0;
    case 0x801900E4u: goto label_801900E4;
    case 0x801900E8u: goto label_801900E8;
    case 0x801900ECu: goto label_801900EC;
    case 0x801900F0u: goto label_801900F0;
    case 0x801900F4u: goto label_801900F4;
    case 0x801900F8u: goto label_801900F8;
    case 0x801900FCu: goto label_801900FC;
    case 0x80190100u: goto label_80190100;
    case 0x80190104u: goto label_80190104;
    case 0x80190108u: goto label_80190108;
    case 0x8019010Cu: goto label_8019010C;
    case 0x80190110u: goto label_80190110;
    case 0x80190114u: goto label_80190114;
    case 0x80190118u: goto label_80190118;
    case 0x8019011Cu: goto label_8019011C;
    case 0x80190120u: goto label_80190120;
    case 0x80190124u: goto label_80190124;
    case 0x80190128u: goto label_80190128;
    case 0x8019012Cu: goto label_8019012C;
    case 0x80190130u: goto label_80190130;
    case 0x80190134u: goto label_80190134;
    case 0x80190138u: goto label_80190138;
    case 0x8019013Cu: goto label_8019013C;
    case 0x80190140u: goto label_80190140;
    case 0x80190144u: goto label_80190144;
    case 0x80190148u: goto label_80190148;
    case 0x8019014Cu: goto label_8019014C;
    case 0x80190150u: goto label_80190150;
    case 0x80190154u: goto label_80190154;
    case 0x80190158u: goto label_80190158;
    case 0x8019015Cu: goto label_8019015C;
    case 0x80190160u: goto label_80190160;
    case 0x80190164u: goto label_80190164;
    case 0x80190168u: goto label_80190168;
    case 0x8019016Cu: goto label_8019016C;
    case 0x80190170u: goto label_80190170;
    case 0x80190174u: goto label_80190174;
    case 0x80190178u: goto label_80190178;
    case 0x8019017Cu: goto label_8019017C;
    case 0x80190180u: goto label_80190180;
    case 0x80190184u: goto label_80190184;
    case 0x80190188u: goto label_80190188;
    case 0x8019018Cu: goto label_8019018C;
    case 0x80190190u: goto label_80190190;
    case 0x80190194u: goto label_80190194;
    case 0x80190198u: goto label_80190198;
    case 0x8019019Cu: goto label_8019019C;
    case 0x801901A0u: goto label_801901A0;
    case 0x801901A4u: goto label_801901A4;
    case 0x801901A8u: goto label_801901A8;
    case 0x801901ACu: goto label_801901AC;
    case 0x801901B0u: goto label_801901B0;
    case 0x801901B4u: goto label_801901B4;
    case 0x801901B8u: goto label_801901B8;
    case 0x801901BCu: goto label_801901BC;
    case 0x801901C0u: goto label_801901C0;
    case 0x801901C4u: goto label_801901C4;
    case 0x801901C8u: goto label_801901C8;
    case 0x801901CCu: goto label_801901CC;
    case 0x801901D0u: goto label_801901D0;
    case 0x801901D4u: goto label_801901D4;
    case 0x801901D8u: goto label_801901D8;
    case 0x801901DCu: goto label_801901DC;
    case 0x801901E0u: goto label_801901E0;
    case 0x801901E4u: goto label_801901E4;
    case 0x801901E8u: goto label_801901E8;
    case 0x801901ECu: goto label_801901EC;
    case 0x801901F0u: goto label_801901F0;
    case 0x801901F4u: goto label_801901F4;
    case 0x801901F8u: goto label_801901F8;
    case 0x801901FCu: goto label_801901FC;
    case 0x80190200u: goto label_80190200;
    case 0x80190204u: goto label_80190204;
    case 0x80190208u: goto label_80190208;
    case 0x8019020Cu: goto label_8019020C;
    case 0x80190210u: goto label_80190210;
    case 0x80190214u: goto label_80190214;
    case 0x80190218u: goto label_80190218;
    case 0x8019021Cu: goto label_8019021C;
    case 0x80190220u: goto label_80190220;
    case 0x80190224u: goto label_80190224;
    case 0x80190228u: goto label_80190228;
    case 0x8019022Cu: goto label_8019022C;
    case 0x80190230u: goto label_80190230;
    case 0x80190234u: goto label_80190234;
    case 0x80190238u: goto label_80190238;
    case 0x8019023Cu: goto label_8019023C;
    case 0x80190240u: goto label_80190240;
    case 0x80190244u: goto label_80190244;
    case 0x80190248u: goto label_80190248;
    case 0x8019024Cu: goto label_8019024C;
    case 0x80190250u: goto label_80190250;
    case 0x80190254u: goto label_80190254;
    case 0x80190258u: goto label_80190258;
    case 0x8019025Cu: goto label_8019025C;
    case 0x80190260u: goto label_80190260;
    case 0x80190264u: goto label_80190264;
    case 0x80190268u: goto label_80190268;
    case 0x8019026Cu: goto label_8019026C;
    case 0x80190270u: goto label_80190270;
    case 0x80190274u: goto label_80190274;
    case 0x80190278u: goto label_80190278;
    case 0x8019027Cu: goto label_8019027C;
    case 0x80190280u: goto label_80190280;
    case 0x80190284u: goto label_80190284;
    case 0x80190288u: goto label_80190288;
    case 0x8019028Cu: goto label_8019028C;
    case 0x80190290u: goto label_80190290;
    case 0x80190294u: goto label_80190294;
    case 0x80190298u: goto label_80190298;
    case 0x8019029Cu: goto label_8019029C;
    case 0x801902A0u: goto label_801902A0;
    case 0x801902A4u: goto label_801902A4;
    case 0x801902A8u: goto label_801902A8;
    case 0x801902ACu: goto label_801902AC;
    case 0x801902B0u: goto label_801902B0;
    case 0x801902B4u: goto label_801902B4;
    case 0x801902B8u: goto label_801902B8;
    case 0x801902BCu: goto label_801902BC;
    case 0x801902C0u: goto label_801902C0;
    case 0x801902C4u: goto label_801902C4;
    case 0x801902C8u: goto label_801902C8;
    case 0x801902CCu: goto label_801902CC;
    case 0x801902D0u: goto label_801902D0;
    case 0x801902D4u: goto label_801902D4;
    case 0x801902D8u: goto label_801902D8;
    case 0x801902DCu: goto label_801902DC;
    case 0x801902E0u: goto label_801902E0;
    case 0x801902E4u: goto label_801902E4;
    case 0x801902E8u: goto label_801902E8;
    case 0x801902ECu: goto label_801902EC;
    case 0x801902F0u: goto label_801902F0;
    case 0x801902F4u: goto label_801902F4;
    case 0x801902F8u: goto label_801902F8;
    case 0x801902FCu: goto label_801902FC;
    case 0x80190300u: goto label_80190300;
    case 0x80190304u: goto label_80190304;
    case 0x80190308u: goto label_80190308;
    case 0x8019030Cu: goto label_8019030C;
    case 0x80190310u: goto label_80190310;
    case 0x80190314u: goto label_80190314;
    case 0x80190318u: goto label_80190318;
    case 0x8019031Cu: goto label_8019031C;
    case 0x80190320u: goto label_80190320;
    case 0x80190324u: goto label_80190324;
    case 0x80190328u: goto label_80190328;
    case 0x8019032Cu: goto label_8019032C;
    case 0x80190330u: goto label_80190330;
    case 0x80190334u: goto label_80190334;
    case 0x80190338u: goto label_80190338;
    case 0x8019033Cu: goto label_8019033C;
    case 0x80190340u: goto label_80190340;
    case 0x80190344u: goto label_80190344;
    case 0x80190348u: goto label_80190348;
    case 0x8019034Cu: goto label_8019034C;
    case 0x80190350u: goto label_80190350;
    case 0x80190354u: goto label_80190354;
    case 0x80190358u: goto label_80190358;
    case 0x8019035Cu: goto label_8019035C;
    case 0x80190360u: goto label_80190360;
    case 0x80190364u: goto label_80190364;
    case 0x80190368u: goto label_80190368;
    case 0x8019036Cu: goto label_8019036C;
    case 0x80190370u: goto label_80190370;
    case 0x80190374u: goto label_80190374;
    case 0x80190378u: goto label_80190378;
    case 0x8019037Cu: goto label_8019037C;
    case 0x80190380u: goto label_80190380;
    case 0x80190384u: goto label_80190384;
    case 0x80190388u: goto label_80190388;
    case 0x8019038Cu: goto label_8019038C;
    case 0x80190390u: goto label_80190390;
    case 0x80190394u: goto label_80190394;
    case 0x80190398u: goto label_80190398;
    case 0x8019039Cu: goto label_8019039C;
    case 0x801903A0u: goto label_801903A0;
    case 0x801903A4u: goto label_801903A4;
    case 0x801903A8u: goto label_801903A8;
    case 0x801903ACu: goto label_801903AC;
    case 0x801903B0u: goto label_801903B0;
    case 0x801903B4u: goto label_801903B4;
    case 0x801903B8u: goto label_801903B8;
    case 0x801903BCu: goto label_801903BC;
    case 0x801903C0u: goto label_801903C0;
    case 0x801903C4u: goto label_801903C4;
    case 0x801903C8u: goto label_801903C8;
    case 0x801903CCu: goto label_801903CC;
    case 0x801903D0u: goto label_801903D0;
    case 0x801903D4u: goto label_801903D4;
    case 0x801903D8u: goto label_801903D8;
    case 0x801903DCu: goto label_801903DC;
    case 0x801903E0u: goto label_801903E0;
    case 0x801903E4u: goto label_801903E4;
    case 0x801903E8u: goto label_801903E8;
    case 0x801903ECu: goto label_801903EC;
    case 0x801903F0u: goto label_801903F0;
    case 0x801903F4u: goto label_801903F4;
    case 0x801903F8u: goto label_801903F8;
    case 0x801903FCu: goto label_801903FC;
    case 0x80190400u: goto label_80190400;
    case 0x80190404u: goto label_80190404;
    case 0x80190408u: goto label_80190408;
    case 0x8019040Cu: goto label_8019040C;
    case 0x80190410u: goto label_80190410;
    case 0x80190414u: goto label_80190414;
    case 0x80190418u: goto label_80190418;
    case 0x8019041Cu: goto label_8019041C;
    case 0x80190420u: goto label_80190420;
    case 0x80190424u: goto label_80190424;
    case 0x80190428u: goto label_80190428;
    case 0x8019042Cu: goto label_8019042C;
    case 0x80190430u: goto label_80190430;
    case 0x80190434u: goto label_80190434;
    case 0x80190438u: goto label_80190438;
    case 0x8019043Cu: goto label_8019043C;
    case 0x80190440u: goto label_80190440;
    case 0x80190444u: goto label_80190444;
    case 0x80190448u: goto label_80190448;
    case 0x8019044Cu: goto label_8019044C;
    case 0x80190450u: goto label_80190450;
    case 0x80190454u: goto label_80190454;
    case 0x80190458u: goto label_80190458;
    case 0x8019045Cu: goto label_8019045C;
    case 0x80190460u: goto label_80190460;
    case 0x80190464u: goto label_80190464;
    case 0x80190468u: goto label_80190468;
    case 0x8019046Cu: goto label_8019046C;
    case 0x80190470u: goto label_80190470;
    case 0x80190474u: goto label_80190474;
    case 0x80190478u: goto label_80190478;
    case 0x8019047Cu: goto label_8019047C;
    case 0x80190480u: goto label_80190480;
    case 0x80190484u: goto label_80190484;
    case 0x80190488u: goto label_80190488;
    case 0x8019048Cu: goto label_8019048C;
    case 0x80190490u: goto label_80190490;
    case 0x80190494u: goto label_80190494;
    case 0x80190498u: goto label_80190498;
    case 0x8019049Cu: goto label_8019049C;
    case 0x801904A0u: goto label_801904A0;
    case 0x801904A4u: goto label_801904A4;
    case 0x801904A8u: goto label_801904A8;
    case 0x801904ACu: goto label_801904AC;
    case 0x801904B0u: goto label_801904B0;
    case 0x801904B4u: goto label_801904B4;
    case 0x801904B8u: goto label_801904B8;
    case 0x801904BCu: goto label_801904BC;
    case 0x801904C0u: goto label_801904C0;
    case 0x801904C4u: goto label_801904C4;
    case 0x801904C8u: goto label_801904C8;
    case 0x801904CCu: goto label_801904CC;
    case 0x801904D0u: goto label_801904D0;
    case 0x801904D4u: goto label_801904D4;
    case 0x801904D8u: goto label_801904D8;
    case 0x801904DCu: goto label_801904DC;
    case 0x801904E0u: goto label_801904E0;
    case 0x801904E4u: goto label_801904E4;
    case 0x801904E8u: goto label_801904E8;
    case 0x801904ECu: goto label_801904EC;
    case 0x801904F0u: goto label_801904F0;
    case 0x801904F4u: goto label_801904F4;
    case 0x801904F8u: goto label_801904F8;
    case 0x801904FCu: goto label_801904FC;
    case 0x80190500u: goto label_80190500;
    case 0x80190504u: goto label_80190504;
    case 0x80190508u: goto label_80190508;
    case 0x8019050Cu: goto label_8019050C;
    case 0x80190510u: goto label_80190510;
    case 0x80190514u: goto label_80190514;
    case 0x80190518u: goto label_80190518;
    case 0x8019051Cu: goto label_8019051C;
    case 0x80190520u: goto label_80190520;
    case 0x80190524u: goto label_80190524;
    case 0x80190528u: goto label_80190528;
    case 0x8019052Cu: goto label_8019052C;
    case 0x80190530u: goto label_80190530;
    case 0x80190534u: goto label_80190534;
    case 0x80190538u: goto label_80190538;
    case 0x8019053Cu: goto label_8019053C;
    case 0x80190540u: goto label_80190540;
    case 0x80190544u: goto label_80190544;
    case 0x80190548u: goto label_80190548;
    case 0x8019054Cu: goto label_8019054C;
    case 0x80190550u: goto label_80190550;
    case 0x80190554u: goto label_80190554;
    case 0x80190558u: goto label_80190558;
    case 0x8019055Cu: goto label_8019055C;
    case 0x80190560u: goto label_80190560;
    case 0x80190564u: goto label_80190564;
    case 0x80190568u: goto label_80190568;
    case 0x8019056Cu: goto label_8019056C;
    case 0x80190570u: goto label_80190570;
    case 0x80190574u: goto label_80190574;
    case 0x80190578u: goto label_80190578;
    case 0x8019057Cu: goto label_8019057C;
    case 0x80190580u: goto label_80190580;
    case 0x80190584u: goto label_80190584;
    case 0x80190588u: goto label_80190588;
    case 0x8019058Cu: goto label_8019058C;
    case 0x80190590u: goto label_80190590;
    case 0x80190594u: goto label_80190594;
    case 0x80190598u: goto label_80190598;
    case 0x8019059Cu: goto label_8019059C;
    case 0x801905A0u: goto label_801905A0;
    case 0x801905A4u: goto label_801905A4;
    case 0x801905A8u: goto label_801905A8;
    case 0x801905ACu: goto label_801905AC;
    case 0x801905B0u: goto label_801905B0;
    case 0x801905B4u: goto label_801905B4;
    case 0x801905B8u: goto label_801905B8;
    case 0x801905BCu: goto label_801905BC;
    case 0x801905C0u: goto label_801905C0;
    case 0x801905C4u: goto label_801905C4;
    case 0x801905C8u: goto label_801905C8;
    case 0x801905CCu: goto label_801905CC;
    case 0x801905D0u: goto label_801905D0;
    case 0x801905D4u: goto label_801905D4;
    case 0x801905D8u: goto label_801905D8;
    case 0x801905DCu: goto label_801905DC;
    case 0x801905E0u: goto label_801905E0;
    case 0x801905E4u: goto label_801905E4;
    case 0x801905E8u: goto label_801905E8;
    case 0x801905ECu: goto label_801905EC;
    case 0x801905F0u: goto label_801905F0;
    case 0x801905F4u: goto label_801905F4;
    case 0x801905F8u: goto label_801905F8;
    case 0x801905FCu: goto label_801905FC;
    case 0x80190600u: goto label_80190600;
    case 0x80190604u: goto label_80190604;
    case 0x80190608u: goto label_80190608;
    case 0x8019060Cu: goto label_8019060C;
    case 0x80190610u: goto label_80190610;
    case 0x80190614u: goto label_80190614;
    case 0x80190618u: goto label_80190618;
    case 0x8019061Cu: goto label_8019061C;
    case 0x80190620u: goto label_80190620;
    case 0x80190624u: goto label_80190624;
    case 0x80190628u: goto label_80190628;
    case 0x8019062Cu: goto label_8019062C;
    case 0x80190630u: goto label_80190630;
    case 0x80190634u: goto label_80190634;
    case 0x80190638u: goto label_80190638;
    case 0x8019063Cu: goto label_8019063C;
    case 0x80190640u: goto label_80190640;
    case 0x80190644u: goto label_80190644;
    case 0x80190648u: goto label_80190648;
    case 0x8019064Cu: goto label_8019064C;
    case 0x80190650u: goto label_80190650;
    case 0x80190654u: goto label_80190654;
    case 0x80190658u: goto label_80190658;
    case 0x8019065Cu: goto label_8019065C;
    case 0x80190660u: goto label_80190660;
    case 0x80190664u: goto label_80190664;
    case 0x80190668u: goto label_80190668;
    case 0x8019066Cu: goto label_8019066C;
    case 0x80190670u: goto label_80190670;
    case 0x80190674u: goto label_80190674;
    case 0x80190678u: goto label_80190678;
    case 0x8019067Cu: goto label_8019067C;
    case 0x80190680u: goto label_80190680;
    case 0x80190684u: goto label_80190684;
    case 0x80190688u: goto label_80190688;
    case 0x8019068Cu: goto label_8019068C;
    case 0x80190690u: goto label_80190690;
    case 0x80190694u: goto label_80190694;
    case 0x80190698u: goto label_80190698;
    case 0x8019069Cu: goto label_8019069C;
    case 0x801906A0u: goto label_801906A0;
    case 0x801906A4u: goto label_801906A4;
    case 0x801906A8u: goto label_801906A8;
    case 0x801906ACu: goto label_801906AC;
    case 0x801906B0u: goto label_801906B0;
    case 0x801906B4u: goto label_801906B4;
    case 0x801906B8u: goto label_801906B8;
    case 0x801906BCu: goto label_801906BC;
    case 0x801906C0u: goto label_801906C0;
    case 0x801906C4u: goto label_801906C4;
    case 0x801906C8u: goto label_801906C8;
    case 0x801906CCu: goto label_801906CC;
    case 0x801906D0u: goto label_801906D0;
    case 0x801906D4u: goto label_801906D4;
    case 0x801906D8u: goto label_801906D8;
    case 0x801906DCu: goto label_801906DC;
    case 0x801906E0u: goto label_801906E0;
    case 0x801906E4u: goto label_801906E4;
    case 0x801906E8u: goto label_801906E8;
    case 0x801906ECu: goto label_801906EC;
    case 0x801906F0u: goto label_801906F0;
    case 0x801906F4u: goto label_801906F4;
    case 0x801906F8u: goto label_801906F8;
    case 0x801906FCu: goto label_801906FC;
    case 0x80190700u: goto label_80190700;
    case 0x80190704u: goto label_80190704;
    case 0x80190708u: goto label_80190708;
    case 0x8019070Cu: goto label_8019070C;
    case 0x80190710u: goto label_80190710;
    case 0x80190714u: goto label_80190714;
    case 0x80190718u: goto label_80190718;
    case 0x8019071Cu: goto label_8019071C;
    case 0x80190720u: goto label_80190720;
    case 0x80190724u: goto label_80190724;
    case 0x80190728u: goto label_80190728;
    case 0x8019072Cu: goto label_8019072C;
    case 0x80190730u: goto label_80190730;
    case 0x80190734u: goto label_80190734;
    case 0x80190738u: goto label_80190738;
    case 0x8019073Cu: goto label_8019073C;
    case 0x80190740u: goto label_80190740;
    case 0x80190744u: goto label_80190744;
    case 0x80190748u: goto label_80190748;
    case 0x8019074Cu: goto label_8019074C;
    case 0x80190750u: goto label_80190750;
    case 0x80190754u: goto label_80190754;
    case 0x80190758u: goto label_80190758;
    case 0x8019075Cu: goto label_8019075C;
    case 0x80190760u: goto label_80190760;
    case 0x80190764u: goto label_80190764;
    case 0x80190768u: goto label_80190768;
    case 0x8019076Cu: goto label_8019076C;
    case 0x80190770u: goto label_80190770;
    case 0x80190774u: goto label_80190774;
    case 0x80190778u: goto label_80190778;
    case 0x8019077Cu: goto label_8019077C;
    case 0x80190780u: goto label_80190780;
    case 0x80190784u: goto label_80190784;
    case 0x80190788u: goto label_80190788;
    case 0x8019078Cu: goto label_8019078C;
    case 0x80190790u: goto label_80190790;
    case 0x80190794u: goto label_80190794;
    case 0x80190798u: goto label_80190798;
    case 0x8019079Cu: goto label_8019079C;
    case 0x801907A0u: goto label_801907A0;
    case 0x801907A4u: goto label_801907A4;
    case 0x801907A8u: goto label_801907A8;
    case 0x801907ACu: goto label_801907AC;
    case 0x801907B0u: goto label_801907B0;
    case 0x801907B4u: goto label_801907B4;
    case 0x801907B8u: goto label_801907B8;
    case 0x801907BCu: goto label_801907BC;
    case 0x801907C0u: goto label_801907C0;
    case 0x801907C4u: goto label_801907C4;
    case 0x801907C8u: goto label_801907C8;
    case 0x801907CCu: goto label_801907CC;
    case 0x801907D0u: goto label_801907D0;
    case 0x801907D4u: goto label_801907D4;
    case 0x801907D8u: goto label_801907D8;
    case 0x801907DCu: goto label_801907DC;
    case 0x801907E0u: goto label_801907E0;
    case 0x801907E4u: goto label_801907E4;
    case 0x801907E8u: goto label_801907E8;
    case 0x801907ECu: goto label_801907EC;
    case 0x801907F0u: goto label_801907F0;
    case 0x801907F4u: goto label_801907F4;
    case 0x801907F8u: goto label_801907F8;
    case 0x801907FCu: goto label_801907FC;
    case 0x80190800u: goto label_80190800;
    case 0x80190804u: goto label_80190804;
    case 0x80190808u: goto label_80190808;
    case 0x8019080Cu: goto label_8019080C;
    case 0x80190810u: goto label_80190810;
    case 0x80190814u: goto label_80190814;
    case 0x80190818u: goto label_80190818;
    case 0x8019081Cu: goto label_8019081C;
    case 0x80190820u: goto label_80190820;
    case 0x80190824u: goto label_80190824;
    case 0x80190828u: goto label_80190828;
    case 0x8019082Cu: goto label_8019082C;
    case 0x80190830u: goto label_80190830;
    case 0x80190834u: goto label_80190834;
    case 0x80190838u: goto label_80190838;
    case 0x8019083Cu: goto label_8019083C;
    case 0x80190840u: goto label_80190840;
    case 0x80190844u: goto label_80190844;
    case 0x80190848u: goto label_80190848;
    case 0x8019084Cu: goto label_8019084C;
    case 0x80190850u: goto label_80190850;
    case 0x80190854u: goto label_80190854;
    case 0x80190858u: goto label_80190858;
    case 0x8019085Cu: goto label_8019085C;
    case 0x80190860u: goto label_80190860;
    case 0x80190864u: goto label_80190864;
    case 0x80190868u: goto label_80190868;
    case 0x8019086Cu: goto label_8019086C;
    case 0x80190870u: goto label_80190870;
    case 0x80190874u: goto label_80190874;
    case 0x80190878u: goto label_80190878;
    case 0x8019087Cu: goto label_8019087C;
    case 0x80190880u: goto label_80190880;
    case 0x80190884u: goto label_80190884;
    case 0x80190888u: goto label_80190888;
    case 0x8019088Cu: goto label_8019088C;
    case 0x80190890u: goto label_80190890;
    case 0x80190894u: goto label_80190894;
    case 0x80190898u: goto label_80190898;
    case 0x8019089Cu: goto label_8019089C;
    case 0x801908A0u: goto label_801908A0;
    case 0x801908A4u: goto label_801908A4;
    case 0x801908A8u: goto label_801908A8;
    case 0x801908ACu: goto label_801908AC;
    case 0x801908B0u: goto label_801908B0;
    case 0x801908B4u: goto label_801908B4;
    case 0x801908B8u: goto label_801908B8;
    case 0x801908BCu: goto label_801908BC;
    case 0x801908C0u: goto label_801908C0;
    case 0x801908C4u: goto label_801908C4;
    case 0x801908C8u: goto label_801908C8;
    case 0x801908CCu: goto label_801908CC;
    case 0x801908D0u: goto label_801908D0;
    case 0x801908D4u: goto label_801908D4;
    case 0x801908D8u: goto label_801908D8;
    case 0x801908DCu: goto label_801908DC;
    case 0x801908E0u: goto label_801908E0;
    case 0x801908E4u: goto label_801908E4;
    case 0x801908E8u: goto label_801908E8;
    case 0x801908ECu: goto label_801908EC;
    case 0x801908F0u: goto label_801908F0;
    case 0x801908F4u: goto label_801908F4;
    case 0x801908F8u: goto label_801908F8;
    case 0x801908FCu: goto label_801908FC;
    case 0x80190900u: goto label_80190900;
    case 0x80190904u: goto label_80190904;
    case 0x80190908u: goto label_80190908;
    case 0x8019090Cu: goto label_8019090C;
    case 0x80190910u: goto label_80190910;
    case 0x80190914u: goto label_80190914;
    case 0x80190918u: goto label_80190918;
    case 0x8019091Cu: goto label_8019091C;
    case 0x80190920u: goto label_80190920;
    case 0x80190924u: goto label_80190924;
    case 0x80190928u: goto label_80190928;
    case 0x8019092Cu: goto label_8019092C;
    case 0x80190930u: goto label_80190930;
    case 0x80190934u: goto label_80190934;
    case 0x80190938u: goto label_80190938;
    case 0x8019093Cu: goto label_8019093C;
    case 0x80190940u: goto label_80190940;
    case 0x80190944u: goto label_80190944;
    case 0x80190948u: goto label_80190948;
    case 0x8019094Cu: goto label_8019094C;
    case 0x80190950u: goto label_80190950;
    case 0x80190954u: goto label_80190954;
    case 0x80190958u: goto label_80190958;
    case 0x8019095Cu: goto label_8019095C;
    case 0x80190960u: goto label_80190960;
    case 0x80190964u: goto label_80190964;
    case 0x80190968u: goto label_80190968;
    case 0x8019096Cu: goto label_8019096C;
    case 0x80190970u: goto label_80190970;
    case 0x80190974u: goto label_80190974;
    case 0x80190978u: goto label_80190978;
    case 0x8019097Cu: goto label_8019097C;
    case 0x80190980u: goto label_80190980;
    case 0x80190984u: goto label_80190984;
    case 0x80190988u: goto label_80190988;
    case 0x8019098Cu: goto label_8019098C;
    case 0x80190990u: goto label_80190990;
    case 0x80190994u: goto label_80190994;
    case 0x80190998u: goto label_80190998;
    case 0x8019099Cu: goto label_8019099C;
    case 0x801909A0u: goto label_801909A0;
    case 0x801909A4u: goto label_801909A4;
    case 0x801909A8u: goto label_801909A8;
    case 0x801909ACu: goto label_801909AC;
    case 0x801909B0u: goto label_801909B0;
    case 0x801909B4u: goto label_801909B4;
    case 0x801909B8u: goto label_801909B8;
    case 0x801909BCu: goto label_801909BC;
    case 0x801909C0u: goto label_801909C0;
    case 0x801909C4u: goto label_801909C4;
    case 0x801909C8u: goto label_801909C8;
    case 0x801909CCu: goto label_801909CC;
    case 0x801909D0u: goto label_801909D0;
    case 0x801909D4u: goto label_801909D4;
    case 0x801909D8u: goto label_801909D8;
    case 0x801909DCu: goto label_801909DC;
    case 0x801909E0u: goto label_801909E0;
    case 0x801909E4u: goto label_801909E4;
    case 0x801909E8u: goto label_801909E8;
    case 0x801909ECu: goto label_801909EC;
    case 0x801909F0u: goto label_801909F0;
    case 0x801909F4u: goto label_801909F4;
    case 0x801909F8u: goto label_801909F8;
    case 0x801909FCu: goto label_801909FC;
    case 0x80190A00u: goto label_80190A00;
    case 0x80190A04u: goto label_80190A04;
    case 0x80190A08u: goto label_80190A08;
    case 0x80190A0Cu: goto label_80190A0C;
    case 0x80190A10u: goto label_80190A10;
    case 0x80190A14u: goto label_80190A14;
    case 0x80190A18u: goto label_80190A18;
    case 0x80190A1Cu: goto label_80190A1C;
    case 0x80190A20u: goto label_80190A20;
    case 0x80190A24u: goto label_80190A24;
    case 0x80190A28u: goto label_80190A28;
    case 0x80190A2Cu: goto label_80190A2C;
    case 0x80190A30u: goto label_80190A30;
    case 0x80190A34u: goto label_80190A34;
    case 0x80190A38u: goto label_80190A38;
    case 0x80190A3Cu: goto label_80190A3C;
    case 0x80190A40u: goto label_80190A40;
    case 0x80190A44u: goto label_80190A44;
    case 0x80190A48u: goto label_80190A48;
    case 0x80190A4Cu: goto label_80190A4C;
    case 0x80190A50u: goto label_80190A50;
    case 0x80190A54u: goto label_80190A54;
    case 0x80190A58u: goto label_80190A58;
    case 0x80190A5Cu: goto label_80190A5C;
    case 0x80190A60u: goto label_80190A60;
    case 0x80190A64u: goto label_80190A64;
    case 0x80190A68u: goto label_80190A68;
    case 0x80190A6Cu: goto label_80190A6C;
    case 0x80190A70u: goto label_80190A70;
    case 0x80190A74u: goto label_80190A74;
    case 0x80190A78u: goto label_80190A78;
    case 0x80190A7Cu: goto label_80190A7C;
    case 0x80190A80u: goto label_80190A80;
    case 0x80190A84u: goto label_80190A84;
    case 0x80190A88u: goto label_80190A88;
    case 0x80190A8Cu: goto label_80190A8C;
    case 0x80190A90u: goto label_80190A90;
    case 0x80190A94u: goto label_80190A94;
    case 0x80190A98u: goto label_80190A98;
    case 0x80190A9Cu: goto label_80190A9C;
    case 0x80190AA0u: goto label_80190AA0;
    case 0x80190AA4u: goto label_80190AA4;
    case 0x80190AA8u: goto label_80190AA8;
    case 0x80190AACu: goto label_80190AAC;
    case 0x80190AB0u: goto label_80190AB0;
    case 0x80190AB4u: goto label_80190AB4;
    case 0x80190AB8u: goto label_80190AB8;
    case 0x80190ABCu: goto label_80190ABC;
    case 0x80190AC0u: goto label_80190AC0;
    case 0x80190AC4u: goto label_80190AC4;
    case 0x80190AC8u: goto label_80190AC8;
    case 0x80190ACCu: goto label_80190ACC;
    case 0x80190AD0u: goto label_80190AD0;
    case 0x80190AD4u: goto label_80190AD4;
    case 0x80190AD8u: goto label_80190AD8;
    case 0x80190ADCu: goto label_80190ADC;
    case 0x80190AE0u: goto label_80190AE0;
    case 0x80190AE4u: goto label_80190AE4;
    case 0x80190AE8u: goto label_80190AE8;
    case 0x80190AECu: goto label_80190AEC;
    case 0x80190AF0u: goto label_80190AF0;
    case 0x80190AF4u: goto label_80190AF4;
    case 0x80190AF8u: goto label_80190AF8;
    case 0x80190AFCu: goto label_80190AFC;
    case 0x80190B00u: goto label_80190B00;
    case 0x80190B04u: goto label_80190B04;
    case 0x80190B08u: goto label_80190B08;
    case 0x80190B0Cu: goto label_80190B0C;
    case 0x80190B10u: goto label_80190B10;
    case 0x80190B14u: goto label_80190B14;
    case 0x80190B18u: goto label_80190B18;
    case 0x80190B1Cu: goto label_80190B1C;
    case 0x80190B20u: goto label_80190B20;
    case 0x80190B24u: goto label_80190B24;
    case 0x80190B28u: goto label_80190B28;
    case 0x80190B2Cu: goto label_80190B2C;
    case 0x80190B30u: goto label_80190B30;
    case 0x80190B34u: goto label_80190B34;
    case 0x80190B38u: goto label_80190B38;
    case 0x80190B3Cu: goto label_80190B3C;
    case 0x80190B40u: goto label_80190B40;
    case 0x80190B44u: goto label_80190B44;
    case 0x80190B48u: goto label_80190B48;
    case 0x80190B4Cu: goto label_80190B4C;
    case 0x80190B50u: goto label_80190B50;
    case 0x80190B54u: goto label_80190B54;
    case 0x80190B58u: goto label_80190B58;
    case 0x80190B5Cu: goto label_80190B5C;
    case 0x80190B60u: goto label_80190B60;
    case 0x80190B64u: goto label_80190B64;
    case 0x80190B68u: goto label_80190B68;
    case 0x80190B6Cu: goto label_80190B6C;
    case 0x80190B70u: goto label_80190B70;
    case 0x80190B74u: goto label_80190B74;
    case 0x80190B78u: goto label_80190B78;
    case 0x80190B7Cu: goto label_80190B7C;
    case 0x80190B80u: goto label_80190B80;
    case 0x80190B84u: goto label_80190B84;
    case 0x80190B88u: goto label_80190B88;
    case 0x80190B8Cu: goto label_80190B8C;
    case 0x80190B90u: goto label_80190B90;
    case 0x80190B94u: goto label_80190B94;
    case 0x80190B98u: goto label_80190B98;
    case 0x80190B9Cu: goto label_80190B9C;
    case 0x80190BA0u: goto label_80190BA0;
    case 0x80190BA4u: goto label_80190BA4;
    case 0x80190BA8u: goto label_80190BA8;
    case 0x80190BACu: goto label_80190BAC;
    case 0x80190BB0u: goto label_80190BB0;
    case 0x80190BB4u: goto label_80190BB4;
    case 0x80190BB8u: goto label_80190BB8;
    case 0x80190BBCu: goto label_80190BBC;
    case 0x80190BC0u: goto label_80190BC0;
    case 0x80190BC4u: goto label_80190BC4;
    case 0x80190BC8u: goto label_80190BC8;
    case 0x80190BCCu: goto label_80190BCC;
    case 0x80190BD0u: goto label_80190BD0;
    case 0x80190BD4u: goto label_80190BD4;
    case 0x80190BD8u: goto label_80190BD8;
    case 0x80190BDCu: goto label_80190BDC;
    case 0x80190BE0u: goto label_80190BE0;
    case 0x80190BE4u: goto label_80190BE4;
    case 0x80190BE8u: goto label_80190BE8;
    case 0x80190BECu: goto label_80190BEC;
    case 0x80190BF0u: goto label_80190BF0;
    case 0x80190BF4u: goto label_80190BF4;
    case 0x80190BF8u: goto label_80190BF8;
    case 0x80190BFCu: goto label_80190BFC;
    case 0x80190C00u: goto label_80190C00;
    case 0x80190C04u: goto label_80190C04;
    case 0x80190C08u: goto label_80190C08;
    case 0x80190C0Cu: goto label_80190C0C;
    case 0x80190C10u: goto label_80190C10;
    case 0x80190C14u: goto label_80190C14;
    case 0x80190C18u: goto label_80190C18;
    case 0x80190C1Cu: goto label_80190C1C;
    case 0x80190C20u: goto label_80190C20;
    case 0x80190C24u: goto label_80190C24;
    case 0x80190C28u: goto label_80190C28;
    case 0x80190C2Cu: goto label_80190C2C;
    case 0x80190C30u: goto label_80190C30;
    case 0x80190C34u: goto label_80190C34;
    case 0x80190C38u: goto label_80190C38;
    case 0x80190C3Cu: goto label_80190C3C;
    case 0x80190C40u: goto label_80190C40;
    case 0x80190C44u: goto label_80190C44;
    case 0x80190C48u: goto label_80190C48;
    case 0x80190C4Cu: goto label_80190C4C;
    case 0x80190C50u: goto label_80190C50;
    case 0x80190C54u: goto label_80190C54;
    case 0x80190C58u: goto label_80190C58;
    case 0x80190C5Cu: goto label_80190C5C;
    case 0x80190C60u: goto label_80190C60;
    case 0x80190C64u: goto label_80190C64;
    case 0x80190C68u: goto label_80190C68;
    case 0x80190C6Cu: goto label_80190C6C;
    case 0x80190C70u: goto label_80190C70;
    case 0x80190C74u: goto label_80190C74;
    case 0x80190C78u: goto label_80190C78;
    case 0x80190C7Cu: goto label_80190C7C;
    case 0x80190C80u: goto label_80190C80;
    case 0x80190C84u: goto label_80190C84;
    case 0x80190C88u: goto label_80190C88;
    case 0x80190C8Cu: goto label_80190C8C;
    case 0x80190C90u: goto label_80190C90;
    case 0x80190C94u: goto label_80190C94;
    case 0x80190C98u: goto label_80190C98;
    case 0x80190C9Cu: goto label_80190C9C;
    case 0x80190CA0u: goto label_80190CA0;
    case 0x80190CA4u: goto label_80190CA4;
    case 0x80190CA8u: goto label_80190CA8;
    case 0x80190CACu: goto label_80190CAC;
    case 0x80190CB0u: goto label_80190CB0;
    case 0x80190CB4u: goto label_80190CB4;
    case 0x80190CB8u: goto label_80190CB8;
    case 0x80190CBCu: goto label_80190CBC;
    case 0x80190CC0u: goto label_80190CC0;
    case 0x80190CC4u: goto label_80190CC4;
    case 0x80190CC8u: goto label_80190CC8;
    case 0x80190CCCu: goto label_80190CCC;
    case 0x80190CD0u: goto label_80190CD0;
    case 0x80190CD4u: goto label_80190CD4;
    case 0x80190CD8u: goto label_80190CD8;
    case 0x80190CDCu: goto label_80190CDC;
    case 0x80190CE0u: goto label_80190CE0;
    case 0x80190CE4u: goto label_80190CE4;
    case 0x80190CE8u: goto label_80190CE8;
    case 0x80190CECu: goto label_80190CEC;
    case 0x80190CF0u: goto label_80190CF0;
    case 0x80190CF4u: goto label_80190CF4;
    case 0x80190CF8u: goto label_80190CF8;
    case 0x80190CFCu: goto label_80190CFC;
    case 0x80190D00u: goto label_80190D00;
    case 0x80190D04u: goto label_80190D04;
    case 0x80190D08u: goto label_80190D08;
    case 0x80190D0Cu: goto label_80190D0C;
    case 0x80190D10u: goto label_80190D10;
    case 0x80190D14u: goto label_80190D14;
    case 0x80190D18u: goto label_80190D18;
    case 0x80190D1Cu: goto label_80190D1C;
    case 0x80190D20u: goto label_80190D20;
    case 0x80190D24u: goto label_80190D24;
    case 0x80190D28u: goto label_80190D28;
    case 0x80190D2Cu: goto label_80190D2C;
    case 0x80190D30u: goto label_80190D30;
    case 0x80190D34u: goto label_80190D34;
    case 0x80190D38u: goto label_80190D38;
    case 0x80190D3Cu: goto label_80190D3C;
    case 0x80190D40u: goto label_80190D40;
    case 0x80190D44u: goto label_80190D44;
    case 0x80190D48u: goto label_80190D48;
    case 0x80190D4Cu: goto label_80190D4C;
    case 0x80190D50u: goto label_80190D50;
    case 0x80190D54u: goto label_80190D54;
    case 0x80190D58u: goto label_80190D58;
    case 0x80190D5Cu: goto label_80190D5C;
    case 0x80190D60u: goto label_80190D60;
    case 0x80190D64u: goto label_80190D64;
    case 0x80190D68u: goto label_80190D68;
    case 0x80190D6Cu: goto label_80190D6C;
    case 0x80190D70u: goto label_80190D70;
    case 0x80190D74u: goto label_80190D74;
    case 0x80190D78u: goto label_80190D78;
    case 0x80190D7Cu: goto label_80190D7C;
    case 0x80190D80u: goto label_80190D80;
    case 0x80190D84u: goto label_80190D84;
    case 0x80190D88u: goto label_80190D88;
    case 0x80190D8Cu: goto label_80190D8C;
    case 0x80190D90u: goto label_80190D90;
    case 0x80190D94u: goto label_80190D94;
    case 0x80190D98u: goto label_80190D98;
    case 0x80190D9Cu: goto label_80190D9C;
    case 0x80190DA0u: goto label_80190DA0;
    case 0x80190DA4u: goto label_80190DA4;
    case 0x80190DA8u: goto label_80190DA8;
    case 0x80190DACu: goto label_80190DAC;
    case 0x80190DB0u: goto label_80190DB0;
    case 0x80190DB4u: goto label_80190DB4;
    case 0x80190DB8u: goto label_80190DB8;
    case 0x80190DBCu: goto label_80190DBC;
    case 0x80190DC0u: goto label_80190DC0;
    case 0x80190DC4u: goto label_80190DC4;
    case 0x80190DC8u: goto label_80190DC8;
    case 0x80190DCCu: goto label_80190DCC;
    case 0x80190DD0u: goto label_80190DD0;
    case 0x80190DD4u: goto label_80190DD4;
    case 0x80190DD8u: goto label_80190DD8;
    case 0x80190DDCu: goto label_80190DDC;
    case 0x80190DE0u: goto label_80190DE0;
    case 0x80190DE4u: goto label_80190DE4;
    case 0x80190DE8u: goto label_80190DE8;
    case 0x80190DECu: goto label_80190DEC;
    case 0x80190DF0u: goto label_80190DF0;
    case 0x80190DF4u: goto label_80190DF4;
    case 0x80190DF8u: goto label_80190DF8;
    case 0x80190DFCu: goto label_80190DFC;
    case 0x80190E00u: goto label_80190E00;
    case 0x80190E04u: goto label_80190E04;
    case 0x80190E08u: goto label_80190E08;
    case 0x80190E0Cu: goto label_80190E0C;
    case 0x80190E10u: goto label_80190E10;
    case 0x80190E14u: goto label_80190E14;
    case 0x80190E18u: goto label_80190E18;
    case 0x80190E1Cu: goto label_80190E1C;
    case 0x80190E20u: goto label_80190E20;
    case 0x80190E24u: goto label_80190E24;
    case 0x80190E28u: goto label_80190E28;
    case 0x80190E2Cu: goto label_80190E2C;
    case 0x80190E30u: goto label_80190E30;
    case 0x80190E34u: goto label_80190E34;
    case 0x80190E38u: goto label_80190E38;
    case 0x80190E3Cu: goto label_80190E3C;
    case 0x80190E40u: goto label_80190E40;
    case 0x80190E44u: goto label_80190E44;
    case 0x80190E48u: goto label_80190E48;
    case 0x80190E4Cu: goto label_80190E4C;
    case 0x80190E50u: goto label_80190E50;
    case 0x80190E54u: goto label_80190E54;
    case 0x80190E58u: goto label_80190E58;
    case 0x80190E5Cu: goto label_80190E5C;
    case 0x80190E60u: goto label_80190E60;
    case 0x80190E64u: goto label_80190E64;
    case 0x80190E68u: goto label_80190E68;
    case 0x80190E6Cu: goto label_80190E6C;
    case 0x80190E70u: goto label_80190E70;
    case 0x80190E74u: goto label_80190E74;
    case 0x80190E78u: goto label_80190E78;
    case 0x80190E7Cu: goto label_80190E7C;
    case 0x80190E80u: goto label_80190E80;
    case 0x80190E84u: goto label_80190E84;
    case 0x80190E88u: goto label_80190E88;
    case 0x80190E8Cu: goto label_80190E8C;
    case 0x80190E90u: goto label_80190E90;
    case 0x80190E94u: goto label_80190E94;
    case 0x80190E98u: goto label_80190E98;
    case 0x80190E9Cu: goto label_80190E9C;
    case 0x80190EA0u: goto label_80190EA0;
    case 0x80190EA4u: goto label_80190EA4;
    case 0x80190EA8u: goto label_80190EA8;
    case 0x80190EACu: goto label_80190EAC;
    case 0x80190EB0u: goto label_80190EB0;
    case 0x80190EB4u: goto label_80190EB4;
    case 0x80190EB8u: goto label_80190EB8;
    case 0x80190EBCu: goto label_80190EBC;
    case 0x80190EC0u: goto label_80190EC0;
    case 0x80190EC4u: goto label_80190EC4;
    case 0x80190EC8u: goto label_80190EC8;
    case 0x80190ECCu: goto label_80190ECC;
    case 0x80190ED0u: goto label_80190ED0;
    case 0x80190ED4u: goto label_80190ED4;
    case 0x80190ED8u: goto label_80190ED8;
    case 0x80190EDCu: goto label_80190EDC;
    case 0x80190EE0u: goto label_80190EE0;
    case 0x80190EE4u: goto label_80190EE4;
    case 0x80190EE8u: goto label_80190EE8;
    case 0x80190EECu: goto label_80190EEC;
    case 0x80190EF0u: goto label_80190EF0;
    case 0x80190EF4u: goto label_80190EF4;
    case 0x80190EF8u: goto label_80190EF8;
    case 0x80190EFCu: goto label_80190EFC;
    case 0x80190F00u: goto label_80190F00;
    case 0x80190F04u: goto label_80190F04;
    case 0x80190F08u: goto label_80190F08;
    case 0x80190F0Cu: goto label_80190F0C;
    case 0x80190F10u: goto label_80190F10;
    case 0x80190F14u: goto label_80190F14;
    case 0x80190F18u: goto label_80190F18;
    case 0x80190F1Cu: goto label_80190F1C;
    case 0x80190F20u: goto label_80190F20;
    case 0x80190F24u: goto label_80190F24;
    case 0x80190F28u: goto label_80190F28;
    case 0x80190F2Cu: goto label_80190F2C;
    case 0x80190F30u: goto label_80190F30;
    case 0x80190F34u: goto label_80190F34;
    case 0x80190F38u: goto label_80190F38;
    case 0x80190F3Cu: goto label_80190F3C;
    case 0x80190F40u: goto label_80190F40;
    case 0x80190F44u: goto label_80190F44;
    case 0x80190F48u: goto label_80190F48;
    case 0x80190F4Cu: goto label_80190F4C;
    case 0x80190F50u: goto label_80190F50;
    case 0x80190F54u: goto label_80190F54;
    case 0x80190F58u: goto label_80190F58;
    case 0x80190F5Cu: goto label_80190F5C;
    case 0x80190F60u: goto label_80190F60;
    case 0x80190F64u: goto label_80190F64;
    case 0x80190F68u: goto label_80190F68;
    case 0x80190F6Cu: goto label_80190F6C;
    case 0x80190F70u: goto label_80190F70;
    case 0x80190F74u: goto label_80190F74;
    case 0x80190F78u: goto label_80190F78;
    case 0x80190F7Cu: goto label_80190F7C;
    case 0x80190F80u: goto label_80190F80;
    case 0x80190F84u: goto label_80190F84;
    case 0x80190F88u: goto label_80190F88;
    case 0x80190F8Cu: goto label_80190F8C;
    case 0x80190F90u: goto label_80190F90;
    case 0x80190F94u: goto label_80190F94;
    case 0x80190F98u: goto label_80190F98;
    case 0x80190F9Cu: goto label_80190F9C;
    case 0x80190FA0u: goto label_80190FA0;
    case 0x80190FA4u: goto label_80190FA4;
    case 0x80190FA8u: goto label_80190FA8;
    case 0x80190FACu: goto label_80190FAC;
    case 0x80190FB0u: goto label_80190FB0;
    case 0x80190FB4u: goto label_80190FB4;
    case 0x80190FB8u: goto label_80190FB8;
    case 0x80190FBCu: goto label_80190FBC;
    case 0x80190FC0u: goto label_80190FC0;
    case 0x80190FC4u: goto label_80190FC4;
    case 0x80190FC8u: goto label_80190FC8;
    case 0x80190FCCu: goto label_80190FCC;
    case 0x80190FD0u: goto label_80190FD0;
    case 0x80190FD4u: goto label_80190FD4;
    case 0x80190FD8u: goto label_80190FD8;
    case 0x80190FDCu: goto label_80190FDC;
    case 0x80190FE0u: goto label_80190FE0;
    case 0x80190FE4u: goto label_80190FE4;
    case 0x80190FE8u: goto label_80190FE8;
    case 0x80190FECu: goto label_80190FEC;
    case 0x80190FF0u: goto label_80190FF0;
    case 0x80190FF4u: goto label_80190FF4;
    case 0x80190FF8u: goto label_80190FF8;
    case 0x80190FFCu: goto label_80190FFC;
    case 0x80191000u: goto label_80191000;
    case 0x80191004u: goto label_80191004;
    case 0x80191008u: goto label_80191008;
    case 0x8019100Cu: goto label_8019100C;
    case 0x80191010u: goto label_80191010;
    case 0x80191014u: goto label_80191014;
    case 0x80191018u: goto label_80191018;
    case 0x8019101Cu: goto label_8019101C;
    case 0x80191020u: goto label_80191020;
    case 0x80191024u: goto label_80191024;
    case 0x80191028u: goto label_80191028;
    case 0x8019102Cu: goto label_8019102C;
    case 0x80191030u: goto label_80191030;
    case 0x80191034u: goto label_80191034;
    case 0x80191038u: goto label_80191038;
    case 0x8019103Cu: goto label_8019103C;
    case 0x80191040u: goto label_80191040;
    case 0x80191044u: goto label_80191044;
    case 0x80191048u: goto label_80191048;
    case 0x8019104Cu: goto label_8019104C;
    case 0x80191050u: goto label_80191050;
    case 0x80191054u: goto label_80191054;
    case 0x80191058u: goto label_80191058;
    case 0x8019105Cu: goto label_8019105C;
    case 0x80191060u: goto label_80191060;
    case 0x80191064u: goto label_80191064;
    case 0x80191068u: goto label_80191068;
    case 0x8019106Cu: goto label_8019106C;
    case 0x80191070u: goto label_80191070;
    case 0x80191074u: goto label_80191074;
    case 0x80191078u: goto label_80191078;
    case 0x8019107Cu: goto label_8019107C;
    case 0x80191080u: goto label_80191080;
    case 0x80191084u: goto label_80191084;
    case 0x80191088u: goto label_80191088;
    case 0x8019108Cu: goto label_8019108C;
    case 0x80191090u: goto label_80191090;
    case 0x80191094u: goto label_80191094;
    case 0x80191098u: goto label_80191098;
    case 0x8019109Cu: goto label_8019109C;
    case 0x801910A0u: goto label_801910A0;
    case 0x801910A4u: goto label_801910A4;
    case 0x801910A8u: goto label_801910A8;
    case 0x801910ACu: goto label_801910AC;
    case 0x801910B0u: goto label_801910B0;
    case 0x801910B4u: goto label_801910B4;
    case 0x801910B8u: goto label_801910B8;
    case 0x801910BCu: goto label_801910BC;
    case 0x801910C0u: goto label_801910C0;
    case 0x801910C4u: goto label_801910C4;
    case 0x801910C8u: goto label_801910C8;
    case 0x801910CCu: goto label_801910CC;
    case 0x801910D0u: goto label_801910D0;
    case 0x801910D4u: goto label_801910D4;
    case 0x801910D8u: goto label_801910D8;
    case 0x801910DCu: goto label_801910DC;
    case 0x801910E0u: goto label_801910E0;
    case 0x801910E4u: goto label_801910E4;
    case 0x801910E8u: goto label_801910E8;
    case 0x801910ECu: goto label_801910EC;
    case 0x801910F0u: goto label_801910F0;
    case 0x801910F4u: goto label_801910F4;
    case 0x801910F8u: goto label_801910F8;
    case 0x801910FCu: goto label_801910FC;
    case 0x80191100u: goto label_80191100;
    case 0x80191104u: goto label_80191104;
    case 0x80191108u: goto label_80191108;
    case 0x8019110Cu: goto label_8019110C;
    case 0x80191110u: goto label_80191110;
    case 0x80191114u: goto label_80191114;
    case 0x80191118u: goto label_80191118;
    case 0x8019111Cu: goto label_8019111C;
    case 0x80191120u: goto label_80191120;
    case 0x80191124u: goto label_80191124;
    case 0x80191128u: goto label_80191128;
    case 0x8019112Cu: goto label_8019112C;
    case 0x80191130u: goto label_80191130;
    case 0x80191134u: goto label_80191134;
    case 0x80191138u: goto label_80191138;
    case 0x8019113Cu: goto label_8019113C;
    case 0x80191140u: goto label_80191140;
    case 0x80191144u: goto label_80191144;
    case 0x80191148u: goto label_80191148;
    case 0x8019114Cu: goto label_8019114C;
    case 0x80191150u: goto label_80191150;
    case 0x80191154u: goto label_80191154;
    case 0x80191158u: goto label_80191158;
    case 0x8019115Cu: goto label_8019115C;
    case 0x80191160u: goto label_80191160;
    case 0x80191164u: goto label_80191164;
    case 0x80191168u: goto label_80191168;
    case 0x8019116Cu: goto label_8019116C;
    case 0x80191170u: goto label_80191170;
    case 0x80191174u: goto label_80191174;
    case 0x80191178u: goto label_80191178;
    case 0x8019117Cu: goto label_8019117C;
    case 0x80191180u: goto label_80191180;
    case 0x80191184u: goto label_80191184;
    case 0x80191188u: goto label_80191188;
    case 0x8019118Cu: goto label_8019118C;
    case 0x80191190u: goto label_80191190;
    case 0x80191194u: goto label_80191194;
    case 0x80191198u: goto label_80191198;
    case 0x8019119Cu: goto label_8019119C;
    case 0x801911A0u: goto label_801911A0;
    case 0x801911A4u: goto label_801911A4;
    case 0x801911A8u: goto label_801911A8;
    case 0x801911ACu: goto label_801911AC;
    case 0x801911B0u: goto label_801911B0;
    case 0x801911B4u: goto label_801911B4;
    case 0x801911B8u: goto label_801911B8;
    case 0x801911BCu: goto label_801911BC;
    case 0x801911C0u: goto label_801911C0;
    case 0x801911C4u: goto label_801911C4;
    case 0x801911C8u: goto label_801911C8;
    case 0x801911CCu: goto label_801911CC;
    case 0x801911D0u: goto label_801911D0;
    case 0x801911D4u: goto label_801911D4;
    case 0x801911D8u: goto label_801911D8;
    case 0x801911DCu: goto label_801911DC;
    case 0x801911E0u: goto label_801911E0;
    case 0x801911E4u: goto label_801911E4;
    case 0x801911E8u: goto label_801911E8;
    case 0x801911ECu: goto label_801911EC;
    case 0x801911F0u: goto label_801911F0;
    case 0x801911F4u: goto label_801911F4;
    case 0x801911F8u: goto label_801911F8;
    case 0x801911FCu: goto label_801911FC;
    case 0x80191200u: goto label_80191200;
    case 0x80191204u: goto label_80191204;
    case 0x80191208u: goto label_80191208;
    case 0x8019120Cu: goto label_8019120C;
    case 0x80191210u: goto label_80191210;
    case 0x80191214u: goto label_80191214;
    case 0x80191218u: goto label_80191218;
    case 0x8019121Cu: goto label_8019121C;
    case 0x80191220u: goto label_80191220;
    case 0x80191224u: goto label_80191224;
    case 0x80191228u: goto label_80191228;
    case 0x8019122Cu: goto label_8019122C;
    case 0x80191230u: goto label_80191230;
    case 0x80191234u: goto label_80191234;
    case 0x80191238u: goto label_80191238;
    case 0x8019123Cu: goto label_8019123C;
    case 0x80191240u: goto label_80191240;
    case 0x80191244u: goto label_80191244;
    case 0x80191248u: goto label_80191248;
    case 0x8019124Cu: goto label_8019124C;
    case 0x80191250u: goto label_80191250;
    case 0x80191254u: goto label_80191254;
    case 0x80191258u: goto label_80191258;
    case 0x8019125Cu: goto label_8019125C;
    case 0x80191260u: goto label_80191260;
    case 0x80191264u: goto label_80191264;
    case 0x80191268u: goto label_80191268;
    case 0x8019126Cu: goto label_8019126C;
    case 0x80191270u: goto label_80191270;
    case 0x80191274u: goto label_80191274;
    case 0x80191278u: goto label_80191278;
    case 0x8019127Cu: goto label_8019127C;
    case 0x80191280u: goto label_80191280;
    case 0x80191284u: goto label_80191284;
    case 0x80191288u: goto label_80191288;
    case 0x8019128Cu: goto label_8019128C;
    case 0x80191290u: goto label_80191290;
    case 0x80191294u: goto label_80191294;
    case 0x80191298u: goto label_80191298;
    case 0x8019129Cu: goto label_8019129C;
    case 0x801912A0u: goto label_801912A0;
    case 0x801912A4u: goto label_801912A4;
    case 0x801912A8u: goto label_801912A8;
    case 0x801912ACu: goto label_801912AC;
    case 0x801912B0u: goto label_801912B0;
    case 0x801912B4u: goto label_801912B4;
    case 0x801912B8u: goto label_801912B8;
    case 0x801912BCu: goto label_801912BC;
    case 0x801912C0u: goto label_801912C0;
    case 0x801912C4u: goto label_801912C4;
    case 0x801912C8u: goto label_801912C8;
    case 0x801912CCu: goto label_801912CC;
    case 0x801912D0u: goto label_801912D0;
    case 0x801912D4u: goto label_801912D4;
    case 0x801912D8u: goto label_801912D8;
    case 0x801912DCu: goto label_801912DC;
    case 0x801912E0u: goto label_801912E0;
    case 0x801912E4u: goto label_801912E4;
    case 0x801912E8u: goto label_801912E8;
    case 0x801912ECu: goto label_801912EC;
    case 0x801912F0u: goto label_801912F0;
    case 0x801912F4u: goto label_801912F4;
    case 0x801912F8u: goto label_801912F8;
    case 0x801912FCu: goto label_801912FC;
    case 0x80191300u: goto label_80191300;
    case 0x80191304u: goto label_80191304;
    case 0x80191308u: goto label_80191308;
    case 0x8019130Cu: goto label_8019130C;
    case 0x80191310u: goto label_80191310;
    case 0x80191314u: goto label_80191314;
    case 0x80191318u: goto label_80191318;
    case 0x8019131Cu: goto label_8019131C;
    case 0x80191320u: goto label_80191320;
    case 0x80191324u: goto label_80191324;
    case 0x80191328u: goto label_80191328;
    case 0x8019132Cu: goto label_8019132C;
    case 0x80191330u: goto label_80191330;
    case 0x80191334u: goto label_80191334;
    case 0x80191338u: goto label_80191338;
    case 0x8019133Cu: goto label_8019133C;
    case 0x80191340u: goto label_80191340;
    case 0x80191344u: goto label_80191344;
    case 0x80191348u: goto label_80191348;
    case 0x8019134Cu: goto label_8019134C;
    case 0x80191350u: goto label_80191350;
    case 0x80191354u: goto label_80191354;
    case 0x80191358u: goto label_80191358;
    case 0x8019135Cu: goto label_8019135C;
    case 0x80191360u: goto label_80191360;
    case 0x80191364u: goto label_80191364;
    case 0x80191368u: goto label_80191368;
    case 0x8019136Cu: goto label_8019136C;
    case 0x80191370u: goto label_80191370;
    case 0x80191374u: goto label_80191374;
    case 0x80191378u: goto label_80191378;
    case 0x8019137Cu: goto label_8019137C;
    case 0x80191380u: goto label_80191380;
    case 0x80191384u: goto label_80191384;
    case 0x80191388u: goto label_80191388;
    case 0x8019138Cu: goto label_8019138C;
    case 0x80191390u: goto label_80191390;
    case 0x80191394u: goto label_80191394;
    case 0x80191398u: goto label_80191398;
    case 0x8019139Cu: goto label_8019139C;
    case 0x801913A0u: goto label_801913A0;
    case 0x801913A4u: goto label_801913A4;
    case 0x801913A8u: goto label_801913A8;
    case 0x801913ACu: goto label_801913AC;
    case 0x801913B0u: goto label_801913B0;
    case 0x801913B4u: goto label_801913B4;
    case 0x801913B8u: goto label_801913B8;
    case 0x801913BCu: goto label_801913BC;
    case 0x801913C0u: goto label_801913C0;
    case 0x801913C4u: goto label_801913C4;
    case 0x801913C8u: goto label_801913C8;
    case 0x801913CCu: goto label_801913CC;
    case 0x801913D0u: goto label_801913D0;
    case 0x801913D4u: goto label_801913D4;
    case 0x801913D8u: goto label_801913D8;
    case 0x801913DCu: goto label_801913DC;
    case 0x801913E0u: goto label_801913E0;
    case 0x801913E4u: goto label_801913E4;
    case 0x801913E8u: goto label_801913E8;
    case 0x801913ECu: goto label_801913EC;
    case 0x801913F0u: goto label_801913F0;
    case 0x801913F4u: goto label_801913F4;
    case 0x801913F8u: goto label_801913F8;
    case 0x801913FCu: goto label_801913FC;
    case 0x80191400u: goto label_80191400;
    case 0x80191404u: goto label_80191404;
    case 0x80191408u: goto label_80191408;
    case 0x8019140Cu: goto label_8019140C;
    case 0x80191410u: goto label_80191410;
    case 0x80191414u: goto label_80191414;
    case 0x80191418u: goto label_80191418;
    case 0x8019141Cu: goto label_8019141C;
    case 0x80191420u: goto label_80191420;
    case 0x80191424u: goto label_80191424;
    case 0x80191428u: goto label_80191428;
    case 0x8019142Cu: goto label_8019142C;
    case 0x80191430u: goto label_80191430;
    case 0x80191434u: goto label_80191434;
    case 0x80191438u: goto label_80191438;
    case 0x8019143Cu: goto label_8019143C;
    case 0x80191440u: goto label_80191440;
    case 0x80191444u: goto label_80191444;
    case 0x80191448u: goto label_80191448;
    case 0x8019144Cu: goto label_8019144C;
    case 0x80191450u: goto label_80191450;
    case 0x80191454u: goto label_80191454;
    case 0x80191458u: goto label_80191458;
    case 0x8019145Cu: goto label_8019145C;
    case 0x80191460u: goto label_80191460;
    case 0x80191464u: goto label_80191464;
    case 0x80191468u: goto label_80191468;
    case 0x8019146Cu: goto label_8019146C;
    case 0x80191470u: goto label_80191470;
    case 0x80191474u: goto label_80191474;
    case 0x80191478u: goto label_80191478;
    case 0x8019147Cu: goto label_8019147C;
    case 0x80191480u: goto label_80191480;
    case 0x80191484u: goto label_80191484;
    case 0x80191488u: goto label_80191488;
    case 0x8019148Cu: goto label_8019148C;
    case 0x80191490u: goto label_80191490;
    case 0x80191494u: goto label_80191494;
    case 0x80191498u: goto label_80191498;
    case 0x8019149Cu: goto label_8019149C;
    case 0x801914A0u: goto label_801914A0;
    case 0x801914A4u: goto label_801914A4;
    case 0x801914A8u: goto label_801914A8;
    case 0x801914ACu: goto label_801914AC;
    case 0x801914B0u: goto label_801914B0;
    case 0x801914B4u: goto label_801914B4;
    case 0x801914B8u: goto label_801914B8;
    case 0x801914BCu: goto label_801914BC;
    case 0x801914C0u: goto label_801914C0;
    case 0x801914C4u: goto label_801914C4;
    case 0x801914C8u: goto label_801914C8;
    case 0x801914CCu: goto label_801914CC;
    case 0x801914D0u: goto label_801914D0;
    case 0x801914D4u: goto label_801914D4;
    case 0x801914D8u: goto label_801914D8;
    case 0x801914DCu: goto label_801914DC;
    case 0x801914E0u: goto label_801914E0;
    case 0x801914E4u: goto label_801914E4;
    case 0x801914E8u: goto label_801914E8;
    case 0x801914ECu: goto label_801914EC;
    case 0x801914F0u: goto label_801914F0;
    case 0x801914F4u: goto label_801914F4;
    case 0x801914F8u: goto label_801914F8;
    case 0x801914FCu: goto label_801914FC;
    case 0x80191500u: goto label_80191500;
    case 0x80191504u: goto label_80191504;
    case 0x80191508u: goto label_80191508;
    case 0x8019150Cu: goto label_8019150C;
    case 0x80191510u: goto label_80191510;
    case 0x80191514u: goto label_80191514;
    case 0x80191518u: goto label_80191518;
    case 0x8019151Cu: goto label_8019151C;
    case 0x80191520u: goto label_80191520;
    case 0x80191524u: goto label_80191524;
    case 0x80191528u: goto label_80191528;
    case 0x8019152Cu: goto label_8019152C;
    case 0x80191530u: goto label_80191530;
    case 0x80191534u: goto label_80191534;
    case 0x80191538u: goto label_80191538;
    case 0x8019153Cu: goto label_8019153C;
    case 0x80191540u: goto label_80191540;
    case 0x80191544u: goto label_80191544;
    case 0x80191548u: goto label_80191548;
    case 0x8019154Cu: goto label_8019154C;
    case 0x80191550u: goto label_80191550;
    case 0x80191554u: goto label_80191554;
    case 0x80191558u: goto label_80191558;
    case 0x8019155Cu: goto label_8019155C;
    case 0x80191560u: goto label_80191560;
    case 0x80191564u: goto label_80191564;
    case 0x80191568u: goto label_80191568;
    case 0x8019156Cu: goto label_8019156C;
    case 0x80191570u: goto label_80191570;
    case 0x80191574u: goto label_80191574;
    case 0x80191578u: goto label_80191578;
    case 0x8019157Cu: goto label_8019157C;
    case 0x80191580u: goto label_80191580;
    case 0x80191584u: goto label_80191584;
    case 0x80191588u: goto label_80191588;
    case 0x8019158Cu: goto label_8019158C;
    case 0x80191590u: goto label_80191590;
    case 0x80191594u: goto label_80191594;
    case 0x80191598u: goto label_80191598;
    case 0x8019159Cu: goto label_8019159C;
    case 0x801915A0u: goto label_801915A0;
    case 0x801915A4u: goto label_801915A4;
    case 0x801915A8u: goto label_801915A8;
    case 0x801915ACu: goto label_801915AC;
    case 0x801915B0u: goto label_801915B0;
    case 0x801915B4u: goto label_801915B4;
    case 0x801915B8u: goto label_801915B8;
    case 0x801915BCu: goto label_801915BC;
    case 0x801915C0u: goto label_801915C0;
    case 0x801915C4u: goto label_801915C4;
    case 0x801915C8u: goto label_801915C8;
    case 0x801915CCu: goto label_801915CC;
    case 0x801915D0u: goto label_801915D0;
    case 0x801915D4u: goto label_801915D4;
    case 0x801915D8u: goto label_801915D8;
    case 0x801915DCu: goto label_801915DC;
    case 0x801915E0u: goto label_801915E0;
    case 0x801915E4u: goto label_801915E4;
    case 0x801915E8u: goto label_801915E8;
    case 0x801915ECu: goto label_801915EC;
    case 0x801915F0u: goto label_801915F0;
    case 0x801915F4u: goto label_801915F4;
    case 0x801915F8u: goto label_801915F8;
    case 0x801915FCu: goto label_801915FC;
    case 0x80191600u: goto label_80191600;
    case 0x80191604u: goto label_80191604;
    case 0x80191608u: goto label_80191608;
    case 0x8019160Cu: goto label_8019160C;
    case 0x80191610u: goto label_80191610;
    case 0x80191614u: goto label_80191614;
    case 0x80191618u: goto label_80191618;
    case 0x8019161Cu: goto label_8019161C;
    case 0x80191620u: goto label_80191620;
    case 0x80191624u: goto label_80191624;
    case 0x80191628u: goto label_80191628;
    case 0x8019162Cu: goto label_8019162C;
    case 0x80191630u: goto label_80191630;
    case 0x80191634u: goto label_80191634;
    case 0x80191638u: goto label_80191638;
    case 0x8019163Cu: goto label_8019163C;
    case 0x80191640u: goto label_80191640;
    case 0x80191644u: goto label_80191644;
    case 0x80191648u: goto label_80191648;
    case 0x8019164Cu: goto label_8019164C;
    case 0x80191650u: goto label_80191650;
    case 0x80191654u: goto label_80191654;
    case 0x80191658u: goto label_80191658;
    case 0x8019165Cu: goto label_8019165C;
    case 0x80191660u: goto label_80191660;
    case 0x80191664u: goto label_80191664;
    case 0x80191668u: goto label_80191668;
    case 0x8019166Cu: goto label_8019166C;
    case 0x80191670u: goto label_80191670;
    case 0x80191674u: goto label_80191674;
    case 0x80191678u: goto label_80191678;
    case 0x8019167Cu: goto label_8019167C;
    case 0x80191680u: goto label_80191680;
    case 0x80191684u: goto label_80191684;
    case 0x80191688u: goto label_80191688;
    case 0x8019168Cu: goto label_8019168C;
    case 0x80191690u: goto label_80191690;
    case 0x80191694u: goto label_80191694;
    case 0x80191698u: goto label_80191698;
    case 0x8019169Cu: goto label_8019169C;
    case 0x801916A0u: goto label_801916A0;
    case 0x801916A4u: goto label_801916A4;
    case 0x801916A8u: goto label_801916A8;
    case 0x801916ACu: goto label_801916AC;
    case 0x801916B0u: goto label_801916B0;
    case 0x801916B4u: goto label_801916B4;
    case 0x801916B8u: goto label_801916B8;
    case 0x801916BCu: goto label_801916BC;
    case 0x801916C0u: goto label_801916C0;
    case 0x801916C4u: goto label_801916C4;
    case 0x801916C8u: goto label_801916C8;
    case 0x801916CCu: goto label_801916CC;
    case 0x801916D0u: goto label_801916D0;
    case 0x801916D4u: goto label_801916D4;
    case 0x801916D8u: goto label_801916D8;
    case 0x801916DCu: goto label_801916DC;
    case 0x801916E0u: goto label_801916E0;
    case 0x801916E4u: goto label_801916E4;
    case 0x801916E8u: goto label_801916E8;
    case 0x801916ECu: goto label_801916EC;
    case 0x801916F0u: goto label_801916F0;
    case 0x801916F4u: goto label_801916F4;
    case 0x801916F8u: goto label_801916F8;
    case 0x801916FCu: goto label_801916FC;
    case 0x80191700u: goto label_80191700;
    case 0x80191704u: goto label_80191704;
    case 0x80191708u: goto label_80191708;
    case 0x8019170Cu: goto label_8019170C;
    case 0x80191710u: goto label_80191710;
    case 0x80191714u: goto label_80191714;
    case 0x80191718u: goto label_80191718;
    case 0x8019171Cu: goto label_8019171C;
    case 0x80191720u: goto label_80191720;
    case 0x80191724u: goto label_80191724;
    case 0x80191728u: goto label_80191728;
    case 0x8019172Cu: goto label_8019172C;
    case 0x80191730u: goto label_80191730;
    case 0x80191734u: goto label_80191734;
    case 0x80191738u: goto label_80191738;
    case 0x8019173Cu: goto label_8019173C;
    case 0x80191740u: goto label_80191740;
    case 0x80191744u: goto label_80191744;
    case 0x80191748u: goto label_80191748;
    case 0x8019174Cu: goto label_8019174C;
    case 0x80191750u: goto label_80191750;
    case 0x80191754u: goto label_80191754;
    case 0x80191758u: goto label_80191758;
    case 0x8019175Cu: goto label_8019175C;
    case 0x80191760u: goto label_80191760;
    case 0x80191764u: goto label_80191764;
    case 0x80191768u: goto label_80191768;
    case 0x8019176Cu: goto label_8019176C;
    case 0x80191770u: goto label_80191770;
    case 0x80191774u: goto label_80191774;
    case 0x80191778u: goto label_80191778;
    case 0x8019177Cu: goto label_8019177C;
    case 0x80191780u: goto label_80191780;
    case 0x80191784u: goto label_80191784;
    case 0x80191788u: goto label_80191788;
    case 0x8019178Cu: goto label_8019178C;
    case 0x80191790u: goto label_80191790;
    case 0x80191794u: goto label_80191794;
    case 0x80191798u: goto label_80191798;
    case 0x8019179Cu: goto label_8019179C;
    case 0x801917A0u: goto label_801917A0;
    case 0x801917A4u: goto label_801917A4;
    case 0x801917A8u: goto label_801917A8;
    case 0x801917ACu: goto label_801917AC;
    case 0x801917B0u: goto label_801917B0;
    case 0x801917B4u: goto label_801917B4;
    case 0x801917B8u: goto label_801917B8;
    case 0x801917BCu: goto label_801917BC;
    case 0x801917C0u: goto label_801917C0;
    case 0x801917C4u: goto label_801917C4;
    case 0x801917C8u: goto label_801917C8;
    case 0x801917CCu: goto label_801917CC;
    case 0x801917D0u: goto label_801917D0;
    case 0x801917D4u: goto label_801917D4;
    case 0x801917D8u: goto label_801917D8;
    case 0x801917DCu: goto label_801917DC;
    case 0x801917E0u: goto label_801917E0;
    case 0x801917E4u: goto label_801917E4;
    case 0x801917E8u: goto label_801917E8;
    case 0x801917ECu: goto label_801917EC;
    case 0x801917F0u: goto label_801917F0;
    case 0x801917F4u: goto label_801917F4;
    case 0x801917F8u: goto label_801917F8;
    case 0x801917FCu: goto label_801917FC;
    case 0x80191800u: goto label_80191800;
    case 0x80191804u: goto label_80191804;
    case 0x80191808u: goto label_80191808;
    case 0x8019180Cu: goto label_8019180C;
    case 0x80191810u: goto label_80191810;
    case 0x80191814u: goto label_80191814;
    case 0x80191818u: goto label_80191818;
    case 0x8019181Cu: goto label_8019181C;
    case 0x80191820u: goto label_80191820;
    case 0x80191824u: goto label_80191824;
    case 0x80191828u: goto label_80191828;
    case 0x8019182Cu: goto label_8019182C;
    case 0x80191830u: goto label_80191830;
    case 0x80191834u: goto label_80191834;
    case 0x80191838u: goto label_80191838;
    case 0x8019183Cu: goto label_8019183C;
    case 0x80191840u: goto label_80191840;
    case 0x80191844u: goto label_80191844;
    case 0x80191848u: goto label_80191848;
    case 0x8019184Cu: goto label_8019184C;
    case 0x80191850u: goto label_80191850;
    case 0x80191854u: goto label_80191854;
    case 0x80191858u: goto label_80191858;
    case 0x8019185Cu: goto label_8019185C;
    case 0x80191860u: goto label_80191860;
    case 0x80191864u: goto label_80191864;
    case 0x80191868u: goto label_80191868;
    case 0x8019186Cu: goto label_8019186C;
    case 0x80191870u: goto label_80191870;
    case 0x80191874u: goto label_80191874;
    case 0x80191878u: goto label_80191878;
    case 0x8019187Cu: goto label_8019187C;
    case 0x80191880u: goto label_80191880;
    case 0x80191884u: goto label_80191884;
    case 0x80191888u: goto label_80191888;
    case 0x8019188Cu: goto label_8019188C;
    case 0x80191890u: goto label_80191890;
    case 0x80191894u: goto label_80191894;
    case 0x80191898u: goto label_80191898;
    case 0x8019189Cu: goto label_8019189C;
    case 0x801918A0u: goto label_801918A0;
    case 0x801918A4u: goto label_801918A4;
    case 0x801918A8u: goto label_801918A8;
    case 0x801918ACu: goto label_801918AC;
    case 0x801918B0u: goto label_801918B0;
    case 0x801918B4u: goto label_801918B4;
    case 0x801918B8u: goto label_801918B8;
    case 0x801918BCu: goto label_801918BC;
    case 0x801918C0u: goto label_801918C0;
    case 0x801918C4u: goto label_801918C4;
    case 0x801918C8u: goto label_801918C8;
    case 0x801918CCu: goto label_801918CC;
    case 0x801918D0u: goto label_801918D0;
    case 0x801918D4u: goto label_801918D4;
    case 0x801918D8u: goto label_801918D8;
    case 0x801918DCu: goto label_801918DC;
    case 0x801918E0u: goto label_801918E0;
    case 0x801918E4u: goto label_801918E4;
    case 0x801918E8u: goto label_801918E8;
    case 0x801918ECu: goto label_801918EC;
    case 0x801918F0u: goto label_801918F0;
    case 0x801918F4u: goto label_801918F4;
    case 0x801918F8u: goto label_801918F8;
    case 0x801918FCu: goto label_801918FC;
    case 0x80191900u: goto label_80191900;
    case 0x80191904u: goto label_80191904;
    case 0x80191908u: goto label_80191908;
    case 0x8019190Cu: goto label_8019190C;
    case 0x80191910u: goto label_80191910;
    case 0x80191914u: goto label_80191914;
    case 0x80191918u: goto label_80191918;
    case 0x8019191Cu: goto label_8019191C;
    case 0x80191920u: goto label_80191920;
    case 0x80191924u: goto label_80191924;
    case 0x80191928u: goto label_80191928;
    case 0x8019192Cu: goto label_8019192C;
    case 0x80191930u: goto label_80191930;
    case 0x80191934u: goto label_80191934;
    case 0x80191938u: goto label_80191938;
    case 0x8019193Cu: goto label_8019193C;
    case 0x80191940u: goto label_80191940;
    case 0x80191944u: goto label_80191944;
    case 0x80191948u: goto label_80191948;
    case 0x8019194Cu: goto label_8019194C;
    case 0x80191950u: goto label_80191950;
    case 0x80191954u: goto label_80191954;
    case 0x80191958u: goto label_80191958;
    case 0x8019195Cu: goto label_8019195C;
    case 0x80191960u: goto label_80191960;
    case 0x80191964u: goto label_80191964;
    case 0x80191968u: goto label_80191968;
    case 0x8019196Cu: goto label_8019196C;
    case 0x80191970u: goto label_80191970;
    case 0x80191974u: goto label_80191974;
    case 0x80191978u: goto label_80191978;
    case 0x8019197Cu: goto label_8019197C;
    case 0x80191980u: goto label_80191980;
    case 0x80191984u: goto label_80191984;
    case 0x80191988u: goto label_80191988;
    case 0x8019198Cu: goto label_8019198C;
    case 0x80191990u: goto label_80191990;
    case 0x80191994u: goto label_80191994;
    case 0x80191998u: goto label_80191998;
    case 0x8019199Cu: goto label_8019199C;
    case 0x801919A0u: goto label_801919A0;
    case 0x801919A4u: goto label_801919A4;
    case 0x801919A8u: goto label_801919A8;
    case 0x801919ACu: goto label_801919AC;
    case 0x801919B0u: goto label_801919B0;
    case 0x801919B4u: goto label_801919B4;
    case 0x801919B8u: goto label_801919B8;
    case 0x801919BCu: goto label_801919BC;
    case 0x801919C0u: goto label_801919C0;
    case 0x801919C4u: goto label_801919C4;
    case 0x801919C8u: goto label_801919C8;
    case 0x801919CCu: goto label_801919CC;
    case 0x801919D0u: goto label_801919D0;
    case 0x801919D4u: goto label_801919D4;
    case 0x801919D8u: goto label_801919D8;
    case 0x801919DCu: goto label_801919DC;
    case 0x801919E0u: goto label_801919E0;
    case 0x801919E4u: goto label_801919E4;
    case 0x801919E8u: goto label_801919E8;
    case 0x801919ECu: goto label_801919EC;
    case 0x801919F0u: goto label_801919F0;
    case 0x801919F4u: goto label_801919F4;
    case 0x801919F8u: goto label_801919F8;
    case 0x801919FCu: goto label_801919FC;
    case 0x80191A00u: goto label_80191A00;
    case 0x80191A04u: goto label_80191A04;
    case 0x80191A08u: goto label_80191A08;
    case 0x80191A0Cu: goto label_80191A0C;
    case 0x80191A10u: goto label_80191A10;
    case 0x80191A14u: goto label_80191A14;
    case 0x80191A18u: goto label_80191A18;
    case 0x80191A1Cu: goto label_80191A1C;
    case 0x80191A20u: goto label_80191A20;
    case 0x80191A24u: goto label_80191A24;
    case 0x80191A28u: goto label_80191A28;
    case 0x80191A2Cu: goto label_80191A2C;
    case 0x80191A30u: goto label_80191A30;
    case 0x80191A34u: goto label_80191A34;
    case 0x80191A38u: goto label_80191A38;
    case 0x80191A3Cu: goto label_80191A3C;
    case 0x80191A40u: goto label_80191A40;
    case 0x80191A44u: goto label_80191A44;
    case 0x80191A48u: goto label_80191A48;
    case 0x80191A4Cu: goto label_80191A4C;
    case 0x80191A50u: goto label_80191A50;
    case 0x80191A54u: goto label_80191A54;
    case 0x80191A58u: goto label_80191A58;
    case 0x80191A5Cu: goto label_80191A5C;
    case 0x80191A60u: goto label_80191A60;
    case 0x80191A64u: goto label_80191A64;
    case 0x80191A68u: goto label_80191A68;
    case 0x80191A6Cu: goto label_80191A6C;
    case 0x80191A70u: goto label_80191A70;
    case 0x80191A74u: goto label_80191A74;
    case 0x80191A78u: goto label_80191A78;
    case 0x80191A7Cu: goto label_80191A7C;
    case 0x80191A80u: goto label_80191A80;
    case 0x80191A84u: goto label_80191A84;
    case 0x80191A88u: goto label_80191A88;
    case 0x80191A8Cu: goto label_80191A8C;
    case 0x80191A90u: goto label_80191A90;
    case 0x80191A94u: goto label_80191A94;
    case 0x80191A98u: goto label_80191A98;
    case 0x80191A9Cu: goto label_80191A9C;
    case 0x80191AA0u: goto label_80191AA0;
    case 0x80191AA4u: goto label_80191AA4;
    case 0x80191AA8u: goto label_80191AA8;
    case 0x80191AACu: goto label_80191AAC;
    case 0x80191AB0u: goto label_80191AB0;
    case 0x80191AB4u: goto label_80191AB4;
    case 0x80191AB8u: goto label_80191AB8;
    case 0x80191ABCu: goto label_80191ABC;
    case 0x80191AC0u: goto label_80191AC0;
    case 0x80191AC4u: goto label_80191AC4;
    case 0x80191AC8u: goto label_80191AC8;
    case 0x80191ACCu: goto label_80191ACC;
    case 0x80191AD0u: goto label_80191AD0;
    case 0x80191AD4u: goto label_80191AD4;
    case 0x80191AD8u: goto label_80191AD8;
    case 0x80191ADCu: goto label_80191ADC;
    case 0x80191AE0u: goto label_80191AE0;
    case 0x80191AE4u: goto label_80191AE4;
    case 0x80191AE8u: goto label_80191AE8;
    case 0x80191AECu: goto label_80191AEC;
    case 0x80191AF0u: goto label_80191AF0;
    case 0x80191AF4u: goto label_80191AF4;
    case 0x80191AF8u: goto label_80191AF8;
    case 0x80191AFCu: goto label_80191AFC;
    case 0x80191B00u: goto label_80191B00;
    case 0x80191B04u: goto label_80191B04;
    case 0x80191B08u: goto label_80191B08;
    case 0x80191B0Cu: goto label_80191B0C;
    case 0x80191B10u: goto label_80191B10;
    case 0x80191B14u: goto label_80191B14;
    case 0x80191B18u: goto label_80191B18;
    case 0x80191B1Cu: goto label_80191B1C;
    case 0x80191B20u: goto label_80191B20;
    case 0x80191B24u: goto label_80191B24;
    case 0x80191B28u: goto label_80191B28;
    case 0x80191B2Cu: goto label_80191B2C;
    case 0x80191B30u: goto label_80191B30;
    case 0x80191B34u: goto label_80191B34;
    case 0x80191B38u: goto label_80191B38;
    case 0x80191B3Cu: goto label_80191B3C;
    case 0x80191B40u: goto label_80191B40;
    case 0x80191B44u: goto label_80191B44;
    case 0x80191B48u: goto label_80191B48;
    case 0x80191B4Cu: goto label_80191B4C;
    case 0x80191B50u: goto label_80191B50;
    case 0x80191B54u: goto label_80191B54;
    case 0x80191B58u: goto label_80191B58;
    case 0x80191B5Cu: goto label_80191B5C;
    case 0x80191B60u: goto label_80191B60;
    case 0x80191B64u: goto label_80191B64;
    case 0x80191B68u: goto label_80191B68;
    case 0x80191B6Cu: goto label_80191B6C;
    case 0x80191B70u: goto label_80191B70;
    case 0x80191B74u: goto label_80191B74;
    case 0x80191B78u: goto label_80191B78;
    case 0x80191B7Cu: goto label_80191B7C;
    case 0x80191B80u: goto label_80191B80;
    case 0x80191B84u: goto label_80191B84;
    case 0x80191B88u: goto label_80191B88;
    case 0x80191B8Cu: goto label_80191B8C;
    case 0x80191B90u: goto label_80191B90;
    case 0x80191B94u: goto label_80191B94;
    case 0x80191B98u: goto label_80191B98;
    case 0x80191B9Cu: goto label_80191B9C;
    case 0x80191BA0u: goto label_80191BA0;
    case 0x80191BA4u: goto label_80191BA4;
    case 0x80191BA8u: goto label_80191BA8;
    case 0x80191BACu: goto label_80191BAC;
    case 0x80191BB0u: goto label_80191BB0;
    case 0x80191BB4u: goto label_80191BB4;
    case 0x80191BB8u: goto label_80191BB8;
    case 0x80191BBCu: goto label_80191BBC;
    case 0x80191BC0u: goto label_80191BC0;
    case 0x80191BC4u: goto label_80191BC4;
    case 0x80191BC8u: goto label_80191BC8;
    case 0x80191BCCu: goto label_80191BCC;
    case 0x80191BD0u: goto label_80191BD0;
    case 0x80191BD4u: goto label_80191BD4;
    case 0x80191BD8u: goto label_80191BD8;
    case 0x80191BDCu: goto label_80191BDC;
    case 0x80191BE0u: goto label_80191BE0;
    case 0x80191BE4u: goto label_80191BE4;
    case 0x80191BE8u: goto label_80191BE8;
    case 0x80191BECu: goto label_80191BEC;
    case 0x80191BF0u: goto label_80191BF0;
    case 0x80191BF4u: goto label_80191BF4;
    case 0x80191BF8u: goto label_80191BF8;
    case 0x80191BFCu: goto label_80191BFC;
    case 0x80191C00u: goto label_80191C00;
    case 0x80191C04u: goto label_80191C04;
    case 0x80191C08u: goto label_80191C08;
    case 0x80191C0Cu: goto label_80191C0C;
    case 0x80191C10u: goto label_80191C10;
    case 0x80191C14u: goto label_80191C14;
    case 0x80191C18u: goto label_80191C18;
    case 0x80191C1Cu: goto label_80191C1C;
    case 0x80191C20u: goto label_80191C20;
    case 0x80191C24u: goto label_80191C24;
    case 0x80191C28u: goto label_80191C28;
    case 0x80191C2Cu: goto label_80191C2C;
    case 0x80191C30u: goto label_80191C30;
    case 0x80191C34u: goto label_80191C34;
    case 0x80191C38u: goto label_80191C38;
    case 0x80191C3Cu: goto label_80191C3C;
    case 0x80191C40u: goto label_80191C40;
    case 0x80191C44u: goto label_80191C44;
    case 0x80191C48u: goto label_80191C48;
    case 0x80191C4Cu: goto label_80191C4C;
    case 0x80191C50u: goto label_80191C50;
    case 0x80191C54u: goto label_80191C54;
    case 0x80191C58u: goto label_80191C58;
    case 0x80191C5Cu: goto label_80191C5C;
    case 0x80191C60u: goto label_80191C60;
    case 0x80191C64u: goto label_80191C64;
    case 0x80191C68u: goto label_80191C68;
    case 0x80191C6Cu: goto label_80191C6C;
    case 0x80191C70u: goto label_80191C70;
    case 0x80191C74u: goto label_80191C74;
    case 0x80191C78u: goto label_80191C78;
    case 0x80191C7Cu: goto label_80191C7C;
    case 0x80191C80u: goto label_80191C80;
    case 0x80191C84u: goto label_80191C84;
    case 0x80191C88u: goto label_80191C88;
    case 0x80191C8Cu: goto label_80191C8C;
    case 0x80191C90u: goto label_80191C90;
    case 0x80191C94u: goto label_80191C94;
    case 0x80191C98u: goto label_80191C98;
    case 0x80191C9Cu: goto label_80191C9C;
    case 0x80191CA0u: goto label_80191CA0;
    case 0x80191CA4u: goto label_80191CA4;
    case 0x80191CA8u: goto label_80191CA8;
    case 0x80191CACu: goto label_80191CAC;
    case 0x80191CB0u: goto label_80191CB0;
    case 0x80191CB4u: goto label_80191CB4;
    case 0x80191CB8u: goto label_80191CB8;
    case 0x80191CBCu: goto label_80191CBC;
    case 0x80191CC0u: goto label_80191CC0;
    case 0x80191CC4u: goto label_80191CC4;
    case 0x80191CC8u: goto label_80191CC8;
    case 0x80191CCCu: goto label_80191CCC;
    case 0x80191CD0u: goto label_80191CD0;
    case 0x80191CD4u: goto label_80191CD4;
    case 0x80191CD8u: goto label_80191CD8;
    case 0x80191CDCu: goto label_80191CDC;
    case 0x80191CE0u: goto label_80191CE0;
    case 0x80191CE4u: goto label_80191CE4;
    case 0x80191CE8u: goto label_80191CE8;
    case 0x80191CECu: goto label_80191CEC;
    case 0x80191CF0u: goto label_80191CF0;
    case 0x80191CF4u: goto label_80191CF4;
    case 0x80191CF8u: goto label_80191CF8;
    case 0x80191CFCu: goto label_80191CFC;
    case 0x80191D00u: goto label_80191D00;
    case 0x80191D04u: goto label_80191D04;
    case 0x80191D08u: goto label_80191D08;
    case 0x80191D0Cu: goto label_80191D0C;
    case 0x80191D10u: goto label_80191D10;
    case 0x80191D14u: goto label_80191D14;
    case 0x80191D18u: goto label_80191D18;
    case 0x80191D1Cu: goto label_80191D1C;
    case 0x80191D20u: goto label_80191D20;
    case 0x80191D24u: goto label_80191D24;
    case 0x80191D28u: goto label_80191D28;
    case 0x80191D2Cu: goto label_80191D2C;
    case 0x80191D30u: goto label_80191D30;
    case 0x80191D34u: goto label_80191D34;
    case 0x80191D38u: goto label_80191D38;
    case 0x80191D3Cu: goto label_80191D3C;
    case 0x80191D40u: goto label_80191D40;
    case 0x80191D44u: goto label_80191D44;
    case 0x80191D48u: goto label_80191D48;
    case 0x80191D4Cu: goto label_80191D4C;
    case 0x80191D50u: goto label_80191D50;
    case 0x80191D54u: goto label_80191D54;
    case 0x80191D58u: goto label_80191D58;
    case 0x80191D5Cu: goto label_80191D5C;
    case 0x80191D60u: goto label_80191D60;
    case 0x80191D64u: goto label_80191D64;
    case 0x80191D68u: goto label_80191D68;
    case 0x80191D6Cu: goto label_80191D6C;
    case 0x80191D70u: goto label_80191D70;
    case 0x80191D74u: goto label_80191D74;
    case 0x80191D78u: goto label_80191D78;
    case 0x80191D7Cu: goto label_80191D7C;
    case 0x80191D80u: goto label_80191D80;
    case 0x80191D84u: goto label_80191D84;
    case 0x80191D88u: goto label_80191D88;
    case 0x80191D8Cu: goto label_80191D8C;
    case 0x80191D90u: goto label_80191D90;
    case 0x80191D94u: goto label_80191D94;
    case 0x80191D98u: goto label_80191D98;
    case 0x80191D9Cu: goto label_80191D9C;
    case 0x80191DA0u: goto label_80191DA0;
    case 0x80191DA4u: goto label_80191DA4;
    case 0x80191DA8u: goto label_80191DA8;
    case 0x80191DACu: goto label_80191DAC;
    case 0x80191DB0u: goto label_80191DB0;
    case 0x80191DB4u: goto label_80191DB4;
    case 0x80191DB8u: goto label_80191DB8;
    case 0x80191DBCu: goto label_80191DBC;
    case 0x80191DC0u: goto label_80191DC0;
    case 0x80191DC4u: goto label_80191DC4;
    case 0x80191DC8u: goto label_80191DC8;
    case 0x80191DCCu: goto label_80191DCC;
    case 0x80191DD0u: goto label_80191DD0;
    case 0x80191DD4u: goto label_80191DD4;
    case 0x80191DD8u: goto label_80191DD8;
    case 0x80191DDCu: goto label_80191DDC;
    case 0x80191DE0u: goto label_80191DE0;
    case 0x80191DE4u: goto label_80191DE4;
    case 0x80191DE8u: goto label_80191DE8;
    case 0x80191DECu: goto label_80191DEC;
    case 0x80191DF0u: goto label_80191DF0;
    case 0x80191DF4u: goto label_80191DF4;
    case 0x80191DF8u: goto label_80191DF8;
    case 0x80191DFCu: goto label_80191DFC;
    case 0x80191E00u: goto label_80191E00;
    case 0x80191E04u: goto label_80191E04;
    case 0x80191E08u: goto label_80191E08;
    case 0x80191E0Cu: goto label_80191E0C;
    case 0x80191E10u: goto label_80191E10;
    case 0x80191E14u: goto label_80191E14;
    case 0x80191E18u: goto label_80191E18;
    case 0x80191E1Cu: goto label_80191E1C;
    case 0x80191E20u: goto label_80191E20;
    case 0x80191E24u: goto label_80191E24;
    case 0x80191E28u: goto label_80191E28;
    case 0x80191E2Cu: goto label_80191E2C;
    case 0x80191E30u: goto label_80191E30;
    case 0x80191E34u: goto label_80191E34;
    case 0x80191E38u: goto label_80191E38;
    case 0x80191E3Cu: goto label_80191E3C;
    case 0x80191E40u: goto label_80191E40;
    case 0x80191E44u: goto label_80191E44;
    case 0x80191E48u: goto label_80191E48;
    case 0x80191E4Cu: goto label_80191E4C;
    case 0x80191E50u: goto label_80191E50;
    case 0x80191E54u: goto label_80191E54;
    case 0x80191E58u: goto label_80191E58;
    case 0x80191E5Cu: goto label_80191E5C;
    case 0x80191E60u: goto label_80191E60;
    case 0x80191E64u: goto label_80191E64;
    case 0x80191E68u: goto label_80191E68;
    case 0x80191E6Cu: goto label_80191E6C;
    case 0x80191E70u: goto label_80191E70;
    case 0x80191E74u: goto label_80191E74;
    case 0x80191E78u: goto label_80191E78;
    case 0x80191E7Cu: goto label_80191E7C;
    case 0x80191E80u: goto label_80191E80;
    case 0x80191E84u: goto label_80191E84;
    case 0x80191E88u: goto label_80191E88;
    case 0x80191E8Cu: goto label_80191E8C;
    case 0x80191E90u: goto label_80191E90;
    case 0x80191E94u: goto label_80191E94;
    case 0x80191E98u: goto label_80191E98;
    case 0x80191E9Cu: goto label_80191E9C;
    case 0x80191EA0u: goto label_80191EA0;
    case 0x80191EA4u: goto label_80191EA4;
    case 0x80191EA8u: goto label_80191EA8;
    case 0x80191EACu: goto label_80191EAC;
    case 0x80191EB0u: goto label_80191EB0;
    case 0x80191EB4u: goto label_80191EB4;
    case 0x80191EB8u: goto label_80191EB8;
    case 0x80191EBCu: goto label_80191EBC;
    case 0x80191EC0u: goto label_80191EC0;
    case 0x80191EC4u: goto label_80191EC4;
    case 0x80191EC8u: goto label_80191EC8;
    case 0x80191ECCu: goto label_80191ECC;
    case 0x80191ED0u: goto label_80191ED0;
    case 0x80191ED4u: goto label_80191ED4;
    case 0x80191ED8u: goto label_80191ED8;
    case 0x80191EDCu: goto label_80191EDC;
    case 0x80191EE0u: goto label_80191EE0;
    case 0x80191EE4u: goto label_80191EE4;
    case 0x80191EE8u: goto label_80191EE8;
    case 0x80191EECu: goto label_80191EEC;
    case 0x80191EF0u: goto label_80191EF0;
    case 0x80191EF4u: goto label_80191EF4;
    case 0x80191EF8u: goto label_80191EF8;
    case 0x80191EFCu: goto label_80191EFC;
    case 0x80191F00u: goto label_80191F00;
    case 0x80191F04u: goto label_80191F04;
    case 0x80191F08u: goto label_80191F08;
    case 0x80191F0Cu: goto label_80191F0C;
    case 0x80191F10u: goto label_80191F10;
    case 0x80191F14u: goto label_80191F14;
    case 0x80191F18u: goto label_80191F18;
    case 0x80191F1Cu: goto label_80191F1C;
    case 0x80191F20u: goto label_80191F20;
    case 0x80191F24u: goto label_80191F24;
    case 0x80191F28u: goto label_80191F28;
    case 0x80191F2Cu: goto label_80191F2C;
    case 0x80191F30u: goto label_80191F30;
    case 0x80191F34u: goto label_80191F34;
    case 0x80191F38u: goto label_80191F38;
    case 0x80191F3Cu: goto label_80191F3C;
    case 0x80191F40u: goto label_80191F40;
    case 0x80191F44u: goto label_80191F44;
    case 0x80191F48u: goto label_80191F48;
    case 0x80191F4Cu: goto label_80191F4C;
    case 0x80191F50u: goto label_80191F50;
    case 0x80191F54u: goto label_80191F54;
    case 0x80191F58u: goto label_80191F58;
    case 0x80191F5Cu: goto label_80191F5C;
    case 0x80191F60u: goto label_80191F60;
    case 0x80191F64u: goto label_80191F64;
    case 0x80191F68u: goto label_80191F68;
    case 0x80191F6Cu: goto label_80191F6C;
    case 0x80191F70u: goto label_80191F70;
    case 0x80191F74u: goto label_80191F74;
    case 0x80191F78u: goto label_80191F78;
    case 0x80191F7Cu: goto label_80191F7C;
    case 0x80191F80u: goto label_80191F80;
    case 0x80191F84u: goto label_80191F84;
    case 0x80191F88u: goto label_80191F88;
    case 0x80191F8Cu: goto label_80191F8C;
    case 0x80191F90u: goto label_80191F90;
    case 0x80191F94u: goto label_80191F94;
    case 0x80191F98u: goto label_80191F98;
    case 0x80191F9Cu: goto label_80191F9C;
    case 0x80191FA0u: goto label_80191FA0;
    case 0x80191FA4u: goto label_80191FA4;
    case 0x80191FA8u: goto label_80191FA8;
    case 0x80191FACu: goto label_80191FAC;
    case 0x80191FB0u: goto label_80191FB0;
    case 0x80191FB4u: goto label_80191FB4;
    case 0x80191FB8u: goto label_80191FB8;
    case 0x80191FBCu: goto label_80191FBC;
    case 0x80191FC0u: goto label_80191FC0;
    case 0x80191FC4u: goto label_80191FC4;
    case 0x80191FC8u: goto label_80191FC8;
    case 0x80191FCCu: goto label_80191FCC;
    case 0x80191FD0u: goto label_80191FD0;
    case 0x80191FD4u: goto label_80191FD4;
    case 0x80191FD8u: goto label_80191FD8;
    case 0x80191FDCu: goto label_80191FDC;
    case 0x80191FE0u: goto label_80191FE0;
    case 0x80191FE4u: goto label_80191FE4;
    case 0x80191FE8u: goto label_80191FE8;
    case 0x80191FECu: goto label_80191FEC;
    case 0x80191FF0u: goto label_80191FF0;
    case 0x80191FF4u: goto label_80191FF4;
    case 0x80191FF8u: goto label_80191FF8;
    case 0x80191FFCu: goto label_80191FFC;
    case 0x80192000u: goto label_80192000;
    case 0x80192004u: goto label_80192004;
    case 0x80192008u: goto label_80192008;
    case 0x8019200Cu: goto label_8019200C;
    case 0x80192010u: goto label_80192010;
    case 0x80192014u: goto label_80192014;
    case 0x80192018u: goto label_80192018;
    case 0x8019201Cu: goto label_8019201C;
    case 0x80192020u: goto label_80192020;
    case 0x80192024u: goto label_80192024;
    case 0x80192028u: goto label_80192028;
    case 0x8019202Cu: goto label_8019202C;
    case 0x80192030u: goto label_80192030;
    case 0x80192034u: goto label_80192034;
    case 0x80192038u: goto label_80192038;
    case 0x8019203Cu: goto label_8019203C;
    case 0x80192040u: goto label_80192040;
    case 0x80192044u: goto label_80192044;
    case 0x80192048u: goto label_80192048;
    case 0x8019204Cu: goto label_8019204C;
    case 0x80192050u: goto label_80192050;
    case 0x80192054u: goto label_80192054;
    case 0x80192058u: goto label_80192058;
    case 0x8019205Cu: goto label_8019205C;
    case 0x80192060u: goto label_80192060;
    case 0x80192064u: goto label_80192064;
    case 0x80192068u: goto label_80192068;
    case 0x8019206Cu: goto label_8019206C;
    case 0x80192070u: goto label_80192070;
    case 0x80192074u: goto label_80192074;
    case 0x80192078u: goto label_80192078;
    case 0x8019207Cu: goto label_8019207C;
    case 0x80192080u: goto label_80192080;
    case 0x80192084u: goto label_80192084;
    case 0x80192088u: goto label_80192088;
    case 0x8019208Cu: goto label_8019208C;
    case 0x80192090u: goto label_80192090;
    case 0x80192094u: goto label_80192094;
    case 0x80192098u: goto label_80192098;
    case 0x8019209Cu: goto label_8019209C;
    case 0x801920A0u: goto label_801920A0;
    case 0x801920A4u: goto label_801920A4;
    case 0x801920A8u: goto label_801920A8;
    case 0x801920ACu: goto label_801920AC;
    case 0x801920B0u: goto label_801920B0;
    case 0x801920B4u: goto label_801920B4;
    case 0x801920B8u: goto label_801920B8;
    case 0x801920BCu: goto label_801920BC;
    case 0x801920C0u: goto label_801920C0;
    case 0x801920C4u: goto label_801920C4;
    case 0x801920C8u: goto label_801920C8;
    case 0x801920CCu: goto label_801920CC;
    case 0x801920D0u: goto label_801920D0;
    case 0x801920D4u: goto label_801920D4;
    case 0x801920D8u: goto label_801920D8;
    case 0x801920DCu: goto label_801920DC;
    case 0x801920E0u: goto label_801920E0;
    case 0x801920E4u: goto label_801920E4;
    case 0x801920E8u: goto label_801920E8;
    case 0x801920ECu: goto label_801920EC;
    case 0x801920F0u: goto label_801920F0;
    case 0x801920F4u: goto label_801920F4;
    case 0x801920F8u: goto label_801920F8;
    case 0x801920FCu: goto label_801920FC;
    case 0x80192100u: goto label_80192100;
    case 0x80192104u: goto label_80192104;
    case 0x80192108u: goto label_80192108;
    case 0x8019210Cu: goto label_8019210C;
    case 0x80192110u: goto label_80192110;
    case 0x80192114u: goto label_80192114;
    case 0x80192118u: goto label_80192118;
    case 0x8019211Cu: goto label_8019211C;
    case 0x80192120u: goto label_80192120;
    case 0x80192124u: goto label_80192124;
    case 0x80192128u: goto label_80192128;
    case 0x8019212Cu: goto label_8019212C;
    case 0x80192130u: goto label_80192130;
    case 0x80192134u: goto label_80192134;
    case 0x80192138u: goto label_80192138;
    case 0x8019213Cu: goto label_8019213C;
    case 0x80192140u: goto label_80192140;
    case 0x80192144u: goto label_80192144;
    case 0x80192148u: goto label_80192148;
    case 0x8019214Cu: goto label_8019214C;
    case 0x80192150u: goto label_80192150;
    case 0x80192154u: goto label_80192154;
    case 0x80192158u: goto label_80192158;
    case 0x8019215Cu: goto label_8019215C;
    case 0x80192160u: goto label_80192160;
    case 0x80192164u: goto label_80192164;
    case 0x80192168u: goto label_80192168;
    case 0x8019216Cu: goto label_8019216C;
    case 0x80192170u: goto label_80192170;
    case 0x80192174u: goto label_80192174;
    case 0x80192178u: goto label_80192178;
    case 0x8019217Cu: goto label_8019217C;
    case 0x80192180u: goto label_80192180;
    case 0x80192184u: goto label_80192184;
    case 0x80192188u: goto label_80192188;
    case 0x8019218Cu: goto label_8019218C;
    case 0x80192190u: goto label_80192190;
    case 0x80192194u: goto label_80192194;
    case 0x80192198u: goto label_80192198;
    case 0x8019219Cu: goto label_8019219C;
    case 0x801921A0u: goto label_801921A0;
    case 0x801921A4u: goto label_801921A4;
    case 0x801921A8u: goto label_801921A8;
    case 0x801921ACu: goto label_801921AC;
    case 0x801921B0u: goto label_801921B0;
    case 0x801921B4u: goto label_801921B4;
    case 0x801921B8u: goto label_801921B8;
    case 0x801921BCu: goto label_801921BC;
    case 0x801921C0u: goto label_801921C0;
    case 0x801921C4u: goto label_801921C4;
    case 0x801921C8u: goto label_801921C8;
    case 0x801921CCu: goto label_801921CC;
    case 0x801921D0u: goto label_801921D0;
    case 0x801921D4u: goto label_801921D4;
    case 0x801921D8u: goto label_801921D8;
    case 0x801921DCu: goto label_801921DC;
    case 0x801921E0u: goto label_801921E0;
    case 0x801921E4u: goto label_801921E4;
    case 0x801921E8u: goto label_801921E8;
    case 0x801921ECu: goto label_801921EC;
    case 0x801921F0u: goto label_801921F0;
    case 0x801921F4u: goto label_801921F4;
    case 0x801921F8u: goto label_801921F8;
    case 0x801921FCu: goto label_801921FC;
    case 0x80192200u: goto label_80192200;
    case 0x80192204u: goto label_80192204;
    case 0x80192208u: goto label_80192208;
    case 0x8019220Cu: goto label_8019220C;
    case 0x80192210u: goto label_80192210;
    case 0x80192214u: goto label_80192214;
    case 0x80192218u: goto label_80192218;
    case 0x8019221Cu: goto label_8019221C;
    case 0x80192220u: goto label_80192220;
    case 0x80192224u: goto label_80192224;
    case 0x80192228u: goto label_80192228;
    case 0x8019222Cu: goto label_8019222C;
    case 0x80192230u: goto label_80192230;
    case 0x80192234u: goto label_80192234;
    case 0x80192238u: goto label_80192238;
    case 0x8019223Cu: goto label_8019223C;
    case 0x80192240u: goto label_80192240;
    case 0x80192244u: goto label_80192244;
    case 0x80192248u: goto label_80192248;
    case 0x8019224Cu: goto label_8019224C;
    case 0x80192250u: goto label_80192250;
    case 0x80192254u: goto label_80192254;
    case 0x80192258u: goto label_80192258;
    case 0x8019225Cu: goto label_8019225C;
    case 0x80192260u: goto label_80192260;
    case 0x80192264u: goto label_80192264;
    case 0x80192268u: goto label_80192268;
    case 0x8019226Cu: goto label_8019226C;
    case 0x80192270u: goto label_80192270;
    case 0x80192274u: goto label_80192274;
    case 0x80192278u: goto label_80192278;
    case 0x8019227Cu: goto label_8019227C;
    case 0x80192280u: goto label_80192280;
    case 0x80192284u: goto label_80192284;
    case 0x80192288u: goto label_80192288;
    case 0x8019228Cu: goto label_8019228C;
    case 0x80192290u: goto label_80192290;
    case 0x80192294u: goto label_80192294;
    case 0x80192298u: goto label_80192298;
    case 0x8019229Cu: goto label_8019229C;
    case 0x801922A0u: goto label_801922A0;
    case 0x801922A4u: goto label_801922A4;
    case 0x801922A8u: goto label_801922A8;
    case 0x801922ACu: goto label_801922AC;
    case 0x801922B0u: goto label_801922B0;
    case 0x801922B4u: goto label_801922B4;
    case 0x801922B8u: goto label_801922B8;
    case 0x801922BCu: goto label_801922BC;
    case 0x801922C0u: goto label_801922C0;
    case 0x801922C4u: goto label_801922C4;
    case 0x801922C8u: goto label_801922C8;
    case 0x801922CCu: goto label_801922CC;
    case 0x801922D0u: goto label_801922D0;
    case 0x801922D4u: goto label_801922D4;
    case 0x801922D8u: goto label_801922D8;
    case 0x801922DCu: goto label_801922DC;
    case 0x801922E0u: goto label_801922E0;
    case 0x801922E4u: goto label_801922E4;
    case 0x801922E8u: goto label_801922E8;
    case 0x801922ECu: goto label_801922EC;
    case 0x801922F0u: goto label_801922F0;
    case 0x801922F4u: goto label_801922F4;
    case 0x801922F8u: goto label_801922F8;
    case 0x801922FCu: goto label_801922FC;
    case 0x80192300u: goto label_80192300;
    case 0x80192304u: goto label_80192304;
    case 0x80192308u: goto label_80192308;
    case 0x8019230Cu: goto label_8019230C;
    case 0x80192310u: goto label_80192310;
    case 0x80192314u: goto label_80192314;
    case 0x80192318u: goto label_80192318;
    case 0x8019231Cu: goto label_8019231C;
    case 0x80192320u: goto label_80192320;
    case 0x80192324u: goto label_80192324;
    case 0x80192328u: goto label_80192328;
    case 0x8019232Cu: goto label_8019232C;
    case 0x80192330u: goto label_80192330;
    case 0x80192334u: goto label_80192334;
    case 0x80192338u: goto label_80192338;
    case 0x8019233Cu: goto label_8019233C;
    case 0x80192340u: goto label_80192340;
    case 0x80192344u: goto label_80192344;
    case 0x80192348u: goto label_80192348;
    case 0x8019234Cu: goto label_8019234C;
    case 0x80192350u: goto label_80192350;
    case 0x80192354u: goto label_80192354;
    case 0x80192358u: goto label_80192358;
    case 0x8019235Cu: goto label_8019235C;
    case 0x80192360u: goto label_80192360;
    case 0x80192364u: goto label_80192364;
    case 0x80192368u: goto label_80192368;
    case 0x8019236Cu: goto label_8019236C;
    case 0x80192370u: goto label_80192370;
    case 0x80192374u: goto label_80192374;
    case 0x80192378u: goto label_80192378;
    case 0x8019237Cu: goto label_8019237C;
    case 0x80192380u: goto label_80192380;
    case 0x80192384u: goto label_80192384;
    case 0x80192388u: goto label_80192388;
    case 0x8019238Cu: goto label_8019238C;
    case 0x80192390u: goto label_80192390;
    case 0x80192394u: goto label_80192394;
    case 0x80192398u: goto label_80192398;
    case 0x8019239Cu: goto label_8019239C;
    case 0x801923A0u: goto label_801923A0;
    case 0x801923A4u: goto label_801923A4;
    case 0x801923A8u: goto label_801923A8;
    case 0x801923ACu: goto label_801923AC;
    case 0x801923B0u: goto label_801923B0;
    case 0x801923B4u: goto label_801923B4;
    case 0x801923B8u: goto label_801923B8;
    case 0x801923BCu: goto label_801923BC;
    case 0x801923C0u: goto label_801923C0;
    case 0x801923C4u: goto label_801923C4;
    case 0x801923C8u: goto label_801923C8;
    case 0x801923CCu: goto label_801923CC;
    case 0x801923D0u: goto label_801923D0;
    case 0x801923D4u: goto label_801923D4;
    case 0x801923D8u: goto label_801923D8;
    case 0x801923DCu: goto label_801923DC;
    case 0x801923E0u: goto label_801923E0;
    case 0x801923E4u: goto label_801923E4;
    case 0x801923E8u: goto label_801923E8;
    case 0x801923ECu: goto label_801923EC;
    case 0x801923F0u: goto label_801923F0;
    case 0x801923F4u: goto label_801923F4;
    case 0x801923F8u: goto label_801923F8;
    case 0x801923FCu: goto label_801923FC;
    case 0x80192400u: goto label_80192400;
    case 0x80192404u: goto label_80192404;
    case 0x80192408u: goto label_80192408;
    case 0x8019240Cu: goto label_8019240C;
    case 0x80192410u: goto label_80192410;
    case 0x80192414u: goto label_80192414;
    case 0x80192418u: goto label_80192418;
    case 0x8019241Cu: goto label_8019241C;
    case 0x80192420u: goto label_80192420;
    case 0x80192424u: goto label_80192424;
    case 0x80192428u: goto label_80192428;
    case 0x8019242Cu: goto label_8019242C;
    case 0x80192430u: goto label_80192430;
    case 0x80192434u: goto label_80192434;
    case 0x80192438u: goto label_80192438;
    case 0x8019243Cu: goto label_8019243C;
    case 0x80192440u: goto label_80192440;
    case 0x80192444u: goto label_80192444;
    case 0x80192448u: goto label_80192448;
    case 0x8019244Cu: goto label_8019244C;
    case 0x80192450u: goto label_80192450;
    case 0x80192454u: goto label_80192454;
    case 0x80192458u: goto label_80192458;
    case 0x8019245Cu: goto label_8019245C;
    case 0x80192460u: goto label_80192460;
    case 0x80192464u: goto label_80192464;
    case 0x80192468u: goto label_80192468;
    case 0x8019246Cu: goto label_8019246C;
    case 0x80192470u: goto label_80192470;
    case 0x80192474u: goto label_80192474;
    case 0x80192478u: goto label_80192478;
    case 0x8019247Cu: goto label_8019247C;
    case 0x80192480u: goto label_80192480;
    case 0x80192484u: goto label_80192484;
    case 0x80192488u: goto label_80192488;
    case 0x8019248Cu: goto label_8019248C;
    case 0x80192490u: goto label_80192490;
    case 0x80192494u: goto label_80192494;
    case 0x80192498u: goto label_80192498;
    case 0x8019249Cu: goto label_8019249C;
    case 0x801924A0u: goto label_801924A0;
    case 0x801924A4u: goto label_801924A4;
    case 0x801924A8u: goto label_801924A8;
    case 0x801924ACu: goto label_801924AC;
    case 0x801924B0u: goto label_801924B0;
    case 0x801924B4u: goto label_801924B4;
    case 0x801924B8u: goto label_801924B8;
    case 0x801924BCu: goto label_801924BC;
    case 0x801924C0u: goto label_801924C0;
    case 0x801924C4u: goto label_801924C4;
    case 0x801924C8u: goto label_801924C8;
    case 0x801924CCu: goto label_801924CC;
    case 0x801924D0u: goto label_801924D0;
    case 0x801924D4u: goto label_801924D4;
    case 0x801924D8u: goto label_801924D8;
    case 0x801924DCu: goto label_801924DC;
    case 0x801924E0u: goto label_801924E0;
    case 0x801924E4u: goto label_801924E4;
    case 0x801924E8u: goto label_801924E8;
    case 0x801924ECu: goto label_801924EC;
    case 0x801924F0u: goto label_801924F0;
    case 0x801924F4u: goto label_801924F4;
    case 0x801924F8u: goto label_801924F8;
    case 0x801924FCu: goto label_801924FC;
    case 0x80192500u: goto label_80192500;
    case 0x80192504u: goto label_80192504;
    case 0x80192508u: goto label_80192508;
    case 0x8019250Cu: goto label_8019250C;
    case 0x80192510u: goto label_80192510;
    case 0x80192514u: goto label_80192514;
    case 0x80192518u: goto label_80192518;
    case 0x8019251Cu: goto label_8019251C;
    case 0x80192520u: goto label_80192520;
    case 0x80192524u: goto label_80192524;
    case 0x80192528u: goto label_80192528;
    case 0x8019252Cu: goto label_8019252C;
    case 0x80192530u: goto label_80192530;
    case 0x80192534u: goto label_80192534;
    case 0x80192538u: goto label_80192538;
    case 0x8019253Cu: goto label_8019253C;
    case 0x80192540u: goto label_80192540;
    case 0x80192544u: goto label_80192544;
    case 0x80192548u: goto label_80192548;
    case 0x8019254Cu: goto label_8019254C;
    case 0x80192550u: goto label_80192550;
    case 0x80192554u: goto label_80192554;
    case 0x80192558u: goto label_80192558;
    case 0x8019255Cu: goto label_8019255C;
    case 0x80192560u: goto label_80192560;
    case 0x80192564u: goto label_80192564;
    case 0x80192568u: goto label_80192568;
    case 0x8019256Cu: goto label_8019256C;
    case 0x80192570u: goto label_80192570;
    case 0x80192574u: goto label_80192574;
    case 0x80192578u: goto label_80192578;
    case 0x8019257Cu: goto label_8019257C;
    case 0x80192580u: goto label_80192580;
    case 0x80192584u: goto label_80192584;
    case 0x80192588u: goto label_80192588;
    case 0x8019258Cu: goto label_8019258C;
    case 0x80192590u: goto label_80192590;
    case 0x80192594u: goto label_80192594;
    case 0x80192598u: goto label_80192598;
    case 0x8019259Cu: goto label_8019259C;
    case 0x801925A0u: goto label_801925A0;
    case 0x801925A4u: goto label_801925A4;
    case 0x801925A8u: goto label_801925A8;
    case 0x801925ACu: goto label_801925AC;
    case 0x801925B0u: goto label_801925B0;
    case 0x801925B4u: goto label_801925B4;
    case 0x801925B8u: goto label_801925B8;
    case 0x801925BCu: goto label_801925BC;
    case 0x801925C0u: goto label_801925C0;
    case 0x801925C4u: goto label_801925C4;
    case 0x801925C8u: goto label_801925C8;
    case 0x801925CCu: goto label_801925CC;
    case 0x801925D0u: goto label_801925D0;
    case 0x801925D4u: goto label_801925D4;
    case 0x801925D8u: goto label_801925D8;
    case 0x801925DCu: goto label_801925DC;
    case 0x801925E0u: goto label_801925E0;
    case 0x801925E4u: goto label_801925E4;
    case 0x801925E8u: goto label_801925E8;
    case 0x801925ECu: goto label_801925EC;
    case 0x801925F0u: goto label_801925F0;
    case 0x801925F4u: goto label_801925F4;
    case 0x801925F8u: goto label_801925F8;
    case 0x801925FCu: goto label_801925FC;
    case 0x80192600u: goto label_80192600;
    case 0x80192604u: goto label_80192604;
    case 0x80192608u: goto label_80192608;
    case 0x8019260Cu: goto label_8019260C;
    case 0x80192610u: goto label_80192610;
    case 0x80192614u: goto label_80192614;
    case 0x80192618u: goto label_80192618;
    case 0x8019261Cu: goto label_8019261C;
    case 0x80192620u: goto label_80192620;
    case 0x80192624u: goto label_80192624;
    case 0x80192628u: goto label_80192628;
    case 0x8019262Cu: goto label_8019262C;
    case 0x80192630u: goto label_80192630;
    case 0x80192634u: goto label_80192634;
    case 0x80192638u: goto label_80192638;
    case 0x8019263Cu: goto label_8019263C;
    case 0x80192640u: goto label_80192640;
    case 0x80192644u: goto label_80192644;
    case 0x80192648u: goto label_80192648;
    case 0x8019264Cu: goto label_8019264C;
    case 0x80192650u: goto label_80192650;
    case 0x80192654u: goto label_80192654;
    case 0x80192658u: goto label_80192658;
    case 0x8019265Cu: goto label_8019265C;
    case 0x80192660u: goto label_80192660;
    case 0x80192664u: goto label_80192664;
    case 0x80192668u: goto label_80192668;
    case 0x8019266Cu: goto label_8019266C;
    case 0x80192670u: goto label_80192670;
    case 0x80192674u: goto label_80192674;
    case 0x80192678u: goto label_80192678;
    case 0x8019267Cu: goto label_8019267C;
    case 0x80192680u: goto label_80192680;
    case 0x80192684u: goto label_80192684;
    case 0x80192688u: goto label_80192688;
    case 0x8019268Cu: goto label_8019268C;
    case 0x80192690u: goto label_80192690;
    case 0x80192694u: goto label_80192694;
    case 0x80192698u: goto label_80192698;
    case 0x8019269Cu: goto label_8019269C;
    case 0x801926A0u: goto label_801926A0;
    case 0x801926A4u: goto label_801926A4;
    case 0x801926A8u: goto label_801926A8;
    case 0x801926ACu: goto label_801926AC;
    case 0x801926B0u: goto label_801926B0;
    case 0x801926B4u: goto label_801926B4;
    case 0x801926B8u: goto label_801926B8;
    case 0x801926BCu: goto label_801926BC;
    case 0x801926C0u: goto label_801926C0;
    case 0x801926C4u: goto label_801926C4;
    case 0x801926C8u: goto label_801926C8;
    case 0x801926CCu: goto label_801926CC;
    case 0x801926D0u: goto label_801926D0;
    case 0x801926D4u: goto label_801926D4;
    case 0x801926D8u: goto label_801926D8;
    case 0x801926DCu: goto label_801926DC;
    case 0x801926E0u: goto label_801926E0;
    case 0x801926E4u: goto label_801926E4;
    case 0x801926E8u: goto label_801926E8;
    case 0x801926ECu: goto label_801926EC;
    case 0x801926F0u: goto label_801926F0;
    case 0x801926F4u: goto label_801926F4;
    case 0x801926F8u: goto label_801926F8;
    case 0x801926FCu: goto label_801926FC;
    case 0x80192700u: goto label_80192700;
    case 0x80192704u: goto label_80192704;
    case 0x80192708u: goto label_80192708;
    case 0x8019270Cu: goto label_8019270C;
    case 0x80192710u: goto label_80192710;
    case 0x80192714u: goto label_80192714;
    case 0x80192718u: goto label_80192718;
    case 0x8019271Cu: goto label_8019271C;
    case 0x80192720u: goto label_80192720;
    case 0x80192724u: goto label_80192724;
    case 0x80192728u: goto label_80192728;
    case 0x8019272Cu: goto label_8019272C;
    case 0x80192730u: goto label_80192730;
    case 0x80192734u: goto label_80192734;
    case 0x80192738u: goto label_80192738;
    case 0x8019273Cu: goto label_8019273C;
    case 0x80192740u: goto label_80192740;
    case 0x80192744u: goto label_80192744;
    case 0x80192748u: goto label_80192748;
    case 0x8019274Cu: goto label_8019274C;
    case 0x80192750u: goto label_80192750;
    case 0x80192754u: goto label_80192754;
    case 0x80192758u: goto label_80192758;
    case 0x8019275Cu: goto label_8019275C;
    case 0x80192760u: goto label_80192760;
    case 0x80192764u: goto label_80192764;
    case 0x80192768u: goto label_80192768;
    case 0x8019276Cu: goto label_8019276C;
    case 0x80192770u: goto label_80192770;
    case 0x80192774u: goto label_80192774;
    case 0x80192778u: goto label_80192778;
    case 0x8019277Cu: goto label_8019277C;
    case 0x80192780u: goto label_80192780;
    case 0x80192784u: goto label_80192784;
    case 0x80192788u: goto label_80192788;
    case 0x8019278Cu: goto label_8019278C;
    case 0x80192790u: goto label_80192790;
    case 0x80192794u: goto label_80192794;
    case 0x80192798u: goto label_80192798;
    case 0x8019279Cu: goto label_8019279C;
    case 0x801927A0u: goto label_801927A0;
    case 0x801927A4u: goto label_801927A4;
    case 0x801927A8u: goto label_801927A8;
    case 0x801927ACu: goto label_801927AC;
    case 0x801927B0u: goto label_801927B0;
    case 0x801927B4u: goto label_801927B4;
    case 0x801927B8u: goto label_801927B8;
    case 0x801927BCu: goto label_801927BC;
    case 0x801927C0u: goto label_801927C0;
    case 0x801927C4u: goto label_801927C4;
    case 0x801927C8u: goto label_801927C8;
    case 0x801927CCu: goto label_801927CC;
    case 0x801927D0u: goto label_801927D0;
    case 0x801927D4u: goto label_801927D4;
    case 0x801927D8u: goto label_801927D8;
    case 0x801927DCu: goto label_801927DC;
    case 0x801927E0u: goto label_801927E0;
    case 0x801927E4u: goto label_801927E4;
    case 0x801927E8u: goto label_801927E8;
    case 0x801927ECu: goto label_801927EC;
    case 0x801927F0u: goto label_801927F0;
    case 0x801927F4u: goto label_801927F4;
    case 0x801927F8u: goto label_801927F8;
    case 0x801927FCu: goto label_801927FC;
    case 0x80192800u: goto label_80192800;
    case 0x80192804u: goto label_80192804;
    case 0x80192808u: goto label_80192808;
    case 0x8019280Cu: goto label_8019280C;
    case 0x80192810u: goto label_80192810;
    case 0x80192814u: goto label_80192814;
    case 0x80192818u: goto label_80192818;
    case 0x8019281Cu: goto label_8019281C;
    case 0x80192820u: goto label_80192820;
    case 0x80192824u: goto label_80192824;
    case 0x80192828u: goto label_80192828;
    case 0x8019282Cu: goto label_8019282C;
    case 0x80192830u: goto label_80192830;
    case 0x80192834u: goto label_80192834;
    case 0x80192838u: goto label_80192838;
    case 0x8019283Cu: goto label_8019283C;
    case 0x80192840u: goto label_80192840;
    case 0x80192844u: goto label_80192844;
    case 0x80192848u: goto label_80192848;
    case 0x8019284Cu: goto label_8019284C;
    case 0x80192850u: goto label_80192850;
    case 0x80192854u: goto label_80192854;
    case 0x80192858u: goto label_80192858;
    case 0x8019285Cu: goto label_8019285C;
    case 0x80192860u: goto label_80192860;
    case 0x80192864u: goto label_80192864;
    case 0x80192868u: goto label_80192868;
    case 0x8019286Cu: goto label_8019286C;
    case 0x80192870u: goto label_80192870;
    case 0x80192874u: goto label_80192874;
    case 0x80192878u: goto label_80192878;
    case 0x8019287Cu: goto label_8019287C;
    case 0x80192880u: goto label_80192880;
    case 0x80192884u: goto label_80192884;
    case 0x80192888u: goto label_80192888;
    case 0x8019288Cu: goto label_8019288C;
    case 0x80192890u: goto label_80192890;
    case 0x80192894u: goto label_80192894;
    case 0x80192898u: goto label_80192898;
    case 0x8019289Cu: goto label_8019289C;
    case 0x801928A0u: goto label_801928A0;
    case 0x801928A4u: goto label_801928A4;
    case 0x801928A8u: goto label_801928A8;
    case 0x801928ACu: goto label_801928AC;
    case 0x801928B0u: goto label_801928B0;
    case 0x801928B4u: goto label_801928B4;
    case 0x801928B8u: goto label_801928B8;
    case 0x801928BCu: goto label_801928BC;
    case 0x801928C0u: goto label_801928C0;
    case 0x801928C4u: goto label_801928C4;
    case 0x801928C8u: goto label_801928C8;
    case 0x801928CCu: goto label_801928CC;
    case 0x801928D0u: goto label_801928D0;
    case 0x801928D4u: goto label_801928D4;
    case 0x801928D8u: goto label_801928D8;
    case 0x801928DCu: goto label_801928DC;
    case 0x801928E0u: goto label_801928E0;
    case 0x801928E4u: goto label_801928E4;
    case 0x801928E8u: goto label_801928E8;
    case 0x801928ECu: goto label_801928EC;
    case 0x801928F0u: goto label_801928F0;
    case 0x801928F4u: goto label_801928F4;
    case 0x801928F8u: goto label_801928F8;
    case 0x801928FCu: goto label_801928FC;
    case 0x80192900u: goto label_80192900;
    case 0x80192904u: goto label_80192904;
    case 0x80192908u: goto label_80192908;
    case 0x8019290Cu: goto label_8019290C;
    case 0x80192910u: goto label_80192910;
    case 0x80192914u: goto label_80192914;
    case 0x80192918u: goto label_80192918;
    case 0x8019291Cu: goto label_8019291C;
    case 0x80192920u: goto label_80192920;
    case 0x80192924u: goto label_80192924;
    case 0x80192928u: goto label_80192928;
    case 0x8019292Cu: goto label_8019292C;
    case 0x80192930u: goto label_80192930;
    case 0x80192934u: goto label_80192934;
    case 0x80192938u: goto label_80192938;
    case 0x8019293Cu: goto label_8019293C;
    case 0x80192940u: goto label_80192940;
    case 0x80192944u: goto label_80192944;
    case 0x80192948u: goto label_80192948;
    case 0x8019294Cu: goto label_8019294C;
    case 0x80192950u: goto label_80192950;
    case 0x80192954u: goto label_80192954;
    case 0x80192958u: goto label_80192958;
    case 0x8019295Cu: goto label_8019295C;
    case 0x80192960u: goto label_80192960;
    case 0x80192964u: goto label_80192964;
    case 0x80192968u: goto label_80192968;
    case 0x8019296Cu: goto label_8019296C;
    case 0x80192970u: goto label_80192970;
    case 0x80192974u: goto label_80192974;
    case 0x80192978u: goto label_80192978;
    case 0x8019297Cu: goto label_8019297C;
    case 0x80192980u: goto label_80192980;
    case 0x80192984u: goto label_80192984;
    case 0x80192988u: goto label_80192988;
    case 0x8019298Cu: goto label_8019298C;
    case 0x80192990u: goto label_80192990;
    case 0x80192994u: goto label_80192994;
    case 0x80192998u: goto label_80192998;
    case 0x8019299Cu: goto label_8019299C;
    case 0x801929A0u: goto label_801929A0;
    case 0x801929A4u: goto label_801929A4;
    case 0x801929A8u: goto label_801929A8;
    case 0x801929ACu: goto label_801929AC;
    case 0x801929B0u: goto label_801929B0;
    case 0x801929B4u: goto label_801929B4;
    case 0x801929B8u: goto label_801929B8;
    case 0x801929BCu: goto label_801929BC;
    case 0x801929C0u: goto label_801929C0;
    case 0x801929C4u: goto label_801929C4;
    case 0x801929C8u: goto label_801929C8;
    case 0x801929CCu: goto label_801929CC;
    case 0x801929D0u: goto label_801929D0;
    case 0x801929D4u: goto label_801929D4;
    case 0x801929D8u: goto label_801929D8;
    case 0x801929DCu: goto label_801929DC;
    case 0x801929E0u: goto label_801929E0;
    case 0x801929E4u: goto label_801929E4;
    case 0x801929E8u: goto label_801929E8;
    case 0x801929ECu: goto label_801929EC;
    case 0x801929F0u: goto label_801929F0;
    case 0x801929F4u: goto label_801929F4;
    case 0x801929F8u: goto label_801929F8;
    case 0x801929FCu: goto label_801929FC;
    case 0x80192A00u: goto label_80192A00;
    case 0x80192A04u: goto label_80192A04;
    case 0x80192A08u: goto label_80192A08;
    case 0x80192A0Cu: goto label_80192A0C;
    case 0x80192A10u: goto label_80192A10;
    case 0x80192A14u: goto label_80192A14;
    case 0x80192A18u: goto label_80192A18;
    case 0x80192A1Cu: goto label_80192A1C;
    case 0x80192A20u: goto label_80192A20;
    case 0x80192A24u: goto label_80192A24;
    case 0x80192A28u: goto label_80192A28;
    case 0x80192A2Cu: goto label_80192A2C;
    case 0x80192A30u: goto label_80192A30;
    case 0x80192A34u: goto label_80192A34;
    case 0x80192A38u: goto label_80192A38;
    case 0x80192A3Cu: goto label_80192A3C;
    case 0x80192A40u: goto label_80192A40;
    case 0x80192A44u: goto label_80192A44;
    case 0x80192A48u: goto label_80192A48;
    case 0x80192A4Cu: goto label_80192A4C;
    case 0x80192A50u: goto label_80192A50;
    case 0x80192A54u: goto label_80192A54;
    case 0x80192A58u: goto label_80192A58;
    case 0x80192A5Cu: goto label_80192A5C;
    case 0x80192A60u: goto label_80192A60;
    case 0x80192A64u: goto label_80192A64;
    case 0x80192A68u: goto label_80192A68;
    case 0x80192A6Cu: goto label_80192A6C;
    case 0x80192A70u: goto label_80192A70;
    case 0x80192A74u: goto label_80192A74;
    case 0x80192A78u: goto label_80192A78;
    case 0x80192A7Cu: goto label_80192A7C;
    case 0x80192A80u: goto label_80192A80;
    case 0x80192A84u: goto label_80192A84;
    case 0x80192A88u: goto label_80192A88;
    case 0x80192A8Cu: goto label_80192A8C;
    case 0x80192A90u: goto label_80192A90;
    case 0x80192A94u: goto label_80192A94;
    case 0x80192A98u: goto label_80192A98;
    case 0x80192A9Cu: goto label_80192A9C;
    case 0x80192AA0u: goto label_80192AA0;
    case 0x80192AA4u: goto label_80192AA4;
    case 0x80192AA8u: goto label_80192AA8;
    case 0x80192AACu: goto label_80192AAC;
    case 0x80192AB0u: goto label_80192AB0;
    case 0x80192AB4u: goto label_80192AB4;
    case 0x80192AB8u: goto label_80192AB8;
    case 0x80192ABCu: goto label_80192ABC;
    case 0x80192AC0u: goto label_80192AC0;
    case 0x80192AC4u: goto label_80192AC4;
    case 0x80192AC8u: goto label_80192AC8;
    case 0x80192ACCu: goto label_80192ACC;
    case 0x80192AD0u: goto label_80192AD0;
    case 0x80192AD4u: goto label_80192AD4;
    case 0x80192AD8u: goto label_80192AD8;
    case 0x80192ADCu: goto label_80192ADC;
    case 0x80192AE0u: goto label_80192AE0;
    case 0x80192AE4u: goto label_80192AE4;
    case 0x80192AE8u: goto label_80192AE8;
    case 0x80192AECu: goto label_80192AEC;
    case 0x80192AF0u: goto label_80192AF0;
    case 0x80192AF4u: goto label_80192AF4;
    case 0x80192AF8u: goto label_80192AF8;
    case 0x80192AFCu: goto label_80192AFC;
    case 0x80192B00u: goto label_80192B00;
    case 0x80192B04u: goto label_80192B04;
    case 0x80192B08u: goto label_80192B08;
    case 0x80192B0Cu: goto label_80192B0C;
    case 0x80192B10u: goto label_80192B10;
    case 0x80192B14u: goto label_80192B14;
    case 0x80192B18u: goto label_80192B18;
    case 0x80192B1Cu: goto label_80192B1C;
    case 0x80192B20u: goto label_80192B20;
    case 0x80192B24u: goto label_80192B24;
    case 0x80192B28u: goto label_80192B28;
    case 0x80192B2Cu: goto label_80192B2C;
    case 0x80192B30u: goto label_80192B30;
    case 0x80192B34u: goto label_80192B34;
    case 0x80192B38u: goto label_80192B38;
    case 0x80192B3Cu: goto label_80192B3C;
    case 0x80192B40u: goto label_80192B40;
    case 0x80192B44u: goto label_80192B44;
    case 0x80192B48u: goto label_80192B48;
    case 0x80192B4Cu: goto label_80192B4C;
    case 0x80192B50u: goto label_80192B50;
    case 0x80192B54u: goto label_80192B54;
    case 0x80192B58u: goto label_80192B58;
    case 0x80192B5Cu: goto label_80192B5C;
    case 0x80192B60u: goto label_80192B60;
    case 0x80192B64u: goto label_80192B64;
    case 0x80192B68u: goto label_80192B68;
    case 0x80192B6Cu: goto label_80192B6C;
    case 0x80192B70u: goto label_80192B70;
    case 0x80192B74u: goto label_80192B74;
    case 0x80192B78u: goto label_80192B78;
    case 0x80192B7Cu: goto label_80192B7C;
    case 0x80192B80u: goto label_80192B80;
    case 0x80192B84u: goto label_80192B84;
    case 0x80192B88u: goto label_80192B88;
    case 0x80192B8Cu: goto label_80192B8C;
    case 0x80192B90u: goto label_80192B90;
    case 0x80192B94u: goto label_80192B94;
    case 0x80192B98u: goto label_80192B98;
    case 0x80192B9Cu: goto label_80192B9C;
    case 0x80192BA0u: goto label_80192BA0;
    case 0x80192BA4u: goto label_80192BA4;
    case 0x80192BA8u: goto label_80192BA8;
    case 0x80192BACu: goto label_80192BAC;
    case 0x80192BB0u: goto label_80192BB0;
    case 0x80192BB4u: goto label_80192BB4;
    case 0x80192BB8u: goto label_80192BB8;
    case 0x80192BBCu: goto label_80192BBC;
    case 0x80192BC0u: goto label_80192BC0;
    case 0x80192BC4u: goto label_80192BC4;
    case 0x80192BC8u: goto label_80192BC8;
    case 0x80192BCCu: goto label_80192BCC;
    case 0x80192BD0u: goto label_80192BD0;
    case 0x80192BD4u: goto label_80192BD4;
    case 0x80192BD8u: goto label_80192BD8;
    case 0x80192BDCu: goto label_80192BDC;
    case 0x80192BE0u: goto label_80192BE0;
    case 0x80192BE4u: goto label_80192BE4;
    case 0x80192BE8u: goto label_80192BE8;
    case 0x80192BECu: goto label_80192BEC;
    case 0x80192BF0u: goto label_80192BF0;
    case 0x80192BF4u: goto label_80192BF4;
    case 0x80192BF8u: goto label_80192BF8;
    case 0x80192BFCu: goto label_80192BFC;
    case 0x80192C00u: goto label_80192C00;
    case 0x80192C04u: goto label_80192C04;
    case 0x80192C08u: goto label_80192C08;
    case 0x80192C0Cu: goto label_80192C0C;
    case 0x80192C10u: goto label_80192C10;
    case 0x80192C14u: goto label_80192C14;
    case 0x80192C18u: goto label_80192C18;
    case 0x80192C1Cu: goto label_80192C1C;
    case 0x80192C20u: goto label_80192C20;
    case 0x80192C24u: goto label_80192C24;
    case 0x80192C28u: goto label_80192C28;
    case 0x80192C2Cu: goto label_80192C2C;
    case 0x80192C30u: goto label_80192C30;
    case 0x80192C34u: goto label_80192C34;
    case 0x80192C38u: goto label_80192C38;
    case 0x80192C3Cu: goto label_80192C3C;
    case 0x80192C40u: goto label_80192C40;
    case 0x80192C44u: goto label_80192C44;
    case 0x80192C48u: goto label_80192C48;
    case 0x80192C4Cu: goto label_80192C4C;
    case 0x80192C50u: goto label_80192C50;
    case 0x80192C54u: goto label_80192C54;
    case 0x80192C58u: goto label_80192C58;
    case 0x80192C5Cu: goto label_80192C5C;
    case 0x80192C60u: goto label_80192C60;
    case 0x80192C64u: goto label_80192C64;
    case 0x80192C68u: goto label_80192C68;
    case 0x80192C6Cu: goto label_80192C6C;
    case 0x80192C70u: goto label_80192C70;
    case 0x80192C74u: goto label_80192C74;
    case 0x80192C78u: goto label_80192C78;
    case 0x80192C7Cu: goto label_80192C7C;
    case 0x80192C80u: goto label_80192C80;
    case 0x80192C84u: goto label_80192C84;
    case 0x80192C88u: goto label_80192C88;
    case 0x80192C8Cu: goto label_80192C8C;
    case 0x80192C90u: goto label_80192C90;
    case 0x80192C94u: goto label_80192C94;
    case 0x80192C98u: goto label_80192C98;
    case 0x80192C9Cu: goto label_80192C9C;
    case 0x80192CA0u: goto label_80192CA0;
    case 0x80192CA4u: goto label_80192CA4;
    case 0x80192CA8u: goto label_80192CA8;
    case 0x80192CACu: goto label_80192CAC;
    case 0x80192CB0u: goto label_80192CB0;
    case 0x80192CB4u: goto label_80192CB4;
    case 0x80192CB8u: goto label_80192CB8;
    case 0x80192CBCu: goto label_80192CBC;
    case 0x80192CC0u: goto label_80192CC0;
    case 0x80192CC4u: goto label_80192CC4;
    case 0x80192CC8u: goto label_80192CC8;
    case 0x80192CCCu: goto label_80192CCC;
    case 0x80192CD0u: goto label_80192CD0;
    case 0x80192CD4u: goto label_80192CD4;
    case 0x80192CD8u: goto label_80192CD8;
    case 0x80192CDCu: goto label_80192CDC;
    case 0x80192CE0u: goto label_80192CE0;
    case 0x80192CE4u: goto label_80192CE4;
    case 0x80192CE8u: goto label_80192CE8;
    case 0x80192CECu: goto label_80192CEC;
    case 0x80192CF0u: goto label_80192CF0;
    case 0x80192CF4u: goto label_80192CF4;
    case 0x80192CF8u: goto label_80192CF8;
    case 0x80192CFCu: goto label_80192CFC;
    case 0x80192D00u: goto label_80192D00;
    case 0x80192D04u: goto label_80192D04;
    case 0x80192D08u: goto label_80192D08;
    case 0x80192D0Cu: goto label_80192D0C;
    case 0x80192D10u: goto label_80192D10;
    case 0x80192D14u: goto label_80192D14;
    case 0x80192D18u: goto label_80192D18;
    case 0x80192D1Cu: goto label_80192D1C;
    case 0x80192D20u: goto label_80192D20;
    case 0x80192D24u: goto label_80192D24;
    case 0x80192D28u: goto label_80192D28;
    case 0x80192D2Cu: goto label_80192D2C;
    case 0x80192D30u: goto label_80192D30;
    case 0x80192D34u: goto label_80192D34;
    case 0x80192D38u: goto label_80192D38;
    case 0x80192D3Cu: goto label_80192D3C;
    case 0x80192D40u: goto label_80192D40;
    case 0x80192D44u: goto label_80192D44;
    case 0x80192D48u: goto label_80192D48;
    case 0x80192D4Cu: goto label_80192D4C;
    case 0x80192D50u: goto label_80192D50;
    case 0x80192D54u: goto label_80192D54;
    case 0x80192D58u: goto label_80192D58;
    case 0x80192D5Cu: goto label_80192D5C;
    case 0x80192D60u: goto label_80192D60;
    case 0x80192D64u: goto label_80192D64;
    case 0x80192D68u: goto label_80192D68;
    case 0x80192D6Cu: goto label_80192D6C;
    case 0x80192D70u: goto label_80192D70;
    case 0x80192D74u: goto label_80192D74;
    case 0x80192D78u: goto label_80192D78;
    case 0x80192D7Cu: goto label_80192D7C;
    case 0x80192D80u: goto label_80192D80;
    case 0x80192D84u: goto label_80192D84;
    case 0x80192D88u: goto label_80192D88;
    case 0x80192D8Cu: goto label_80192D8C;
    case 0x80192D90u: goto label_80192D90;
    case 0x80192D94u: goto label_80192D94;
    case 0x80192D98u: goto label_80192D98;
    case 0x80192D9Cu: goto label_80192D9C;
    case 0x80192DA0u: goto label_80192DA0;
    case 0x80192DA4u: goto label_80192DA4;
    case 0x80192DA8u: goto label_80192DA8;
    case 0x80192DACu: goto label_80192DAC;
    case 0x80192DB0u: goto label_80192DB0;
    case 0x80192DB4u: goto label_80192DB4;
    case 0x80192DB8u: goto label_80192DB8;
    case 0x80192DBCu: goto label_80192DBC;
    case 0x80192DC0u: goto label_80192DC0;
    case 0x80192DC4u: goto label_80192DC4;
    case 0x80192DC8u: goto label_80192DC8;
    case 0x80192DCCu: goto label_80192DCC;
    case 0x80192DD0u: goto label_80192DD0;
    case 0x80192DD4u: goto label_80192DD4;
    case 0x80192DD8u: goto label_80192DD8;
    case 0x80192DDCu: goto label_80192DDC;
    case 0x80192DE0u: goto label_80192DE0;
    case 0x80192DE4u: goto label_80192DE4;
    case 0x80192DE8u: goto label_80192DE8;
    case 0x80192DECu: goto label_80192DEC;
    case 0x80192DF0u: goto label_80192DF0;
    case 0x80192DF4u: goto label_80192DF4;
    case 0x80192DF8u: goto label_80192DF8;
    case 0x80192DFCu: goto label_80192DFC;
    case 0x80192E00u: goto label_80192E00;
    case 0x80192E04u: goto label_80192E04;
    case 0x80192E08u: goto label_80192E08;
    case 0x80192E0Cu: goto label_80192E0C;
    case 0x80192E10u: goto label_80192E10;
    case 0x80192E14u: goto label_80192E14;
    case 0x80192E18u: goto label_80192E18;
    case 0x80192E1Cu: goto label_80192E1C;
    case 0x80192E20u: goto label_80192E20;
    case 0x80192E24u: goto label_80192E24;
    case 0x80192E28u: goto label_80192E28;
    case 0x80192E2Cu: goto label_80192E2C;
    case 0x80192E30u: goto label_80192E30;
    case 0x80192E34u: goto label_80192E34;
    case 0x80192E38u: goto label_80192E38;
    case 0x80192E3Cu: goto label_80192E3C;
    case 0x80192E40u: goto label_80192E40;
    case 0x80192E44u: goto label_80192E44;
    case 0x80192E48u: goto label_80192E48;
    case 0x80192E4Cu: goto label_80192E4C;
    case 0x80192E50u: goto label_80192E50;
    case 0x80192E54u: goto label_80192E54;
    case 0x80192E58u: goto label_80192E58;
    case 0x80192E5Cu: goto label_80192E5C;
    case 0x80192E60u: goto label_80192E60;
    case 0x80192E64u: goto label_80192E64;
    case 0x80192E68u: goto label_80192E68;
    case 0x80192E6Cu: goto label_80192E6C;
    case 0x80192E70u: goto label_80192E70;
    case 0x80192E74u: goto label_80192E74;
    case 0x80192E78u: goto label_80192E78;
    case 0x80192E7Cu: goto label_80192E7C;
    case 0x80192E80u: goto label_80192E80;
    case 0x80192E84u: goto label_80192E84;
    case 0x80192E88u: goto label_80192E88;
    case 0x80192E8Cu: goto label_80192E8C;
    case 0x80192E90u: goto label_80192E90;
    case 0x80192E94u: goto label_80192E94;
    case 0x80192E98u: goto label_80192E98;
    case 0x80192E9Cu: goto label_80192E9C;
    case 0x80192EA0u: goto label_80192EA0;
    case 0x80192EA4u: goto label_80192EA4;
    case 0x80192EA8u: goto label_80192EA8;
    case 0x80192EACu: goto label_80192EAC;
    case 0x80192EB0u: goto label_80192EB0;
    case 0x80192EB4u: goto label_80192EB4;
    case 0x80192EB8u: goto label_80192EB8;
    case 0x80192EBCu: goto label_80192EBC;
    case 0x80192EC0u: goto label_80192EC0;
    case 0x80192EC4u: goto label_80192EC4;
    case 0x80192EC8u: goto label_80192EC8;
    case 0x80192ECCu: goto label_80192ECC;
    case 0x80192ED0u: goto label_80192ED0;
    case 0x80192ED4u: goto label_80192ED4;
    case 0x80192ED8u: goto label_80192ED8;
    case 0x80192EDCu: goto label_80192EDC;
    case 0x80192EE0u: goto label_80192EE0;
    case 0x80192EE4u: goto label_80192EE4;
    case 0x80192EE8u: goto label_80192EE8;
    case 0x80192EECu: goto label_80192EEC;
    case 0x80192EF0u: goto label_80192EF0;
    case 0x80192EF4u: goto label_80192EF4;
    case 0x80192EF8u: goto label_80192EF8;
    case 0x80192EFCu: goto label_80192EFC;
    case 0x80192F00u: goto label_80192F00;
    case 0x80192F04u: goto label_80192F04;
    case 0x80192F08u: goto label_80192F08;
    case 0x80192F0Cu: goto label_80192F0C;
    case 0x80192F10u: goto label_80192F10;
    case 0x80192F14u: goto label_80192F14;
    case 0x80192F18u: goto label_80192F18;
    case 0x80192F1Cu: goto label_80192F1C;
    case 0x80192F20u: goto label_80192F20;
    case 0x80192F24u: goto label_80192F24;
    case 0x80192F28u: goto label_80192F28;
    case 0x80192F2Cu: goto label_80192F2C;
    case 0x80192F30u: goto label_80192F30;
    case 0x80192F34u: goto label_80192F34;
    case 0x80192F38u: goto label_80192F38;
    case 0x80192F3Cu: goto label_80192F3C;
    case 0x80192F40u: goto label_80192F40;
    case 0x80192F44u: goto label_80192F44;
    case 0x80192F48u: goto label_80192F48;
    case 0x80192F4Cu: goto label_80192F4C;
    case 0x80192F50u: goto label_80192F50;
    case 0x80192F54u: goto label_80192F54;
    case 0x80192F58u: goto label_80192F58;
    case 0x80192F5Cu: goto label_80192F5C;
    case 0x80192F60u: goto label_80192F60;
    case 0x80192F64u: goto label_80192F64;
    case 0x80192F68u: goto label_80192F68;
    case 0x80192F6Cu: goto label_80192F6C;
    case 0x80192F70u: goto label_80192F70;
    case 0x80192F74u: goto label_80192F74;
    case 0x80192F78u: goto label_80192F78;
    case 0x80192F7Cu: goto label_80192F7C;
    case 0x80192F80u: goto label_80192F80;
    case 0x80192F84u: goto label_80192F84;
    case 0x80192F88u: goto label_80192F88;
    case 0x80192F8Cu: goto label_80192F8C;
    case 0x80192F90u: goto label_80192F90;
    case 0x80192F94u: goto label_80192F94;
    case 0x80192F98u: goto label_80192F98;
    case 0x80192F9Cu: goto label_80192F9C;
    case 0x80192FA0u: goto label_80192FA0;
    case 0x80192FA4u: goto label_80192FA4;
    case 0x80192FA8u: goto label_80192FA8;
    case 0x80192FACu: goto label_80192FAC;
    case 0x80192FB0u: goto label_80192FB0;
    case 0x80192FB4u: goto label_80192FB4;
    case 0x80192FB8u: goto label_80192FB8;
    case 0x80192FBCu: goto label_80192FBC;
    case 0x80192FC0u: goto label_80192FC0;
    case 0x80192FC4u: goto label_80192FC4;
    case 0x80192FC8u: goto label_80192FC8;
    case 0x80192FCCu: goto label_80192FCC;
    case 0x80192FD0u: goto label_80192FD0;
    case 0x80192FD4u: goto label_80192FD4;
    case 0x80192FD8u: goto label_80192FD8;
    case 0x80192FDCu: goto label_80192FDC;
    case 0x80192FE0u: goto label_80192FE0;
    case 0x80192FE4u: goto label_80192FE4;
    case 0x80192FE8u: goto label_80192FE8;
    case 0x80192FECu: goto label_80192FEC;
    case 0x80192FF0u: goto label_80192FF0;
    case 0x80192FF4u: goto label_80192FF4;
    case 0x80192FF8u: goto label_80192FF8;
    case 0x80192FFCu: goto label_80192FFC;
    case 0x80193000u: goto label_80193000;
    case 0x80193004u: goto label_80193004;
    case 0x80193008u: goto label_80193008;
    case 0x8019300Cu: goto label_8019300C;
    case 0x80193010u: goto label_80193010;
    case 0x80193014u: goto label_80193014;
    case 0x80193018u: goto label_80193018;
    case 0x8019301Cu: goto label_8019301C;
    case 0x80193020u: goto label_80193020;
    case 0x80193024u: goto label_80193024;
    case 0x80193028u: goto label_80193028;
    case 0x8019302Cu: goto label_8019302C;
    case 0x80193030u: goto label_80193030;
    case 0x80193034u: goto label_80193034;
    case 0x80193038u: goto label_80193038;
    case 0x8019303Cu: goto label_8019303C;
    case 0x80193040u: goto label_80193040;
    case 0x80193044u: goto label_80193044;
    case 0x80193048u: goto label_80193048;
    case 0x8019304Cu: goto label_8019304C;
    case 0x80193050u: goto label_80193050;
    case 0x80193054u: goto label_80193054;
    case 0x80193058u: goto label_80193058;
    case 0x8019305Cu: goto label_8019305C;
    case 0x80193060u: goto label_80193060;
    case 0x80193064u: goto label_80193064;
    case 0x80193068u: goto label_80193068;
    case 0x8019306Cu: goto label_8019306C;
    case 0x80193070u: goto label_80193070;
    case 0x80193074u: goto label_80193074;
    case 0x80193078u: goto label_80193078;
    case 0x8019307Cu: goto label_8019307C;
    case 0x80193080u: goto label_80193080;
    case 0x80193084u: goto label_80193084;
    case 0x80193088u: goto label_80193088;
    case 0x8019308Cu: goto label_8019308C;
    case 0x80193090u: goto label_80193090;
    case 0x80193094u: goto label_80193094;
    case 0x80193098u: goto label_80193098;
    case 0x8019309Cu: goto label_8019309C;
    case 0x801930A0u: goto label_801930A0;
    case 0x801930A4u: goto label_801930A4;
    case 0x801930A8u: goto label_801930A8;
    case 0x801930ACu: goto label_801930AC;
    case 0x801930B0u: goto label_801930B0;
    case 0x801930B4u: goto label_801930B4;
    case 0x801930B8u: goto label_801930B8;
    case 0x801930BCu: goto label_801930BC;
    case 0x801930C0u: goto label_801930C0;
    case 0x801930C4u: goto label_801930C4;
    case 0x801930C8u: goto label_801930C8;
    case 0x801930CCu: goto label_801930CC;
    case 0x801930D0u: goto label_801930D0;
    case 0x801930D4u: goto label_801930D4;
    case 0x801930D8u: goto label_801930D8;
    case 0x801930DCu: goto label_801930DC;
    case 0x801930E0u: goto label_801930E0;
    case 0x801930E4u: goto label_801930E4;
    case 0x801930E8u: goto label_801930E8;
    case 0x801930ECu: goto label_801930EC;
    case 0x801930F0u: goto label_801930F0;
    case 0x801930F4u: goto label_801930F4;
    case 0x801930F8u: goto label_801930F8;
    case 0x801930FCu: goto label_801930FC;
    case 0x80193100u: goto label_80193100;
    case 0x80193104u: goto label_80193104;
    case 0x80193108u: goto label_80193108;
    case 0x8019310Cu: goto label_8019310C;
    case 0x80193110u: goto label_80193110;
    case 0x80193114u: goto label_80193114;
    case 0x80193118u: goto label_80193118;
    case 0x8019311Cu: goto label_8019311C;
    case 0x80193120u: goto label_80193120;
    case 0x80193124u: goto label_80193124;
    case 0x80193128u: goto label_80193128;
    case 0x8019312Cu: goto label_8019312C;
    case 0x80193130u: goto label_80193130;
    case 0x80193134u: goto label_80193134;
    case 0x80193138u: goto label_80193138;
    case 0x8019313Cu: goto label_8019313C;
    case 0x80193140u: goto label_80193140;
    case 0x80193144u: goto label_80193144;
    case 0x80193148u: goto label_80193148;
    case 0x8019314Cu: goto label_8019314C;
    case 0x80193150u: goto label_80193150;
    case 0x80193154u: goto label_80193154;
    case 0x80193158u: goto label_80193158;
    case 0x8019315Cu: goto label_8019315C;
    case 0x80193160u: goto label_80193160;
    case 0x80193164u: goto label_80193164;
    case 0x80193168u: goto label_80193168;
    case 0x8019316Cu: goto label_8019316C;
    case 0x80193170u: goto label_80193170;
    case 0x80193174u: goto label_80193174;
    case 0x80193178u: goto label_80193178;
    case 0x8019317Cu: goto label_8019317C;
    case 0x80193180u: goto label_80193180;
    case 0x80193184u: goto label_80193184;
    case 0x80193188u: goto label_80193188;
    case 0x8019318Cu: goto label_8019318C;
    case 0x80193190u: goto label_80193190;
    case 0x80193194u: goto label_80193194;
    case 0x80193198u: goto label_80193198;
    case 0x8019319Cu: goto label_8019319C;
    case 0x801931A0u: goto label_801931A0;
    case 0x801931A4u: goto label_801931A4;
    case 0x801931A8u: goto label_801931A8;
    case 0x801931ACu: goto label_801931AC;
    case 0x801931B0u: goto label_801931B0;
    case 0x801931B4u: goto label_801931B4;
    case 0x801931B8u: goto label_801931B8;
    case 0x801931BCu: goto label_801931BC;
    case 0x801931C0u: goto label_801931C0;
    case 0x801931C4u: goto label_801931C4;
    case 0x801931C8u: goto label_801931C8;
    case 0x801931CCu: goto label_801931CC;
    case 0x801931D0u: goto label_801931D0;
    case 0x801931D4u: goto label_801931D4;
    case 0x801931D8u: goto label_801931D8;
    case 0x801931DCu: goto label_801931DC;
    case 0x801931E0u: goto label_801931E0;
    case 0x801931E4u: goto label_801931E4;
    case 0x801931E8u: goto label_801931E8;
    case 0x801931ECu: goto label_801931EC;
    case 0x801931F0u: goto label_801931F0;
    case 0x801931F4u: goto label_801931F4;
    case 0x801931F8u: goto label_801931F8;
    case 0x801931FCu: goto label_801931FC;
    case 0x80193200u: goto label_80193200;
    case 0x80193204u: goto label_80193204;
    case 0x80193208u: goto label_80193208;
    case 0x8019320Cu: goto label_8019320C;
    case 0x80193210u: goto label_80193210;
    case 0x80193214u: goto label_80193214;
    case 0x80193218u: goto label_80193218;
    case 0x8019321Cu: goto label_8019321C;
    case 0x80193220u: goto label_80193220;
    case 0x80193224u: goto label_80193224;
    case 0x80193228u: goto label_80193228;
    case 0x8019322Cu: goto label_8019322C;
    case 0x80193230u: goto label_80193230;
    case 0x80193234u: goto label_80193234;
    case 0x80193238u: goto label_80193238;
    case 0x8019323Cu: goto label_8019323C;
    case 0x80193240u: goto label_80193240;
    case 0x80193244u: goto label_80193244;
    case 0x80193248u: goto label_80193248;
    case 0x8019324Cu: goto label_8019324C;
    case 0x80193250u: goto label_80193250;
    case 0x80193254u: goto label_80193254;
    case 0x80193258u: goto label_80193258;
    case 0x8019325Cu: goto label_8019325C;
    case 0x80193260u: goto label_80193260;
    case 0x80193264u: goto label_80193264;
    case 0x80193268u: goto label_80193268;
    case 0x8019326Cu: goto label_8019326C;
    case 0x80193270u: goto label_80193270;
    case 0x80193274u: goto label_80193274;
    case 0x80193278u: goto label_80193278;
    case 0x8019327Cu: goto label_8019327C;
    case 0x80193280u: goto label_80193280;
    case 0x80193284u: goto label_80193284;
    case 0x80193288u: goto label_80193288;
    case 0x8019328Cu: goto label_8019328C;
    case 0x80193290u: goto label_80193290;
    case 0x80193294u: goto label_80193294;
    case 0x80193298u: goto label_80193298;
    case 0x8019329Cu: goto label_8019329C;
    case 0x801932A0u: goto label_801932A0;
    case 0x801932A4u: goto label_801932A4;
    case 0x801932A8u: goto label_801932A8;
    case 0x801932ACu: goto label_801932AC;
    case 0x801932B0u: goto label_801932B0;
    case 0x801932B4u: goto label_801932B4;
    case 0x801932B8u: goto label_801932B8;
    case 0x801932BCu: goto label_801932BC;
    case 0x801932C0u: goto label_801932C0;
    case 0x801932C4u: goto label_801932C4;
    case 0x801932C8u: goto label_801932C8;
    case 0x801932CCu: goto label_801932CC;
    case 0x801932D0u: goto label_801932D0;
    case 0x801932D4u: goto label_801932D4;
    case 0x801932D8u: goto label_801932D8;
    case 0x801932DCu: goto label_801932DC;
    case 0x801932E0u: goto label_801932E0;
    case 0x801932E4u: goto label_801932E4;
    case 0x801932E8u: goto label_801932E8;
    case 0x801932ECu: goto label_801932EC;
    case 0x801932F0u: goto label_801932F0;
    case 0x801932F4u: goto label_801932F4;
    case 0x801932F8u: goto label_801932F8;
    case 0x801932FCu: goto label_801932FC;
    case 0x80193300u: goto label_80193300;
    case 0x80193304u: goto label_80193304;
    case 0x80193308u: goto label_80193308;
    case 0x8019330Cu: goto label_8019330C;
    case 0x80193310u: goto label_80193310;
    case 0x80193314u: goto label_80193314;
    case 0x80193318u: goto label_80193318;
    case 0x8019331Cu: goto label_8019331C;
    case 0x80193320u: goto label_80193320;
    case 0x80193324u: goto label_80193324;
    case 0x80193328u: goto label_80193328;
    case 0x8019332Cu: goto label_8019332C;
    case 0x80193330u: goto label_80193330;
    case 0x80193334u: goto label_80193334;
    case 0x80193338u: goto label_80193338;
    case 0x8019333Cu: goto label_8019333C;
    case 0x80193340u: goto label_80193340;
    case 0x80193344u: goto label_80193344;
    case 0x80193348u: goto label_80193348;
    case 0x8019334Cu: goto label_8019334C;
    case 0x80193350u: goto label_80193350;
    case 0x80193354u: goto label_80193354;
    case 0x80193358u: goto label_80193358;
    case 0x8019335Cu: goto label_8019335C;
    case 0x80193360u: goto label_80193360;
    case 0x80193364u: goto label_80193364;
    case 0x80193368u: goto label_80193368;
    case 0x8019336Cu: goto label_8019336C;
    case 0x80193370u: goto label_80193370;
    case 0x80193374u: goto label_80193374;
    case 0x80193378u: goto label_80193378;
    case 0x8019337Cu: goto label_8019337C;
    case 0x80193380u: goto label_80193380;
    case 0x80193384u: goto label_80193384;
    case 0x80193388u: goto label_80193388;
    case 0x8019338Cu: goto label_8019338C;
    case 0x80193390u: goto label_80193390;
    case 0x80193394u: goto label_80193394;
    case 0x80193398u: goto label_80193398;
    case 0x8019339Cu: goto label_8019339C;
    case 0x801933A0u: goto label_801933A0;
    case 0x801933A4u: goto label_801933A4;
    case 0x801933A8u: goto label_801933A8;
    case 0x801933ACu: goto label_801933AC;
    case 0x801933B0u: goto label_801933B0;
    case 0x801933B4u: goto label_801933B4;
    case 0x801933B8u: goto label_801933B8;
    case 0x801933BCu: goto label_801933BC;
    case 0x801933C0u: goto label_801933C0;
    case 0x801933C4u: goto label_801933C4;
    case 0x801933C8u: goto label_801933C8;
    case 0x801933CCu: goto label_801933CC;
    case 0x801933D0u: goto label_801933D0;
    case 0x801933D4u: goto label_801933D4;
    case 0x801933D8u: goto label_801933D8;
    case 0x801933DCu: goto label_801933DC;
    case 0x801933E0u: goto label_801933E0;
    case 0x801933E4u: goto label_801933E4;
    case 0x801933E8u: goto label_801933E8;
    case 0x801933ECu: goto label_801933EC;
    case 0x801933F0u: goto label_801933F0;
    case 0x801933F4u: goto label_801933F4;
    case 0x801933F8u: goto label_801933F8;
    case 0x801933FCu: goto label_801933FC;
    case 0x80193400u: goto label_80193400;
    case 0x80193404u: goto label_80193404;
    case 0x80193408u: goto label_80193408;
    case 0x8019340Cu: goto label_8019340C;
    case 0x80193410u: goto label_80193410;
    case 0x80193414u: goto label_80193414;
    case 0x80193418u: goto label_80193418;
    case 0x8019341Cu: goto label_8019341C;
    case 0x80193420u: goto label_80193420;
    case 0x80193424u: goto label_80193424;
    case 0x80193428u: goto label_80193428;
    case 0x8019342Cu: goto label_8019342C;
    case 0x80193430u: goto label_80193430;
    case 0x80193434u: goto label_80193434;
    case 0x80193438u: goto label_80193438;
    case 0x8019343Cu: goto label_8019343C;
    case 0x80193440u: goto label_80193440;
    case 0x80193444u: goto label_80193444;
    case 0x80193448u: goto label_80193448;
    case 0x8019344Cu: goto label_8019344C;
    case 0x80193450u: goto label_80193450;
    case 0x80193454u: goto label_80193454;
    case 0x80193458u: goto label_80193458;
    case 0x8019345Cu: goto label_8019345C;
    case 0x80193460u: goto label_80193460;
    case 0x80193464u: goto label_80193464;
    case 0x80193468u: goto label_80193468;
    case 0x8019346Cu: goto label_8019346C;
    case 0x80193470u: goto label_80193470;
    case 0x80193474u: goto label_80193474;
    case 0x80193478u: goto label_80193478;
    case 0x8019347Cu: goto label_8019347C;
    case 0x80193480u: goto label_80193480;
    case 0x80193484u: goto label_80193484;
    case 0x80193488u: goto label_80193488;
    case 0x8019348Cu: goto label_8019348C;
    case 0x80193490u: goto label_80193490;
    case 0x80193494u: goto label_80193494;
    case 0x80193498u: goto label_80193498;
    case 0x8019349Cu: goto label_8019349C;
    case 0x801934A0u: goto label_801934A0;
    case 0x801934A4u: goto label_801934A4;
    case 0x801934A8u: goto label_801934A8;
    case 0x801934ACu: goto label_801934AC;
    case 0x801934B0u: goto label_801934B0;
    case 0x801934B4u: goto label_801934B4;
    case 0x801934B8u: goto label_801934B8;
    case 0x801934BCu: goto label_801934BC;
    default: return;
    }
label_8018F4C0:
    ctx->pc = 0x8018F4C0u;
    ctx->downcount -= 2;
    // 8018F4C0: lis     r22, -32720
    ctx->gpr[22] = ((u32)(s32)(-32720) << 16);

label_8018F4C4:
    ctx->pc = 0x8018F4C4u;
    // 8018F4C4: bl      0x801D009C
    {
            ctx->lr = 0x8018F4C8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F4C8:
    ctx->pc = 0x8018F4C8u;
    ctx->downcount -= 6;
    // 8018F4C8: addi    r24, r31, 384
    ctx->gpr[24] = ctx->gpr[31] + (u32)(s32)(384);

label_8018F4CC:
    ctx->pc = 0x8018F4CCu;
    // 8018F4CC: addi    r0, r1, 128
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(128);

label_8018F4D0:
    ctx->pc = 0x8018F4D0u;
    // 8018F4D0: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8018F4D4:
    ctx->pc = 0x8018F4D4u;
    // 8018F4D4: stw     r0, 832(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(832);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018F4D8:
    ctx->pc = 0x8018F4D8u;
    // 8018F4D8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F4DC:
    ctx->pc = 0x8018F4DCu;
    // 8018F4DC: bl      0x801D009C
    {
            ctx->lr = 0x8018F4E0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F4E0:
    ctx->pc = 0x8018F4E0u;
    ctx->downcount -= 10;
    // 8018F4E0: li      r23, 0
    ctx->gpr[23] = (u32)(s32)(0);

label_8018F4E4:
    ctx->pc = 0x8018F4E4u;
    // 8018F4E4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8018F4E8:
    ctx->pc = 0x8018F4E8u;
    // 8018F4E8: stfs     f1, 1776(r31)
    if (!ppc_fp_available_inline(ctx, 0x8018F4E8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1776);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F4EC:
    ctx->pc = 0x8018F4ECu;
    // 8018F4EC: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F4F0:
    ctx->pc = 0x8018F4F0u;
    // 8018F4F0: lfs     f1, -16612(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F4F0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16612);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8018F4F4:
    ctx->pc = 0x8018F4F4u;
    // 8018F4F4: addi    r30, r30, -17212
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17212);

label_8018F4F8:
    ctx->pc = 0x8018F4F8u;
    // 8018F4F8: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F4FC:
    ctx->pc = 0x8018F4FCu;
    // 8018F4FC: addi    r15, r1, 136
    ctx->gpr[15] = ctx->gpr[1] + (u32)(s32)(136);

label_8018F500:
    ctx->pc = 0x8018F500u;
    // 8018F500: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F504:
    ctx->pc = 0x8018F504u;
    // 8018F504: bl      0x801D009C
    {
            ctx->lr = 0x8018F508u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F508:
    ctx->pc = 0x8018F508u;
    ctx->downcount -= 5;
    // 8018F508: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8018F50C:
    ctx->pc = 0x8018F50Cu;
    // 8018F50C: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8018F510:
    ctx->pc = 0x8018F510u;
    // 8018F510: addi    r21, r1, 200
    ctx->gpr[21] = ctx->gpr[1] + (u32)(s32)(200);

label_8018F514:
    ctx->pc = 0x8018F514u;
    // 8018F514: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F518:
    ctx->pc = 0x8018F518u;
    // 8018F518: bl      0x801D009C
    {
            ctx->lr = 0x8018F51Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F51C:
    ctx->pc = 0x8018F51Cu;
    ctx->downcount -= 11;
    // 8018F51C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8018F520:
    ctx->pc = 0x8018F520u;
    // 8018F520: addi    r0, r31, 452
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(452);

label_8018F524:
    ctx->pc = 0x8018F524u;
    // 8018F524: lfs     f31, -16624(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F524u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16624);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8018F528:
    ctx->pc = 0x8018F528u;
    // 8018F528: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F52C:
    ctx->pc = 0x8018F52Cu;
    // 8018F52C: stw     r0, 836(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(836);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018F530:
    ctx->pc = 0x8018F530u;
    // 8018F530: addi    r30, r30, -17200
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17200);

label_8018F534:
    ctx->pc = 0x8018F534u;
    // 8018F534: stfs     f1, 1748(r31)
    if (!ppc_fp_available_inline(ctx, 0x8018F534u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1748);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F538:
    ctx->pc = 0x8018F538u;
    // 8018F538: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F53C:
    ctx->pc = 0x8018F53Cu;
    // 8018F53C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F540:
    ctx->pc = 0x8018F540u;
    // 8018F540: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8018F540u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8018F544:
    ctx->pc = 0x8018F544u;
    // 8018F544: bl      0x801D009C
    {
            ctx->lr = 0x8018F548u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F548:
    ctx->pc = 0x8018F548u;
    ctx->downcount -= 3;
    // 8018F548: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8018F54C:
    ctx->pc = 0x8018F54Cu;
    // 8018F54C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F550:
    ctx->pc = 0x8018F550u;
    // 8018F550: bl      0x801D009C
    {
            ctx->lr = 0x8018F554u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F554:
    ctx->pc = 0x8018F554u;
    ctx->downcount -= 7;
    // 8018F554: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F558:
    ctx->pc = 0x8018F558u;
    // 8018F558: stfs     f1, 1708(r31)
    if (!ppc_fp_available_inline(ctx, 0x8018F558u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1708);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F55C:
    ctx->pc = 0x8018F55Cu;
    // 8018F55C: addi    r30, r30, -17184
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17184);

label_8018F560:
    ctx->pc = 0x8018F560u;
    // 8018F560: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F564:
    ctx->pc = 0x8018F564u;
    // 8018F564: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F568:
    ctx->pc = 0x8018F568u;
    // 8018F568: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8018F568u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8018F56C:
    ctx->pc = 0x8018F56Cu;
    // 8018F56C: bl      0x801D009C
    {
            ctx->lr = 0x8018F570u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F570:
    ctx->pc = 0x8018F570u;
    ctx->downcount -= 3;
    // 8018F570: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8018F574:
    ctx->pc = 0x8018F574u;
    // 8018F574: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F578:
    ctx->pc = 0x8018F578u;
    // 8018F578: bl      0x801D009C
    {
            ctx->lr = 0x8018F57Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F57C:
    ctx->pc = 0x8018F57Cu;
    ctx->downcount -= 7;
    // 8018F57C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F580:
    ctx->pc = 0x8018F580u;
    // 8018F580: stfs     f1, 1712(r31)
    if (!ppc_fp_available_inline(ctx, 0x8018F580u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1712);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F584:
    ctx->pc = 0x8018F584u;
    // 8018F584: addi    r30, r30, -17172
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17172);

label_8018F588:
    ctx->pc = 0x8018F588u;
    // 8018F588: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F58C:
    ctx->pc = 0x8018F58Cu;
    // 8018F58C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F590:
    ctx->pc = 0x8018F590u;
    // 8018F590: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8018F590u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8018F594:
    ctx->pc = 0x8018F594u;
    // 8018F594: bl      0x801D009C
    {
            ctx->lr = 0x8018F598u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F598:
    ctx->pc = 0x8018F598u;
    ctx->downcount -= 3;
    // 8018F598: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F59C:
    ctx->pc = 0x8018F59Cu;
    // 8018F59C: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8018F5A0:
    ctx->pc = 0x8018F5A0u;
    // 8018F5A0: bl      0x801D009C
    {
            ctx->lr = 0x8018F5A4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F5A4:
    ctx->pc = 0x8018F5A4u;
    ctx->downcount -= 5;
    // 8018F5A4: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_8018F5A8:
    ctx->pc = 0x8018F5A8u;
    // 8018F5A8: lis     r11, -32718
    ctx->gpr[11] = ((u32)(s32)(-32718) << 16);

label_8018F5AC:
    ctx->pc = 0x8018F5ACu;
    // 8018F5AC: stfs     f1, 1832(r31)
    if (!ppc_fp_available_inline(ctx, 0x8018F5ACu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1832);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F5B0:
    ctx->pc = 0x8018F5B0u;
    // 8018F5B0: addi    r27, r9, -704
    ctx->gpr[27] = ctx->gpr[9] + (u32)(s32)(-704);

label_8018F5B4:
    ctx->pc = 0x8018F5B4u;
    // 8018F5B4: addi    r30, r11, -556
    ctx->gpr[30] = ctx->gpr[11] + (u32)(s32)(-556);

label_8018F5B8:
    ctx->pc = 0x8018F5B8u;
    ctx->downcount -= 7;
    // 8018F5B8: lwzx    r5, r29, r27
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[27];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018F5BC:
    // 8018F5BC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F5C0:
    ctx->pc = 0x8018F5C0u;
    // 8018F5C0: lwz     r7, 824(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(824);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8018F5C4:
    // 8018F5C4: addi    r4, r1, 112
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F5C8:
    ctx->pc = 0x8018F5C8u;
    // 8018F5C8: lwz     r6, 828(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(828);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8018F5CC:
    ctx->pc = 0x8018F5CCu;
    // 8018F5CC: stb     r23, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write8(ctx, ea, (u8)ctx->gpr[23]);
    }

label_8018F5D0:
    // 8018F5D0: bl      0x801B4568
    {
            ctx->lr = 0x8018F5D4u;
            ctx->pc = 0x801B4568u;
            return;
    }

label_8018F5D4:
    ctx->downcount -= 3;
    // 8018F5D4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8018F5D8:
    // 8018F5D8: cmpwi   r28, 32
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018F5DC:
    // 8018F5DC: bc    12, 2, 0x8018F5E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018F5E8;
        }
    }

label_8018F5E0:
    ctx->downcount -= 2;
    // 8018F5E0: cmpwi   r28, 34
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(34);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018F5E4:
    // 8018F5E4: bc    4, 2, 0x8018F5EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018F5EC;
        }
    }

label_8018F5E8:
    ctx->downcount -= 1;
    // 8018F5E8: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_8018F5EC:
    ctx->pc = 0x8018F5ECu;
    ctx->downcount -= 8;
    // 8018F5EC: lwzx    r5, r29, r30
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[30];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018F5F0:
    // 8018F5F0: li      r6, 32
    ctx->gpr[6] = (u32)(s32)(32);

label_8018F5F4:
    ctx->pc = 0x8018F5F4u;
    // 8018F5F4: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018F5F8:
    // 8018F5F8: or   r8, r25, r25
    {
        ctx->gpr[8] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F5FC:
    ctx->pc = 0x8018F5FCu;
    // 8018F5FC: lwz     r4, 828(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(828);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018F600:
    // 8018F600: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F604:
    // 8018F604: or   r10, r31, r31
    {
        ctx->gpr[10] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018F608:
    // 8018F608: bl      0x801B2180
    {
            ctx->lr = 0x8018F60Cu;
            ctx->pc = 0x801B2180u;
            return;
    }

label_8018F60C:
    ctx->pc = 0x8018F60Cu;
    ctx->downcount -= 5;
    // 8018F60C: stwx    r3, r29, r26
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[26];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018F610:
    // 8018F610: cmpwi   r28, 36
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(36);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018F614:
    // 8018F614: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_8018F618:
    // 8018F618: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_8018F61C:
    // 8018F61C: bc    4, 2, 0x8018F5B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018F5B8u;
                return;
            }
            goto label_8018F5B8;
        }
    }

label_8018F620:
    ctx->pc = 0x8018F620u;
    ctx->downcount -= 5;
    // 8018F620: lwz     r3, 828(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(828);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018F624:
    ctx->pc = 0x8018F624u;
    // 8018F624: addi    r4, r1, 112
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F628:
    ctx->pc = 0x8018F628u;
    // 8018F628: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018F62C:
    ctx->pc = 0x8018F62Cu;
    // 8018F62C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F630:
    ctx->pc = 0x8018F630u;
    // 8018F630: bl      0x801CFE40
    {
            ctx->lr = 0x8018F634u;
            ctx->pc = 0x801CFE40u;
            return;
    }

label_8018F634:
    ctx->pc = 0x8018F634u;
    ctx->downcount -= 5;
    // 8018F634: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8018F638:
    ctx->pc = 0x8018F638u;
    // 8018F638: lwz     r3, 828(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(828);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018F63C:
    ctx->pc = 0x8018F63Cu;
    // 8018F63C: addi    r4, r30, -17156
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-17156);

label_8018F640:
    ctx->pc = 0x8018F640u;
    // 8018F640: li      r28, 4
    ctx->gpr[28] = (u32)(s32)(4);

label_8018F644:
    ctx->pc = 0x8018F644u;
    // 8018F644: bl      0x801CFC48
    {
            ctx->lr = 0x8018F648u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8018F648:
    ctx->pc = 0x8018F648u;
    ctx->downcount -= 4;
    // 8018F648: lwz     r3, 832(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(832);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018F64C:
    ctx->pc = 0x8018F64Cu;
    // 8018F64C: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F650:
    ctx->pc = 0x8018F650u;
    // 8018F650: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018F654:
    ctx->pc = 0x8018F654u;
    // 8018F654: bl      0x801CFE40
    {
            ctx->lr = 0x8018F658u;
            ctx->pc = 0x801CFE40u;
            return;
    }

label_8018F658:
    ctx->pc = 0x8018F658u;
    ctx->downcount -= 3;
    // 8018F658: lwz     r3, 832(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(832);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018F65C:
    ctx->pc = 0x8018F65Cu;
    // 8018F65C: addi    r4, r30, -17156
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-17156);

label_8018F660:
    ctx->pc = 0x8018F660u;
    // 8018F660: bl      0x801CFC48
    {
            ctx->lr = 0x8018F664u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8018F664:
    ctx->pc = 0x8018F664u;
    ctx->downcount -= 2;
    // 8018F664: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8018F668:
    ctx->pc = 0x8018F668u;
    // 8018F668: addi    r27, r9, -17124
    ctx->gpr[27] = ctx->gpr[9] + (u32)(s32)(-17124);

label_8018F66C:
    ctx->pc = 0x8018F66Cu;
    ctx->downcount -= 5;
    // 8018F66C: lwzx    r30, r29, r27
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[27];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018F670:
    // 8018F670: addi    r3, r1, 120
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(120);

label_8018F674:
    ctx->pc = 0x8018F674u;
    // 8018F674: lfs     f1, -16608(r22)
    if (!ppc_fp_available_inline(ctx, 0x8018F674u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(-16608);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8018F678:
    // 8018F678: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F67C:
    // 8018F67C: bl      0x801D009C
    {
            ctx->lr = 0x8018F680u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F680:
    ctx->downcount -= 3;
    // 8018F680: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F684:
    // 8018F684: addi    r3, r1, 128
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(128);

label_8018F688:
    // 8018F688: bl      0x801D009C
    {
            ctx->lr = 0x8018F68Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F68C:
    ctx->pc = 0x8018F68Cu;
    ctx->downcount -= 4;
    // 8018F68C: stfsx    f1, r29, r24
    if (!ppc_fp_available_inline(ctx, 0x8018F68Cu)) return;
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[24];
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F690:
    // 8018F690: addic.  r28, r28, -1
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

label_8018F694:
    // 8018F694: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_8018F698:
    // 8018F698: bc    4, 2, 0x8018F66C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018F66Cu;
                return;
            }
            goto label_8018F66C;
        }
    }

label_8018F69C:
    ctx->pc = 0x8018F69Cu;
    ctx->downcount -= 7;
    // 8018F69C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F6A0:
    ctx->pc = 0x8018F6A0u;
    // 8018F6A0: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_8018F6A4:
    ctx->pc = 0x8018F6A4u;
    // 8018F6A4: addi    r30, r30, -17108
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17108);

label_8018F6A8:
    ctx->pc = 0x8018F6A8u;
    // 8018F6A8: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F6AC:
    ctx->pc = 0x8018F6ACu;
    // 8018F6AC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F6B0:
    ctx->pc = 0x8018F6B0u;
    // 8018F6B0: addi    r5, r5, -18884
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-18884);

label_8018F6B4:
    ctx->pc = 0x8018F6B4u;
    // 8018F6B4: bl      0x801D012C
    {
            ctx->lr = 0x8018F6B8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8018F6B8:
    ctx->pc = 0x8018F6B8u;
    ctx->downcount -= 4;
    // 8018F6B8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018F6BC:
    ctx->pc = 0x8018F6BCu;
    // 8018F6BC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F6C0:
    ctx->pc = 0x8018F6C0u;
    // 8018F6C0: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8018F6C4:
    ctx->pc = 0x8018F6C4u;
    // 8018F6C4: bl      0x801D012C
    {
            ctx->lr = 0x8018F6C8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8018F6C8:
    ctx->pc = 0x8018F6C8u;
    ctx->downcount -= 4;
    // 8018F6C8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018F6CC:
    ctx->pc = 0x8018F6CCu;
    // 8018F6CC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8018F6D0:
    ctx->pc = 0x8018F6D0u;
    // 8018F6D0: addi    r4, r4, -17092
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-17092);

label_8018F6D4:
    ctx->pc = 0x8018F6D4u;
    // 8018F6D4: bl      0x80297FBC
    {
            ctx->lr = 0x8018F6D8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_8018F6D8:
    ctx->pc = 0x8018F6D8u;
    ctx->downcount -= 2;
    // 8018F6D8: cmpwi   r3, 0
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

label_8018F6DC:
    ctx->pc = 0x8018F6DCu;
    // 8018F6DC: bc    4, 2, 0x8018F6EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018F6EC;
        }
    }

label_8018F6E0:
    ctx->pc = 0x8018F6E0u;
    ctx->downcount -= 3;
    // 8018F6E0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8018F6E4:
    ctx->pc = 0x8018F6E4u;
    // 8018F6E4: stw     r0, 1716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1716);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018F6E8:
    ctx->pc = 0x8018F6E8u;
    // 8018F6E8: b       0x8018F714
    {
            goto label_8018F714;
    }

label_8018F6EC:
    ctx->pc = 0x8018F6ECu;
    ctx->downcount -= 4;
    // 8018F6EC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8018F6F0:
    ctx->pc = 0x8018F6F0u;
    // 8018F6F0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F6F4:
    ctx->pc = 0x8018F6F4u;
    // 8018F6F4: addi    r4, r4, -17084
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-17084);

label_8018F6F8:
    ctx->pc = 0x8018F6F8u;
    // 8018F6F8: bl      0x80297FBC
    {
            ctx->lr = 0x8018F6FCu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_8018F6FC:
    ctx->pc = 0x8018F6FCu;
    ctx->downcount -= 2;
    // 8018F6FC: cmpwi   r3, 0
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

label_8018F700:
    ctx->pc = 0x8018F700u;
    // 8018F700: bc    4, 2, 0x8018F710
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018F710;
        }
    }

label_8018F704:
    ctx->pc = 0x8018F704u;
    ctx->downcount -= 3;
    // 8018F704: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8018F708:
    ctx->pc = 0x8018F708u;
    // 8018F708: stw     r0, 1716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1716);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018F70C:
    ctx->pc = 0x8018F70Cu;
    // 8018F70C: b       0x8018F714
    {
            goto label_8018F714;
    }

label_8018F710:
    ctx->pc = 0x8018F710u;
    ctx->downcount -= 1;
    // 8018F710: stw     r28, 1716(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1716);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8018F714:
    ctx->pc = 0x8018F714u;
    ctx->downcount -= 4;
    // 8018F714: addi    r5, r1, 112
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F718:
    ctx->pc = 0x8018F718u;
    // 8018F718: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018F71C:
    ctx->pc = 0x8018F71Cu;
    // 8018F71C: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F720:
    ctx->pc = 0x8018F720u;
    // 8018F720: bl      0x80194D48
    {
            ctx->lr = 0x8018F724u;
            ctx->pc = 0x80194D48u;
            return;
    }

label_8018F724:
    ctx->pc = 0x8018F724u;
    ctx->downcount -= 7;
    // 8018F724: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8018F728:
    ctx->pc = 0x8018F728u;
    // 8018F728: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F72C:
    ctx->pc = 0x8018F72Cu;
    // 8018F72C: addi    r30, r30, -17072
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17072);

label_8018F730:
    ctx->pc = 0x8018F730u;
    // 8018F730: lfs     f1, -16640(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F730u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16640);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8018F734:
    ctx->pc = 0x8018F734u;
    // 8018F734: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F738:
    ctx->pc = 0x8018F738u;
    // 8018F738: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F73C:
    ctx->pc = 0x8018F73Cu;
    // 8018F73C: bl      0x801D009C
    {
            ctx->lr = 0x8018F740u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F740:
    ctx->pc = 0x8018F740u;
    ctx->downcount -= 3;
    // 8018F740: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F744:
    ctx->pc = 0x8018F744u;
    // 8018F744: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F748:
    ctx->pc = 0x8018F748u;
    // 8018F748: bl      0x801D009C
    {
            ctx->lr = 0x8018F74Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F74C:
    ctx->pc = 0x8018F74Cu;
    ctx->downcount -= 8;
    // 8018F74C: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F750:
    ctx->pc = 0x8018F750u;
    // 8018F750: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F754:
    ctx->pc = 0x8018F754u;
    // 8018F754: addi    r30, r30, -17052
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17052);

label_8018F758:
    ctx->pc = 0x8018F758u;
    // 8018F758: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F75C:
    ctx->pc = 0x8018F75Cu;
    // 8018F75C: stfs     f1, 4(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F75Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F760:
    ctx->pc = 0x8018F760u;
    // 8018F760: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F764:
    ctx->pc = 0x8018F764u;
    // 8018F764: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018F768:
    ctx->pc = 0x8018F768u;
    // 8018F768: bl      0x801CFFC8
    {
            ctx->lr = 0x8018F76Cu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8018F76C:
    ctx->pc = 0x8018F76Cu;
    ctx->downcount -= 4;
    // 8018F76C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018F770:
    ctx->pc = 0x8018F770u;
    // 8018F770: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F774:
    ctx->pc = 0x8018F774u;
    // 8018F774: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F778:
    ctx->pc = 0x8018F778u;
    // 8018F778: bl      0x801CFFC8
    {
            ctx->lr = 0x8018F77Cu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8018F77C:
    ctx->pc = 0x8018F77Cu;
    ctx->downcount -= 8;
    // 8018F77C: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F780:
    ctx->pc = 0x8018F780u;
    // 8018F780: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F784:
    ctx->pc = 0x8018F784u;
    // 8018F784: addi    r30, r30, -17044
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17044);

label_8018F788:
    ctx->pc = 0x8018F788u;
    // 8018F788: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018F78C:
    ctx->pc = 0x8018F78Cu;
    // 8018F78C: stw     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018F790:
    ctx->pc = 0x8018F790u;
    // 8018F790: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F794:
    ctx->pc = 0x8018F794u;
    // 8018F794: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F798:
    ctx->pc = 0x8018F798u;
    // 8018F798: bl      0x801CFFC8
    {
            ctx->lr = 0x8018F79Cu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8018F79C:
    ctx->pc = 0x8018F79Cu;
    ctx->downcount -= 4;
    // 8018F79C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018F7A0:
    ctx->pc = 0x8018F7A0u;
    // 8018F7A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F7A4:
    ctx->pc = 0x8018F7A4u;
    // 8018F7A4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F7A8:
    ctx->pc = 0x8018F7A8u;
    // 8018F7A8: bl      0x801CFFC8
    {
            ctx->lr = 0x8018F7ACu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8018F7AC:
    ctx->pc = 0x8018F7ACu;
    ctx->downcount -= 8;
    // 8018F7AC: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F7B0:
    ctx->pc = 0x8018F7B0u;
    // 8018F7B0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F7B4:
    ctx->pc = 0x8018F7B4u;
    // 8018F7B4: addi    r30, r30, -17036
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17036);

label_8018F7B8:
    ctx->pc = 0x8018F7B8u;
    // 8018F7B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018F7BC:
    ctx->pc = 0x8018F7BCu;
    // 8018F7BC: stw     r3, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018F7C0:
    ctx->pc = 0x8018F7C0u;
    // 8018F7C0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F7C4:
    ctx->pc = 0x8018F7C4u;
    // 8018F7C4: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F7C8:
    ctx->pc = 0x8018F7C8u;
    // 8018F7C8: bl      0x801CFFC8
    {
            ctx->lr = 0x8018F7CCu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8018F7CC:
    ctx->pc = 0x8018F7CCu;
    ctx->downcount -= 4;
    // 8018F7CC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018F7D0:
    ctx->pc = 0x8018F7D0u;
    // 8018F7D0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F7D4:
    ctx->pc = 0x8018F7D4u;
    // 8018F7D4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F7D8:
    ctx->pc = 0x8018F7D8u;
    // 8018F7D8: bl      0x801CFFC8
    {
            ctx->lr = 0x8018F7DCu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8018F7DC:
    ctx->pc = 0x8018F7DCu;
    ctx->downcount -= 8;
    // 8018F7DC: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F7E0:
    ctx->pc = 0x8018F7E0u;
    // 8018F7E0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F7E4:
    ctx->pc = 0x8018F7E4u;
    // 8018F7E4: addi    r30, r30, -17024
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17024);

label_8018F7E8:
    ctx->pc = 0x8018F7E8u;
    // 8018F7E8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018F7EC:
    ctx->pc = 0x8018F7ECu;
    // 8018F7EC: stw     r3, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018F7F0:
    ctx->pc = 0x8018F7F0u;
    // 8018F7F0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F7F4:
    ctx->pc = 0x8018F7F4u;
    // 8018F7F4: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F7F8:
    ctx->pc = 0x8018F7F8u;
    // 8018F7F8: bl      0x801CFFC8
    {
            ctx->lr = 0x8018F7FCu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8018F7FC:
    ctx->pc = 0x8018F7FCu;
    ctx->downcount -= 4;
    // 8018F7FC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018F800:
    ctx->pc = 0x8018F800u;
    // 8018F800: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F804:
    ctx->pc = 0x8018F804u;
    // 8018F804: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F808:
    ctx->pc = 0x8018F808u;
    // 8018F808: bl      0x801CFFC8
    {
            ctx->lr = 0x8018F80Cu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8018F80C:
    ctx->pc = 0x8018F80Cu;
    ctx->downcount -= 9;
    // 8018F80C: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F810:
    ctx->pc = 0x8018F810u;
    // 8018F810: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_8018F814:
    ctx->pc = 0x8018F814u;
    // 8018F814: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F818:
    ctx->pc = 0x8018F818u;
    // 8018F818: lfs     f1, -16644(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018F818u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16644);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8018F81C:
    ctx->pc = 0x8018F81Cu;
    // 8018F81C: addi    r30, r30, -17012
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-17012);

label_8018F820:
    ctx->pc = 0x8018F820u;
    // 8018F820: stw     r3, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018F824:
    ctx->pc = 0x8018F824u;
    // 8018F824: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F828:
    ctx->pc = 0x8018F828u;
    // 8018F828: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F82C:
    ctx->pc = 0x8018F82Cu;
    // 8018F82C: bl      0x801D009C
    {
            ctx->lr = 0x8018F830u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F830:
    ctx->pc = 0x8018F830u;
    ctx->downcount -= 3;
    // 8018F830: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F834:
    ctx->pc = 0x8018F834u;
    // 8018F834: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F838:
    ctx->pc = 0x8018F838u;
    // 8018F838: bl      0x801D009C
    {
            ctx->lr = 0x8018F83Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F83C:
    ctx->pc = 0x8018F83Cu;
    ctx->downcount -= 9;
    // 8018F83C: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F840:
    ctx->pc = 0x8018F840u;
    // 8018F840: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_8018F844:
    ctx->pc = 0x8018F844u;
    // 8018F844: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F848:
    ctx->pc = 0x8018F848u;
    // 8018F848: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F84C:
    ctx->pc = 0x8018F84Cu;
    // 8018F84C: stfs     f1, 24(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F84Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F850:
    ctx->pc = 0x8018F850u;
    // 8018F850: addi    r30, r30, -16996
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16996);

label_8018F854:
    ctx->pc = 0x8018F854u;
    // 8018F854: lfs     f1, -16604(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018F854u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16604);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8018F858:
    ctx->pc = 0x8018F858u;
    // 8018F858: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F85C:
    ctx->pc = 0x8018F85Cu;
    // 8018F85C: bl      0x801D009C
    {
            ctx->lr = 0x8018F860u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F860:
    ctx->pc = 0x8018F860u;
    ctx->downcount -= 3;
    // 8018F860: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F864:
    ctx->pc = 0x8018F864u;
    // 8018F864: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F868:
    ctx->pc = 0x8018F868u;
    // 8018F868: bl      0x801D009C
    {
            ctx->lr = 0x8018F86Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F86C:
    ctx->pc = 0x8018F86Cu;
    ctx->downcount -= 10;
    // 8018F86C: lwz     r11, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8018F870:
    ctx->pc = 0x8018F870u;
    // 8018F870: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8018F874:
    ctx->pc = 0x8018F874u;
    // 8018F874: lfs     f30, -16668(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F874u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16668);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_8018F878:
    ctx->pc = 0x8018F878u;
    // 8018F878: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F87C:
    ctx->pc = 0x8018F87Cu;
    // 8018F87C: stfs     f1, 28(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018F87Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F880:
    ctx->pc = 0x8018F880u;
    // 8018F880: addi    r30, r30, -16976
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16976);

label_8018F884:
    ctx->pc = 0x8018F884u;
    // 8018F884: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F888:
    ctx->pc = 0x8018F888u;
    // 8018F888: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F88C:
    ctx->pc = 0x8018F88Cu;
    // 8018F88C: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x8018F88Cu)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8018F890:
    ctx->pc = 0x8018F890u;
    // 8018F890: bl      0x801D009C
    {
            ctx->lr = 0x8018F894u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F894:
    ctx->pc = 0x8018F894u;
    ctx->downcount -= 3;
    // 8018F894: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F898:
    ctx->pc = 0x8018F898u;
    // 8018F898: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F89C:
    ctx->pc = 0x8018F89Cu;
    // 8018F89C: bl      0x801D009C
    {
            ctx->lr = 0x8018F8A0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F8A0:
    ctx->pc = 0x8018F8A0u;
    ctx->downcount -= 9;
    // 8018F8A0: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F8A4:
    ctx->pc = 0x8018F8A4u;
    // 8018F8A4: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_8018F8A8:
    ctx->pc = 0x8018F8A8u;
    // 8018F8A8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F8AC:
    ctx->pc = 0x8018F8ACu;
    // 8018F8AC: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F8B0:
    ctx->pc = 0x8018F8B0u;
    // 8018F8B0: stfs     f1, 32(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F8B0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F8B4:
    ctx->pc = 0x8018F8B4u;
    // 8018F8B4: addi    r30, r30, -16956
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16956);

label_8018F8B8:
    ctx->pc = 0x8018F8B8u;
    // 8018F8B8: lfs     f1, -16600(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018F8B8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16600);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8018F8BC:
    ctx->pc = 0x8018F8BCu;
    // 8018F8BC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F8C0:
    ctx->pc = 0x8018F8C0u;
    // 8018F8C0: bl      0x801D009C
    {
            ctx->lr = 0x8018F8C4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F8C4:
    ctx->pc = 0x8018F8C4u;
    ctx->downcount -= 3;
    // 8018F8C4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F8C8:
    ctx->pc = 0x8018F8C8u;
    // 8018F8C8: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F8CC:
    ctx->pc = 0x8018F8CCu;
    // 8018F8CC: bl      0x801D009C
    {
            ctx->lr = 0x8018F8D0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F8D0:
    ctx->pc = 0x8018F8D0u;
    ctx->downcount -= 8;
    // 8018F8D0: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F8D4:
    ctx->pc = 0x8018F8D4u;
    // 8018F8D4: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F8D8:
    ctx->pc = 0x8018F8D8u;
    // 8018F8D8: addi    r30, r30, -16940
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16940);

label_8018F8DC:
    ctx->pc = 0x8018F8DCu;
    // 8018F8DC: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F8E0:
    ctx->pc = 0x8018F8E0u;
    // 8018F8E0: stfs     f1, 36(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F8E0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F8E4:
    ctx->pc = 0x8018F8E4u;
    // 8018F8E4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F8E8:
    ctx->pc = 0x8018F8E8u;
    // 8018F8E8: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x8018F8E8u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8018F8EC:
    ctx->pc = 0x8018F8ECu;
    // 8018F8EC: bl      0x801D009C
    {
            ctx->lr = 0x8018F8F0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F8F0:
    ctx->pc = 0x8018F8F0u;
    ctx->downcount -= 3;
    // 8018F8F0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F8F4:
    ctx->pc = 0x8018F8F4u;
    // 8018F8F4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F8F8:
    ctx->pc = 0x8018F8F8u;
    // 8018F8F8: bl      0x801D009C
    {
            ctx->lr = 0x8018F8FCu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F8FC:
    ctx->pc = 0x8018F8FCu;
    ctx->downcount -= 8;
    // 8018F8FC: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F900:
    ctx->pc = 0x8018F900u;
    // 8018F900: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F904:
    ctx->pc = 0x8018F904u;
    // 8018F904: addi    r30, r30, -16924
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16924);

label_8018F908:
    ctx->pc = 0x8018F908u;
    // 8018F908: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F90C:
    ctx->pc = 0x8018F90Cu;
    // 8018F90C: stfs     f1, 40(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F90Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F910:
    ctx->pc = 0x8018F910u;
    // 8018F910: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F914:
    ctx->pc = 0x8018F914u;
    // 8018F914: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x8018F914u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8018F918:
    ctx->pc = 0x8018F918u;
    // 8018F918: bl      0x801D009C
    {
            ctx->lr = 0x8018F91Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F91C:
    ctx->pc = 0x8018F91Cu;
    ctx->downcount -= 3;
    // 8018F91C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F920:
    ctx->pc = 0x8018F920u;
    // 8018F920: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F924:
    ctx->pc = 0x8018F924u;
    // 8018F924: bl      0x801D009C
    {
            ctx->lr = 0x8018F928u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F928:
    ctx->pc = 0x8018F928u;
    ctx->downcount -= 8;
    // 8018F928: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F92C:
    ctx->pc = 0x8018F92Cu;
    // 8018F92C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F930:
    ctx->pc = 0x8018F930u;
    // 8018F930: addi    r30, r30, -16904
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16904);

label_8018F934:
    ctx->pc = 0x8018F934u;
    // 8018F934: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F938:
    ctx->pc = 0x8018F938u;
    // 8018F938: stfs     f1, 44(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F938u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F93C:
    ctx->pc = 0x8018F93Cu;
    // 8018F93C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F940:
    ctx->pc = 0x8018F940u;
    // 8018F940: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x8018F940u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8018F944:
    ctx->pc = 0x8018F944u;
    // 8018F944: bl      0x801D009C
    {
            ctx->lr = 0x8018F948u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F948:
    ctx->pc = 0x8018F948u;
    ctx->downcount -= 3;
    // 8018F948: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F94C:
    ctx->pc = 0x8018F94Cu;
    // 8018F94C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F950:
    ctx->pc = 0x8018F950u;
    // 8018F950: bl      0x801D009C
    {
            ctx->lr = 0x8018F954u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F954:
    ctx->pc = 0x8018F954u;
    ctx->downcount -= 9;
    // 8018F954: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F958:
    ctx->pc = 0x8018F958u;
    // 8018F958: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F95C:
    ctx->pc = 0x8018F95Cu;
    // 8018F95C: addi    r30, r30, -16884
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16884);

label_8018F960:
    ctx->pc = 0x8018F960u;
    // 8018F960: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F964:
    ctx->pc = 0x8018F964u;
    // 8018F964: stfs     f1, 48(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F964u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F968:
    ctx->pc = 0x8018F968u;
    // 8018F968: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F96C:
    ctx->pc = 0x8018F96Cu;
    // 8018F96C: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x8018F96Cu)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8018F970:
    ctx->pc = 0x8018F970u;
    // 8018F970: lwz     r29, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018F974:
    ctx->pc = 0x8018F974u;
    // 8018F974: bl      0x801D009C
    {
            ctx->lr = 0x8018F978u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F978:
    ctx->pc = 0x8018F978u;
    ctx->downcount -= 3;
    // 8018F978: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F97C:
    ctx->pc = 0x8018F97Cu;
    // 8018F97C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F980:
    ctx->pc = 0x8018F980u;
    // 8018F980: bl      0x801D009C
    {
            ctx->lr = 0x8018F984u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F984:
    ctx->pc = 0x8018F984u;
    ctx->downcount -= 9;
    // 8018F984: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8018F988:
    ctx->pc = 0x8018F988u;
    // 8018F988: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018F98C:
    ctx->pc = 0x8018F98Cu;
    // 8018F98C: lfs     f29, -16676(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F98Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16676);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[29] = value;
        ctx->ps1[29] = value;
    }

label_8018F990:
    ctx->pc = 0x8018F990u;
    // 8018F990: addi    r30, r30, -16864
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16864);

label_8018F994:
    ctx->pc = 0x8018F994u;
    // 8018F994: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x8018F994u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_8018F998:
    ctx->pc = 0x8018F998u;
    // 8018F998: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018F99C:
    ctx->pc = 0x8018F99Cu;
    // 8018F99C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F9A0:
    ctx->pc = 0x8018F9A0u;
    // 8018F9A0: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x8018F9A0u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_8018F9A4:
    ctx->pc = 0x8018F9A4u;
    // 8018F9A4: bl      0x801D009C
    {
            ctx->lr = 0x8018F9A8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F9A8:
    ctx->pc = 0x8018F9A8u;
    ctx->downcount -= 3;
    // 8018F9A8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018F9AC:
    ctx->pc = 0x8018F9ACu;
    // 8018F9AC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018F9B0:
    ctx->pc = 0x8018F9B0u;
    // 8018F9B0: bl      0x801D009C
    {
            ctx->lr = 0x8018F9B4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018F9B4:
    ctx->pc = 0x8018F9B4u;
    ctx->downcount -= 14;
    // 8018F9B4: stfs     f31, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018F9B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8018F9B8:
    ctx->pc = 0x8018F9B8u;
    // 8018F9B8: stfs     f1, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018F9B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018F9BC:
    ctx->pc = 0x8018F9BCu;
    // 8018F9BC: lwz     r0, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018F9C0:
    ctx->pc = 0x8018F9C0u;
    // 8018F9C0: lwz     r9, 4(r15)
    {
        u32 ea = ctx->gpr[15] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F9C4:
    ctx->pc = 0x8018F9C4u;
    // 8018F9C4: stw     r0, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018F9C8:
    ctx->pc = 0x8018F9C8u;
    // 8018F9C8: stw     r9, 56(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8018F9CC:
    ctx->pc = 0x8018F9CCu;
    // 8018F9CC: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018F9D0:
    ctx->pc = 0x8018F9D0u;
    // 8018F9D0: addi    r11, r9, 52
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(52);

label_8018F9D4:
    ctx->pc = 0x8018F9D4u;
    // 8018F9D4: lfs     f9, 52(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018F9D4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_8018F9D8:
    ctx->pc = 0x8018F9D8u;
    // 8018F9D8: lfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018F9D8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8018F9DC:
    ctx->pc = 0x8018F9DCu;
    // 8018F9DC: fmuls   f0, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8018F9DCu)) return;
    ppc_fmuls(ctx, 0, 0, 0);

label_8018F9E0:
    ctx->pc = 0x8018F9E0u;
    // 8018F9E0: fmadds f10, f9, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x8018F9E0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[9], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_8018F9E4:
    ctx->pc = 0x8018F9E4u;
    // 8018F9E4: fcmpu   cr0, f10, f30
    if (!ppc_fp_available_inline(ctx, 0x8018F9E4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[10], ctx->fpr[30], false);

label_8018F9E8:
    ctx->pc = 0x8018F9E8u;
    // 8018F9E8: bc    12, 2, 0x8018FA1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FA1C;
        }
    }

label_8018F9EC:
    ctx->pc = 0x8018F9ECu;
    ctx->downcount -= 12;
    // 8018F9EC: lfs     f12, -29676(r13)
    if (!ppc_fp_available_inline(ctx, 0x8018F9ECu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29676);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8018F9F0:
    ctx->pc = 0x8018F9F0u;
    // 8018F9F0: frsqrte    f0, f10
    if (!ppc_fp_available_inline(ctx, 0x8018F9F0u)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[10], &result)) ctx->fpr[0] = result; }

label_8018F9F4:
    ctx->pc = 0x8018F9F4u;
    // 8018F9F4: lfs     f11, -29688(r13)
    if (!ppc_fp_available_inline(ctx, 0x8018F9F4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8018F9F8:
    ctx->pc = 0x8018F9F8u;
    // 8018F9F8: fmuls   f13, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8018F9F8u)) return;
    ppc_fmuls(ctx, 13, 0, 0);

label_8018F9FC:
    ctx->pc = 0x8018F9FCu;
    // 8018F9FC: fnmsubs f13, f13, f10, f12
    if (!ppc_fp_available_inline(ctx, 0x8018F9FCu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[13], ctx->fpr[10], ctx->fpr[12], true, true, true, &result))
            ctx->fpr[13] = ctx->ps1[13] = result;
    }

label_8018FA00:
    ctx->pc = 0x8018FA00u;
    // 8018FA00: fmuls   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x8018FA00u)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_8018FA04:
    ctx->pc = 0x8018FA04u;
    // 8018FA04: fmuls   f13, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x8018FA04u)) return;
    ppc_fmuls(ctx, 13, 13, 0);

label_8018FA08:
    ctx->pc = 0x8018FA08u;
    // 8018FA08: fmuls   f12, f9, f13
    if (!ppc_fp_available_inline(ctx, 0x8018FA08u)) return;
    ppc_fmuls(ctx, 12, 9, 13);

label_8018FA0C:
    ctx->pc = 0x8018FA0Cu;
    // 8018FA0C: stfs     f12, 52(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018FA0Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_8018FA10:
    ctx->pc = 0x8018FA10u;
    // 8018FA10: lfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018FA10u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8018FA14:
    ctx->pc = 0x8018FA14u;
    // 8018FA14: fmuls   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x8018FA14u)) return;
    ppc_fmuls(ctx, 0, 0, 13);

label_8018FA18:
    ctx->pc = 0x8018FA18u;
    // 8018FA18: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018FA18u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8018FA1C:
    ctx->pc = 0x8018FA1Cu;
    ctx->downcount -= 11;
    // 8018FA1C: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018FA20:
    ctx->pc = 0x8018FA20u;
    // 8018FA20: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018FA24:
    ctx->pc = 0x8018FA24u;
    // 8018FA24: addi    r30, r30, -16844
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16844);

label_8018FA28:
    ctx->pc = 0x8018FA28u;
    // 8018FA28: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018FA2C:
    ctx->pc = 0x8018FA2Cu;
    // 8018FA2C: lfs     f0, 52(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018FA2Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8018FA30:
    ctx->pc = 0x8018FA30u;
    // 8018FA30: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FA34:
    ctx->pc = 0x8018FA34u;
    // 8018FA34: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x8018FA34u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_8018FA38:
    ctx->pc = 0x8018FA38u;
    // 8018FA38: fabs    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8018FA38u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) & 0x7FFFFFFFFFFFFFFFull);

label_8018FA3C:
    ctx->pc = 0x8018FA3Cu;
    // 8018FA3C: stfs     f0, 52(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018FA3Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8018FA40:
    ctx->pc = 0x8018FA40u;
    // 8018FA40: lwz     r29, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018FA44:
    ctx->pc = 0x8018FA44u;
    // 8018FA44: bl      0x801D009C
    {
            ctx->lr = 0x8018FA48u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018FA48:
    ctx->pc = 0x8018FA48u;
    ctx->downcount -= 3;
    // 8018FA48: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FA4C:
    ctx->pc = 0x8018FA4Cu;
    // 8018FA4C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018FA50:
    ctx->pc = 0x8018FA50u;
    // 8018FA50: bl      0x801D009C
    {
            ctx->lr = 0x8018FA54u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018FA54:
    ctx->pc = 0x8018FA54u;
    ctx->downcount -= 7;
    // 8018FA54: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018FA58:
    ctx->pc = 0x8018FA58u;
    // 8018FA58: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x8018FA58u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_8018FA5C:
    ctx->pc = 0x8018FA5Cu;
    // 8018FA5C: addi    r30, r30, -16824
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16824);

label_8018FA60:
    ctx->pc = 0x8018FA60u;
    // 8018FA60: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018FA64:
    ctx->pc = 0x8018FA64u;
    // 8018FA64: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FA68:
    ctx->pc = 0x8018FA68u;
    // 8018FA68: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x8018FA68u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8018FA6C:
    ctx->pc = 0x8018FA6Cu;
    // 8018FA6C: bl      0x801D009C
    {
            ctx->lr = 0x8018FA70u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018FA70:
    ctx->pc = 0x8018FA70u;
    ctx->downcount -= 3;
    // 8018FA70: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FA74:
    ctx->pc = 0x8018FA74u;
    // 8018FA74: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018FA78:
    ctx->pc = 0x8018FA78u;
    // 8018FA78: bl      0x801D009C
    {
            ctx->lr = 0x8018FA7Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8018FA7C:
    ctx->pc = 0x8018FA7Cu;
    ctx->downcount -= 14;
    // 8018FA7C: stfs     f31, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FA7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8018FA80:
    ctx->pc = 0x8018FA80u;
    // 8018FA80: stfs     f1, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FA80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8018FA84:
    ctx->pc = 0x8018FA84u;
    // 8018FA84: lwz     r0, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FA88:
    ctx->pc = 0x8018FA88u;
    // 8018FA88: lwz     r9, 4(r15)
    {
        u32 ea = ctx->gpr[15] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018FA8C:
    ctx->pc = 0x8018FA8Cu;
    // 8018FA8C: stw     r0, 60(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018FA90:
    ctx->pc = 0x8018FA90u;
    // 8018FA90: stw     r9, 64(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8018FA94:
    ctx->pc = 0x8018FA94u;
    // 8018FA94: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018FA98:
    ctx->pc = 0x8018FA98u;
    // 8018FA98: addi    r11, r9, 60
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(60);

label_8018FA9C:
    ctx->pc = 0x8018FA9Cu;
    // 8018FA9C: lfs     f9, 60(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018FA9Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_8018FAA0:
    ctx->pc = 0x8018FAA0u;
    // 8018FAA0: lfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018FAA0u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8018FAA4:
    ctx->pc = 0x8018FAA4u;
    // 8018FAA4: fmuls   f0, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8018FAA4u)) return;
    ppc_fmuls(ctx, 0, 0, 0);

label_8018FAA8:
    ctx->pc = 0x8018FAA8u;
    // 8018FAA8: fmadds f10, f9, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x8018FAA8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[9], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_8018FAAC:
    ctx->pc = 0x8018FAACu;
    // 8018FAAC: fcmpu   cr0, f10, f30
    if (!ppc_fp_available_inline(ctx, 0x8018FAACu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[10], ctx->fpr[30], false);

label_8018FAB0:
    ctx->pc = 0x8018FAB0u;
    // 8018FAB0: bc    12, 2, 0x8018FAE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FAE4;
        }
    }

label_8018FAB4:
    ctx->pc = 0x8018FAB4u;
    ctx->downcount -= 12;
    // 8018FAB4: lfs     f12, -29676(r13)
    if (!ppc_fp_available_inline(ctx, 0x8018FAB4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29676);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8018FAB8:
    ctx->pc = 0x8018FAB8u;
    // 8018FAB8: frsqrte    f0, f10
    if (!ppc_fp_available_inline(ctx, 0x8018FAB8u)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[10], &result)) ctx->fpr[0] = result; }

label_8018FABC:
    ctx->pc = 0x8018FABCu;
    // 8018FABC: lfs     f11, -29688(r13)
    if (!ppc_fp_available_inline(ctx, 0x8018FABCu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8018FAC0:
    ctx->pc = 0x8018FAC0u;
    // 8018FAC0: fmuls   f13, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8018FAC0u)) return;
    ppc_fmuls(ctx, 13, 0, 0);

label_8018FAC4:
    ctx->pc = 0x8018FAC4u;
    // 8018FAC4: fnmsubs f13, f13, f10, f12
    if (!ppc_fp_available_inline(ctx, 0x8018FAC4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[13], ctx->fpr[10], ctx->fpr[12], true, true, true, &result))
            ctx->fpr[13] = ctx->ps1[13] = result;
    }

label_8018FAC8:
    ctx->pc = 0x8018FAC8u;
    // 8018FAC8: fmuls   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x8018FAC8u)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_8018FACC:
    ctx->pc = 0x8018FACCu;
    // 8018FACC: fmuls   f13, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x8018FACCu)) return;
    ppc_fmuls(ctx, 13, 13, 0);

label_8018FAD0:
    ctx->pc = 0x8018FAD0u;
    // 8018FAD0: fmuls   f12, f9, f13
    if (!ppc_fp_available_inline(ctx, 0x8018FAD0u)) return;
    ppc_fmuls(ctx, 12, 9, 13);

label_8018FAD4:
    ctx->pc = 0x8018FAD4u;
    // 8018FAD4: stfs     f12, 60(r9)
    if (!ppc_fp_available_inline(ctx, 0x8018FAD4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_8018FAD8:
    ctx->pc = 0x8018FAD8u;
    // 8018FAD8: lfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018FAD8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8018FADC:
    ctx->pc = 0x8018FADCu;
    // 8018FADC: fmuls   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x8018FADCu)) return;
    ppc_fmuls(ctx, 0, 0, 13);

label_8018FAE0:
    ctx->pc = 0x8018FAE0u;
    // 8018FAE0: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018FAE0u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8018FAE4:
    ctx->pc = 0x8018FAE4u;
    ctx->downcount -= 12;
    // 8018FAE4: lwz     r11, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8018FAE8:
    ctx->pc = 0x8018FAE8u;
    // 8018FAE8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018FAEC:
    ctx->pc = 0x8018FAECu;
    // 8018FAEC: addi    r30, r30, -16804
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16804);

label_8018FAF0:
    ctx->pc = 0x8018FAF0u;
    // 8018FAF0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018FAF4:
    ctx->pc = 0x8018FAF4u;
    // 8018FAF4: lfs     f0, 60(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018FAF4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8018FAF8:
    ctx->pc = 0x8018FAF8u;
    // 8018FAF8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FAFC:
    ctx->pc = 0x8018FAFCu;
    // 8018FAFC: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018FB00:
    ctx->pc = 0x8018FB00u;
    // 8018FB00: fabs    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8018FB00u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) & 0x7FFFFFFFFFFFFFFFull);

label_8018FB04:
    ctx->pc = 0x8018FB04u;
    // 8018FB04: stfs     f0, 60(r11)
    if (!ppc_fp_available_inline(ctx, 0x8018FB04u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8018FB08:
    ctx->pc = 0x8018FB08u;
    // 8018FB08: lwz     r9, 1840(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1840);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018FB0C:
    ctx->pc = 0x8018FB0Cu;
    // 8018FB0C: stw     r31, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018FB10:
    ctx->pc = 0x8018FB10u;
    // 8018FB10: bl      0x801D012C
    {
            ctx->lr = 0x8018FB14u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8018FB14:
    ctx->pc = 0x8018FB14u;
    ctx->downcount -= 4;
    // 8018FB14: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018FB18:
    ctx->pc = 0x8018FB18u;
    // 8018FB18: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FB1C:
    ctx->pc = 0x8018FB1Cu;
    // 8018FB1C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018FB20:
    ctx->pc = 0x8018FB20u;
    // 8018FB20: bl      0x801D012C
    {
            ctx->lr = 0x8018FB24u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8018FB24:
    ctx->pc = 0x8018FB24u;
    ctx->downcount -= 2;
    // 8018FB24: or.   r30, r3, r3
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

label_8018FB28:
    ctx->pc = 0x8018FB28u;
    // 8018FB28: bc    12, 2, 0x8018FB80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FB80;
        }
    }

label_8018FB2C:
    ctx->pc = 0x8018FB2Cu;
    ctx->downcount -= 4;
    // 8018FB2C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8018FB30:
    ctx->pc = 0x8018FB30u;
    // 8018FB30: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FB34:
    ctx->pc = 0x8018FB34u;
    // 8018FB34: addi    r4, r4, -16788
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16788);

label_8018FB38:
    ctx->pc = 0x8018FB38u;
    // 8018FB38: bl      0x80297FBC
    {
            ctx->lr = 0x8018FB3Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_8018FB3C:
    ctx->pc = 0x8018FB3Cu;
    ctx->downcount -= 2;
    // 8018FB3C: cmpwi   r3, 0
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

label_8018FB40:
    ctx->pc = 0x8018FB40u;
    // 8018FB40: bc    4, 2, 0x8018FB4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018FB4C;
        }
    }

label_8018FB44:
    ctx->pc = 0x8018FB44u;
    ctx->downcount -= 2;
    // 8018FB44: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_8018FB48:
    ctx->pc = 0x8018FB48u;
    // 8018FB48: b       0x8018FB84
    {
            goto label_8018FB84;
    }

label_8018FB4C:
    ctx->pc = 0x8018FB4Cu;
    ctx->downcount -= 4;
    // 8018FB4C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8018FB50:
    ctx->pc = 0x8018FB50u;
    // 8018FB50: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FB54:
    ctx->pc = 0x8018FB54u;
    // 8018FB54: addi    r4, r4, -16776
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16776);

label_8018FB58:
    ctx->pc = 0x8018FB58u;
    // 8018FB58: bl      0x80297FBC
    {
            ctx->lr = 0x8018FB5Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_8018FB5C:
    ctx->pc = 0x8018FB5Cu;
    ctx->downcount -= 2;
    // 8018FB5C: cmpwi   r3, 0
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

label_8018FB60:
    ctx->pc = 0x8018FB60u;
    // 8018FB60: bc    4, 2, 0x8018FB6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018FB6C;
        }
    }

label_8018FB64:
    ctx->pc = 0x8018FB64u;
    ctx->downcount -= 2;
    // 8018FB64: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8018FB68:
    ctx->pc = 0x8018FB68u;
    // 8018FB68: b       0x8018FB84
    {
            goto label_8018FB84;
    }

label_8018FB6C:
    ctx->pc = 0x8018FB6Cu;
    ctx->downcount -= 4;
    // 8018FB6C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8018FB70:
    ctx->pc = 0x8018FB70u;
    // 8018FB70: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FB74:
    ctx->pc = 0x8018FB74u;
    // 8018FB74: addi    r4, r4, -16760
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16760);

label_8018FB78:
    ctx->pc = 0x8018FB78u;
    // 8018FB78: bl      0x80297FBC
    {
            ctx->lr = 0x8018FB7Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_8018FB7C:
    ctx->pc = 0x8018FB7Cu;
    ctx->downcount -= 1;
    // 8018FB7C: cmpwi   r3, 0
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

label_8018FB80:
    ctx->pc = 0x8018FB80u;
    ctx->downcount -= 1;
    // 8018FB80: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_8018FB84:
    ctx->pc = 0x8018FB84u;
    ctx->downcount -= 7;
    // 8018FB84: stw     r0, 1800(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1800);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018FB88:
    ctx->pc = 0x8018FB88u;
    // 8018FB88: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8018FB8C:
    ctx->pc = 0x8018FB8Cu;
    // 8018FB8C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018FB90:
    ctx->pc = 0x8018FB90u;
    // 8018FB90: addi    r30, r30, -16748
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16748);

label_8018FB94:
    ctx->pc = 0x8018FB94u;
    // 8018FB94: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018FB98:
    ctx->pc = 0x8018FB98u;
    // 8018FB98: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FB9C:
    ctx->pc = 0x8018FB9Cu;
    // 8018FB9C: bl      0x801D012C
    {
            ctx->lr = 0x8018FBA0u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8018FBA0:
    ctx->pc = 0x8018FBA0u;
    ctx->downcount -= 4;
    // 8018FBA0: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018FBA4:
    ctx->pc = 0x8018FBA4u;
    // 8018FBA4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FBA8:
    ctx->pc = 0x8018FBA8u;
    // 8018FBA8: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8018FBAC:
    ctx->pc = 0x8018FBACu;
    // 8018FBAC: bl      0x801D012C
    {
            ctx->lr = 0x8018FBB0u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8018FBB0:
    ctx->pc = 0x8018FBB0u;
    ctx->downcount -= 2;
    // 8018FBB0: or.   r30, r3, r3
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

label_8018FBB4:
    ctx->pc = 0x8018FBB4u;
    // 8018FBB4: bc    12, 2, 0x8018FBFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FBFC;
        }
    }

label_8018FBB8:
    ctx->pc = 0x8018FBB8u;
    ctx->downcount -= 2;
    // 8018FBB8: li      r3, 2032
    ctx->gpr[3] = (u32)(s32)(2032);

label_8018FBBC:
    ctx->pc = 0x8018FBBCu;
    // 8018FBBC: bl      0x80281C60
    {
            ctx->lr = 0x8018FBC0u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8018FBC0:
    ctx->pc = 0x8018FBC0u;
    ctx->downcount -= 3;
    // 8018FBC0: lwz     r4, 816(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(816);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018FBC4:
    ctx->pc = 0x8018FBC4u;
    // 8018FBC4: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FBC8:
    ctx->pc = 0x8018FBC8u;
    // 8018FBC8: bl      0x8018E844
    {
            ctx->lr = 0x8018FBCCu;
            ctx->pc = 0x8018E844u;
            return;
    }

label_8018FBCC:
    ctx->pc = 0x8018FBCCu;
    ctx->downcount -= 7;
    // 8018FBCC: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018FBD0:
    ctx->pc = 0x8018FBD0u;
    // 8018FBD0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FBD4:
    ctx->pc = 0x8018FBD4u;
    // 8018FBD4: stw     r9, 1508(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1508);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8018FBD8:
    ctx->pc = 0x8018FBD8u;
    // 8018FBD8: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_8018FBDC:
    ctx->pc = 0x8018FBDCu;
    // 8018FBDC: stw     r31, 1512(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1512);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018FBE0:
    ctx->pc = 0x8018FBE0u;
    // 8018FBE0: li      r5, 80
    ctx->gpr[5] = (u32)(s32)(80);

label_8018FBE4:
    ctx->pc = 0x8018FBE4u;
    // 8018FBE4: bl      0x80287F10
    {
            ctx->lr = 0x8018FBE8u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8018FBE8:
    ctx->pc = 0x8018FBE8u;
    ctx->downcount -= 1;
    // 8018FBE8: b       0x8018FBFC
    {
            goto label_8018FBFC;
    }

label_8018FBEC:
    ctx->downcount -= 3;
    // 8018FBEC: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_8018FBF0:
    // 8018FBF0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8018FBF4:
    // 8018FBF4: bl      0x801CFEAC
    {
            ctx->lr = 0x8018FBF8u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_8018FBF8:
    ctx->downcount -= 1;
    // 8018FBF8: b       0x8018FEB8
    {
            goto label_8018FEB8;
    }

label_8018FBFC:
    ctx->downcount -= 8;
    // 8018FBFC: li      r22, 0
    ctx->gpr[22] = (u32)(s32)(0);

label_8018FC00:
    // 8018FC00: lis     r20, -16132
    ctx->gpr[20] = ((u32)(s32)(-16132) << 16);

label_8018FC04:
    ctx->pc = 0x8018FC04u;
    // 8018FC04: stb     r22, 200(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(200);
        mem_write8(ctx, ea, (u8)ctx->gpr[22]);
    }

label_8018FC08:
    // 8018FC08: li      r14, 0
    ctx->gpr[14] = (u32)(s32)(0);

label_8018FC0C:
    // 8018FC0C: addi    r16, r1, 280
    ctx->gpr[16] = ctx->gpr[1] + (u32)(s32)(280);

label_8018FC10:
    // 8018FC10: or   r17, r15, r15
    {
        ctx->gpr[17] = ctx->gpr[15] | ctx->gpr[15];
    }

label_8018FC14:
    // 8018FC14: or   r18, r19, r19
    {
        ctx->gpr[18] = ctx->gpr[19] | ctx->gpr[19];
    }

label_8018FC18:
    // 8018FC18: ori     r20, r20, 0x0FC1
    ctx->gpr[20] = ctx->gpr[20] | 0x0FC1u;

label_8018FC1C:
    ctx->downcount -= 6;
    // 8018FC1C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8018FC20:
    // 8018FC20: or   r5, r14, r14
    {
        ctx->gpr[5] = ctx->gpr[14] | ctx->gpr[14];
    }

label_8018FC24:
    // 8018FC24: addi    r4, r9, -16736
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-16736);

label_8018FC28:
    // 8018FC28: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_8018FC2C:
    // 8018FC2C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8018FC30:
    // 8018FC30: bl      0x800E48B0
    {
            ctx->lr = 0x8018FC34u;
            ctx->pc = 0x800E48B0u;
            return;
    }

label_8018FC34:
    ctx->downcount -= 5;
    // 8018FC34: addi    r14, r14, 1
    ctx->gpr[14] = ctx->gpr[14] + (u32)(s32)(1);

label_8018FC38:
    // 8018FC38: or   r4, r21, r21
    {
        ctx->gpr[4] = ctx->gpr[21] | ctx->gpr[21];
    }

label_8018FC3C:
    // 8018FC3C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018FC40:
    // 8018FC40: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018FC44:
    // 8018FC44: bl      0x801D012C
    {
            ctx->lr = 0x8018FC48u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8018FC48:
    ctx->downcount -= 4;
    // 8018FC48: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018FC4C:
    // 8018FC4C: or   r4, r21, r21
    {
        ctx->gpr[4] = ctx->gpr[21] | ctx->gpr[21];
    }

label_8018FC50:
    // 8018FC50: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8018FC54:
    // 8018FC54: bl      0x801D012C
    {
            ctx->lr = 0x8018FC58u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8018FC58:
    ctx->downcount -= 3;
    // 8018FC58: or.   r22, r3, r3
    {
        ctx->gpr[22] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[22];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018FC5C:
    // 8018FC5C: mfcr    r30
    ctx->gpr[30] = ctx->cr;

label_8018FC60:
    // 8018FC60: bc    12, 2, 0x8018FEB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FEB8;
        }
    }

label_8018FC64:
    ctx->downcount -= 8;
    // 8018FC64: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018FC68:
    // 8018FC68: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8018FC6C:
    // 8018FC6C: or   r5, r22, r22
    {
        ctx->gpr[5] = ctx->gpr[22] | ctx->gpr[22];
    }

label_8018FC70:
    // 8018FC70: addi    r4, r4, -16720
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16720);

label_8018FC74:
    ctx->pc = 0x8018FC74u;
    // 8018FC74: stb     r0, 280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018FC78:
    // 8018FC78: or   r3, r16, r16
    {
        ctx->gpr[3] = ctx->gpr[16] | ctx->gpr[16];
    }

label_8018FC7C:
    // 8018FC7C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8018FC80:
    // 8018FC80: bl      0x8009258C
    {
            ctx->lr = 0x8018FC84u;
            ctx->pc = 0x8009258Cu;
            return;
    }

label_8018FC84:
    ctx->downcount -= 2;
    // 8018FC84: or   r3, r17, r17
    {
        ctx->gpr[3] = ctx->gpr[17] | ctx->gpr[17];
    }

label_8018FC88:
    // 8018FC88: bl      0x801CFD60
    {
            ctx->lr = 0x8018FC8Cu;
            ctx->pc = 0x801CFD60u;
            return;
    }

label_8018FC8C:
    ctx->downcount -= 3;
    // 8018FC8C: or   r3, r17, r17
    {
        ctx->gpr[3] = ctx->gpr[17] | ctx->gpr[17];
    }

label_8018FC90:
    // 8018FC90: or   r4, r16, r16
    {
        ctx->gpr[4] = ctx->gpr[16] | ctx->gpr[16];
    }

label_8018FC94:
    // 8018FC94: bl      0x801CFF5C
    {
            ctx->lr = 0x8018FC98u;
            ctx->pc = 0x801CFF5Cu;
            return;
    }

label_8018FC98:
    ctx->downcount -= 2;
    // 8018FC98: cmpwi   r3, 0
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

label_8018FC9C:
    // 8018FC9C: bc    12, 2, 0x8018FBEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FBECu;
                return;
            }
            goto label_8018FBEC;
        }
    }

label_8018FCA0:
    ctx->pc = 0x8018FCA0u;
    ctx->downcount -= 3;
    // 8018FCA0: lwz     r4, 820(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(820);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018FCA4:
    // 8018FCA4: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_8018FCA8:
    // 8018FCA8: bl      0x801CFC48
    {
            ctx->lr = 0x8018FCACu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8018FCAC:
    ctx->downcount -= 5;
    // 8018FCAC: addi    r24, r1, 544
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(544);

label_8018FCB0:
    // 8018FCB0: or   r4, r22, r22
    {
        ctx->gpr[4] = ctx->gpr[22] | ctx->gpr[22];
    }

label_8018FCB4:
    // 8018FCB4: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8018FCB8:
    // 8018FCB8: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_8018FCBC:
    // 8018FCBC: bl      0x80287F10
    {
            ctx->lr = 0x8018FCC0u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8018FCC0:
    ctx->pc = 0x8018FCC0u;
    ctx->downcount -= 4;
    // 8018FCC0: lwz     r3, 4(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018FCC4:
    ctx->pc = 0x8018FCC4u;
    // 8018FCC4: lwz     r0, 12(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FCC8:
    // 8018FCC8: cmpw    r3, r0
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

label_8018FCCC:
    // 8018FCCC: bc    12, 2, 0x8018FD00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FD00;
        }
    }

label_8018FCD0:
    ctx->downcount -= 2;
    // 8018FCD0: cmpwi   r3, 0
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

label_8018FCD4:
    // 8018FCD4: bc    12, 2, 0x8018FCE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FCE4;
        }
    }

label_8018FCD8:
    ctx->downcount -= 3;
    // 8018FCD8: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8018FCDC:
    // 8018FCDC: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_8018FCE0:
    // 8018FCE0: bl      0x80287F10
    {
            ctx->lr = 0x8018FCE4u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8018FCE4:
    ctx->pc = 0x8018FCE4u;
    ctx->downcount -= 7;
    // 8018FCE4: lwz     r9, 4(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018FCE8:
    // 8018FCE8: rlwinm r30, r30, 16, 0, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 16u) & 0xFFFFFFFFu;
    }

label_8018FCEC:
    // 8018FCEC: mtcrf   0x08, r30
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[30] & 0x0000F000u);

label_8018FCF0:
    // 8018FCF0: rlwinm r30, r30, 16, 0, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 16u) & 0xFFFFFFFFu;
    }

label_8018FCF4:
    // 8018FCF4: addi    r9, r9, 260
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(260);

label_8018FCF8:
    ctx->pc = 0x8018FCF8u;
    // 8018FCF8: stw     r9, 4(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8018FCFC:
    // 8018FCFC: b       0x8018FE90
    {
            goto label_8018FE90;
    }

label_8018FD00:
    ctx->pc = 0x8018FD00u;
    ctx->downcount -= 16;
    // 8018FD00: lwz     r28, 4(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(4);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8018FD04:
    // 8018FD04: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8018FD08:
    ctx->pc = 0x8018FD08u;
    // 8018FD08: lwz     r0, 1664(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1664);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FD0C:
    // 8018FD0C: addi    r11, r1, 812
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(812);

label_8018FD10:
    ctx->pc = 0x8018FD10u;
    // 8018FD10: stw     r9, 812(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(812);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8018FD14:
    // 8018FD14: addi    r10, r1, 808
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(808);

label_8018FD18:
    // 8018FD18: subf   r0, r0, r28
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[28];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8018FD1C:
    // 8018FD1C: mullw   r0, r0, r20
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[20];
        ctx->gpr[0] = (u32)product;
    }

label_8018FD20:
    // 8018FD20: srawi r9, r0, 2
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

label_8018FD24:
    ctx->pc = 0x8018FD24u;
    // 8018FD24: stw     r9, 808(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(808);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8018FD28:
    // 8018FD28: cmplwi  r9, 0x0001
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

label_8018FD2C:
    // 8018FD2C: bc    4, 0, 0x8018FD34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018FD34;
        }
    }

label_8018FD30:
    ctx->downcount -= 1;
    // 8018FD30: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8018FD34:
    ctx->pc = 0x8018FD34u;
    ctx->downcount -= 3;
    // 8018FD34: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FD38:
    // 8018FD38: add.   r26, r9, r0
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[26] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[26];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018FD3C:
    // 8018FD3C: bc    12, 2, 0x8018FD68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FD68;
        }
    }

label_8018FD40:
    ctx->downcount -= 6;
    // 8018FD40: rlwinm r0, r26, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[26], 6u) & 0xFFFFFFC0u;
    }

label_8018FD44:
    // 8018FD44: add   r9, r0, r26
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8018FD48:
    // 8018FD48: or   r23, r0, r0
    {
        ctx->gpr[23] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8018FD4C:
    // 8018FD4C: rlwinm r3, r9, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8018FD50:
    // 8018FD50: cmplwi  r3, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018FD54:
    // 8018FD54: bc    4, 1, 0x8018FD60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018FD60;
        }
    }

label_8018FD58:
    ctx->downcount -= 1;
    // 8018FD58: bl      0x80281C60
    {
            ctx->lr = 0x8018FD5Cu;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8018FD5C:
    ctx->downcount -= 1;
    // 8018FD5C: b       0x8018FD70
    {
            goto label_8018FD70;
    }

label_8018FD60:
    ctx->downcount -= 1;
    // 8018FD60: bl      0x80004024
    {
            ctx->lr = 0x8018FD64u;
            ctx->pc = 0x80004024u;
            return;
    }

label_8018FD64:
    ctx->downcount -= 1;
    // 8018FD64: b       0x8018FD70
    {
            goto label_8018FD70;
    }

label_8018FD68:
    ctx->downcount -= 2;
    // 8018FD68: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018FD6C:
    // 8018FD6C: li      r23, 0
    ctx->gpr[23] = (u32)(s32)(0);

label_8018FD70:
    ctx->downcount -= 6;
    // 8018FD70: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018FD74:
    ctx->pc = 0x8018FD74u;
    // 8018FD74: lwz     r30, 0(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018FD78:
    // 8018FD78: or   r27, r29, r29
    {
        ctx->gpr[27] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8018FD7C:
    // 8018FD7C: cmpwi   cr4, r22, 0
    {
        s32 val_a = (s32)(ctx->gpr[22]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_8018FD80:
    // 8018FD80: cmpw    r30, r28
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018FD84:
    // 8018FD84: bc    12, 2, 0x8018FDC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FDC0;
        }
    }

label_8018FD88:
    ctx->downcount -= 2;
    // 8018FD88: cmpwi   r29, 0
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

label_8018FD8C:
    // 8018FD8C: bc    12, 2, 0x8018FDB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FDB0;
        }
    }

label_8018FD90:
    ctx->downcount -= 2;
    // 8018FD90: cmpwi   r30, 0
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

label_8018FD94:
    // 8018FD94: bc    12, 2, 0x8018FDAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FDAC;
        }
    }

label_8018FD98:
    ctx->downcount -= 4;
    // 8018FD98: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8018FD9C:
    // 8018FD9C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FDA0:
    // 8018FDA0: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_8018FDA4:
    // 8018FDA4: bl      0x80287F10
    {
            ctx->lr = 0x8018FDA8u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8018FDA8:
    ctx->downcount -= 1;
    // 8018FDA8: b       0x8018FDB0
    {
            goto label_8018FDB0;
    }

label_8018FDAC:
    ctx->pc = 0x8018FDACu;
    ctx->downcount -= 1;
    // 8018FDAC: stb     r30, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_8018FDB0:
    ctx->downcount -= 4;
    // 8018FDB0: addi    r30, r30, 260
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(260);

label_8018FDB4:
    // 8018FDB4: addi    r29, r29, 260
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(260);

label_8018FDB8:
    // 8018FDB8: cmpw    r30, r28
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018FDBC:
    // 8018FDBC: bc    4, 2, 0x8018FD88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FD88u;
                return;
            }
            goto label_8018FD88;
        }
    }

label_8018FDC0:
    ctx->pc = 0x8018FDC0u;
    ctx->downcount -= 3;
    // 8018FDC0: lwz     r0, 812(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(812);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FDC4:
    // 8018FDC4: cmpwi   r0, 1
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

label_8018FDC8:
    // 8018FDC8: bc    4, 2, 0x8018FDEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018FDEC;
        }
    }

label_8018FDCC:
    ctx->downcount -= 2;
    // 8018FDCC: cmpwi   r29, 0
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

label_8018FDD0:
    // 8018FDD0: bc    12, 2, 0x8018FDE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FDE4;
        }
    }

label_8018FDD4:
    ctx->downcount -= 4;
    // 8018FDD4: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8018FDD8:
    // 8018FDD8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8018FDDC:
    // 8018FDDC: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_8018FDE0:
    // 8018FDE0: bl      0x80287F10
    {
            ctx->lr = 0x8018FDE4u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8018FDE4:
    ctx->downcount -= 2;
    // 8018FDE4: addi    r29, r29, 260
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(260);

label_8018FDE8:
    // 8018FDE8: b       0x8018FE20
    {
            goto label_8018FE20;
    }

label_8018FDEC:
    ctx->downcount -= 3;
    // 8018FDEC: or   r30, r29, r29
    {
        ctx->gpr[30] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8018FDF0:
    // 8018FDF0: or.   r29, r0, r0
    {
        ctx->gpr[29] = ctx->gpr[0] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018FDF4:
    // 8018FDF4: bc    12, 2, 0x8018FE1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FE1C;
        }
    }

label_8018FDF8:
    ctx->downcount -= 2;
    // 8018FDF8: cmpwi   r30, 0
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

label_8018FDFC:
    // 8018FDFC: bc    12, 2, 0x8018FE10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FE10;
        }
    }

label_8018FE00:
    ctx->downcount -= 4;
    // 8018FE00: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FE04:
    // 8018FE04: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8018FE08:
    // 8018FE08: li      r5, 260
    ctx->gpr[5] = (u32)(s32)(260);

label_8018FE0C:
    // 8018FE0C: bl      0x80287F10
    {
            ctx->lr = 0x8018FE10u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8018FE10:
    ctx->downcount -= 3;
    // 8018FE10: addi    r30, r30, 260
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(260);

label_8018FE14:
    // 8018FE14: addic.  r29, r29, -1
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

label_8018FE18:
    // 8018FE18: bc    4, 2, 0x8018FDF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FDF8u;
                return;
            }
            goto label_8018FDF8;
        }
    }

label_8018FE1C:
    ctx->downcount -= 1;
    // 8018FE1C: or   r29, r30, r30
    {
        ctx->gpr[29] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018FE20:
    ctx->pc = 0x8018FE20u;
    ctx->downcount -= 6;
    // 8018FE20: lwz     r9, 0(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018FE24:
    ctx->pc = 0x8018FE24u;
    // 8018FE24: lwz     r11, 4(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8018FE28:
    // 8018FE28: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8018FE2C:
    ctx->pc = 0x8018FE2Cu;
    // 8018FE2C: lwz     r0, 12(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FE30:
    // 8018FE30: cmpw    r9, r11
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

label_8018FE34:
    // 8018FE34: bc    12, 2, 0x8018FE44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FE44;
        }
    }

label_8018FE38:
    loop_8018FE38(ctx);
    if (ctx->pc == 0x8018FE44u) goto label_8018FE44;
    return;
label_8018FE3C:
    // 8018FE3C: cmpw    r9, r11
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

label_8018FE40:
    // 8018FE40: bc    4, 2, 0x8018FE38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FE38u;
                return;
            }
            goto label_8018FE38;
        }
    }

label_8018FE44:
    ctx->downcount -= 9;
    // 8018FE44: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8018FE48:
    // 8018FE48: cmpwi   r3, 0
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

label_8018FE4C:
    // 8018FE4C: mullw   r0, r0, r20
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[20];
        ctx->gpr[0] = (u32)product;
    }

label_8018FE50:
    // 8018FE50: srawi r9, r0, 2
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

label_8018FE54:
    // 8018FE54: bc    12, 2, 0x8018FE78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018FE78;
        }
    }

label_8018FE58:
    ctx->downcount -= 5;
    // 8018FE58: rlwinm r0, r9, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[9], 6u) & 0xFFFFFFC0u;
    }

label_8018FE5C:
    // 8018FE5C: add   r0, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8018FE60:
    // 8018FE60: rlwinm r4, r0, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8018FE64:
    // 8018FE64: cmplwi  r4, 0x0080
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

label_8018FE68:
    // 8018FE68: bc    4, 1, 0x8018FE74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018FE74;
        }
    }

label_8018FE6C:
    ctx->downcount -= 1;
    // 8018FE6C: bl      0x80281D80
    {
            ctx->lr = 0x8018FE70u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8018FE70:
    ctx->downcount -= 1;
    // 8018FE70: b       0x8018FE78
    {
            goto label_8018FE78;
    }

label_8018FE74:
    ctx->downcount -= 1;
    // 8018FE74: bl      0x8001D934
    {
            ctx->lr = 0x8018FE78u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8018FE78:
    ctx->downcount -= 6;
    // 8018FE78: add   r0, r23, r26
    {
        u32 a = ctx->gpr[23];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8018FE7C:
    ctx->pc = 0x8018FE7Cu;
    // 8018FE7C: stw     r27, 0(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8018FE80:
    // 8018FE80: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8018FE84:
    ctx->pc = 0x8018FE84u;
    // 8018FE84: stw     r29, 4(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8018FE88:
    // 8018FE88: add   r0, r0, r27
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8018FE8C:
    ctx->pc = 0x8018FE8Cu;
    // 8018FE8C: stw     r0, 12(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018FE90:
    ctx->downcount -= 2;
    // 8018FE90: li      r3, 1060
    ctx->gpr[3] = (u32)(s32)(1060);

label_8018FE94:
    // 8018FE94: bl      0x80281C60
    {
            ctx->lr = 0x8018FE98u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_8018FE98:
    ctx->pc = 0x8018FE98u;
    ctx->downcount -= 4;
    // 8018FE98: lwz     r4, 816(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(816);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018FE9C:
    // 8018FE9C: or   r5, r22, r22
    {
        ctx->gpr[5] = ctx->gpr[22] | ctx->gpr[22];
    }

label_8018FEA0:
    // 8018FEA0: or   r6, r31, r31
    {
        ctx->gpr[6] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018FEA4:
    // 8018FEA4: bl      0x801A586C
    {
            ctx->lr = 0x8018FEA8u;
            ctx->pc = 0x801A586Cu;
            return;
    }

label_8018FEA8:
    ctx->downcount -= 3;
    // 8018FEA8: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_8018FEAC:
    // 8018FEAC: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8018FEB0:
    // 8018FEB0: bl      0x801CFEAC
    {
            ctx->lr = 0x8018FEB4u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_8018FEB4:
    ctx->downcount -= 1;
    // 8018FEB4: bc    4, 18, 0x8018FC1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FC1Cu;
                return;
            }
            goto label_8018FC1C;
        }
    }

label_8018FEB8:
    ctx->pc = 0x8018FEB8u;
    ctx->downcount -= 7;
    // 8018FEB8: lwz     r6, 836(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(836);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8018FEBC:
    ctx->pc = 0x8018FEBCu;
    // 8018FEBC: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_8018FEC0:
    ctx->pc = 0x8018FEC0u;
    // 8018FEC0: lwz     r7, 824(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(824);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8018FEC4:
    ctx->pc = 0x8018FEC4u;
    // 8018FEC4: addi    r4, r1, 112
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(112);

label_8018FEC8:
    ctx->pc = 0x8018FEC8u;
    // 8018FEC8: addi    r5, r5, -16700
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-16700);

label_8018FECC:
    ctx->pc = 0x8018FECCu;
    // 8018FECC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018FED0:
    ctx->pc = 0x8018FED0u;
    // 8018FED0: bl      0x801B4568
    {
            ctx->lr = 0x8018FED4u;
            ctx->pc = 0x801B4568u;
            return;
    }

label_8018FED4:
    ctx->pc = 0x8018FED4u;
    ctx->downcount -= 2;
    // 8018FED4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018FED8:
    ctx->pc = 0x8018FED8u;
    // 8018FED8: bl      0x801907EC
    {
            ctx->lr = 0x8018FEDCu;
            goto label_801907EC;
    }

label_8018FEDC:
    ctx->pc = 0x8018FEDCu;
    ctx->downcount -= 2;
    // 8018FEDC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018FEE0:
    ctx->pc = 0x8018FEE0u;
    // 8018FEE0: bl      0x8019549C
    {
            ctx->lr = 0x8018FEE4u;
            ctx->pc = 0x8019549Cu;
            return;
    }

label_8018FEE4:
    ctx->pc = 0x8018FEE4u;
    ctx->downcount -= 3;
    // 8018FEE4: lwz     r3, 832(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(832);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018FEE8:
    ctx->pc = 0x8018FEE8u;
    // 8018FEE8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8018FEEC:
    ctx->pc = 0x8018FEECu;
    // 8018FEEC: bl      0x801CFEAC
    {
            ctx->lr = 0x8018FEF0u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_8018FEF0:
    ctx->pc = 0x8018FEF0u;
    ctx->downcount -= 3;
    // 8018FEF0: lwz     r3, 828(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(828);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018FEF4:
    ctx->pc = 0x8018FEF4u;
    // 8018FEF4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8018FEF8:
    ctx->pc = 0x8018FEF8u;
    // 8018FEF8: bl      0x801CFEAC
    {
            ctx->lr = 0x8018FEFCu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_8018FEFC:
    ctx->pc = 0x8018FEFCu;
    ctx->downcount -= 3;
    // 8018FEFC: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8018FF00:
    ctx->pc = 0x8018FF00u;
    // 8018FF00: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8018FF04:
    ctx->pc = 0x8018FF04u;
    // 8018FF04: bl      0x801CFEAC
    {
            ctx->lr = 0x8018FF08u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_8018FF08:
    ctx->pc = 0x8018FF08u;
    ctx->downcount -= 3;
    // 8018FF08: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8018FF0C:
    ctx->pc = 0x8018FF0Cu;
    // 8018FF0C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8018FF10:
    ctx->pc = 0x8018FF10u;
    // 8018FF10: bl      0x801CFEAC
    {
            ctx->lr = 0x8018FF14u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_8018FF14:
    ctx->pc = 0x8018FF14u;
    ctx->downcount -= 29;
    // 8018FF14: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018FF18:
    ctx->pc = 0x8018FF18u;
    // 8018FF18: lwz     r0, 1100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FF1C:
    ctx->pc = 0x8018FF1Cu;
    // 8018FF1C: lwz     r12, 940(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(940);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8018FF20:
    ctx->pc = 0x8018FF20u;
    // 8018FF20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018FF24:
    ctx->pc = 0x8018FF24u;
    // 8018FF24: lmw     r14, 944(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(944);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8018FF28:
    ctx->pc = 0x8018FF28u;
    // 8018FF28: lfd     f22, 1016(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1016);
        ctx->fpr[22] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF2C:
    ctx->pc = 0x8018FF2Cu;
    // 8018FF2C: lfd     f23, 1024(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1024);
        ctx->fpr[23] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF30:
    ctx->pc = 0x8018FF30u;
    // 8018FF30: lfd     f24, 1032(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1032);
        ctx->fpr[24] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF34:
    ctx->pc = 0x8018FF34u;
    // 8018FF34: lfd     f25, 1040(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1040);
        ctx->fpr[25] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF38:
    ctx->pc = 0x8018FF38u;
    // 8018FF38: lfd     f26, 1048(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1048);
        ctx->fpr[26] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF3C:
    ctx->pc = 0x8018FF3Cu;
    // 8018FF3C: lfd     f27, 1056(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1056);
        ctx->fpr[27] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF40:
    ctx->pc = 0x8018FF40u;
    // 8018FF40: lfd     f28, 1064(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF40u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1064);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF44:
    ctx->pc = 0x8018FF44u;
    // 8018FF44: lfd     f29, 1072(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF44u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1072);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF48:
    ctx->pc = 0x8018FF48u;
    // 8018FF48: lfd     f30, 1080(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF48u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1080);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF4C:
    ctx->pc = 0x8018FF4Cu;
    // 8018FF4C: lfd     f31, 1088(r1)
    if (!ppc_fp_available_inline(ctx, 0x8018FF4Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1088);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8018FF50:
    ctx->pc = 0x8018FF50u;
    // 8018FF50: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_8018FF54:
    ctx->pc = 0x8018FF54u;
    // 8018FF54: addi    r1, r1, 1096
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(1096);

label_8018FF58:
    ctx->pc = 0x8018FF58u;
    // 8018FF58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8018F4C0;
        }
    }

label_8018FF5C:
    ctx->pc = 0x8018FF5Cu;
    ctx->downcount -= 21;
    // 8018FF5C: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018FF60:
    ctx->pc = 0x8018FF60u;
    // 8018FF60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018FF64:
    ctx->pc = 0x8018FF64u;
    // 8018FF64: stmw     r16, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 16; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8018FF68:
    ctx->pc = 0x8018FF68u;
    // 8018FF68: stw     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018FF6C:
    ctx->pc = 0x8018FF6Cu;
    // 8018FF6C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018FF70:
    ctx->pc = 0x8018FF70u;
    // 8018FF70: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8018FF74:
    ctx->pc = 0x8018FF74u;
    // 8018FF74: addi    r9, r9, -11880
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-11880);

label_8018FF78:
    ctx->pc = 0x8018FF78u;
    // 8018FF78: lwz     r3, 1840(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1840);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018FF7C:
    ctx->pc = 0x8018FF7Cu;
    // 8018FF7C: stw     r9, 448(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(448);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8018FF80:
    ctx->pc = 0x8018FF80u;
    // 8018FF80: or   r16, r4, r4
    {
        ctx->gpr[16] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8018FF84:
    ctx->pc = 0x8018FF84u;
    // 8018FF84: bl      0x80281D80
    {
            ctx->lr = 0x8018FF88u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8018FF88:
    ctx->pc = 0x8018FF88u;
    ctx->downcount -= 5;
    // 8018FF88: addi    r9, r29, 1984
    ctx->gpr[9] = ctx->gpr[29] + (u32)(s32)(1984);

label_8018FF8C:
    ctx->pc = 0x8018FF8Cu;
    // 8018FF8C: lwz     r31, 1984(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1984);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018FF90:
    ctx->pc = 0x8018FF90u;
    // 8018FF90: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FF94:
    ctx->pc = 0x8018FF94u;
    // 8018FF94: cmpw    r31, r0
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

label_8018FF98:
    ctx->pc = 0x8018FF98u;
    // 8018FF98: bc    12, 2, 0x80190078
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190078;
        }
    }

label_8018FF9C:
    ctx->pc = 0x8018FF9Cu;
    ctx->downcount -= 4;
    // 8018FF9C: lis     r27, -3856
    ctx->gpr[27] = ((u32)(s32)(-3856) << 16);

label_8018FFA0:
    ctx->pc = 0x8018FFA0u;
    // 8018FFA0: or   r30, r9, r9
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8018FFA4:
    ctx->pc = 0x8018FFA4u;
    // 8018FFA4: addi    r28, r31, 136
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(136);

label_8018FFA8:
    ctx->pc = 0x8018FFA8u;
    // 8018FFA8: ori     r27, r27, 0xF0F1
    ctx->gpr[27] = ctx->gpr[27] | 0xF0F1u;

label_8018FFAC:
    ctx->pc = 0x8018FFACu;
    ctx->downcount -= 3;
    // 8018FFAC: lwz     r4, 132(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018FFB0:
    // 8018FFB0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8018FFB4:
    // 8018FFB4: bl      0x80190670
    {
            ctx->lr = 0x8018FFB8u;
            goto label_80190670;
    }

label_8018FFB8:
    ctx->pc = 0x8018FFB8u;
    ctx->downcount -= 3;
    // 8018FFB8: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018FFBC:
    // 8018FFBC: cmpw    r28, r0
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

label_8018FFC0:
    // 8018FFC0: bc    12, 2, 0x80190064
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190064;
        }
    }

label_8018FFC4:
    ctx->downcount -= 10;
    // 8018FFC4: or   r8, r28, r28
    {
        ctx->gpr[8] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8018FFC8:
    // 8018FFC8: or   r7, r31, r31
    {
        ctx->gpr[7] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018FFCC:
    // 8018FFCC: subf   r0, r8, r0
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8018FFD0:
    // 8018FFD0: mullw   r0, r0, r27
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[27];
        ctx->gpr[0] = (u32)product;
    }

label_8018FFD4:
    // 8018FFD4: srawi. r6, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[6] = value;
        } else if (sh > 31) {
            ctx->gpr[6] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[6] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018FFD8:
    // 8018FFD8: bc    4, 1, 0x80190064
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190064;
        }
    }

label_8018FFDC:
    ctx->downcount -= 6;
    // 8018FFDC: or   r10, r7, r7
    {
        ctx->gpr[10] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8018FFE0:
    // 8018FFE0: or   r11, r8, r8
    {
        ctx->gpr[11] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8018FFE4:
    // 8018FFE4: addi    r7, r11, 136
    ctx->gpr[7] = ctx->gpr[11] + (u32)(s32)(136);

label_8018FFE8:
    // 8018FFE8: addi    r5, r10, 136
    ctx->gpr[5] = ctx->gpr[10] + (u32)(s32)(136);

label_8018FFEC:
    // 8018FFEC: addi    r0, r6, -1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(-1);

label_8018FFF0:
    // 8018FFF0: li      r8, 120
    ctx->gpr[8] = (u32)(s32)(120);

label_8018FFF4:
    loop_8018FFF4(ctx);
    if (ctx->pc == 0x80190034u) goto label_80190034;
    return;
label_8018FFF8:
    // 8018FFF8: addic.  r8, r8, -24
    {
        u64 a = ctx->gpr[8];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018FFFC:
    ctx->pc = 0x8018FFFCu;
    // 8018FFFC: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190000:
    ctx->pc = 0x80190000u;
    // 80190000: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190004:
    ctx->pc = 0x80190004u;
    // 80190004: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190008:
    ctx->pc = 0x80190008u;
    // 80190008: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019000C:
    ctx->pc = 0x8019000Cu;
    // 8019000C: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190010:
    ctx->pc = 0x80190010u;
    // 80190010: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190014:
    ctx->pc = 0x80190014u;
    // 80190014: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190018:
    ctx->pc = 0x80190018u;
    // 80190018: lwz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019001C:
    ctx->pc = 0x8019001Cu;
    // 8019001C: stw     r9, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190020:
    ctx->pc = 0x80190020u;
    // 80190020: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190024:
    // 80190024: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

label_80190028:
    ctx->pc = 0x80190028u;
    // 80190028: stw     r9, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019002C:
    // 8019002C: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

label_80190030:
    // 80190030: bc    4, 2, 0x8018FFF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FFF4u;
                return;
            }
            goto label_8018FFF4;
        }
    }

label_80190034:
    ctx->pc = 0x80190034u;
    ctx->downcount -= 12;
    // 80190034: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190038:
    // 80190038: or   r8, r7, r7
    {
        ctx->gpr[8] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8019003C:
    // 8019003C: or   r7, r5, r5
    {
        ctx->gpr[7] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80190040:
    // 80190040: or.   r6, r0, r0
    {
        ctx->gpr[6] = ctx->gpr[0] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80190044:
    ctx->pc = 0x80190044u;
    // 80190044: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190048:
    ctx->pc = 0x80190048u;
    // 80190048: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019004C:
    ctx->pc = 0x8019004Cu;
    // 8019004C: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190050:
    ctx->pc = 0x80190050u;
    // 80190050: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190054:
    ctx->pc = 0x80190054u;
    // 80190054: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190058:
    ctx->pc = 0x80190058u;
    // 80190058: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019005C:
    ctx->pc = 0x8019005Cu;
    // 8019005C: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190060:
    // 80190060: bc    12, 1, 0x8018FFDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FFDCu;
                return;
            }
            goto label_8018FFDC;
        }
    }

label_80190064:
    ctx->pc = 0x80190064u;
    ctx->downcount -= 5;
    // 80190064: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190068:
    // 80190068: addi    r9, r9, -136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-136);

label_8019006C:
    // 8019006C: cmpw    r31, r9
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190070:
    ctx->pc = 0x80190070u;
    // 80190070: stw     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190074:
    // 80190074: bc    4, 2, 0x8018FFAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018FFACu;
                return;
            }
            goto label_8018FFAC;
        }
    }

label_80190078:
    ctx->pc = 0x80190078u;
    ctx->downcount -= 16;
    // 80190078: addi    r9, r29, 2000
    ctx->gpr[9] = ctx->gpr[29] + (u32)(s32)(2000);

label_8019007C:
    ctx->pc = 0x8019007Cu;
    // 8019007C: lwz     r31, 2000(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2000);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80190080:
    ctx->pc = 0x80190080u;
    // 80190080: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190084:
    ctx->pc = 0x80190084u;
    // 80190084: or   r26, r9, r9
    {
        ctx->gpr[26] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80190088:
    ctx->pc = 0x80190088u;
    // 80190088: addi    r23, r29, 1984
    ctx->gpr[23] = ctx->gpr[29] + (u32)(s32)(1984);

label_8019008C:
    ctx->pc = 0x8019008Cu;
    // 8019008C: addi    r27, r29, 2016
    ctx->gpr[27] = ctx->gpr[29] + (u32)(s32)(2016);

label_80190090:
    ctx->pc = 0x80190090u;
    // 80190090: cmpw    r31, r0
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

label_80190094:
    ctx->pc = 0x80190094u;
    // 80190094: addi    r24, r29, 1888
    ctx->gpr[24] = ctx->gpr[29] + (u32)(s32)(1888);

label_80190098:
    ctx->pc = 0x80190098u;
    // 80190098: addi    r25, r29, 1904
    ctx->gpr[25] = ctx->gpr[29] + (u32)(s32)(1904);

label_8019009C:
    ctx->pc = 0x8019009Cu;
    // 8019009C: addi    r22, r29, 1968
    ctx->gpr[22] = ctx->gpr[29] + (u32)(s32)(1968);

label_801900A0:
    ctx->pc = 0x801900A0u;
    // 801900A0: addi    r19, r29, 1936
    ctx->gpr[19] = ctx->gpr[29] + (u32)(s32)(1936);

label_801900A4:
    ctx->pc = 0x801900A4u;
    // 801900A4: addi    r18, r29, 1920
    ctx->gpr[18] = ctx->gpr[29] + (u32)(s32)(1920);

label_801900A8:
    ctx->pc = 0x801900A8u;
    // 801900A8: addi    r17, r29, 1872
    ctx->gpr[17] = ctx->gpr[29] + (u32)(s32)(1872);

label_801900AC:
    ctx->pc = 0x801900ACu;
    // 801900AC: addi    r20, r29, 1864
    ctx->gpr[20] = ctx->gpr[29] + (u32)(s32)(1864);

label_801900B0:
    ctx->pc = 0x801900B0u;
    // 801900B0: addi    r21, r29, 1664
    ctx->gpr[21] = ctx->gpr[29] + (u32)(s32)(1664);

label_801900B4:
    ctx->pc = 0x801900B4u;
    // 801900B4: bc    12, 2, 0x80190190
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190190;
        }
    }

label_801900B8:
    ctx->pc = 0x801900B8u;
    ctx->downcount -= 3;
    // 801900B8: lis     r28, -3856
    ctx->gpr[28] = ((u32)(s32)(-3856) << 16);

label_801900BC:
    ctx->pc = 0x801900BCu;
    // 801900BC: addi    r30, r31, 136
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(136);

label_801900C0:
    ctx->pc = 0x801900C0u;
    // 801900C0: ori     r28, r28, 0xF0F1
    ctx->gpr[28] = ctx->gpr[28] | 0xF0F1u;

label_801900C4:
    ctx->pc = 0x801900C4u;
    ctx->downcount -= 3;
    // 801900C4: lwz     r4, 132(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801900C8:
    // 801900C8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801900CC:
    // 801900CC: bl      0x80190670
    {
            ctx->lr = 0x801900D0u;
            goto label_80190670;
    }

label_801900D0:
    ctx->pc = 0x801900D0u;
    ctx->downcount -= 3;
    // 801900D0: lwz     r0, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801900D4:
    // 801900D4: cmpw    r30, r0
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

label_801900D8:
    // 801900D8: bc    12, 2, 0x8019017C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019017C;
        }
    }

label_801900DC:
    ctx->downcount -= 10;
    // 801900DC: or   r8, r30, r30
    {
        ctx->gpr[8] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801900E0:
    // 801900E0: or   r7, r31, r31
    {
        ctx->gpr[7] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801900E4:
    // 801900E4: subf   r0, r8, r0
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801900E8:
    // 801900E8: mullw   r0, r0, r28
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[28];
        ctx->gpr[0] = (u32)product;
    }

label_801900EC:
    // 801900EC: srawi. r6, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[6] = value;
        } else if (sh > 31) {
            ctx->gpr[6] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[6] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801900F0:
    // 801900F0: bc    4, 1, 0x8019017C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019017C;
        }
    }

label_801900F4:
    ctx->downcount -= 6;
    // 801900F4: or   r10, r7, r7
    {
        ctx->gpr[10] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801900F8:
    // 801900F8: or   r11, r8, r8
    {
        ctx->gpr[11] = ctx->gpr[8] | ctx->gpr[8];
    }

label_801900FC:
    // 801900FC: addi    r7, r11, 136
    ctx->gpr[7] = ctx->gpr[11] + (u32)(s32)(136);

label_80190100:
    // 80190100: addi    r5, r10, 136
    ctx->gpr[5] = ctx->gpr[10] + (u32)(s32)(136);

label_80190104:
    // 80190104: addi    r0, r6, -1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(-1);

label_80190108:
    // 80190108: li      r8, 120
    ctx->gpr[8] = (u32)(s32)(120);

label_8019010C:
    loop_8019010C(ctx);
    if (ctx->pc == 0x8019014Cu) goto label_8019014C;
    return;
label_80190110:
    // 80190110: addic.  r8, r8, -24
    {
        u64 a = ctx->gpr[8];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80190114:
    ctx->pc = 0x80190114u;
    // 80190114: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190118:
    ctx->pc = 0x80190118u;
    // 80190118: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019011C:
    ctx->pc = 0x8019011Cu;
    // 8019011C: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190120:
    ctx->pc = 0x80190120u;
    // 80190120: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190124:
    ctx->pc = 0x80190124u;
    // 80190124: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190128:
    ctx->pc = 0x80190128u;
    // 80190128: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019012C:
    ctx->pc = 0x8019012Cu;
    // 8019012C: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190130:
    ctx->pc = 0x80190130u;
    // 80190130: lwz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190134:
    ctx->pc = 0x80190134u;
    // 80190134: stw     r9, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190138:
    ctx->pc = 0x80190138u;
    // 80190138: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019013C:
    // 8019013C: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

label_80190140:
    ctx->pc = 0x80190140u;
    // 80190140: stw     r9, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190144:
    // 80190144: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

label_80190148:
    // 80190148: bc    4, 2, 0x8019010C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019010Cu;
                return;
            }
            goto label_8019010C;
        }
    }

label_8019014C:
    ctx->pc = 0x8019014Cu;
    ctx->downcount -= 12;
    // 8019014C: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190150:
    // 80190150: or   r8, r7, r7
    {
        ctx->gpr[8] = ctx->gpr[7] | ctx->gpr[7];
    }

label_80190154:
    // 80190154: or   r7, r5, r5
    {
        ctx->gpr[7] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80190158:
    // 80190158: or.   r6, r0, r0
    {
        ctx->gpr[6] = ctx->gpr[0] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019015C:
    ctx->pc = 0x8019015Cu;
    // 8019015C: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190160:
    ctx->pc = 0x80190160u;
    // 80190160: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190164:
    ctx->pc = 0x80190164u;
    // 80190164: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190168:
    ctx->pc = 0x80190168u;
    // 80190168: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019016C:
    ctx->pc = 0x8019016Cu;
    // 8019016C: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190170:
    ctx->pc = 0x80190170u;
    // 80190170: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190174:
    ctx->pc = 0x80190174u;
    // 80190174: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190178:
    // 80190178: bc    12, 1, 0x801900F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801900F4u;
                return;
            }
            goto label_801900F4;
        }
    }

label_8019017C:
    ctx->pc = 0x8019017Cu;
    ctx->downcount -= 5;
    // 8019017C: lwz     r9, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190180:
    // 80190180: addi    r9, r9, -136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-136);

label_80190184:
    // 80190184: cmpw    r31, r9
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190188:
    ctx->pc = 0x80190188u;
    // 80190188: stw     r9, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019018C:
    // 8019018C: bc    4, 2, 0x801900C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801900C4u;
                return;
            }
            goto label_801900C4;
        }
    }

label_80190190:
    ctx->pc = 0x80190190u;
    ctx->downcount -= 4;
    // 80190190: lwz     r31, 2016(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2016);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80190194:
    ctx->pc = 0x80190194u;
    // 80190194: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190198:
    ctx->pc = 0x80190198u;
    // 80190198: cmpw    r31, r0
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

label_8019019C:
    ctx->pc = 0x8019019Cu;
    // 8019019C: bc    12, 2, 0x80190278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190278;
        }
    }

label_801901A0:
    ctx->pc = 0x801901A0u;
    ctx->downcount -= 3;
    // 801901A0: lis     r28, -3856
    ctx->gpr[28] = ((u32)(s32)(-3856) << 16);

label_801901A4:
    ctx->pc = 0x801901A4u;
    // 801901A4: addi    r30, r31, 136
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(136);

label_801901A8:
    ctx->pc = 0x801901A8u;
    // 801901A8: ori     r28, r28, 0xF0F1
    ctx->gpr[28] = ctx->gpr[28] | 0xF0F1u;

label_801901AC:
    ctx->pc = 0x801901ACu;
    ctx->downcount -= 3;
    // 801901AC: lwz     r4, 132(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801901B0:
    // 801901B0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801901B4:
    // 801901B4: bl      0x80190670
    {
            ctx->lr = 0x801901B8u;
            goto label_80190670;
    }

label_801901B8:
    ctx->pc = 0x801901B8u;
    ctx->downcount -= 3;
    // 801901B8: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801901BC:
    // 801901BC: cmpw    r30, r0
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

label_801901C0:
    // 801901C0: bc    12, 2, 0x80190264
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190264;
        }
    }

label_801901C4:
    ctx->downcount -= 10;
    // 801901C4: or   r8, r30, r30
    {
        ctx->gpr[8] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801901C8:
    // 801901C8: or   r7, r31, r31
    {
        ctx->gpr[7] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801901CC:
    // 801901CC: subf   r0, r8, r0
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801901D0:
    // 801901D0: mullw   r0, r0, r28
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[28];
        ctx->gpr[0] = (u32)product;
    }

label_801901D4:
    // 801901D4: srawi. r6, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[6] = value;
        } else if (sh > 31) {
            ctx->gpr[6] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[6] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801901D8:
    // 801901D8: bc    4, 1, 0x80190264
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190264;
        }
    }

label_801901DC:
    ctx->downcount -= 6;
    // 801901DC: or   r10, r7, r7
    {
        ctx->gpr[10] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801901E0:
    // 801901E0: or   r11, r8, r8
    {
        ctx->gpr[11] = ctx->gpr[8] | ctx->gpr[8];
    }

label_801901E4:
    // 801901E4: addi    r7, r11, 136
    ctx->gpr[7] = ctx->gpr[11] + (u32)(s32)(136);

label_801901E8:
    // 801901E8: addi    r5, r10, 136
    ctx->gpr[5] = ctx->gpr[10] + (u32)(s32)(136);

label_801901EC:
    // 801901EC: addi    r0, r6, -1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(-1);

label_801901F0:
    // 801901F0: li      r8, 120
    ctx->gpr[8] = (u32)(s32)(120);

label_801901F4:
    loop_801901F4(ctx);
    if (ctx->pc == 0x80190234u) goto label_80190234;
    return;
label_801901F8:
    // 801901F8: addic.  r8, r8, -24
    {
        u64 a = ctx->gpr[8];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801901FC:
    ctx->pc = 0x801901FCu;
    // 801901FC: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190200:
    ctx->pc = 0x80190200u;
    // 80190200: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190204:
    ctx->pc = 0x80190204u;
    // 80190204: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190208:
    ctx->pc = 0x80190208u;
    // 80190208: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019020C:
    ctx->pc = 0x8019020Cu;
    // 8019020C: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190210:
    ctx->pc = 0x80190210u;
    // 80190210: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190214:
    ctx->pc = 0x80190214u;
    // 80190214: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190218:
    ctx->pc = 0x80190218u;
    // 80190218: lwz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019021C:
    ctx->pc = 0x8019021Cu;
    // 8019021C: stw     r9, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190220:
    ctx->pc = 0x80190220u;
    // 80190220: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190224:
    // 80190224: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

label_80190228:
    ctx->pc = 0x80190228u;
    // 80190228: stw     r9, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019022C:
    // 8019022C: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

label_80190230:
    // 80190230: bc    4, 2, 0x801901F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801901F4u;
                return;
            }
            goto label_801901F4;
        }
    }

label_80190234:
    ctx->pc = 0x80190234u;
    ctx->downcount -= 12;
    // 80190234: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190238:
    // 80190238: or   r8, r7, r7
    {
        ctx->gpr[8] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8019023C:
    // 8019023C: or   r7, r5, r5
    {
        ctx->gpr[7] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80190240:
    // 80190240: or.   r6, r0, r0
    {
        ctx->gpr[6] = ctx->gpr[0] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80190244:
    ctx->pc = 0x80190244u;
    // 80190244: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190248:
    ctx->pc = 0x80190248u;
    // 80190248: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019024C:
    ctx->pc = 0x8019024Cu;
    // 8019024C: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190250:
    ctx->pc = 0x80190250u;
    // 80190250: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190254:
    ctx->pc = 0x80190254u;
    // 80190254: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190258:
    ctx->pc = 0x80190258u;
    // 80190258: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019025C:
    ctx->pc = 0x8019025Cu;
    // 8019025C: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190260:
    // 80190260: bc    12, 1, 0x801901DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801901DCu;
                return;
            }
            goto label_801901DC;
        }
    }

label_80190264:
    ctx->pc = 0x80190264u;
    ctx->downcount -= 5;
    // 80190264: lwz     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190268:
    // 80190268: addi    r9, r9, -136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-136);

label_8019026C:
    // 8019026C: cmpw    r31, r9
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190270:
    ctx->pc = 0x80190270u;
    // 80190270: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190274:
    // 80190274: bc    4, 2, 0x801901AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801901ACu;
                return;
            }
            goto label_801901AC;
        }
    }

label_80190278:
    ctx->pc = 0x80190278u;
    ctx->downcount -= 4;
    // 80190278: lwz     r31, 1888(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1888);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8019027C:
    ctx->pc = 0x8019027Cu;
    // 8019027C: lwz     r0, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190280:
    ctx->pc = 0x80190280u;
    // 80190280: cmpw    r31, r0
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

label_80190284:
    ctx->pc = 0x80190284u;
    // 80190284: bc    12, 2, 0x801902D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801902D4;
        }
    }

label_80190288:
    ctx->pc = 0x80190288u;
    ctx->downcount -= 3;
    // 80190288: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019028C:
    // 8019028C: cmpwi   r3, 0
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

label_80190290:
    // 80190290: bc    12, 2, 0x8019029C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019029C;
        }
    }

label_80190294:
    ctx->downcount -= 2;
    // 80190294: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80190298:
    // 80190298: bl      0x8018E564
    {
            ctx->lr = 0x8019029Cu;
            ctx->pc = 0x8018E564u;
            return;
    }

label_8019029C:
    ctx->pc = 0x8019029Cu;
    ctx->downcount -= 4;
    // 8019029C: lwz     r5, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801902A0:
    // 801902A0: addi    r4, r31, 4
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(4);

label_801902A4:
    // 801902A4: cmpw    r4, r5
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

label_801902A8:
    // 801902A8: bc    12, 2, 0x801902C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801902C0;
        }
    }

label_801902AC:
    ctx->downcount -= 2;
    // 801902AC: cmpw    r5, r4
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

label_801902B0:
    // 801902B0: bc    12, 2, 0x801902C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801902C0;
        }
    }

label_801902B4:
    ctx->downcount -= 3;
    // 801902B4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801902B8:
    // 801902B8: subf   r5, r4, r5
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_801902BC:
    // 801902BC: bl      0x80297E3C
    {
            ctx->lr = 0x801902C0u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_801902C0:
    ctx->pc = 0x801902C0u;
    ctx->downcount -= 5;
    // 801902C0: lwz     r9, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801902C4:
    // 801902C4: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_801902C8:
    // 801902C8: cmpw    r31, r9
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801902CC:
    ctx->pc = 0x801902CCu;
    // 801902CC: stw     r9, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801902D0:
    // 801902D0: bc    4, 2, 0x80190288
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190288u;
                return;
            }
            goto label_80190288;
        }
    }

label_801902D4:
    ctx->pc = 0x801902D4u;
    ctx->downcount -= 4;
    // 801902D4: lwz     r30, 1904(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1904);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801902D8:
    ctx->pc = 0x801902D8u;
    // 801902D8: lwz     r0, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801902DC:
    ctx->pc = 0x801902DCu;
    // 801902DC: cmpw    r30, r0
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

label_801902E0:
    ctx->pc = 0x801902E0u;
    // 801902E0: bc    12, 2, 0x80190398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190398;
        }
    }

label_801902E4:
    ctx->pc = 0x801902E4u;
    ctx->downcount -= 1;
    // 801902E4: lis     r28, -32720
    ctx->gpr[28] = ((u32)(s32)(-32720) << 16);

label_801902E8:
    ctx->pc = 0x801902E8u;
    ctx->downcount -= 4;
    // 801902E8: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801902EC:
    // 801902EC: addi    r31, r30, 4
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(4);

label_801902F0:
    // 801902F0: cmpwi   r3, 0
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

label_801902F4:
    // 801902F4: bc    12, 2, 0x80190360
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190360;
        }
    }

label_801902F8:
    ctx->downcount -= 9;
    // 801902F8: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_801902FC:
    // 801902FC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190300:
    ctx->pc = 0x80190300u;
    // 80190300: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80190304:
    ctx->pc = 0x80190304u;
    // 80190304: lfs     f0, -16596(r28)
    if (!ppc_fp_available_inline(ctx, 0x80190304u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(-16596);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80190308:
    ctx->pc = 0x80190308u;
    // 80190308: lfs     f13, -16592(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190308u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16592);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8019030C:
    // 8019030C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80190310:
    // 80190310: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80190314:
    // 80190314: addi    r11, r3, 96
    ctx->gpr[11] = ctx->gpr[3] + (u32)(s32)(96);

label_80190318:
    ctx->pc = 0x80190318u;
    ctx->downcount -= 17;
    // 80190318: stfs     f0, 8(r11)
    if (!ppc_fp_available_inline(ctx, 0x80190318u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019031C:
    ctx->pc = 0x8019031Cu;
    // 8019031C: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x8019031Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80190320:
    ctx->pc = 0x80190320u;
    // 80190320: stfs     f13, 20(r11)
    if (!ppc_fp_available_inline(ctx, 0x80190320u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80190324:
    ctx->pc = 0x80190324u;
    // 80190324: stfs     f0, 24(r11)
    if (!ppc_fp_available_inline(ctx, 0x80190324u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80190328:
    ctx->pc = 0x80190328u;
    // 80190328: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x80190328u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019032C:
    ctx->pc = 0x8019032Cu;
    // 8019032C: stfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019032Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80190330:
    ctx->pc = 0x80190330u;
    // 80190330: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190334:
    ctx->pc = 0x80190334u;
    // 80190334: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190338:
    ctx->pc = 0x80190338u;
    // 80190338: stw     r0, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019033C:
    ctx->pc = 0x8019033Cu;
    // 8019033C: stw     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190340:
    ctx->pc = 0x80190340u;
    // 80190340: stw     r0, 36(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80190344:
    ctx->pc = 0x80190344u;
    // 80190344: stw     r9, 40(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190348:
    ctx->pc = 0x80190348u;
    // 80190348: stw     r10, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8019034C:
    ctx->pc = 0x8019034Cu;
    // 8019034C: stw     r10, 48(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80190350:
    ctx->pc = 0x80190350u;
    // 80190350: stw     r8, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80190354:
    // 80190354: addi    r11, r11, 120
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(120);

label_80190358:
    // 80190358: bc    16, 0, 0x80190318
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190318u;
                return;
            }
            goto label_80190318;
        }
    }

label_8019035C:
    ctx->downcount -= 1;
    // 8019035C: bl      0x80281D80
    {
            ctx->lr = 0x80190360u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80190360:
    ctx->pc = 0x80190360u;
    ctx->downcount -= 3;
    // 80190360: lwz     r5, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80190364:
    // 80190364: cmpw    r31, r5
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190368:
    // 80190368: bc    12, 2, 0x80190384
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190384;
        }
    }

label_8019036C:
    ctx->downcount -= 2;
    // 8019036C: cmpw    r5, r31
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190370:
    // 80190370: bc    12, 2, 0x80190384
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190384;
        }
    }

label_80190374:
    ctx->downcount -= 4;
    // 80190374: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80190378:
    // 80190378: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019037C:
    // 8019037C: subf   r5, r4, r5
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80190380:
    // 80190380: bl      0x80297E3C
    {
            ctx->lr = 0x80190384u;
            ctx->pc = 0x80297E3Cu;
            return;
    }

label_80190384:
    ctx->pc = 0x80190384u;
    ctx->downcount -= 5;
    // 80190384: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190388:
    // 80190388: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_8019038C:
    // 8019038C: cmpw    r30, r9
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190390:
    ctx->pc = 0x80190390u;
    // 80190390: stw     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190394:
    // 80190394: bc    4, 2, 0x801902E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801902E8u;
                return;
            }
            goto label_801902E8;
        }
    }

label_80190398:
    ctx->pc = 0x80190398u;
    ctx->downcount -= 4;
    // 80190398: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019039C:
    ctx->pc = 0x8019039Cu;
    // 8019039C: lwz     r9, 2016(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2016);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801903A0:
    ctx->pc = 0x801903A0u;
    // 801903A0: cmpw    r9, r0
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

label_801903A4:
    ctx->pc = 0x801903A4u;
    // 801903A4: bc    12, 2, 0x801903B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801903B4;
        }
    }

label_801903A8:
    loop_801903A8(ctx);
    if (ctx->pc == 0x801903B4u) goto label_801903B4;
    return;
label_801903AC:
    // 801903AC: cmpw    r9, r0
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

label_801903B0:
    // 801903B0: bc    4, 2, 0x801903A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801903A8u;
                return;
            }
            goto label_801903A8;
        }
    }

label_801903B4:
    ctx->pc = 0x801903B4u;
    ctx->downcount -= 3;
    // 801903B4: lwz     r3, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801903B8:
    ctx->pc = 0x801903B8u;
    // 801903B8: cmpwi   r3, 0
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

label_801903BC:
    ctx->pc = 0x801903BCu;
    // 801903BC: bc    12, 2, 0x801903F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801903F0;
        }
    }

label_801903C0:
    ctx->pc = 0x801903C0u;
    ctx->downcount -= 15;
    // 801903C0: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801903C4:
    ctx->pc = 0x801903C4u;
    // 801903C4: lis     r9, -3856
    ctx->gpr[9] = ((u32)(s32)(-3856) << 16);

label_801903C8:
    ctx->pc = 0x801903C8u;
    // 801903C8: ori     r9, r9, 0xF0F1
    ctx->gpr[9] = ctx->gpr[9] | 0xF0F1u;

label_801903CC:
    ctx->pc = 0x801903CCu;
    // 801903CC: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801903D0:
    ctx->pc = 0x801903D0u;
    // 801903D0: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_801903D4:
    ctx->pc = 0x801903D4u;
    // 801903D4: srawi r0, r0, 3
    {
        u32 sh = 3u;
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

label_801903D8:
    ctx->pc = 0x801903D8u;
    // 801903D8: mulli   r4, r0, 136
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)136);

label_801903DC:
    ctx->pc = 0x801903DCu;
    // 801903DC: cmplwi  r4, 0x0080
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

label_801903E0:
    ctx->pc = 0x801903E0u;
    // 801903E0: bc    4, 1, 0x801903EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801903EC;
        }
    }

label_801903E4:
    ctx->pc = 0x801903E4u;
    ctx->downcount -= 1;
    // 801903E4: bl      0x80281D80
    {
            ctx->lr = 0x801903E8u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801903E8:
    ctx->pc = 0x801903E8u;
    ctx->downcount -= 1;
    // 801903E8: b       0x801903F0
    {
            goto label_801903F0;
    }

label_801903EC:
    ctx->pc = 0x801903ECu;
    ctx->downcount -= 1;
    // 801903EC: bl      0x8001D934
    {
            ctx->lr = 0x801903F0u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801903F0:
    ctx->pc = 0x801903F0u;
    ctx->downcount -= 4;
    // 801903F0: lwz     r0, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801903F4:
    ctx->pc = 0x801903F4u;
    // 801903F4: lwz     r9, 2000(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2000);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801903F8:
    ctx->pc = 0x801903F8u;
    // 801903F8: cmpw    r9, r0
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

label_801903FC:
    ctx->pc = 0x801903FCu;
    // 801903FC: bc    12, 2, 0x8019040C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019040C;
        }
    }

label_80190400:
    loop_80190400(ctx);
    if (ctx->pc == 0x8019040Cu) goto label_8019040C;
    return;
label_80190404:
    // 80190404: cmpw    r9, r0
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

label_80190408:
    // 80190408: bc    4, 2, 0x80190400
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190400u;
                return;
            }
            goto label_80190400;
        }
    }

label_8019040C:
    ctx->pc = 0x8019040Cu;
    ctx->downcount -= 3;
    // 8019040C: lwz     r3, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190410:
    ctx->pc = 0x80190410u;
    // 80190410: cmpwi   r3, 0
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

label_80190414:
    ctx->pc = 0x80190414u;
    // 80190414: bc    12, 2, 0x80190448
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190448;
        }
    }

label_80190418:
    ctx->pc = 0x80190418u;
    ctx->downcount -= 15;
    // 80190418: lwz     r0, 12(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019041C:
    ctx->pc = 0x8019041Cu;
    // 8019041C: lis     r9, -3856
    ctx->gpr[9] = ((u32)(s32)(-3856) << 16);

label_80190420:
    ctx->pc = 0x80190420u;
    // 80190420: ori     r9, r9, 0xF0F1
    ctx->gpr[9] = ctx->gpr[9] | 0xF0F1u;

label_80190424:
    ctx->pc = 0x80190424u;
    // 80190424: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80190428:
    ctx->pc = 0x80190428u;
    // 80190428: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_8019042C:
    ctx->pc = 0x8019042Cu;
    // 8019042C: srawi r0, r0, 3
    {
        u32 sh = 3u;
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

label_80190430:
    ctx->pc = 0x80190430u;
    // 80190430: mulli   r4, r0, 136
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)136);

label_80190434:
    ctx->pc = 0x80190434u;
    // 80190434: cmplwi  r4, 0x0080
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

label_80190438:
    ctx->pc = 0x80190438u;
    // 80190438: bc    4, 1, 0x80190444
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190444;
        }
    }

label_8019043C:
    ctx->pc = 0x8019043Cu;
    ctx->downcount -= 1;
    // 8019043C: bl      0x80281D80
    {
            ctx->lr = 0x80190440u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80190440:
    ctx->pc = 0x80190440u;
    ctx->downcount -= 1;
    // 80190440: b       0x80190448
    {
            goto label_80190448;
    }

label_80190444:
    ctx->pc = 0x80190444u;
    ctx->downcount -= 1;
    // 80190444: bl      0x8001D934
    {
            ctx->lr = 0x80190448u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80190448:
    ctx->pc = 0x80190448u;
    ctx->downcount -= 4;
    // 80190448: lwz     r0, 4(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019044C:
    ctx->pc = 0x8019044Cu;
    // 8019044C: lwz     r9, 1984(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1984);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190450:
    ctx->pc = 0x80190450u;
    // 80190450: cmpw    r9, r0
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

label_80190454:
    ctx->pc = 0x80190454u;
    // 80190454: bc    12, 2, 0x80190464
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190464;
        }
    }

label_80190458:
    loop_80190458(ctx);
    if (ctx->pc == 0x80190464u) goto label_80190464;
    return;
label_8019045C:
    // 8019045C: cmpw    r9, r0
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

label_80190460:
    // 80190460: bc    4, 2, 0x80190458
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190458u;
                return;
            }
            goto label_80190458;
        }
    }

label_80190464:
    ctx->pc = 0x80190464u;
    ctx->downcount -= 3;
    // 80190464: lwz     r3, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190468:
    ctx->pc = 0x80190468u;
    // 80190468: cmpwi   r3, 0
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

label_8019046C:
    ctx->pc = 0x8019046Cu;
    // 8019046C: bc    12, 2, 0x801904A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801904A0;
        }
    }

label_80190470:
    ctx->pc = 0x80190470u;
    ctx->downcount -= 15;
    // 80190470: lwz     r0, 12(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190474:
    ctx->pc = 0x80190474u;
    // 80190474: lis     r9, -3856
    ctx->gpr[9] = ((u32)(s32)(-3856) << 16);

label_80190478:
    ctx->pc = 0x80190478u;
    // 80190478: ori     r9, r9, 0xF0F1
    ctx->gpr[9] = ctx->gpr[9] | 0xF0F1u;

label_8019047C:
    ctx->pc = 0x8019047Cu;
    // 8019047C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80190480:
    ctx->pc = 0x80190480u;
    // 80190480: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_80190484:
    ctx->pc = 0x80190484u;
    // 80190484: srawi r0, r0, 3
    {
        u32 sh = 3u;
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

label_80190488:
    ctx->pc = 0x80190488u;
    // 80190488: mulli   r4, r0, 136
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)136);

label_8019048C:
    ctx->pc = 0x8019048Cu;
    // 8019048C: cmplwi  r4, 0x0080
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

label_80190490:
    ctx->pc = 0x80190490u;
    // 80190490: bc    4, 1, 0x8019049C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019049C;
        }
    }

label_80190494:
    ctx->pc = 0x80190494u;
    ctx->downcount -= 1;
    // 80190494: bl      0x80281D80
    {
            ctx->lr = 0x80190498u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80190498:
    ctx->pc = 0x80190498u;
    ctx->downcount -= 1;
    // 80190498: b       0x801904A0
    {
            goto label_801904A0;
    }

label_8019049C:
    ctx->pc = 0x8019049Cu;
    ctx->downcount -= 1;
    // 8019049C: bl      0x8001D934
    {
            ctx->lr = 0x801904A0u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801904A0:
    ctx->pc = 0x801904A0u;
    ctx->downcount -= 4;
    // 801904A0: lwz     r0, 4(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801904A4:
    ctx->pc = 0x801904A4u;
    // 801904A4: lwz     r9, 1968(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1968);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801904A8:
    ctx->pc = 0x801904A8u;
    // 801904A8: cmpw    r9, r0
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

label_801904AC:
    ctx->pc = 0x801904ACu;
    // 801904AC: bc    12, 2, 0x801904BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801904BC;
        }
    }

label_801904B0:
    loop_801904B0(ctx);
    if (ctx->pc == 0x801904BCu) goto label_801904BC;
    return;
label_801904B4:
    // 801904B4: cmpw    r9, r0
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

label_801904B8:
    // 801904B8: bc    4, 2, 0x801904B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801904B0u;
                return;
            }
            goto label_801904B0;
        }
    }

label_801904BC:
    ctx->pc = 0x801904BCu;
    ctx->downcount -= 3;
    // 801904BC: lwz     r3, 0(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801904C0:
    ctx->pc = 0x801904C0u;
    // 801904C0: cmpwi   r3, 0
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

label_801904C4:
    ctx->pc = 0x801904C4u;
    // 801904C4: bc    12, 2, 0x801904F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801904F8;
        }
    }

label_801904C8:
    ctx->pc = 0x801904C8u;
    ctx->downcount -= 15;
    // 801904C8: lwz     r0, 12(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801904CC:
    ctx->pc = 0x801904CCu;
    // 801904CC: lis     r9, 29950
    ctx->gpr[9] = ((u32)(s32)(29950) << 16);

label_801904D0:
    ctx->pc = 0x801904D0u;
    // 801904D0: ori     r9, r9, 0xD775
    ctx->gpr[9] = ctx->gpr[9] | 0xD775u;

label_801904D4:
    ctx->pc = 0x801904D4u;
    // 801904D4: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801904D8:
    ctx->pc = 0x801904D8u;
    // 801904D8: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_801904DC:
    ctx->pc = 0x801904DCu;
    // 801904DC: srawi r0, r0, 2
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

label_801904E0:
    ctx->pc = 0x801904E0u;
    // 801904E0: mulli   r4, r0, 884
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)884);

label_801904E4:
    ctx->pc = 0x801904E4u;
    // 801904E4: cmplwi  r4, 0x0080
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

label_801904E8:
    ctx->pc = 0x801904E8u;
    // 801904E8: bc    4, 1, 0x801904F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801904F4;
        }
    }

label_801904EC:
    ctx->pc = 0x801904ECu;
    ctx->downcount -= 1;
    // 801904EC: bl      0x80281D80
    {
            ctx->lr = 0x801904F0u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801904F0:
    ctx->pc = 0x801904F0u;
    ctx->downcount -= 1;
    // 801904F0: b       0x801904F8
    {
            goto label_801904F8;
    }

label_801904F4:
    ctx->pc = 0x801904F4u;
    ctx->downcount -= 1;
    // 801904F4: bl      0x8001D934
    {
            ctx->lr = 0x801904F8u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801904F8:
    ctx->pc = 0x801904F8u;
    ctx->downcount -= 3;
    // 801904F8: lwz     r3, 1936(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1936);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801904FC:
    ctx->pc = 0x801904FCu;
    // 801904FC: cmpwi   r3, 0
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

label_80190500:
    ctx->pc = 0x80190500u;
    // 80190500: bc    12, 2, 0x80190524
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190524;
        }
    }

label_80190504:
    ctx->pc = 0x80190504u;
    ctx->downcount -= 5;
    // 80190504: lwz     r0, 12(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190508:
    ctx->pc = 0x80190508u;
    // 80190508: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8019050C:
    ctx->pc = 0x8019050Cu;
    // 8019050C: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80190510:
    ctx->pc = 0x80190510u;
    // 80190510: cmplwi  r4, 0x0080
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

label_80190514:
    ctx->pc = 0x80190514u;
    // 80190514: bc    4, 1, 0x80190520
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190520;
        }
    }

label_80190518:
    ctx->pc = 0x80190518u;
    ctx->downcount -= 1;
    // 80190518: bl      0x80281D80
    {
            ctx->lr = 0x8019051Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_8019051C:
    ctx->pc = 0x8019051Cu;
    ctx->downcount -= 1;
    // 8019051C: b       0x80190524
    {
            goto label_80190524;
    }

label_80190520:
    ctx->pc = 0x80190520u;
    ctx->downcount -= 1;
    // 80190520: bl      0x8001D934
    {
            ctx->lr = 0x80190524u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80190524:
    ctx->pc = 0x80190524u;
    ctx->downcount -= 3;
    // 80190524: lwz     r3, 1920(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1920);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190528:
    ctx->pc = 0x80190528u;
    // 80190528: cmpwi   r3, 0
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

label_8019052C:
    ctx->pc = 0x8019052Cu;
    // 8019052C: bc    12, 2, 0x80190550
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190550;
        }
    }

label_80190530:
    ctx->pc = 0x80190530u;
    ctx->downcount -= 5;
    // 80190530: lwz     r0, 12(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190534:
    ctx->pc = 0x80190534u;
    // 80190534: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80190538:
    ctx->pc = 0x80190538u;
    // 80190538: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_8019053C:
    ctx->pc = 0x8019053Cu;
    // 8019053C: cmplwi  r4, 0x0080
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

label_80190540:
    ctx->pc = 0x80190540u;
    // 80190540: bc    4, 1, 0x8019054C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019054C;
        }
    }

label_80190544:
    ctx->pc = 0x80190544u;
    ctx->downcount -= 1;
    // 80190544: bl      0x80281D80
    {
            ctx->lr = 0x80190548u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80190548:
    ctx->pc = 0x80190548u;
    ctx->downcount -= 1;
    // 80190548: b       0x80190550
    {
            goto label_80190550;
    }

label_8019054C:
    ctx->pc = 0x8019054Cu;
    ctx->downcount -= 1;
    // 8019054C: bl      0x8001D934
    {
            ctx->lr = 0x80190550u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80190550:
    ctx->pc = 0x80190550u;
    ctx->downcount -= 3;
    // 80190550: lwz     r3, 1904(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1904);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190554:
    ctx->pc = 0x80190554u;
    // 80190554: cmpwi   r3, 0
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

label_80190558:
    ctx->pc = 0x80190558u;
    // 80190558: bc    12, 2, 0x8019057C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019057C;
        }
    }

label_8019055C:
    ctx->pc = 0x8019055Cu;
    ctx->downcount -= 5;
    // 8019055C: lwz     r0, 12(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190560:
    ctx->pc = 0x80190560u;
    // 80190560: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80190564:
    ctx->pc = 0x80190564u;
    // 80190564: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80190568:
    ctx->pc = 0x80190568u;
    // 80190568: cmplwi  r4, 0x0080
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

label_8019056C:
    ctx->pc = 0x8019056Cu;
    // 8019056C: bc    4, 1, 0x80190578
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190578;
        }
    }

label_80190570:
    ctx->pc = 0x80190570u;
    ctx->downcount -= 1;
    // 80190570: bl      0x80281D80
    {
            ctx->lr = 0x80190574u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80190574:
    ctx->pc = 0x80190574u;
    ctx->downcount -= 1;
    // 80190574: b       0x8019057C
    {
            goto label_8019057C;
    }

label_80190578:
    ctx->pc = 0x80190578u;
    ctx->downcount -= 1;
    // 80190578: bl      0x8001D934
    {
            ctx->lr = 0x8019057Cu;
            ctx->pc = 0x8001D934u;
            return;
    }

label_8019057C:
    ctx->pc = 0x8019057Cu;
    ctx->downcount -= 3;
    // 8019057C: lwz     r3, 1888(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1888);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190580:
    ctx->pc = 0x80190580u;
    // 80190580: cmpwi   r3, 0
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

label_80190584:
    ctx->pc = 0x80190584u;
    // 80190584: bc    12, 2, 0x801905A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801905A8;
        }
    }

label_80190588:
    ctx->pc = 0x80190588u;
    ctx->downcount -= 5;
    // 80190588: lwz     r0, 12(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019058C:
    ctx->pc = 0x8019058Cu;
    // 8019058C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80190590:
    ctx->pc = 0x80190590u;
    // 80190590: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80190594:
    ctx->pc = 0x80190594u;
    // 80190594: cmplwi  r4, 0x0080
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

label_80190598:
    ctx->pc = 0x80190598u;
    // 80190598: bc    4, 1, 0x801905A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801905A4;
        }
    }

label_8019059C:
    ctx->pc = 0x8019059Cu;
    ctx->downcount -= 1;
    // 8019059C: bl      0x80281D80
    {
            ctx->lr = 0x801905A0u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801905A0:
    ctx->pc = 0x801905A0u;
    ctx->downcount -= 1;
    // 801905A0: b       0x801905A8
    {
            goto label_801905A8;
    }

label_801905A4:
    ctx->pc = 0x801905A4u;
    ctx->downcount -= 1;
    // 801905A4: bl      0x8001D934
    {
            ctx->lr = 0x801905A8u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801905A8:
    ctx->pc = 0x801905A8u;
    ctx->downcount -= 3;
    // 801905A8: lwz     r3, 1872(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1872);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801905AC:
    ctx->pc = 0x801905ACu;
    // 801905AC: cmpwi   r3, 0
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

label_801905B0:
    ctx->pc = 0x801905B0u;
    // 801905B0: bc    12, 2, 0x801905D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801905D4;
        }
    }

label_801905B4:
    ctx->pc = 0x801905B4u;
    ctx->downcount -= 5;
    // 801905B4: lwz     r0, 12(r17)
    {
        u32 ea = ctx->gpr[17] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801905B8:
    ctx->pc = 0x801905B8u;
    // 801905B8: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801905BC:
    ctx->pc = 0x801905BCu;
    // 801905BC: rlwinm r4, r0, 0, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_801905C0:
    ctx->pc = 0x801905C0u;
    // 801905C0: cmplwi  r4, 0x0080
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

label_801905C4:
    ctx->pc = 0x801905C4u;
    // 801905C4: bc    4, 1, 0x801905D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801905D0;
        }
    }

label_801905C8:
    ctx->pc = 0x801905C8u;
    ctx->downcount -= 1;
    // 801905C8: bl      0x80281D80
    {
            ctx->lr = 0x801905CCu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801905CC:
    ctx->pc = 0x801905CCu;
    ctx->downcount -= 1;
    // 801905CC: b       0x801905D4
    {
            goto label_801905D4;
    }

label_801905D0:
    ctx->pc = 0x801905D0u;
    ctx->downcount -= 1;
    // 801905D0: bl      0x8001D934
    {
            ctx->lr = 0x801905D4u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801905D4:
    ctx->pc = 0x801905D4u;
    ctx->downcount -= 2;
    // 801905D4: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_801905D8:
    ctx->pc = 0x801905D8u;
    // 801905D8: bl      0x801986F0
    {
            ctx->lr = 0x801905DCu;
            ctx->pc = 0x801986F0u;
            return;
    }

label_801905DC:
    ctx->pc = 0x801905DCu;
    ctx->downcount -= 3;
    // 801905DC: lwz     r3, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801905E0:
    ctx->pc = 0x801905E0u;
    // 801905E0: cmpwi   r3, 0
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

label_801905E4:
    ctx->pc = 0x801905E4u;
    // 801905E4: bc    12, 2, 0x801905F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801905F0;
        }
    }

label_801905E8:
    ctx->pc = 0x801905E8u;
    ctx->downcount -= 2;
    // 801905E8: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_801905EC:
    ctx->pc = 0x801905ECu;
    // 801905EC: bl      0x8001D934
    {
            ctx->lr = 0x801905F0u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801905F0:
    ctx->pc = 0x801905F0u;
    ctx->downcount -= 4;
    // 801905F0: lwz     r0, 4(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801905F4:
    ctx->pc = 0x801905F4u;
    // 801905F4: lwz     r9, 1664(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1664);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801905F8:
    ctx->pc = 0x801905F8u;
    // 801905F8: cmpw    r9, r0
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

label_801905FC:
    ctx->pc = 0x801905FCu;
    // 801905FC: bc    12, 2, 0x8019060C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019060C;
        }
    }

label_80190600:
    loop_80190600(ctx);
    if (ctx->pc == 0x8019060Cu) goto label_8019060C;
    return;
label_80190604:
    // 80190604: cmpw    r9, r0
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

label_80190608:
    // 80190608: bc    4, 2, 0x80190600
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190600u;
                return;
            }
            goto label_80190600;
        }
    }

label_8019060C:
    ctx->pc = 0x8019060Cu;
    ctx->downcount -= 3;
    // 8019060C: lwz     r3, 0(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190610:
    ctx->pc = 0x80190610u;
    // 80190610: cmpwi   r3, 0
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

label_80190614:
    ctx->pc = 0x80190614u;
    // 80190614: bc    12, 2, 0x80190650
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190650;
        }
    }

label_80190618:
    ctx->pc = 0x80190618u;
    ctx->downcount -= 15;
    // 80190618: lwz     r0, 12(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019061C:
    ctx->pc = 0x8019061Cu;
    // 8019061C: lis     r9, -16132
    ctx->gpr[9] = ((u32)(s32)(-16132) << 16);

label_80190620:
    ctx->pc = 0x80190620u;
    // 80190620: ori     r9, r9, 0x0FC1
    ctx->gpr[9] = ctx->gpr[9] | 0x0FC1u;

label_80190624:
    ctx->pc = 0x80190624u;
    // 80190624: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80190628:
    ctx->pc = 0x80190628u;
    // 80190628: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_8019062C:
    ctx->pc = 0x8019062Cu;
    // 8019062C: srawi r0, r0, 2
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

label_80190630:
    ctx->pc = 0x80190630u;
    // 80190630: rlwinm r9, r0, 6, 0, 25
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 6u) & 0xFFFFFFC0u;
    }

label_80190634:
    ctx->pc = 0x80190634u;
    // 80190634: add   r9, r9, r0
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80190638:
    ctx->pc = 0x80190638u;
    // 80190638: rlwinm r4, r9, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8019063C:
    ctx->pc = 0x8019063Cu;
    // 8019063C: cmplwi  r4, 0x0080
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

label_80190640:
    ctx->pc = 0x80190640u;
    // 80190640: bc    4, 1, 0x8019064C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019064C;
        }
    }

label_80190644:
    ctx->pc = 0x80190644u;
    ctx->downcount -= 1;
    // 80190644: bl      0x80281D80
    {
            ctx->lr = 0x80190648u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80190648:
    ctx->pc = 0x80190648u;
    ctx->downcount -= 1;
    // 80190648: b       0x80190650
    {
            goto label_80190650;
    }

label_8019064C:
    ctx->pc = 0x8019064Cu;
    ctx->downcount -= 1;
    // 8019064C: bl      0x8001D934
    {
            ctx->lr = 0x80190650u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80190650:
    ctx->pc = 0x80190650u;
    ctx->downcount -= 3;
    // 80190650: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80190654:
    ctx->pc = 0x80190654u;
    // 80190654: or   r4, r16, r16
    {
        ctx->gpr[4] = ctx->gpr[16] | ctx->gpr[16];
    }

label_80190658:
    ctx->pc = 0x80190658u;
    // 80190658: bl      0x801B62EC
    {
            ctx->lr = 0x8019065Cu;
            ctx->pc = 0x801B62ECu;
            return;
    }

label_8019065C:
    ctx->pc = 0x8019065Cu;
    ctx->downcount -= 16;
    // 8019065C: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190660:
    ctx->pc = 0x80190660u;
    // 80190660: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80190664:
    ctx->pc = 0x80190664u;
    // 80190664: lmw     r16, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 16; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80190668:
    ctx->pc = 0x80190668u;
    // 80190668: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_8019066C:
    ctx->pc = 0x8019066Cu;
    // 8019066C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8018F4C0;
        }
    }

label_80190670:
    ctx->pc = 0x80190670u;
    ctx->downcount -= 20;
    // 80190670: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80190674:
    ctx->pc = 0x80190674u;
    // 80190674: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80190678:
    ctx->pc = 0x80190678u;
    // 80190678: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8019067C:
    ctx->pc = 0x8019067Cu;
    // 8019067C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80190680:
    ctx->pc = 0x80190680u;
    // 80190680: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80190684:
    ctx->pc = 0x80190684u;
    // 80190684: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190688:
    ctx->pc = 0x80190688u;
    // 80190688: lwz     r30, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8019068C:
    ctx->pc = 0x8019068Cu;
    // 8019068C: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190690:
    ctx->pc = 0x80190690u;
    // 80190690: cmpw    r30, r0
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

label_80190694:
    ctx->pc = 0x80190694u;
    // 80190694: bc    12, 2, 0x80190770
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190770;
        }
    }

label_80190698:
    ctx->pc = 0x80190698u;
    ctx->downcount -= 3;
    // 80190698: lis     r28, -3856
    ctx->gpr[28] = ((u32)(s32)(-3856) << 16);

label_8019069C:
    ctx->pc = 0x8019069Cu;
    // 8019069C: addi    r29, r30, 136
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(136);

label_801906A0:
    ctx->pc = 0x801906A0u;
    // 801906A0: ori     r28, r28, 0xF0F1
    ctx->gpr[28] = ctx->gpr[28] | 0xF0F1u;

label_801906A4:
    ctx->pc = 0x801906A4u;
    ctx->downcount -= 3;
    // 801906A4: lwz     r4, 132(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801906A8:
    // 801906A8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801906AC:
    // 801906AC: bl      0x80190670
    {
            ctx->lr = 0x801906B0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190670u;
                return;
            }
            goto label_80190670;
    }

label_801906B0:
    ctx->pc = 0x801906B0u;
    ctx->downcount -= 3;
    // 801906B0: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801906B4:
    // 801906B4: cmpw    r29, r0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801906B8:
    // 801906B8: bc    12, 2, 0x8019075C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019075C;
        }
    }

label_801906BC:
    ctx->downcount -= 10;
    // 801906BC: or   r8, r29, r29
    {
        ctx->gpr[8] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801906C0:
    // 801906C0: or   r7, r30, r30
    {
        ctx->gpr[7] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801906C4:
    // 801906C4: subf   r0, r8, r0
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801906C8:
    // 801906C8: mullw   r0, r0, r28
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[28];
        ctx->gpr[0] = (u32)product;
    }

label_801906CC:
    // 801906CC: srawi. r6, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[6] = value;
        } else if (sh > 31) {
            ctx->gpr[6] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[6] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801906D0:
    // 801906D0: bc    4, 1, 0x8019075C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019075C;
        }
    }

label_801906D4:
    ctx->downcount -= 6;
    // 801906D4: or   r10, r7, r7
    {
        ctx->gpr[10] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801906D8:
    // 801906D8: or   r11, r8, r8
    {
        ctx->gpr[11] = ctx->gpr[8] | ctx->gpr[8];
    }

label_801906DC:
    // 801906DC: addi    r7, r11, 136
    ctx->gpr[7] = ctx->gpr[11] + (u32)(s32)(136);

label_801906E0:
    // 801906E0: addi    r5, r10, 136
    ctx->gpr[5] = ctx->gpr[10] + (u32)(s32)(136);

label_801906E4:
    // 801906E4: addi    r0, r6, -1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(-1);

label_801906E8:
    // 801906E8: li      r8, 120
    ctx->gpr[8] = (u32)(s32)(120);

label_801906EC:
    loop_801906EC(ctx);
    if (ctx->pc == 0x8019072Cu) goto label_8019072C;
    return;
label_801906F0:
    // 801906F0: addic.  r8, r8, -24
    {
        u64 a = ctx->gpr[8];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801906F4:
    ctx->pc = 0x801906F4u;
    // 801906F4: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801906F8:
    ctx->pc = 0x801906F8u;
    // 801906F8: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801906FC:
    ctx->pc = 0x801906FCu;
    // 801906FC: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190700:
    ctx->pc = 0x80190700u;
    // 80190700: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190704:
    ctx->pc = 0x80190704u;
    // 80190704: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190708:
    ctx->pc = 0x80190708u;
    // 80190708: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019070C:
    ctx->pc = 0x8019070Cu;
    // 8019070C: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190710:
    ctx->pc = 0x80190710u;
    // 80190710: lwz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190714:
    ctx->pc = 0x80190714u;
    // 80190714: stw     r9, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190718:
    ctx->pc = 0x80190718u;
    // 80190718: lwz     r9, 20(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019071C:
    // 8019071C: addi    r11, r11, 24
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(24);

label_80190720:
    ctx->pc = 0x80190720u;
    // 80190720: stw     r9, 20(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190724:
    // 80190724: addi    r10, r10, 24
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(24);

label_80190728:
    // 80190728: bc    4, 2, 0x801906EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801906ECu;
                return;
            }
            goto label_801906EC;
        }
    }

label_8019072C:
    ctx->pc = 0x8019072Cu;
    ctx->downcount -= 12;
    // 8019072C: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190730:
    // 80190730: or   r8, r7, r7
    {
        ctx->gpr[8] = ctx->gpr[7] | ctx->gpr[7];
    }

label_80190734:
    // 80190734: or   r7, r5, r5
    {
        ctx->gpr[7] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80190738:
    // 80190738: or.   r6, r0, r0
    {
        ctx->gpr[6] = ctx->gpr[0] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019073C:
    ctx->pc = 0x8019073Cu;
    // 8019073C: stw     r9, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190740:
    ctx->pc = 0x80190740u;
    // 80190740: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190744:
    ctx->pc = 0x80190744u;
    // 80190744: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190748:
    ctx->pc = 0x80190748u;
    // 80190748: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019074C:
    ctx->pc = 0x8019074Cu;
    // 8019074C: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190750:
    ctx->pc = 0x80190750u;
    // 80190750: lwz     r9, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190754:
    ctx->pc = 0x80190754u;
    // 80190754: stw     r9, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190758:
    // 80190758: bc    12, 1, 0x801906D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801906D4u;
                return;
            }
            goto label_801906D4;
        }
    }

label_8019075C:
    ctx->pc = 0x8019075Cu;
    ctx->downcount -= 5;
    // 8019075C: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190760:
    // 80190760: addi    r9, r9, -136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-136);

label_80190764:
    // 80190764: cmpw    r30, r9
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190768:
    ctx->pc = 0x80190768u;
    // 80190768: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019076C:
    // 8019076C: bc    4, 2, 0x801906A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801906A4u;
                return;
            }
            goto label_801906A4;
        }
    }

label_80190770:
    ctx->pc = 0x80190770u;
    ctx->downcount -= 2;
    // 80190770: cmpwi   r31, 0
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

label_80190774:
    ctx->pc = 0x80190774u;
    // 80190774: bc    12, 2, 0x801907D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801907D8;
        }
    }

label_80190778:
    ctx->pc = 0x80190778u;
    ctx->downcount -= 5;
    // 80190778: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019077C:
    ctx->pc = 0x8019077Cu;
    // 8019077C: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190780:
    ctx->pc = 0x80190780u;
    // 80190780: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80190784:
    ctx->pc = 0x80190784u;
    // 80190784: cmpw    r9, r0
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

label_80190788:
    ctx->pc = 0x80190788u;
    // 80190788: bc    12, 2, 0x80190798
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190798;
        }
    }

label_8019078C:
    loop_8019078C(ctx);
    if (ctx->pc == 0x80190798u) goto label_80190798;
    return;
label_80190790:
    // 80190790: cmpw    r9, r0
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

label_80190794:
    // 80190794: bc    4, 2, 0x8019078C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019078Cu;
                return;
            }
            goto label_8019078C;
        }
    }

label_80190798:
    ctx->pc = 0x80190798u;
    ctx->downcount -= 2;
    // 80190798: cmpwi   r3, 0
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

label_8019079C:
    ctx->pc = 0x8019079Cu;
    // 8019079C: bc    12, 2, 0x801907D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801907D0;
        }
    }

label_801907A0:
    ctx->pc = 0x801907A0u;
    ctx->downcount -= 15;
    // 801907A0: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801907A4:
    ctx->pc = 0x801907A4u;
    // 801907A4: lis     r9, -3856
    ctx->gpr[9] = ((u32)(s32)(-3856) << 16);

label_801907A8:
    ctx->pc = 0x801907A8u;
    // 801907A8: ori     r9, r9, 0xF0F1
    ctx->gpr[9] = ctx->gpr[9] | 0xF0F1u;

label_801907AC:
    ctx->pc = 0x801907ACu;
    // 801907AC: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801907B0:
    ctx->pc = 0x801907B0u;
    // 801907B0: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_801907B4:
    ctx->pc = 0x801907B4u;
    // 801907B4: srawi r0, r0, 3
    {
        u32 sh = 3u;
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

label_801907B8:
    ctx->pc = 0x801907B8u;
    // 801907B8: mulli   r4, r0, 136
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)136);

label_801907BC:
    ctx->pc = 0x801907BCu;
    // 801907BC: cmplwi  r4, 0x0080
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

label_801907C0:
    ctx->pc = 0x801907C0u;
    // 801907C0: bc    4, 1, 0x801907CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801907CC;
        }
    }

label_801907C4:
    ctx->pc = 0x801907C4u;
    ctx->downcount -= 1;
    // 801907C4: bl      0x80281D80
    {
            ctx->lr = 0x801907C8u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801907C8:
    ctx->pc = 0x801907C8u;
    ctx->downcount -= 1;
    // 801907C8: b       0x801907D0
    {
            goto label_801907D0;
    }

label_801907CC:
    ctx->pc = 0x801907CCu;
    ctx->downcount -= 1;
    // 801907CC: bl      0x8001D934
    {
            ctx->lr = 0x801907D0u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_801907D0:
    ctx->pc = 0x801907D0u;
    ctx->downcount -= 2;
    // 801907D0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801907D4:
    ctx->pc = 0x801907D4u;
    // 801907D4: bl      0x80281D80
    {
            ctx->lr = 0x801907D8u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_801907D8:
    ctx->pc = 0x801907D8u;
    ctx->downcount -= 16;
    // 801907D8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801907DC:
    ctx->pc = 0x801907DCu;
    // 801907DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801907E0:
    ctx->pc = 0x801907E0u;
    // 801907E0: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801907E4:
    ctx->pc = 0x801907E4u;
    // 801907E4: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801907E8:
    ctx->pc = 0x801907E8u;
    // 801907E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8018F4C0;
        }
    }

label_801907EC:
    ctx->pc = 0x801907ECu;
    ctx->downcount -= 24;
    // 801907EC: stwu     r1, -1592(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-1592);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801907F0:
    ctx->pc = 0x801907F0u;
    // 801907F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801907F4:
    ctx->pc = 0x801907F4u;
    // 801907F4: stmw     r21, 1548(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1548);
        for (u32 r = 21; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801907F8:
    ctx->pc = 0x801907F8u;
    // 801907F8: stw     r0, 1596(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801907FC:
    ctx->pc = 0x801907FCu;
    // 801907FC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190800:
    ctx->pc = 0x80190800u;
    // 80190800: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_80190804:
    ctx->pc = 0x80190804u;
    // 80190804: lwz     r9, 1936(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1936);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190808:
    ctx->pc = 0x80190808u;
    // 80190808: lwz     r0, 1920(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1920);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019080C:
    ctx->pc = 0x8019080Cu;
    // 8019080C: addi    r26, r1, 264
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(264);

label_80190810:
    ctx->pc = 0x80190810u;
    // 80190810: stw     r9, 1940(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1940);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190814:
    ctx->pc = 0x80190814u;
    // 80190814: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80190818:
    ctx->pc = 0x80190818u;
    // 80190818: stw     r0, 1924(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1924);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019081C:
    ctx->pc = 0x8019081Cu;
    // 8019081C: or   r21, r29, r29
    {
        ctx->gpr[21] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80190820:
    ctx->pc = 0x80190820u;
    // 80190820: bl      0x801948E4
    {
            ctx->lr = 0x80190824u;
            ctx->pc = 0x801948E4u;
            return;
    }

label_80190824:
    ctx->pc = 0x80190824u;
    ctx->downcount -= 7;
    // 80190824: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80190828:
    ctx->pc = 0x80190828u;
    // 80190828: stb     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_8019082C:
    ctx->pc = 0x8019082Cu;
    // 8019082C: addi    r4, r4, -16720
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16720);

label_80190830:
    ctx->pc = 0x80190830u;
    // 80190830: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80190834:
    ctx->pc = 0x80190834u;
    // 80190834: addi    r5, r31, 4
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(4);

label_80190838:
    ctx->pc = 0x80190838u;
    // 80190838: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8019083C:
    ctx->pc = 0x8019083Cu;
    // 8019083C: bl      0x8013F048
    {
            ctx->lr = 0x80190840u;
            ctx->pc = 0x8013F048u;
            return;
    }

label_80190840:
    ctx->pc = 0x80190840u;
    ctx->downcount -= 4;
    // 80190840: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190844:
    ctx->pc = 0x80190844u;
    // 80190844: addi    r4, r9, -18032
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-18032);

label_80190848:
    ctx->pc = 0x80190848u;
    // 80190848: cmpwi   r4, 0
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

label_8019084C:
    ctx->pc = 0x8019084Cu;
    // 8019084C: bc    12, 2, 0x80190860
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190860;
        }
    }

label_80190850:
    ctx->pc = 0x80190850u;
    ctx->downcount -= 3;
    // 80190850: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190854:
    ctx->pc = 0x80190854u;
    // 80190854: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190858:
    ctx->pc = 0x80190858u;
    // 80190858: bl      0x80287F10
    {
            ctx->lr = 0x8019085Cu;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8019085C:
    ctx->pc = 0x8019085Cu;
    ctx->downcount -= 1;
    // 8019085C: b       0x80190864
    {
            goto label_80190864;
    }

label_80190860:
    ctx->pc = 0x80190860u;
    ctx->downcount -= 1;
    // 80190860: stb     r4, 264(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(264);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80190864:
    ctx->pc = 0x80190864u;
    ctx->downcount -= 13;
    // 80190864: lwz     r11, 1968(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1968);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80190868:
    ctx->pc = 0x80190868u;
    // 80190868: addi    r10, r31, 1968
    ctx->gpr[10] = ctx->gpr[31] + (u32)(s32)(1968);

label_8019086C:
    ctx->pc = 0x8019086Cu;
    // 8019086C: addi    r30, r31, 1984
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(1984);

label_80190870:
    ctx->pc = 0x80190870u;
    // 80190870: addi    r28, r1, 520
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(520);

label_80190874:
    ctx->pc = 0x80190874u;
    // 80190874: addi    r27, r1, 776
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(776);

label_80190878:
    ctx->pc = 0x80190878u;
    // 80190878: addi    r23, r31, 2000
    ctx->gpr[23] = ctx->gpr[31] + (u32)(s32)(2000);

label_8019087C:
    ctx->pc = 0x8019087Cu;
    // 8019087C: addi    r25, r1, 1032
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(1032);

label_80190880:
    ctx->pc = 0x80190880u;
    // 80190880: addi    r24, r1, 1288
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(1288);

label_80190884:
    ctx->pc = 0x80190884u;
    // 80190884: addi    r22, r31, 2016
    ctx->gpr[22] = ctx->gpr[31] + (u32)(s32)(2016);

label_80190888:
    ctx->pc = 0x80190888u;
    // 80190888: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019088C:
    ctx->pc = 0x8019088Cu;
    // 8019088C: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80190890:
    ctx->pc = 0x80190890u;
    // 80190890: cmpw    r11, r0
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

label_80190894:
    ctx->pc = 0x80190894u;
    // 80190894: bc    12, 2, 0x801908A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801908A4;
        }
    }

label_80190898:
    loop_80190898(ctx);
    if (ctx->pc == 0x801908A4u) goto label_801908A4;
    return;
label_8019089C:
    // 8019089C: cmpw    r9, r0
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

label_801908A0:
    // 801908A0: bc    4, 2, 0x80190898
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190898u;
                return;
            }
            goto label_80190898;
        }
    }

label_801908A4:
    ctx->pc = 0x801908A4u;
    ctx->downcount -= 5;
    // 801908A4: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_801908A8:
    ctx->pc = 0x801908A8u;
    // 801908A8: stw     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801908AC:
    ctx->pc = 0x801908ACu;
    // 801908AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801908B0:
    ctx->pc = 0x801908B0u;
    // 801908B0: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801908B4:
    ctx->pc = 0x801908B4u;
    // 801908B4: bl      0x80191A98
    {
            ctx->lr = 0x801908B8u;
            goto label_80191A98;
    }

label_801908B8:
    ctx->pc = 0x801908B8u;
    ctx->downcount -= 7;
    // 801908B8: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801908BC:
    ctx->pc = 0x801908BCu;
    // 801908BC: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_801908C0:
    ctx->pc = 0x801908C0u;
    // 801908C0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_801908C4:
    ctx->pc = 0x801908C4u;
    // 801908C4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_801908C8:
    ctx->pc = 0x801908C8u;
    // 801908C8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801908CC:
    ctx->pc = 0x801908CCu;
    // 801908CC: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801908D0:
    ctx->pc = 0x801908D0u;
    // 801908D0: bl      0x801909D8
    {
            ctx->lr = 0x801908D4u;
            goto label_801909D8;
    }

label_801908D4:
    ctx->pc = 0x801908D4u;
    ctx->downcount -= 4;
    // 801908D4: or   r4, r21, r21
    {
        ctx->gpr[4] = ctx->gpr[21] | ctx->gpr[21];
    }

label_801908D8:
    ctx->pc = 0x801908D8u;
    // 801908D8: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_801908DC:
    ctx->pc = 0x801908DCu;
    // 801908DC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801908E0:
    ctx->pc = 0x801908E0u;
    // 801908E0: bl      0x80287F10
    {
            ctx->lr = 0x801908E4u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_801908E4:
    ctx->pc = 0x801908E4u;
    ctx->downcount -= 4;
    // 801908E4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801908E8:
    ctx->pc = 0x801908E8u;
    // 801908E8: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801908EC:
    ctx->pc = 0x801908ECu;
    // 801908EC: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_801908F0:
    ctx->pc = 0x801908F0u;
    // 801908F0: bl      0x80287F10
    {
            ctx->lr = 0x801908F4u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_801908F4:
    ctx->pc = 0x801908F4u;
    ctx->downcount -= 5;
    // 801908F4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801908F8:
    ctx->pc = 0x801908F8u;
    // 801908F8: addi    r30, r9, -16588
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-16588);

label_801908FC:
    ctx->pc = 0x801908FCu;
    // 801908FC: cmpwi   r30, 0
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

label_80190900:
    ctx->pc = 0x80190900u;
    // 80190900: mfcr    r29
    ctx->gpr[29] = ctx->cr;

label_80190904:
    ctx->pc = 0x80190904u;
    // 80190904: bc    12, 2, 0x80190930
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190930;
        }
    }

label_80190908:
    ctx->pc = 0x80190908u;
    ctx->downcount -= 4;
    // 80190908: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8019090C:
    ctx->pc = 0x8019090Cu;
    // 8019090C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80190910:
    ctx->pc = 0x80190910u;
    // 80190910: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190914:
    ctx->pc = 0x80190914u;
    // 80190914: bl      0x80287E64
    {
            ctx->lr = 0x80190918u;
            ctx->pc = 0x80287E64u;
            return;
    }

label_80190918:
    ctx->pc = 0x80190918u;
    ctx->downcount -= 2;
    // 80190918: mtcrf   0x80, r29
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[29] & 0xF0000000u);

label_8019091C:
    ctx->pc = 0x8019091Cu;
    // 8019091C: bc    12, 2, 0x80190930
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190930;
        }
    }

label_80190920:
    ctx->pc = 0x80190920u;
    ctx->downcount -= 4;
    // 80190920: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80190924:
    ctx->pc = 0x80190924u;
    // 80190924: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80190928:
    ctx->pc = 0x80190928u;
    // 80190928: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_8019092C:
    ctx->pc = 0x8019092Cu;
    // 8019092C: bl      0x80287E64
    {
            ctx->lr = 0x80190930u;
            ctx->pc = 0x80287E64u;
            return;
    }

label_80190930:
    ctx->pc = 0x80190930u;
    ctx->downcount -= 7;
    // 80190930: or   r6, r23, r23
    {
        ctx->gpr[6] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80190934:
    ctx->pc = 0x80190934u;
    // 80190934: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80190938:
    ctx->pc = 0x80190938u;
    // 80190938: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8019093C:
    ctx->pc = 0x8019093Cu;
    // 8019093C: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80190940:
    ctx->pc = 0x80190940u;
    // 80190940: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80190944:
    ctx->pc = 0x80190944u;
    // 80190944: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80190948:
    ctx->pc = 0x80190948u;
    // 80190948: bl      0x801909D8
    {
            ctx->lr = 0x8019094Cu;
            goto label_801909D8;
    }

label_8019094C:
    ctx->pc = 0x8019094Cu;
    ctx->downcount -= 4;
    // 8019094C: or   r4, r21, r21
    {
        ctx->gpr[4] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80190950:
    ctx->pc = 0x80190950u;
    // 80190950: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190954:
    ctx->pc = 0x80190954u;
    // 80190954: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80190958:
    ctx->pc = 0x80190958u;
    // 80190958: bl      0x80287F10
    {
            ctx->lr = 0x8019095Cu;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8019095C:
    ctx->pc = 0x8019095Cu;
    ctx->downcount -= 4;
    // 8019095C: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190960:
    ctx->pc = 0x80190960u;
    // 80190960: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80190964:
    ctx->pc = 0x80190964u;
    // 80190964: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190968:
    ctx->pc = 0x80190968u;
    // 80190968: bl      0x80287F10
    {
            ctx->lr = 0x8019096Cu;
            ctx->pc = 0x80287F10u;
            return;
    }

label_8019096C:
    ctx->pc = 0x8019096Cu;
    ctx->downcount -= 5;
    // 8019096C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190970:
    ctx->pc = 0x80190970u;
    // 80190970: addi    r30, r9, -16580
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-16580);

label_80190974:
    ctx->pc = 0x80190974u;
    // 80190974: cmpwi   r30, 0
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

label_80190978:
    ctx->pc = 0x80190978u;
    // 80190978: mfcr    r29
    ctx->gpr[29] = ctx->cr;

label_8019097C:
    ctx->pc = 0x8019097Cu;
    // 8019097C: bc    12, 2, 0x801909A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801909A8;
        }
    }

label_80190980:
    ctx->pc = 0x80190980u;
    ctx->downcount -= 4;
    // 80190980: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80190984:
    ctx->pc = 0x80190984u;
    // 80190984: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80190988:
    ctx->pc = 0x80190988u;
    // 80190988: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_8019098C:
    ctx->pc = 0x8019098Cu;
    // 8019098C: bl      0x80287E64
    {
            ctx->lr = 0x80190990u;
            ctx->pc = 0x80287E64u;
            return;
    }

label_80190990:
    ctx->pc = 0x80190990u;
    ctx->downcount -= 2;
    // 80190990: mtcrf   0x80, r29
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[29] & 0xF0000000u);

label_80190994:
    ctx->pc = 0x80190994u;
    // 80190994: bc    12, 2, 0x801909A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801909A8;
        }
    }

label_80190998:
    ctx->pc = 0x80190998u;
    ctx->downcount -= 4;
    // 80190998: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019099C:
    ctx->pc = 0x8019099Cu;
    // 8019099C: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801909A0:
    ctx->pc = 0x801909A0u;
    // 801909A0: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_801909A4:
    ctx->pc = 0x801909A4u;
    // 801909A4: bl      0x80287E64
    {
            ctx->lr = 0x801909A8u;
            ctx->pc = 0x80287E64u;
            return;
    }

label_801909A8:
    ctx->pc = 0x801909A8u;
    ctx->downcount -= 7;
    // 801909A8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801909AC:
    ctx->pc = 0x801909ACu;
    // 801909AC: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801909B0:
    ctx->pc = 0x801909B0u;
    // 801909B0: or   r5, r24, r24
    {
        ctx->gpr[5] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801909B4:
    ctx->pc = 0x801909B4u;
    // 801909B4: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_801909B8:
    ctx->pc = 0x801909B8u;
    // 801909B8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_801909BC:
    ctx->pc = 0x801909BCu;
    // 801909BC: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_801909C0:
    ctx->pc = 0x801909C0u;
    // 801909C0: bl      0x801909D8
    {
            ctx->lr = 0x801909C4u;
            goto label_801909D8;
    }

label_801909C4:
    ctx->pc = 0x801909C4u;
    ctx->downcount -= 16;
    // 801909C4: lwz     r0, 1596(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801909C8:
    ctx->pc = 0x801909C8u;
    // 801909C8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801909CC:
    ctx->pc = 0x801909CCu;
    // 801909CC: lmw     r21, 1548(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1548);
        for (u32 r = 21; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801909D0:
    ctx->pc = 0x801909D0u;
    // 801909D0: addi    r1, r1, 1592
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(1592);

label_801909D4:
    ctx->pc = 0x801909D4u;
    // 801909D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8018F4C0;
        }
    }

label_801909D8:
    ctx->pc = 0x801909D8u;
    ctx->downcount -= 28;
    // 801909D8: stwu     r1, -792(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-792);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801909DC:
    ctx->pc = 0x801909DCu;
    // 801909DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801909E0:
    ctx->pc = 0x801909E0u;
    // 801909E0: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801909E4:
    ctx->pc = 0x801909E4u;
    // 801909E4: stmw     r14, 720(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(720);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801909E8:
    ctx->pc = 0x801909E8u;
    // 801909E8: stw     r0, 796(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(796);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801909EC:
    ctx->pc = 0x801909ECu;
    // 801909EC: stw     r12, 716(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(716);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801909F0:
    ctx->pc = 0x801909F0u;
    // 801909F0: stw     r7, 696(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(696);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_801909F4:
    ctx->pc = 0x801909F4u;
    // 801909F4: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801909F8:
    ctx->pc = 0x801909F8u;
    // 801909F8: stw     r8, 700(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(700);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801909FC:
    ctx->pc = 0x801909FCu;
    // 801909FC: or   r14, r4, r4
    {
        ctx->gpr[14] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80190A00:
    ctx->pc = 0x80190A00u;
    // 80190A00: or   r15, r5, r5
    {
        ctx->gpr[15] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80190A04:
    ctx->pc = 0x80190A04u;
    // 80190A04: or   r25, r6, r6
    {
        ctx->gpr[25] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80190A08:
    ctx->pc = 0x80190A08u;
    // 80190A08: li      r23, 0
    ctx->gpr[23] = (u32)(s32)(0);

label_80190A0C:
    ctx->pc = 0x80190A0Cu;
    // 80190A0C: addi    r0, r1, 24
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(24);

label_80190A10:
    ctx->pc = 0x80190A10u;
    // 80190A10: addi    r9, r1, 280
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(280);

label_80190A14:
    ctx->pc = 0x80190A14u;
    // 80190A14: stw     r0, 708(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(708);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80190A18:
    ctx->pc = 0x80190A18u;
    // 80190A18: addi    r21, r1, 16
    ctx->gpr[21] = ctx->gpr[1] + (u32)(s32)(16);

label_80190A1C:
    ctx->pc = 0x80190A1Cu;
    // 80190A1C: stw     r9, 704(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(704);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190A20:
    ctx->downcount -= 2;
    // 80190A20: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80190A24:
    // 80190A24: bl      0x801CFD60
    {
            ctx->lr = 0x80190A28u;
            ctx->pc = 0x801CFD60u;
            return;
    }

label_80190A28:
    ctx->downcount -= 2;
    // 80190A28: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80190A2C:
    // 80190A2C: bl      0x801CFD60
    {
            ctx->lr = 0x80190A30u;
            ctx->pc = 0x801CFD60u;
            return;
    }

label_80190A30:
    ctx->downcount -= 2;
    // 80190A30: cmpwi   r14, 0
    {
        s32 val_a = (s32)(ctx->gpr[14]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190A34:
    // 80190A34: bc    12, 2, 0x80190A4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190A4C;
        }
    }

label_80190A38:
    ctx->pc = 0x80190A38u;
    ctx->downcount -= 4;
    // 80190A38: lwz     r3, 708(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(708);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190A3C:
    // 80190A3C: or   r4, r14, r14
    {
        ctx->gpr[4] = ctx->gpr[14] | ctx->gpr[14];
    }

label_80190A40:
    // 80190A40: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190A44:
    // 80190A44: bl      0x80287F10
    {
            ctx->lr = 0x80190A48u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_80190A48:
    ctx->downcount -= 1;
    // 80190A48: b       0x80190A50
    {
            goto label_80190A50;
    }

label_80190A4C:
    ctx->pc = 0x80190A4Cu;
    ctx->downcount -= 1;
    // 80190A4C: stb     r14, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write8(ctx, ea, (u8)ctx->gpr[14]);
    }

label_80190A50:
    ctx->downcount -= 2;
    // 80190A50: cmpwi   r15, 0
    {
        s32 val_a = (s32)(ctx->gpr[15]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190A54:
    // 80190A54: bc    12, 2, 0x80190A6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190A6C;
        }
    }

label_80190A58:
    ctx->pc = 0x80190A58u;
    ctx->downcount -= 4;
    // 80190A58: lwz     r3, 704(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190A5C:
    // 80190A5C: or   r4, r15, r15
    {
        ctx->gpr[4] = ctx->gpr[15] | ctx->gpr[15];
    }

label_80190A60:
    // 80190A60: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190A64:
    // 80190A64: bl      0x80287F10
    {
            ctx->lr = 0x80190A68u;
            ctx->pc = 0x80287F10u;
            return;
    }

label_80190A68:
    ctx->downcount -= 1;
    // 80190A68: b       0x80190A70
    {
            goto label_80190A70;
    }

label_80190A6C:
    ctx->pc = 0x80190A6Cu;
    ctx->downcount -= 1;
    // 80190A6C: stb     r15, 280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        mem_write8(ctx, ea, (u8)ctx->gpr[15]);
    }

label_80190A70:
    ctx->downcount -= 5;
    // 80190A70: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190A74:
    // 80190A74: addi    r31, r9, -16572
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-16572);

label_80190A78:
    // 80190A78: cmpwi   r31, 0
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

label_80190A7C:
    // 80190A7C: mfcr    r30
    ctx->gpr[30] = ctx->cr;

label_80190A80:
    // 80190A80: bc    12, 2, 0x80190AAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190AAC;
        }
    }

label_80190A84:
    ctx->downcount -= 4;
    // 80190A84: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_80190A88:
    // 80190A88: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80190A8C:
    // 80190A8C: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190A90:
    // 80190A90: bl      0x80287E64
    {
            ctx->lr = 0x80190A94u;
            ctx->pc = 0x80287E64u;
            return;
    }

label_80190A94:
    ctx->downcount -= 2;
    // 80190A94: mtcrf   0x80, r30
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[30] & 0xF0000000u);

label_80190A98:
    // 80190A98: bc    12, 2, 0x80190AAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190AAC;
        }
    }

label_80190A9C:
    ctx->downcount -= 4;
    // 80190A9C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80190AA0:
    // 80190AA0: addi    r3, r1, 280
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(280);

label_80190AA4:
    // 80190AA4: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190AA8:
    // 80190AA8: bl      0x80287E64
    {
            ctx->lr = 0x80190AACu;
            ctx->pc = 0x80287E64u;
            return;
    }

label_80190AAC:
    ctx->downcount -= 6;
    // 80190AAC: lis     r9, -32718
    ctx->gpr[9] = ((u32)(s32)(-32718) << 16);

label_80190AB0:
    // 80190AB0: rlwinm r30, r23, 2, 0, 29
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[23], 2u) & 0xFFFFFFFCu;
    }

label_80190AB4:
    // 80190AB4: addi    r29, r9, -780
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-780);

label_80190AB8:
    ctx->pc = 0x80190AB8u;
    // 80190AB8: lwzx    r4, r29, r30
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80190ABC:
    // 80190ABC: cmpwi   r4, 0
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

label_80190AC0:
    // 80190AC0: bc    12, 2, 0x80190AD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190AD0;
        }
    }

label_80190AC4:
    ctx->downcount -= 3;
    // 80190AC4: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_80190AC8:
    // 80190AC8: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190ACC:
    // 80190ACC: bl      0x80287E64
    {
            ctx->lr = 0x80190AD0u;
            ctx->pc = 0x80287E64u;
            return;
    }

label_80190AD0:
    ctx->pc = 0x80190AD0u;
    ctx->downcount -= 3;
    // 80190AD0: lwzx    r4, r29, r30
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[30];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80190AD4:
    // 80190AD4: cmpwi   r4, 0
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

label_80190AD8:
    // 80190AD8: bc    12, 2, 0x80190AE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190AE8;
        }
    }

label_80190ADC:
    ctx->downcount -= 3;
    // 80190ADC: addi    r3, r1, 280
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(280);

label_80190AE0:
    // 80190AE0: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80190AE4:
    // 80190AE4: bl      0x80287E64
    {
            ctx->lr = 0x80190AE8u;
            ctx->pc = 0x80287E64u;
            return;
    }

label_80190AE8:
    ctx->pc = 0x80190AE8u;
    ctx->downcount -= 3;
    // 80190AE8: lwz     r4, 704(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(704);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80190AEC:
    // 80190AEC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80190AF0:
    // 80190AF0: bl      0x801CFF5C
    {
            ctx->lr = 0x80190AF4u;
            ctx->pc = 0x801CFF5Cu;
            return;
    }

label_80190AF4:
    ctx->downcount -= 4;
    // 80190AF4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190AF8:
    ctx->pc = 0x80190AF8u;
    // 80190AF8: lwz     r4, 708(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(708);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80190AFC:
    // 80190AFC: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80190B00:
    // 80190B00: bl      0x801CFF5C
    {
            ctx->lr = 0x80190B04u;
            ctx->pc = 0x801CFF5Cu;
            return;
    }

label_80190B04:
    ctx->downcount -= 2;
    // 80190B04: cmpwi   r30, 0
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

label_80190B08:
    // 80190B08: bc    4, 2, 0x80190B28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190B28;
        }
    }

label_80190B0C:
    ctx->downcount -= 2;
    // 80190B0C: cmpwi   r3, 0
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

label_80190B10:
    // 80190B10: bc    4, 2, 0x80190B28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190B28;
        }
    }

label_80190B14:
    ctx->downcount -= 3;
    // 80190B14: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80190B18:
    // 80190B18: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80190B1C:
    // 80190B1C: bl      0x801CFEAC
    {
            ctx->lr = 0x80190B20u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80190B20:
    ctx->downcount -= 2;
    // 80190B20: addi    r17, r23, 1
    ctx->gpr[17] = ctx->gpr[23] + (u32)(s32)(1);

label_80190B24:
    // 80190B24: b       0x80190CBC
    {
            goto label_80190CBC;
    }

label_80190B28:
    ctx->downcount -= 3;
    // 80190B28: addi    r3, r1, 536
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(536);

label_80190B2C:
    // 80190B2C: or   r16, r3, r3
    {
        ctx->gpr[16] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190B30:
    // 80190B30: bl      0x8008ED08
    {
            ctx->lr = 0x80190B34u;
            ctx->pc = 0x8008ED08u;
            return;
    }

label_80190B34:
    ctx->downcount -= 3;
    // 80190B34: cmpwi   r30, 0
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

label_80190B38:
    ctx->pc = 0x80190B38u;
    // 80190B38: stw     r23, 540(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(540);
        mem_write32(ctx, ea, (u32)ctx->gpr[23]);
    }

label_80190B3C:
    // 80190B3C: bc    4, 2, 0x80190B60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190B60;
        }
    }

label_80190B40:
    ctx->downcount -= 6;
    // 80190B40: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190B44:
    // 80190B44: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80190B48:
    // 80190B48: addi    r4, r9, -16568
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-16568);

label_80190B4C:
    // 80190B4C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190B50:
    // 80190B50: addi    r5, r9, -18884
    ctx->gpr[5] = ctx->gpr[9] + (u32)(s32)(-18884);

label_80190B54:
    // 80190B54: b       0x80190B90
    {
            goto label_80190B90;
    }

label_80190B58:
    ctx->pc = 0x80190B58u;
    ctx->downcount -= 2;
    // 80190B58: stwx    r3, r11, r30
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80190B5C:
    // 80190B5C: b       0x80190C54
    {
            goto label_80190C54;
    }

label_80190B60:
    ctx->downcount -= 7;
    // 80190B60: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190B64:
    // 80190B64: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80190B68:
    // 80190B68: addi    r9, r9, -16532
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-16532);

label_80190B6C:
    ctx->pc = 0x80190B6Cu;
    // 80190B6C: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80190B70:
    // 80190B70: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190B74:
    // 80190B74: addi    r5, r9, -18884
    ctx->gpr[5] = ctx->gpr[9] + (u32)(s32)(-18884);

label_80190B78:
    // 80190B78: bl      0x801D012C
    {
            ctx->lr = 0x80190B7Cu;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80190B7C:
    ctx->downcount -= 5;
    // 80190B7C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190B80:
    // 80190B80: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190B84:
    // 80190B84: addi    r9, r9, -16532
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-16532);

label_80190B88:
    // 80190B88: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80190B8C:
    ctx->pc = 0x80190B8Cu;
    // 80190B8C: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80190B90:
    ctx->downcount -= 1;
    // 80190B90: bl      0x801D012C
    {
            ctx->lr = 0x80190B94u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80190B94:
    ctx->downcount -= 22;
    // 80190B94: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190B98:
    // 80190B98: addi    r9, r24, 1968
    ctx->gpr[9] = ctx->gpr[24] + (u32)(s32)(1968);

label_80190B9C:
    ctx->pc = 0x80190B9Cu;
    // 80190B9C: lwz     r10, 1968(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(1968);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80190BA0:
    ctx->pc = 0x80190BA0u;
    // 80190BA0: lwz     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80190BA4:
    // 80190BA4: lis     r0, 29950
    ctx->gpr[0] = ((u32)(s32)(29950) << 16);

label_80190BA8:
    // 80190BA8: ori     r0, r0, 0xD775
    ctx->gpr[0] = ctx->gpr[0] | 0xD775u;

label_80190BAC:
    // 80190BAC: or   r27, r9, r9
    {
        ctx->gpr[27] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80190BB0:
    // 80190BB0: subf   r11, r10, r11
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[11] = res;
    }

label_80190BB4:
    // 80190BB4: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80190BB8:
    // 80190BB8: mullw   r11, r11, r0
    {
        s64 product = (s64)(s32)ctx->gpr[11] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_80190BBC:
    // 80190BBC: addi    r26, r1, 672
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(672);

label_80190BC0:
    // 80190BC0: lis     r20, -32720
    ctx->gpr[20] = ((u32)(s32)(-32720) << 16);

label_80190BC4:
    // 80190BC4: addi    r22, r24, 4
    ctx->gpr[22] = ctx->gpr[24] + (u32)(s32)(4);

label_80190BC8:
    // 80190BC8: lis     r19, -32720
    ctx->gpr[19] = ((u32)(s32)(-32720) << 16);

label_80190BCC:
    // 80190BCC: lis     r18, -32720
    ctx->gpr[18] = ((u32)(s32)(-32720) << 16);

label_80190BD0:
    // 80190BD0: addi    r17, r23, 1
    ctx->gpr[17] = ctx->gpr[23] + (u32)(s32)(1);

label_80190BD4:
    // 80190BD4: rlwinm. r0, r11, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 30u) & 0x3FFFFFFFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80190BD8:
    // 80190BD8: bc    12, 2, 0x80190C54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190C54;
        }
    }

label_80190BDC:
    ctx->downcount -= 5;
    // 80190BDC: lis     r31, 29950
    ctx->gpr[31] = ((u32)(s32)(29950) << 16);

label_80190BE0:
    // 80190BE0: cmpwi   cr4, r23, 12
    {
        s32 val_a = (s32)(ctx->gpr[23]);
        s32 val_b = (s32)(12);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_80190BE4:
    // 80190BE4: li      r23, 1
    ctx->gpr[23] = (u32)(s32)(1);

label_80190BE8:
    // 80190BE8: ori     r31, r31, 0xD775
    ctx->gpr[31] = ctx->gpr[31] | 0xD775u;

label_80190BEC:
    // 80190BEC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80190BF0:
    ctx->pc = 0x80190BF0u;
    ctx->downcount -= 6;
    // 80190BF0: lwz     r9, 1968(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(1968);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190BF4:
    // 80190BF4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80190BF8:
    // 80190BF8: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_80190BFC:
    // 80190BFC: add   r9, r9, r30
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80190C00:
    ctx->pc = 0x80190C00u;
    // 80190C00: lwz     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80190C04:
    // 80190C04: bl      0x80297FBC
    {
            ctx->lr = 0x80190C08u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80190C08:
    ctx->downcount -= 2;
    // 80190C08: or.   r3, r3, r3
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

label_80190C0C:
    // 80190C0C: bc    4, 2, 0x80190C34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190C34;
        }
    }

label_80190C10:
    ctx->pc = 0x80190C10u;
    ctx->downcount -= 6;
    // 80190C10: lwz     r11, 1968(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(1968);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80190C14:
    ctx->pc = 0x80190C14u;
    // 80190C14: lwz     r9, 1508(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(1508);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190C18:
    // 80190C18: add   r0, r11, r30
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80190C1C:
    ctx->pc = 0x80190C1Cu;
    // 80190C1C: stw     r0, 536(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(536);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80190C20:
    // 80190C20: cmpwi   r9, 0
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

label_80190C24:
    // 80190C24: bc    12, 2, 0x80190C2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190C2C;
        }
    }

label_80190C28:
    ctx->downcount -= 1;
    // 80190C28: bc    12, 18, 0x80190B58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190B58u;
                return;
            }
            goto label_80190B58;
        }
    }

label_80190C2C:
    ctx->pc = 0x80190C2Cu;
    ctx->downcount -= 2;
    // 80190C2C: stwx    r23, r11, r30
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[23]);
    }

label_80190C30:
    // 80190C30: b       0x80190C54
    {
            goto label_80190C54;
    }

label_80190C34:
    ctx->pc = 0x80190C34u;
    ctx->downcount -= 12;
    // 80190C34: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190C38:
    // 80190C38: addi    r30, r30, 884
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(884);

label_80190C3C:
    ctx->pc = 0x80190C3Cu;
    // 80190C3C: lwz     r9, 1968(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(1968);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190C40:
    // 80190C40: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80190C44:
    // 80190C44: mullw   r0, r0, r31
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[31];
        ctx->gpr[0] = (u32)product;
    }

label_80190C48:
    // 80190C48: srawi r0, r0, 2
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

label_80190C4C:
    // 80190C4C: cmplw   r29, r0
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

label_80190C50:
    // 80190C50: bc    12, 0, 0x80190BF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190BF0u;
                return;
            }
            goto label_80190BF0;
        }
    }

label_80190C54:
    ctx->downcount -= 2;
    // 80190C54: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190C58:
    // 80190C58: bl      0x801CFD60
    {
            ctx->lr = 0x80190C5Cu;
            ctx->pc = 0x801CFD60u;
            return;
    }

label_80190C5C:
    ctx->downcount -= 3;
    // 80190C5C: addi    r4, r20, -18048
    ctx->gpr[4] = ctx->gpr[20] + (u32)(s32)(-18048);

label_80190C60:
    // 80190C60: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190C64:
    // 80190C64: bl      0x801CFF5C
    {
            ctx->lr = 0x80190C68u;
            ctx->pc = 0x801CFF5Cu;
            return;
    }

label_80190C68:
    ctx->downcount -= 3;
    // 80190C68: or   r4, r22, r22
    {
        ctx->gpr[4] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80190C6C:
    // 80190C6C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190C70:
    // 80190C70: bl      0x801CFC48
    {
            ctx->lr = 0x80190C74u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80190C74:
    ctx->downcount -= 3;
    // 80190C74: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_80190C78:
    // 80190C78: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190C7C:
    // 80190C7C: bl      0x801CFC48
    {
            ctx->lr = 0x80190C80u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80190C80:
    ctx->downcount -= 3;
    // 80190C80: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80190C84:
    // 80190C84: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190C88:
    // 80190C88: bl      0x801CFC48
    {
            ctx->lr = 0x80190C8Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80190C8C:
    ctx->downcount -= 4;
    // 80190C8C: addi    r4, r18, -16540
    ctx->gpr[4] = ctx->gpr[18] + (u32)(s32)(-16540);

label_80190C90:
    // 80190C90: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190C94:
    // 80190C94: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80190C98:
    // 80190C98: bl      0x801CFFC8
    {
            ctx->lr = 0x80190C9Cu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80190C9C:
    ctx->downcount -= 2;
    // 80190C9C: or.   r30, r3, r3
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

label_80190CA0:
    // 80190CA0: bc    12, 2, 0x80190CCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190CCC;
        }
    }

label_80190CA4:
    ctx->downcount -= 3;
    // 80190CA4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190CA8:
    // 80190CA8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80190CAC:
    // 80190CAC: bl      0x801CFEAC
    {
            ctx->lr = 0x80190CB0u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80190CB0:
    ctx->downcount -= 3;
    // 80190CB0: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80190CB4:
    // 80190CB4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80190CB8:
    // 80190CB8: bl      0x801CFEAC
    {
            ctx->lr = 0x80190CBCu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80190CBC:
    ctx->downcount -= 3;
    // 80190CBC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80190CC0:
    // 80190CC0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80190CC4:
    // 80190CC4: bl      0x801CFEAC
    {
            ctx->lr = 0x80190CC8u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80190CC8:
    ctx->downcount -= 1;
    // 80190CC8: b       0x80190EE8
    {
            goto label_80190EE8;
    }

label_80190CCC:
    ctx->downcount -= 2;
    // 80190CCC: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80190CD0:
    // 80190CD0: bl      0x80281C60
    {
            ctx->lr = 0x80190CD4u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80190CD4:
    ctx->downcount -= 10;
    // 80190CD4: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190CD8:
    // 80190CD8: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_80190CDC:
    ctx->pc = 0x80190CDCu;
    // 80190CDC: stw     r30, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80190CE0:
    // 80190CE0: addi    r5, r1, 280
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(280);

label_80190CE4:
    ctx->pc = 0x80190CE4u;
    // 80190CE4: stw     r9, 668(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(668);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190CE8:
    // 80190CE8: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80190CEC:
    ctx->pc = 0x80190CECu;
    // 80190CEC: stw     r30, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80190CF0:
    // 80190CF0: or   r6, r16, r16
    {
        ctx->gpr[6] = ctx->gpr[16] | ctx->gpr[16];
    }

label_80190CF4:
    ctx->pc = 0x80190CF4u;
    // 80190CF4: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80190CF8:
    // 80190CF8: bl      0x80190F10
    {
            ctx->lr = 0x80190CFCu;
            goto label_80190F10;
    }

label_80190CFC:
    ctx->pc = 0x80190CFCu;
    ctx->downcount -= 7;
    // 80190CFC: lwz     r6, 668(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(668);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80190D00:
    // 80190D00: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80190D04:
    ctx->pc = 0x80190D04u;
    // 80190D04: lwz     r7, 696(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80190D08:
    // 80190D08: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_80190D0C:
    ctx->pc = 0x80190D0Cu;
    // 80190D0C: lwz     r8, 700(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(700);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80190D10:
    // 80190D10: addi    r5, r1, 280
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(280);

label_80190D14:
    // 80190D14: bl      0x801909D8
    {
            ctx->lr = 0x80190D18u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801909D8u;
                return;
            }
            goto label_801909D8;
    }

label_80190D18:
    ctx->pc = 0x80190D18u;
    ctx->downcount -= 8;
    // 80190D18: lwz     r0, 12(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190D1C:
    ctx->pc = 0x80190D1Cu;
    // 80190D1C: lwz     r3, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80190D20:
    ctx->pc = 0x80190D20u;
    // 80190D20: lwz     r9, 696(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(696);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190D24:
    // 80190D24: cmpw    r3, r0
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

label_80190D28:
    ctx->pc = 0x80190D28u;
    // 80190D28: lwz     r0, 700(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(700);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190D2C:
    ctx->pc = 0x80190D2Cu;
    // 80190D2C: stw     r9, 616(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(616);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190D30:
    ctx->pc = 0x80190D30u;
    // 80190D30: stw     r0, 620(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(620);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80190D34:
    // 80190D34: bc    12, 2, 0x80190D58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190D58;
        }
    }

label_80190D38:
    ctx->downcount -= 2;
    // 80190D38: cmpwi   r3, 0
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

label_80190D3C:
    // 80190D3C: bc    12, 2, 0x80190D48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190D48;
        }
    }

label_80190D40:
    ctx->downcount -= 2;
    // 80190D40: or   r4, r16, r16
    {
        ctx->gpr[4] = ctx->gpr[16] | ctx->gpr[16];
    }

label_80190D44:
    // 80190D44: bl      0x80197C38
    {
            ctx->lr = 0x80190D48u;
            ctx->pc = 0x80197C38u;
            return;
    }

label_80190D48:
    ctx->pc = 0x80190D48u;
    ctx->downcount -= 4;
    // 80190D48: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190D4C:
    // 80190D4C: addi    r9, r9, 136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(136);

label_80190D50:
    ctx->pc = 0x80190D50u;
    // 80190D50: stw     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190D54:
    // 80190D54: b       0x80190EC4
    {
            goto label_80190EC4;
    }

label_80190D58:
    ctx->pc = 0x80190D58u;
    ctx->downcount -= 18;
    // 80190D58: lwz     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190D5C:
    // 80190D5C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190D60:
    // 80190D60: lis     r9, -3856
    ctx->gpr[9] = ((u32)(s32)(-3856) << 16);

label_80190D64:
    // 80190D64: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_80190D68:
    // 80190D68: ori     r9, r9, 0xF0F1
    ctx->gpr[9] = ctx->gpr[9] | 0xF0F1u;

label_80190D6C:
    // 80190D6C: subf   r0, r0, r29
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[29];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80190D70:
    // 80190D70: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_80190D74:
    ctx->pc = 0x80190D74u;
    // 80190D74: stw     r11, 692(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(692);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80190D78:
    // 80190D78: addi    r11, r1, 692
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(692);

label_80190D7C:
    // 80190D7C: addi    r10, r1, 688
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(688);

label_80190D80:
    // 80190D80: srawi r9, r0, 3
    {
        u32 sh = 3u;
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

label_80190D84:
    ctx->pc = 0x80190D84u;
    // 80190D84: stw     r9, 688(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(688);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80190D88:
    // 80190D88: cmplwi  r9, 0x0001
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

label_80190D8C:
    // 80190D8C: bc    4, 0, 0x80190D94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190D94;
        }
    }

label_80190D90:
    ctx->downcount -= 1;
    // 80190D90: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80190D94:
    ctx->pc = 0x80190D94u;
    ctx->downcount -= 3;
    // 80190D94: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190D98:
    // 80190D98: add.   r0, r9, r0
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

label_80190D9C:
    // 80190D9C: bc    12, 2, 0x80190DC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190DC8;
        }
    }

label_80190DA0:
    ctx->downcount -= 6;
    // 80190DA0: mulli   r0, r0, 136
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)136);

label_80190DA4:
    // 80190DA4: or   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80190DA8:
    // 80190DA8: cmplwi  r0, 0x0080
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

label_80190DAC:
    // 80190DAC: bc    4, 1, 0x80190DBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190DBC;
        }
    }

label_80190DB0:
    ctx->downcount -= 2;
    // 80190DB0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80190DB4:
    // 80190DB4: bl      0x80281C60
    {
            ctx->lr = 0x80190DB8u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80190DB8:
    ctx->downcount -= 1;
    // 80190DB8: b       0x80190DD0
    {
            goto label_80190DD0;
    }

label_80190DBC:
    ctx->downcount -= 2;
    // 80190DBC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80190DC0:
    // 80190DC0: bl      0x80004024
    {
            ctx->lr = 0x80190DC4u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80190DC4:
    ctx->downcount -= 1;
    // 80190DC4: b       0x80190DD0
    {
            goto label_80190DD0;
    }

label_80190DC8:
    ctx->downcount -= 2;
    // 80190DC8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80190DCC:
    // 80190DCC: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80190DD0:
    ctx->downcount -= 3;
    // 80190DD0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190DD4:
    ctx->pc = 0x80190DD4u;
    // 80190DD4: lwz     r31, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80190DD8:
    // 80190DD8: or   r27, r30, r30
    {
        ctx->gpr[27] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80190DDC:
    ctx->downcount -= 2;
    // 80190DDC: cmpw    r31, r29
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190DE0:
    // 80190DE0: bc    12, 2, 0x80190E04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190E04;
        }
    }

label_80190DE4:
    ctx->downcount -= 6;
    // 80190DE4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80190DE8:
    // 80190DE8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80190DEC:
    // 80190DEC: cmpwi   r30, 0
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

label_80190DF0:
    // 80190DF0: addi    r31, r31, 136
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(136);

label_80190DF4:
    // 80190DF4: addi    r30, r30, 136
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(136);

label_80190DF8:
    // 80190DF8: bc    12, 2, 0x80190DDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190DDCu;
                return;
            }
            goto label_80190DDC;
        }
    }

label_80190DFC:
    ctx->downcount -= 1;
    // 80190DFC: bl      0x80197C38
    {
            ctx->lr = 0x80190E00u;
            ctx->pc = 0x80197C38u;
            return;
    }

label_80190E00:
    ctx->downcount -= 1;
    // 80190E00: b       0x80190DDC
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190DDCu;
                return;
            }
            goto label_80190DDC;
    }

label_80190E04:
    ctx->pc = 0x80190E04u;
    ctx->downcount -= 3;
    // 80190E04: lwz     r0, 692(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(692);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190E08:
    // 80190E08: cmpwi   r0, 1
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

label_80190E0C:
    // 80190E0C: bc    4, 2, 0x80190E2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190E2C;
        }
    }

label_80190E10:
    ctx->downcount -= 2;
    // 80190E10: cmpwi   r30, 0
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

label_80190E14:
    // 80190E14: bc    12, 2, 0x80190E24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190E24;
        }
    }

label_80190E18:
    ctx->downcount -= 3;
    // 80190E18: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80190E1C:
    // 80190E1C: addi    r4, r1, 536
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(536);

label_80190E20:
    // 80190E20: bl      0x80197C38
    {
            ctx->lr = 0x80190E24u;
            ctx->pc = 0x80197C38u;
            return;
    }

label_80190E24:
    ctx->downcount -= 2;
    // 80190E24: addi    r30, r30, 136
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(136);

label_80190E28:
    // 80190E28: b       0x80190E5C
    {
            goto label_80190E5C;
    }

label_80190E2C:
    ctx->downcount -= 3;
    // 80190E2C: or   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80190E30:
    // 80190E30: or.   r30, r0, r0
    {
        ctx->gpr[30] = ctx->gpr[0] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80190E34:
    // 80190E34: bc    12, 2, 0x80190E58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190E58;
        }
    }

label_80190E38:
    ctx->downcount -= 5;
    // 80190E38: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80190E3C:
    // 80190E3C: cmpwi   r31, 0
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

label_80190E40:
    // 80190E40: addi    r4, r1, 536
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(536);

label_80190E44:
    // 80190E44: addi    r31, r31, 136
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(136);

label_80190E48:
    // 80190E48: bc    12, 2, 0x80190E50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190E50;
        }
    }

label_80190E4C:
    ctx->downcount -= 1;
    // 80190E4C: bl      0x80197C38
    {
            ctx->lr = 0x80190E50u;
            ctx->pc = 0x80197C38u;
            return;
    }

label_80190E50:
    ctx->downcount -= 2;
    // 80190E50: addic.  r30, r30, -1
    {
        u64 a = ctx->gpr[30];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[30] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80190E54:
    // 80190E54: bc    4, 2, 0x80190E38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190E38u;
                return;
            }
            goto label_80190E38;
        }
    }

label_80190E58:
    ctx->downcount -= 1;
    // 80190E58: or   r30, r31, r31
    {
        ctx->gpr[30] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80190E5C:
    ctx->pc = 0x80190E5Cu;
    ctx->downcount -= 6;
    // 80190E5C: lwz     r11, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80190E60:
    ctx->pc = 0x80190E60u;
    // 80190E60: lwz     r0, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190E64:
    // 80190E64: or   r3, r11, r11
    {
        ctx->gpr[3] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80190E68:
    ctx->pc = 0x80190E68u;
    // 80190E68: lwz     r9, 12(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190E6C:
    // 80190E6C: cmpw    r11, r0
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

label_80190E70:
    // 80190E70: bc    12, 2, 0x80190E80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190E80;
        }
    }

label_80190E74:
    loop_80190E74(ctx);
    if (ctx->pc == 0x80190E80u) goto label_80190E80;
    return;
label_80190E78:
    // 80190E78: cmpw    r11, r0
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

label_80190E7C:
    // 80190E7C: bc    4, 2, 0x80190E74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190E74u;
                return;
            }
            goto label_80190E74;
        }
    }

label_80190E80:
    ctx->downcount -= 11;
    // 80190E80: lis     r0, -3856
    ctx->gpr[0] = ((u32)(s32)(-3856) << 16);

label_80190E84:
    // 80190E84: subf   r9, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80190E88:
    // 80190E88: ori     r0, r0, 0xF0F1
    ctx->gpr[0] = ctx->gpr[0] | 0xF0F1u;

label_80190E8C:
    // 80190E8C: cmpwi   r3, 0
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

label_80190E90:
    // 80190E90: mullw   r9, r9, r0
    {
        s64 product = (s64)(s32)ctx->gpr[9] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[9] = (u32)product;
    }

label_80190E94:
    // 80190E94: srawi r4, r9, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[9];
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

label_80190E98:
    // 80190E98: bc    12, 2, 0x80190EB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190EB4;
        }
    }

label_80190E9C:
    ctx->downcount -= 5;
    // 80190E9C: mulli   r4, r4, 136
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)136);

label_80190EA0:
    // 80190EA0: cmplwi  r4, 0x0080
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

label_80190EA4:
    // 80190EA4: bc    4, 1, 0x80190EB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80190EB0;
        }
    }

label_80190EA8:
    ctx->downcount -= 1;
    // 80190EA8: bl      0x80281D80
    {
            ctx->lr = 0x80190EACu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80190EAC:
    ctx->downcount -= 1;
    // 80190EAC: b       0x80190EB4
    {
            goto label_80190EB4;
    }

label_80190EB0:
    ctx->downcount -= 1;
    // 80190EB0: bl      0x8001D934
    {
            ctx->lr = 0x80190EB4u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80190EB4:
    ctx->downcount -= 4;
    // 80190EB4: add   r0, r28, r27
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80190EB8:
    ctx->pc = 0x80190EB8u;
    // 80190EB8: stw     r27, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80190EBC:
    ctx->pc = 0x80190EBCu;
    // 80190EBC: stw     r30, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80190EC0:
    ctx->pc = 0x80190EC0u;
    // 80190EC0: stw     r0, 12(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80190EC4:
    ctx->downcount -= 3;
    // 80190EC4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80190EC8:
    // 80190EC8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80190ECC:
    // 80190ECC: bl      0x801CFEAC
    {
            ctx->lr = 0x80190ED0u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80190ED0:
    ctx->downcount -= 3;
    // 80190ED0: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80190ED4:
    // 80190ED4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80190ED8:
    // 80190ED8: bl      0x801CFEAC
    {
            ctx->lr = 0x80190EDCu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80190EDC:
    ctx->downcount -= 3;
    // 80190EDC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80190EE0:
    // 80190EE0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80190EE4:
    // 80190EE4: bl      0x801CFEAC
    {
            ctx->lr = 0x80190EE8u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80190EE8:
    ctx->downcount -= 3;
    // 80190EE8: or   r23, r17, r17
    {
        ctx->gpr[23] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80190EEC:
    // 80190EEC: cmpwi   r23, 19
    {
        s32 val_a = (s32)(ctx->gpr[23]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80190EF0:
    // 80190EF0: bc    4, 2, 0x80190A20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80190A20u;
                return;
            }
            goto label_80190A20;
        }
    }

label_80190EF4:
    ctx->pc = 0x80190EF4u;
    ctx->downcount -= 18;
    // 80190EF4: lwz     r0, 796(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(796);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190EF8:
    ctx->pc = 0x80190EF8u;
    // 80190EF8: lwz     r12, 716(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(716);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80190EFC:
    ctx->pc = 0x80190EFCu;
    // 80190EFC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80190F00:
    ctx->pc = 0x80190F00u;
    // 80190F00: lmw     r14, 720(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(720);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80190F04:
    ctx->pc = 0x80190F04u;
    // 80190F04: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_80190F08:
    ctx->pc = 0x80190F08u;
    // 80190F08: addi    r1, r1, 792
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(792);

label_80190F0C:
    ctx->pc = 0x80190F0Cu;
    // 80190F0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8018F4C0;
        }
    }

label_80190F10:
    ctx->pc = 0x80190F10u;
    ctx->downcount -= 20;
    // 80190F10: stwu     r1, -1072(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-1072);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80190F14:
    ctx->pc = 0x80190F14u;
    // 80190F14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80190F18:
    ctx->pc = 0x80190F18u;
    // 80190F18: stmw     r14, 1000(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1000);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80190F1C:
    ctx->pc = 0x80190F1Cu;
    // 80190F1C: stw     r0, 1076(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1076);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80190F20:
    ctx->pc = 0x80190F20u;
    // 80190F20: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80190F24:
    ctx->pc = 0x80190F24u;
    // 80190F24: stw     r4, 992(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(992);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80190F28:
    ctx->pc = 0x80190F28u;
    // 80190F28: stw     r5, 996(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(996);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80190F2C:
    ctx->pc = 0x80190F2Cu;
    // 80190F2C: or   r31, r6, r6
    {
        ctx->gpr[31] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80190F30:
    ctx->pc = 0x80190F30u;
    // 80190F30: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80190F34:
    ctx->pc = 0x80190F34u;
    // 80190F34: bl      0x801CFE08
    {
            ctx->lr = 0x80190F38u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80190F38:
    ctx->pc = 0x80190F38u;
    ctx->downcount -= 3;
    // 80190F38: lwz     r4, 996(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(996);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80190F3C:
    ctx->pc = 0x80190F3Cu;
    // 80190F3C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80190F40:
    ctx->pc = 0x80190F40u;
    // 80190F40: bl      0x801CFE08
    {
            ctx->lr = 0x80190F44u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80190F44:
    ctx->pc = 0x80190F44u;
    ctx->downcount -= 2;
    // 80190F44: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_80190F48:
    ctx->pc = 0x80190F48u;
    // 80190F48: bl      0x8008E974
    {
            ctx->lr = 0x80190F4Cu;
            ctx->pc = 0x8008E974u;
            return;
    }

label_80190F4C:
    ctx->pc = 0x80190F4Cu;
    ctx->downcount -= 3;
    // 80190F4C: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190F50:
    ctx->pc = 0x80190F50u;
    // 80190F50: cmpwi   r9, 0
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

label_80190F54:
    ctx->pc = 0x80190F54u;
    // 80190F54: bc    12, 2, 0x80190F60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190F60;
        }
    }

label_80190F58:
    ctx->pc = 0x80190F58u;
    ctx->downcount -= 2;
    // 80190F58: lfs     f0, 40(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190F58u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80190F5C:
    ctx->pc = 0x80190F5Cu;
    // 80190F5C: b       0x80190F68
    {
            goto label_80190F68;
    }

label_80190F60:
    ctx->pc = 0x80190F60u;
    ctx->downcount -= 2;
    // 80190F60: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190F64:
    ctx->pc = 0x80190F64u;
    // 80190F64: lfs     f0, -16088(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190F64u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16088);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80190F68:
    ctx->pc = 0x80190F68u;
    ctx->downcount -= 4;
    // 80190F68: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190F6C:
    ctx->pc = 0x80190F6Cu;
    // 80190F6C: stfs     f0, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80190F6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80190F70:
    ctx->pc = 0x80190F70u;
    // 80190F70: cmpwi   r9, 0
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

label_80190F74:
    ctx->pc = 0x80190F74u;
    // 80190F74: bc    12, 2, 0x80190F80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190F80;
        }
    }

label_80190F78:
    ctx->pc = 0x80190F78u;
    ctx->downcount -= 2;
    // 80190F78: lfs     f0, 44(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190F78u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80190F7C:
    ctx->pc = 0x80190F7Cu;
    // 80190F7C: b       0x80190F88
    {
            goto label_80190F88;
    }

label_80190F80:
    ctx->pc = 0x80190F80u;
    ctx->downcount -= 2;
    // 80190F80: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190F84:
    ctx->pc = 0x80190F84u;
    // 80190F84: lfs     f0, -16084(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190F84u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80190F88:
    ctx->pc = 0x80190F88u;
    ctx->downcount -= 4;
    // 80190F88: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190F8C:
    ctx->pc = 0x80190F8Cu;
    // 80190F8C: stfs     f0, 68(r1)
    if (!ppc_fp_available_inline(ctx, 0x80190F8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80190F90:
    ctx->pc = 0x80190F90u;
    // 80190F90: cmpwi   r9, 0
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

label_80190F94:
    ctx->pc = 0x80190F94u;
    // 80190F94: bc    12, 2, 0x80190FA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190FA0;
        }
    }

label_80190F98:
    ctx->pc = 0x80190F98u;
    ctx->downcount -= 2;
    // 80190F98: lfs     f0, 48(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190F98u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80190F9C:
    ctx->pc = 0x80190F9Cu;
    // 80190F9C: b       0x80190FA8
    {
            goto label_80190FA8;
    }

label_80190FA0:
    ctx->pc = 0x80190FA0u;
    ctx->downcount -= 2;
    // 80190FA0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80190FA4:
    ctx->pc = 0x80190FA4u;
    // 80190FA4: lfs     f0, -16088(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190FA4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16088);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80190FA8:
    ctx->pc = 0x80190FA8u;
    ctx->downcount -= 5;
    // 80190FA8: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190FAC:
    ctx->pc = 0x80190FACu;
    // 80190FAC: fmr    f13, f0
    if (!ppc_fp_available_inline(ctx, 0x80190FACu)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_80190FB0:
    ctx->pc = 0x80190FB0u;
    // 80190FB0: stfs     f0, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x80190FB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80190FB4:
    ctx->pc = 0x80190FB4u;
    // 80190FB4: cmpwi   r9, 0
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

label_80190FB8:
    ctx->pc = 0x80190FB8u;
    // 80190FB8: bc    12, 2, 0x80190FC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190FC0;
        }
    }

label_80190FBC:
    ctx->pc = 0x80190FBCu;
    ctx->downcount -= 1;
    // 80190FBC: lfs     f13, 52(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190FBCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80190FC0:
    ctx->pc = 0x80190FC0u;
    ctx->downcount -= 2;
    // 80190FC0: stfs     f13, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x80190FC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80190FC4:
    ctx->pc = 0x80190FC4u;
    // 80190FC4: bc    12, 2, 0x80190FCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190FCC;
        }
    }

label_80190FC8:
    ctx->pc = 0x80190FC8u;
    ctx->downcount -= 1;
    // 80190FC8: lfs     f0, 56(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190FC8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80190FCC:
    ctx->pc = 0x80190FCCu;
    ctx->downcount -= 5;
    // 80190FCC: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80190FD0:
    ctx->pc = 0x80190FD0u;
    // 80190FD0: fmr    f13, f0
    if (!ppc_fp_available_inline(ctx, 0x80190FD0u)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_80190FD4:
    ctx->pc = 0x80190FD4u;
    // 80190FD4: stfs     f0, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x80190FD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80190FD8:
    ctx->pc = 0x80190FD8u;
    // 80190FD8: cmpwi   r9, 0
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

label_80190FDC:
    ctx->pc = 0x80190FDCu;
    // 80190FDC: bc    12, 2, 0x80190FE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190FE4;
        }
    }

label_80190FE0:
    ctx->pc = 0x80190FE0u;
    ctx->downcount -= 1;
    // 80190FE0: lfs     f13, 60(r9)
    if (!ppc_fp_available_inline(ctx, 0x80190FE0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80190FE4:
    ctx->pc = 0x80190FE4u;
    ctx->downcount -= 3;
    // 80190FE4: stfs     f13, 84(r1)
    if (!ppc_fp_available_inline(ctx, 0x80190FE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80190FE8:
    ctx->pc = 0x80190FE8u;
    // 80190FE8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80190FEC:
    ctx->pc = 0x80190FECu;
    // 80190FEC: bc    12, 2, 0x80190FF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80190FF4;
        }
    }

label_80190FF0:
    ctx->pc = 0x80190FF0u;
    ctx->downcount -= 1;
    // 80190FF0: lwz     r0, 116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80190FF4:
    ctx->pc = 0x80190FF4u;
    ctx->downcount -= 3;
    // 80190FF4: stw     r0, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80190FF8:
    ctx->pc = 0x80190FF8u;
    // 80190FF8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80190FFC:
    ctx->pc = 0x80190FFCu;
    // 80190FFC: bc    12, 2, 0x80191004
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191004;
        }
    }

label_80191000:
    ctx->pc = 0x80191000u;
    ctx->downcount -= 1;
    // 80191000: lwz     r0, 880(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(880);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191004:
    ctx->pc = 0x80191004u;
    ctx->downcount -= 3;
    // 80191004: stw     r0, 904(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(904);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191008:
    ctx->pc = 0x80191008u;
    // 80191008: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019100C:
    ctx->pc = 0x8019100Cu;
    // 8019100C: bc    12, 2, 0x80191014
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191014;
        }
    }

label_80191010:
    ctx->pc = 0x80191010u;
    ctx->downcount -= 1;
    // 80191010: lwz     r0, 224(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(224);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191014:
    ctx->pc = 0x80191014u;
    ctx->downcount -= 2;
    // 80191014: stw     r0, 248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191018:
    ctx->pc = 0x80191018u;
    // 80191018: bc    12, 2, 0x80191034
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191034;
        }
    }

label_8019101C:
    ctx->pc = 0x8019101Cu;
    ctx->downcount -= 6;
    // 8019101C: lfs     f13, 120(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019101Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(120);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80191020:
    ctx->pc = 0x80191020u;
    // 80191020: addi    r14, r1, 912
    ctx->gpr[14] = ctx->gpr[1] + (u32)(s32)(912);

label_80191024:
    ctx->pc = 0x80191024u;
    // 80191024: stfs     f13, 912(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191024u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80191028:
    ctx->pc = 0x80191028u;
    // 80191028: lfs     f0, 124(r9)
    if (!ppc_fp_available_inline(ctx, 0x80191028u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019102C:
    ctx->pc = 0x8019102Cu;
    // 8019102C: stfs     f0, 916(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019102Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(916);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191030:
    ctx->pc = 0x80191030u;
    // 80191030: b       0x8019104C
    {
            goto label_8019104C;
    }

label_80191034:
    ctx->pc = 0x80191034u;
    ctx->downcount -= 6;
    // 80191034: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80191038:
    ctx->pc = 0x80191038u;
    // 80191038: addi    r11, r1, 912
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(912);

label_8019103C:
    ctx->pc = 0x8019103Cu;
    // 8019103C: lfs     f0, -16080(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019103Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191040:
    ctx->pc = 0x80191040u;
    // 80191040: or   r14, r11, r11
    {
        ctx->gpr[14] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80191044:
    ctx->pc = 0x80191044u;
    // 80191044: stfs     f0, 912(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191044u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191048:
    ctx->pc = 0x80191048u;
    // 80191048: stfs     f0, 4(r11)
    if (!ppc_fp_available_inline(ctx, 0x80191048u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019104C:
    ctx->pc = 0x8019104Cu;
    ctx->downcount -= 9;
    // 8019104C: lwz     r0, 912(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191050:
    ctx->pc = 0x80191050u;
    // 80191050: addi    r10, r1, 144
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(144);

label_80191054:
    ctx->pc = 0x80191054u;
    // 80191054: lwz     r8, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80191058:
    ctx->pc = 0x80191058u;
    // 80191058: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8019105C:
    ctx->pc = 0x8019105Cu;
    // 8019105C: lwz     r9, 4(r14)
    {
        u32 ea = ctx->gpr[14] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191060:
    ctx->pc = 0x80191060u;
    // 80191060: stw     r0, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191064:
    ctx->pc = 0x80191064u;
    // 80191064: cmpwi   r8, 0
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191068:
    ctx->pc = 0x80191068u;
    // 80191068: stw     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019106C:
    ctx->pc = 0x8019106Cu;
    // 8019106C: bc    12, 2, 0x80191074
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191074;
        }
    }

label_80191070:
    ctx->pc = 0x80191070u;
    ctx->downcount -= 1;
    // 80191070: addi    r11, r8, 128
    ctx->gpr[11] = ctx->gpr[8] + (u32)(s32)(128);

label_80191074:
    ctx->pc = 0x80191074u;
    ctx->downcount -= 5;
    // 80191074: lwz     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191078:
    ctx->pc = 0x80191078u;
    // 80191078: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019107C:
    ctx->pc = 0x8019107Cu;
    // 8019107C: stw     r9, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80191080:
    ctx->pc = 0x80191080u;
    // 80191080: stw     r0, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191084:
    ctx->pc = 0x80191084u;
    // 80191084: bc    12, 2, 0x8019108C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019108C;
        }
    }

label_80191088:
    ctx->pc = 0x80191088u;
    ctx->downcount -= 1;
    // 80191088: addi    r10, r8, 152
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(152);

label_8019108C:
    ctx->pc = 0x8019108Cu;
    ctx->downcount -= 7;
    // 8019108C: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191090:
    ctx->pc = 0x80191090u;
    // 80191090: addi    r9, r1, 176
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(176);

label_80191094:
    ctx->pc = 0x80191094u;
    // 80191094: lwz     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80191098:
    ctx->pc = 0x80191098u;
    // 80191098: stw     r0, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019109C:
    ctx->pc = 0x8019109Cu;
    // 8019109C: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801910A0:
    ctx->pc = 0x801910A0u;
    // 801910A0: stw     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801910A4:
    ctx->pc = 0x801910A4u;
    // 801910A4: bc    12, 2, 0x801910AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801910AC;
        }
    }

label_801910A8:
    ctx->pc = 0x801910A8u;
    ctx->downcount -= 1;
    // 801910A8: addi    r10, r8, 160
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(160);

label_801910AC:
    ctx->pc = 0x801910ACu;
    ctx->downcount -= 7;
    // 801910AC: lwz     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801910B0:
    ctx->pc = 0x801910B0u;
    // 801910B0: addi    r11, r1, 192
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(192);

label_801910B4:
    ctx->pc = 0x801910B4u;
    // 801910B4: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801910B8:
    ctx->pc = 0x801910B8u;
    // 801910B8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801910BC:
    ctx->pc = 0x801910BCu;
    // 801910BC: stw     r9, 188(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801910C0:
    ctx->pc = 0x801910C0u;
    // 801910C0: stw     r0, 184(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801910C4:
    ctx->pc = 0x801910C4u;
    // 801910C4: bc    12, 2, 0x801910CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801910CC;
        }
    }

label_801910C8:
    ctx->pc = 0x801910C8u;
    ctx->downcount -= 1;
    // 801910C8: addi    r11, r8, 168
    ctx->gpr[11] = ctx->gpr[8] + (u32)(s32)(168);

label_801910CC:
    ctx->pc = 0x801910CCu;
    ctx->downcount -= 5;
    // 801910CC: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801910D0:
    ctx->pc = 0x801910D0u;
    // 801910D0: lwz     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801910D4:
    ctx->pc = 0x801910D4u;
    // 801910D4: stw     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801910D8:
    ctx->pc = 0x801910D8u;
    // 801910D8: stw     r9, 192(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801910DC:
    ctx->pc = 0x801910DCu;
    // 801910DC: bc    12, 2, 0x801910F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801910F4;
        }
    }

label_801910E0:
    ctx->pc = 0x801910E0u;
    ctx->downcount -= 5;
    // 801910E0: lfs     f0, 136(r8)
    if (!ppc_fp_available_inline(ctx, 0x801910E0u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(136);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801910E4:
    ctx->pc = 0x801910E4u;
    // 801910E4: stfs     f0, 912(r1)
    if (!ppc_fp_available_inline(ctx, 0x801910E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801910E8:
    ctx->pc = 0x801910E8u;
    // 801910E8: lfs     f13, 140(r8)
    if (!ppc_fp_available_inline(ctx, 0x801910E8u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(140);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801910EC:
    ctx->pc = 0x801910ECu;
    // 801910EC: stfs     f13, 916(r1)
    if (!ppc_fp_available_inline(ctx, 0x801910ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(916);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801910F0:
    ctx->pc = 0x801910F0u;
    // 801910F0: b       0x80191104
    {
            goto label_80191104;
    }

label_801910F4:
    ctx->pc = 0x801910F4u;
    ctx->downcount -= 4;
    // 801910F4: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801910F8:
    ctx->pc = 0x801910F8u;
    // 801910F8: lfs     f0, -16080(r9)
    if (!ppc_fp_available_inline(ctx, 0x801910F8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801910FC:
    ctx->pc = 0x801910FCu;
    // 801910FC: stfs     f0, 912(r1)
    if (!ppc_fp_available_inline(ctx, 0x801910FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191100:
    ctx->pc = 0x80191100u;
    // 80191100: stfs     f0, 4(r14)
    if (!ppc_fp_available_inline(ctx, 0x80191100u)) return;
    {
        u32 ea = ctx->gpr[14] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191104:
    ctx->pc = 0x80191104u;
    ctx->downcount -= 7;
    // 80191104: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80191108:
    ctx->pc = 0x80191108u;
    // 80191108: lwz     r9, 4(r14)
    {
        u32 ea = ctx->gpr[14] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019110C:
    ctx->pc = 0x8019110Cu;
    // 8019110C: lwz     r0, 912(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191110:
    ctx->pc = 0x80191110u;
    // 80191110: cmpwi   r11, 0
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

label_80191114:
    ctx->pc = 0x80191114u;
    // 80191114: stw     r9, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80191118:
    ctx->pc = 0x80191118u;
    // 80191118: stw     r0, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019111C:
    ctx->pc = 0x8019111Cu;
    // 8019111C: bc    12, 2, 0x80191134
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191134;
        }
    }

label_80191120:
    ctx->pc = 0x80191120u;
    ctx->downcount -= 5;
    // 80191120: lfs     f0, 144(r11)
    if (!ppc_fp_available_inline(ctx, 0x80191120u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191124:
    ctx->pc = 0x80191124u;
    // 80191124: stfs     f0, 912(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191124u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191128:
    ctx->pc = 0x80191128u;
    // 80191128: lfs     f13, 148(r11)
    if (!ppc_fp_available_inline(ctx, 0x80191128u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(148);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8019112C:
    ctx->pc = 0x8019112Cu;
    // 8019112C: stfs     f13, 916(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019112Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(916);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80191130:
    ctx->pc = 0x80191130u;
    // 80191130: b       0x8019114C
    {
            goto label_8019114C;
    }

label_80191134:
    ctx->pc = 0x80191134u;
    ctx->downcount -= 6;
    // 80191134: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80191138:
    ctx->pc = 0x80191138u;
    // 80191138: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_8019113C:
    ctx->pc = 0x8019113Cu;
    // 8019113C: lfs     f0, -16088(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019113Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16088);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191140:
    ctx->pc = 0x80191140u;
    // 80191140: lfs     f13, -16080(r11)
    if (!ppc_fp_available_inline(ctx, 0x80191140u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80191144:
    ctx->pc = 0x80191144u;
    // 80191144: stfs     f0, 912(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191144u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191148:
    ctx->pc = 0x80191148u;
    // 80191148: stfs     f13, 4(r14)
    if (!ppc_fp_available_inline(ctx, 0x80191148u)) return;
    {
        u32 ea = ctx->gpr[14] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8019114C:
    ctx->pc = 0x8019114Cu;
    ctx->downcount -= 7;
    // 8019114C: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80191150:
    ctx->pc = 0x80191150u;
    // 80191150: lwz     r9, 4(r14)
    {
        u32 ea = ctx->gpr[14] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191154:
    ctx->pc = 0x80191154u;
    // 80191154: lwz     r0, 912(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(912);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191158:
    ctx->pc = 0x80191158u;
    // 80191158: cmpwi   r11, 0
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

label_8019115C:
    ctx->pc = 0x8019115Cu;
    // 8019115C: stw     r9, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80191160:
    ctx->pc = 0x80191160u;
    // 80191160: stw     r0, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191164:
    ctx->pc = 0x80191164u;
    // 80191164: bc    12, 2, 0x80191170
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191170;
        }
    }

label_80191168:
    ctx->pc = 0x80191168u;
    ctx->downcount -= 2;
    // 80191168: lfs     f0, 108(r11)
    if (!ppc_fp_available_inline(ctx, 0x80191168u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(108);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019116C:
    ctx->pc = 0x8019116Cu;
    // 8019116C: b       0x80191178
    {
            goto label_80191178;
    }

label_80191170:
    ctx->pc = 0x80191170u;
    ctx->downcount -= 2;
    // 80191170: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80191174:
    ctx->pc = 0x80191174u;
    // 80191174: lfs     f0, -16076(r9)
    if (!ppc_fp_available_inline(ctx, 0x80191174u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16076);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191178:
    ctx->pc = 0x80191178u;
    ctx->downcount -= 4;
    // 80191178: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019117C:
    ctx->pc = 0x8019117Cu;
    // 8019117C: stfs     f0, 132(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019117Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191180:
    ctx->pc = 0x80191180u;
    // 80191180: cmpwi   r3, 0
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

label_80191184:
    ctx->pc = 0x80191184u;
    // 80191184: bc    12, 2, 0x80191190
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191190;
        }
    }

label_80191188:
    ctx->pc = 0x80191188u;
    ctx->downcount -= 2;
    // 80191188: lwz     r3, 288(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(288);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019118C:
    ctx->pc = 0x8019118Cu;
    // 8019118C: b       0x801911A0
    {
            goto label_801911A0;
    }

label_80191190:
    ctx->pc = 0x80191190u;
    ctx->downcount -= 4;
    // 80191190: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80191194:
    ctx->pc = 0x80191194u;
    // 80191194: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191198:
    ctx->pc = 0x80191198u;
    // 80191198: addi    r4, r4, -16528
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16528);

label_8019119C:
    ctx->pc = 0x8019119Cu;
    // 8019119C: bl      0x8019862C
    {
            ctx->lr = 0x801911A0u;
            ctx->pc = 0x8019862Cu;
            return;
    }

label_801911A0:
    ctx->pc = 0x801911A0u;
    ctx->downcount -= 4;
    // 801911A0: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801911A4:
    ctx->pc = 0x801911A4u;
    // 801911A4: stw     r3, 312(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801911A8:
    ctx->pc = 0x801911A8u;
    // 801911A8: cmpwi   r9, 0
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

label_801911AC:
    ctx->pc = 0x801911ACu;
    // 801911AC: bc    12, 2, 0x801911B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801911B8;
        }
    }

label_801911B0:
    ctx->pc = 0x801911B0u;
    ctx->downcount -= 2;
    // 801911B0: lfs     f0, 292(r9)
    if (!ppc_fp_available_inline(ctx, 0x801911B0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(292);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801911B4:
    ctx->pc = 0x801911B4u;
    // 801911B4: b       0x801911C0
    {
            goto label_801911C0;
    }

label_801911B8:
    ctx->pc = 0x801911B8u;
    ctx->downcount -= 2;
    // 801911B8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801911BC:
    ctx->pc = 0x801911BCu;
    // 801911BC: lfs     f0, -16080(r9)
    if (!ppc_fp_available_inline(ctx, 0x801911BCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801911C0:
    ctx->pc = 0x801911C0u;
    ctx->downcount -= 4;
    // 801911C0: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801911C4:
    ctx->pc = 0x801911C4u;
    // 801911C4: stfs     f0, 316(r1)
    if (!ppc_fp_available_inline(ctx, 0x801911C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(316);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801911C8:
    ctx->pc = 0x801911C8u;
    // 801911C8: cmpwi   r9, 0
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

label_801911CC:
    ctx->pc = 0x801911CCu;
    // 801911CC: bc    12, 2, 0x801911D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801911D8;
        }
    }

label_801911D0:
    ctx->pc = 0x801911D0u;
    ctx->downcount -= 2;
    // 801911D0: lfs     f0, 324(r9)
    if (!ppc_fp_available_inline(ctx, 0x801911D0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(324);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801911D4:
    ctx->pc = 0x801911D4u;
    // 801911D4: b       0x801911E0
    {
            goto label_801911E0;
    }

label_801911D8:
    ctx->pc = 0x801911D8u;
    ctx->downcount -= 2;
    // 801911D8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801911DC:
    ctx->pc = 0x801911DCu;
    // 801911DC: lfs     f0, -16072(r9)
    if (!ppc_fp_available_inline(ctx, 0x801911DCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16072);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801911E0:
    ctx->pc = 0x801911E0u;
    ctx->downcount -= 4;
    // 801911E0: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801911E4:
    ctx->pc = 0x801911E4u;
    // 801911E4: stfs     f0, 348(r1)
    if (!ppc_fp_available_inline(ctx, 0x801911E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(348);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801911E8:
    ctx->pc = 0x801911E8u;
    // 801911E8: cmpwi   r9, 0
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

label_801911EC:
    ctx->pc = 0x801911ECu;
    // 801911EC: bc    12, 2, 0x801911F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801911F8;
        }
    }

label_801911F0:
    ctx->pc = 0x801911F0u;
    ctx->downcount -= 2;
    // 801911F0: lfs     f0, 328(r9)
    if (!ppc_fp_available_inline(ctx, 0x801911F0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(328);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801911F4:
    ctx->pc = 0x801911F4u;
    // 801911F4: b       0x80191200
    {
            goto label_80191200;
    }

label_801911F8:
    ctx->pc = 0x801911F8u;
    ctx->downcount -= 2;
    // 801911F8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801911FC:
    ctx->pc = 0x801911FCu;
    // 801911FC: lfs     f0, -16068(r9)
    if (!ppc_fp_available_inline(ctx, 0x801911FCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16068);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191200:
    ctx->pc = 0x80191200u;
    ctx->downcount -= 5;
    // 80191200: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191204:
    ctx->pc = 0x80191204u;
    // 80191204: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80191208:
    ctx->pc = 0x80191208u;
    // 80191208: stfs     f0, 352(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191208u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(352);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019120C:
    ctx->pc = 0x8019120Cu;
    // 8019120C: cmpwi   r9, 0
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

label_80191210:
    ctx->pc = 0x80191210u;
    // 80191210: bc    12, 2, 0x80191218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191218;
        }
    }

label_80191214:
    ctx->pc = 0x80191214u;
    ctx->downcount -= 1;
    // 80191214: lwz     r0, 332(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(332);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191218:
    ctx->pc = 0x80191218u;
    ctx->downcount -= 2;
    // 80191218: stw     r0, 356(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(356);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019121C:
    ctx->pc = 0x8019121Cu;
    // 8019121C: bc    12, 2, 0x80191228
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191228;
        }
    }

label_80191220:
    ctx->pc = 0x80191220u;
    ctx->downcount -= 2;
    // 80191220: lfs     f0, 336(r9)
    if (!ppc_fp_available_inline(ctx, 0x80191220u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(336);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191224:
    ctx->pc = 0x80191224u;
    // 80191224: b       0x80191230
    {
            goto label_80191230;
    }

label_80191228:
    ctx->pc = 0x80191228u;
    ctx->downcount -= 2;
    // 80191228: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8019122C:
    ctx->pc = 0x8019122Cu;
    // 8019122C: lfs     f0, -16064(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019122Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16064);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191230:
    ctx->pc = 0x80191230u;
    ctx->downcount -= 5;
    // 80191230: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191234:
    ctx->pc = 0x80191234u;
    // 80191234: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80191238:
    ctx->pc = 0x80191238u;
    // 80191238: stfs     f0, 360(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191238u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(360);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019123C:
    ctx->pc = 0x8019123Cu;
    // 8019123C: cmpwi   r9, 0
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

label_80191240:
    ctx->pc = 0x80191240u;
    // 80191240: bc    12, 2, 0x80191248
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191248;
        }
    }

label_80191244:
    ctx->pc = 0x80191244u;
    ctx->downcount -= 1;
    // 80191244: lwz     r0, 340(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(340);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191248:
    ctx->pc = 0x80191248u;
    ctx->downcount -= 3;
    // 80191248: stw     r0, 364(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(364);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019124C:
    ctx->pc = 0x8019124Cu;
    // 8019124C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80191250:
    ctx->pc = 0x80191250u;
    // 80191250: bc    12, 2, 0x80191258
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191258;
        }
    }

label_80191254:
    ctx->pc = 0x80191254u;
    ctx->downcount -= 1;
    // 80191254: lwz     r0, 296(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(296);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191258:
    ctx->pc = 0x80191258u;
    ctx->downcount -= 2;
    // 80191258: stw     r0, 320(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019125C:
    ctx->pc = 0x8019125Cu;
    // 8019125C: bc    12, 2, 0x80191268
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191268;
        }
    }

label_80191260:
    ctx->pc = 0x80191260u;
    ctx->downcount -= 2;
    // 80191260: lfs     f0, 300(r9)
    if (!ppc_fp_available_inline(ctx, 0x80191260u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(300);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191264:
    ctx->pc = 0x80191264u;
    // 80191264: b       0x80191270
    {
            goto label_80191270;
    }

label_80191268:
    ctx->pc = 0x80191268u;
    ctx->downcount -= 2;
    // 80191268: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8019126C:
    ctx->pc = 0x8019126Cu;
    // 8019126C: lfs     f0, -16060(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019126Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16060);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191270:
    ctx->pc = 0x80191270u;
    ctx->downcount -= 4;
    // 80191270: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191274:
    ctx->pc = 0x80191274u;
    // 80191274: stfs     f0, 324(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191274u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(324);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191278:
    ctx->pc = 0x80191278u;
    // 80191278: cmpwi   r9, 0
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

label_8019127C:
    ctx->pc = 0x8019127Cu;
    // 8019127C: bc    12, 2, 0x80191288
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191288;
        }
    }

label_80191280:
    ctx->pc = 0x80191280u;
    ctx->downcount -= 2;
    // 80191280: lfs     f0, 304(r9)
    if (!ppc_fp_available_inline(ctx, 0x80191280u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(304);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191284:
    ctx->pc = 0x80191284u;
    // 80191284: b       0x80191290
    {
            goto label_80191290;
    }

label_80191288:
    ctx->pc = 0x80191288u;
    ctx->downcount -= 2;
    // 80191288: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8019128C:
    ctx->pc = 0x8019128Cu;
    // 8019128C: lfs     f0, -16080(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019128Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80191290:
    ctx->pc = 0x80191290u;
    ctx->downcount -= 4;
    // 80191290: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191294:
    ctx->pc = 0x80191294u;
    // 80191294: stfs     f0, 328(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191294u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80191298:
    ctx->pc = 0x80191298u;
    // 80191298: cmpwi   r9, 0
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

label_8019129C:
    ctx->pc = 0x8019129Cu;
    // 8019129C: bc    12, 2, 0x801912A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801912A8;
        }
    }

label_801912A0:
    ctx->pc = 0x801912A0u;
    ctx->downcount -= 2;
    // 801912A0: lfs     f0, 308(r9)
    if (!ppc_fp_available_inline(ctx, 0x801912A0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(308);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801912A4:
    ctx->pc = 0x801912A4u;
    // 801912A4: b       0x801912B0
    {
            goto label_801912B0;
    }

label_801912A8:
    ctx->pc = 0x801912A8u;
    ctx->downcount -= 2;
    // 801912A8: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801912AC:
    ctx->pc = 0x801912ACu;
    // 801912AC: lfs     f0, -16080(r9)
    if (!ppc_fp_available_inline(ctx, 0x801912ACu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801912B0:
    ctx->pc = 0x801912B0u;
    ctx->downcount -= 5;
    // 801912B0: lwz     r9, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801912B4:
    ctx->pc = 0x801912B4u;
    // 801912B4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801912B8:
    ctx->pc = 0x801912B8u;
    // 801912B8: stfs     f0, 332(r1)
    if (!ppc_fp_available_inline(ctx, 0x801912B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(332);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801912BC:
    ctx->pc = 0x801912BCu;
    // 801912BC: cmpwi   r9, 0
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

label_801912C0:
    ctx->pc = 0x801912C0u;
    // 801912C0: bc    12, 2, 0x801912C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801912C8;
        }
    }

label_801912C4:
    ctx->pc = 0x801912C4u;
    ctx->downcount -= 1;
    // 801912C4: lwz     r0, 312(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(312);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801912C8:
    ctx->pc = 0x801912C8u;
    ctx->downcount -= 3;
    // 801912C8: stw     r0, 336(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(336);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801912CC:
    ctx->pc = 0x801912CCu;
    // 801912CC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801912D0:
    ctx->pc = 0x801912D0u;
    // 801912D0: bc    12, 2, 0x801912D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801912D8;
        }
    }

label_801912D4:
    ctx->pc = 0x801912D4u;
    ctx->downcount -= 1;
    // 801912D4: lwz     r0, 316(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(316);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801912D8:
    ctx->pc = 0x801912D8u;
    ctx->downcount -= 3;
    // 801912D8: stw     r0, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801912DC:
    ctx->pc = 0x801912DCu;
    // 801912DC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801912E0:
    ctx->pc = 0x801912E0u;
    // 801912E0: bc    12, 2, 0x801912E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801912E8;
        }
    }

label_801912E4:
    ctx->pc = 0x801912E4u;
    ctx->downcount -= 1;
    // 801912E4: lwz     r0, 320(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(320);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801912E8:
    ctx->pc = 0x801912E8u;
    ctx->downcount -= 7;
    // 801912E8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801912EC:
    ctx->pc = 0x801912ECu;
    // 801912EC: lfs     f1, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x801912ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801912F0:
    ctx->pc = 0x801912F0u;
    // 801912F0: addi    r30, r30, -16520
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16520);

label_801912F4:
    ctx->pc = 0x801912F4u;
    // 801912F4: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801912F8:
    ctx->pc = 0x801912F8u;
    // 801912F8: stw     r0, 344(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(344);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801912FC:
    ctx->pc = 0x801912FCu;
    // 801912FC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191300:
    ctx->pc = 0x80191300u;
    // 80191300: bl      0x801D009C
    {
            ctx->lr = 0x80191304u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191304:
    ctx->pc = 0x80191304u;
    ctx->downcount -= 4;
    // 80191304: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_80191308:
    ctx->pc = 0x80191308u;
    // 80191308: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019130C:
    ctx->pc = 0x8019130Cu;
    // 8019130C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191310:
    ctx->pc = 0x80191310u;
    // 80191310: bl      0x801D009C
    {
            ctx->lr = 0x80191314u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191314:
    ctx->pc = 0x80191314u;
    ctx->downcount -= 7;
    // 80191314: stfs     f1, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191314u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191318:
    ctx->pc = 0x80191318u;
    // 80191318: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019131C:
    ctx->pc = 0x8019131Cu;
    // 8019131C: lfs     f1, 68(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019131Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191320:
    ctx->pc = 0x80191320u;
    // 80191320: addi    r30, r30, -16508
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16508);

label_80191324:
    ctx->pc = 0x80191324u;
    // 80191324: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191328:
    ctx->pc = 0x80191328u;
    // 80191328: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019132C:
    ctx->pc = 0x8019132Cu;
    // 8019132C: bl      0x801D009C
    {
            ctx->lr = 0x80191330u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191330:
    ctx->pc = 0x80191330u;
    ctx->downcount -= 3;
    // 80191330: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191334:
    ctx->pc = 0x80191334u;
    // 80191334: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191338:
    ctx->pc = 0x80191338u;
    // 80191338: bl      0x801D009C
    {
            ctx->lr = 0x8019133Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019133C:
    ctx->pc = 0x8019133Cu;
    ctx->downcount -= 7;
    // 8019133C: stfs     f1, 12(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019133Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191340:
    ctx->pc = 0x80191340u;
    // 80191340: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191344:
    ctx->pc = 0x80191344u;
    // 80191344: lfs     f1, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191344u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191348:
    ctx->pc = 0x80191348u;
    // 80191348: addi    r30, r30, -16496
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16496);

label_8019134C:
    ctx->pc = 0x8019134Cu;
    // 8019134C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191350:
    ctx->pc = 0x80191350u;
    // 80191350: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191354:
    ctx->pc = 0x80191354u;
    // 80191354: bl      0x801D009C
    {
            ctx->lr = 0x80191358u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191358:
    ctx->pc = 0x80191358u;
    ctx->downcount -= 3;
    // 80191358: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019135C:
    ctx->pc = 0x8019135Cu;
    // 8019135C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191360:
    ctx->pc = 0x80191360u;
    // 80191360: bl      0x801D009C
    {
            ctx->lr = 0x80191364u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191364:
    ctx->pc = 0x80191364u;
    ctx->downcount -= 7;
    // 80191364: stfs     f1, 16(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191364u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191368:
    ctx->pc = 0x80191368u;
    // 80191368: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019136C:
    ctx->pc = 0x8019136Cu;
    // 8019136C: lfs     f1, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019136Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191370:
    ctx->pc = 0x80191370u;
    // 80191370: addi    r30, r30, -16488
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16488);

label_80191374:
    ctx->pc = 0x80191374u;
    // 80191374: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191378:
    ctx->pc = 0x80191378u;
    // 80191378: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019137C:
    ctx->pc = 0x8019137Cu;
    // 8019137C: bl      0x801D009C
    {
            ctx->lr = 0x80191380u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191380:
    ctx->pc = 0x80191380u;
    ctx->downcount -= 3;
    // 80191380: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191384:
    ctx->pc = 0x80191384u;
    // 80191384: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191388:
    ctx->pc = 0x80191388u;
    // 80191388: bl      0x801D009C
    {
            ctx->lr = 0x8019138Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019138C:
    ctx->pc = 0x8019138Cu;
    ctx->downcount -= 7;
    // 8019138C: stfs     f1, 120(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019138Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191390:
    ctx->pc = 0x80191390u;
    // 80191390: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191394:
    ctx->pc = 0x80191394u;
    // 80191394: lfs     f1, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191394u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191398:
    ctx->pc = 0x80191398u;
    // 80191398: addi    r30, r30, -16476
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16476);

label_8019139C:
    ctx->pc = 0x8019139Cu;
    // 8019139C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801913A0:
    ctx->pc = 0x801913A0u;
    // 801913A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801913A4:
    ctx->pc = 0x801913A4u;
    // 801913A4: bl      0x801D009C
    {
            ctx->lr = 0x801913A8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801913A8:
    ctx->pc = 0x801913A8u;
    ctx->downcount -= 3;
    // 801913A8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801913AC:
    ctx->pc = 0x801913ACu;
    // 801913AC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801913B0:
    ctx->pc = 0x801913B0u;
    // 801913B0: bl      0x801D009C
    {
            ctx->lr = 0x801913B4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801913B4:
    ctx->pc = 0x801913B4u;
    ctx->downcount -= 7;
    // 801913B4: stfs     f1, 20(r31)
    if (!ppc_fp_available_inline(ctx, 0x801913B4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801913B8:
    ctx->pc = 0x801913B8u;
    // 801913B8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801913BC:
    ctx->pc = 0x801913BCu;
    // 801913BC: lfs     f1, 84(r1)
    if (!ppc_fp_available_inline(ctx, 0x801913BCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801913C0:
    ctx->pc = 0x801913C0u;
    // 801913C0: addi    r30, r30, -16464
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16464);

label_801913C4:
    ctx->pc = 0x801913C4u;
    // 801913C4: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801913C8:
    ctx->pc = 0x801913C8u;
    // 801913C8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801913CC:
    ctx->pc = 0x801913CCu;
    // 801913CC: bl      0x801D009C
    {
            ctx->lr = 0x801913D0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801913D0:
    ctx->pc = 0x801913D0u;
    ctx->downcount -= 3;
    // 801913D0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801913D4:
    ctx->pc = 0x801913D4u;
    // 801913D4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801913D8:
    ctx->pc = 0x801913D8u;
    // 801913D8: bl      0x801D009C
    {
            ctx->lr = 0x801913DCu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801913DC:
    ctx->pc = 0x801913DCu;
    ctx->downcount -= 7;
    // 801913DC: stfs     f1, 24(r31)
    if (!ppc_fp_available_inline(ctx, 0x801913DCu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801913E0:
    ctx->pc = 0x801913E0u;
    // 801913E0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801913E4:
    ctx->pc = 0x801913E4u;
    // 801913E4: lfs     f1, 348(r1)
    if (!ppc_fp_available_inline(ctx, 0x801913E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(348);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801913E8:
    ctx->pc = 0x801913E8u;
    // 801913E8: addi    r30, r30, -16452
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16452);

label_801913EC:
    ctx->pc = 0x801913ECu;
    // 801913EC: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801913F0:
    ctx->pc = 0x801913F0u;
    // 801913F0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801913F4:
    ctx->pc = 0x801913F4u;
    // 801913F4: bl      0x801D009C
    {
            ctx->lr = 0x801913F8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801913F8:
    ctx->pc = 0x801913F8u;
    ctx->downcount -= 3;
    // 801913F8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801913FC:
    ctx->pc = 0x801913FCu;
    // 801913FC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191400:
    ctx->pc = 0x80191400u;
    // 80191400: bl      0x801D009C
    {
            ctx->lr = 0x80191404u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191404:
    ctx->pc = 0x80191404u;
    ctx->downcount -= 7;
    // 80191404: stfs     f1, 96(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191404u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191408:
    ctx->pc = 0x80191408u;
    // 80191408: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019140C:
    ctx->pc = 0x8019140Cu;
    // 8019140C: lfs     f1, 352(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019140Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(352);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191410:
    ctx->pc = 0x80191410u;
    // 80191410: addi    r30, r30, -16440
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16440);

label_80191414:
    ctx->pc = 0x80191414u;
    // 80191414: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191418:
    ctx->pc = 0x80191418u;
    // 80191418: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019141C:
    ctx->pc = 0x8019141Cu;
    // 8019141C: bl      0x801D009C
    {
            ctx->lr = 0x80191420u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191420:
    ctx->pc = 0x80191420u;
    ctx->downcount -= 3;
    // 80191420: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191424:
    ctx->pc = 0x80191424u;
    // 80191424: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191428:
    ctx->pc = 0x80191428u;
    // 80191428: bl      0x801D009C
    {
            ctx->lr = 0x8019142Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019142C:
    ctx->pc = 0x8019142Cu;
    ctx->downcount -= 7;
    // 8019142C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191430:
    ctx->pc = 0x80191430u;
    // 80191430: lwz     r5, 356(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(356);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80191434:
    ctx->pc = 0x80191434u;
    // 80191434: addi    r30, r30, -16428
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16428);

label_80191438:
    ctx->pc = 0x80191438u;
    // 80191438: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8019143C:
    ctx->pc = 0x8019143Cu;
    // 8019143C: stfs     f1, 100(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019143Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(100);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191440:
    ctx->pc = 0x80191440u;
    // 80191440: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191444:
    ctx->pc = 0x80191444u;
    // 80191444: bl      0x801CFFC8
    {
            ctx->lr = 0x80191448u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80191448:
    ctx->pc = 0x80191448u;
    ctx->downcount -= 4;
    // 80191448: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019144C:
    ctx->pc = 0x8019144Cu;
    // 8019144C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191450:
    ctx->pc = 0x80191450u;
    // 80191450: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191454:
    ctx->pc = 0x80191454u;
    // 80191454: bl      0x801CFFC8
    {
            ctx->lr = 0x80191458u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80191458:
    ctx->pc = 0x80191458u;
    ctx->downcount -= 7;
    // 80191458: stw     r3, 104(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019145C:
    ctx->pc = 0x8019145Cu;
    // 8019145C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191460:
    ctx->pc = 0x80191460u;
    // 80191460: addi    r30, r30, -16404
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16404);

label_80191464:
    ctx->pc = 0x80191464u;
    // 80191464: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191468:
    ctx->pc = 0x80191468u;
    // 80191468: lfs     f1, 360(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191468u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(360);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8019146C:
    ctx->pc = 0x8019146Cu;
    // 8019146C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191470:
    ctx->pc = 0x80191470u;
    // 80191470: bl      0x801D009C
    {
            ctx->lr = 0x80191474u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191474:
    ctx->pc = 0x80191474u;
    ctx->downcount -= 3;
    // 80191474: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191478:
    ctx->pc = 0x80191478u;
    // 80191478: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8019147C:
    ctx->pc = 0x8019147Cu;
    // 8019147C: bl      0x801D009C
    {
            ctx->lr = 0x80191480u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191480:
    ctx->pc = 0x80191480u;
    ctx->downcount -= 7;
    // 80191480: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191484:
    ctx->pc = 0x80191484u;
    // 80191484: lwz     r5, 364(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(364);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80191488:
    ctx->pc = 0x80191488u;
    // 80191488: addi    r30, r30, -16388
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16388);

label_8019148C:
    ctx->pc = 0x8019148Cu;
    // 8019148C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191490:
    ctx->pc = 0x80191490u;
    // 80191490: stfs     f1, 108(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191490u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191494:
    ctx->pc = 0x80191494u;
    // 80191494: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191498:
    ctx->pc = 0x80191498u;
    // 80191498: bl      0x801CFFC8
    {
            ctx->lr = 0x8019149Cu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_8019149C:
    ctx->pc = 0x8019149Cu;
    ctx->downcount -= 4;
    // 8019149C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801914A0:
    ctx->pc = 0x801914A0u;
    // 801914A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801914A4:
    ctx->pc = 0x801914A4u;
    // 801914A4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801914A8:
    ctx->pc = 0x801914A8u;
    // 801914A8: bl      0x801CFFC8
    {
            ctx->lr = 0x801914ACu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801914AC:
    ctx->pc = 0x801914ACu;
    ctx->downcount -= 7;
    // 801914AC: stw     r3, 112(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801914B0:
    ctx->pc = 0x801914B0u;
    // 801914B0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801914B4:
    ctx->pc = 0x801914B4u;
    // 801914B4: addi    r30, r30, -16372
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16372);

label_801914B8:
    ctx->pc = 0x801914B8u;
    // 801914B8: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801914BC:
    ctx->pc = 0x801914BCu;
    // 801914BC: lfs     f1, 324(r1)
    if (!ppc_fp_available_inline(ctx, 0x801914BCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(324);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801914C0:
    ctx->pc = 0x801914C0u;
    // 801914C0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801914C4:
    ctx->pc = 0x801914C4u;
    // 801914C4: bl      0x801D009C
    {
            ctx->lr = 0x801914C8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801914C8:
    ctx->pc = 0x801914C8u;
    ctx->downcount -= 3;
    // 801914C8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801914CC:
    ctx->pc = 0x801914CCu;
    // 801914CC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801914D0:
    ctx->pc = 0x801914D0u;
    // 801914D0: bl      0x801D009C
    {
            ctx->lr = 0x801914D4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801914D4:
    ctx->pc = 0x801914D4u;
    ctx->downcount -= 7;
    // 801914D4: stfs     f1, 116(r31)
    if (!ppc_fp_available_inline(ctx, 0x801914D4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801914D8:
    ctx->pc = 0x801914D8u;
    // 801914D8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801914DC:
    ctx->pc = 0x801914DCu;
    // 801914DC: lfs     f1, 332(r1)
    if (!ppc_fp_available_inline(ctx, 0x801914DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(332);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801914E0:
    ctx->pc = 0x801914E0u;
    // 801914E0: addi    r30, r30, -16356
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16356);

label_801914E4:
    ctx->pc = 0x801914E4u;
    // 801914E4: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801914E8:
    ctx->pc = 0x801914E8u;
    // 801914E8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801914EC:
    ctx->pc = 0x801914ECu;
    // 801914EC: bl      0x801D009C
    {
            ctx->lr = 0x801914F0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801914F0:
    ctx->pc = 0x801914F0u;
    ctx->downcount -= 3;
    // 801914F0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801914F4:
    ctx->pc = 0x801914F4u;
    // 801914F4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801914F8:
    ctx->pc = 0x801914F8u;
    // 801914F8: bl      0x801D009C
    {
            ctx->lr = 0x801914FCu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801914FC:
    ctx->pc = 0x801914FCu;
    ctx->downcount -= 7;
    // 801914FC: stfs     f1, 128(r31)
    if (!ppc_fp_available_inline(ctx, 0x801914FCu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191500:
    ctx->pc = 0x80191500u;
    // 80191500: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191504:
    ctx->pc = 0x80191504u;
    // 80191504: lfs     f1, 328(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191504u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191508:
    ctx->pc = 0x80191508u;
    // 80191508: addi    r30, r30, -16332
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16332);

label_8019150C:
    ctx->pc = 0x8019150Cu;
    // 8019150C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191510:
    ctx->pc = 0x80191510u;
    // 80191510: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191514:
    ctx->pc = 0x80191514u;
    // 80191514: bl      0x801D009C
    {
            ctx->lr = 0x80191518u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191518:
    ctx->pc = 0x80191518u;
    ctx->downcount -= 3;
    // 80191518: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019151C:
    ctx->pc = 0x8019151Cu;
    // 8019151C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191520:
    ctx->pc = 0x80191520u;
    // 80191520: bl      0x801D009C
    {
            ctx->lr = 0x80191524u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191524:
    ctx->pc = 0x80191524u;
    ctx->downcount -= 8;
    // 80191524: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191528:
    ctx->pc = 0x80191528u;
    // 80191528: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_8019152C:
    ctx->pc = 0x8019152Cu;
    // 8019152C: addi    r30, r30, -16312
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16312);

label_80191530:
    ctx->pc = 0x80191530u;
    // 80191530: stfs     f1, 124(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191530u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191534:
    ctx->pc = 0x80191534u;
    // 80191534: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191538:
    ctx->pc = 0x80191538u;
    // 80191538: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8019153C:
    ctx->pc = 0x8019153Cu;
    // 8019153C: addi    r5, r5, -18884
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-18884);

label_80191540:
    ctx->pc = 0x80191540u;
    // 80191540: bl      0x801D012C
    {
            ctx->lr = 0x80191544u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80191544:
    ctx->pc = 0x80191544u;
    ctx->downcount -= 4;
    // 80191544: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191548:
    ctx->pc = 0x80191548u;
    // 80191548: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019154C:
    ctx->pc = 0x8019154Cu;
    // 8019154C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191550:
    ctx->pc = 0x80191550u;
    // 80191550: bl      0x801D012C
    {
            ctx->lr = 0x80191554u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80191554:
    ctx->pc = 0x80191554u;
    ctx->downcount -= 4;
    // 80191554: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191558:
    ctx->pc = 0x80191558u;
    // 80191558: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8019155C:
    ctx->pc = 0x8019155Cu;
    // 8019155C: addi    r4, r4, -16304
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16304);

label_80191560:
    ctx->pc = 0x80191560u;
    // 80191560: bl      0x80297FBC
    {
            ctx->lr = 0x80191564u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80191564:
    ctx->pc = 0x80191564u;
    ctx->downcount -= 2;
    // 80191564: cmpwi   r3, 0
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

label_80191568:
    ctx->pc = 0x80191568u;
    // 80191568: bc    4, 2, 0x80191574
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191574;
        }
    }

label_8019156C:
    ctx->pc = 0x8019156Cu;
    ctx->downcount -= 2;
    // 8019156C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80191570:
    ctx->pc = 0x80191570u;
    // 80191570: b       0x801915F8
    {
            goto label_801915F8;
    }

label_80191574:
    ctx->pc = 0x80191574u;
    ctx->downcount -= 4;
    // 80191574: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80191578:
    ctx->pc = 0x80191578u;
    // 80191578: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019157C:
    ctx->pc = 0x8019157Cu;
    // 8019157C: addi    r4, r4, -16296
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16296);

label_80191580:
    ctx->pc = 0x80191580u;
    // 80191580: bl      0x80297FBC
    {
            ctx->lr = 0x80191584u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80191584:
    ctx->pc = 0x80191584u;
    ctx->downcount -= 2;
    // 80191584: cmpwi   r3, 0
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

label_80191588:
    ctx->pc = 0x80191588u;
    // 80191588: bc    4, 2, 0x80191594
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191594;
        }
    }

label_8019158C:
    ctx->pc = 0x8019158Cu;
    ctx->downcount -= 2;
    // 8019158C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80191590:
    ctx->pc = 0x80191590u;
    // 80191590: b       0x801915F8
    {
            goto label_801915F8;
    }

label_80191594:
    ctx->pc = 0x80191594u;
    ctx->downcount -= 4;
    // 80191594: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80191598:
    ctx->pc = 0x80191598u;
    // 80191598: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019159C:
    ctx->pc = 0x8019159Cu;
    // 8019159C: addi    r4, r4, -16288
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16288);

label_801915A0:
    ctx->pc = 0x801915A0u;
    // 801915A0: bl      0x80297FBC
    {
            ctx->lr = 0x801915A4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801915A4:
    ctx->pc = 0x801915A4u;
    ctx->downcount -= 2;
    // 801915A4: cmpwi   r3, 0
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

label_801915A8:
    ctx->pc = 0x801915A8u;
    // 801915A8: bc    4, 2, 0x801915B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801915B4;
        }
    }

label_801915AC:
    ctx->pc = 0x801915ACu;
    ctx->downcount -= 2;
    // 801915AC: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_801915B0:
    ctx->pc = 0x801915B0u;
    // 801915B0: b       0x801915F8
    {
            goto label_801915F8;
    }

label_801915B4:
    ctx->pc = 0x801915B4u;
    ctx->downcount -= 4;
    // 801915B4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801915B8:
    ctx->pc = 0x801915B8u;
    // 801915B8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801915BC:
    ctx->pc = 0x801915BCu;
    // 801915BC: addi    r4, r4, -16276
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16276);

label_801915C0:
    ctx->pc = 0x801915C0u;
    // 801915C0: bl      0x80297FBC
    {
            ctx->lr = 0x801915C4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801915C4:
    ctx->pc = 0x801915C4u;
    ctx->downcount -= 2;
    // 801915C4: cmpwi   r3, 0
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

label_801915C8:
    ctx->pc = 0x801915C8u;
    // 801915C8: bc    4, 2, 0x801915D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801915D4;
        }
    }

label_801915CC:
    ctx->pc = 0x801915CCu;
    ctx->downcount -= 2;
    // 801915CC: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_801915D0:
    ctx->pc = 0x801915D0u;
    // 801915D0: b       0x801915F8
    {
            goto label_801915F8;
    }

label_801915D4:
    ctx->pc = 0x801915D4u;
    ctx->downcount -= 4;
    // 801915D4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801915D8:
    ctx->pc = 0x801915D8u;
    // 801915D8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801915DC:
    ctx->pc = 0x801915DCu;
    // 801915DC: addi    r4, r4, -16268
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16268);

label_801915E0:
    ctx->pc = 0x801915E0u;
    // 801915E0: bl      0x80297FBC
    {
            ctx->lr = 0x801915E4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801915E4:
    ctx->pc = 0x801915E4u;
    ctx->downcount -= 2;
    // 801915E4: or.   r3, r3, r3
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

label_801915E8:
    ctx->pc = 0x801915E8u;
    // 801915E8: bc    4, 2, 0x801915F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801915F4;
        }
    }

label_801915EC:
    ctx->pc = 0x801915ECu;
    ctx->downcount -= 2;
    // 801915EC: stw     r3, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801915F0:
    ctx->pc = 0x801915F0u;
    // 801915F0: b       0x801915FC
    {
            goto label_801915FC;
    }

label_801915F4:
    ctx->pc = 0x801915F4u;
    ctx->downcount -= 1;
    // 801915F4: lwz     r0, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801915F8:
    ctx->pc = 0x801915F8u;
    ctx->downcount -= 1;
    // 801915F8: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801915FC:
    ctx->pc = 0x801915FCu;
    ctx->downcount -= 8;
    // 801915FC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80191600:
    ctx->pc = 0x80191600u;
    // 80191600: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191604:
    ctx->pc = 0x80191604u;
    // 80191604: addi    r29, r9, -18884
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-18884);

label_80191608:
    ctx->pc = 0x80191608u;
    // 80191608: addi    r30, r30, -16260
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16260);

label_8019160C:
    ctx->pc = 0x8019160Cu;
    // 8019160C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191610:
    ctx->pc = 0x80191610u;
    // 80191610: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191614:
    ctx->pc = 0x80191614u;
    // 80191614: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191618:
    ctx->pc = 0x80191618u;
    // 80191618: bl      0x801D012C
    {
            ctx->lr = 0x8019161Cu;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8019161C:
    ctx->pc = 0x8019161Cu;
    ctx->downcount -= 4;
    // 8019161C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191620:
    ctx->pc = 0x80191620u;
    // 80191620: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191624:
    ctx->pc = 0x80191624u;
    // 80191624: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80191628:
    ctx->pc = 0x80191628u;
    // 80191628: bl      0x801D012C
    {
            ctx->lr = 0x8019162Cu;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8019162C:
    ctx->pc = 0x8019162Cu;
    ctx->downcount -= 4;
    // 8019162C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191630:
    ctx->pc = 0x80191630u;
    // 80191630: lwz     r5, 904(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(904);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80191634:
    ctx->pc = 0x80191634u;
    // 80191634: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191638:
    ctx->pc = 0x80191638u;
    // 80191638: bl      0x80196F14
    {
            ctx->lr = 0x8019163Cu;
            ctx->pc = 0x80196F14u;
            return;
    }

label_8019163C:
    ctx->pc = 0x8019163Cu;
    ctx->downcount -= 3;
    // 8019163C: cmpwi   r3, 0
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

label_80191640:
    ctx->pc = 0x80191640u;
    // 80191640: stw     r3, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80191644:
    ctx->pc = 0x80191644u;
    // 80191644: bc    4, 2, 0x80191650
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191650;
        }
    }

label_80191648:
    ctx->pc = 0x80191648u;
    ctx->downcount -= 2;
    // 80191648: lwz     r0, 904(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(904);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019164C:
    ctx->pc = 0x8019164Cu;
    // 8019164C: stw     r0, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191650:
    ctx->pc = 0x80191650u;
    ctx->downcount -= 6;
    // 80191650: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191654:
    ctx->pc = 0x80191654u;
    // 80191654: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191658:
    ctx->pc = 0x80191658u;
    // 80191658: addi    r30, r30, -16252
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16252);

label_8019165C:
    ctx->pc = 0x8019165Cu;
    // 8019165C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191660:
    ctx->pc = 0x80191660u;
    // 80191660: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191664:
    ctx->pc = 0x80191664u;
    // 80191664: bl      0x801D012C
    {
            ctx->lr = 0x80191668u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80191668:
    ctx->pc = 0x80191668u;
    ctx->downcount -= 4;
    // 80191668: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019166C:
    ctx->pc = 0x8019166Cu;
    // 8019166C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191670:
    ctx->pc = 0x80191670u;
    // 80191670: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80191674:
    ctx->pc = 0x80191674u;
    // 80191674: bl      0x801D012C
    {
            ctx->lr = 0x80191678u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80191678:
    ctx->pc = 0x80191678u;
    ctx->downcount -= 4;
    // 80191678: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019167C:
    ctx->pc = 0x8019167Cu;
    // 8019167C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80191680:
    ctx->pc = 0x80191680u;
    // 80191680: addi    r4, r4, -16240
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16240);

label_80191684:
    ctx->pc = 0x80191684u;
    // 80191684: bl      0x80297FBC
    {
            ctx->lr = 0x80191688u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80191688:
    ctx->pc = 0x80191688u;
    ctx->downcount -= 2;
    // 80191688: cmpwi   r3, 0
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

label_8019168C:
    ctx->pc = 0x8019168Cu;
    // 8019168C: bc    4, 2, 0x80191698
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191698;
        }
    }

label_80191690:
    ctx->pc = 0x80191690u;
    ctx->downcount -= 2;
    // 80191690: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80191694:
    ctx->pc = 0x80191694u;
    // 80191694: b       0x8019171C
    {
            goto label_8019171C;
    }

label_80191698:
    ctx->pc = 0x80191698u;
    ctx->downcount -= 4;
    // 80191698: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_8019169C:
    ctx->pc = 0x8019169Cu;
    // 8019169C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801916A0:
    ctx->pc = 0x801916A0u;
    // 801916A0: addi    r4, r4, -16232
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16232);

label_801916A4:
    ctx->pc = 0x801916A4u;
    // 801916A4: bl      0x80297FBC
    {
            ctx->lr = 0x801916A8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801916A8:
    ctx->pc = 0x801916A8u;
    ctx->downcount -= 2;
    // 801916A8: cmpwi   r3, 0
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

label_801916AC:
    ctx->pc = 0x801916ACu;
    // 801916AC: bc    4, 2, 0x801916B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801916B8;
        }
    }

label_801916B0:
    ctx->pc = 0x801916B0u;
    ctx->downcount -= 2;
    // 801916B0: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_801916B4:
    ctx->pc = 0x801916B4u;
    // 801916B4: b       0x8019171C
    {
            goto label_8019171C;
    }

label_801916B8:
    ctx->pc = 0x801916B8u;
    ctx->downcount -= 4;
    // 801916B8: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801916BC:
    ctx->pc = 0x801916BCu;
    // 801916BC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801916C0:
    ctx->pc = 0x801916C0u;
    // 801916C0: addi    r4, r4, -16224
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16224);

label_801916C4:
    ctx->pc = 0x801916C4u;
    // 801916C4: bl      0x80297FBC
    {
            ctx->lr = 0x801916C8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801916C8:
    ctx->pc = 0x801916C8u;
    ctx->downcount -= 2;
    // 801916C8: cmpwi   r3, 0
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

label_801916CC:
    ctx->pc = 0x801916CCu;
    // 801916CC: bc    4, 2, 0x801916D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801916D8;
        }
    }

label_801916D0:
    ctx->pc = 0x801916D0u;
    ctx->downcount -= 2;
    // 801916D0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801916D4:
    ctx->pc = 0x801916D4u;
    // 801916D4: b       0x8019171C
    {
            goto label_8019171C;
    }

label_801916D8:
    ctx->pc = 0x801916D8u;
    ctx->downcount -= 4;
    // 801916D8: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801916DC:
    ctx->pc = 0x801916DCu;
    // 801916DC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801916E0:
    ctx->pc = 0x801916E0u;
    // 801916E0: addi    r4, r4, -16216
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16216);

label_801916E4:
    ctx->pc = 0x801916E4u;
    // 801916E4: bl      0x80297FBC
    {
            ctx->lr = 0x801916E8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_801916E8:
    ctx->pc = 0x801916E8u;
    ctx->downcount -= 2;
    // 801916E8: cmpwi   r3, 0
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

label_801916EC:
    ctx->pc = 0x801916ECu;
    // 801916EC: bc    4, 2, 0x801916F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801916F8;
        }
    }

label_801916F0:
    ctx->pc = 0x801916F0u;
    ctx->downcount -= 2;
    // 801916F0: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_801916F4:
    ctx->pc = 0x801916F4u;
    // 801916F4: b       0x8019171C
    {
            goto label_8019171C;
    }

label_801916F8:
    ctx->pc = 0x801916F8u;
    ctx->downcount -= 4;
    // 801916F8: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_801916FC:
    ctx->pc = 0x801916FCu;
    // 801916FC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191700:
    ctx->pc = 0x80191700u;
    // 80191700: addi    r4, r4, -16268
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16268);

label_80191704:
    ctx->pc = 0x80191704u;
    // 80191704: bl      0x80297FBC
    {
            ctx->lr = 0x80191708u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80191708:
    ctx->pc = 0x80191708u;
    ctx->downcount -= 2;
    // 80191708: or.   r3, r3, r3
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

label_8019170C:
    ctx->pc = 0x8019170Cu;
    // 8019170C: bc    4, 2, 0x80191718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191718;
        }
    }

label_80191710:
    ctx->pc = 0x80191710u;
    ctx->downcount -= 2;
    // 80191710: stw     r3, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80191714:
    ctx->pc = 0x80191714u;
    // 80191714: b       0x80191720
    {
            goto label_80191720;
    }

label_80191718:
    ctx->pc = 0x80191718u;
    ctx->downcount -= 1;
    // 80191718: lwz     r0, 248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019171C:
    ctx->pc = 0x8019171Cu;
    ctx->downcount -= 1;
    // 8019171C: stw     r0, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191720:
    ctx->pc = 0x80191720u;
    ctx->downcount -= 5;
    // 80191720: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191724:
    ctx->pc = 0x80191724u;
    // 80191724: addi    r19, r1, 920
    ctx->gpr[19] = ctx->gpr[1] + (u32)(s32)(920);

label_80191728:
    ctx->pc = 0x80191728u;
    // 80191728: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8019172C:
    ctx->pc = 0x8019172Cu;
    // 8019172C: addi    r4, r30, -16200
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-16200);

label_80191730:
    ctx->pc = 0x80191730u;
    // 80191730: bl      0x801CFC48
    {
            ctx->lr = 0x80191734u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191734:
    ctx->pc = 0x80191734u;
    ctx->downcount -= 4;
    // 80191734: lis     r22, -32720
    ctx->gpr[22] = ((u32)(s32)(-32720) << 16);

label_80191738:
    ctx->pc = 0x80191738u;
    // 80191738: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8019173C:
    ctx->pc = 0x8019173Cu;
    // 8019173C: addi    r4, r30, -16200
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-16200);

label_80191740:
    ctx->pc = 0x80191740u;
    // 80191740: bl      0x801CFC48
    {
            ctx->lr = 0x80191744u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191744:
    ctx->pc = 0x80191744u;
    ctx->downcount -= 10;
    // 80191744: lis     r18, -32720
    ctx->gpr[18] = ((u32)(s32)(-32720) << 16);

label_80191748:
    ctx->pc = 0x80191748u;
    // 80191748: lis     r29, -32720
    ctx->gpr[29] = ((u32)(s32)(-32720) << 16);

label_8019174C:
    ctx->pc = 0x8019174Cu;
    // 8019174C: lfs     f1, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019174Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191750:
    ctx->pc = 0x80191750u;
    // 80191750: addi    r29, r29, -16188
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-16188);

label_80191754:
    ctx->pc = 0x80191754u;
    // 80191754: addi    r20, r1, 928
    ctx->gpr[20] = ctx->gpr[1] + (u32)(s32)(928);

label_80191758:
    ctx->pc = 0x80191758u;
    // 80191758: addi    r21, r1, 936
    ctx->gpr[21] = ctx->gpr[1] + (u32)(s32)(936);

label_8019175C:
    ctx->pc = 0x8019175Cu;
    // 8019175C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191760:
    ctx->pc = 0x80191760u;
    // 80191760: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191764:
    ctx->pc = 0x80191764u;
    // 80191764: lis     r17, -32720
    ctx->gpr[17] = ((u32)(s32)(-32720) << 16);

label_80191768:
    ctx->pc = 0x80191768u;
    // 80191768: bl      0x801D009C
    {
            ctx->lr = 0x8019176Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019176C:
    ctx->pc = 0x8019176Cu;
    ctx->downcount -= 6;
    // 8019176C: lis     r16, -32720
    ctx->gpr[16] = ((u32)(s32)(-32720) << 16);

label_80191770:
    ctx->pc = 0x80191770u;
    // 80191770: addi    r23, r1, 944
    ctx->gpr[23] = ctx->gpr[1] + (u32)(s32)(944);

label_80191774:
    ctx->pc = 0x80191774u;
    // 80191774: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80191778:
    ctx->pc = 0x80191778u;
    // 80191778: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8019177C:
    ctx->pc = 0x8019177Cu;
    // 8019177C: lis     r15, -32720
    ctx->gpr[15] = ((u32)(s32)(-32720) << 16);

label_80191780:
    ctx->pc = 0x80191780u;
    // 80191780: bl      0x801D009C
    {
            ctx->lr = 0x80191784u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191784:
    ctx->pc = 0x80191784u;
    ctx->downcount -= 8;
    // 80191784: stfs     f1, 32(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191784u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191788:
    ctx->pc = 0x80191788u;
    // 80191788: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019178C:
    ctx->pc = 0x8019178Cu;
    // 8019178C: lfs     f1, 148(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019178Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191790:
    ctx->pc = 0x80191790u;
    // 80191790: addi    r30, r30, -16184
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16184);

label_80191794:
    ctx->pc = 0x80191794u;
    // 80191794: addi    r24, r1, 952
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(952);

label_80191798:
    ctx->pc = 0x80191798u;
    // 80191798: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8019179C:
    ctx->pc = 0x8019179Cu;
    // 8019179C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801917A0:
    ctx->pc = 0x801917A0u;
    // 801917A0: bl      0x801D009C
    {
            ctx->lr = 0x801917A4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801917A4:
    ctx->pc = 0x801917A4u;
    ctx->downcount -= 4;
    // 801917A4: addi    r25, r1, 960
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(960);

label_801917A8:
    ctx->pc = 0x801917A8u;
    // 801917A8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_801917AC:
    ctx->pc = 0x801917ACu;
    // 801917AC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801917B0:
    ctx->pc = 0x801917B0u;
    // 801917B0: bl      0x801D009C
    {
            ctx->lr = 0x801917B4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801917B4:
    ctx->pc = 0x801917B4u;
    ctx->downcount -= 5;
    // 801917B4: stfs     f1, 36(r31)
    if (!ppc_fp_available_inline(ctx, 0x801917B4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801917B8:
    ctx->pc = 0x801917B8u;
    // 801917B8: addi    r26, r1, 968
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(968);

label_801917BC:
    ctx->pc = 0x801917BCu;
    // 801917BC: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_801917C0:
    ctx->pc = 0x801917C0u;
    // 801917C0: lwz     r4, 992(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(992);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801917C4:
    ctx->pc = 0x801917C4u;
    // 801917C4: bl      0x801CFE08
    {
            ctx->lr = 0x801917C8u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801917C8:
    ctx->pc = 0x801917C8u;
    ctx->downcount -= 4;
    // 801917C8: lwz     r4, 996(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(996);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801917CC:
    ctx->pc = 0x801917CCu;
    // 801917CC: addi    r27, r1, 976
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(976);

label_801917D0:
    ctx->pc = 0x801917D0u;
    // 801917D0: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_801917D4:
    ctx->pc = 0x801917D4u;
    // 801917D4: bl      0x801CFE08
    {
            ctx->lr = 0x801917D8u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801917D8:
    ctx->pc = 0x801917D8u;
    ctx->downcount -= 4;
    // 801917D8: addi    r28, r1, 984
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(984);

label_801917DC:
    ctx->pc = 0x801917DCu;
    // 801917DC: addi    r4, r22, -16180
    ctx->gpr[4] = ctx->gpr[22] + (u32)(s32)(-16180);

label_801917E0:
    ctx->pc = 0x801917E0u;
    // 801917E0: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_801917E4:
    ctx->pc = 0x801917E4u;
    // 801917E4: bl      0x801CFC48
    {
            ctx->lr = 0x801917E8u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801917E8:
    ctx->pc = 0x801917E8u;
    ctx->downcount -= 3;
    // 801917E8: addi    r4, r22, -16180
    ctx->gpr[4] = ctx->gpr[22] + (u32)(s32)(-16180);

label_801917EC:
    ctx->pc = 0x801917ECu;
    // 801917EC: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_801917F0:
    ctx->pc = 0x801917F0u;
    // 801917F0: bl      0x801CFC48
    {
            ctx->lr = 0x801917F4u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801917F4:
    ctx->pc = 0x801917F4u;
    ctx->downcount -= 4;
    // 801917F4: lfs     f1, 152(r1)
    if (!ppc_fp_available_inline(ctx, 0x801917F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801917F8:
    ctx->pc = 0x801917F8u;
    // 801917F8: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_801917FC:
    ctx->pc = 0x801917FCu;
    // 801917FC: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191800:
    ctx->pc = 0x80191800u;
    // 80191800: bl      0x801D009C
    {
            ctx->lr = 0x80191804u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191804:
    ctx->pc = 0x80191804u;
    ctx->downcount -= 3;
    // 80191804: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_80191808:
    ctx->pc = 0x80191808u;
    // 80191808: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8019180C:
    ctx->pc = 0x8019180Cu;
    // 8019180C: bl      0x801D009C
    {
            ctx->lr = 0x80191810u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191810:
    ctx->pc = 0x80191810u;
    ctx->downcount -= 5;
    // 80191810: stfs     f1, 40(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191810u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191814:
    ctx->pc = 0x80191814u;
    // 80191814: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80191818:
    ctx->pc = 0x80191818u;
    // 80191818: lfs     f1, 156(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191818u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8019181C:
    ctx->pc = 0x8019181Cu;
    // 8019181C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191820:
    ctx->pc = 0x80191820u;
    // 80191820: bl      0x801D009C
    {
            ctx->lr = 0x80191824u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191824:
    ctx->pc = 0x80191824u;
    ctx->downcount -= 3;
    // 80191824: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_80191828:
    ctx->pc = 0x80191828u;
    // 80191828: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019182C:
    ctx->pc = 0x8019182Cu;
    // 8019182C: bl      0x801D009C
    {
            ctx->lr = 0x80191830u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191830:
    ctx->pc = 0x80191830u;
    ctx->downcount -= 4;
    // 80191830: stfs     f1, 44(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191830u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191834:
    ctx->pc = 0x80191834u;
    // 80191834: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191838:
    ctx->pc = 0x80191838u;
    // 80191838: lwz     r4, 992(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(992);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019183C:
    ctx->pc = 0x8019183Cu;
    // 8019183C: bl      0x801CFE08
    {
            ctx->lr = 0x80191840u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191840:
    ctx->pc = 0x80191840u;
    ctx->downcount -= 3;
    // 80191840: lwz     r4, 996(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(996);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80191844:
    ctx->pc = 0x80191844u;
    // 80191844: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80191848:
    ctx->pc = 0x80191848u;
    // 80191848: bl      0x801CFE08
    {
            ctx->lr = 0x8019184Cu;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_8019184C:
    ctx->pc = 0x8019184Cu;
    ctx->downcount -= 3;
    // 8019184C: addi    r4, r18, -16160
    ctx->gpr[4] = ctx->gpr[18] + (u32)(s32)(-16160);

label_80191850:
    ctx->pc = 0x80191850u;
    // 80191850: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191854:
    ctx->pc = 0x80191854u;
    // 80191854: bl      0x801CFC48
    {
            ctx->lr = 0x80191858u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191858:
    ctx->pc = 0x80191858u;
    ctx->downcount -= 3;
    // 80191858: addi    r4, r18, -16160
    ctx->gpr[4] = ctx->gpr[18] + (u32)(s32)(-16160);

label_8019185C:
    ctx->pc = 0x8019185Cu;
    // 8019185C: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80191860:
    ctx->pc = 0x80191860u;
    // 80191860: bl      0x801CFC48
    {
            ctx->lr = 0x80191864u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191864:
    ctx->pc = 0x80191864u;
    ctx->downcount -= 4;
    // 80191864: lfs     f1, 160(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191864u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191868:
    ctx->pc = 0x80191868u;
    // 80191868: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_8019186C:
    ctx->pc = 0x8019186Cu;
    // 8019186C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191870:
    ctx->pc = 0x80191870u;
    // 80191870: bl      0x801D009C
    {
            ctx->lr = 0x80191874u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191874:
    ctx->pc = 0x80191874u;
    ctx->downcount -= 3;
    // 80191874: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191878:
    ctx->pc = 0x80191878u;
    // 80191878: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8019187C:
    ctx->pc = 0x8019187Cu;
    // 8019187C: bl      0x801D009C
    {
            ctx->lr = 0x80191880u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191880:
    ctx->pc = 0x80191880u;
    ctx->downcount -= 5;
    // 80191880: stfs     f1, 48(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191880u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191884:
    ctx->pc = 0x80191884u;
    // 80191884: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80191888:
    ctx->pc = 0x80191888u;
    // 80191888: lfs     f1, 164(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191888u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8019188C:
    ctx->pc = 0x8019188Cu;
    // 8019188C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191890:
    ctx->pc = 0x80191890u;
    // 80191890: bl      0x801D009C
    {
            ctx->lr = 0x80191894u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191894:
    ctx->pc = 0x80191894u;
    ctx->downcount -= 3;
    // 80191894: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191898:
    ctx->pc = 0x80191898u;
    // 80191898: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019189C:
    ctx->pc = 0x8019189Cu;
    // 8019189C: bl      0x801D009C
    {
            ctx->lr = 0x801918A0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801918A0:
    ctx->pc = 0x801918A0u;
    ctx->downcount -= 4;
    // 801918A0: stfs     f1, 52(r31)
    if (!ppc_fp_available_inline(ctx, 0x801918A0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801918A4:
    ctx->pc = 0x801918A4u;
    // 801918A4: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_801918A8:
    ctx->pc = 0x801918A8u;
    // 801918A8: lwz     r4, 992(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(992);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801918AC:
    ctx->pc = 0x801918ACu;
    // 801918AC: bl      0x801CFE08
    {
            ctx->lr = 0x801918B0u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801918B0:
    ctx->pc = 0x801918B0u;
    ctx->downcount -= 3;
    // 801918B0: lwz     r4, 996(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(996);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801918B4:
    ctx->pc = 0x801918B4u;
    // 801918B4: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801918B8:
    ctx->pc = 0x801918B8u;
    // 801918B8: bl      0x801CFE08
    {
            ctx->lr = 0x801918BCu;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801918BC:
    ctx->pc = 0x801918BCu;
    ctx->downcount -= 3;
    // 801918BC: addi    r4, r17, -16144
    ctx->gpr[4] = ctx->gpr[17] + (u32)(s32)(-16144);

label_801918C0:
    ctx->pc = 0x801918C0u;
    // 801918C0: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_801918C4:
    ctx->pc = 0x801918C4u;
    // 801918C4: bl      0x801CFC48
    {
            ctx->lr = 0x801918C8u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801918C8:
    ctx->pc = 0x801918C8u;
    ctx->downcount -= 3;
    // 801918C8: addi    r4, r17, -16144
    ctx->gpr[4] = ctx->gpr[17] + (u32)(s32)(-16144);

label_801918CC:
    ctx->pc = 0x801918CCu;
    // 801918CC: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801918D0:
    ctx->pc = 0x801918D0u;
    // 801918D0: bl      0x801CFC48
    {
            ctx->lr = 0x801918D4u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801918D4:
    ctx->pc = 0x801918D4u;
    ctx->downcount -= 4;
    // 801918D4: lfs     f1, 176(r1)
    if (!ppc_fp_available_inline(ctx, 0x801918D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801918D8:
    ctx->pc = 0x801918D8u;
    // 801918D8: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801918DC:
    ctx->pc = 0x801918DCu;
    // 801918DC: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801918E0:
    ctx->pc = 0x801918E0u;
    // 801918E0: bl      0x801D009C
    {
            ctx->lr = 0x801918E4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801918E4:
    ctx->pc = 0x801918E4u;
    ctx->downcount -= 3;
    // 801918E4: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_801918E8:
    ctx->pc = 0x801918E8u;
    // 801918E8: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801918EC:
    ctx->pc = 0x801918ECu;
    // 801918EC: bl      0x801D009C
    {
            ctx->lr = 0x801918F0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801918F0:
    ctx->pc = 0x801918F0u;
    ctx->downcount -= 5;
    // 801918F0: stfs     f1, 56(r31)
    if (!ppc_fp_available_inline(ctx, 0x801918F0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801918F4:
    ctx->pc = 0x801918F4u;
    // 801918F4: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801918F8:
    ctx->pc = 0x801918F8u;
    // 801918F8: lfs     f1, 180(r1)
    if (!ppc_fp_available_inline(ctx, 0x801918F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(180);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801918FC:
    ctx->pc = 0x801918FCu;
    // 801918FC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191900:
    ctx->pc = 0x80191900u;
    // 80191900: bl      0x801D009C
    {
            ctx->lr = 0x80191904u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191904:
    ctx->pc = 0x80191904u;
    ctx->downcount -= 3;
    // 80191904: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80191908:
    ctx->pc = 0x80191908u;
    // 80191908: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019190C:
    ctx->pc = 0x8019190Cu;
    // 8019190C: bl      0x801D009C
    {
            ctx->lr = 0x80191910u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191910:
    ctx->pc = 0x80191910u;
    ctx->downcount -= 4;
    // 80191910: stfs     f1, 60(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191910u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191914:
    ctx->pc = 0x80191914u;
    // 80191914: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191918:
    ctx->pc = 0x80191918u;
    // 80191918: lwz     r4, 992(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(992);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019191C:
    ctx->pc = 0x8019191Cu;
    // 8019191C: bl      0x801CFE08
    {
            ctx->lr = 0x80191920u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191920:
    ctx->pc = 0x80191920u;
    ctx->downcount -= 3;
    // 80191920: lwz     r4, 996(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(996);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80191924:
    ctx->pc = 0x80191924u;
    // 80191924: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80191928:
    ctx->pc = 0x80191928u;
    // 80191928: bl      0x801CFE08
    {
            ctx->lr = 0x8019192Cu;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_8019192C:
    ctx->pc = 0x8019192Cu;
    ctx->downcount -= 3;
    // 8019192C: addi    r4, r16, -16128
    ctx->gpr[4] = ctx->gpr[16] + (u32)(s32)(-16128);

label_80191930:
    ctx->pc = 0x80191930u;
    // 80191930: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191934:
    ctx->pc = 0x80191934u;
    // 80191934: bl      0x801CFC48
    {
            ctx->lr = 0x80191938u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191938:
    ctx->pc = 0x80191938u;
    ctx->downcount -= 3;
    // 80191938: addi    r4, r16, -16128
    ctx->gpr[4] = ctx->gpr[16] + (u32)(s32)(-16128);

label_8019193C:
    ctx->pc = 0x8019193Cu;
    // 8019193C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80191940:
    ctx->pc = 0x80191940u;
    // 80191940: bl      0x801CFC48
    {
            ctx->lr = 0x80191944u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191944:
    ctx->pc = 0x80191944u;
    ctx->downcount -= 4;
    // 80191944: lfs     f1, 184(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191944u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(184);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80191948:
    ctx->pc = 0x80191948u;
    // 80191948: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8019194C:
    ctx->pc = 0x8019194Cu;
    // 8019194C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191950:
    ctx->pc = 0x80191950u;
    // 80191950: bl      0x801D009C
    {
            ctx->lr = 0x80191954u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191954:
    ctx->pc = 0x80191954u;
    ctx->downcount -= 3;
    // 80191954: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191958:
    ctx->pc = 0x80191958u;
    // 80191958: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8019195C:
    ctx->pc = 0x8019195Cu;
    // 8019195C: bl      0x801D009C
    {
            ctx->lr = 0x80191960u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191960:
    ctx->pc = 0x80191960u;
    ctx->downcount -= 5;
    // 80191960: stfs     f1, 64(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191960u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191964:
    ctx->pc = 0x80191964u;
    // 80191964: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80191968:
    ctx->pc = 0x80191968u;
    // 80191968: lfs     f1, 188(r1)
    if (!ppc_fp_available_inline(ctx, 0x80191968u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8019196C:
    ctx->pc = 0x8019196Cu;
    // 8019196C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191970:
    ctx->pc = 0x80191970u;
    // 80191970: bl      0x801D009C
    {
            ctx->lr = 0x80191974u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191974:
    ctx->pc = 0x80191974u;
    ctx->downcount -= 3;
    // 80191974: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191978:
    ctx->pc = 0x80191978u;
    // 80191978: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019197C:
    ctx->pc = 0x8019197Cu;
    // 8019197C: bl      0x801D009C
    {
            ctx->lr = 0x80191980u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80191980:
    ctx->pc = 0x80191980u;
    ctx->downcount -= 4;
    // 80191980: stfs     f1, 68(r31)
    if (!ppc_fp_available_inline(ctx, 0x80191980u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80191984:
    ctx->pc = 0x80191984u;
    // 80191984: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80191988:
    ctx->pc = 0x80191988u;
    // 80191988: lwz     r4, 992(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(992);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019198C:
    ctx->pc = 0x8019198Cu;
    // 8019198C: bl      0x801CFE08
    {
            ctx->lr = 0x80191990u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191990:
    ctx->pc = 0x80191990u;
    ctx->downcount -= 3;
    // 80191990: lwz     r4, 996(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(996);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80191994:
    ctx->pc = 0x80191994u;
    // 80191994: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191998:
    ctx->pc = 0x80191998u;
    // 80191998: bl      0x801CFE08
    {
            ctx->lr = 0x8019199Cu;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_8019199C:
    ctx->pc = 0x8019199Cu;
    ctx->downcount -= 3;
    // 8019199C: addi    r4, r15, -16108
    ctx->gpr[4] = ctx->gpr[15] + (u32)(s32)(-16108);

label_801919A0:
    ctx->pc = 0x801919A0u;
    // 801919A0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801919A4:
    ctx->pc = 0x801919A4u;
    // 801919A4: bl      0x801CFC48
    {
            ctx->lr = 0x801919A8u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801919A8:
    ctx->pc = 0x801919A8u;
    ctx->downcount -= 3;
    // 801919A8: addi    r4, r15, -16108
    ctx->gpr[4] = ctx->gpr[15] + (u32)(s32)(-16108);

label_801919AC:
    ctx->pc = 0x801919ACu;
    // 801919AC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801919B0:
    ctx->pc = 0x801919B0u;
    // 801919B0: bl      0x801CFC48
    {
            ctx->lr = 0x801919B4u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801919B4:
    ctx->pc = 0x801919B4u;
    ctx->downcount -= 4;
    // 801919B4: lfs     f1, 192(r1)
    if (!ppc_fp_available_inline(ctx, 0x801919B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801919B8:
    ctx->pc = 0x801919B8u;
    // 801919B8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801919BC:
    ctx->pc = 0x801919BCu;
    // 801919BC: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801919C0:
    ctx->pc = 0x801919C0u;
    // 801919C0: bl      0x801D009C
    {
            ctx->lr = 0x801919C4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801919C4:
    ctx->pc = 0x801919C4u;
    ctx->downcount -= 3;
    // 801919C4: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801919C8:
    ctx->pc = 0x801919C8u;
    // 801919C8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801919CC:
    ctx->pc = 0x801919CCu;
    // 801919CC: bl      0x801D009C
    {
            ctx->lr = 0x801919D0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801919D0:
    ctx->pc = 0x801919D0u;
    ctx->downcount -= 5;
    // 801919D0: stfs     f1, 72(r31)
    if (!ppc_fp_available_inline(ctx, 0x801919D0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801919D4:
    ctx->pc = 0x801919D4u;
    // 801919D4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801919D8:
    ctx->pc = 0x801919D8u;
    // 801919D8: lfs     f1, 196(r1)
    if (!ppc_fp_available_inline(ctx, 0x801919D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(196);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801919DC:
    ctx->pc = 0x801919DCu;
    // 801919DC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801919E0:
    ctx->pc = 0x801919E0u;
    // 801919E0: bl      0x801D009C
    {
            ctx->lr = 0x801919E4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801919E4:
    ctx->pc = 0x801919E4u;
    ctx->downcount -= 3;
    // 801919E4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801919E8:
    ctx->pc = 0x801919E8u;
    // 801919E8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801919EC:
    ctx->pc = 0x801919ECu;
    // 801919EC: bl      0x801D009C
    {
            ctx->lr = 0x801919F0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801919F0:
    ctx->pc = 0x801919F0u;
    ctx->downcount -= 4;
    // 801919F0: stfs     f1, 76(r31)
    if (!ppc_fp_available_inline(ctx, 0x801919F0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801919F4:
    ctx->pc = 0x801919F4u;
    // 801919F4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801919F8:
    ctx->pc = 0x801919F8u;
    // 801919F8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801919FC:
    ctx->pc = 0x801919FCu;
    // 801919FC: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A00u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A00:
    ctx->pc = 0x80191A00u;
    ctx->downcount -= 3;
    // 80191A00: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80191A04:
    ctx->pc = 0x80191A04u;
    // 80191A04: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A08:
    ctx->pc = 0x80191A08u;
    // 80191A08: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A0Cu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A0C:
    ctx->pc = 0x80191A0Cu;
    ctx->downcount -= 3;
    // 80191A0C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80191A10:
    ctx->pc = 0x80191A10u;
    // 80191A10: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A14:
    ctx->pc = 0x80191A14u;
    // 80191A14: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A18u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A18:
    ctx->pc = 0x80191A18u;
    ctx->downcount -= 3;
    // 80191A18: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191A1C:
    ctx->pc = 0x80191A1Cu;
    // 80191A1C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A20:
    ctx->pc = 0x80191A20u;
    // 80191A20: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A24u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A24:
    ctx->pc = 0x80191A24u;
    ctx->downcount -= 3;
    // 80191A24: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191A28:
    ctx->pc = 0x80191A28u;
    // 80191A28: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A2C:
    ctx->pc = 0x80191A2Cu;
    // 80191A2C: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A30u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A30:
    ctx->pc = 0x80191A30u;
    ctx->downcount -= 3;
    // 80191A30: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80191A34:
    ctx->pc = 0x80191A34u;
    // 80191A34: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A38:
    ctx->pc = 0x80191A38u;
    // 80191A38: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A3Cu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A3C:
    ctx->pc = 0x80191A3Cu;
    ctx->downcount -= 3;
    // 80191A3C: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80191A40:
    ctx->pc = 0x80191A40u;
    // 80191A40: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A44:
    ctx->pc = 0x80191A44u;
    // 80191A44: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A48u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A48:
    ctx->pc = 0x80191A48u;
    ctx->downcount -= 3;
    // 80191A48: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191A4C:
    ctx->pc = 0x80191A4Cu;
    // 80191A4C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A50:
    ctx->pc = 0x80191A50u;
    // 80191A50: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A54u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A54:
    ctx->pc = 0x80191A54u;
    ctx->downcount -= 3;
    // 80191A54: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80191A58:
    ctx->pc = 0x80191A58u;
    // 80191A58: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A5C:
    ctx->pc = 0x80191A5Cu;
    // 80191A5C: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A60u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A60:
    ctx->pc = 0x80191A60u;
    ctx->downcount -= 3;
    // 80191A60: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_80191A64:
    ctx->pc = 0x80191A64u;
    // 80191A64: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A68:
    ctx->pc = 0x80191A68u;
    // 80191A68: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A6Cu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A6C:
    ctx->pc = 0x80191A6Cu;
    ctx->downcount -= 3;
    // 80191A6C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80191A70:
    ctx->pc = 0x80191A70u;
    // 80191A70: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A74:
    ctx->pc = 0x80191A74u;
    // 80191A74: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A78u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A78:
    ctx->pc = 0x80191A78u;
    ctx->downcount -= 3;
    // 80191A78: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80191A7C:
    ctx->pc = 0x80191A7Cu;
    // 80191A7C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191A80:
    ctx->pc = 0x80191A80u;
    // 80191A80: bl      0x801CFEAC
    {
            ctx->lr = 0x80191A84u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191A84:
    ctx->pc = 0x80191A84u;
    ctx->downcount -= 16;
    // 80191A84: lwz     r0, 1076(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1076);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191A88:
    ctx->pc = 0x80191A88u;
    // 80191A88: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80191A8C:
    ctx->pc = 0x80191A8Cu;
    // 80191A8C: lmw     r14, 1000(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1000);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80191A90:
    ctx->pc = 0x80191A90u;
    // 80191A90: addi    r1, r1, 1072
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(1072);

label_80191A94:
    ctx->pc = 0x80191A94u;
    // 80191A94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8018F4C0;
        }
    }

label_80191A98:
    ctx->pc = 0x80191A98u;
    ctx->downcount -= 20;
    // 80191A98: stwu     r1, -1024(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-1024);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80191A9C:
    ctx->pc = 0x80191A9Cu;
    // 80191A9C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80191AA0:
    ctx->pc = 0x80191AA0u;
    // 80191AA0: stmw     r15, 956(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(956);
        for (u32 r = 15; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80191AA4:
    ctx->pc = 0x80191AA4u;
    // 80191AA4: stw     r0, 1028(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1028);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191AA8:
    ctx->pc = 0x80191AA8u;
    // 80191AA8: or   r23, r3, r3
    {
        ctx->gpr[23] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191AAC:
    ctx->pc = 0x80191AACu;
    // 80191AAC: or   r20, r4, r4
    {
        ctx->gpr[20] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80191AB0:
    ctx->pc = 0x80191AB0u;
    // 80191AB0: addi    r30, r1, 16
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(16);

label_80191AB4:
    ctx->pc = 0x80191AB4u;
    // 80191AB4: or   r19, r5, r5
    {
        ctx->gpr[19] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80191AB8:
    ctx->pc = 0x80191AB8u;
    // 80191AB8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80191ABC:
    ctx->pc = 0x80191ABCu;
    // 80191ABC: bl      0x801CFE08
    {
            ctx->lr = 0x80191AC0u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191AC0:
    ctx->pc = 0x80191AC0u;
    ctx->downcount -= 4;
    // 80191AC0: lis     r28, -32720
    ctx->gpr[28] = ((u32)(s32)(-32720) << 16);

label_80191AC4:
    ctx->pc = 0x80191AC4u;
    // 80191AC4: or   r4, r19, r19
    {
        ctx->gpr[4] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80191AC8:
    ctx->pc = 0x80191AC8u;
    // 80191AC8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191ACC:
    ctx->pc = 0x80191ACCu;
    // 80191ACC: bl      0x801CFE08
    {
            ctx->lr = 0x80191AD0u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191AD0:
    ctx->pc = 0x80191AD0u;
    ctx->downcount -= 4;
    // 80191AD0: addi    r29, r1, 24
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(24);

label_80191AD4:
    ctx->pc = 0x80191AD4u;
    // 80191AD4: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80191AD8:
    ctx->pc = 0x80191AD8u;
    // 80191AD8: addi    r4, r28, -16556
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(-16556);

label_80191ADC:
    ctx->pc = 0x80191ADCu;
    // 80191ADC: bl      0x801CFC48
    {
            ctx->lr = 0x80191AE0u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191AE0:
    ctx->pc = 0x80191AE0u;
    ctx->downcount -= 3;
    // 80191AE0: addi    r4, r28, -16556
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(-16556);

label_80191AE4:
    ctx->pc = 0x80191AE4u;
    // 80191AE4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191AE8:
    ctx->pc = 0x80191AE8u;
    // 80191AE8: bl      0x801CFC48
    {
            ctx->lr = 0x80191AECu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191AEC:
    ctx->pc = 0x80191AECu;
    ctx->downcount -= 3;
    // 80191AEC: lwz     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80191AF0:
    ctx->pc = 0x80191AF0u;
    // 80191AF0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191AF4:
    ctx->pc = 0x80191AF4u;
    // 80191AF4: bl      0x8008E974
    {
            ctx->lr = 0x80191AF8u;
            ctx->pc = 0x8008E974u;
            return;
    }

label_80191AF8:
    ctx->pc = 0x80191AF8u;
    ctx->downcount -= 3;
    // 80191AF8: lwz     r25, -26944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26944);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80191AFC:
    ctx->pc = 0x80191AFCu;
    // 80191AFC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191B00:
    ctx->pc = 0x80191B00u;
    // 80191B00: bl      0x8025E00C
    {
            ctx->lr = 0x80191B04u;
            ctx->pc = 0x8025E00Cu;
            return;
    }

label_80191B04:
    ctx->pc = 0x80191B04u;
    ctx->downcount -= 5;
    // 80191B04: or   r16, r3, r3
    {
        ctx->gpr[16] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191B08:
    ctx->pc = 0x80191B08u;
    // 80191B08: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191B0C:
    ctx->pc = 0x80191B0Cu;
    // 80191B0C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191B10:
    ctx->pc = 0x80191B10u;
    // 80191B10: li      r4, -10000
    ctx->gpr[4] = (u32)(s32)(-10000);

label_80191B14:
    ctx->pc = 0x80191B14u;
    // 80191B14: bl      0x8025EE94
    {
            ctx->lr = 0x80191B18u;
            ctx->pc = 0x8025EE94u;
            return;
    }

label_80191B18:
    ctx->pc = 0x80191B18u;
    ctx->downcount -= 2;
    // 80191B18: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191B1C:
    ctx->pc = 0x80191B1Cu;
    // 80191B1C: bl      0x8025EA18
    {
            ctx->lr = 0x80191B20u;
            ctx->pc = 0x8025EA18u;
            return;
    }

label_80191B20:
    ctx->pc = 0x80191B20u;
    ctx->downcount -= 5;
    // 80191B20: or   r15, r30, r30
    {
        ctx->gpr[15] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191B24:
    ctx->pc = 0x80191B24u;
    // 80191B24: or   r18, r29, r29
    {
        ctx->gpr[18] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191B28:
    ctx->pc = 0x80191B28u;
    // 80191B28: lis     r17, -32720
    ctx->gpr[17] = ((u32)(s32)(-32720) << 16);

label_80191B2C:
    ctx->pc = 0x80191B2Cu;
    // 80191B2C: addi    r24, r1, 912
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(912);

label_80191B30:
    ctx->pc = 0x80191B30u;
    // 80191B30: b       0x80191DC8
    {
            goto label_80191DC8;
    }

label_80191B34:
    ctx->downcount -= 3;
    // 80191B34: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_80191B38:
    // 80191B38: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191B3C:
    // 80191B3C: bl      0x8025D7A8
    {
            ctx->lr = 0x80191B40u;
            ctx->pc = 0x8025D7A8u;
            return;
    }

label_80191B40:
    ctx->downcount -= 6;
    // 80191B40: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80191B44:
    // 80191B44: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191B48:
    // 80191B48: addi    r28, r1, 920
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(920);

label_80191B4C:
    // 80191B4C: or   r4, r20, r20
    {
        ctx->gpr[4] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191B50:
    // 80191B50: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191B54:
    // 80191B54: bl      0x801CFE08
    {
            ctx->lr = 0x80191B58u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191B58:
    ctx->downcount -= 4;
    // 80191B58: or   r22, r28, r28
    {
        ctx->gpr[22] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191B5C:
    // 80191B5C: or   r4, r19, r19
    {
        ctx->gpr[4] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80191B60:
    // 80191B60: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191B64:
    // 80191B64: bl      0x801CFE08
    {
            ctx->lr = 0x80191B68u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191B68:
    ctx->downcount -= 3;
    // 80191B68: addi    r4, r30, -16556
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-16556);

label_80191B6C:
    // 80191B6C: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191B70:
    // 80191B70: bl      0x801CFC48
    {
            ctx->lr = 0x80191B74u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191B74:
    ctx->downcount -= 3;
    // 80191B74: addi    r4, r30, -16556
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-16556);

label_80191B78:
    // 80191B78: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191B7C:
    // 80191B7C: bl      0x801CFC48
    {
            ctx->lr = 0x80191B80u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191B80:
    ctx->downcount -= 3;
    // 80191B80: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80191B84:
    // 80191B84: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191B88:
    // 80191B88: bl      0x801CFC48
    {
            ctx->lr = 0x80191B8Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191B8C:
    ctx->downcount -= 3;
    // 80191B8C: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80191B90:
    // 80191B90: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191B94:
    // 80191B94: bl      0x801CFC48
    {
            ctx->lr = 0x80191B98u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191B98:
    ctx->downcount -= 5;
    // 80191B98: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80191B9C:
    // 80191B9C: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191BA0:
    // 80191BA0: addi    r4, r4, -16540
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16540);

label_80191BA4:
    // 80191BA4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80191BA8:
    // 80191BA8: bl      0x801CFFC8
    {
            ctx->lr = 0x80191BACu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80191BAC:
    ctx->downcount -= 2;
    // 80191BAC: cmpwi   r3, 0
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

label_80191BB0:
    // 80191BB0: bc    12, 2, 0x80191BDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191BDC;
        }
    }

label_80191BB4:
    ctx->downcount -= 3;
    // 80191BB4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191BB8:
    // 80191BB8: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_80191BBC:
    // 80191BBC: bl      0x8025E020
    {
            ctx->lr = 0x80191BC0u;
            ctx->pc = 0x8025E020u;
            return;
    }

label_80191BC0:
    ctx->downcount -= 3;
    // 80191BC0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191BC4:
    // 80191BC4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191BC8:
    // 80191BC8: bl      0x801CFEAC
    {
            ctx->lr = 0x80191BCCu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191BCC:
    ctx->downcount -= 3;
    // 80191BCC: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191BD0:
    // 80191BD0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191BD4:
    // 80191BD4: bl      0x801CFEAC
    {
            ctx->lr = 0x80191BD8u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191BD8:
    ctx->downcount -= 1;
    // 80191BD8: b       0x80191DC8
    {
            goto label_80191DC8;
    }

label_80191BDC:
    ctx->downcount -= 3;
    // 80191BDC: or   r3, r18, r18
    {
        ctx->gpr[3] = ctx->gpr[18] | ctx->gpr[18];
    }

label_80191BE0:
    // 80191BE0: addi    r29, r23, 1968
    ctx->gpr[29] = ctx->gpr[23] + (u32)(s32)(1968);

label_80191BE4:
    // 80191BE4: bl      0x8008E9C0
    {
            ctx->lr = 0x80191BE8u;
            ctx->pc = 0x8008E9C0u;
            return;
    }

label_80191BE8:
    ctx->downcount -= 9;
    // 80191BE8: or   r31, r29, r29
    {
        ctx->gpr[31] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191BEC:
    // 80191BEC: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80191BF0:
    ctx->pc = 0x80191BF0u;
    // 80191BF0: stw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80191BF4:
    // 80191BF4: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191BF8:
    // 80191BF8: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_80191BFC:
    // 80191BFC: or   r5, r24, r24
    {
        ctx->gpr[5] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191C00:
    // 80191C00: or   r7, r20, r20
    {
        ctx->gpr[7] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191C04:
    // 80191C04: or   r8, r19, r19
    {
        ctx->gpr[8] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80191C08:
    // 80191C08: bl      0x80192108
    {
            ctx->lr = 0x80191C0Cu;
            goto label_80192108;
    }

label_80191C0C:
    ctx->pc = 0x80191C0Cu;
    ctx->downcount -= 4;
    // 80191C0C: lwz     r3, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80191C10:
    ctx->pc = 0x80191C10u;
    // 80191C10: lwz     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191C14:
    // 80191C14: cmpw    r3, r0
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

label_80191C18:
    // 80191C18: bc    12, 2, 0x80191C3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191C3C;
        }
    }

label_80191C1C:
    ctx->downcount -= 2;
    // 80191C1C: cmpwi   r3, 0
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

label_80191C20:
    // 80191C20: bc    12, 2, 0x80191C2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191C2C;
        }
    }

label_80191C24:
    ctx->downcount -= 2;
    // 80191C24: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_80191C28:
    // 80191C28: bl      0x80197838
    {
            ctx->lr = 0x80191C2Cu;
            ctx->pc = 0x80197838u;
            return;
    }

label_80191C2C:
    ctx->pc = 0x80191C2Cu;
    ctx->downcount -= 4;
    // 80191C2C: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191C30:
    // 80191C30: addi    r9, r9, 884
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(884);

label_80191C34:
    ctx->pc = 0x80191C34u;
    // 80191C34: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80191C38:
    // 80191C38: b       0x80191DA4
    {
            goto label_80191DA4;
    }

label_80191C3C:
    ctx->pc = 0x80191C3Cu;
    ctx->downcount -= 18;
    // 80191C3C: lwz     r0, 1968(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(1968);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191C40:
    // 80191C40: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191C44:
    // 80191C44: lis     r9, 29950
    ctx->gpr[9] = ((u32)(s32)(29950) << 16);

label_80191C48:
    // 80191C48: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_80191C4C:
    // 80191C4C: ori     r9, r9, 0xD775
    ctx->gpr[9] = ctx->gpr[9] | 0xD775u;

label_80191C50:
    // 80191C50: subf   r0, r0, r27
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80191C54:
    // 80191C54: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_80191C58:
    ctx->pc = 0x80191C58u;
    // 80191C58: stw     r11, 940(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(940);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80191C5C:
    // 80191C5C: addi    r10, r1, 940
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(940);

label_80191C60:
    // 80191C60: addi    r11, r1, 936
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(936);

label_80191C64:
    // 80191C64: srawi r9, r0, 2
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

label_80191C68:
    ctx->pc = 0x80191C68u;
    // 80191C68: stw     r9, 936(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(936);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80191C6C:
    // 80191C6C: cmplwi  r9, 0x0001
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

label_80191C70:
    // 80191C70: bc    4, 0, 0x80191C78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191C78;
        }
    }

label_80191C74:
    ctx->downcount -= 1;
    // 80191C74: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_80191C78:
    ctx->pc = 0x80191C78u;
    ctx->downcount -= 3;
    // 80191C78: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191C7C:
    // 80191C7C: add.   r3, r9, r0
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80191C80:
    // 80191C80: bc    12, 2, 0x80191CA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191CA4;
        }
    }

label_80191C84:
    ctx->downcount -= 6;
    // 80191C84: mulli   r3, r3, 884
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)884);

label_80191C88:
    // 80191C88: cmplwi  r3, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191C8C:
    // 80191C8C: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191C90:
    // 80191C90: bc    4, 1, 0x80191C9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191C9C;
        }
    }

label_80191C94:
    ctx->downcount -= 1;
    // 80191C94: bl      0x80281C60
    {
            ctx->lr = 0x80191C98u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80191C98:
    ctx->downcount -= 1;
    // 80191C98: b       0x80191CAC
    {
            goto label_80191CAC;
    }

label_80191C9C:
    ctx->downcount -= 1;
    // 80191C9C: bl      0x80004024
    {
            ctx->lr = 0x80191CA0u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80191CA0:
    ctx->downcount -= 1;
    // 80191CA0: b       0x80191CAC
    {
            goto label_80191CAC;
    }

label_80191CA4:
    ctx->downcount -= 2;
    // 80191CA4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80191CA8:
    // 80191CA8: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80191CAC:
    ctx->downcount -= 5;
    // 80191CAC: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191CB0:
    ctx->pc = 0x80191CB0u;
    // 80191CB0: lwz     r30, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80191CB4:
    // 80191CB4: or   r31, r28, r28
    {
        ctx->gpr[31] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191CB8:
    // 80191CB8: cmpw    r30, r27
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191CBC:
    // 80191CBC: bc    12, 2, 0x80191CE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191CE4;
        }
    }

label_80191CC0:
    ctx->downcount -= 2;
    // 80191CC0: cmpwi   r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191CC4:
    // 80191CC4: bc    12, 2, 0x80191CD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191CD4;
        }
    }

label_80191CC8:
    ctx->downcount -= 3;
    // 80191CC8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191CCC:
    // 80191CCC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191CD0:
    // 80191CD0: bl      0x80197838
    {
            ctx->lr = 0x80191CD4u;
            ctx->pc = 0x80197838u;
            return;
    }

label_80191CD4:
    ctx->downcount -= 4;
    // 80191CD4: addi    r30, r30, 884
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(884);

label_80191CD8:
    // 80191CD8: addi    r28, r28, 884
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(884);

label_80191CDC:
    // 80191CDC: cmpw    r30, r27
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191CE0:
    // 80191CE0: bc    4, 2, 0x80191CC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80191CC0u;
                return;
            }
            goto label_80191CC0;
        }
    }

label_80191CE4:
    ctx->pc = 0x80191CE4u;
    ctx->downcount -= 3;
    // 80191CE4: lwz     r0, 940(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(940);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191CE8:
    // 80191CE8: cmpwi   r0, 1
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

label_80191CEC:
    // 80191CEC: bc    4, 2, 0x80191D0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191D0C;
        }
    }

label_80191CF0:
    ctx->downcount -= 2;
    // 80191CF0: cmpwi   r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191CF4:
    // 80191CF4: bc    12, 2, 0x80191D04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191D04;
        }
    }

label_80191CF8:
    ctx->downcount -= 3;
    // 80191CF8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191CFC:
    // 80191CFC: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_80191D00:
    // 80191D00: bl      0x80197838
    {
            ctx->lr = 0x80191D04u;
            ctx->pc = 0x80197838u;
            return;
    }

label_80191D04:
    ctx->downcount -= 2;
    // 80191D04: addi    r28, r28, 884
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(884);

label_80191D08:
    // 80191D08: b       0x80191D3C
    {
            goto label_80191D3C;
    }

label_80191D0C:
    ctx->downcount -= 3;
    // 80191D0C: or   r30, r28, r28
    {
        ctx->gpr[30] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191D10:
    // 80191D10: or.   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[28];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80191D14:
    // 80191D14: bc    12, 2, 0x80191D38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191D38;
        }
    }

label_80191D18:
    ctx->downcount -= 2;
    // 80191D18: cmpwi   r30, 0
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

label_80191D1C:
    // 80191D1C: bc    12, 2, 0x80191D2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191D2C;
        }
    }

label_80191D20:
    ctx->downcount -= 3;
    // 80191D20: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191D24:
    // 80191D24: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_80191D28:
    // 80191D28: bl      0x80197838
    {
            ctx->lr = 0x80191D2Cu;
            ctx->pc = 0x80197838u;
            return;
    }

label_80191D2C:
    ctx->downcount -= 3;
    // 80191D2C: addi    r30, r30, 884
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(884);

label_80191D30:
    // 80191D30: addic.  r28, r28, -1
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

label_80191D34:
    // 80191D34: bc    4, 2, 0x80191D18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80191D18u;
                return;
            }
            goto label_80191D18;
        }
    }

label_80191D38:
    ctx->downcount -= 1;
    // 80191D38: or   r28, r30, r30
    {
        ctx->gpr[28] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191D3C:
    ctx->pc = 0x80191D3Cu;
    ctx->downcount -= 6;
    // 80191D3C: lwz     r11, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80191D40:
    ctx->pc = 0x80191D40u;
    // 80191D40: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191D44:
    // 80191D44: or   r3, r11, r11
    {
        ctx->gpr[3] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80191D48:
    ctx->pc = 0x80191D48u;
    // 80191D48: lwz     r9, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191D4C:
    // 80191D4C: cmpw    r11, r0
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

label_80191D50:
    // 80191D50: bc    12, 2, 0x80191D60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191D60;
        }
    }

label_80191D54:
    loop_80191D54(ctx);
    if (ctx->pc == 0x80191D60u) goto label_80191D60;
    return;
label_80191D58:
    // 80191D58: cmpw    r11, r0
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

label_80191D5C:
    // 80191D5C: bc    4, 2, 0x80191D54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80191D54u;
                return;
            }
            goto label_80191D54;
        }
    }

label_80191D60:
    ctx->downcount -= 11;
    // 80191D60: lis     r0, 29950
    ctx->gpr[0] = ((u32)(s32)(29950) << 16);

label_80191D64:
    // 80191D64: subf   r9, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80191D68:
    // 80191D68: ori     r0, r0, 0xD775
    ctx->gpr[0] = ctx->gpr[0] | 0xD775u;

label_80191D6C:
    // 80191D6C: cmpwi   r3, 0
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

label_80191D70:
    // 80191D70: mullw   r9, r9, r0
    {
        s64 product = (s64)(s32)ctx->gpr[9] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[9] = (u32)product;
    }

label_80191D74:
    // 80191D74: srawi r4, r9, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[9];
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

label_80191D78:
    // 80191D78: bc    12, 2, 0x80191D94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191D94;
        }
    }

label_80191D7C:
    ctx->downcount -= 5;
    // 80191D7C: mulli   r4, r4, 884
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)884);

label_80191D80:
    // 80191D80: cmplwi  r4, 0x0080
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

label_80191D84:
    // 80191D84: bc    4, 1, 0x80191D90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191D90;
        }
    }

label_80191D88:
    ctx->downcount -= 1;
    // 80191D88: bl      0x80281D80
    {
            ctx->lr = 0x80191D8Cu;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80191D8C:
    ctx->downcount -= 1;
    // 80191D8C: b       0x80191D94
    {
            goto label_80191D94;
    }

label_80191D90:
    ctx->downcount -= 1;
    // 80191D90: bl      0x8001D934
    {
            ctx->lr = 0x80191D94u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80191D94:
    ctx->downcount -= 4;
    // 80191D94: add   r0, r26, r31
    {
        u32 a = ctx->gpr[26];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80191D98:
    ctx->pc = 0x80191D98u;
    // 80191D98: stw     r31, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80191D9C:
    ctx->pc = 0x80191D9Cu;
    // 80191D9C: stw     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80191DA0:
    ctx->pc = 0x80191DA0u;
    // 80191DA0: stw     r28, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80191DA4:
    ctx->downcount -= 3;
    // 80191DA4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191DA8:
    // 80191DA8: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_80191DAC:
    // 80191DAC: bl      0x8025E020
    {
            ctx->lr = 0x80191DB0u;
            ctx->pc = 0x8025E020u;
            return;
    }

label_80191DB0:
    ctx->downcount -= 3;
    // 80191DB0: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80191DB4:
    // 80191DB4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191DB8:
    // 80191DB8: bl      0x801CFEAC
    {
            ctx->lr = 0x80191DBCu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191DBC:
    ctx->downcount -= 3;
    // 80191DBC: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191DC0:
    // 80191DC0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191DC4:
    // 80191DC4: bl      0x801CFEAC
    {
            ctx->lr = 0x80191DC8u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191DC8:
    ctx->downcount -= 3;
    // 80191DC8: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191DCC:
    // 80191DCC: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_80191DD0:
    // 80191DD0: bl      0x8025F7B8
    {
            ctx->lr = 0x80191DD4u;
            ctx->pc = 0x8025F7B8u;
            return;
    }

label_80191DD4:
    ctx->downcount -= 2;
    // 80191DD4: cmpwi   r3, 0
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

label_80191DD8:
    // 80191DD8: bc    4, 2, 0x80191B34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80191B34u;
                return;
            }
            goto label_80191B34;
        }
    }

label_80191DDC:
    ctx->pc = 0x80191DDCu;
    ctx->downcount -= 5;
    // 80191DDC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80191DE0:
    ctx->pc = 0x80191DE0u;
    // 80191DE0: addi    r22, r1, 928
    ctx->gpr[22] = ctx->gpr[1] + (u32)(s32)(928);

label_80191DE4:
    ctx->pc = 0x80191DE4u;
    // 80191DE4: addi    r4, r4, -18884
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-18884);

label_80191DE8:
    ctx->pc = 0x80191DE8u;
    // 80191DE8: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191DEC:
    ctx->pc = 0x80191DECu;
    // 80191DEC: bl      0x801CFE08
    {
            ctx->lr = 0x80191DF0u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191DF0:
    ctx->pc = 0x80191DF0u;
    ctx->downcount -= 5;
    // 80191DF0: lwz     r25, -26944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26944);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80191DF4:
    ctx->pc = 0x80191DF4u;
    // 80191DF4: li      r4, -10000
    ctx->gpr[4] = (u32)(s32)(-10000);

label_80191DF8:
    ctx->pc = 0x80191DF8u;
    // 80191DF8: lwz     r5, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80191DFC:
    ctx->pc = 0x80191DFCu;
    // 80191DFC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191E00:
    ctx->pc = 0x80191E00u;
    // 80191E00: bl      0x8025EE94
    {
            ctx->lr = 0x80191E04u;
            ctx->pc = 0x8025EE94u;
            return;
    }

label_80191E04:
    ctx->pc = 0x80191E04u;
    ctx->downcount -= 2;
    // 80191E04: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191E08:
    ctx->pc = 0x80191E08u;
    // 80191E08: bl      0x8025EA18
    {
            ctx->lr = 0x80191E0Cu;
            ctx->pc = 0x8025EA18u;
            return;
    }

label_80191E0C:
    ctx->pc = 0x80191E0Cu;
    ctx->downcount -= 1;
    // 80191E0C: b       0x801920B0
    {
            goto label_801920B0;
    }

label_80191E10:
    ctx->downcount -= 3;
    // 80191E10: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191E14:
    // 80191E14: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_80191E18:
    // 80191E18: bl      0x8025D7A8
    {
            ctx->lr = 0x80191E1Cu;
            ctx->pc = 0x8025D7A8u;
            return;
    }

label_80191E1C:
    ctx->downcount -= 6;
    // 80191E1C: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80191E20:
    // 80191E20: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191E24:
    // 80191E24: or   r4, r20, r20
    {
        ctx->gpr[4] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191E28:
    // 80191E28: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80191E2C:
    // 80191E2C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80191E30:
    // 80191E30: bl      0x801CFE08
    {
            ctx->lr = 0x80191E34u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80191E34:
    ctx->downcount -= 3;
    // 80191E34: addi    r4, r17, -16556
    ctx->gpr[4] = ctx->gpr[17] + (u32)(s32)(-16556);

label_80191E38:
    // 80191E38: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80191E3C:
    // 80191E3C: bl      0x801CFC48
    {
            ctx->lr = 0x80191E40u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191E40:
    ctx->downcount -= 3;
    // 80191E40: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80191E44:
    // 80191E44: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191E48:
    // 80191E48: bl      0x801CFC48
    {
            ctx->lr = 0x80191E4Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80191E4C:
    ctx->pc = 0x80191E4Cu;
    ctx->downcount -= 4;
    // 80191E4C: stw     r30, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80191E50:
    // 80191E50: addi    r31, r23, 1968
    ctx->gpr[31] = ctx->gpr[23] + (u32)(s32)(1968);

label_80191E54:
    // 80191E54: or   r21, r22, r22
    {
        ctx->gpr[21] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80191E58:
    // 80191E58: b       0x80191E60
    {
            goto label_80191E60;
    }

label_80191E5C:
    ctx->downcount -= 1;
    // 80191E5C: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_80191E60:
    ctx->pc = 0x80191E60u;
    ctx->downcount -= 13;
    // 80191E60: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191E64:
    // 80191E64: lis     r30, 29950
    ctx->gpr[30] = ((u32)(s32)(29950) << 16);

label_80191E68:
    ctx->pc = 0x80191E68u;
    // 80191E68: lwz     r11, 1968(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(1968);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80191E6C:
    // 80191E6C: ori     r30, r30, 0xD775
    ctx->gpr[30] = ctx->gpr[30] | 0xD775u;

label_80191E70:
    // 80191E70: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80191E74:
    // 80191E74: mullw   r0, r0, r30
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[30];
        ctx->gpr[0] = (u32)product;
    }

label_80191E78:
    // 80191E78: srawi r0, r0, 2
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

label_80191E7C:
    // 80191E7C: cmplw   r28, r0
    {
        u32 val_a = (u32)(ctx->gpr[28]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191E80:
    // 80191E80: bc    4, 0, 0x80191EA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191EA4;
        }
    }

label_80191E84:
    ctx->downcount -= 7;
    // 80191E84: mulli   r9, r28, 884
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[28] * (s64)(s32)884);

label_80191E88:
    ctx->pc = 0x80191E88u;
    // 80191E88: lwz     r3, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80191E8C:
    // 80191E8C: add   r9, r11, r9
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80191E90:
    ctx->pc = 0x80191E90u;
    // 80191E90: lwz     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80191E94:
    // 80191E94: bl      0x80297FBC
    {
            ctx->lr = 0x80191E98u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80191E98:
    ctx->downcount -= 2;
    // 80191E98: cmpwi   r3, 0
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

label_80191E9C:
    // 80191E9C: bc    4, 2, 0x80191E5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80191E5Cu;
                return;
            }
            goto label_80191E5C;
        }
    }

label_80191EA0:
    ctx->downcount -= 1;
    // 80191EA0: li      r27, 1
    ctx->gpr[27] = (u32)(s32)(1);

label_80191EA4:
    ctx->downcount -= 2;
    // 80191EA4: cmpwi   r27, 0
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

label_80191EA8:
    // 80191EA8: bc    4, 2, 0x80192098
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192098;
        }
    }

label_80191EAC:
    ctx->downcount -= 5;
    // 80191EAC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80191EB0:
    // 80191EB0: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80191EB4:
    // 80191EB4: addi    r4, r4, -16540
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16540);

label_80191EB8:
    // 80191EB8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80191EBC:
    // 80191EBC: bl      0x801CFFC8
    {
            ctx->lr = 0x80191EC0u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80191EC0:
    ctx->downcount -= 2;
    // 80191EC0: cmpwi   r3, 0
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

label_80191EC4:
    // 80191EC4: bc    12, 2, 0x80191EE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191EE4;
        }
    }

label_80191EC8:
    ctx->downcount -= 3;
    // 80191EC8: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80191ECC:
    // 80191ECC: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_80191ED0:
    // 80191ED0: bl      0x8025E020
    {
            ctx->lr = 0x80191ED4u;
            ctx->pc = 0x8025E020u;
            return;
    }

label_80191ED4:
    ctx->downcount -= 3;
    // 80191ED4: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80191ED8:
    // 80191ED8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80191EDC:
    // 80191EDC: bl      0x801CFEAC
    {
            ctx->lr = 0x80191EE0u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_80191EE0:
    ctx->downcount -= 1;
    // 80191EE0: b       0x801920B0
    {
            goto label_801920B0;
    }

label_80191EE4:
    ctx->downcount -= 7;
    // 80191EE4: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80191EE8:
    // 80191EE8: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_80191EEC:
    // 80191EEC: or   r5, r21, r21
    {
        ctx->gpr[5] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80191EF0:
    // 80191EF0: or   r6, r24, r24
    {
        ctx->gpr[6] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80191EF4:
    // 80191EF4: or   r7, r20, r20
    {
        ctx->gpr[7] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80191EF8:
    // 80191EF8: or   r8, r19, r19
    {
        ctx->gpr[8] = ctx->gpr[19] | ctx->gpr[19];
    }

label_80191EFC:
    // 80191EFC: bl      0x80192108
    {
            ctx->lr = 0x80191F00u;
            goto label_80192108;
    }

label_80191F00:
    ctx->pc = 0x80191F00u;
    ctx->downcount -= 4;
    // 80191F00: lwz     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80191F04:
    ctx->pc = 0x80191F04u;
    // 80191F04: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191F08:
    // 80191F08: cmpw    r3, r0
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

label_80191F0C:
    // 80191F0C: bc    12, 2, 0x80191F30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191F30;
        }
    }

label_80191F10:
    ctx->downcount -= 2;
    // 80191F10: cmpwi   r3, 0
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

label_80191F14:
    // 80191F14: bc    12, 2, 0x80191F20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191F20;
        }
    }

label_80191F18:
    ctx->downcount -= 2;
    // 80191F18: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_80191F1C:
    // 80191F1C: bl      0x80197838
    {
            ctx->lr = 0x80191F20u;
            ctx->pc = 0x80197838u;
            return;
    }

label_80191F20:
    ctx->pc = 0x80191F20u;
    ctx->downcount -= 4;
    // 80191F20: lwz     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80191F24:
    // 80191F24: addi    r9, r9, 884
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(884);

label_80191F28:
    ctx->pc = 0x80191F28u;
    // 80191F28: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80191F2C:
    // 80191F2C: b       0x80192098
    {
            goto label_80192098;
    }

label_80191F30:
    ctx->pc = 0x80191F30u;
    ctx->downcount -= 16;
    // 80191F30: lwz     r0, 1968(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(1968);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191F34:
    // 80191F34: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191F38:
    // 80191F38: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80191F3C:
    // 80191F3C: addi    r10, r1, 948
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(948);

label_80191F40:
    // 80191F40: subf   r0, r0, r27
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80191F44:
    ctx->pc = 0x80191F44u;
    // 80191F44: stw     r9, 948(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(948);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80191F48:
    // 80191F48: mullw   r0, r0, r30
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[30];
        ctx->gpr[0] = (u32)product;
    }

label_80191F4C:
    // 80191F4C: addi    r11, r1, 944
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(944);

label_80191F50:
    // 80191F50: srawi r9, r0, 2
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

label_80191F54:
    ctx->pc = 0x80191F54u;
    // 80191F54: stw     r9, 944(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(944);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80191F58:
    // 80191F58: cmplwi  r9, 0x0001
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

label_80191F5C:
    // 80191F5C: bc    4, 0, 0x80191F64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191F64;
        }
    }

label_80191F60:
    ctx->downcount -= 1;
    // 80191F60: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_80191F64:
    ctx->pc = 0x80191F64u;
    ctx->downcount -= 3;
    // 80191F64: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191F68:
    // 80191F68: add.   r0, r9, r0
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

label_80191F6C:
    // 80191F6C: bc    12, 2, 0x80191F98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191F98;
        }
    }

label_80191F70:
    ctx->downcount -= 6;
    // 80191F70: mulli   r0, r0, 884
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)884);

label_80191F74:
    // 80191F74: or   r29, r0, r0
    {
        ctx->gpr[29] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80191F78:
    // 80191F78: cmplwi  r0, 0x0080
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

label_80191F7C:
    // 80191F7C: bc    4, 1, 0x80191F8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80191F8C;
        }
    }

label_80191F80:
    ctx->downcount -= 2;
    // 80191F80: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191F84:
    // 80191F84: bl      0x80281C60
    {
            ctx->lr = 0x80191F88u;
            ctx->pc = 0x80281C60u;
            return;
    }

label_80191F88:
    ctx->downcount -= 1;
    // 80191F88: b       0x80191FA0
    {
            goto label_80191FA0;
    }

label_80191F8C:
    ctx->downcount -= 2;
    // 80191F8C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80191F90:
    // 80191F90: bl      0x80004024
    {
            ctx->lr = 0x80191F94u;
            ctx->pc = 0x80004024u;
            return;
    }

label_80191F94:
    ctx->downcount -= 1;
    // 80191F94: b       0x80191FA0
    {
            goto label_80191FA0;
    }

label_80191F98:
    ctx->downcount -= 2;
    // 80191F98: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80191F9C:
    // 80191F9C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80191FA0:
    ctx->downcount -= 5;
    // 80191FA0: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80191FA4:
    ctx->pc = 0x80191FA4u;
    // 80191FA4: lwz     r30, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80191FA8:
    // 80191FA8: or   r26, r28, r28
    {
        ctx->gpr[26] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191FAC:
    // 80191FAC: cmpw    r30, r27
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191FB0:
    // 80191FB0: bc    12, 2, 0x80191FD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191FD8;
        }
    }

label_80191FB4:
    ctx->downcount -= 2;
    // 80191FB4: cmpwi   r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191FB8:
    // 80191FB8: bc    12, 2, 0x80191FC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191FC8;
        }
    }

label_80191FBC:
    ctx->downcount -= 3;
    // 80191FBC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191FC0:
    // 80191FC0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80191FC4:
    // 80191FC4: bl      0x80197838
    {
            ctx->lr = 0x80191FC8u;
            ctx->pc = 0x80197838u;
            return;
    }

label_80191FC8:
    ctx->downcount -= 4;
    // 80191FC8: addi    r30, r30, 884
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(884);

label_80191FCC:
    // 80191FCC: addi    r28, r28, 884
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(884);

label_80191FD0:
    // 80191FD0: cmpw    r30, r27
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191FD4:
    // 80191FD4: bc    4, 2, 0x80191FB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80191FB4u;
                return;
            }
            goto label_80191FB4;
        }
    }

label_80191FD8:
    ctx->pc = 0x80191FD8u;
    ctx->downcount -= 3;
    // 80191FD8: lwz     r0, 948(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80191FDC:
    // 80191FDC: cmpwi   r0, 1
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

label_80191FE0:
    // 80191FE0: bc    4, 2, 0x80192000
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192000;
        }
    }

label_80191FE4:
    ctx->downcount -= 2;
    // 80191FE4: cmpwi   r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80191FE8:
    // 80191FE8: bc    12, 2, 0x80191FF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80191FF8;
        }
    }

label_80191FEC:
    ctx->downcount -= 3;
    // 80191FEC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80191FF0:
    // 80191FF0: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_80191FF4:
    // 80191FF4: bl      0x80197838
    {
            ctx->lr = 0x80191FF8u;
            ctx->pc = 0x80197838u;
            return;
    }

label_80191FF8:
    ctx->downcount -= 2;
    // 80191FF8: addi    r28, r28, 884
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(884);

label_80191FFC:
    // 80191FFC: b       0x80192030
    {
            goto label_80192030;
    }

label_80192000:
    ctx->downcount -= 3;
    // 80192000: or   r30, r28, r28
    {
        ctx->gpr[30] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80192004:
    // 80192004: or.   r28, r0, r0
    {
        ctx->gpr[28] = ctx->gpr[0] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[28];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80192008:
    // 80192008: bc    12, 2, 0x8019202C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019202C;
        }
    }

label_8019200C:
    ctx->downcount -= 2;
    // 8019200C: cmpwi   r30, 0
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

label_80192010:
    // 80192010: bc    12, 2, 0x80192020
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80192020;
        }
    }

label_80192014:
    ctx->downcount -= 3;
    // 80192014: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192018:
    // 80192018: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_8019201C:
    // 8019201C: bl      0x80197838
    {
            ctx->lr = 0x80192020u;
            ctx->pc = 0x80197838u;
            return;
    }

label_80192020:
    ctx->downcount -= 3;
    // 80192020: addi    r30, r30, 884
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(884);

label_80192024:
    // 80192024: addic.  r28, r28, -1
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

label_80192028:
    // 80192028: bc    4, 2, 0x8019200C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019200Cu;
                return;
            }
            goto label_8019200C;
        }
    }

label_8019202C:
    ctx->downcount -= 1;
    // 8019202C: or   r28, r30, r30
    {
        ctx->gpr[28] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192030:
    ctx->pc = 0x80192030u;
    ctx->downcount -= 6;
    // 80192030: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80192034:
    ctx->pc = 0x80192034u;
    // 80192034: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80192038:
    // 80192038: or   r3, r11, r11
    {
        ctx->gpr[3] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8019203C:
    ctx->pc = 0x8019203Cu;
    // 8019203C: lwz     r9, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80192040:
    // 80192040: cmpw    r11, r0
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

label_80192044:
    // 80192044: bc    12, 2, 0x80192054
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80192054;
        }
    }

label_80192048:
    loop_80192048(ctx);
    if (ctx->pc == 0x80192054u) goto label_80192054;
    return;
label_8019204C:
    // 8019204C: cmpw    r11, r0
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

label_80192050:
    // 80192050: bc    4, 2, 0x80192048
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80192048u;
                return;
            }
            goto label_80192048;
        }
    }

label_80192054:
    ctx->downcount -= 11;
    // 80192054: lis     r0, 29950
    ctx->gpr[0] = ((u32)(s32)(29950) << 16);

label_80192058:
    // 80192058: subf   r9, r3, r9
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_8019205C:
    // 8019205C: ori     r0, r0, 0xD775
    ctx->gpr[0] = ctx->gpr[0] | 0xD775u;

label_80192060:
    // 80192060: cmpwi   r3, 0
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

label_80192064:
    // 80192064: mullw   r9, r9, r0
    {
        s64 product = (s64)(s32)ctx->gpr[9] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[9] = (u32)product;
    }

label_80192068:
    // 80192068: srawi r4, r9, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[9];
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

label_8019206C:
    // 8019206C: bc    12, 2, 0x80192088
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80192088;
        }
    }

label_80192070:
    ctx->downcount -= 5;
    // 80192070: mulli   r4, r4, 884
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)884);

label_80192074:
    // 80192074: cmplwi  r4, 0x0080
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

label_80192078:
    // 80192078: bc    4, 1, 0x80192084
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192084;
        }
    }

label_8019207C:
    ctx->downcount -= 1;
    // 8019207C: bl      0x80281D80
    {
            ctx->lr = 0x80192080u;
            ctx->pc = 0x80281D80u;
            return;
    }

label_80192080:
    ctx->downcount -= 1;
    // 80192080: b       0x80192088
    {
            goto label_80192088;
    }

label_80192084:
    ctx->downcount -= 1;
    // 80192084: bl      0x8001D934
    {
            ctx->lr = 0x80192088u;
            ctx->pc = 0x8001D934u;
            return;
    }

label_80192088:
    ctx->downcount -= 4;
    // 80192088: add   r0, r29, r26
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8019208C:
    ctx->pc = 0x8019208Cu;
    // 8019208C: stw     r26, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80192090:
    ctx->pc = 0x80192090u;
    // 80192090: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192094:
    ctx->pc = 0x80192094u;
    // 80192094: stw     r28, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80192098:
    ctx->downcount -= 3;
    // 80192098: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8019209C:
    // 8019209C: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_801920A0:
    // 801920A0: bl      0x8025E020
    {
            ctx->lr = 0x801920A4u;
            ctx->pc = 0x8025E020u;
            return;
    }

label_801920A4:
    ctx->downcount -= 3;
    // 801920A4: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_801920A8:
    // 801920A8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801920AC:
    // 801920AC: bl      0x801CFEAC
    {
            ctx->lr = 0x801920B0u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_801920B0:
    ctx->downcount -= 3;
    // 801920B0: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801920B4:
    // 801920B4: li      r4, -2
    ctx->gpr[4] = (u32)(s32)(-2);

label_801920B8:
    // 801920B8: bl      0x8025F7B8
    {
            ctx->lr = 0x801920BCu;
            ctx->pc = 0x8025F7B8u;
            return;
    }

label_801920BC:
    ctx->downcount -= 2;
    // 801920BC: cmpwi   r3, 0
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

label_801920C0:
    // 801920C0: bc    4, 2, 0x80191E10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80191E10u;
                return;
            }
            goto label_80191E10;
        }
    }

label_801920C4:
    ctx->pc = 0x801920C4u;
    ctx->downcount -= 3;
    // 801920C4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801920C8:
    ctx->pc = 0x801920C8u;
    // 801920C8: or   r4, r16, r16
    {
        ctx->gpr[4] = ctx->gpr[16] | ctx->gpr[16];
    }

label_801920CC:
    ctx->pc = 0x801920CCu;
    // 801920CC: bl      0x8025E020
    {
            ctx->lr = 0x801920D0u;
            ctx->pc = 0x8025E020u;
            return;
    }

label_801920D0:
    ctx->pc = 0x801920D0u;
    ctx->downcount -= 3;
    // 801920D0: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801920D4:
    ctx->pc = 0x801920D4u;
    // 801920D4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801920D8:
    ctx->pc = 0x801920D8u;
    // 801920D8: bl      0x801CFEAC
    {
            ctx->lr = 0x801920DCu;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_801920DC:
    ctx->pc = 0x801920DCu;
    ctx->downcount -= 3;
    // 801920DC: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_801920E0:
    ctx->pc = 0x801920E0u;
    // 801920E0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801920E4:
    ctx->pc = 0x801920E4u;
    // 801920E4: bl      0x801CFEAC
    {
            ctx->lr = 0x801920E8u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_801920E8:
    ctx->pc = 0x801920E8u;
    ctx->downcount -= 3;
    // 801920E8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_801920EC:
    ctx->pc = 0x801920ECu;
    // 801920EC: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801920F0:
    ctx->pc = 0x801920F0u;
    // 801920F0: bl      0x801CFEAC
    {
            ctx->lr = 0x801920F4u;
            ctx->pc = 0x801CFEACu;
            return;
    }

label_801920F4:
    ctx->pc = 0x801920F4u;
    ctx->downcount -= 16;
    // 801920F4: lwz     r0, 1028(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1028);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801920F8:
    ctx->pc = 0x801920F8u;
    // 801920F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801920FC:
    ctx->pc = 0x801920FCu;
    // 801920FC: lmw     r15, 956(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(956);
        for (u32 r = 15; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80192100:
    ctx->pc = 0x80192100u;
    // 80192100: addi    r1, r1, 1024
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(1024);

label_80192104:
    ctx->pc = 0x80192104u;
    // 80192104: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8018F4C0;
        }
    }

label_80192108:
    ctx->pc = 0x80192108u;
    ctx->downcount -= 33;
    // 80192108: stwu     r1, -256(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-256);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019210C:
    ctx->pc = 0x8019210Cu;
    // 8019210C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80192110:
    ctx->pc = 0x80192110u;
    // 80192110: stfd     f28, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192110u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[28]));
    }

label_80192114:
    ctx->pc = 0x80192114u;
    // 80192114: stfd     f29, 232(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192114u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_80192118:
    ctx->pc = 0x80192118u;
    // 80192118: stfd     f30, 240(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192118u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8019211C:
    ctx->pc = 0x8019211Cu;
    // 8019211C: stfd     f31, 248(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019211Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80192120:
    ctx->pc = 0x80192120u;
    // 80192120: stmw     r14, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80192124:
    ctx->pc = 0x80192124u;
    // 80192124: stw     r0, 260(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(260);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192128:
    ctx->pc = 0x80192128u;
    // 80192128: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8019212C:
    ctx->pc = 0x8019212Cu;
    // 8019212C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192130:
    ctx->pc = 0x80192130u;
    // 80192130: lfs     f30, -15240(r9)
    if (!ppc_fp_available_inline(ctx, 0x80192130u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15240);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_80192134:
    ctx->pc = 0x80192134u;
    // 80192134: or   r26, r6, r6
    {
        ctx->gpr[26] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80192138:
    ctx->pc = 0x80192138u;
    // 80192138: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8019213C:
    ctx->pc = 0x8019213Cu;
    // 8019213C: addi    r30, r30, -16520
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16520);

label_80192140:
    ctx->pc = 0x80192140u;
    // 80192140: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192144:
    ctx->pc = 0x80192144u;
    // 80192144: stw     r7, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80192148:
    ctx->pc = 0x80192148u;
    // 80192148: stw     r8, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019214C:
    ctx->pc = 0x8019214Cu;
    // 8019214C: or   r27, r5, r5
    {
        ctx->gpr[27] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80192150:
    ctx->pc = 0x80192150u;
    // 80192150: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192154:
    ctx->pc = 0x80192154u;
    // 80192154: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192158:
    ctx->pc = 0x80192158u;
    // 80192158: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x80192158u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8019215C:
    ctx->pc = 0x8019215Cu;
    // 8019215C: lis     r29, 17200
    ctx->gpr[29] = ((u32)(s32)(17200) << 16);

label_80192160:
    ctx->pc = 0x80192160u;
    // 80192160: bl      0x801D009C
    {
            ctx->lr = 0x80192164u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192164:
    ctx->pc = 0x80192164u;
    ctx->downcount -= 3;
    // 80192164: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192168:
    ctx->pc = 0x80192168u;
    // 80192168: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8019216C:
    ctx->pc = 0x8019216Cu;
    // 8019216C: bl      0x801D009C
    {
            ctx->lr = 0x80192170u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192170:
    ctx->pc = 0x80192170u;
    ctx->downcount -= 8;
    // 80192170: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192174:
    ctx->pc = 0x80192174u;
    // 80192174: stfs     f1, 40(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192174u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192178:
    ctx->pc = 0x80192178u;
    // 80192178: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019217C:
    ctx->pc = 0x8019217Cu;
    // 8019217C: lfs     f1, -15236(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019217Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15236);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80192180:
    ctx->pc = 0x80192180u;
    // 80192180: addi    r30, r30, -16508
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16508);

label_80192184:
    ctx->pc = 0x80192184u;
    // 80192184: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192188:
    ctx->pc = 0x80192188u;
    // 80192188: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019218C:
    ctx->pc = 0x8019218Cu;
    // 8019218C: bl      0x801D009C
    {
            ctx->lr = 0x80192190u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192190:
    ctx->pc = 0x80192190u;
    ctx->downcount -= 3;
    // 80192190: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192194:
    ctx->pc = 0x80192194u;
    // 80192194: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192198:
    ctx->pc = 0x80192198u;
    // 80192198: bl      0x801D009C
    {
            ctx->lr = 0x8019219Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019219C:
    ctx->pc = 0x8019219Cu;
    ctx->downcount -= 7;
    // 8019219C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801921A0:
    ctx->pc = 0x801921A0u;
    // 801921A0: stfs     f1, 44(r31)
    if (!ppc_fp_available_inline(ctx, 0x801921A0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801921A4:
    ctx->pc = 0x801921A4u;
    // 801921A4: addi    r30, r30, -16496
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16496);

label_801921A8:
    ctx->pc = 0x801921A8u;
    // 801921A8: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801921AC:
    ctx->pc = 0x801921ACu;
    // 801921AC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801921B0:
    ctx->pc = 0x801921B0u;
    // 801921B0: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x801921B0u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_801921B4:
    ctx->pc = 0x801921B4u;
    // 801921B4: bl      0x801D009C
    {
            ctx->lr = 0x801921B8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801921B8:
    ctx->pc = 0x801921B8u;
    ctx->downcount -= 3;
    // 801921B8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801921BC:
    ctx->pc = 0x801921BCu;
    // 801921BC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801921C0:
    ctx->pc = 0x801921C0u;
    // 801921C0: bl      0x801D009C
    {
            ctx->lr = 0x801921C4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801921C4:
    ctx->pc = 0x801921C4u;
    ctx->downcount -= 7;
    // 801921C4: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801921C8:
    ctx->pc = 0x801921C8u;
    // 801921C8: fmr    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801921C8u)) return;
    ctx->fpr[0] = ctx->fpr[1];

label_801921CC:
    ctx->pc = 0x801921CCu;
    // 801921CC: addi    r30, r30, -16488
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16488);

label_801921D0:
    ctx->pc = 0x801921D0u;
    // 801921D0: stfs     f0, 48(r31)
    if (!ppc_fp_available_inline(ctx, 0x801921D0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801921D4:
    ctx->pc = 0x801921D4u;
    // 801921D4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801921D8:
    ctx->pc = 0x801921D8u;
    // 801921D8: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801921DC:
    ctx->pc = 0x801921DCu;
    // 801921DC: bl      0x801D009C
    {
            ctx->lr = 0x801921E0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801921E0:
    ctx->pc = 0x801921E0u;
    ctx->downcount -= 3;
    // 801921E0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801921E4:
    ctx->pc = 0x801921E4u;
    // 801921E4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801921E8:
    ctx->pc = 0x801921E8u;
    // 801921E8: bl      0x801D009C
    {
            ctx->lr = 0x801921ECu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801921EC:
    ctx->pc = 0x801921ECu;
    ctx->downcount -= 7;
    // 801921EC: stfs     f1, 52(r31)
    if (!ppc_fp_available_inline(ctx, 0x801921ECu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801921F0:
    ctx->pc = 0x801921F0u;
    // 801921F0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801921F4:
    ctx->pc = 0x801921F4u;
    // 801921F4: addi    r30, r30, -16476
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16476);

label_801921F8:
    ctx->pc = 0x801921F8u;
    // 801921F8: lfs     f1, 48(r31)
    if (!ppc_fp_available_inline(ctx, 0x801921F8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801921FC:
    ctx->pc = 0x801921FCu;
    // 801921FC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192200:
    ctx->pc = 0x80192200u;
    // 80192200: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192204:
    ctx->pc = 0x80192204u;
    // 80192204: bl      0x801D009C
    {
            ctx->lr = 0x80192208u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192208:
    ctx->pc = 0x80192208u;
    ctx->downcount -= 3;
    // 80192208: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019220C:
    ctx->pc = 0x8019220Cu;
    // 8019220C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192210:
    ctx->pc = 0x80192210u;
    // 80192210: bl      0x801D009C
    {
            ctx->lr = 0x80192214u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192214:
    ctx->pc = 0x80192214u;
    ctx->downcount -= 7;
    // 80192214: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192218:
    ctx->pc = 0x80192218u;
    // 80192218: fmr    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80192218u)) return;
    ctx->fpr[0] = ctx->fpr[1];

label_8019221C:
    ctx->pc = 0x8019221Cu;
    // 8019221C: addi    r30, r30, -16464
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16464);

label_80192220:
    ctx->pc = 0x80192220u;
    // 80192220: stfs     f0, 56(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192220u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80192224:
    ctx->pc = 0x80192224u;
    // 80192224: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192228:
    ctx->pc = 0x80192228u;
    // 80192228: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8019222C:
    ctx->pc = 0x8019222Cu;
    // 8019222C: bl      0x801D009C
    {
            ctx->lr = 0x80192230u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192230:
    ctx->pc = 0x80192230u;
    ctx->downcount -= 3;
    // 80192230: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192234:
    ctx->pc = 0x80192234u;
    // 80192234: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192238:
    ctx->pc = 0x80192238u;
    // 80192238: bl      0x801D009C
    {
            ctx->lr = 0x8019223Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019223C:
    ctx->pc = 0x8019223Cu;
    ctx->downcount -= 7;
    // 8019223C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192240:
    ctx->pc = 0x80192240u;
    // 80192240: stfs     f1, 60(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192240u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192244:
    ctx->pc = 0x80192244u;
    // 80192244: addi    r30, r30, -16056
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16056);

label_80192248:
    ctx->pc = 0x80192248u;
    // 80192248: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8019224C:
    ctx->pc = 0x8019224Cu;
    // 8019224C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192250:
    ctx->pc = 0x80192250u;
    // 80192250: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192254:
    ctx->pc = 0x80192254u;
    // 80192254: bl      0x801CFFC8
    {
            ctx->lr = 0x80192258u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192258:
    ctx->pc = 0x80192258u;
    ctx->downcount -= 4;
    // 80192258: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019225C:
    ctx->pc = 0x8019225Cu;
    // 8019225C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192260:
    ctx->pc = 0x80192260u;
    // 80192260: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192264:
    ctx->pc = 0x80192264u;
    // 80192264: bl      0x801CFFC8
    {
            ctx->lr = 0x80192268u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192268:
    ctx->pc = 0x80192268u;
    ctx->downcount -= 7;
    // 80192268: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019226C:
    ctx->pc = 0x8019226Cu;
    // 8019226C: stw     r3, 180(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(180);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192270:
    ctx->pc = 0x80192270u;
    // 80192270: addi    r30, r30, -16044
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16044);

label_80192274:
    ctx->pc = 0x80192274u;
    // 80192274: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192278:
    ctx->pc = 0x80192278u;
    // 80192278: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019227C:
    ctx->pc = 0x8019227Cu;
    // 8019227C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192280:
    ctx->pc = 0x80192280u;
    // 80192280: bl      0x801CFFC8
    {
            ctx->lr = 0x80192284u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192284:
    ctx->pc = 0x80192284u;
    ctx->downcount -= 4;
    // 80192284: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192288:
    ctx->pc = 0x80192288u;
    // 80192288: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019228C:
    ctx->pc = 0x8019228Cu;
    // 8019228C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192290:
    ctx->pc = 0x80192290u;
    // 80192290: bl      0x801CFFC8
    {
            ctx->lr = 0x80192294u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192294:
    ctx->pc = 0x80192294u;
    ctx->downcount -= 7;
    // 80192294: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192298:
    ctx->pc = 0x80192298u;
    // 80192298: stw     r3, 192(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(192);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019229C:
    ctx->pc = 0x8019229Cu;
    // 8019229C: addi    r30, r30, -16032
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16032);

label_801922A0:
    ctx->pc = 0x801922A0u;
    // 801922A0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801922A4:
    ctx->pc = 0x801922A4u;
    // 801922A4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801922A8:
    ctx->pc = 0x801922A8u;
    // 801922A8: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801922AC:
    ctx->pc = 0x801922ACu;
    // 801922AC: bl      0x801CFFC8
    {
            ctx->lr = 0x801922B0u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801922B0:
    ctx->pc = 0x801922B0u;
    ctx->downcount -= 4;
    // 801922B0: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801922B4:
    ctx->pc = 0x801922B4u;
    // 801922B4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801922B8:
    ctx->pc = 0x801922B8u;
    // 801922B8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801922BC:
    ctx->pc = 0x801922BCu;
    // 801922BC: bl      0x801CFFC8
    {
            ctx->lr = 0x801922C0u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801922C0:
    ctx->pc = 0x801922C0u;
    ctx->downcount -= 7;
    // 801922C0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801922C4:
    ctx->pc = 0x801922C4u;
    // 801922C4: stw     r3, 196(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(196);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801922C8:
    ctx->pc = 0x801922C8u;
    // 801922C8: addi    r30, r30, -16024
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16024);

label_801922CC:
    ctx->pc = 0x801922CCu;
    // 801922CC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801922D0:
    ctx->pc = 0x801922D0u;
    // 801922D0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801922D4:
    ctx->pc = 0x801922D4u;
    // 801922D4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801922D8:
    ctx->pc = 0x801922D8u;
    // 801922D8: bl      0x801CFFC8
    {
            ctx->lr = 0x801922DCu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801922DC:
    ctx->pc = 0x801922DCu;
    ctx->downcount -= 4;
    // 801922DC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801922E0:
    ctx->pc = 0x801922E0u;
    // 801922E0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801922E4:
    ctx->pc = 0x801922E4u;
    // 801922E4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801922E8:
    ctx->pc = 0x801922E8u;
    // 801922E8: bl      0x801CFFC8
    {
            ctx->lr = 0x801922ECu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801922EC:
    ctx->pc = 0x801922ECu;
    ctx->downcount -= 7;
    // 801922EC: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801922F0:
    ctx->pc = 0x801922F0u;
    // 801922F0: stw     r3, 200(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(200);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801922F4:
    ctx->pc = 0x801922F4u;
    // 801922F4: addi    r30, r30, -16008
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16008);

label_801922F8:
    ctx->pc = 0x801922F8u;
    // 801922F8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801922FC:
    ctx->pc = 0x801922FCu;
    // 801922FC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192300:
    ctx->pc = 0x80192300u;
    // 80192300: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192304:
    ctx->pc = 0x80192304u;
    // 80192304: bl      0x801CFFC8
    {
            ctx->lr = 0x80192308u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192308:
    ctx->pc = 0x80192308u;
    ctx->downcount -= 4;
    // 80192308: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019230C:
    ctx->pc = 0x8019230Cu;
    // 8019230C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192310:
    ctx->pc = 0x80192310u;
    // 80192310: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192314:
    ctx->pc = 0x80192314u;
    // 80192314: bl      0x801CFFC8
    {
            ctx->lr = 0x80192318u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192318:
    ctx->pc = 0x80192318u;
    ctx->downcount -= 9;
    // 80192318: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_8019231C:
    ctx->pc = 0x8019231Cu;
    // 8019231C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192320:
    ctx->pc = 0x80192320u;
    // 80192320: lfs     f29, -15232(r9)
    if (!ppc_fp_available_inline(ctx, 0x80192320u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15232);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[29] = value;
        ctx->ps1[29] = value;
    }

label_80192324:
    ctx->pc = 0x80192324u;
    // 80192324: addi    r30, r30, -15992
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15992);

label_80192328:
    ctx->pc = 0x80192328u;
    // 80192328: stw     r3, 216(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(216);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019232C:
    ctx->pc = 0x8019232Cu;
    // 8019232C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192330:
    ctx->pc = 0x80192330u;
    // 80192330: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192334:
    ctx->pc = 0x80192334u;
    // 80192334: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x80192334u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_80192338:
    ctx->pc = 0x80192338u;
    // 80192338: bl      0x801D009C
    {
            ctx->lr = 0x8019233Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019233C:
    ctx->pc = 0x8019233Cu;
    ctx->downcount -= 3;
    // 8019233C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192340:
    ctx->pc = 0x80192340u;
    // 80192340: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192344:
    ctx->pc = 0x80192344u;
    // 80192344: bl      0x801D009C
    {
            ctx->lr = 0x80192348u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192348:
    ctx->pc = 0x80192348u;
    ctx->downcount -= 7;
    // 80192348: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019234C:
    ctx->pc = 0x8019234Cu;
    // 8019234C: stfs     f1, 64(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019234Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192350:
    ctx->pc = 0x80192350u;
    // 80192350: addi    r30, r30, -15976
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15976);

label_80192354:
    ctx->pc = 0x80192354u;
    // 80192354: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192358:
    ctx->pc = 0x80192358u;
    // 80192358: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019235C:
    ctx->pc = 0x8019235Cu;
    // 8019235C: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x8019235Cu)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_80192360:
    ctx->pc = 0x80192360u;
    // 80192360: bl      0x801D009C
    {
            ctx->lr = 0x80192364u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192364:
    ctx->pc = 0x80192364u;
    ctx->downcount -= 3;
    // 80192364: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192368:
    ctx->pc = 0x80192368u;
    // 80192368: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8019236C:
    ctx->pc = 0x8019236Cu;
    // 8019236C: bl      0x801D009C
    {
            ctx->lr = 0x80192370u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192370:
    ctx->pc = 0x80192370u;
    ctx->downcount -= 7;
    // 80192370: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192374:
    ctx->pc = 0x80192374u;
    // 80192374: stfs     f1, 68(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192374u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192378:
    ctx->pc = 0x80192378u;
    // 80192378: addi    r30, r30, -15964
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15964);

label_8019237C:
    ctx->pc = 0x8019237Cu;
    // 8019237C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192380:
    ctx->pc = 0x80192380u;
    // 80192380: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192384:
    ctx->pc = 0x80192384u;
    // 80192384: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x80192384u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_80192388:
    ctx->pc = 0x80192388u;
    // 80192388: bl      0x801D009C
    {
            ctx->lr = 0x8019238Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019238C:
    ctx->pc = 0x8019238Cu;
    ctx->downcount -= 3;
    // 8019238C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192390:
    ctx->pc = 0x80192390u;
    // 80192390: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192394:
    ctx->pc = 0x80192394u;
    // 80192394: bl      0x801D009C
    {
            ctx->lr = 0x80192398u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192398:
    ctx->pc = 0x80192398u;
    ctx->downcount -= 7;
    // 80192398: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019239C:
    ctx->pc = 0x8019239Cu;
    // 8019239C: stfs     f1, 72(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019239Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801923A0:
    ctx->pc = 0x801923A0u;
    // 801923A0: addi    r30, r30, -15952
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15952);

label_801923A4:
    ctx->pc = 0x801923A4u;
    // 801923A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801923A8:
    ctx->pc = 0x801923A8u;
    // 801923A8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801923AC:
    ctx->pc = 0x801923ACu;
    // 801923AC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801923B0:
    ctx->pc = 0x801923B0u;
    // 801923B0: bl      0x801CFFC8
    {
            ctx->lr = 0x801923B4u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801923B4:
    ctx->pc = 0x801923B4u;
    ctx->downcount -= 4;
    // 801923B4: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801923B8:
    ctx->pc = 0x801923B8u;
    // 801923B8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801923BC:
    ctx->pc = 0x801923BCu;
    // 801923BC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801923C0:
    ctx->pc = 0x801923C0u;
    // 801923C0: bl      0x801CFFC8
    {
            ctx->lr = 0x801923C4u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801923C4:
    ctx->pc = 0x801923C4u;
    ctx->downcount -= 7;
    // 801923C4: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801923C8:
    ctx->pc = 0x801923C8u;
    // 801923C8: stw     r3, 204(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(204);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801923CC:
    ctx->pc = 0x801923CCu;
    // 801923CC: addi    r30, r30, -15944
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15944);

label_801923D0:
    ctx->pc = 0x801923D0u;
    // 801923D0: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801923D4:
    ctx->pc = 0x801923D4u;
    // 801923D4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801923D8:
    ctx->pc = 0x801923D8u;
    // 801923D8: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x801923D8u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_801923DC:
    ctx->pc = 0x801923DCu;
    // 801923DC: bl      0x801D009C
    {
            ctx->lr = 0x801923E0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801923E0:
    ctx->pc = 0x801923E0u;
    ctx->downcount -= 3;
    // 801923E0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801923E4:
    ctx->pc = 0x801923E4u;
    // 801923E4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801923E8:
    ctx->pc = 0x801923E8u;
    // 801923E8: bl      0x801D009C
    {
            ctx->lr = 0x801923ECu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801923EC:
    ctx->pc = 0x801923ECu;
    ctx->downcount -= 16;
    // 801923EC: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_801923F0:
    ctx->pc = 0x801923F0u;
    // 801923F0: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_801923F4:
    ctx->pc = 0x801923F4u;
    // 801923F4: stfs     f1, 76(r31)
    if (!ppc_fp_available_inline(ctx, 0x801923F4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801923F8:
    ctx->pc = 0x801923F8u;
    // 801923F8: stw     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801923FC:
    ctx->pc = 0x801923FCu;
    // 801923FC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192400:
    ctx->pc = 0x80192400u;
    // 80192400: lfd     f31, -15224(r9)
    if (!ppc_fp_available_inline(ctx, 0x80192400u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15224);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80192404:
    ctx->pc = 0x80192404u;
    // 80192404: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192408:
    ctx->pc = 0x80192408u;
    // 80192408: stw     r29, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8019240C:
    ctx->pc = 0x8019240Cu;
    // 8019240C: addi    r30, r30, -15936
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15936);

label_80192410:
    ctx->pc = 0x80192410u;
    // 80192410: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192414:
    ctx->pc = 0x80192414u;
    // 80192414: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192418:
    ctx->pc = 0x80192418u;
    // 80192418: lfd     f28, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192418u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019241C:
    ctx->pc = 0x8019241Cu;
    // 8019241C: fsub   f28, f28, f31
    if (!ppc_fp_available_inline(ctx, 0x8019241Cu)) return;
    ppc_fsub(ctx, 28, 28, 31);

label_80192420:
    ctx->pc = 0x80192420u;
    // 80192420: frsp    f28, f28
    if (!ppc_fp_available_inline(ctx, 0x80192420u)) return;
    ppc_frsp(ctx, 28, 28);

label_80192424:
    ctx->pc = 0x80192424u;
    // 80192424: fmr    f1, f28
    if (!ppc_fp_available_inline(ctx, 0x80192424u)) return;
    ctx->fpr[1] = ctx->fpr[28];

label_80192428:
    ctx->pc = 0x80192428u;
    // 80192428: bl      0x801D009C
    {
            ctx->lr = 0x8019242Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019242C:
    ctx->pc = 0x8019242Cu;
    ctx->downcount -= 13;
    // 8019242C: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8019242Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80192430:
    ctx->pc = 0x80192430u;
    // 80192430: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80192434:
    ctx->pc = 0x80192434u;
    // 80192434: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192434u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80192438:
    ctx->pc = 0x80192438u;
    // 80192438: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019243C:
    ctx->pc = 0x8019243Cu;
    // 8019243C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192440:
    ctx->pc = 0x80192440u;
    // 80192440: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80192444:
    ctx->pc = 0x80192444u;
    // 80192444: xoris   r9, r9, 0x8000
    ctx->gpr[9] = ctx->gpr[9] ^ (0x8000u << 16);

label_80192448:
    ctx->pc = 0x80192448u;
    // 80192448: stw     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019244C:
    ctx->pc = 0x8019244Cu;
    // 8019244C: stw     r29, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80192450:
    ctx->pc = 0x80192450u;
    // 80192450: lfd     f1, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192450u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80192454:
    ctx->pc = 0x80192454u;
    // 80192454: fsub   f1, f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80192454u)) return;
    ppc_fsub(ctx, 1, 1, 31);

label_80192458:
    ctx->pc = 0x80192458u;
    // 80192458: frsp    f1, f1
    if (!ppc_fp_available_inline(ctx, 0x80192458u)) return;
    ppc_frsp(ctx, 1, 1);

label_8019245C:
    ctx->pc = 0x8019245Cu;
    // 8019245C: bl      0x801D009C
    {
            ctx->lr = 0x80192460u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192460:
    ctx->pc = 0x80192460u;
    ctx->downcount -= 10;
    // 80192460: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80192460u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80192464:
    ctx->pc = 0x80192464u;
    // 80192464: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192468:
    ctx->pc = 0x80192468u;
    // 80192468: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192468u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8019246C:
    ctx->pc = 0x8019246Cu;
    // 8019246C: addi    r30, r30, -15924
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15924);

label_80192470:
    ctx->pc = 0x80192470u;
    // 80192470: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192474:
    ctx->pc = 0x80192474u;
    // 80192474: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192478:
    ctx->pc = 0x80192478u;
    // 80192478: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019247C:
    ctx->pc = 0x8019247Cu;
    // 8019247C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192480:
    ctx->pc = 0x80192480u;
    // 80192480: stw     r9, 232(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(232);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80192484:
    ctx->pc = 0x80192484u;
    // 80192484: bl      0x801CFFC8
    {
            ctx->lr = 0x80192488u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192488:
    ctx->pc = 0x80192488u;
    ctx->downcount -= 4;
    // 80192488: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019248C:
    ctx->pc = 0x8019248Cu;
    // 8019248C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192490:
    ctx->pc = 0x80192490u;
    // 80192490: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192494:
    ctx->pc = 0x80192494u;
    // 80192494: bl      0x801CFFC8
    {
            ctx->lr = 0x80192498u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192498:
    ctx->pc = 0x80192498u;
    ctx->downcount -= 7;
    // 80192498: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019249C:
    ctx->pc = 0x8019249Cu;
    // 8019249C: stw     r3, 208(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(208);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801924A0:
    ctx->pc = 0x801924A0u;
    // 801924A0: addi    r30, r30, -15912
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15912);

label_801924A4:
    ctx->pc = 0x801924A4u;
    // 801924A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801924A8:
    ctx->pc = 0x801924A8u;
    // 801924A8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801924AC:
    ctx->pc = 0x801924ACu;
    // 801924AC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801924B0:
    ctx->pc = 0x801924B0u;
    // 801924B0: bl      0x801CFFC8
    {
            ctx->lr = 0x801924B4u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801924B4:
    ctx->pc = 0x801924B4u;
    ctx->downcount -= 4;
    // 801924B4: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801924B8:
    ctx->pc = 0x801924B8u;
    // 801924B8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801924BC:
    ctx->pc = 0x801924BCu;
    // 801924BC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801924C0:
    ctx->pc = 0x801924C0u;
    // 801924C0: bl      0x801CFFC8
    {
            ctx->lr = 0x801924C4u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801924C4:
    ctx->pc = 0x801924C4u;
    ctx->downcount -= 7;
    // 801924C4: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801924C8:
    ctx->pc = 0x801924C8u;
    // 801924C8: stw     r3, 176(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801924CC:
    ctx->pc = 0x801924CCu;
    // 801924CC: addi    r30, r30, -15892
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15892);

label_801924D0:
    ctx->pc = 0x801924D0u;
    // 801924D0: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801924D4:
    ctx->pc = 0x801924D4u;
    // 801924D4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801924D8:
    ctx->pc = 0x801924D8u;
    // 801924D8: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x801924D8u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_801924DC:
    ctx->pc = 0x801924DCu;
    // 801924DC: bl      0x801D009C
    {
            ctx->lr = 0x801924E0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801924E0:
    ctx->pc = 0x801924E0u;
    ctx->downcount -= 3;
    // 801924E0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801924E4:
    ctx->pc = 0x801924E4u;
    // 801924E4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801924E8:
    ctx->pc = 0x801924E8u;
    // 801924E8: bl      0x801D009C
    {
            ctx->lr = 0x801924ECu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801924EC:
    ctx->pc = 0x801924ECu;
    ctx->downcount -= 7;
    // 801924EC: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801924F0:
    ctx->pc = 0x801924F0u;
    // 801924F0: stfs     f1, 80(r31)
    if (!ppc_fp_available_inline(ctx, 0x801924F0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801924F4:
    ctx->pc = 0x801924F4u;
    // 801924F4: addi    r30, r30, -15880
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15880);

label_801924F8:
    ctx->pc = 0x801924F8u;
    // 801924F8: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801924FC:
    ctx->pc = 0x801924FCu;
    // 801924FC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192500:
    ctx->pc = 0x80192500u;
    // 80192500: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x80192500u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_80192504:
    ctx->pc = 0x80192504u;
    // 80192504: bl      0x801D009C
    {
            ctx->lr = 0x80192508u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192508:
    ctx->pc = 0x80192508u;
    ctx->downcount -= 3;
    // 80192508: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019250C:
    ctx->pc = 0x8019250Cu;
    // 8019250C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192510:
    ctx->pc = 0x80192510u;
    // 80192510: bl      0x801D009C
    {
            ctx->lr = 0x80192514u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192514:
    ctx->pc = 0x80192514u;
    ctx->downcount -= 7;
    // 80192514: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192518:
    ctx->pc = 0x80192518u;
    // 80192518: stfs     f1, 84(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192518u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(84);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019251C:
    ctx->pc = 0x8019251Cu;
    // 8019251C: addi    r30, r30, -15864
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15864);

label_80192520:
    ctx->pc = 0x80192520u;
    // 80192520: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192524:
    ctx->pc = 0x80192524u;
    // 80192524: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192528:
    ctx->pc = 0x80192528u;
    // 80192528: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x80192528u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_8019252C:
    ctx->pc = 0x8019252Cu;
    // 8019252C: bl      0x801D009C
    {
            ctx->lr = 0x80192530u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192530:
    ctx->pc = 0x80192530u;
    ctx->downcount -= 3;
    // 80192530: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192534:
    ctx->pc = 0x80192534u;
    // 80192534: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192538:
    ctx->pc = 0x80192538u;
    // 80192538: bl      0x801D009C
    {
            ctx->lr = 0x8019253Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019253C:
    ctx->pc = 0x8019253Cu;
    ctx->downcount -= 7;
    // 8019253C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192540:
    ctx->pc = 0x80192540u;
    // 80192540: stfs     f1, 88(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192540u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192544:
    ctx->pc = 0x80192544u;
    // 80192544: addi    r30, r30, -15852
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15852);

label_80192548:
    ctx->pc = 0x80192548u;
    // 80192548: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8019254C:
    ctx->pc = 0x8019254Cu;
    // 8019254C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192550:
    ctx->pc = 0x80192550u;
    // 80192550: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192554:
    ctx->pc = 0x80192554u;
    // 80192554: bl      0x801CFFC8
    {
            ctx->lr = 0x80192558u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192558:
    ctx->pc = 0x80192558u;
    ctx->downcount -= 4;
    // 80192558: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019255C:
    ctx->pc = 0x8019255Cu;
    // 8019255C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192560:
    ctx->pc = 0x80192560u;
    // 80192560: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192564:
    ctx->pc = 0x80192564u;
    // 80192564: bl      0x801CFFC8
    {
            ctx->lr = 0x80192568u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192568:
    ctx->pc = 0x80192568u;
    ctx->downcount -= 7;
    // 80192568: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019256C:
    ctx->pc = 0x8019256Cu;
    // 8019256C: stw     r3, 212(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(212);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192570:
    ctx->pc = 0x80192570u;
    // 80192570: addi    r30, r30, -15844
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15844);

label_80192574:
    ctx->pc = 0x80192574u;
    // 80192574: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192578:
    ctx->pc = 0x80192578u;
    // 80192578: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019257C:
    ctx->pc = 0x8019257Cu;
    // 8019257C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192580:
    ctx->pc = 0x80192580u;
    // 80192580: bl      0x801CFFC8
    {
            ctx->lr = 0x80192584u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192584:
    ctx->pc = 0x80192584u;
    ctx->downcount -= 4;
    // 80192584: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192588:
    ctx->pc = 0x80192588u;
    // 80192588: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019258C:
    ctx->pc = 0x8019258Cu;
    // 8019258C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192590:
    ctx->pc = 0x80192590u;
    // 80192590: bl      0x801CFFC8
    {
            ctx->lr = 0x80192594u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192594:
    ctx->pc = 0x80192594u;
    ctx->downcount -= 7;
    // 80192594: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192598:
    ctx->pc = 0x80192598u;
    // 80192598: stw     r3, 248(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(248);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019259C:
    ctx->pc = 0x8019259Cu;
    // 8019259C: addi    r30, r30, -15836
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15836);

label_801925A0:
    ctx->pc = 0x801925A0u;
    // 801925A0: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801925A4:
    ctx->pc = 0x801925A4u;
    // 801925A4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801925A8:
    ctx->pc = 0x801925A8u;
    // 801925A8: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x801925A8u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_801925AC:
    ctx->pc = 0x801925ACu;
    // 801925AC: bl      0x801D009C
    {
            ctx->lr = 0x801925B0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801925B0:
    ctx->pc = 0x801925B0u;
    ctx->downcount -= 3;
    // 801925B0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801925B4:
    ctx->pc = 0x801925B4u;
    // 801925B4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801925B8:
    ctx->pc = 0x801925B8u;
    // 801925B8: bl      0x801D009C
    {
            ctx->lr = 0x801925BCu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801925BC:
    ctx->pc = 0x801925BCu;
    ctx->downcount -= 7;
    // 801925BC: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801925C0:
    ctx->pc = 0x801925C0u;
    // 801925C0: stfs     f1, 252(r31)
    if (!ppc_fp_available_inline(ctx, 0x801925C0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(252);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801925C4:
    ctx->pc = 0x801925C4u;
    // 801925C4: addi    r30, r30, -15820
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15820);

label_801925C8:
    ctx->pc = 0x801925C8u;
    // 801925C8: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801925CC:
    ctx->pc = 0x801925CCu;
    // 801925CC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801925D0:
    ctx->pc = 0x801925D0u;
    // 801925D0: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x801925D0u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_801925D4:
    ctx->pc = 0x801925D4u;
    // 801925D4: bl      0x801D009C
    {
            ctx->lr = 0x801925D8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801925D8:
    ctx->pc = 0x801925D8u;
    ctx->downcount -= 3;
    // 801925D8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801925DC:
    ctx->pc = 0x801925DCu;
    // 801925DC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801925E0:
    ctx->pc = 0x801925E0u;
    // 801925E0: bl      0x801D009C
    {
            ctx->lr = 0x801925E4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801925E4:
    ctx->pc = 0x801925E4u;
    ctx->downcount -= 7;
    // 801925E4: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801925E8:
    ctx->pc = 0x801925E8u;
    // 801925E8: stfs     f1, 264(r31)
    if (!ppc_fp_available_inline(ctx, 0x801925E8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(264);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801925EC:
    ctx->pc = 0x801925ECu;
    // 801925EC: addi    r30, r30, -15804
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15804);

label_801925F0:
    ctx->pc = 0x801925F0u;
    // 801925F0: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801925F4:
    ctx->pc = 0x801925F4u;
    // 801925F4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801925F8:
    ctx->pc = 0x801925F8u;
    // 801925F8: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x801925F8u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_801925FC:
    ctx->pc = 0x801925FCu;
    // 801925FC: bl      0x801D009C
    {
            ctx->lr = 0x80192600u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192600:
    ctx->pc = 0x80192600u;
    ctx->downcount -= 3;
    // 80192600: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192604:
    ctx->pc = 0x80192604u;
    // 80192604: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192608:
    ctx->pc = 0x80192608u;
    // 80192608: bl      0x801D009C
    {
            ctx->lr = 0x8019260Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019260C:
    ctx->pc = 0x8019260Cu;
    ctx->downcount -= 7;
    // 8019260C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192610:
    ctx->pc = 0x80192610u;
    // 80192610: stfs     f1, 256(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192610u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(256);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192614:
    ctx->pc = 0x80192614u;
    // 80192614: addi    r30, r30, -15784
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15784);

label_80192618:
    ctx->pc = 0x80192618u;
    // 80192618: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8019261C:
    ctx->pc = 0x8019261Cu;
    // 8019261C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192620:
    ctx->pc = 0x80192620u;
    // 80192620: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x80192620u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_80192624:
    ctx->pc = 0x80192624u;
    // 80192624: bl      0x801D009C
    {
            ctx->lr = 0x80192628u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192628:
    ctx->pc = 0x80192628u;
    ctx->downcount -= 3;
    // 80192628: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019262C:
    ctx->pc = 0x8019262Cu;
    // 8019262C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192630:
    ctx->pc = 0x80192630u;
    // 80192630: bl      0x801D009C
    {
            ctx->lr = 0x80192634u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192634:
    ctx->pc = 0x80192634u;
    ctx->downcount -= 7;
    // 80192634: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192638:
    ctx->pc = 0x80192638u;
    // 80192638: stfs     f1, 260(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192638u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(260);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019263C:
    ctx->pc = 0x8019263Cu;
    // 8019263C: addi    r30, r30, -15764
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15764);

label_80192640:
    ctx->pc = 0x80192640u;
    // 80192640: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192644:
    ctx->pc = 0x80192644u;
    // 80192644: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192648:
    ctx->pc = 0x80192648u;
    // 80192648: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x80192648u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_8019264C:
    ctx->pc = 0x8019264Cu;
    // 8019264C: bl      0x801D009C
    {
            ctx->lr = 0x80192650u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192650:
    ctx->pc = 0x80192650u;
    ctx->downcount -= 3;
    // 80192650: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192654:
    ctx->pc = 0x80192654u;
    // 80192654: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192658:
    ctx->pc = 0x80192658u;
    // 80192658: bl      0x801D009C
    {
            ctx->lr = 0x8019265Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019265C:
    ctx->pc = 0x8019265Cu;
    ctx->downcount -= 8;
    // 8019265C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192660:
    ctx->pc = 0x80192660u;
    // 80192660: stfs     f1, 92(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192660u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192664:
    ctx->pc = 0x80192664u;
    // 80192664: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192668:
    ctx->pc = 0x80192668u;
    // 80192668: lfs     f1, -15216(r9)
    if (!ppc_fp_available_inline(ctx, 0x80192668u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8019266C:
    ctx->pc = 0x8019266Cu;
    // 8019266C: addi    r30, r30, -15752
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15752);

label_80192670:
    ctx->pc = 0x80192670u;
    // 80192670: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192674:
    ctx->pc = 0x80192674u;
    // 80192674: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192678:
    ctx->pc = 0x80192678u;
    // 80192678: bl      0x801D009C
    {
            ctx->lr = 0x8019267Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019267C:
    ctx->pc = 0x8019267Cu;
    ctx->downcount -= 3;
    // 8019267C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192680:
    ctx->pc = 0x80192680u;
    // 80192680: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192684:
    ctx->pc = 0x80192684u;
    // 80192684: bl      0x801D009C
    {
            ctx->lr = 0x80192688u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192688:
    ctx->pc = 0x80192688u;
    ctx->downcount -= 7;
    // 80192688: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019268C:
    ctx->pc = 0x8019268Cu;
    // 8019268C: stfs     f1, 96(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019268Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192690:
    ctx->pc = 0x80192690u;
    // 80192690: addi    r30, r30, -15740
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15740);

label_80192694:
    ctx->pc = 0x80192694u;
    // 80192694: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192698:
    ctx->pc = 0x80192698u;
    // 80192698: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019269C:
    ctx->pc = 0x8019269Cu;
    // 8019269C: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x8019269Cu)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_801926A0:
    ctx->pc = 0x801926A0u;
    // 801926A0: bl      0x801D009C
    {
            ctx->lr = 0x801926A4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801926A4:
    ctx->pc = 0x801926A4u;
    ctx->downcount -= 13;
    // 801926A4: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801926A4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801926A8:
    ctx->pc = 0x801926A8u;
    // 801926A8: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801926AC:
    ctx->pc = 0x801926ACu;
    // 801926AC: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x801926ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801926B0:
    ctx->pc = 0x801926B0u;
    // 801926B0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801926B4:
    ctx->pc = 0x801926B4u;
    // 801926B4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801926B8:
    ctx->pc = 0x801926B8u;
    // 801926B8: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801926BC:
    ctx->pc = 0x801926BCu;
    // 801926BC: xoris   r9, r9, 0x8000
    ctx->gpr[9] = ctx->gpr[9] ^ (0x8000u << 16);

label_801926C0:
    ctx->pc = 0x801926C0u;
    // 801926C0: stw     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801926C4:
    ctx->pc = 0x801926C4u;
    // 801926C4: stw     r29, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801926C8:
    ctx->pc = 0x801926C8u;
    // 801926C8: lfd     f1, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x801926C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801926CC:
    ctx->pc = 0x801926CCu;
    // 801926CC: fsub   f1, f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801926CCu)) return;
    ppc_fsub(ctx, 1, 1, 31);

label_801926D0:
    ctx->pc = 0x801926D0u;
    // 801926D0: frsp    f1, f1
    if (!ppc_fp_available_inline(ctx, 0x801926D0u)) return;
    ppc_frsp(ctx, 1, 1);

label_801926D4:
    ctx->pc = 0x801926D4u;
    // 801926D4: bl      0x801D009C
    {
            ctx->lr = 0x801926D8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801926D8:
    ctx->pc = 0x801926D8u;
    ctx->downcount -= 10;
    // 801926D8: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801926D8u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801926DC:
    ctx->pc = 0x801926DCu;
    // 801926DC: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801926E0:
    ctx->pc = 0x801926E0u;
    // 801926E0: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x801926E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801926E4:
    ctx->pc = 0x801926E4u;
    // 801926E4: addi    r30, r30, -15724
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15724);

label_801926E8:
    ctx->pc = 0x801926E8u;
    // 801926E8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801926EC:
    ctx->pc = 0x801926ECu;
    // 801926EC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801926F0:
    ctx->pc = 0x801926F0u;
    // 801926F0: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801926F4:
    ctx->pc = 0x801926F4u;
    // 801926F4: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x801926F4u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_801926F8:
    ctx->pc = 0x801926F8u;
    // 801926F8: stw     r9, 112(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801926FC:
    ctx->pc = 0x801926FCu;
    // 801926FC: bl      0x801D009C
    {
            ctx->lr = 0x80192700u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192700:
    ctx->pc = 0x80192700u;
    ctx->downcount -= 13;
    // 80192700: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80192700u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80192704:
    ctx->pc = 0x80192704u;
    // 80192704: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80192708:
    ctx->pc = 0x80192708u;
    // 80192708: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192708u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8019270C:
    ctx->pc = 0x8019270Cu;
    // 8019270C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192710:
    ctx->pc = 0x80192710u;
    // 80192710: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192714:
    ctx->pc = 0x80192714u;
    // 80192714: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80192718:
    ctx->pc = 0x80192718u;
    // 80192718: xoris   r9, r9, 0x8000
    ctx->gpr[9] = ctx->gpr[9] ^ (0x8000u << 16);

label_8019271C:
    ctx->pc = 0x8019271Cu;
    // 8019271C: stw     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80192720:
    ctx->pc = 0x80192720u;
    // 80192720: stw     r29, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80192724:
    ctx->pc = 0x80192724u;
    // 80192724: lfd     f1, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192724u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80192728:
    ctx->pc = 0x80192728u;
    // 80192728: fsub   f1, f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80192728u)) return;
    ppc_fsub(ctx, 1, 1, 31);

label_8019272C:
    ctx->pc = 0x8019272Cu;
    // 8019272C: frsp    f1, f1
    if (!ppc_fp_available_inline(ctx, 0x8019272Cu)) return;
    ppc_frsp(ctx, 1, 1);

label_80192730:
    ctx->pc = 0x80192730u;
    // 80192730: bl      0x801D009C
    {
            ctx->lr = 0x80192734u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192734:
    ctx->pc = 0x80192734u;
    ctx->downcount -= 10;
    // 80192734: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80192734u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80192738:
    ctx->pc = 0x80192738u;
    // 80192738: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019273C:
    ctx->pc = 0x8019273Cu;
    // 8019273C: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x8019273Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80192740:
    ctx->pc = 0x80192740u;
    // 80192740: addi    r30, r30, -15708
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15708);

label_80192744:
    ctx->pc = 0x80192744u;
    // 80192744: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192748:
    ctx->pc = 0x80192748u;
    // 80192748: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8019274C:
    ctx->pc = 0x8019274Cu;
    // 8019274C: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80192750:
    ctx->pc = 0x80192750u;
    // 80192750: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x80192750u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_80192754:
    ctx->pc = 0x80192754u;
    // 80192754: stw     r9, 236(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(236);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80192758:
    ctx->pc = 0x80192758u;
    // 80192758: bl      0x801D009C
    {
            ctx->lr = 0x8019275Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019275C:
    ctx->pc = 0x8019275Cu;
    ctx->downcount -= 13;
    // 8019275C: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8019275Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80192760:
    ctx->pc = 0x80192760u;
    // 80192760: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80192764:
    ctx->pc = 0x80192764u;
    // 80192764: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192764u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80192768:
    ctx->pc = 0x80192768u;
    // 80192768: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019276C:
    ctx->pc = 0x8019276Cu;
    // 8019276C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192770:
    ctx->pc = 0x80192770u;
    // 80192770: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80192774:
    ctx->pc = 0x80192774u;
    // 80192774: xoris   r9, r9, 0x8000
    ctx->gpr[9] = ctx->gpr[9] ^ (0x8000u << 16);

label_80192778:
    ctx->pc = 0x80192778u;
    // 80192778: stw     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019277C:
    ctx->pc = 0x8019277Cu;
    // 8019277C: stw     r29, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80192780:
    ctx->pc = 0x80192780u;
    // 80192780: lfd     f1, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192780u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80192784:
    ctx->pc = 0x80192784u;
    // 80192784: fsub   f1, f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80192784u)) return;
    ppc_fsub(ctx, 1, 1, 31);

label_80192788:
    ctx->pc = 0x80192788u;
    // 80192788: frsp    f1, f1
    if (!ppc_fp_available_inline(ctx, 0x80192788u)) return;
    ppc_frsp(ctx, 1, 1);

label_8019278C:
    ctx->pc = 0x8019278Cu;
    // 8019278C: bl      0x801D009C
    {
            ctx->lr = 0x80192790u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192790:
    ctx->pc = 0x80192790u;
    ctx->downcount -= 10;
    // 80192790: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80192790u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80192794:
    ctx->pc = 0x80192794u;
    // 80192794: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192798:
    ctx->pc = 0x80192798u;
    // 80192798: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x80192798u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8019279C:
    ctx->pc = 0x8019279Cu;
    // 8019279C: addi    r30, r30, -15688
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15688);

label_801927A0:
    ctx->pc = 0x801927A0u;
    // 801927A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801927A4:
    ctx->pc = 0x801927A4u;
    // 801927A4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801927A8:
    ctx->pc = 0x801927A8u;
    // 801927A8: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801927AC:
    ctx->pc = 0x801927ACu;
    // 801927AC: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x801927ACu)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_801927B0:
    ctx->pc = 0x801927B0u;
    // 801927B0: stw     r9, 240(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(240);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801927B4:
    ctx->pc = 0x801927B4u;
    // 801927B4: bl      0x801D009C
    {
            ctx->lr = 0x801927B8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801927B8:
    ctx->pc = 0x801927B8u;
    ctx->downcount -= 13;
    // 801927B8: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801927B8u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801927BC:
    ctx->pc = 0x801927BCu;
    // 801927BC: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_801927C0:
    ctx->pc = 0x801927C0u;
    // 801927C0: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x801927C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801927C4:
    ctx->pc = 0x801927C4u;
    // 801927C4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801927C8:
    ctx->pc = 0x801927C8u;
    // 801927C8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801927CC:
    ctx->pc = 0x801927CCu;
    // 801927CC: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801927D0:
    ctx->pc = 0x801927D0u;
    // 801927D0: xoris   r9, r9, 0x8000
    ctx->gpr[9] = ctx->gpr[9] ^ (0x8000u << 16);

label_801927D4:
    ctx->pc = 0x801927D4u;
    // 801927D4: stw     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801927D8:
    ctx->pc = 0x801927D8u;
    // 801927D8: stw     r29, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801927DC:
    ctx->pc = 0x801927DCu;
    // 801927DC: lfd     f1, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x801927DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801927E0:
    ctx->pc = 0x801927E0u;
    // 801927E0: fsub   f1, f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801927E0u)) return;
    ppc_fsub(ctx, 1, 1, 31);

label_801927E4:
    ctx->pc = 0x801927E4u;
    // 801927E4: frsp    f1, f1
    if (!ppc_fp_available_inline(ctx, 0x801927E4u)) return;
    ppc_frsp(ctx, 1, 1);

label_801927E8:
    ctx->pc = 0x801927E8u;
    // 801927E8: bl      0x801D009C
    {
            ctx->lr = 0x801927ECu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801927EC:
    ctx->pc = 0x801927ECu;
    ctx->downcount -= 10;
    // 801927EC: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x801927ECu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801927F0:
    ctx->pc = 0x801927F0u;
    // 801927F0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801927F4:
    ctx->pc = 0x801927F4u;
    // 801927F4: stfd     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x801927F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801927F8:
    ctx->pc = 0x801927F8u;
    // 801927F8: addi    r30, r30, -15672
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15672);

label_801927FC:
    ctx->pc = 0x801927FCu;
    // 801927FC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192800:
    ctx->pc = 0x80192800u;
    // 80192800: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192804:
    ctx->pc = 0x80192804u;
    // 80192804: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80192808:
    ctx->pc = 0x80192808u;
    // 80192808: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x80192808u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_8019280C:
    ctx->pc = 0x8019280Cu;
    // 8019280C: stw     r9, 244(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(244);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80192810:
    ctx->pc = 0x80192810u;
    // 80192810: bl      0x801D009C
    {
            ctx->lr = 0x80192814u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192814:
    ctx->pc = 0x80192814u;
    ctx->downcount -= 3;
    // 80192814: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192818:
    ctx->pc = 0x80192818u;
    // 80192818: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8019281C:
    ctx->pc = 0x8019281Cu;
    // 8019281C: bl      0x801D009C
    {
            ctx->lr = 0x80192820u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192820:
    ctx->pc = 0x80192820u;
    ctx->downcount -= 8;
    // 80192820: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192824:
    ctx->pc = 0x80192824u;
    // 80192824: stfs     f1, 268(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192824u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(268);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192828:
    ctx->pc = 0x80192828u;
    // 80192828: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019282C:
    ctx->pc = 0x8019282Cu;
    // 8019282C: lfs     f1, -15212(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019282Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15212);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80192830:
    ctx->pc = 0x80192830u;
    // 80192830: addi    r30, r30, -15660
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15660);

label_80192834:
    ctx->pc = 0x80192834u;
    // 80192834: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192838:
    ctx->pc = 0x80192838u;
    // 80192838: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019283C:
    ctx->pc = 0x8019283Cu;
    // 8019283C: bl      0x801D009C
    {
            ctx->lr = 0x80192840u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192840:
    ctx->pc = 0x80192840u;
    ctx->downcount -= 3;
    // 80192840: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192844:
    ctx->pc = 0x80192844u;
    // 80192844: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192848:
    ctx->pc = 0x80192848u;
    // 80192848: bl      0x801D009C
    {
            ctx->lr = 0x8019284Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019284C:
    ctx->pc = 0x8019284Cu;
    ctx->downcount -= 9;
    // 8019284C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192850:
    ctx->pc = 0x80192850u;
    // 80192850: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192854:
    ctx->pc = 0x80192854u;
    // 80192854: lfs     f31, -15208(r9)
    if (!ppc_fp_available_inline(ctx, 0x80192854u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15208);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80192858:
    ctx->pc = 0x80192858u;
    // 80192858: addi    r30, r30, -15644
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15644);

label_8019285C:
    ctx->pc = 0x8019285Cu;
    // 8019285C: stfs     f1, 108(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019285Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192860:
    ctx->pc = 0x80192860u;
    // 80192860: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192864:
    ctx->pc = 0x80192864u;
    // 80192864: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192868:
    ctx->pc = 0x80192868u;
    // 80192868: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80192868u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8019286C:
    ctx->pc = 0x8019286Cu;
    // 8019286C: bl      0x801D009C
    {
            ctx->lr = 0x80192870u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192870:
    ctx->pc = 0x80192870u;
    ctx->downcount -= 3;
    // 80192870: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192874:
    ctx->pc = 0x80192874u;
    // 80192874: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192878:
    ctx->pc = 0x80192878u;
    // 80192878: bl      0x801D009C
    {
            ctx->lr = 0x8019287Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019287C:
    ctx->pc = 0x8019287Cu;
    ctx->downcount -= 7;
    // 8019287C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192880:
    ctx->pc = 0x80192880u;
    // 80192880: stfs     f1, 272(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192880u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(272);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192884:
    ctx->pc = 0x80192884u;
    // 80192884: addi    r30, r30, -15624
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15624);

label_80192888:
    ctx->pc = 0x80192888u;
    // 80192888: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80192888u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8019288C:
    ctx->pc = 0x8019288Cu;
    // 8019288C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192890:
    ctx->pc = 0x80192890u;
    // 80192890: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192894:
    ctx->pc = 0x80192894u;
    // 80192894: bl      0x801D009C
    {
            ctx->lr = 0x80192898u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192898:
    ctx->pc = 0x80192898u;
    ctx->downcount -= 3;
    // 80192898: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019289C:
    ctx->pc = 0x8019289Cu;
    // 8019289C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801928A0:
    ctx->pc = 0x801928A0u;
    // 801928A0: bl      0x801D009C
    {
            ctx->lr = 0x801928A4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801928A4:
    ctx->pc = 0x801928A4u;
    ctx->downcount -= 7;
    // 801928A4: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801928A8:
    ctx->pc = 0x801928A8u;
    // 801928A8: stfs     f1, 276(r31)
    if (!ppc_fp_available_inline(ctx, 0x801928A8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(276);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801928AC:
    ctx->pc = 0x801928ACu;
    // 801928AC: addi    r30, r30, -15600
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15600);

label_801928B0:
    ctx->pc = 0x801928B0u;
    // 801928B0: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801928B4:
    ctx->pc = 0x801928B4u;
    // 801928B4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801928B8:
    ctx->pc = 0x801928B8u;
    // 801928B8: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801928BC:
    ctx->pc = 0x801928BCu;
    // 801928BC: bl      0x801CFFC8
    {
            ctx->lr = 0x801928C0u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801928C0:
    ctx->pc = 0x801928C0u;
    ctx->downcount -= 4;
    // 801928C0: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801928C4:
    ctx->pc = 0x801928C4u;
    // 801928C4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801928C8:
    ctx->pc = 0x801928C8u;
    // 801928C8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801928CC:
    ctx->pc = 0x801928CCu;
    // 801928CC: bl      0x801CFFC8
    {
            ctx->lr = 0x801928D0u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801928D0:
    ctx->pc = 0x801928D0u;
    ctx->downcount -= 7;
    // 801928D0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801928D4:
    ctx->pc = 0x801928D4u;
    // 801928D4: stw     r3, 280(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(280);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801928D8:
    ctx->pc = 0x801928D8u;
    // 801928D8: addi    r30, r30, -15584
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15584);

label_801928DC:
    ctx->pc = 0x801928DCu;
    // 801928DC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801928E0:
    ctx->pc = 0x801928E0u;
    // 801928E0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801928E4:
    ctx->pc = 0x801928E4u;
    // 801928E4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801928E8:
    ctx->pc = 0x801928E8u;
    // 801928E8: bl      0x801CFFC8
    {
            ctx->lr = 0x801928ECu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801928EC:
    ctx->pc = 0x801928ECu;
    ctx->downcount -= 4;
    // 801928EC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801928F0:
    ctx->pc = 0x801928F0u;
    // 801928F0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801928F4:
    ctx->pc = 0x801928F4u;
    // 801928F4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801928F8:
    ctx->pc = 0x801928F8u;
    // 801928F8: bl      0x801CFFC8
    {
            ctx->lr = 0x801928FCu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_801928FC:
    ctx->pc = 0x801928FCu;
    ctx->downcount -= 9;
    // 801928FC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192900:
    ctx->pc = 0x80192900u;
    // 80192900: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192904:
    ctx->pc = 0x80192904u;
    // 80192904: lfs     f31, -15204(r9)
    if (!ppc_fp_available_inline(ctx, 0x80192904u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15204);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80192908:
    ctx->pc = 0x80192908u;
    // 80192908: addi    r30, r30, -15568
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15568);

label_8019290C:
    ctx->pc = 0x8019290Cu;
    // 8019290C: stw     r3, 284(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(284);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192910:
    ctx->pc = 0x80192910u;
    // 80192910: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192914:
    ctx->pc = 0x80192914u;
    // 80192914: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192918:
    ctx->pc = 0x80192918u;
    // 80192918: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80192918u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8019291C:
    ctx->pc = 0x8019291Cu;
    // 8019291C: bl      0x801D009C
    {
            ctx->lr = 0x80192920u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192920:
    ctx->pc = 0x80192920u;
    ctx->downcount -= 3;
    // 80192920: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192924:
    ctx->pc = 0x80192924u;
    // 80192924: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192928:
    ctx->pc = 0x80192928u;
    // 80192928: bl      0x801D009C
    {
            ctx->lr = 0x8019292Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019292C:
    ctx->pc = 0x8019292Cu;
    ctx->downcount -= 7;
    // 8019292C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192930:
    ctx->pc = 0x80192930u;
    // 80192930: stfs     f1, 100(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192930u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(100);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192934:
    ctx->pc = 0x80192934u;
    // 80192934: addi    r30, r30, -15556
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15556);

label_80192938:
    ctx->pc = 0x80192938u;
    // 80192938: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8019293C:
    ctx->pc = 0x8019293Cu;
    // 8019293C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192940:
    ctx->pc = 0x80192940u;
    // 80192940: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80192940u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80192944:
    ctx->pc = 0x80192944u;
    // 80192944: bl      0x801D009C
    {
            ctx->lr = 0x80192948u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192948:
    ctx->pc = 0x80192948u;
    ctx->downcount -= 3;
    // 80192948: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019294C:
    ctx->pc = 0x8019294Cu;
    // 8019294C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192950:
    ctx->pc = 0x80192950u;
    // 80192950: bl      0x801D009C
    {
            ctx->lr = 0x80192954u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192954:
    ctx->pc = 0x80192954u;
    ctx->downcount -= 8;
    // 80192954: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192958:
    ctx->pc = 0x80192958u;
    // 80192958: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_8019295C:
    ctx->pc = 0x8019295Cu;
    // 8019295C: addi    r30, r30, -15540
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15540);

label_80192960:
    ctx->pc = 0x80192960u;
    // 80192960: stfs     f1, 104(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192960u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(104);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192964:
    ctx->pc = 0x80192964u;
    // 80192964: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192968:
    ctx->pc = 0x80192968u;
    // 80192968: addi    r5, r5, -16528
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-16528);

label_8019296C:
    ctx->pc = 0x8019296Cu;
    // 8019296C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192970:
    ctx->pc = 0x80192970u;
    // 80192970: bl      0x801D012C
    {
            ctx->lr = 0x80192974u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192974:
    ctx->pc = 0x80192974u;
    ctx->downcount -= 4;
    // 80192974: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192978:
    ctx->pc = 0x80192978u;
    // 80192978: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019297C:
    ctx->pc = 0x8019297Cu;
    // 8019297C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192980:
    ctx->pc = 0x80192980u;
    // 80192980: bl      0x801D012C
    {
            ctx->lr = 0x80192984u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192984:
    ctx->pc = 0x80192984u;
    ctx->downcount -= 3;
    // 80192984: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192988:
    ctx->pc = 0x80192988u;
    // 80192988: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8019298C:
    ctx->pc = 0x8019298Cu;
    // 8019298C: bl      0x8019862C
    {
            ctx->lr = 0x80192990u;
            ctx->pc = 0x8019862Cu;
            return;
    }

label_80192990:
    ctx->pc = 0x80192990u;
    ctx->downcount -= 7;
    // 80192990: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192994:
    ctx->pc = 0x80192994u;
    // 80192994: stw     r3, 288(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(288);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192998:
    ctx->pc = 0x80192998u;
    // 80192998: addi    r30, r30, -15528
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15528);

label_8019299C:
    ctx->pc = 0x8019299Cu;
    // 8019299C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801929A0:
    ctx->pc = 0x801929A0u;
    // 801929A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801929A4:
    ctx->pc = 0x801929A4u;
    // 801929A4: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x801929A4u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_801929A8:
    ctx->pc = 0x801929A8u;
    // 801929A8: bl      0x801D009C
    {
            ctx->lr = 0x801929ACu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801929AC:
    ctx->pc = 0x801929ACu;
    ctx->downcount -= 3;
    // 801929AC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801929B0:
    ctx->pc = 0x801929B0u;
    // 801929B0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801929B4:
    ctx->pc = 0x801929B4u;
    // 801929B4: bl      0x801D009C
    {
            ctx->lr = 0x801929B8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801929B8:
    ctx->pc = 0x801929B8u;
    ctx->downcount -= 7;
    // 801929B8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801929BC:
    ctx->pc = 0x801929BCu;
    // 801929BC: stfs     f1, 292(r31)
    if (!ppc_fp_available_inline(ctx, 0x801929BCu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(292);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801929C0:
    ctx->pc = 0x801929C0u;
    // 801929C0: addi    r30, r30, -16452
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16452);

label_801929C4:
    ctx->pc = 0x801929C4u;
    // 801929C4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801929C8:
    ctx->pc = 0x801929C8u;
    // 801929C8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801929CC:
    ctx->pc = 0x801929CCu;
    // 801929CC: fmr    f1, f28
    if (!ppc_fp_available_inline(ctx, 0x801929CCu)) return;
    ctx->fpr[1] = ctx->fpr[28];

label_801929D0:
    ctx->pc = 0x801929D0u;
    // 801929D0: bl      0x801D009C
    {
            ctx->lr = 0x801929D4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801929D4:
    ctx->pc = 0x801929D4u;
    ctx->downcount -= 3;
    // 801929D4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801929D8:
    ctx->pc = 0x801929D8u;
    // 801929D8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801929DC:
    ctx->pc = 0x801929DCu;
    // 801929DC: bl      0x801D009C
    {
            ctx->lr = 0x801929E0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801929E0:
    ctx->pc = 0x801929E0u;
    ctx->downcount -= 8;
    // 801929E0: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_801929E4:
    ctx->pc = 0x801929E4u;
    // 801929E4: stfs     f1, 324(r31)
    if (!ppc_fp_available_inline(ctx, 0x801929E4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801929E8:
    ctx->pc = 0x801929E8u;
    // 801929E8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801929EC:
    ctx->pc = 0x801929ECu;
    // 801929EC: lfs     f1, -15200(r9)
    if (!ppc_fp_available_inline(ctx, 0x801929ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15200);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801929F0:
    ctx->pc = 0x801929F0u;
    // 801929F0: addi    r30, r30, -16440
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16440);

label_801929F4:
    ctx->pc = 0x801929F4u;
    // 801929F4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801929F8:
    ctx->pc = 0x801929F8u;
    // 801929F8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801929FC:
    ctx->pc = 0x801929FCu;
    // 801929FC: bl      0x801D009C
    {
            ctx->lr = 0x80192A00u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192A00:
    ctx->pc = 0x80192A00u;
    ctx->downcount -= 3;
    // 80192A00: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192A04:
    ctx->pc = 0x80192A04u;
    // 80192A04: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192A08:
    ctx->pc = 0x80192A08u;
    // 80192A08: bl      0x801D009C
    {
            ctx->lr = 0x80192A0Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192A0C:
    ctx->pc = 0x80192A0Cu;
    ctx->downcount -= 7;
    // 80192A0C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192A10:
    ctx->pc = 0x80192A10u;
    // 80192A10: stfs     f1, 328(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192A10u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(328);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192A14:
    ctx->pc = 0x80192A14u;
    // 80192A14: addi    r30, r30, -16428
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16428);

label_80192A18:
    ctx->pc = 0x80192A18u;
    // 80192A18: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192A1C:
    ctx->pc = 0x80192A1Cu;
    // 80192A1C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192A20:
    ctx->pc = 0x80192A20u;
    // 80192A20: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192A24:
    ctx->pc = 0x80192A24u;
    // 80192A24: bl      0x801CFFC8
    {
            ctx->lr = 0x80192A28u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192A28:
    ctx->pc = 0x80192A28u;
    ctx->downcount -= 4;
    // 80192A28: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192A2C:
    ctx->pc = 0x80192A2Cu;
    // 80192A2C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192A30:
    ctx->pc = 0x80192A30u;
    // 80192A30: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192A34:
    ctx->pc = 0x80192A34u;
    // 80192A34: bl      0x801CFFC8
    {
            ctx->lr = 0x80192A38u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192A38:
    ctx->pc = 0x80192A38u;
    ctx->downcount -= 8;
    // 80192A38: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192A3C:
    ctx->pc = 0x80192A3Cu;
    // 80192A3C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192A40:
    ctx->pc = 0x80192A40u;
    // 80192A40: lfs     f1, -15196(r9)
    if (!ppc_fp_available_inline(ctx, 0x80192A40u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15196);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80192A44:
    ctx->pc = 0x80192A44u;
    // 80192A44: addi    r30, r30, -16404
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16404);

label_80192A48:
    ctx->pc = 0x80192A48u;
    // 80192A48: stw     r3, 332(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(332);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192A4C:
    ctx->pc = 0x80192A4Cu;
    // 80192A4C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192A50:
    ctx->pc = 0x80192A50u;
    // 80192A50: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192A54:
    ctx->pc = 0x80192A54u;
    // 80192A54: bl      0x801D009C
    {
            ctx->lr = 0x80192A58u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192A58:
    ctx->pc = 0x80192A58u;
    ctx->downcount -= 3;
    // 80192A58: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192A5C:
    ctx->pc = 0x80192A5Cu;
    // 80192A5C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192A60:
    ctx->pc = 0x80192A60u;
    // 80192A60: bl      0x801D009C
    {
            ctx->lr = 0x80192A64u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192A64:
    ctx->pc = 0x80192A64u;
    ctx->downcount -= 7;
    // 80192A64: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192A68:
    ctx->pc = 0x80192A68u;
    // 80192A68: stfs     f1, 336(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192A68u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(336);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192A6C:
    ctx->pc = 0x80192A6Cu;
    // 80192A6C: addi    r30, r30, -16388
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16388);

label_80192A70:
    ctx->pc = 0x80192A70u;
    // 80192A70: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80192A74:
    ctx->pc = 0x80192A74u;
    // 80192A74: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192A78:
    ctx->pc = 0x80192A78u;
    // 80192A78: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192A7C:
    ctx->pc = 0x80192A7Cu;
    // 80192A7C: bl      0x801CFFC8
    {
            ctx->lr = 0x80192A80u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192A80:
    ctx->pc = 0x80192A80u;
    ctx->downcount -= 4;
    // 80192A80: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192A84:
    ctx->pc = 0x80192A84u;
    // 80192A84: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192A88:
    ctx->pc = 0x80192A88u;
    // 80192A88: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192A8C:
    ctx->pc = 0x80192A8Cu;
    // 80192A8C: bl      0x801CFFC8
    {
            ctx->lr = 0x80192A90u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192A90:
    ctx->pc = 0x80192A90u;
    ctx->downcount -= 7;
    // 80192A90: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192A94:
    ctx->pc = 0x80192A94u;
    // 80192A94: stw     r3, 340(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(340);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192A98:
    ctx->pc = 0x80192A98u;
    // 80192A98: addi    r30, r30, -15512
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15512);

label_80192A9C:
    ctx->pc = 0x80192A9Cu;
    // 80192A9C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192AA0:
    ctx->pc = 0x80192AA0u;
    // 80192AA0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192AA4:
    ctx->pc = 0x80192AA4u;
    // 80192AA4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192AA8:
    ctx->pc = 0x80192AA8u;
    // 80192AA8: bl      0x801CFFC8
    {
            ctx->lr = 0x80192AACu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192AAC:
    ctx->pc = 0x80192AACu;
    ctx->downcount -= 4;
    // 80192AAC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192AB0:
    ctx->pc = 0x80192AB0u;
    // 80192AB0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192AB4:
    ctx->pc = 0x80192AB4u;
    // 80192AB4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192AB8:
    ctx->pc = 0x80192AB8u;
    // 80192AB8: bl      0x801CFFC8
    {
            ctx->lr = 0x80192ABCu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192ABC:
    ctx->pc = 0x80192ABCu;
    ctx->downcount -= 8;
    // 80192ABC: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192AC0:
    ctx->pc = 0x80192AC0u;
    // 80192AC0: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192AC4:
    ctx->pc = 0x80192AC4u;
    // 80192AC4: lfs     f1, -15192(r9)
    if (!ppc_fp_available_inline(ctx, 0x80192AC4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15192);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80192AC8:
    ctx->pc = 0x80192AC8u;
    // 80192AC8: addi    r30, r30, -16372
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16372);

label_80192ACC:
    ctx->pc = 0x80192ACCu;
    // 80192ACC: stw     r3, 296(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(296);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192AD0:
    ctx->pc = 0x80192AD0u;
    // 80192AD0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192AD4:
    ctx->pc = 0x80192AD4u;
    // 80192AD4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192AD8:
    ctx->pc = 0x80192AD8u;
    // 80192AD8: bl      0x801D009C
    {
            ctx->lr = 0x80192ADCu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192ADC:
    ctx->pc = 0x80192ADCu;
    ctx->downcount -= 3;
    // 80192ADC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192AE0:
    ctx->pc = 0x80192AE0u;
    // 80192AE0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192AE4:
    ctx->pc = 0x80192AE4u;
    // 80192AE4: bl      0x801D009C
    {
            ctx->lr = 0x80192AE8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192AE8:
    ctx->pc = 0x80192AE8u;
    ctx->downcount -= 7;
    // 80192AE8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192AEC:
    ctx->pc = 0x80192AECu;
    // 80192AEC: stfs     f1, 300(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192AECu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(300);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192AF0:
    ctx->pc = 0x80192AF0u;
    // 80192AF0: addi    r30, r30, -16332
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16332);

label_80192AF4:
    ctx->pc = 0x80192AF4u;
    // 80192AF4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192AF8:
    ctx->pc = 0x80192AF8u;
    // 80192AF8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192AFC:
    ctx->pc = 0x80192AFCu;
    // 80192AFC: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x80192AFCu)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_80192B00:
    ctx->pc = 0x80192B00u;
    // 80192B00: bl      0x801D009C
    {
            ctx->lr = 0x80192B04u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192B04:
    ctx->pc = 0x80192B04u;
    ctx->downcount -= 3;
    // 80192B04: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192B08:
    ctx->pc = 0x80192B08u;
    // 80192B08: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192B0C:
    ctx->pc = 0x80192B0Cu;
    // 80192B0C: bl      0x801D009C
    {
            ctx->lr = 0x80192B10u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192B10:
    ctx->pc = 0x80192B10u;
    ctx->downcount -= 7;
    // 80192B10: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192B14:
    ctx->pc = 0x80192B14u;
    // 80192B14: stfs     f1, 304(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192B14u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(304);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192B18:
    ctx->pc = 0x80192B18u;
    // 80192B18: addi    r30, r30, -16356
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16356);

label_80192B1C:
    ctx->pc = 0x80192B1Cu;
    // 80192B1C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192B20:
    ctx->pc = 0x80192B20u;
    // 80192B20: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192B24:
    ctx->pc = 0x80192B24u;
    // 80192B24: fmr    f1, f29
    if (!ppc_fp_available_inline(ctx, 0x80192B24u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_80192B28:
    ctx->pc = 0x80192B28u;
    // 80192B28: bl      0x801D009C
    {
            ctx->lr = 0x80192B2Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192B2C:
    ctx->pc = 0x80192B2Cu;
    ctx->downcount -= 3;
    // 80192B2C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192B30:
    ctx->pc = 0x80192B30u;
    // 80192B30: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192B34:
    ctx->pc = 0x80192B34u;
    // 80192B34: bl      0x801D009C
    {
            ctx->lr = 0x80192B38u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80192B38:
    ctx->pc = 0x80192B38u;
    ctx->downcount -= 7;
    // 80192B38: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192B3C:
    ctx->pc = 0x80192B3Cu;
    // 80192B3C: stfs     f1, 308(r31)
    if (!ppc_fp_available_inline(ctx, 0x80192B3Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(308);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80192B40:
    ctx->pc = 0x80192B40u;
    // 80192B40: addi    r30, r30, -15504
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15504);

label_80192B44:
    ctx->pc = 0x80192B44u;
    // 80192B44: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192B48:
    ctx->pc = 0x80192B48u;
    // 80192B48: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192B4C:
    ctx->pc = 0x80192B4Cu;
    // 80192B4C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192B50:
    ctx->pc = 0x80192B50u;
    // 80192B50: bl      0x801CFFC8
    {
            ctx->lr = 0x80192B54u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192B54:
    ctx->pc = 0x80192B54u;
    ctx->downcount -= 4;
    // 80192B54: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192B58:
    ctx->pc = 0x80192B58u;
    // 80192B58: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192B5C:
    ctx->pc = 0x80192B5Cu;
    // 80192B5C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192B60:
    ctx->pc = 0x80192B60u;
    // 80192B60: bl      0x801CFFC8
    {
            ctx->lr = 0x80192B64u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192B64:
    ctx->pc = 0x80192B64u;
    ctx->downcount -= 7;
    // 80192B64: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192B68:
    ctx->pc = 0x80192B68u;
    // 80192B68: stw     r3, 312(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192B6C:
    ctx->pc = 0x80192B6Cu;
    // 80192B6C: addi    r30, r30, -15488
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15488);

label_80192B70:
    ctx->pc = 0x80192B70u;
    // 80192B70: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192B74:
    ctx->pc = 0x80192B74u;
    // 80192B74: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192B78:
    ctx->pc = 0x80192B78u;
    // 80192B78: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192B7C:
    ctx->pc = 0x80192B7Cu;
    // 80192B7C: bl      0x801CFFC8
    {
            ctx->lr = 0x80192B80u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192B80:
    ctx->pc = 0x80192B80u;
    ctx->downcount -= 4;
    // 80192B80: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192B84:
    ctx->pc = 0x80192B84u;
    // 80192B84: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192B88:
    ctx->pc = 0x80192B88u;
    // 80192B88: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192B8C:
    ctx->pc = 0x80192B8Cu;
    // 80192B8C: bl      0x801CFFC8
    {
            ctx->lr = 0x80192B90u;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192B90:
    ctx->pc = 0x80192B90u;
    ctx->downcount -= 7;
    // 80192B90: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192B94:
    ctx->pc = 0x80192B94u;
    // 80192B94: stw     r3, 316(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(316);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192B98:
    ctx->pc = 0x80192B98u;
    // 80192B98: addi    r30, r30, -15472
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15472);

label_80192B9C:
    ctx->pc = 0x80192B9Cu;
    // 80192B9C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192BA0:
    ctx->pc = 0x80192BA0u;
    // 80192BA0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192BA4:
    ctx->pc = 0x80192BA4u;
    // 80192BA4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192BA8:
    ctx->pc = 0x80192BA8u;
    // 80192BA8: bl      0x801CFFC8
    {
            ctx->lr = 0x80192BACu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192BAC:
    ctx->pc = 0x80192BACu;
    ctx->downcount -= 4;
    // 80192BAC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192BB0:
    ctx->pc = 0x80192BB0u;
    // 80192BB0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192BB4:
    ctx->pc = 0x80192BB4u;
    // 80192BB4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192BB8:
    ctx->pc = 0x80192BB8u;
    // 80192BB8: bl      0x801CFFC8
    {
            ctx->lr = 0x80192BBCu;
            ctx->pc = 0x801CFFC8u;
            return;
    }

label_80192BBC:
    ctx->pc = 0x80192BBCu;
    ctx->downcount -= 7;
    // 80192BBC: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192BC0:
    ctx->pc = 0x80192BC0u;
    // 80192BC0: stw     r3, 320(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(320);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192BC4:
    ctx->pc = 0x80192BC4u;
    // 80192BC4: addi    r30, r30, -15452
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15452);

label_80192BC8:
    ctx->pc = 0x80192BC8u;
    // 80192BC8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192BCC:
    ctx->pc = 0x80192BCCu;
    // 80192BCC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192BD0:
    ctx->pc = 0x80192BD0u;
    // 80192BD0: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192BD4:
    ctx->pc = 0x80192BD4u;
    // 80192BD4: bl      0x801D012C
    {
            ctx->lr = 0x80192BD8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192BD8:
    ctx->pc = 0x80192BD8u;
    ctx->downcount -= 4;
    // 80192BD8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192BDC:
    ctx->pc = 0x80192BDCu;
    // 80192BDC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192BE0:
    ctx->pc = 0x80192BE0u;
    // 80192BE0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192BE4:
    ctx->pc = 0x80192BE4u;
    // 80192BE4: bl      0x801D012C
    {
            ctx->lr = 0x80192BE8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192BE8:
    ctx->pc = 0x80192BE8u;
    ctx->downcount -= 7;
    // 80192BE8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192BEC:
    ctx->pc = 0x80192BECu;
    // 80192BEC: stw     r3, 368(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(368);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192BF0:
    ctx->pc = 0x80192BF0u;
    // 80192BF0: addi    r30, r30, -15440
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15440);

label_80192BF4:
    ctx->pc = 0x80192BF4u;
    // 80192BF4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192BF8:
    ctx->pc = 0x80192BF8u;
    // 80192BF8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192BFC:
    ctx->pc = 0x80192BFCu;
    // 80192BFC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192C00:
    ctx->pc = 0x80192C00u;
    // 80192C00: bl      0x801D012C
    {
            ctx->lr = 0x80192C04u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192C04:
    ctx->pc = 0x80192C04u;
    ctx->downcount -= 4;
    // 80192C04: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192C08:
    ctx->pc = 0x80192C08u;
    // 80192C08: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192C0C:
    ctx->pc = 0x80192C0Cu;
    // 80192C0C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192C10:
    ctx->pc = 0x80192C10u;
    // 80192C10: bl      0x801D012C
    {
            ctx->lr = 0x80192C14u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192C14:
    ctx->pc = 0x80192C14u;
    ctx->downcount -= 9;
    // 80192C14: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80192C18:
    ctx->pc = 0x80192C18u;
    // 80192C18: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192C1C:
    ctx->pc = 0x80192C1Cu;
    // 80192C1C: addi    r29, r9, -15416
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-15416);

label_80192C20:
    ctx->pc = 0x80192C20u;
    // 80192C20: addi    r30, r30, -15428
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15428);

label_80192C24:
    ctx->pc = 0x80192C24u;
    // 80192C24: stw     r3, 372(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(372);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192C28:
    ctx->pc = 0x80192C28u;
    // 80192C28: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192C2C:
    ctx->pc = 0x80192C2Cu;
    // 80192C2C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192C30:
    ctx->pc = 0x80192C30u;
    // 80192C30: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192C34:
    ctx->pc = 0x80192C34u;
    // 80192C34: bl      0x801D012C
    {
            ctx->lr = 0x80192C38u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192C38:
    ctx->pc = 0x80192C38u;
    ctx->downcount -= 4;
    // 80192C38: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192C3C:
    ctx->pc = 0x80192C3Cu;
    // 80192C3C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192C40:
    ctx->pc = 0x80192C40u;
    // 80192C40: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192C44:
    ctx->pc = 0x80192C44u;
    // 80192C44: bl      0x801D012C
    {
            ctx->lr = 0x80192C48u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192C48:
    ctx->pc = 0x80192C48u;
    ctx->downcount -= 4;
    // 80192C48: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192C4C:
    ctx->pc = 0x80192C4Cu;
    // 80192C4C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192C50:
    ctx->pc = 0x80192C50u;
    // 80192C50: addi    r4, r4, -16268
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16268);

label_80192C54:
    ctx->pc = 0x80192C54u;
    // 80192C54: bl      0x80297FBC
    {
            ctx->lr = 0x80192C58u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192C58:
    ctx->pc = 0x80192C58u;
    ctx->downcount -= 2;
    // 80192C58: or.   r3, r3, r3
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

label_80192C5C:
    ctx->pc = 0x80192C5Cu;
    // 80192C5C: bc    4, 2, 0x80192C68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192C68;
        }
    }

label_80192C60:
    ctx->pc = 0x80192C60u;
    ctx->downcount -= 2;
    // 80192C60: stw     r3, 220(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(220);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192C64:
    ctx->pc = 0x80192C64u;
    // 80192C64: b       0x80192CC4
    {
            goto label_80192CC4;
    }

label_80192C68:
    ctx->pc = 0x80192C68u;
    ctx->downcount -= 4;
    // 80192C68: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192C6C:
    ctx->pc = 0x80192C6Cu;
    // 80192C6C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192C70:
    ctx->pc = 0x80192C70u;
    // 80192C70: addi    r4, r4, -15412
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-15412);

label_80192C74:
    ctx->pc = 0x80192C74u;
    // 80192C74: bl      0x80297FBC
    {
            ctx->lr = 0x80192C78u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192C78:
    ctx->pc = 0x80192C78u;
    ctx->downcount -= 2;
    // 80192C78: cmpwi   r3, 0
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

label_80192C7C:
    ctx->pc = 0x80192C7Cu;
    // 80192C7C: bc    4, 2, 0x80192C88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192C88;
        }
    }

label_80192C80:
    ctx->pc = 0x80192C80u;
    ctx->downcount -= 2;
    // 80192C80: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80192C84:
    ctx->pc = 0x80192C84u;
    // 80192C84: b       0x80192CC0
    {
            goto label_80192CC0;
    }

label_80192C88:
    ctx->pc = 0x80192C88u;
    ctx->downcount -= 4;
    // 80192C88: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192C8C:
    ctx->pc = 0x80192C8Cu;
    // 80192C8C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192C90:
    ctx->pc = 0x80192C90u;
    // 80192C90: addi    r4, r4, -15404
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-15404);

label_80192C94:
    ctx->pc = 0x80192C94u;
    // 80192C94: bl      0x80297FBC
    {
            ctx->lr = 0x80192C98u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192C98:
    ctx->pc = 0x80192C98u;
    ctx->downcount -= 2;
    // 80192C98: cmpwi   r3, 0
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

label_80192C9C:
    ctx->pc = 0x80192C9Cu;
    // 80192C9C: bc    4, 2, 0x80192CA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192CA8;
        }
    }

label_80192CA0:
    ctx->pc = 0x80192CA0u;
    ctx->downcount -= 2;
    // 80192CA0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80192CA4:
    ctx->pc = 0x80192CA4u;
    // 80192CA4: b       0x80192CC0
    {
            goto label_80192CC0;
    }

label_80192CA8:
    ctx->pc = 0x80192CA8u;
    ctx->downcount -= 3;
    // 80192CA8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192CAC:
    ctx->pc = 0x80192CACu;
    // 80192CAC: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192CB0:
    ctx->pc = 0x80192CB0u;
    // 80192CB0: bl      0x80297FBC
    {
            ctx->lr = 0x80192CB4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192CB4:
    ctx->pc = 0x80192CB4u;
    ctx->downcount -= 2;
    // 80192CB4: cmpwi   r3, 0
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

label_80192CB8:
    ctx->pc = 0x80192CB8u;
    // 80192CB8: bc    4, 2, 0x80192CC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192CC4;
        }
    }

label_80192CBC:
    ctx->pc = 0x80192CBCu;
    ctx->downcount -= 1;
    // 80192CBC: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80192CC0:
    ctx->pc = 0x80192CC0u;
    ctx->downcount -= 1;
    // 80192CC0: stw     r0, 220(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(220);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192CC4:
    ctx->pc = 0x80192CC4u;
    ctx->downcount -= 9;
    // 80192CC4: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192CC8:
    ctx->pc = 0x80192CC8u;
    // 80192CC8: lis     r28, -32720
    ctx->gpr[28] = ((u32)(s32)(-32720) << 16);

label_80192CCC:
    ctx->pc = 0x80192CCCu;
    // 80192CCC: addi    r30, r30, -15396
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15396);

label_80192CD0:
    ctx->pc = 0x80192CD0u;
    // 80192CD0: addi    r28, r28, -16268
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(-16268);

label_80192CD4:
    ctx->pc = 0x80192CD4u;
    // 80192CD4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192CD8:
    ctx->pc = 0x80192CD8u;
    // 80192CD8: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80192CDC:
    ctx->pc = 0x80192CDCu;
    // 80192CDC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192CE0:
    ctx->pc = 0x80192CE0u;
    // 80192CE0: addi    r29, r24, 4
    ctx->gpr[29] = ctx->gpr[24] + (u32)(s32)(4);

label_80192CE4:
    ctx->pc = 0x80192CE4u;
    // 80192CE4: bl      0x801D012C
    {
            ctx->lr = 0x80192CE8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192CE8:
    ctx->pc = 0x80192CE8u;
    ctx->downcount -= 5;
    // 80192CE8: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_80192CEC:
    ctx->pc = 0x80192CECu;
    // 80192CEC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192CF0:
    ctx->pc = 0x80192CF0u;
    // 80192CF0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192CF4:
    ctx->pc = 0x80192CF4u;
    // 80192CF4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192CF8:
    ctx->pc = 0x80192CF8u;
    // 80192CF8: bl      0x801D012C
    {
            ctx->lr = 0x80192CFCu;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192CFC:
    ctx->pc = 0x80192CFCu;
    ctx->downcount -= 1;
    // 80192CFC: bl      0x8008F24C
    {
            ctx->lr = 0x80192D00u;
            ctx->pc = 0x8008F24Cu;
            return;
    }

label_80192D00:
    ctx->pc = 0x80192D00u;
    ctx->downcount -= 8;
    // 80192D00: stw     r3, 228(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(228);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192D04:
    ctx->pc = 0x80192D04u;
    // 80192D04: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_80192D08:
    ctx->pc = 0x80192D08u;
    // 80192D08: addi    r5, r5, -15384
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-15384);

label_80192D0C:
    ctx->pc = 0x80192D0Cu;
    // 80192D0C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192D10:
    ctx->pc = 0x80192D10u;
    // 80192D10: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192D14:
    ctx->pc = 0x80192D14u;
    // 80192D14: addi    r6, r31, 380
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(380);

label_80192D18:
    ctx->pc = 0x80192D18u;
    // 80192D18: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192D1C:
    ctx->pc = 0x80192D1Cu;
    // 80192D1C: bl      0x801B4568
    {
            ctx->lr = 0x80192D20u;
            ctx->pc = 0x801B4568u;
            return;
    }

label_80192D20:
    ctx->pc = 0x80192D20u;
    ctx->downcount -= 7;
    // 80192D20: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_80192D24:
    ctx->pc = 0x80192D24u;
    // 80192D24: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192D28:
    ctx->pc = 0x80192D28u;
    // 80192D28: addi    r5, r5, -15372
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-15372);

label_80192D2C:
    ctx->pc = 0x80192D2Cu;
    // 80192D2C: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192D30:
    ctx->pc = 0x80192D30u;
    // 80192D30: addi    r6, r31, 460
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(460);

label_80192D34:
    ctx->pc = 0x80192D34u;
    // 80192D34: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192D38:
    ctx->pc = 0x80192D38u;
    // 80192D38: bl      0x801B4568
    {
            ctx->lr = 0x80192D3Cu;
            ctx->pc = 0x801B4568u;
            return;
    }

label_80192D3C:
    ctx->pc = 0x80192D3Cu;
    ctx->downcount -= 8;
    // 80192D3C: stw     r25, 540(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(540);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80192D40:
    ctx->pc = 0x80192D40u;
    // 80192D40: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_80192D44:
    ctx->pc = 0x80192D44u;
    // 80192D44: addi    r5, r5, -15364
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-15364);

label_80192D48:
    ctx->pc = 0x80192D48u;
    // 80192D48: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192D4C:
    ctx->pc = 0x80192D4Cu;
    // 80192D4C: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192D50:
    ctx->pc = 0x80192D50u;
    // 80192D50: addi    r6, r31, 628
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(628);

label_80192D54:
    ctx->pc = 0x80192D54u;
    // 80192D54: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192D58:
    ctx->pc = 0x80192D58u;
    // 80192D58: bl      0x801B4568
    {
            ctx->lr = 0x80192D5Cu;
            ctx->pc = 0x801B4568u;
            return;
    }

label_80192D5C:
    ctx->pc = 0x80192D5Cu;
    ctx->downcount -= 8;
    // 80192D5C: stw     r25, 708(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(708);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80192D60:
    ctx->pc = 0x80192D60u;
    // 80192D60: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_80192D64:
    ctx->pc = 0x80192D64u;
    // 80192D64: addi    r5, r5, -15356
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-15356);

label_80192D68:
    ctx->pc = 0x80192D68u;
    // 80192D68: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192D6C:
    ctx->pc = 0x80192D6Cu;
    // 80192D6C: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192D70:
    ctx->pc = 0x80192D70u;
    // 80192D70: addi    r6, r31, 712
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(712);

label_80192D74:
    ctx->pc = 0x80192D74u;
    // 80192D74: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192D78:
    ctx->pc = 0x80192D78u;
    // 80192D78: bl      0x801B4568
    {
            ctx->lr = 0x80192D7Cu;
            ctx->pc = 0x801B4568u;
            return;
    }

label_80192D7C:
    ctx->pc = 0x80192D7Cu;
    ctx->downcount -= 8;
    // 80192D7C: stw     r25, 792(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(792);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80192D80:
    ctx->pc = 0x80192D80u;
    // 80192D80: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_80192D84:
    ctx->pc = 0x80192D84u;
    // 80192D84: addi    r5, r5, -15344
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-15344);

label_80192D88:
    ctx->pc = 0x80192D88u;
    // 80192D88: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192D8C:
    ctx->pc = 0x80192D8Cu;
    // 80192D8C: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192D90:
    ctx->pc = 0x80192D90u;
    // 80192D90: addi    r6, r31, 796
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(796);

label_80192D94:
    ctx->pc = 0x80192D94u;
    // 80192D94: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192D98:
    ctx->pc = 0x80192D98u;
    // 80192D98: bl      0x801B4568
    {
            ctx->lr = 0x80192D9Cu;
            ctx->pc = 0x801B4568u;
            return;
    }

label_80192D9C:
    ctx->pc = 0x80192D9Cu;
    ctx->downcount -= 8;
    // 80192D9C: stw     r25, 876(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(876);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80192DA0:
    ctx->pc = 0x80192DA0u;
    // 80192DA0: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_80192DA4:
    ctx->pc = 0x80192DA4u;
    // 80192DA4: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192DA8:
    ctx->pc = 0x80192DA8u;
    // 80192DA8: addi    r6, r31, 544
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(544);

label_80192DAC:
    ctx->pc = 0x80192DACu;
    // 80192DAC: addi    r5, r5, -15332
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-15332);

label_80192DB0:
    ctx->pc = 0x80192DB0u;
    // 80192DB0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192DB4:
    ctx->pc = 0x80192DB4u;
    // 80192DB4: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192DB8:
    ctx->pc = 0x80192DB8u;
    // 80192DB8: bl      0x801B4568
    {
            ctx->lr = 0x80192DBCu;
            ctx->pc = 0x801B4568u;
            return;
    }

label_80192DBC:
    ctx->pc = 0x80192DBCu;
    ctx->downcount -= 7;
    // 80192DBC: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192DC0:
    ctx->pc = 0x80192DC0u;
    // 80192DC0: stw     r25, 624(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(624);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80192DC4:
    ctx->pc = 0x80192DC4u;
    // 80192DC4: addi    r30, r30, -16312
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16312);

label_80192DC8:
    ctx->pc = 0x80192DC8u;
    // 80192DC8: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80192DCC:
    ctx->pc = 0x80192DCCu;
    // 80192DCC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192DD0:
    ctx->pc = 0x80192DD0u;
    // 80192DD0: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192DD4:
    ctx->pc = 0x80192DD4u;
    // 80192DD4: bl      0x801D012C
    {
            ctx->lr = 0x80192DD8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192DD8:
    ctx->pc = 0x80192DD8u;
    ctx->downcount -= 4;
    // 80192DD8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192DDC:
    ctx->pc = 0x80192DDCu;
    // 80192DDC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192DE0:
    ctx->pc = 0x80192DE0u;
    // 80192DE0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192DE4:
    ctx->pc = 0x80192DE4u;
    // 80192DE4: bl      0x801D012C
    {
            ctx->lr = 0x80192DE8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192DE8:
    ctx->pc = 0x80192DE8u;
    ctx->downcount -= 4;
    // 80192DE8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192DEC:
    ctx->pc = 0x80192DECu;
    // 80192DEC: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192DF0:
    ctx->pc = 0x80192DF0u;
    // 80192DF0: addi    r4, r4, -16304
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16304);

label_80192DF4:
    ctx->pc = 0x80192DF4u;
    // 80192DF4: bl      0x80297FBC
    {
            ctx->lr = 0x80192DF8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192DF8:
    ctx->pc = 0x80192DF8u;
    ctx->downcount -= 2;
    // 80192DF8: cmpwi   r3, 0
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

label_80192DFC:
    ctx->pc = 0x80192DFCu;
    // 80192DFC: bc    4, 2, 0x80192E0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192E0C;
        }
    }

label_80192E00:
    ctx->pc = 0x80192E00u;
    ctx->downcount -= 3;
    // 80192E00: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80192E04:
    ctx->pc = 0x80192E04u;
    // 80192E04: stw     r0, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192E08:
    ctx->pc = 0x80192E08u;
    // 80192E08: b       0x80192E7C
    {
            goto label_80192E7C;
    }

label_80192E0C:
    ctx->pc = 0x80192E0Cu;
    ctx->downcount -= 4;
    // 80192E0C: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192E10:
    ctx->pc = 0x80192E10u;
    // 80192E10: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192E14:
    ctx->pc = 0x80192E14u;
    // 80192E14: addi    r4, r4, -16296
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16296);

label_80192E18:
    ctx->pc = 0x80192E18u;
    // 80192E18: bl      0x80297FBC
    {
            ctx->lr = 0x80192E1Cu;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192E1C:
    ctx->pc = 0x80192E1Cu;
    ctx->downcount -= 2;
    // 80192E1C: cmpwi   r3, 0
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

label_80192E20:
    ctx->pc = 0x80192E20u;
    // 80192E20: bc    4, 2, 0x80192E30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192E30;
        }
    }

label_80192E24:
    ctx->pc = 0x80192E24u;
    ctx->downcount -= 3;
    // 80192E24: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80192E28:
    ctx->pc = 0x80192E28u;
    // 80192E28: stw     r0, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192E2C:
    ctx->pc = 0x80192E2Cu;
    // 80192E2C: b       0x80192E7C
    {
            goto label_80192E7C;
    }

label_80192E30:
    ctx->pc = 0x80192E30u;
    ctx->downcount -= 4;
    // 80192E30: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192E34:
    ctx->pc = 0x80192E34u;
    // 80192E34: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192E38:
    ctx->pc = 0x80192E38u;
    // 80192E38: addi    r4, r4, -16288
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16288);

label_80192E3C:
    ctx->pc = 0x80192E3Cu;
    // 80192E3C: bl      0x80297FBC
    {
            ctx->lr = 0x80192E40u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192E40:
    ctx->pc = 0x80192E40u;
    ctx->downcount -= 2;
    // 80192E40: cmpwi   r3, 0
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

label_80192E44:
    ctx->pc = 0x80192E44u;
    // 80192E44: bc    4, 2, 0x80192E54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192E54;
        }
    }

label_80192E48:
    ctx->pc = 0x80192E48u;
    ctx->downcount -= 3;
    // 80192E48: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80192E4C:
    ctx->pc = 0x80192E4Cu;
    // 80192E4C: stw     r0, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192E50:
    ctx->pc = 0x80192E50u;
    // 80192E50: b       0x80192E7C
    {
            goto label_80192E7C;
    }

label_80192E54:
    ctx->pc = 0x80192E54u;
    ctx->downcount -= 4;
    // 80192E54: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192E58:
    ctx->pc = 0x80192E58u;
    // 80192E58: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192E5C:
    ctx->pc = 0x80192E5Cu;
    // 80192E5C: addi    r4, r4, -16276
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16276);

label_80192E60:
    ctx->pc = 0x80192E60u;
    // 80192E60: bl      0x80297FBC
    {
            ctx->lr = 0x80192E64u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192E64:
    ctx->pc = 0x80192E64u;
    ctx->downcount -= 2;
    // 80192E64: cmpwi   r3, 0
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

label_80192E68:
    ctx->pc = 0x80192E68u;
    // 80192E68: bc    4, 2, 0x80192E78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192E78;
        }
    }

label_80192E6C:
    ctx->pc = 0x80192E6Cu;
    ctx->downcount -= 3;
    // 80192E6C: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_80192E70:
    ctx->pc = 0x80192E70u;
    // 80192E70: stw     r0, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192E74:
    ctx->pc = 0x80192E74u;
    // 80192E74: b       0x80192E7C
    {
            goto label_80192E7C;
    }

label_80192E78:
    ctx->pc = 0x80192E78u;
    ctx->downcount -= 1;
    // 80192E78: stw     r25, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80192E7C:
    ctx->pc = 0x80192E7Cu;
    ctx->downcount -= 7;
    // 80192E7C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192E80:
    ctx->pc = 0x80192E80u;
    // 80192E80: lis     r5, -32720
    ctx->gpr[5] = ((u32)(s32)(-32720) << 16);

label_80192E84:
    ctx->pc = 0x80192E84u;
    // 80192E84: addi    r30, r30, -15320
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15320);

label_80192E88:
    ctx->pc = 0x80192E88u;
    // 80192E88: addi    r5, r5, -16240
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-16240);

label_80192E8C:
    ctx->pc = 0x80192E8Cu;
    // 80192E8C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192E90:
    ctx->pc = 0x80192E90u;
    // 80192E90: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192E94:
    ctx->pc = 0x80192E94u;
    // 80192E94: bl      0x801D012C
    {
            ctx->lr = 0x80192E98u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192E98:
    ctx->pc = 0x80192E98u;
    ctx->downcount -= 4;
    // 80192E98: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192E9C:
    ctx->pc = 0x80192E9Cu;
    // 80192E9C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192EA0:
    ctx->pc = 0x80192EA0u;
    // 80192EA0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192EA4:
    ctx->pc = 0x80192EA4u;
    // 80192EA4: bl      0x801D012C
    {
            ctx->lr = 0x80192EA8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192EA8:
    ctx->pc = 0x80192EA8u;
    ctx->downcount -= 7;
    // 80192EA8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80192EAC:
    ctx->pc = 0x80192EACu;
    // 80192EAC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192EB0:
    ctx->pc = 0x80192EB0u;
    // 80192EB0: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192EB4:
    ctx->pc = 0x80192EB4u;
    // 80192EB4: stw     r0, 188(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(188);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192EB8:
    ctx->pc = 0x80192EB8u;
    // 80192EB8: addi    r4, r4, -15308
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-15308);

label_80192EBC:
    ctx->pc = 0x80192EBCu;
    // 80192EBC: stw     r0, 184(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192EC0:
    ctx->pc = 0x80192EC0u;
    // 80192EC0: bl      0x80297FBC
    {
            ctx->lr = 0x80192EC4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192EC4:
    ctx->pc = 0x80192EC4u;
    ctx->downcount -= 2;
    // 80192EC4: cmpwi   r3, 0
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

label_80192EC8:
    ctx->pc = 0x80192EC8u;
    // 80192EC8: bc    4, 2, 0x80192ED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192ED8;
        }
    }

label_80192ECC:
    ctx->pc = 0x80192ECCu;
    ctx->downcount -= 3;
    // 80192ECC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80192ED0:
    ctx->pc = 0x80192ED0u;
    // 80192ED0: stw     r0, 184(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192ED4:
    ctx->pc = 0x80192ED4u;
    // 80192ED4: b       0x80192EF8
    {
            goto label_80192EF8;
    }

label_80192ED8:
    ctx->pc = 0x80192ED8u;
    ctx->downcount -= 4;
    // 80192ED8: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192EDC:
    ctx->pc = 0x80192EDCu;
    // 80192EDC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192EE0:
    ctx->pc = 0x80192EE0u;
    // 80192EE0: addi    r4, r4, -16224
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16224);

label_80192EE4:
    ctx->pc = 0x80192EE4u;
    // 80192EE4: bl      0x80297FBC
    {
            ctx->lr = 0x80192EE8u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192EE8:
    ctx->pc = 0x80192EE8u;
    ctx->downcount -= 2;
    // 80192EE8: cmpwi   r3, 0
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

label_80192EEC:
    ctx->pc = 0x80192EECu;
    // 80192EEC: bc    4, 2, 0x80192EF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192EF8;
        }
    }

label_80192EF0:
    ctx->pc = 0x80192EF0u;
    ctx->downcount -= 2;
    // 80192EF0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80192EF4:
    ctx->pc = 0x80192EF4u;
    // 80192EF4: stw     r0, 188(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(188);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192EF8:
    ctx->pc = 0x80192EF8u;
    ctx->downcount -= 8;
    // 80192EF8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192EFC:
    ctx->pc = 0x80192EFCu;
    // 80192EFC: lis     r29, -32720
    ctx->gpr[29] = ((u32)(s32)(-32720) << 16);

label_80192F00:
    ctx->pc = 0x80192F00u;
    // 80192F00: addi    r30, r30, -16260
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16260);

label_80192F04:
    ctx->pc = 0x80192F04u;
    // 80192F04: addi    r29, r29, -16268
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-16268);

label_80192F08:
    ctx->pc = 0x80192F08u;
    // 80192F08: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192F0C:
    ctx->pc = 0x80192F0Cu;
    // 80192F0C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192F10:
    ctx->pc = 0x80192F10u;
    // 80192F10: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192F14:
    ctx->pc = 0x80192F14u;
    // 80192F14: bl      0x801D012C
    {
            ctx->lr = 0x80192F18u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192F18:
    ctx->pc = 0x80192F18u;
    ctx->downcount -= 4;
    // 80192F18: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192F1C:
    ctx->pc = 0x80192F1Cu;
    // 80192F1C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192F20:
    ctx->pc = 0x80192F20u;
    // 80192F20: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192F24:
    ctx->pc = 0x80192F24u;
    // 80192F24: bl      0x801D012C
    {
            ctx->lr = 0x80192F28u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192F28:
    ctx->pc = 0x80192F28u;
    ctx->downcount -= 4;
    // 80192F28: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192F2C:
    ctx->pc = 0x80192F2Cu;
    // 80192F2C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80192F30:
    ctx->pc = 0x80192F30u;
    // 80192F30: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80192F34:
    ctx->pc = 0x80192F34u;
    // 80192F34: bl      0x80196F14
    {
            ctx->lr = 0x80192F38u;
            ctx->pc = 0x80196F14u;
            return;
    }

label_80192F38:
    ctx->pc = 0x80192F38u;
    ctx->downcount -= 7;
    // 80192F38: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192F3C:
    ctx->pc = 0x80192F3Cu;
    // 80192F3C: stw     r3, 880(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(880);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80192F40:
    ctx->pc = 0x80192F40u;
    // 80192F40: addi    r30, r30, -16252
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-16252);

label_80192F44:
    ctx->pc = 0x80192F44u;
    // 80192F44: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80192F48:
    ctx->pc = 0x80192F48u;
    // 80192F48: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192F4C:
    ctx->pc = 0x80192F4Cu;
    // 80192F4C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80192F50:
    ctx->pc = 0x80192F50u;
    // 80192F50: bl      0x801D012C
    {
            ctx->lr = 0x80192F54u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192F54:
    ctx->pc = 0x80192F54u;
    ctx->downcount -= 4;
    // 80192F54: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192F58:
    ctx->pc = 0x80192F58u;
    // 80192F58: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192F5C:
    ctx->pc = 0x80192F5Cu;
    // 80192F5C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80192F60:
    ctx->pc = 0x80192F60u;
    // 80192F60: bl      0x801D012C
    {
            ctx->lr = 0x80192F64u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80192F64:
    ctx->pc = 0x80192F64u;
    ctx->downcount -= 4;
    // 80192F64: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80192F68:
    ctx->pc = 0x80192F68u;
    // 80192F68: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192F6C:
    ctx->pc = 0x80192F6Cu;
    // 80192F6C: addi    r4, r4, -16240
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16240);

label_80192F70:
    ctx->pc = 0x80192F70u;
    // 80192F70: bl      0x80297FBC
    {
            ctx->lr = 0x80192F74u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192F74:
    ctx->pc = 0x80192F74u;
    ctx->downcount -= 2;
    // 80192F74: cmpwi   r3, 0
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

label_80192F78:
    ctx->pc = 0x80192F78u;
    // 80192F78: bc    4, 2, 0x80192F84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192F84;
        }
    }

label_80192F7C:
    ctx->pc = 0x80192F7Cu;
    ctx->downcount -= 2;
    // 80192F7C: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80192F80:
    ctx->pc = 0x80192F80u;
    // 80192F80: b       0x80192FE4
    {
            goto label_80192FE4;
    }

label_80192F84:
    ctx->pc = 0x80192F84u;
    ctx->downcount -= 4;
    // 80192F84: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192F88:
    ctx->pc = 0x80192F88u;
    // 80192F88: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192F8C:
    ctx->pc = 0x80192F8Cu;
    // 80192F8C: addi    r4, r4, -16232
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16232);

label_80192F90:
    ctx->pc = 0x80192F90u;
    // 80192F90: bl      0x80297FBC
    {
            ctx->lr = 0x80192F94u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192F94:
    ctx->pc = 0x80192F94u;
    ctx->downcount -= 2;
    // 80192F94: cmpwi   r3, 0
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

label_80192F98:
    ctx->pc = 0x80192F98u;
    // 80192F98: bc    4, 2, 0x80192FA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192FA4;
        }
    }

label_80192F9C:
    ctx->pc = 0x80192F9Cu;
    ctx->downcount -= 2;
    // 80192F9C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80192FA0:
    ctx->pc = 0x80192FA0u;
    // 80192FA0: b       0x80192FE4
    {
            goto label_80192FE4;
    }

label_80192FA4:
    ctx->pc = 0x80192FA4u;
    ctx->downcount -= 4;
    // 80192FA4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192FA8:
    ctx->pc = 0x80192FA8u;
    // 80192FA8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192FAC:
    ctx->pc = 0x80192FACu;
    // 80192FAC: addi    r4, r4, -16224
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16224);

label_80192FB0:
    ctx->pc = 0x80192FB0u;
    // 80192FB0: bl      0x80297FBC
    {
            ctx->lr = 0x80192FB4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192FB4:
    ctx->pc = 0x80192FB4u;
    ctx->downcount -= 2;
    // 80192FB4: cmpwi   r3, 0
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

label_80192FB8:
    ctx->pc = 0x80192FB8u;
    // 80192FB8: bc    4, 2, 0x80192FC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192FC4;
        }
    }

label_80192FBC:
    ctx->pc = 0x80192FBCu;
    ctx->downcount -= 2;
    // 80192FBC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80192FC0:
    ctx->pc = 0x80192FC0u;
    // 80192FC0: b       0x80192FE4
    {
            goto label_80192FE4;
    }

label_80192FC4:
    ctx->pc = 0x80192FC4u;
    ctx->downcount -= 4;
    // 80192FC4: lis     r4, -32720
    ctx->gpr[4] = ((u32)(s32)(-32720) << 16);

label_80192FC8:
    ctx->pc = 0x80192FC8u;
    // 80192FC8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192FCC:
    ctx->pc = 0x80192FCCu;
    // 80192FCC: addi    r4, r4, -16216
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16216);

label_80192FD0:
    ctx->pc = 0x80192FD0u;
    // 80192FD0: bl      0x80297FBC
    {
            ctx->lr = 0x80192FD4u;
            ctx->pc = 0x80297FBCu;
            return;
    }

label_80192FD4:
    ctx->pc = 0x80192FD4u;
    ctx->downcount -= 3;
    // 80192FD4: cmpwi   r3, 0
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

label_80192FD8:
    ctx->pc = 0x80192FD8u;
    // 80192FD8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80192FDC:
    ctx->pc = 0x80192FDCu;
    // 80192FDC: bc    4, 2, 0x80192FE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80192FE4;
        }
    }

label_80192FE0:
    ctx->pc = 0x80192FE0u;
    ctx->downcount -= 1;
    // 80192FE0: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_80192FE4:
    ctx->pc = 0x80192FE4u;
    ctx->downcount -= 9;
    // 80192FE4: stw     r0, 224(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(224);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80192FE8:
    ctx->pc = 0x80192FE8u;
    // 80192FE8: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80192FEC:
    ctx->pc = 0x80192FECu;
    // 80192FEC: lis     r29, -32720
    ctx->gpr[29] = ((u32)(s32)(-32720) << 16);

label_80192FF0:
    ctx->pc = 0x80192FF0u;
    // 80192FF0: addi    r29, r29, -16268
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-16268);

label_80192FF4:
    ctx->pc = 0x80192FF4u;
    // 80192FF4: addi    r30, r30, -15300
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15300);

label_80192FF8:
    ctx->pc = 0x80192FF8u;
    // 80192FF8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80192FFC:
    ctx->pc = 0x80192FFCu;
    // 80192FFC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80193000:
    ctx->pc = 0x80193000u;
    // 80193000: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193004:
    ctx->pc = 0x80193004u;
    // 80193004: bl      0x801D012C
    {
            ctx->lr = 0x80193008u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80193008:
    ctx->pc = 0x80193008u;
    ctx->downcount -= 4;
    // 80193008: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019300C:
    ctx->pc = 0x8019300Cu;
    // 8019300C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80193010:
    ctx->pc = 0x80193010u;
    // 80193010: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80193014:
    ctx->pc = 0x80193014u;
    // 80193014: bl      0x801D012C
    {
            ctx->lr = 0x80193018u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80193018:
    ctx->pc = 0x80193018u;
    ctx->downcount -= 7;
    // 80193018: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019301C:
    ctx->pc = 0x8019301Cu;
    // 8019301C: stw     r3, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80193020:
    ctx->pc = 0x80193020u;
    // 80193020: addi    r30, r30, -15292
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15292);

label_80193024:
    ctx->pc = 0x80193024u;
    // 80193024: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80193028:
    ctx->pc = 0x80193028u;
    // 80193028: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019302C:
    ctx->pc = 0x8019302Cu;
    // 8019302C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193030:
    ctx->pc = 0x80193030u;
    // 80193030: bl      0x801D012C
    {
            ctx->lr = 0x80193034u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80193034:
    ctx->pc = 0x80193034u;
    ctx->downcount -= 4;
    // 80193034: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80193038:
    ctx->pc = 0x80193038u;
    // 80193038: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019303C:
    ctx->pc = 0x8019303Cu;
    // 8019303C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80193040:
    ctx->pc = 0x80193040u;
    // 80193040: bl      0x801D012C
    {
            ctx->lr = 0x80193044u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80193044:
    ctx->pc = 0x80193044u;
    ctx->downcount -= 7;
    // 80193044: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80193048:
    ctx->pc = 0x80193048u;
    // 80193048: stw     r3, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019304C:
    ctx->pc = 0x8019304Cu;
    // 8019304C: addi    r30, r30, -15284
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15284);

label_80193050:
    ctx->pc = 0x80193050u;
    // 80193050: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80193054:
    ctx->pc = 0x80193054u;
    // 80193054: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80193058:
    ctx->pc = 0x80193058u;
    // 80193058: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8019305C:
    ctx->pc = 0x8019305Cu;
    // 8019305C: bl      0x801D012C
    {
            ctx->lr = 0x80193060u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80193060:
    ctx->pc = 0x80193060u;
    ctx->downcount -= 4;
    // 80193060: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80193064:
    ctx->pc = 0x80193064u;
    // 80193064: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80193068:
    ctx->pc = 0x80193068u;
    // 80193068: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8019306C:
    ctx->pc = 0x8019306Cu;
    // 8019306C: bl      0x801D012C
    {
            ctx->lr = 0x80193070u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_80193070:
    ctx->pc = 0x80193070u;
    ctx->downcount -= 7;
    // 80193070: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_80193074:
    ctx->pc = 0x80193074u;
    // 80193074: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80193078:
    ctx->pc = 0x80193078u;
    // 80193078: addi    r30, r30, -15276
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15276);

label_8019307C:
    ctx->pc = 0x8019307Cu;
    // 8019307C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80193080:
    ctx->pc = 0x80193080u;
    // 80193080: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80193084:
    ctx->pc = 0x80193084u;
    // 80193084: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193088:
    ctx->pc = 0x80193088u;
    // 80193088: bl      0x801D012C
    {
            ctx->lr = 0x8019308Cu;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8019308C:
    ctx->pc = 0x8019308Cu;
    ctx->downcount -= 4;
    // 8019308C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80193090:
    ctx->pc = 0x80193090u;
    // 80193090: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80193094:
    ctx->pc = 0x80193094u;
    // 80193094: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80193098:
    ctx->pc = 0x80193098u;
    // 80193098: bl      0x801D012C
    {
            ctx->lr = 0x8019309Cu;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_8019309C:
    ctx->pc = 0x8019309Cu;
    ctx->downcount -= 7;
    // 8019309C: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801930A0:
    ctx->pc = 0x801930A0u;
    // 801930A0: stw     r3, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801930A4:
    ctx->pc = 0x801930A4u;
    // 801930A4: addi    r30, r30, -15264
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-15264);

label_801930A8:
    ctx->pc = 0x801930A8u;
    // 801930A8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801930AC:
    ctx->pc = 0x801930ACu;
    // 801930AC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801930B0:
    ctx->pc = 0x801930B0u;
    // 801930B0: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_801930B4:
    ctx->pc = 0x801930B4u;
    // 801930B4: bl      0x801D012C
    {
            ctx->lr = 0x801930B8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_801930B8:
    ctx->pc = 0x801930B8u;
    ctx->downcount -= 4;
    // 801930B8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801930BC:
    ctx->pc = 0x801930BCu;
    // 801930BC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801930C0:
    ctx->pc = 0x801930C0u;
    // 801930C0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801930C4:
    ctx->pc = 0x801930C4u;
    // 801930C4: bl      0x801D012C
    {
            ctx->lr = 0x801930C8u;
            ctx->pc = 0x801D012Cu;
            return;
    }

label_801930C8:
    ctx->pc = 0x801930C8u;
    ctx->downcount -= 3;
    // 801930C8: stw     r3, 376(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(376);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801930CC:
    ctx->pc = 0x801930CCu;
    // 801930CC: cmpwi   r3, 0
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

label_801930D0:
    ctx->pc = 0x801930D0u;
    // 801930D0: bc    12, 2, 0x801930E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801930E4;
        }
    }

label_801930D4:
    ctx->pc = 0x801930D4u;
    ctx->downcount -= 1;
    // 801930D4: bl      0x80298908
    {
            ctx->lr = 0x801930D8u;
            ctx->pc = 0x80298908u;
            return;
    }

label_801930D8:
    ctx->pc = 0x801930D8u;
    ctx->downcount -= 2;
    // 801930D8: or.   r3, r3, r3
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

label_801930DC:
    ctx->pc = 0x801930DCu;
    // 801930DC: bc    4, 2, 0x801930E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801930E4;
        }
    }

label_801930E0:
    ctx->pc = 0x801930E0u;
    ctx->downcount -= 1;
    // 801930E0: stw     r3, 376(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(376);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801930E4:
    ctx->pc = 0x801930E4u;
    ctx->downcount -= 5;
    // 801930E4: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_801930E8:
    ctx->pc = 0x801930E8u;
    // 801930E8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801930EC:
    ctx->pc = 0x801930ECu;
    // 801930EC: addi    r4, r30, -16200
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-16200);

label_801930F0:
    ctx->pc = 0x801930F0u;
    // 801930F0: lis     r19, -32720
    ctx->gpr[19] = ((u32)(s32)(-32720) << 16);

label_801930F4:
    ctx->pc = 0x801930F4u;
    // 801930F4: bl      0x801CFC48
    {
            ctx->lr = 0x801930F8u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801930F8:
    ctx->pc = 0x801930F8u;
    ctx->downcount -= 4;
    // 801930F8: lis     r29, -32720
    ctx->gpr[29] = ((u32)(s32)(-32720) << 16);

label_801930FC:
    ctx->pc = 0x801930FCu;
    // 801930FC: addi    r4, r30, -16200
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-16200);

label_80193100:
    ctx->pc = 0x80193100u;
    // 80193100: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193104:
    ctx->pc = 0x80193104u;
    // 80193104: bl      0x801CFC48
    {
            ctx->lr = 0x80193108u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193108:
    ctx->pc = 0x80193108u;
    ctx->downcount -= 10;
    // 80193108: lis     r30, -32720
    ctx->gpr[30] = ((u32)(s32)(-32720) << 16);

label_8019310C:
    ctx->pc = 0x8019310Cu;
    // 8019310C: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80193110:
    ctx->pc = 0x80193110u;
    // 80193110: lis     r11, -32720
    ctx->gpr[11] = ((u32)(s32)(-32720) << 16);

label_80193114:
    ctx->pc = 0x80193114u;
    // 80193114: lfs     f31, -15232(r9)
    if (!ppc_fp_available_inline(ctx, 0x80193114u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15232);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80193118:
    ctx->pc = 0x80193118u;
    // 80193118: addi    r17, r11, -16188
    ctx->gpr[17] = ctx->gpr[11] + (u32)(s32)(-16188);

label_8019311C:
    ctx->pc = 0x8019311Cu;
    // 8019311C: addi    r14, r1, 16
    ctx->gpr[14] = ctx->gpr[1] + (u32)(s32)(16);

label_80193120:
    ctx->pc = 0x80193120u;
    // 80193120: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193124:
    ctx->pc = 0x80193124u;
    // 80193124: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80193128:
    ctx->pc = 0x80193128u;
    // 80193128: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x80193128u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8019312C:
    ctx->pc = 0x8019312Cu;
    // 8019312C: bl      0x801D009C
    {
            ctx->lr = 0x80193130u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193130:
    ctx->pc = 0x80193130u;
    ctx->downcount -= 5;
    // 80193130: addi    r28, r31, 144
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(144);

label_80193134:
    ctx->pc = 0x80193134u;
    // 80193134: addi    r15, r1, 24
    ctx->gpr[15] = ctx->gpr[1] + (u32)(s32)(24);

label_80193138:
    ctx->pc = 0x80193138u;
    // 80193138: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8019313C:
    ctx->pc = 0x8019313Cu;
    // 8019313C: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80193140:
    ctx->pc = 0x80193140u;
    // 80193140: bl      0x801D009C
    {
            ctx->lr = 0x80193144u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193144:
    ctx->pc = 0x80193144u;
    ctx->downcount -= 8;
    // 80193144: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80193148:
    ctx->pc = 0x80193148u;
    // 80193148: stfs     f1, 120(r31)
    if (!ppc_fp_available_inline(ctx, 0x80193148u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019314C:
    ctx->pc = 0x8019314Cu;
    // 8019314C: addi    r18, r9, -16184
    ctx->gpr[18] = ctx->gpr[9] + (u32)(s32)(-16184);

label_80193150:
    ctx->pc = 0x80193150u;
    // 80193150: addi    r16, r1, 32
    ctx->gpr[16] = ctx->gpr[1] + (u32)(s32)(32);

label_80193154:
    ctx->pc = 0x80193154u;
    // 80193154: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193158:
    ctx->pc = 0x80193158u;
    // 80193158: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_8019315C:
    ctx->pc = 0x8019315Cu;
    // 8019315C: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8019315Cu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80193160:
    ctx->pc = 0x80193160u;
    // 80193160: bl      0x801D009C
    {
            ctx->lr = 0x80193164u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193164:
    ctx->pc = 0x80193164u;
    ctx->downcount -= 3;
    // 80193164: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80193168:
    ctx->pc = 0x80193168u;
    // 80193168: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_8019316C:
    ctx->pc = 0x8019316Cu;
    // 8019316C: bl      0x801D009C
    {
            ctx->lr = 0x80193170u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193170:
    ctx->pc = 0x80193170u;
    ctx->downcount -= 4;
    // 80193170: stfs     f1, 124(r31)
    if (!ppc_fp_available_inline(ctx, 0x80193170u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80193174:
    ctx->pc = 0x80193174u;
    // 80193174: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80193178:
    ctx->pc = 0x80193178u;
    // 80193178: lwz     r4, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019317C:
    ctx->pc = 0x8019317Cu;
    // 8019317C: bl      0x801CFE08
    {
            ctx->lr = 0x80193180u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80193180:
    ctx->pc = 0x80193180u;
    ctx->downcount -= 3;
    // 80193180: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80193184:
    ctx->pc = 0x80193184u;
    // 80193184: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_80193188:
    ctx->pc = 0x80193188u;
    // 80193188: bl      0x801CFC48
    {
            ctx->lr = 0x8019318Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8019318C:
    ctx->pc = 0x8019318Cu;
    ctx->downcount -= 3;
    // 8019318C: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193190:
    ctx->pc = 0x80193190u;
    // 80193190: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80193194:
    ctx->pc = 0x80193194u;
    // 80193194: bl      0x801CFC48
    {
            ctx->lr = 0x80193198u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193198:
    ctx->pc = 0x80193198u;
    ctx->downcount -= 3;
    // 80193198: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8019319C:
    ctx->pc = 0x8019319Cu;
    // 8019319C: addi    r4, r29, -16160
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(-16160);

label_801931A0:
    ctx->pc = 0x801931A0u;
    // 801931A0: bl      0x801CFC48
    {
            ctx->lr = 0x801931A4u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801931A4:
    ctx->pc = 0x801931A4u;
    ctx->downcount -= 3;
    // 801931A4: lwz     r4, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801931A8:
    ctx->pc = 0x801931A8u;
    // 801931A8: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_801931AC:
    ctx->pc = 0x801931ACu;
    // 801931AC: bl      0x801CFE08
    {
            ctx->lr = 0x801931B0u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801931B0:
    ctx->pc = 0x801931B0u;
    ctx->downcount -= 3;
    // 801931B0: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_801931B4:
    ctx->pc = 0x801931B4u;
    // 801931B4: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_801931B8:
    ctx->pc = 0x801931B8u;
    // 801931B8: bl      0x801CFC48
    {
            ctx->lr = 0x801931BCu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801931BC:
    ctx->pc = 0x801931BCu;
    ctx->downcount -= 3;
    // 801931BC: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801931C0:
    ctx->pc = 0x801931C0u;
    // 801931C0: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_801931C4:
    ctx->pc = 0x801931C4u;
    // 801931C4: bl      0x801CFC48
    {
            ctx->lr = 0x801931C8u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801931C8:
    ctx->pc = 0x801931C8u;
    ctx->downcount -= 3;
    // 801931C8: addi    r4, r29, -16160
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(-16160);

label_801931CC:
    ctx->pc = 0x801931CCu;
    // 801931CC: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_801931D0:
    ctx->pc = 0x801931D0u;
    // 801931D0: bl      0x801CFC48
    {
            ctx->lr = 0x801931D4u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801931D4:
    ctx->pc = 0x801931D4u;
    ctx->downcount -= 4;
    // 801931D4: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_801931D8:
    ctx->pc = 0x801931D8u;
    // 801931D8: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_801931DC:
    ctx->pc = 0x801931DCu;
    // 801931DC: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801931DCu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801931E0:
    ctx->pc = 0x801931E0u;
    // 801931E0: bl      0x801D009C
    {
            ctx->lr = 0x801931E4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801931E4:
    ctx->pc = 0x801931E4u;
    ctx->downcount -= 3;
    // 801931E4: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_801931E8:
    ctx->pc = 0x801931E8u;
    // 801931E8: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_801931EC:
    ctx->pc = 0x801931ECu;
    // 801931EC: bl      0x801D009C
    {
            ctx->lr = 0x801931F0u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801931F0:
    ctx->pc = 0x801931F0u;
    ctx->downcount -= 5;
    // 801931F0: stfs     f1, 136(r31)
    if (!ppc_fp_available_inline(ctx, 0x801931F0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801931F4:
    ctx->pc = 0x801931F4u;
    // 801931F4: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_801931F8:
    ctx->pc = 0x801931F8u;
    // 801931F8: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_801931FC:
    ctx->pc = 0x801931FCu;
    // 801931FC: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801931FCu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_80193200:
    ctx->pc = 0x80193200u;
    // 80193200: bl      0x801D009C
    {
            ctx->lr = 0x80193204u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193204:
    ctx->pc = 0x80193204u;
    ctx->downcount -= 3;
    // 80193204: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80193208:
    ctx->pc = 0x80193208u;
    // 80193208: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_8019320C:
    ctx->pc = 0x8019320Cu;
    // 8019320C: bl      0x801D009C
    {
            ctx->lr = 0x80193210u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193210:
    ctx->pc = 0x80193210u;
    ctx->downcount -= 4;
    // 80193210: stfs     f1, 140(r31)
    if (!ppc_fp_available_inline(ctx, 0x80193210u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80193214:
    ctx->pc = 0x80193214u;
    // 80193214: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_80193218:
    ctx->pc = 0x80193218u;
    // 80193218: lwz     r4, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019321C:
    ctx->pc = 0x8019321Cu;
    // 8019321C: bl      0x801CFE08
    {
            ctx->lr = 0x80193220u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80193220:
    ctx->pc = 0x80193220u;
    ctx->downcount -= 3;
    // 80193220: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_80193224:
    ctx->pc = 0x80193224u;
    // 80193224: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_80193228:
    ctx->pc = 0x80193228u;
    // 80193228: bl      0x801CFC48
    {
            ctx->lr = 0x8019322Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8019322C:
    ctx->pc = 0x8019322Cu;
    ctx->downcount -= 3;
    // 8019322C: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193230:
    ctx->pc = 0x80193230u;
    // 80193230: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_80193234:
    ctx->pc = 0x80193234u;
    // 80193234: bl      0x801CFC48
    {
            ctx->lr = 0x80193238u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193238:
    ctx->pc = 0x80193238u;
    ctx->downcount -= 3;
    // 80193238: addi    r4, r30, -15252
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-15252);

label_8019323C:
    ctx->pc = 0x8019323Cu;
    // 8019323C: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_80193240:
    ctx->pc = 0x80193240u;
    // 80193240: bl      0x801CFC48
    {
            ctx->lr = 0x80193244u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193244:
    ctx->pc = 0x80193244u;
    ctx->downcount -= 3;
    // 80193244: lwz     r4, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193248:
    ctx->pc = 0x80193248u;
    // 80193248: or   r3, r16, r16
    {
        ctx->gpr[3] = ctx->gpr[16] | ctx->gpr[16];
    }

label_8019324C:
    ctx->pc = 0x8019324Cu;
    // 8019324C: bl      0x801CFE08
    {
            ctx->lr = 0x80193250u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80193250:
    ctx->pc = 0x80193250u;
    ctx->downcount -= 3;
    // 80193250: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_80193254:
    ctx->pc = 0x80193254u;
    // 80193254: or   r3, r16, r16
    {
        ctx->gpr[3] = ctx->gpr[16] | ctx->gpr[16];
    }

label_80193258:
    ctx->pc = 0x80193258u;
    // 80193258: bl      0x801CFC48
    {
            ctx->lr = 0x8019325Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8019325C:
    ctx->pc = 0x8019325Cu;
    ctx->downcount -= 3;
    // 8019325C: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193260:
    ctx->pc = 0x80193260u;
    // 80193260: or   r3, r16, r16
    {
        ctx->gpr[3] = ctx->gpr[16] | ctx->gpr[16];
    }

label_80193264:
    ctx->pc = 0x80193264u;
    // 80193264: bl      0x801CFC48
    {
            ctx->lr = 0x80193268u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193268:
    ctx->pc = 0x80193268u;
    ctx->downcount -= 3;
    // 80193268: addi    r4, r30, -15252
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-15252);

label_8019326C:
    ctx->pc = 0x8019326Cu;
    // 8019326C: or   r3, r16, r16
    {
        ctx->gpr[3] = ctx->gpr[16] | ctx->gpr[16];
    }

label_80193270:
    ctx->pc = 0x80193270u;
    // 80193270: bl      0x801CFC48
    {
            ctx->lr = 0x80193274u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193274:
    ctx->pc = 0x80193274u;
    ctx->downcount -= 5;
    // 80193274: lis     r9, -32720
    ctx->gpr[9] = ((u32)(s32)(-32720) << 16);

label_80193278:
    ctx->pc = 0x80193278u;
    // 80193278: or   r3, r16, r16
    {
        ctx->gpr[3] = ctx->gpr[16] | ctx->gpr[16];
    }

label_8019327C:
    ctx->pc = 0x8019327Cu;
    // 8019327C: lfs     f1, -15240(r9)
    if (!ppc_fp_available_inline(ctx, 0x8019327Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15240);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80193280:
    ctx->pc = 0x80193280u;
    // 80193280: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80193284:
    ctx->pc = 0x80193284u;
    // 80193284: bl      0x801D009C
    {
            ctx->lr = 0x80193288u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193288:
    ctx->pc = 0x80193288u;
    ctx->downcount -= 3;
    // 80193288: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_8019328C:
    ctx->pc = 0x8019328Cu;
    // 8019328C: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80193290:
    ctx->pc = 0x80193290u;
    // 80193290: bl      0x801D009C
    {
            ctx->lr = 0x80193294u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193294:
    ctx->pc = 0x80193294u;
    ctx->downcount -= 5;
    // 80193294: stfs     f1, 144(r31)
    if (!ppc_fp_available_inline(ctx, 0x80193294u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80193298:
    ctx->pc = 0x80193298u;
    // 80193298: or   r3, r16, r16
    {
        ctx->gpr[3] = ctx->gpr[16] | ctx->gpr[16];
    }

label_8019329C:
    ctx->pc = 0x8019329Cu;
    // 8019329C: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_801932A0:
    ctx->pc = 0x801932A0u;
    // 801932A0: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x801932A0u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801932A4:
    ctx->pc = 0x801932A4u;
    // 801932A4: bl      0x801D009C
    {
            ctx->lr = 0x801932A8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801932A8:
    ctx->pc = 0x801932A8u;
    ctx->downcount -= 3;
    // 801932A8: or   r3, r15, r15
    {
        ctx->gpr[3] = ctx->gpr[15] | ctx->gpr[15];
    }

label_801932AC:
    ctx->pc = 0x801932ACu;
    // 801932AC: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_801932B0:
    ctx->pc = 0x801932B0u;
    // 801932B0: bl      0x801D009C
    {
            ctx->lr = 0x801932B4u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801932B4:
    ctx->pc = 0x801932B4u;
    ctx->downcount -= 7;
    // 801932B4: stfs     f1, 148(r31)
    if (!ppc_fp_available_inline(ctx, 0x801932B4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(148);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801932B8:
    ctx->pc = 0x801932B8u;
    // 801932B8: lfs     f9, 144(r31)
    if (!ppc_fp_available_inline(ctx, 0x801932B8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_801932BC:
    ctx->pc = 0x801932BCu;
    // 801932BC: lfs     f0, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x801932BCu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801932C0:
    ctx->pc = 0x801932C0u;
    // 801932C0: fmuls   f0, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x801932C0u)) return;
    ppc_fmuls(ctx, 0, 0, 0);

label_801932C4:
    ctx->pc = 0x801932C4u;
    // 801932C4: fmadds f10, f9, f9, f0
    if (!ppc_fp_available_inline(ctx, 0x801932C4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[9], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[10] = ctx->ps1[10] = result;
    }

label_801932C8:
    ctx->pc = 0x801932C8u;
    // 801932C8: fcmpu   cr0, f10, f31
    if (!ppc_fp_available_inline(ctx, 0x801932C8u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[10], ctx->fpr[31], false);

label_801932CC:
    ctx->pc = 0x801932CCu;
    // 801932CC: bc    12, 2, 0x80193300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80193300;
        }
    }

label_801932D0:
    ctx->pc = 0x801932D0u;
    ctx->downcount -= 12;
    // 801932D0: lfs     f12, -29676(r13)
    if (!ppc_fp_available_inline(ctx, 0x801932D0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29676);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801932D4:
    ctx->pc = 0x801932D4u;
    // 801932D4: frsqrte    f0, f10
    if (!ppc_fp_available_inline(ctx, 0x801932D4u)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[10], &result)) ctx->fpr[0] = result; }

label_801932D8:
    ctx->pc = 0x801932D8u;
    // 801932D8: lfs     f11, -29688(r13)
    if (!ppc_fp_available_inline(ctx, 0x801932D8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801932DC:
    ctx->pc = 0x801932DCu;
    // 801932DC: fmuls   f13, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x801932DCu)) return;
    ppc_fmuls(ctx, 13, 0, 0);

label_801932E0:
    ctx->pc = 0x801932E0u;
    // 801932E0: fnmsubs f13, f13, f10, f12
    if (!ppc_fp_available_inline(ctx, 0x801932E0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[13], ctx->fpr[10], ctx->fpr[12], true, true, true, &result))
            ctx->fpr[13] = ctx->ps1[13] = result;
    }

label_801932E4:
    ctx->pc = 0x801932E4u;
    // 801932E4: fmuls   f0, f0, f11
    if (!ppc_fp_available_inline(ctx, 0x801932E4u)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_801932E8:
    ctx->pc = 0x801932E8u;
    // 801932E8: fmuls   f13, f13, f0
    if (!ppc_fp_available_inline(ctx, 0x801932E8u)) return;
    ppc_fmuls(ctx, 13, 13, 0);

label_801932EC:
    ctx->pc = 0x801932ECu;
    // 801932EC: fmuls   f12, f9, f13
    if (!ppc_fp_available_inline(ctx, 0x801932ECu)) return;
    ppc_fmuls(ctx, 12, 9, 13);

label_801932F0:
    ctx->pc = 0x801932F0u;
    // 801932F0: stfs     f12, 144(r31)
    if (!ppc_fp_available_inline(ctx, 0x801932F0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_801932F4:
    ctx->pc = 0x801932F4u;
    // 801932F4: lfs     f0, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x801932F4u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801932F8:
    ctx->pc = 0x801932F8u;
    // 801932F8: fmuls   f0, f0, f13
    if (!ppc_fp_available_inline(ctx, 0x801932F8u)) return;
    ppc_fmuls(ctx, 0, 0, 13);

label_801932FC:
    ctx->pc = 0x801932FCu;
    // 801932FC: stfs     f0, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x801932FCu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80193300:
    ctx->pc = 0x80193300u;
    ctx->downcount -= 5;
    // 80193300: addi    r23, r1, 40
    ctx->gpr[23] = ctx->gpr[1] + (u32)(s32)(40);

label_80193304:
    ctx->pc = 0x80193304u;
    // 80193304: lwz     r4, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193308:
    ctx->pc = 0x80193308u;
    // 80193308: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8019330C:
    ctx->pc = 0x8019330Cu;
    // 8019330C: lis     r22, -32720
    ctx->gpr[22] = ((u32)(s32)(-32720) << 16);

label_80193310:
    ctx->pc = 0x80193310u;
    // 80193310: bl      0x801CFE08
    {
            ctx->lr = 0x80193314u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80193314:
    ctx->pc = 0x80193314u;
    ctx->downcount -= 6;
    // 80193314: lis     r21, -32720
    ctx->gpr[21] = ((u32)(s32)(-32720) << 16);

label_80193318:
    ctx->pc = 0x80193318u;
    // 80193318: addi    r24, r1, 48
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(48);

label_8019331C:
    ctx->pc = 0x8019331Cu;
    // 8019331C: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_80193320:
    ctx->pc = 0x80193320u;
    // 80193320: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80193324:
    ctx->pc = 0x80193324u;
    // 80193324: lis     r20, -32720
    ctx->gpr[20] = ((u32)(s32)(-32720) << 16);

label_80193328:
    ctx->pc = 0x80193328u;
    // 80193328: bl      0x801CFC48
    {
            ctx->lr = 0x8019332Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8019332C:
    ctx->pc = 0x8019332Cu;
    ctx->downcount -= 5;
    // 8019332C: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193330:
    ctx->pc = 0x80193330u;
    // 80193330: addi    r25, r1, 56
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(56);

label_80193334:
    ctx->pc = 0x80193334u;
    // 80193334: addi    r26, r1, 64
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(64);

label_80193338:
    ctx->pc = 0x80193338u;
    // 80193338: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8019333C:
    ctx->pc = 0x8019333Cu;
    // 8019333C: bl      0x801CFC48
    {
            ctx->lr = 0x80193340u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193340:
    ctx->pc = 0x80193340u;
    ctx->downcount -= 4;
    // 80193340: addi    r27, r1, 72
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(72);

label_80193344:
    ctx->pc = 0x80193344u;
    // 80193344: addi    r4, r22, -16144
    ctx->gpr[4] = ctx->gpr[22] + (u32)(s32)(-16144);

label_80193348:
    ctx->pc = 0x80193348u;
    // 80193348: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8019334C:
    ctx->pc = 0x8019334Cu;
    // 8019334C: bl      0x801CFC48
    {
            ctx->lr = 0x80193350u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193350:
    ctx->pc = 0x80193350u;
    ctx->downcount -= 3;
    // 80193350: lwz     r4, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193354:
    ctx->pc = 0x80193354u;
    // 80193354: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80193358:
    ctx->pc = 0x80193358u;
    // 80193358: bl      0x801CFE08
    {
            ctx->lr = 0x8019335Cu;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_8019335C:
    ctx->pc = 0x8019335Cu;
    ctx->downcount -= 4;
    // 8019335C: addi    r28, r1, 80
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(80);

label_80193360:
    ctx->pc = 0x80193360u;
    // 80193360: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_80193364:
    ctx->pc = 0x80193364u;
    // 80193364: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80193368:
    ctx->pc = 0x80193368u;
    // 80193368: bl      0x801CFC48
    {
            ctx->lr = 0x8019336Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8019336C:
    ctx->pc = 0x8019336Cu;
    ctx->downcount -= 5;
    // 8019336C: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193370:
    ctx->pc = 0x80193370u;
    // 80193370: addi    r29, r1, 88
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(88);

label_80193374:
    ctx->pc = 0x80193374u;
    // 80193374: addi    r30, r1, 96
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(96);

label_80193378:
    ctx->pc = 0x80193378u;
    // 80193378: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8019337C:
    ctx->pc = 0x8019337Cu;
    // 8019337C: bl      0x801CFC48
    {
            ctx->lr = 0x80193380u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193380:
    ctx->pc = 0x80193380u;
    ctx->downcount -= 3;
    // 80193380: addi    r4, r22, -16144
    ctx->gpr[4] = ctx->gpr[22] + (u32)(s32)(-16144);

label_80193384:
    ctx->pc = 0x80193384u;
    // 80193384: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80193388:
    ctx->pc = 0x80193388u;
    // 80193388: bl      0x801CFC48
    {
            ctx->lr = 0x8019338Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8019338C:
    ctx->pc = 0x8019338Cu;
    ctx->downcount -= 4;
    // 8019338C: lfs     f1, 120(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019338Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80193390:
    ctx->pc = 0x80193390u;
    // 80193390: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_80193394:
    ctx->pc = 0x80193394u;
    // 80193394: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80193398:
    ctx->pc = 0x80193398u;
    // 80193398: bl      0x801D009C
    {
            ctx->lr = 0x8019339Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019339C:
    ctx->pc = 0x8019339Cu;
    ctx->downcount -= 3;
    // 8019339C: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_801933A0:
    ctx->pc = 0x801933A0u;
    // 801933A0: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_801933A4:
    ctx->pc = 0x801933A4u;
    // 801933A4: bl      0x801D009C
    {
            ctx->lr = 0x801933A8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801933A8:
    ctx->pc = 0x801933A8u;
    ctx->downcount -= 5;
    // 801933A8: stfs     f1, 152(r31)
    if (!ppc_fp_available_inline(ctx, 0x801933A8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(152);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801933AC:
    ctx->pc = 0x801933ACu;
    // 801933AC: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_801933B0:
    ctx->pc = 0x801933B0u;
    // 801933B0: lfs     f1, 124(r31)
    if (!ppc_fp_available_inline(ctx, 0x801933B0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801933B4:
    ctx->pc = 0x801933B4u;
    // 801933B4: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_801933B8:
    ctx->pc = 0x801933B8u;
    // 801933B8: bl      0x801D009C
    {
            ctx->lr = 0x801933BCu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801933BC:
    ctx->pc = 0x801933BCu;
    ctx->downcount -= 3;
    // 801933BC: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_801933C0:
    ctx->pc = 0x801933C0u;
    // 801933C0: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_801933C4:
    ctx->pc = 0x801933C4u;
    // 801933C4: bl      0x801D009C
    {
            ctx->lr = 0x801933C8u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_801933C8:
    ctx->pc = 0x801933C8u;
    ctx->downcount -= 4;
    // 801933C8: stfs     f1, 156(r31)
    if (!ppc_fp_available_inline(ctx, 0x801933C8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801933CC:
    ctx->pc = 0x801933CCu;
    // 801933CC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801933D0:
    ctx->pc = 0x801933D0u;
    // 801933D0: lwz     r4, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801933D4:
    ctx->pc = 0x801933D4u;
    // 801933D4: bl      0x801CFE08
    {
            ctx->lr = 0x801933D8u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801933D8:
    ctx->pc = 0x801933D8u;
    ctx->downcount -= 3;
    // 801933D8: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_801933DC:
    ctx->pc = 0x801933DCu;
    // 801933DC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801933E0:
    ctx->pc = 0x801933E0u;
    // 801933E0: bl      0x801CFC48
    {
            ctx->lr = 0x801933E4u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801933E4:
    ctx->pc = 0x801933E4u;
    ctx->downcount -= 3;
    // 801933E4: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801933E8:
    ctx->pc = 0x801933E8u;
    // 801933E8: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801933EC:
    ctx->pc = 0x801933ECu;
    // 801933EC: bl      0x801CFC48
    {
            ctx->lr = 0x801933F0u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801933F0:
    ctx->pc = 0x801933F0u;
    ctx->downcount -= 3;
    // 801933F0: addi    r4, r21, -16180
    ctx->gpr[4] = ctx->gpr[21] + (u32)(s32)(-16180);

label_801933F4:
    ctx->pc = 0x801933F4u;
    // 801933F4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801933F8:
    ctx->pc = 0x801933F8u;
    // 801933F8: bl      0x801CFC48
    {
            ctx->lr = 0x801933FCu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801933FC:
    ctx->pc = 0x801933FCu;
    ctx->downcount -= 3;
    // 801933FC: lwz     r4, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193400:
    ctx->pc = 0x80193400u;
    // 80193400: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193404:
    ctx->pc = 0x80193404u;
    // 80193404: bl      0x801CFE08
    {
            ctx->lr = 0x80193408u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80193408:
    ctx->pc = 0x80193408u;
    ctx->downcount -= 3;
    // 80193408: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_8019340C:
    ctx->pc = 0x8019340Cu;
    // 8019340C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193410:
    ctx->pc = 0x80193410u;
    // 80193410: bl      0x801CFC48
    {
            ctx->lr = 0x80193414u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193414:
    ctx->pc = 0x80193414u;
    ctx->downcount -= 3;
    // 80193414: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193418:
    ctx->pc = 0x80193418u;
    // 80193418: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8019341C:
    ctx->pc = 0x8019341Cu;
    // 8019341C: bl      0x801CFC48
    {
            ctx->lr = 0x80193420u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193420:
    ctx->pc = 0x80193420u;
    ctx->downcount -= 3;
    // 80193420: addi    r4, r21, -16180
    ctx->gpr[4] = ctx->gpr[21] + (u32)(s32)(-16180);

label_80193424:
    ctx->pc = 0x80193424u;
    // 80193424: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193428:
    ctx->pc = 0x80193428u;
    // 80193428: bl      0x801CFC48
    {
            ctx->lr = 0x8019342Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8019342C:
    ctx->pc = 0x8019342Cu;
    ctx->downcount -= 4;
    // 8019342C: lfs     f1, 120(r31)
    if (!ppc_fp_available_inline(ctx, 0x8019342Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80193430:
    ctx->pc = 0x80193430u;
    // 80193430: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193434:
    ctx->pc = 0x80193434u;
    // 80193434: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80193438:
    ctx->pc = 0x80193438u;
    // 80193438: bl      0x801D009C
    {
            ctx->lr = 0x8019343Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019343C:
    ctx->pc = 0x8019343Cu;
    ctx->downcount -= 3;
    // 8019343C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80193440:
    ctx->pc = 0x80193440u;
    // 80193440: or   r4, r17, r17
    {
        ctx->gpr[4] = ctx->gpr[17] | ctx->gpr[17];
    }

label_80193444:
    ctx->pc = 0x80193444u;
    // 80193444: bl      0x801D009C
    {
            ctx->lr = 0x80193448u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193448:
    ctx->pc = 0x80193448u;
    ctx->downcount -= 5;
    // 80193448: stfs     f1, 128(r31)
    if (!ppc_fp_available_inline(ctx, 0x80193448u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019344C:
    ctx->pc = 0x8019344Cu;
    // 8019344C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80193450:
    ctx->pc = 0x80193450u;
    // 80193450: lfs     f1, 124(r31)
    if (!ppc_fp_available_inline(ctx, 0x80193450u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80193454:
    ctx->pc = 0x80193454u;
    // 80193454: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_80193458:
    ctx->pc = 0x80193458u;
    // 80193458: bl      0x801D009C
    {
            ctx->lr = 0x8019345Cu;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_8019345C:
    ctx->pc = 0x8019345Cu;
    ctx->downcount -= 3;
    // 8019345C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80193460:
    ctx->pc = 0x80193460u;
    // 80193460: or   r4, r18, r18
    {
        ctx->gpr[4] = ctx->gpr[18] | ctx->gpr[18];
    }

label_80193464:
    ctx->pc = 0x80193464u;
    // 80193464: bl      0x801D009C
    {
            ctx->lr = 0x80193468u;
            ctx->pc = 0x801D009Cu;
            return;
    }

label_80193468:
    ctx->pc = 0x80193468u;
    ctx->downcount -= 4;
    // 80193468: stfs     f1, 132(r31)
    if (!ppc_fp_available_inline(ctx, 0x80193468u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(132);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019346C:
    ctx->pc = 0x8019346Cu;
    // 8019346C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80193470:
    ctx->pc = 0x80193470u;
    // 80193470: lwz     r4, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193474:
    ctx->pc = 0x80193474u;
    // 80193474: bl      0x801CFE08
    {
            ctx->lr = 0x80193478u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_80193478:
    ctx->pc = 0x80193478u;
    ctx->downcount -= 3;
    // 80193478: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_8019347C:
    ctx->pc = 0x8019347Cu;
    // 8019347C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80193480:
    ctx->pc = 0x80193480u;
    // 80193480: bl      0x801CFC48
    {
            ctx->lr = 0x80193484u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193484:
    ctx->pc = 0x80193484u;
    ctx->downcount -= 3;
    // 80193484: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80193488:
    ctx->pc = 0x80193488u;
    // 80193488: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8019348C:
    ctx->pc = 0x8019348Cu;
    // 8019348C: bl      0x801CFC48
    {
            ctx->lr = 0x80193490u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_80193490:
    ctx->pc = 0x80193490u;
    ctx->downcount -= 3;
    // 80193490: addi    r4, r20, -16128
    ctx->gpr[4] = ctx->gpr[20] + (u32)(s32)(-16128);

label_80193494:
    ctx->pc = 0x80193494u;
    // 80193494: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80193498:
    ctx->pc = 0x80193498u;
    // 80193498: bl      0x801CFC48
    {
            ctx->lr = 0x8019349Cu;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_8019349C:
    ctx->pc = 0x8019349Cu;
    ctx->downcount -= 3;
    // 8019349C: lwz     r4, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801934A0:
    ctx->pc = 0x801934A0u;
    // 801934A0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801934A4:
    ctx->pc = 0x801934A4u;
    // 801934A4: bl      0x801CFE08
    {
            ctx->lr = 0x801934A8u;
            ctx->pc = 0x801CFE08u;
            return;
    }

label_801934A8:
    ctx->pc = 0x801934A8u;
    ctx->downcount -= 3;
    // 801934A8: addi    r4, r19, -16556
    ctx->gpr[4] = ctx->gpr[19] + (u32)(s32)(-16556);

label_801934AC:
    ctx->pc = 0x801934ACu;
    // 801934AC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801934B0:
    ctx->pc = 0x801934B0u;
    // 801934B0: bl      0x801CFC48
    {
            ctx->lr = 0x801934B4u;
            ctx->pc = 0x801CFC48u;
            return;
    }

label_801934B4:
    ctx->pc = 0x801934B4u;
    ctx->downcount -= 3;
    // 801934B4: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801934B8:
    ctx->pc = 0x801934B8u;
    // 801934B8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801934BC:
    ctx->pc = 0x801934BCu;
    // 801934BC: bl      0x801CFC48
    {
            ctx->lr = 0x801934C0u;
            ctx->pc = 0x801CFC48u;
            return;
    }

    ctx->pc = 0x801934C0u;
    return;
return_dispatch_8018F4C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8018F4C8u: goto label_8018F4C8;
    case 0x8018F4E0u: goto label_8018F4E0;
    case 0x8018F508u: goto label_8018F508;
    case 0x8018F51Cu: goto label_8018F51C;
    case 0x8018F548u: goto label_8018F548;
    case 0x8018F554u: goto label_8018F554;
    case 0x8018F570u: goto label_8018F570;
    case 0x8018F57Cu: goto label_8018F57C;
    case 0x8018F598u: goto label_8018F598;
    case 0x8018F5A4u: goto label_8018F5A4;
    case 0x8018F5D4u: goto label_8018F5D4;
    case 0x8018F60Cu: goto label_8018F60C;
    case 0x8018F634u: goto label_8018F634;
    case 0x8018F648u: goto label_8018F648;
    case 0x8018F658u: goto label_8018F658;
    case 0x8018F664u: goto label_8018F664;
    case 0x8018F680u: goto label_8018F680;
    case 0x8018F68Cu: goto label_8018F68C;
    case 0x8018F6B8u: goto label_8018F6B8;
    case 0x8018F6C8u: goto label_8018F6C8;
    case 0x8018F6D8u: goto label_8018F6D8;
    case 0x8018F6FCu: goto label_8018F6FC;
    case 0x8018F724u: goto label_8018F724;
    case 0x8018F740u: goto label_8018F740;
    case 0x8018F74Cu: goto label_8018F74C;
    case 0x8018F76Cu: goto label_8018F76C;
    case 0x8018F77Cu: goto label_8018F77C;
    case 0x8018F79Cu: goto label_8018F79C;
    case 0x8018F7ACu: goto label_8018F7AC;
    case 0x8018F7CCu: goto label_8018F7CC;
    case 0x8018F7DCu: goto label_8018F7DC;
    case 0x8018F7FCu: goto label_8018F7FC;
    case 0x8018F80Cu: goto label_8018F80C;
    case 0x8018F830u: goto label_8018F830;
    case 0x8018F83Cu: goto label_8018F83C;
    case 0x8018F860u: goto label_8018F860;
    case 0x8018F86Cu: goto label_8018F86C;
    case 0x8018F894u: goto label_8018F894;
    case 0x8018F8A0u: goto label_8018F8A0;
    case 0x8018F8C4u: goto label_8018F8C4;
    case 0x8018F8D0u: goto label_8018F8D0;
    case 0x8018F8F0u: goto label_8018F8F0;
    case 0x8018F8FCu: goto label_8018F8FC;
    case 0x8018F91Cu: goto label_8018F91C;
    case 0x8018F928u: goto label_8018F928;
    case 0x8018F948u: goto label_8018F948;
    case 0x8018F954u: goto label_8018F954;
    case 0x8018F978u: goto label_8018F978;
    case 0x8018F984u: goto label_8018F984;
    case 0x8018F9A8u: goto label_8018F9A8;
    case 0x8018F9B4u: goto label_8018F9B4;
    case 0x8018FA48u: goto label_8018FA48;
    case 0x8018FA54u: goto label_8018FA54;
    case 0x8018FA70u: goto label_8018FA70;
    case 0x8018FA7Cu: goto label_8018FA7C;
    case 0x8018FB14u: goto label_8018FB14;
    case 0x8018FB24u: goto label_8018FB24;
    case 0x8018FB3Cu: goto label_8018FB3C;
    case 0x8018FB5Cu: goto label_8018FB5C;
    case 0x8018FB7Cu: goto label_8018FB7C;
    case 0x8018FBA0u: goto label_8018FBA0;
    case 0x8018FBB0u: goto label_8018FBB0;
    case 0x8018FBC0u: goto label_8018FBC0;
    case 0x8018FBCCu: goto label_8018FBCC;
    case 0x8018FBE8u: goto label_8018FBE8;
    case 0x8018FBF8u: goto label_8018FBF8;
    case 0x8018FC34u: goto label_8018FC34;
    case 0x8018FC48u: goto label_8018FC48;
    case 0x8018FC58u: goto label_8018FC58;
    case 0x8018FC84u: goto label_8018FC84;
    case 0x8018FC8Cu: goto label_8018FC8C;
    case 0x8018FC98u: goto label_8018FC98;
    case 0x8018FCACu: goto label_8018FCAC;
    case 0x8018FCC0u: goto label_8018FCC0;
    case 0x8018FCE4u: goto label_8018FCE4;
    case 0x8018FD5Cu: goto label_8018FD5C;
    case 0x8018FD64u: goto label_8018FD64;
    case 0x8018FDA8u: goto label_8018FDA8;
    case 0x8018FDE4u: goto label_8018FDE4;
    case 0x8018FE10u: goto label_8018FE10;
    case 0x8018FE70u: goto label_8018FE70;
    case 0x8018FE78u: goto label_8018FE78;
    case 0x8018FE98u: goto label_8018FE98;
    case 0x8018FEA8u: goto label_8018FEA8;
    case 0x8018FEB4u: goto label_8018FEB4;
    case 0x8018FED4u: goto label_8018FED4;
    case 0x8018FEDCu: goto label_8018FEDC;
    case 0x8018FEE4u: goto label_8018FEE4;
    case 0x8018FEF0u: goto label_8018FEF0;
    case 0x8018FEFCu: goto label_8018FEFC;
    case 0x8018FF08u: goto label_8018FF08;
    case 0x8018FF14u: goto label_8018FF14;
    case 0x8018FF88u: goto label_8018FF88;
    case 0x8018FFB8u: goto label_8018FFB8;
    case 0x801900D0u: goto label_801900D0;
    case 0x801901B8u: goto label_801901B8;
    case 0x8019029Cu: goto label_8019029C;
    case 0x801902C0u: goto label_801902C0;
    case 0x80190360u: goto label_80190360;
    case 0x80190384u: goto label_80190384;
    case 0x801903E8u: goto label_801903E8;
    case 0x801903F0u: goto label_801903F0;
    case 0x80190440u: goto label_80190440;
    case 0x80190448u: goto label_80190448;
    case 0x80190498u: goto label_80190498;
    case 0x801904A0u: goto label_801904A0;
    case 0x801904F0u: goto label_801904F0;
    case 0x801904F8u: goto label_801904F8;
    case 0x8019051Cu: goto label_8019051C;
    case 0x80190524u: goto label_80190524;
    case 0x80190548u: goto label_80190548;
    case 0x80190550u: goto label_80190550;
    case 0x80190574u: goto label_80190574;
    case 0x8019057Cu: goto label_8019057C;
    case 0x801905A0u: goto label_801905A0;
    case 0x801905A8u: goto label_801905A8;
    case 0x801905CCu: goto label_801905CC;
    case 0x801905D4u: goto label_801905D4;
    case 0x801905DCu: goto label_801905DC;
    case 0x801905F0u: goto label_801905F0;
    case 0x80190648u: goto label_80190648;
    case 0x80190650u: goto label_80190650;
    case 0x8019065Cu: goto label_8019065C;
    case 0x801906B0u: goto label_801906B0;
    case 0x801907C8u: goto label_801907C8;
    case 0x801907D0u: goto label_801907D0;
    case 0x801907D8u: goto label_801907D8;
    case 0x80190824u: goto label_80190824;
    case 0x80190840u: goto label_80190840;
    case 0x8019085Cu: goto label_8019085C;
    case 0x801908B8u: goto label_801908B8;
    case 0x801908D4u: goto label_801908D4;
    case 0x801908E4u: goto label_801908E4;
    case 0x801908F4u: goto label_801908F4;
    case 0x80190918u: goto label_80190918;
    case 0x80190930u: goto label_80190930;
    case 0x8019094Cu: goto label_8019094C;
    case 0x8019095Cu: goto label_8019095C;
    case 0x8019096Cu: goto label_8019096C;
    case 0x80190990u: goto label_80190990;
    case 0x801909A8u: goto label_801909A8;
    case 0x801909C4u: goto label_801909C4;
    case 0x80190A28u: goto label_80190A28;
    case 0x80190A30u: goto label_80190A30;
    case 0x80190A48u: goto label_80190A48;
    case 0x80190A68u: goto label_80190A68;
    case 0x80190A94u: goto label_80190A94;
    case 0x80190AACu: goto label_80190AAC;
    case 0x80190AD0u: goto label_80190AD0;
    case 0x80190AE8u: goto label_80190AE8;
    case 0x80190AF4u: goto label_80190AF4;
    case 0x80190B04u: goto label_80190B04;
    case 0x80190B20u: goto label_80190B20;
    case 0x80190B34u: goto label_80190B34;
    case 0x80190B7Cu: goto label_80190B7C;
    case 0x80190B94u: goto label_80190B94;
    case 0x80190C08u: goto label_80190C08;
    case 0x80190C5Cu: goto label_80190C5C;
    case 0x80190C68u: goto label_80190C68;
    case 0x80190C74u: goto label_80190C74;
    case 0x80190C80u: goto label_80190C80;
    case 0x80190C8Cu: goto label_80190C8C;
    case 0x80190C9Cu: goto label_80190C9C;
    case 0x80190CB0u: goto label_80190CB0;
    case 0x80190CBCu: goto label_80190CBC;
    case 0x80190CC8u: goto label_80190CC8;
    case 0x80190CD4u: goto label_80190CD4;
    case 0x80190CFCu: goto label_80190CFC;
    case 0x80190D18u: goto label_80190D18;
    case 0x80190D48u: goto label_80190D48;
    case 0x80190DB8u: goto label_80190DB8;
    case 0x80190DC4u: goto label_80190DC4;
    case 0x80190E00u: goto label_80190E00;
    case 0x80190E24u: goto label_80190E24;
    case 0x80190E50u: goto label_80190E50;
    case 0x80190EACu: goto label_80190EAC;
    case 0x80190EB4u: goto label_80190EB4;
    case 0x80190ED0u: goto label_80190ED0;
    case 0x80190EDCu: goto label_80190EDC;
    case 0x80190EE8u: goto label_80190EE8;
    case 0x80190F38u: goto label_80190F38;
    case 0x80190F44u: goto label_80190F44;
    case 0x80190F4Cu: goto label_80190F4C;
    case 0x801911A0u: goto label_801911A0;
    case 0x80191304u: goto label_80191304;
    case 0x80191314u: goto label_80191314;
    case 0x80191330u: goto label_80191330;
    case 0x8019133Cu: goto label_8019133C;
    case 0x80191358u: goto label_80191358;
    case 0x80191364u: goto label_80191364;
    case 0x80191380u: goto label_80191380;
    case 0x8019138Cu: goto label_8019138C;
    case 0x801913A8u: goto label_801913A8;
    case 0x801913B4u: goto label_801913B4;
    case 0x801913D0u: goto label_801913D0;
    case 0x801913DCu: goto label_801913DC;
    case 0x801913F8u: goto label_801913F8;
    case 0x80191404u: goto label_80191404;
    case 0x80191420u: goto label_80191420;
    case 0x8019142Cu: goto label_8019142C;
    case 0x80191448u: goto label_80191448;
    case 0x80191458u: goto label_80191458;
    case 0x80191474u: goto label_80191474;
    case 0x80191480u: goto label_80191480;
    case 0x8019149Cu: goto label_8019149C;
    case 0x801914ACu: goto label_801914AC;
    case 0x801914C8u: goto label_801914C8;
    case 0x801914D4u: goto label_801914D4;
    case 0x801914F0u: goto label_801914F0;
    case 0x801914FCu: goto label_801914FC;
    case 0x80191518u: goto label_80191518;
    case 0x80191524u: goto label_80191524;
    case 0x80191544u: goto label_80191544;
    case 0x80191554u: goto label_80191554;
    case 0x80191564u: goto label_80191564;
    case 0x80191584u: goto label_80191584;
    case 0x801915A4u: goto label_801915A4;
    case 0x801915C4u: goto label_801915C4;
    case 0x801915E4u: goto label_801915E4;
    case 0x8019161Cu: goto label_8019161C;
    case 0x8019162Cu: goto label_8019162C;
    case 0x8019163Cu: goto label_8019163C;
    case 0x80191668u: goto label_80191668;
    case 0x80191678u: goto label_80191678;
    case 0x80191688u: goto label_80191688;
    case 0x801916A8u: goto label_801916A8;
    case 0x801916C8u: goto label_801916C8;
    case 0x801916E8u: goto label_801916E8;
    case 0x80191708u: goto label_80191708;
    case 0x80191734u: goto label_80191734;
    case 0x80191744u: goto label_80191744;
    case 0x8019176Cu: goto label_8019176C;
    case 0x80191784u: goto label_80191784;
    case 0x801917A4u: goto label_801917A4;
    case 0x801917B4u: goto label_801917B4;
    case 0x801917C8u: goto label_801917C8;
    case 0x801917D8u: goto label_801917D8;
    case 0x801917E8u: goto label_801917E8;
    case 0x801917F4u: goto label_801917F4;
    case 0x80191804u: goto label_80191804;
    case 0x80191810u: goto label_80191810;
    case 0x80191824u: goto label_80191824;
    case 0x80191830u: goto label_80191830;
    case 0x80191840u: goto label_80191840;
    case 0x8019184Cu: goto label_8019184C;
    case 0x80191858u: goto label_80191858;
    case 0x80191864u: goto label_80191864;
    case 0x80191874u: goto label_80191874;
    case 0x80191880u: goto label_80191880;
    case 0x80191894u: goto label_80191894;
    case 0x801918A0u: goto label_801918A0;
    case 0x801918B0u: goto label_801918B0;
    case 0x801918BCu: goto label_801918BC;
    case 0x801918C8u: goto label_801918C8;
    case 0x801918D4u: goto label_801918D4;
    case 0x801918E4u: goto label_801918E4;
    case 0x801918F0u: goto label_801918F0;
    case 0x80191904u: goto label_80191904;
    case 0x80191910u: goto label_80191910;
    case 0x80191920u: goto label_80191920;
    case 0x8019192Cu: goto label_8019192C;
    case 0x80191938u: goto label_80191938;
    case 0x80191944u: goto label_80191944;
    case 0x80191954u: goto label_80191954;
    case 0x80191960u: goto label_80191960;
    case 0x80191974u: goto label_80191974;
    case 0x80191980u: goto label_80191980;
    case 0x80191990u: goto label_80191990;
    case 0x8019199Cu: goto label_8019199C;
    case 0x801919A8u: goto label_801919A8;
    case 0x801919B4u: goto label_801919B4;
    case 0x801919C4u: goto label_801919C4;
    case 0x801919D0u: goto label_801919D0;
    case 0x801919E4u: goto label_801919E4;
    case 0x801919F0u: goto label_801919F0;
    case 0x80191A00u: goto label_80191A00;
    case 0x80191A0Cu: goto label_80191A0C;
    case 0x80191A18u: goto label_80191A18;
    case 0x80191A24u: goto label_80191A24;
    case 0x80191A30u: goto label_80191A30;
    case 0x80191A3Cu: goto label_80191A3C;
    case 0x80191A48u: goto label_80191A48;
    case 0x80191A54u: goto label_80191A54;
    case 0x80191A60u: goto label_80191A60;
    case 0x80191A6Cu: goto label_80191A6C;
    case 0x80191A78u: goto label_80191A78;
    case 0x80191A84u: goto label_80191A84;
    case 0x80191AC0u: goto label_80191AC0;
    case 0x80191AD0u: goto label_80191AD0;
    case 0x80191AE0u: goto label_80191AE0;
    case 0x80191AECu: goto label_80191AEC;
    case 0x80191AF8u: goto label_80191AF8;
    case 0x80191B04u: goto label_80191B04;
    case 0x80191B18u: goto label_80191B18;
    case 0x80191B20u: goto label_80191B20;
    case 0x80191B40u: goto label_80191B40;
    case 0x80191B58u: goto label_80191B58;
    case 0x80191B68u: goto label_80191B68;
    case 0x80191B74u: goto label_80191B74;
    case 0x80191B80u: goto label_80191B80;
    case 0x80191B8Cu: goto label_80191B8C;
    case 0x80191B98u: goto label_80191B98;
    case 0x80191BACu: goto label_80191BAC;
    case 0x80191BC0u: goto label_80191BC0;
    case 0x80191BCCu: goto label_80191BCC;
    case 0x80191BD8u: goto label_80191BD8;
    case 0x80191BE8u: goto label_80191BE8;
    case 0x80191C0Cu: goto label_80191C0C;
    case 0x80191C2Cu: goto label_80191C2C;
    case 0x80191C98u: goto label_80191C98;
    case 0x80191CA0u: goto label_80191CA0;
    case 0x80191CD4u: goto label_80191CD4;
    case 0x80191D04u: goto label_80191D04;
    case 0x80191D2Cu: goto label_80191D2C;
    case 0x80191D8Cu: goto label_80191D8C;
    case 0x80191D94u: goto label_80191D94;
    case 0x80191DB0u: goto label_80191DB0;
    case 0x80191DBCu: goto label_80191DBC;
    case 0x80191DC8u: goto label_80191DC8;
    case 0x80191DD4u: goto label_80191DD4;
    case 0x80191DF0u: goto label_80191DF0;
    case 0x80191E04u: goto label_80191E04;
    case 0x80191E0Cu: goto label_80191E0C;
    case 0x80191E1Cu: goto label_80191E1C;
    case 0x80191E34u: goto label_80191E34;
    case 0x80191E40u: goto label_80191E40;
    case 0x80191E4Cu: goto label_80191E4C;
    case 0x80191E98u: goto label_80191E98;
    case 0x80191EC0u: goto label_80191EC0;
    case 0x80191ED4u: goto label_80191ED4;
    case 0x80191EE0u: goto label_80191EE0;
    case 0x80191F00u: goto label_80191F00;
    case 0x80191F20u: goto label_80191F20;
    case 0x80191F88u: goto label_80191F88;
    case 0x80191F94u: goto label_80191F94;
    case 0x80191FC8u: goto label_80191FC8;
    case 0x80191FF8u: goto label_80191FF8;
    case 0x80192020u: goto label_80192020;
    case 0x80192080u: goto label_80192080;
    case 0x80192088u: goto label_80192088;
    case 0x801920A4u: goto label_801920A4;
    case 0x801920B0u: goto label_801920B0;
    case 0x801920BCu: goto label_801920BC;
    case 0x801920D0u: goto label_801920D0;
    case 0x801920DCu: goto label_801920DC;
    case 0x801920E8u: goto label_801920E8;
    case 0x801920F4u: goto label_801920F4;
    case 0x80192164u: goto label_80192164;
    case 0x80192170u: goto label_80192170;
    case 0x80192190u: goto label_80192190;
    case 0x8019219Cu: goto label_8019219C;
    case 0x801921B8u: goto label_801921B8;
    case 0x801921C4u: goto label_801921C4;
    case 0x801921E0u: goto label_801921E0;
    case 0x801921ECu: goto label_801921EC;
    case 0x80192208u: goto label_80192208;
    case 0x80192214u: goto label_80192214;
    case 0x80192230u: goto label_80192230;
    case 0x8019223Cu: goto label_8019223C;
    case 0x80192258u: goto label_80192258;
    case 0x80192268u: goto label_80192268;
    case 0x80192284u: goto label_80192284;
    case 0x80192294u: goto label_80192294;
    case 0x801922B0u: goto label_801922B0;
    case 0x801922C0u: goto label_801922C0;
    case 0x801922DCu: goto label_801922DC;
    case 0x801922ECu: goto label_801922EC;
    case 0x80192308u: goto label_80192308;
    case 0x80192318u: goto label_80192318;
    case 0x8019233Cu: goto label_8019233C;
    case 0x80192348u: goto label_80192348;
    case 0x80192364u: goto label_80192364;
    case 0x80192370u: goto label_80192370;
    case 0x8019238Cu: goto label_8019238C;
    case 0x80192398u: goto label_80192398;
    case 0x801923B4u: goto label_801923B4;
    case 0x801923C4u: goto label_801923C4;
    case 0x801923E0u: goto label_801923E0;
    case 0x801923ECu: goto label_801923EC;
    case 0x8019242Cu: goto label_8019242C;
    case 0x80192460u: goto label_80192460;
    case 0x80192488u: goto label_80192488;
    case 0x80192498u: goto label_80192498;
    case 0x801924B4u: goto label_801924B4;
    case 0x801924C4u: goto label_801924C4;
    case 0x801924E0u: goto label_801924E0;
    case 0x801924ECu: goto label_801924EC;
    case 0x80192508u: goto label_80192508;
    case 0x80192514u: goto label_80192514;
    case 0x80192530u: goto label_80192530;
    case 0x8019253Cu: goto label_8019253C;
    case 0x80192558u: goto label_80192558;
    case 0x80192568u: goto label_80192568;
    case 0x80192584u: goto label_80192584;
    case 0x80192594u: goto label_80192594;
    case 0x801925B0u: goto label_801925B0;
    case 0x801925BCu: goto label_801925BC;
    case 0x801925D8u: goto label_801925D8;
    case 0x801925E4u: goto label_801925E4;
    case 0x80192600u: goto label_80192600;
    case 0x8019260Cu: goto label_8019260C;
    case 0x80192628u: goto label_80192628;
    case 0x80192634u: goto label_80192634;
    case 0x80192650u: goto label_80192650;
    case 0x8019265Cu: goto label_8019265C;
    case 0x8019267Cu: goto label_8019267C;
    case 0x80192688u: goto label_80192688;
    case 0x801926A4u: goto label_801926A4;
    case 0x801926D8u: goto label_801926D8;
    case 0x80192700u: goto label_80192700;
    case 0x80192734u: goto label_80192734;
    case 0x8019275Cu: goto label_8019275C;
    case 0x80192790u: goto label_80192790;
    case 0x801927B8u: goto label_801927B8;
    case 0x801927ECu: goto label_801927EC;
    case 0x80192814u: goto label_80192814;
    case 0x80192820u: goto label_80192820;
    case 0x80192840u: goto label_80192840;
    case 0x8019284Cu: goto label_8019284C;
    case 0x80192870u: goto label_80192870;
    case 0x8019287Cu: goto label_8019287C;
    case 0x80192898u: goto label_80192898;
    case 0x801928A4u: goto label_801928A4;
    case 0x801928C0u: goto label_801928C0;
    case 0x801928D0u: goto label_801928D0;
    case 0x801928ECu: goto label_801928EC;
    case 0x801928FCu: goto label_801928FC;
    case 0x80192920u: goto label_80192920;
    case 0x8019292Cu: goto label_8019292C;
    case 0x80192948u: goto label_80192948;
    case 0x80192954u: goto label_80192954;
    case 0x80192974u: goto label_80192974;
    case 0x80192984u: goto label_80192984;
    case 0x80192990u: goto label_80192990;
    case 0x801929ACu: goto label_801929AC;
    case 0x801929B8u: goto label_801929B8;
    case 0x801929D4u: goto label_801929D4;
    case 0x801929E0u: goto label_801929E0;
    case 0x80192A00u: goto label_80192A00;
    case 0x80192A0Cu: goto label_80192A0C;
    case 0x80192A28u: goto label_80192A28;
    case 0x80192A38u: goto label_80192A38;
    case 0x80192A58u: goto label_80192A58;
    case 0x80192A64u: goto label_80192A64;
    case 0x80192A80u: goto label_80192A80;
    case 0x80192A90u: goto label_80192A90;
    case 0x80192AACu: goto label_80192AAC;
    case 0x80192ABCu: goto label_80192ABC;
    case 0x80192ADCu: goto label_80192ADC;
    case 0x80192AE8u: goto label_80192AE8;
    case 0x80192B04u: goto label_80192B04;
    case 0x80192B10u: goto label_80192B10;
    case 0x80192B2Cu: goto label_80192B2C;
    case 0x80192B38u: goto label_80192B38;
    case 0x80192B54u: goto label_80192B54;
    case 0x80192B64u: goto label_80192B64;
    case 0x80192B80u: goto label_80192B80;
    case 0x80192B90u: goto label_80192B90;
    case 0x80192BACu: goto label_80192BAC;
    case 0x80192BBCu: goto label_80192BBC;
    case 0x80192BD8u: goto label_80192BD8;
    case 0x80192BE8u: goto label_80192BE8;
    case 0x80192C04u: goto label_80192C04;
    case 0x80192C14u: goto label_80192C14;
    case 0x80192C38u: goto label_80192C38;
    case 0x80192C48u: goto label_80192C48;
    case 0x80192C58u: goto label_80192C58;
    case 0x80192C78u: goto label_80192C78;
    case 0x80192C98u: goto label_80192C98;
    case 0x80192CB4u: goto label_80192CB4;
    case 0x80192CE8u: goto label_80192CE8;
    case 0x80192CFCu: goto label_80192CFC;
    case 0x80192D00u: goto label_80192D00;
    case 0x80192D20u: goto label_80192D20;
    case 0x80192D3Cu: goto label_80192D3C;
    case 0x80192D5Cu: goto label_80192D5C;
    case 0x80192D7Cu: goto label_80192D7C;
    case 0x80192D9Cu: goto label_80192D9C;
    case 0x80192DBCu: goto label_80192DBC;
    case 0x80192DD8u: goto label_80192DD8;
    case 0x80192DE8u: goto label_80192DE8;
    case 0x80192DF8u: goto label_80192DF8;
    case 0x80192E1Cu: goto label_80192E1C;
    case 0x80192E40u: goto label_80192E40;
    case 0x80192E64u: goto label_80192E64;
    case 0x80192E98u: goto label_80192E98;
    case 0x80192EA8u: goto label_80192EA8;
    case 0x80192EC4u: goto label_80192EC4;
    case 0x80192EE8u: goto label_80192EE8;
    case 0x80192F18u: goto label_80192F18;
    case 0x80192F28u: goto label_80192F28;
    case 0x80192F38u: goto label_80192F38;
    case 0x80192F54u: goto label_80192F54;
    case 0x80192F64u: goto label_80192F64;
    case 0x80192F74u: goto label_80192F74;
    case 0x80192F94u: goto label_80192F94;
    case 0x80192FB4u: goto label_80192FB4;
    case 0x80192FD4u: goto label_80192FD4;
    case 0x80193008u: goto label_80193008;
    case 0x80193018u: goto label_80193018;
    case 0x80193034u: goto label_80193034;
    case 0x80193044u: goto label_80193044;
    case 0x80193060u: goto label_80193060;
    case 0x80193070u: goto label_80193070;
    case 0x8019308Cu: goto label_8019308C;
    case 0x8019309Cu: goto label_8019309C;
    case 0x801930B8u: goto label_801930B8;
    case 0x801930C8u: goto label_801930C8;
    case 0x801930D8u: goto label_801930D8;
    case 0x801930F8u: goto label_801930F8;
    case 0x80193108u: goto label_80193108;
    case 0x80193130u: goto label_80193130;
    case 0x80193144u: goto label_80193144;
    case 0x80193164u: goto label_80193164;
    case 0x80193170u: goto label_80193170;
    case 0x80193180u: goto label_80193180;
    case 0x8019318Cu: goto label_8019318C;
    case 0x80193198u: goto label_80193198;
    case 0x801931A4u: goto label_801931A4;
    case 0x801931B0u: goto label_801931B0;
    case 0x801931BCu: goto label_801931BC;
    case 0x801931C8u: goto label_801931C8;
    case 0x801931D4u: goto label_801931D4;
    case 0x801931E4u: goto label_801931E4;
    case 0x801931F0u: goto label_801931F0;
    case 0x80193204u: goto label_80193204;
    case 0x80193210u: goto label_80193210;
    case 0x80193220u: goto label_80193220;
    case 0x8019322Cu: goto label_8019322C;
    case 0x80193238u: goto label_80193238;
    case 0x80193244u: goto label_80193244;
    case 0x80193250u: goto label_80193250;
    case 0x8019325Cu: goto label_8019325C;
    case 0x80193268u: goto label_80193268;
    case 0x80193274u: goto label_80193274;
    case 0x80193288u: goto label_80193288;
    case 0x80193294u: goto label_80193294;
    case 0x801932A8u: goto label_801932A8;
    case 0x801932B4u: goto label_801932B4;
    case 0x80193314u: goto label_80193314;
    case 0x8019332Cu: goto label_8019332C;
    case 0x80193340u: goto label_80193340;
    case 0x80193350u: goto label_80193350;
    case 0x8019335Cu: goto label_8019335C;
    case 0x8019336Cu: goto label_8019336C;
    case 0x80193380u: goto label_80193380;
    case 0x8019338Cu: goto label_8019338C;
    case 0x8019339Cu: goto label_8019339C;
    case 0x801933A8u: goto label_801933A8;
    case 0x801933BCu: goto label_801933BC;
    case 0x801933C8u: goto label_801933C8;
    case 0x801933D8u: goto label_801933D8;
    case 0x801933E4u: goto label_801933E4;
    case 0x801933F0u: goto label_801933F0;
    case 0x801933FCu: goto label_801933FC;
    case 0x80193408u: goto label_80193408;
    case 0x80193414u: goto label_80193414;
    case 0x80193420u: goto label_80193420;
    case 0x8019342Cu: goto label_8019342C;
    case 0x8019343Cu: goto label_8019343C;
    case 0x80193448u: goto label_80193448;
    case 0x8019345Cu: goto label_8019345C;
    case 0x80193468u: goto label_80193468;
    case 0x80193478u: goto label_80193478;
    case 0x80193484u: goto label_80193484;
    case 0x80193490u: goto label_80193490;
    case 0x8019349Cu: goto label_8019349C;
    case 0x801934A8u: goto label_801934A8;
    case 0x801934B4u: goto label_801934B4;
    default: return;
    }
}

