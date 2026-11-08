# Chamadas constantes entre chunks e FIFO sem fence artificial

## Leitura da execução anterior

Log preservado: `build_test/runtime_before_direct_edges.log`.
Resumo reproduzível: `build_test/direct_edges_prior_summary.json`.

Últimos 960 quadros de combate registrados, média por quadro:

| Contador anterior | Valor |
|---|---:|
| CPU lógica | 17,1813 ms |
| Quadro completo | 19,2613 ms |
| Segmentos executados | 52.260,13 |
| Links iterativos internos | 36.687,53 |
| Chamadas pelo laço host | 12.549,22 |
| Branch direto | 743,42 |
| Branch linkado | 19.380,24 |
| CTR explícito | 253,81 |
| Orçamento | 1.215,87 |
| LR explícito | 0 |
| Saída pelo switch do chunk | 23.300,95 |
| Adapter/desconhecido | 6.809,63 |
| Exceção/guarda FP | 556,22 |
| Paradas por fence | 8.606,37 |

Limitação identificada na instrumentação anterior: `miss` marcava o `default`
do switch `return_dispatch`, que também é usado para retornos guest normais
para outro chunk. Não significa 23 mil endereços inválidos e não permite separar
retroativamente todos os retornos LR. `fence_stops` misturava MMIO, hooks e
fallback, sem identificar isoladamente as escritas GX. As categorias não são
rebatizadas como medições que não foram gravadas.

## Mudanças

A gravação de categoria em cada saída foi removida integralmente: sem
`CHUNK_RETURN`, `g_chunk_exit_kind`, `dispatch_trace.h` ou define de trace no
Release. As cópias de build dos 185 chunks foram regeneradas; os fontes originais
continuam intactos. Permanecem contadores agregados no executor, sem classificação
nem printf nos pontos de retorno do código gerado.

`handle_external_write` trata primeiro a janela do gather pipe `0xCC008000..1F`
e seu alias físico `0x0C008000..1F`. Essas escritas enfileiram os comandos sem
ativar o fence genérico. Se CP/PE levantar uma interrupção, o teste de IRQ pendente
continua encerrando o encadeamento. Outros dispositivos e os safepoints de áudio,
VI, DVD, callbacks e scheduler preservam suas condições de saída.

`tools/pc_dead_stores.py` converte **39.046 arestas estáticas** `b`/`bl` de destino
constante para `CHUNK_DIRECT(ctx, func_BASE_DO_CHUNK)`. Isso é contagem de sites de
código, não chamadas por quadro. PC e LR permanecem nas instruções originais.
Destinos são verificados contra os limites e funções da tabela gerada. Arestas
dinâmicas, mesmo chunk, hooks e PCs protegidos mantêm o dispatcher. A lista de
hooks e seu hash fazem parte da validação de cache/configuração do CMake.

O runtime autoriza a chamada direta apenas com orçamento, contexto de continuação,
sem override de host, exceção ou fence e após os mesmos safepoints do encadeamento
iterativo. O passo lógico/TB é contabilizado antes do destino, sem reiniciar
downcount. Ao bloquear, a aresta conserva PC e retorna normalmente ao executor.

Uma chamada C seguida de return **não garante** um `jmp` no MSVC, sobretudo com
frames grandes, unwind e verificações. O caminho final não contém limpeza após
a chamada, permitindo o tail-call. Sua segurança não depende dessa otimização:
mede o crescimento real da pilha host e devolve o controle ao executor ao alcançar
**2 MiB**. O executável reserva **8 MiB**, incluindo o default do worker SDL.
As chamadas internas geradas conservam o limite anterior de 24 níveis. O maior
frame de chunk medido pelos unwind records tem 168.968 bytes; a reserva anterior
de 1 MiB não cobria uma cadeia arbitrária de 24 frames desse tamanho.
Nenhuma função guest
foi substituída por HLE. Quantum1024/downcount768, pacer recuperado e relógios
permanecem inalterados. A guarda comum de preparação fica fora de linha para
evitar replicar seu corpo nos milhares de sites.

## Verificação

Os testes adicionais comparam o caminho direto ao iterativo incluindo registradores,
FPR/PS, RAM e downcount, comprimentos até 4096 passos e renovação de orçamento.
Uma chamada com alocação real de 3 MiB verifica a rejeição pela guarda de pilha.
Também verificam override host, exceção, orçamento esgotado e o limite legado de
24 níveis. As comparações reais de CPU/RAM/locked cache do
encadeamento anterior permanecem ativas.

Release final: SHA256
`D5797F407BDC4746D28F5A1724FD8E60A497AA631B6199D1D75D16B0F8E814C9`.
Build CMake/MSVC saída0 sem warnings: `build_tail_edges.log`. CTest **18/18**:
`test_tail_edges_ctest.log`, incluindo a rejeição real do encadeamento com
3MiB adicionais de pilha. Replay17 lotes idêntico, SHA256
`2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.
Inventário216 objetos/11885 nomes; `.text`143,886253MiB, contra144,275780MiB
da revisão instrumentada. Reserva PE confirmada8MiB; PGO OFF.

`build_test/tail_edge_assembly.txt` confirma um `call` relativo para
`func_801CF4C0`, sem tabela, no exemplo selecionado. **Não confirmou `jmp`**.
A remoção da limpeza permite a otimização, mas não a obriga; a guarda de pilha
mantém o caso `call` limitado. Não se afirma que todos os39.046 sites foram
transformados pelo compilador em saltos sem frame.

Mapa/manifesto: `build_test/tail_edges_active.map`, `tail_edges_manifest.json`.
O jogo foi reaberto com input exclusivamente físico. Nova captura prevista em
`build_test/tail_edges_combat960.json`; desempenho final em combate ainda pendente.

## Capturas finais e comparação na mesma instância

A captura final recebeu960 quadros completos em combate, sem watchdog:
CPU13,1064ms, frontend GX1,5561ms (incluindo fila0,8440ms), quadro16,8707ms.
Picos individuais: CPU25,8361ms e quadro29,1882ms. Média de107,351draws/quadro,
9.847,33 chamadas host e12.819,92 chamadas C diretas/quadro. Pico registrado de
crescimento de pilha em arestas aceitas:331.520bytes. Essa carga difere da
captura antiga de124,184draws; não é prova controlada de ganho.

Foi feita depois uma comparação0/1 na mesma luta e sem novos inputs do agente,
descartando duas janelas após cada troca. Configuração final restaurada1.

| Medição | Encadeamento0:240quadros | Encadeamento1:960quadros |
|---|---:|---:|
| CPU lógica | 15,9752ms | 16,1847ms |
| Quadro completo | 18,0148ms | 18,2765ms |
| Draws/quadro | 117,908 | 130,782 |
| Posições lógicas/quadro | 56.013,24 | 58.323,51 |
| Chamadas host/quadro | 56.013,24 | 12.523,86 |
| Chamadas C diretas/quadro | 0 | 16.963,70 |

Artefatos: `tail_edges_off240.json`, `tail_edges_on960.json` e
`tail_edges_ab_summary.json`, em `build_test/`. O modo0 desativa os dois tipos de
encadeamento; não isola apenas o efeito das chamadas C diretas. O combate continuou
dinâmico e a carga aumentou no modo1. A redução de transições está confirmada;
**o ganho de tempo/FPS não está demonstrado**. A medição não justifica alegar
60FPS constantes. O mesmo executável permanece aberto para confirmação visual e
sonora e uma futura comparação com a carga fixada pelo usuário.

## Tentativa intermediária descartada

A primeira versão com limpeza de profundidade após cada chamada foi executada
antes do ajuste final: 960 quadros, CPU18,7482ms, total20,7431ms,
128,440draws/quadro, 15.224,46 chamadas diretas/quadro. Não demonstrou ganho.
Dados preservados em `build_test/direct_edges_first_run.json` e
`runtime_direct_edges_first_run.log`. A desmontagem confirmou `call`, seguido
de outra chamada de limpeza: isso impedia o tail-call. A versão final remove
essa limpeza e usa a guarda de pilha descrita acima. Os números intermediários
não serão apresentados como desempenho do binário final.
