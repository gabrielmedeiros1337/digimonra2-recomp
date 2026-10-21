// DolRecomp output
#include "../generated.h"

static void loop_802DF928(CPUState* ctx) {
label_802DF928:
    ctx->downcount -= 4;
    // 802DF928: addi    r29, r25, 26624
    ctx->gpr[29] = ctx->gpr[25] + (u32)(s32)(26624);

    ctx->pc = 0x802DF92Cu;
    // 802DF92C: lwzu     r0, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[29] = ea;
    }

    // 802DF930: rlwinm. r0, r0, 0, 31, 31
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

    // 802DF934: bc    4, 2, 0x802DF928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF928u;
                return;
            }
            goto label_802DF928;
        }
    }

    ctx->pc = 0x802DF938u;
}

static void loop_802DF948(CPUState* ctx) {
label_802DF948:
    ctx->downcount -= 3;
    ctx->pc = 0x802DF948u;
    // 802DF948: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DF94C: rlwinm. r0, r0, 0, 31, 31
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

    // 802DF950: bc    4, 2, 0x802DF948
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF948u;
                return;
            }
            goto label_802DF948;
        }
    }

    ctx->pc = 0x802DF954u;
}

static void loop_802DF9E8(CPUState* ctx) {
label_802DF9E8:
    ctx->downcount -= 3;
    ctx->pc = 0x802DF9E8u;
    // 802DF9E8: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DF9EC: rlwinm. r0, r0, 0, 31, 31
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

    // 802DF9F0: bc    4, 2, 0x802DF9E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF9E8u;
                return;
            }
            goto label_802DF9E8;
        }
    }

    ctx->pc = 0x802DF9F4u;
}

static void loop_802DFA04(CPUState* ctx) {
label_802DFA04:
    ctx->downcount -= 3;
    ctx->pc = 0x802DFA04u;
    // 802DFA04: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DFA08: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFA0C: bc    4, 2, 0x802DFA04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFA04u;
                return;
            }
            goto label_802DFA04;
        }
    }

    ctx->pc = 0x802DFA10u;
}

static void loop_802DFA6C(CPUState* ctx) {
label_802DFA6C:
    ctx->downcount -= 3;
    ctx->pc = 0x802DFA6Cu;
    // 802DFA6C: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DFA70: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFA74: bc    4, 2, 0x802DFA6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFA6Cu;
                return;
            }
            goto label_802DFA6C;
        }
    }

    ctx->pc = 0x802DFA78u;
}

static void loop_802DFABC(CPUState* ctx) {
label_802DFABC:
    ctx->downcount -= 3;
    ctx->pc = 0x802DFABCu;
    // 802DFABC: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DFAC0: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFAC4: bc    4, 2, 0x802DFABC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFABCu;
                return;
            }
            goto label_802DFABC;
        }
    }

    ctx->pc = 0x802DFAC8u;
}

static void loop_802DFAE4(CPUState* ctx) {
label_802DFAE4:
    ctx->downcount -= 3;
    ctx->pc = 0x802DFAE4u;
    // 802DFAE4: lwz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DFAE8: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFAEC: bc    4, 2, 0x802DFAE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFAE4u;
                return;
            }
            goto label_802DFAE4;
        }
    }

    ctx->pc = 0x802DFAF0u;
}

static void loop_802DFCAC(CPUState* ctx) {
label_802DFCAC:
    ctx->downcount -= 4;
    // 802DFCAC: addi    r30, r28, 26624
    ctx->gpr[30] = ctx->gpr[28] + (u32)(s32)(26624);

    ctx->pc = 0x802DFCB0u;
    // 802DFCB0: lwzu     r0, 52(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[30] = ea;
    }

    // 802DFCB4: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFCB8: bc    4, 2, 0x802DFCAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFCACu;
                return;
            }
            goto label_802DFCAC;
        }
    }

    ctx->pc = 0x802DFCBCu;
}

static void loop_802DFCCC(CPUState* ctx) {
label_802DFCCC:
    ctx->downcount -= 3;
    ctx->pc = 0x802DFCCCu;
    // 802DFCCC: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DFCD0: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFCD4: bc    4, 2, 0x802DFCCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFCCCu;
                return;
            }
            goto label_802DFCCC;
        }
    }

    ctx->pc = 0x802DFCD8u;
}

static void loop_802DFD20(CPUState* ctx) {
label_802DFD20:
    ctx->downcount -= 3;
    ctx->pc = 0x802DFD20u;
    // 802DFD20: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DFD24: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFD28: bc    4, 2, 0x802DFD20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFD20u;
                return;
            }
            goto label_802DFD20;
        }
    }

    ctx->pc = 0x802DFD2Cu;
}

static void loop_802DFD3C(CPUState* ctx) {
label_802DFD3C:
    ctx->downcount -= 3;
    ctx->pc = 0x802DFD3Cu;
    // 802DFD3C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DFD40: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFD44: bc    4, 2, 0x802DFD3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFD3Cu;
                return;
            }
            goto label_802DFD3C;
        }
    }

    ctx->pc = 0x802DFD48u;
}

static void loop_802DFF3C(CPUState* ctx) {
label_802DFF3C:
    ctx->downcount -= 4;
    // 802DFF3C: addi    r28, r30, 26624
    ctx->gpr[28] = ctx->gpr[30] + (u32)(s32)(26624);

    ctx->pc = 0x802DFF40u;
    // 802DFF40: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

    // 802DFF44: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFF48: bc    4, 2, 0x802DFF3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFF3Cu;
                return;
            }
            goto label_802DFF3C;
        }
    }

    ctx->pc = 0x802DFF4Cu;
}

static void loop_802DFF68(CPUState* ctx) {
label_802DFF68:
    ctx->downcount -= 3;
    ctx->pc = 0x802DFF68u;
    // 802DFF68: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802DFF6C: rlwinm. r0, r0, 0, 31, 31
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

    // 802DFF70: bc    4, 2, 0x802DFF68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFF68u;
                return;
            }
            goto label_802DFF68;
        }
    }

    ctx->pc = 0x802DFF74u;
}

static void loop_802DFFF4(CPUState* ctx) {
label_802DFFF4:
    ctx->downcount -= 4;
    // 802DFFF4: addi    r28, r29, 26624
    ctx->gpr[28] = ctx->gpr[29] + (u32)(s32)(26624);

    ctx->pc = 0x802DFFF8u;
    // 802DFFF8: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

    // 802DFFFC: rlwinm. r0, r0, 0, 31, 31
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

    // 802E0000: bc    4, 2, 0x802DFFF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFFF4u;
                return;
            }
            goto label_802DFFF4;
        }
    }

    ctx->pc = 0x802E0004u;
}

static void loop_802E0030(CPUState* ctx) {
label_802E0030:
    ctx->downcount -= 3;
    ctx->pc = 0x802E0030u;
    // 802E0030: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802E0034: rlwinm. r0, r0, 0, 31, 31
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

    // 802E0038: bc    4, 2, 0x802E0030
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0030u;
                return;
            }
            goto label_802E0030;
        }
    }

    ctx->pc = 0x802E003Cu;
}

static void loop_802E00D0(CPUState* ctx) {
label_802E00D0:
    ctx->downcount -= 4;
    // 802E00D0: addi    r28, r29, 26624
    ctx->gpr[28] = ctx->gpr[29] + (u32)(s32)(26624);

    ctx->pc = 0x802E00D4u;
    // 802E00D4: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

    // 802E00D8: rlwinm. r0, r0, 0, 31, 31
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

    // 802E00DC: bc    4, 2, 0x802E00D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E00D0u;
                return;
            }
            goto label_802E00D0;
        }
    }

    ctx->pc = 0x802E00E0u;
}

static void loop_802E0100(CPUState* ctx) {
label_802E0100:
    ctx->downcount -= 3;
    ctx->pc = 0x802E0100u;
    // 802E0100: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802E0104: rlwinm. r0, r0, 0, 31, 31
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

    // 802E0108: bc    4, 2, 0x802E0100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0100u;
                return;
            }
            goto label_802E0100;
        }
    }

    ctx->pc = 0x802E010Cu;
}

static void loop_802E01A0(CPUState* ctx) {
label_802E01A0:
    ctx->downcount -= 4;
    // 802E01A0: addi    r28, r30, 26624
    ctx->gpr[28] = ctx->gpr[30] + (u32)(s32)(26624);

    ctx->pc = 0x802E01A4u;
    // 802E01A4: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

    // 802E01A8: rlwinm. r0, r0, 0, 31, 31
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

    // 802E01AC: bc    4, 2, 0x802E01A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E01A0u;
                return;
            }
            goto label_802E01A0;
        }
    }

    ctx->pc = 0x802E01B0u;
}

static void loop_802E01CC(CPUState* ctx) {
label_802E01CC:
    ctx->downcount -= 3;
    ctx->pc = 0x802E01CCu;
    // 802E01CC: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802E01D0: rlwinm. r0, r0, 0, 31, 31
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

    // 802E01D4: bc    4, 2, 0x802E01CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E01CCu;
                return;
            }
            goto label_802E01CC;
        }
    }

    ctx->pc = 0x802E01D8u;
}

static void loop_802E0254(CPUState* ctx) {
label_802E0254:
    ctx->downcount -= 3;
    ctx->pc = 0x802E0254u;
    // 802E0254: lwz     r0, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802E0258: rlwinm. r0, r0, 0, 31, 31
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

    // 802E025C: bc    4, 2, 0x802E0254
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0254u;
                return;
            }
            goto label_802E0254;
        }
    }

    ctx->pc = 0x802E0260u;
}

static void loop_802E02D8(CPUState* ctx) {
label_802E02D8:
    ctx->downcount -= 4;
    // 802E02D8: addi    r28, r30, 26624
    ctx->gpr[28] = ctx->gpr[30] + (u32)(s32)(26624);

    ctx->pc = 0x802E02DCu;
    // 802E02DC: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

    // 802E02E0: rlwinm. r0, r0, 0, 31, 31
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

    // 802E02E4: bc    4, 2, 0x802E02D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E02D8u;
                return;
            }
            goto label_802E02D8;
        }
    }

    ctx->pc = 0x802E02E8u;
}

static void loop_802E0304(CPUState* ctx) {
label_802E0304:
    ctx->downcount -= 3;
    ctx->pc = 0x802E0304u;
    // 802E0304: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802E0308: rlwinm. r0, r0, 0, 31, 31
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

    // 802E030C: bc    4, 2, 0x802E0304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0304u;
                return;
            }
            goto label_802E0304;
        }
    }

    ctx->pc = 0x802E0310u;
}

static void loop_802E0394(CPUState* ctx) {
label_802E0394:
    ctx->downcount -= 49;
    // 802E0394: subfic  r6, r29, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[29]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E0398u;
    // 802E0398: lbz     r12, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read8(ctx, ea);
    }

    // 802E039C: addi    r0, r29, 1
    ctx->gpr[0] = ctx->gpr[29] + (u32)(s32)(1);

    ctx->pc = 0x802E03A0u;
    // 802E03A0: lbz     r11, 1(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

    // 802E03A4: rlwinm r10, r6, 3, 0, 28
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    ctx->pc = 0x802E03A8u;
    // 802E03A8: lbz     r9, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

    // 802E03AC: subfic  r8, r0, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E03B0u;
    // 802E03B0: lbz     r7, 3(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

    // 802E03B4: addi    r6, r29, 2
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(2);

    ctx->pc = 0x802E03B8u;
    // 802E03B8: lbz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

    // 802E03BC: slw   r12, r12, r10
    {
        u32 sh = ctx->gpr[10] & 0x3Fu;
        ctx->gpr[12] = sh > 31 ? 0u : (ctx->gpr[12] << sh);
    }

    ctx->pc = 0x802E03C0u;
    // 802E03C0: lbz     r23, 5(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5);
        ctx->gpr[23] = mem_read8(ctx, ea);
    }

    // 802E03C4: rlwinm r10, r8, 3, 0, 28
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

    ctx->pc = 0x802E03C8u;
    // 802E03C8: lbz     r25, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        ctx->gpr[25] = mem_read8(ctx, ea);
    }

    // 802E03CC: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E03D0u;
    // 802E03D0: lbz     r27, 7(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(7);
        ctx->gpr[27] = mem_read8(ctx, ea);
    }

    // 802E03D4: rlwinm r8, r6, 3, 0, 28
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E03D8: neg  r6, r29
    {
        u32 a = ctx->gpr[29];
        ctx->gpr[6] = (~a) + 1u;
    }

    // 802E03DC: addi    r22, r29, 4
    ctx->gpr[22] = ctx->gpr[29] + (u32)(s32)(4);

    // 802E03E0: rlwinm r6, r6, 3, 0, 28
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E03E4: subfic  r22, r22, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[22]) + 1u;
        ctx->gpr[22] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 802E03E8: addi    r24, r29, 5
    ctx->gpr[24] = ctx->gpr[29] + (u32)(s32)(5);

    // 802E03EC: rlwinm r22, r22, 3, 0, 28
    {
        ctx->gpr[22] = dolrecomp_rotl32(ctx->gpr[22], 3u) & 0xFFFFFFF8u;
    }

    // 802E03F0: subfic  r24, r24, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[24]) + 1u;
        ctx->gpr[24] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 802E03F4: addi    r26, r29, 6
    ctx->gpr[26] = ctx->gpr[29] + (u32)(s32)(6);

    // 802E03F8: rlwinm r24, r24, 3, 0, 28
    {
        ctx->gpr[24] = dolrecomp_rotl32(ctx->gpr[24], 3u) & 0xFFFFFFF8u;
    }

    // 802E03FC: subfic  r26, r26, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[26]) + 1u;
        ctx->gpr[26] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 802E0400: addi    r28, r29, 7
    ctx->gpr[28] = ctx->gpr[29] + (u32)(s32)(7);

    // 802E0404: rlwinm r26, r26, 3, 0, 28
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[26], 3u) & 0xFFFFFFF8u;
    }

    // 802E0408: subfic  r28, r28, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[28]) + 1u;
        ctx->gpr[28] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 802E040C: rlwinm r28, r28, 3, 0, 28
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[28], 3u) & 0xFFFFFFF8u;
    }

    // 802E0410: or   r30, r30, r12
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[12];
    }

    // 802E0414: slw   r10, r11, r10
    {
        u32 sh = ctx->gpr[10] & 0x3Fu;
        ctx->gpr[10] = sh > 31 ? 0u : (ctx->gpr[11] << sh);
    }

    // 802E0418: or   r30, r30, r10
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[10];
    }

    // 802E041C: slw   r8, r9, r8
    {
        u32 sh = ctx->gpr[8] & 0x3Fu;
        ctx->gpr[8] = sh > 31 ? 0u : (ctx->gpr[9] << sh);
    }

    // 802E0420: or   r30, r30, r8
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[8];
    }

    // 802E0424: slw   r6, r7, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
        ctx->gpr[6] = sh > 31 ? 0u : (ctx->gpr[7] << sh);
    }

    // 802E0428: or   r30, r30, r6
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[6];
    }

    // 802E042C: slw   r0, r0, r22
    {
        u32 sh = ctx->gpr[22] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

    // 802E0430: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

    // 802E0434: slw   r0, r23, r24
    {
        u32 sh = ctx->gpr[24] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[23] << sh);
    }

    // 802E0438: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

    // 802E043C: slw   r0, r25, r26
    {
        u32 sh = ctx->gpr[26] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[25] << sh);
    }

    // 802E0440: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

    // 802E0444: slw   r0, r27, r28
    {
        u32 sh = ctx->gpr[28] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[27] << sh);
    }

    // 802E0448: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

    // 802E044C: addi    r31, r31, 8
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(8);

    // 802E0450: addi    r29, r29, 8
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(8);

    // 802E0454: bc    16, 0, 0x802E0394
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0394u;
                return;
            }
            goto label_802E0394;
        }
    }

    ctx->pc = 0x802E0458u;
}

static void loop_802E046C(CPUState* ctx) {
label_802E046C:
    ctx->downcount -= 8;
    // 802E046C: subfic  r0, r29, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[29]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E0470u;
    // 802E0470: lbz     r6, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

    // 802E0474: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

    // 802E0478: slw   r0, r6, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[6] << sh);
    }

    // 802E047C: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

    // 802E0480: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

    // 802E0484: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

    // 802E0488: bc    16, 0, 0x802E046C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E046Cu;
                return;
            }
            goto label_802E046C;
        }
    }

    ctx->pc = 0x802E048Cu;
}

static void loop_802E04B4(CPUState* ctx) {
label_802E04B4:
    ctx->downcount -= 3;
    ctx->pc = 0x802E04B4u;
    // 802E04B4: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802E04B8: rlwinm. r0, r0, 0, 31, 31
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

    // 802E04BC: bc    4, 2, 0x802E04B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E04B4u;
                return;
            }
            goto label_802E04B4;
        }
    }

    ctx->pc = 0x802E04C0u;
}

static void loop_802E04FC(CPUState* ctx) {
label_802E04FC:
    ctx->downcount -= 41;
    // 802E04FC: subfic  r6, r5, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[5]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 802E0500: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E0504: addi    r6, r5, 1
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(1);

    // 802E0508: srw   r8, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[8] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    // 802E050C: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E0510u;
    // 802E0510: stb     r8, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

    // 802E0514: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E0518: addi    r6, r5, 2
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(2);

    // 802E051C: srw   r12, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[12] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    // 802E0520: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E0524u;
    // 802E0524: stb     r12, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[12]);
    }

    // 802E0528: rlwinm r6, r6, 3, 0, 28
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E052C: srw   r11, r0, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
        ctx->gpr[11] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    // 802E0530: neg  r6, r5
    {
        u32 a = ctx->gpr[5];
        ctx->gpr[6] = (~a) + 1u;
    }

    ctx->pc = 0x802E0534u;
    // 802E0534: stb     r11, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

    // 802E0538: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E053C: addi    r6, r5, 4
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(4);

    // 802E0540: srw   r10, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[10] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    // 802E0544: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E0548u;
    // 802E0548: stb     r10, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

    // 802E054C: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E0550: addi    r6, r5, 5
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(5);

    // 802E0554: srw   r9, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[9] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    // 802E0558: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E055Cu;
    // 802E055C: stb     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

    // 802E0560: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E0564: srw   r8, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[8] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    // 802E0568: addi    r6, r5, 6
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(6);

    ctx->pc = 0x802E056Cu;
    // 802E056C: stb     r8, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

    // 802E0570: subfic  r7, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[7] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 802E0574: addi    r6, r5, 7
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(7);

    // 802E0578: rlwinm r7, r7, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 3u) & 0xFFFFFFF8u;
    }

    // 802E057C: srw   r7, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[7] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    // 802E0580: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    ctx->pc = 0x802E0584u;
    // 802E0584: stb     r7, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

    // 802E0588: rlwinm r6, r6, 3, 0, 28
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

    // 802E058C: srw   r6, r0, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
        ctx->gpr[6] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    ctx->pc = 0x802E0590u;
    // 802E0590: stb     r6, 7(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

    // 802E0594: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

    // 802E0598: addi    r5, r5, 8
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(8);

    // 802E059C: bc    16, 0, 0x802E04FC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E04FCu;
                return;
            }
            goto label_802E04FC;
        }
    }

    ctx->pc = 0x802E05A0u;
}

static void loop_802E05B0(CPUState* ctx) {
label_802E05B0:
    ctx->downcount -= 7;
    // 802E05B0: subfic  r4, r5, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[5]) + 1u;
        ctx->gpr[4] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 802E05B4: rlwinm r4, r4, 3, 0, 28
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    // 802E05B8: srw   r4, r0, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[4] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

    ctx->pc = 0x802E05BCu;
    // 802E05BC: stb     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    // 802E05C0: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

    // 802E05C4: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

    // 802E05C8: bc    16, 0, 0x802E05B0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E05B0u;
                return;
            }
            goto label_802E05B0;
        }
    }

    ctx->pc = 0x802E05CCu;
}

static void loop_802E05F0(CPUState* ctx) {
label_802E05F0:
    ctx->downcount -= 3;
    ctx->pc = 0x802E05F0u;
    // 802E05F0: lwz     r0, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 802E05F4: rlwinm. r0, r0, 0, 31, 31
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

    // 802E05F8: bc    4, 2, 0x802E05F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E05F0u;
                return;
            }
            goto label_802E05F0;
        }
    }

    ctx->pc = 0x802E05FCu;
}

void func_802DF4C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x802DF4C0u: goto label_802DF4C0;
    case 0x802DF4C4u: goto label_802DF4C4;
    case 0x802DF4C8u: goto label_802DF4C8;
    case 0x802DF4CCu: goto label_802DF4CC;
    case 0x802DF4D0u: goto label_802DF4D0;
    case 0x802DF4D4u: goto label_802DF4D4;
    case 0x802DF4D8u: goto label_802DF4D8;
    case 0x802DF4DCu: goto label_802DF4DC;
    case 0x802DF4E0u: goto label_802DF4E0;
    case 0x802DF4E4u: goto label_802DF4E4;
    case 0x802DF4E8u: goto label_802DF4E8;
    case 0x802DF4ECu: goto label_802DF4EC;
    case 0x802DF4F0u: goto label_802DF4F0;
    case 0x802DF4F4u: goto label_802DF4F4;
    case 0x802DF4F8u: goto label_802DF4F8;
    case 0x802DF4FCu: goto label_802DF4FC;
    case 0x802DF500u: goto label_802DF500;
    case 0x802DF504u: goto label_802DF504;
    case 0x802DF508u: goto label_802DF508;
    case 0x802DF50Cu: goto label_802DF50C;
    case 0x802DF510u: goto label_802DF510;
    case 0x802DF514u: goto label_802DF514;
    case 0x802DF518u: goto label_802DF518;
    case 0x802DF51Cu: goto label_802DF51C;
    case 0x802DF520u: goto label_802DF520;
    case 0x802DF524u: goto label_802DF524;
    case 0x802DF528u: goto label_802DF528;
    case 0x802DF52Cu: goto label_802DF52C;
    case 0x802DF530u: goto label_802DF530;
    case 0x802DF534u: goto label_802DF534;
    case 0x802DF538u: goto label_802DF538;
    case 0x802DF53Cu: goto label_802DF53C;
    case 0x802DF540u: goto label_802DF540;
    case 0x802DF544u: goto label_802DF544;
    case 0x802DF548u: goto label_802DF548;
    case 0x802DF54Cu: goto label_802DF54C;
    case 0x802DF550u: goto label_802DF550;
    case 0x802DF554u: goto label_802DF554;
    case 0x802DF558u: goto label_802DF558;
    case 0x802DF55Cu: goto label_802DF55C;
    case 0x802DF560u: goto label_802DF560;
    case 0x802DF564u: goto label_802DF564;
    case 0x802DF568u: goto label_802DF568;
    case 0x802DF56Cu: goto label_802DF56C;
    case 0x802DF570u: goto label_802DF570;
    case 0x802DF574u: goto label_802DF574;
    case 0x802DF578u: goto label_802DF578;
    case 0x802DF57Cu: goto label_802DF57C;
    case 0x802DF580u: goto label_802DF580;
    case 0x802DF584u: goto label_802DF584;
    case 0x802DF588u: goto label_802DF588;
    case 0x802DF58Cu: goto label_802DF58C;
    case 0x802DF590u: goto label_802DF590;
    case 0x802DF594u: goto label_802DF594;
    case 0x802DF598u: goto label_802DF598;
    case 0x802DF59Cu: goto label_802DF59C;
    case 0x802DF5A0u: goto label_802DF5A0;
    case 0x802DF5A4u: goto label_802DF5A4;
    case 0x802DF5A8u: goto label_802DF5A8;
    case 0x802DF5ACu: goto label_802DF5AC;
    case 0x802DF5B0u: goto label_802DF5B0;
    case 0x802DF5B4u: goto label_802DF5B4;
    case 0x802DF5B8u: goto label_802DF5B8;
    case 0x802DF5BCu: goto label_802DF5BC;
    case 0x802DF5C0u: goto label_802DF5C0;
    case 0x802DF5C4u: goto label_802DF5C4;
    case 0x802DF5C8u: goto label_802DF5C8;
    case 0x802DF5CCu: goto label_802DF5CC;
    case 0x802DF5D0u: goto label_802DF5D0;
    case 0x802DF5D4u: goto label_802DF5D4;
    case 0x802DF5D8u: goto label_802DF5D8;
    case 0x802DF5DCu: goto label_802DF5DC;
    case 0x802DF5E0u: goto label_802DF5E0;
    case 0x802DF5E4u: goto label_802DF5E4;
    case 0x802DF5E8u: goto label_802DF5E8;
    case 0x802DF5ECu: goto label_802DF5EC;
    case 0x802DF5F0u: goto label_802DF5F0;
    case 0x802DF5F4u: goto label_802DF5F4;
    case 0x802DF5F8u: goto label_802DF5F8;
    case 0x802DF5FCu: goto label_802DF5FC;
    case 0x802DF600u: goto label_802DF600;
    case 0x802DF604u: goto label_802DF604;
    case 0x802DF608u: goto label_802DF608;
    case 0x802DF60Cu: goto label_802DF60C;
    case 0x802DF610u: goto label_802DF610;
    case 0x802DF614u: goto label_802DF614;
    case 0x802DF618u: goto label_802DF618;
    case 0x802DF61Cu: goto label_802DF61C;
    case 0x802DF620u: goto label_802DF620;
    case 0x802DF624u: goto label_802DF624;
    case 0x802DF628u: goto label_802DF628;
    case 0x802DF62Cu: goto label_802DF62C;
    case 0x802DF630u: goto label_802DF630;
    case 0x802DF634u: goto label_802DF634;
    case 0x802DF638u: goto label_802DF638;
    case 0x802DF63Cu: goto label_802DF63C;
    case 0x802DF640u: goto label_802DF640;
    case 0x802DF644u: goto label_802DF644;
    case 0x802DF648u: goto label_802DF648;
    case 0x802DF64Cu: goto label_802DF64C;
    case 0x802DF650u: goto label_802DF650;
    case 0x802DF654u: goto label_802DF654;
    case 0x802DF658u: goto label_802DF658;
    case 0x802DF65Cu: goto label_802DF65C;
    case 0x802DF660u: goto label_802DF660;
    case 0x802DF664u: goto label_802DF664;
    case 0x802DF668u: goto label_802DF668;
    case 0x802DF66Cu: goto label_802DF66C;
    case 0x802DF670u: goto label_802DF670;
    case 0x802DF674u: goto label_802DF674;
    case 0x802DF678u: goto label_802DF678;
    case 0x802DF67Cu: goto label_802DF67C;
    case 0x802DF680u: goto label_802DF680;
    case 0x802DF684u: goto label_802DF684;
    case 0x802DF688u: goto label_802DF688;
    case 0x802DF68Cu: goto label_802DF68C;
    case 0x802DF690u: goto label_802DF690;
    case 0x802DF694u: goto label_802DF694;
    case 0x802DF698u: goto label_802DF698;
    case 0x802DF69Cu: goto label_802DF69C;
    case 0x802DF6A0u: goto label_802DF6A0;
    case 0x802DF6A4u: goto label_802DF6A4;
    case 0x802DF6A8u: goto label_802DF6A8;
    case 0x802DF6ACu: goto label_802DF6AC;
    case 0x802DF6B0u: goto label_802DF6B0;
    case 0x802DF6B4u: goto label_802DF6B4;
    case 0x802DF6B8u: goto label_802DF6B8;
    case 0x802DF6BCu: goto label_802DF6BC;
    case 0x802DF6C0u: goto label_802DF6C0;
    case 0x802DF6C4u: goto label_802DF6C4;
    case 0x802DF6C8u: goto label_802DF6C8;
    case 0x802DF6CCu: goto label_802DF6CC;
    case 0x802DF6D0u: goto label_802DF6D0;
    case 0x802DF6D4u: goto label_802DF6D4;
    case 0x802DF6D8u: goto label_802DF6D8;
    case 0x802DF6DCu: goto label_802DF6DC;
    case 0x802DF6E0u: goto label_802DF6E0;
    case 0x802DF6E4u: goto label_802DF6E4;
    case 0x802DF6E8u: goto label_802DF6E8;
    case 0x802DF6ECu: goto label_802DF6EC;
    case 0x802DF6F0u: goto label_802DF6F0;
    case 0x802DF6F4u: goto label_802DF6F4;
    case 0x802DF6F8u: goto label_802DF6F8;
    case 0x802DF6FCu: goto label_802DF6FC;
    case 0x802DF700u: goto label_802DF700;
    case 0x802DF704u: goto label_802DF704;
    case 0x802DF708u: goto label_802DF708;
    case 0x802DF70Cu: goto label_802DF70C;
    case 0x802DF710u: goto label_802DF710;
    case 0x802DF714u: goto label_802DF714;
    case 0x802DF718u: goto label_802DF718;
    case 0x802DF71Cu: goto label_802DF71C;
    case 0x802DF720u: goto label_802DF720;
    case 0x802DF724u: goto label_802DF724;
    case 0x802DF728u: goto label_802DF728;
    case 0x802DF72Cu: goto label_802DF72C;
    case 0x802DF730u: goto label_802DF730;
    case 0x802DF734u: goto label_802DF734;
    case 0x802DF738u: goto label_802DF738;
    case 0x802DF73Cu: goto label_802DF73C;
    case 0x802DF740u: goto label_802DF740;
    case 0x802DF744u: goto label_802DF744;
    case 0x802DF748u: goto label_802DF748;
    case 0x802DF74Cu: goto label_802DF74C;
    case 0x802DF750u: goto label_802DF750;
    case 0x802DF754u: goto label_802DF754;
    case 0x802DF758u: goto label_802DF758;
    case 0x802DF75Cu: goto label_802DF75C;
    case 0x802DF760u: goto label_802DF760;
    case 0x802DF764u: goto label_802DF764;
    case 0x802DF768u: goto label_802DF768;
    case 0x802DF76Cu: goto label_802DF76C;
    case 0x802DF770u: goto label_802DF770;
    case 0x802DF774u: goto label_802DF774;
    case 0x802DF778u: goto label_802DF778;
    case 0x802DF77Cu: goto label_802DF77C;
    case 0x802DF780u: goto label_802DF780;
    case 0x802DF784u: goto label_802DF784;
    case 0x802DF788u: goto label_802DF788;
    case 0x802DF78Cu: goto label_802DF78C;
    case 0x802DF790u: goto label_802DF790;
    case 0x802DF794u: goto label_802DF794;
    case 0x802DF798u: goto label_802DF798;
    case 0x802DF79Cu: goto label_802DF79C;
    case 0x802DF7A0u: goto label_802DF7A0;
    case 0x802DF7A4u: goto label_802DF7A4;
    case 0x802DF7A8u: goto label_802DF7A8;
    case 0x802DF7ACu: goto label_802DF7AC;
    case 0x802DF7B0u: goto label_802DF7B0;
    case 0x802DF7B4u: goto label_802DF7B4;
    case 0x802DF7B8u: goto label_802DF7B8;
    case 0x802DF7BCu: goto label_802DF7BC;
    case 0x802DF7C0u: goto label_802DF7C0;
    case 0x802DF7C4u: goto label_802DF7C4;
    case 0x802DF7C8u: goto label_802DF7C8;
    case 0x802DF7CCu: goto label_802DF7CC;
    case 0x802DF7D0u: goto label_802DF7D0;
    case 0x802DF7D4u: goto label_802DF7D4;
    case 0x802DF7D8u: goto label_802DF7D8;
    case 0x802DF7DCu: goto label_802DF7DC;
    case 0x802DF7E0u: goto label_802DF7E0;
    case 0x802DF7E4u: goto label_802DF7E4;
    case 0x802DF7E8u: goto label_802DF7E8;
    case 0x802DF7ECu: goto label_802DF7EC;
    case 0x802DF7F0u: goto label_802DF7F0;
    case 0x802DF7F4u: goto label_802DF7F4;
    case 0x802DF7F8u: goto label_802DF7F8;
    case 0x802DF7FCu: goto label_802DF7FC;
    case 0x802DF800u: goto label_802DF800;
    case 0x802DF804u: goto label_802DF804;
    case 0x802DF808u: goto label_802DF808;
    case 0x802DF80Cu: goto label_802DF80C;
    case 0x802DF810u: goto label_802DF810;
    case 0x802DF814u: goto label_802DF814;
    case 0x802DF818u: goto label_802DF818;
    case 0x802DF81Cu: goto label_802DF81C;
    case 0x802DF820u: goto label_802DF820;
    case 0x802DF824u: goto label_802DF824;
    case 0x802DF828u: goto label_802DF828;
    case 0x802DF82Cu: goto label_802DF82C;
    case 0x802DF830u: goto label_802DF830;
    case 0x802DF834u: goto label_802DF834;
    case 0x802DF838u: goto label_802DF838;
    case 0x802DF83Cu: goto label_802DF83C;
    case 0x802DF840u: goto label_802DF840;
    case 0x802DF844u: goto label_802DF844;
    case 0x802DF848u: goto label_802DF848;
    case 0x802DF84Cu: goto label_802DF84C;
    case 0x802DF850u: goto label_802DF850;
    case 0x802DF854u: goto label_802DF854;
    case 0x802DF858u: goto label_802DF858;
    case 0x802DF85Cu: goto label_802DF85C;
    case 0x802DF860u: goto label_802DF860;
    case 0x802DF864u: goto label_802DF864;
    case 0x802DF868u: goto label_802DF868;
    case 0x802DF86Cu: goto label_802DF86C;
    case 0x802DF870u: goto label_802DF870;
    case 0x802DF874u: goto label_802DF874;
    case 0x802DF878u: goto label_802DF878;
    case 0x802DF87Cu: goto label_802DF87C;
    case 0x802DF880u: goto label_802DF880;
    case 0x802DF884u: goto label_802DF884;
    case 0x802DF888u: goto label_802DF888;
    case 0x802DF88Cu: goto label_802DF88C;
    case 0x802DF890u: goto label_802DF890;
    case 0x802DF894u: goto label_802DF894;
    case 0x802DF898u: goto label_802DF898;
    case 0x802DF89Cu: goto label_802DF89C;
    case 0x802DF8A0u: goto label_802DF8A0;
    case 0x802DF8A4u: goto label_802DF8A4;
    case 0x802DF8A8u: goto label_802DF8A8;
    case 0x802DF8ACu: goto label_802DF8AC;
    case 0x802DF8B0u: goto label_802DF8B0;
    case 0x802DF8B4u: goto label_802DF8B4;
    case 0x802DF8B8u: goto label_802DF8B8;
    case 0x802DF8BCu: goto label_802DF8BC;
    case 0x802DF8C0u: goto label_802DF8C0;
    case 0x802DF8C4u: goto label_802DF8C4;
    case 0x802DF8C8u: goto label_802DF8C8;
    case 0x802DF8CCu: goto label_802DF8CC;
    case 0x802DF8D0u: goto label_802DF8D0;
    case 0x802DF8D4u: goto label_802DF8D4;
    case 0x802DF8D8u: goto label_802DF8D8;
    case 0x802DF8DCu: goto label_802DF8DC;
    case 0x802DF8E0u: goto label_802DF8E0;
    case 0x802DF8E4u: goto label_802DF8E4;
    case 0x802DF8E8u: goto label_802DF8E8;
    case 0x802DF8ECu: goto label_802DF8EC;
    case 0x802DF8F0u: goto label_802DF8F0;
    case 0x802DF8F4u: goto label_802DF8F4;
    case 0x802DF8F8u: goto label_802DF8F8;
    case 0x802DF8FCu: goto label_802DF8FC;
    case 0x802DF900u: goto label_802DF900;
    case 0x802DF904u: goto label_802DF904;
    case 0x802DF908u: goto label_802DF908;
    case 0x802DF90Cu: goto label_802DF90C;
    case 0x802DF910u: goto label_802DF910;
    case 0x802DF914u: goto label_802DF914;
    case 0x802DF918u: goto label_802DF918;
    case 0x802DF91Cu: goto label_802DF91C;
    case 0x802DF920u: goto label_802DF920;
    case 0x802DF924u: goto label_802DF924;
    case 0x802DF928u: goto label_802DF928;
    case 0x802DF92Cu: goto label_802DF92C;
    case 0x802DF930u: goto label_802DF930;
    case 0x802DF934u: goto label_802DF934;
    case 0x802DF938u: goto label_802DF938;
    case 0x802DF93Cu: goto label_802DF93C;
    case 0x802DF940u: goto label_802DF940;
    case 0x802DF944u: goto label_802DF944;
    case 0x802DF948u: goto label_802DF948;
    case 0x802DF94Cu: goto label_802DF94C;
    case 0x802DF950u: goto label_802DF950;
    case 0x802DF954u: goto label_802DF954;
    case 0x802DF958u: goto label_802DF958;
    case 0x802DF95Cu: goto label_802DF95C;
    case 0x802DF960u: goto label_802DF960;
    case 0x802DF964u: goto label_802DF964;
    case 0x802DF968u: goto label_802DF968;
    case 0x802DF96Cu: goto label_802DF96C;
    case 0x802DF970u: goto label_802DF970;
    case 0x802DF974u: goto label_802DF974;
    case 0x802DF978u: goto label_802DF978;
    case 0x802DF97Cu: goto label_802DF97C;
    case 0x802DF980u: goto label_802DF980;
    case 0x802DF984u: goto label_802DF984;
    case 0x802DF988u: goto label_802DF988;
    case 0x802DF98Cu: goto label_802DF98C;
    case 0x802DF990u: goto label_802DF990;
    case 0x802DF994u: goto label_802DF994;
    case 0x802DF998u: goto label_802DF998;
    case 0x802DF99Cu: goto label_802DF99C;
    case 0x802DF9A0u: goto label_802DF9A0;
    case 0x802DF9A4u: goto label_802DF9A4;
    case 0x802DF9A8u: goto label_802DF9A8;
    case 0x802DF9ACu: goto label_802DF9AC;
    case 0x802DF9B0u: goto label_802DF9B0;
    case 0x802DF9B4u: goto label_802DF9B4;
    case 0x802DF9B8u: goto label_802DF9B8;
    case 0x802DF9BCu: goto label_802DF9BC;
    case 0x802DF9C0u: goto label_802DF9C0;
    case 0x802DF9C4u: goto label_802DF9C4;
    case 0x802DF9C8u: goto label_802DF9C8;
    case 0x802DF9CCu: goto label_802DF9CC;
    case 0x802DF9D0u: goto label_802DF9D0;
    case 0x802DF9D4u: goto label_802DF9D4;
    case 0x802DF9D8u: goto label_802DF9D8;
    case 0x802DF9DCu: goto label_802DF9DC;
    case 0x802DF9E0u: goto label_802DF9E0;
    case 0x802DF9E4u: goto label_802DF9E4;
    case 0x802DF9E8u: goto label_802DF9E8;
    case 0x802DF9ECu: goto label_802DF9EC;
    case 0x802DF9F0u: goto label_802DF9F0;
    case 0x802DF9F4u: goto label_802DF9F4;
    case 0x802DF9F8u: goto label_802DF9F8;
    case 0x802DF9FCu: goto label_802DF9FC;
    case 0x802DFA00u: goto label_802DFA00;
    case 0x802DFA04u: goto label_802DFA04;
    case 0x802DFA08u: goto label_802DFA08;
    case 0x802DFA0Cu: goto label_802DFA0C;
    case 0x802DFA10u: goto label_802DFA10;
    case 0x802DFA14u: goto label_802DFA14;
    case 0x802DFA18u: goto label_802DFA18;
    case 0x802DFA1Cu: goto label_802DFA1C;
    case 0x802DFA20u: goto label_802DFA20;
    case 0x802DFA24u: goto label_802DFA24;
    case 0x802DFA28u: goto label_802DFA28;
    case 0x802DFA2Cu: goto label_802DFA2C;
    case 0x802DFA30u: goto label_802DFA30;
    case 0x802DFA34u: goto label_802DFA34;
    case 0x802DFA38u: goto label_802DFA38;
    case 0x802DFA3Cu: goto label_802DFA3C;
    case 0x802DFA40u: goto label_802DFA40;
    case 0x802DFA44u: goto label_802DFA44;
    case 0x802DFA48u: goto label_802DFA48;
    case 0x802DFA4Cu: goto label_802DFA4C;
    case 0x802DFA50u: goto label_802DFA50;
    case 0x802DFA54u: goto label_802DFA54;
    case 0x802DFA58u: goto label_802DFA58;
    case 0x802DFA5Cu: goto label_802DFA5C;
    case 0x802DFA60u: goto label_802DFA60;
    case 0x802DFA64u: goto label_802DFA64;
    case 0x802DFA68u: goto label_802DFA68;
    case 0x802DFA6Cu: goto label_802DFA6C;
    case 0x802DFA70u: goto label_802DFA70;
    case 0x802DFA74u: goto label_802DFA74;
    case 0x802DFA78u: goto label_802DFA78;
    case 0x802DFA7Cu: goto label_802DFA7C;
    case 0x802DFA80u: goto label_802DFA80;
    case 0x802DFA84u: goto label_802DFA84;
    case 0x802DFA88u: goto label_802DFA88;
    case 0x802DFA8Cu: goto label_802DFA8C;
    case 0x802DFA90u: goto label_802DFA90;
    case 0x802DFA94u: goto label_802DFA94;
    case 0x802DFA98u: goto label_802DFA98;
    case 0x802DFA9Cu: goto label_802DFA9C;
    case 0x802DFAA0u: goto label_802DFAA0;
    case 0x802DFAA4u: goto label_802DFAA4;
    case 0x802DFAA8u: goto label_802DFAA8;
    case 0x802DFAACu: goto label_802DFAAC;
    case 0x802DFAB0u: goto label_802DFAB0;
    case 0x802DFAB4u: goto label_802DFAB4;
    case 0x802DFAB8u: goto label_802DFAB8;
    case 0x802DFABCu: goto label_802DFABC;
    case 0x802DFAC0u: goto label_802DFAC0;
    case 0x802DFAC4u: goto label_802DFAC4;
    case 0x802DFAC8u: goto label_802DFAC8;
    case 0x802DFACCu: goto label_802DFACC;
    case 0x802DFAD0u: goto label_802DFAD0;
    case 0x802DFAD4u: goto label_802DFAD4;
    case 0x802DFAD8u: goto label_802DFAD8;
    case 0x802DFADCu: goto label_802DFADC;
    case 0x802DFAE0u: goto label_802DFAE0;
    case 0x802DFAE4u: goto label_802DFAE4;
    case 0x802DFAE8u: goto label_802DFAE8;
    case 0x802DFAECu: goto label_802DFAEC;
    case 0x802DFAF0u: goto label_802DFAF0;
    case 0x802DFAF4u: goto label_802DFAF4;
    case 0x802DFAF8u: goto label_802DFAF8;
    case 0x802DFAFCu: goto label_802DFAFC;
    case 0x802DFB00u: goto label_802DFB00;
    case 0x802DFB04u: goto label_802DFB04;
    case 0x802DFB08u: goto label_802DFB08;
    case 0x802DFB0Cu: goto label_802DFB0C;
    case 0x802DFB10u: goto label_802DFB10;
    case 0x802DFB14u: goto label_802DFB14;
    case 0x802DFB18u: goto label_802DFB18;
    case 0x802DFB1Cu: goto label_802DFB1C;
    case 0x802DFB20u: goto label_802DFB20;
    case 0x802DFB24u: goto label_802DFB24;
    case 0x802DFB28u: goto label_802DFB28;
    case 0x802DFB2Cu: goto label_802DFB2C;
    case 0x802DFB30u: goto label_802DFB30;
    case 0x802DFB34u: goto label_802DFB34;
    case 0x802DFB38u: goto label_802DFB38;
    case 0x802DFB3Cu: goto label_802DFB3C;
    case 0x802DFB40u: goto label_802DFB40;
    case 0x802DFB44u: goto label_802DFB44;
    case 0x802DFB48u: goto label_802DFB48;
    case 0x802DFB4Cu: goto label_802DFB4C;
    case 0x802DFB50u: goto label_802DFB50;
    case 0x802DFB54u: goto label_802DFB54;
    case 0x802DFB58u: goto label_802DFB58;
    case 0x802DFB5Cu: goto label_802DFB5C;
    case 0x802DFB60u: goto label_802DFB60;
    case 0x802DFB64u: goto label_802DFB64;
    case 0x802DFB68u: goto label_802DFB68;
    case 0x802DFB6Cu: goto label_802DFB6C;
    case 0x802DFB70u: goto label_802DFB70;
    case 0x802DFB74u: goto label_802DFB74;
    case 0x802DFB78u: goto label_802DFB78;
    case 0x802DFB7Cu: goto label_802DFB7C;
    case 0x802DFB80u: goto label_802DFB80;
    case 0x802DFB84u: goto label_802DFB84;
    case 0x802DFB88u: goto label_802DFB88;
    case 0x802DFB8Cu: goto label_802DFB8C;
    case 0x802DFB90u: goto label_802DFB90;
    case 0x802DFB94u: goto label_802DFB94;
    case 0x802DFB98u: goto label_802DFB98;
    case 0x802DFB9Cu: goto label_802DFB9C;
    case 0x802DFBA0u: goto label_802DFBA0;
    case 0x802DFBA4u: goto label_802DFBA4;
    case 0x802DFBA8u: goto label_802DFBA8;
    case 0x802DFBACu: goto label_802DFBAC;
    case 0x802DFBB0u: goto label_802DFBB0;
    case 0x802DFBB4u: goto label_802DFBB4;
    case 0x802DFBB8u: goto label_802DFBB8;
    case 0x802DFBBCu: goto label_802DFBBC;
    case 0x802DFBC0u: goto label_802DFBC0;
    case 0x802DFBC4u: goto label_802DFBC4;
    case 0x802DFBC8u: goto label_802DFBC8;
    case 0x802DFBCCu: goto label_802DFBCC;
    case 0x802DFBD0u: goto label_802DFBD0;
    case 0x802DFBD4u: goto label_802DFBD4;
    case 0x802DFBD8u: goto label_802DFBD8;
    case 0x802DFBDCu: goto label_802DFBDC;
    case 0x802DFBE0u: goto label_802DFBE0;
    case 0x802DFBE4u: goto label_802DFBE4;
    case 0x802DFBE8u: goto label_802DFBE8;
    case 0x802DFBECu: goto label_802DFBEC;
    case 0x802DFBF0u: goto label_802DFBF0;
    case 0x802DFBF4u: goto label_802DFBF4;
    case 0x802DFBF8u: goto label_802DFBF8;
    case 0x802DFBFCu: goto label_802DFBFC;
    case 0x802DFC00u: goto label_802DFC00;
    case 0x802DFC04u: goto label_802DFC04;
    case 0x802DFC08u: goto label_802DFC08;
    case 0x802DFC0Cu: goto label_802DFC0C;
    case 0x802DFC10u: goto label_802DFC10;
    case 0x802DFC14u: goto label_802DFC14;
    case 0x802DFC18u: goto label_802DFC18;
    case 0x802DFC1Cu: goto label_802DFC1C;
    case 0x802DFC20u: goto label_802DFC20;
    case 0x802DFC24u: goto label_802DFC24;
    case 0x802DFC28u: goto label_802DFC28;
    case 0x802DFC2Cu: goto label_802DFC2C;
    case 0x802DFC30u: goto label_802DFC30;
    case 0x802DFC34u: goto label_802DFC34;
    case 0x802DFC38u: goto label_802DFC38;
    case 0x802DFC3Cu: goto label_802DFC3C;
    case 0x802DFC40u: goto label_802DFC40;
    case 0x802DFC44u: goto label_802DFC44;
    case 0x802DFC48u: goto label_802DFC48;
    case 0x802DFC4Cu: goto label_802DFC4C;
    case 0x802DFC50u: goto label_802DFC50;
    case 0x802DFC54u: goto label_802DFC54;
    case 0x802DFC58u: goto label_802DFC58;
    case 0x802DFC5Cu: goto label_802DFC5C;
    case 0x802DFC60u: goto label_802DFC60;
    case 0x802DFC64u: goto label_802DFC64;
    case 0x802DFC68u: goto label_802DFC68;
    case 0x802DFC6Cu: goto label_802DFC6C;
    case 0x802DFC70u: goto label_802DFC70;
    case 0x802DFC74u: goto label_802DFC74;
    case 0x802DFC78u: goto label_802DFC78;
    case 0x802DFC7Cu: goto label_802DFC7C;
    case 0x802DFC80u: goto label_802DFC80;
    case 0x802DFC84u: goto label_802DFC84;
    case 0x802DFC88u: goto label_802DFC88;
    case 0x802DFC8Cu: goto label_802DFC8C;
    case 0x802DFC90u: goto label_802DFC90;
    case 0x802DFC94u: goto label_802DFC94;
    case 0x802DFC98u: goto label_802DFC98;
    case 0x802DFC9Cu: goto label_802DFC9C;
    case 0x802DFCA0u: goto label_802DFCA0;
    case 0x802DFCA4u: goto label_802DFCA4;
    case 0x802DFCA8u: goto label_802DFCA8;
    case 0x802DFCACu: goto label_802DFCAC;
    case 0x802DFCB0u: goto label_802DFCB0;
    case 0x802DFCB4u: goto label_802DFCB4;
    case 0x802DFCB8u: goto label_802DFCB8;
    case 0x802DFCBCu: goto label_802DFCBC;
    case 0x802DFCC0u: goto label_802DFCC0;
    case 0x802DFCC4u: goto label_802DFCC4;
    case 0x802DFCC8u: goto label_802DFCC8;
    case 0x802DFCCCu: goto label_802DFCCC;
    case 0x802DFCD0u: goto label_802DFCD0;
    case 0x802DFCD4u: goto label_802DFCD4;
    case 0x802DFCD8u: goto label_802DFCD8;
    case 0x802DFCDCu: goto label_802DFCDC;
    case 0x802DFCE0u: goto label_802DFCE0;
    case 0x802DFCE4u: goto label_802DFCE4;
    case 0x802DFCE8u: goto label_802DFCE8;
    case 0x802DFCECu: goto label_802DFCEC;
    case 0x802DFCF0u: goto label_802DFCF0;
    case 0x802DFCF4u: goto label_802DFCF4;
    case 0x802DFCF8u: goto label_802DFCF8;
    case 0x802DFCFCu: goto label_802DFCFC;
    case 0x802DFD00u: goto label_802DFD00;
    case 0x802DFD04u: goto label_802DFD04;
    case 0x802DFD08u: goto label_802DFD08;
    case 0x802DFD0Cu: goto label_802DFD0C;
    case 0x802DFD10u: goto label_802DFD10;
    case 0x802DFD14u: goto label_802DFD14;
    case 0x802DFD18u: goto label_802DFD18;
    case 0x802DFD1Cu: goto label_802DFD1C;
    case 0x802DFD20u: goto label_802DFD20;
    case 0x802DFD24u: goto label_802DFD24;
    case 0x802DFD28u: goto label_802DFD28;
    case 0x802DFD2Cu: goto label_802DFD2C;
    case 0x802DFD30u: goto label_802DFD30;
    case 0x802DFD34u: goto label_802DFD34;
    case 0x802DFD38u: goto label_802DFD38;
    case 0x802DFD3Cu: goto label_802DFD3C;
    case 0x802DFD40u: goto label_802DFD40;
    case 0x802DFD44u: goto label_802DFD44;
    case 0x802DFD48u: goto label_802DFD48;
    case 0x802DFD4Cu: goto label_802DFD4C;
    case 0x802DFD50u: goto label_802DFD50;
    case 0x802DFD54u: goto label_802DFD54;
    case 0x802DFD58u: goto label_802DFD58;
    case 0x802DFD5Cu: goto label_802DFD5C;
    case 0x802DFD60u: goto label_802DFD60;
    case 0x802DFD64u: goto label_802DFD64;
    case 0x802DFD68u: goto label_802DFD68;
    case 0x802DFD6Cu: goto label_802DFD6C;
    case 0x802DFD70u: goto label_802DFD70;
    case 0x802DFD74u: goto label_802DFD74;
    case 0x802DFD78u: goto label_802DFD78;
    case 0x802DFD7Cu: goto label_802DFD7C;
    case 0x802DFD80u: goto label_802DFD80;
    case 0x802DFD84u: goto label_802DFD84;
    case 0x802DFD88u: goto label_802DFD88;
    case 0x802DFD8Cu: goto label_802DFD8C;
    case 0x802DFD90u: goto label_802DFD90;
    case 0x802DFD94u: goto label_802DFD94;
    case 0x802DFD98u: goto label_802DFD98;
    case 0x802DFD9Cu: goto label_802DFD9C;
    case 0x802DFDA0u: goto label_802DFDA0;
    case 0x802DFDA4u: goto label_802DFDA4;
    case 0x802DFDA8u: goto label_802DFDA8;
    case 0x802DFDACu: goto label_802DFDAC;
    case 0x802DFDB0u: goto label_802DFDB0;
    case 0x802DFDB4u: goto label_802DFDB4;
    case 0x802DFDB8u: goto label_802DFDB8;
    case 0x802DFDBCu: goto label_802DFDBC;
    case 0x802DFDC0u: goto label_802DFDC0;
    case 0x802DFDC4u: goto label_802DFDC4;
    case 0x802DFDC8u: goto label_802DFDC8;
    case 0x802DFDCCu: goto label_802DFDCC;
    case 0x802DFDD0u: goto label_802DFDD0;
    case 0x802DFDD4u: goto label_802DFDD4;
    case 0x802DFDD8u: goto label_802DFDD8;
    case 0x802DFDDCu: goto label_802DFDDC;
    case 0x802DFDE0u: goto label_802DFDE0;
    case 0x802DFDE4u: goto label_802DFDE4;
    case 0x802DFDE8u: goto label_802DFDE8;
    case 0x802DFDECu: goto label_802DFDEC;
    case 0x802DFDF0u: goto label_802DFDF0;
    case 0x802DFDF4u: goto label_802DFDF4;
    case 0x802DFDF8u: goto label_802DFDF8;
    case 0x802DFDFCu: goto label_802DFDFC;
    case 0x802DFE00u: goto label_802DFE00;
    case 0x802DFE04u: goto label_802DFE04;
    case 0x802DFE08u: goto label_802DFE08;
    case 0x802DFE0Cu: goto label_802DFE0C;
    case 0x802DFE10u: goto label_802DFE10;
    case 0x802DFE14u: goto label_802DFE14;
    case 0x802DFE18u: goto label_802DFE18;
    case 0x802DFE1Cu: goto label_802DFE1C;
    case 0x802DFE20u: goto label_802DFE20;
    case 0x802DFE24u: goto label_802DFE24;
    case 0x802DFE28u: goto label_802DFE28;
    case 0x802DFE2Cu: goto label_802DFE2C;
    case 0x802DFE30u: goto label_802DFE30;
    case 0x802DFE34u: goto label_802DFE34;
    case 0x802DFE38u: goto label_802DFE38;
    case 0x802DFE3Cu: goto label_802DFE3C;
    case 0x802DFE40u: goto label_802DFE40;
    case 0x802DFE44u: goto label_802DFE44;
    case 0x802DFE48u: goto label_802DFE48;
    case 0x802DFE4Cu: goto label_802DFE4C;
    case 0x802DFE50u: goto label_802DFE50;
    case 0x802DFE54u: goto label_802DFE54;
    case 0x802DFE58u: goto label_802DFE58;
    case 0x802DFE5Cu: goto label_802DFE5C;
    case 0x802DFE60u: goto label_802DFE60;
    case 0x802DFE64u: goto label_802DFE64;
    case 0x802DFE68u: goto label_802DFE68;
    case 0x802DFE6Cu: goto label_802DFE6C;
    case 0x802DFE70u: goto label_802DFE70;
    case 0x802DFE74u: goto label_802DFE74;
    case 0x802DFE78u: goto label_802DFE78;
    case 0x802DFE7Cu: goto label_802DFE7C;
    case 0x802DFE80u: goto label_802DFE80;
    case 0x802DFE84u: goto label_802DFE84;
    case 0x802DFE88u: goto label_802DFE88;
    case 0x802DFE8Cu: goto label_802DFE8C;
    case 0x802DFE90u: goto label_802DFE90;
    case 0x802DFE94u: goto label_802DFE94;
    case 0x802DFE98u: goto label_802DFE98;
    case 0x802DFE9Cu: goto label_802DFE9C;
    case 0x802DFEA0u: goto label_802DFEA0;
    case 0x802DFEA4u: goto label_802DFEA4;
    case 0x802DFEA8u: goto label_802DFEA8;
    case 0x802DFEACu: goto label_802DFEAC;
    case 0x802DFEB0u: goto label_802DFEB0;
    case 0x802DFEB4u: goto label_802DFEB4;
    case 0x802DFEB8u: goto label_802DFEB8;
    case 0x802DFEBCu: goto label_802DFEBC;
    case 0x802DFEC0u: goto label_802DFEC0;
    case 0x802DFEC4u: goto label_802DFEC4;
    case 0x802DFEC8u: goto label_802DFEC8;
    case 0x802DFECCu: goto label_802DFECC;
    case 0x802DFED0u: goto label_802DFED0;
    case 0x802DFED4u: goto label_802DFED4;
    case 0x802DFED8u: goto label_802DFED8;
    case 0x802DFEDCu: goto label_802DFEDC;
    case 0x802DFEE0u: goto label_802DFEE0;
    case 0x802DFEE4u: goto label_802DFEE4;
    case 0x802DFEE8u: goto label_802DFEE8;
    case 0x802DFEECu: goto label_802DFEEC;
    case 0x802DFEF0u: goto label_802DFEF0;
    case 0x802DFEF4u: goto label_802DFEF4;
    case 0x802DFEF8u: goto label_802DFEF8;
    case 0x802DFEFCu: goto label_802DFEFC;
    case 0x802DFF00u: goto label_802DFF00;
    case 0x802DFF04u: goto label_802DFF04;
    case 0x802DFF08u: goto label_802DFF08;
    case 0x802DFF0Cu: goto label_802DFF0C;
    case 0x802DFF10u: goto label_802DFF10;
    case 0x802DFF14u: goto label_802DFF14;
    case 0x802DFF18u: goto label_802DFF18;
    case 0x802DFF1Cu: goto label_802DFF1C;
    case 0x802DFF20u: goto label_802DFF20;
    case 0x802DFF24u: goto label_802DFF24;
    case 0x802DFF28u: goto label_802DFF28;
    case 0x802DFF2Cu: goto label_802DFF2C;
    case 0x802DFF30u: goto label_802DFF30;
    case 0x802DFF34u: goto label_802DFF34;
    case 0x802DFF38u: goto label_802DFF38;
    case 0x802DFF3Cu: goto label_802DFF3C;
    case 0x802DFF40u: goto label_802DFF40;
    case 0x802DFF44u: goto label_802DFF44;
    case 0x802DFF48u: goto label_802DFF48;
    case 0x802DFF4Cu: goto label_802DFF4C;
    case 0x802DFF50u: goto label_802DFF50;
    case 0x802DFF54u: goto label_802DFF54;
    case 0x802DFF58u: goto label_802DFF58;
    case 0x802DFF5Cu: goto label_802DFF5C;
    case 0x802DFF60u: goto label_802DFF60;
    case 0x802DFF64u: goto label_802DFF64;
    case 0x802DFF68u: goto label_802DFF68;
    case 0x802DFF6Cu: goto label_802DFF6C;
    case 0x802DFF70u: goto label_802DFF70;
    case 0x802DFF74u: goto label_802DFF74;
    case 0x802DFF78u: goto label_802DFF78;
    case 0x802DFF7Cu: goto label_802DFF7C;
    case 0x802DFF80u: goto label_802DFF80;
    case 0x802DFF84u: goto label_802DFF84;
    case 0x802DFF88u: goto label_802DFF88;
    case 0x802DFF8Cu: goto label_802DFF8C;
    case 0x802DFF90u: goto label_802DFF90;
    case 0x802DFF94u: goto label_802DFF94;
    case 0x802DFF98u: goto label_802DFF98;
    case 0x802DFF9Cu: goto label_802DFF9C;
    case 0x802DFFA0u: goto label_802DFFA0;
    case 0x802DFFA4u: goto label_802DFFA4;
    case 0x802DFFA8u: goto label_802DFFA8;
    case 0x802DFFACu: goto label_802DFFAC;
    case 0x802DFFB0u: goto label_802DFFB0;
    case 0x802DFFB4u: goto label_802DFFB4;
    case 0x802DFFB8u: goto label_802DFFB8;
    case 0x802DFFBCu: goto label_802DFFBC;
    case 0x802DFFC0u: goto label_802DFFC0;
    case 0x802DFFC4u: goto label_802DFFC4;
    case 0x802DFFC8u: goto label_802DFFC8;
    case 0x802DFFCCu: goto label_802DFFCC;
    case 0x802DFFD0u: goto label_802DFFD0;
    case 0x802DFFD4u: goto label_802DFFD4;
    case 0x802DFFD8u: goto label_802DFFD8;
    case 0x802DFFDCu: goto label_802DFFDC;
    case 0x802DFFE0u: goto label_802DFFE0;
    case 0x802DFFE4u: goto label_802DFFE4;
    case 0x802DFFE8u: goto label_802DFFE8;
    case 0x802DFFECu: goto label_802DFFEC;
    case 0x802DFFF0u: goto label_802DFFF0;
    case 0x802DFFF4u: goto label_802DFFF4;
    case 0x802DFFF8u: goto label_802DFFF8;
    case 0x802DFFFCu: goto label_802DFFFC;
    case 0x802E0000u: goto label_802E0000;
    case 0x802E0004u: goto label_802E0004;
    case 0x802E0008u: goto label_802E0008;
    case 0x802E000Cu: goto label_802E000C;
    case 0x802E0010u: goto label_802E0010;
    case 0x802E0014u: goto label_802E0014;
    case 0x802E0018u: goto label_802E0018;
    case 0x802E001Cu: goto label_802E001C;
    case 0x802E0020u: goto label_802E0020;
    case 0x802E0024u: goto label_802E0024;
    case 0x802E0028u: goto label_802E0028;
    case 0x802E002Cu: goto label_802E002C;
    case 0x802E0030u: goto label_802E0030;
    case 0x802E0034u: goto label_802E0034;
    case 0x802E0038u: goto label_802E0038;
    case 0x802E003Cu: goto label_802E003C;
    case 0x802E0040u: goto label_802E0040;
    case 0x802E0044u: goto label_802E0044;
    case 0x802E0048u: goto label_802E0048;
    case 0x802E004Cu: goto label_802E004C;
    case 0x802E0050u: goto label_802E0050;
    case 0x802E0054u: goto label_802E0054;
    case 0x802E0058u: goto label_802E0058;
    case 0x802E005Cu: goto label_802E005C;
    case 0x802E0060u: goto label_802E0060;
    case 0x802E0064u: goto label_802E0064;
    case 0x802E0068u: goto label_802E0068;
    case 0x802E006Cu: goto label_802E006C;
    case 0x802E0070u: goto label_802E0070;
    case 0x802E0074u: goto label_802E0074;
    case 0x802E0078u: goto label_802E0078;
    case 0x802E007Cu: goto label_802E007C;
    case 0x802E0080u: goto label_802E0080;
    case 0x802E0084u: goto label_802E0084;
    case 0x802E0088u: goto label_802E0088;
    case 0x802E008Cu: goto label_802E008C;
    case 0x802E0090u: goto label_802E0090;
    case 0x802E0094u: goto label_802E0094;
    case 0x802E0098u: goto label_802E0098;
    case 0x802E009Cu: goto label_802E009C;
    case 0x802E00A0u: goto label_802E00A0;
    case 0x802E00A4u: goto label_802E00A4;
    case 0x802E00A8u: goto label_802E00A8;
    case 0x802E00ACu: goto label_802E00AC;
    case 0x802E00B0u: goto label_802E00B0;
    case 0x802E00B4u: goto label_802E00B4;
    case 0x802E00B8u: goto label_802E00B8;
    case 0x802E00BCu: goto label_802E00BC;
    case 0x802E00C0u: goto label_802E00C0;
    case 0x802E00C4u: goto label_802E00C4;
    case 0x802E00C8u: goto label_802E00C8;
    case 0x802E00CCu: goto label_802E00CC;
    case 0x802E00D0u: goto label_802E00D0;
    case 0x802E00D4u: goto label_802E00D4;
    case 0x802E00D8u: goto label_802E00D8;
    case 0x802E00DCu: goto label_802E00DC;
    case 0x802E00E0u: goto label_802E00E0;
    case 0x802E00E4u: goto label_802E00E4;
    case 0x802E00E8u: goto label_802E00E8;
    case 0x802E00ECu: goto label_802E00EC;
    case 0x802E00F0u: goto label_802E00F0;
    case 0x802E00F4u: goto label_802E00F4;
    case 0x802E00F8u: goto label_802E00F8;
    case 0x802E00FCu: goto label_802E00FC;
    case 0x802E0100u: goto label_802E0100;
    case 0x802E0104u: goto label_802E0104;
    case 0x802E0108u: goto label_802E0108;
    case 0x802E010Cu: goto label_802E010C;
    case 0x802E0110u: goto label_802E0110;
    case 0x802E0114u: goto label_802E0114;
    case 0x802E0118u: goto label_802E0118;
    case 0x802E011Cu: goto label_802E011C;
    case 0x802E0120u: goto label_802E0120;
    case 0x802E0124u: goto label_802E0124;
    case 0x802E0128u: goto label_802E0128;
    case 0x802E012Cu: goto label_802E012C;
    case 0x802E0130u: goto label_802E0130;
    case 0x802E0134u: goto label_802E0134;
    case 0x802E0138u: goto label_802E0138;
    case 0x802E013Cu: goto label_802E013C;
    case 0x802E0140u: goto label_802E0140;
    case 0x802E0144u: goto label_802E0144;
    case 0x802E0148u: goto label_802E0148;
    case 0x802E014Cu: goto label_802E014C;
    case 0x802E0150u: goto label_802E0150;
    case 0x802E0154u: goto label_802E0154;
    case 0x802E0158u: goto label_802E0158;
    case 0x802E015Cu: goto label_802E015C;
    case 0x802E0160u: goto label_802E0160;
    case 0x802E0164u: goto label_802E0164;
    case 0x802E0168u: goto label_802E0168;
    case 0x802E016Cu: goto label_802E016C;
    case 0x802E0170u: goto label_802E0170;
    case 0x802E0174u: goto label_802E0174;
    case 0x802E0178u: goto label_802E0178;
    case 0x802E017Cu: goto label_802E017C;
    case 0x802E0180u: goto label_802E0180;
    case 0x802E0184u: goto label_802E0184;
    case 0x802E0188u: goto label_802E0188;
    case 0x802E018Cu: goto label_802E018C;
    case 0x802E0190u: goto label_802E0190;
    case 0x802E0194u: goto label_802E0194;
    case 0x802E0198u: goto label_802E0198;
    case 0x802E019Cu: goto label_802E019C;
    case 0x802E01A0u: goto label_802E01A0;
    case 0x802E01A4u: goto label_802E01A4;
    case 0x802E01A8u: goto label_802E01A8;
    case 0x802E01ACu: goto label_802E01AC;
    case 0x802E01B0u: goto label_802E01B0;
    case 0x802E01B4u: goto label_802E01B4;
    case 0x802E01B8u: goto label_802E01B8;
    case 0x802E01BCu: goto label_802E01BC;
    case 0x802E01C0u: goto label_802E01C0;
    case 0x802E01C4u: goto label_802E01C4;
    case 0x802E01C8u: goto label_802E01C8;
    case 0x802E01CCu: goto label_802E01CC;
    case 0x802E01D0u: goto label_802E01D0;
    case 0x802E01D4u: goto label_802E01D4;
    case 0x802E01D8u: goto label_802E01D8;
    case 0x802E01DCu: goto label_802E01DC;
    case 0x802E01E0u: goto label_802E01E0;
    case 0x802E01E4u: goto label_802E01E4;
    case 0x802E01E8u: goto label_802E01E8;
    case 0x802E01ECu: goto label_802E01EC;
    case 0x802E01F0u: goto label_802E01F0;
    case 0x802E01F4u: goto label_802E01F4;
    case 0x802E01F8u: goto label_802E01F8;
    case 0x802E01FCu: goto label_802E01FC;
    case 0x802E0200u: goto label_802E0200;
    case 0x802E0204u: goto label_802E0204;
    case 0x802E0208u: goto label_802E0208;
    case 0x802E020Cu: goto label_802E020C;
    case 0x802E0210u: goto label_802E0210;
    case 0x802E0214u: goto label_802E0214;
    case 0x802E0218u: goto label_802E0218;
    case 0x802E021Cu: goto label_802E021C;
    case 0x802E0220u: goto label_802E0220;
    case 0x802E0224u: goto label_802E0224;
    case 0x802E0228u: goto label_802E0228;
    case 0x802E022Cu: goto label_802E022C;
    case 0x802E0230u: goto label_802E0230;
    case 0x802E0234u: goto label_802E0234;
    case 0x802E0238u: goto label_802E0238;
    case 0x802E023Cu: goto label_802E023C;
    case 0x802E0240u: goto label_802E0240;
    case 0x802E0244u: goto label_802E0244;
    case 0x802E0248u: goto label_802E0248;
    case 0x802E024Cu: goto label_802E024C;
    case 0x802E0250u: goto label_802E0250;
    case 0x802E0254u: goto label_802E0254;
    case 0x802E0258u: goto label_802E0258;
    case 0x802E025Cu: goto label_802E025C;
    case 0x802E0260u: goto label_802E0260;
    case 0x802E0264u: goto label_802E0264;
    case 0x802E0268u: goto label_802E0268;
    case 0x802E026Cu: goto label_802E026C;
    case 0x802E0270u: goto label_802E0270;
    case 0x802E0274u: goto label_802E0274;
    case 0x802E0278u: goto label_802E0278;
    case 0x802E027Cu: goto label_802E027C;
    case 0x802E0280u: goto label_802E0280;
    case 0x802E0284u: goto label_802E0284;
    case 0x802E0288u: goto label_802E0288;
    case 0x802E028Cu: goto label_802E028C;
    case 0x802E0290u: goto label_802E0290;
    case 0x802E0294u: goto label_802E0294;
    case 0x802E0298u: goto label_802E0298;
    case 0x802E029Cu: goto label_802E029C;
    case 0x802E02A0u: goto label_802E02A0;
    case 0x802E02A4u: goto label_802E02A4;
    case 0x802E02A8u: goto label_802E02A8;
    case 0x802E02ACu: goto label_802E02AC;
    case 0x802E02B0u: goto label_802E02B0;
    case 0x802E02B4u: goto label_802E02B4;
    case 0x802E02B8u: goto label_802E02B8;
    case 0x802E02BCu: goto label_802E02BC;
    case 0x802E02C0u: goto label_802E02C0;
    case 0x802E02C4u: goto label_802E02C4;
    case 0x802E02C8u: goto label_802E02C8;
    case 0x802E02CCu: goto label_802E02CC;
    case 0x802E02D0u: goto label_802E02D0;
    case 0x802E02D4u: goto label_802E02D4;
    case 0x802E02D8u: goto label_802E02D8;
    case 0x802E02DCu: goto label_802E02DC;
    case 0x802E02E0u: goto label_802E02E0;
    case 0x802E02E4u: goto label_802E02E4;
    case 0x802E02E8u: goto label_802E02E8;
    case 0x802E02ECu: goto label_802E02EC;
    case 0x802E02F0u: goto label_802E02F0;
    case 0x802E02F4u: goto label_802E02F4;
    case 0x802E02F8u: goto label_802E02F8;
    case 0x802E02FCu: goto label_802E02FC;
    case 0x802E0300u: goto label_802E0300;
    case 0x802E0304u: goto label_802E0304;
    case 0x802E0308u: goto label_802E0308;
    case 0x802E030Cu: goto label_802E030C;
    case 0x802E0310u: goto label_802E0310;
    case 0x802E0314u: goto label_802E0314;
    case 0x802E0318u: goto label_802E0318;
    case 0x802E031Cu: goto label_802E031C;
    case 0x802E0320u: goto label_802E0320;
    case 0x802E0324u: goto label_802E0324;
    case 0x802E0328u: goto label_802E0328;
    case 0x802E032Cu: goto label_802E032C;
    case 0x802E0330u: goto label_802E0330;
    case 0x802E0334u: goto label_802E0334;
    case 0x802E0338u: goto label_802E0338;
    case 0x802E033Cu: goto label_802E033C;
    case 0x802E0340u: goto label_802E0340;
    case 0x802E0344u: goto label_802E0344;
    case 0x802E0348u: goto label_802E0348;
    case 0x802E034Cu: goto label_802E034C;
    case 0x802E0350u: goto label_802E0350;
    case 0x802E0354u: goto label_802E0354;
    case 0x802E0358u: goto label_802E0358;
    case 0x802E035Cu: goto label_802E035C;
    case 0x802E0360u: goto label_802E0360;
    case 0x802E0364u: goto label_802E0364;
    case 0x802E0368u: goto label_802E0368;
    case 0x802E036Cu: goto label_802E036C;
    case 0x802E0370u: goto label_802E0370;
    case 0x802E0374u: goto label_802E0374;
    case 0x802E0378u: goto label_802E0378;
    case 0x802E037Cu: goto label_802E037C;
    case 0x802E0380u: goto label_802E0380;
    case 0x802E0384u: goto label_802E0384;
    case 0x802E0388u: goto label_802E0388;
    case 0x802E038Cu: goto label_802E038C;
    case 0x802E0390u: goto label_802E0390;
    case 0x802E0394u: goto label_802E0394;
    case 0x802E0398u: goto label_802E0398;
    case 0x802E039Cu: goto label_802E039C;
    case 0x802E03A0u: goto label_802E03A0;
    case 0x802E03A4u: goto label_802E03A4;
    case 0x802E03A8u: goto label_802E03A8;
    case 0x802E03ACu: goto label_802E03AC;
    case 0x802E03B0u: goto label_802E03B0;
    case 0x802E03B4u: goto label_802E03B4;
    case 0x802E03B8u: goto label_802E03B8;
    case 0x802E03BCu: goto label_802E03BC;
    case 0x802E03C0u: goto label_802E03C0;
    case 0x802E03C4u: goto label_802E03C4;
    case 0x802E03C8u: goto label_802E03C8;
    case 0x802E03CCu: goto label_802E03CC;
    case 0x802E03D0u: goto label_802E03D0;
    case 0x802E03D4u: goto label_802E03D4;
    case 0x802E03D8u: goto label_802E03D8;
    case 0x802E03DCu: goto label_802E03DC;
    case 0x802E03E0u: goto label_802E03E0;
    case 0x802E03E4u: goto label_802E03E4;
    case 0x802E03E8u: goto label_802E03E8;
    case 0x802E03ECu: goto label_802E03EC;
    case 0x802E03F0u: goto label_802E03F0;
    case 0x802E03F4u: goto label_802E03F4;
    case 0x802E03F8u: goto label_802E03F8;
    case 0x802E03FCu: goto label_802E03FC;
    case 0x802E0400u: goto label_802E0400;
    case 0x802E0404u: goto label_802E0404;
    case 0x802E0408u: goto label_802E0408;
    case 0x802E040Cu: goto label_802E040C;
    case 0x802E0410u: goto label_802E0410;
    case 0x802E0414u: goto label_802E0414;
    case 0x802E0418u: goto label_802E0418;
    case 0x802E041Cu: goto label_802E041C;
    case 0x802E0420u: goto label_802E0420;
    case 0x802E0424u: goto label_802E0424;
    case 0x802E0428u: goto label_802E0428;
    case 0x802E042Cu: goto label_802E042C;
    case 0x802E0430u: goto label_802E0430;
    case 0x802E0434u: goto label_802E0434;
    case 0x802E0438u: goto label_802E0438;
    case 0x802E043Cu: goto label_802E043C;
    case 0x802E0440u: goto label_802E0440;
    case 0x802E0444u: goto label_802E0444;
    case 0x802E0448u: goto label_802E0448;
    case 0x802E044Cu: goto label_802E044C;
    case 0x802E0450u: goto label_802E0450;
    case 0x802E0454u: goto label_802E0454;
    case 0x802E0458u: goto label_802E0458;
    case 0x802E045Cu: goto label_802E045C;
    case 0x802E0460u: goto label_802E0460;
    case 0x802E0464u: goto label_802E0464;
    case 0x802E0468u: goto label_802E0468;
    case 0x802E046Cu: goto label_802E046C;
    case 0x802E0470u: goto label_802E0470;
    case 0x802E0474u: goto label_802E0474;
    case 0x802E0478u: goto label_802E0478;
    case 0x802E047Cu: goto label_802E047C;
    case 0x802E0480u: goto label_802E0480;
    case 0x802E0484u: goto label_802E0484;
    case 0x802E0488u: goto label_802E0488;
    case 0x802E048Cu: goto label_802E048C;
    case 0x802E0490u: goto label_802E0490;
    case 0x802E0494u: goto label_802E0494;
    case 0x802E0498u: goto label_802E0498;
    case 0x802E049Cu: goto label_802E049C;
    case 0x802E04A0u: goto label_802E04A0;
    case 0x802E04A4u: goto label_802E04A4;
    case 0x802E04A8u: goto label_802E04A8;
    case 0x802E04ACu: goto label_802E04AC;
    case 0x802E04B0u: goto label_802E04B0;
    case 0x802E04B4u: goto label_802E04B4;
    case 0x802E04B8u: goto label_802E04B8;
    case 0x802E04BCu: goto label_802E04BC;
    case 0x802E04C0u: goto label_802E04C0;
    case 0x802E04C4u: goto label_802E04C4;
    case 0x802E04C8u: goto label_802E04C8;
    case 0x802E04CCu: goto label_802E04CC;
    case 0x802E04D0u: goto label_802E04D0;
    case 0x802E04D4u: goto label_802E04D4;
    case 0x802E04D8u: goto label_802E04D8;
    case 0x802E04DCu: goto label_802E04DC;
    case 0x802E04E0u: goto label_802E04E0;
    case 0x802E04E4u: goto label_802E04E4;
    case 0x802E04E8u: goto label_802E04E8;
    case 0x802E04ECu: goto label_802E04EC;
    case 0x802E04F0u: goto label_802E04F0;
    case 0x802E04F4u: goto label_802E04F4;
    case 0x802E04F8u: goto label_802E04F8;
    case 0x802E04FCu: goto label_802E04FC;
    case 0x802E0500u: goto label_802E0500;
    case 0x802E0504u: goto label_802E0504;
    case 0x802E0508u: goto label_802E0508;
    case 0x802E050Cu: goto label_802E050C;
    case 0x802E0510u: goto label_802E0510;
    case 0x802E0514u: goto label_802E0514;
    case 0x802E0518u: goto label_802E0518;
    case 0x802E051Cu: goto label_802E051C;
    case 0x802E0520u: goto label_802E0520;
    case 0x802E0524u: goto label_802E0524;
    case 0x802E0528u: goto label_802E0528;
    case 0x802E052Cu: goto label_802E052C;
    case 0x802E0530u: goto label_802E0530;
    case 0x802E0534u: goto label_802E0534;
    case 0x802E0538u: goto label_802E0538;
    case 0x802E053Cu: goto label_802E053C;
    case 0x802E0540u: goto label_802E0540;
    case 0x802E0544u: goto label_802E0544;
    case 0x802E0548u: goto label_802E0548;
    case 0x802E054Cu: goto label_802E054C;
    case 0x802E0550u: goto label_802E0550;
    case 0x802E0554u: goto label_802E0554;
    case 0x802E0558u: goto label_802E0558;
    case 0x802E055Cu: goto label_802E055C;
    case 0x802E0560u: goto label_802E0560;
    case 0x802E0564u: goto label_802E0564;
    case 0x802E0568u: goto label_802E0568;
    case 0x802E056Cu: goto label_802E056C;
    case 0x802E0570u: goto label_802E0570;
    case 0x802E0574u: goto label_802E0574;
    case 0x802E0578u: goto label_802E0578;
    case 0x802E057Cu: goto label_802E057C;
    case 0x802E0580u: goto label_802E0580;
    case 0x802E0584u: goto label_802E0584;
    case 0x802E0588u: goto label_802E0588;
    case 0x802E058Cu: goto label_802E058C;
    case 0x802E0590u: goto label_802E0590;
    case 0x802E0594u: goto label_802E0594;
    case 0x802E0598u: goto label_802E0598;
    case 0x802E059Cu: goto label_802E059C;
    case 0x802E05A0u: goto label_802E05A0;
    case 0x802E05A4u: goto label_802E05A4;
    case 0x802E05A8u: goto label_802E05A8;
    case 0x802E05ACu: goto label_802E05AC;
    case 0x802E05B0u: goto label_802E05B0;
    case 0x802E05B4u: goto label_802E05B4;
    case 0x802E05B8u: goto label_802E05B8;
    case 0x802E05BCu: goto label_802E05BC;
    case 0x802E05C0u: goto label_802E05C0;
    case 0x802E05C4u: goto label_802E05C4;
    case 0x802E05C8u: goto label_802E05C8;
    case 0x802E05CCu: goto label_802E05CC;
    case 0x802E05D0u: goto label_802E05D0;
    case 0x802E05D4u: goto label_802E05D4;
    case 0x802E05D8u: goto label_802E05D8;
    case 0x802E05DCu: goto label_802E05DC;
    case 0x802E05E0u: goto label_802E05E0;
    case 0x802E05E4u: goto label_802E05E4;
    case 0x802E05E8u: goto label_802E05E8;
    case 0x802E05ECu: goto label_802E05EC;
    case 0x802E05F0u: goto label_802E05F0;
    case 0x802E05F4u: goto label_802E05F4;
    case 0x802E05F8u: goto label_802E05F8;
    case 0x802E05FCu: goto label_802E05FC;
    case 0x802E0600u: goto label_802E0600;
    case 0x802E0604u: goto label_802E0604;
    case 0x802E0608u: goto label_802E0608;
    case 0x802E060Cu: goto label_802E060C;
    case 0x802E0610u: goto label_802E0610;
    case 0x802E0614u: goto label_802E0614;
    case 0x802E0618u: goto label_802E0618;
    case 0x802E061Cu: goto label_802E061C;
    case 0x802E0620u: goto label_802E0620;
    case 0x802E0624u: goto label_802E0624;
    case 0x802E0628u: goto label_802E0628;
    case 0x802E062Cu: goto label_802E062C;
    case 0x802E0630u: goto label_802E0630;
    case 0x802E0634u: goto label_802E0634;
    case 0x802E0638u: goto label_802E0638;
    case 0x802E063Cu: goto label_802E063C;
    case 0x802E0640u: goto label_802E0640;
    case 0x802E0644u: goto label_802E0644;
    case 0x802E0648u: goto label_802E0648;
    case 0x802E064Cu: goto label_802E064C;
    case 0x802E0650u: goto label_802E0650;
    case 0x802E0654u: goto label_802E0654;
    case 0x802E0658u: goto label_802E0658;
    case 0x802E065Cu: goto label_802E065C;
    case 0x802E0660u: goto label_802E0660;
    case 0x802E0664u: goto label_802E0664;
    case 0x802E0668u: goto label_802E0668;
    case 0x802E066Cu: goto label_802E066C;
    case 0x802E0670u: goto label_802E0670;
    case 0x802E0674u: goto label_802E0674;
    case 0x802E0678u: goto label_802E0678;
    case 0x802E067Cu: goto label_802E067C;
    case 0x802E0680u: goto label_802E0680;
    case 0x802E0684u: goto label_802E0684;
    case 0x802E0688u: goto label_802E0688;
    case 0x802E068Cu: goto label_802E068C;
    case 0x802E0690u: goto label_802E0690;
    case 0x802E0694u: goto label_802E0694;
    case 0x802E0698u: goto label_802E0698;
    case 0x802E069Cu: goto label_802E069C;
    case 0x802E06A0u: goto label_802E06A0;
    case 0x802E06A4u: goto label_802E06A4;
    case 0x802E06A8u: goto label_802E06A8;
    case 0x802E06ACu: goto label_802E06AC;
    case 0x802E06B0u: goto label_802E06B0;
    case 0x802E06B4u: goto label_802E06B4;
    case 0x802E06B8u: goto label_802E06B8;
    case 0x802E06BCu: goto label_802E06BC;
    case 0x802E06C0u: goto label_802E06C0;
    case 0x802E06C4u: goto label_802E06C4;
    case 0x802E06C8u: goto label_802E06C8;
    case 0x802E06CCu: goto label_802E06CC;
    case 0x802E06D0u: goto label_802E06D0;
    case 0x802E06D4u: goto label_802E06D4;
    case 0x802E06D8u: goto label_802E06D8;
    case 0x802E06DCu: goto label_802E06DC;
    case 0x802E06E0u: goto label_802E06E0;
    case 0x802E06E4u: goto label_802E06E4;
    case 0x802E06E8u: goto label_802E06E8;
    case 0x802E06ECu: goto label_802E06EC;
    case 0x802E06F0u: goto label_802E06F0;
    case 0x802E06F4u: goto label_802E06F4;
    case 0x802E06F8u: goto label_802E06F8;
    case 0x802E06FCu: goto label_802E06FC;
    case 0x802E0700u: goto label_802E0700;
    case 0x802E0704u: goto label_802E0704;
    case 0x802E0708u: goto label_802E0708;
    case 0x802E070Cu: goto label_802E070C;
    case 0x802E0710u: goto label_802E0710;
    case 0x802E0714u: goto label_802E0714;
    case 0x802E0718u: goto label_802E0718;
    case 0x802E071Cu: goto label_802E071C;
    case 0x802E0720u: goto label_802E0720;
    case 0x802E0724u: goto label_802E0724;
    case 0x802E0728u: goto label_802E0728;
    case 0x802E072Cu: goto label_802E072C;
    case 0x802E0730u: goto label_802E0730;
    case 0x802E0734u: goto label_802E0734;
    case 0x802E0738u: goto label_802E0738;
    case 0x802E073Cu: goto label_802E073C;
    case 0x802E0740u: goto label_802E0740;
    case 0x802E0744u: goto label_802E0744;
    case 0x802E0748u: goto label_802E0748;
    case 0x802E074Cu: goto label_802E074C;
    case 0x802E0750u: goto label_802E0750;
    case 0x802E0754u: goto label_802E0754;
    case 0x802E0758u: goto label_802E0758;
    case 0x802E075Cu: goto label_802E075C;
    case 0x802E0760u: goto label_802E0760;
    case 0x802E0764u: goto label_802E0764;
    case 0x802E0768u: goto label_802E0768;
    case 0x802E076Cu: goto label_802E076C;
    case 0x802E0770u: goto label_802E0770;
    case 0x802E0774u: goto label_802E0774;
    case 0x802E0778u: goto label_802E0778;
    case 0x802E077Cu: goto label_802E077C;
    case 0x802E0780u: goto label_802E0780;
    case 0x802E0784u: goto label_802E0784;
    case 0x802E0788u: goto label_802E0788;
    case 0x802E078Cu: goto label_802E078C;
    case 0x802E0790u: goto label_802E0790;
    case 0x802E0794u: goto label_802E0794;
    case 0x802E0798u: goto label_802E0798;
    case 0x802E079Cu: goto label_802E079C;
    case 0x802E07A0u: goto label_802E07A0;
    case 0x802E07A4u: goto label_802E07A4;
    case 0x802E07A8u: goto label_802E07A8;
    case 0x802E07ACu: goto label_802E07AC;
    case 0x802E07B0u: goto label_802E07B0;
    case 0x802E07B4u: goto label_802E07B4;
    case 0x802E07B8u: goto label_802E07B8;
    case 0x802E07BCu: goto label_802E07BC;
    case 0x802E07C0u: goto label_802E07C0;
    case 0x802E07C4u: goto label_802E07C4;
    case 0x802E07C8u: goto label_802E07C8;
    case 0x802E07CCu: goto label_802E07CC;
    case 0x802E07D0u: goto label_802E07D0;
    case 0x802E07D4u: goto label_802E07D4;
    case 0x802E07D8u: goto label_802E07D8;
    case 0x802E07DCu: goto label_802E07DC;
    case 0x802E07E0u: goto label_802E07E0;
    case 0x802E07E4u: goto label_802E07E4;
    case 0x802E07E8u: goto label_802E07E8;
    case 0x802E07ECu: goto label_802E07EC;
    case 0x802E07F0u: goto label_802E07F0;
    case 0x802E07F4u: goto label_802E07F4;
    case 0x802E07F8u: goto label_802E07F8;
    case 0x802E07FCu: goto label_802E07FC;
    case 0x802E0800u: goto label_802E0800;
    case 0x802E0804u: goto label_802E0804;
    case 0x802E0808u: goto label_802E0808;
    case 0x802E080Cu: goto label_802E080C;
    case 0x802E0810u: goto label_802E0810;
    case 0x802E0814u: goto label_802E0814;
    case 0x802E0818u: goto label_802E0818;
    case 0x802E081Cu: goto label_802E081C;
    case 0x802E0820u: goto label_802E0820;
    case 0x802E0824u: goto label_802E0824;
    case 0x802E0828u: goto label_802E0828;
    case 0x802E082Cu: goto label_802E082C;
    case 0x802E0830u: goto label_802E0830;
    case 0x802E0834u: goto label_802E0834;
    case 0x802E0838u: goto label_802E0838;
    case 0x802E083Cu: goto label_802E083C;
    case 0x802E0840u: goto label_802E0840;
    case 0x802E0844u: goto label_802E0844;
    case 0x802E0848u: goto label_802E0848;
    case 0x802E084Cu: goto label_802E084C;
    case 0x802E0850u: goto label_802E0850;
    case 0x802E0854u: goto label_802E0854;
    case 0x802E0858u: goto label_802E0858;
    case 0x802E085Cu: goto label_802E085C;
    case 0x802E0860u: goto label_802E0860;
    case 0x802E0864u: goto label_802E0864;
    case 0x802E0868u: goto label_802E0868;
    case 0x802E086Cu: goto label_802E086C;
    case 0x802E0870u: goto label_802E0870;
    case 0x802E0874u: goto label_802E0874;
    case 0x802E0878u: goto label_802E0878;
    case 0x802E087Cu: goto label_802E087C;
    case 0x802E0880u: goto label_802E0880;
    case 0x802E0884u: goto label_802E0884;
    case 0x802E0888u: goto label_802E0888;
    case 0x802E088Cu: goto label_802E088C;
    case 0x802E0890u: goto label_802E0890;
    case 0x802E0894u: goto label_802E0894;
    case 0x802E0898u: goto label_802E0898;
    case 0x802E089Cu: goto label_802E089C;
    case 0x802E08A0u: goto label_802E08A0;
    case 0x802E08A4u: goto label_802E08A4;
    case 0x802E08A8u: goto label_802E08A8;
    case 0x802E08ACu: goto label_802E08AC;
    case 0x802E08B0u: goto label_802E08B0;
    case 0x802E08B4u: goto label_802E08B4;
    case 0x802E08B8u: goto label_802E08B8;
    case 0x802E08BCu: goto label_802E08BC;
    case 0x802E08C0u: goto label_802E08C0;
    case 0x802E08C4u: goto label_802E08C4;
    case 0x802E08C8u: goto label_802E08C8;
    case 0x802E08CCu: goto label_802E08CC;
    case 0x802E08D0u: goto label_802E08D0;
    case 0x802E08D4u: goto label_802E08D4;
    case 0x802E08D8u: goto label_802E08D8;
    case 0x802E08DCu: goto label_802E08DC;
    case 0x802E08E0u: goto label_802E08E0;
    case 0x802E08E4u: goto label_802E08E4;
    case 0x802E08E8u: goto label_802E08E8;
    case 0x802E08ECu: goto label_802E08EC;
    case 0x802E08F0u: goto label_802E08F0;
    case 0x802E08F4u: goto label_802E08F4;
    case 0x802E08F8u: goto label_802E08F8;
    case 0x802E08FCu: goto label_802E08FC;
    case 0x802E0900u: goto label_802E0900;
    case 0x802E0904u: goto label_802E0904;
    case 0x802E0908u: goto label_802E0908;
    case 0x802E090Cu: goto label_802E090C;
    case 0x802E0910u: goto label_802E0910;
    case 0x802E0914u: goto label_802E0914;
    case 0x802E0918u: goto label_802E0918;
    case 0x802E091Cu: goto label_802E091C;
    case 0x802E0920u: goto label_802E0920;
    case 0x802E0924u: goto label_802E0924;
    case 0x802E0928u: goto label_802E0928;
    case 0x802E092Cu: goto label_802E092C;
    case 0x802E0930u: goto label_802E0930;
    case 0x802E0934u: goto label_802E0934;
    case 0x802E0938u: goto label_802E0938;
    case 0x802E093Cu: goto label_802E093C;
    case 0x802E0940u: goto label_802E0940;
    case 0x802E0944u: goto label_802E0944;
    case 0x802E0948u: goto label_802E0948;
    case 0x802E094Cu: goto label_802E094C;
    case 0x802E0950u: goto label_802E0950;
    case 0x802E0954u: goto label_802E0954;
    case 0x802E0958u: goto label_802E0958;
    case 0x802E095Cu: goto label_802E095C;
    case 0x802E0960u: goto label_802E0960;
    case 0x802E0964u: goto label_802E0964;
    case 0x802E0968u: goto label_802E0968;
    case 0x802E096Cu: goto label_802E096C;
    case 0x802E0970u: goto label_802E0970;
    case 0x802E0974u: goto label_802E0974;
    case 0x802E0978u: goto label_802E0978;
    case 0x802E097Cu: goto label_802E097C;
    case 0x802E0980u: goto label_802E0980;
    case 0x802E0984u: goto label_802E0984;
    case 0x802E0988u: goto label_802E0988;
    case 0x802E098Cu: goto label_802E098C;
    case 0x802E0990u: goto label_802E0990;
    case 0x802E0994u: goto label_802E0994;
    case 0x802E0998u: goto label_802E0998;
    case 0x802E099Cu: goto label_802E099C;
    case 0x802E09A0u: goto label_802E09A0;
    case 0x802E09A4u: goto label_802E09A4;
    case 0x802E09A8u: goto label_802E09A8;
    case 0x802E09ACu: goto label_802E09AC;
    case 0x802E09B0u: goto label_802E09B0;
    case 0x802E09B4u: goto label_802E09B4;
    case 0x802E09B8u: goto label_802E09B8;
    case 0x802E09BCu: goto label_802E09BC;
    case 0x802E09C0u: goto label_802E09C0;
    case 0x802E09C4u: goto label_802E09C4;
    case 0x802E09C8u: goto label_802E09C8;
    case 0x802E09CCu: goto label_802E09CC;
    case 0x802E09D0u: goto label_802E09D0;
    case 0x802E09D4u: goto label_802E09D4;
    case 0x802E09D8u: goto label_802E09D8;
    case 0x802E09DCu: goto label_802E09DC;
    case 0x802E09E0u: goto label_802E09E0;
    case 0x802E09E4u: goto label_802E09E4;
    case 0x802E09E8u: goto label_802E09E8;
    case 0x802E09ECu: goto label_802E09EC;
    case 0x802E09F0u: goto label_802E09F0;
    case 0x802E09F4u: goto label_802E09F4;
    case 0x802E09F8u: goto label_802E09F8;
    case 0x802E09FCu: goto label_802E09FC;
    case 0x802E0A00u: goto label_802E0A00;
    case 0x802E0A04u: goto label_802E0A04;
    case 0x802E0A08u: goto label_802E0A08;
    case 0x802E0A0Cu: goto label_802E0A0C;
    case 0x802E0A10u: goto label_802E0A10;
    case 0x802E0A14u: goto label_802E0A14;
    case 0x802E0A18u: goto label_802E0A18;
    case 0x802E0A1Cu: goto label_802E0A1C;
    case 0x802E0A20u: goto label_802E0A20;
    case 0x802E0A24u: goto label_802E0A24;
    case 0x802E0A28u: goto label_802E0A28;
    case 0x802E0A2Cu: goto label_802E0A2C;
    case 0x802E0A30u: goto label_802E0A30;
    case 0x802E0A34u: goto label_802E0A34;
    case 0x802E0A38u: goto label_802E0A38;
    case 0x802E0A3Cu: goto label_802E0A3C;
    case 0x802E0A40u: goto label_802E0A40;
    case 0x802E0A44u: goto label_802E0A44;
    case 0x802E0A48u: goto label_802E0A48;
    case 0x802E0A4Cu: goto label_802E0A4C;
    case 0x802E0A50u: goto label_802E0A50;
    case 0x802E0A54u: goto label_802E0A54;
    case 0x802E0A58u: goto label_802E0A58;
    case 0x802E0A5Cu: goto label_802E0A5C;
    case 0x802E0A60u: goto label_802E0A60;
    case 0x802E0A64u: goto label_802E0A64;
    case 0x802E0A68u: goto label_802E0A68;
    case 0x802E0A6Cu: goto label_802E0A6C;
    case 0x802E0A70u: goto label_802E0A70;
    case 0x802E0A74u: goto label_802E0A74;
    case 0x802E0A78u: goto label_802E0A78;
    case 0x802E0A7Cu: goto label_802E0A7C;
    case 0x802E0A80u: goto label_802E0A80;
    case 0x802E0A84u: goto label_802E0A84;
    case 0x802E0A88u: goto label_802E0A88;
    case 0x802E0A8Cu: goto label_802E0A8C;
    case 0x802E0A90u: goto label_802E0A90;
    case 0x802E0A94u: goto label_802E0A94;
    case 0x802E0A98u: goto label_802E0A98;
    case 0x802E0A9Cu: goto label_802E0A9C;
    case 0x802E0AA0u: goto label_802E0AA0;
    case 0x802E0AA4u: goto label_802E0AA4;
    case 0x802E0AA8u: goto label_802E0AA8;
    case 0x802E0AACu: goto label_802E0AAC;
    case 0x802E0AB0u: goto label_802E0AB0;
    case 0x802E0AB4u: goto label_802E0AB4;
    case 0x802E0AB8u: goto label_802E0AB8;
    case 0x802E0ABCu: goto label_802E0ABC;
    case 0x802E0AC0u: goto label_802E0AC0;
    case 0x802E0AC4u: goto label_802E0AC4;
    case 0x802E0AC8u: goto label_802E0AC8;
    case 0x802E0ACCu: goto label_802E0ACC;
    case 0x802E0AD0u: goto label_802E0AD0;
    case 0x802E0AD4u: goto label_802E0AD4;
    case 0x802E0AD8u: goto label_802E0AD8;
    case 0x802E0ADCu: goto label_802E0ADC;
    case 0x802E0AE0u: goto label_802E0AE0;
    case 0x802E0AE4u: goto label_802E0AE4;
    case 0x802E0AE8u: goto label_802E0AE8;
    case 0x802E0AECu: goto label_802E0AEC;
    case 0x802E0AF0u: goto label_802E0AF0;
    case 0x802E0AF4u: goto label_802E0AF4;
    case 0x802E0AF8u: goto label_802E0AF8;
    case 0x802E0AFCu: goto label_802E0AFC;
    case 0x802E0B00u: goto label_802E0B00;
    case 0x802E0B04u: goto label_802E0B04;
    case 0x802E0B08u: goto label_802E0B08;
    case 0x802E0B0Cu: goto label_802E0B0C;
    case 0x802E0B10u: goto label_802E0B10;
    case 0x802E0B14u: goto label_802E0B14;
    case 0x802E0B18u: goto label_802E0B18;
    case 0x802E0B1Cu: goto label_802E0B1C;
    case 0x802E0B20u: goto label_802E0B20;
    case 0x802E0B24u: goto label_802E0B24;
    case 0x802E0B28u: goto label_802E0B28;
    case 0x802E0B2Cu: goto label_802E0B2C;
    case 0x802E0B30u: goto label_802E0B30;
    case 0x802E0B34u: goto label_802E0B34;
    case 0x802E0B38u: goto label_802E0B38;
    case 0x802E0B3Cu: goto label_802E0B3C;
    case 0x802E0B40u: goto label_802E0B40;
    case 0x802E0B44u: goto label_802E0B44;
    case 0x802E0B48u: goto label_802E0B48;
    case 0x802E0B4Cu: goto label_802E0B4C;
    case 0x802E0B50u: goto label_802E0B50;
    case 0x802E0B54u: goto label_802E0B54;
    case 0x802E0B58u: goto label_802E0B58;
    case 0x802E0B5Cu: goto label_802E0B5C;
    case 0x802E0B60u: goto label_802E0B60;
    case 0x802E0B64u: goto label_802E0B64;
    case 0x802E0B68u: goto label_802E0B68;
    case 0x802E0B6Cu: goto label_802E0B6C;
    case 0x802E0B70u: goto label_802E0B70;
    case 0x802E0B74u: goto label_802E0B74;
    case 0x802E0B78u: goto label_802E0B78;
    case 0x802E0B7Cu: goto label_802E0B7C;
    case 0x802E0B80u: goto label_802E0B80;
    case 0x802E0B84u: goto label_802E0B84;
    case 0x802E0B88u: goto label_802E0B88;
    case 0x802E0B8Cu: goto label_802E0B8C;
    case 0x802E0B90u: goto label_802E0B90;
    case 0x802E0B94u: goto label_802E0B94;
    case 0x802E0B98u: goto label_802E0B98;
    case 0x802E0B9Cu: goto label_802E0B9C;
    case 0x802E0BA0u: goto label_802E0BA0;
    case 0x802E0BA4u: goto label_802E0BA4;
    case 0x802E0BA8u: goto label_802E0BA8;
    case 0x802E0BACu: goto label_802E0BAC;
    case 0x802E0BB0u: goto label_802E0BB0;
    case 0x802E0BB4u: goto label_802E0BB4;
    case 0x802E0BB8u: goto label_802E0BB8;
    case 0x802E0BBCu: goto label_802E0BBC;
    case 0x802E0BC0u: goto label_802E0BC0;
    case 0x802E0BC4u: goto label_802E0BC4;
    case 0x802E0BC8u: goto label_802E0BC8;
    case 0x802E0BCCu: goto label_802E0BCC;
    case 0x802E0BD0u: goto label_802E0BD0;
    case 0x802E0BD4u: goto label_802E0BD4;
    case 0x802E0BD8u: goto label_802E0BD8;
    case 0x802E0BDCu: goto label_802E0BDC;
    case 0x802E0BE0u: goto label_802E0BE0;
    case 0x802E0BE4u: goto label_802E0BE4;
    case 0x802E0BE8u: goto label_802E0BE8;
    case 0x802E0BECu: goto label_802E0BEC;
    case 0x802E0BF0u: goto label_802E0BF0;
    case 0x802E0BF4u: goto label_802E0BF4;
    case 0x802E0BF8u: goto label_802E0BF8;
    case 0x802E0BFCu: goto label_802E0BFC;
    case 0x802E0C00u: goto label_802E0C00;
    case 0x802E0C04u: goto label_802E0C04;
    case 0x802E0C08u: goto label_802E0C08;
    case 0x802E0C0Cu: goto label_802E0C0C;
    case 0x802E0C10u: goto label_802E0C10;
    case 0x802E0C14u: goto label_802E0C14;
    case 0x802E0C18u: goto label_802E0C18;
    case 0x802E0C1Cu: goto label_802E0C1C;
    case 0x802E0C20u: goto label_802E0C20;
    case 0x802E0C24u: goto label_802E0C24;
    case 0x802E0C28u: goto label_802E0C28;
    case 0x802E0C2Cu: goto label_802E0C2C;
    case 0x802E0C30u: goto label_802E0C30;
    case 0x802E0C34u: goto label_802E0C34;
    case 0x802E0C38u: goto label_802E0C38;
    case 0x802E0C3Cu: goto label_802E0C3C;
    case 0x802E0C40u: goto label_802E0C40;
    case 0x802E0C44u: goto label_802E0C44;
    case 0x802E0C48u: goto label_802E0C48;
    case 0x802E0C4Cu: goto label_802E0C4C;
    case 0x802E0C50u: goto label_802E0C50;
    case 0x802E0C54u: goto label_802E0C54;
    case 0x802E0C58u: goto label_802E0C58;
    case 0x802E0C5Cu: goto label_802E0C5C;
    case 0x802E0C60u: goto label_802E0C60;
    case 0x802E0C64u: goto label_802E0C64;
    case 0x802E0C68u: goto label_802E0C68;
    case 0x802E0C6Cu: goto label_802E0C6C;
    case 0x802E0C70u: goto label_802E0C70;
    case 0x802E0C74u: goto label_802E0C74;
    case 0x802E0C78u: goto label_802E0C78;
    case 0x802E0C7Cu: goto label_802E0C7C;
    case 0x802E0C80u: goto label_802E0C80;
    case 0x802E0C84u: goto label_802E0C84;
    case 0x802E0C88u: goto label_802E0C88;
    case 0x802E0C8Cu: goto label_802E0C8C;
    case 0x802E0C90u: goto label_802E0C90;
    case 0x802E0C94u: goto label_802E0C94;
    case 0x802E0C98u: goto label_802E0C98;
    case 0x802E0C9Cu: goto label_802E0C9C;
    case 0x802E0CA0u: goto label_802E0CA0;
    case 0x802E0CA4u: goto label_802E0CA4;
    case 0x802E0CA8u: goto label_802E0CA8;
    case 0x802E0CACu: goto label_802E0CAC;
    case 0x802E0CB0u: goto label_802E0CB0;
    case 0x802E0CB4u: goto label_802E0CB4;
    case 0x802E0CB8u: goto label_802E0CB8;
    case 0x802E0CBCu: goto label_802E0CBC;
    case 0x802E0CC0u: goto label_802E0CC0;
    case 0x802E0CC4u: goto label_802E0CC4;
    case 0x802E0CC8u: goto label_802E0CC8;
    case 0x802E0CCCu: goto label_802E0CCC;
    case 0x802E0CD0u: goto label_802E0CD0;
    case 0x802E0CD4u: goto label_802E0CD4;
    case 0x802E0CD8u: goto label_802E0CD8;
    case 0x802E0CDCu: goto label_802E0CDC;
    case 0x802E0CE0u: goto label_802E0CE0;
    case 0x802E0CE4u: goto label_802E0CE4;
    case 0x802E0CE8u: goto label_802E0CE8;
    case 0x802E0CECu: goto label_802E0CEC;
    case 0x802E0CF0u: goto label_802E0CF0;
    case 0x802E0CF4u: goto label_802E0CF4;
    case 0x802E0CF8u: goto label_802E0CF8;
    case 0x802E0CFCu: goto label_802E0CFC;
    case 0x802E0D00u: goto label_802E0D00;
    case 0x802E0D04u: goto label_802E0D04;
    case 0x802E0D08u: goto label_802E0D08;
    case 0x802E0D0Cu: goto label_802E0D0C;
    case 0x802E0D10u: goto label_802E0D10;
    case 0x802E0D14u: goto label_802E0D14;
    case 0x802E0D18u: goto label_802E0D18;
    case 0x802E0D1Cu: goto label_802E0D1C;
    case 0x802E0D20u: goto label_802E0D20;
    case 0x802E0D24u: goto label_802E0D24;
    case 0x802E0D28u: goto label_802E0D28;
    case 0x802E0D2Cu: goto label_802E0D2C;
    case 0x802E0D30u: goto label_802E0D30;
    case 0x802E0D34u: goto label_802E0D34;
    case 0x802E0D38u: goto label_802E0D38;
    case 0x802E0D3Cu: goto label_802E0D3C;
    case 0x802E0D40u: goto label_802E0D40;
    case 0x802E0D44u: goto label_802E0D44;
    case 0x802E0D48u: goto label_802E0D48;
    case 0x802E0D4Cu: goto label_802E0D4C;
    case 0x802E0D50u: goto label_802E0D50;
    case 0x802E0D54u: goto label_802E0D54;
    case 0x802E0D58u: goto label_802E0D58;
    case 0x802E0D5Cu: goto label_802E0D5C;
    case 0x802E0D60u: goto label_802E0D60;
    case 0x802E0D64u: goto label_802E0D64;
    case 0x802E0D68u: goto label_802E0D68;
    case 0x802E0D6Cu: goto label_802E0D6C;
    case 0x802E0D70u: goto label_802E0D70;
    case 0x802E0D74u: goto label_802E0D74;
    case 0x802E0D78u: goto label_802E0D78;
    case 0x802E0D7Cu: goto label_802E0D7C;
    case 0x802E0D80u: goto label_802E0D80;
    case 0x802E0D84u: goto label_802E0D84;
    case 0x802E0D88u: goto label_802E0D88;
    case 0x802E0D8Cu: goto label_802E0D8C;
    case 0x802E0D90u: goto label_802E0D90;
    case 0x802E0D94u: goto label_802E0D94;
    case 0x802E0D98u: goto label_802E0D98;
    case 0x802E0D9Cu: goto label_802E0D9C;
    case 0x802E0DA0u: goto label_802E0DA0;
    case 0x802E0DA4u: goto label_802E0DA4;
    case 0x802E0DA8u: goto label_802E0DA8;
    case 0x802E0DACu: goto label_802E0DAC;
    case 0x802E0DB0u: goto label_802E0DB0;
    case 0x802E0DB4u: goto label_802E0DB4;
    case 0x802E0DB8u: goto label_802E0DB8;
    case 0x802E0DBCu: goto label_802E0DBC;
    case 0x802E0DC0u: goto label_802E0DC0;
    case 0x802E0DC4u: goto label_802E0DC4;
    case 0x802E0DC8u: goto label_802E0DC8;
    case 0x802E0DCCu: goto label_802E0DCC;
    case 0x802E0DD0u: goto label_802E0DD0;
    case 0x802E0DD4u: goto label_802E0DD4;
    case 0x802E0DD8u: goto label_802E0DD8;
    case 0x802E0DDCu: goto label_802E0DDC;
    case 0x802E0DE0u: goto label_802E0DE0;
    case 0x802E0DE4u: goto label_802E0DE4;
    case 0x802E0DE8u: goto label_802E0DE8;
    case 0x802E0DECu: goto label_802E0DEC;
    case 0x802E0DF0u: goto label_802E0DF0;
    case 0x802E0DF4u: goto label_802E0DF4;
    case 0x802E0DF8u: goto label_802E0DF8;
    case 0x802E0DFCu: goto label_802E0DFC;
    case 0x802E0E00u: goto label_802E0E00;
    case 0x802E0E04u: goto label_802E0E04;
    case 0x802E0E08u: goto label_802E0E08;
    case 0x802E0E0Cu: goto label_802E0E0C;
    case 0x802E0E10u: goto label_802E0E10;
    case 0x802E0E14u: goto label_802E0E14;
    case 0x802E0E18u: goto label_802E0E18;
    case 0x802E0E1Cu: goto label_802E0E1C;
    case 0x802E0E20u: goto label_802E0E20;
    case 0x802E0E24u: goto label_802E0E24;
    case 0x802E0E28u: goto label_802E0E28;
    case 0x802E0E2Cu: goto label_802E0E2C;
    case 0x802E0E30u: goto label_802E0E30;
    case 0x802E0E34u: goto label_802E0E34;
    case 0x802E0E38u: goto label_802E0E38;
    case 0x802E0E3Cu: goto label_802E0E3C;
    case 0x802E0E40u: goto label_802E0E40;
    case 0x802E0E44u: goto label_802E0E44;
    case 0x802E0E48u: goto label_802E0E48;
    case 0x802E0E4Cu: goto label_802E0E4C;
    case 0x802E0E50u: goto label_802E0E50;
    case 0x802E0E54u: goto label_802E0E54;
    case 0x802E0E58u: goto label_802E0E58;
    case 0x802E0E5Cu: goto label_802E0E5C;
    case 0x802E0E60u: goto label_802E0E60;
    case 0x802E0E64u: goto label_802E0E64;
    case 0x802E0E68u: goto label_802E0E68;
    case 0x802E0E6Cu: goto label_802E0E6C;
    case 0x802E0E70u: goto label_802E0E70;
    case 0x802E0E74u: goto label_802E0E74;
    case 0x802E0E78u: goto label_802E0E78;
    case 0x802E0E7Cu: goto label_802E0E7C;
    case 0x802E0E80u: goto label_802E0E80;
    case 0x802E0E84u: goto label_802E0E84;
    case 0x802E0E88u: goto label_802E0E88;
    case 0x802E0E8Cu: goto label_802E0E8C;
    case 0x802E0E90u: goto label_802E0E90;
    case 0x802E0E94u: goto label_802E0E94;
    case 0x802E0E98u: goto label_802E0E98;
    case 0x802E0E9Cu: goto label_802E0E9C;
    case 0x802E0EA0u: goto label_802E0EA0;
    case 0x802E0EA4u: goto label_802E0EA4;
    case 0x802E0EA8u: goto label_802E0EA8;
    case 0x802E0EACu: goto label_802E0EAC;
    case 0x802E0EB0u: goto label_802E0EB0;
    case 0x802E0EB4u: goto label_802E0EB4;
    case 0x802E0EB8u: goto label_802E0EB8;
    case 0x802E0EBCu: goto label_802E0EBC;
    case 0x802E0EC0u: goto label_802E0EC0;
    case 0x802E0EC4u: goto label_802E0EC4;
    case 0x802E0EC8u: goto label_802E0EC8;
    case 0x802E0ECCu: goto label_802E0ECC;
    case 0x802E0ED0u: goto label_802E0ED0;
    case 0x802E0ED4u: goto label_802E0ED4;
    case 0x802E0ED8u: goto label_802E0ED8;
    case 0x802E0EDCu: goto label_802E0EDC;
    case 0x802E0EE0u: goto label_802E0EE0;
    case 0x802E0EE4u: goto label_802E0EE4;
    case 0x802E0EE8u: goto label_802E0EE8;
    case 0x802E0EECu: goto label_802E0EEC;
    case 0x802E0EF0u: goto label_802E0EF0;
    case 0x802E0EF4u: goto label_802E0EF4;
    case 0x802E0EF8u: goto label_802E0EF8;
    case 0x802E0EFCu: goto label_802E0EFC;
    case 0x802E0F00u: goto label_802E0F00;
    case 0x802E0F04u: goto label_802E0F04;
    case 0x802E0F08u: goto label_802E0F08;
    case 0x802E0F0Cu: goto label_802E0F0C;
    case 0x802E0F10u: goto label_802E0F10;
    case 0x802E0F14u: goto label_802E0F14;
    case 0x802E0F18u: goto label_802E0F18;
    case 0x802E0F1Cu: goto label_802E0F1C;
    case 0x802E0F20u: goto label_802E0F20;
    case 0x802E0F24u: goto label_802E0F24;
    case 0x802E0F28u: goto label_802E0F28;
    case 0x802E0F2Cu: goto label_802E0F2C;
    case 0x802E0F30u: goto label_802E0F30;
    case 0x802E0F34u: goto label_802E0F34;
    case 0x802E0F38u: goto label_802E0F38;
    case 0x802E0F3Cu: goto label_802E0F3C;
    case 0x802E0F40u: goto label_802E0F40;
    case 0x802E0F44u: goto label_802E0F44;
    case 0x802E0F48u: goto label_802E0F48;
    case 0x802E0F4Cu: goto label_802E0F4C;
    case 0x802E0F50u: goto label_802E0F50;
    case 0x802E0F54u: goto label_802E0F54;
    case 0x802E0F58u: goto label_802E0F58;
    case 0x802E0F5Cu: goto label_802E0F5C;
    case 0x802E0F60u: goto label_802E0F60;
    case 0x802E0F64u: goto label_802E0F64;
    case 0x802E0F68u: goto label_802E0F68;
    case 0x802E0F6Cu: goto label_802E0F6C;
    case 0x802E0F70u: goto label_802E0F70;
    case 0x802E0F74u: goto label_802E0F74;
    case 0x802E0F78u: goto label_802E0F78;
    case 0x802E0F7Cu: goto label_802E0F7C;
    case 0x802E0F80u: goto label_802E0F80;
    case 0x802E0F84u: goto label_802E0F84;
    case 0x802E0F88u: goto label_802E0F88;
    case 0x802E0F8Cu: goto label_802E0F8C;
    case 0x802E0F90u: goto label_802E0F90;
    case 0x802E0F94u: goto label_802E0F94;
    case 0x802E0F98u: goto label_802E0F98;
    case 0x802E0F9Cu: goto label_802E0F9C;
    case 0x802E0FA0u: goto label_802E0FA0;
    case 0x802E0FA4u: goto label_802E0FA4;
    case 0x802E0FA8u: goto label_802E0FA8;
    case 0x802E0FACu: goto label_802E0FAC;
    case 0x802E0FB0u: goto label_802E0FB0;
    case 0x802E0FB4u: goto label_802E0FB4;
    case 0x802E0FB8u: goto label_802E0FB8;
    case 0x802E0FBCu: goto label_802E0FBC;
    case 0x802E0FC0u: goto label_802E0FC0;
    case 0x802E0FC4u: goto label_802E0FC4;
    case 0x802E0FC8u: goto label_802E0FC8;
    case 0x802E0FCCu: goto label_802E0FCC;
    case 0x802E0FD0u: goto label_802E0FD0;
    case 0x802E0FD4u: goto label_802E0FD4;
    case 0x802E0FD8u: goto label_802E0FD8;
    case 0x802E0FDCu: goto label_802E0FDC;
    case 0x802E0FE0u: goto label_802E0FE0;
    case 0x802E0FE4u: goto label_802E0FE4;
    case 0x802E0FE8u: goto label_802E0FE8;
    case 0x802E0FECu: goto label_802E0FEC;
    case 0x802E0FF0u: goto label_802E0FF0;
    case 0x802E0FF4u: goto label_802E0FF4;
    case 0x802E0FF8u: goto label_802E0FF8;
    case 0x802E0FFCu: goto label_802E0FFC;
    case 0x802E1000u: goto label_802E1000;
    case 0x802E1004u: goto label_802E1004;
    case 0x802E1008u: goto label_802E1008;
    case 0x802E100Cu: goto label_802E100C;
    case 0x802E1010u: goto label_802E1010;
    case 0x802E1014u: goto label_802E1014;
    case 0x802E1018u: goto label_802E1018;
    case 0x802E101Cu: goto label_802E101C;
    case 0x802E1020u: goto label_802E1020;
    case 0x802E1024u: goto label_802E1024;
    case 0x802E1028u: goto label_802E1028;
    case 0x802E102Cu: goto label_802E102C;
    case 0x802E1030u: goto label_802E1030;
    case 0x802E1034u: goto label_802E1034;
    case 0x802E1038u: goto label_802E1038;
    case 0x802E103Cu: goto label_802E103C;
    case 0x802E1040u: goto label_802E1040;
    case 0x802E1044u: goto label_802E1044;
    case 0x802E1048u: goto label_802E1048;
    case 0x802E104Cu: goto label_802E104C;
    case 0x802E1050u: goto label_802E1050;
    case 0x802E1054u: goto label_802E1054;
    case 0x802E1058u: goto label_802E1058;
    case 0x802E105Cu: goto label_802E105C;
    case 0x802E1060u: goto label_802E1060;
    case 0x802E1064u: goto label_802E1064;
    case 0x802E1068u: goto label_802E1068;
    case 0x802E106Cu: goto label_802E106C;
    case 0x802E1070u: goto label_802E1070;
    case 0x802E1074u: goto label_802E1074;
    case 0x802E1078u: goto label_802E1078;
    case 0x802E107Cu: goto label_802E107C;
    case 0x802E1080u: goto label_802E1080;
    case 0x802E1084u: goto label_802E1084;
    case 0x802E1088u: goto label_802E1088;
    case 0x802E108Cu: goto label_802E108C;
    case 0x802E1090u: goto label_802E1090;
    case 0x802E1094u: goto label_802E1094;
    case 0x802E1098u: goto label_802E1098;
    case 0x802E109Cu: goto label_802E109C;
    case 0x802E10A0u: goto label_802E10A0;
    case 0x802E10A4u: goto label_802E10A4;
    case 0x802E10A8u: goto label_802E10A8;
    case 0x802E10ACu: goto label_802E10AC;
    case 0x802E10B0u: goto label_802E10B0;
    case 0x802E10B4u: goto label_802E10B4;
    case 0x802E10B8u: goto label_802E10B8;
    case 0x802E10BCu: goto label_802E10BC;
    case 0x802E10C0u: goto label_802E10C0;
    case 0x802E10C4u: goto label_802E10C4;
    case 0x802E10C8u: goto label_802E10C8;
    case 0x802E10CCu: goto label_802E10CC;
    case 0x802E10D0u: goto label_802E10D0;
    case 0x802E10D4u: goto label_802E10D4;
    case 0x802E10D8u: goto label_802E10D8;
    case 0x802E10DCu: goto label_802E10DC;
    case 0x802E10E0u: goto label_802E10E0;
    case 0x802E10E4u: goto label_802E10E4;
    case 0x802E10E8u: goto label_802E10E8;
    case 0x802E10ECu: goto label_802E10EC;
    case 0x802E10F0u: goto label_802E10F0;
    case 0x802E10F4u: goto label_802E10F4;
    case 0x802E10F8u: goto label_802E10F8;
    case 0x802E10FCu: goto label_802E10FC;
    case 0x802E1100u: goto label_802E1100;
    case 0x802E1104u: goto label_802E1104;
    case 0x802E1108u: goto label_802E1108;
    case 0x802E110Cu: goto label_802E110C;
    case 0x802E1110u: goto label_802E1110;
    case 0x802E1114u: goto label_802E1114;
    case 0x802E1118u: goto label_802E1118;
    case 0x802E111Cu: goto label_802E111C;
    case 0x802E1120u: goto label_802E1120;
    case 0x802E1124u: goto label_802E1124;
    case 0x802E1128u: goto label_802E1128;
    case 0x802E112Cu: goto label_802E112C;
    case 0x802E1130u: goto label_802E1130;
    case 0x802E1134u: goto label_802E1134;
    case 0x802E1138u: goto label_802E1138;
    case 0x802E113Cu: goto label_802E113C;
    case 0x802E1140u: goto label_802E1140;
    case 0x802E1144u: goto label_802E1144;
    case 0x802E1148u: goto label_802E1148;
    case 0x802E114Cu: goto label_802E114C;
    case 0x802E1150u: goto label_802E1150;
    case 0x802E1154u: goto label_802E1154;
    case 0x802E1158u: goto label_802E1158;
    case 0x802E115Cu: goto label_802E115C;
    case 0x802E1160u: goto label_802E1160;
    case 0x802E1164u: goto label_802E1164;
    case 0x802E1168u: goto label_802E1168;
    case 0x802E116Cu: goto label_802E116C;
    case 0x802E1170u: goto label_802E1170;
    case 0x802E1174u: goto label_802E1174;
    case 0x802E1178u: goto label_802E1178;
    case 0x802E117Cu: goto label_802E117C;
    case 0x802E1180u: goto label_802E1180;
    case 0x802E1184u: goto label_802E1184;
    case 0x802E1188u: goto label_802E1188;
    case 0x802E118Cu: goto label_802E118C;
    case 0x802E1190u: goto label_802E1190;
    case 0x802E1194u: goto label_802E1194;
    case 0x802E1198u: goto label_802E1198;
    case 0x802E119Cu: goto label_802E119C;
    case 0x802E11A0u: goto label_802E11A0;
    case 0x802E11A4u: goto label_802E11A4;
    case 0x802E11A8u: goto label_802E11A8;
    case 0x802E11ACu: goto label_802E11AC;
    case 0x802E11B0u: goto label_802E11B0;
    case 0x802E11B4u: goto label_802E11B4;
    case 0x802E11B8u: goto label_802E11B8;
    case 0x802E11BCu: goto label_802E11BC;
    case 0x802E11C0u: goto label_802E11C0;
    case 0x802E11C4u: goto label_802E11C4;
    case 0x802E11C8u: goto label_802E11C8;
    case 0x802E11CCu: goto label_802E11CC;
    case 0x802E11D0u: goto label_802E11D0;
    case 0x802E11D4u: goto label_802E11D4;
    case 0x802E11D8u: goto label_802E11D8;
    case 0x802E11DCu: goto label_802E11DC;
    case 0x802E11E0u: goto label_802E11E0;
    case 0x802E11E4u: goto label_802E11E4;
    case 0x802E11E8u: goto label_802E11E8;
    case 0x802E11ECu: goto label_802E11EC;
    case 0x802E11F0u: goto label_802E11F0;
    case 0x802E11F4u: goto label_802E11F4;
    case 0x802E11F8u: goto label_802E11F8;
    case 0x802E11FCu: goto label_802E11FC;
    case 0x802E1200u: goto label_802E1200;
    case 0x802E1204u: goto label_802E1204;
    case 0x802E1208u: goto label_802E1208;
    case 0x802E120Cu: goto label_802E120C;
    case 0x802E1210u: goto label_802E1210;
    case 0x802E1214u: goto label_802E1214;
    case 0x802E1218u: goto label_802E1218;
    case 0x802E121Cu: goto label_802E121C;
    case 0x802E1220u: goto label_802E1220;
    case 0x802E1224u: goto label_802E1224;
    case 0x802E1228u: goto label_802E1228;
    case 0x802E122Cu: goto label_802E122C;
    case 0x802E1230u: goto label_802E1230;
    case 0x802E1234u: goto label_802E1234;
    case 0x802E1238u: goto label_802E1238;
    case 0x802E123Cu: goto label_802E123C;
    case 0x802E1240u: goto label_802E1240;
    case 0x802E1244u: goto label_802E1244;
    case 0x802E1248u: goto label_802E1248;
    case 0x802E124Cu: goto label_802E124C;
    case 0x802E1250u: goto label_802E1250;
    case 0x802E1254u: goto label_802E1254;
    case 0x802E1258u: goto label_802E1258;
    case 0x802E125Cu: goto label_802E125C;
    case 0x802E1260u: goto label_802E1260;
    case 0x802E1264u: goto label_802E1264;
    case 0x802E1268u: goto label_802E1268;
    case 0x802E126Cu: goto label_802E126C;
    case 0x802E1270u: goto label_802E1270;
    case 0x802E1274u: goto label_802E1274;
    case 0x802E1278u: goto label_802E1278;
    case 0x802E127Cu: goto label_802E127C;
    case 0x802E1280u: goto label_802E1280;
    case 0x802E1284u: goto label_802E1284;
    case 0x802E1288u: goto label_802E1288;
    case 0x802E128Cu: goto label_802E128C;
    case 0x802E1290u: goto label_802E1290;
    case 0x802E1294u: goto label_802E1294;
    case 0x802E1298u: goto label_802E1298;
    case 0x802E129Cu: goto label_802E129C;
    case 0x802E12A0u: goto label_802E12A0;
    case 0x802E12A4u: goto label_802E12A4;
    case 0x802E12A8u: goto label_802E12A8;
    case 0x802E12ACu: goto label_802E12AC;
    case 0x802E12B0u: goto label_802E12B0;
    case 0x802E12B4u: goto label_802E12B4;
    case 0x802E12B8u: goto label_802E12B8;
    case 0x802E12BCu: goto label_802E12BC;
    case 0x802E12C0u: goto label_802E12C0;
    case 0x802E12C4u: goto label_802E12C4;
    case 0x802E12C8u: goto label_802E12C8;
    case 0x802E12CCu: goto label_802E12CC;
    case 0x802E12D0u: goto label_802E12D0;
    case 0x802E12D4u: goto label_802E12D4;
    case 0x802E12D8u: goto label_802E12D8;
    case 0x802E12DCu: goto label_802E12DC;
    case 0x802E12E0u: goto label_802E12E0;
    case 0x802E12E4u: goto label_802E12E4;
    case 0x802E12E8u: goto label_802E12E8;
    case 0x802E12ECu: goto label_802E12EC;
    case 0x802E12F0u: goto label_802E12F0;
    case 0x802E12F4u: goto label_802E12F4;
    case 0x802E12F8u: goto label_802E12F8;
    case 0x802E12FCu: goto label_802E12FC;
    case 0x802E1300u: goto label_802E1300;
    case 0x802E1304u: goto label_802E1304;
    case 0x802E1308u: goto label_802E1308;
    case 0x802E130Cu: goto label_802E130C;
    case 0x802E1310u: goto label_802E1310;
    case 0x802E1314u: goto label_802E1314;
    case 0x802E1318u: goto label_802E1318;
    case 0x802E131Cu: goto label_802E131C;
    case 0x802E1320u: goto label_802E1320;
    case 0x802E1324u: goto label_802E1324;
    case 0x802E1328u: goto label_802E1328;
    case 0x802E132Cu: goto label_802E132C;
    case 0x802E1330u: goto label_802E1330;
    case 0x802E1334u: goto label_802E1334;
    case 0x802E1338u: goto label_802E1338;
    case 0x802E133Cu: goto label_802E133C;
    default: return;
    }
label_802DF4C0:
    ctx->pc = 0x802DF4C0u;
    ctx->downcount -= 9;
    // 802DF4C0: subf   r30, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_802DF4C4:
    ctx->pc = 0x802DF4C4u;
    // 802DF4C4: rlwinm r3, r30, 31, 1, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[30], 31u) & 0x7FFFFFFFu;
    }

label_802DF4C8:
    ctx->pc = 0x802DF4C8u;
    // 802DF4C8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF4CC:
    ctx->pc = 0x802DF4CCu;
    // 802DF4CC: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802DF4D0:
    ctx->pc = 0x802DF4D0u;
    // 802DF4D0: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802DF4D4:
    ctx->pc = 0x802DF4D4u;
    // 802DF4D4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_802DF4D8:
    ctx->pc = 0x802DF4D8u;
    // 802DF4D8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DF4DC:
    ctx->pc = 0x802DF4DCu;
    // 802DF4DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF4E0:
    ctx->pc = 0x802DF4E0u;
    ctx->downcount -= 5;
    // 802DF4E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DF4E4:
    ctx->pc = 0x802DF4E4u;
    // 802DF4E4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DF4E8:
    ctx->pc = 0x802DF4E8u;
    // 802DF4E8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DF4EC:
    ctx->pc = 0x802DF4ECu;
    // 802DF4EC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DF4F0:
    ctx->pc = 0x802DF4F0u;
    // 802DF4F0: bl      0x802C30E8
    {
            ctx->lr = 0x802DF4F4u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802DF4F4:
    ctx->pc = 0x802DF4F4u;
    ctx->downcount -= 3;
    // 802DF4F4: lwz     r5, -25132(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25132);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802DF4F8:
    ctx->pc = 0x802DF4F8u;
    // 802DF4F8: cmplwi  r5, 0x0006
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0006u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802DF4FC:
    ctx->pc = 0x802DF4FCu;
    // 802DF4FC: bc    12, 1, 0x802DF52C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802DF52C;
        }
    }

label_802DF500:
    ctx->pc = 0x802DF500u;
    ctx->downcount -= 7;
    // 802DF500: lis     r4, -32714
    ctx->gpr[4] = ((u32)(s32)(-32714) << 16);

label_802DF504:
    ctx->pc = 0x802DF504u;
    // 802DF504: addi    r4, r4, -28228
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-28228);

label_802DF508:
    ctx->pc = 0x802DF508u;
    // 802DF508: rlwinm r0, r5, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_802DF50C:
    ctx->pc = 0x802DF50Cu;
    // 802DF50C: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF510:
    ctx->pc = 0x802DF510u;
    // 802DF510: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802DF514:
    ctx->pc = 0x802DF514u;
    // 802DF514: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802DF518:
    ctx->pc = 0x802DF518u;
    ctx->downcount -= 2;
    // 802DF518: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_802DF51C:
    ctx->pc = 0x802DF51Cu;
    // 802DF51C: b       0x802DF52C
    {
            goto label_802DF52C;
    }

label_802DF520:
    ctx->pc = 0x802DF520u;
    ctx->downcount -= 2;
    // 802DF520: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_802DF524:
    ctx->pc = 0x802DF524u;
    // 802DF524: b       0x802DF52C
    {
            goto label_802DF52C;
    }

label_802DF528:
    ctx->pc = 0x802DF528u;
    ctx->downcount -= 1;
    // 802DF528: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

label_802DF52C:
    ctx->pc = 0x802DF52Cu;
    ctx->downcount -= 1;
    // 802DF52C: bl      0x802C3110
    {
            ctx->lr = 0x802DF530u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802DF530:
    ctx->pc = 0x802DF530u;
    ctx->downcount -= 7;
    // 802DF530: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802DF534:
    ctx->pc = 0x802DF534u;
    // 802DF534: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF538:
    ctx->pc = 0x802DF538u;
    // 802DF538: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802DF53C:
    ctx->pc = 0x802DF53Cu;
    // 802DF53C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_802DF540:
    ctx->pc = 0x802DF540u;
    // 802DF540: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DF544:
    ctx->pc = 0x802DF544u;
    // 802DF544: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF548:
    ctx->pc = 0x802DF548u;
    ctx->downcount -= 5;
    // 802DF548: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DF54C:
    ctx->pc = 0x802DF54Cu;
    // 802DF54C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DF550:
    ctx->pc = 0x802DF550u;
    // 802DF550: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DF554:
    ctx->pc = 0x802DF554u;
    // 802DF554: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DF558:
    ctx->pc = 0x802DF558u;
    // 802DF558: bl      0x802C30E8
    {
            ctx->lr = 0x802DF55Cu;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802DF55C:
    ctx->pc = 0x802DF55Cu;
    ctx->downcount -= 4;
    // 802DF55C: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_802DF560:
    ctx->pc = 0x802DF560u;
    // 802DF560: lhz     r0, 8302(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8302);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802DF564:
    ctx->pc = 0x802DF564u;
    // 802DF564: rlwinm r31, r0, 0, 30, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000003u;
    }

label_802DF568:
    ctx->pc = 0x802DF568u;
    // 802DF568: bl      0x802C3110
    {
            ctx->lr = 0x802DF56Cu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802DF56C:
    ctx->pc = 0x802DF56Cu;
    ctx->downcount -= 7;
    // 802DF56C: rlwinm r3, r31, 0, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00000001u;
    }

label_802DF570:
    ctx->pc = 0x802DF570u;
    // 802DF570: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF574:
    ctx->pc = 0x802DF574u;
    // 802DF574: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802DF578:
    ctx->pc = 0x802DF578u;
    // 802DF578: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_802DF57C:
    ctx->pc = 0x802DF57Cu;
    // 802DF57C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DF580:
    ctx->pc = 0x802DF580u;
    // 802DF580: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF584:
    ctx->pc = 0x802DF584u;
    ctx->downcount -= 19;
    // 802DF584: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DF588:
    ctx->pc = 0x802DF588u;
    // 802DF588: lis     r5, -32709
    ctx->gpr[5] = ((u32)(s32)(-32709) << 16);

label_802DF58C:
    ctx->pc = 0x802DF58Cu;
    // 802DF58C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DF590:
    ctx->pc = 0x802DF590u;
    // 802DF590: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DF594:
    ctx->pc = 0x802DF594u;
    // 802DF594: stmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802DF598:
    ctx->pc = 0x802DF598u;
    // 802DF598: addi    r28, r3, 0
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(0);

label_802DF59C:
    ctx->pc = 0x802DF59Cu;
    // 802DF59C: addi    r27, r4, 0
    ctx->gpr[27] = ctx->gpr[4] + (u32)(s32)(0);

label_802DF5A0:
    ctx->pc = 0x802DF5A0u;
    // 802DF5A0: addi    r30, r5, 17464
    ctx->gpr[30] = ctx->gpr[5] + (u32)(s32)(17464);

label_802DF5A4:
    ctx->pc = 0x802DF5A4u;
    // 802DF5A4: bl      0x802C30E8
    {
            ctx->lr = 0x802DF5A8u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802DF5A8:
    ctx->pc = 0x802DF5A8u;
    ctx->downcount -= 13;
    // 802DF5A8: sth     r28, -25168(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25168);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_802DF5AC:
    ctx->pc = 0x802DF5ACu;
    // 802DF5AC: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802DF5B0:
    ctx->pc = 0x802DF5B0u;
    // 802DF5B0: extsh r4, r28
    {
        ctx->gpr[4] = (u32)(s32)(s16)ctx->gpr[28];
    }

label_802DF5B4:
    ctx->pc = 0x802DF5B4u;
    // 802DF5B4: sth     r27, -25166(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25166);
        mem_write16(ctx, ea, (u16)ctx->gpr[27]);
    }

label_802DF5B8:
    ctx->pc = 0x802DF5B8u;
    // 802DF5B8: addi    r9, r30, 244
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(244);

label_802DF5BC:
    ctx->pc = 0x802DF5BCu;
    // 802DF5BC: lha     r3, 240(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(240);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_802DF5C0:
    ctx->pc = 0x802DF5C0u;
    // 802DF5C0: lhz     r0, 244(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_802DF5C4:
    ctx->pc = 0x802DF5C4u;
    // 802DF5C4: lwz     r29, 324(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(324);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802DF5C8:
    ctx->pc = 0x802DF5C8u;
    // 802DF5C8: add   r3, r3, r4
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802DF5CC:
    ctx->pc = 0x802DF5CCu;
    // 802DF5CC: subfic  r0, r0, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802DF5D0:
    ctx->pc = 0x802DF5D0u;
    // 802DF5D0: cmpw    r3, r0
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

label_802DF5D4:
    ctx->pc = 0x802DF5D4u;
    // 802DF5D4: lhz     r6, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_802DF5D8:
    ctx->pc = 0x802DF5D8u;
    // 802DF5D8: bc    4, 1, 0x802DF5E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF5E0;
        }
    }

label_802DF5DC:
    ctx->pc = 0x802DF5DCu;
    ctx->downcount -= 1;
    // 802DF5DC: b       0x802DF5F0
    {
            goto label_802DF5F0;
    }

label_802DF5E0:
    ctx->pc = 0x802DF5E0u;
    ctx->downcount -= 2;
    // 802DF5E0: cmpwi   r3, 0
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

label_802DF5E4:
    ctx->pc = 0x802DF5E4u;
    // 802DF5E4: bc    4, 0, 0x802DF5EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF5EC;
        }
    }

label_802DF5E8:
    ctx->pc = 0x802DF5E8u;
    ctx->downcount -= 1;
    // 802DF5E8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DF5EC:
    ctx->pc = 0x802DF5ECu;
    ctx->downcount -= 1;
    // 802DF5EC: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802DF5F0:
    ctx->pc = 0x802DF5F0u;
    ctx->downcount -= 5;
    // 802DF5F0: sth     r0, 248(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(248);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802DF5F4:
    ctx->pc = 0x802DF5F4u;
    // 802DF5F4: addi    r8, r30, 248
    ctx->gpr[8] = ctx->gpr[30] + (u32)(s32)(248);

label_802DF5F8:
    ctx->pc = 0x802DF5F8u;
    // 802DF5F8: lwz     r0, 272(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF5FC:
    ctx->pc = 0x802DF5FCu;
    // 802DF5FC: cmpwi   r0, 0
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

label_802DF600:
    ctx->pc = 0x802DF600u;
    // 802DF600: bc    4, 2, 0x802DF60C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF60C;
        }
    }

label_802DF604:
    ctx->pc = 0x802DF604u;
    ctx->downcount -= 2;
    // 802DF604: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_802DF608:
    ctx->pc = 0x802DF608u;
    // 802DF608: b       0x802DF610
    {
            goto label_802DF610;
    }

label_802DF60C:
    ctx->pc = 0x802DF60Cu;
    ctx->downcount -= 1;
    // 802DF60C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802DF610:
    ctx->pc = 0x802DF610u;
    ctx->downcount -= 8;
    // 802DF610: lhz     r3, 242(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(242);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802DF614:
    ctx->pc = 0x802DF614u;
    // 802DF614: extsh r4, r27
    {
        ctx->gpr[4] = (u32)(s32)(s16)ctx->gpr[27];
    }

label_802DF618:
    ctx->pc = 0x802DF618u;
    // 802DF618: addi    r5, r30, 242
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(242);

label_802DF61C:
    ctx->pc = 0x802DF61Cu;
    // 802DF61C: extsh r7, r3
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_802DF620:
    ctx->pc = 0x802DF620u;
    // 802DF620: rlwinm r3, r3, 0, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
    }

label_802DF624:
    ctx->pc = 0x802DF624u;
    // 802DF624: add   r7, r7, r4
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802DF628:
    ctx->pc = 0x802DF628u;
    // 802DF628: cmpw    r7, r3
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802DF62C:
    ctx->pc = 0x802DF62Cu;
    // 802DF62C: bc    4, 1, 0x802DF634
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF634;
        }
    }

label_802DF630:
    ctx->pc = 0x802DF630u;
    ctx->downcount -= 1;
    // 802DF630: b       0x802DF638
    {
            goto label_802DF638;
    }

label_802DF634:
    ctx->pc = 0x802DF634u;
    ctx->downcount -= 1;
    // 802DF634: or   r7, r3, r3
    {
        ctx->gpr[7] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802DF638:
    ctx->pc = 0x802DF638u;
    ctx->downcount -= 13;
    // 802DF638: sth     r7, 250(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(250);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_802DF63C:
    ctx->pc = 0x802DF63Cu;
    // 802DF63C: extsh r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s16)ctx->gpr[6];
    }

label_802DF640:
    ctx->pc = 0x802DF640u;
    // 802DF640: rlwinm r6, r6, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_802DF644:
    ctx->pc = 0x802DF644u;
    // 802DF644: lhz     r28, 246(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(246);
        ctx->gpr[28] = mem_read16(ctx, ea);
    }

label_802DF648:
    ctx->pc = 0x802DF648u;
    // 802DF648: subf   r6, r3, r6
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_802DF64C:
    ctx->pc = 0x802DF64Cu;
    // 802DF64C: lha     r12, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[12] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_802DF650:
    ctx->pc = 0x802DF650u;
    // 802DF650: addi    r27, r30, 250
    ctx->gpr[27] = ctx->gpr[30] + (u32)(s32)(250);

label_802DF654:
    ctx->pc = 0x802DF654u;
    // 802DF654: extsh r10, r28
    {
        ctx->gpr[10] = (u32)(s32)(s16)ctx->gpr[28];
    }

label_802DF658:
    ctx->pc = 0x802DF658u;
    // 802DF658: add   r11, r10, r4
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_802DF65C:
    ctx->pc = 0x802DF65Cu;
    // 802DF65C: add   r11, r12, r11
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_802DF660:
    ctx->pc = 0x802DF660u;
    // 802DF660: subf.   r10, r6, r11
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DF664:
    ctx->pc = 0x802DF664u;
    // 802DF664: addi    r7, r30, 246
    ctx->gpr[7] = ctx->gpr[30] + (u32)(s32)(246);

label_802DF668:
    ctx->pc = 0x802DF668u;
    // 802DF668: bc    4, 1, 0x802DF674
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF674;
        }
    }

label_802DF66C:
    ctx->pc = 0x802DF66Cu;
    ctx->downcount -= 2;
    // 802DF66C: subf   r11, r6, r11
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[11] = res;
    }

label_802DF670:
    ctx->pc = 0x802DF670u;
    // 802DF670: b       0x802DF678
    {
            goto label_802DF678;
    }

label_802DF674:
    ctx->pc = 0x802DF674u;
    ctx->downcount -= 1;
    // 802DF674: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_802DF678:
    ctx->pc = 0x802DF678u;
    ctx->downcount -= 3;
    // 802DF678: add   r12, r12, r4
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[12] = res;
    }

label_802DF67C:
    ctx->pc = 0x802DF67Cu;
    // 802DF67C: subf.   r10, r3, r12
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[12];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DF680:
    ctx->pc = 0x802DF680u;
    // 802DF680: bc    4, 0, 0x802DF68C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF68C;
        }
    }

label_802DF684:
    ctx->pc = 0x802DF684u;
    ctx->downcount -= 2;
    // 802DF684: subf   r10, r3, r12
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[12];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_802DF688:
    ctx->pc = 0x802DF688u;
    // 802DF688: b       0x802DF690
    {
            goto label_802DF690;
    }

label_802DF68C:
    ctx->pc = 0x802DF68Cu;
    ctx->downcount -= 1;
    // 802DF68C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_802DF690:
    ctx->pc = 0x802DF690u;
    ctx->downcount -= 8;
    // 802DF690: add   r10, r28, r10
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_802DF694:
    ctx->pc = 0x802DF694u;
    // 802DF694: subf   r10, r11, r10
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_802DF698:
    ctx->pc = 0x802DF698u;
    // 802DF698: addi    r28, r30, 252
    ctx->gpr[28] = ctx->gpr[30] + (u32)(s32)(252);

label_802DF69C:
    ctx->pc = 0x802DF69Cu;
    // 802DF69C: sth     r10, 252(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(252);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_802DF6A0:
    ctx->pc = 0x802DF6A0u;
    // 802DF6A0: lha     r10, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_802DF6A4:
    ctx->pc = 0x802DF6A4u;
    // 802DF6A4: add   r11, r10, r4
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_802DF6A8:
    ctx->pc = 0x802DF6A8u;
    // 802DF6A8: subf.   r10, r3, r11
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DF6AC:
    ctx->pc = 0x802DF6ACu;
    // 802DF6AC: bc    4, 0, 0x802DF6B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF6B8;
        }
    }

label_802DF6B0:
    ctx->pc = 0x802DF6B0u;
    ctx->downcount -= 2;
    // 802DF6B0: subf   r10, r3, r11
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_802DF6B4:
    ctx->pc = 0x802DF6B4u;
    // 802DF6B4: b       0x802DF6BC
    {
            goto label_802DF6BC;
    }

label_802DF6B8:
    ctx->pc = 0x802DF6B8u;
    ctx->downcount -= 1;
    // 802DF6B8: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_802DF6BC:
    ctx->pc = 0x802DF6BCu;
    ctx->downcount -= 49;
    // 802DF6BC: divw   r11, r10, r0
    {
        s32 dividend = (s32)ctx->gpr[10];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[11] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_802DF6C0:
    ctx->pc = 0x802DF6C0u;
    // 802DF6C0: lhz     r10, 264(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(264);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_802DF6C4:
    ctx->pc = 0x802DF6C4u;
    // 802DF6C4: subf   r10, r11, r10
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_802DF6C8:
    ctx->pc = 0x802DF6C8u;
    // 802DF6C8: sth     r10, 254(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(254);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_802DF6CC:
    ctx->pc = 0x802DF6CCu;
    // 802DF6CC: lha     r7, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[7] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_802DF6D0:
    ctx->pc = 0x802DF6D0u;
    // 802DF6D0: lha     r10, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_802DF6D4:
    ctx->pc = 0x802DF6D4u;
    // 802DF6D4: add   r7, r7, r4
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802DF6D8:
    ctx->pc = 0x802DF6D8u;
    // 802DF6D8: add   r7, r10, r7
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802DF6DC:
    ctx->pc = 0x802DF6DCu;
    // 802DF6DC: subf.   r5, r6, r7
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[7];
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

label_802DF6E0:
    ctx->pc = 0x802DF6E0u;
    // 802DF6E0: bc    4, 1, 0x802DF6EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF6EC;
        }
    }

label_802DF6E4:
    ctx->pc = 0x802DF6E4u;
    ctx->downcount -= 2;
    // 802DF6E4: subf   r5, r6, r7
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_802DF6E8:
    ctx->pc = 0x802DF6E8u;
    // 802DF6E8: b       0x802DF6F0
    {
            goto label_802DF6F0;
    }

label_802DF6EC:
    ctx->pc = 0x802DF6ECu;
    ctx->downcount -= 1;
    // 802DF6EC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802DF6F0:
    ctx->pc = 0x802DF6F0u;
    ctx->downcount -= 3;
    // 802DF6F0: add   r6, r10, r4
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_802DF6F4:
    ctx->pc = 0x802DF6F4u;
    // 802DF6F4: subf.   r4, r3, r6
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[6];
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

label_802DF6F8:
    ctx->pc = 0x802DF6F8u;
    // 802DF6F8: bc    4, 0, 0x802DF704
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DF704;
        }
    }

label_802DF6FC:
    ctx->pc = 0x802DF6FCu;
    ctx->downcount -= 2;
    // 802DF6FC: subf   r3, r3, r6
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_802DF700:
    ctx->pc = 0x802DF700u;
    // 802DF700: b       0x802DF708
    {
            goto label_802DF708;
    }

label_802DF704:
    ctx->pc = 0x802DF704u;
    ctx->downcount -= 1;
    // 802DF704: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DF708:
    ctx->pc = 0x802DF708u;
    ctx->downcount -= 135;
    // 802DF708: divw   r3, r3, r0
    {
        s32 dividend = (s32)ctx->gpr[3];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[3] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_802DF70C:
    ctx->pc = 0x802DF70Cu;
    // 802DF70C: lhz     r4, 268(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(268);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802DF710:
    ctx->pc = 0x802DF710u;
    // 802DF710: divw   r5, r5, r0
    {
        s32 dividend = (s32)ctx->gpr[5];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[5] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_802DF714:
    ctx->pc = 0x802DF714u;
    // 802DF714: add   r0, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802DF718:
    ctx->pc = 0x802DF718u;
    // 802DF718: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_802DF71C:
    ctx->pc = 0x802DF71Cu;
    // 802DF71C: sth     r0, 256(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(256);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802DF720:
    ctx->pc = 0x802DF720u;
    // 802DF720: lis     r5, 4096
    ctx->gpr[5] = ((u32)(s32)(4096) << 16);

label_802DF724:
    ctx->pc = 0x802DF724u;
    // 802DF724: lis     r4, 8192
    ctx->gpr[4] = ((u32)(s32)(8192) << 16);

label_802DF728:
    ctx->pc = 0x802DF728u;
    // 802DF728: lhz     r10, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_802DF72C:
    ctx->pc = 0x802DF72Cu;
    // 802DF72C: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_802DF730:
    ctx->pc = 0x802DF730u;
    // 802DF730: lhz     r6, 26(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(26);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_802DF734:
    ctx->pc = 0x802DF734u;
    // 802DF734: lis     r3, 2048
    ctx->gpr[3] = ((u32)(s32)(2048) << 16);

label_802DF738:
    ctx->pc = 0x802DF738u;
    // 802DF738: sth     r6, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_802DF73C:
    ctx->pc = 0x802DF73Cu;
    // 802DF73C: lwz     r6, -25160(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25160);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802DF740:
    ctx->pc = 0x802DF740u;
    // 802DF740: lwz     r7, -25156(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25156);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802DF744:
    ctx->pc = 0x802DF744u;
    // 802DF744: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_802DF748:
    ctx->pc = 0x802DF748u;
    // 802DF748: stw     r7, -25156(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25156);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_802DF74C:
    ctx->pc = 0x802DF74Cu;
    // 802DF74C: stw     r5, -25160(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25160);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802DF750:
    ctx->pc = 0x802DF750u;
    // 802DF750: lbz     r5, 29(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(29);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_802DF754:
    ctx->pc = 0x802DF754u;
    // 802DF754: lbz     r6, 30(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(30);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_802DF758:
    ctx->pc = 0x802DF758u;
    // 802DF758: rlwimi r6, r5, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[5], 8u);
        ctx->gpr[6] = (ctx->gpr[6] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_802DF75C:
    ctx->pc = 0x802DF75Cu;
    // 802DF75C: sth     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_802DF760:
    ctx->pc = 0x802DF760u;
    // 802DF760: lwz     r5, -25160(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25160);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802DF764:
    ctx->pc = 0x802DF764u;
    // 802DF764: lwz     r6, -25156(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25156);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802DF768:
    ctx->pc = 0x802DF768u;
    // 802DF768: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802DF76C:
    ctx->pc = 0x802DF76Cu;
    // 802DF76C: stw     r6, -25156(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25156);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802DF770:
    ctx->pc = 0x802DF770u;
    // 802DF770: stw     r4, -25160(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25160);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802DF774:
    ctx->pc = 0x802DF774u;
    // 802DF774: lbz     r4, 31(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(31);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_802DF778:
    ctx->pc = 0x802DF778u;
    // 802DF778: lbz     r5, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_802DF77C:
    ctx->pc = 0x802DF77Cu;
    // 802DF77C: add   r8, r4, r10
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802DF780:
    ctx->pc = 0x802DF780u;
    // 802DF780: lhz     r7, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_802DF784:
    ctx->pc = 0x802DF784u;
    // 802DF784: addi    r8, r8, -40
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(-40);

label_802DF788:
    ctx->pc = 0x802DF788u;
    // 802DF788: lhz     r6, 32(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(32);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_802DF78C:
    ctx->pc = 0x802DF78Cu;
    // 802DF78C: rlwinm r4, r8, 7, 16, 24
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 7u) & 0x0000FF80u;
    }

label_802DF790:
    ctx->pc = 0x802DF790u;
    // 802DF790: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802DF794:
    ctx->pc = 0x802DF794u;
    // 802DF794: add   r5, r6, r10
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_802DF798:
    ctx->pc = 0x802DF798u;
    // 802DF798: sth     r4, 10(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_802DF79C:
    ctx->pc = 0x802DF79Cu;
    // 802DF79C: subfic  r6, r7, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802DF7A0:
    ctx->pc = 0x802DF7A0u;
    // 802DF7A0: addi    r5, r5, 40
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(40);

label_802DF7A4:
    ctx->pc = 0x802DF7A4u;
    // 802DF7A4: lwz     r4, -25160(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25160);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802DF7A8:
    ctx->pc = 0x802DF7A8u;
    // 802DF7A8: subf   r7, r6, r5
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_802DF7AC:
    ctx->pc = 0x802DF7ACu;
    // 802DF7AC: or   r5, r4, r0
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802DF7B0:
    ctx->pc = 0x802DF7B0u;
    // 802DF7B0: lwz     r6, -25156(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25156);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802DF7B4:
    ctx->pc = 0x802DF7B4u;
    // 802DF7B4: rlwinm r4, r8, 23, 9, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 23u) & 0x007FFFFFu;
    }

label_802DF7B8:
    ctx->pc = 0x802DF7B8u;
    // 802DF7B8: stw     r6, -25156(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25156);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802DF7BC:
    ctx->pc = 0x802DF7BCu;
    // 802DF7BC: rlwinm r0, r7, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 1u) & 0xFFFFFFFEu;
    }

label_802DF7C0:
    ctx->pc = 0x802DF7C0u;
    // 802DF7C0: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802DF7C4:
    ctx->pc = 0x802DF7C4u;
    // 802DF7C4: stw     r5, -25160(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25160);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802DF7C8:
    ctx->pc = 0x802DF7C8u;
    // 802DF7C8: sth     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802DF7CC:
    ctx->pc = 0x802DF7CCu;
    // 802DF7CC: lwz     r4, -25160(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25160);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802DF7D0:
    ctx->pc = 0x802DF7D0u;
    // 802DF7D0: lwz     r0, -25120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25120);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF7D4:
    ctx->pc = 0x802DF7D4u;
    // 802DF7D4: lwz     r5, -25156(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25156);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802DF7D8:
    ctx->pc = 0x802DF7D8u;
    // 802DF7D8: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_802DF7DC:
    ctx->pc = 0x802DF7DCu;
    // 802DF7DC: cmplwi  r0, 0x0000
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

label_802DF7E0:
    ctx->pc = 0x802DF7E0u;
    // 802DF7E0: stw     r5, -25156(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25156);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802DF7E4:
    ctx->pc = 0x802DF7E4u;
    // 802DF7E4: stw     r3, -25160(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25160);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802DF7E8:
    ctx->pc = 0x802DF7E8u;
    // 802DF7E8: bc    12, 2, 0x802DF804
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802DF804;
        }
    }

label_802DF7EC:
    ctx->pc = 0x802DF7ECu;
    ctx->downcount -= 6;
    // 802DF7EC: addi    r3, r30, 240
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(240);

label_802DF7F0:
    ctx->pc = 0x802DF7F0u;
    // 802DF7F0: addi    r4, r30, 292
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(292);

label_802DF7F4:
    ctx->pc = 0x802DF7F4u;
    // 802DF7F4: addi    r5, r30, 296
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(296);

label_802DF7F8:
    ctx->pc = 0x802DF7F8u;
    // 802DF7F8: addi    r6, r30, 316
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(316);

label_802DF7FC:
    ctx->pc = 0x802DF7FCu;
    // 802DF7FC: addi    r7, r30, 320
    ctx->gpr[7] = ctx->gpr[30] + (u32)(s32)(320);

label_802DF800:
    ctx->pc = 0x802DF800u;
    // 802DF800: bl      0x802DDDBC
    {
            ctx->lr = 0x802DF804u;
            ctx->pc = 0x802DDDBCu;
            return;
    }

label_802DF804:
    ctx->pc = 0x802DF804u;
    ctx->downcount -= 11;
    // 802DF804: lwz     r0, 304(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(304);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF808:
    ctx->pc = 0x802DF808u;
    // 802DF808: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DF80C:
    ctx->pc = 0x802DF80Cu;
    // 802DF80C: lhz     r3, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_802DF810:
    ctx->pc = 0x802DF810u;
    // 802DF810: lhz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_802DF814:
    ctx->pc = 0x802DF814u;
    // 802DF814: lbz     r5, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_802DF818:
    ctx->pc = 0x802DF818u;
    // 802DF818: lhz     r6, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_802DF81C:
    ctx->pc = 0x802DF81Cu;
    // 802DF81C: lhz     r7, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_802DF820:
    ctx->pc = 0x802DF820u;
    // 802DF820: lhz     r8, 6(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_802DF824:
    ctx->pc = 0x802DF824u;
    // 802DF824: lhz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_802DF828:
    ctx->pc = 0x802DF828u;
    // 802DF828: lhz     r10, 10(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(10);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_802DF82C:
    ctx->pc = 0x802DF82Cu;
    // 802DF82C: bl      0x802DE15C
    {
            ctx->lr = 0x802DF830u;
            ctx->pc = 0x802DE15Cu;
            return;
    }

label_802DF830:
    ctx->pc = 0x802DF830u;
    ctx->downcount -= 2;
    // 802DF830: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802DF834:
    ctx->pc = 0x802DF834u;
    // 802DF834: bl      0x802C3110
    {
            ctx->lr = 0x802DF838u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802DF838:
    ctx->pc = 0x802DF838u;
    ctx->downcount -= 16;
    // 802DF838: lmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802DF83C:
    ctx->pc = 0x802DF83Cu;
    // 802DF83C: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF840:
    ctx->pc = 0x802DF840u;
    // 802DF840: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_802DF844:
    ctx->pc = 0x802DF844u;
    // 802DF844: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DF848:
    ctx->pc = 0x802DF848u;
    // 802DF848: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF84C:
    ctx->pc = 0x802DF84Cu;
    ctx->downcount -= 8;
    // 802DF84C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DF850:
    ctx->pc = 0x802DF850u;
    // 802DF850: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DF854:
    ctx->pc = 0x802DF854u;
    // 802DF854: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DF858:
    ctx->pc = 0x802DF858u;
    // 802DF858: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DF85C:
    ctx->pc = 0x802DF85Cu;
    // 802DF85C: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_802DF860:
    ctx->pc = 0x802DF860u;
    // 802DF860: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802DF864:
    ctx->pc = 0x802DF864u;
    // 802DF864: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_802DF868:
    ctx->pc = 0x802DF868u;
    // 802DF868: bl      0x802C30E8
    {
            ctx->lr = 0x802DF86Cu;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802DF86C:
    ctx->pc = 0x802DF86Cu;
    ctx->downcount -= 5;
    // 802DF86C: lha     r0, -25168(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25168);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_802DF870:
    ctx->pc = 0x802DF870u;
    // 802DF870: sth     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802DF874:
    ctx->pc = 0x802DF874u;
    // 802DF874: lha     r0, -25166(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25166);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_802DF878:
    ctx->pc = 0x802DF878u;
    // 802DF878: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802DF87C:
    ctx->pc = 0x802DF87Cu;
    // 802DF87C: bl      0x802C3110
    {
            ctx->lr = 0x802DF880u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802DF880:
    ctx->pc = 0x802DF880u;
    ctx->downcount -= 7;
    // 802DF880: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF884:
    ctx->pc = 0x802DF884u;
    // 802DF884: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802DF888:
    ctx->pc = 0x802DF888u;
    // 802DF888: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802DF88C:
    ctx->pc = 0x802DF88Cu;
    // 802DF88C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802DF890:
    ctx->pc = 0x802DF890u;
    // 802DF890: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DF894:
    ctx->pc = 0x802DF894u;
    // 802DF894: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF898:
    ctx->pc = 0x802DF898u;
    ctx->downcount -= 1;
    // 802DF898: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF89C:
    ctx->pc = 0x802DF89Cu;
    ctx->downcount -= 1;
    // 802DF89C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8A0:
    ctx->pc = 0x802DF8A0u;
    ctx->downcount -= 2;
    // 802DF8A0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DF8A4:
    ctx->pc = 0x802DF8A4u;
    // 802DF8A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8A8:
    ctx->pc = 0x802DF8A8u;
    ctx->downcount -= 2;
    // 802DF8A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DF8AC:
    ctx->pc = 0x802DF8ACu;
    // 802DF8AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8B0:
    ctx->pc = 0x802DF8B0u;
    ctx->downcount -= 2;
    // 802DF8B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DF8B4:
    ctx->pc = 0x802DF8B4u;
    // 802DF8B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8B8:
    ctx->pc = 0x802DF8B8u;
    ctx->downcount -= 1;
    // 802DF8B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8BC:
    ctx->pc = 0x802DF8BCu;
    ctx->downcount -= 1;
    // 802DF8BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8C0:
    ctx->pc = 0x802DF8C0u;
    ctx->downcount -= 2;
    // 802DF8C0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802DF8C4:
    ctx->pc = 0x802DF8C4u;
    // 802DF8C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8C8:
    ctx->pc = 0x802DF8C8u;
    ctx->downcount -= 1;
    // 802DF8C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8CC:
    ctx->pc = 0x802DF8CCu;
    ctx->downcount -= 1;
    // 802DF8CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DF8D0:
    ctx->pc = 0x802DF8D0u;
    ctx->downcount -= 17;
    // 802DF8D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DF8D4:
    ctx->pc = 0x802DF8D4u;
    // 802DF8D4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DF8D8:
    ctx->pc = 0x802DF8D8u;
    // 802DF8D8: stwu     r1, -120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-120);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DF8DC:
    ctx->pc = 0x802DF8DCu;
    // 802DF8DC: stmw     r24, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        for (u32 r = 24; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802DF8E0:
    ctx->pc = 0x802DF8E0u;
    // 802DF8E0: addi    r26, r3, 0
    ctx->gpr[26] = ctx->gpr[3] + (u32)(s32)(0);

label_802DF8E4:
    ctx->pc = 0x802DF8E4u;
    // 802DF8E4: addi    r27, r4, 0
    ctx->gpr[27] = ctx->gpr[4] + (u32)(s32)(0);

label_802DF8E8:
    ctx->pc = 0x802DF8E8u;
    // 802DF8E8: bl      0x802C30E8
    {
            ctx->lr = 0x802DF8ECu;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802DF8EC:
    ctx->pc = 0x802DF8ECu;
    ctx->downcount -= 3;
    // 802DF8EC: addi    r28, r3, 0
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(0);

label_802DF8F0:
    ctx->pc = 0x802DF8F0u;
    // 802DF8F0: lis     r25, -13312
    ctx->gpr[25] = ((u32)(s32)(-13312) << 16);

label_802DF8F4:
    ctx->pc = 0x802DF8F4u;
    // 802DF8F4: lis     r31, 16384
    ctx->gpr[31] = ((u32)(s32)(16384) << 16);

label_802DF8F8:
    ctx->pc = 0x802DF8F8u;
    ctx->downcount -= 10;
    // 802DF8F8: lwz     r0, 26664(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(26664);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF8FC:
    // 802DF8FC: addi    r30, r25, 26624
    ctx->gpr[30] = ctx->gpr[25] + (u32)(s32)(26624);

label_802DF900:
    // 802DF900: addi    r3, r1, 80
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(80);

label_802DF904:
    // 802DF904: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DF908:
    // 802DF908: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802DF90C:
    // 802DF90C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802DF910:
    // 802DF910: ori     r0, r0, 0x00C0
    ctx->gpr[0] = ctx->gpr[0] | 0x00C0u;

label_802DF914:
    ctx->pc = 0x802DF914u;
    // 802DF914: stwu     r0, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
        ctx->gpr[30] = ea;
    }

label_802DF918:
    ctx->pc = 0x802DF918u;
    // 802DF918: stw     r31, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DF91C:
    // 802DF91C: bl      0x802E0350
    {
            ctx->lr = 0x802DF920u;
            goto label_802E0350;
    }

label_802DF920:
    ctx->downcount -= 2;
    // 802DF920: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DF924:
    // 802DF924: rlwinm r24, r0, 27, 5, 31
    {
        ctx->gpr[24] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DF928:
    loop_802DF928(ctx);
    if (ctx->pc == 0x802DF938u) goto label_802DF938;
    return;
label_802DF92C:
    ctx->pc = 0x802DF92Cu;
    // 802DF92C: lwzu     r0, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[29] = ea;
    }

label_802DF930:
    // 802DF930: rlwinm. r0, r0, 0, 31, 31
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

label_802DF934:
    // 802DF934: bc    4, 2, 0x802DF928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF928u;
                return;
            }
            goto label_802DF928;
        }
    }

label_802DF938:
    ctx->downcount -= 4;
    // 802DF938: addi    r3, r1, 84
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(84);

label_802DF93C:
    // 802DF93C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802DF940:
    // 802DF940: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802DF944:
    // 802DF944: bl      0x802E0350
    {
            ctx->lr = 0x802DF948u;
            goto label_802E0350;
    }

label_802DF948:
    loop_802DF948(ctx);
    if (ctx->pc == 0x802DF954u) goto label_802DF954;
    return;
label_802DF94C:
    // 802DF94C: rlwinm. r0, r0, 0, 31, 31
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

label_802DF950:
    // 802DF950: bc    4, 2, 0x802DF948
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF948u;
                return;
            }
            goto label_802DF948;
        }
    }

label_802DF954:
    ctx->pc = 0x802DF954u;
    ctx->downcount -= 6;
    // 802DF954: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF958:
    // 802DF958: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DF95C:
    ctx->pc = 0x802DF95Cu;
    // 802DF95C: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DF960:
    ctx->pc = 0x802DF960u;
    // 802DF960: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF964:
    // 802DF964: rlwinm. r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DF968:
    // 802DF968: bc    4, 2, 0x802DF8F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF8F8u;
                return;
            }
            goto label_802DF8F8;
        }
    }

label_802DF96C:
    ctx->pc = 0x802DF96Cu;
    ctx->downcount -= 6;
    // 802DF96C: lbz     r3, -27872(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27872);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_802DF970:
    ctx->pc = 0x802DF970u;
    // 802DF970: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_802DF974:
    ctx->pc = 0x802DF974u;
    // 802DF974: stb     r0, -27872(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27872);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802DF978:
    ctx->pc = 0x802DF978u;
    // 802DF978: lbz     r0, -27872(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27872);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802DF97C:
    ctx->pc = 0x802DF97Cu;
    // 802DF97C: rlwinm. r0, r0, 0, 31, 31
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

label_802DF980:
    ctx->pc = 0x802DF980u;
    // 802DF980: bc    12, 2, 0x802DF98C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802DF98C;
        }
    }

label_802DF984:
    ctx->pc = 0x802DF984u;
    ctx->downcount -= 2;
    // 802DF984: li      r3, 4096
    ctx->gpr[3] = (u32)(s32)(4096);

label_802DF988:
    ctx->pc = 0x802DF988u;
    // 802DF988: b       0x802DF990
    {
            goto label_802DF990;
    }

label_802DF98C:
    ctx->pc = 0x802DF98Cu;
    ctx->downcount -= 1;
    // 802DF98C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DF990:
    ctx->pc = 0x802DF990u;
    ctx->downcount -= 4;
    // 802DF990: addi    r0, r27, 3
    ctx->gpr[0] = ctx->gpr[27] + (u32)(s32)(3);

label_802DF994:
    ctx->pc = 0x802DF994u;
    // 802DF994: oris    r25, r3, 0x0001
    ctx->gpr[25] = ctx->gpr[3] | (0x0001u << 16);

label_802DF998:
    ctx->pc = 0x802DF998u;
    // 802DF998: rlwinm r24, r0, 0, 0, 29
    {
        ctx->gpr[24] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_802DF99C:
    ctx->pc = 0x802DF99Cu;
    // 802DF99C: ori     r25, r25, 0xC000
    ctx->gpr[25] = ctx->gpr[25] | 0xC000u;

label_802DF9A0:
    ctx->downcount -= 4;
    // 802DF9A0: addi    r3, r25, 0
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(0);

label_802DF9A4:
    // 802DF9A4: addi    r4, r26, 0
    ctx->gpr[4] = ctx->gpr[26] + (u32)(s32)(0);

label_802DF9A8:
    // 802DF9A8: addi    r5, r24, 0
    ctx->gpr[5] = ctx->gpr[24] + (u32)(s32)(0);

label_802DF9AC:
    // 802DF9AC: bl      0x802DFF9C
    {
            ctx->lr = 0x802DF9B0u;
            goto label_802DFF9C;
    }

label_802DF9B0:
    ctx->downcount -= 2;
    // 802DF9B0: cmpwi   r3, 0
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

label_802DF9B4:
    // 802DF9B4: bc    12, 2, 0x802DF9A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF9A0u;
                return;
            }
            goto label_802DF9A0;
        }
    }

label_802DF9B8:
    ctx->pc = 0x802DF9B8u;
    ctx->downcount -= 1;
    // 802DF9B8: lis     r31, 16384
    ctx->gpr[31] = ((u32)(s32)(16384) << 16);

label_802DF9BC:
    ctx->pc = 0x802DF9BCu;
    ctx->downcount -= 9;
    // 802DF9BC: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DF9C0:
    // 802DF9C0: addi    r3, r1, 76
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(76);

label_802DF9C4:
    // 802DF9C4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802DF9C8:
    // 802DF9C8: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DF9CC:
    // 802DF9CC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802DF9D0:
    // 802DF9D0: ori     r0, r0, 0x00C0
    ctx->gpr[0] = ctx->gpr[0] | 0x00C0u;

label_802DF9D4:
    ctx->pc = 0x802DF9D4u;
    // 802DF9D4: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DF9D8:
    ctx->pc = 0x802DF9D8u;
    // 802DF9D8: stw     r31, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DF9DC:
    // 802DF9DC: bl      0x802E0350
    {
            ctx->lr = 0x802DF9E0u;
            goto label_802E0350;
    }

label_802DF9E0:
    ctx->downcount -= 2;
    // 802DF9E0: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DF9E4:
    // 802DF9E4: rlwinm r26, r0, 27, 5, 31
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DF9E8:
    loop_802DF9E8(ctx);
    if (ctx->pc == 0x802DF9F4u) goto label_802DF9F4;
    return;
label_802DF9EC:
    // 802DF9EC: rlwinm. r0, r0, 0, 31, 31
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

label_802DF9F0:
    // 802DF9F0: bc    4, 2, 0x802DF9E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF9E8u;
                return;
            }
            goto label_802DF9E8;
        }
    }

label_802DF9F4:
    ctx->downcount -= 4;
    // 802DF9F4: addi    r3, r1, 84
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(84);

label_802DF9F8:
    // 802DF9F8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802DF9FC:
    // 802DF9FC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802DFA00:
    // 802DFA00: bl      0x802E0350
    {
            ctx->lr = 0x802DFA04u;
            goto label_802E0350;
    }

label_802DFA04:
    loop_802DFA04(ctx);
    if (ctx->pc == 0x802DFA10u) goto label_802DFA10;
    return;
label_802DFA08:
    // 802DFA08: rlwinm. r0, r0, 0, 31, 31
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

label_802DFA0C:
    // 802DFA0C: bc    4, 2, 0x802DFA04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFA04u;
                return;
            }
            goto label_802DFA04;
        }
    }

label_802DFA10:
    ctx->pc = 0x802DFA10u;
    ctx->downcount -= 6;
    // 802DFA10: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFA14:
    // 802DFA14: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFA18:
    ctx->pc = 0x802DFA18u;
    // 802DFA18: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFA1C:
    ctx->pc = 0x802DFA1Cu;
    // 802DFA1C: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFA20:
    // 802DFA20: rlwinm. r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFA24:
    // 802DFA24: bc    4, 2, 0x802DF9BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DF9BCu;
                return;
            }
            goto label_802DF9BC;
        }
    }

label_802DFA28:
    ctx->pc = 0x802DFA28u;
    ctx->downcount -= 6;
    // 802DFA28: lbz     r0, -27872(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27872);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802DFA2C:
    ctx->pc = 0x802DFA2Cu;
    // 802DFA2C: rlwinm r0, r0, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0xFFFF0000u;
    }

label_802DFA30:
    ctx->pc = 0x802DFA30u;
    // 802DFA30: oris    r0, r0, 0x1F00
    ctx->gpr[0] = ctx->gpr[0] | (0x1F00u << 16);

label_802DFA34:
    ctx->pc = 0x802DFA34u;
    // 802DFA34: or   r0, r0, r27
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[27];
    }

label_802DFA38:
    ctx->pc = 0x802DFA38u;
    // 802DFA38: rlwinm r0, r0, 0, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x1FFFFFFFu;
    }

label_802DFA3C:
    ctx->pc = 0x802DFA3Cu;
    // 802DFA3C: oris    r24, r0, 0xC000
    ctx->gpr[24] = ctx->gpr[0] | (0xC000u << 16);

label_802DFA40:
    ctx->pc = 0x802DFA40u;
    ctx->downcount -= 9;
    // 802DFA40: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFA44:
    // 802DFA44: addi    r3, r1, 68
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(68);

label_802DFA48:
    // 802DFA48: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802DFA4C:
    // 802DFA4C: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFA50:
    // 802DFA50: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802DFA54:
    // 802DFA54: ori     r0, r0, 0x00C0
    ctx->gpr[0] = ctx->gpr[0] | 0x00C0u;

label_802DFA58:
    ctx->pc = 0x802DFA58u;
    // 802DFA58: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFA5C:
    ctx->pc = 0x802DFA5Cu;
    // 802DFA5C: stw     r24, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_802DFA60:
    // 802DFA60: bl      0x802E0350
    {
            ctx->lr = 0x802DFA64u;
            goto label_802E0350;
    }

label_802DFA64:
    ctx->downcount -= 2;
    // 802DFA64: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFA68:
    // 802DFA68: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFA6C:
    loop_802DFA6C(ctx);
    if (ctx->pc == 0x802DFA78u) goto label_802DFA78;
    return;
label_802DFA70:
    // 802DFA70: rlwinm. r0, r0, 0, 31, 31
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

label_802DFA74:
    // 802DFA74: bc    4, 2, 0x802DFA6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFA6Cu;
                return;
            }
            goto label_802DFA6C;
        }
    }

label_802DFA78:
    ctx->pc = 0x802DFA78u;
    ctx->downcount -= 5;
    // 802DFA78: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFA7C:
    // 802DFA7C: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFA80:
    // 802DFA80: cmpwi   r3, 0
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

label_802DFA84:
    ctx->pc = 0x802DFA84u;
    // 802DFA84: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFA88:
    // 802DFA88: bc    4, 2, 0x802DFA40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFA40u;
                return;
            }
            goto label_802DFA40;
        }
    }

label_802DFA8C:
    ctx->pc = 0x802DFA8Cu;
    ctx->downcount -= 1;
    // 802DFA8C: lis     r27, 16384
    ctx->gpr[27] = ((u32)(s32)(16384) << 16);

label_802DFA90:
    ctx->pc = 0x802DFA90u;
    ctx->downcount -= 9;
    // 802DFA90: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFA94:
    // 802DFA94: addi    r3, r1, 60
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(60);

label_802DFA98:
    // 802DFA98: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802DFA9C:
    // 802DFA9C: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFAA0:
    // 802DFAA0: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802DFAA4:
    // 802DFAA4: ori     r0, r0, 0x00C0
    ctx->gpr[0] = ctx->gpr[0] | 0x00C0u;

label_802DFAA8:
    ctx->pc = 0x802DFAA8u;
    // 802DFAA8: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFAAC:
    ctx->pc = 0x802DFAACu;
    // 802DFAAC: stw     r27, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_802DFAB0:
    // 802DFAB0: bl      0x802E0350
    {
            ctx->lr = 0x802DFAB4u;
            goto label_802E0350;
    }

label_802DFAB4:
    ctx->downcount -= 2;
    // 802DFAB4: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFAB8:
    // 802DFAB8: rlwinm r26, r0, 27, 5, 31
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFABC:
    loop_802DFABC(ctx);
    if (ctx->pc == 0x802DFAC8u) goto label_802DFAC8;
    return;
label_802DFAC0:
    // 802DFAC0: rlwinm. r0, r0, 0, 31, 31
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

label_802DFAC4:
    // 802DFAC4: bc    4, 2, 0x802DFABC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFABCu;
                return;
            }
            goto label_802DFABC;
        }
    }

label_802DFAC8:
    ctx->downcount -= 4;
    // 802DFAC8: addi    r3, r1, 84
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(84);

label_802DFACC:
    // 802DFACC: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802DFAD0:
    // 802DFAD0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802DFAD4:
    // 802DFAD4: bl      0x802E0350
    {
            ctx->lr = 0x802DFAD8u;
            goto label_802E0350;
    }

label_802DFAD8:
    ctx->downcount -= 3;
    // 802DFAD8: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFADC:
    // 802DFADC: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFAE0:
    // 802DFAE0: or   r3, r26, r0
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[0];
    }

label_802DFAE4:
    loop_802DFAE4(ctx);
    if (ctx->pc == 0x802DFAF0u) goto label_802DFAF0;
    return;
label_802DFAE8:
    // 802DFAE8: rlwinm. r0, r0, 0, 31, 31
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

label_802DFAEC:
    // 802DFAEC: bc    4, 2, 0x802DFAE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFAE4u;
                return;
            }
            goto label_802DFAE4;
        }
    }

label_802DFAF0:
    ctx->pc = 0x802DFAF0u;
    ctx->downcount -= 5;
    // 802DFAF0: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFAF4:
    // 802DFAF4: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFAF8:
    // 802DFAF8: cmpwi   r3, 0
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

label_802DFAFC:
    ctx->pc = 0x802DFAFCu;
    // 802DFAFC: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFB00:
    // 802DFB00: bc    4, 2, 0x802DFA90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFA90u;
                return;
            }
            goto label_802DFA90;
        }
    }

label_802DFB04:
    ctx->pc = 0x802DFB04u;
    ctx->downcount -= 3;
    // 802DFB04: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFB08:
    // 802DFB08: rlwinm. r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFB0C:
    // 802DFB0C: bc    4, 2, 0x802DFA90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFA90u;
                return;
            }
            goto label_802DFA90;
        }
    }

label_802DFB10:
    ctx->pc = 0x802DFB10u;
    ctx->downcount -= 2;
    // 802DFB10: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_802DFB14:
    ctx->pc = 0x802DFB14u;
    // 802DFB14: bl      0x802C3110
    {
            ctx->lr = 0x802DFB18u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802DFB18:
    ctx->pc = 0x802DFB18u;
    ctx->downcount -= 17;
    // 802DFB18: lmw     r24, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        for (u32 r = 24; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802DFB1C:
    ctx->pc = 0x802DFB1Cu;
    // 802DFB1C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DFB20:
    ctx->pc = 0x802DFB20u;
    // 802DFB20: lwz     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFB24:
    ctx->pc = 0x802DFB24u;
    // 802DFB24: addi    r1, r1, 120
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(120);

label_802DFB28:
    ctx->pc = 0x802DFB28u;
    // 802DFB28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFB2C:
    ctx->pc = 0x802DFB2Cu;
    // 802DFB2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFB30:
    ctx->pc = 0x802DFB30u;
    ctx->downcount -= 9;
    // 802DFB30: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFB34:
    ctx->pc = 0x802DFB34u;
    // 802DFB34: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFB38:
    ctx->pc = 0x802DFB38u;
    // 802DFB38: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFB3C:
    ctx->pc = 0x802DFB3Cu;
    // 802DFB3C: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DFB40:
    ctx->pc = 0x802DFB40u;
    // 802DFB40: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802DFB44:
    ctx->pc = 0x802DFB44u;
    // 802DFB44: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_802DFB48:
    ctx->pc = 0x802DFB48u;
    // 802DFB48: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802DFB4C:
    ctx->pc = 0x802DFB4Cu;
    // 802DFB4C: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802DFB50:
    ctx->pc = 0x802DFB50u;
    // 802DFB50: bl      0x802C30E8
    {
            ctx->lr = 0x802DFB54u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802DFB54:
    ctx->pc = 0x802DFB54u;
    ctx->downcount -= 4;
    // 802DFB54: lwz     r0, -25104(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25104);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFB58:
    ctx->pc = 0x802DFB58u;
    // 802DFB58: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802DFB5C:
    ctx->pc = 0x802DFB5Cu;
    // 802DFB5C: rlwinm. r0, r0, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00010000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFB60:
    ctx->pc = 0x802DFB60u;
    // 802DFB60: bc    12, 2, 0x802DFB6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802DFB6C;
        }
    }

label_802DFB64:
    ctx->pc = 0x802DFB64u;
    ctx->downcount -= 2;
    // 802DFB64: li      r3, 4096
    ctx->gpr[3] = (u32)(s32)(4096);

label_802DFB68:
    ctx->pc = 0x802DFB68u;
    // 802DFB68: b       0x802DFB70
    {
            goto label_802DFB70;
    }

label_802DFB6C:
    ctx->pc = 0x802DFB6Cu;
    ctx->downcount -= 1;
    // 802DFB6C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DFB70:
    ctx->pc = 0x802DFB70u;
    ctx->downcount -= 6;
    // 802DFB70: addis   r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + ((u32)(s32)(2) << 16);

label_802DFB74:
    ctx->pc = 0x802DFB74u;
    // 802DFB74: addi    r0, r30, 3
    ctx->gpr[0] = ctx->gpr[30] + (u32)(s32)(3);

label_802DFB78:
    ctx->pc = 0x802DFB78u;
    // 802DFB78: addi    r4, r29, 0
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(0);

label_802DFB7C:
    ctx->pc = 0x802DFB7Cu;
    // 802DFB7C: rlwinm r5, r0, 0, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_802DFB80:
    ctx->pc = 0x802DFB80u;
    // 802DFB80: addi    r3, r3, -8192
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-8192);

label_802DFB84:
    ctx->pc = 0x802DFB84u;
    // 802DFB84: bl      0x802E0078
    {
            ctx->lr = 0x802DFB88u;
            goto label_802E0078;
    }

label_802DFB88:
    ctx->pc = 0x802DFB88u;
    ctx->downcount -= 5;
    // 802DFB88: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802DFB8C:
    ctx->pc = 0x802DFB8Cu;
    // 802DFB8C: stw     r0, -25100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFB90:
    ctx->pc = 0x802DFB90u;
    // 802DFB90: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802DFB94:
    ctx->pc = 0x802DFB94u;
    // 802DFB94: stb     r0, -25092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25092);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802DFB98:
    ctx->pc = 0x802DFB98u;
    // 802DFB98: bl      0x802C3110
    {
            ctx->lr = 0x802DFB9Cu;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802DFB9C:
    ctx->pc = 0x802DFB9Cu;
    ctx->downcount -= 9;
    // 802DFB9C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFBA0:
    ctx->pc = 0x802DFBA0u;
    // 802DFBA0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DFBA4:
    ctx->pc = 0x802DFBA4u;
    // 802DFBA4: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802DFBA8:
    ctx->pc = 0x802DFBA8u;
    // 802DFBA8: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802DFBAC:
    ctx->pc = 0x802DFBACu;
    // 802DFBAC: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802DFBB0:
    ctx->pc = 0x802DFBB0u;
    // 802DFBB0: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802DFBB4:
    ctx->pc = 0x802DFBB4u;
    // 802DFBB4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFBB8:
    ctx->pc = 0x802DFBB8u;
    // 802DFBB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFBBC:
    ctx->pc = 0x802DFBBCu;
    ctx->downcount -= 9;
    // 802DFBBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFBC0:
    ctx->pc = 0x802DFBC0u;
    // 802DFBC0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DFBC4:
    ctx->pc = 0x802DFBC4u;
    // 802DFBC4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFBC8:
    ctx->pc = 0x802DFBC8u;
    // 802DFBC8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFBCC:
    ctx->pc = 0x802DFBCCu;
    // 802DFBCC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DFBD0:
    ctx->pc = 0x802DFBD0u;
    // 802DFBD0: lwz     r0, -25100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFBD4:
    ctx->pc = 0x802DFBD4u;
    // 802DFBD4: stb     r3, -25092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25092);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802DFBD8:
    ctx->pc = 0x802DFBD8u;
    // 802DFBD8: cmpwi   r0, 0
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

label_802DFBDC:
    ctx->pc = 0x802DFBDCu;
    // 802DFBDC: bc    4, 2, 0x802DFC40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DFC40;
        }
    }

label_802DFBE0:
    ctx->pc = 0x802DFBE0u;
    ctx->downcount -= 1;
    // 802DFBE0: bl      0x802C30E8
    {
            ctx->lr = 0x802DFBE4u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802DFBE4:
    ctx->pc = 0x802DFBE4u;
    ctx->downcount -= 3;
    // 802DFBE4: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802DFBE8:
    ctx->pc = 0x802DFBE8u;
    // 802DFBE8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_802DFBEC:
    ctx->pc = 0x802DFBECu;
    // 802DFBEC: bl      0x802DFEF0
    {
            ctx->lr = 0x802DFBF0u;
            goto label_802DFEF0;
    }

label_802DFBF0:
    ctx->pc = 0x802DFBF0u;
    ctx->downcount -= 3;
    // 802DFBF0: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFBF4:
    ctx->pc = 0x802DFBF4u;
    // 802DFBF4: rlwinm. r0, r0, 0, 31, 31
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

label_802DFBF8:
    ctx->pc = 0x802DFBF8u;
    // 802DFBF8: bc    12, 2, 0x802DFC38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802DFC38;
        }
    }

label_802DFBFC:
    ctx->pc = 0x802DFBFCu;
    ctx->downcount -= 2;
    // 802DFBFC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_802DFC00:
    ctx->pc = 0x802DFC00u;
    // 802DFC00: bl      0x802E0154
    {
            ctx->lr = 0x802DFC04u;
            goto label_802E0154;
    }

label_802DFC04:
    ctx->pc = 0x802DFC04u;
    ctx->downcount -= 8;
    // 802DFC04: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFC08:
    ctx->pc = 0x802DFC08u;
    // 802DFC08: rlwinm r0, r0, 0, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x1FFFFFFFu;
    }

label_802DFC0C:
    ctx->pc = 0x802DFC0Cu;
    // 802DFC0C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFC10:
    ctx->pc = 0x802DFC10u;
    // 802DFC10: lwz     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802DFC14:
    ctx->pc = 0x802DFC14u;
    // 802DFC14: rlwinm r3, r4, 0, 3, 7
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x1F000000u;
    }

label_802DFC18:
    ctx->pc = 0x802DFC18u;
    // 802DFC18: addis   r0, r3, -7936
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-7936) << 16);

label_802DFC1C:
    ctx->pc = 0x802DFC1Cu;
    // 802DFC1C: cmplwi  r0, 0x0000
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

label_802DFC20:
    ctx->pc = 0x802DFC20u;
    // 802DFC20: bc    4, 2, 0x802DFC38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DFC38;
        }
    }

label_802DFC24:
    ctx->pc = 0x802DFC24u;
    ctx->downcount -= 5;
    // 802DFC24: rlwinm r3, r4, 0, 17, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00007FFFu;
    }

label_802DFC28:
    ctx->pc = 0x802DFC28u;
    // 802DFC28: stw     r4, -25104(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25104);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802DFC2C:
    ctx->pc = 0x802DFC2Cu;
    // 802DFC2C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802DFC30:
    ctx->pc = 0x802DFC30u;
    // 802DFC30: stw     r3, -25100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25100);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802DFC34:
    ctx->pc = 0x802DFC34u;
    // 802DFC34: stb     r0, -25092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25092);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802DFC38:
    ctx->pc = 0x802DFC38u;
    ctx->downcount -= 2;
    // 802DFC38: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802DFC3C:
    ctx->pc = 0x802DFC3Cu;
    // 802DFC3C: bl      0x802C3110
    {
            ctx->lr = 0x802DFC40u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802DFC40:
    ctx->pc = 0x802DFC40u;
    ctx->downcount -= 7;
    // 802DFC40: lwz     r3, -25100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25100);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802DFC44:
    ctx->pc = 0x802DFC44u;
    // 802DFC44: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFC48:
    ctx->pc = 0x802DFC48u;
    // 802DFC48: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802DFC4C:
    ctx->pc = 0x802DFC4Cu;
    // 802DFC4C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802DFC50:
    ctx->pc = 0x802DFC50u;
    // 802DFC50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFC54:
    ctx->pc = 0x802DFC54u;
    // 802DFC54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFC58:
    ctx->pc = 0x802DFC58u;
    ctx->downcount -= 19;
    // 802DFC58: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFC5C:
    ctx->pc = 0x802DFC5Cu;
    // 802DFC5C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802DFC60:
    ctx->pc = 0x802DFC60u;
    // 802DFC60: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFC64:
    ctx->pc = 0x802DFC64u;
    // 802DFC64: lis     r0, 16384
    ctx->gpr[0] = ((u32)(s32)(16384) << 16);

label_802DFC68:
    ctx->pc = 0x802DFC68u;
    // 802DFC68: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802DFC6C:
    ctx->pc = 0x802DFC6Cu;
    // 802DFC6C: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFC70:
    ctx->pc = 0x802DFC70u;
    // 802DFC70: stw     r31, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DFC74:
    ctx->pc = 0x802DFC74u;
    // 802DFC74: addi    r3, r1, 36
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(36);

label_802DFC78:
    ctx->pc = 0x802DFC78u;
    // 802DFC78: stw     r30, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802DFC7C:
    ctx->pc = 0x802DFC7Cu;
    // 802DFC7C: stw     r29, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802DFC80:
    ctx->pc = 0x802DFC80u;
    // 802DFC80: stw     r28, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_802DFC84:
    ctx->pc = 0x802DFC84u;
    // 802DFC84: lis     r28, -13312
    ctx->gpr[28] = ((u32)(s32)(-13312) << 16);

label_802DFC88:
    ctx->pc = 0x802DFC88u;
    // 802DFC88: addi    r31, r28, 26624
    ctx->gpr[31] = ctx->gpr[28] + (u32)(s32)(26624);

label_802DFC8C:
    ctx->pc = 0x802DFC8Cu;
    // 802DFC8C: lwz     r6, 26664(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(26664);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802DFC90:
    ctx->pc = 0x802DFC90u;
    // 802DFC90: andi.   r6, r6, 0x0405
    {
        ctx->gpr[6] = ctx->gpr[6] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFC94:
    ctx->pc = 0x802DFC94u;
    // 802DFC94: ori     r6, r6, 0x00C0
    ctx->gpr[6] = ctx->gpr[6] | 0x00C0u;

label_802DFC98:
    ctx->pc = 0x802DFC98u;
    // 802DFC98: stwu     r6, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[31] = ea;
    }

label_802DFC9C:
    ctx->pc = 0x802DFC9Cu;
    // 802DFC9C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFCA0:
    ctx->pc = 0x802DFCA0u;
    // 802DFCA0: bl      0x802E0350
    {
            ctx->lr = 0x802DFCA4u;
            goto label_802E0350;
    }

label_802DFCA4:
    ctx->pc = 0x802DFCA4u;
    ctx->downcount -= 2;
    // 802DFCA4: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFCA8:
    ctx->pc = 0x802DFCA8u;
    // 802DFCA8: rlwinm r29, r0, 27, 5, 31
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFCAC:
    loop_802DFCAC(ctx);
    if (ctx->pc == 0x802DFCBCu) goto label_802DFCBC;
    return;
label_802DFCB0:
    ctx->pc = 0x802DFCB0u;
    // 802DFCB0: lwzu     r0, 52(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[30] = ea;
    }

label_802DFCB4:
    // 802DFCB4: rlwinm. r0, r0, 0, 31, 31
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

label_802DFCB8:
    // 802DFCB8: bc    4, 2, 0x802DFCAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFCACu;
                return;
            }
            goto label_802DFCAC;
        }
    }

label_802DFCBC:
    ctx->pc = 0x802DFCBCu;
    ctx->downcount -= 4;
    // 802DFCBC: addi    r3, r1, 40
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(40);

label_802DFCC0:
    ctx->pc = 0x802DFCC0u;
    // 802DFCC0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802DFCC4:
    ctx->pc = 0x802DFCC4u;
    // 802DFCC4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802DFCC8:
    ctx->pc = 0x802DFCC8u;
    // 802DFCC8: bl      0x802E0350
    {
            ctx->lr = 0x802DFCCCu;
            goto label_802E0350;
    }

label_802DFCCC:
    loop_802DFCCC(ctx);
    if (ctx->pc == 0x802DFCD8u) goto label_802DFCD8;
    return;
label_802DFCD0:
    // 802DFCD0: rlwinm. r0, r0, 0, 31, 31
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

label_802DFCD4:
    // 802DFCD4: bc    4, 2, 0x802DFCCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFCCCu;
                return;
            }
            goto label_802DFCCC;
        }
    }

label_802DFCD8:
    ctx->pc = 0x802DFCD8u;
    ctx->downcount -= 6;
    // 802DFCD8: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFCDC:
    ctx->pc = 0x802DFCDCu;
    // 802DFCDC: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFCE0:
    ctx->pc = 0x802DFCE0u;
    // 802DFCE0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFCE4:
    ctx->pc = 0x802DFCE4u;
    // 802DFCE4: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFCE8:
    ctx->pc = 0x802DFCE8u;
    // 802DFCE8: rlwinm. r0, r0, 0, 31, 31
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

label_802DFCEC:
    ctx->pc = 0x802DFCECu;
    // 802DFCEC: bc    12, 2, 0x802DFD88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802DFD88;
        }
    }

label_802DFCF0:
    ctx->pc = 0x802DFCF0u;
    ctx->downcount -= 10;
    // 802DFCF0: lwz     r6, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802DFCF4:
    ctx->pc = 0x802DFCF4u;
    // 802DFCF4: lis     r0, 24576
    ctx->gpr[0] = ((u32)(s32)(24576) << 16);

label_802DFCF8:
    ctx->pc = 0x802DFCF8u;
    // 802DFCF8: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_802DFCFC:
    ctx->pc = 0x802DFCFCu;
    // 802DFCFC: andi.   r6, r6, 0x0405
    {
        ctx->gpr[6] = ctx->gpr[6] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFD00:
    ctx->pc = 0x802DFD00u;
    // 802DFD00: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802DFD04:
    ctx->pc = 0x802DFD04u;
    // 802DFD04: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802DFD08:
    ctx->pc = 0x802DFD08u;
    // 802DFD08: ori     r6, r6, 0x00C0
    ctx->gpr[6] = ctx->gpr[6] | 0x00C0u;

label_802DFD0C:
    ctx->pc = 0x802DFD0Cu;
    // 802DFD0C: stw     r6, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802DFD10:
    ctx->pc = 0x802DFD10u;
    // 802DFD10: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFD14:
    ctx->pc = 0x802DFD14u;
    // 802DFD14: bl      0x802E0350
    {
            ctx->lr = 0x802DFD18u;
            goto label_802E0350;
    }

label_802DFD18:
    ctx->pc = 0x802DFD18u;
    ctx->downcount -= 2;
    // 802DFD18: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFD1C:
    ctx->pc = 0x802DFD1Cu;
    // 802DFD1C: rlwinm r29, r0, 27, 5, 31
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFD20:
    loop_802DFD20(ctx);
    if (ctx->pc == 0x802DFD2Cu) goto label_802DFD2C;
    return;
label_802DFD24:
    // 802DFD24: rlwinm. r0, r0, 0, 31, 31
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

label_802DFD28:
    // 802DFD28: bc    4, 2, 0x802DFD20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFD20u;
                return;
            }
            goto label_802DFD20;
        }
    }

label_802DFD2C:
    ctx->pc = 0x802DFD2Cu;
    ctx->downcount -= 4;
    // 802DFD2C: addi    r3, r1, 40
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(40);

label_802DFD30:
    ctx->pc = 0x802DFD30u;
    // 802DFD30: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802DFD34:
    ctx->pc = 0x802DFD34u;
    // 802DFD34: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802DFD38:
    ctx->pc = 0x802DFD38u;
    // 802DFD38: bl      0x802E0350
    {
            ctx->lr = 0x802DFD3Cu;
            goto label_802E0350;
    }

label_802DFD3C:
    loop_802DFD3C(ctx);
    if (ctx->pc == 0x802DFD48u) goto label_802DFD48;
    return;
label_802DFD40:
    // 802DFD40: rlwinm. r0, r0, 0, 31, 31
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

label_802DFD44:
    // 802DFD44: bc    4, 2, 0x802DFD3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFD3Cu;
                return;
            }
            goto label_802DFD3C;
        }
    }

label_802DFD48:
    ctx->pc = 0x802DFD48u;
    ctx->downcount -= 11;
    // 802DFD48: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFD4C:
    ctx->pc = 0x802DFD4Cu;
    // 802DFD4C: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFD50:
    ctx->pc = 0x802DFD50u;
    // 802DFD50: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFD54:
    ctx->pc = 0x802DFD54u;
    // 802DFD54: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFD58:
    ctx->pc = 0x802DFD58u;
    // 802DFD58: rlwinm r0, r0, 0, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x1FFFFFFFu;
    }

label_802DFD5C:
    ctx->pc = 0x802DFD5Cu;
    // 802DFD5C: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFD60:
    ctx->pc = 0x802DFD60u;
    // 802DFD60: lwz     r4, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802DFD64:
    ctx->pc = 0x802DFD64u;
    // 802DFD64: rlwinm r3, r4, 0, 3, 7
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x1F000000u;
    }

label_802DFD68:
    ctx->pc = 0x802DFD68u;
    // 802DFD68: addis   r0, r3, -7936
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-7936) << 16);

label_802DFD6C:
    ctx->pc = 0x802DFD6Cu;
    // 802DFD6C: cmplwi  r0, 0x0000
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

label_802DFD70:
    ctx->pc = 0x802DFD70u;
    // 802DFD70: bc    4, 2, 0x802DFD88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802DFD88;
        }
    }

label_802DFD74:
    ctx->pc = 0x802DFD74u;
    ctx->downcount -= 5;
    // 802DFD74: rlwinm r3, r4, 0, 17, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00007FFFu;
    }

label_802DFD78:
    ctx->pc = 0x802DFD78u;
    // 802DFD78: stw     r4, -25104(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25104);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802DFD7C:
    ctx->pc = 0x802DFD7Cu;
    // 802DFD7C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802DFD80:
    ctx->pc = 0x802DFD80u;
    // 802DFD80: stw     r3, -25100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25100);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802DFD84:
    ctx->pc = 0x802DFD84u;
    // 802DFD84: stb     r0, -25092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25092);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802DFD88:
    ctx->pc = 0x802DFD88u;
    ctx->downcount -= 9;
    // 802DFD88: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFD8C:
    ctx->pc = 0x802DFD8Cu;
    // 802DFD8C: lwz     r31, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802DFD90:
    ctx->pc = 0x802DFD90u;
    // 802DFD90: lwz     r30, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802DFD94:
    ctx->pc = 0x802DFD94u;
    // 802DFD94: lwz     r29, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802DFD98:
    ctx->pc = 0x802DFD98u;
    // 802DFD98: lwz     r28, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_802DFD9C:
    ctx->pc = 0x802DFD9Cu;
    // 802DFD9C: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_802DFDA0:
    ctx->pc = 0x802DFDA0u;
    // 802DFDA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFDA4:
    ctx->pc = 0x802DFDA4u;
    // 802DFDA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFDA8:
    ctx->pc = 0x802DFDA8u;
    ctx->downcount -= 6;
    // 802DFDA8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFDAC:
    ctx->pc = 0x802DFDACu;
    // 802DFDAC: lis     r3, 2
    ctx->gpr[3] = ((u32)(s32)(2) << 16);

label_802DFDB0:
    ctx->pc = 0x802DFDB0u;
    // 802DFDB0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFDB4:
    ctx->pc = 0x802DFDB4u;
    // 802DFDB4: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_802DFDB8:
    ctx->pc = 0x802DFDB8u;
    // 802DFDB8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFDBC:
    ctx->pc = 0x802DFDBCu;
    // 802DFDBC: bl      0x802C354C
    {
            ctx->lr = 0x802DFDC0u;
            ctx->pc = 0x802C354Cu;
            return;
    }

label_802DFDC0:
    ctx->pc = 0x802DFDC0u;
    ctx->downcount -= 2;
    // 802DFDC0: li      r3, 64
    ctx->gpr[3] = (u32)(s32)(64);

label_802DFDC4:
    ctx->pc = 0x802DFDC4u;
    // 802DFDC4: bl      0x802C354C
    {
            ctx->lr = 0x802DFDC8u;
            ctx->pc = 0x802C354Cu;
            return;
    }

label_802DFDC8:
    ctx->pc = 0x802DFDC8u;
    ctx->downcount -= 7;
    // 802DFDC8: lis     r3, -32722
    ctx->gpr[3] = ((u32)(s32)(-32722) << 16);

label_802DFDCC:
    ctx->pc = 0x802DFDCCu;
    // 802DFDCC: addi    r0, r3, -332
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-332);

label_802DFDD0:
    ctx->pc = 0x802DFDD0u;
    // 802DFDD0: lis     r3, -32722
    ctx->gpr[3] = ((u32)(s32)(-32722) << 16);

label_802DFDD4:
    ctx->pc = 0x802DFDD4u;
    // 802DFDD4: stw     r0, -25108(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25108);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFDD8:
    ctx->pc = 0x802DFDD8u;
    // 802DFDD8: addi    r4, r3, -396
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-396);

label_802DFDDC:
    ctx->pc = 0x802DFDDCu;
    // 802DFDDC: li      r3, 25
    ctx->gpr[3] = (u32)(s32)(25);

label_802DFDE0:
    ctx->pc = 0x802DFDE0u;
    // 802DFDE0: bl      0x802C3134
    {
            ctx->lr = 0x802DFDE4u;
            ctx->pc = 0x802C3134u;
            return;
    }

label_802DFDE4:
    ctx->pc = 0x802DFDE4u;
    ctx->downcount -= 2;
    // 802DFDE4: li      r3, 64
    ctx->gpr[3] = (u32)(s32)(64);

label_802DFDE8:
    ctx->pc = 0x802DFDE8u;
    // 802DFDE8: bl      0x802C35D4
    {
            ctx->lr = 0x802DFDECu;
            ctx->pc = 0x802C35D4u;
            return;
    }

label_802DFDEC:
    ctx->pc = 0x802DFDECu;
    ctx->downcount -= 5;
    // 802DFDEC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFDF0:
    ctx->pc = 0x802DFDF0u;
    // 802DFDF0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802DFDF4:
    ctx->pc = 0x802DFDF4u;
    // 802DFDF4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFDF8:
    ctx->pc = 0x802DFDF8u;
    // 802DFDF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFDFC:
    ctx->pc = 0x802DFDFCu;
    ctx->downcount -= 9;
    // 802DFDFC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFE00:
    ctx->pc = 0x802DFE00u;
    // 802DFE00: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFE04:
    ctx->pc = 0x802DFE04u;
    // 802DFE04: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFE08:
    ctx->pc = 0x802DFE08u;
    // 802DFE08: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802DFE0C:
    ctx->pc = 0x802DFE0Cu;
    // 802DFE0C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802DFE10:
    ctx->pc = 0x802DFE10u;
    // 802DFE10: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_802DFE14:
    ctx->pc = 0x802DFE14u;
    // 802DFE14: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802DFE18:
    ctx->pc = 0x802DFE18u;
    // 802DFE18: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802DFE1C:
    ctx->pc = 0x802DFE1Cu;
    // 802DFE1C: bl      0x802C30E8
    {
            ctx->lr = 0x802DFE20u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802DFE20:
    ctx->pc = 0x802DFE20u;
    ctx->downcount -= 9;
    // 802DFE20: addi    r0, r13, -25092
    ctx->gpr[0] = ctx->gpr[13] + (u32)(s32)(-25092);

label_802DFE24:
    ctx->pc = 0x802DFE24u;
    // 802DFE24: stw     r0, -25096(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25096);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFE28:
    ctx->pc = 0x802DFE28u;
    // 802DFE28: lis     r4, 2
    ctx->gpr[4] = ((u32)(s32)(2) << 16);

label_802DFE2C:
    ctx->pc = 0x802DFE2Cu;
    // 802DFE2C: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802DFE30:
    ctx->pc = 0x802DFE30u;
    // 802DFE30: lwz     r0, -25096(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25096);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFE34:
    ctx->pc = 0x802DFE34u;
    // 802DFE34: addi    r3, r4, -32768
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(-32768);

label_802DFE38:
    ctx->pc = 0x802DFE38u;
    // 802DFE38: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFE3C:
    ctx->pc = 0x802DFE3Cu;
    // 802DFE3C: stw     r30, -25112(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25112);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802DFE40:
    ctx->pc = 0x802DFE40u;
    // 802DFE40: bl      0x802C354C
    {
            ctx->lr = 0x802DFE44u;
            ctx->pc = 0x802C354Cu;
            return;
    }

label_802DFE44:
    ctx->pc = 0x802DFE44u;
    ctx->downcount -= 5;
    // 802DFE44: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_802DFE48:
    ctx->pc = 0x802DFE48u;
    // 802DFE48: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802DFE4C:
    ctx->pc = 0x802DFE4Cu;
    // 802DFE4C: stw     r0, 26664(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26664);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFE50:
    ctx->pc = 0x802DFE50u;
    // 802DFE50: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802DFE54:
    ctx->pc = 0x802DFE54u;
    // 802DFE54: bl      0x802C3110
    {
            ctx->lr = 0x802DFE58u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802DFE58:
    ctx->pc = 0x802DFE58u;
    ctx->downcount -= 8;
    // 802DFE58: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFE5C:
    ctx->pc = 0x802DFE5Cu;
    // 802DFE5C: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802DFE60:
    ctx->pc = 0x802DFE60u;
    // 802DFE60: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802DFE64:
    ctx->pc = 0x802DFE64u;
    // 802DFE64: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802DFE68:
    ctx->pc = 0x802DFE68u;
    // 802DFE68: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802DFE6C:
    ctx->pc = 0x802DFE6Cu;
    // 802DFE6C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFE70:
    ctx->pc = 0x802DFE70u;
    // 802DFE70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFE74:
    ctx->pc = 0x802DFE74u;
    ctx->downcount -= 9;
    // 802DFE74: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFE78:
    ctx->pc = 0x802DFE78u;
    // 802DFE78: lis     r5, -13312
    ctx->gpr[5] = ((u32)(s32)(-13312) << 16);

label_802DFE7C:
    ctx->pc = 0x802DFE7Cu;
    // 802DFE7C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFE80:
    ctx->pc = 0x802DFE80u;
    // 802DFE80: li      r0, 4096
    ctx->gpr[0] = (u32)(s32)(4096);

label_802DFE84:
    ctx->pc = 0x802DFE84u;
    // 802DFE84: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFE88:
    ctx->pc = 0x802DFE88u;
    // 802DFE88: lwz     r12, -25108(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25108);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802DFE8C:
    ctx->pc = 0x802DFE8Cu;
    // 802DFE8C: stw     r0, 12288(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(12288);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFE90:
    ctx->pc = 0x802DFE90u;
    // 802DFE90: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802DFE94:
    ctx->pc = 0x802DFE94u;
    // 802DFE94: bc    12, 2, 0x802DFEA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802DFEA4;
        }
    }

label_802DFE98:
    ctx->pc = 0x802DFE98u;
    ctx->downcount -= 4;
    // 802DFE98: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802DFE9C:
    ctx->pc = 0x802DFE9Cu;
    // 802DFE9C: extsh r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_802DFEA0:
    ctx->pc = 0x802DFEA0u;
    // 802DFEA0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802DFEA4u;
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFEA4:
    ctx->pc = 0x802DFEA4u;
    ctx->downcount -= 5;
    // 802DFEA4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFEA8:
    ctx->pc = 0x802DFEA8u;
    // 802DFEA8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802DFEAC:
    ctx->pc = 0x802DFEACu;
    // 802DFEAC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFEB0:
    ctx->pc = 0x802DFEB0u;
    // 802DFEB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFEB4:
    ctx->pc = 0x802DFEB4u;
    ctx->downcount -= 8;
    // 802DFEB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFEB8:
    ctx->pc = 0x802DFEB8u;
    // 802DFEB8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFEBC:
    ctx->pc = 0x802DFEBCu;
    // 802DFEBC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802DFEC0:
    ctx->pc = 0x802DFEC0u;
    // 802DFEC0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFEC4:
    ctx->pc = 0x802DFEC4u;
    // 802DFEC4: lwz     r12, -25112(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25112);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802DFEC8:
    ctx->pc = 0x802DFEC8u;
    // 802DFEC8: stb     r0, -25092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25092);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802DFECC:
    ctx->pc = 0x802DFECCu;
    // 802DFECC: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802DFED0:
    ctx->pc = 0x802DFED0u;
    // 802DFED0: bc    12, 2, 0x802DFEE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802DFEE0;
        }
    }

label_802DFED4:
    ctx->pc = 0x802DFED4u;
    ctx->downcount -= 4;
    // 802DFED4: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802DFED8:
    ctx->pc = 0x802DFED8u;
    // 802DFED8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802DFEDC:
    ctx->pc = 0x802DFEDCu;
    // 802DFEDC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802DFEE0u;
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFEE0:
    ctx->pc = 0x802DFEE0u;
    ctx->downcount -= 5;
    // 802DFEE0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFEE4:
    ctx->pc = 0x802DFEE4u;
    // 802DFEE4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802DFEE8:
    ctx->pc = 0x802DFEE8u;
    // 802DFEE8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFEEC:
    ctx->pc = 0x802DFEECu;
    // 802DFEEC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFEF0:
    ctx->pc = 0x802DFEF0u;
    ctx->downcount -= 27;
    // 802DFEF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFEF4:
    ctx->pc = 0x802DFEF4u;
    // 802DFEF4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802DFEF8:
    ctx->pc = 0x802DFEF8u;
    // 802DFEF8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFEFC:
    ctx->pc = 0x802DFEFCu;
    // 802DFEFC: lis     r0, 16384
    ctx->gpr[0] = ((u32)(s32)(16384) << 16);

label_802DFF00:
    ctx->pc = 0x802DFF00u;
    // 802DFF00: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFF04:
    ctx->pc = 0x802DFF04u;
    // 802DFF04: stmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802DFF08:
    ctx->pc = 0x802DFF08u;
    // 802DFF08: lis     r30, -13312
    ctx->gpr[30] = ((u32)(s32)(-13312) << 16);

label_802DFF0C:
    ctx->pc = 0x802DFF0Cu;
    // 802DFF0C: addi    r27, r3, 0
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(0);

label_802DFF10:
    ctx->pc = 0x802DFF10u;
    // 802DFF10: addi    r29, r30, 26624
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(26624);

label_802DFF14:
    ctx->pc = 0x802DFF14u;
    // 802DFF14: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_802DFF18:
    ctx->pc = 0x802DFF18u;
    // 802DFF18: lwz     r5, 26664(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(26664);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802DFF1C:
    ctx->pc = 0x802DFF1Cu;
    // 802DFF1C: andi.   r5, r5, 0x0405
    {
        ctx->gpr[5] = ctx->gpr[5] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFF20:
    ctx->pc = 0x802DFF20u;
    // 802DFF20: ori     r5, r5, 0x00C0
    ctx->gpr[5] = ctx->gpr[5] | 0x00C0u;

label_802DFF24:
    ctx->pc = 0x802DFF24u;
    // 802DFF24: stwu     r5, 40(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
        ctx->gpr[29] = ea;
    }

label_802DFF28:
    ctx->pc = 0x802DFF28u;
    // 802DFF28: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802DFF2C:
    ctx->pc = 0x802DFF2Cu;
    // 802DFF2C: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFF30:
    ctx->pc = 0x802DFF30u;
    // 802DFF30: bl      0x802E0350
    {
            ctx->lr = 0x802DFF34u;
            goto label_802E0350;
    }

label_802DFF34:
    ctx->pc = 0x802DFF34u;
    ctx->downcount -= 2;
    // 802DFF34: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFF38:
    ctx->pc = 0x802DFF38u;
    // 802DFF38: rlwinm r31, r0, 27, 5, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFF3C:
    loop_802DFF3C(ctx);
    if (ctx->pc == 0x802DFF4Cu) goto label_802DFF4C;
    return;
label_802DFF40:
    ctx->pc = 0x802DFF40u;
    // 802DFF40: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

label_802DFF44:
    // 802DFF44: rlwinm. r0, r0, 0, 31, 31
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

label_802DFF48:
    // 802DFF48: bc    4, 2, 0x802DFF3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFF3Cu;
                return;
            }
            goto label_802DFF3C;
        }
    }

label_802DFF4C:
    ctx->pc = 0x802DFF4Cu;
    ctx->downcount -= 4;
    // 802DFF4C: addi    r3, r27, 0
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(0);

label_802DFF50:
    ctx->pc = 0x802DFF50u;
    // 802DFF50: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802DFF54:
    ctx->pc = 0x802DFF54u;
    // 802DFF54: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802DFF58:
    ctx->pc = 0x802DFF58u;
    // 802DFF58: bl      0x802E0350
    {
            ctx->lr = 0x802DFF5Cu;
            goto label_802E0350;
    }

label_802DFF5C:
    ctx->pc = 0x802DFF5Cu;
    ctx->downcount -= 3;
    // 802DFF5C: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFF60:
    ctx->pc = 0x802DFF60u;
    // 802DFF60: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFF64:
    ctx->pc = 0x802DFF64u;
    // 802DFF64: or   r3, r31, r0
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[0];
    }

label_802DFF68:
    loop_802DFF68(ctx);
    if (ctx->pc == 0x802DFF74u) goto label_802DFF74;
    return;
label_802DFF6C:
    // 802DFF6C: rlwinm. r0, r0, 0, 31, 31
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

label_802DFF70:
    // 802DFF70: bc    4, 2, 0x802DFF68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFF68u;
                return;
            }
            goto label_802DFF68;
        }
    }

label_802DFF74:
    ctx->pc = 0x802DFF74u;
    ctx->downcount -= 21;
    // 802DFF74: lwz     r4, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802DFF78:
    ctx->pc = 0x802DFF78u;
    // 802DFF78: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFF7C:
    ctx->pc = 0x802DFF7Cu;
    // 802DFF7C: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFF80:
    ctx->pc = 0x802DFF80u;
    // 802DFF80: andi.   r0, r4, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[4] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFF84:
    ctx->pc = 0x802DFF84u;
    // 802DFF84: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFF88:
    ctx->pc = 0x802DFF88u;
    // 802DFF88: lmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802DFF8C:
    ctx->pc = 0x802DFF8Cu;
    // 802DFF8C: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802DFF90:
    ctx->pc = 0x802DFF90u;
    // 802DFF90: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_802DFF94:
    ctx->pc = 0x802DFF94u;
    // 802DFF94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802DFF98:
    ctx->pc = 0x802DFF98u;
    // 802DFF98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802DFF9C:
    ctx->pc = 0x802DFF9Cu;
    ctx->downcount -= 29;
    // 802DFF9C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802DFFA0:
    ctx->pc = 0x802DFFA0u;
    // 802DFFA0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFFA4:
    ctx->pc = 0x802DFFA4u;
    // 802DFFA4: rlwinm r0, r3, 8, 7, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x01FFFC00u;
    }

label_802DFFA8:
    ctx->pc = 0x802DFFA8u;
    // 802DFFA8: oris    r0, r0, 0xA000
    ctx->gpr[0] = ctx->gpr[0] | (0xA000u << 16);

label_802DFFAC:
    ctx->pc = 0x802DFFACu;
    // 802DFFAC: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802DFFB0:
    ctx->pc = 0x802DFFB0u;
    // 802DFFB0: stmw     r26, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802DFFB4:
    ctx->pc = 0x802DFFB4u;
    // 802DFFB4: lis     r29, -13312
    ctx->gpr[29] = ((u32)(s32)(-13312) << 16);

label_802DFFB8:
    ctx->pc = 0x802DFFB8u;
    // 802DFFB8: addi    r30, r5, 0
    ctx->gpr[30] = ctx->gpr[5] + (u32)(s32)(0);

label_802DFFBC:
    ctx->pc = 0x802DFFBCu;
    // 802DFFBC: addi    r26, r4, 0
    ctx->gpr[26] = ctx->gpr[4] + (u32)(s32)(0);

label_802DFFC0:
    ctx->pc = 0x802DFFC0u;
    // 802DFFC0: addi    r31, r29, 26624
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(26624);

label_802DFFC4:
    ctx->pc = 0x802DFFC4u;
    // 802DFFC4: addi    r3, r1, 36
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(36);

label_802DFFC8:
    ctx->pc = 0x802DFFC8u;
    // 802DFFC8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802DFFCC:
    ctx->pc = 0x802DFFCCu;
    // 802DFFCC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802DFFD0:
    ctx->pc = 0x802DFFD0u;
    // 802DFFD0: lwz     r6, 26664(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(26664);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802DFFD4:
    ctx->pc = 0x802DFFD4u;
    // 802DFFD4: andi.   r6, r6, 0x0405
    {
        ctx->gpr[6] = ctx->gpr[6] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802DFFD8:
    ctx->pc = 0x802DFFD8u;
    // 802DFFD8: ori     r6, r6, 0x00C0
    ctx->gpr[6] = ctx->gpr[6] | 0x00C0u;

label_802DFFDC:
    ctx->pc = 0x802DFFDCu;
    // 802DFFDC: stwu     r6, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[31] = ea;
    }

label_802DFFE0:
    ctx->pc = 0x802DFFE0u;
    // 802DFFE0: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802DFFE4:
    ctx->pc = 0x802DFFE4u;
    // 802DFFE4: bl      0x802E0350
    {
            ctx->lr = 0x802DFFE8u;
            goto label_802E0350;
    }

label_802DFFE8:
    ctx->pc = 0x802DFFE8u;
    ctx->downcount -= 3;
    // 802DFFE8: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802DFFEC:
    ctx->pc = 0x802DFFECu;
    // 802DFFEC: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802DFFF0:
    ctx->pc = 0x802DFFF0u;
    // 802DFFF0: or   r27, r0, r0
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802DFFF4:
    loop_802DFFF4(ctx);
    if (ctx->pc == 0x802E0004u) goto label_802E0004;
    return;
label_802DFFF8:
    ctx->pc = 0x802DFFF8u;
    // 802DFFF8: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

label_802DFFFC:
    // 802DFFFC: rlwinm. r0, r0, 0, 31, 31
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

label_802E0000:
    // 802E0000: bc    4, 2, 0x802DFFF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802DFFF4u;
                return;
            }
            goto label_802DFFF4;
        }
    }

label_802E0004:
    ctx->pc = 0x802E0004u;
    ctx->downcount -= 1;
    // 802E0004: b       0x802E0048
    {
            goto label_802E0048;
    }

label_802E0008:
    ctx->pc = 0x802E0008u;
    ctx->downcount -= 7;
    // 802E0008: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E000C:
    // 802E000C: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_802E0010:
    // 802E0010: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802E0014:
    ctx->pc = 0x802E0014u;
    // 802E0014: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0018:
    // 802E0018: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802E001C:
    // 802E001C: addi    r26, r26, 4
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(4);

label_802E0020:
    // 802E0020: bl      0x802E0350
    {
            ctx->lr = 0x802E0024u;
            goto label_802E0350;
    }

label_802E0024:
    ctx->downcount -= 3;
    // 802E0024: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E0028:
    // 802E0028: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E002C:
    // 802E002C: or   r27, r27, r0
    {
        ctx->gpr[27] = ctx->gpr[27] | ctx->gpr[0];
    }

label_802E0030:
    loop_802E0030(ctx);
    if (ctx->pc == 0x802E003Cu) goto label_802E003C;
    return;
label_802E0034:
    // 802E0034: rlwinm. r0, r0, 0, 31, 31
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

label_802E0038:
    // 802E0038: bc    4, 2, 0x802E0030
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0030u;
                return;
            }
            goto label_802E0030;
        }
    }

label_802E003C:
    ctx->downcount -= 2;
    // 802E003C: addic.  r30, r30, -4
    {
        u64 a = ctx->gpr[30];
        u64 b = (u32)(s32)(-4);
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

label_802E0040:
    // 802E0040: bc    4, 0, 0x802E0048
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E0048;
        }
    }

label_802E0044:
    ctx->downcount -= 1;
    // 802E0044: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802E0048:
    ctx->downcount -= 2;
    // 802E0048: cmpwi   r30, 0
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

label_802E004C:
    // 802E004C: bc    4, 2, 0x802E0008
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0008u;
                return;
            }
            goto label_802E0008;
        }
    }

label_802E0050:
    ctx->pc = 0x802E0050u;
    ctx->downcount -= 21;
    // 802E0050: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E0054:
    ctx->pc = 0x802E0054u;
    // 802E0054: cntlzw r0, r27
    {
        u32 v = ctx->gpr[27];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E0058:
    ctx->pc = 0x802E0058u;
    // 802E0058: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E005C:
    ctx->pc = 0x802E005Cu;
    // 802E005C: andi.   r0, r4, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[4] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0060:
    ctx->pc = 0x802E0060u;
    // 802E0060: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0064:
    ctx->pc = 0x802E0064u;
    // 802E0064: lmw     r26, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E0068:
    ctx->pc = 0x802E0068u;
    // 802E0068: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E006C:
    ctx->pc = 0x802E006Cu;
    // 802E006C: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_802E0070:
    ctx->pc = 0x802E0070u;
    // 802E0070: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0074:
    ctx->pc = 0x802E0074u;
    // 802E0074: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0078:
    ctx->pc = 0x802E0078u;
    ctx->downcount -= 29;
    // 802E0078: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E007C:
    ctx->pc = 0x802E007Cu;
    // 802E007C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0080:
    ctx->pc = 0x802E0080u;
    // 802E0080: rlwinm r0, r3, 8, 7, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x01FFFC00u;
    }

label_802E0084:
    ctx->pc = 0x802E0084u;
    // 802E0084: oris    r0, r0, 0x2000
    ctx->gpr[0] = ctx->gpr[0] | (0x2000u << 16);

label_802E0088:
    ctx->pc = 0x802E0088u;
    // 802E0088: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E008C:
    ctx->pc = 0x802E008Cu;
    // 802E008C: stmw     r26, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E0090:
    ctx->pc = 0x802E0090u;
    // 802E0090: lis     r29, -13312
    ctx->gpr[29] = ((u32)(s32)(-13312) << 16);

label_802E0094:
    ctx->pc = 0x802E0094u;
    // 802E0094: addi    r30, r5, 0
    ctx->gpr[30] = ctx->gpr[5] + (u32)(s32)(0);

label_802E0098:
    ctx->pc = 0x802E0098u;
    // 802E0098: addi    r26, r4, 0
    ctx->gpr[26] = ctx->gpr[4] + (u32)(s32)(0);

label_802E009C:
    ctx->pc = 0x802E009Cu;
    // 802E009C: addi    r31, r29, 26624
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(26624);

label_802E00A0:
    ctx->pc = 0x802E00A0u;
    // 802E00A0: addi    r3, r1, 36
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(36);

label_802E00A4:
    ctx->pc = 0x802E00A4u;
    // 802E00A4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802E00A8:
    ctx->pc = 0x802E00A8u;
    // 802E00A8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802E00AC:
    ctx->pc = 0x802E00ACu;
    // 802E00AC: lwz     r6, 26664(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(26664);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802E00B0:
    ctx->pc = 0x802E00B0u;
    // 802E00B0: andi.   r6, r6, 0x0405
    {
        ctx->gpr[6] = ctx->gpr[6] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E00B4:
    ctx->pc = 0x802E00B4u;
    // 802E00B4: ori     r6, r6, 0x00C0
    ctx->gpr[6] = ctx->gpr[6] | 0x00C0u;

label_802E00B8:
    ctx->pc = 0x802E00B8u;
    // 802E00B8: stwu     r6, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[31] = ea;
    }

label_802E00BC:
    ctx->pc = 0x802E00BCu;
    // 802E00BC: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E00C0:
    ctx->pc = 0x802E00C0u;
    // 802E00C0: bl      0x802E0350
    {
            ctx->lr = 0x802E00C4u;
            goto label_802E0350;
    }

label_802E00C4:
    ctx->pc = 0x802E00C4u;
    ctx->downcount -= 3;
    // 802E00C4: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E00C8:
    ctx->pc = 0x802E00C8u;
    // 802E00C8: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E00CC:
    ctx->pc = 0x802E00CCu;
    // 802E00CC: or   r27, r0, r0
    {
        ctx->gpr[27] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802E00D0:
    loop_802E00D0(ctx);
    if (ctx->pc == 0x802E00E0u) goto label_802E00E0;
    return;
label_802E00D4:
    ctx->pc = 0x802E00D4u;
    // 802E00D4: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

label_802E00D8:
    // 802E00D8: rlwinm. r0, r0, 0, 31, 31
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

label_802E00DC:
    // 802E00DC: bc    4, 2, 0x802E00D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E00D0u;
                return;
            }
            goto label_802E00D0;
        }
    }

label_802E00E0:
    ctx->pc = 0x802E00E0u;
    ctx->downcount -= 1;
    // 802E00E0: b       0x802E0124
    {
            goto label_802E0124;
    }

label_802E00E4:
    ctx->downcount -= 4;
    // 802E00E4: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_802E00E8:
    // 802E00E8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802E00EC:
    // 802E00EC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802E00F0:
    // 802E00F0: bl      0x802E0350
    {
            ctx->lr = 0x802E00F4u;
            goto label_802E0350;
    }

label_802E00F4:
    ctx->downcount -= 3;
    // 802E00F4: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E00F8:
    // 802E00F8: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E00FC:
    // 802E00FC: or   r27, r27, r0
    {
        ctx->gpr[27] = ctx->gpr[27] | ctx->gpr[0];
    }

label_802E0100:
    loop_802E0100(ctx);
    if (ctx->pc == 0x802E010Cu) goto label_802E010C;
    return;
label_802E0104:
    // 802E0104: rlwinm. r0, r0, 0, 31, 31
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

label_802E0108:
    // 802E0108: bc    4, 2, 0x802E0100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0100u;
                return;
            }
            goto label_802E0100;
        }
    }

label_802E010C:
    ctx->pc = 0x802E010Cu;
    ctx->downcount -= 5;
    // 802E010C: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0110:
    // 802E0110: addic.  r30, r30, -4
    {
        u64 a = ctx->gpr[30];
        u64 b = (u32)(s32)(-4);
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

label_802E0114:
    ctx->pc = 0x802E0114u;
    // 802E0114: stw     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0118:
    // 802E0118: addi    r26, r26, 4
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(4);

label_802E011C:
    // 802E011C: bc    4, 0, 0x802E0124
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E0124;
        }
    }

label_802E0120:
    ctx->downcount -= 1;
    // 802E0120: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802E0124:
    ctx->downcount -= 2;
    // 802E0124: cmpwi   r30, 0
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

label_802E0128:
    // 802E0128: bc    4, 2, 0x802E00E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E00E4u;
                return;
            }
            goto label_802E00E4;
        }
    }

label_802E012C:
    ctx->pc = 0x802E012Cu;
    ctx->downcount -= 21;
    // 802E012C: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E0130:
    ctx->pc = 0x802E0130u;
    // 802E0130: cntlzw r0, r27
    {
        u32 v = ctx->gpr[27];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E0134:
    ctx->pc = 0x802E0134u;
    // 802E0134: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E0138:
    ctx->pc = 0x802E0138u;
    // 802E0138: andi.   r0, r4, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[4] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E013C:
    ctx->pc = 0x802E013Cu;
    // 802E013C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0140:
    ctx->pc = 0x802E0140u;
    // 802E0140: lmw     r26, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E0144:
    ctx->pc = 0x802E0144u;
    // 802E0144: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0148:
    ctx->pc = 0x802E0148u;
    // 802E0148: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_802E014C:
    ctx->pc = 0x802E014Cu;
    // 802E014C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0150:
    ctx->pc = 0x802E0150u;
    // 802E0150: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0154:
    ctx->pc = 0x802E0154u;
    ctx->downcount -= 27;
    // 802E0154: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0158:
    ctx->pc = 0x802E0158u;
    // 802E0158: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802E015C:
    ctx->pc = 0x802E015Cu;
    // 802E015C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0160:
    ctx->pc = 0x802E0160u;
    // 802E0160: lis     r0, 24576
    ctx->gpr[0] = ((u32)(s32)(24576) << 16);

label_802E0164:
    ctx->pc = 0x802E0164u;
    // 802E0164: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0168:
    ctx->pc = 0x802E0168u;
    // 802E0168: stmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E016C:
    ctx->pc = 0x802E016Cu;
    // 802E016C: lis     r30, -13312
    ctx->gpr[30] = ((u32)(s32)(-13312) << 16);

label_802E0170:
    ctx->pc = 0x802E0170u;
    // 802E0170: addi    r27, r3, 0
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(0);

label_802E0174:
    ctx->pc = 0x802E0174u;
    // 802E0174: addi    r29, r30, 26624
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(26624);

label_802E0178:
    ctx->pc = 0x802E0178u;
    // 802E0178: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_802E017C:
    ctx->pc = 0x802E017Cu;
    // 802E017C: lwz     r5, 26664(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(26664);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802E0180:
    ctx->pc = 0x802E0180u;
    // 802E0180: andi.   r5, r5, 0x0405
    {
        ctx->gpr[5] = ctx->gpr[5] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0184:
    ctx->pc = 0x802E0184u;
    // 802E0184: ori     r5, r5, 0x00C0
    ctx->gpr[5] = ctx->gpr[5] | 0x00C0u;

label_802E0188:
    ctx->pc = 0x802E0188u;
    // 802E0188: stwu     r5, 40(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
        ctx->gpr[29] = ea;
    }

label_802E018C:
    ctx->pc = 0x802E018Cu;
    // 802E018C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802E0190:
    ctx->pc = 0x802E0190u;
    // 802E0190: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0194:
    ctx->pc = 0x802E0194u;
    // 802E0194: bl      0x802E0350
    {
            ctx->lr = 0x802E0198u;
            goto label_802E0350;
    }

label_802E0198:
    ctx->pc = 0x802E0198u;
    ctx->downcount -= 2;
    // 802E0198: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E019C:
    ctx->pc = 0x802E019Cu;
    // 802E019C: rlwinm r31, r0, 27, 5, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E01A0:
    loop_802E01A0(ctx);
    if (ctx->pc == 0x802E01B0u) goto label_802E01B0;
    return;
label_802E01A4:
    ctx->pc = 0x802E01A4u;
    // 802E01A4: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

label_802E01A8:
    // 802E01A8: rlwinm. r0, r0, 0, 31, 31
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

label_802E01AC:
    // 802E01AC: bc    4, 2, 0x802E01A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E01A0u;
                return;
            }
            goto label_802E01A0;
        }
    }

label_802E01B0:
    ctx->pc = 0x802E01B0u;
    ctx->downcount -= 4;
    // 802E01B0: addi    r3, r27, 0
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(0);

label_802E01B4:
    ctx->pc = 0x802E01B4u;
    // 802E01B4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802E01B8:
    ctx->pc = 0x802E01B8u;
    // 802E01B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802E01BC:
    ctx->pc = 0x802E01BCu;
    // 802E01BC: bl      0x802E0350
    {
            ctx->lr = 0x802E01C0u;
            goto label_802E0350;
    }

label_802E01C0:
    ctx->pc = 0x802E01C0u;
    ctx->downcount -= 3;
    // 802E01C0: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E01C4:
    ctx->pc = 0x802E01C4u;
    // 802E01C4: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E01C8:
    ctx->pc = 0x802E01C8u;
    // 802E01C8: or   r3, r31, r0
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[0];
    }

label_802E01CC:
    loop_802E01CC(ctx);
    if (ctx->pc == 0x802E01D8u) goto label_802E01D8;
    return;
label_802E01D0:
    // 802E01D0: rlwinm. r0, r0, 0, 31, 31
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

label_802E01D4:
    // 802E01D4: bc    4, 2, 0x802E01CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E01CCu;
                return;
            }
            goto label_802E01CC;
        }
    }

label_802E01D8:
    ctx->pc = 0x802E01D8u;
    ctx->downcount -= 21;
    // 802E01D8: lwz     r4, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E01DC:
    ctx->pc = 0x802E01DCu;
    // 802E01DC: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E01E0:
    ctx->pc = 0x802E01E0u;
    // 802E01E0: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E01E4:
    ctx->pc = 0x802E01E4u;
    // 802E01E4: andi.   r0, r4, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[4] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E01E8:
    ctx->pc = 0x802E01E8u;
    // 802E01E8: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E01EC:
    ctx->pc = 0x802E01ECu;
    // 802E01EC: lmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E01F0:
    ctx->pc = 0x802E01F0u;
    // 802E01F0: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E01F4:
    ctx->pc = 0x802E01F4u;
    // 802E01F4: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_802E01F8:
    ctx->pc = 0x802E01F8u;
    // 802E01F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E01FC:
    ctx->pc = 0x802E01FCu;
    // 802E01FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0200:
    ctx->pc = 0x802E0200u;
    ctx->downcount -= 18;
    // 802E0200: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0204:
    ctx->pc = 0x802E0204u;
    // 802E0204: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802E0208:
    ctx->pc = 0x802E0208u;
    // 802E0208: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E020C:
    ctx->pc = 0x802E020Cu;
    // 802E020C: rlwinm r0, r3, 0, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x1FFFFFFFu;
    }

label_802E0210:
    ctx->pc = 0x802E0210u;
    // 802E0210: oris    r0, r0, 0xC000
    ctx->gpr[0] = ctx->gpr[0] | (0xC000u << 16);

label_802E0214:
    ctx->pc = 0x802E0214u;
    // 802E0214: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0218:
    ctx->pc = 0x802E0218u;
    // 802E0218: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E021C:
    ctx->pc = 0x802E021Cu;
    // 802E021C: lis     r31, -13312
    ctx->gpr[31] = ((u32)(s32)(-13312) << 16);

label_802E0220:
    ctx->pc = 0x802E0220u;
    // 802E0220: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_802E0224:
    ctx->pc = 0x802E0224u;
    // 802E0224: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E0228:
    ctx->pc = 0x802E0228u;
    // 802E0228: addi    r30, r31, 26624
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(26624);

label_802E022C:
    ctx->pc = 0x802E022Cu;
    // 802E022C: lwz     r5, 26664(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(26664);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802E0230:
    ctx->pc = 0x802E0230u;
    // 802E0230: andi.   r5, r5, 0x0405
    {
        ctx->gpr[5] = ctx->gpr[5] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0234:
    ctx->pc = 0x802E0234u;
    // 802E0234: ori     r5, r5, 0x00C0
    ctx->gpr[5] = ctx->gpr[5] | 0x00C0u;

label_802E0238:
    ctx->pc = 0x802E0238u;
    // 802E0238: stwu     r5, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
        ctx->gpr[30] = ea;
    }

label_802E023C:
    ctx->pc = 0x802E023Cu;
    // 802E023C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802E0240:
    ctx->pc = 0x802E0240u;
    // 802E0240: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0244:
    ctx->pc = 0x802E0244u;
    // 802E0244: bl      0x802E0350
    {
            ctx->lr = 0x802E0248u;
            goto label_802E0350;
    }

label_802E0248:
    ctx->pc = 0x802E0248u;
    ctx->downcount -= 3;
    // 802E0248: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E024C:
    ctx->pc = 0x802E024Cu;
    // 802E024C: rlwinm r4, r0, 27, 5, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E0250:
    ctx->pc = 0x802E0250u;
    // 802E0250: addi    r3, r31, 26624
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(26624);

label_802E0254:
    loop_802E0254(ctx);
    if (ctx->pc == 0x802E0260u) goto label_802E0260;
    return;
label_802E0258:
    // 802E0258: rlwinm. r0, r0, 0, 31, 31
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

label_802E025C:
    // 802E025C: bc    4, 2, 0x802E0254
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0254u;
                return;
            }
            goto label_802E0254;
        }
    }

label_802E0260:
    ctx->pc = 0x802E0260u;
    ctx->downcount -= 12;
    // 802E0260: lwz     r5, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802E0264:
    ctx->pc = 0x802E0264u;
    // 802E0264: cntlzw r0, r4
    {
        u32 v = ctx->gpr[4];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E0268:
    ctx->pc = 0x802E0268u;
    // 802E0268: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E026C:
    ctx->pc = 0x802E026Cu;
    // 802E026C: andi.   r0, r5, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[5] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0270:
    ctx->pc = 0x802E0270u;
    // 802E0270: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0274:
    ctx->pc = 0x802E0274u;
    // 802E0274: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0278:
    ctx->pc = 0x802E0278u;
    // 802E0278: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E027C:
    ctx->pc = 0x802E027Cu;
    // 802E027C: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802E0280:
    ctx->pc = 0x802E0280u;
    // 802E0280: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802E0284:
    ctx->pc = 0x802E0284u;
    // 802E0284: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0288:
    ctx->pc = 0x802E0288u;
    // 802E0288: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E028C:
    ctx->pc = 0x802E028Cu;
    ctx->downcount -= 27;
    // 802E028C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0290:
    ctx->pc = 0x802E0290u;
    // 802E0290: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802E0294:
    ctx->pc = 0x802E0294u;
    // 802E0294: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0298:
    ctx->pc = 0x802E0298u;
    // 802E0298: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E029C:
    ctx->pc = 0x802E029Cu;
    // 802E029C: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E02A0:
    ctx->pc = 0x802E02A0u;
    // 802E02A0: stmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E02A4:
    ctx->pc = 0x802E02A4u;
    // 802E02A4: lis     r30, -13312
    ctx->gpr[30] = ((u32)(s32)(-13312) << 16);

label_802E02A8:
    ctx->pc = 0x802E02A8u;
    // 802E02A8: addi    r27, r3, 0
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(0);

label_802E02AC:
    ctx->pc = 0x802E02ACu;
    // 802E02AC: addi    r29, r30, 26624
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(26624);

label_802E02B0:
    ctx->pc = 0x802E02B0u;
    // 802E02B0: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_802E02B4:
    ctx->pc = 0x802E02B4u;
    // 802E02B4: lwz     r5, 26664(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(26664);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802E02B8:
    ctx->pc = 0x802E02B8u;
    // 802E02B8: andi.   r5, r5, 0x0405
    {
        ctx->gpr[5] = ctx->gpr[5] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E02BC:
    ctx->pc = 0x802E02BCu;
    // 802E02BC: ori     r5, r5, 0x0080
    ctx->gpr[5] = ctx->gpr[5] | 0x0080u;

label_802E02C0:
    ctx->pc = 0x802E02C0u;
    // 802E02C0: stwu     r5, 40(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
        ctx->gpr[29] = ea;
    }

label_802E02C4:
    ctx->pc = 0x802E02C4u;
    // 802E02C4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802E02C8:
    ctx->pc = 0x802E02C8u;
    // 802E02C8: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E02CC:
    ctx->pc = 0x802E02CCu;
    // 802E02CC: bl      0x802E0350
    {
            ctx->lr = 0x802E02D0u;
            goto label_802E0350;
    }

label_802E02D0:
    ctx->pc = 0x802E02D0u;
    ctx->downcount -= 2;
    // 802E02D0: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E02D4:
    ctx->pc = 0x802E02D4u;
    // 802E02D4: rlwinm r31, r0, 27, 5, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E02D8:
    loop_802E02D8(ctx);
    if (ctx->pc == 0x802E02E8u) goto label_802E02E8;
    return;
label_802E02DC:
    ctx->pc = 0x802E02DCu;
    // 802E02DC: lwzu     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[28] = ea;
    }

label_802E02E0:
    // 802E02E0: rlwinm. r0, r0, 0, 31, 31
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

label_802E02E4:
    // 802E02E4: bc    4, 2, 0x802E02D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E02D8u;
                return;
            }
            goto label_802E02D8;
        }
    }

label_802E02E8:
    ctx->pc = 0x802E02E8u;
    ctx->downcount -= 4;
    // 802E02E8: addi    r3, r27, 0
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(0);

label_802E02EC:
    ctx->pc = 0x802E02ECu;
    // 802E02EC: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_802E02F0:
    ctx->pc = 0x802E02F0u;
    // 802E02F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802E02F4:
    ctx->pc = 0x802E02F4u;
    // 802E02F4: bl      0x802E0350
    {
            ctx->lr = 0x802E02F8u;
            goto label_802E0350;
    }

label_802E02F8:
    ctx->pc = 0x802E02F8u;
    ctx->downcount -= 3;
    // 802E02F8: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E02FC:
    ctx->pc = 0x802E02FCu;
    // 802E02FC: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E0300:
    ctx->pc = 0x802E0300u;
    // 802E0300: or   r3, r31, r0
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[0];
    }

label_802E0304:
    loop_802E0304(ctx);
    if (ctx->pc == 0x802E0310u) goto label_802E0310;
    return;
label_802E0308:
    // 802E0308: rlwinm. r0, r0, 0, 31, 31
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

label_802E030C:
    // 802E030C: bc    4, 2, 0x802E0304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0304u;
                return;
            }
            goto label_802E0304;
        }
    }

label_802E0310:
    ctx->pc = 0x802E0310u;
    ctx->downcount -= 21;
    // 802E0310: lwz     r4, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E0314:
    ctx->pc = 0x802E0314u;
    // 802E0314: cntlzw r0, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802E0318:
    ctx->pc = 0x802E0318u;
    // 802E0318: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_802E031C:
    ctx->pc = 0x802E031Cu;
    // 802E031C: andi.   r0, r4, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[4] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0320:
    ctx->pc = 0x802E0320u;
    // 802E0320: stw     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0324:
    ctx->pc = 0x802E0324u;
    // 802E0324: lmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E0328:
    ctx->pc = 0x802E0328u;
    // 802E0328: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E032C:
    ctx->pc = 0x802E032Cu;
    // 802E032C: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_802E0330:
    ctx->pc = 0x802E0330u;
    // 802E0330: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0334:
    ctx->pc = 0x802E0334u;
    // 802E0334: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0338:
    ctx->pc = 0x802E0338u;
    ctx->downcount -= 6;
    // 802E0338: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_802E033C:
    ctx->pc = 0x802E033Cu;
    // 802E033C: addi    r4, r3, 26624
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(26624);

label_802E0340:
    ctx->pc = 0x802E0340u;
    // 802E0340: lwz     r3, 26664(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26664);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E0344:
    ctx->pc = 0x802E0344u;
    // 802E0344: li      r0, 2058
    ctx->gpr[0] = (u32)(s32)(2058);

label_802E0348:
    ctx->pc = 0x802E0348u;
    // 802E0348: stw     r0, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E034C:
    ctx->pc = 0x802E034Cu;
    // 802E034C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0350:
    ctx->pc = 0x802E0350u;
    ctx->downcount -= 14;
    // 802E0350: stwu     r1, -72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-72);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0354:
    ctx->pc = 0x802E0354u;
    // 802E0354: cmplwi  r5, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E0358:
    ctx->pc = 0x802E0358u;
    // 802E0358: stmw     r22, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 22; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E035C:
    ctx->pc = 0x802E035Cu;
    // 802E035C: bc    12, 2, 0x802E0494
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0494;
        }
    }

label_802E0360:
    ctx->pc = 0x802E0360u;
    ctx->downcount -= 4;
    // 802E0360: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_802E0364:
    ctx->pc = 0x802E0364u;
    // 802E0364: cmpw    r29, r4
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

label_802E0368:
    ctx->pc = 0x802E0368u;
    // 802E0368: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802E036C:
    ctx->pc = 0x802E036Cu;
    // 802E036C: bc    4, 0, 0x802E048C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E048C;
        }
    }

label_802E0370:
    ctx->pc = 0x802E0370u;
    ctx->downcount -= 3;
    // 802E0370: cmpwi   r4, 8
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(8);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E0374:
    ctx->pc = 0x802E0374u;
    // 802E0374: addi    r6, r4, -8
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(-8);

label_802E0378:
    ctx->pc = 0x802E0378u;
    // 802E0378: bc    4, 1, 0x802E05D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E05D4;
        }
    }

label_802E037C:
    ctx->pc = 0x802E037Cu;
    ctx->downcount -= 7;
    // 802E037C: addi    r0, r6, 7
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(7);

label_802E0380:
    ctx->pc = 0x802E0380u;
    // 802E0380: rlwinm r0, r0, 29, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x1FFFFFFFu;
    }

label_802E0384:
    ctx->pc = 0x802E0384u;
    // 802E0384: cmpwi   r6, 0
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

label_802E0388:
    ctx->pc = 0x802E0388u;
    // 802E0388: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802E038C:
    ctx->pc = 0x802E038Cu;
    // 802E038C: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802E0390:
    ctx->pc = 0x802E0390u;
    // 802E0390: bc    4, 1, 0x802E05D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E05D4;
        }
    }

label_802E0394:
    loop_802E0394(ctx);
    if (ctx->pc == 0x802E0458u) goto label_802E0458;
    return;
label_802E0398:
    ctx->pc = 0x802E0398u;
    // 802E0398: lbz     r12, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read8(ctx, ea);
    }

label_802E039C:
    // 802E039C: addi    r0, r29, 1
    ctx->gpr[0] = ctx->gpr[29] + (u32)(s32)(1);

label_802E03A0:
    ctx->pc = 0x802E03A0u;
    // 802E03A0: lbz     r11, 1(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_802E03A4:
    // 802E03A4: rlwinm r10, r6, 3, 0, 28
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E03A8:
    ctx->pc = 0x802E03A8u;
    // 802E03A8: lbz     r9, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_802E03AC:
    // 802E03AC: subfic  r8, r0, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E03B0:
    ctx->pc = 0x802E03B0u;
    // 802E03B0: lbz     r7, 3(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_802E03B4:
    // 802E03B4: addi    r6, r29, 2
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(2);

label_802E03B8:
    ctx->pc = 0x802E03B8u;
    // 802E03B8: lbz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802E03BC:
    // 802E03BC: slw   r12, r12, r10
    {
        u32 sh = ctx->gpr[10] & 0x3Fu;
        ctx->gpr[12] = sh > 31 ? 0u : (ctx->gpr[12] << sh);
    }

label_802E03C0:
    ctx->pc = 0x802E03C0u;
    // 802E03C0: lbz     r23, 5(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5);
        ctx->gpr[23] = mem_read8(ctx, ea);
    }

label_802E03C4:
    // 802E03C4: rlwinm r10, r8, 3, 0, 28
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_802E03C8:
    ctx->pc = 0x802E03C8u;
    // 802E03C8: lbz     r25, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        ctx->gpr[25] = mem_read8(ctx, ea);
    }

label_802E03CC:
    // 802E03CC: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E03D0:
    ctx->pc = 0x802E03D0u;
    // 802E03D0: lbz     r27, 7(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(7);
        ctx->gpr[27] = mem_read8(ctx, ea);
    }

label_802E03D4:
    // 802E03D4: rlwinm r8, r6, 3, 0, 28
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E03D8:
    // 802E03D8: neg  r6, r29
    {
        u32 a = ctx->gpr[29];
        ctx->gpr[6] = (~a) + 1u;
    }

label_802E03DC:
    // 802E03DC: addi    r22, r29, 4
    ctx->gpr[22] = ctx->gpr[29] + (u32)(s32)(4);

label_802E03E0:
    // 802E03E0: rlwinm r6, r6, 3, 0, 28
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E03E4:
    // 802E03E4: subfic  r22, r22, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[22]) + 1u;
        ctx->gpr[22] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E03E8:
    // 802E03E8: addi    r24, r29, 5
    ctx->gpr[24] = ctx->gpr[29] + (u32)(s32)(5);

label_802E03EC:
    // 802E03EC: rlwinm r22, r22, 3, 0, 28
    {
        ctx->gpr[22] = dolrecomp_rotl32(ctx->gpr[22], 3u) & 0xFFFFFFF8u;
    }

label_802E03F0:
    // 802E03F0: subfic  r24, r24, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[24]) + 1u;
        ctx->gpr[24] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E03F4:
    // 802E03F4: addi    r26, r29, 6
    ctx->gpr[26] = ctx->gpr[29] + (u32)(s32)(6);

label_802E03F8:
    // 802E03F8: rlwinm r24, r24, 3, 0, 28
    {
        ctx->gpr[24] = dolrecomp_rotl32(ctx->gpr[24], 3u) & 0xFFFFFFF8u;
    }

label_802E03FC:
    // 802E03FC: subfic  r26, r26, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[26]) + 1u;
        ctx->gpr[26] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E0400:
    // 802E0400: addi    r28, r29, 7
    ctx->gpr[28] = ctx->gpr[29] + (u32)(s32)(7);

label_802E0404:
    // 802E0404: rlwinm r26, r26, 3, 0, 28
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[26], 3u) & 0xFFFFFFF8u;
    }

label_802E0408:
    // 802E0408: subfic  r28, r28, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[28]) + 1u;
        ctx->gpr[28] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E040C:
    // 802E040C: rlwinm r28, r28, 3, 0, 28
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[28], 3u) & 0xFFFFFFF8u;
    }

label_802E0410:
    // 802E0410: or   r30, r30, r12
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[12];
    }

label_802E0414:
    // 802E0414: slw   r10, r11, r10
    {
        u32 sh = ctx->gpr[10] & 0x3Fu;
        ctx->gpr[10] = sh > 31 ? 0u : (ctx->gpr[11] << sh);
    }

label_802E0418:
    // 802E0418: or   r30, r30, r10
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[10];
    }

label_802E041C:
    // 802E041C: slw   r8, r9, r8
    {
        u32 sh = ctx->gpr[8] & 0x3Fu;
        ctx->gpr[8] = sh > 31 ? 0u : (ctx->gpr[9] << sh);
    }

label_802E0420:
    // 802E0420: or   r30, r30, r8
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[8];
    }

label_802E0424:
    // 802E0424: slw   r6, r7, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
        ctx->gpr[6] = sh > 31 ? 0u : (ctx->gpr[7] << sh);
    }

label_802E0428:
    // 802E0428: or   r30, r30, r6
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[6];
    }

label_802E042C:
    // 802E042C: slw   r0, r0, r22
    {
        u32 sh = ctx->gpr[22] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_802E0430:
    // 802E0430: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

label_802E0434:
    // 802E0434: slw   r0, r23, r24
    {
        u32 sh = ctx->gpr[24] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[23] << sh);
    }

label_802E0438:
    // 802E0438: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

label_802E043C:
    // 802E043C: slw   r0, r25, r26
    {
        u32 sh = ctx->gpr[26] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[25] << sh);
    }

label_802E0440:
    // 802E0440: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

label_802E0444:
    // 802E0444: slw   r0, r27, r28
    {
        u32 sh = ctx->gpr[28] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[27] << sh);
    }

label_802E0448:
    // 802E0448: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

label_802E044C:
    // 802E044C: addi    r31, r31, 8
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(8);

label_802E0450:
    // 802E0450: addi    r29, r29, 8
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(8);

label_802E0454:
    // 802E0454: bc    16, 0, 0x802E0394
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0394u;
                return;
            }
            goto label_802E0394;
        }
    }

label_802E0458:
    ctx->pc = 0x802E0458u;
    ctx->downcount -= 1;
    // 802E0458: b       0x802E05D4
    {
            goto label_802E05D4;
    }

label_802E045C:
    ctx->downcount -= 5;
    // 802E045C: subf   r0, r29, r4
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_802E0460:
    // 802E0460: cmpw    r29, r4
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

label_802E0464:
    ctx->pc = 0x802E0464u;
    // 802E0464: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802E0468:
    // 802E0468: bc    4, 0, 0x802E048C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E048C;
        }
    }

label_802E046C:
    loop_802E046C(ctx);
    if (ctx->pc == 0x802E048Cu) goto label_802E048C;
    return;
label_802E0470:
    ctx->pc = 0x802E0470u;
    // 802E0470: lbz     r6, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_802E0474:
    // 802E0474: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_802E0478:
    // 802E0478: slw   r0, r6, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[6] << sh);
    }

label_802E047C:
    // 802E047C: or   r30, r30, r0
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[0];
    }

label_802E0480:
    // 802E0480: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

label_802E0484:
    // 802E0484: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_802E0488:
    // 802E0488: bc    16, 0, 0x802E046C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E046Cu;
                return;
            }
            goto label_802E046C;
        }
    }

label_802E048C:
    ctx->downcount -= 2;
    // 802E048C: lis     r6, -13312
    ctx->gpr[6] = ((u32)(s32)(-13312) << 16);

label_802E0490:
    ctx->pc = 0x802E0490u;
    // 802E0490: stw     r30, 26680(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(26680);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E0494:
    ctx->downcount -= 8;
    // 802E0494: addi    r0, r4, -1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-1);

label_802E0498:
    // 802E0498: lis     r6, -13312
    ctx->gpr[6] = ((u32)(s32)(-13312) << 16);

label_802E049C:
    // 802E049C: rlwinm r7, r5, 2, 0, 29
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_802E04A0:
    // 802E04A0: addi    r8, r6, 26624
    ctx->gpr[8] = ctx->gpr[6] + (u32)(s32)(26624);

label_802E04A4:
    // 802E04A4: ori     r6, r7, 0x0001
    ctx->gpr[6] = ctx->gpr[7] | 0x0001u;

label_802E04A8:
    // 802E04A8: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_802E04AC:
    // 802E04AC: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802E04B0:
    ctx->pc = 0x802E04B0u;
    // 802E04B0: stwu     r0, 52(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
        ctx->gpr[8] = ea;
    }

label_802E04B4:
    loop_802E04B4(ctx);
    if (ctx->pc == 0x802E04C0u) goto label_802E04C0;
    return;
label_802E04B8:
    // 802E04B8: rlwinm. r0, r0, 0, 31, 31
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

label_802E04BC:
    // 802E04BC: bc    4, 2, 0x802E04B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E04B4u;
                return;
            }
            goto label_802E04B4;
        }
    }

label_802E04C0:
    ctx->downcount -= 2;
    // 802E04C0: cmplwi  r5, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E04C4:
    // 802E04C4: bc    4, 2, 0x802E05CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E05CC;
        }
    }

label_802E04C8:
    ctx->downcount -= 5;
    // 802E04C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802E04CC:
    // 802E04CC: lis     r6, -13312
    ctx->gpr[6] = ((u32)(s32)(-13312) << 16);

label_802E04D0:
    // 802E04D0: cmpw    r5, r4
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

label_802E04D4:
    ctx->pc = 0x802E04D4u;
    // 802E04D4: lwz     r0, 26680(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(26680);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E04D8:
    // 802E04D8: bc    4, 0, 0x802E05CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E05CC;
        }
    }

label_802E04DC:
    ctx->downcount -= 3;
    // 802E04DC: cmpwi   r4, 8
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(8);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E04E0:
    // 802E04E0: addi    r7, r4, -8
    ctx->gpr[7] = ctx->gpr[4] + (u32)(s32)(-8);

label_802E04E4:
    // 802E04E4: bc    4, 1, 0x802E05A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E05A0;
        }
    }

label_802E04E8:
    ctx->downcount -= 6;
    // 802E04E8: addi    r6, r7, 7
    ctx->gpr[6] = ctx->gpr[7] + (u32)(s32)(7);

label_802E04EC:
    // 802E04EC: rlwinm r6, r6, 29, 3, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 29u) & 0x1FFFFFFFu;
    }

label_802E04F0:
    // 802E04F0: cmpwi   r7, 0
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E04F4:
    ctx->pc = 0x802E04F4u;
    // 802E04F4: mtctr    r6
    ctx->ctr = ctx->gpr[6];

label_802E04F8:
    // 802E04F8: bc    4, 1, 0x802E05A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E05A0;
        }
    }

label_802E04FC:
    loop_802E04FC(ctx);
    if (ctx->pc == 0x802E05A0u) goto label_802E05A0;
    return;
label_802E0500:
    // 802E0500: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E0504:
    // 802E0504: addi    r6, r5, 1
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(1);

label_802E0508:
    // 802E0508: srw   r8, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[8] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E050C:
    // 802E050C: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E0510:
    ctx->pc = 0x802E0510u;
    // 802E0510: stb     r8, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802E0514:
    // 802E0514: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E0518:
    // 802E0518: addi    r6, r5, 2
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(2);

label_802E051C:
    // 802E051C: srw   r12, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[12] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E0520:
    // 802E0520: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E0524:
    ctx->pc = 0x802E0524u;
    // 802E0524: stb     r12, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[12]);
    }

label_802E0528:
    // 802E0528: rlwinm r6, r6, 3, 0, 28
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E052C:
    // 802E052C: srw   r11, r0, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
        ctx->gpr[11] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E0530:
    // 802E0530: neg  r6, r5
    {
        u32 a = ctx->gpr[5];
        ctx->gpr[6] = (~a) + 1u;
    }

label_802E0534:
    ctx->pc = 0x802E0534u;
    // 802E0534: stb     r11, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[11]);
    }

label_802E0538:
    // 802E0538: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E053C:
    // 802E053C: addi    r6, r5, 4
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(4);

label_802E0540:
    // 802E0540: srw   r10, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[10] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E0544:
    // 802E0544: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E0548:
    ctx->pc = 0x802E0548u;
    // 802E0548: stb     r10, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

label_802E054C:
    // 802E054C: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E0550:
    // 802E0550: addi    r6, r5, 5
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(5);

label_802E0554:
    // 802E0554: srw   r9, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[9] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E0558:
    // 802E0558: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E055C:
    ctx->pc = 0x802E055Cu;
    // 802E055C: stb     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_802E0560:
    // 802E0560: rlwinm r7, r6, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E0564:
    // 802E0564: srw   r8, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[8] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E0568:
    // 802E0568: addi    r6, r5, 6
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(6);

label_802E056C:
    ctx->pc = 0x802E056Cu;
    // 802E056C: stb     r8, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802E0570:
    // 802E0570: subfic  r7, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[7] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E0574:
    // 802E0574: addi    r6, r5, 7
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(7);

label_802E0578:
    // 802E0578: rlwinm r7, r7, 3, 0, 28
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 3u) & 0xFFFFFFF8u;
    }

label_802E057C:
    // 802E057C: srw   r7, r0, r7
    {
        u32 sh = ctx->gpr[7] & 0x3Fu;
        ctx->gpr[7] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E0580:
    // 802E0580: subfic  r6, r6, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_802E0584:
    ctx->pc = 0x802E0584u;
    // 802E0584: stb     r7, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_802E0588:
    // 802E0588: rlwinm r6, r6, 3, 0, 28
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 3u) & 0xFFFFFFF8u;
    }

label_802E058C:
    // 802E058C: srw   r6, r0, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
        ctx->gpr[6] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E0590:
    ctx->pc = 0x802E0590u;
    // 802E0590: stb     r6, 7(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802E0594:
    // 802E0594: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

label_802E0598:
    // 802E0598: addi    r5, r5, 8
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(8);

label_802E059C:
    // 802E059C: bc    16, 0, 0x802E04FC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E04FCu;
                return;
            }
            goto label_802E04FC;
        }
    }

label_802E05A0:
    ctx->downcount -= 5;
    // 802E05A0: subf   r6, r5, r4
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_802E05A4:
    // 802E05A4: cmpw    r5, r4
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

label_802E05A8:
    ctx->pc = 0x802E05A8u;
    // 802E05A8: mtctr    r6
    ctx->ctr = ctx->gpr[6];

label_802E05AC:
    // 802E05AC: bc    4, 0, 0x802E05CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E05CC;
        }
    }

label_802E05B0:
    loop_802E05B0(ctx);
    if (ctx->pc == 0x802E05CCu) goto label_802E05CC;
    return;
label_802E05B4:
    // 802E05B4: rlwinm r4, r4, 3, 0, 28
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_802E05B8:
    // 802E05B8: srw   r4, r0, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[4] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_802E05BC:
    ctx->pc = 0x802E05BCu;
    // 802E05BC: stb     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802E05C0:
    // 802E05C0: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_802E05C4:
    // 802E05C4: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_802E05C8:
    // 802E05C8: bc    16, 0, 0x802E05B0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E05B0u;
                return;
            }
            goto label_802E05B0;
        }
    }

label_802E05CC:
    ctx->downcount -= 2;
    // 802E05CC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802E05D0:
    // 802E05D0: b       0x802E05DC
    {
            goto label_802E05DC;
    }

label_802E05D4:
    ctx->downcount -= 2;
    // 802E05D4: add   r7, r3, r29
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802E05D8:
    // 802E05D8: b       0x802E045C
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E045Cu;
                return;
            }
            goto label_802E045C;
    }

label_802E05DC:
    ctx->pc = 0x802E05DCu;
    ctx->downcount -= 13;
    // 802E05DC: lmw     r22, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 22; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E05E0:
    ctx->pc = 0x802E05E0u;
    // 802E05E0: addi    r1, r1, 72
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(72);

label_802E05E4:
    ctx->pc = 0x802E05E4u;
    // 802E05E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E05E8:
    ctx->pc = 0x802E05E8u;
    ctx->downcount -= 2;
    // 802E05E8: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_802E05EC:
    ctx->pc = 0x802E05ECu;
    // 802E05EC: addi    r3, r3, 26624
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(26624);

label_802E05F0:
    loop_802E05F0(ctx);
    if (ctx->pc == 0x802E05FCu) goto label_802E05FC;
    return;
label_802E05F4:
    // 802E05F4: rlwinm. r0, r0, 0, 31, 31
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

label_802E05F8:
    // 802E05F8: bc    4, 2, 0x802E05F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E05F0u;
                return;
            }
            goto label_802E05F0;
        }
    }

label_802E05FC:
    ctx->pc = 0x802E05FCu;
    ctx->downcount -= 2;
    // 802E05FC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802E0600:
    ctx->pc = 0x802E0600u;
    // 802E0600: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0604:
    ctx->pc = 0x802E0604u;
    ctx->downcount -= 7;
    // 802E0604: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_802E0608:
    ctx->pc = 0x802E0608u;
    // 802E0608: lwz     r0, 26664(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26664);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E060C:
    ctx->pc = 0x802E060Cu;
    // 802E060C: addi    r4, r3, 26624
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(26624);

label_802E0610:
    ctx->pc = 0x802E0610u;
    // 802E0610: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802E0614:
    ctx->pc = 0x802E0614u;
    // 802E0614: andi.   r0, r0, 0x0405
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0618:
    ctx->pc = 0x802E0618u;
    // 802E0618: stw     r0, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E061C:
    ctx->pc = 0x802E061Cu;
    // 802E061C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0620:
    ctx->pc = 0x802E0620u;
    ctx->downcount -= 10;
    // 802E0620: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_802E0624:
    ctx->pc = 0x802E0624u;
    // 802E0624: addi    r4, r4, 26624
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(26624);

label_802E0628:
    ctx->pc = 0x802E0628u;
    // 802E0628: lwz     r5, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802E062C:
    ctx->pc = 0x802E062Cu;
    // 802E062C: rlwinm r0, r3, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0xFFFFFFF0u;
    }

label_802E0630:
    ctx->pc = 0x802E0630u;
    // 802E0630: ori     r0, r0, 0x0080
    ctx->gpr[0] = ctx->gpr[0] | 0x0080u;

label_802E0634:
    ctx->pc = 0x802E0634u;
    // 802E0634: andi.   r5, r5, 0x0405
    {
        ctx->gpr[5] = ctx->gpr[5] & 0x0405u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0638:
    ctx->pc = 0x802E0638u;
    // 802E0638: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802E063C:
    ctx->pc = 0x802E063Cu;
    // 802E063C: or   r5, r5, r0
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802E0640:
    ctx->pc = 0x802E0640u;
    // 802E0640: stw     r5, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802E0644:
    ctx->pc = 0x802E0644u;
    // 802E0644: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0648:
    ctx->pc = 0x802E0648u;
    ctx->downcount -= 6;
    // 802E0648: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E064C:
    ctx->pc = 0x802E064Cu;
    // 802E064C: lis     r3, 2
    ctx->gpr[3] = ((u32)(s32)(2) << 16);

label_802E0650:
    ctx->pc = 0x802E0650u;
    // 802E0650: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0654:
    ctx->pc = 0x802E0654u;
    // 802E0654: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_802E0658:
    ctx->pc = 0x802E0658u;
    // 802E0658: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E065C:
    ctx->pc = 0x802E065Cu;
    // 802E065C: bl      0x802C354C
    {
            ctx->lr = 0x802E0660u;
            ctx->pc = 0x802C354Cu;
            return;
    }

label_802E0660:
    ctx->pc = 0x802E0660u;
    ctx->downcount -= 8;
    // 802E0660: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_802E0664:
    ctx->pc = 0x802E0664u;
    // 802E0664: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E0668:
    ctx->pc = 0x802E0668u;
    // 802E0668: stw     r0, 26664(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26664);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E066C:
    ctx->pc = 0x802E066Cu;
    // 802E066C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0670:
    ctx->pc = 0x802E0670u;
    // 802E0670: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E0674:
    ctx->pc = 0x802E0674u;
    // 802E0674: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0678:
    ctx->pc = 0x802E0678u;
    // 802E0678: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E067C:
    ctx->pc = 0x802E067Cu;
    ctx->downcount -= 20;
    // 802E067C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0680:
    ctx->pc = 0x802E0680u;
    // 802E0680: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0684:
    ctx->pc = 0x802E0684u;
    // 802E0684: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E0688:
    ctx->pc = 0x802E0688u;
    // 802E0688: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E068C:
    ctx->pc = 0x802E068Cu;
    // 802E068C: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_802E0690:
    ctx->pc = 0x802E0690u;
    // 802E0690: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802E0694:
    ctx->pc = 0x802E0694u;
    // 802E0694: lwz     r0, -28200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-28200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0698:
    ctx->pc = 0x802E0698u;
    // 802E0698: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802E069C:
    ctx->pc = 0x802E069Cu;
    // 802E069C: cmpwi   r0, 0
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

label_802E06A0:
    ctx->pc = 0x802E06A0u;
    // 802E06A0: bc    12, 2, 0x802E06B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E06B4;
        }
    }

label_802E06A4:
    ctx->pc = 0x802E06A4u;
    ctx->downcount -= 4;
    // 802E06A4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E06A8:
    ctx->pc = 0x802E06A8u;
    // 802E06A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802E06AC:
    ctx->pc = 0x802E06ACu;
    // 802E06AC: stw     r0, -28200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-28200);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E06B0:
    ctx->pc = 0x802E06B0u;
    // 802E06B0: bl      0x802DACC8
    {
            ctx->lr = 0x802E06B4u;
            ctx->pc = 0x802DACC8u;
            return;
    }

label_802E06B4:
    ctx->pc = 0x802E06B4u;
    ctx->downcount -= 3;
    // 802E06B4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802E06B8:
    ctx->pc = 0x802E06B8u;
    // 802E06B8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E06BC:
    ctx->pc = 0x802E06BCu;
    // 802E06BC: bl      0x802DADD8
    {
            ctx->lr = 0x802E06C0u;
            ctx->pc = 0x802DADD8u;
            return;
    }

label_802E06C0:
    ctx->pc = 0x802E06C0u;
    ctx->downcount -= 17;
    // 802E06C0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E06C4:
    ctx->pc = 0x802E06C4u;
    // 802E06C4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E06C8:
    ctx->pc = 0x802E06C8u;
    // 802E06C8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E06CC:
    ctx->pc = 0x802E06CCu;
    // 802E06CC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E06D0:
    ctx->pc = 0x802E06D0u;
    // 802E06D0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_802E06D4:
    ctx->pc = 0x802E06D4u;
    // 802E06D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E06D8:
    ctx->pc = 0x802E06D8u;
    ctx->downcount -= 7;
    // 802E06D8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E06DC:
    ctx->pc = 0x802E06DCu;
    // 802E06DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E06E0:
    ctx->pc = 0x802E06E0u;
    // 802E06E0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E06E4:
    ctx->pc = 0x802E06E4u;
    // 802E06E4: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802E06E8:
    ctx->pc = 0x802E06E8u;
    // 802E06E8: addi    r0, r9, -1
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-1);

label_802E06EC:
    ctx->pc = 0x802E06ECu;
    // 802E06EC: cmplwi  r0, 0x0001
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

label_802E06F0:
    ctx->pc = 0x802E06F0u;
    // 802E06F0: bc    4, 1, 0x802E070C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E070C;
        }
    }

label_802E06F4:
    ctx->pc = 0x802E06F4u;
    ctx->downcount -= 3;
    // 802E06F4: cmpwi   r9, 0
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

label_802E06F8:
    ctx->pc = 0x802E06F8u;
    // 802E06F8: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_802E06FC:
    ctx->pc = 0x802E06FCu;
    // 802E06FC: bc    12, 2, 0x802E0718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0718;
        }
    }

label_802E0700:
    ctx->pc = 0x802E0700u;
    ctx->downcount -= 2;
    // 802E0700: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_802E0704:
    ctx->pc = 0x802E0704u;
    // 802E0704: bl      0x80291688
    {
            ctx->lr = 0x802E0708u;
            ctx->pc = 0x80291688u;
            return;
    }

label_802E0708:
    ctx->pc = 0x802E0708u;
    ctx->downcount -= 1;
    // 802E0708: b       0x802E0718
    {
            goto label_802E0718;
    }

label_802E070C:
    ctx->pc = 0x802E070Cu;
    ctx->downcount -= 3;
    // 802E070C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802E0710:
    ctx->pc = 0x802E0710u;
    // 802E0710: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_802E0714:
    ctx->pc = 0x802E0714u;
    // 802E0714: bl      0x802E067C
    {
            ctx->lr = 0x802E0718u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E067Cu;
                return;
            }
            goto label_802E067C;
    }

label_802E0718:
    ctx->pc = 0x802E0718u;
    ctx->downcount -= 5;
    // 802E0718: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E071C:
    ctx->pc = 0x802E071Cu;
    // 802E071C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0720:
    ctx->pc = 0x802E0720u;
    // 802E0720: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E0724:
    ctx->pc = 0x802E0724u;
    // 802E0724: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0728:
    ctx->pc = 0x802E0728u;
    ctx->downcount -= 4;
    // 802E0728: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E072C:
    ctx->pc = 0x802E072Cu;
    // 802E072C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0730:
    ctx->pc = 0x802E0730u;
    // 802E0730: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0734:
    ctx->pc = 0x802E0734u;
    // 802E0734: bl      0x802E06D8
    {
            ctx->lr = 0x802E0738u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E06D8u;
                return;
            }
            goto label_802E06D8;
    }

label_802E0738:
    ctx->pc = 0x802E0738u;
    ctx->downcount -= 5;
    // 802E0738: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E073C:
    ctx->pc = 0x802E073Cu;
    // 802E073C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0740:
    ctx->pc = 0x802E0740u;
    // 802E0740: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E0744:
    ctx->pc = 0x802E0744u;
    // 802E0744: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0748:
    ctx->pc = 0x802E0748u;
    ctx->downcount -= 4;
    // 802E0748: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E074C:
    ctx->pc = 0x802E074Cu;
    // 802E074C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0750:
    ctx->pc = 0x802E0750u;
    // 802E0750: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0754:
    ctx->pc = 0x802E0754u;
    // 802E0754: bl      0x80291678
    {
            ctx->lr = 0x802E0758u;
            ctx->pc = 0x80291678u;
            return;
    }

label_802E0758:
    ctx->pc = 0x802E0758u;
    ctx->downcount -= 5;
    // 802E0758: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E075C:
    ctx->pc = 0x802E075Cu;
    // 802E075C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0760:
    ctx->pc = 0x802E0760u;
    // 802E0760: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E0764:
    ctx->pc = 0x802E0764u;
    // 802E0764: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0768:
    ctx->pc = 0x802E0768u;
    ctx->downcount -= 4;
    // 802E0768: li      r0, 8192
    ctx->gpr[0] = (u32)(s32)(8192);

label_802E076C:
    ctx->pc = 0x802E076Cu;
    // 802E076C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802E0770:
    ctx->pc = 0x802E0770u;
    // 802E0770: stw     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0774:
    ctx->pc = 0x802E0774u;
    // 802E0774: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0778:
    ctx->pc = 0x802E0778u;
    ctx->downcount -= 4;
    // 802E0778: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E077C:
    ctx->pc = 0x802E077Cu;
    // 802E077C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0780:
    ctx->pc = 0x802E0780u;
    // 802E0780: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0784:
    ctx->pc = 0x802E0784u;
    // 802E0784: bl      0x80291690
    {
            ctx->lr = 0x802E0788u;
            ctx->pc = 0x80291690u;
            return;
    }

label_802E0788:
    ctx->pc = 0x802E0788u;
    ctx->downcount -= 5;
    // 802E0788: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E078C:
    ctx->pc = 0x802E078Cu;
    // 802E078C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0790:
    ctx->pc = 0x802E0790u;
    // 802E0790: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E0794:
    ctx->pc = 0x802E0794u;
    // 802E0794: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0798:
    ctx->pc = 0x802E0798u;
    ctx->downcount -= 4;
    // 802E0798: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E079C:
    ctx->pc = 0x802E079Cu;
    // 802E079C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E07A0:
    ctx->pc = 0x802E07A0u;
    // 802E07A0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E07A4:
    ctx->pc = 0x802E07A4u;
    // 802E07A4: bl      0x80291680
    {
            ctx->lr = 0x802E07A8u;
            ctx->pc = 0x80291680u;
            return;
    }

label_802E07A8:
    ctx->pc = 0x802E07A8u;
    ctx->downcount -= 5;
    // 802E07A8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E07AC:
    ctx->pc = 0x802E07ACu;
    // 802E07AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E07B0:
    ctx->pc = 0x802E07B0u;
    // 802E07B0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E07B4:
    ctx->pc = 0x802E07B4u;
    // 802E07B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E07B8:
    ctx->pc = 0x802E07B8u;
    ctx->downcount -= 22;
    // 802E07B8: stwu     r1, -120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-120);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E07BC:
    ctx->pc = 0x802E07BCu;
    // 802E07BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E07C0:
    ctx->pc = 0x802E07C0u;
    // 802E07C0: stmw     r30, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E07C4:
    ctx->pc = 0x802E07C4u;
    // 802E07C4: stw     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E07C8:
    ctx->pc = 0x802E07C8u;
    // 802E07C8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802E07CC:
    ctx->pc = 0x802E07CCu;
    // 802E07CC: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802E07D0:
    ctx->pc = 0x802E07D0u;
    // 802E07D0: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802E07D4:
    ctx->pc = 0x802E07D4u;
    // 802E07D4: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_802E07D8:
    ctx->pc = 0x802E07D8u;
    // 802E07D8: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_802E07DC:
    ctx->pc = 0x802E07DCu;
    // 802E07DC: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_802E07E0:
    ctx->pc = 0x802E07E0u;
    // 802E07E0: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_802E07E4:
    ctx->pc = 0x802E07E4u;
    // 802E07E4: bc    4, 6, 0x802E0808
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E0808;
        }
    }

label_802E07E8:
    ctx->pc = 0x802E07E8u;
    ctx->downcount -= 8;
    // 802E07E8: stfd     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x802E07E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_802E07EC:
    ctx->pc = 0x802E07ECu;
    // 802E07EC: stfd     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x802E07ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_802E07F0:
    ctx->pc = 0x802E07F0u;
    // 802E07F0: stfd     f3, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x802E07F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_802E07F4:
    ctx->pc = 0x802E07F4u;
    // 802E07F4: stfd     f4, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x802E07F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_802E07F8:
    ctx->pc = 0x802E07F8u;
    // 802E07F8: stfd     f5, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x802E07F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_802E07FC:
    ctx->pc = 0x802E07FCu;
    // 802E07FC: stfd     f6, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x802E07FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_802E0800:
    ctx->pc = 0x802E0800u;
    // 802E0800: stfd     f7, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x802E0800u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_802E0804:
    ctx->pc = 0x802E0804u;
    // 802E0804: stfd     f8, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x802E0804u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_802E0808:
    ctx->pc = 0x802E0808u;
    ctx->downcount -= 3;
    // 802E0808: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802E080C:
    ctx->pc = 0x802E080Cu;
    // 802E080C: andi.   r0, r31, 0x0200
    {
        ctx->gpr[0] = ctx->gpr[31] & 0x0200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0810:
    ctx->pc = 0x802E0810u;
    // 802E0810: bc    12, 2, 0x802E0838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0838;
        }
    }

label_802E0814:
    ctx->pc = 0x802E0814u;
    ctx->downcount -= 3;
    // 802E0814: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802E0818:
    ctx->pc = 0x802E0818u;
    // 802E0818: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802E081C:
    ctx->pc = 0x802E081Cu;
    // 802E081C: bl      0x80291668
    {
            ctx->lr = 0x802E0820u;
            ctx->pc = 0x80291668u;
            return;
    }

label_802E0820:
    ctx->pc = 0x802E0820u;
    ctx->downcount -= 2;
    // 802E0820: cmpwi   r3, -1
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

label_802E0824:
    ctx->pc = 0x802E0824u;
    // 802E0824: bc    12, 2, 0x802E0838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0838;
        }
    }

label_802E0828:
    ctx->pc = 0x802E0828u;
    ctx->downcount -= 1;
    // 802E0828: bl      0x80291678
    {
            ctx->lr = 0x802E082Cu;
            ctx->pc = 0x80291678u;
            return;
    }

label_802E082C:
    ctx->pc = 0x802E082Cu;
    ctx->downcount -= 3;
    // 802E082C: cmpwi   r3, 0
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

label_802E0830:
    ctx->pc = 0x802E0830u;
    // 802E0830: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_802E0834:
    ctx->pc = 0x802E0834u;
    // 802E0834: bc    4, 2, 0x802E0848
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E0848;
        }
    }

label_802E0838:
    ctx->pc = 0x802E0838u;
    ctx->downcount -= 4;
    // 802E0838: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802E083C:
    ctx->pc = 0x802E083Cu;
    // 802E083C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E0840:
    ctx->pc = 0x802E0840u;
    // 802E0840: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802E0844:
    ctx->pc = 0x802E0844u;
    // 802E0844: bl      0x80291670
    {
            ctx->lr = 0x802E0848u;
            ctx->pc = 0x80291670u;
            return;
    }

label_802E0848:
    ctx->pc = 0x802E0848u;
    ctx->downcount -= 16;
    // 802E0848: lwz     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E084C:
    ctx->pc = 0x802E084Cu;
    // 802E084C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0850:
    ctx->pc = 0x802E0850u;
    // 802E0850: lmw     r30, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E0854:
    ctx->pc = 0x802E0854u;
    // 802E0854: addi    r1, r1, 120
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(120);

label_802E0858:
    ctx->pc = 0x802E0858u;
    // 802E0858: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E085C:
    ctx->pc = 0x802E085Cu;
    ctx->downcount -= 2;
    // 802E085C: cntlzw r3, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_802E0860:
    ctx->pc = 0x802E0860u;
    // 802E0860: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0864:
    ctx->pc = 0x802E0864u;
    ctx->downcount -= 2;
    // 802E0864: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802E0868:
    ctx->pc = 0x802E0868u;
    // 802E0868: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E086C:
    ctx->pc = 0x802E086Cu;
    ctx->downcount -= 2;
    // 802E086C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802E0870:
    ctx->pc = 0x802E0870u;
    // 802E0870: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0874:
    ctx->pc = 0x802E0874u;
    ctx->downcount -= 9;
    // 802E0874: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0878:
    ctx->pc = 0x802E0878u;
    // 802E0878: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E087C:
    ctx->pc = 0x802E087Cu;
    // 802E087C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0880:
    ctx->pc = 0x802E0880u;
    // 802E0880: lwz     r9, -29484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-29484);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_802E0884:
    ctx->pc = 0x802E0884u;
    // 802E0884: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802E0888:
    ctx->pc = 0x802E0888u;
    // 802E0888: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802E088C:
    ctx->pc = 0x802E088Cu;
    // 802E088C: lwz     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E0890:
    ctx->pc = 0x802E0890u;
    // 802E0890: or   r4, r0, r0
    {
        ctx->gpr[4] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802E0894:
    ctx->pc = 0x802E0894u;
    // 802E0894: bl      0x80299648
    {
            ctx->lr = 0x802E0898u;
            ctx->pc = 0x80299648u;
            return;
    }

label_802E0898:
    ctx->pc = 0x802E0898u;
    ctx->downcount -= 5;
    // 802E0898: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E089C:
    ctx->pc = 0x802E089Cu;
    // 802E089C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E08A0:
    ctx->pc = 0x802E08A0u;
    // 802E08A0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E08A4:
    ctx->pc = 0x802E08A4u;
    // 802E08A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E08A8:
    ctx->pc = 0x802E08A8u;
    ctx->downcount -= 7;
    // 802E08A8: lis     r4, -32709
    ctx->gpr[4] = ((u32)(s32)(-32709) << 16);

label_802E08AC:
    ctx->pc = 0x802E08ACu;
    // 802E08AC: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E08B0:
    ctx->pc = 0x802E08B0u;
    // 802E08B0: addi    r0, r4, 18048
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(18048);

label_802E08B4:
    ctx->pc = 0x802E08B4u;
    // 802E08B4: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802E08B8:
    ctx->pc = 0x802E08B8u;
    // 802E08B8: lwz     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E08BC:
    ctx->pc = 0x802E08BCu;
    // 802E08BC: cmpwi   r0, 0
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

label_802E08C0:
    ctx->pc = 0x802E08C0u;
    // 802E08C0: bclr  4, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E08C4:
    ctx->pc = 0x802E08C4u;
    ctx->downcount -= 3;
    // 802E08C4: lbz     r0, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802E08C8:
    ctx->pc = 0x802E08C8u;
    // 802E08C8: cmplwi  r0, 0x0000
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

label_802E08CC:
    ctx->pc = 0x802E08CCu;
    // 802E08CC: bc    4, 2, 0x802E08DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E08DC;
        }
    }

label_802E08D0:
    ctx->pc = 0x802E08D0u;
    ctx->downcount -= 3;
    // 802E08D0: lbz     r0, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802E08D4:
    ctx->pc = 0x802E08D4u;
    // 802E08D4: cmplwi  r0, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E08D8:
    ctx->pc = 0x802E08D8u;
    // 802E08D8: bc    12, 2, 0x802E08E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E08E8;
        }
    }

label_802E08DC:
    ctx->pc = 0x802E08DCu;
    ctx->downcount -= 3;
    // 802E08DC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802E08E0:
    ctx->pc = 0x802E08E0u;
    // 802E08E0: stw     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E08E4:
    ctx->pc = 0x802E08E4u;
    // 802E08E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E08E8:
    ctx->pc = 0x802E08E8u;
    ctx->downcount -= 5;
    // 802E08E8: lbz     r0, 7(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(7);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802E08EC:
    ctx->pc = 0x802E08ECu;
    // 802E08EC: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E08F0:
    ctx->pc = 0x802E08F0u;
    // 802E08F0: andi.   r0, r0, 0x003A
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x003Au;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E08F4:
    ctx->pc = 0x802E08F4u;
    // 802E08F4: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E08F8:
    ctx->pc = 0x802E08F8u;
    // 802E08F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E08FC:
    ctx->pc = 0x802E08FCu;
    ctx->downcount -= 35;
    // 802E08FC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0900:
    ctx->pc = 0x802E0900u;
    // 802E0900: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_802E0904:
    ctx->pc = 0x802E0904u;
    // 802E0904: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0908:
    ctx->pc = 0x802E0908u;
    // 802E0908: lis     r4, -32709
    ctx->gpr[4] = ((u32)(s32)(-32709) << 16);

label_802E090C:
    ctx->pc = 0x802E090Cu;
    // 802E090C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0910:
    ctx->pc = 0x802E0910u;
    // 802E0910: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E0914:
    ctx->pc = 0x802E0914u;
    // 802E0914: addi    r29, r4, 18048
    ctx->gpr[29] = ctx->gpr[4] + (u32)(s32)(18048);

label_802E0918:
    ctx->pc = 0x802E0918u;
    // 802E0918: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_802E091C:
    ctx->pc = 0x802E091Cu;
    // 802E091C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_802E0920:
    ctx->pc = 0x802E0920u;
    // 802E0920: lwz     r0, 248(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0924:
    ctx->pc = 0x802E0924u;
    // 802E0924: lis     r3, 17180
    ctx->gpr[3] = ((u32)(s32)(17180) << 16);

label_802E0928:
    ctx->pc = 0x802E0928u;
    // 802E0928: addi    r3, r3, -8573
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-8573);

label_802E092C:
    ctx->pc = 0x802E092Cu;
    // 802E092C: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_802E0930:
    ctx->pc = 0x802E0930u;
    // 802E0930: mulhwu   r0, r3, r0
    {
        u64 product = (u64)ctx->gpr[3] * (u64)ctx->gpr[0];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_802E0934:
    ctx->pc = 0x802E0934u;
    // 802E0934: rlwinm r0, r0, 17, 15, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x0001FFFFu;
    }

label_802E0938:
    ctx->pc = 0x802E0938u;
    // 802E0938: mulli   r0, r0, 60
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)60);

label_802E093C:
    ctx->pc = 0x802E093Cu;
    // 802E093C: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E0940:
    ctx->pc = 0x802E0940u;
    // 802E0940: addi    r28, r3, 17792
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(17792);

label_802E0944:
    ctx->pc = 0x802E0944u;
    // 802E0944: rlwinm r30, r0, 29, 3, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x1FFFFFFFu;
    }

label_802E0948:
    ctx->pc = 0x802E0948u;
    ctx->downcount -= 4;
    // 802E0948: stw     r30, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E094C:
    // 802E094C: addi    r3, r29, 36
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(36);

label_802E0950:
    ctx->pc = 0x802E0950u;
    // 802E0950: stw     r31, 48(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E0954:
    // 802E0954: bl      0x802C73D4
    {
            ctx->lr = 0x802E0958u;
            ctx->pc = 0x802C73D4u;
            return;
    }

label_802E0958:
    ctx->downcount -= 6;
    // 802E0958: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_802E095C:
    ctx->pc = 0x802E095Cu;
    // 802E095C: stw     r28, 248(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(248);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_802E0960:
    // 802E0960: cmpwi   r27, 4
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E0964:
    // 802E0964: addi    r29, r29, 256
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(256);

label_802E0968:
    // 802E0968: addi    r28, r28, 64
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(64);

label_802E096C:
    // 802E096C: bc    12, 0, 0x802E0948
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E0948u;
                return;
            }
            goto label_802E0948;
        }
    }

label_802E0970:
    ctx->pc = 0x802E0970u;
    ctx->downcount -= 1;
    // 802E0970: bl      0x802BDAB4
    {
            ctx->lr = 0x802E0974u;
            ctx->pc = 0x802BDAB4u;
            return;
    }

label_802E0974:
    ctx->pc = 0x802E0974u;
    ctx->downcount -= 1;
    // 802E0974: bl      0x802AF5C0
    {
            ctx->lr = 0x802E0978u;
            ctx->pc = 0x802AF5C0u;
            return;
    }

label_802E0978:
    ctx->pc = 0x802E0978u;
    ctx->downcount -= 5;
    // 802E0978: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E097C:
    ctx->pc = 0x802E097Cu;
    // 802E097C: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_802E0980:
    ctx->pc = 0x802E0980u;
    // 802E0980: stw     r0, -25088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25088);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0984:
    ctx->pc = 0x802E0984u;
    // 802E0984: addi    r3, r3, -28176
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-28176);

label_802E0988:
    ctx->pc = 0x802E0988u;
    // 802E0988: bl      0x802C4E6C
    {
            ctx->lr = 0x802E098Cu;
            ctx->pc = 0x802C4E6Cu;
            return;
    }

label_802E098C:
    ctx->pc = 0x802E098Cu;
    ctx->downcount -= 16;
    // 802E098C: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E0990:
    ctx->pc = 0x802E0990u;
    // 802E0990: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0994:
    ctx->pc = 0x802E0994u;
    // 802E0994: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802E0998:
    ctx->pc = 0x802E0998u;
    // 802E0998: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E099C:
    ctx->pc = 0x802E099Cu;
    // 802E099C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E09A0:
    ctx->pc = 0x802E09A0u;
    ctx->downcount -= 10;
    // 802E09A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E09A4:
    ctx->pc = 0x802E09A4u;
    // 802E09A4: lis     r6, -32709
    ctx->gpr[6] = ((u32)(s32)(-32709) << 16);

label_802E09A8:
    ctx->pc = 0x802E09A8u;
    // 802E09A8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E09AC:
    ctx->pc = 0x802E09ACu;
    // 802E09AC: rlwinm r7, r3, 8, 0, 23
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E09B0:
    ctx->pc = 0x802E09B0u;
    // 802E09B0: addi    r0, r6, 18048
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(18048);

label_802E09B4:
    ctx->pc = 0x802E09B4u;
    // 802E09B4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E09B8:
    ctx->pc = 0x802E09B8u;
    // 802E09B8: add   r7, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802E09BC:
    ctx->pc = 0x802E09BCu;
    // 802E09BC: lwz     r0, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E09C0:
    ctx->pc = 0x802E09C0u;
    // 802E09C0: cmplwi  r0, 0x0000
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

label_802E09C4:
    ctx->pc = 0x802E09C4u;
    // 802E09C4: bc    12, 2, 0x802E09D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E09D0;
        }
    }

label_802E09C8:
    ctx->pc = 0x802E09C8u;
    ctx->downcount -= 2;
    // 802E09C8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802E09CC:
    ctx->pc = 0x802E09CCu;
    // 802E09CC: b       0x802E09F4
    {
            goto label_802E09F4;
    }

label_802E09D0:
    ctx->pc = 0x802E09D0u;
    ctx->downcount -= 9;
    // 802E09D0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E09D4:
    ctx->pc = 0x802E09D4u;
    // 802E09D4: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E09D8:
    ctx->pc = 0x802E09D8u;
    // 802E09D8: lis     r6, -32722
    ctx->gpr[6] = ((u32)(s32)(-32722) << 16);

label_802E09DC:
    ctx->pc = 0x802E09DCu;
    // 802E09DC: addi    r6, r6, 2216
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2216);

label_802E09E0:
    ctx->pc = 0x802E09E0u;
    // 802E09E0: stw     r4, 20(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802E09E4:
    ctx->pc = 0x802E09E4u;
    // 802E09E4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802E09E8:
    ctx->pc = 0x802E09E8u;
    // 802E09E8: stw     r5, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802E09EC:
    ctx->pc = 0x802E09ECu;
    // 802E09EC: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_802E09F0:
    ctx->pc = 0x802E09F0u;
    // 802E09F0: bl      0x802E1294
    {
            ctx->lr = 0x802E09F4u;
            goto label_802E1294;
    }

label_802E09F4:
    ctx->pc = 0x802E09F4u;
    ctx->downcount -= 5;
    // 802E09F4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E09F8:
    ctx->pc = 0x802E09F8u;
    // 802E09F8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E09FC:
    ctx->pc = 0x802E09FCu;
    // 802E09FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0A00:
    ctx->pc = 0x802E0A00u;
    // 802E0A00: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0A04:
    ctx->pc = 0x802E0A04u;
    ctx->downcount -= 12;
    // 802E0A04: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0A08:
    ctx->pc = 0x802E0A08u;
    // 802E0A08: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0A0C:
    ctx->pc = 0x802E0A0Cu;
    // 802E0A0C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0A10:
    ctx->pc = 0x802E0A10u;
    // 802E0A10: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E0A14:
    ctx->pc = 0x802E0A14u;
    // 802E0A14: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802E0A18:
    ctx->pc = 0x802E0A18u;
    // 802E0A18: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E0A1C:
    ctx->pc = 0x802E0A1Cu;
    // 802E0A1C: rlwinm r5, r31, 8, 0, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 8u) & 0xFFFFFF00u;
    }

label_802E0A20:
    ctx->pc = 0x802E0A20u;
    // 802E0A20: addi    r0, r3, 18048
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18048);

label_802E0A24:
    ctx->pc = 0x802E0A24u;
    // 802E0A24: add   r7, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802E0A28:
    ctx->pc = 0x802E0A28u;
    // 802E0A28: lwz     r0, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0A2C:
    ctx->pc = 0x802E0A2Cu;
    // 802E0A2C: cmplwi  r0, 0x0000
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

label_802E0A30:
    ctx->pc = 0x802E0A30u;
    // 802E0A30: bc    12, 2, 0x802E0A3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0A3C;
        }
    }

label_802E0A34:
    ctx->pc = 0x802E0A34u;
    ctx->downcount -= 2;
    // 802E0A34: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802E0A38:
    ctx->pc = 0x802E0A38u;
    // 802E0A38: b       0x802E0A6C
    {
            goto label_802E0A6C;
    }

label_802E0A3C:
    ctx->pc = 0x802E0A3Cu;
    ctx->downcount -= 12;
    // 802E0A3C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E0A40:
    ctx->pc = 0x802E0A40u;
    // 802E0A40: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0A44:
    ctx->pc = 0x802E0A44u;
    // 802E0A44: lis     r5, -32722
    ctx->gpr[5] = ((u32)(s32)(-32722) << 16);

label_802E0A48:
    ctx->pc = 0x802E0A48u;
    // 802E0A48: addi    r0, r5, 4304
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(4304);

label_802E0A4C:
    ctx->pc = 0x802E0A4Cu;
    // 802E0A4C: stw     r4, 20(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802E0A50:
    ctx->pc = 0x802E0A50u;
    // 802E0A50: lis     r3, -32722
    ctx->gpr[3] = ((u32)(s32)(-32722) << 16);

label_802E0A54:
    ctx->pc = 0x802E0A54u;
    // 802E0A54: addi    r6, r3, 2216
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(2216);

label_802E0A58:
    ctx->pc = 0x802E0A58u;
    // 802E0A58: stw     r0, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0A5C:
    ctx->pc = 0x802E0A5Cu;
    // 802E0A5C: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_802E0A60:
    ctx->pc = 0x802E0A60u;
    // 802E0A60: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802E0A64:
    ctx->pc = 0x802E0A64u;
    // 802E0A64: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_802E0A68:
    ctx->pc = 0x802E0A68u;
    // 802E0A68: bl      0x802E1294
    {
            ctx->lr = 0x802E0A6Cu;
            goto label_802E1294;
    }

label_802E0A6C:
    ctx->pc = 0x802E0A6Cu;
    ctx->downcount -= 2;
    // 802E0A6C: cmpwi   r3, 0
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

label_802E0A70:
    ctx->pc = 0x802E0A70u;
    // 802E0A70: bc    12, 2, 0x802E0A78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0A78;
        }
    }

label_802E0A74:
    ctx->pc = 0x802E0A74u;
    ctx->downcount -= 1;
    // 802E0A74: b       0x802E0A80
    {
            goto label_802E0A80;
    }

label_802E0A78:
    ctx->pc = 0x802E0A78u;
    ctx->downcount -= 2;
    // 802E0A78: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E0A7C:
    ctx->pc = 0x802E0A7Cu;
    // 802E0A7C: bl      0x802E1104
    {
            ctx->lr = 0x802E0A80u;
            goto label_802E1104;
    }

label_802E0A80:
    ctx->pc = 0x802E0A80u;
    ctx->downcount -= 6;
    // 802E0A80: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0A84:
    ctx->pc = 0x802E0A84u;
    // 802E0A84: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E0A88:
    ctx->pc = 0x802E0A88u;
    // 802E0A88: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802E0A8C:
    ctx->pc = 0x802E0A8Cu;
    // 802E0A8C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0A90:
    ctx->pc = 0x802E0A90u;
    // 802E0A90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0A94:
    ctx->pc = 0x802E0A94u;
    ctx->downcount -= 10;
    // 802E0A94: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0A98:
    ctx->pc = 0x802E0A98u;
    // 802E0A98: lis     r6, -32709
    ctx->gpr[6] = ((u32)(s32)(-32709) << 16);

label_802E0A9C:
    ctx->pc = 0x802E0A9Cu;
    // 802E0A9C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0AA0:
    ctx->pc = 0x802E0AA0u;
    // 802E0AA0: rlwinm r7, r3, 8, 0, 23
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E0AA4:
    ctx->pc = 0x802E0AA4u;
    // 802E0AA4: addi    r0, r6, 18048
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(18048);

label_802E0AA8:
    ctx->pc = 0x802E0AA8u;
    // 802E0AA8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0AAC:
    ctx->pc = 0x802E0AACu;
    // 802E0AAC: add   r7, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802E0AB0:
    ctx->pc = 0x802E0AB0u;
    // 802E0AB0: lwz     r0, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0AB4:
    ctx->pc = 0x802E0AB4u;
    // 802E0AB4: cmplwi  r0, 0x0000
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

label_802E0AB8:
    ctx->pc = 0x802E0AB8u;
    // 802E0AB8: bc    12, 2, 0x802E0AC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0AC4;
        }
    }

label_802E0ABC:
    ctx->pc = 0x802E0ABCu;
    ctx->downcount -= 2;
    // 802E0ABC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802E0AC0:
    ctx->pc = 0x802E0AC0u;
    // 802E0AC0: b       0x802E0AE8
    {
            goto label_802E0AE8;
    }

label_802E0AC4:
    ctx->pc = 0x802E0AC4u;
    ctx->downcount -= 9;
    // 802E0AC4: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_802E0AC8:
    ctx->pc = 0x802E0AC8u;
    // 802E0AC8: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0ACC:
    ctx->pc = 0x802E0ACCu;
    // 802E0ACC: lis     r6, -32722
    ctx->gpr[6] = ((u32)(s32)(-32722) << 16);

label_802E0AD0:
    ctx->pc = 0x802E0AD0u;
    // 802E0AD0: addi    r6, r6, 2216
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2216);

label_802E0AD4:
    ctx->pc = 0x802E0AD4u;
    // 802E0AD4: stw     r4, 20(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802E0AD8:
    ctx->pc = 0x802E0AD8u;
    // 802E0AD8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802E0ADC:
    ctx->pc = 0x802E0ADCu;
    // 802E0ADC: stw     r5, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802E0AE0:
    ctx->pc = 0x802E0AE0u;
    // 802E0AE0: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_802E0AE4:
    ctx->pc = 0x802E0AE4u;
    // 802E0AE4: bl      0x802E1294
    {
            ctx->lr = 0x802E0AE8u;
            goto label_802E1294;
    }

label_802E0AE8:
    ctx->pc = 0x802E0AE8u;
    ctx->downcount -= 5;
    // 802E0AE8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0AEC:
    ctx->pc = 0x802E0AECu;
    // 802E0AEC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E0AF0:
    ctx->pc = 0x802E0AF0u;
    // 802E0AF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0AF4:
    ctx->pc = 0x802E0AF4u;
    // 802E0AF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0AF8:
    ctx->pc = 0x802E0AF8u;
    ctx->downcount -= 12;
    // 802E0AF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0AFC:
    ctx->pc = 0x802E0AFCu;
    // 802E0AFC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0B00:
    ctx->pc = 0x802E0B00u;
    // 802E0B00: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0B04:
    ctx->pc = 0x802E0B04u;
    // 802E0B04: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E0B08:
    ctx->pc = 0x802E0B08u;
    // 802E0B08: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802E0B0C:
    ctx->pc = 0x802E0B0Cu;
    // 802E0B0C: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E0B10:
    ctx->pc = 0x802E0B10u;
    // 802E0B10: rlwinm r5, r31, 8, 0, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 8u) & 0xFFFFFF00u;
    }

label_802E0B14:
    ctx->pc = 0x802E0B14u;
    // 802E0B14: addi    r0, r3, 18048
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18048);

label_802E0B18:
    ctx->pc = 0x802E0B18u;
    // 802E0B18: add   r7, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802E0B1C:
    ctx->pc = 0x802E0B1Cu;
    // 802E0B1C: lwz     r0, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0B20:
    ctx->pc = 0x802E0B20u;
    // 802E0B20: cmplwi  r0, 0x0000
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

label_802E0B24:
    ctx->pc = 0x802E0B24u;
    // 802E0B24: bc    12, 2, 0x802E0B30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0B30;
        }
    }

label_802E0B28:
    ctx->pc = 0x802E0B28u;
    ctx->downcount -= 2;
    // 802E0B28: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802E0B2C:
    ctx->pc = 0x802E0B2Cu;
    // 802E0B2C: b       0x802E0B60
    {
            goto label_802E0B60;
    }

label_802E0B30:
    ctx->pc = 0x802E0B30u;
    ctx->downcount -= 12;
    // 802E0B30: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_802E0B34:
    ctx->pc = 0x802E0B34u;
    // 802E0B34: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0B38:
    ctx->pc = 0x802E0B38u;
    // 802E0B38: lis     r5, -32722
    ctx->gpr[5] = ((u32)(s32)(-32722) << 16);

label_802E0B3C:
    ctx->pc = 0x802E0B3Cu;
    // 802E0B3C: addi    r0, r5, 4304
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(4304);

label_802E0B40:
    ctx->pc = 0x802E0B40u;
    // 802E0B40: stw     r4, 20(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802E0B44:
    ctx->pc = 0x802E0B44u;
    // 802E0B44: lis     r3, -32722
    ctx->gpr[3] = ((u32)(s32)(-32722) << 16);

label_802E0B48:
    ctx->pc = 0x802E0B48u;
    // 802E0B48: addi    r6, r3, 2216
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(2216);

label_802E0B4C:
    ctx->pc = 0x802E0B4Cu;
    // 802E0B4C: stw     r0, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0B50:
    ctx->pc = 0x802E0B50u;
    // 802E0B50: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_802E0B54:
    ctx->pc = 0x802E0B54u;
    // 802E0B54: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802E0B58:
    ctx->pc = 0x802E0B58u;
    // 802E0B58: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_802E0B5C:
    ctx->pc = 0x802E0B5Cu;
    // 802E0B5C: bl      0x802E1294
    {
            ctx->lr = 0x802E0B60u;
            goto label_802E1294;
    }

label_802E0B60:
    ctx->pc = 0x802E0B60u;
    ctx->downcount -= 2;
    // 802E0B60: cmpwi   r3, 0
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

label_802E0B64:
    ctx->pc = 0x802E0B64u;
    // 802E0B64: bc    12, 2, 0x802E0B6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0B6C;
        }
    }

label_802E0B68:
    ctx->pc = 0x802E0B68u;
    ctx->downcount -= 1;
    // 802E0B68: b       0x802E0B74
    {
            goto label_802E0B74;
    }

label_802E0B6C:
    ctx->pc = 0x802E0B6Cu;
    ctx->downcount -= 2;
    // 802E0B6C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E0B70:
    ctx->pc = 0x802E0B70u;
    // 802E0B70: bl      0x802E1104
    {
            ctx->lr = 0x802E0B74u;
            goto label_802E1104;
    }

label_802E0B74:
    ctx->pc = 0x802E0B74u;
    ctx->downcount -= 6;
    // 802E0B74: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0B78:
    ctx->pc = 0x802E0B78u;
    // 802E0B78: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E0B7C:
    ctx->pc = 0x802E0B7Cu;
    // 802E0B7C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802E0B80:
    ctx->pc = 0x802E0B80u;
    // 802E0B80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0B84:
    ctx->pc = 0x802E0B84u;
    // 802E0B84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0B88:
    ctx->pc = 0x802E0B88u;
    ctx->downcount -= 4;
    // 802E0B88: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802E0B8C:
    ctx->pc = 0x802E0B8Cu;
    // 802E0B8C: stw     r0, -25088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25088);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0B90:
    ctx->pc = 0x802E0B90u;
    // 802E0B90: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802E0B94:
    ctx->pc = 0x802E0B94u;
    // 802E0B94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0B98:
    ctx->pc = 0x802E0B98u;
    ctx->downcount -= 21;
    // 802E0B98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0B9C:
    ctx->pc = 0x802E0B9Cu;
    // 802E0B9C: lis     r5, -32709
    ctx->gpr[5] = ((u32)(s32)(-32709) << 16);

label_802E0BA0:
    ctx->pc = 0x802E0BA0u;
    // 802E0BA0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0BA4:
    ctx->pc = 0x802E0BA4u;
    // 802E0BA4: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E0BA8:
    ctx->pc = 0x802E0BA8u;
    // 802E0BA8: addi    r0, r5, 18048
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(18048);

label_802E0BAC:
    ctx->pc = 0x802E0BACu;
    // 802E0BAC: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0BB0:
    ctx->pc = 0x802E0BB0u;
    // 802E0BB0: stmw     r23, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 23; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E0BB4:
    ctx->pc = 0x802E0BB4u;
    // 802E0BB4: add   r23, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[23] = res;
    }

label_802E0BB8:
    ctx->pc = 0x802E0BB8u;
    // 802E0BB8: addi    r24, r4, 0
    ctx->gpr[24] = ctx->gpr[4] + (u32)(s32)(0);

label_802E0BBC:
    ctx->pc = 0x802E0BBCu;
    // 802E0BBC: addi    r31, r23, 64
    ctx->gpr[31] = ctx->gpr[23] + (u32)(s32)(64);

label_802E0BC0:
    ctx->pc = 0x802E0BC0u;
    // 802E0BC0: bl      0x802C30E8
    {
            ctx->lr = 0x802E0BC4u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802E0BC4:
    ctx->pc = 0x802E0BC4u;
    ctx->downcount -= 4;
    // 802E0BC4: lwz     r0, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0BC8:
    ctx->pc = 0x802E0BC8u;
    // 802E0BC8: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802E0BCC:
    ctx->pc = 0x802E0BCCu;
    // 802E0BCC: cmplwi  r0, 0x0000
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

label_802E0BD0:
    ctx->pc = 0x802E0BD0u;
    // 802E0BD0: bc    12, 2, 0x802E0CD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0CD4;
        }
    }

label_802E0BD4:
    ctx->pc = 0x802E0BD4u;
    ctx->downcount -= 54;
    // 802E0BD4: lwz     r3, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E0BD8:
    ctx->pc = 0x802E0BD8u;
    // 802E0BD8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_802E0BDC:
    ctx->pc = 0x802E0BDCu;
    // 802E0BDC: lwz     r0, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0BE0:
    ctx->pc = 0x802E0BE0u;
    // 802E0BE0: li      r28, 2
    ctx->gpr[28] = (u32)(s32)(2);

label_802E0BE4:
    ctx->pc = 0x802E0BE4u;
    // 802E0BE4: mulli   r5, r3, 100
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)100);

label_802E0BE8:
    ctx->pc = 0x802E0BE8u;
    // 802E0BE8: lwz     r4, 100(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(100);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E0BEC:
    ctx->pc = 0x802E0BECu;
    // 802E0BEC: lwz     r3, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E0BF0:
    ctx->pc = 0x802E0BF0u;
    // 802E0BF0: divw   r4, r5, r4
    {
        s32 dividend = (s32)ctx->gpr[5];
        s32 divisor = (s32)ctx->gpr[4];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[4] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_802E0BF4:
    ctx->pc = 0x802E0BF4u;
    // 802E0BF4: xor   r3, r3, r30
    {
        ctx->gpr[3] = ctx->gpr[3] ^ ctx->gpr[30];
    }

label_802E0BF8:
    ctx->pc = 0x802E0BF8u;
    // 802E0BF8: xor   r0, r0, r30
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[30];
    }

label_802E0BFC:
    ctx->pc = 0x802E0BFCu;
    // 802E0BFC: or.   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0C00:
    ctx->pc = 0x802E0C00u;
    // 802E0C00: rlwinm r27, r4, 0, 24, 31
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_802E0C04:
    ctx->pc = 0x802E0C04u;
    // 802E0C04: bc    12, 2, 0x802E0CC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0CC4;
        }
    }

label_802E0C08:
    ctx->pc = 0x802E0C08u;
    ctx->downcount -= 1;
    // 802E0C08: bl      0x802C927C
    {
            ctx->lr = 0x802E0C0Cu;
            ctx->pc = 0x802C927Cu;
            return;
    }

label_802E0C0C:
    ctx->pc = 0x802E0C0Cu;
    ctx->downcount -= 19;
    // 802E0C0C: lis     r23, -32768
    ctx->gpr[23] = ((u32)(s32)(-32768) << 16);

label_802E0C10:
    ctx->pc = 0x802E0C10u;
    // 802E0C10: lwz     r6, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802E0C14:
    ctx->pc = 0x802E0C14u;
    // 802E0C14: lwz     r0, 248(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0C18:
    ctx->pc = 0x802E0C18u;
    // 802E0C18: lis     r5, 4194
    ctx->gpr[5] = ((u32)(s32)(4194) << 16);

label_802E0C1C:
    ctx->pc = 0x802E0C1Cu;
    // 802E0C1C: subfc   r25, r6, r4
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[25] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802E0C20:
    ctx->pc = 0x802E0C20u;
    // 802E0C20: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E0C24:
    ctx->pc = 0x802E0C24u;
    // 802E0C24: addi    r31, r5, 19923
    ctx->gpr[31] = ctx->gpr[5] + (u32)(s32)(19923);

label_802E0C28:
    ctx->pc = 0x802E0C28u;
    // 802E0C28: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_802E0C2C:
    ctx->pc = 0x802E0C2Cu;
    // 802E0C2C: mulhwu   r0, r31, r0
    {
        u64 product = (u64)ctx->gpr[31] * (u64)ctx->gpr[0];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_802E0C30:
    ctx->pc = 0x802E0C30u;
    // 802E0C30: subfe   r26, r4, r3
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[26] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802E0C34:
    ctx->pc = 0x802E0C34u;
    // 802E0C34: rlwinm r6, r0, 26, 6, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x03FFFFFFu;
    }

label_802E0C38:
    ctx->pc = 0x802E0C38u;
    // 802E0C38: addi    r3, r26, 0
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(0);

label_802E0C3C:
    ctx->pc = 0x802E0C3Cu;
    // 802E0C3C: addi    r4, r25, 0
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(0);

label_802E0C40:
    ctx->pc = 0x802E0C40u;
    // 802E0C40: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_802E0C44:
    ctx->pc = 0x802E0C44u;
    // 802E0C44: bl      0x80292134
    {
            ctx->lr = 0x802E0C48u;
            ctx->pc = 0x80292134u;
            return;
    }

label_802E0C48:
    ctx->pc = 0x802E0C48u;
    ctx->downcount -= 8;
    // 802E0C48: li      r7, 5500
    ctx->gpr[7] = (u32)(s32)(5500);

label_802E0C4C:
    ctx->pc = 0x802E0C4Cu;
    // 802E0C4C: xoris   r5, r3, 0x8000
    ctx->gpr[5] = ctx->gpr[3] ^ (0x8000u << 16);

label_802E0C50:
    ctx->pc = 0x802E0C50u;
    // 802E0C50: xoris   r3, r30, 0x8000
    ctx->gpr[3] = ctx->gpr[30] ^ (0x8000u << 16);

label_802E0C54:
    ctx->pc = 0x802E0C54u;
    // 802E0C54: subfc   r0, r7, r4
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802E0C58:
    ctx->pc = 0x802E0C58u;
    // 802E0C58: subfe   r3, r3, r5
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[5];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802E0C5C:
    ctx->pc = 0x802E0C5Cu;
    // 802E0C5C: subfe   r3, r5, r5
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[5];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_802E0C60:
    ctx->pc = 0x802E0C60u;
    // 802E0C60: neg.  r3, r3
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

label_802E0C64:
    ctx->pc = 0x802E0C64u;
    // 802E0C64: bc    12, 2, 0x802E0CB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0CB4;
        }
    }

label_802E0C68:
    ctx->pc = 0x802E0C68u;
    ctx->downcount -= 54;
    // 802E0C68: lwz     r3, 248(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(248);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E0C6C:
    ctx->pc = 0x802E0C6Cu;
    // 802E0C6C: mullw   r5, r30, r7
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[7];
        ctx->gpr[5] = (u32)product;
    }

label_802E0C70:
    ctx->pc = 0x802E0C70u;
    // 802E0C70: rlwinm r3, r3, 30, 2, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 30u) & 0x3FFFFFFFu;
    }

label_802E0C74:
    ctx->pc = 0x802E0C74u;
    // 802E0C74: mulhwu   r3, r31, r3
    {
        u64 product = (u64)ctx->gpr[31] * (u64)ctx->gpr[3];
        ctx->gpr[3] = (u32)(product >> 32);
    }

label_802E0C78:
    ctx->pc = 0x802E0C78u;
    // 802E0C78: rlwinm r6, r3, 26, 6, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[3], 26u) & 0x03FFFFFFu;
    }

label_802E0C7C:
    ctx->pc = 0x802E0C7Cu;
    // 802E0C7C: mulhwu   r3, r6, r7
    {
        u64 product = (u64)ctx->gpr[6] * (u64)ctx->gpr[7];
        ctx->gpr[3] = (u32)(product >> 32);
    }

label_802E0C80:
    ctx->pc = 0x802E0C80u;
    // 802E0C80: add   r5, r5, r3
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_802E0C84:
    ctx->pc = 0x802E0C84u;
    // 802E0C84: mullw   r3, r6, r30
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[30];
        ctx->gpr[3] = (u32)product;
    }

label_802E0C88:
    ctx->pc = 0x802E0C88u;
    // 802E0C88: srawi r0, r27, 31
    {
        u32 sh = 31u;
        u32 value = ctx->gpr[27];
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

label_802E0C8C:
    ctx->pc = 0x802E0C8Cu;
    // 802E0C8C: add   r5, r5, r3
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_802E0C90:
    ctx->pc = 0x802E0C90u;
    // 802E0C90: mullw   r3, r0, r25
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[25];
        ctx->gpr[3] = (u32)product;
    }

label_802E0C94:
    ctx->pc = 0x802E0C94u;
    // 802E0C94: mulhwu   r0, r27, r25
    {
        u64 product = (u64)ctx->gpr[27] * (u64)ctx->gpr[25];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_802E0C98:
    ctx->pc = 0x802E0C98u;
    // 802E0C98: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802E0C9C:
    ctx->pc = 0x802E0C9Cu;
    // 802E0C9C: mullw   r0, r27, r26
    {
        s64 product = (s64)(s32)ctx->gpr[27] * (s64)(s32)ctx->gpr[26];
        ctx->gpr[0] = (u32)product;
    }

label_802E0CA0:
    ctx->pc = 0x802E0CA0u;
    // 802E0CA0: mullw   r4, r27, r25
    {
        s64 product = (s64)(s32)ctx->gpr[27] * (s64)(s32)ctx->gpr[25];
        ctx->gpr[4] = (u32)product;
    }

label_802E0CA4:
    ctx->pc = 0x802E0CA4u;
    // 802E0CA4: mullw   r6, r6, r7
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[7];
        ctx->gpr[6] = (u32)product;
    }

label_802E0CA8:
    ctx->pc = 0x802E0CA8u;
    // 802E0CA8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802E0CAC:
    ctx->pc = 0x802E0CACu;
    // 802E0CAC: bl      0x80292134
    {
            ctx->lr = 0x802E0CB0u;
            ctx->pc = 0x80292134u;
            return;
    }

label_802E0CB0:
    ctx->pc = 0x802E0CB0u;
    ctx->downcount -= 1;
    // 802E0CB0: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_802E0CB4:
    ctx->pc = 0x802E0CB4u;
    ctx->downcount -= 3;
    // 802E0CB4: rlwinm r0, r27, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[27], 0u) & 0x000000FFu;
    }

label_802E0CB8:
    ctx->pc = 0x802E0CB8u;
    // 802E0CB8: cmplwi  r0, 0x0064
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0064u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E0CBC:
    ctx->pc = 0x802E0CBCu;
    // 802E0CBC: bc    12, 0, 0x802E0CC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0CC4;
        }
    }

label_802E0CC0:
    ctx->pc = 0x802E0CC0u;
    ctx->downcount -= 1;
    // 802E0CC0: li      r27, 100
    ctx->gpr[27] = (u32)(s32)(100);

label_802E0CC4:
    ctx->pc = 0x802E0CC4u;
    ctx->downcount -= 2;
    // 802E0CC4: cmplwi  r24, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[24]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E0CC8:
    ctx->pc = 0x802E0CC8u;
    // 802E0CC8: bc    12, 2, 0x802E0CEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0CEC;
        }
    }

label_802E0CCC:
    ctx->pc = 0x802E0CCCu;
    ctx->downcount -= 2;
    // 802E0CCC: stb     r27, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[27]);
    }

label_802E0CD0:
    ctx->pc = 0x802E0CD0u;
    // 802E0CD0: b       0x802E0CEC
    {
            goto label_802E0CEC;
    }

label_802E0CD4:
    ctx->pc = 0x802E0CD4u;
    ctx->downcount -= 3;
    // 802E0CD4: lwz     r0, 28(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0CD8:
    ctx->pc = 0x802E0CD8u;
    // 802E0CD8: cmplwi  r0, 0x0000
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

label_802E0CDC:
    ctx->pc = 0x802E0CDCu;
    // 802E0CDC: bc    12, 2, 0x802E0CE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0CE8;
        }
    }

label_802E0CE0:
    ctx->pc = 0x802E0CE0u;
    ctx->downcount -= 2;
    // 802E0CE0: li      r28, 2
    ctx->gpr[28] = (u32)(s32)(2);

label_802E0CE4:
    ctx->pc = 0x802E0CE4u;
    // 802E0CE4: b       0x802E0CEC
    {
            goto label_802E0CEC;
    }

label_802E0CE8:
    ctx->pc = 0x802E0CE8u;
    ctx->downcount -= 1;
    // 802E0CE8: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_802E0CEC:
    ctx->pc = 0x802E0CECu;
    ctx->downcount -= 2;
    // 802E0CEC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_802E0CF0:
    ctx->pc = 0x802E0CF0u;
    // 802E0CF0: bl      0x802C3110
    {
            ctx->lr = 0x802E0CF4u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802E0CF4:
    ctx->pc = 0x802E0CF4u;
    ctx->downcount -= 17;
    // 802E0CF4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_802E0CF8:
    ctx->pc = 0x802E0CF8u;
    // 802E0CF8: lmw     r23, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 23; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E0CFC:
    ctx->pc = 0x802E0CFCu;
    // 802E0CFC: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0D00:
    ctx->pc = 0x802E0D00u;
    // 802E0D00: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_802E0D04:
    ctx->pc = 0x802E0D04u;
    // 802E0D04: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0D08:
    ctx->pc = 0x802E0D08u;
    // 802E0D08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0D0C:
    ctx->pc = 0x802E0D0Cu;
    ctx->downcount -= 11;
    // 802E0D0C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0D10:
    ctx->pc = 0x802E0D10u;
    // 802E0D10: lis     r4, -32709
    ctx->gpr[4] = ((u32)(s32)(-32709) << 16);

label_802E0D14:
    ctx->pc = 0x802E0D14u;
    // 802E0D14: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0D18:
    ctx->pc = 0x802E0D18u;
    // 802E0D18: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E0D1C:
    ctx->pc = 0x802E0D1Cu;
    // 802E0D1C: addi    r0, r4, 18048
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(18048);

label_802E0D20:
    ctx->pc = 0x802E0D20u;
    // 802E0D20: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0D24:
    ctx->pc = 0x802E0D24u;
    // 802E0D24: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E0D28:
    ctx->pc = 0x802E0D28u;
    // 802E0D28: add   r31, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_802E0D2C:
    ctx->pc = 0x802E0D2Cu;
    // 802E0D2C: lwz     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0D30:
    ctx->pc = 0x802E0D30u;
    // 802E0D30: cmpwi   r0, 0
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

label_802E0D34:
    ctx->pc = 0x802E0D34u;
    // 802E0D34: bc    4, 2, 0x802E0D58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E0D58;
        }
    }

label_802E0D38:
    ctx->pc = 0x802E0D38u;
    ctx->downcount -= 4;
    // 802E0D38: lwz     r3, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E0D3C:
    ctx->pc = 0x802E0D3Cu;
    // 802E0D3C: addi    r4, r31, 5
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(5);

label_802E0D40:
    ctx->pc = 0x802E0D40u;
    // 802E0D40: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_802E0D44:
    ctx->pc = 0x802E0D44u;
    // 802E0D44: bl      0x80297D98
    {
            ctx->lr = 0x802E0D48u;
            ctx->pc = 0x80297D98u;
            return;
    }

label_802E0D48:
    ctx->pc = 0x802E0D48u;
    ctx->downcount -= 4;
    // 802E0D48: lbz     r0, 9(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(9);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802E0D4C:
    ctx->pc = 0x802E0D4Cu;
    // 802E0D4C: lwz     r3, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E0D50:
    ctx->pc = 0x802E0D50u;
    // 802E0D50: andi.   r0, r0, 0x003A
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x003Au;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0D54:
    ctx->pc = 0x802E0D54u;
    // 802E0D54: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0D58:
    ctx->pc = 0x802E0D58u;
    ctx->downcount -= 6;
    // 802E0D58: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0D5C:
    ctx->pc = 0x802E0D5Cu;
    // 802E0D5C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E0D60:
    ctx->pc = 0x802E0D60u;
    // 802E0D60: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802E0D64:
    ctx->pc = 0x802E0D64u;
    // 802E0D64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0D68:
    ctx->pc = 0x802E0D68u;
    // 802E0D68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0D6C:
    ctx->pc = 0x802E0D6Cu;
    ctx->downcount -= 10;
    // 802E0D6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0D70:
    ctx->pc = 0x802E0D70u;
    // 802E0D70: lis     r7, -32709
    ctx->gpr[7] = ((u32)(s32)(-32709) << 16);

label_802E0D74:
    ctx->pc = 0x802E0D74u;
    // 802E0D74: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0D78:
    ctx->pc = 0x802E0D78u;
    // 802E0D78: rlwinm r8, r3, 8, 0, 23
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E0D7C:
    ctx->pc = 0x802E0D7Cu;
    // 802E0D7C: addi    r0, r7, 18048
    ctx->gpr[0] = ctx->gpr[7] + (u32)(s32)(18048);

label_802E0D80:
    ctx->pc = 0x802E0D80u;
    // 802E0D80: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0D84:
    ctx->pc = 0x802E0D84u;
    // 802E0D84: add   r8, r0, r8
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802E0D88:
    ctx->pc = 0x802E0D88u;
    // 802E0D88: lwz     r0, 28(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0D8C:
    ctx->pc = 0x802E0D8Cu;
    // 802E0D8C: cmplwi  r0, 0x0000
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

label_802E0D90:
    ctx->pc = 0x802E0D90u;
    // 802E0D90: bc    12, 2, 0x802E0D9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0D9C;
        }
    }

label_802E0D94:
    ctx->pc = 0x802E0D94u;
    ctx->downcount -= 2;
    // 802E0D94: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802E0D98:
    ctx->pc = 0x802E0D98u;
    // 802E0D98: b       0x802E0DC8
    {
            goto label_802E0DC8;
    }

label_802E0D9C:
    ctx->pc = 0x802E0D9Cu;
    ctx->downcount -= 11;
    // 802E0D9C: li      r0, 20
    ctx->gpr[0] = (u32)(s32)(20);

label_802E0DA0:
    ctx->pc = 0x802E0DA0u;
    // 802E0DA0: stb     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0DA4:
    ctx->pc = 0x802E0DA4u;
    // 802E0DA4: lis     r7, -32722
    ctx->gpr[7] = ((u32)(s32)(-32722) << 16);

label_802E0DA8:
    ctx->pc = 0x802E0DA8u;
    // 802E0DA8: addi    r0, r7, 3340
    ctx->gpr[0] = ctx->gpr[7] + (u32)(s32)(3340);

label_802E0DAC:
    ctx->pc = 0x802E0DACu;
    // 802E0DAC: stw     r4, 24(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802E0DB0:
    ctx->pc = 0x802E0DB0u;
    // 802E0DB0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802E0DB4:
    ctx->pc = 0x802E0DB4u;
    // 802E0DB4: stw     r5, 20(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802E0DB8:
    ctx->pc = 0x802E0DB8u;
    // 802E0DB8: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_802E0DBC:
    ctx->pc = 0x802E0DBCu;
    // 802E0DBC: stw     r6, 28(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802E0DC0:
    ctx->pc = 0x802E0DC0u;
    // 802E0DC0: or   r6, r0, r0
    {
        ctx->gpr[6] = ctx->gpr[0] | ctx->gpr[0];
    }

label_802E0DC4:
    ctx->pc = 0x802E0DC4u;
    // 802E0DC4: bl      0x802E1294
    {
            ctx->lr = 0x802E0DC8u;
            goto label_802E1294;
    }

label_802E0DC8:
    ctx->pc = 0x802E0DC8u;
    ctx->downcount -= 5;
    // 802E0DC8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0DCC:
    ctx->pc = 0x802E0DCCu;
    // 802E0DCC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E0DD0:
    ctx->pc = 0x802E0DD0u;
    // 802E0DD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0DD4:
    ctx->pc = 0x802E0DD4u;
    // 802E0DD4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0DD8:
    ctx->pc = 0x802E0DD8u;
    ctx->downcount -= 12;
    // 802E0DD8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0DDC:
    ctx->pc = 0x802E0DDCu;
    // 802E0DDC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0DE0:
    ctx->pc = 0x802E0DE0u;
    // 802E0DE0: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0DE4:
    ctx->pc = 0x802E0DE4u;
    // 802E0DE4: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E0DE8:
    ctx->pc = 0x802E0DE8u;
    // 802E0DE8: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802E0DEC:
    ctx->pc = 0x802E0DECu;
    // 802E0DEC: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E0DF0:
    ctx->pc = 0x802E0DF0u;
    // 802E0DF0: rlwinm r6, r31, 8, 0, 23
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[31], 8u) & 0xFFFFFF00u;
    }

label_802E0DF4:
    ctx->pc = 0x802E0DF4u;
    // 802E0DF4: addi    r0, r3, 18048
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18048);

label_802E0DF8:
    ctx->pc = 0x802E0DF8u;
    // 802E0DF8: add   r8, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802E0DFC:
    ctx->pc = 0x802E0DFCu;
    // 802E0DFC: lwz     r0, 28(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0E00:
    ctx->pc = 0x802E0E00u;
    // 802E0E00: cmplwi  r0, 0x0000
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

label_802E0E04:
    ctx->pc = 0x802E0E04u;
    // 802E0E04: bc    12, 2, 0x802E0E10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0E10;
        }
    }

label_802E0E08:
    ctx->pc = 0x802E0E08u;
    ctx->downcount -= 2;
    // 802E0E08: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802E0E0C:
    ctx->pc = 0x802E0E0Cu;
    // 802E0E0C: b       0x802E0E44
    {
            goto label_802E0E44;
    }

label_802E0E10:
    ctx->pc = 0x802E0E10u;
    ctx->downcount -= 13;
    // 802E0E10: li      r0, 20
    ctx->gpr[0] = (u32)(s32)(20);

label_802E0E14:
    ctx->pc = 0x802E0E14u;
    // 802E0E14: stb     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0E18:
    ctx->pc = 0x802E0E18u;
    // 802E0E18: lis     r7, -32722
    ctx->gpr[7] = ((u32)(s32)(-32722) << 16);

label_802E0E1C:
    ctx->pc = 0x802E0E1Cu;
    // 802E0E1C: lis     r3, -32722
    ctx->gpr[3] = ((u32)(s32)(-32722) << 16);

label_802E0E20:
    ctx->pc = 0x802E0E20u;
    // 802E0E20: stw     r4, 24(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802E0E24:
    ctx->pc = 0x802E0E24u;
    // 802E0E24: addi    r6, r3, 3340
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(3340);

label_802E0E28:
    ctx->pc = 0x802E0E28u;
    // 802E0E28: addi    r0, r7, 4304
    ctx->gpr[0] = ctx->gpr[7] + (u32)(s32)(4304);

label_802E0E2C:
    ctx->pc = 0x802E0E2Cu;
    // 802E0E2C: stw     r5, 20(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802E0E30:
    ctx->pc = 0x802E0E30u;
    // 802E0E30: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E0E34:
    ctx->pc = 0x802E0E34u;
    // 802E0E34: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802E0E38:
    ctx->pc = 0x802E0E38u;
    // 802E0E38: stw     r0, 28(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0E3C:
    ctx->pc = 0x802E0E3Cu;
    // 802E0E3C: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_802E0E40:
    ctx->pc = 0x802E0E40u;
    // 802E0E40: bl      0x802E1294
    {
            ctx->lr = 0x802E0E44u;
            goto label_802E1294;
    }

label_802E0E44:
    ctx->pc = 0x802E0E44u;
    ctx->downcount -= 2;
    // 802E0E44: cmpwi   r3, 0
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

label_802E0E48:
    ctx->pc = 0x802E0E48u;
    // 802E0E48: bc    12, 2, 0x802E0E50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0E50;
        }
    }

label_802E0E4C:
    ctx->pc = 0x802E0E4Cu;
    ctx->downcount -= 1;
    // 802E0E4C: b       0x802E0E58
    {
            goto label_802E0E58;
    }

label_802E0E50:
    ctx->pc = 0x802E0E50u;
    ctx->downcount -= 2;
    // 802E0E50: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E0E54:
    ctx->pc = 0x802E0E54u;
    // 802E0E54: bl      0x802E1104
    {
            ctx->lr = 0x802E0E58u;
            goto label_802E1104;
    }

label_802E0E58:
    ctx->pc = 0x802E0E58u;
    ctx->downcount -= 6;
    // 802E0E58: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0E5C:
    ctx->pc = 0x802E0E5Cu;
    // 802E0E5C: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E0E60:
    ctx->pc = 0x802E0E60u;
    // 802E0E60: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_802E0E64:
    ctx->pc = 0x802E0E64u;
    // 802E0E64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0E68:
    ctx->pc = 0x802E0E68u;
    // 802E0E68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0E6C:
    ctx->pc = 0x802E0E6Cu;
    ctx->downcount -= 7;
    // 802E0E6C: lis     r4, -32709
    ctx->gpr[4] = ((u32)(s32)(-32709) << 16);

label_802E0E70:
    ctx->pc = 0x802E0E70u;
    // 802E0E70: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E0E74:
    ctx->pc = 0x802E0E74u;
    // 802E0E74: addi    r0, r4, 18048
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(18048);

label_802E0E78:
    ctx->pc = 0x802E0E78u;
    // 802E0E78: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802E0E7C:
    ctx->pc = 0x802E0E7Cu;
    // 802E0E7C: lwz     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0E80:
    ctx->pc = 0x802E0E80u;
    // 802E0E80: cmpwi   r0, 0
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

label_802E0E84:
    ctx->pc = 0x802E0E84u;
    // 802E0E84: bclr  4, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0E88:
    ctx->pc = 0x802E0E88u;
    ctx->downcount -= 5;
    // 802E0E88: lbz     r0, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802E0E8C:
    ctx->pc = 0x802E0E8Cu;
    // 802E0E8C: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E0E90:
    ctx->pc = 0x802E0E90u;
    // 802E0E90: andi.   r0, r0, 0x003A
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x003Au;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E0E94:
    ctx->pc = 0x802E0E94u;
    // 802E0E94: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0E98:
    ctx->pc = 0x802E0E98u;
    // 802E0E98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0E9C:
    ctx->pc = 0x802E0E9Cu;
    ctx->downcount -= 25;
    // 802E0E9C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0EA0:
    ctx->pc = 0x802E0EA0u;
    // 802E0EA0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0EA4:
    ctx->pc = 0x802E0EA4u;
    // 802E0EA4: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0EA8:
    ctx->pc = 0x802E0EA8u;
    // 802E0EA8: stmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E0EAC:
    ctx->pc = 0x802E0EACu;
    // 802E0EAC: addi    r27, r3, 0
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(0);

label_802E0EB0:
    ctx->pc = 0x802E0EB0u;
    // 802E0EB0: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E0EB4:
    ctx->pc = 0x802E0EB4u;
    // 802E0EB4: rlwinm r7, r27, 8, 0, 23
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[27], 8u) & 0xFFFFFF00u;
    }

label_802E0EB8:
    ctx->pc = 0x802E0EB8u;
    // 802E0EB8: addi    r0, r3, 18048
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18048);

label_802E0EBC:
    ctx->pc = 0x802E0EBCu;
    // 802E0EBC: add   r31, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_802E0EC0:
    ctx->pc = 0x802E0EC0u;
    // 802E0EC0: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_802E0EC4:
    ctx->pc = 0x802E0EC4u;
    // 802E0EC4: addi    r29, r5, 0
    ctx->gpr[29] = ctx->gpr[5] + (u32)(s32)(0);

label_802E0EC8:
    ctx->pc = 0x802E0EC8u;
    // 802E0EC8: lwz     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0ECC:
    ctx->pc = 0x802E0ECCu;
    // 802E0ECC: addi    r30, r6, 0
    ctx->gpr[30] = ctx->gpr[6] + (u32)(s32)(0);

label_802E0ED0:
    ctx->pc = 0x802E0ED0u;
    // 802E0ED0: cmplwi  r0, 0x0000
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

label_802E0ED4:
    ctx->pc = 0x802E0ED4u;
    // 802E0ED4: bc    12, 2, 0x802E0EE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0EE0;
        }
    }

label_802E0ED8:
    ctx->pc = 0x802E0ED8u;
    ctx->downcount -= 2;
    // 802E0ED8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802E0EDC:
    ctx->pc = 0x802E0EDCu;
    // 802E0EDC: b       0x802E0F1C
    {
            goto label_802E0F1C;
    }

label_802E0EE0:
    ctx->pc = 0x802E0EE0u;
    ctx->downcount -= 6;
    // 802E0EE0: li      r0, 21
    ctx->gpr[0] = (u32)(s32)(21);

label_802E0EE4:
    ctx->pc = 0x802E0EE4u;
    // 802E0EE4: stb     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0EE8:
    ctx->pc = 0x802E0EE8u;
    // 802E0EE8: addi    r4, r28, 0
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(0);

label_802E0EEC:
    ctx->pc = 0x802E0EECu;
    // 802E0EEC: addi    r3, r31, 1
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(1);

label_802E0EF0:
    ctx->pc = 0x802E0EF0u;
    // 802E0EF0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_802E0EF4:
    ctx->pc = 0x802E0EF4u;
    // 802E0EF4: bl      0x80297D98
    {
            ctx->lr = 0x802E0EF8u;
            ctx->pc = 0x80297D98u;
            return;
    }

label_802E0EF8:
    ctx->pc = 0x802E0EF8u;
    ctx->downcount -= 9;
    // 802E0EF8: stw     r28, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_802E0EFC:
    ctx->pc = 0x802E0EFCu;
    // 802E0EFC: lis     r3, -32722
    ctx->gpr[3] = ((u32)(s32)(-32722) << 16);

label_802E0F00:
    ctx->pc = 0x802E0F00u;
    // 802E0F00: addi    r6, r3, 3692
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(3692);

label_802E0F04:
    ctx->pc = 0x802E0F04u;
    // 802E0F04: stw     r29, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802E0F08:
    ctx->pc = 0x802E0F08u;
    // 802E0F08: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_802E0F0C:
    ctx->pc = 0x802E0F0Cu;
    // 802E0F0C: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_802E0F10:
    ctx->pc = 0x802E0F10u;
    // 802E0F10: stw     r30, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E0F14:
    ctx->pc = 0x802E0F14u;
    // 802E0F14: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802E0F18:
    ctx->pc = 0x802E0F18u;
    // 802E0F18: bl      0x802E1294
    {
            ctx->lr = 0x802E0F1Cu;
            goto label_802E1294;
    }

label_802E0F1C:
    ctx->pc = 0x802E0F1Cu;
    ctx->downcount -= 16;
    // 802E0F1C: lmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E0F20:
    ctx->pc = 0x802E0F20u;
    // 802E0F20: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0F24:
    ctx->pc = 0x802E0F24u;
    // 802E0F24: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_802E0F28:
    ctx->pc = 0x802E0F28u;
    // 802E0F28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0F2C:
    ctx->pc = 0x802E0F2Cu;
    // 802E0F2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0F30:
    ctx->pc = 0x802E0F30u;
    ctx->downcount -= 17;
    // 802E0F30: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0F34:
    ctx->pc = 0x802E0F34u;
    // 802E0F34: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0F38:
    ctx->pc = 0x802E0F38u;
    // 802E0F38: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E0F3C:
    ctx->pc = 0x802E0F3Cu;
    // 802E0F3C: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E0F40:
    ctx->pc = 0x802E0F40u;
    // 802E0F40: stw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E0F44:
    ctx->pc = 0x802E0F44u;
    // 802E0F44: addi    r30, r5, 0
    ctx->gpr[30] = ctx->gpr[5] + (u32)(s32)(0);

label_802E0F48:
    ctx->pc = 0x802E0F48u;
    // 802E0F48: stw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802E0F4C:
    ctx->pc = 0x802E0F4Cu;
    // 802E0F4C: addi    r29, r4, 0
    ctx->gpr[29] = ctx->gpr[4] + (u32)(s32)(0);

label_802E0F50:
    ctx->pc = 0x802E0F50u;
    // 802E0F50: stw     r28, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_802E0F54:
    ctx->pc = 0x802E0F54u;
    // 802E0F54: addi    r28, r3, 0
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(0);

label_802E0F58:
    ctx->pc = 0x802E0F58u;
    // 802E0F58: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E0F5C:
    ctx->pc = 0x802E0F5Cu;
    // 802E0F5C: rlwinm r6, r28, 8, 0, 23
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[28], 8u) & 0xFFFFFF00u;
    }

label_802E0F60:
    ctx->pc = 0x802E0F60u;
    // 802E0F60: addi    r0, r3, 18048
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18048);

label_802E0F64:
    ctx->pc = 0x802E0F64u;
    // 802E0F64: add   r31, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_802E0F68:
    ctx->pc = 0x802E0F68u;
    // 802E0F68: lwz     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0F6C:
    ctx->pc = 0x802E0F6Cu;
    // 802E0F6C: cmplwi  r0, 0x0000
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

label_802E0F70:
    ctx->pc = 0x802E0F70u;
    // 802E0F70: bc    12, 2, 0x802E0F7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0F7C;
        }
    }

label_802E0F74:
    ctx->pc = 0x802E0F74u;
    ctx->downcount -= 2;
    // 802E0F74: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802E0F78:
    ctx->pc = 0x802E0F78u;
    // 802E0F78: b       0x802E0FC0
    {
            goto label_802E0FC0;
    }

label_802E0F7C:
    ctx->pc = 0x802E0F7Cu;
    ctx->downcount -= 6;
    // 802E0F7C: li      r0, 21
    ctx->gpr[0] = (u32)(s32)(21);

label_802E0F80:
    ctx->pc = 0x802E0F80u;
    // 802E0F80: stb     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802E0F84:
    ctx->pc = 0x802E0F84u;
    // 802E0F84: addi    r4, r29, 0
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(0);

label_802E0F88:
    ctx->pc = 0x802E0F88u;
    // 802E0F88: addi    r3, r31, 1
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(1);

label_802E0F8C:
    ctx->pc = 0x802E0F8Cu;
    // 802E0F8C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_802E0F90:
    ctx->pc = 0x802E0F90u;
    // 802E0F90: bl      0x80297D98
    {
            ctx->lr = 0x802E0F94u;
            ctx->pc = 0x80297D98u;
            return;
    }

label_802E0F94:
    ctx->pc = 0x802E0F94u;
    ctx->downcount -= 11;
    // 802E0F94: stw     r29, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802E0F98:
    ctx->pc = 0x802E0F98u;
    // 802E0F98: lis     r4, -32722
    ctx->gpr[4] = ((u32)(s32)(-32722) << 16);

label_802E0F9C:
    ctx->pc = 0x802E0F9Cu;
    // 802E0F9C: addi    r0, r4, 4304
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(4304);

label_802E0FA0:
    ctx->pc = 0x802E0FA0u;
    // 802E0FA0: stw     r30, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E0FA4:
    ctx->pc = 0x802E0FA4u;
    // 802E0FA4: lis     r3, -32722
    ctx->gpr[3] = ((u32)(s32)(-32722) << 16);

label_802E0FA8:
    ctx->pc = 0x802E0FA8u;
    // 802E0FA8: addi    r6, r3, 3692
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(3692);

label_802E0FAC:
    ctx->pc = 0x802E0FACu;
    // 802E0FAC: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0FB0:
    ctx->pc = 0x802E0FB0u;
    // 802E0FB0: addi    r3, r28, 0
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(0);

label_802E0FB4:
    ctx->pc = 0x802E0FB4u;
    // 802E0FB4: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_802E0FB8:
    ctx->pc = 0x802E0FB8u;
    // 802E0FB8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_802E0FBC:
    ctx->pc = 0x802E0FBCu;
    // 802E0FBC: bl      0x802E1294
    {
            ctx->lr = 0x802E0FC0u;
            goto label_802E1294;
    }

label_802E0FC0:
    ctx->pc = 0x802E0FC0u;
    ctx->downcount -= 2;
    // 802E0FC0: cmpwi   r3, 0
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

label_802E0FC4:
    ctx->pc = 0x802E0FC4u;
    // 802E0FC4: bc    12, 2, 0x802E0FCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E0FCC;
        }
    }

label_802E0FC8:
    ctx->pc = 0x802E0FC8u;
    ctx->downcount -= 1;
    // 802E0FC8: b       0x802E0FD4
    {
            goto label_802E0FD4;
    }

label_802E0FCC:
    ctx->pc = 0x802E0FCCu;
    ctx->downcount -= 2;
    // 802E0FCC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_802E0FD0:
    ctx->pc = 0x802E0FD0u;
    // 802E0FD0: bl      0x802E1104
    {
            ctx->lr = 0x802E0FD4u;
            goto label_802E1104;
    }

label_802E0FD4:
    ctx->pc = 0x802E0FD4u;
    ctx->downcount -= 9;
    // 802E0FD4: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E0FD8:
    ctx->pc = 0x802E0FD8u;
    // 802E0FD8: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E0FDC:
    ctx->pc = 0x802E0FDCu;
    // 802E0FDC: lwz     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802E0FE0:
    ctx->pc = 0x802E0FE0u;
    // 802E0FE0: lwz     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802E0FE4:
    ctx->pc = 0x802E0FE4u;
    // 802E0FE4: lwz     r28, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_802E0FE8:
    ctx->pc = 0x802E0FE8u;
    // 802E0FE8: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_802E0FEC:
    ctx->pc = 0x802E0FECu;
    // 802E0FEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E0FF0:
    ctx->pc = 0x802E0FF0u;
    // 802E0FF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E0FF4:
    ctx->pc = 0x802E0FF4u;
    ctx->downcount -= 15;
    // 802E0FF4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E0FF8:
    ctx->pc = 0x802E0FF8u;
    // 802E0FF8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E0FFC:
    ctx->pc = 0x802E0FFCu;
    // 802E0FFC: stwu     r1, -760(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-760);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E1000:
    ctx->pc = 0x802E1000u;
    // 802E1000: stw     r31, 756(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(756);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E1004:
    ctx->pc = 0x802E1004u;
    // 802E1004: stw     r30, 752(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(752);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E1008:
    ctx->pc = 0x802E1008u;
    // 802E1008: addi    r30, r5, 0
    ctx->gpr[30] = ctx->gpr[5] + (u32)(s32)(0);

label_802E100C:
    ctx->pc = 0x802E100Cu;
    // 802E100C: stw     r29, 748(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(748);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802E1010:
    ctx->pc = 0x802E1010u;
    // 802E1010: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802E1014:
    ctx->pc = 0x802E1014u;
    // 802E1014: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E1018:
    ctx->pc = 0x802E1018u;
    // 802E1018: lwz     r0, -25088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25088);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E101C:
    ctx->pc = 0x802E101Cu;
    // 802E101C: rlwinm r6, r29, 8, 0, 23
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[29], 8u) & 0xFFFFFF00u;
    }

label_802E1020:
    ctx->pc = 0x802E1020u;
    // 802E1020: cmpwi   r0, 0
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

label_802E1024:
    ctx->pc = 0x802E1024u;
    // 802E1024: addi    r0, r3, 18048
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18048);

label_802E1028:
    ctx->pc = 0x802E1028u;
    // 802E1028: add   r31, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_802E102C:
    ctx->pc = 0x802E102Cu;
    // 802E102C: bc    4, 2, 0x802E10B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E10B4;
        }
    }

label_802E1030:
    ctx->pc = 0x802E1030u;
    ctx->downcount -= 2;
    // 802E1030: rlwinm. r0, r4, 0, 28, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000000Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E1034:
    ctx->pc = 0x802E1034u;
    // 802E1034: bc    12, 2, 0x802E1044
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E1044;
        }
    }

label_802E1038:
    ctx->pc = 0x802E1038u;
    ctx->downcount -= 3;
    // 802E1038: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802E103C:
    ctx->pc = 0x802E103Cu;
    // 802E103C: stw     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E1040:
    ctx->pc = 0x802E1040u;
    // 802E1040: b       0x802E104C
    {
            goto label_802E104C;
    }

label_802E1044:
    ctx->pc = 0x802E1044u;
    ctx->downcount -= 2;
    // 802E1044: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E1048:
    ctx->pc = 0x802E1048u;
    // 802E1048: stw     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E104C:
    ctx->pc = 0x802E104Cu;
    ctx->downcount -= 3;
    // 802E104C: lwz     r12, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802E1050:
    ctx->pc = 0x802E1050u;
    // 802E1050: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E1054:
    ctx->pc = 0x802E1054u;
    // 802E1054: bc    12, 2, 0x802E106C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E106C;
        }
    }

label_802E1058:
    ctx->pc = 0x802E1058u;
    ctx->downcount -= 6;
    // 802E1058: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E105C:
    ctx->pc = 0x802E105Cu;
    // 802E105C: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802E1060:
    ctx->pc = 0x802E1060u;
    // 802E1060: stw     r0, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E1064:
    ctx->pc = 0x802E1064u;
    // 802E1064: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_802E1068:
    ctx->pc = 0x802E1068u;
    // 802E1068: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802E106Cu;
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E106C:
    ctx->pc = 0x802E106Cu;
    ctx->downcount -= 3;
    // 802E106C: lwz     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E1070:
    ctx->pc = 0x802E1070u;
    // 802E1070: cmplwi  r0, 0x0000
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

label_802E1074:
    ctx->pc = 0x802E1074u;
    // 802E1074: bc    12, 2, 0x802E10B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E10B4;
        }
    }

label_802E1078:
    ctx->pc = 0x802E1078u;
    ctx->downcount -= 2;
    // 802E1078: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_802E107C:
    ctx->pc = 0x802E107Cu;
    // 802E107C: bl      0x802C013C
    {
            ctx->lr = 0x802E1080u;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802E1080:
    ctx->pc = 0x802E1080u;
    ctx->downcount -= 2;
    // 802E1080: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_802E1084:
    ctx->pc = 0x802E1084u;
    // 802E1084: bl      0x802BFF34
    {
            ctx->lr = 0x802E1088u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802E1088:
    ctx->pc = 0x802E1088u;
    ctx->downcount -= 8;
    // 802E1088: lwz     r12, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802E108C:
    ctx->pc = 0x802E108Cu;
    // 802E108C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E1090:
    ctx->pc = 0x802E1090u;
    // 802E1090: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_802E1094:
    ctx->pc = 0x802E1094u;
    // 802E1094: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E1098:
    ctx->pc = 0x802E1098u;
    // 802E1098: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802E109C:
    ctx->pc = 0x802E109Cu;
    // 802E109C: lwz     r4, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E10A0:
    ctx->pc = 0x802E10A0u;
    // 802E10A0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802E10A4u;
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E10A4:
    ctx->pc = 0x802E10A4u;
    ctx->downcount -= 2;
    // 802E10A4: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_802E10A8:
    ctx->pc = 0x802E10A8u;
    // 802E10A8: bl      0x802C013C
    {
            ctx->lr = 0x802E10ACu;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802E10AC:
    ctx->pc = 0x802E10ACu;
    ctx->downcount -= 2;
    // 802E10AC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802E10B0:
    ctx->pc = 0x802E10B0u;
    // 802E10B0: bl      0x802BFF34
    {
            ctx->lr = 0x802E10B4u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802E10B4:
    ctx->pc = 0x802E10B4u;
    ctx->downcount -= 8;
    // 802E10B4: lwz     r0, 764(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(764);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E10B8:
    ctx->pc = 0x802E10B8u;
    // 802E10B8: lwz     r31, 756(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(756);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E10BC:
    ctx->pc = 0x802E10BCu;
    // 802E10BC: lwz     r30, 752(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(752);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802E10C0:
    ctx->pc = 0x802E10C0u;
    // 802E10C0: lwz     r29, 748(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(748);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802E10C4:
    ctx->pc = 0x802E10C4u;
    // 802E10C4: addi    r1, r1, 760
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(760);

label_802E10C8:
    ctx->pc = 0x802E10C8u;
    // 802E10C8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E10CC:
    ctx->pc = 0x802E10CCu;
    // 802E10CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E10D0:
    ctx->pc = 0x802E10D0u;
    ctx->downcount -= 9;
    // 802E10D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E10D4:
    ctx->pc = 0x802E10D4u;
    // 802E10D4: lis     r4, -32709
    ctx->gpr[4] = ((u32)(s32)(-32709) << 16);

label_802E10D8:
    ctx->pc = 0x802E10D8u;
    // 802E10D8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E10DC:
    ctx->pc = 0x802E10DCu;
    // 802E10DC: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E10E0:
    ctx->pc = 0x802E10E0u;
    // 802E10E0: addi    r0, r4, 18048
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(18048);

label_802E10E4:
    ctx->pc = 0x802E10E4u;
    // 802E10E4: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_802E10E8:
    ctx->pc = 0x802E10E8u;
    // 802E10E8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E10EC:
    ctx->pc = 0x802E10ECu;
    // 802E10EC: addi    r3, r3, 36
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(36);

label_802E10F0:
    ctx->pc = 0x802E10F0u;
    // 802E10F0: bl      0x802C86D8
    {
            ctx->lr = 0x802E10F4u;
            ctx->pc = 0x802C86D8u;
            return;
    }

label_802E10F4:
    ctx->pc = 0x802E10F4u;
    ctx->downcount -= 5;
    // 802E10F4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E10F8:
    ctx->pc = 0x802E10F8u;
    // 802E10F8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802E10FC:
    ctx->pc = 0x802E10FCu;
    // 802E10FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E1100:
    ctx->pc = 0x802E1100u;
    // 802E1100: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E1104:
    ctx->pc = 0x802E1104u;
    ctx->downcount -= 10;
    // 802E1104: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E1108:
    ctx->pc = 0x802E1108u;
    // 802E1108: lis     r4, -32709
    ctx->gpr[4] = ((u32)(s32)(-32709) << 16);

label_802E110C:
    ctx->pc = 0x802E110Cu;
    // 802E110C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E1110:
    ctx->pc = 0x802E1110u;
    // 802E1110: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E1114:
    ctx->pc = 0x802E1114u;
    // 802E1114: addi    r0, r4, 18048
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(18048);

label_802E1118:
    ctx->pc = 0x802E1118u;
    // 802E1118: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E111C:
    ctx->pc = 0x802E111Cu;
    // 802E111C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E1120:
    ctx->pc = 0x802E1120u;
    // 802E1120: add   r31, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_802E1124:
    ctx->pc = 0x802E1124u;
    // 802E1124: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E1128:
    ctx->pc = 0x802E1128u;
    // 802E1128: bl      0x802C30E8
    {
            ctx->lr = 0x802E112Cu;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802E112C:
    ctx->pc = 0x802E112Cu;
    ctx->downcount -= 2;
    // 802E112C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802E1130:
    ctx->pc = 0x802E1130u;
    // 802E1130: b       0x802E113C
    {
            goto label_802E113C;
    }

label_802E1134:
    ctx->downcount -= 2;
    // 802E1134: addi    r3, r31, 36
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(36);

label_802E1138:
    // 802E1138: bl      0x802C85EC
    {
            ctx->lr = 0x802E113Cu;
            ctx->pc = 0x802C85ECu;
            return;
    }

label_802E113C:
    ctx->pc = 0x802E113Cu;
    ctx->downcount -= 3;
    // 802E113C: lwz     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E1140:
    // 802E1140: cmplwi  r0, 0x0000
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

label_802E1144:
    // 802E1144: bc    4, 2, 0x802E1134
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802E1134u;
                return;
            }
            goto label_802E1134;
        }
    }

label_802E1148:
    ctx->pc = 0x802E1148u;
    ctx->downcount -= 3;
    // 802E1148: lwz     r31, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E114C:
    ctx->pc = 0x802E114Cu;
    // 802E114C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_802E1150:
    ctx->pc = 0x802E1150u;
    // 802E1150: bl      0x802C3110
    {
            ctx->lr = 0x802E1154u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802E1154:
    ctx->pc = 0x802E1154u;
    ctx->downcount -= 8;
    // 802E1154: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E1158:
    ctx->pc = 0x802E1158u;
    // 802E1158: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E115C:
    ctx->pc = 0x802E115Cu;
    // 802E115C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E1160:
    ctx->pc = 0x802E1160u;
    // 802E1160: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802E1164:
    ctx->pc = 0x802E1164u;
    // 802E1164: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_802E1168:
    ctx->pc = 0x802E1168u;
    // 802E1168: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E116C:
    ctx->pc = 0x802E116Cu;
    // 802E116C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E1170:
    ctx->pc = 0x802E1170u;
    ctx->downcount -= 14;
    // 802E1170: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E1174:
    ctx->pc = 0x802E1174u;
    // 802E1174: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E1178:
    ctx->pc = 0x802E1178u;
    // 802E1178: stwu     r1, -752(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-752);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E117C:
    ctx->pc = 0x802E117Cu;
    // 802E117C: stw     r31, 748(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(748);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E1180:
    ctx->pc = 0x802E1180u;
    // 802E1180: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802E1184:
    ctx->pc = 0x802E1184u;
    // 802E1184: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E1188:
    ctx->pc = 0x802E1188u;
    // 802E1188: stw     r30, 744(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(744);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802E118C:
    ctx->pc = 0x802E118Cu;
    // 802E118C: rlwinm r5, r31, 8, 0, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 8u) & 0xFFFFFF00u;
    }

label_802E1190:
    ctx->pc = 0x802E1190u;
    // 802E1190: stw     r29, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802E1194:
    ctx->pc = 0x802E1194u;
    // 802E1194: lwz     r0, -25088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25088);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E1198:
    ctx->pc = 0x802E1198u;
    // 802E1198: cmpwi   r0, 0
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

label_802E119C:
    ctx->pc = 0x802E119Cu;
    // 802E119C: addi    r0, r3, 18048
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18048);

label_802E11A0:
    ctx->pc = 0x802E11A0u;
    // 802E11A0: add   r30, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_802E11A4:
    ctx->pc = 0x802E11A4u;
    // 802E11A4: bc    4, 2, 0x802E1278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E1278;
        }
    }

label_802E11A8:
    ctx->pc = 0x802E11A8u;
    ctx->downcount -= 2;
    // 802E11A8: rlwinm. r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802E11AC:
    ctx->pc = 0x802E11ACu;
    // 802E11AC: bc    4, 2, 0x802E11C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E11C0;
        }
    }

label_802E11B0:
    ctx->pc = 0x802E11B0u;
    ctx->downcount -= 4;
    // 802E11B0: rlwinm r3, r4, 0, 0, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF0000u;
    }

label_802E11B4:
    ctx->pc = 0x802E11B4u;
    // 802E11B4: addis   r0, r3, -4
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-4) << 16);

label_802E11B8:
    ctx->pc = 0x802E11B8u;
    // 802E11B8: cmplwi  r0, 0x0000
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

label_802E11BC:
    ctx->pc = 0x802E11BCu;
    // 802E11BC: bc    12, 2, 0x802E11CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E11CC;
        }
    }

label_802E11C0:
    ctx->pc = 0x802E11C0u;
    ctx->downcount -= 3;
    // 802E11C0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802E11C4:
    ctx->pc = 0x802E11C4u;
    // 802E11C4: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E11C8:
    ctx->pc = 0x802E11C8u;
    // 802E11C8: b       0x802E1204
    {
            goto label_802E1204;
    }

label_802E11CC:
    ctx->pc = 0x802E11CCu;
    ctx->downcount -= 10;
    // 802E11CC: lis     r3, -32722
    ctx->gpr[3] = ((u32)(s32)(-32722) << 16);

label_802E11D0:
    ctx->pc = 0x802E11D0u;
    // 802E11D0: lwz     r5, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802E11D4:
    ctx->pc = 0x802E11D4u;
    // 802E11D4: addi    r8, r3, 4084
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(4084);

label_802E11D8:
    ctx->pc = 0x802E11D8u;
    // 802E11D8: lwz     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802E11DC:
    ctx->pc = 0x802E11DCu;
    // 802E11DC: lwz     r9, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_802E11E0:
    ctx->pc = 0x802E11E0u;
    // 802E11E0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E11E4:
    ctx->pc = 0x802E11E4u;
    // 802E11E4: lwz     r10, 52(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_802E11E8:
    ctx->pc = 0x802E11E8u;
    // 802E11E8: addi    r4, r30, 0
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(0);

label_802E11EC:
    ctx->pc = 0x802E11ECu;
    // 802E11EC: addi    r6, r30, 5
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(5);

label_802E11F0:
    ctx->pc = 0x802E11F0u;
    // 802E11F0: bl      0x802DC208
    {
            ctx->lr = 0x802E11F4u;
            ctx->pc = 0x802DC208u;
            return;
    }

label_802E11F4:
    ctx->pc = 0x802E11F4u;
    ctx->downcount -= 2;
    // 802E11F4: cmpwi   r3, 0
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

label_802E11F8:
    ctx->pc = 0x802E11F8u;
    // 802E11F8: bc    4, 2, 0x802E1278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802E1278;
        }
    }

label_802E11FC:
    ctx->pc = 0x802E11FCu;
    ctx->downcount -= 2;
    // 802E11FC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_802E1200:
    ctx->pc = 0x802E1200u;
    // 802E1200: stw     r0, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E1204:
    ctx->pc = 0x802E1204u;
    ctx->downcount -= 3;
    // 802E1204: lwz     r12, 56(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802E1208:
    ctx->pc = 0x802E1208u;
    // 802E1208: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802E120C:
    ctx->pc = 0x802E120Cu;
    // 802E120C: bc    12, 2, 0x802E1224
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E1224;
        }
    }

label_802E1210:
    ctx->pc = 0x802E1210u;
    ctx->downcount -= 6;
    // 802E1210: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E1214:
    ctx->pc = 0x802E1214u;
    // 802E1214: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802E1218:
    ctx->pc = 0x802E1218u;
    // 802E1218: stw     r0, 56(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E121C:
    ctx->pc = 0x802E121Cu;
    // 802E121C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E1220:
    ctx->pc = 0x802E1220u;
    // 802E1220: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802E1224u;
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E1224:
    ctx->pc = 0x802E1224u;
    ctx->downcount -= 3;
    // 802E1224: lwz     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E1228:
    ctx->pc = 0x802E1228u;
    // 802E1228: cmplwi  r0, 0x0000
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

label_802E122C:
    ctx->pc = 0x802E122Cu;
    // 802E122C: bc    12, 2, 0x802E1278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802E1278;
        }
    }

label_802E1230:
    ctx->pc = 0x802E1230u;
    ctx->downcount -= 1;
    // 802E1230: bl      0x802BFF90
    {
            ctx->lr = 0x802E1234u;
            ctx->pc = 0x802BFF90u;
            return;
    }

label_802E1234:
    ctx->pc = 0x802E1234u;
    ctx->downcount -= 3;
    // 802E1234: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802E1238:
    ctx->pc = 0x802E1238u;
    // 802E1238: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802E123C:
    ctx->pc = 0x802E123Cu;
    // 802E123C: bl      0x802C013C
    {
            ctx->lr = 0x802E1240u;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802E1240:
    ctx->pc = 0x802E1240u;
    ctx->downcount -= 2;
    // 802E1240: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802E1244:
    ctx->pc = 0x802E1244u;
    // 802E1244: bl      0x802BFF34
    {
            ctx->lr = 0x802E1248u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802E1248:
    ctx->pc = 0x802E1248u;
    ctx->downcount -= 8;
    // 802E1248: lwz     r12, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802E124C:
    ctx->pc = 0x802E124Cu;
    // 802E124C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802E1250:
    ctx->pc = 0x802E1250u;
    // 802E1250: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_802E1254:
    ctx->pc = 0x802E1254u;
    // 802E1254: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E1258:
    ctx->pc = 0x802E1258u;
    // 802E1258: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802E125C:
    ctx->pc = 0x802E125Cu;
    // 802E125C: lwz     r4, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E1260:
    ctx->pc = 0x802E1260u;
    // 802E1260: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802E1264u;
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E1264:
    ctx->pc = 0x802E1264u;
    ctx->downcount -= 2;
    // 802E1264: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802E1268:
    ctx->pc = 0x802E1268u;
    // 802E1268: bl      0x802C013C
    {
            ctx->lr = 0x802E126Cu;
            ctx->pc = 0x802C013Cu;
            return;
    }

label_802E126C:
    ctx->pc = 0x802E126Cu;
    ctx->downcount -= 2;
    // 802E126C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_802E1270:
    ctx->pc = 0x802E1270u;
    // 802E1270: bl      0x802BFF34
    {
            ctx->lr = 0x802E1274u;
            ctx->pc = 0x802BFF34u;
            return;
    }

label_802E1274:
    ctx->pc = 0x802E1274u;
    ctx->downcount -= 1;
    // 802E1274: bl      0x802C7B20
    {
            ctx->lr = 0x802E1278u;
            ctx->pc = 0x802C7B20u;
            return;
    }

label_802E1278:
    ctx->pc = 0x802E1278u;
    ctx->downcount -= 8;
    // 802E1278: lwz     r0, 756(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(756);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E127C:
    ctx->pc = 0x802E127Cu;
    // 802E127C: lwz     r31, 748(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(748);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802E1280:
    ctx->pc = 0x802E1280u;
    // 802E1280: lwz     r30, 744(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(744);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802E1284:
    ctx->pc = 0x802E1284u;
    // 802E1284: lwz     r29, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802E1288:
    ctx->pc = 0x802E1288u;
    // 802E1288: addi    r1, r1, 752
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(752);

label_802E128C:
    ctx->pc = 0x802E128Cu;
    // 802E128C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E1290:
    ctx->pc = 0x802E1290u;
    // 802E1290: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E1294:
    ctx->pc = 0x802E1294u;
    ctx->downcount -= 23;
    // 802E1294: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802E1298:
    ctx->pc = 0x802E1298u;
    // 802E1298: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802E129C:
    ctx->pc = 0x802E129Cu;
    // 802E129C: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802E12A0:
    ctx->pc = 0x802E12A0u;
    // 802E12A0: stmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_802E12A4:
    ctx->pc = 0x802E12A4u;
    // 802E12A4: addi    r27, r3, 0
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(0);

label_802E12A8:
    ctx->pc = 0x802E12A8u;
    // 802E12A8: lis     r3, -32709
    ctx->gpr[3] = ((u32)(s32)(-32709) << 16);

label_802E12AC:
    ctx->pc = 0x802E12ACu;
    // 802E12AC: rlwinm r7, r27, 8, 0, 23
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[27], 8u) & 0xFFFFFF00u;
    }

label_802E12B0:
    ctx->pc = 0x802E12B0u;
    // 802E12B0: addi    r0, r3, 18048
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18048);

label_802E12B4:
    ctx->pc = 0x802E12B4u;
    // 802E12B4: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_802E12B8:
    ctx->pc = 0x802E12B8u;
    // 802E12B8: addi    r29, r5, 0
    ctx->gpr[29] = ctx->gpr[5] + (u32)(s32)(0);

label_802E12BC:
    ctx->pc = 0x802E12BCu;
    // 802E12BC: addi    r31, r6, 0
    ctx->gpr[31] = ctx->gpr[6] + (u32)(s32)(0);

label_802E12C0:
    ctx->pc = 0x802E12C0u;
    // 802E12C0: add   r30, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_802E12C4:
    ctx->pc = 0x802E12C4u;
    // 802E12C4: bl      0x802C30E8
    {
            ctx->lr = 0x802E12C8u;
            ctx->pc = 0x802C30E8u;
            return;
    }

label_802E12C8:
    ctx->pc = 0x802E12C8u;
    ctx->downcount -= 8;
    // 802E12C8: stw     r31, 56(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802E12CC:
    ctx->pc = 0x802E12CCu;
    // 802E12CC: lis     r4, -32722
    ctx->gpr[4] = ((u32)(s32)(-32722) << 16);

label_802E12D0:
    ctx->pc = 0x802E12D0u;
    // 802E12D0: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_802E12D4:
    ctx->pc = 0x802E12D4u;
    // 802E12D4: stw     r28, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_802E12D8:
    ctx->pc = 0x802E12D8u;
    // 802E12D8: addi    r4, r4, 4464
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4464);

label_802E12DC:
    ctx->pc = 0x802E12DCu;
    // 802E12DC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_802E12E0:
    ctx->pc = 0x802E12E0u;
    // 802E12E0: stw     r29, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802E12E4:
    ctx->pc = 0x802E12E4u;
    // 802E12E4: bl      0x802DC848
    {
            ctx->lr = 0x802E12E8u;
            ctx->pc = 0x802DC848u;
            return;
    }

label_802E12E8:
    ctx->pc = 0x802E12E8u;
    ctx->downcount -= 2;
    // 802E12E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802E12EC:
    ctx->pc = 0x802E12ECu;
    // 802E12EC: bl      0x802C3110
    {
            ctx->lr = 0x802E12F0u;
            ctx->pc = 0x802C3110u;
            return;
    }

label_802E12F0:
    ctx->pc = 0x802E12F0u;
    ctx->downcount -= 17;
    // 802E12F0: lmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_802E12F4:
    ctx->pc = 0x802E12F4u;
    // 802E12F4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802E12F8:
    ctx->pc = 0x802E12F8u;
    // 802E12F8: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802E12FC:
    ctx->pc = 0x802E12FCu;
    // 802E12FC: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_802E1300:
    ctx->pc = 0x802E1300u;
    // 802E1300: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802E1304:
    ctx->pc = 0x802E1304u;
    // 802E1304: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E1308:
    ctx->pc = 0x802E1308u;
    ctx->downcount -= 9;
    // 802E1308: lis     r4, -32709
    ctx->gpr[4] = ((u32)(s32)(-32709) << 16);

label_802E130C:
    ctx->pc = 0x802E130Cu;
    // 802E130C: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_802E1310:
    ctx->pc = 0x802E1310u;
    // 802E1310: addi    r0, r4, 18048
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(18048);

label_802E1314:
    ctx->pc = 0x802E1314u;
    // 802E1314: add   r7, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802E1318:
    ctx->pc = 0x802E1318u;
    // 802E1318: lwz     r3, 48(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(48);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802E131C:
    ctx->pc = 0x802E131Cu;
    // 802E131C: lwz     r4, 52(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(52);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802E1320:
    ctx->pc = 0x802E1320u;
    // 802E1320: stw     r6, 52(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802E1324:
    ctx->pc = 0x802E1324u;
    // 802E1324: stw     r5, 48(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802E1328:
    ctx->pc = 0x802E1328u;
    // 802E1328: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802DF4C0;
        }
    }

label_802E132C:
    ctx->pc = 0x802E132Cu;
    // 802E132C: .long   0x00000000
    // embedded data

label_802E1330:
    ctx->pc = 0x802E1330u;
    // 802E1330: .long   0x00000000
    // embedded data

label_802E1334:
    ctx->pc = 0x802E1334u;
    // 802E1334: .long   0x00000000
    // embedded data

label_802E1338:
    ctx->pc = 0x802E1338u;
    // 802E1338: .long   0x00000000
    // embedded data

label_802E133C:
    ctx->pc = 0x802E133Cu;
    // 802E133C: .long   0x00000000
    // embedded data

    ctx->pc = 0x802E1340u;
    return;
return_dispatch_802DF4C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x802DF4F4u: goto label_802DF4F4;
    case 0x802DF530u: goto label_802DF530;
    case 0x802DF55Cu: goto label_802DF55C;
    case 0x802DF56Cu: goto label_802DF56C;
    case 0x802DF5A8u: goto label_802DF5A8;
    case 0x802DF804u: goto label_802DF804;
    case 0x802DF830u: goto label_802DF830;
    case 0x802DF838u: goto label_802DF838;
    case 0x802DF86Cu: goto label_802DF86C;
    case 0x802DF880u: goto label_802DF880;
    case 0x802DF8ECu: goto label_802DF8EC;
    case 0x802DF920u: goto label_802DF920;
    case 0x802DF948u: goto label_802DF948;
    case 0x802DF9B0u: goto label_802DF9B0;
    case 0x802DF9E0u: goto label_802DF9E0;
    case 0x802DFA04u: goto label_802DFA04;
    case 0x802DFA64u: goto label_802DFA64;
    case 0x802DFAB4u: goto label_802DFAB4;
    case 0x802DFAD8u: goto label_802DFAD8;
    case 0x802DFB18u: goto label_802DFB18;
    case 0x802DFB54u: goto label_802DFB54;
    case 0x802DFB88u: goto label_802DFB88;
    case 0x802DFB9Cu: goto label_802DFB9C;
    case 0x802DFBE4u: goto label_802DFBE4;
    case 0x802DFBF0u: goto label_802DFBF0;
    case 0x802DFC04u: goto label_802DFC04;
    case 0x802DFC40u: goto label_802DFC40;
    case 0x802DFCA4u: goto label_802DFCA4;
    case 0x802DFCCCu: goto label_802DFCCC;
    case 0x802DFD18u: goto label_802DFD18;
    case 0x802DFD3Cu: goto label_802DFD3C;
    case 0x802DFDC0u: goto label_802DFDC0;
    case 0x802DFDC8u: goto label_802DFDC8;
    case 0x802DFDE4u: goto label_802DFDE4;
    case 0x802DFDECu: goto label_802DFDEC;
    case 0x802DFE20u: goto label_802DFE20;
    case 0x802DFE44u: goto label_802DFE44;
    case 0x802DFE58u: goto label_802DFE58;
    case 0x802DFEA4u: goto label_802DFEA4;
    case 0x802DFEE0u: goto label_802DFEE0;
    case 0x802DFF34u: goto label_802DFF34;
    case 0x802DFF5Cu: goto label_802DFF5C;
    case 0x802DFFE8u: goto label_802DFFE8;
    case 0x802E0024u: goto label_802E0024;
    case 0x802E00C4u: goto label_802E00C4;
    case 0x802E00F4u: goto label_802E00F4;
    case 0x802E0198u: goto label_802E0198;
    case 0x802E01C0u: goto label_802E01C0;
    case 0x802E0248u: goto label_802E0248;
    case 0x802E02D0u: goto label_802E02D0;
    case 0x802E02F8u: goto label_802E02F8;
    case 0x802E0660u: goto label_802E0660;
    case 0x802E06B4u: goto label_802E06B4;
    case 0x802E06C0u: goto label_802E06C0;
    case 0x802E0708u: goto label_802E0708;
    case 0x802E0718u: goto label_802E0718;
    case 0x802E0738u: goto label_802E0738;
    case 0x802E0758u: goto label_802E0758;
    case 0x802E0788u: goto label_802E0788;
    case 0x802E07A8u: goto label_802E07A8;
    case 0x802E0820u: goto label_802E0820;
    case 0x802E082Cu: goto label_802E082C;
    case 0x802E0848u: goto label_802E0848;
    case 0x802E0898u: goto label_802E0898;
    case 0x802E0958u: goto label_802E0958;
    case 0x802E0974u: goto label_802E0974;
    case 0x802E0978u: goto label_802E0978;
    case 0x802E098Cu: goto label_802E098C;
    case 0x802E09F4u: goto label_802E09F4;
    case 0x802E0A6Cu: goto label_802E0A6C;
    case 0x802E0A80u: goto label_802E0A80;
    case 0x802E0AE8u: goto label_802E0AE8;
    case 0x802E0B60u: goto label_802E0B60;
    case 0x802E0B74u: goto label_802E0B74;
    case 0x802E0BC4u: goto label_802E0BC4;
    case 0x802E0C0Cu: goto label_802E0C0C;
    case 0x802E0C48u: goto label_802E0C48;
    case 0x802E0CB0u: goto label_802E0CB0;
    case 0x802E0CF4u: goto label_802E0CF4;
    case 0x802E0D48u: goto label_802E0D48;
    case 0x802E0DC8u: goto label_802E0DC8;
    case 0x802E0E44u: goto label_802E0E44;
    case 0x802E0E58u: goto label_802E0E58;
    case 0x802E0EF8u: goto label_802E0EF8;
    case 0x802E0F1Cu: goto label_802E0F1C;
    case 0x802E0F94u: goto label_802E0F94;
    case 0x802E0FC0u: goto label_802E0FC0;
    case 0x802E0FD4u: goto label_802E0FD4;
    case 0x802E106Cu: goto label_802E106C;
    case 0x802E1080u: goto label_802E1080;
    case 0x802E1088u: goto label_802E1088;
    case 0x802E10A4u: goto label_802E10A4;
    case 0x802E10ACu: goto label_802E10AC;
    case 0x802E10B4u: goto label_802E10B4;
    case 0x802E10F4u: goto label_802E10F4;
    case 0x802E112Cu: goto label_802E112C;
    case 0x802E113Cu: goto label_802E113C;
    case 0x802E1154u: goto label_802E1154;
    case 0x802E11F4u: goto label_802E11F4;
    case 0x802E1224u: goto label_802E1224;
    case 0x802E1234u: goto label_802E1234;
    case 0x802E1240u: goto label_802E1240;
    case 0x802E1248u: goto label_802E1248;
    case 0x802E1264u: goto label_802E1264;
    case 0x802E126Cu: goto label_802E126C;
    case 0x802E1274u: goto label_802E1274;
    case 0x802E1278u: goto label_802E1278;
    case 0x802E12C8u: goto label_802E12C8;
    case 0x802E12E8u: goto label_802E12E8;
    case 0x802E12F0u: goto label_802E12F0;
    default: return;
    }
}

