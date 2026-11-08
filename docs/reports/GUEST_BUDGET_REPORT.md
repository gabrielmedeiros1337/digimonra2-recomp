# Execução guest, idle e fronteiras de quadro

Release: `973A8D367C9CDC85C57798369A62595637D525CAC82B1E99D35C6EFD37777F4E`.
Executável: `build_test/Release/digimon_test.exe`. Base preservada em
`build_test/pre_guest_budget.exe`, SHA256 `E40C97E8EC961AD3F6A2DDC39BBB99B7BA0615D1794CC493AFA28D8B08376E8D`.

## Funcionamento anterior confirmado

`cpu_frame.c` é o transporte de jobs para o worker; o orçamento efetivo está em
`run_guest_frame`, em `test_main.c`. A configuração usa quantum 1024. Cada
`platform_execute_cpu_slice` inicia downcount em `1024 - 256 = 768` e permite
continuações do código gerado até o limiar de -256. É uma unidade aproximada de
execução recompilada, não uma simulação ciclo a ciclo de uma CPU de 486 MHz.

Cada rodada tinha 100.000 posições de slice, avançando TB em 6/7 ticks,
totalizando 675.000 ticks a 40,5 MHz: 1/60 segundo. Não existia término antecipado
em GXCopyDisp/VIWaitForRetrace. Ao esgotar a rodada, o host apresentava e emitia
outro VI na rodada seguinte mesmo se o guest ainda estivesse preparando o quadro.
Os logs antigos não contavam separadamente esses casos; não demonstram que isso
era a causa dos FPS baixos.

O idle já tinha uma otimização: em `0x802C7A44`, sem threads prontas, pulava até
127 posições e avançava o relógio correspondente. Portanto não executava todas
as instruções do loop vazio, mas ainda percorria aproximadamente 781 pontos de
polling por rodada completamente ociosa. Não foi identificado um segundo loop
de orçamento em `cpu_frame.c`.

## Política implementada

O combate usa `GuestFrameBudget`, com **300.000 posições por job**, quantum
inalterado e **675.000 ticks TB nominais entre VIs**. O passo TB passa de 27/4
para 9/4 por posição: três vezes mais oportunidades de execução sem triplicar a
velocidade do áudio, os relógios do SDK ou o VBlank. Boot e menus preservam a
política recuperada anterior.

O limite de job agora é um watchdog de responsividade. Se o trabalho não terminou,
o próximo job continua CPU/PC/pilha no mesmo intervalo: não dispara outro VI,
não força a DefThread, não apresenta outro XFB e não paga outro limitador de
16,67 ms. Se o trabalho exceder inclusive o prazo nominal, TB continua avançando
para não travar polling de timers/dispositivos; o VI seguinte aguarda uma fronteira
segura. Isso evita transformar o esgotamento da cota em um quadro guest novo,
sem prometer que qualquer carga cabe em 16,67 ms de tempo real.

`GXCopyDisp` bem-sucedido incrementa um contador de submissão pertencente ao
produtor CPU. O contador de cópias efetivamente executadas no OpenGL permanece
separado, evitando tomar a latência da render thread como falta de quadro.
CopyDisp não altera artificialmente PC nem descarta a rotina que o chamou.

Quando o scheduler chega ao idle real (`0x802C7A44`, RunBits zero, EE ativo,
sem exceção/callback pendente), o host avança diretamente ao próximo evento de
hardware ou ao prazo VI. DMA de áudio, contador AI e mailbox DSP determinam o
próximo despertar. Alarmes OS e DVD pendente mantêm o limite conservador anterior
de polling de 864 ticks TB. O guest volta a executar se um evento acordar uma
thread. Não se pula o mixer guest para simplesmente emitir outro retrace.

No prazo VI, idle conclui o intervalo. Uma submissão XFB já concluída também
permite encerrar o intervalo em código foreground seguro, preservando o PC para
o próximo VI; não interrompe IRQ, callback HLE ou a thread de áudio conhecida.
Um intervalo ocioso sem XFB é contado separadamente como `empty`.

`VIWaitForRetrace` foi identificado em `0x802DDA7C`; chama OSSleepThread
`0x802C85EC` na fila r13-25188 e compara o contador r13-25196. Não se faz yield na
entrada dessa função: fazê-lo antes de capturar seu contador pode adicionar uma
espera por retrace extra. A detecção usa o estado real do scheduler e da fila.

## Arquivos e contadores

- `guest_frame.c/.h`: política pura de orçamento, relógio, conclusão e deadlines.
- `test_main.c`: integração no combate, continuação sem VI/pacing extra e contadores.
- `cpu_frame.c/.h`: cancelamento atômico para fechar a janela durante um job longo.
- `video_audio.c/.h`: cálculo do próximo evento sem executar OpenGL nem alterar input.
- `gx_pipe.c/.h`: contador de CopyDisp aceito pelo produtor.
- `hle_callbacks.c/.h`: consulta de callback ativo/pendente antes de saltar o idle.
- `guest_frame_tests.c`, `platform_tests.c`, CMake: contratos do orçamento e DMA real.
- `tools/capture_frame60.py`: anexa os novos contadores às janelas de captura.

`[Guest budget60]` registra quota, quantum, intervalos concluídos/submetidos/vazios,
jobs watchdog, intervalos acima de 100 mil dispatches, saltos/ticks de idle,
esperas de retrace, máximo de dispatches e estado pendente. `[Guest boundary60]`
separa conclusão no prazo com XFB de conclusão em idle. As janelas Frame60 ainda
representam jobs host; ao existir watchdog, seus números precisam ser lidos junto
dos intervalos guest concluídos, sem chamar cada job de frame exibido.

## Verificação e limites da conclusão

- O Release anterior foi reconstruído e confirmado concluído antes das mudanças.
- Novo build CMake/MSVC Release: saída 0, sem warnings (`build_guest_budget.log`).
- CTest **18/18**: `test_guest_budget_ctest.log`, incluindo quota tripla,
  continuação, distinção CopyDisp/idle, deadlines e DMA preservando comprimento
  ativo quando o próximo buffer é reprogramado.
- Replay de combate: 17 lotes, imagem idêntica à base, SHA256
  `2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.
- Inventário: 216 objetos, 11.637 nomes no mapa; `inventory_guest_budget.log`.
- `.text`: 142,200859 MiB; gerados originais, flags e HLEs anteriores preservados.
- Manifesto/mapa: `build_test/guest_budget_manifest.json`, `guest_budget_active.map`.

O executável foi aberto com input exclusivamente físico. A medição comparável
de 960 quadros com quatro evoluídos ainda depende da luta nesta nova instância.
Não há confirmação de 60 FPS nem prova de que a cota antiga era o gargalo até
ler `over_base`, watchdogs e os novos tempos dessa execução.
