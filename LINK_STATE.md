# Digimon Rumble Arena 2 — integração HLE

Atualizado em 2026-11-01. Relatório: [ENGINEERING_REPORT.md](ENGINEERING_REPORT.md).

## Estado verificado

O DOL real fornecido pelo usuário inicializa e o usuário confirmou Title → menu → Practice, seleção de personagens e carregamento de Jungle Ruins. Cores e ícones foram confirmados corretos. Após a implementação do locked cache de 16 KiB e DMAU/DMAL, o usuário confirmou todos os modelos corretos. O consumo imediato do FIFO sozinho não havia resolvido a geometria.

O som e os modelos foram confirmados corretos pelo usuário. Com PGO, a seleção com quatro Digimons sustenta 60 FPS. Em Jungle Ruins, o usuário confirmou aproximadamente 40–46 FPS, com quedas ocasionais próximas de 30. **60 FPS sustentados em combate ainda não foi atingido.** Os benchmarks isolados de DMA, skinning e reflexão não representam ganho equivalente no frame completo.

A comparação do adaptador de RAM não mostrou benefício: mediana de 35,2 FPS desligado e 30,9 ligado, com carga variável na mesma luta. O custo estimado de CPU por despacho também não melhorou (338,8 contra 343,4 ns). O adaptador foi retirado do build padrão; permanece experimental e coberto por contratos. A revisão do despachante preservou os handlers, mas não atingiu 60 FPS. A revisão atual alcança os núcleos também pelos saltos locais do chunk; a comparação em combate ficou em 43,55 FPS desligada e 45,65 ligada, com carga variável; 60 FPS ainda não foi atingido.

O orçamento sintético mantém 100 mil dispatches e 675 mil ticks TB por retrace, com quantum 1024. Contadores distinguem cópias XFB, listas AX e FPS host. Input continua exclusivamente físico.
## Arquitetura

```text
PPC gerado (inalterado) → runtime CPU (ABI inalterada)
  ├─ exceções FP → os_context: proprietário FPU D8, contexto atual D4
  │    └─ scalar f64 + dois paired singles f32 no formato SDK
  ├─ locked cache E0000000: 16 KiB + DMAU/DMAL, transferências reais
  ├─ PADRead → SDL físico → PADStatus guest big endian
  ├─ DVDReadAbsAsyncPrio → ISO/CISO bounded → fila de callbacks
  │    └─ contexto/pilha temporários, EE/FP mascarados, retorno guest seguro
  └─ MMIO aliases 0C/CC
       ├─ PI/CP: gather 32 bytes → FIFO RAM → parser GX
       │    ├─ consumo ao habilitar GP e ao completar gather ligado
       │    ├─ VCD/VAT, XF, matrizes e snapshots dos vértices indexados
       │    └─ PE finish/token por comando → IRQ → callback SDK
       ├─ GX: OpenGL TEV por pixel, texturas, profundidade, alpha, recorte
       │    ├─ envio de arrays em lote e EFB persistente
       │    ├─ GXCopyTex → textura tiled na RAM + clear
       │    └─ GXCopyDisp → XFB YUY2 na RAM
       ├─ VI: seleção do scanout no VBlank → XFB → SDL/OpenGL
       └─ DSP/ARAM/AI: AX PB/command lists → PCM → SDL/resampling
```

`80248B60` é GXDrawDoneCallback e limpa `r13-29800`. O handler PE `802CF444` atualiza DrawDone em `r13-25320`. A espera adicional do Title passava pelo controlador de som: `8015ED34 → 8015BA2C → 8015EF9C → 80143B78 → 801B35AC`. A voz permanecia ativa sem backend DSP que avançasse e encerrasse a amostra.

A cópia FPU antiga estava errada: SDK `psq_st` salva dois `float32` em cada slot de 8 bytes a partir de `OSContext+1C8`, não um `double` PS1. O novo teste compara o HLE com a própria rotina SDK `802BFF2C` e verifica troca de proprietário FPU.

## Build e execução

```powershell
$cmake = 'C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe'
& $cmake --build build_test --config Release --clean-first --parallel 4
& 'C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\ctest.exe' --test-dir build_test -C Release --output-on-failure
python tools/symbol_inventory.py
python tools/hle_audit.py
.\build_test\Release\digimon_test.exe
```

Requer DolRecomp do submódulo e SDL2 VC x64 2.32.0 em `third_party/SDL2/lib/x64`. CMake copia a DLL para junto do EXE. O disco e o DOL são recursos locais, não mudanças de código. CLI aceita DOL e ISO/CISO como argumentos opcionais.

**Input exclusivamente manual:** Z/J=A, X/K=B, C/U=X, V/I=Y, Enter/Espaço=Start, WASD/setas=movimento, Q/Shift esquerdo=L, E/Shift direito=R, Tab=Z; Esc fecha. Controle SDL: A/B/X/Y/Start, sticks esquerdo/C, D-pad, LT/RT, LB=L e RB=Z. Quatro portas de teclado conectadas: 7/8/9=A dos jogadores 2/3/4; Shift+o mesmo número=Start; aceita também o numérico. O controle SDL físico permanece no jogador 1. O attract mode original do jogo permanece nativo.

## Diagnóstico

- `--self-test`: suíte de contratos ativa em Release. CTest usa software e OpenGL, verificando que a rota GL realmente está ativa.
- `GX_RECORD=1`: captura frames para `build_test/gx_scene*_copy*.gxc`, incluindo RAM, paletas, materiais, vértices e eventos de copy/clear. Não injeta input.
- `digimon_test --gx-replay captura.gxc saida.bmp [software]`: replay de renderer sem executar a CPU do jogo.
- `tools/gx_capture_inspect.py`: inspeção dos bytes de posição, VAT, matrizes e limites dos draws capturados.
- `GX_FORCE_SDL=1`: comparação diagnóstica com a rota SDL anterior; não é o backend normal.
- `RUNTIME_TRACE=1`: logs por frame e screenshots; desligados na execução normal para evitar I/O de diagnóstico.
- `CPU_PROFILE=1`: amostragem de tempo por entrada PPC, relatório local em build_test/cpu_profile.csv; desligada na execução normal.
- `dsp_coef.bin`: coeficientes livres do checkout Dolphin, copiados pelo CMake para junto do executável; ausência usa fallback linear explícito.
- `tools/inspect_guest.py`: snapshot read-only de RAM/XFB do processo.
- `runtime_crash.log`: exceção host e registradores PPC. O log de execução distingue Escape/SDL_QUIT de falha host.
- O travamento anterior no VS produziu erro Lua `attempt to index a number value` e caiu em `exit(1)`; o stub gerado retornava e entrava no getenv adjacente. O contexto e os callbacks foram corrigidos depois dessa captura. Não se contornou o script com flags de sucesso.

A auditoria percorre 185 chunks, 7.349.164 linhas e 5.053 destinos diretos. O inventário de objetos lista importações antes do link e símbolos COMDAT; a resolução final é verificada pelo linker e por dumpbin /imports.


## Revisão de desempenho: PSQ direto e cópia YUY2 na GPU

O usuário confirmou cores, ícones, modelos e som corrigidos. O problema remanescente é desempenho: a referência mais recente com quatro Digimons ficou em 47–49 FPS, raramente 50. A meta de 60 FPS sustentados na seleção e em combate ainda não foi comprovada.

O caminho PSQ rápido preserva limites, alinhamento, endianness, quantização, exceções, journal e reservas. Acesso direto é restrito à RAM coerente e aos 16 KiB de locked cache; MMIO permanece nos callbacks. O hook external_pointer existente fornece a área LC sem alterar CPUState. Os auxiliares privados ps_fast.h e psq_fast.h fazem parte do patch reproduzível do runtime. O código gerado continua inalterado.

As experiências de inlining público amplo e de expansão SIMD nos call sites passaram nos testes numéricos, mas reduziram o desempenho real para aproximadamente 24–30 FPS. Foram revertidas. O ganho retido veio de PSQ direto, buffers reutilizados e auxiliares privados, sem fast-math.

O arquivo opcional build_test/runtime_tuning.cfg aceita `quantum workers [packed_copy]`, aplicado entre frames. Ele altera somente parâmetros host, sem botões ou flags guest. Na mesma seleção, quantum 1024 e workers ligados foi ligeiramente melhor que 512; 2048 não trouxe vantagem. O custo de vértices caiu de aproximadamente 2,8 para 2,2 ms com workers. O perfil ainda apontou custo significativo no runtime CPU e em texturas/cópias.

A nova rota OpenGL empacota dois pixels EFB em um texel RGBA de bytes Y0/U/Y1/V, lê esse resultado diretamente para a RAM XFB e mantém a apresentação pelo VI. Há fallback CPU e comparação diagnóstica GX_VALIDATE_COPY=1, que verifica cada byte contra a conversão CPU. As suítes software e OpenGL passaram, incluindo recorte e escalas verticais normal/inversa. O desempenho dessa rota com quatro modelos está aguardando comparação na mesma tela.

O cache de texturas agora distingue a paleta também na busca de entradas existentes; alternar duas paletas de uma imagem CI não destrói/reenvia a mesma textura em cada draw. O teste verifica cores e duas transferências para quatro draws alternados. Escritas TLUT invalidam a época mesmo sem draws pendentes. Quando disponível no checkout local, XXH64 substitui o hash byte a byte; existe fallback sem dependência adicional.


## Atualização de desempenho e validação da cópia YUY2

O usuário confirmou cores, ícones, modelos e som corretos; quatro personagens ainda ficam em 47–49 FPS, raramente 50. Os 60 FPS sustentados na seleção/combate continuam pendentes.

O PSQ direto preserva alinhamento, limites, endianness, quantização, exceções, journal e reservas. Somente RAM coerente e locked cache usam acesso direto; MMIO conserva callbacks. O hook external_pointer já existente fornece LC sem alterar CPUState. cpu.h e os novos ps_fast.h/psq_fast.h estão incluídos no patch reproduzível do runtime, validado com git apply --reverse --check. O código gerado permanece inalterado.

Inlining público amplo e expansão SIMD nos call sites passaram nos testes numéricos, mas regrediram para 24–30 FPS. Ambos foram revertidos. Permanecem auxiliares privados, PSQ direto e buffers reutilizados, sem fast-math.

build_test/runtime_tuning.cfg aceita `quantum workers [packed_copy]`, aplicado entre frames, sem input ou flags guest. Comparação na mesma seleção favoreceu ligeiramente quantum 1024 e workers ligados; 2048 não trouxe vantagem. Workers reduziram vértices de aproximadamente 2,8 para 2,2 ms.

A nova rota OpenGL empacota dois pixels EFB em RGBA com bytes Y0/U/Y1/V e lê diretamente para a RAM XFB. O VI continua apresentando essa RAM. Fallback CPU permanece disponível. GX_VALIDATE_COPY=1 compara cada byte com a conversão CPU. As suítes software/OpenGL passaram, incluindo fontes recortadas e escalas verticais normal/inversa; desempenho com quatro modelos ainda aguarda comparação na mesma tela.

O cache agora distingue a paleta na segunda busca de entradas, evitando destruir/recriar uma textura CI a cada alternância de paleta. O teste verifica cores e exatamente duas transferências para quatro draws alternados. TLUT atualiza a época mesmo sem draws pendentes. XXH64 do checkout local acelera o hash quando disponível, com fallback sem dependência adicional.

A comparação ao vivo CPU/GPU na mesma seleção mediu cópia YUY2 de 2,9–3,2 ms na CPU e 1,6–1,8 ms na GPU; a taxa passou de aproximadamente 43 para 46 FPS. O usuário observou 42–48 FPS. Isso confirma ganho parcial, não a meta. A resolução escalar de memória agora usa tradução única de aliases e inline apenas do auxiliar privado, preservando os entry points públicos. Testes adicionais cobrem MEM1/MEM2, quatro aliases, limites de 1/2/4/8 bytes e callbacks de MMIO/LC. Ambas as suítes passaram. Quantum padrão ajustado para 1024 após comparação ao vivo.

Validação da revisão escalar de memória: build canônico build_test/Release com saída 0 e sem warnings; CTest 2/2 (software/OpenGL), saída 0. Inventário atualizado: 199 objetos /GL opacos para /SYMBOLS e 9.131 nomes no mapa final; imports DLL verificados. Patch do runtime regenerado com cpu.c, cpu.h e os dois headers novos, e reverse-check aprovado. Executável aberto para comparação física com quatro modelos; desempenho ainda não confirmado.


### Revisão de acessos big endian

O usuário confirmou 46–48 FPS, com picos de 50, após a simplificação de aliases. Ainda abaixo da meta. O perfil de cinco segundos manteve psq_direct_load, mem_read32 e operações pareadas entre os maiores custos. A desmontagem do executável mostrou quatro cargas de byte e shifts em mem_read32, sem BSWAP.

No MSVC x64, a nova revisão usa memcpy de tamanho constante seguido dos intrinsics byteswap em acessos escalares de 16/32/64 bits e PSQ. A tradução/bounds, callbacks, journal e invalidação de reserva permanecem antes da operação. Demais plataformas conservam a implementação anterior. PSQ inteiro usa produto binary64 exato: valores de 8/16 bits multiplicados por potência de dois são representáveis exatamente em todos os fatores GQR. Novos testes cobrem offsets desalinhados 1..7 em MEM1/MEM2 cached/uncached. Build e medição dessa revisão ainda em andamento.

Validação concluída da revisão big endian: build canônico Release saída 0, sem warnings; CTest software/OpenGL 2/2, saída 0; inventário atualizado com 199 objetos /GL e 9.132 nomes no mapa final. A desmontagem confirma MOV dword + BSWAP em mem_read32. Patch reverse-check aprovado. Executável aberto para medição com quatro personagens; não há resultado de FPS confirmado para essa revisão.


### Laço de skinning agrupado (validação funcional, desempenho pendente)

A revisão big endian não comprovou ganho no jogo: o usuário mediu 43–45 FPS com quatro personagens. Repetir fatias de 512/1024/2048/4096 mostrou variação, mas nenhuma configuração sustentou 60. Não se considera menor contagem de instruções uma prova de ganho.

paired_skinning.c/.h implementa especificamente o corpo 8024BC48..8024BCE8, mantendo as 41 instruções em ordem, PSQ, resultado final de registradores e os limites de downcount. Só aceita MSR FP e HID2 corretos, GQR7 S16 para load/store, peso quantizado válido, arrays coerentes com limites antecipadamente validados e ausência de journal/reserva. Demais estados continuam pelo original. O prólogo e o epílogo permanecem na rotina gerada; código gerado não foi editado. Auxiliares SIMD privados são expandidos apenas nesse núcleo pequeno.

A suíte comparou toda a RAM de teste e todos os bytes de CPUState (ajustando apenas o ponteiro da RAM de referência) com func_8024B4C0 original em 64 combinações: quatro arredondamentos, quatro orçamentos e quatro contagens, incluindo saída pelo epílogo e retorno ao despachante. Software e OpenGL passaram. O build de validação terminou sem warnings. A quarta coluna opcional de runtime_tuning.cfg liga/desliga esse núcleo: `1024 1 1 0` original, `1024 1 1 1` agrupado. Essa opção é exclusivamente host; nenhum input ou flag de jogo é alterado. Contador [Skinning] registra vértices aceitos para não confundir ausência de uso com ausência de ganho. A revisão está aberta em build_test/skinning_validation para comparação no mesmo estado físico escolhido pelo usuário.


### Expansão do núcleo de skinning

O usuário confirmou melhora para 49–55 FPS com quatro Digimons na revisão do primeiro laço. A comparação ao vivo no mesmo executável (skinning_comparison.json) mostrou redução parcial do custo, com variação entre frames; 60 FPS ainda não foram alcançados. O estado anterior de 43–45 FPS não é tratado como um benchmark controlado entre binários.

A versão seguinte também agrupa 8024BE80..8024BF28 (43 instruções) e 8024C130..8024C184 (22 instruções). O terceiro laço usa input r4/output r5 e não lê pesos; a validação de memória respeita essa diferença. Foram executadas 192 comparações completas CPU/RAM contra o original, incluindo quatro formatos de peso, arredondamentos, orçamentos e saída pelo epílogo. As suítes software/OpenGL retornaram 0. A versão ampliada ainda precisa ser medida com quatro modelos; as cores/geometria e o som confirmados anteriormente devem ser preservados na validação funcional.

Build canônico da expansão: saída 0, sem warnings; CTest 2/2 saída 0; inventário de 200 objetos /GL e 9.159 nomes no mapa final. Execução aberta em build_test/Release, log runtime_skinning_expanded.log. Desempenho da expansão pendente de confirmação física.


### Reversão da expansão após medição real

O usuário mediu 40–45 FPS na revisão com três laços. A comparação ao vivo também não mostrou ganho consistente da expansão: o original do mesmo binário variou aproximadamente 41–49 e a rota agrupada 43–50. Após encerrar a alternância, os registros voltaram a 48–49, mas não superaram a revisão menor. Os dois laços adicionais foram removidos do código e do hook. Mantido somente 8024BC48..8024BCE8, a revisão que o usuário havia confirmado em 49–55 FPS. As 192 comparações demonstravam equivalência funcional, não desempenho. A suíte ativa volta às 64 combinações do núcleo retido.

Meta continua pendente: sustentar 60 FPS com quatro personagens e em combate. Nenhuma alteração de ritmo guest, frame skipping ou input foi usada para mascarar as quedas.

Restauração concluída: recompilação LTO completa de 4.383 funções, build saída 0 e sem warnings; CTest software/OpenGL 2/2 saída 0. Inventário: 200 objetos /GL, 9.156 nomes no mapa final e DLLs verificadas. Patch reverse-check aprovado. Núcleo único reaberto em build_test/Release, log runtime_skinning_restored.log; sem novas alternâncias nesta execução. A recuperação dos 49–55 FPS depende da confirmação na mesma seleção física.


### Cache de parâmetros OpenGL (em validação)

O usuário confirmou a recuperação do núcleo menor: em geral 53–55 FPS, às vezes 51 ou 56, com quatro personagens. A meta de 60 FPS sustentados continua pendente. O novo perfil mantém runtime CPU e decode de vértices como custos importantes; render custa aproximadamente 1,6 ms e readback/YUY2 1,6 ms nessa seleção.

A revisão seguinte conserva o núcleo menor e adiciona cache por valor dos uniforms do programa TEV: cores, konst, swap, seletores, equações, alpha e número de estágios. Uniforms pertencem ao programa e sobrevivem à seleção de outros programas pelo SDL. Só valores modificados são enviados novamente; recriar/destruir o programa invalida o cache. Novos testes conferem zero uploads para material idêntico e atualização visual ao alternar um registrador 64→65→64, além das alternâncias de TEV e alpha já exercitadas. Performance ainda não medida.

Cache de uniforms: suítes software/OpenGL saída 0; teste de material repetido e alternância de cor passou. Replay da captura gx_scene18_copy180.gxc completou 11 batches em ambas as versões, com BMPs de SHA256 idêntico F233AC519A00C5F51240B143BB69C8BD8491383A2A3BE2BBF44DE4FCEEDF2557. Binário anterior preservado em build_test/baseline_skinning_53fps com DLL/coeficientes e identificação SHA256. Não se presume ganho de FPS antes da medição ao vivo.

Validação canônica do cache OpenGL concluída: build saída 0 e sem warnings, CTest software/OpenGL 2/2, inventário de 200 objetos /GL e 9.171 nomes no mapa final. Execução aberta em build_test/Release, log runtime_uniform.log. Nenhuma alternância ao vivo programada; o resultado com quatro personagens permanece pendente.


### Cache de uniforms retirado; verificação FP isolada em teste

O usuário mediu 49–52 FPS no cache de uniforms, abaixo dos 53–55 da referência. A mudança foi retirada de gx_gl.c/.h, dos testes e da telemetria. A equivalência de imagem do replay não demonstrava ganho de velocidade. Reabriu-se o binário exato de build_test/baseline_skinning_53fps para preservar a referência, sem depender de um novo layout do linker.

A próxima revisão muda somente a escolha de inlining da curta verificação ppc_fp_available_inline no MSVC. O teste de MSR FP fica no local e o tratamento completo da exceção continua na função pública original. Não se força expansão das operações aritméticas nem se habilita Ob3. Novos testes comparam o CPUState inteiro com ppc_fp_available original, com FP ligado/desligado e combinações de MSR. Build e medição em andamento; ainda sem ganho confirmado.

Validação da verificação FP isolada: build canônico saída 0 e sem warnings; CTest software/OpenGL 2/2 saída 0. Inventário: 200 objetos /GL e 10.171 nomes no mapa final. O binário aumentou de 106.078.720 para 109.850.112 bytes, portanto o custo de código também precisa ser avaliado no teste real. Patch do runtime regenerado e reverse-check aprovado. Executável aberto em build_test/Release, log runtime_fp_guard.log. Sem alternância de configurações; resultado de desempenho ainda pendente.


### Perfil conjunto native/PPC e fronteiras de cache

A verificação FP isolada ficou em 50–55 FPS segundo o usuário, sem atingir a meta. Em vez de novas alterações especulativas no renderer, tools/sample_native.py agora aceita --guest-pc com o mapa exato do executável. Lê o ponteiro s_crash_cpu via ASLR e valida o layout/tamanho da RAM; durante a suspensão já usada para obter RIP, lê também o PC guest. O processo é aberto só com permissões de leitura/query. A thread é retomada no finally. Não escreve CPU/RAM nem input.

A captura native_guest_profile.json identificou custo no skinning 8024C244..8024C2D0 e amostras recorrentes em 8024C2CC, logo após dcbst 8024C2C8, inclusive dentro de despacho, consulta de interrupções e chamadas de input. A captura incluiu transição/carregamento e a fase state=4; não é tratada como benchmark exclusivo da seleção.

O harness já permitia continuar prefetch dcbt/dcbtst na mesma fatia. Agora faz isso também para dcbst/dcbf quando cache_control é NULL, condição da RAM coerente atual. Cada instrução original e seu orçamento continuam sendo executados; não se agrupa aritmética, não se mexe nos vértices e não se atravessa callback de cache instalado. DCBI/ICBI não foram incluídos nessa continuação.

Novos testes executam a rotina original a partir de 8024C244 com 2/9/37 iterações e quatro arredondamentos. Comparam toda a RAM e CPUState, normalizando somente ponteiro/configuração de referência e o downcount renovado por fatia; verificam também menos chamadas ao despachante. Software e OpenGL passaram na validação inicial. Ganho ao vivo ainda pendente.

Validação canônica da continuação dcbst/dcbf: build saída 0 sem warnings; CTest software/OpenGL 2/2 saída 0; teste mediu 204 retornos originais contra 16 na rota agrupada, com CPU/RAM iguais. Inventário atualizado: 200 objetos /GL e 10.178 nomes no mapa final. Execução aberta em build_test/Release, log runtime_cache_boundary.log, configuração fixa. Ganho de FPS ainda não confirmado.


### Núcleo vetorial de acumulação 8024C244

A continuação dcbst/dcbf reduziu retornos no teste isolado, mas o usuário não observou ganho suficiente no jogo. O perfil conjunto native/PPC passou a orientar a mudança seguinte: skinning_accumulate.c implementa o laço indexado de acumulação S16 em vetores binary32 locais. As matrizes e os resultados intermediários permanecem em pares SIMD durante a fatia, evitando classificação e conversões double/float a cada operação. A sequência de operações fused multiply-add do original foi preservada.

A rota exige MSVC x64 com FMA detectado por CPUID/OSXSAVE/XCR0, MSR FP/HID2 válidos, RAM/LC coerentes e bounded, ausência de callback de cache/journal/reserva, índices e buffers acessíveis, GQR7 S16 e pesos GQR6 U8. Matrizes ficam no intervalo conservador de magnitude 2^-16..2^16 (ou zero), vértices iniciais 2^-16..2^31 e escalas GQR -16..16. Esses limites impedem NaN, infinito e subnormal intermediários; dados fora desse domínio usam o original. Hosts sem FMA mantêm fallback e não devem falhar na suíte por ausência da otimização.

Saturação S16 usa scaling exato por potência de dois, clamp antes de truncar e armazenamento big endian. Guarda de orçamento preserva a divisão em 8024C2CC após dcbst e a checagem da backedge, incluindo os custos 33 + 2 do código original. O núcleo pequeno anterior 8024BC48 permanece separado. Não houve alteração de CPUState, código gerado, input ou flags de cena.

A primeira validação completa passou software/OpenGL com 120 combinações de arredondamento, NI e escalas, comparando CPU/RAM contra o original. Benchmark de 185 mil vértices, com checksum dos resultados e CPU, mediu 43,716 ms original contra 4,990 ms nativo (8,76x no laço, não no jogo inteiro). A suíte foi ampliada para 360 combinações com índices sequenciais, repetidos e invertidos, mais seis recusas sem mutação. O build canônico dessa ampliação está em validação; ainda não há resultado de FPS confirmado para o novo núcleo.


Validação canônica do núcleo vetorial concluída: build saída 0, sem warnings; CTest software/OpenGL 2/2 saída 0. As 360 combinações e seis recusas sem mutação passaram. Benchmark dos 185 mil vértices no build final: 50,213→7,197 ms (6,98x) e 46,250→5,082 ms (9,10x), checksum 102C34A5 idêntico; são medições do laço, não promessa de FPS global. Inventário: 201 objetos /GL e 10.204 nomes no mapa final. Execução normal aberta em build_test/Release, log runtime_accumulate.log; bancada e perfis desativados, input exclusivamente físico. Resultado ao vivo ainda pendente.


### Correção da entrada real do núcleo vetorial

A execução registrou apenas 49 vértices no novo acumulador, enquanto o usuário ainda observou 50–55 FPS. A captura read-only das condições reais (accumulate_real_states.json e accumulate_guard_states.json) mostrou matrizes/GQR válidos, FP habilitado, ausência de exceção/reserva/callback e inputs em locked cache. A hipótese de recusa numérica não se confirmou. A causa foi a conexão somente em 8024C244: quase todas as fatias retomam em 8024C2CC, depois de dcbst, e percorrem o laço internamente sem passar pelo hook.

O hook agora também aceita 8024C2CC. Executa add r21,r20,r6 e decremento/branch de CTR com custo 2 e as checagens de orçamento correspondentes antes de entrar no núcleo vetorial. Não houve relaxamento dos limites numéricos. A suíte foi ampliada para ambos os pontos de entrada e inputs RAM/LC, totalizando 1.440 combinações. Inclui matriz e GQR6=08040804/GQR7=0C070C07 observados no jogo. Compara CPU/RAM e exige uso do núcleo em cada caso suportado, evitando aprovação de um teste que só exercite fallback.

A validação inicial software/OpenGL passou para 720 combinações e a expansão LC passou na suíte software, preservando CPU/memória. O build canônico e a checagem adicional de uso por caso estão em validação. Ainda não há resultado de FPS confirmado para a entrada corrigida.

Build canônico da entrada corrigida: saída 0 sem warnings; CTest software/OpenGL 2/2 saída 0, com 1.440 combinações e exigência de uso do núcleo em cada caso suportado. Teste agregado: 23.760 retornos originais contra 3.360 na rota otimizada, CPU/RAM iguais. Inventário: 201 objetos /GL e 10.215 nomes no mapa final. Execução aberta em build_test/Release, log runtime_accumulate_resume.log; aguarda seleção física para confirmar uso no jogo e taxa de frames.


### Normalização e reflexão (environment mapping)

O usuário confirmou 57–59 FPS na seleção com quatro personagens após conectar o acumulador em 8024C2CC. A fase ainda pesa mais. O perfil seguinte mostrou 8024C500 como o maior bloco restante de matemática dos modelos. skinning_environment.c otimiza a normalização dos raios/normais e a reflexão que produz pares de coordenadas de textura.

Mantém ppc_approx_rsqrt, incluindo a tabela original de aproximação e force_25_bit do multiplicador antes de cada normalização. Preserva a ordem dos somatórios, FMA e inversão de sinal de ps_nmsub. Valores excepcionais/degenerados, subnormais intermediários, formatos e regiões não suportados permanecem no original. A cópia usa entrada S16 bounded em RAM/LC, e o código gerado continua executando os stores e o epílogo. A continuação entre corpo nativo e prefixo respeita downcount.

Esse chunk emite dcbt como no-op, sem fallback. Por isso, a integração cobre 8024C500/8024C508, além de 8024C518; não presume um retorno após o hint. Os testes exigem que cada caso suportado efetivamente use o núcleo. As 144 combinações cobrem RAM/LC, três pontos de entrada, NI e quatro arredondamentos. CPU/RAM e downcount ficaram idênticos, normalizando apenas ponteiro de RAM e callback de referência. Sete recusas sem mutação também passaram.

Benchmark inicial de 370 mil vértices: 134,608→37,079 ms (3,63x). No build canônico: 92,710→28,965 ms (3,20x) e 91,466→37,063 ms (2,47x), checksum 6CB80AC5 idêntico. Isso mede o laço isolado. Build saída 0 sem warnings, CTest software/OpenGL 2/2, inventário de 202 objetos /GL e 10.255 nomes no mapa final. Referência exata de 57–59 FPS preservada em build_test/baseline_accumulate_59fps. Revisão atual aberta em build_test/Release, log runtime_environment.log e mapa correspondente preservado em build_test/environment_active.map. Resultado de seleção/combate dessa revisão ainda pendente.

## Continuação: custo real em combate e XF

A revisão com normalização/reflexão registrou aproximadamente 33–35 FPS em combate. O perfil está em build_test/combat_latest_profile.json. Os timers de texture copy incluem flush/render e não são aditivos.

Foi acrescentada captura read-only de lotes GX em tools/capture_gx_decode.py e validação `--gx-validate-decode captura.gxvd [scalar|vector] [repeticoes]`. O lote real de 447 vértices permaneceu byte a byte igual após preparar matrizes de posição/normais em SIMD e eliminar a normalização sem luz difusa ativa. 24.576 comparações adicionais cobrem arredondamentos, FTZ/DAZ e invalidação XF. A experiência com matrizes de pós-textura foi retirada por ausência de ganho consistente.

Build Release saída 0 sem warnings, CTest 2/2, inventário 202 objetos /GL e 10.293 nomes. O benchmark do lote variou entre ganho pequeno e empate; o ganho global de FPS não foi confirmado. Execução atual: runtime_xf.log, mapa build_test/xf_active.map, configuração fixa 1024 1 1 1, input exclusivamente físico. Referência anterior preservada em build_test/baseline_environment. A meta de 60 FPS em combate permanece aberta.

## Transformação rígida em combate: 8024C014

Jungle Ruins foi perfilada com a execução real aberta pelo usuário: cerca de 36–41 FPS inicialmente, com variação posterior para 32–33. build_test/combat_xf_profile.json localizou o laço pipelined 8024C014..8024C060 ainda no caminho original. A implementação separada em skinning_accumulate.c mantém pares SIMD, ordem de stores/loads sobrepostos, quantização S16, orçamento de 20 instruções e fallback conservador. Hook em 8024C014; log [Skinning] inclui transform=.

Validação: 3.840 casos CPU/RAM/LC/downcount iguais ao original e oito recusas sem mutação. Benchmark canônico de 505 mil vértices: 91,450 → 10,616 ms (8,61x), checksum 3EA9A7B5. Build sem warnings, CTest 2/2, inventário 202 objetos /GL e 10.320 nomes. Execução atual runtime_rigid.log e mapa build_test/rigid_active.map. Referência anterior preservada em build_test/baseline_xf_combat. Ganho global e 60 FPS em combate ainda não confirmados.

## PGO do compilador com treino real (2026-11-01)

O hook 8024C014 está ativo em combate (milhões de vértices), mas a luta medida ainda ficou por volta de 36–38 FPS. Novo perfil: build_test/combat_rigid_profile.json.

CMake oferece DIGIMON_PGO_MODE=OFF|GENERATE|USE, DIGIMON_PGO_DATABASE e DIGIMON_PGO_COUNTS. OFF é o padrão; GENERATE usa FASTGENPROFILE. O build leve de coleta passou nas suítes software/OpenGL; dados desses testes foram arquivados separadamente. A captura real de Jungle Ruins tem 1.826.816 bytes, 4.256 funções e nenhum descarte por estouro. Entradas preservadas em build_test/pgo_capture_archive/untrained.pgd e combat_01.pgc; manifesto no mesmo diretório.

USE prepara uma cópia limpa da base e das contagens antes de cada link, evitando avisos de dados duplicados/ausentes. A primeira versão otimizada passou nas duas suítes e manteve os 447 vértices reais byte a byte iguais. O build canônico Release terminou com saída 0 sem warnings; CTest 2/2 e inventário 202 objetos /GL, 10.840 nomes. O lote real manteve todos os bytes e ficou cerca de 9% mais rápido na média do benchmark. Execução final: runtime_pgo_release.log, mapa build_test/pgo_release_active.map, sem coleta/compilação concorrente, configuração 1024 1 1 1. Referência normal preservada em build_test/baseline_rigid_combat. O usuário confirmou 60 FPS estáveis na seleção e 40–46 FPS no combate, com modelos e som corretos. O combate ainda apresenta slow motion. O cache atual está em USE com cópias preservadas da base e do PGC de combate.

## Laço de reflexão agrupado: revisão atual

DMA de LC usa cópias contíguas com wrap, validado em 1.792 casos. A entrada rígida 8024BF84 foi comparada em 7.680 casos e usada no jogo; o usuário manteve 60 FPS na seleção e 40–46 em combate. Não houve ganho global claro dessa entrada ou do DMA.

O laço de reflexão C500/C508/C518 agora mantém pares SIMD locais ao longo do quantum, com stores antes dos prefetches, estimativa Gekko e orçamento preservados. Passou em 1.728 casos de CPU/RAM/LC/downcount, incluindo quanta, sobreposição e FPSCR. Benchmark do núcleo: 27,082 → 14,511 ms, checksum 6CB80AC5 igual. Novo contador: env_batches.

Build completo Release saída 0 sem warnings, artefato promovido para build_test/Release com SHA-256 conferido; CTest 3/3, inventário 202 objetos /GL e 10.831 nomes. Execução: runtime_environment_loop.log, mapa build_test/environment_loop_active.map. Referência anterior em build_test/baseline_rigid_entry_verified. Input físico, configuração fixa 1024 1 1 1. FPS da revisão agrupada ainda não confirmado; meta de 60 FPS em combate pendente.

## Revisão em teste: RAM inline seletiva

A reflexão agrupada foi usada (env_batches ativo), mas o usuário confirmou novamente seleção a 60 e combate aproximadamente 40–46 FPS, com quedas ocasionais próximas de 30. A referência está preservada em build_test/baseline_environment_loop_verified.

cpu_native_adapter.h usa DOLRECOMP_CPU_HEADER em dez chunks quentes, preservando o código gerado. Expande somente RAM cached/uncached de 32 bits; físico, MEM2, MMIO, reservas, journal e spans inválidos seguem o runtime original. A verificação independente passou em 1.624 casos de CPU/memória/callbacks.

Build completo saída 0 sem warnings; CTest 4/4; inventário 203 objetos /GL e 10.842 nomes; 447 vértices reais iguais. Execução atual runtime_native_ram.log, mapa build_test/native_ram_active.map. Quinto campo opcional de runtime_tuning.cfg controla ram_inline (padrão 1); os quatro campos anteriores mantêm compatibilidade. tools/compare_native_ram.py faz A/B/B/A na mesma luta e restaura a configuração. Comparação real ainda pendente; a meta de 60 FPS em combate continua aberta.


### Resultado da comparação RAM e seleção dos hooks (2026-11-01)

A comparação local está em build_test/native_ram_comparison.json: 16 amostras OFF e 20 ON. Medianas OFF/ON: FPS 35,2/30,9; CPU+GX 27,970/31,895 ms; CPU estimada por despacho 338,8/343,4 ns. A luta variou em quantidade de despachos por frame; o último intervalo terminou com SDL_QUIT e contém somente uma amostra. Portanto, a diferença de FPS não é uma estimativa causal precisa. Não houve evidência de ganho, inclusive após a normalização aproximada. A configuração original de quatro campos foi restaurada pelo script. O processo terminou por SDL_QUIT, sem registro de crash nesse log.

Decisão: DIGIMON_NATIVE_RAM_FASTPATH=OFF por padrão e no cache build_test; chave RAM inline também assume 0 quando omitida. O adaptador/teste independente permanece disponível como experiência explícita. O binário experimental anterior e seu manifesto continuam arquivados; ele não deve ser descrito como uma otimização aprovada.

O despachante HLE passou de comparações sequenciais para switch por PC exato. Mantém 37 casos, incluindo o sentinel de retorno de callback 81800000, e o guard por faixa de dados. Os corpos dos handlers foram preservados. A auditoria local dispatcher_case_audit.json compara os endereços com a implementação anterior e confirma os corpos dos handlers sem mudança. Núcleos recusados retornam 0, continuando o guest; seleção de estado, PAD, orçamento, tempo e callbacks não são acelerados artificialmente. A compilação e validação deste build estão em andamento. Não há resultado de FPS atribuído à nova seleção dos hooks.


Validação da revisão do despachante: build completo Release em build_test/dispatch_validation, saída 0 sem warnings; promoção por cópia dos artefatos conferida por SHA-256 05E6AA975E2256B7ADACA35FA8DF7E23902378EDD63CB3C45BB35C84DA92E25B. CTest canônico final 4/4 aprovados, inventário 203 objetos /GL e 10.833 nomes no mapa. A captura real continua com 447 vértices byte a byte iguais, checksum 8FE14D9B. PGO preservado em 4.247/4.256 funções e 92,8% das instruções ponderadas. Manifesto: build_test/dispatch_manifest.json.

Execução atual: runtime_dispatch.log, mapa build_test/dispatch_active.map, configuração 1024 1 1 1, RAM inline=0, sem perfil/coleta ou compilador concorrente. O jogo foi reaberto para confirmação física dos prompts e coleta em Jungle Ruins com quatro Digimons. O ganho global desta revisão ainda não foi medido; os 60 FPS no combate continuam pendentes.


Medição da revisão do despachante na luta: build_test/dispatch_combat_timing.json, 20 amostras sem compilador ou amostrador concorrente; mediana 41,55 FPS (37,0–45,9), CPU+GX 23,68 ms, vértices 3,795 ms, render 2,53 ms e copy 1,675 ms. O usuário confirmou 39–40 FPS. Não é uma comparação de carga idêntica com a referência anterior e não demonstra ganho causal do switch. A primeira janela de coleta sobreposta ao sampler foi explicitamente invalidada e preservada separadamente em dispatch_combat_timing_profile_overlap.json; suas taxas não foram usadas como resultado.

Perfis read-only adicionais: combat_dispatch_profile.json e combat_skinning_residual.json. Confirmam código PPC remanescente no laço de dois ossos BC48, além do decode e das esperas dos workers. Foram capturados 16 contextos desse laço; os exemplos usam GQR6=08040804, GQR7=0B070B07/0C070C07 e buffers E000... válidos. A existência do hook somente na backedge deixa malhas curtas executarem antes dele no mesmo chunk. A referência exata do executável está em baseline_dispatch_verified, com mapa próprio.

Próxima revisão em validação: entrada 8024BB18, prólogo original com débito 77 (76 instruções explícitas antes de BC48) e laço SIMD de mistura de duas matrizes. O caminho per-op anterior permanece como fallback conservador. A validação e promoção dessa revisão estão registradas na seção seguinte; seu FPS continua sem confirmação.


### Skinning de dois ossos: entrada BB18 e pares locais

A nova implementação preserva o prólogo 8024BB18..8024BC44 usando as operações originais do runtime, incluindo stack/backchain, saves FPR14..27/r25, cargas e pré-buscas. Mantém o débito original de 77 antes da backedge BC48. Isso alcança malhas que não retornavam ao host antes de terminar o laço. O epílogo 8024BCEC continua no código gerado.

skinning_accumulate.c acrescenta paired_skinning_blend_step/entry e o contador blended; paired_skinning.c tenta o núcleo SIMD antes do caminho per-op anterior. test_main.c acrescenta o hook BB18 e o campo blend no log, e paired_skinning.h declara as interfaces. Os pares das duas matrizes e dos vértices ficam locais durante o lote. Mantém a ordem FMA, seleção das lanes, stores do vértice anterior antes dos loads, saturação S16 big endian, PS1/FPRF, CTR e orçamento. GQR6 é U8 e GQR7 é S16 no domínio rápido, com escalas limitadas e guardas de valores, memória, callbacks de cache, reserva, journal e exceções. Estados fora desse domínio usam o caminho anterior/original. CPUState e código gerado permanecem inalterados.

A primeira comparação detectou um seletor incorreto da coordenada Z: madds0 exige a lane baixa de f9, enquanto a alta contém a normal X no layout intercalado. Os quatro usos foram corrigidos antes da promoção do executável. O núcleo corrigido passou em 880 comparações isoladas, todas com SIMD utilizado. A comparação completa passou em 7.680 casos de entrada/backedge, RAM/LC, quatro sobreposições, NI, quatro arredondamentos, cinco escalas, quatro contagens e três orçamentos. Compara CPUState inteiro, RAM/LC e downcount com a rotina gerada, não apenas posições finais.

Build completo Release saída 0 sem warnings em build_test/blend_validation; artefatos promovidos por cópia com SHA-256 1DA5A82D517459F6D0FB341BB0DEF81CCD31150802DDC413B1E06DE47DFD553D. CTest canônico 4/4, inventário 203 objetos /GL e 10.831 nomes; os 447 vértices capturados permanecem byte a byte iguais. PGO preservado em 4.245/4.256 funções e 92,7% das instruções ponderadas. Manifesto: build_test/blend_manifest.json.

Execução atual: runtime_blend.log, mapa build_test/blend_active.map; configuração 1024 1 1 1, adaptador RAM desativado, input físico e nenhum compilador/perfil ativo. Foi solicitado carregamento físico de Jungle Ruins com quatro Digimons para conferir o uso de blend e medir o frame completo. Não há ganho global de FPS confirmado para esta revisão. A referência exata anterior está em baseline_dispatch_verified. 60 FPS em combate permanece pendente.


Resultado da revisão blend: o usuário informou FPS próximo do anterior, possivelmente com mais estabilidade. A coleta de 12 amostras sem compilador/amostrador em blend_combat_timing.json teve mediana 43,45 FPS (39,8–51,9), CPU+GX 22,61 ms, decode 3,445 ms, render 2,36 ms e copy 1,625 ms. A carga difere da janela anterior; não demonstra ganho causal. O contador blend confirma uso do núcleo, mas 60 FPS ainda não foi atingido. A referência exata está em baseline_blend_verified.

### Rotas locais no chunk e entrada dos núcleos

A análise do gerado confirmou que 8024B550/8024B6E0 e outras chamadas chegam a BB18 com goto local. Esses caminhos não passam por dolrecomp_dispatch_replacement. O mesmo ocorre nas entradas e backedges dos outros laços no chunk 8024B4C0. Acrescentar somente um hook de função não garante cobertura das malhas pequenas.

A próxima revisão usa cpu_block_adapter.h, selecionado por DOLRECOMP_CPU_HEADER somente nesse chunk, sem editar o gerado. A decisão de CIA é constante no chamador: somente BC48, C014, C244 e C500 consultam a chave host; os demais guards FP mantêm o caminho original. native_blocks.c entra nos núcleos já validados, devolve somente o débito prévio ao guard (41, 20, 33 e 2) e conserva o orçamento de cada laço. C500 debita 2 antes dos stores e 56 em C508; não se devolvem 58 nesse ponto. Uma recusa restaura downcount e executa o guard/runtime original. Quando o lote termina, retorna ao chassi no PC resultante e continua a mesma fatia se ainda houver orçamento. Não cria exceção FPU nem muda a frequência guest. A reflexão chamada dessa rota deixa o epílogo para o chassi, evitando recursão do chunk.

Os testes de referência desativam explicitamente o adaptador. Rígido/blend também são executados com o adaptador automático, sem chamar o núcleo diretamente pelo teste. O probe isolado dessa rota passou em 7.680 casos blend e em 180 casos de reflexão com CPU/RAM/downcount inteiros iguais. A auditoria das cobranças consultou os próprios blocos gerados. A compilação final inclui a chave de diagnóstico como sexto campo opcional de runtime_tuning.cfg; quatro/cinco campos continuam válidos. Campos: quantum, workers, packed_copy, skinning, ram_inline (padrão 0), block_entries (padrão 1).

A ferramenta compare_native_blocks.py altera somente esse sexto campo, coleta A/B/B/A na mesma luta, rejeita log parado/encerrado, marca intervalos incompletos e restaura os bytes originais do arquivo em finally. Não escreve memória guest ou PAD. A comparação ainda está pendente do executável final validado; não há FPS atribuído a essa rota.


Validação final da rota automática: build completo Release em build_test/blocks_validation, saída 0 sem warnings; promoção conferida por SHA-256 11D10CC216E289D9BA717F5F9859FD48E3D7988FF8FA9243D4C8DB6D0B88C805. CTest canônico 4/4, inventário 204 objetos /GL e 10.838 nomes. As suítes software/OpenGL confirmaram 12.800 entradas automáticas, incluindo os testes rígido/blend com referência desativada e execução automática ativada. Os 447 vértices capturados continuam idênticos, checksum 8FE14D9B. PGO preservado em 4.245/4.256 funções e 92,7% das instruções ponderadas. O guard de reflexão foi auditado para devolver apenas as 2 instruções cobradas antes do store; o probe direto de 180 casos verifica esse orçamento. A reflexão nessa rota retorna seu PC ao chassi, sem chamar recursivamente o chunk.

Execução atual: runtime_blocks.log, mapa build_test/blocks_active.map, manifesto build_test/blocks_manifest.json. Sem compilador/coleta ativos, input físico e configuração de quatro campos 1024 1 1 1 (RAM=0, block_entries=1 por padrão). A chave blocks ocupa o sexto campo opcional; o log [Native RAM] inclui ambos os estados para permitir separar as amostras corretamente. Após carregamento físico da luta, compare_native_blocks.py fará a comparação na mesma instância, preservando as seleções e restaurando a configuração. Ganho de FPS e a meta de 60 em combate continuam pendentes de medição real.


Resultado da comparação da rota automática: native_blocks_comparison.json contém oito intervalos completos A/B/B/A repetidos, com 20 amostras por estado e restauração confirmada do arquivo original 1024 1 1 1. Medianas OFF/ON: 43,55/45,65 FPS; CPU+GX 22,55/21,50 ms. As médias FPS foram 44,03/45,09. A carga da luta variou, portanto não se atribui uma aceleração causal exata de 4,8% a essa diferença; o resultado favorece conservar a rota, sem demonstrar 60 FPS. Amostragem posterior separada em combat_blocks_profile.json, sem usar seu FPS como benchmark. O usuário informou taxa semelhante, talvez maior estabilidade.

O usuário destacou quedas com bolhas de drops, projéteis, ataques, movimentação e ambientação, pedindo atribuir primeiro o custo dos modelos. Nenhuma mudança específica nos efeitos foi aplicada. Foi solicitado um intervalo de luta com quatro personagens sem atacar/mover, sem pausar, antes de medir a janela com efeitos. A origem das quedas ainda não foi isolada.

capture_frame_cost.py acrescenta coleta somente por leitura do log: tempos CPU/GX, draws, bytes FIFO e deltas por VBlank dos contadores de acumulação, transformação, blend e reflexão. Esses contadores representam operações, não quantidade de modelos únicos; não se classifica um draw como efeito apenas por transparência. A captura pode ter rótulo informado pelo usuário; sem confirmação, permanece unclassified. blocks_frame_cost_history.json é somente histórico diagnóstico misto (inclui A/B e intervalos de sampler), não benchmark de uma carga controlada. A próxima coleta idle/effects ainda depende da confirmação física desse cenário. A janela runtime_blocks.log continua aberta, com a rota ativa e nenhuma compilação/amostragem em andamento.


### Quatro controles de teclado para isolar a carga (2026-11-01)

O usuário informou que não consegue manter os personagens parados com a configuração atual e solicitou um botão por controle em 7/8/9. A revisão acrescenta P2=7, P3=8 e P4=9 para A/confirmar; Shift+o mesmo número envia somente Start. As teclas equivalentes do teclado numérico também funcionam. P1 mantém teclado/controle SDL/joystick. As quatro portas de teclado estão conectadas, com sticks e botões neutros enquanto não houver teclas pressionadas. A escolha de humano/CPU continua sendo feita pelo usuário nos menus originais; nenhuma flag de IA foi alterada.

input.c/.h: helper puro para as três teclas, liberação por key-up/perda de foco, exclusão de A quando o acorde Start é usado e supressão de L/R do P1 quando Shift pertence a esse acorde. Acrescenta serialização dos quatro PADStatus de 12 bytes, erros individuais, máscara de canais conectados e limites de RAM sem overflow. As leituras SI de botões/sticks atendem as quatro posições. O primeiro controle físico SDL continua no P1; as novas portas são os atalhos de teclado solicitados.

test_main.c: PADRead deixou de preencher apenas P1 e forçar os outros três como desconectados. Agora copia os quatro estados físicos host, grava a estrutura guest big endian e retorna a máscara correspondente (F0000000 com os quatro conectados). O log mostra os quatro grupos de botões. input_poll registra alterações dos três controles extras; nenhum timer, auto-press, SDL_PushEvent ou injeção de PAD foi acrescentado.

platform_tests.c: contratos de independência das seis teclas (fila superior e numérico), ambos os Shifts, release, perda de foco, conservação do P1, quatro slots big endian, máscara/erro de desconexão e canários de limites. O probe isolado e as suítes completas passaram. Build completo Release em build_test/multiplayer_validation: saída 0 sem warnings; promoção validada por SHA-256 798ADA72C5ACCC25D960D7F42C1872EBFC9A1D78A550017C5D5C599552F08407. CTest canônico 4/4; inventário 204 objetos /GL, 10.875 nomes; os 447 vértices permanecem byte a byte iguais. PGO conservado em 4.242/4.256 funções e 92,7% das instruções ponderadas.

Execução atual: runtime_multiplayer.log, mapa build_test/multiplayer_active.map, manifesto build_test/multiplayer_manifest.json. Configuração 1024 1 1 1, RAM adapter=0, block entries=1. O usuário foi solicitado a testar os controles e assumir os demais personagens fisicamente. A medição idle/effects ainda depende desse teste; não se concluiu que o custo dos modelos foi eliminado. A referência exata anterior está em baseline_blocks_verified. A meta de 60 FPS em combate continua pendente.


### Medição com quatro jogadores humanos parados

O usuário confirmou os inputs P2/P3/P4 e carregou Jungle Ruins com todos sem comandos. multiplayer_idle_cost.json coletou 18 amostras sem compilador/sampler simultâneo: mediana 45,75 FPS, CPU+GX 21,455 ms, decode 3,38 ms, render 2,355 ms e copy 1,53 ms. O residual de CPU é uma estimativa de 13,8 ms; render/copy/decode estão contidos no total. Houve um intervalo de 50,09 ms/19,7 FPS ainda sem causa atribuída. A cena teve aproximadamente 143 draws/frame e 4.534 operações de reflexão/frame, constantes. Animações de idle e ambientação continuam ativas; isto não é uma cena congelada nem demonstra que só os modelos causam o limite. Confirma que ataques/projéteis não explicam sozinhos o gargalo básico. Nenhuma otimização específica de efeitos foi aplicada.

### Conclusão agrupada dos workers: experimento não aprovado como ganho

vertex_completion.c/.h implementa contador atômico de jobs e registro CAS do único consumidor. Somente o último worker sinaliza quando há consumidor esperando; se todos terminaram antes, não há chamada de espera nem sinal pendente. As barreiras SDL publicam os buffers antes da leitura pelo main. gx_pipe.c mantém as duas rotas, com o mesmo parser, dados, cálculos e espera por todos os jobs antes de continuar. A estrutura VertexDecodeJob não mudou, preservando os offsets da ferramenta de captura. platform_tests.c compara 212.992 vértices completos entre serial, sincronização antiga e agrupada, com wrap do FIFO e quatro arredondamentos. vertex_completion_contracts passou em 6.144 lotes com 0..3 workers, conclusões cedo/tarde, visibilidade, ausência de tokens sobrando e reinicialização.

Build completo Release validado em completion_validation: saída 0 sem warnings, promoção por cópia conferida por SHA-256 93FFE738720D27B7B93CE16BB5A7C8E97465E8C92F364018B1C92DAB624CAEEE. CTest canônico 5/5, inventário 205 objetos /GL e 10.887 nomes. Os 447 vértices capturados reais seguem idênticos. Manifesto completion_manifest.json. PGO conservado em 4.238/4.256 funções e 92,7% das instruções ponderadas.

O usuário voltou a deixar a luta parada. completion_comparison.json tem oito intervalos completos, 18 amostras OFF e 20 ON. Medianas OFF/ON: 46,9/48,2 FPS; CPU+GX 20,885/20,355 ms; decode 3,505/3,520 ms. Não houve redução no decode, que era a etapa visada; a diferença global de FPS não foi atribuída ao mecanismo. A rota antiga foi mantida via runtime_tuning.cfg = 1024 1 1 1 0 1 0. A implementação experimental/testes permanecem disponíveis, mas os defaults de código foram revertidos para OFF na próxima revisão em compilação. Campos 5/6/7 são RAM-inline, block-entries e conclusão agrupada. compare_native_blocks.py aceita --feature completion, mantém as outras flags e restaura o arquivo original.

### Pilhas nativas e polling de eventos

sample_stacks.c usa PROCESS_VM_READ/QUERY e contexto de thread, sem permissão de escrita. Suspende somente para copiar contexto e até 64 KiB da pilha; retoma antes de StackWalk64. Unwind usa essa cópia para dados da pilha e lê metadados das imagens carregadas; não usa servidor de símbolos. Foram coletadas 160 pilhas em idle_stacks.raw e rotuladas com o mapa correto em idle_stacks_labeled.json. Servem para atribuição qualitativa; o FPS durante a coleta não é benchmark.

As pilhas mostram esperas por SDL sob decode_vertices, por driver AMD sob GXCopyTex/pack YUY2 e chamadas XInput sob main. Não se classificou toda espera ntdll como worker. main chama SDL_PumpEvents a cada 2.048 fatias, embora o PAD seja atualizado pelo event loop/input_poll uma vez por quadro. A próxima revisão mede o tempo e o número dessas chamadas. Uma chave host permite comparar a rota original com polling interno limitado a checagens separadas por aproximadamente 8,3 ms; SDL_PollEvent no início do quadro permanece. Não altera botões, timebase, orçamento PPC, modelos, IA, animações ou efeitos. A comparação ainda está pendente; nenhuma melhora de FPS foi declarada para esse candidato. O novo oitavo campo da configuração controla esse experimento, com padrão OFF.


### Resultado do polling e do quantum na cena parada

Build instrumentado em pump_validation: saída 0 sem warnings, promoção conferida por SHA-256 7F5FD3608CDDBD48F11DE830C40DCE62E0BCE18408D7428D80BDBB0FF2AC41B3, CTest canônico 5/5, inventário 205 objetos /GL e 10.889 nomes. Os 447 vértices reais continuam byte a byte iguais. A nova telemetria [Host input] mede o polling interno dentro de CPU+GX; não deve ser somada novamente ao total. A conclusão agrupada tem padrão OFF no código e na configuração.

pump_comparison.json: oito intervalos completos, 20 amostras da rota original e 19 da limitada. Medianas OFF/ON: 47,75/49,0 FPS, CPU+GX 20,55/19,99 ms. Chamadas de SDL_PumpEvents: 49,0/2,0 por quadro; tempo medido 0,3745/0,0570 ms por quadro. Esse custo alvo foi reduzido diretamente em aproximadamente 0,318 ms; a variação global de FPS é maior e não se atribui integralmente ao polling. A chave foi mantida ativa na execução: 1024 1 1 1 0 1 0 1. O oitavo campo controla somente esse polling; padrões ausentes mantêm a rota original. Nenhum input foi simulado.

idle_quantum_comparison.json comparou 1024/4096 nessa mesma luta, com polling fixo ativo. Vinte amostras por estado, mesma mediana de 52,65 FPS. CPU+GX 18,575/18,600 ms, dispatches 42.498/42.209,5 por quadro. Não houve ganho: quantum 1024 foi restaurado, mantendo 675 mil ticks TB por frame. As duas janelas são diferentes no tempo; os 52,65 FPS não demonstram que o polling sozinho causou toda a diferença. Consulta somente de leitura ao contador de desempenho do processador indicou cerca de 170% da frequência base de 2,5 GHz na amostra; não foi alterada configuração do Windows.

### Coeficientes válidos recusados pelos núcleos dos modelos

sample_native.py agora permite filtrar snapshots pelo símbolo host e intervalo PPC. idle_model_guards.json coletou 16 contextos dentro de func_8024B4C0, excluindo os próprios núcleos SIMD. Em BC D0/BC58, a execução já estava dentro do corpo gerado do blend; a matriz constante f22 continha respectivamente 2,7624369067780208e-6 e 1,0892075806623325e-5. São float32 normais válidos menores que a guarda 2^-16. Isso identifica um motivo concreto para continuar no caminho escalar em determinadas poses. Não permite afirmar que explica todo o tempo restante ou que os efeitos já foram isolados.

A revisão seguinte amplia somente a guarda das matrizes para 2^-48..2^16 e dos resultados pendentes de store para 2^-126 até o máximo anterior. Entradas de posição conservam mínimo 2^-16; tipos GQR, escalas -16..16, spans, reservas/journal, caches/callbacks e exceções continuam restritos. Valores fora do domínio conservador permanecem no original. A função matemática e a ordem das operações são as mesmas.

Justificativa numérica: matrizes binary32 >=2^-48 são múltiplas de 2^-71; posições binary32 >=2^-16, de 2^-39. Produtos e somas intermediários ficam na grade 2^-110. Pesos U8 com escalas <=16 mantêm grade mínima 2^-16, portanto os resultados ponderados são múltiplos de 2^-126: zero ou float32 normal. O limite superior continua abaixo do overflow. Rounding para binary32 conserva essa grade. Stores de valores pendentes menores podem produzir valor subnormal/zero ao escalar, mas ambos quantizadores truncam para inteiro zero e não alteram o FPSCR arquitetural.

O probe isolado passou em 576 casos de blend/rígido/acumulação: coeficientes realmente observados, RAM/LC, NI, quatro arredondamentos, duas contagens e dois orçamentos. Compara CPUState completo, RAM/LC e downcount com o trecho gerado original; exige aceitação do núcleo novo e recusa do domínio anterior. Um caso de cancelamento produz exatamente -2^-126 em f11 e é comparado bit a bit, incluindo NI. Abaixo do piso novo (2^-49) ainda é recusado sem mutação. O adaptador fica desativado nas referências. A compilação e suítes completas dessa revisão estão em andamento, sem ganho de FPS atribuído ainda.

A chave de domínio ocupará o nono campo opcional, com padrão 1 para a faixa validada. A/B futura manterá as demais opções fixas. As ferramentas registram deltas dos contadores por VBlank para verificar cobertura, não apenas FPS. Nenhuma mudança específica de bolhas, ataques, projéteis ou ambientação foi aplicada.


Validação completa do domínio ampliado: build Release em domain_validation, saída 0 sem warnings; promoção por cópia conferida por SHA-256 1F9C7DE53A93643062481404568C83380A8BB4796A115CC6C3D7CE6A057DCDCD. CTest canônico 5/5, inventário 205 objetos /GL e 10.895 nomes. As suítes software/OpenGL passaram nos 576 casos novos, nas 212.992 comparações de vértices e nos demais contratos. Os 447 vértices reais continuam byte a byte iguais, checksum 8FE14D9B. PGO preservado em 4.237/4.256 funções e 92,6% das instruções ponderadas. Manifesto domain_manifest.json contém os hashes das fontes correspondentes.

Execução atual: runtime_domain.log, mapa domain_active.map. Configuração 1024 1 1 1 0 1 0 1, com domínio ampliado=1 quando o nono campo não está presente; conclusão agrupada permanece OFF, quantum 1024, polling limitado ativo. A referência anterior exata está em baseline_pump_verified. Foi solicitado o mesmo cenário de quatro jogadores humanos parados para A/B da guarda na mesma instância. Não há ganho de FPS confirmado para esse domínio até a coleta. A velocidade de ataques/projéteis e a atribuição restante entre modelos/ambientação continuam pendentes.


### Resultado do domínio e próximo custo de matrizes SDK

Na mesma luta parada, domain_comparison.json comparou oito intervalos completos, vinte amostras por estado: medianas OFF/ON 47,6/47,0 FPS e CPU+GX 20,565/20,655 ms. Não demonstrou ganho global. A cobertura blend aumentou de 1.316,4 para 1.377 operações/frame, e o caminho per-op caiu de 8,14 para zero. O domínio ampliado permanece matematicamente validado; não é apresentado como solução dos 60 FPS. A referência exata foi preservada em baseline_domain_verified.

A atribuição por amostras identificou PSMTX44Concat em 802B4D08 como a rotina SDK aritmética com mais ocorrências nessa coleta (139; contagem qualitativa, não porcentagem de tempo). sdk_signatures.py compara o checksum do código com totaldb.dsy do Dolphin fixado no checkout; os nomes são candidatos até conferir as instruções. Foram auditadas as 65 instruções de 802B4D08..802B4E08 e capturados 16 conjuntos de ponteiros reais, todos com saída sem sobreposição aos inputs.

sdk_mtx44.c implementa multiplicação 4x4 com as quatro etapas na ordem original: multiply e três FMA. Aceita float32 zero/normal até 2^16, preflighta cada resultado intermediário e recusa subnormais antes de alterar CPU/RAM. Preserva as lanes FPR/PS1 voláteis, último FPRF, endereço de retorno e débito de 65 instruções. Mantém fallback para overlap de saída, estados excepcionais, GQR não float, reserva/journal/cache callback e memória fora do span direto. Não muda CPUState, layout guest ou fontes geradas. A guarda privada de dois chunks alcança também gotos locais; a rota desfaz somente o débito já feito no guard antes de executar o núcleo.

O teste isolado passou em 4.096 comparações integrais CPU/RAM/locked cache/orçamento com o corpo original extraído automaticamente pelo CMake, além de 18 recusas sem mutação; cobre NI, quatro arredondamentos, mínimos normais, cancelamento, aliases e subnormais intermediários. O original da referência permanece com o adaptador desativado. A integração no executável e a medição real ainda estão em validação. O décimo campo opcional m44 permite comparação na mesma luta; os outros campos são preservados. Nenhum comportamento de efeitos/ataques ou input automático foi acrescentado.


Validação da concatenação SDK: build Release completo em mtx44_validation, saída 0 sem warnings; artefato promovido por cópia com SHA-256 2810D2BA2003D2E08B924802C2CDBBA562C86344846C22F53BFE406884E9E07A. CTest canônico 6/6, inventário 206 objetos /GL e 10.918 nomes. Além das 4.096 comparações isoladas e 18 recusas, as suítes completas verificaram 32 chamadas ao chunk real com adaptador automático versus original desativado: CPU/RAM/LC/downcount iguais e contadores confirmando a entrada. Os 447 vértices reais continuam byte a byte iguais, checksum 8FE14D9B. PGO conservado em 4.237/4.256 funções e 92,6% das instruções ponderadas.

Execução reaberta: runtime_mtx44.log, mapa mtx44_active.map, manifesto mtx44_manifest.json. Sem compilador ou coleta de perfil ativos. Input exclusivamente físico. Foi solicitado o mesmo cenário de quatro humanos parados para comparação m44 na mesma instância; desempenho global desta revisão ainda não medido. A referência anterior está em baseline_domain_verified. A meta de 60 FPS em combate e a atribuição do custo dos efeitos continuam pendentes.


Retomada em 2026-11-02: o processo anterior tinha recebido SDL_QUIT. Reaberto o mesmo executável validado, agora em runtime_mtx44_resume.log, sem rebuild ou alteração de configuração. Aguardando seleção física de quatro humanos em Jungle Ruins para comparação m44 ligada/desligada. O histórico runtime_mtx44.log varia aproximadamente entre 46 e 60 FPS com draws/carga diferentes; não comprova ganho causal nem correção da queda com quatro personagens. Não há compilador ou profiler concorrente.


### Medição m44 e custo do decoder (2026-11-02)

O usuário confirmou quatro humanos parados em Jungle Ruins. mtx44_comparison.json contém oito intervalos completos A/B/B/A, 19 amostras OFF e 20 ON; configuração original restaurada. Medianas OFF/ON: 47,9/49,45 FPS, CPU+GX 20,46/19,805 ms, residual estimado de CPU 12,77/12,15 ms. O contador confirmou 0/659,5 concatenações rápidas por VBlank. A carga variou um pouco (reflexão 6.710/6.778, transformações 5.613/5.774 por quadro), portanto não se atribui uma aceleração exata à diferença global. Mantida a rotina; 60 FPS em combate não foi atingido.

Após encerrar a medição, combat_mtx44_profile.json coletou oito segundos de amostras read-only, sem usar o FPS desse intervalo como benchmark. decode_vertex/run_vertex_job/shade_vertex e esperas associadas continuam relevantes, além de mem_read32 e trabalho PPC distribuído. O PC guest 802CCA84 corresponde à escrita que alimenta GX; não é uma função guest que consome sozinha todas as amostras atribuídas ao renderizador. Não se concluiu que o custo dos modelos desapareceu.

Uma captura real adicional, combat_four_players_mtx44.gxvd, registra 594 vértices completos do executável atual e seus dados para comparação futura. Contém RAM do jogo e é apenas artefato local de teste. Próximo candidato: evitar as cópias temporárias dos atributos GX quando o span FIFO/RAM é válido e contíguo, mantendo o caminho anterior para wrap/limites. Não altera cálculos de posições, normais, textura, iluminação, TEV, comandos ou efeitos. A chave host attrs ocupará o décimo primeiro campo opcional para A/B na mesma luta. Validação e desempenho desse candidato ainda pendentes.


A validação preliminar de attrs passou nos 24.576 casos e nas suítes software/OpenGL. As capturas reais de 447 e 594 vértices foram idênticas, checksums 8FE14D9B e 632257F1. Foi detectado C4018 somente no laço do teste (comparação do índice unsigned com promoção signed de normal_indices); corrigido com conversão explícita para u32/1u. O link final sem esse aviso está em andamento. Não foi promovido o artefato preliminar. Este build altera a forma do decoder e o PGO informou 77,6% de instruções ponderadas com perfil utilizável, abaixo dos 92,6% da referência; qualquer comparação deverá considerar também essa mudança de cobertura do perfil. Nenhum ganho do decoder foi declarado.


Validação final de attrs: build completo Release em attrs_validation, saída 0 sem warnings (build_attrs_final.log); promoção por cópia conferida por SHA-256 3E7BF347C4A221C3D9EEF777B2F47B8234070A6A5B52D6D9893098FFED7427B2. CTest canônico 6/6, inventário 206 objetos /GL e 10.906 nomes. Suítes software/OpenGL passaram nos 24.576 casos novos, além dos contratos anteriores. As duas capturas reais totalizam 1.041 vértices byte a byte iguais, checksums 8FE14D9B e 632257F1. PGO reutilizável: 4.236/4.256 funções, 77,6% das instruções ponderadas; a função alterada não conserva todas as contagens anteriores.

Execução reaberta em runtime_attrs.log, mapa attrs_active.map, manifesto attrs_manifest.json. Sem compilador/profiler ativo. Configuração original de oito campos mantida; domain/m44/attrs ausentes têm padrão 1, conclusão agrupada OFF. Décimo primeiro campo controla somente a leitura de atributos; compare_native_blocks.py --feature attrs preserva as demais chaves e restaura o arquivo. Foi solicitado carregamento físico da mesma luta. Desempenho ainda pendente; não se afirma correção dos 60 FPS. A referência anterior exata está em baseline_mtx44_verified.


Resultado de attrs: o usuário confirmou imagem correta. attrs_comparison.json coletou oito intervalos completos, 19 amostras por estado; medianas OFF/ON 43,2/42,9 FPS e CPU+GX 22,68/22,77 ms. O decoder medido caiu de 3,87 para 3,72 ms, mas a carga variou e não houve melhora global consistente. Não é apresentado como solução dos 60 FPS.

Na mesma instância, attrs_workers_comparison.json comparou a execução serial com três workers (20 amostras por estado): 46,65/48,45 FPS, CPU+GX 20,985/20,20 ms, decoder 4,255/3,535 ms. Os contadores confirmam 0/15 lotes paralelos por quadro. As contagens blend/rígido/acumulação/reflexão ficaram constantes entre estados (1.465/3.988/4.758/4.480). Mantido parallel=1. A ferramenta deriva o estado observado pelo delta de lotes, rejeitando intervalos sem confirmação; não supõe que a chave foi aplicada apenas por escrever o arquivo. Arquivo original restaurado. A cena parada ainda anima personagens/ambientação.

combat_attrs_bounds.json coletou novo perfil separado da medição. Auxiliares dolrecomp_f32_from_bits/to_bits seguem frequentes (124/51 amostras nessa coleta qualitativa). A próxima revisão usa forced-include somente em 14 chunks quentes, sem editar gerados, com wrappers curtos de operações inteiras para os casos comuns. Mantém os helpers originais nos casos especiais e pode ser desligada pelo décimo segundo campo host. O teste isolado passou em 2.359.296 pares de conversão: fronteiras de todos os expoentes/sinais, payloads aleatórios, quatro arredondamentos, FTZ/DAZ e MXCSR inalterado. A referência dos testes é extraída literalmente do generated.h pelo CMake; não cria stubs de funções guest. O link inicial do alvo isolado foi corrigido para incluir somente esses helpers, evitando dependências do dispatcher completo. Integração com chamadas reais ao chunk e build completo ainda em validação; sem ganho de FPS declarado.


Validação final dos wrappers de conversão: build completo Release em float_validation, saída 0 sem warnings; promoção por cópia conferida por SHA-256 FD41FCFD4258A2A43173F59306CA770548370192406F7C32BC2D2E90842C6140. CTest canônico 7/7, inventário 207 objetos /GL e 10.956 nomes. O teste isolado compara 2.359.296 pares com os helpers extraídos literalmente do generated.h e verifica flags host inalteradas. As suítes software/OpenGL também comparam 768 execuções do chunk real 802774C0 na entrada 80278CC4 (loads/stores e multiplicações de seis floats), com otimização desligada/ligada, RAM cached/uncached/LC, quatro arredondamentos, NI, dois orçamentos, zeros/sinais/subnormais/infinitos/NaNs e CPUState inteiro iguais. Os 1.041 vértices capturados continuam byte a byte iguais.

CMake aplica /FIgenerated_float_adapter.h somente a 14 chunks quentes, preservando os adaptadores CPU privados por arquivo. O header inclui as definições originais antes de redirecionar as chamadas subsequentes; nenhuma edição no gerado ou CPUState. Casos comuns usam mapeamento inteiro curto; casos especiais preservam o helper original. Não usa casts FP que mudariam NaNs/FTZ ou arredondamento. PGO manteve 4.236/4.256 funções e 77,6% das instruções ponderadas, igual à revisão attrs.

Execução reaberta em runtime_float.log, mapa float_active.map, manifesto float_manifest.json. A chave fbits é o décimo segundo campo opcional, padrão 1. Demais opções fixas (parallel=1, completion=0, quantum=1024, pump=1, domain/m44/attrs=1); arquivo original de oito campos permanece válido. Sem compilação/perfil ativo, input exclusivamente físico. Foi solicitado carregar a mesma luta para A/B; ainda não há ganho de FPS confirmado. Referência anterior exata: baseline_attrs_verified. 60 FPS com quatro jogadores em combate continua pendente.


### Conversão experimental rejeitada; auditoria CPU/GPU (2026-11-02)

float_comparison.json: oito intervalos completos, vinte amostras por estado, medianas OFF/ON 51,95/50,25 FPS e CPU+GX 18,82/19,46 ms. As contagens dos laços de skinning foram constantes, mas houve variação de dispatches e cópias de imagem; não houve ganho consistente. A rota experimental foi desativada na configuração e DIGIMON_NATIVE_FLOAT_BITS passou a OFF no CMake, com flag de disponibilidade compilada que impede ativar um caminho ausente. Os testes matemáticos permanecem, mas não há otimização de FPS atribuída a eles. A referência executável atual, com a chave desligada, foi preservada em baseline_float_disabled_verified.

Divisão real do port:

| Etapa | Execução |
|---|---|
| Jogo PPC, scripts, física/colisões, threads OS, DVD, PAD e AX | CPU; preserva os estados e efeitos observáveis pelo guest |
| Skinning que escreve vértices na RAM/locked cache | CPU SIMD; não foi transferido para shader nesta revisão |
| Parser FIFO, atributos/indexação/endian e cache de vértices | CPU; prepara os dados enviados ao backend |
| Projeção, iluminação e texgen/pós-matrizes | Nova rota vertex shader OpenGL em validação; rota CPU preservada como referência/fallback |
| Rasterização, 16 estágios TEV, oito texturas, blend/depth/clip | GPU pelo OpenGL nativo |
| Decodificação de formatos de textura/TLUT em cache | CPU com upload SDL/OpenGL |
| Packing YUY2 | Shader GPU quando suportado; leitura posterior preenche o XFB guest |
| Cópias EFB para texturas tiled e memória guest | Incluem sincronização/readback e codificação CPU; não se omitem as escritas que o jogo pode ler |
| SDL input e mistura AX/áudio | CPU |

Mover lógica, disco e áudio integralmente para GPU não é requisito de um port nativo. A mudança em desenvolvimento aborda o custo gráfico real que permanecia na CPU, sem retirar lógica ou efeitos da simulação.

### Rota XF no vertex shader

GXGLRawVertex é um buffer host separado: posição, normal, atributos de textura, cor e índices de matrizes. QueuedVertex e QueuedDraw mantêm seus formatos, preservando capturas e replay antigos. Cada draw guarda um snapshot XF próprio; o shader aplica matrizes de posição/normal, projeção/viewport, iluminação por canal e oito gerações de textura/pós-matrizes. O fragment shader TEV permanece o mesmo. Sem capacidade GPU, com arredondamento host não nearest ou durante uma captura de referência, o parser usa a rota CPU anterior. A memória e os registradores guest não mudam.

Os workers recebem ponteiros adicionais somente no final da estrutura privada, mantendo o prefixo antigo. O cache raw é separado do cache CPU, e todas as tarefas terminam antes da apresentação ou mudança de parâmetros. A suíte software passou em 425.984 comparações de vértices CPU/raw, serial/sincronizações, índices repetidos, wrap e quatro arredondamentos. A ferramenta de snapshot reconhece o novo mapa e recusa capturar jobs raw como se fossem saídas CPU.

O teste isolado de GPU compara oito framebuffers completos, exige pixels realmente preenchidos e faz transform feedback. A suíte maior comparou 384 vértices em doze cenários: matrizes nos extremos, projeção com w normal/zero/negativo, luz difusa/spot, oito texgens e pós-normalização. Cores foram iguais; diferenças máximas sintéticas de posição ~1,5e-7 e textura ~6e-8. Nas capturas reais de 447/594 vértices, cores e texturas foram iguais e diferenças máximas de posição 7,63e-6/5,72e-6. São medidas de precisão do backend gráfico, não equivalência bit a bit de CPU nem ganho de FPS.

A validação detectou GL_RASTERIZER_DISCARD deixado ativo pelo próprio teste de transform feedback: GL_ALL_ATTRIB_BITS não restaurou esse estado moderno. Corrigida restauração explícita e acrescentada verificação de pixel não vazio. O executável preliminar não foi promovido; link final e repetição integral dos testes estão em andamento. A rota nova ainda não foi medida em combate e 60 FPS continua pendente.


### Revisão do driver, texturas e I/O — 2026-11-07

Patch validado em `build_test/Release/digimon_test.exe`. SHA-256: `C9E966A341BB21A203FA6BB040CF5F6AD2BAE7701991B7008D34C8C6FEF61C11`. Build saída 0 sem warnings, CTest 8/8, inventário 207 objetos /GL e 11.120 nomes. FPS com Mega/digivolução ainda depende de reprodução física; não foi declarado 60 FPS em combate.


Detalhes por arquivo, limites e validação em GRAPHICS_DRIVER_AUDIT.md. VBO circular/orphan/map sem sync, cache de geometria por conteúdo, mapa de texturas LRU com update in-place, uniforms XF por bloco e locations do pack guardadas, cópias GPU dos 13 formatos e worker DVD SDK/DI. As escritas EFB/XFB guest e o skinning SIMD continuam preservados. FPS Mega/efeito azul pendente de reprodução física.
Manifesto: build_test/driver_manifest.json; execução: runtime_driver.log; mapa: build_test/driver_active.map. Referência anterior: baseline_gpu_xf_verified.


### VRAM-only I4 e streaming sem hash � 2026-11-07

Execut�vel validado e aberto: build_test/Release/digimon_test.exe, SHA-256 `5A3C84EEF5F1723E2453AB8268A5FF22D206873B73B0E7F9D208DD8D09C3F129`. Build sa�da 0 sem warnings; CTest 8/8; invent�rio 207 objetos /GL, 11.149 nomes no mapa. Manifesto build_test/vram_manifest.json, mapa vram_active.map, execu��o runtime_vram.log. Refer�ncia anterior preservada em baseline_driver_verified.

GXCopyTex I4 64�64/stride256 agora usa somente a textura GPU, sem readback nem escrita guest, conforme o contrato de consumo de textura informado pelo usu�rio. As demais c�pias mant�m materializa��o. Slots pendentes s�o protegidos, at� 64; captura, desligamento e aliases incompat�veis resolvem RAM. N�o existe intercepta��o geral de leituras CPU arbitr�rias. Teste integrado confirmou RAM inalterada, contador de readback inalterado, amostragem GPU correta e materializa��o tiled ao desligar.

Cache integral de geometria desligado por padr�o: raw segue ao ring UNSYNCHRONIZED sem hash/memcmp do mesh. Cache de �ndices dentro do draw preservado. Listas independentes adjacentes com material/XF id�nticos s�o agrupadas sem reordenar. Raw n�o limpa/copia a estrutura de proje��o CPU n�o utilizada. 24.576 compara��es de atributos e 425.984 v�rtices serial/workers CPU/raw aprovados; teste GPU confirma streaming sem hash e framebuffer de listas agrupadas; replay de combate id�ntico byte a byte � refer�ncia anterior.

Configura��o ao vivo: campos 14 VRAM-only (padr�o1), 15 cache de geometria (padr�o0). Novos contadores GL incluem merges, hashes, streams, c�pias VRAM-only, materializa��es e pend�ncias. No prompt inicial: geometry_hashes=0, geometry_hits=0 e dynamic_streams acompanhando draws, confirmando bypass ativo; isso n�o mede combate. Refer�ncia antiga: mediana ~133 draws e8 readbacks/frame,44,85FPS. Ganho na luta e60FPS ainda pendentes de teste f�sico; solicitada reprodu��o com quatro humanos, sem inje��o de input.


### VRAM-only I4 e streaming sem hash - 2026-11-07

Build final: saida 0, sem warnings; CTest 8/8; inventario 207 objetos /GL e 11.149 nomes. SHA-256: `5A3C84EEF5F1723E2453AB8268A5FF22D206873B73B0E7F9D208DD8D09C3F129`. Manifesto: build_test/vram_manifest.json; mapa: build_test/vram_active.map; runtime: runtime_vram.log. Baseline anterior preservada.

GXCopyTex I4 64x64/stride256 usa somente VRAM, sem readback ou escrita guest, conforme contrato de consumo informado pelo usuario. Demais formatos/tamanhos preservam materializacao. Slots pendentes protegidos, limite64; captura/desligamento/aliases incompativeis resolvem RAM. Nao ha interceptacao geral de leituras CPU arbitrarias. Teste integrado confirmou RAM e contador de readback inalterados, amostragem GPU e materializacao tiled corretas.

Cache integral de geometria OFF por padrao: raw segue direto ao ring UNSYNCHRONIZED sem hash/memcmp do mesh. Cache de indices dentro de um draw preservado. Agrupamento conservador de listas consecutivas com material/XF identicos, sem reordenacao. Raw evita limpar/copiar a estrutura de projecao CPU inutilizada. 24.576 comparacoes de atributos e 425.984 vertices CPU/raw/serial/workers aprovados; teste GPU confirma bypass de hash e framebuffer de listas agrupadas; replay de combate identico byte a byte.

Config campos14/15: VRAM-only=1, cache geometria=0. Telemetria inclui draws, merges, hashes, streams, copias VRAM, materializacoes e pendencias. Prompt inicial confirma geometry_hashes=0 e dynamic_streams ativo. Referencia anterior: ~133 draws e8 readbacks/frame,44,85FPS mediano. Ganho em combate e60FPS pendentes de reproducao fisica; solicitados quatro humanos em Jungle Ruins. Nenhum input automatico. Detalhes: GRAPHICS_DRIVER_AUDIT.md.


### Cache VBO restaurado + cinco timers QPC - validado 2026-11-07

Release ativo SHA-256 `8658394B43CD043AC554D81BED0D39652EFFADDCF99CDC1C75DDA12673D78F2F`; build_timing_release.log saida0 sem warnings, CTest8/8, inventario208 objetos /GL e11.177 nomes. Mapa: build_test/timing_active.map; manifesto: build_test/timing_manifest.json. Execucao: runtime_vram.log; log anterior preservado em build_test/runtime_vram_before_timers.log.

Cache VBO ON por padrao e configuracao, mantendo I4 64x64 VRAM-only. Registro confirmou geometry_cache=1 e geometry_hits aumentando, com dynamic_streams=0. Cache do backend evita repacking/upload; decode GX anterior permanece.

frame_timing.c/h mede diretamente QPC no Windows. [Frame60] a cada60 frames: cpu_game_logic_ms, cpu_gx_decode_ms, gl_draw_submit_ms, gl_efb_copy_ms, gl_swap_wait_ms. Campos adicionais host_other_ms/host_pacing_ms fecham a soma com frame_wall_ms. Zonas aninhadas exclusivas separam flush/draws de copies; workers nao somados em paralelo. Contrato sintetico de60 quadros aprovado e soma dos registros reais conferida com erro de arredondamento menor que0,0005ms.

Escopo: game inclui loop recompilado/despachante/HLE fora de GX; decode inclui parser/DL, atributos, texturas e hash/repacking VBO; submit inclui backend/driver e upload/apresentacao XFB; copy inclui GXCopyTex e GXCopyDisp/XFB; swap mede SDL_RenderPresent/SwapBuffers, nao o limitador de60Hz (campo pacing separado). Sao tempos de parede CPU/espera, nao timestamps de execucao GPU.

Release /O2 /USEPROFILE confirmado; nenhuma flag GENERATE/PGI e nenhuma importacao pgort/pgoboot. stdout64KiB bufferizado; novo resumo descarregado a cada60 frames e resumo legado por segundo, sem flush por frame/draw no caminho normal. Teste fisico de quatro humanos solicitado; nenhuma alegacao de60FPS em combate ou novos tempos de luta antes da reproducao.


### Medicao real de quatro humanos em Jungle Ruins - 2026-11-07

Usuario confirmou luta aberta. Captura de20s,16 janelas de60 quadros (960 frames), sem compilador, amostragem ou alternancia de configuracao durante a captura. Artefatos: build_test/frame60_combat_capture.log e frame60_combat_summary.json.

Medias QPC exclusivas por quadro: cpu_game_logic_ms=13,01564; cpu_gx_decode_ms=4,32976; gl_draw_submit_ms=2,47194; gl_efb_copy_ms=1,66834; gl_swap_wait_ms=0,10189; host_other_ms=0,09181; host_pacing_ms=0,00029; frame_wall_ms=21,67968. Media do indicador FPS=46,235. Janelas variaram de19,03 a25,20ms. Faltam aproximadamente5,01ms por quadro para o orcamento de16,67ms.

Por quadro:135,72 draws OpenGL;112,84 hits de geometria (83,1%);7,99 copias I4 VRAM-only;0 materializacoes;0 readbacks de TEXTURA;0 compilacoes de shader;0 consultas de uniforms. GXCopyDisp/XFB ainda inclui sua copia/readback no campo EFB de1,67ms: zero readbacks de textura nao significa zero readbacks totais. Cache ON e VRAM-only efetivamente ativos.

O maior grupo medido e execucao recompilada/runtime fora do GX (~60% do tempo), seguido do decode GX (~20%). O submit OpenGL nao explica sozinho o deficit de5ms. Esta medicao nao identifica uma unica funcao de jogo responsavel pelos13ms.

Apos encerrar a captura de FPS foram feitas amostragens separadas, sem escrita guest/input: frame60_combat_native_profile.json (3.761 amostras) e frame60_combat_stacks.txt (318 pilhas; simbolizacao em frame60_stack_summary.json, mapa timing_active.map). Custos distribuidos entre chunks recompilados, mem_read32/mem_write32 e auxiliares float; dentro do GX aparecem decode_vertex/run_vertex_job e espera de workers. PC802CCA84 corresponde a escrita no registrador CP que dispara processamento GX, e nao a uma funcao de IA lenta; contagem inclusiva de PC nao deve ser confundida com custo exclusivo. Amostragem tem limites estatisticos e perturba a execucao: seus FPS nao entram na referencia acima.

Nenhuma nova otimizacao especulativa nem mudanca de flags aplicada apos a medicao. Executavel e configuracoes mantidos; janela preservada.60FPS em combate ainda nao atingidos.


### XFB GPU + cache anterior ao decode + caminhos RAM/float - validado 2026-11-07

Release ativo: SHA-256 `1D4BE9633DA366A79024C3A2B0C8D5CAA523C2DA34DFA19EECD94F952669B68E`; build_xfb_clean.log saida0 sem warnings; CTest8/8; inventario208 objetos /GL e11.523 nomes. Manifesto build_test/xfb_manifest.json; mapa xfb_active.map; runtime_vram.log. Referencia anterior preservada em timing_validation/timing_active.map e runtime_before_xfb_gpu.log.

Implementacao detalhada na secao XFB GPU de GRAPHICS_DRIVER_AUDIT.md. XFB usa snapshots GPU por endereco e VI real, somente no gameplay; YUY2/RAM materializados ao desligar/sair da luta/capturar. Cache anterior ao decode valida FIFO, CP e arrays RAM por hash+assinatura completa, reutiliza atributos raw e hash VBO; invalidacao por RAM/FIFO testada. Raw draws menores que4096 vertices dispensam workers; novos contadores GX60 separam key/main/wait/hash/lookup/repack. Cache VBO e I4 VRAM mantidos.

RAM principal32 inline nos chunks usa bounds e byteswap, preservando MMIO, aliases, reservas e journal (2.436 casos). Float finito une atualizacoes FPSCR e mantem referencia para especiais (131.072 comparacoes completas CPU/flags/excecoes host). Nao houve remocao semantica de FPSCR nem /fp:fast global. Runtime /O2 /Ob3 /Oi, chunks /O2 /Oi e helpers pequenos forceinline. Sem PGI nem importacao do runtime de coleta.

Testes integrados incluem425.984 vertices CPU/raw/serial/workers, cache com mutacoes reais, XFB independente por alocacao e materializacao YUY2;8/8 aprovados. Na primeira validacao o proprio teste XFB deixava pixels no EFB, detectado pelo teste seguinte; corrigida restauracao do EFB e estado SDL no teste. Replay de referencia permaneceu identico. No prompt inicial da execucao nova, cache de decode confirmou hits e vertex_main_ms/worker_wait_ms zerados em pacotes reutilizados; nao e medicao de combate.

Config opcional16 XFB VRAM solicitado=1 (efetivo scene4),17 cache decode=1. Nova medicao de960 frames em Jungle Ruins com quatro humanos solicitada e pendente de confirmacao fisica; nao ha alegacao de<15ms ou60FPS nesta revisao.


### Diferencial idle/acao e AABB nativo - 2026-11-07

Release atual SHA-256 `B4380734C9346DEA1B55FD5255638BED15A88EC3918E418969ED372EC5A5270A`; mapa `build_test/motion_active.map`, manifesto `build_test/motion_manifest.json`. Build `build_motion_release.log` saida0 sem warnings, PGO USE sem coleta; CTest9/9 em `test_motion_ctest.log`.209 objetos /GL,11.501 nomes no mapa; sem runtime PGI importado.

Mesma luta, modos11 fixos,360quadros por janela antes do patch: idle GAME11.392ms/GX3.043ms; acao GAME13.358ms/GX3.150ms; submit1.808/1.926ms; EFB0.115/0.120ms. Cache123hits/15misses idle versus124.07/21.44acao. Hash0.053ms em acao; espera workers~0.0006ms. Nao ha evidencia de explosao de misses ou espera dominante. Profiler separado e estimativas por funcao em ULTIMATE_CPU_PROFILE.md, com artefatos JSON.

Novos HLEs completos80276CC0(expansao AABB por ponto) e80276D6C(uniao AABB), acionados tambem intrachunk pelo adapter FPU de802734C0.2.560 comparacoes completasCPU/RAM incluem aliases,signedzero,CR/FPSCR,PS1 e downcount; especiais/budget insuficiente fazem fallback. Mantidos1.920 testes dos planos/AABB. Travessia BVH80275528 permanece original: seu custo estimado nao cresceu no diferencial(0.255->0.227ms); dispatcher ja e tabela diretaO(1).

Dirty tracking agora64B, com shadow de RAM para refinar os4KB reportados pelo Windows. Escritores gerenciados marcam inline; GetWriteWatch uma chamada por hostframe, nunca no lookup GX. Escritas em outra linha64B da mesma pagina4KB nao invalidam atributos; escritas externas observadas na barreira seguinte. Custos de memoria adicionais:24MiB shadow +3MiB geracoes para24MiB de RAM. Chave GX remove estados CP nao usados, conserva layout/indices/arrays/FIFO e assinatura integral validada apos hash. Testes de falsocompartilhamento/CP irrelevante e invalidacao real passaram em software/OpenGL.

Input permanece fisico, fast_float=1 e dirty_tracking=1 no cfg, cache VBO e I4/XFB em VRAM preservados. Sem alteracao em generated/. Medicao de combate deste novo binario ainda depende de entrada fisica; nao se alega60FPS ou novo tempo apos patch.


### Diferencial idle/acao e AABB nativo - 2026-11-07

Release SHA-256 `B4380734C9346DEA1B55FD5255638BED15A88EC3918E418969ED372EC5A5270A`; mapa `build_test/motion_active.map`; manifesto `build_test/motion_manifest.json`. Build saida0 sem warnings, PGO USE sem coleta; CTest9/9 em `test_motion_ctest.log`.209 objetos /GL e11.501 nomes no mapa.

Janelas360quadros/mode11: GAME11.392->13.358ms, GX3.043->3.150ms, submit1.808->1.926ms, EFB0.120ms na acao. Cache123/15 hits/misses idle e124.07/21.44 na acao. Hash0.053ms, espera workers~0.0006ms na acao. Perfis independentes e top10 incrementos em ULTIMATE_CPU_PROFILE.md.

HLEs completos80276CC0(expansao AABB por ponto) e80276D6C(uniao), incluindo entradas intrachunk:2.560 comparacoes CPU/RAM com aliases,signedzero,CR/FPSCR,PS1,downcount. Mantidos1.920 casos dos planos/AABB. BVH80275528 permanece original: estimativa nao cresceu(0.255->0.227ms). Dispatcher ja usa tabela diretaO(1).

Dirty tracking64B nos escritores gerenciados + shadow24MiB e geracoes3MiB; GetWriteWatch uma vez por hostframe e refinamento das paginas4KB em linhas64B realmente alteradas. Escritas vizinhas em outra linha nao invalidam vertices. Escritas externas observadas na barreira seguinte. CP key inclui apenas layout/indices/arrays usados, mantendo FIFO e comparacao integral apos hash. Testes de false sharing/CP irrelevante/invalidacao real passaram software/OpenGL.

Input fisico e cfg11 preservados; VBO/I4/XFB GPU mantidos; generated/ intacto. Novo tempo em combate pendente de entrada fisica, sem alegacao de60FPS nesta revisao.


### Rollback64B, FIFO e pacing - 2026-11-07

Release `303168CC3AD10EF68F00DBF36BFBCBE345C6806323B6EDAC3B69BDF41D261BFC`, mapa fifo_active.map, manifesto fifo_manifest.json. PGO USE sem coleta; build0 sem warnings; CTest9/9;209 objetos/GL e11.538 nomes. Removidos geracoes64B/shadow; tracking4KB com uma GetWriteWatch/frame. FIFO transporta blocos e nao reinterpreta pacotes vinculados incompletos:578linhas/3parses no teste,mas contador0deferrals no combate predominantemente nao vinculado. VSync0 confirmado; pacer sem espera extra apos atraso validado.

960quadros atuais:GAME14.938ms/GX3.345ms/submit2.280ms/EFB0.118ms/swap0.068ms/quadro20.893ms. Anterior64B:GAME16.653ms/quadro22.528ms; acoes variaveis impedem alegar ganho causal. Top15 total exclusivo/inclusivo parcial e todas as limitacoes em CPU_TOTAL_FIFO_REPORT.md. Nao e60FPS; thread CPU/GX continua sincrona, input fisico preservado. Pilhas/amostragem separadas dos timers.


### HLE/inline compacto e worker GX raw - 2026-11-07

Release `DAECE957DB16E34B848EAB58A8F1487CB3B92DF88A308AD0C849CB1CA438B184`; mapa async_active.map; manifesto async_manifest.json. Build0 sem warnings, PGO USE, CTest12/12,214objetosGL/11.653nomes. Novos nucleos em tres funcoesTop10(copias matriciais),floor8029D888 e vetores8028BEDC/BF58; comparacoes completasCPU/RAM aprovadas. Helpers compactos forceinline em todos os chunks, referencias/excepcionais fora de linha.

Worker captura comandos+atributos imutaveis no parser comum, incluindo FIFO nao vinculado; prepara raw vertices de misses enquantoCPU segue. Cache hits preservados. EventosPE/EFB/copia e reuso de output aguardam pendencias; GL fica na main. Codigo/cfg async=1 por padrao,campo20 controlaA/B. Timers worker/wait/snapshot separados. Detalhes/limites em ASYNC_GX_HLE_REPORT.md; novo desempenho em combate ainda nao medido. Tracking4KB e inputfisico mantidos.


### Correcao de reutilizacao intradraw do worker - 2026-11-07

Release `221D241B852DE1A8B5FA465F04A3EC510E5F3477B2570A035849816127328DDC`; mapa async_reuse_active.map; manifesto async_reuse_manifest.json. Build0 sem warnings, CTest12/12,214objetosGL/11659nomes. Primeira captura confirmou jobs/HLE ativos mas quase todo1.02ms de worker virava espera0.96ms. Cargas on/off variaram; coletor relia42MB/log a cada250ms e foi corrigido para seek/tail. Nao se alega ganho de FPS com essas janelas.

Worker agora preserva tambem cache intradraw de vertices indexados:64vertices/4combinacoes deram4misses/60hits e output identico, incluindo reutilizacao de RAM/CP/FIFO antes de agendar. Novos contadores de reuse/drains/peak. Async=1 mantido no codigo/cfg; nova comparacao idle pendente. Detalhes/medidas/ressalvas em ASYNC_COMBAT_FIRST_RESULTS.md.


### Recursos imutaveis e barreiraTLUT - 2026-11-07

Release `408A7829D11811A4EF9D187C02934483D30E31EED64293F9EB4D2E7A52AC0002`; mapa images_active.map; manifesto images_manifest.json. Build0 sem warnings, PGO USE, CTest13/13,215objetosGL/11712nomes. Pilhas confirmaram flushBP65 como11de17esperas observadas. Novo gx_images.c preserva fontes e paletas por versao; BP65 pode adiar flush com dados imutaveis. ChaveGPU64bit por identidade evita reupload/hash repetido. EFB/PE/I4VRAM continuam ordenados, sem readback novo.

Testes incluem reutilizacao simultanea de pixels e paleta antes deCopyDisp e lookup sem syscalls. Replay17batches identico antes/depois, formatoQueuedDraw preservado. Cfg20async=1,21immutable_images=1; novos contadores deTLUT/copies/fallback. Desempenho novo ainda nao medido; limites/evidencias em TLUT_PIPELINE_REPORT.md.


## CPU HLE Release 2026-11-07
SHA256 7E59D3F17B482214464378EC5D633CDF5CFDB408B4FF0675F2E1EF2C0809D74C. async_decode=0, immutable_images=0 in code/config. No GX async/image/TLUT algorithm changes. Native quaternion 80283A70; animation-channel loops inside 80252488; fast-float environment HLE 8024C47C avoids per-op classification and matches fast rsqrt multiplier narrowing. Inline primary RAM 8/16/32-bit, dirty generations remain 4KB. All 185 chunks verified /O2 /Ob3 /Oi /Ot /GL /arch:AVX2 /fp:fast. PGO USE without PGI. Build exit0, no warnings, CTest14/14, inventory216 /GL objects /11731 map symbols. Details CPU_HLE_RELEASE_REPORT.md and build_test/cpu_hle_manifest.json. Combat timing pending physical input; no FPS gain asserted.


## Recovery Release 2026-11-07 (supersedes CPU HLE 7E59)
SHA256 7C6BD836FD71E75BECCB170503C7F769C29146472CD5E763DE8B38C4A17A2E46. Removed native_animation and bounds hooks from production; removed async/image modules and GX snapshot/override paths. Pure primary RAM stores, DOLRECOMP_RAM_TRACKING=0 for scalar/PSQ/DMA, no GetWriteWatch imports. Hash predecode cache, XFB VRAM and I4 VRAM retained. Compact O2/LTCG, PGO OFF. Build exit0 no warnings; CTest13/13, identical17-batch GX replay; inventory212 GL objects /11475 map symbols. RECOVERY_CPU_ANATOMY.md documents four root families and partial inclusive callback accounting. Physical recovery FPS capture pending.


## Dense chunks + native SDK transfers 2026-11-07
Release FE5B8A8156A6568CE4F271E361F4D4B4710AABB2ED6A129BBB3E6652602DF001. text148.9282MiB vs recovery150.8171; O1-only152.9048. Modest1.25pct reduction, no confirmed cache/FPS gain. All185 chunks O1/Oi/Os/fpfast/AVX2/GF without GL; core O2/Ot/LTCG; PGO OFF. Shared large float/PSQ helpers. New XF802D4EBC bulk FIFO producer and intra-chunk continuation; new LC load/store leaves and upper-SPR fallback reach native block DMA. Existing SIMD skinning/quantization preserved. 5120 reference comparisons +128 gather/wrap cases; CTest14/14; build0 no warnings; inventory213 objects (185conventional,28GL),8155 map symbols. DENSITY_XF_DMA_REPORT.md describes scheduler callbacks. Physical combat capture pending; no60FPS claim.


## Restored O2 + CPU/backend frame pipeline 2026-11-07

Supersedes the density/XF/DMA patch. User physically confirmed restored models. Rebuilt rollback .text exactly matches recovered code SHA256 14BD6C9453F3F7FC727F82F6B813EB78FC243BE793EAB81D24CB5AF9BA039F1B. Removed XF/SDK-transfer adapters; O2/LTCG, PGO OFF, RAM tracking OFF, old async/images OFF.

New Release 9D9CA34BA623A396AB2F0A4431A4307664C26E8FDA7D42BB065AD1800096B2AD. SDL/GL stays on main; one CPU worker in combat, two immutable command arenas with ordered copies/resources. PE/readback/new allocation barriers retained. Decode remains on CPU. No new partial HLE, no generated edits. Existing inline MSR_FP guard preserved for lazy FPU ownership; PC stores not removed.

Build exit0 no warnings; CTest14/14; GL self-test and I4/XFB async-reuse/materialization contracts passed; 3720 queue packets/549 barriers passed; 17-batch replay bitmap identical. Inventory214 LTCG objects/11612 map names. text150.831612MiB. FRAME_PIPELINE_REPORT.md and build_test/frame_pipeline_manifest.json document ownership/timers/limits. cfg22=1 enables combat pipeline. New combat FPS capture pending physical input; no60FPS claim.


## Raw GX backend + queued PE + PC DSE 2026-11-07

Supersedes prior frame pipeline. Release 9D83426EB63791C03A5F367D0A11FA18E0FBB01AF2F28E5AECAFD212BAE7AFDF; map build_test/raw_backend_active.map; manifest build_test/raw_backend_manifest.json. All attribute decode/cache/byte-swap and software-XF fallback now consume raw immutable inputs on SDL/main, with private decoder matrices and captured rounding. CPU frontend retains packet framing and byte capture. PE Finish/Token acknowledge queue delivery, no GL completion wait. First/reused eligible I4/XFB copies are asynchronous. Real RAM readbacks/alias materialization retain synchronization. Two arenas plus frame credit limit previous-frame backlog.

237681 proven PC stores removed from build copies of185chunks; originals SHA-verified unchanged. O2/LTCG, PGO OFF, RAM tracking OFF; old async/images remain OFF. text146.312798MiB vs150.831612. Build0 no warnings; CTest16/16; 142080 PC comparisons,7200 raw/native-XF vertices,1041 captured real vertices in both routes, ordered VRAM copies and same17-batch bitmap passed. Inventory214GL/11636map names. New per-frame barrier vs queue waits/counts, PE submissions, backend decode and frame credits logged. Prior960frames: game15.0652ms,GX6.8825ms,producer wait2.8194ms,backend3.2681ms,wall22.2288ms. New combat timing pending physical input; no60FPS claim. See FRAME_PIPELINE_REPORT.md.


### Raw-backend live combat captures completed

Same9D83426 Release: first960frames game12.9430ms/frontendGX1.5949ms/backendDecode3.6803ms/backendDraw3.2788ms/copies0.1382ms/wall17.0094ms; latest960 with239.517draws/frame game17.1002ms/frontendGX1.8784ms/backendDecode3.9018ms/backendDraw4.6526ms/copies0.1331ms/wall19.1276ms. Both: zero explicit barriers/frame, zero barrier wait, zero RAM copies. Queue backpressure0.7646/0.7494ms. PE about1/frame; raw decode active. No stable60FPS claim: latest CPU logic alone exceeds16.6667ms. Workloads varied; evolution names not logged. JSON raw_backend_combat_summary.json/raw_backend_combat_latest960.json; updated FRAME_PIPELINE_REPORT.md. Instance preserved.


## Restrict + lazy RAM CIA + triple command arenas 2026-11-07

Release E40C97E8EC961AD3F6A2DDC39BBB99B7BA0615D1794CC493AFA28D8B08376E8D; map restrict_arena_active.map; manifest restrict_arena_manifest.json. Build copies only:3009 ABI-preserving local restrict context aliases,265952 bounded scalar RAM calls with scoped CPU/RAM no-alias leaves; cold paths materialize exact CIA for MMIO/reservation/journal/aliases. Protected adapter stores unchanged. Total468805 PC stores removed (+231124); zero eligible adjacent cycle merges. Three64MiB command arenas, one-frame presentation credit retained; per-arena exact-content snapshot reuse by generation/offset, no store dirty tracking.

Build0 no warnings, CTest17/17,142080 generated CPU/RAM cases,2304 memory observer/reservation/journal cases; GX snapshot reuse+same-arena RAM mutation,1041 real raw/native vertices, identical17-batch replay passed. Inventory215GL/11622 map names; text142.198204MiB vs146.312798. First live run143draws average/max183.7 was not the requested heavy load; snapshot reuse591KB/frame, comparison0.0308ms. No performance gain claimed from unlike load. Same binary reopened; comparable960-frame window mean220..260draws pending physical input. RESTRICT_ARENA_REPORT.md has limits/evidence.


## Guest budget / idle - 2026-11-07

Release 973A8D367C9CDC85C57798369A62595637D525CAC82B1E99D35C6EFD37777F4E. Previous Release verified complete before changes. Combat quota300000 vs100000, quantum1024 unchanged, nominal675000TB/VI. Watchdog continuation preserves same VI/PC/stack and skips extra presentation/pacer; idle advances to hardware deadlines while guest audio/callbacks remain serviced. CopyDisp producer counter independent of async GL completion. Boot/menu preserved. CMake/MSVC build0 no warnings; CTest18/18; identical17-batch replay; inventory216objects/11637map names; text142.200859MiB. GUEST_BUDGET_REPORT.md documents exact old loop, SDK wait sites, event scheduling and limitations. build_test/guest_budget_manifest.json and guest_budget_active.map identify binary. Combat960-frame measurement pending physical input; no60FPS claim.


## Quantum / bounded pacing - 2026-11-07

Release 5D655078C79CC8253C772C90E9C7F61346F3D763254098243551D594C9D54B55. Quantum4096/default+cfg, downcount3840 to-256; nominal VI/audio clocks unchanged. Pacer keeps phase over <=2 periods lateness, rebases long stalls. No new HLE, GX or arena ownership changes. Cycle audit13772backedges/0forward/185entry; no safe adjacent debit merges. Adds true per-job timing peaks and exact completed-frame dispatch sum/peak. Build0 no warnings, CTest18/18, identical17-batch replay, inventory216GL/11638map, text142.202156MiB, PGO OFF. QUANTUM_PACER_REPORT.md records prior960 results14.5363msCPU/17.0819mswall and limits of old averaged logs. New combat capture pending physical input.

Quantum/pacer live capture completed: build_test/quantum_pacer_combat960.json,960frames scene4 quantum4096; CPU13.7982ms,wall16.8132ms, individual peaks31.8066/35.2788ms; dispatch mean41693.74/peak56349,idle3839,watchdog0. New98.746 vsold128.530draws/frame: unlike load, not controlled speedup proof. No60FPS-constant claim; same running instance preserved.


## Dispatcher chaining / rollback - 2026-11-07

Release 4A3990E81D3F8E103FE7D1A845E508F04464822CED4B8C056E9D3C71DECE73DF. Quantum1024/downcount768 restored, rebase-on-late pacer restored. Combat iterative continuation shares positive downcount, accounts each logical TB position; stops on MMIO, hooks, pending IRQ/callback/DVD, scheduler/OS, guest patches, device deadline and128-position poll. Build copies mark return categories; originals unchanged. Distinguishes host calls/chunk returns/internal links; no new game HLE. 18/18 tests with added chained CPU/RAM/LC final-state comparisons; identical17-batch replay; build0 no warnings, inventory216GL/11957map, text144.275780MiB. DISPATCH_CHAIN_REPORT.md, build_test/dispatch_chain_manifest.json. Dynamic combat return counts and FPS gain pending physical input.


## Constant C edges, FIFO and trace removal - 2026-11-07

Release D5797F407BDC4746D28F5A1724FD8E60A497AA631B6199D1D75D16B0F8E814C9. Removed category markers/trace define/header from185build copies; originals unchanged. Gather pipe CC008000/physical0C008000 writes no generic fence, real IRQ/safepoints preserved.39046static b/bl cross-chunk edges call known C chunk directly, hooks/host overrides protected. Actual inspected MSVC opcode CALL, not guaranteed JMP; no post-call cleanup, physical stack-growth gate2MiB plus8MiB PE reserve, legacy24-level guard retained. CTest18/18 incl real3MiB headroom rejection, registers/RAM/downcount and realLC comparisons; identical17-batch replay; build0 no warnings, inventory216GL/11885map, text143.886253MiB. DIRECT_EDGE_REPORT.md and build_test/tail_edges_manifest.json identify evidence. Final960 CPU13.1064/wall16.8707ms at107draws; subsequent same-instance off/on CPU15.9752/16.1847ms at118/131draws. Host calls56013->12524 confirmed; no timing/FPS gain proven under changing workload. cfg1 restored, process22444 preserved; no auto input.


## Flat segmented chunks / verified stack - 2026-11-08

Release ECEA9F470B2AFFE7B207C80899CDEBC74DA7040F8B19A87757148C9A5B2C9959. Removed recursive cross-chunk C edges/cpu_direct; flat executor and FIFO-no-fence retained. Build-only control-equivalent split185large bodies into23677small noinline regions,2824small functions preserved; flow address private, never CPUState.pc scratch. No HLE/FP/clock/budget semantics changes. Linked PE verifies185public wrappers,max72bytes; all production region/loop frames max168bytes vs168968; chkstk prologues183->0. Postbuild enforces max4095/no chkstk. text143.886253->47.883034MiB. CTest19/19 including12288 exact control-flow/CPU/RAM cases; old tests and identical17-batch replay passed. Build0 no warnings; inventory216objects/116069map names. Original generated sources unchanged; PGO OFF. Lookup already compact O1 with offset-base/shift14; region tables O1. FLAT_STACK_REPORT.md and build_test/flat_regions_manifest.json. New combat960 measurement pending physical input, window21712 preserved.


## Portable usability layer (isolated from stable-60fps)

Branch codex/launcher-portable-save; build_test/usability. Native Win32 launcher,
UTF-8 JSON controller configuration, ISO/CISO/NKit ISO/GC RVZ disc reader,
portable Slot A CARD HLE with durable atomic saves/MemoryCardA.card.
Packaging: cmake --build build_test/usability --config Release --target package_release
creates DigimonRA2_PC from an explicit allowlist, no game data or development artifacts.
Release build and 22/22 CTest passed; public chunk max stack 72 bytes, internal
max 168 bytes, zero chkstk. CPU/GX/timing/codegen sources and stable executable
remain unchanged. See USABILITY_RELEASE_NOTES.md for architecture and validation.
