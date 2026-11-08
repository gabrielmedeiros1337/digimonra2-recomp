# Revis�o VRAM-only e streaming din�mico � 2026-11-07

Esta se��o substitui, para o caminho I4 descrito abaixo, a pol�tica de readback e o padr�o de cache de geometria da auditoria hist�rica ao final. Valida��o final e medi��o da luta ser�o registradas em LINK_STATE.md.

- `gx_pipe.c:copy_efb_texture`: I4 64�64, sem redu��o, stride 256 bytes, fora de captura, copia/quantiza diretamente na textura GPU. Publica a chave guest no cache sem `SDL_RenderReadPixels`, codifica��o tiled ou escrita na RAM. As demais c�pias mant�m a refer�ncia anterior. A otimiza��o usa a premissa explicitamente fornecida pelo usu�rio de que estas imagens s�o consumidas como texturas, n�o pela CPU.
- O slot VRAM fica protegido de expuls�o; at� 64 imagens pendentes. Desligar o modo ou iniciar captura materializa a RAM. Uma visualiza��o incompat�vel/sobreposta tamb�m resolve a c�pia; altera��es de conte�do guest invalidam a imagem GPU. Isso n�o implementa intercepta��o geral de toda leitura CPU da RAM.
- `gx_gl.c:gx_gl_draw_internal`: cache integral de geometria desligado por padr�o. Os draws raw seguem diretamente ao ring de 16 MiB, sem hash/memcmp do buffer completo. O cache antigo permanece apenas como op��o diagn�stica. O cache de �ndices dentro de um �nico pacote GX permanece: ele evita decodificar �ndices repetidos e n�o reutiliza poses entre frames.
- `gx_pipe.c:merge_raw_draws`: agrupa somente listas independentes consecutivas, cont�guas, com primitiva, material TEV e snapshot XF id�nticos. Strips/fans e estados diferentes n�o s�o agrupados. A ordem original � preservada.
- `decode_vertex`: a rota raw GPU n�o limpa nem copia a estrutura de proje��o CPU de 168 bytes por v�rtice; preenche apenas os atributos raw utilizados pelo shader. A refer�ncia CPU permanece dispon�vel. O teste de workers compara a sa�da apropriada de cada rota.
- Telemetria: draws efetivos, pacotes unidos, hashes de geometria, streams din�micos, c�pias VRAM-only, materializa��es e pend�ncias. Campos 14/15 do arquivo de configura��o controlam VRAM-only/cache de geometria, respectivamente; padr�es 1/0.

A captura anterior apresentava mediana de 133 draws e 8 readbacks de textura por quadro, com FPS mediano 44,85. N�o eram milhares de draws. Esses dados s�o da revis�o anterior, n�o evid�ncia de ganho do novo patch. Os shaders TEV j� eram fixos/cacheados; n�o foi encontrada compila��o por efeito.

---

# Auditoria GX → OpenGL — 2026-11-07

Patch validado em `build_test/Release/digimon_test.exe`. SHA-256: `C9E966A341BB21A203FA6BB040CF5F6AD2BAE7701991B7008D34C8C6FEF61C11`. Build saída 0 sem warnings, CTest 8/8, inventário 207 objetos /GL e 11.120 nomes. FPS com Mega/digivolução ainda depende de reprodução física; não foi declarado 60 FPS em combate.

## 1. Desenho, buffers e submalhas

Em `src_test/gx_gl.c`, `gx_gl_draw_internal` (linha 321) submetia um draw por pacote GX usando arrays na RAM host, `GL_ARRAY_BUFFER=0`, após reempacotar os vértices. Não havia VBO de streaming no caminho de desenho; o `glBufferData` encontrado antes desta revisão pertencia ao teste de transform feedback, não aos modelos. Não há evidência suficiente para afirmar milhares de draws na situação Mega descrita sem capturar essa situação.

O patch usa um VBO circular de 16 MiB, escreve em regiões disjuntas e troca o armazenamento com `glBufferData(NULL)` antes de voltar ao início. Usa `glMapBufferRange` com WRITE/UNSYNCHRONIZED/INVALIDATE_RANGE quando disponível, com fallback para SubData. Não há fence/finish nem escrita em regiões de draws anteriores. Se unmap indicar perda dos dados, troca o armazenamento e reenvia o pacote.

`geometry_find`/`geometry_store` (linhas 190/200) acrescentam cache de VBOs imutáveis por conteúdo raw, com hash e comparação integral contra colisões. Uma repetição confirma o candidato antes da promoção; poses que mudam constantemente usam o ring. São 128 entradas LRU, até 32 MiB combinados de RAM host e VRAM. Um hit evita reempacotar e reenviar os atributos. Materiais, ordem de desenho e XF continuam aplicados a cada draw; não se juntam materiais/transparências incompatíveis.

## 2. Texturas

`src_test/gx_pipe.c:get_or_create_texture` (linha 523) já verificava hash, portanto não decodificava toda textura a cada frame. Os problemas concretos eram duas buscas lineares de até 512 entradas e destruição/recriação da textura quando o conteúdo mudava.

Agora `texture_find` (linha 378) usa 1.024 buckets, chave endereço/dimensões/formato/TLUT, e LRU. Alterações reais usam `SDL_UpdateTexture` no objeto existente. Hash do conteúdo e paleta preserva coerência com escritas guest; o atalho por época só vale no lote síncrono atual. O buffer de decodificação é reutilizado. Texturas estáticas continuam sendo convertidas do formato GameCube na primeira utilização, com armazenamento persistente no OpenGL.

## 3. TEV e uniforms

Os programas TEV e XF já eram fixos, compilados uma vez por contexto. Não foi encontrado compilador por material/modelo/efeito. Entretanto `gx_gl_pack_yuy2` (linha 597) consultava três locations em cada cópia: agora são guardadas na criação do programa. Falhas de compilação também são guardadas para evitar novas tentativas a cada frame.

`upload_xf` (linha 283) antes reenviava todos os grupos de uniforms em cada draw, inclusive luzes, viewport, projeção e texgen inalterados. O patch compara blocos e atualiza somente os alterados. Matrizes que mudam por osso continuam sendo enviadas; o resto conserva os valores privados do programa. A validação por transform feedback usa seu próprio programa e não modifica esse cache.

## 4. GXCopyTex / readback

`copy_efb_texture` (linha 1730) fazia readback, codificação tiled na RAM e, quando a textura era usada, decodificação e novo upload. O log anterior confirma cópias I4 64×64 repetidas; ele sozinho não identifica qual chamada corresponde ao efeito azul.

`cache_efb_texture` (linha 1721) agora mantém a imagem amostrada em VRAM. RGBA8 sem redução usa FBO blit; os demais formatos usam um programa de cópia/quantização único. São tratados os 13 formatos do runtime, redução 2×2 com média inteira e conversão de intensidade. O objeto GPU é publicado no mesmo cache com hash dos bytes guest. Se a CPU mudar esses bytes, a consulta seguinte atualiza a textura a partir da RAM.

**Limite importante:** o readback que materializa a RAM guest continua. O jogo e os testes podem ler essas cópias pela CPU. O patch elimina a volta RAM→decodificador→upload da textura amostrada; não omite a escrita guest. Remover todo readback exige rastrear leituras/escritas e materializar sob demanda, incluindo PSQ, DMA, kernels nativos e arrays dos workers. Essa infraestrutura não foi introduzida disfarçadamente. Nenhum frame ou efeito foi descartado.

## 5. Endianness e display lists

`gx_pipe_process_display_list` (linha 579) continua interpretando os comandos; uma DL pode alterar BP/XF, chamar outras listas ou referenciar arrays que mudam. Os atributos/indexação ainda são lidos e convertidos na CPU. O cache novo reutiliza o VBO quando a geometria efetiva é idêntica, inclusive para DLs estáticas; não reutiliza uma pose apenas pelo endereço da lista. A conversão de atributos anterior ao cache GPU continua como custo residual explícito.

## 6. Ossos e skinning

Projeção, matrizes XF de posição/normal, luzes e texgen usam o vertex shader já existente. O skinning realizado pelo programa PPC, em `paired_skinning.c`/`skinning_accumulate.c`, continua nos kernels SIMD da CPU: ele produz bytes em RAM/locked cache e estados observáveis pelo guest. A revisão não afirma que essa parte foi migrada para GPU. Mantiveram-se os testes de CPU/RAM/FPSCR/orçamento e os modelos não foram simplificados.

## 7. I/O e áudio

O hook `DVDReadAsyncPrio` em `test_main.c` chamava `dvd_vfs_read_bytes` diretamente antes de enfileirar o callback. Portanto o I/O era síncrono na thread principal apesar do nome. O DMA DI também fazia leitura síncrona.

`dvd_vfs.c:dvd_worker` (linha 38) agora faz seek/read em buffers privados numa fila de 16 pedidos. Um mutex protege o cursor do arquivo, inclusive contra leituras de boot/FST. `dvd_vfs_pump` (linha 64), chamado antes do polling de interrupções/idle, publica bytes e estado guest e enfileira o callback ou sinaliza DI. O worker não toca RAM guest, registradores ou OpenGL. A fila mantém estado busy até publicação; falhas não publicam um buffer parcial. Shutdown/remount aguardam o worker e liberam os pedidos.

No áudio, o fread dos coeficientes DSP está na inicialização. Não foi encontrada leitura de arquivo de música dentro do renderizador; mistura AX e SDL_QueueAudio continuam na CPU. Não foi atribuída a elas uma causa de queda com Mega sem medição.

## Validação e medição

- Oito testes CTest aprovados, incluindo software e OpenGL.
- Oito comparações de framebuffer exigem conteúdo realmente desenhado.
- Wrap do VBO, geometria estática reutilizada, mudança de pose e mudança de atributos.
- 52 cópias GPU comparadas pixel a pixel: 13 formatos × 2 filtros × 2 modos de intensidade.
- 520 chaves de textura, colisões, pressão LRU, escrita guest e atualização no mesmo objeto.
- Cópia I4 integrada: bytes tiled corretos na RAM e amostragem GPU sem upload CPU adicional.
- DVD assíncrono: ABI do callback real, DMA DI busy/completion, CISO sparse/truncado, fila cheia e seeks concorrentes.
- Replay de combate com todos os bytes BMP iguais à referência: 640×528, SHA-256 `2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.

O log `runtime_driver.log` informa `[GL driver]` (draws, bytes do ring, orphans, compilações, queries, cópias VRAM, hits de geometria e blocos XF enviados), `[Texture cache]` (hashes/uploads/readbacks) e DVD pendente. Os totais precisam ser convertidos em deltas por VBlank, feito por `capture_frame_cost.py`. Eles permitem verificar a carga Mega/efeito sem supor a causa pelo FPS. O processo está aberto com input físico; a reprodução de combate foi solicitada. Não há compilador ou sampler ativo na execução entregue.


### VRAM-only I4 e streaming sem hash - 2026-11-07

Build final: saida 0, sem warnings; CTest 8/8; inventario 207 objetos /GL e 11.149 nomes. SHA-256: `5A3C84EEF5F1723E2453AB8268A5FF22D206873B73B0E7F9D208DD8D09C3F129`. Manifesto: build_test/vram_manifest.json; mapa: build_test/vram_active.map; runtime: runtime_vram.log. Baseline anterior preservada.

GXCopyTex I4 64x64/stride256 usa somente VRAM, sem readback ou escrita guest, conforme contrato de consumo informado pelo usuario. Demais formatos/tamanhos preservam materializacao. Slots pendentes protegidos, limite64; captura/desligamento/aliases incompativeis resolvem RAM. Nao ha interceptacao geral de leituras CPU arbitrarias. Teste integrado confirmou RAM e contador de readback inalterados, amostragem GPU e materializacao tiled corretas.

Cache integral de geometria OFF por padrao: raw segue direto ao ring UNSYNCHRONIZED sem hash/memcmp do mesh. Cache de indices dentro de um draw preservado. Agrupamento conservador de listas consecutivas com material/XF identicos, sem reordenacao. Raw evita limpar/copiar a estrutura de projecao CPU inutilizada. 24.576 comparacoes de atributos e 425.984 vertices CPU/raw/serial/workers aprovados; teste GPU confirma bypass de hash e framebuffer de listas agrupadas; replay de combate identico byte a byte.

Config campos14/15: VRAM-only=1, cache geometria=0. Telemetria inclui draws, merges, hashes, streams, copias VRAM, materializacoes e pendencias. Prompt inicial confirma geometry_hashes=0 e dynamic_streams ativo. Referencia anterior: ~133 draws e8 readbacks/frame,44,85FPS mediano. Ganho em combate e60FPS pendentes de reproducao fisica; solicitados quatro humanos em Jungle Ruins. Nenhum input automatico. Detalhes: GRAPHICS_DRIVER_AUDIT.md.


### Restauracao do cache e medicao exclusiva por QPC - em validacao

O cache integral de VBO voltou ao padrao ON, com fast-path I4 64x64 VRAM-only preservado. Configuracao runtime: campos14/15 =1/1. O cache esta no backend, depois do decode GX: evita repacking/upload de meshes repetidos, nao a leitura de atributos anterior.

frame_timing.c usa QueryPerformanceCounter/QueryPerformanceFrequency diretamente no Windows. Zonas aninhadas exclusivas impedem contar flush de draws tanto em GXCopyTex quanto em submit. O marcador [Frame60] registra a media de60 frames para cpu_game_logic_ms, cpu_gx_decode_ms, gl_draw_submit_ms, gl_efb_copy_ms e gl_swap_wait_ms. Soma inclui host_other_ms e host_pacing_ms e deve corresponder a frame_wall_ms. O teste sintetico verifica60 quadros, aninhamento e conservacao da soma.

cpu_game_logic_ms inclui o laco de execucao recompilado/despachante/HLE fora das zonas GX, nao apenas fisica/IA. cpu_gx_decode_ms inclui parser FIFO/DL, atributos, texturas e hash/repacking de VBO; gl_draw_submit_ms inclui chamadas backend/driver e apresentacao do XFB ao SDL; gl_efb_copy_ms inclui GXCopyTex e GXCopyDisp/XFB, com codificacao/readback quando necessario; gl_swap_wait_ms mede SDL_RenderPresent, incluindo espera do driver/SwapBuffers. Sao tempos de parede no host, nao timestamps GPU nem soma dos tempos dos workers. Espera pelos workers pertence ao decode.

O Release anterior e o projeto usam /O2 /USEPROFILE, nao /GENPROFILE, /FASTGENPROFILE ou /LTCG:PGINSTRUMENT. Dumpbin do executavel anterior nao importa pgort. O pgort140.dll remanescente da coleta nao implica uso. CPU_PROFILE/RUNTIME_TRACE/GX_FIFO_TRACE nao estao ativos. stdout agora usa buffer64KiB; [Frame60] e descarregado apenas a cada60 frames, alem do resumo legado por segundo e eventos pontuais. Sem flush de log por vertice/draw/frame no caminho normal.


### Cache VBO restaurado + cinco timers QPC - validado 2026-11-07

Release ativo SHA-256 `8658394B43CD043AC554D81BED0D39652EFFADDCF99CDC1C75DDA12673D78F2F`; build_timing_release.log saida0 sem warnings, CTest8/8, inventario208 objetos /GL e11.177 nomes. Mapa: build_test/timing_active.map; manifesto: build_test/timing_manifest.json. Execucao: runtime_vram.log; log anterior preservado em build_test/runtime_vram_before_timers.log.

Cache VBO ON por padrao e configuracao, mantendo I4 64x64 VRAM-only. Registro confirmou geometry_cache=1 e geometry_hits aumentando, com dynamic_streams=0. Cache do backend evita repacking/upload; decode GX anterior permanece.

frame_timing.c/h mede diretamente QPC no Windows. [Frame60] a cada60 frames: cpu_game_logic_ms, cpu_gx_decode_ms, gl_draw_submit_ms, gl_efb_copy_ms, gl_swap_wait_ms. Campos adicionais host_other_ms/host_pacing_ms fecham a soma com frame_wall_ms. Zonas aninhadas exclusivas separam flush/draws de copies; workers nao somados em paralelo. Contrato sintetico de60 quadros aprovado e soma dos registros reais conferida com erro de arredondamento menor que0,0005ms.

Escopo: game inclui loop recompilado/despachante/HLE fora de GX; decode inclui parser/DL, atributos, texturas e hash/repacking VBO; submit inclui backend/driver e upload/apresentacao XFB; copy inclui GXCopyTex e GXCopyDisp/XFB; swap mede SDL_RenderPresent/SwapBuffers, nao o limitador de60Hz (campo pacing separado). Sao tempos de parede CPU/espera, nao timestamps de execucao GPU.

Release /O2 /USEPROFILE confirmado; nenhuma flag GENERATE/PGI e nenhuma importacao pgort/pgoboot. stdout64KiB bufferizado; novo resumo descarregado a cada60 frames e resumo legado por segundo, sem flush por frame/draw no caminho normal. Teste fisico de quatro humanos solicitado; nenhuma alegacao de60FPS em combate ou novos tempos de luta antes da reproducao.


### Medicao real de quatro humanos em Jungle Ruins - 2026-11-07

Usuario confirmou luta aberta. Captura de20s,16 janelas de60 quadros (960 frames), sem compilador, amostragem ou alternancia de configuracao durante a captura. Artefatos: build_test/frame60_combat_capture.log e frame60_combat_summary.json.

Medias QPC exclusivas por quadro: cpu_game_logic_ms=13,01564; cpu_gx_decode_ms=4,32976; gl_draw_submit_ms=2,47194; gl_efb_copy_ms=1,66834; gl_swap_wait_ms=0,10189; host_other_ms=0,09181; host_pacing_ms=0,00029; frame_wall_ms=21,67968. Media do indicador FPS=46,235. Janelas variaram de19,03 a25,20ms. Faltam aproximadamente5,01ms por quadro para o orcamento de16,67ms.

Por quadro:135,72 draws OpenGL;112,84 hits de geometria (83,1%);7,99 copias I4 VRAM-only;0 materializacoes;0 readbacks de TEXTURA;0 compilacoes de shader;0 consultas de uniforms. GXCopyDisp/XFB ainda inclui sua copia/readback no campo EFB de1,67ms: zero readbacks de textura nao significa zero readbacks totais. Cache ON e VRAM-only efetivamente ativos.

O maior grupo medido e execucao recompilada/runtime fora do GX (~60% do tempo), seguido do decode GX (~20%). O submit OpenGL nao explica sozinho o deficit de5ms. Esta medicao nao identifica uma unica funcao de jogo responsavel pelos13ms.

Apos encerrar a captura de FPS foram feitas amostragens separadas, sem escrita guest/input: frame60_combat_native_profile.json (3.761 amostras) e frame60_combat_stacks.txt (318 pilhas; simbolizacao em frame60_stack_summary.json, mapa timing_active.map). Custos distribuidos entre chunks recompilados, mem_read32/mem_write32 e auxiliares float; dentro do GX aparecem decode_vertex/run_vertex_job e espera de workers. PC802CCA84 corresponde a escrita no registrador CP que dispara processamento GX, e nao a uma funcao de IA lenta; contagem inclusiva de PC nao deve ser confundida com custo exclusivo. Amostragem tem limites estatisticos e perturba a execucao: seus FPS nao entram na referencia acima.

Nenhuma nova otimizacao especulativa nem mudanca de flags aplicada apos a medicao. Executavel e configuracoes mantidos; janela preservada.60FPS em combate ainda nao atingidos.


### XFB GPU, cache de decode e RAM/float - arquitetura da revisao em validacao

XFB: gx_pipe.c guarda ate8 snapshots RGBA GPU separados por endereco guest. GXCopyDisp durante scene4 copia EFB para a alocacao GPU correspondente, registra tamanho/pitch e emite os mesmos efeitos de PE/VI/clear; video_present_frame consulta o endereco realmente selecionado pelo VI. Nao apresenta o EFB corrente nem faz upload da RAM stale. Fora do gameplay, ao desligar a opcao ou iniciar captura, imagens pendentes materializam YUY2 usando o caminho de referencia. O pack shader consulta dimensoes reais da textura, incluindo snapshots pequenos. O fast-path assume o contrato informado pelo usuario (CPU nao le XFB durante a luta), sem interceptacao universal de leituras RAM. A apresentacao direta RGBA evita a perda RGB->YUY2->RGB, portanto nao se declara identidade byte a byte com a imagem YUV antiga no modo rapido.

Decode: cache de256 entradas/32MiB, separado do VBO, antes de decode_vertices. Chave inclui layout, CP, bytes FIFO e spans exatos/conservadores das arrays referenciadas (min/max de indices); assinatura completa e comparada apos XXH64. Alteracao de RAM/FIFO/CP invalida a entrada, nao ha reutilizacao apenas pelo ponteiro. XF e materiais permanecem snapshots independentes enviados ao shader. Cache hit reutiliza atributos raw e hash de saida validado; o VBO ainda verifica seu conteudo, mas nao recalcula o hash inteiro no hit do decode. Assinaturas de entrada continuam verificadas em cada pacote. Draws raw menores que4096 vertices ficam na thread principal; software mantem limiar1024.

[GX60] detalha key_ms (construcao/hash/lookup da assinatura), worker_wait_ms, vertex_main_ms, vbo_hash_ms, vbo_lookup_ms e vbo_repack_ms, alem de hits/misses do decode. Sao submedidas de parede; main e espera nao somam tempos de CPU de todos os workers. Workers/testes de referencia continuam disponiveis; teste do cache altera RAM e FIFO, exige invalidacao e reuso apenas quando igual.

RAM: primary_ram.h e incluido pelo build nos chunks sem editar codigo gerado. Helpers32 pequenos __forceinline usam RAM base e bounds, memcpy4 que MSVC reduz a mov, e _byteswap_ulong. MMIO, aliases fisicos, MEM2, locked cache e acessos cruzando limite conservam fallback. Escritas com reserva/journal tambem conservam o runtime. O indicador historico Native RAM inline=0 refere-se ao adaptador experimental antigo; nao desliga estes helpers novos compilados.

Float: binary_single_reference preservado; binary_single possui caminho finito com classificacao por bits e atualizacao FPSCR reunida em uma escrita. Flags nao foram removidos. NI, NaN/infinito, divisao e overflow double fazem fallback.131.072 comparacoes completas CPU/FPSCR/excecoes do host, cobrindo oito controles de arredondamento/NI e entradas adversas, passaram. Paired Singles SIMD anteriores preservados. Nao foram aplicados /fp:fast nem AVX2 global: alteram semantica ou requisitos sem demonstrar ganho. Runtime usa /O2 /Ob3 /Oi; chunks /O2, /Oi e somente helpers pequenos de RAM forcados inline.

Config opcional16: XFB VRAM solicitado (default1, efetivo apenas scene4). Campo17: cache decode (default1). Cache VBO continua ON; I4 VRAM-only continua ON. Validacao final, hash do binario e nova medicao serao acrescentados apos build.


### XFB GPU + cache anterior ao decode + caminhos RAM/float - validado 2026-11-07

Release ativo: SHA-256 `1D4BE9633DA366A79024C3A2B0C8D5CAA523C2DA34DFA19EECD94F952669B68E`; build_xfb_clean.log saida0 sem warnings; CTest8/8; inventario208 objetos /GL e11.523 nomes. Manifesto build_test/xfb_manifest.json; mapa xfb_active.map; runtime_vram.log. Referencia anterior preservada em timing_validation/timing_active.map e runtime_before_xfb_gpu.log.

Implementacao detalhada na secao XFB GPU de GRAPHICS_DRIVER_AUDIT.md. XFB usa snapshots GPU por endereco e VI real, somente no gameplay; YUY2/RAM materializados ao desligar/sair da luta/capturar. Cache anterior ao decode valida FIFO, CP e arrays RAM por hash+assinatura completa, reutiliza atributos raw e hash VBO; invalidacao por RAM/FIFO testada. Raw draws menores que4096 vertices dispensam workers; novos contadores GX60 separam key/main/wait/hash/lookup/repack. Cache VBO e I4 VRAM mantidos.

RAM principal32 inline nos chunks usa bounds e byteswap, preservando MMIO, aliases, reservas e journal (2.436 casos). Float finito une atualizacoes FPSCR e mantem referencia para especiais (131.072 comparacoes completas CPU/flags/excecoes host). Nao houve remocao semantica de FPSCR nem /fp:fast global. Runtime /O2 /Ob3 /Oi, chunks /O2 /Oi e helpers pequenos forceinline. Sem PGI nem importacao do runtime de coleta.

Testes integrados incluem425.984 vertices CPU/raw/serial/workers, cache com mutacoes reais, XFB independente por alocacao e materializacao YUY2;8/8 aprovados. Na primeira validacao o proprio teste XFB deixava pixels no EFB, detectado pelo teste seguinte; corrigida restauracao do EFB e estado SDL no teste. Replay de referencia permaneceu identico. No prompt inicial da execucao nova, cache de decode confirmou hits e vertex_main_ms/worker_wait_ms zerados em pacotes reutilizados; nao e medicao de combate.

Config opcional16 XFB VRAM solicitado=1 (efetivo scene4),17 cache decode=1. Nova medicao de960 frames em Jungle Ruins com quatro humanos solicitada e pendente de confirmacao fisica; nao ha alegacao de<15ms ou60FPS nesta revisao.


### Diferencial idle/acao e AABB nativo - 2026-11-07

Release SHA-256 `B4380734C9346DEA1B55FD5255638BED15A88EC3918E418969ED372EC5A5270A`; mapa `build_test/motion_active.map`; manifesto `build_test/motion_manifest.json`. Build saida0 sem warnings, PGO USE sem coleta; CTest9/9 em `test_motion_ctest.log`.209 objetos /GL e11.501 nomes no mapa.

Janelas360quadros/mode11: GAME11.392->13.358ms, GX3.043->3.150ms, submit1.808->1.926ms, EFB0.120ms na acao. Cache123/15 hits/misses idle e124.07/21.44 na acao. Hash0.053ms, espera workers~0.0006ms na acao. Perfis independentes e top10 incrementos em ULTIMATE_CPU_PROFILE.md.

HLEs completos80276CC0(expansao AABB por ponto) e80276D6C(uniao), incluindo entradas intrachunk:2.560 comparacoes CPU/RAM com aliases,signedzero,CR/FPSCR,PS1,downcount. Mantidos1.920 casos dos planos/AABB. BVH80275528 permanece original: estimativa nao cresceu(0.255->0.227ms). Dispatcher ja usa tabela diretaO(1).

Dirty tracking64B nos escritores gerenciados + shadow24MiB e geracoes3MiB; GetWriteWatch uma vez por hostframe e refinamento das paginas4KB em linhas64B realmente alteradas. Escritas vizinhas em outra linha nao invalidam vertices. Escritas externas observadas na barreira seguinte. CP key inclui apenas layout/indices/arrays usados, mantendo FIFO e comparacao integral apos hash. Testes de false sharing/CP irrelevante/invalidacao real passaram software/OpenGL.

Input fisico e cfg11 preservados; VBO/I4/XFB GPU mantidos; generated/ intacto. Novo tempo em combate pendente de entrada fisica, sem alegacao de60FPS nesta revisao.


### Rollback64B, FIFO e pacing - 2026-11-07

Release `303168CC3AD10EF68F00DBF36BFBCBE345C6806323B6EDAC3B69BDF41D261BFC`, mapa fifo_active.map, manifesto fifo_manifest.json. PGO USE sem coleta; build0 sem warnings; CTest9/9;209 objetos/GL e11.538 nomes. Removidos geracoes64B/shadow; tracking4KB com uma GetWriteWatch/frame. FIFO transporta blocos e nao reinterpreta pacotes vinculados incompletos:578linhas/3parses no teste,mas contador0deferrals no combate predominantemente nao vinculado. VSync0 confirmado; pacer sem espera extra apos atraso validado.

960quadros atuais:GAME14.938ms/GX3.345ms/submit2.280ms/EFB0.118ms/swap0.068ms/quadro20.893ms. Anterior64B:GAME16.653ms/quadro22.528ms; acoes variaveis impedem alegar ganho causal. Top15 total exclusivo/inclusivo parcial e todas as limitacoes em CPU_TOTAL_FIFO_REPORT.md. Nao e60FPS; thread CPU/GX continua sincrona, input fisico preservado. Pilhas/amostragem separadas dos timers.


### HLE/inline compacto e worker GX raw - 2026-11-07

Release `DAECE957DB16E34B848EAB58A8F1487CB3B92DF88A308AD0C849CB1CA438B184`; mapa async_active.map; manifesto async_manifest.json. Build0 sem warnings, PGO USE, CTest12/12,214objetosGL/11.653nomes. Novos nucleos em tres funcoesTop10(copias matriciais),floor8029D888 e vetores8028BEDC/BF58; comparacoes completasCPU/RAM aprovadas. Helpers compactos forceinline em todos os chunks, referencias/excepcionais fora de linha.

Worker captura comandos+atributos imutaveis no parser comum, incluindo FIFO nao vinculado; prepara raw vertices de misses enquantoCPU segue. Cache hits preservados. EventosPE/EFB/copia e reuso de output aguardam pendencias; GL fica na main. Codigo/cfg async=1 por padrao,campo20 controlaA/B. Timers worker/wait/snapshot separados. Detalhes/limites em ASYNC_GX_HLE_REPORT.md; novo desempenho em combate ainda nao medido. Tracking4KB e inputfisico mantidos.


### Correcao de reutilizacao intradraw do worker - 2026-11-07

Release `221D241B852DE1A8B5FA465F04A3EC510E5F3477B2570A035849816127328DDC`; mapa async_reuse_active.map; manifesto async_reuse_manifest.json. Build0 sem warnings, CTest12/12,214objetosGL/11659nomes. Primeira captura confirmou jobs/HLE ativos mas quase todo1.02ms de worker virava espera0.96ms. Cargas on/off variaram; coletor relia42MB/log a cada250ms e foi corrigido para seek/tail. Nao se alega ganho de FPS com essas janelas.

Worker agora preserva tambem cache intradraw de vertices indexados:64vertices/4combinacoes deram4misses/60hits e output identico, incluindo reutilizacao de RAM/CP/FIFO antes de agendar. Novos contadores de reuse/drains/peak. Async=1 mantido no codigo/cfg; nova comparacao idle pendente. Detalhes/medidas/ressalvas em ASYNC_COMBAT_FIRST_RESULTS.md.


### Recursos imutaveis e barreiraTLUT - 2026-11-07

Release `408A7829D11811A4EF9D187C02934483D30E31EED64293F9EB4D2E7A52AC0002`; mapa images_active.map; manifesto images_manifest.json. Build0 sem warnings, PGO USE, CTest13/13,215objetosGL/11712nomes. Pilhas confirmaram flushBP65 como11de17esperas observadas. Novo gx_images.c preserva fontes e paletas por versao; BP65 pode adiar flush com dados imutaveis. ChaveGPU64bit por identidade evita reupload/hash repetido. EFB/PE/I4VRAM continuam ordenados, sem readback novo.

Testes incluem reutilizacao simultanea de pixels e paleta antes deCopyDisp e lookup sem syscalls. Replay17batches identico antes/depois, formatoQueuedDraw preservado. Cfg20async=1,21immutable_images=1; novos contadores deTLUT/copies/fallback. Desempenho novo ainda nao medido; limites/evidencias em TLUT_PIPELINE_REPORT.md.
