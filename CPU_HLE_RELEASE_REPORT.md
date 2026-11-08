# CPU HLE e Release - 2026-11-07

## Escopo e configuracao

`async_decode=0` e `immutable_images=0` nos defaults de gx_pipe.c, no carregador de configuracao e em build_test/runtime_tuning.cfg. Nenhuma alteracao em gx_decode_async.c, gx_images.c ou TLUT nesta revisao. Cache de vertices/texturas e copias VRAM existentes preservados.

## Top 20 da captura de CPU disponivel

Fonte: build_test/async_combat_cpu_profile.json, consolidado em async_combat_cpu_totals.json. 2.811 amostras GAME; media QPC GAME de 17,0918 ms da janela associada. Este valor pertence a essa captura, nao a nova revisao. O relatorio historico CPU_TOTAL_FIFO_REPORT.md usa outra captura, de 14,9380 ms. Tempos por funcao sao estimativas amostrais; inclusivos sao parciais por PC/LR/backchain e se sobrepoem. Nao somar inclusivos. Nomes SDK nao foram presumidos.

| Guest | Exclusivo ms | % GAME | Inclusivo parcial ms |
|---|---:|---:|---:|
| sub_8024C47C | 0.6506 | 3.81% | 0.6506 |
| sub_8023DF34 | 0.5716 | 3.34% | 1.5626 |
| sub_801C64A8 | 0.4317 | 2.53% | 1.7390 |
| sub_8024D1EC | 0.4013 | 2.35% | 0.9120 |
| sub_8024B030 | 0.3587 | 2.10% | 1.7025 |
| sub_8024C1B8 | 0.3527 | 2.06% | 0.3527 |
| sub_8024A088 | 0.3405 | 1.99% | 0.4439 |
| sub_8024BB18 | 0.3162 | 1.85% | 0.3162 |
| sub_801CBD10 | 0.2736 | 1.60% | 1.1674 |
| sub_8023DA04 | 0.2615 | 1.53% | 0.6567 |
| sub_80275528 | 0.2432 | 1.42% | 0.2675 |
| sub_802B4D08 | 0.2432 | 1.42% | 0.2432 |
| sub_80252488 | 0.2250 | 1.32% | 0.2250 |
| sub_8024BF84 | 0.2189 | 1.28% | 0.2189 |
| sub_801E6434 | 0.2067 | 1.21% | 1.2282 |
| sub_80276E20 | 0.2007 | 1.17% | 0.2189 |
| sub_80283A70 | 0.2007 | 1.17% | 0.2007 |
| sub_802AF56C | 0.1824 | 1.07% | 0.1824 |
| sub_802BF5DC | 0.1702 | 1.00% | 0.1702 |
| sub_80287610 | 0.1581 | 0.92% | 7.7038 |

## Mudancas de CPU

- **0x80283A70**: HLE completo da composicao de quaternions. Carrega os dois operandos uma vez, usa FMA nativo, preserva ordem de arredondamento/store e todos os FPR/PS1 volateis, GPR9, PC e budget. Entradas e saidas sobrepostas suportadas. Hook de dispatcher e guarda FPU intrachunk evitam perder a cobertura em chamadas locais.
- **0x80252488**: HLE dos loops de canais de animacao, nao da funcao inteira. Intercepta 0x802524E4 (canais constantes), 0x80252848 (interpolados) e 0x802528CC (constantes entre canais mistos). Converte S16 diretamente, calcula interpolacao com a mesma ordem FMA, agrupa componentes ate o limite de budget e preserva escritas no scratch da stack, registradores e CR/XER. Busca de keyframes e prologo/epilogo continuam no guest. Sao rotas de animacao da CPU, nao decodificacao GX.
- **0x8024C47C**, HLE de reflexao ja existente: em fast-float elimina classificacao de resultados intermediarios repetida em cada operacao SIMD. Mantem validacao de entrada, comprimentos positivos, a estimativa rsqrt Gekko e validacao de saida antes do commit. Modo estrito mantem as verificacoes originais. Nao substitui rsqrt por aproximacao arbitraria da GPU.
- **primary_ram.h**: acesso inline limitado a RAM principal cached tambem para 8/16 bits; byteswap intrinseco para 16 bits. MMIO/aliases/fronteiras/reservas/journal mantem o runtime. Dirty tracking continua por pagina de 4 KB.
- **CMakeLists.txt**: todos os 185 chunks recebem /O2 /Ob3 /Oi /Ot /GL /arch:AVX2 /fp:fast. IPO/LTCG Release ativo. Runtime e oraculos independentes mantem o contrato de float preciso; fast-float aritmetico segue opt-in efetivo no combate conforme configuracao existente.

Nao houve conversao completa das Top 5. As rotinas 0x8023DF34 e 0x8024D1EC incluem respectivamente configuracao de materiais/chamadas GX e consultas de colisao, e nao podem ser substituidas por uma multiplicacao de matriz generica. O patch acima cobre tres rotinas do Top 20, com os limites descritos; nao atribui a elas os 13-17 ms totais nem promete remover 3,5 ms sem medir.

## Validacao

8.704 comparacoes completas contra trechos originais independentes: quaternion com aliases, canais constantes/interpolados/mistos, budgets exauridos e continuacoes. 4.060 casos de memoria incluindo 8/16/32 bits, aliases, fronteiras, MMIO, reservas e journal. Regressao de reflexao tambem sera executada em fast-float e em modo estrito.

Release final SHA-256 `7E59D3F17B482214464378EC5D633CDF5CFDB408B4FF0675F2E1EF2C0809D74C`; mapa `build_test/cpu_hle_active.map`. Build completo e link corrigido com saida 0 e zero warnings. CTest **14/14** aprovado. Software e OpenGL aprovados, incluindo 1.728 casos de reflexao estrita e outros 1.728 em fast-float. Inventario: 216 objetos /GL e 11.731 simbolos no mapa ligado; imports sem runtime de instrumentacao PGI. Manifesto: build_test/cpu_hle_manifest.json.

A primeira verificacao adicional de reflexao fast-float detectou diferenca de arredondamento: o HLE mantinha o multiplicador de rsqrt de 25 bits do modo estrito, enquanto o runtime fast-float estreita primeiro esse multiplicador a binary32. Corrigido no HLE, mantendo a tabela Gekko e a semantica correspondente a cada modo. A segunda execucao completa passou; o binario que falhou nao foi promovido.

**Ainda nao ha novos milissegundos de combate.** A medicao depende da luta com input fisico neste binario. Valores da tabela sao do perfil anterior; nao foram apresentados como resultado do patch. Nenhuma garantia de 60 FPS ou reducao de 3,5 ms sem essa captura.
