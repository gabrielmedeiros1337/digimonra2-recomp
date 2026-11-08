# Restrict, PC adiado na RAM e três arenas

Release: `E40C97E8EC961AD3F6A2DDC39BBB99B7BA0615D1794CC493AFA28D8B08376E8D`.
Mapa: `build_test/restrict_arena_active.map`; manifesto: `build_test/restrict_arena_manifest.json`.

## Código aplicado

`tools/pc_dead_stores.py` continua trabalhando somente em cópias de build dos 185 chunks. Os hashes dos originais foram verificados, sem modificações em `recompiled_code/generated/`.

- **3.009 funções** recebem um alias local `CPUState* __restrict ctx`. A assinatura externa permanece compatível com a tabela do dispatcher: MSVC considera o parâmetro `__restrict` um tipo diferente em certos ponteiros de função. O alias preserva a ABI sem suprimir warnings de tipos.
- **265.952 chamadas** de leitura/escrita escalar usam os helpers de `chunk_memory.h`. CPU e RAM têm ponteiros `__restrict` separados nos helpers. A base da RAM é capturada por função; seu contrato restrito termina na folha, sem atravessar callbacks HLE que podem acessar `ctx->ram`.
- No caminho normal da RAM principal, os helpers fazem acesso direto com `memcpy`/byteswap intrínseco. Não atualizam PC, tabelas de páginas ou dirty tracking. Reservas, journal, aliases, MMIO e acessos fora dos limites usam os caminhos lentos de `chunk_memory.c`, que materializam a **CIA exata antes do runtime/callback**.
- Stores que acionam HLEs por PC, incluindo os tails de cópia de matrizes, mantêm a macro e o PC originais. PSQ e chamadas desconhecidas continuam protegidos.
- **468.805 escritas de PC removidas no total**, sendo **231.124 adicionais** às 237.681 anteriores. As restantes incluem chamadas, retornos, branches, interceptações e outras situações observáveis; não são todas loads/stores comuns.
- O exame de ciclos encontrou **zero somas consecutivas elegíveis**. Atualizações separadas por labels, leitura de orçamento, chamadas ou controle não foram combinadas.

`gx_frame.c` passa a usar **três arenas** reutilizáveis, com no máximo 64 MiB cada. O crédito que limita o avanço da CPU a um quadro anterior pendente continua ativo. A alteração aumenta a capacidade de comandos, sem permitir uma fila ilimitada de imagens.

`gx_frame_backend.inc` reutiliza snapshots por endereço, tamanho, tipo de recurso e geração da arena. Uma comparação **exata de bytes** valida o conteúdo antes de reutilizar o offset. Uma escrita da CPU, DMA ou HLE é detectada sem instrumentar stores escalares. Colisões da tabela não produzem hits falsos. Referências não atravessam arenas recicláveis; a capacidade não utilizada no final do pacote é devolvida ao builder.

Novos contadores: `capture_unique_bytes_per_frame`, `capture_reused_bytes_per_frame`, `capture_compare_ms` e `arenas`. Barreiras, fila e decode no backend continuam separados. `queue_wait_ms` já está incluído em `cpu_gx_decode_ms` e não deve ser somado novamente.

## Validação

- Build CMake/MSVC Release: saída 0, sem warnings; `/O2`/LTCG, PGO OFF.
- CTest: **17/17**.
- **142.080** comparações de trechos gerados, agora incluindo RAM, callbacks que observam PC e reservas.
- **2.304** comparações independentes dos helpers: larguras, endianness, alinhamento, limites, aliases, MMIO/CIA, reservas e journal.
- Testes GX com reutilização de snapshot idêntico e alteração de RAM **dentro da mesma arena**, além de wrap do FIFO, XF privado e arredondamento.
- **1.041 vértices reais** das duas capturas idênticos nos caminhos raw e CPU-XF com snapshots compartilhados.
- Replay visual de 17 lotes idêntico: SHA256 `2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.
- Inventário: **215 objetos LTCG**, **11.622 nomes** no mapa final.
- `.text`: **146,3128 → 142,1982 MiB**. Isso mede tamanho, não demonstra isoladamente ganho de I-cache ou 4 ms.

## Medição do combate

A referência pesada informada era 17,1002 ms de lógica + 1,8784 ms de frontend GX, totalizando **18,9786 ms**. Os 0,7494 ms de fila já estavam dentro do frontend. Também foi preservada uma janela anterior recuperada do log, com 221,034 draws/quadro: `build_test/restrict_heavy_baseline960.json`.

A primeira execução nova teve no máximo **183,7 draws/quadro** e terminou normalmente. Seus últimos 960 quadros tiveram média de **143,039 draws**, portanto não são uma comparação válida com a carga pesada pedida. Dados preservados em `build_test/restrict_available_light960.json` e `build_test/runtime_restrict_first_run.log`.

Nessa janela disponível, a lógica CPU levou **15,6964 ms**, o frontend GX **1,8442 ms** (incluindo **0,9605 ms** de fila), e o quadro completo **18,0505 ms**. Esses valores não demonstram o corte de 4 ms na carga de aproximadamente 240 draws.

Nessa execução, a instrumentação confirmou cerca de **591 KB/quadro reutilizados**, contra 1,199 MB de dados únicos, com **0,0308 ms** de comparação. A fila ainda teve espera; três arenas não garantem eliminá-la em qualquer distribuição de trabalho. Não foi alegado ganho de FPS a partir dessa carga diferente.

O mesmo binário foi reaberto. A nova coleta exige **16 janelas consecutivas de 60 quadros**, com média de **220–260 draws/quadro** no conjunto, descartando o aquecimento. Não filtra por FPS. Resultado previsto: `build_test/restrict_heavy_new960.json`. Os nomes/evoluções e os inputs do combate precisam de confirmação física; não existe automação de botões. A redução de 4 ms ainda depende dessa medição comparável.
