# Recuperacao e anatomia da CPU - 2026-11-07

## Recuperacao aplicada antes de qualquer novo HLE

- native_animation.c/.h, cpu_animation_adapter.h e seus testes retirados da arvore ativa; copia em patches/cpu_recovery_7e59. CMake/dispatcher e hooks intrachunk correspondentes removidos.
- Hooks de AABB/planos removidos do dispatcher e dos chunks; sdk_bounds.c nao integra o executavel. Contratos isolados permanecem como referencia, sem custo em producao.
- primary_ram.h voltou aos acessos compactos de 32 bits. Store cached bounded = byteswap + memcpy de 4 bytes (MSVC gera store direto); nenhuma chamada a tracking. Memoria fora da RAM principal, reserva e journal preservam o runtime correto.
- DOLRECOMP_RAM_TRACKING=0 em toda a producao: scalar/PSQ/DMA/HLE compilam ppc_mark_host_write como vazio; RAM usa calloc sem MEM_WRITE_WATCH; nao ha GetWriteWatch ou ResetWriteWatch nos imports. Config dirty_tracking=0, async_decode=0, immutable_images=0.
- gx_pipe.c nao contem mais filas/snapshots GX nem snapshots/versionamento de imagens. Modulos gx_decode_async.c e gx_images.c desvinculados da producao. APIs diagnosticas retornam zeros e nao podem reativar esses modos. Removidos loops de release draw x 8, memcmp de imagens durante merge, selecao de overrides e captura de recursos. TLUT mantem sua barreira sincrona correta.
- Cache pre-decode usa assinatura dos comandos/layout/arrays consumidos e hash XXH64, com verificacao da assinatura nos hits; nao consulta geracoes/paginas. Cache VBO, XFB em VRAM e I4 64x64 em VRAM preservados.
- Chunks retornaram ao /O2 com inlining padrao compacto; retirada a expansao /Ob3 e /fp:fast global da rodada regressiva. PGO OFF nesta recuperacao, mantendo LTCG, para nao reutilizar o perfil anterior sobre a nova disposicao do codigo. Nenhuma coleta PGI.
- Correcao numerica de reflexao preservada: fast-float estreita o multiplicador rsqrt como o runtime; verificacoes conservadoras do kernel anterior restauradas. Isto evita restaurar uma divergencia numerica encontrada nos testes.

## Evidencia de validacao

SHA-256 `7C6BD836FD71E75BECCB170503C7F769C29146472CD5E763DE8B38C4A17A2E46`. Build final com saida 0, sem warnings; CTest13/13; software/OpenGL passaram. Replay de 17 lotes preservou SHA `2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`. Inventario: 212 objetos /GL e 11.475 simbolos no mapa ligado. Secao .text: 186.94 MiB na rodada anterior, 150.82 MiB nesta recuperacao. Esta reducao mede tamanho, nao prova a causa do FPS.

**Recuperacao de 60 FPS na selecao / ~50 FPS na luta ainda pendente de teste fisico.** O build foi reaberto sem input automatico. Nao apresentar tempos historicos como medicao desse executavel.

## Anatomia das quatro familias (nenhum HLE novo aplicado)

Desmontagem da main.dol e comentarios de instrucoes nos chunks gerados. Listagens em build_test/recovery_*.asm; call-sites em recovery_family_calls.json. Limites inferidos por entradas/prologos; inclusive do sampler e parcial, nao um contador exato de chamadas.

| Raiz | Proprio ms | Inclusivo ms | Comportamento observado |
|---|---:|---:|---|
| 80287610 | 0.1581 | 7.7038 | Scheduler de tarefas/callbacks do motor: roda ate o tick alvo, listas intrusivas, 64 buckets temporais e 32 filas de prioridade; ordena por chave quando necessario. |
| 801C64A8 | 0.4317 | 1.7390 | Atualizacao/blend da pose: tres tracks de 0x44 bytes, scratch de 0x60 bytes por elemento, canais compactados, normalizacao/orientacao e atualizacao dos registros associados. |
| 8024B030 | 0.3587 | 1.7025 | Coordenador de skinning: escolhe quantizacao GQR, transfere buffers para locked cache, copia matrizes, alterna buffers e chama transformacao rigida/blend/acumulacao. |
| 8023DF34 | 0.5716 | 1.5626 | Preparacao de materiais/estado GX: cores e parametros de iluminacao/TEV, comparacao com estado anterior, conversoes de cor, matrizes e chamadas SDK de configuracao/submissao. |

### 80287610: onde estao os 7,70 ms

Incrementa tick em ctx+4 e processa ate r4; usa buckets em ctx+0x324 e listas por prioridade em ctx+0x24. Ordenacao 802874E4 e merge-sort de listas. Em 80287820 faz blrl para o metodo associado ao no, com ajuste assinado de this; callbacks opcionais em ctx+0x10 e ctx+0x0C sao chamados em 80287764/80287834. Nao ha espera de host, VIWaitForRetrace ou leitura de timer de hardware nessa raiz. O loop por ticks nao e uma espera por VBlank.

No perfil anterior, ramos imediatamente abaixo da raiz (agrupados por entrada inferida):

| Callback/ramo | Inclusivo observado ms |
|---|---:|
| 8016BB30 | 2.5294 |
| 80183A7C | 2.0734 |
| 801D29A0 | 1.4289 |
| 8005C198 | 0.5472 |
| 801F6460 | 0.2736 |
| 8009953C | 0.2371 |
| Scheduler propriamente dito | 0.1581 |

As tres primeiras familias concentram 6,03 ms dos callbacks observados. Trocar apenas o scheduler por C nao elimina esse trabalho. Os dois primeiros callbacks consultam objetos de jogo e chamam varios metodos; 801D29A0 consulta flags e chama 801D23E4/801E7C5C. Precisam ser perfilados por comportamento antes de receber nomes de sistema mais especificos.

### 801C64A8: pose, nao um simples envio GX

801C6544 chama 801C70AC para atualizar tracks; 801C66A4 reserva scratch via 80287D94; 801C6870 avalia canal com 80252488; ha loops por elementos com strides 0x60/0xC0 e normalizacao de quatro componentes via frsqrte. 801C6C80 chama 8028433C; 801C6EC8 chama 801C6F28, que percorre registros, flags e dados associados antes de chamar 8024CCB4. Ramos observados: 8028433C~0,4803 ms, 801C6F28~0,4378 ms, 801C70AC~0,2007 ms e 80252488~0,1885 ms. Estes numeros sao inclusivos parciais.

Nao agrupar 801CBD10 ou 801E6434 sob essa raiz so porque os enderecos sao proximos. O call-graph observado acima deve determinar a relacao.

### 8024B030: locked cache e skinning

8024B07C chama 8024B00C, que configura GQR7 (mtspr0x397). 802BF704/802BF5DC enviam DMA para locked cache; 802BF600 faz a direcao inversa; 802BF868 verifica a fila DMA no SPR0x398. Ja ha HLE de DMA em blocos. A funcao alterna buffers, copia matrizes de48 bytes e chama 8024BF84 (rigido), 8024BB18 (blend) e 8024C1B8 (acumulacao), alem dos respectivos preparadores.

**Nao e um loop de GXBegin/GXEnd nem escreve diretamente 0xCC008000.** O custo inclusivo abrange os kernels de skinning ja nativos e DMA. Uma futura substituicao inteira precisa reproduzir GQR, buffers RAM/LC, quantizacao, ordenacao e efeitos visiveis ao guest; nao pode virar apenas glDraw*. A funcao cruza a fronteira entre os chunks 802474C0 e 8024B4C0.

### 8023DF34: estado/material e matrizes GX

Funcao extensa (~3.150 instrucoes no intervalo observado), cruza 8023B4C0/8023F4C0. 8023DFBC chama 8024A088 para calcular parametros; diversas chamadas SDK configuram cores, TEV e estado, usando comparacoes para evitar reenviar valores iguais. Converte canais de cor com floor, concatena matrizes via 802B4D08 e carrega matrizes com 802D4EBC.

O envio ao FIFO e confirmado nos descendentes: 802D4EF8 carrega 0xCC010000, e os stores em -0x8000 (802D4EFC/802D4F08) escrevem 0xCC008000, emitindo opcode XF0x10 e cabecalho. **A raiz participa da preparacao/submissao GX, mas nao e um mero empacotador de vertices**. Preservar cache guest de estado e side effects e obrigatorio em um HLE completo. 8023DA04 e outra rotina de composicao/preparacao de matrizes, nao deve ter seu inclusivo somado automaticamente ao dessa raiz.

## Proxima comparacao

Manter esta configuracao fixa. Primeiro quatro modelos na selecao; depois quatro humanos em Jungle Ruins. Capturar QPC sem compilador/sampler concorrente e so depois amostrar os callbacks mais caros. Nenhum HLE de alto nivel sera aplicado antes de confirmar a base e apresentar esta anatomia.
