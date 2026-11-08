# Chunks planos, unidades de otimização menores e pilha verificada

Release SHA256: `ECEA9F470B2AFFE7B207C80899CDEBC74DA7040F8B19A87757148C9A5B2C9959`.
Executável: `build_test/Release/digimon_test.exe`. Base anterior preservada em
`build_test/pre_stack_flat.exe` / `.map`, SHA256
`D5797F407BDC4746D28F5A1724FD8E60A497AA631B6199D1D75D16B0F8E814C9`.

## Causa e evidência

Não havia um array local de165KiB no código gerado. O listing de
`func_802B34C0` confirmou `mov eax,168968; call __chkstk; sub rsp,rax` e milhares
de slots separados para `value`, `wide`, `v`, `charge`, `ea` e temporários internos
`tv...`. Havia2414 declarações u32 e647 f64 no fonte desse chunk, além das
expansões dos helpers inline. O comando efetivo do compilador tinha `/O2`.
Mesmo assim o corpo mantinha `ctx`, endereços intermediários e valores simples
na pilha, sem a reutilização/otimização esperada num corpo pequeno.

Listings preservados: `build_test/chunk_stack_baseline.asm` e
`chunk_stack_outline.asm`. O experimento de retirar os helpers hot-float da
linha reduziu o frame para109272bytes, ainda inadequado. Esse experimento foi
retirado: a revisão final preserva os helpers rápidos inline e os contratos
aritméticos anteriores. A redução efetiva veio de limitar a unidade C que o
otimizador precisa processar de uma vez. Não foi necessário alterar CPUState,
transferir buffers para o contexto guest, mudar endianness ou desativar provas
de pilha com `/Gs`.

## Transformação de controle

Foram removidas as39046 arestas de chamada C entre chunks, `cpu_direct.h`, a
preparação/guarda de chamadas diretas e seus testes específicos já obsoletos.
Continuam ativos o laço iterativo do executor, quantum1024/downcount768, o pacer
recuperado e FIFO GX sem fence artificial. A classificação por retorno não voltou.

`tools/chunk_segments.py` transforma somente as cópias de build dos185 corpos
grandes em wrappers planos e23677 regiões privadas de no máximo128bytes de código
guest (32instruções). As2824 funções pequenas mantêm seu corpo original.
Cada wrapper chama uma região e recebe um controle local: retorno original,
endereço privado de continuação ou retorno ao dispatcher interno original.
Os wrappers não chamam outros chunks e as regiões não se chamam recursivamente.

O endereço privado de continuação nunca é armazenado em `ctx->pc`. As atribuições
de PC, LR, registradores, operações, FP guards e descontos do orçamento originais
permanecem. Macros/adapters que retornavam da função continuam encerrando o
wrapper. A fronteira de região não renova orçamento, não faz polling do host,
não avança TB, não emite VI e não cria uma nova apresentação. O teste de orçamento
do `return_dispatch` continua no ponto original; saltos para frente não ganham
uma nova interrupção artificial.

Os temporários ficam nos escopos pequenos dessas regiões e o compilador volta a
otimizar e reutilizar registradores/slots. As funções públicas mantêm a ABI
`void func_80XXXXXX(CPUState*)`. Os185 arquivos de `recompiled_code/generated/`
não foram editados.

## Lookup plano O(1)

`dolrecomp_find_original` já usa o array compacto de185 chunks. No segmento text1,
o índice é `(pc - 0x800034C0) >> 14`, após validar intervalo e alinhamento; não
existe busca binária/hash. Text0 e aliases preservam o tratamento anterior.
A base dos chunks não é alinhada em0x4000, portanto usar diretamente
`(pc-0x80000000)>>14` selecionaria o chunk errado nas fronteiras.

Cada wrapper usa outra tabela compacta O(1), indexada por região de128bytes.
Os testes de entry PC e do retorno interno preservam os mesmos destinos legais
dos switches originais. Hooks e overrides continuam no executor original.

## Antes/depois no executável ligado

Dados de unwind do PE x64 e inspeção dos prólogos, não estimativa do fonte:

| Métrica | Antes | Depois |
|---|---:|---:|
| Chunks públicos verificados | 185 | 185 |
| Maior frame público | 168968bytes | **72bytes** |
| Maior frame de produção, incluindo regiões e loops | 168968bytes | **168bytes** |
| Prólogos de produção com `__chkstk` | 183 | **0** |
| `.text` | 143,886253MiB | **47,883034MiB** |

Artefatos: `build_test/stack_before_regions.json`, `stack_after_regions.json`.
`tools/inspect_chunk_stacks.py` conta alocação e pushes de registradores não
voláteis pelos unwind records e verifica chamadas a `__chkstk` nos prólogos.
O post-build falha se faltar algum dos185 wrappers, se qualquer frame de produção
atingir4096bytes ou se aparecer um prólogo com probing. As salvaguardas ABI de
registradores necessários continuam corretas. A contagem se refere às funções
de produção dos chunks, suas regiões e loops; o executável também contém rotinas
de validação e runtime com outros requisitos de pilha.

## Validação

- CMake/MSVC Release saída0, sem warnings: `build_flat_regions_release.log`.
- CTest **19/19**: `test_flat_regions_ctest.log`.
- Novo contrato: **12288 comparações exatas** CPU/RAM, três tamanhos de região,
  entry PC válido/inválido, helper sem switch inicial, PC observado por MMIO,
  fallthrough, saltos frente/trás, budget negativo, reserva e exceção de FPU.
- As comparações reais de CPU/RAM/locked cache, helpers de memória e PC DSE
  continuam passando; não foram substituídas pelo novo teste.
- Replay17 lotes idêntico: SHA256
  `2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79`.
- Inventário216 objetos /116069 nomes no mapa. O aumento de nomes inclui as
  regiões privadas; tamanho de código medido caiu cerca de66,7%.
- PGO OFF; nenhum perfil antigo ou instrumentação PGI foi usado.

## Medição do combate

O executável foi reaberto para input físico, com compilação e testes encerrados.
A coleta de960 quadros está preparada em `build_test/flat_regions_combat960.json`.
O novo tempo em combate depende dessa execução chegar à luta com os quatro
evoluídos. Não se usa o tempo do menu como substituto nem se afirma60FPS sem
medição/validação visual dessa carga. A redução de pilha e ausência de probing
já estão verificadas independentemente dessa confirmação.

A tentativa inicial aguardou180 segundos e recebeu zero janelas de combate:
o jogo permaneceu em scene2, no prompt físico inicial. O coletor terminou;
a janela foi preservada. Portanto ainda não há um novo número válido de CPU
na luta para apresentar nesta revisão.
