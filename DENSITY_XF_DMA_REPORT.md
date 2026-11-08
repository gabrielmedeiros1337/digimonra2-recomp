# Densidade dos chunks, XF e DMA - 2026-11-07

## Tamanho medido, sem atribuir cache misses por suposicao

| Variante | .text MiB |
|---|---:|
| Recuperacao O2/LTCG (7C6BD836) | 150.8171 |
| O1 sem GL, helpers forceinline | 152.9048 |
| O1 sem GL, helpers maiores compartilhados (final) | 148.9282 |

A variante final reduziu cerca de1,25%, nao uma reducao drastica. O1 sozinho aumentou o tamanho. QPC mede duracao, nao instruction-cache misses. Nenhuma coleta PMU foi feita; o tamanho total de .text nao e a medida do working set quente. Nao foi comprovado que os ~4ms restantes sao I-cache thrashing.

Inspecao: os185 chunks contem713.737 atribuicoes dePC,170.175 descontos de budget,75.298 guardas deFPU e245.632 acessos32-bit deRAM. Mapas de uma variante intermediaria atribuem aproximadamente148,24MiB aos corpos func_* e1,01MiB aos loop_* (intervalos aproximados entre simbolos, incluem alinhamento). A expansao predominante esta nos corpos dos chunks/despachantes com estado observavel por instrucao, nao em213 prologos pequenos. Helpers matematicos compartilhados nao removeram essa estrutura.

CMake configura todos os185 arquivos com /O1 /Oi /Os /fp:fast /arch:AVX2 /GF; objetos convencionais fora deLTCG. Core/runtime/GX/HLE mantem /O2 /Ot eLTCG. Sem /GL e /GL- contraditorios no mesmo comando. Confirmado em density_chunk_flags.json, incluindo os chunks de adapters. DIGIMON_DENSE_CHUNKS=OFF permite comparar a politica compacta comO2, mantendo os mesmos HLEs. PGO permaneceOFF. Nenhuma edicao em recompiled_code/generated.

## HLE XF 802D4EBC

sdk_transfers.c substitui o emissor inteiro para matrizes8/12 words, preservando destinoXF, cabecalho, CR, GPR, FPR/PS1, PC/LR e budget. Matrizes normais/zero emRAM ouLC sao aceitas; alinhamento, GQR eFPU sao verificados; casos fora do dominio executam o original.

gx_pipe_write_fifo_bytes compartilha o transporte escalar existente. Cabeçalho5bytes e payload32/48bytes entram em duas chamadas, em vez de10/14 callbacksMMIO. Mantem linhas gather32B, wrap, ponteirosPI/CP e ordenacao; nao escreve XF diretamente por fora do FIFO. A matriz e lida depois da emissao do cabecalho, como noSDK. Adapter em4F14/4F4C cobre tambem chamadas internas no chunkSDK, cujo cabecalho ja foi emitido. Testes incluem128 combinacoes de prefixo/alinhamento de gather e wrap do ring.

## Skinning e locked cache sob8024B030

| Rota | Implementacao |
|---|---|
| 8024BF84 /8024C014 | Transformacao rigida ja nativa SSE/FMA, com entrada e loop. Preservada. |
| 8024BB18 /8024BC48 | Blend de duas matrizes ja nativo SSE/FMA. Preservado. |
| 8024C1B8 /8024C244 | Acumulacao ponderada nativa no loop. Preservada. |
| Quantizacao S16/U8 | Conversao/saturacao/pack nativos dos kernels, com GQR e ordem de arredondamento preservados. |
| 802BF5DC /802BF600 | Novo HLE das folhas de transferencia load/store em blocos. |
| mtdmau/mtdmal | Novo atalho no fallback superior5E8/60C evita dois retornos ao host por transferencia na rota interna real. |
| Backend LC | memcpy em blocos ja nativo, wrap de16KiB e bloco0=128 preservados. |

Os wrappers maiores802BF704/802BF7B0 ainda fazem orquestracao guest; nao foram apresentados como HLE completo. Tambem nao houve nova substituicao inteira de8024B030. Os testes comparam o fluxo antigo com seus fallbacks: o budget recompilado cobra7 unidades por folha, nao9; o HLE preserva exatamente7, ou4 restantes na continuacao.

## Callbacks do scheduler

Papeis inferidos do fluxo e dos campos; nomes originais de classes nao disponiveis. O perfil usado e o anterior async_combat_cpu_profile.json. Amostragem mostra tempo, nao numero exato de chamadas. Enderecos de entrada sao inferidos e inclusivos sao parciais/ sobrepostos. Detalhes e call-sites: density_callback_families.json e callback_*.asm.

| Callback | Fluxo observado | Folhas/familias relevantes |
|---|---|---|
| 8016BB30 (2,529ms inclusivos) | Atualizacao de acoes/estado do ator, metodos virtuais e movimento/colisao. Ramo800E041C responde por~1,648ms observados. | 8024D1EC~0,353ms proprios,80275528~0,207ms,BVH/testes geometricos8027F624~0,122ms,80276E20~0,067ms; matriz802B54EC e transformacao8028BEDC aparecem na arvore. |
| 80183A7C (2,073ms inclusivos) | Atualizacao comum do personagem, passando por800DDE74 (~1,854ms) e pose/animacao. | 801C64A8~0,432ms proprios,80252488~0,225ms,80283A70~0,188ms,801C70AC e802841B0~0,122ms cada;8028433C e8028B888 tambem aparecem. |
| 801D29A0 (1,429ms inclusivos) | Atualiza objeto conforme flags, chama801D23E4 e801E7C5C. Este chama801E6434 e reinsere o objeto no bucket temporal do scheduler. | 801E6434~0,195ms proprios,8024EC38/8024F92C~0,097ms cada,8024F634~0,073ms; concat802B4D08~0,067ms. |

Nao converter esses callbacks inteiros por nome presumido: o primeiro inclui estado de combate e callbacks virtuais; o segundo mistura tracks e quaternions; o terceiro processa parametros/objetos e reagendamento. Nenhum desses tres recebeu HLE generico nesta revisao.

## Validacao e proxima medicao

5.120 comparacoes independentes completas deCPU/FIFO/RAM/LC, incluindo matrizes8/12, IDs, continuacoes carregadas, wrapLC e zero=128 blocos; mais recusas sem mutacao para desalinhamento, FPU/GQR invalido eNaN. Suite de helpers compartilhados compara strict/fast, FPSCR e caminhos especiais. Software eOpenGL passaram; CTest14/14 aprovado. Replay17 lotes preservou SHA2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79.

Release `FE5B8A8156A6568CE4F271E361F4D4B4710AABB2ED6A129BBB3E6652602DF001`; build final0 sem warnings; inventario213 objetos (185COFF +28GL),8.155 nomes no mapa ligado. Imports semPGORT/GetWriteWatch. Manifesto density_manifest.json.

A ultima janela disponivel da recuperacao tem960 quadros: GAME15,7354ms, GX3,7718ms, submit2,3369ms, EFB0,1253ms, wall22,1094ms. Modelos/evolucoes nao sao identificados pelo log. **Ainda nao existem tempos/FPS de combate deste novo binario.** A proxima captura exige os botoes fisicos do usuario; medir960 quadros sem compilacao/sampler ativo e depois verificar os novos contadoresXF/LC. As variantes nao estabelecem ganho causal de cache sem medida equivalente.
