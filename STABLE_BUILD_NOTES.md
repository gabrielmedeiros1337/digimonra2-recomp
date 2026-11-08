# Manual de ouro — v1.0-stable-60fps

Congelamento local: **8 de novembro de 2026**. O usuário confirmou combate
praticamente estável em **60 FPS**, com mínimas pontuais de **58 FPS** nas
transições mais pesadas de digivolução. Esse é o resultado observado nesta
máquina e nesta versão; não é uma garantia para qualquer hardware/carga.

Executável validado: `build_test/Release/digimon_test.exe`.
SHA256: `ECEA9F470B2AFFE7B207C80899CDEBC74DA7040F8B19A87757148C9A5B2C9959`.
Mapa correspondente: SHA256
`5B582F1A9737EDFCE6B0DA0A53FAFBB8DF4F56DB780F01A9ACEB6AC0F51226FF`.
Catálogo versionado: `stable_releases/v1.0-stable-60fps.json`.
Backup: `build_test/stable_release/v1.0-stable-60fps/`.

## Regras de preservação

Esta tag é a referência imutável. Não mover, substituir ou reutilizar a tag para
outro executável. Não reconstruir sobre o diretório do backup. Experimentos
devem ocorrer em outra branch e outro diretório de build. Uma mudança só pode
ser promovida depois de equivalência, contratos, inspeção da pilha e comparação
de desempenho com carga equivalente; melhorar um contador não prova ganho de FPS.

### 1. Executor plano e iterativo

O executor consome os destinos de `ctx->pc` num laço com downcount positivo,
preservando hooks, exceções, callbacks, relógios e os safepoints de dispositivos.
**Não reintroduzir chamadas C recursivas entre os chunks públicos.**
`cpu_direct.h`, `CHUNK_DIRECT` e as 39.046 arestas C experimentais foram retirados.
Não depender da suposição de que o MSVC sempre transforma `call; return` em `jmp`.

O lookup principal já é O(1): array compacto, índice
`(pc - 0x800034C0) >> 14` para text1, com validação de intervalo/alinhamento e
tratamento preservado de text0/aliases. Não substituir essa base pelo endereço
0x80000000 sem corrigir as fronteiras, pois os chunks começam desalinhados.

### 2. Frames pequenos e zero probing nos chunks

`tools/pc_dead_stores.py` e `tools/chunk_segments.py` trabalham exclusivamente
em **cópias de build**, mantendo intocados os 185 fontes originais gerados.
Os corpos grandes são distribuídos em 23.677 regiões privadas pequenas,
percorridas por wrappers planos. A continuidade entre regiões usa estado local;
`ctx->pc` não serve como scratch para o roteamento interno.

Cada região cobre no máximo 128 bytes de código guest, ou 32 instruções.
Os helpers rápidos continuam inline. Não reintegrar esses corpos numa função
monolítica: a combinação de milhares de labels, switches e expansões inline
materializava milhares de temporários na pilha, mesmo com `/O2`.

Medições no PE x64 ligado:

| Invariante | Valor estável |
|---|---:|
| Chunks públicos | 185 |
| Maior frame dos wrappers | 72 bytes |
| Maior frame incluindo regiões/loops de produção | 168 bytes |
| Prólogos desse conjunto com `__chkstk` | 0 |
| Seção `.text` | 47,883034 MiB |

O limite obrigatório é **menos de 4 KiB por função de produção dos chunks**.
O post-build executa `tools/inspect_chunk_stacks.py --max-frame 4095` e falha
em violação. Não desativar `/Gs`, mascarar o verificador ou apenas aumentar a
pilha para esconder uma regressão. Salvamentos exigidos pela ABI x64 continuam
válidos. Os frames pequenos cabem confortavelmente no L1d; residência efetiva
no cache depende também dos dados do jogo e da CPU, não é uma garantia absoluta.

### 3. FIFO e backend em paralelo

Escritas no gather pipe `0xCC008000..0xCC00801F` e alias físico
`0x0C008000..0x0C00801F` **não ativam o fence genérico de MMIO**. Interrupções
reais de CP/PE e os safepoints continuam sendo respeitados. Não fazer flush,
readback, espera de GPU ou bombeamento pesado do host em cada store do FIFO.

A **thread principal** possui SDL, eventos e OpenGL; uma **worker persistente**
executa a CPU guest. `gx_frame.c` mantém **três arenas** e snapshots imutáveis
dos comandos/recursos. Decode e submit do backend se sobrepõem à CPU. Preservar
ordenação, limites de fila e propriedade das arenas; três arenas não autorizam
uma fila ilimitada de quadros nem acesso concorrente à RAM mutável sem snapshot.

Manter XFB e cópias I4 64x64 elegíveis em VRAM, caches de textura/geometry e os
casos de sincronização realmente necessários. Não reativar os experimentos
`gx_decode_async`, `immutable_images` ou dirty tracking por store para supostos
ganhos sem A/B controlado. A configuração congelada está no backup.

### 4. Quantum, tempo guest e apresentação

**Quantum 1024; downcount inicial 768; limiar de saída -256.** Não mudar para
4096 como atalho de desempenho. O orçamento de combate permite 300.000 posições
por job, mantendo 675.000 ticks TB nominais por VI. Um watchdog continua o mesmo
quadro, sem VBlank extra, apresentação artificial ou outra espera de 16,67 ms.

Idle real avança até o próximo evento relevante ou prazo VI, entregando áudio,
interrupções e callbacks. Não simplesmente saltar `VIWaitForRetrace` na entrada
nem descartar o trabalho posterior a `GXCopyDisp`. O pacer está na política
recuperada, sem catch-up acumulado; VSync está explicitamente desligado para
evitar duplo limitador.

## Receita e validação preservadas

Toolchain deste binário: MSVC **19.51.36260.0**, CMake/gerador
**Visual Studio 18 2026**, x64, C11, Release. `/O2`, helpers compactos, IPO/LTCG
ligado; **PGO OFF**. `DIGIMON_PC_DSE=ON` e `DIGIMON_ENABLE_IPO=ON`.
Não reutilizar perfis PGO antigos de outra forma de código.

Para reconstruir em diretório separado, com os mesmos fontes e dependências:

```powershell
cmake -S . -B build_test/rebuild_stable -G "Visual Studio 18 2026" -A x64 -DDIGIMON_PC_DSE=ON -DDIGIMON_ENABLE_IPO=ON -DDIGIMON_PGO_MODE=OFF
cmake --build build_test/rebuild_stable --config Release --parallel 4
ctest --test-dir build_test/rebuild_stable -C Release --output-on-failure
```

Uma reconstrução pode gerar outro hash por caminho, versão ou metadados do
toolchain. **O binário catalogado é a referência exata**; comparar comportamento,
frames e timings antes de adotar outro. Preserve os arquivos de configuração
congelados ao executar e use somente input físico, sem auto-press.

Validação da versão: build saída 0 sem warnings, **19/19 testes**; 12.288
comparações adicionais de controle/CPU/RAM, além dos testes reais de CPU,
locked cache, FPU e memória. Replay de 17 lotes idêntico, SHA256
`2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.
Relatórios anteriores são históricos; a confirmação manual de 60/58 FPS acima
é posterior à coleta que inicialmente aguardava os prompts.

## Conteúdo do congelamento e recuperação

O backup inclui EXE, mapa, SDL2, configurações, bibliotecas x64 de link, evidências,
inventário SHA256, fontes de trabalho arquivados e arquivos Git (bundles e mirrors
bare que preservam os clones rasos existentes). O manifesto local registra o
commit exato da tag e os commits dos submódulos. Os arquivos Git preservam
os commits locais dos submódulos, que não dependem de terem sido publicados nos
remotos upstream. O arquivo de fontes conserva os bytes de trabalho, inclusive
terminadores de linha; Git registra também sua forma canônica.

O snapshot preserva o estado encontrado dos vendors opcionais, inclusive
checkouts parciais/arquivos de testes já ausentes. Eles não são correções novas
do jogo. O runtime DolRecomp modificado e o xxHash efetivamente usado estão
incluídos. Dumps, imagens de disco e assets extraídos permanecem externos.

Para inspecionar a referência no repositório atual:

```powershell
git show --no-patch v1.0-stable-60fps
git rev-parse "v1.0-stable-60fps^{commit}"
```

O backup contém instruções de recuperação e hashes próprios. Nunca fazer
`reset --hard` sobre trabalho novo para voltar à referência; usar outro checkout.
