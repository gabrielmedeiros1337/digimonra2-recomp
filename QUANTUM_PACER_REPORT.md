# Quantum e cadência sobre a base validada

Release SHA256: `5D655078C79CC8253C772C90E9C7F61346F3D763254098243551D594C9D54B55`.
Base anterior preservada: `build_test/pre_quantum_pacer.exe` / `.map`.
Log anterior preservado integralmente em `build_test/runtime_guest_budget_validated.log`;
resumo em `build_test/guest_budget_observed_summary.json`.

## Números efetivamente registrados antes do patch

Todos os máximos abaixo são **máximos de médias de janelas de 60 jobs**, não
picos individuais. A instrumentação anterior não gravava estes últimos.

| Métrica | Combate inteiro: 183 janelas | Últimos 960 jobs de combate |
|---|---:|---:|
| CPU lógica, média | 14,0923 ms | 14,5363 ms |
| CPU lógica, maior média de janela | 17,0172 ms | 16,1020 ms |
| Quadro total, média | 17,0525 ms | 17,0819 ms |
| Quadro total, maior média de janela | 19,0551 ms | 17,8103 ms |
| Pacer, média | 1,2442 ms | 0,8840 ms |
| Espera de fila, média (incluída no GX) | 0,8472 ms | 0,8135 ms |
| Saltos de idle | 40.418 | 3.727 |
| Jobs watchdog em janelas scene=4 | 0 | 0 |
| Quadros acima de 100 mil dispatches | 13 | 0 |

Os últimos 960 jobs concluíram 960 quadros, todos com XFB e espera de retrace.
Foram saltados 530.730.027 ticks TB de idle (3,882 saltos por quadro). O trabalho
sem pacer teve média 16,1979 ms e maior média de janela 17,7917 ms: há carga real
além de deriva da cadência. Não se pode atribuir cada mínima individual ao pacer
usando um log que só guarda médias.

O contador `[Progress]` dos últimos 16 relatórios de aproximadamente um segundo
indicou média 54.357,8 dispatches/quadro e máxima dessas médias de 63.449. Não há
como recuperar o pico individual de dispatches em combate desse formato antigo.
O campo `max_dispatches=2033225` é cumulativo desde o início e inclui uma
transição reportada em **scene=3**, com seis jobs watchdog e uma conclusão.
Não é o pico da luta nem significa 2 milhões de dispatches em um único job.
As janelas scene=4 não registraram watchdog de 300 mil posições; seis ocorrências
na transição foram continuadas sem criar VIs adicionais.

## Alterações mecânicas

`test_main.c` e `build_test/runtime_tuning.cfg` passam a usar quantum **4096**.
O downcount inicial é `4096 - 256 = 3840`; o limiar gerado é **-256**. Antes era
768 até -256, aproximadamente 1024 unidades de desconto, não 512. A nova faixa é
aproximadamente quatro vezes maior. Um retorno normal de função/dispatcher pode
acontecer antes do esgotamento; não se promete reduzir todos os retornos em 4x/8x.
TB, deadlines AI/DSP e intervalo VI nominal de 675.000 ticks não foram alterados.

A auditoria em `tools/pc_dead_stores.py` encontrou **13.772 guardas estruturadas
em backedges**, **zero em forward edges desse padrão** e **185 guardas de entrada**
nos chunks. Não existem descontos adjacentes incondicionais elegíveis para a
consolidação conservadora (zero). Labels podem ser entradas de dispatcher ou
saltos internos; seus descontos e safepoints foram preservados. A auditoria é
somente leitura: não altera os 185 arquivos gerados originais ou seus resultados
de transformação, nem introduz HLEs.

`frame_pacer_target` preserva a fase de 60 Hz para atrasos curtos. Um frame de
17,2 ms não desloca permanentemente a próxima referência; um frame seguinte de
15 ms pode recuperar o atraso. Acima de dois períodos de dívida, a referência é
reiniciada para evitar uma sequência longa de catch-up após loading/debugger.
Não há frame skip, VSync adicional ou mudança de ordem dos comandos.

As três arenas permanecem com os mesmos contratos. A execução registrou zero
`frame_limit_ms_total`; ampliar os créditos não trataria o custo observado. O
novo pacer absorve folga temporal disponível sem aumentar a latência da fila.

## Instrumentação e validação

`[Guest dispatch60]` agora registra soma, máximo e quantidade exata de quadros
concluídos na janela. `[Frame60]` acrescenta `cpu_game_logic_peak_ms` e
`frame_wall_peak_ms` de jobs individuais. `capture_frame60.py` agrega esses
contadores sem confundir máximo cumulativo com pico da janela.

Build CMake/MSVC Release saída 0, sem warnings (`build_quantum_pacer.log`).
CTest **18/18**, incluindo comparações CPU/RAM/locked cache nos quanta
64/256/1024/4096, relógios/DMA e contratos de pacer/continuação.
Replay de 17 lotes idêntico: SHA256
`2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.
Inventário: 216 objetos LTCG, 11.638 nomes no mapa; `.text` 142,202156 MiB.
PGO continua **OFF**; nenhum perfil antigo foi reutilizado.

Manifesto: `build_test/quantum_pacer_manifest.json`; mapa:
`build_test/quantum_pacer_active.map`. O executável foi aberto para input físico.
Os 57–59 FPS são o resultado confirmado pelo usuário na base anterior.

## Captura da nova execução, sem compilação ativa

`build_test/quantum_pacer_combat960.json`: 16 janelas consecutivas, 960 quadros,
scene=4, quantum4096 em todas. Não há filtro por FPS.

| Métrica | Valor novo |
|---|---:|
| CPU lógica média | 13,7982 ms |
| Maior média CPU de janela | 15,1446 ms |
| **Pico CPU individual** | **31,8066 ms** |
| Quadro total médio | 16,8132 ms |
| Maior média total de janela | 17,6677 ms |
| **Pico total individual** | **35,2788 ms** |
| Frontend GX médio, incluindo fila | 1,5953 ms |
| Fila média | 0,7853 ms |
| Backend médio, sobreposto | 6,0207 ms |
| Dispatches por quadro concluído, média exata | 41.693,74 |
| Dispatches por quadro concluído, pico exato | 56.349 |
| Idle jumps | 3.839 |
| Watchdogs | 0 |

Todos os 960 intervalos concluíram com XFB. A captura teve 98,746 draws/quadro,
contra 128,530 na janela antiga;
os nomes/evoluções dos quatro personagens não constam dos contadores. A diferença
de carga impede tratar a comparação com os últimos 960 quadros antigos como A/B
controlado. Os valores medidos são menores, mas não se atribui toda a diferença
ao quantum/pacer. Os picos individuais ainda ultrapassam o orçamento: **não há
60 FPS constantes confirmados**. QPC mede tempo decorrido, incluindo possíveis
preempções do host; sozinho não identifica a causa de cada pico como instruções
guest, I/O ou escalonamento Windows.
