# Primeira captura do GX assincrono e correcao de reutilizacao

A captura foi fisicamente identificada pelo usuario como combate. Binario medido DAECE957, anterior a correcao local de reutilizacao. Compilador/profiler ausentes durante960quadros; amostragem CPU executada DEPOIS de concluir as duas janelas.

| Etapa ms/quadro | Async ligado | Async desligado |
|---|---:|---:|
| `cpu_game_logic_ms` | 21.1994 | 17.0918 |
| `cpu_gx_decode_ms` | 3.6317 | 3.3866 |
| `gl_draw_submit_ms` | 2.3051 | 2.0872 |
| `gl_efb_copy_ms` | 0.1497 | 0.1184 |
| `gl_swap_wait_ms` | 0.1041 | 0.0709 |
| `host_other_ms` | 2.2664 | 0.1414 |
| `frame_wall_ms` | 29.6566 | 22.9166 |
| `async_worker_ms` | 1.0201 | 0.0000 |
| `async_wait_ms` | 0.9621 | 0.0000 |
| `async_snapshot_ms` | 0.1608 | 0.0000 |

Ligado: 117.90 hits/21.11 misses por quadro. Desligado: 87.99/27.72. A quantidade de draws e as acoes variaram; portanto NAO se atribui a diferenca de FPS somente a fila. async_worker_ms e tempo decorrido no worker (QPC), nao tempoCPU de thread nem valor para somar ao quadro main.

Limite metodologico encontrado: o coletor antigo relia todo runtime_vram.log(42MB) a cada250ms e so depois descartava o prefixo. Isso pode perturbar cache/escalonamento; a primeira janela teve GAME14.54..50.49ms e a segunda14.82..18.39ms em medias de60quadros. Os dados permanecem arquivados com ressalva, nao sao referencia rigorosa contra14.938ms anterior. tools/capture_frame60.py agora faz seek ao inicio da captura e le somente o trecho novo.

Conclusao confirmada: worker e HLEs eram acionados; espera0.962ms de1.020ms no worker mostrou pouco overlap nesta janela. Nao foi comprovado ganho60FPS.

Regressao funcional de desempenho encontrada no novo caminho: cache entre draws estava ativo, mas o decoder assincrono nao reutilizava vertices indexados repetidos DENTRO do draw, diferentemente do decoder legado. Corrigido com tabela local4096indices, hash+comparacao completa da linhaFIFO; hits copiam o raw ja produzido no mesmo snapshot imutavel. Nao se usa hash sem verificacao, nem se reintroduziu tracking64B.

Teste novo submete dois snapshots depois de reutilizar RAM/CP/FIFO; no segundo,64vertices com4combinacoes produziram4misses e60hits, resultado byte a byte identico aos4vertices originais. Testes integrados425.984vertices passaram software/OpenGL e CTest12/12. Novo telemetry inclui async_vertex_hits/misses,async_drains e async_peak_pending(cumulativo). Esses contadores permitirao distinguir o custo do worker de quantos jobs realmente podem acumular antes de cada barreira.

Amostragem exclusiva GAME posterior da revisao inicial:2811amostras, helpers PPC/float externos estimados0.468ms contra1.249ms na captura historica; chunks agora13.407ms incluindo helpers inline. Nao e prova de ganho total: referencia QPC e carga mudaram. Dados em async_combat_cpu_profile.json/async_combat_cpu_totals.json.

Release corrigido atual: `221D241B852DE1A8B5FA465F04A3EC510E5F3477B2570A035849816127328DDC`; mapa async_reuse_active.map; manifesto async_reuse_manifest.json; build0 sem warnings; CTest12/12;214objetos/GL e11659nomes. Codigo/cfg continuam async=1 por padrao. Nova medicao controlada depende de quatro humanos parados na mesma luta; nenhum input foi simulado.
