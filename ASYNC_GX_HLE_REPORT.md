# HLE, helpers compactos e decode GX assincrono - 2026-11-07

Release `DAECE957DB16E34B848EAB58A8F1487CB3B92DF88A308AD0C849CB1CA438B184`, mapa `build_test/async_active.map`, manifesto `build_test/async_manifest.json`. Build0 sem warnings, PGO USE, CTest12/12;214 objetos/GL e11.653 nomes no mapa. Nenhuma edicao em generated/. Input exclusivamente fisico.

## Nucleos nativos aplicados

- `native_copy.c`/`native_copy_adapter.h`: loops de copia de matrizes dentro de8023DA04,8024B030,8024D1EC. O ultimo store interceptado completa as iteracoes restantes com SSE2/memcpy, sem byte-swap duplo. Preserva ponteiros,GPR0,XER/CR,stores e budget/backedge. Nao substitui chamadas/efeitos restantes dessas funcoes nem declara suas wrappers inteiramente HLE. Copias sobrepostas,callbacks/journal/reserva/cache-control/orcamentos inadequados usam original.
- `sdk_floor.c`: HLE da rotina8029D888 para dominio comum j<20 e valores ja inteiros j>51, com retorno/stack/GPR/FPR/CR/FPSCR/downcount completos. Expoentes20..51,NaN/Inf e controles especiais permanecem referencia. Entrada real intrachunk D88C e entrada externa cobertas.
- `sdk_vec.c`: HLE completo de8028BEDC/8028BF58, transformacao vetorial4x4 com tres lanes SIMD/FMA, mesma ordem de arredondamento. Preserva todos os volateis observaveis,FPR/PS1,ordem de stores Z/X/Y e aliases. Fast-float/hostFMA exigidos; entradas especiais usam original. Alcanca tambem primeira instrucao dentro do chunk.
- HLEs anteriores de skinning/blend/reflexao/AABB mantidos. Nao se converteu cegamente um dispatcher de callbacks que tem6.5ms inclusivos e0.128ms proprios: os descendentes continuam necessarios.

Validacao contra corpos originais independentes:5.632 comparacoes CPU/RAM de floor,320 de copia,3.072 de vetores. Mais11.776 comparacoes CPU de helpers escalares/FMA/PSQ e2.359.296 pares de conversao de bits, incluindoNaNs/subnormais/signedzero/rounding/FTZ/DAZ e flags host.

## Helpers inline

`hot_float_adapter.h` e force-included em todos os chunks, sem depender do antigo diagnostico fbits. Caminhos compactos __forceinline para conversoesf32/f64, arithmetic scalar/FMA no fast_float e PSQ float normal em RAM. Excepcionais e referencia rigorosa ficam fora de linha em hot_float.c/runtime, sem clonar toda a implementacao FPSCR em cada instrucao. Fast-float segue efetivo na scene4, ligado por padrao no cfg. Nao se usam /fp:fast nem remocao de fcmp. Os1.25ms anteriores nao sao tratados como ganho automatico: parte do custo agora entra no RIP do chunk e outras operacoes PSQ/estimativas/comparacoes continuam necessarias.

Codigo nativo passou de170.43MiB para183.83MiB; esta revisao precisa de medicao real de instruction-cache/desempenho. Nao ha promessa de eliminacao integral dos1.25ms.

## Pipeline assincrono na rota real

A luta usa predominantemente FIFO nao vinculado: CPU escreve pelo gather em RAM e o CP drena a fila selecionada. O novo ponto de enqueue esta no parser comum de draws raw GPU, independente do bit de vinculacao. Portanto nao depende do atalho vinculado do patch anterior.

1. Main thread identifica pacote completo e captura CP/material/XF do draw.
2. Cache pre-decode continua ativo: hits reutilizam os vertices e o hash validado. Misses com>=16vertices capturam bytes do pacote e spans de atributos RAM referenciados, com layout/indices/strides/defaults de matriz.
3. Worker recebe somente snapshots imutaveis e output raw em span exclusivo. Nao recebeCPUState,ponteiros guest mutaveis,renderer ou contextoGL. Nao chamaSDL/OpenGL graficos. Fenv/MXCSR do submit sao restaurados no worker.
4. Main continua codigo guest enquanto worker decodifica/prepara/hash os atributos. No flush EFB/DrawDone/token/copia ou reuso da fila aguarda apenas jobs pendentes; publica cache/hash na main e so entao envia drawsGL/dispara eventosPE.
5. Backpressure limitado a128jobs/16MiB pendentes; malloc/queue/domain failures fazem fallback sincrono. Encerramento e desligamento do modo drenam a fila antes de liberar snapshots/output.

Parser e estadoGX, lookup de cache, cache hits, snapshot, comandos com dependencia e OpenGL continuam na main. Nao se alega mover todos os3.35ms ao worker: essa medida anterior incluia mais que decode de misses. Novo telemetry separa async_worker_ms (tempo de worker, nao somar ao wall main),async_wait_ms easync_snapshot_ms. Tempo de espera continua registrado no GX exclusivo.

Teste isolado reutiliza RAM/FIFO/CP ANTES de agendar worker. Teste integrado compara snapshots com decoder legado em tamanhos1024/4096/8192,FIFO wrap e reutilizacao de arrays; contratos completos425.984vertices preservados. Software/OpenGL passaram, incluindo EFB,YUY2,PE/IRQ/token,DL aninhadas e consumo imediato de arrays transitorios.

## Configuracao e medicao

`build_test/runtime_tuning.cfg`: campos18 fast_float=1,19 dirty_tracking=1,20 async_decode=1. O modo async tambem e true no codigo se o campo20 nao existir. Campo20=0 drena/desliga somente async para A/B na mesma luta. Tracking permanece4KB/GetWriteWatch uma vez por hostframe; nao se reintroduziu64B ou shadow.

Log `[Native top]` mostrafloor,matrix_copy_bytes,vector_transforms; `[GX async60]` mostrajobs/vertices/worker/wait/snapshot. Build/testes encerrados antes de abrir o novo executavel. Medicao de combate960quadros desta revisao depende da confirmacao fisica; nao se declara60FPS nem ganho de3-4ms com base apenas nos testes.


### Correcao de reutilizacao intradraw do worker - 2026-11-07

Release `221D241B852DE1A8B5FA465F04A3EC510E5F3477B2570A035849816127328DDC`; mapa async_reuse_active.map; manifesto async_reuse_manifest.json. Build0 sem warnings, CTest12/12,214objetosGL/11659nomes. Primeira captura confirmou jobs/HLE ativos mas quase todo1.02ms de worker virava espera0.96ms. Cargas on/off variaram; coletor relia42MB/log a cada250ms e foi corrigido para seek/tail. Nao se alega ganho de FPS com essas janelas.

Worker agora preserva tambem cache intradraw de vertices indexados:64vertices/4combinacoes deram4misses/60hits e output identico, incluindo reutilizacao de RAM/CP/FIFO antes de agendar. Novos contadores de reuse/drains/peak. Async=1 mantido no codigo/cfg; nova comparacao idle pendente. Detalhes/medidas/ressalvas em ASYNC_COMBAT_FIRST_RESULTS.md.


### Recursos imutaveis e barreiraTLUT - 2026-11-07

Release `408A7829D11811A4EF9D187C02934483D30E31EED64293F9EB4D2E7A52AC0002`; mapa images_active.map; manifesto images_manifest.json. Build0 sem warnings, PGO USE, CTest13/13,215objetosGL/11712nomes. Pilhas confirmaram flushBP65 como11de17esperas observadas. Novo gx_images.c preserva fontes e paletas por versao; BP65 pode adiar flush com dados imutaveis. ChaveGPU64bit por identidade evita reupload/hash repetido. EFB/PE/I4VRAM continuam ordenados, sem readback novo.

Testes incluem reutilizacao simultanea de pixels e paleta antes deCopyDisp e lookup sem syscalls. Replay17batches identico antes/depois, formatoQueuedDraw preservado. Cfg20async=1,21immutable_images=1; novos contadores deTLUT/copies/fallback. Desempenho novo ainda nao medido; limites/evidencias em TLUT_PIPELINE_REPORT.md.
