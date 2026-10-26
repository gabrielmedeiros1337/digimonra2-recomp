# LINK_STATE.md — Digimon Rumble Arena 2 Recomp (Link Phase)
_Atualizado: 2026-10-26_

---

## Estado atual: ✅ BUILD LIMPO — SEM ERROS

O projeto compila e linka completamente sem `undefined reference` nem
`multiple definition`. O EXE gerado (`build_test/Release/digimon_test.exe`)
já está rodando e alcança a Title Screen (estado 11 do Scene Manager,
2800+ draw calls, 13 MB de FIFO processados).

---

## Comandos de Build

```powershell
# Build incremental (rápido):
& "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build ".\build_test" --config Release

# Build limpo (confirma estado real, ~90s):
& "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build ".\build_test" --config Release --clean-first 2>&1 | Tee-Object build_full.log

# Gerar inventário de símbolos:
python tools/symbol_inventory.py
```

---

## Estrutura de Pastas

```
RECOMPILAÇÃO FINAL/
├── CMakeLists.txt                # Build principal (MSVC, Release)
├── CMakeLists_test.txt           # Variante sem SDL2 (desatualizada)
├── ModernGekko-Template/
│   └── lib/DolRecomp/src/
│       ├── cpu/cpu.c + cpu.h     # Runtime PPC: CPUState, mem_read/write, ppc_*
│       └── common/types.h        # u8/u16/u32/u64/s8/.../f32/f64
├── recompiled_code/generated/
│   ├── generated.h               # Header comum + helpers inline (rotl, f32↔bits, etc.)
│   ├── generated.c               # Arquivo-índice (só inclui generated.h; lista os chunks)
│   └── chunks/                   # 185 arquivos chunk_NNNN_textN_8XXXXXXX.c
├── src_test/                     # Camada HLE / plataforma
│   ├── test_main.c               # Loop principal + hooks de PC + dispatch de SDK
│   ├── video_audio.c             # VI/AI MMIO, XFB YUY2→SDL2, PE interrupts
│   ├── gx_pipe.c                 # GX FIFO parser, Display Lists, SDL2 Renderer
│   ├── input.c                   # PAD/keyboard/gamepad via SDL2
│   ├── dol_loader.c              # DOL loader (seções text/data → RAM guest)
│   └── dvd_vfs.c                 # ISO/CISO VFS (DVDReadAsyncPrio HLE)
├── third_party/SDL2/             # SDL2 headers + SDL2.lib + SDL2main.lib + SDL2.dll
├── tools/symbol_inventory.py    # Inventário de símbolos (dumpbin + análise)
└── build_test/                   # Diretório de build CMake (não commitar)
    └── Release/digimon_test.exe  # Binário gerado
```

---

## Padrão de Nomes do Código Gerado

| Padrão                       | Significado                                |
|------------------------------|--------------------------------------------|
| `func_80XXXXXX(CPUState*)`   | Função guest de entrada de chunk           |
| `loop_80XXXXXX(CPUState*)`   | Loop interno (static dentro do chunk)      |
| `lbl_80XXXXXX`               | Label de jump (goto interno ao chunk)      |
| `dolrecomp_call_depth`       | Profundidade de chamada cross-chunk        |
| `dolrecomp_rotl32`, `f32_from_bits`, etc. | Helpers inline no generated.h |

---

## Tipo da CPU e Assinatura das Funções

```c
// Em cpu/cpu.h:
typedef struct CPUState CPUState;
struct CPUState {
    u32 gpr[32];   // r0..r31
    f64 fpr[32];   // f0..f31
    f64 ps1[32];   // paired-singles slot 1
    u32 pc, lr, ctr, cr, xer, fpscr, msr;
    u32 srr0, srr1, dar, dsisr, ear, hid2;
    u64 timebase;
    u32 sr[16], gqr[8];
    u32 exception;
    u8* ram;
    u32 ram_size;
    s64 downcount, cycle_budget;
    // callbacks: external_read, external_write, instruction_fallback, host_call ...
};

// Assinatura de todas as funções geradas:
void func_80XXXXXX(CPUState* ctx);
```

---

## Acesso à Memória Guest

```c
// Todos os endereços guest são u32 big-endian.
// Conversão via helpers do runtime (cpu.h):
u32  mem_read32(CPUState* cpu, u32 addr);
void mem_write32(CPUState* cpu, u32 addr, u32 value);
u64  mem_read64(CPUState* cpu, u32 addr);
void mem_write64(CPUState* cpu, u32 addr, u64 value);
u16  mem_read16(CPUState* cpu, u32 addr);
u8   mem_read8(CPUState* cpu, u32 addr);
// mem_write16, mem_write8 também existem

// Acesso direto a RAM (para blocos):
cpu->ram + (guest_addr - GC_RAM_BASE)  // apenas quando validado
```

---

## Substituição de SDK (HLE)

O SDK não está linkado como biblioteca. Em vez disso:

- **Interceptação por PC**: `test_main.c` compara `cpu.pc` com endereços fixos
  e substitui a lógica da função antes de chamar `dolrecomp_run_blocks`.
- **Exemplos implementados**: `DVDReadAsyncPrio` (`0x802B92B0`), `VIWaitForRetrace`,
  `GXCopyDisp`, Scene Manager hooks (`0x801AC614`, `0x801AD0CC`, `0x801BE824`),
  Fader Check (`0x8009B3C4`), OSReport (`0x802C06BC`).
- **Tabela de dispatch**: `dolrecomp_run_blocks(cpu, 1)` executa um bloco de código
  recompilado; o dispatch de funções acontece pela tabela em `generated.h` + hook de PC.

---

## Inventário de Símbolos — Estado Inicial (2026-10-26)

| Métrica                              | Valor |
|--------------------------------------|-------|
| Arquivos .obj analisados             | 193   |
| Símbolos definidos únicos            | 358   |
| **Indefinidos (pre-link, .obj)**     | **84** |
| **Multidefinidos (pre-link)**        | **9** |
| **Erros de link reais (no EXE)**     | **0** |

> ⚠️ Os 84 "indefinidos" e 9 "multidefinidos" são **artefatos de análise pre-link**
> via `dumpbin /SYMBOLS`. O linker MSVC resolve todos antes de gerar o EXE.
> Verificado via `dumpbin /IMPORTS digimon_test.exe`: todos os imports estão
> satisfeitos (SDL2.dll, CRT via api-ms-win-crt-*.dll, KERNEL32.dll).

### Categorias pre-link "indefinidos" (resolvidos pelo linker):
- **HOST_SDL2 (48)**: Todas as funções SDL2 — resolvidas por `SDL2.lib`
- **UNKNOWN/CRT (36)**: `printf`, `memcpy`, `fopen`, `ceil`, `fma`, etc. —
  resolvidas pelo CRT MSVC (`api-ms-win-crt-*.dll`)
- **Especiais MSVC**: `GSHandlerCheck`, `security_cookie`, `chkstk`, `ImageBase` —
  fornecidas pelo runtime MSVC internamente

### Categorias pre-link "multidefinidos" (resolvidos pelo linker):
- `printf`, `fprintf`, `vfprintf_l`, `local_stdio_printf_options`: definições
  inline do CRT em múltiplos .obj — normal no MSVC com `/MT` ou inclusão de headers
- `real@0000000000000000`, `xmm@*`: constantes literais duplicadas — linkadas com COMDAT

---

## Decisões Tomadas (histórico)

1. **Tela verde YUY2**: corrigida em `video_audio.c` → buffer zero → skip blit; croma 0x00 → 0x80
2. **Troca de contexto de thread**: `save_thread_context`/`restore_thread_context` em `test_main.c`
   restauram todos os 32 GPR, 32 FPR, CR, LR, CTR, XER, GQR[8], PC, MSR com `|0x8000`
3. **GX FIFO opcodes 0x20/0x28/0x30/0x38 (LoadIndx) e 0x40 (CallDL) e 0x48**: implementados
   em `gx_pipe.c`; `gx_pipe_process_internal` separado de `gx_pipe_process_frame`
4. **DSP mail loop `0x802BEFFC`**: contornado com skip `cpu.pc = 0x802BF114u`
5. **DVDReadAsyncPrio**: HLE em `test_main.c` faz leitura real do ISO via `dvd_vfs_read_bytes`
   e invoca `user_cb` diretamente

---

## Estado do Jogo em Execução

- ✅ Boot → Pre-Init → "Press Button to Continue" → "Save Your Progress" (sem auto-click)
- ✅ Confirmação via Enter/Z → Loading... → Title Screen (state 11)
- ✅ 2800+ draw calls, 13+ MB de FIFO, texturas CI8+TLUT decodificadas
- ⏳ Renderização do Title Screen: GX→SDL2 ok, XFB (YUY2) parcialmente preenchido
- ⏳ "Press Start" → gameplay: não testado

---

## PRÓXIMO PROMPT (para retomar):

> Você está em `C:\Users\gabri\OneDrive\Área de Trabalho\RECOMPILAÇÃO FINAL`.
> Build: CMake --build build_test --config Release (já funciona, zero erros de link).
> Contexto em LINK_STATE.md. O jogo chega ao Title Screen (state=11, 2800+ draws).
> Próxima tarefa: investigar por que o XFB YUY2 (0x804F26A0) não está sendo preenchido
> com os pixels do Title Screen (frame_capture_260.bmp mostra só "Loading..." text),
> e fazer o Title Screen renderizar visualmente com texturas corretas.
