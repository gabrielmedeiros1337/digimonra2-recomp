# CPU total, FIFO e pacing - 2026-11-07

Release SHA-256 `303168CC3AD10EF68F00DBF36BFBCBE345C6806323B6EDAC3B69BDF41D261BFC`, mapa fifo_active.map, PGO USE (sem coleta). Build sem warnings, CTest9/9; manifesto fifo_manifest.json. Janela mantida aberta, input exclusivamente fisico.

## Tempos QPC:960 quadros por execucao

O usuario confirmou combate na revisao nova. Captura sem compilador/sampler ativo, modos11; samplers foram executados depois. O log anterior foi encerrado pelo usuario e preservado. Acoes/modelos/evolucoes nao sao identificados no log: estas nao sao cargas identicas nem A/B causal.

| Etapa ms/quadro | Anterior64B B4380734 | Atual4KB303168CC |
|---|---:|---:|
| `cpu_game_logic_ms` | 16.6530 | 14.9380 |
| `cpu_gx_decode_ms` | 3.1739 | 3.3451 |
| `gl_draw_submit_ms` | 2.1361 | 2.2800 |
| `gl_efb_copy_ms` | 0.1147 | 0.1176 |
| `gl_swap_wait_ms` | 0.0785 | 0.0683 |
| `frame_wall_ms` | 22.5285 | 20.8927 |

## Onde o tempo total esta

Amostragem exclusiva GAME de10segundos, separada do QPC:4.567 amostras. Milissegundos por funcao/categoria sao estimativas da fracao de amostras multiplicada pela media QPC14.938ms, nao timers individuais exatos. Chunks incluem matematica/memoria que o compilador inlineou; nao se pode separar esses auxiliares apenas pelo nome do simbolo nativo.

| Categoria RIP exclusivo | Estimativa ms/quadro |
|---|---:|
| chunks PPC (includes inlined math/memory) | 10.9737 |
| runtime PPC / float conversion (non-inlined) | 1.2495 |
| other native host/HLE | 1.2298 |
| host DLL / system (caller unresolved) | 0.4645 |
| runtime memory (non-inlined) | 0.4448 |
| dispatcher / replacement lookup | 0.4350 |
| FIFO producer | 0.0883 |
| AX/audio native | 0.0327 |
| MMIO / locked cache | 0.0196 |

Regioes de prologo nativo identificadas por PE UNWIND_INFO SizeOfProlog: estimativa0.504ms, sobreposta as categorias acima. Nao inclui epilogos. Nao se atribui todo o custo dos chunks aos prologos. Produtor FIFO~0.088ms e audio nativo~0.033ms nesta captura; processamento GX nao esta contado de novo em GAME. O teste de timers verifica entrada/saida aninhada GAME->GX->EFB->GL sem dupla contagem.

## Top15 por custo proprio (total, nao diferencial)

Inclusive abaixo inclui descendentes observados pelo PC/LR/backchain guest. Todas as4.567 cadeias terminaram num limite/raiz nao validada: os valores inclusivos sao parciais, com ambiguidade em prologos/leaf/tail calls; nao sao medicao completa exata. Nao somar tempos inclusivos. Nomes por endereco inferidos da DOL e prologos stwu, nao nomes SDK presumidos.

| Funcao guest | Exclusivo estimado ms | Inclusivo parcial estimado ms |
|---|---:|---:|
| `0x8023DF34` | 0.4743 | 1.5929 |
| `0x8024C47C` | 0.3631 | 0.3631 |
| `0x8024D1EC` | 0.3533 | 0.8504 |
| `0x801CBD10` | 0.3369 | 1.2135 |
| `0x8024BB18` | 0.3107 | 0.3107 |
| `0x8024B030` | 0.2813 | 1.2985 |
| `0x801C64A8` | 0.2780 | 1.1710 |
| `0x8023DA04` | 0.2682 | 0.6836 |
| `0x802AF56C` | 0.2617 | 0.2617 |
| `0x8029D888` | 0.2519 | 0.2519 |
| `0x8023C690` | 0.2224 | 0.4874 |
| `0x80275528` | 0.2159 | 0.2257 |
| `0x80252488` | 0.2093 | 0.2093 |
| `0x8024C1B8` | 0.2028 | 0.2028 |
| `0x8028BEDC` | 0.1995 | 0.1995 |

## Top15 por custo inclusivo observado

| Funcao guest | Exclusivo estimado ms | Inclusivo parcial estimado ms |
|---|---:|---:|
| `0x80110818` | 0.0033 | 14.9380 |
| `0x801ACB04` | 0.0065 | 8.2229 |
| `0x800F8EB8` | 0.0164 | 7.3463 |
| `0x80287610` | 0.1276 | 6.4992 |
| `0x801AC614` | 0.0131 | 6.4338 |
| `0x800F89E4` | 0.0033 | 6.3814 |
| `0x8020A818` | 0.0196 | 4.5988 |
| `0x801DB970` | 0.0425 | 3.9316 |
| `0x80244970` | 0.0458 | 2.8162 |
| `0x801C75E8` | 0.0229 | 2.7214 |
| `0x801C7AA4` | 0.0327 | 2.6985 |
| `0x8020ACD0` | 0.0065 | 2.6952 |
| `0x801CDBB8` | 0.0033 | 2.6886 |
| `0x8018CF38` | 0.0098 | 2.1555 |
| `0x800DC434` | 0.0262 | 2.1457 |

0x80287610 e um despachante de listas/callbacks com ordenacao e chamadas indiretas:6.499ms inclusivos, apenas0.128ms proprios. Substituir o loop nao elimina o tempo dos callbacks. O mesmo cuidado vale para wrappers801ACB04/800F8EB8. 801DB970 chama8023DF34/80244970;80244970 chama rotinas802D5244/802D48D8 e preparacao de desenho. A cadeia8020ACD0->801CDBB8->801CBD10 alcanca os testes de volumes/planos. Sao cadeias verificadas no codigo, sem chamar todos esses custos de colisao/SDK ou supor que podem ser removidos.

Tambem foi capturada a pilha nativa via StackWalk64 filtrada GAME:274 amostras,64 frames maximos, thread retomada antes do unwind. O unwind nao alcanca o inicio do processo em todas as amostras; JSON contem ranking nativo inclusivo/exclusivo separado, sem fingir que e um call graph guest completo.

## Ranking da captura historica13.358ms

Esta e a captura4C8EAA86 anterior ao patch64B; nao misturar com14.938ms atual. Nao registrava pilhas, portanto seu inclusivo nao pode ser reconstruido. JSON motion_total_top15.json conserva todas as entradas e suas categorias.

| Funcao guest | Exclusivo estimado ms |
|---|---:|
| `0x8023DF34` | 0.5182 |
| `0x8024C47C` | 0.3504 |
| `0x801C64A8` | 0.3010 |
| `0x8024D1EC` | 0.2961 |
| `0x8029D888` | 0.2566 |
| `0x8023DA04` | 0.2517 |
| `0x801CBD10` | 0.2369 |
| `0x8024B030` | 0.2319 |
| `0x80275528` | 0.2270 |
| `0x8024BB18` | 0.2122 |
| `0x8024C1B8` | 0.2023 |
| `0x8023C690` | 0.1974 |
| `0x802023A4` | 0.1875 |
| `0x802AF56C` | 0.1777 |
| `0x8024A088` | 0.1727 |

Top15 somam3.8195ms; outras funcoes somam9.5389ms. Nao havia uma unica funcao escondida de13ms.

## Mudancas aplicadas e limites

- RAM: removidos geracoes64B e shadow24MiB; restauradas paginas4KB e GetWriteWatch no maximo uma vez por hostframe. Nao se aumentou a instrumentacao escalar. CP key normalizada e cache VBO preservados.
- FIFO: porta CC008000/0C008000 tratada antes dos dispositivos nao relacionados; gather e ring escritos por memcpy em blocos. No FIFO vinculado, linha transportada imediatamente, parser aguarda tamanho completo do pacote. Teste578linhas->3parses,575tentativas evitadas; CP read/distance, IRQ/token, ring wrap, DLs e snapshot de arrays transitorios preservados.
- IMPORTANTE: o combate desta captura usa predominantemente FIFO NAO vinculado e o contador incomplete_deferrals permaneceu0. O ganho do teste vinculado nao e apresentado como ganho de combate. O transporte em blocos e o rollback RAM sao os caminhos usados; nao se atribui a eles toda a diferenca de FPS.
- VSync: SDL_RenderSetVSync(renderer,0),SDL_GL_SetSwapInterval(0),SDL_GL_GetSwapInterval()==0 confirmados em runtime; retornos0. Swap0.068ms atual, portanto nao era espera16.66ms nesta captura.
- Pacer: prazo vencido retorna agora, sem arredondar para outra janela de VBlank. O codigo anterior ja pulava a espera em frames atrasados; novo helper explicita rebase e testes cobrem17/20/40ms sem espera extra. Nao acelera TB, injeta input nem pula simulacao.
- Mantidos HLEs AABB ja validados, XFB/I4 em VRAM, shaders/texturas/VBO caches. Sem edicao em generated/.
- CPU e decoder continuam na mesma thread; nao foi introduzido render thread com ponteiros guest mutaveis. Media20.893ms ainda acima do orcamento60FPS; nao se declara objetivo atingido.

Artefatos em build_test: fifo_before_timing.json,fifo_after_timing.json,fifo_game_profile_deep.json,fifo_game_stacks_deep.txt,fifo_total_top15_deep.json,fifo_manifest.json. Fontes de amostragem/reporte em tools/sample_native.py,sample_stacks.c,report_cpu_totals.py.
