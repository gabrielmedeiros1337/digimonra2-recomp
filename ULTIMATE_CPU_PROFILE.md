# Jungle Ruins: perfil exclusivo de CPU e HLE

Amostragem de8 segundos,4.985 amostras totais,3.382 no estagio GAME. Leitura do PC e da zona QPC enquanto a thread principal estava suspensa; retomada garantida antes da simbolizacao. As porcentagens abaixo sao amostras do estagio, nao tempos exclusivos medidos por funcao. Entradas inferidas por destinos BL/ponteiros da DOL; instrucoes iniciais verificadas no arquivo local, nao nomes SDK presumidos.

| Entrada guest | Amostras | Parcela GAME |
|---|---:|---:|
| `sub_8024C47C` | 122 | 3.61% |
| `sub_8023DF34` | 89 | 2.63% |
| `sub_80278E10` | 85 | 2.51% |
| `sub_8024BB18` | 80 | 2.37% |
| `sub_801C64A8` | 74 | 2.19% |
| `sub_80278EF4` | 69 | 2.04% |
| `sub_8024D1EC` | 68 | 2.01% |
| `sub_8024B030` | 66 | 1.95% |
| `sub_8024C1B8` | 63 | 1.86% |
| `sub_801CBD10` | 63 | 1.86% |

0x8024C47C e reflexao/texgen com vertices e normais, ja parcialmente SIMD: acrescentadas entradas nativas intrachunk em C508/C518, que alcancam tambem a primeira iteracao. 0x8024BB18 e blend de skinning e0x8024C1B8 acumulacao, com nucleos nativos existentes. 0x80278E10/0x80278EF4 sao testes de planos contra AABB: novos HLEs SSE/FMA, incluindo continuacao apos prologo e preservacao CPU/RAM/downcount. 0x80275528 percorre uma estrutura de colisao com testes AABB e recursao. As outras entradas nao receberam nomes SDK sem verificacao. O perfil nao sustenta atribuir todos os20ms a PSMTXConcat/PSQUAT.

Validacao dos dois novos HLEs:1.920 comparacoes completas de CPU e RAM contra corpo original extraido para um oraculo de teste. Fast-float precisa estar ativo; referencia precisa preservada quando desligado. Entradas excepcionais/aliases de stack, limites e orcamento insuficiente fazem fallback. Nenhuma alteracao em recompiled_code/generated/.

Dirty tracking corrigido: geracoes atualizadas inline nas escritas escalares, primary RAM, PSQ, stores nativos e publicacoes DMA/DVD/GX. Chaves de cache leem geracoes em user-space. GetWriteWatch foi retirado do lookup; uma barreira de seguranca por host frame coleta escritas Windows e avanca paginas alteradas. Modificacoes por ponteiros externos nao gerenciados so sao observadas nessa barreira, nao no meio do quadro. Todos os escritores do runtime devem usar a marcacao antes do store.

A comparacao abaixo e ANTERIOR a essa correcao e aos novos HLEs, executavel D7581FF7...,mesma luta mas carga variavel (960frames por modo). Os modos sao fast-float/dirty-tracking. Nao usar esses valores como resultado do executavel final.

| Modo | Jogo ms | GX ms | Submit ms | EFB ms | Quadro ms |
|---|---:|---:|---:|---:|---:|
|00|16.794|3.606|2.228|0.120|22.871|
|01|17.937|4.711|2.321|0.124|25.216|
|10|14.130|3.384|2.030|0.119|19.787|
|11|14.609|4.452|2.073|0.122|21.392|

Artefatos: build_test/ultimate_game_staged_profile.json, ultimate_top_guest.json e ultimate_modes_before_hle.json. Binario/HLE e medicao apos a correcao serao registrados no manifesto da revisao.


## Diferencial fisico idle/acao, mesma revisao 4C8EAA86, modos11 fixos

Duas janelas QPC de360 quadros cada, sem compilacao/amostrador simultaneo. Amostragem posterior separada por estagio GAME; valores por funcao abaixo sao estimativas estatisticas, nao QPC individual.

| Etapa ms/quadro | Idle | Acao | Diferenca |
|---|---:|---:|---:|
| `cpu_game_logic_ms` | 11.3918 | 13.3585 | +1.9667 |
| `cpu_gx_decode_ms` | 3.0427 | 3.1502 | +0.1075 |
| `key_ms` | 0.4919 | 0.5116 | +0.0197 |
| `input_hash_ms` | 0.0499 | 0.0532 | +0.0034 |
| `input_lookup_ms` | 0.0785 | 0.0812 | +0.0028 |
| `decode_miss_ms` | 1.1218 | 1.1825 | +0.0607 |
| `worker_wait_ms` | 0.0004 | 0.0006 | +0.0002 |
| `gl_draw_submit_ms` | 1.8076 | 1.9264 | +0.1188 |
| `gl_efb_copy_ms` | 0.1151 | 0.1200 | +0.0049 |
| `frame_wall_ms` | 16.7466 | 18.7612 | +2.0146 |

Cache pre-decode: idle 123.00 hits / 15.00 misses por quadro; acao 124.07 / 21.44. Nao houve explosao de misses; incremento principal ocorreu em GAME.

| Entrada | Idle estimado ms | Acao estimado ms | Aumento ms |
|---|---:|---:|---:|
| `0x8023C690` | 0.0000 | 0.1975 | +0.1975 |
| `0x802023A4` | 0.0000 | 0.1876 | +0.1876 |
| `0x80276CC0` | 0.0527 | 0.1432 | +0.0905 |
| `0x80276E20` | 0.0615 | 0.1432 | +0.0817 |
| `0x80276D6C` | 0.0351 | 0.1086 | +0.0735 |
| `0x801E6434` | 0.0263 | 0.0938 | +0.0675 |
| `0x80244A74` | 0.0395 | 0.1037 | +0.0642 |
| `0x801C7AA4` | 0.0395 | 0.1037 | +0.0642 |
| `0x8023DF34` | 0.4565 | 0.5183 | +0.0618 |
| `0x8024F92C` | 0.0351 | 0.0889 | +0.0537 |

Chamadores verificados:80278E10 recebe chamadas de801CBD10,80275968 e80275D14;80278EF4 de801CBD10. AABB BVH80275528 e chamado pelo pai80275AD4 e recursivamente por si mesmo. Filho esquerdo+40, direito+44, volume+0..20, indicador interno assinado+24; ordem esquerda-direita. Traversal estimado0.2545ms idle e0.2270ms acao; nao cresceu nesta amostra. A implementacao completa de travessia permanece original, nao se alega HLE desse loop. Dispatcher original ja usa tabela direta O(1), sem busca linear; nao foi adicionado cache redundante.

Patch diferencial: HLE completo de expand-by-point80276CC0 e union80276D6C, incluidos caminhos intrachunk, stores ordenados para aliases, registros volateis/PS1,CR/FPSCR e downcount.2.560 comparacoes CPU/RAM contra corpos originais independentes; casos especiais/orcamento insuficiente fazem fallback. Mantidas1.920 comparacoes de planos/AABB. Nao se alterou generated/.

Cache: geracoes por bloco64B, atualizadas nos mesmos escritores escalares/PSQ/DMA. GetWriteWatch segue uma chamada por host frame; nas paginas retornadas compara linhas64B com shadow, invalidando apenas linhas cujos bytes mudaram. Assim escritas vizinhas na mesma pagina4KB nao invalidam a malha. Custo adicional: shadow24MiB + geracoes64B3MiB na RAM principal; conservador em escritas repetidas/retorno ao mesmo conteudo. Escritas externas nao marcadas continuam observadas na barreira seguinte. Cache mantem comparacao integral da assinatura apos hash; sem reutilizacao baseada somente em hash. Chave CP reduzida ao layout ativo, indices de matriz e arrays realmente consumidos; outros VATs/materiais nao invalidam vertices raw. Testes incluem escritas em outra linha da mesma pagina, barreira Windows, stores cruzando linha e alteracao de CP nao usado. Isso corrige false sharing por construcao, mas nao prova que ele era o gargalo principal no combate.

Artefatos: motion_idle_timing.json, motion_action_timing.json, motion_idle_profile.json, motion_action_profile.json, motion_profile_diff.json em build_test. Novo custo apos patch depende de uma nova janela fisica; nao substituir estes numeros por previsoes nem usar periodos com compilador ativo.

VBO driver, snapshots proximos das janelas QPC (emissao independente): idle49.818draws/42.959hits/0uploads; acao54.552draws/43.904hits/29uploads. Nao interpretar como taxas exatamente alinhadas aos360quadros. Artefato motion_vbo_counts.json. GAME inclui preparacao de comandos graficos fora do decoder GX; nao e uma medida isolada de fisica/IA.
