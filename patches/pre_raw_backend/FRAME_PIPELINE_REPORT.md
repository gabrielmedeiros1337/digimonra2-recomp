# Recuperacao e pipeline CPU/backend por quadro

## Base restaurada

O usuario confirmou que os modelos voltaram a aparecer em idle e andando com o executavel recuperado `7C6BD836...`. Os fontes da rodada de densidade/XF/DMA foram arquivados em `patches/reverted_density_xf/`.

Foram retirados da compilacao `cpu_xf_adapter.h`, `sdk_transfers.c/.h` e os testes correspondentes. Os chunks voltaram a `/O2` e LTCG; PGO esta OFF. Nao ha `/O1`, `/Os` ou `/fp:fast` introduzidos pela rodada revertida. O produtor XF/FIFO escalar foi restaurado. Nao foram adicionados novos HLEs de funcoes internas dos modelos.

O rebuild anterior a introducao do pipeline produziu a mesma secao `.text` da base recuperada: 150,817070 MiB, SHA256 `14BD6C9453F3F7FC727F82F6B813EB78FC243BE793EAB81D24CB5AF9BA039F1B`. Isso verifica a reversao do codigo de maquina, alem da confirmacao visual do usuario.

## Arquitetura implementada

O SDL2 distribuido no projeto exige que o renderer seja usado na thread principal (`SDL_render.h`). Por isso, o contexto OpenGL permanece nessa thread e a execucao da CPU guest passa para um worker persistente durante o combate (scene=4).

`gx_frame.c` possui duas arenas de comandos, reutilizadas e limitadas a 64 MiB cada. O produtor publica pacotes imutaveis em ordem; a thread principal consome os pacotes enquanto o worker continua a executar a CPU. A fila aplica contrapressao quando os dois buffers estao ocupados. Nao cria workers por draw.

O estado produtor CP/BP/XF, FIFO e caches de decode permanece na thread de CPU. O backend recebe copias dos vertices decodificados, materiais, transformacoes e apenas dos intervalos de texturas/paletas usados. Sua RAM sombra e privada. Isso evita ler RAM que a CPU ja reutilizou para outro modelo ou pose. A copia inicial da RAM ocorre ao ativar a rota; nao ocorre uma copia completa por draw.

As copias EFB delimitam lotes que podem ser consumidos antes do fim da logica do quadro. I4 64x64 e XFB ja inicializados permanecem em VRAM e podem ser enfileirados sem espera. Novas alocacoes, materializacao/alias de textura, readbacks reais e eventos PE/DrawDone mantem barreiras. A CPU nunca recebe conclusao antecipada de uma copia que precisa escrever na RAM guest.

Na apresentacao, o endereco e a geometria VI/XFB tambem sao capturados. Eventos SDL e leitura dos dispositivos continuam na thread principal. Cada job da CPU recebe os quatro PADs fisicos do inicio do quadro; nao ha input automatico.

O corpo do antigo loop guest foi extraido sem alterar suas decisoes, orcamentos ou hooks. A auditoria normalizada esta em `build_test/cpu_frame_extraction_audit.txt`. Somente o pumping SDL foi transferido para a thread principal. O worker inicializa seu ambiente host de arredondamento/denormais a partir do FPSCR guest.

## FPU e PC

`ppc_fp_available_inline` ja e `__forceinline` e retorna imediatamente quando `MSR_FP` esta ligado; nao chama o helper externo nesse caso. O jogo realmente desliga esse bit ao trocar a propriedade da FPU (`restore_thread_context`). Transformar toda guarda em no-op suprimiria a restauracao lazy da FPU, que ja causou corrupcao de modelos anteriormente. Os testes de ownership/FPU continuam aprovados.

As atribuicoes `ctx->pc = ...` sao instrucoes C literais nos arquivos gerados, nao uma macro substituivel no header. Elas nao foram removidas: chamadas, excecoes e retornos ao dispatcher precisam observar o PC correto. Elimina-las com seguranca exige analise de efeitos e pontos de saida no gerador. Nenhum arquivo de `recompiled_code/generated/` foi modificado. Nao se alega ganho por remover guardas ou PC nesta revisao.

## Arquivos principais

| Arquivo | Alteracao |
|---|---|
| `src_test/gx_frame.c/.h` | Fila ordenada de duas arenas, barreiras, ownership e estatisticas publicadas sob mutex. |
| `src_test/cpu_frame.c/.h` | Worker unico da CPU, handoff de jobs e encerramento ordenado. |
| `src_test/gx_frame_backend.inc` | Pacotes de draws/copies/presentacao com recursos imutaveis; backend GL exclusivo da main. |
| `src_test/gx_pipe.c/.h` | Render view independente da fila mutavel; encaminhamento das copias/PE; diagnosticos por snapshot. |
| `src_test/test_main.c` | Extracao do loop CPU, consumo GL durante o job, ativacao apenas no combate. |
| `src_test/input.c/.h` | Snapshot fisico dos quatro PADs por job via TLS. |
| `src_test/video_audio.c/.h` | Apresentacao a partir de metadata VI/XFB capturada. |
| `src_test/frame_timing.c/.h` | Timeline exclusiva da CPU com ownership transferido; backend paralelo medido separadamente. |
| `src_test/frame_pipeline_tests.c` | Ordem, imutabilidade, ownership, contrapressao, barreiras e ausencia de dupla contagem. |
| `src_test/platform_tests.c` | Copias reais I4/XFB, reutilizacao assincrona e materializacao posterior. |
| `tools/capture_frame60.py` | Inclusao dos tempos separados do backend nas capturas. |

## Validacao e limites

Release `9D9CA34BA623A396AB2F0A4431A4307664C26E8FDA7D42BB065AD1800096B2AD`; mapa `build_test/frame_pipeline_active.map`; manifesto `build_test/frame_pipeline_manifest.json`. Build CMake/MSVC completo: exit 0, sem warnings. CTest: 14/14. Self-test OpenGL: exit 0. Teste de fila: 3.720 pacotes e 549 barreiras aprovados. Inventario: 214 objetos LTCG, 11.612 nomes no mapa final; objetos LTCG nao expoem a tabela COFF ao dumpbin.

Replay dos 17 lotes reais de combate: imagem identica, SHA256 `2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`. Testes GL verificaram as imagens vermelha/azul em XFBs ordenados, nenhuma escrita guest no fast path I4/XFB e conversao correta ao exigir materializacao.

A secao `.text` nova tem 150,831612 MiB. O objetivo desta rodada e sobrepor execucao, sem refazer a tentativa regressiva de densidade de codigo.

O decode de atributos permanece na CPU; esta implementacao nao elimina automaticamente os 5,5 ms inteiros citados no pedido. Copias de recursos e barreiras tambem custam tempo. Portanto, `max(CPU,GX)` e um limite ideal, nao uma garantia de 60 FPS.

`[Render pipeline60]` informa `backend_draw_ms`, `backend_copy_ms`, `backend_swap_ms`, `backend_work_ms` e `producer_wait_ms`. Esses tempos sao paralelos: nao devem ser somados a `[Frame60]` como se fossem etapas em serie. A espera continua incluida no tempo de parede da CPU. Os zeros das categorias GL na timeline CPU nao significam que o trabalho GL desapareceu.

O 22o campo de `build_test/runtime_tuning.cfg` habilita o pipeline (1). `async_decode=0`, `immutable_images=0`, dirty tracking=0 e caches pre-decode/VBO + XFB/I4 em VRAM permanecem na base restaurada. Alterar uma configuracao drena a fila antes de trocar estados. O binario foi aberto para teste fisico; o FPS desta arquitetura ainda depende da captura do combate com quatro jogadores.
