# Retornos dos chunks e encadeamento com quantum 1024

## Restauração

Quantum padrão e `build_test/runtime_tuning.cfg` voltam a **1024**, downcount
inicial **768**, limiar **-256**. O algoritmo de pacer em `frame_timing.c` volta
ao da revisão `GUEST_BUDGET_REPORT.md`: atraso já vencido fica imediatamente
executável e reinicia a referência, sem catch-up acumulado. A política de
`guest_frame.c` permanece a mesma dessa base; os contadores de janela e picos
individuais foram preservados, sem alteração do relógio ou dos deadlines.

A base confirmada pelo usuário está preservada em `build_test/pre_quantum_pacer.exe`,
SHA256 `973A8D367C9CDC85C57798369A62595637D525CAC82B1E99D35C6EFD37777F4E`.

## O que os 41–56 mil dispatches significavam

`GuestFrameBudget.dispatches` era incrementado antes de cada chamada externa a
`platform_execute_cpu_slice`. Essa função renovava o orçamento e chamava
`dolrecomp_run_blocks(cpu,1)`. Exceto pela continuação já existente de instruções
de cache/prefetch, retornava ao laço host após um segmento gerado, mesmo com
downcount positivo. O orçamento é um **teto**, não uma quantidade mínima de
instruções por chamada. Não se pode dividir uma contagem de segmentos por 1024
para deduzir o número de chamadas do host.

Exemplo confirmado no fonte gerado: o `bl 0x801D009C` em `0x8018F4C4` grava LR,
grava PC de destino e retorna ao host. Há outros padrões: saltos indiretos,
retorno LR para outro chunk, fallthrough e yield por orçamento. Chamadas/gotos
que já permanecem dentro do chunk não fazem necessariamente essa volta.

`dolrecomp_find_original` já resolve o chunk por tabela/faixa direta. Não havia
uma busca por hash para substituir. A correção mantém essa resolução e os hooks
de replacement existentes, encadeando iterativamente o PC de saída com o destino.
Não cria recursão C adicional nem modifica a lógica de funções guest.

## Encadeamento e safepoints

No combate, `platform_execute_cpu_slice` reutiliza o downcount positivo para
executar o próximo segmento, sem voltar às bombas pesadas do host. Cada
transição encadeada mantém a contabilização da posição lógica e o mesmo avanço
TB que teria ocorrido no laço anterior. A cota de 300 mil posições e os relógios
AI/DSP/VI não foram aumentados.

O encadeamento para em orçamento esgotado, MMIO, exceção, hook HLE tratado,
interrupção pendente, callback ativo/pendente, DVD pendente, regiões do scheduler
e handlers OS/VI, PCs com correções host, deadline de dispositivo e antes de
atravessar a fronteira original de polling de 128 posições. O perfil amostral de
funções também desativa o encadeamento para preservar a atribuição por PC.
O flag de MMIO é local à thread; o backend não interfere no flag da CPU guest.

`build_test/dispatch_chain.cfg` permite comparar 0/1 na mesma execução, sem
reiniciar, emitir input ou alterar os personagens. Padrão: 1. Fora do combate e
sem contexto de continuação, a função conserva a política de execução anterior.

## Medição dos motivos de retorno

Os logs antigos **não registravam os motivos**. Não há como decompor
retrospectivamente os 56.349 retornos com precisão a partir deles. Também não
provam que o pico QPC de 31,8 ms representou dois quadros fundidos: o valor inclui
preempção e espera do host, e a base antiga não guardava picos individuais.

O pós-processador agora insere `CHUNK_RETURN` somente nas cópias de build,
preservando os pontos de retorno e os 185 fontes originais. Um marcador distingue
orçamento, branch direto/linkado, CTR, LR, fallthrough, retorno de filho,
exceção e falha de despacho. Retornos de adapters que escapam por macros podem
ficar como `unknown`; essa categoria é explícita, sem inventar um opcode.
Orçamento e exceção têm prioridade quando observados na fronteira externa.

`[Dispatch60]` separa **hosts**, **calls**, **links**, motivos de saída e paradas
por orçamento/fence. `calls` pode incluir continuação de cache já existente;
`hosts` mede chamadas ao executor a partir do laço host. Os contadores de posição
guest continuam incluindo os links: diminuir o número impresso artificialmente
mudaria a interpretação do relógio.

## Validação

As comparações existentes de CPU/RAM/LC permanecem intactas. Uma terceira
execução compara o caminho encadeado ao resultado final já validado, em quatro
quanta, modos de arredondamento/NI, aliases e RAM/locked cache. Somente downcount
é normalizado nessa comparação adicional porque a renovação do orçamento é
justamente a diferença de agendamento testada; registradores, flags e memória
precisam coincidir integralmente.

Release final: SHA256
`4A3990E81D3F8E103FE7D1A845E508F04464822CED4B8C056E9D3C71DECE73DF`.
Build CMake/MSVC saída 0, sem warnings (`build_dispatch_final.log`), CTest
**18/18** (`test_dispatch_final_ctest.log`). Replay de 17 lotes idêntico, SHA256
`2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.
Inventário: 216 objetos LTCG, 11.957 nomes no mapa. `.text`: 144,275780 MiB;
a instrumentação dos retornos também altera tamanho/layout, portanto equivalência
de estados não basta para afirmar ganho de FPS.

Mapa/manifesto: `build_test/dispatch_chain_active.map`, `dispatch_chain_manifest.json`.
O jogo foi reaberto, sem automação de botões. A coleta prevê 240 quadros com
encadeamento desligado e 960 ligado na mesma luta, descartando duas janelas de
transição por modo. Até a luta ser confirmada, contagens por motivo e ganho de
FPS permanecem pendentes, não substituídos por números sintéticos.

A tentativa inicial de coleta aguardou 120 segundos e recebeu zero janelas de combate (scene=4): a instância permaneceu no prompt inicial. O coletor terminou e restaurou dispatch_chain.cfg=1. Janela preservada para a confirmação física; não há números de retorno de combate novos a apresentar nesta tentativa.
