> Revisao atual: E40C97E8, restrict/PC-RAM e tres arenas. Veja [RESTRICT_ARENA_REPORT.md](RESTRICT_ARENA_REPORT.md). Os numeros abaixo documentam a revisao anterior 9D83426.

# Pipeline GX bruto, PE assíncrono e remoção de PC redundante

Esta revisão substitui o pipeline anterior. Executável: `9D83426EB63791C03A5F367D0A11FA18E0FBB01AF2F28E5AECAFD212BAE7AFDF`. Mapa correspondente: `build_test/raw_backend_active.map`. O relatório anterior está preservado em `patches/pre_raw_backend/FRAME_PIPELINE_REPORT.md`.

## Medição da luta anterior

Foram lidas as últimas 16 janelas completas (960 quadros, scene=4), sem executar compilação ou amostrador durante aquela coleta. Dados preservados em `build_test/frame_pipeline_before_raw.json` e `build_test/runtime_before_raw_backend.log`.

| Medida | Média por quadro | Intervalo das janelas |
|---|---:|---:|
| CPU: lógica do jogo | 15,0652 ms | 8,9598–17,4852 ms |
| CPU: categoria GX, incluindo captura e espera | 6,8825 ms | 4,8956–8,0393 ms |
| Espera total do produtor | 2,8194 ms | 2,1383–3,3224 ms |
| Backend: desenho | 2,9937 ms | 2,1612–3,6030 ms |
| Backend: cópias EFB/XFB | 0,1653 ms | 0,1578–0,1727 ms |
| Backend: swap | 0,0720 ms | 0,0651–0,0811 ms |
| Backend: trabalho total | 3,2681 ms | 2,4292–3,8664 ms |
| Parede do quadro | 22,2288 ms | 16,8594–25,7358 ms |

O cache pré-decode teve 100,048 hits e 23,793 misses por quadro; o hash de entrada custou 0,0875 ms e os misses 1,6196 ms. A categoria GX da CPU não era apenas o decode: incluía empacotamento e espera. O log antigo não registrou quantidade nem causa das barreiras; não é possível extrair uma contagem retrospectiva exata. `packets` não é uma contagem de barreiras. Tempos simultâneos do backend não devem ser somados à timeline exclusiva da CPU.

## Alterações implementadas

**PE Finish/Token:** os registros BP 0x45/0x48 publicam os comandos capturados por `frame_queue_pe()`/`gx_frame_submit_pe()` e sinalizam a conclusão ao guest depois dessa entrega, sem aguardar a execução GL. Nesse modo a conclusão PE significa entrega à fila, conforme solicitado; não é uma fence de término físico da GPU. Falha na entrega não sinaliza sucesso. Readbacks que realmente escrevem na RAM guest continuam sendo concluídos antes de liberar o chamador.

**GXCopyTex/GXCopyDisp em VRAM:** a primeira alocação elegível I4 64×64 também é enfileirada sem drain. XFB elegível segue a mesma regra. O frontend registra os handles e o consumidor cria/atualiza as texturas na ordem dos comandos. Capacidade/alias incompatível ou cópia que exige resultado em RAM usa o caminho com sincronização. Uma falha do backend não é disfarçada como cópia GPU bem-sucedida.

**Decode no backend:** a CPU guest captura layout, FIFO bruto, CP/XF/material, arredondamento e os intervalos de arrays/texturas/paletas usados. `FRAME_RAW` transfere a conversão de atributos, byte-swapping, lookup/hash do cache pré-decode, espera dos auxiliares de vértices e preparação de geometria para a thread principal/OpenGL. O fallback de XF em software também é executado nessa thread, usando um ambiente privado, com matrizes e normalização isoladas dos registros que a CPU continua atualizando. O parser de pacotes e a captura dos bytes permanecem no frontend CPU; não se promete custo GX literalmente zero nessa thread.

O contexto SDL/OpenGL permanece na thread principal, conforme exigência do SDL2 deste projeto. Não há restauração temporária dos CP/XF globais durante a execução concorrente. A conversão usa os mesmos algoritmos da rota anterior, com uma visão explícita dos dados capturados. Caches pré-decode e VBO continuam ativos. Não foram reativados `gx_decode_async`, `gx_images`, dirty tracking ou GetWriteWatch, nem adicionados novos HLEs de funções guest.

**Limite de quadros:** duas arenas reutilizáveis, de até 64 MiB cada, impõem contrapressão por capacidade. Um crédito separado permite CPU N+1 durante render N, mas impede CPU N+2 de ultrapassar a apresentação N. PE/I4 não geram drains; fila cheia ainda pode exigir espera, que é medida separadamente.

**PC DSE:** `tools/pc_dead_stores.py` gera cópias em `build_test/pc_compact_chunks/`; os 185 arquivos originais permanecem intactos. Foram removidas **237,681** escritas dentre 640.618 stores constantes candidatos, em um total original de 713.737 atribuições de PC. A transformação mantém labels e instruções; só remove um store quando outro store incondicional domina sua continuação sem leitura observável de PC. Memória/MMIO, aliases, chamadas desconhecidas e saídas são conservadas. A guarda FPU pode ser atravessada apenas quando usa CIA explícita e sobrescreve PC no caminho de exceção. Pontos dos adaptadores são protegidos e suas alterações invalidam a geração. SHA256 dos inputs/outputs e decisões constam em `pc_dse_audit.json`.

A opção CMake `DIGIMON_PC_DSE=ON` é o padrão. Continuam `/O2`/LTCG e PGO OFF. Não foram removidas guardas de FPU indiscriminadamente, nem mudadas as regras de propriedade/restauração da FPU.

## Contadores da nova execução

`[Render sync60]` informa:

- `backend_decode_ms`: conversão/cache/auxiliares no consumidor;
- `barrier_wait_ms`, `barriers_per_frame`, `blocked_barriers_per_frame`: drains explícitos;
- `queue_wait_ms`, `queue_blocks_per_frame`: contrapressão das arenas;
- `pe_submits_per_frame`: entregas PE sem espera de conclusão;
- `raw_draws_per_frame`, `raw_vertices_per_frame`, `captured_bytes_per_frame`: uso real da rota;
- `ram_copies_per_frame`: cópias que exigiram RAM guest.

`[Render credits]` expõe quadros entregues/apresentados e o tempo acumulado de espera pelo limite de um quadro anterior. `[Frame60]` mantém o tempo de parede real; zeros GL na timeline CPU não são apresentados como trabalho GL eliminado. `tools/capture_frame60.py` inclui os novos tempos no JSON de coleta.

## Evidências de validação

- CMake/MSVC Release: saída 0, sem warnings; CTest **16/16**.
- PC DSE: **142.080** comparações de estado completo em **555** trechos reais, incluindo FPSCR, PC, exceção FPU e modos de arredondamento.
- Transporte: ordem/imutabilidade/contrapressão, prova de progresso da CPU durante o callback consumidor, PE sem drain e crédito de um quadro.
- GX: **7.200** vértices raw/CPU-XF, direct/index8/index16/NBT, quatro modos de arredondamento e FIFO com wrap, após sobrescrever RAM/CP/XF/FIFO.
- Capturas reais: **447 + 594 = 1.041** vértices idênticos nos caminhos raw e CPU-XF após sobrescrita completa da RAM/FIFO/CP/XF. Testes também zeraram a RAM sombra para comprovar que os pacotes fornecem os bytes necessários.
- I4/XFB: alocação e reutilização sem drain, RAM guest intacta no fast path, imagens ordenadas e materialização explícita posterior corretas.
- Replay de 17 lotes: bitmap idêntico, SHA256 `2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.
- Inventário: **214 objetos LTCG**, **11.636 nomes** no mapa final; objetos LTCG não expõem uma tabela COFF legível ao dumpbin.
- `.text`: **150,8316 → 146.3128 MiB**. Isso não demonstra sozinho ganho de I-cache ou 20–30% de desempenho.

## Medições novas em combate

Duas capturas completas de 960 quadros foram concluídas no Release acima, sem compilação ou profiler ativo. A quantidade de draws cresceu de 128,389 para 239,517 por quadro entre a primeira e a mais recente. Os nomes/evoluções não são registrados; esta comparação de janelas não constitui A/B controlado de personagens idênticos.

| Medida por quadro | Execução anterior | Primeiros 960 novos | 960 novos mais recentes |
|---|---:|---:|---:|
| Lógica CPU | 15,0652 ms | 12,9430 ms | 17,1002 ms |
| GX na CPU: captura/parser/espera | 6,8825 ms | 1,5949 ms | 1,8784 ms |
| Espera total do produtor | 2,8194 ms | 0,7646 ms | 0,7494 ms |
| Espera por barreira explícita | Não separada | **0,0000 ms** | **0,0000 ms** |
| Decode no backend | Não separado | 3,6803 ms | 3,9018 ms |
| Desenho no backend | 2,9937 ms | 3,2788 ms | 4,6526 ms |
| Cópias no backend | 0,1653 ms | 0,1382 ms | 0,1331 ms |
| Parede do quadro, com pacing | 22,2288 ms | **17,0094 ms** | **19,1276 ms** |

Ambas as capturas novas registraram **zero barreiras explícitas por quadro**, zero barreiras bloqueadas e zero cópias para RAM guest. A primeira registrou 1 entrega PE e 7,865 bloqueios curtos por capacidade da fila por quadro; a mais recente, 0,997 entrega PE e 7,640 bloqueios de fila. A espera agora é de contrapressão das arenas, não de DrawDone/I4. O crédito de quadros não acumulou espera na observação registrada.

As janelas da primeira captura ficaram entre 16,6655 e 18,4988 ms; as mais recentes, entre 17,5168 e 23,4123 ms. **Não são 60 FPS estáveis em toda a ação.** Na primeira, o backend trabalhou 7,2364 ms, enquanto a timeline CPU sem pacing somou aproximadamente 14,6485 ms: esses tempos já não se somam em série. O parser/captura custou cerca de 0,83 ms depois de descontar a espera de fila.

No trecho mais pesado, a lógica CPU média de **17,1002 ms** já excede o orçamento de 16,6667 ms. O patch implementou o desacoplamento e a DSE solicitados; não elimina esse custo restante da lógica do jogo. Nenhum HLE parcial adicional foi introduzido para contornar esse limite.

Dados completos: `build_test/raw_backend_combat_summary.json` e `build_test/raw_backend_combat_latest960.json`. O executável foi mantido aberto. A confirmação visual do usuário desta revisão permanece separada dos testes automatizados de vértices/imagem.
