# Relatório de engenharia — Digimon Rumble Arena 2

Revisão de 2026-11-01. Windows x64, MSVC 14.51 / Visual Studio 18 2026, CMake, SDL2 2.32.0 e OpenGL. Jogo USA GD6EB2, DOL real com entrada 80003100.

## Resultado e critério de conclusão

O usuário confirmou input físico pelo Title/menu/Practice, seleção e Jungle Ruins, além de cores, ícones, modelos e som corrigidos. Na execução final com PGO, confirmou 60 FPS estáveis na seleção e 40–46 FPS no combate, com modelos e som corretos; o slow motion em combate permanece. A velocidade permanece pendente: após restaurar o núcleo menor de skinning, confirmou 57–59 FPS com quatro personagens na seleção após corrigir a entrada do acumulador. A fase ainda apresentou quedas. A expansão para outros dois laços foi revertida por não mostrar vantagem consistente.

O cache dos uniforms TEV passou na equivalência visual, mas regrediu para 49–52 FPS e foi retirado. O acumulador vetorial 8024C244/8024C2CC passou nas 1.440 comparações CPU/RAM e seu ganho na seleção foi confirmado pelo usuário. Na revisão seguinte, com normalização/reflexão nativa, a luta medida ficou em aproximadamente 33–35 FPS, apesar da seleção próxima de 60. **O trabalho não está integralmente concluído: faltam 60 FPS sustentados e a validação final em combate.** As seções de desempenho registram também experiências anteriores, inclusive as revertidas.

## Abrangência da auditoria

Foram examinados os seis fontes originais de src_test, seus headers, o runtime CPU e a fronteira com o código gerado. O script tools/hle_audit.py percorre os 185 chunks: 7.349.164 linhas, 5.053 destinos diretos, read32=135.681, write32=109.951, read16=6.304, write16=2.138, read8=2.309, write8=2.888, read64=3.300 e write64=3.407.

Essa cobertura mecânica integral dos arquivos não é uma prova semântica de todos os caminhos possíveis. Os pontos abaixo foram investigados por assembly, execução, snapshots e testes. Nenhum arquivo de recompiled_code/generated foi alterado. CPUState, assinaturas e endereços guest preservam a ABI. A revisão de desempenho otimiza a escala PSQ e operações paired-single no runtime CPU, conforme seção abaixo e patches/dolrecomp-cpu-fastpaths.patch.

O checkout inicial estava sem build_test, fontes do submódulo e import libraries SDL. As dependências necessárias foram restauradas e o target configurado. A atualização recursiva de dependências Dolphin não utilizadas pelo target encontrou limites de caminho do Windows; há também uma alteração intencional em DolRecomp/src/cpu/cpu.c para caminhos numéricos exatos, exportada em patches/dolrecomp-cpu-fastpaths.patch. Não foi trocado o gitlink. O disco fornecido pelo usuário foi usado localmente; DOL extraído do offset 0x1EC00, tamanho 3.525.376 bytes. Recursos do jogo não fazem parte das mudanças de código.

## 1. Causa das esperas no estado 11

A quantidade de draws/FIFO não demonstra prontidão da cena. Havia condições independentes de GPU, interrupções, DVD e som. O número 11 corresponde também ao próprio Title em execução normal; remapeá-lo artificialmente não seria uma correção.

### GPU e callback correto

- A abertura gather aceitava somente CC008000. Stores paired-single em CC008004 perdiam o segundo word, truncando matrizes e vértices. Agora são aceitos os 32 bytes da abertura e o alias físico 0Cxxxxxx.
- Os pares LO/HI de CP estavam invertidos. O consumidor não executava corretamente FIFO selecionado na RAM quando CPU e GP usavam FIFOs distintos. Há agora base/end/read/write/distance e ring wrap reais.
- Finish/token eram inventados por frame host. Agora BP45 finish e BP48 token geram eventos PE latched, respeitando máscaras e acknowledge; BP47 atualiza token sem IRQ.
- O SDK em 802CF444 atualiza o byte DrawDone em r13-25320 e chama o callback em r13-25324. O callback 80248B60 limpa r13-29800, consultado em 80248E84. Ele é **GXDrawDoneCallback**, não VIRetraceCallback. Os callbacks VI pre/post observados eram zero.
- O idle saía antes de entregar eventos. Agora os dispositivos e interrupções avançam durante idle. O salto de idle apenas vai até a próxima consulta de dispositivo, preservando o timebase.

### Voz que não terminava

O caminho Title 8015ED34 → base 8015BA2C → prontidão virtual 8015EF9C → 80143B78 consulta controladores via 801B35AC. Os offsets 308/312/316/320 incluem controladores de animação/efeito. Na execução bloqueada, a lista global em r13-27068 continha um controlador de som ativo. Os ponteiros observados eram alocações daquela execução, não endereços usados como patch.

8021B210 consulta flags em +20 e duração em +24 para determinar se a voz continua tocando. O DSP anterior reconhecia mensagens sem executar o mixer nem avançar a amostra. A voz não alcançava o fim, e a transição continuava aguardando mesmo com GPU concluída. AX agora avança PCM/ADPCM, escreve o estado do PB e encerra one-shots. O log registrou dezenas de encerramentos e o usuário confirmou saída do Title com input físico. Nenhum flag de cena ou conclusão de som é fabricado.

### DVD e ABI

802B92B0 é DVDReadAbsAsyncPrio. O callback vem de r7 e recebe (resultadoEmBytes, DVDCommandBlock*) em r3/r4. O código antigo chamava o campo +56 com ABI errada, alterava bookkeeping privado do motor e pulava leituras por heurística de offset/contagem. Esses comportamentos foram removidos.

A leitura bounded ISO/CISO devolve dados reais, preenche os campos SDK e agenda r7. Falha devolve -1, não sucesso fictício. A fila de 128 callbacks preserva CPUState completo, mantém mutações de RAM/timebase e executa cada callback em pilha/contexto temporários, com EE/FP mascarados como numa interrupção. O contexto temporário impede reschedule dentro de OSWakeupThread. O retorno restaura contexto atual, proprietário da FPU e controle FPSCR host.

## 2. Corrupção do contexto FPU

O código host salvava PS1 como double de 64 bits em OSContext+1C8. O SDK usa psq_st com GQR0=0 e escreve **dois float32**: PS0 e PS1. A restauração nativa passava a ler a representação de double como dois floats, corrompendo paired singles. Isso afeta especialmente matrizes, skinning e outras rotinas vetoriais.

Além disso, o contexto atual em 800000D4 não é necessariamente o dono físico dos registradores FPU em 800000D8. Interrupções agora entram com EE e FP limpos. A exceção FP-unavailable salva o dono anterior, carrega o contexto atual quando FPSAVED está definido e atualiza a propriedade. O flag EXC (bit 1) é preservado separadamente de FPSAVED (bit 0). Não se grava FPU do dono errado no contexto interrompido.

os_context.c implementa essa fronteira. Um teste executa a própria rotina SDK 802BFF2C, compara os bytes dos 32 escalares e dos 32 pares com o salvamento HLE e verifica ida/volta entre dois proprietários FPU. Os testes confirmam o formato e preservação. A correção anterior de apenas reabilitar FP também perdia EE do MSR salvo; isso foi corrigido.

## 3. Loading de VS e Lua

A execução antiga que parecia crash produziu a mensagem Lua **attempt to index a number value**. A pilha passa por 801D012C, lua_gettable, luaD_throw em 8026270C e exit(1). Na RAM, uma referência do registry apontava para um nó numérico da free list. O código gerado para o stub 80293820 contém zero tratado como embedded data e retorna; após exit retornar indevidamente, a execução cai no getenv adjacente e gira.

Esse registro distingue o erro guest de uma exceção host. O log runtime_crash.log só registra exceções host; logs de saída distinguem Escape e SDL_QUIT. Contexto FPU e execução dos callbacks foram corrigidos depois dessa captura; o usuário voltou a carregar Jungle Ruins. Isso não prova a inexistência de outras falhas Lua. Não foi substituída tabela de script por dados inventados nem forçado sucesso no carregamento.

## 4. EFB, XFB e apresentação

Apenas escrever o endereço de GXCopyDisp não realiza uma cópia. BP COPY_TRIGGER executa os draws pendentes no EFB persistente, lê pixels, converte RGB→YUY2 BT.601 e escreve o XFB na RAM. Origem, dimensões, pitch e limites são verificados. VI seleciona scanout no VBlank, inclusive escritas fragmentadas de registradores. Present lê o XFB e não modifica a RAM. Foram removidos overlay direto sobre a janela, crominância artificial e endereços mágicos de framebuffer.

GXCopyTex também era ignorado. A cópia para texturas agora escreve layout tiled de cor na RAM, suporta half-scale e aplica clear depois da cópia. O teste verifica RGB565, segundo tile e a cor do EFB após clear. Eventos de copy/clear e bytes produzidos são preservados no replay. Cópias de profundidade/alguns modos especiais ainda não estão completas.

## 5. Renderização e geometria

O parser deriva tamanho de vértice de VCD/VAT e mantém pacotes incompletos entre frames. Interpreta índices 8/16 bits, arrays CP, uploads XF diretos/indexados, matrizes, projeção, viewport, display lists, texgen e post-matrizes. A origem de cor XF (material ou vértice), ambiente e iluminação básica também é considerada.

Foram corrigidos seleção de unidade pelo TEV order, bancos de registradores TEV e konst, KSEL, paletas em TMEM por unidade, cache por conteúdo/paleta e formatos I4/I8/IA4/IA8/RGB565/RGB5A3/RGBA8/CI4/CI8/CI14/CMPR. O cache tem 512 entradas e evita repetir hashes dentro de um lote. Paleta ausente não vira grayscale inventado.

A rota OpenGL implementa avaliação por pixel de até 16 estágios TEV com oito unidades de textura, constantes, comparações, swap tables, alpha test, blend, scissor e Z-buffer. Mantém coordenadas homogêneas, recorte -w..0 do GX antes de aplicar profundidade de viewport e interpolação em perspectiva. O winding foi conferido por replay no EFB, cuja convenção Y difere da janela OGL. A rota SDL anterior permanece apenas para comparação e testes.

O envio em lote por arrays substitui chamadas de driver por vértice. Os testes GL verificam textura somada a registrador, profundidade, alpha, clipping atrás da câmera, clear de Z e orientação de faces. Eles exigem que a rota GL esteja ativa; fallback não faz o teste passar.

O perfil de CPU localizou cerca de 56% do tempo amostrado no caminho que habilita e consome o FIFO GP. O decodificador executava tev_vertex em todos os vértices, embora native.color já tivesse sido salvo antes desse cálculo e o shader executasse TEV por pixel. A rota GL agora omite esse cálculo redundante; software e captura mantêm o fallback. A escolha de coordenada é calculada por draw, em vez de repetir a busca de estágio por vértice. Atributos inteiros são escalados por multiplicação exata por 2^-fração, eliminando chamadas CRT ldexpf por componente. Os atributos, iluminação e TEV do shader permanecem os mesmos. As duas suítes passaram; desempenho com um/dois modelos está em validação.

A leitura GP de FIFO já pronto usa memcpy em blocos contíguos de até 64 KiB, respeitando ring wrap, capacidade, breakpoint e orçamento. Gathers ligados de 32 bytes continuam sendo consumidos imediatamente. Um cache por draw compara a chave FIFO completa e reutiliza o vértice somente enquanto RAM/XF/CP estão imutáveis. Mede cerca de 49% de reutilização com personagens. Fatores de iluminação iguais são compartilhados entre canais RGB, mantendo a ordem da soma por canal.

O decodificador pode usar três helpers SDL persistentes para draws com pelo menos 1024 vértices. Cada helper possui cache próprio e recebe intervalo de saída independente; CPU PPC e chamadas OpenGL continuam na thread principal. O parser aguarda todos os helpers antes de alterar RAM/registradores/FIFO. Arredondamento e MXCSR são copiados para os helpers. GX_VALIDATE_WORKERS compara cada vértice com a execução serial; o teste de 3072 vértices exercita isso e verifica pixels finais. GX_SINGLE_THREADED permite comparação de desempenho. As duas suítes passaram; teste funcional com dois/quatro modelos está em andamento.

As display lists alocavam/liberavam 1 MiB por chamada, independentemente do comprimento. Agora cada um dos oito níveis de aninhamento reutiliza seu próprio buffer; o teste confere DL aninhada e reaproveitamento com comprimento menor, sem executar o tail antigo. A leitura RGBA do EFB também reutiliza uma área de 640×528, evitando alocação grande por cópia. Flags de backend/captura são consultadas uma vez por processo. Essas alterações preservam limites, bytes e ordenação dos comandos.

### Reutilização de arrays indexadas

A captura de um personagem mostrou VAT S16 lendo padrões de um buffer float reutilizado. O consumidor GP só era consultado em intervalos do loop host, inclusive depois de a CPU voltar a modificar uma área transitória. O parser passa a executar o FIFO selecionado ao habilitar leitura GP e a consumir gathers ligados assim que completam 32 bytes. Vértices são decodificados antes da reutilização da array.

O teste envia um draw indexado, reutiliza a RAM de origem e verifica que a imagem ainda contém a geometria original. Também verifica execução imediata de FIFO RAM selecionado e ring wrap. Esse ajuste isolado não corrigiu o Agumon real; a causa adicional era o locked cache abaixo. Não foi aplicada uma heurística que trate stride 12 como float contra o VAT.

### Locked cache e DMA de skinning

O consumo imediato do FIFO não bastou para corrigir o Agumon, conforme teste do usuário. Foi encontrado outro caminho ausente: a memória locked cache em E0000000 não era mapeada, e os SPR DMAU/DMAL (922/923) eram ignorados pelo fallback. O jogo usa rotinas de load/store desse cache no processamento de vértices. Sem as transferências, o GX podia ler dados anteriores ao processamento/quantização.

locked_cache.c agora fornece 16 KiB big endian, DMA RAM↔LC em blocos de 32 bytes, comprimento zero representando 128 blocos, wrap de LC, trigger/status e limites de RAM. O fallback e os callbacks SPR do harness encaminham essas operações. Testes executam as rotinas SDK originais 802BF5DC e 802BF600, verificam ida/volta, wrap e psq_st S16 quantizado. O usuário testou essa revisão e confirmou todos os modelos corretos.

## 6. Câmera lenta e ritmo

A janela usava SDL_RENDERER_PRESENTVSYNC junto com um segundo cap de 60 FPS. Ultrapassar um refresh por pouco podia acrescentar uma espera de apresentação e quantizar a taxa em torno de 30 FPS. A janela agora usa uma única cadência host, baseada em performance counter, sem VSync somado ao cap. O timebase e os eventos guest continuam avançando pelo orçamento emulado; não há fast-forward de estado ou input.

O Title registrou 60 FPS na revisão sem o duplo limitador. Há contadores separados para CPU+GX, renderer e readback/conversão. Renderer/readback podem estar incluídos em CPU+GX quando são disparados durante a execução CPU; não são categorias disjuntas. Desempenho de combate ainda requer medição após a correção dos modelos.

O orçamento fixo de 50 mil dispatches podia distribuir a produção de uma imagem por dois retraces. A revisão de diagnóstico permite 100 mil, preservando exatamente 675 mil ticks TB por intervalo; idle salta até o próximo poll sem executar blocos. Essa calibração por blocos continua aproximada, não é temporização de instruções PPC. Foram removidos polls duplicados e logs/screenshots por frame só ficam ativos com RUNTIME_TRACE. Contadores novos mostram menus leves a 60 cópias XFB/s e 200 listas AX/s, mas seleção com modelos a 33–47 imagens/s, CPU+GX 21–30 ms e renderer perto de 2 ms. IPO MSVC entre chunks e helpers passou nos testes, mas não resolveu as quedas. O perfil CPU_PROFILE confirmou custo alto no processamento GX, motivando a remoção do trabalho duplicado descrita acima. Medições durante compilação concorrente não são usadas como baseline.

O fallback agrupa iterações restantes de cinco loops SDK de cache (DCInvalidateRange/DCFlushRange/DCStoreRange e variantes sem sync) somente sem callback de cache instalado. Na RAM coerente host essas operações já eram neutras. GPRs, CTR, CR e retomada no sync/retorno original são preservados; os testes comparam a execução agrupada com as cinco rotinas geradas originais, incluindo endereço desalinhado e SC.

No runtime, cargas PSQ inteiras multiplicam por uma potência de dois binary64 construída a partir do GQR, em vez de chamar ldexp por componente. Stores comparam limites inteiros antes da conversão C, que já trunca, removendo trunc redundante. Foram comparados todos os 64 fatores, quatro formatos e quatro arredondamentos com ldexp/trunc, incluindo saturação, extremos, NaN e infinito. Não houve alteração de ABI ou relaxamento de precisão. O patch foi exportado e validado com git apply --reverse --check. Essas otimizações isoladas ainda não sustentaram 60 FPS com dois modelos; o pool de vértices é a revisão seguinte em teste.

Foi corrigido também o rearmamento de downcount. O harness nunca renovava esse orçamento consumido pelos guards do código gerado; depois do boot, cada backedge podia devolver o controle ao host. platform_execute_cpu_slice zera o contador antes de cada fatia. Um teste compara memória, GPRs, CR e CTR da rotina memset original com orçamento antigo/renovado e verifica a redução de dispatches. Hints dcbt/dcbtst neutros podem continuar dentro da mesma fatia, ainda limitada pelo orçamento gerado. O timebase continua no intervalo de retrace, sem modificar estados de jogo ou input.

O runtime MSVC x64 possui caminhos SSE para soma, subtração, multiplicação, multiplicação escalar e sum0/sum1, além de FMA empacotado com detecção CPUID/OSXSAVE/XCR0. Só são aceitos zeros ou operandos normais exatamente representáveis em binary32; os demais continuam na implementação escalar. FPRF e zeros com sinal são preservados. As suítes comparam resultados com as operações escalares em quatro arredondamentos, NI ligado/desligado e destinos sobrepostos. Não se habilitou fast-math. Os auxiliares privados são forçados inline para evitar spills/calls do ABI de __m128: no benchmark local de 30 milhões de operações, o tempo foi de 257,869 para 192,212 ms, com resultado e FPSCR idênticos. Isso não equivale a prometer o mesmo ganho no jogo.

O usuário confirmou quatro personagens corretos, mas ainda 39–41 FPS na revisão SIMD anterior ao reaproveitamento de buffers. A medição separada encontrou cerca de 2,3 ms para vértices e zero para cópias de textura nessa tela. A revisão de buffers/inline/hints está em teste. A meta de 60 FPS sustentados ainda não foi demonstrada.

## 7. Áudio

AI real em CC006C00, antes confundido com EXI, agora tem counter por timebase, controle de taxa e IRQ. DSP CC005000 usa registradores byte-addressed big endian e halfwords sem sobrescrever vizinhos. Há 16 MiB de ARAM e DMA MRAM↔ARAM, status/ack e mailbox/bootstrap AX observado.

AX processa 160 amostras por lista em cinco subframes, PB updates, PCM8/16, DSP ADPCM, envelopes, mixer principal/AUX, loops e fim de voz. O layout antigo sem LPF, observado com stride PB 236, tem roteamento e loop counter específicos. Corrigidos ramps SETUP, volumes nos três buses e substituição AUXB LR. SRC distingue nearest, linear e polifásico de quatro taps com histórico/fase; os coeficientes livres de Dolphin são copiados como dsp_coef.bin, com fallback linear explícito se ausentes. Saída R/L é convertida para L/R SDL, com resampling 32→48 kHz e fila bounded.

O DMA anterior zerava cursor e fase em toda escrita do registrador de comprimento. Agora só a borda de enable inicializa a transferência; endereço/comprimento reprogramados são aplicados no reload. Consumo ocorre em blocos de 32 bytes, downcounter é zero-based e interrupção AID vem no término. A suíte verifica a reprogramação no meio de uma transferência. O comando AX 0x12 compressor, observado nas listas reais, passa a aplicar a tabela guest com attack/release antes da saturação final. Ganhos de mixer saturam cada voz em s16 e devolvem os valores de de-pop ao PB. Testes verificam compressor, seleção de banco e convolução SRC.

O usuário confirmou o som corrigido nessa revisão. Isso é validação funcional, sem prometer igualdade bit a bit: os coeficientes livres aproximam DROM oficial; reverb/DPL e DSP fora do AX observado permanecem parciais. Rodar o guest abaixo de tempo real ainda reduz o ritmo de produção de áudio; as quedas de FPS continuam sendo investigadas.

## 8. Mudanças por arquivo

| Arquivo | Alteração |
|---|---|
| src_test/test_main.c | MMIO, exceções, contexto/thread, eventos em idle, pacing único, DVD ABI, remoção de auto-input e patches de prontidão/cena, timings e diagnósticos. |
| src_test/gx_pipe.c/.h | Parser/FIFOs CP/PI, arrays e matrizes, textura/TMEM/cache, EFB/XFB/copy, eventos PE, snapshots, replay e timings. |
| src_test/gx_gl.c/.h | Backend GL por pixel, rasterização 3D e submissão por arrays. |
| src_test/skinning_environment.c | Normalização/reflexão vetorial, estimativa Gekko e multiplicador de 25 bits preservados; RAM/LC, orçamento e fallback. |
| src_test/skinning_accumulate.c | Acumulação S16 indexada e transformação rígida pipelined 8024C014 em SIMD local, guardas conservadoras, quantização/endian e fallback; benchmark e comparação com o original. |
| src_test/paired_skinning.c/.h | Núcleo limitado de skinning, comparado byte a byte com a rotina PPC original; preserva orçamento e fallback. |
| src_test/locked_cache.c/.h | Área LC de 16 KiB e DMAU/DMAL de skinning; cópias contíguas com limites e wrap. |
| src_test/locked_cache_tests.c | 1.792 casos de transferência RAM/LC, status e limites; benchmark isolado de DMA. |
| src_test/cpu_native_adapter.h, native_ram.c | Caminho curto de RAM cached/uncached em dez chunks selecionados; fallback original e chave host para A/B. |
| src_test/native_ram_tests.c | 1.624 casos de igualdade com o runtime: aliases, callbacks, limites, reservas e journal. |
| src_test/os_context.c/.h | Formato FPU SDK e propriedade lazy entre contextos. |
| src_test/hle_callbacks.c/.h | Fila, contexto/pilha temporários, retorno sentinela e restauração CPU/FPU. |
| src_test/video_audio.c/.h | VI scanout, IRQs, DSP/ARAM, AI/DMA, PCM/resampling e present. |
| src_test/ax_hle.c/.h | Command lists AX, vozes, mix e telemetria. |
| src_test/input.c/.h | Somente input físico, hotplug GameController/Joystick, teclado com foco e PADStatus guest. |
| src_test/dvd_vfs.c | ISO/CISO bounded, cross-block, sparse zero, truncamento e status DI. |
| src_test/dol_loader.c | Header/seções truncadas e limites; sem boot de seção incompleta. |
| src_test/platform_tests.c | Contratos ativos em Release e probes isolados de funções guest sobre cópia de RAM. |
| ModernGekko-Template/lib/DolRecomp/src/cpu/cpu.c | Escala PSQ exata e operações pareadas SSE/FMA restritas a operandos compatíveis. ABI preservada; patch exportado em patches/. |
| CMakeLists.txt | Fontes novas, OpenGL, cópia da DLL correta e duas suítes CTest. |
| tools/hle_audit.py | Auditoria de todos os chunks e assembly de esperas/SDK/Lua/FPU. |
| tools/inspect_guest.py | Leitura de processo para RAM/XFB, sem escrita nem input. |
| tools/gx_capture_inspect.py | Bytes de posições, VAT/matrizes e amostras dos draws. |

## 9. Input configurado

| GameCube | Teclado | SDL GameController |
|---|---|---|
| A | Z/J | A |
| B | X/K | B |
| X | C/U | X |
| Y | V/I | Y |
| Start | Enter/Espaço | Start |
| Movimento/D-pad | WASD/setas | Stick esquerdo/D-pad |
| C-stick | sem binding de teclado | Stick direito |
| L | Q/Shift esquerdo | LT analógico/LB digital |
| R | E/Shift direito | RT analógico |
| Z | Tab | RB |
| Fechar janela | Esc | fechar janela |

Joystick genérico: botões 0..7 = A/B/X/Y/L/Z/Start/R, eixos 0/1, hat 0. Só porta 1 conectada. PADStatus de 12 bytes é escrito em big endian pelo PADRead. Não há auto-press, timer de confirmação, botão injetado nem escrita direta de botão no objeto UI. O attract mode nativo não foi removido.

## 10. Validação e limites remanescentes

As suítes software/OpenGL passaram após as últimas correções. Foram exercitados endian/aliases, FP/EE, FPU contra SDK e troca de dono, callbacks reais e contexto temporário, ARAM DMA/IRQ, AI counter, FIFO fragmentado/ligado/desligado, arrays transitórias, EFB→XFB e EFB→textura, YUY2/present, PE finish/token, paletas/TEV, XF material, PCM/ADPCM/loop/SRC/AUX, DVD ABI, CISO sparse/truncado e DOL truncado. Logs de validação ficam locais no build.

O inventário analisa objetos antes do link: importações SDL/OpenGL/CRT/Win32 não são símbolos finais não resolvidos. COMDAT repetidos também não equivalem a multiple definition fatal. A conclusão de link depende da saída real MSVC e da tabela dumpbin /imports. O build limpo e o inventário devem ser atualizados na revisão final.

Permanecem parciais: indirect TEV, fog e efeitos/iluminação especiais; cópias de profundidade e modos especiais de textura; VI beam/PAL/interlace; CP watermark/breakpoint IRQ completo; DSP genérico fora do AX observado; EXI/memory card; SI baixo nível/quatro jogadores; rumble; temporização CPU por blocos e alguns guards antigos de listas/thread/PC inválido. Não se declara ausência de bugs nesses caminhos. Um combate estável com geometria e áudio corretos ainda é o critério final.


## Atualização de desempenho e validação da cópia YUY2

O usuário confirmou cores, ícones, modelos e som corretos; quatro personagens ainda ficam em 47–49 FPS, raramente 50. Os 60 FPS sustentados na seleção/combate continuam pendentes.

O PSQ direto preserva alinhamento, limites, endianness, quantização, exceções, journal e reservas. Somente RAM coerente e locked cache usam acesso direto; MMIO conserva callbacks. O hook external_pointer já existente fornece LC sem alterar CPUState. cpu.h e os novos ps_fast.h/psq_fast.h estão incluídos no patch reproduzível do runtime, validado com git apply --reverse --check. O código gerado permanece inalterado.

Inlining público amplo e expansão SIMD nos call sites passaram nos testes numéricos, mas regrediram para 24–30 FPS. Ambos foram revertidos. Permanecem auxiliares privados, PSQ direto e buffers reutilizados, sem fast-math.

build_test/runtime_tuning.cfg aceita `quantum workers [packed_copy]`, aplicado entre frames, sem input ou flags guest. Comparação na mesma seleção favoreceu ligeiramente quantum 1024 e workers ligados; 2048 não trouxe vantagem. Workers reduziram vértices de aproximadamente 2,8 para 2,2 ms.

A nova rota OpenGL empacota dois pixels EFB em RGBA com bytes Y0/U/Y1/V e lê diretamente para a RAM XFB. O VI continua apresentando essa RAM. Fallback CPU permanece disponível. GX_VALIDATE_COPY=1 compara cada byte com a conversão CPU. As suítes software/OpenGL passaram, incluindo fontes recortadas e escalas verticais normal/inversa; desempenho com quatro modelos ainda aguarda comparação na mesma tela.

O cache agora distingue a paleta na segunda busca de entradas, evitando destruir/recriar uma textura CI a cada alternância de paleta. O teste verifica cores e exatamente duas transferências para quatro draws alternados. TLUT atualiza a época mesmo sem draws pendentes. XXH64 do checkout local acelera o hash quando disponível, com fallback sem dependência adicional.

Comparação ao vivo registrada em build_test/packed_comparison.json: cópia CPU 2,9–3,2 ms contra GPU 1,6–1,8 ms; cerca de 43 contra 46 FPS. O usuário informou 42–48 FPS. Simplificação posterior de resolve_addr preserva MEM1/MEM2 e encaminhamento de endereços externos; testes de fronteiras e aliases passaram nas duas rotas. Quantum padrão agora 1024. Validação de desempenho dessa última mudança ainda pendente.

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

### Captura do decodificador GX e transformações XF

A luta da revisão anterior foi medida em cerca de 33–35 FPS, com CPU+GX de 28–29 ms/frame e decodificação de vértices de 4,4–4,5 ms/frame. Renderização e cópias têm timers aninhados: `texture copy` inclui o flush do EFB/render, portanto seus tempos não podem ser somados como custos independentes. O perfil correspondente está em build_test/combat_latest_profile.json.

Foi criada tools/capture_gx_decode.py: captura read-only de um worker indexado concluído enquanto a thread principal está suspensa, retomando-a em finally. Não escreve RAM, não simula PAD e não constitui um savestate completo. A captura local combat_decode_reference.gxvd contém 447 vértices reais, CP/XF, FIFO e RAM; não deve ser distribuída como código do projeto.

Em gx_pipe.c, as colunas das matrizes de posição/normais são preparadas antes dos workers e invalidadas por escritas XF diretas e indexadas. A transformação SIMD mantém a associação dos produtos e somas, sem FMA. A transformação/normalização da normal deixa de ser calculada quando nenhum canal com luz difusa ativa pode usá-la. Não há alteração de projeção, TEV, input, orçamento guest ou código gerado.

A CLI `--gx-validate-decode captura.gxvd [scalar|vector] [repeticoes]` compara todos os 168 bytes de cada vértice com a captura anterior e permite medir o mesmo lote sem input. Ambas as rotas produziram 447 vértices idênticos, checksum 8FE14D9B. A suíte inclui 24.576 comparações de transformações com 64 índices, quatro arredondamentos, FTZ/DAZ ligados/desligados, zeros/subnormais, invalidação das matrizes e equivalência de iluminação sem contribuição da normal.

A tentativa de vetorizar também as matrizes de pós-textura passou na equivalência, mas não mostrou vantagem consistente e foi removida antes da revisão final. As medições de posição/normais variaram: houve ganhos de aproximadamente 1–5% no lote isolado e também medições canônicas praticamente iguais (599,302 ms escalar contra 598,664 ms vetorial para 4,47 milhões de vértices). Isso não comprova ganho global de FPS. Não se declara 60 FPS no combate.

Build canônico build_test/Release: saída 0, sem warnings; CTest software/OpenGL 2/2 aprovados; inventário de 202 objetos /GL e 10.293 nomes no mapa final. Executável anterior e mapa correspondente preservados em build_test/baseline_environment. Nova execução com input físico, sem compilador/perfil pesado concorrente, log runtime_xf.log; mapa correspondente build_test/xf_active.map. Aguarda uma luta mantida aberta para medir o custo real dessa revisão.

### Transformação rígida pipelined 8024C014 em combate

Com Jungle Ruins mantida aberta pelo usuário, runtime_xf.log registrou inicialmente cerca de 36–41 FPS, variando depois para 32–33 conforme o custo da luta. Não houve compilação durante a amostragem de oito segundos. build_test/combat_xf_profile.json contém 4.972 amostras e 16 snapshots read-only dos registradores. O trecho 8024BFA0..8024C060 respondeu por 166 amostras no executável; também houve espera em workers, driver e chamadas de janela, portanto a contagem não representa porcentagem isolada de instruções PPC.

O trecho 8024C014..8024C060 transforma posição e normal, escrevendo a saída do vértice anterior antes de ler o próximo. A nova função paired_skinning_transform_step, separada do acumulador no mesmo arquivo skinning_accumulate.c, mantém os pares em SIMD local e preserva FMA e quantização S16 big endian. A ordem dos stores antes dos loads é indispensável quando entrada/saída compartilham locked cache. Matrizes/entradas fora dos limites numéricos, formatos diferentes, exceções, reservas, journal ou callback de cache permanecem no original. A entrada é a backedge real 8024C014, com 20 instruções por iteração, yield original e epílogo em 8024C064. Não altera frames, timebase, input ou flags guest.

Os 3.840 casos compararam CPUState completo, RAM/LC e downcount com a função gerada original. Cobrem quatro arredondamentos, NI, cinco escalas PSQ, quatro contagens, três orçamentos, RAM/LC e quatro padrões de sobreposição. Cada caso suportado exige incremento do contador nativo; oito recusas adicionais verificam ausência de mutação. Benchmark canônico de 505 mil vértices: original 91,450 ms, nativo 10,616 ms (8,61x), checksum 3EA9A7B5 idêntico. O benchmark anterior no binário de validação mediu 9,17x. Esses resultados são do laço, não do jogo inteiro.

Build canônico: saída 0 sem warnings; CTest software/OpenGL 2/2 aprovados; inventário de 202 objetos /GL e 10.320 nomes no mapa final. Fonte gerado e ABI inalterados. A execução anterior foi preservada em build_test/baseline_xf_combat com o mapa correspondente antes do encerramento. Nova execução: runtime_rigid.log, mapa build_test/rigid_active.map; configuração fixa 1024 1 1 1, sem perfis/compilação concorrente. O log passa a incluir transform= no contador de skinning. Aguarda retorno físico à luta para confirmar ativação, imagem e FPS; 60 FPS sustentados continuam pendentes.

### PGO do MSVC com perfil real de combate (2026-11-01)

O usuário manteve Jungle Ruins aberta na revisão de transformação rígida. runtime_rigid.log confirmou milhões de vértices em transform=, com aproximadamente 36–38 FPS e CPU+GX de 26–27 ms/frame nesse intervalo. Isso confirma ativação do hook, mas não uma melhora global suficiente. build_test/combat_rigid_profile.json contém a nova amostragem de oito segundos; o custo restante está distribuído entre código gerado, memória e GX. O ganho do benchmark isolado não se converteu em 60 FPS.

CMakeLists.txt agora oferece DIGIMON_PGO_MODE=OFF|GENERATE|USE, DIGIMON_PGO_DATABASE e DIGIMON_PGO_COUNTS. OFF é o padrão e preserva o build usual. GENERATE usa /LTCG e /FASTGENPROFILE; USE requer uma base existente e usa /USEPROFILE. Somente Release recebe essas opções. A configuração recusa PGO sem IPO e copia pgort140.dll para o build de coleta. Não muda /fp, ABI, fonte gerado ou input. Referências: [coleta MSVC](https://learn.microsoft.com/en-us/cpp/build/reference/genprofile-fastgenprofile-generate-profiling-instrumented-build?view=msvc-170), [uso do perfil](https://learn.microsoft.com/en-us/cpp/build/reference/useprofile?view=msvc-170) e [pgosweep](https://learn.microsoft.com/en-us/cpp/build/pgosweep?view=msvc-170).

O experimento com contadores atômicos EXACT/COUNTER64 teve custo excessivo e sua execução de testes foi encerrada sem certificação. Foi substituído pelos padrões leves de FASTGENPROFILE: os contadores estatísticos podem perder precisão entre workers, conforme o modo suportado pelo MSVC, sem alterar os dados do jogo. Não se usa o FPS instrumentado como medida de desempenho final.

O build leve terminou com saída 0 sem warnings em build_test/pgo_training_fast. Suítes software e OpenGL passaram, incluindo as 3.840 comparações da transformação rígida. Inventário separado build_test/pgo_training_inventory.txt: 202 objetos /GL, 10.595 nomes e dependência pgort140.DLL esperada. Os dois PGCs desses testes foram movidos para build_test/pgo_validation_profiles e não serão usados como treino da luta.

A versão normal anterior e seu mapa estão preservados em build_test/baseline_rigid_combat. A coleta foi feita em Jungle Ruins com quatro Digimons, usando apenas o input físico do usuário. pgosweep zerou os contadores após o carregamento e salvou combat_01.pgc, com 1.826.816 bytes. A captura foi incorporada sem descarte por estouro. A base contém 4.256 funções, 30.955 arcos e contador máximo de 510.235.222 (11,88% do limite de 32 bits). O manifesto está em build_test/pgo_capture_archive/training_manifest.json. Instruções dinâmicas do perfil não são porcentagens de tempo de CPU.

USE também exige DIGIMON_PGO_COUNTS, uma lista de PGCs arquivados. Antes de cada link, CMake copia a base para uma pasta temporária identificada pelo conjunto de entradas, limpa apenas as contagens dessa cópia e copia os PGCs selecionados. O linker incorpora os dados automaticamente. Esse fluxo evita os avisos PG0181 (dados já incorporados) e PG0188 (nenhum PGC), detectados nas primeiras tentativas de religação. A base e a captura originais permanecem preservadas. Novas coletas devem ter arquivos próprios e ser selecionadas na configuração CMake.

Entradas atuais: build_test/pgo_capture_archive/untrained.pgd e combat_01.pgc. A primeira versão USEPROFILE isolada passou nas suítes software/OpenGL e manteve os 447 vértices capturados byte a byte iguais; não depende de pgort140.dll. O compilador confirmou uso do perfil em 4.255 das 4.256 funções. O build canônico em build_test/Release terminou com saída 0 e nenhum warning. CTest software/OpenGL 2/2 aprovados, inventário 202 objetos /GL e 10.840 nomes; os 447 vértices reais continuam byte a byte iguais. O runtime de coleta não é dependência do executável final. Benchmark sem jogo/compilador concorrentes: 4,47 milhões de vértices em 597,228 e 558,816 ms na referência, contra 508,882 e 544,004 ms com PGO (cerca de 9% menos tempo na média, checksum 8FE14D9B). O usuário posteriormente confirmou 60 FPS estáveis na seleção e 40–46 FPS na luta, com modelos e som corretos. Isso confirma melhora, mas não a meta de combate. A execução final está aberta em runtime_pgo_release.log, mapa build_test/pgo_release_active.map, configuração fixa 1024 1 1 1 e sem coleta. A meta de 60 FPS em combate continua pendente de medição real.

### Combate: DMA contíguo, entrada rígida e reflexão agrupada

O usuário confirmou 60 FPS estáveis na seleção e 40–46 FPS no combate após o PGO, com modelos e som corretos. A comparação de workers na mesma luta (worker_comparison.json) mediu decodificação mediana de 3,22 ms com workers contra 4,29 ms sem eles. Os intervalos tiveram variação de carga da luta, então não demonstram isoladamente uma diferença exata de FPS. A configuração original foi restaurada: 1024 1 1 1.

locked_cache.c passou da cópia byte a byte para uma ou duas cópias contíguas. Uma transferência tem no máximo 4 KiB e cruza no máximo uma vez o limite de 16 KiB. Preserva bits DMAU/DMAL, status, direção, tamanho zero=128 blocos e rejeição de RAM inválida. O novo alvo locked_cache_contracts compara RAM/LC completos em 1.792 combinações de direção, comprimento e ponto de wrap. Também verifica ausência de transferência sem trigger e em spans inválidos. Benchmark de 500 mil transferências/112 MB: 69,710 → 4,589 ms, checksum 338FA445. Esse ganho é do DMA, não do frame completo.

A entrada 8024BF84 do transformador rígido agora executa o prólogo original antes de chamar o núcleo 8024C014. Isso cobre malhas que terminavam dentro do chunk antes do primeiro yield e não passavam pelo hook da backedge. Preserva stack/backchain, saves/restores, ordem dos loads, GQR, 37 instruções do prólogo e 20 por iteração. As 7.680 combinações compararam CPUState, RAM/LC e orçamento completo com o código gerado. O usuário confirmou novamente 60 FPS na seleção, mas a luta manteve 40–46 FPS. O contador confirmou uso da entrada; não se atribui um ganho global a esse benchmark.

O perfil seguinte, combat_rigid_entry_profile.json, mostrou o trecho de reflexão 8024C500 ainda como maior grupo matemático restante. A revisão seguinte agrupa esse laço: matrizes/câmera e pares SIMD permanecem locais ao longo do quantum; registradores CPU são gravados na saída. Mantém ppc_approx_rsqrt, arredondamento do multiplicador para 25 bits, FMA e ordem dos somatórios. Uma iteração é validada em valores locais antes de alterar o guest. Os stores pendentes antecedem o prefetch, mesmo quando entrada/saída se sobrepõem. O custo é 58 instruções em C500, 56 em C508 e zero adicional na primeira entrada C518, cujo bloco já foi debitado. O epílogo permanece original. Dados fora do domínio conservador usam o caminho anterior/original.

A validação da reflexão foi ampliada para 1.728 casos: RAM/LC, três entradas, quatro quanta (64/256/1024/4096), sobreposição, NI, quatro arredondamentos e flags FPSCR. Compara CPUState completo, memória e downcount e exige uso do novo contador env_batches. Os testes de recusa sem mutação permanecem. Comparação isolada sem jogo/compilador concorrentes: núcleo anterior 27,082 ms contra laço agrupado 14,511 ms para 370 mil vértices; original PPC 67,328/67,156 ms, checksum 6CB80AC5 idêntico. O ganho do núcleo foi aproximadamente 1,87x, sem extrapolação para FPS global.

Build de todos os alvos Release em build_test/environment_loop_validation: saída 0 sem warnings. Artefatos promovidos por cópia para build_test/Release com SHA-256 conferido: A45C72652D14C0D48294874E45C95CAA12E1E3C758B04224194FB22D68C1BDD9. CTest final 3/3, inventário 202 objetos /GL e 10.831 nomes. A captura dos 447 vértices continua byte a byte igual. O PGO foi preservado nos módulos compatíveis: 4.247/4.256 funções e 92,8% das instruções ponderadas do perfil foram usadas, sem necessidade de novo treino para os caminhos inalterados.

Execução atual: runtime_environment_loop.log, mapa build_test/environment_loop_active.map; sem compilador ou coleta ativos, input físico e configuração 1024 1 1 1. Referência anterior exata em build_test/baseline_rigid_entry_verified. O novo contador env_batches permite confirmar processamento agrupado no jogo. O usuário posteriormente confirmou 60 FPS na seleção e aproximadamente 40–46 FPS na luta, com quedas ocasionais próximas de 30. A meta de 60 FPS em combate permanece aberta.

### Acesso curto à RAM nos chunks quentes

O usuário confirmou que a reflexão agrupada manteve 60 FPS na seleção, mas a luta continuou em aproximadamente 40–46 FPS, com quedas ocasionais próximas de 30. env_batches confirmou execução do laço agrupado. Seu benchmark isolado não resolveu o frame completo. A referência dessa execução está em build_test/baseline_environment_loop_verified.

A revisão em teste acrescenta cpu_native_adapter.h via DOLRECOMP_CPU_HEADER, extensão já prevista no header gerado. CMake seleciona dez chunks pelo perfil de leituras/escritas, sem editar recompiled_code/generated: 801C34C0, 8020B4C0, 8023B4C0, 802434C0, 802474C0, 8024B4C0, 802734C0, 802774C0, 802834C0 e 8028B4C0. Somente o acesso de 32 bits aos aliases RAM 800.../C00..., com span completo válido, é expandido no chamador. Endianness continua big endian. Reservas e journal usam mem_write32 original; MEM2, endereços físicos, MMIO e limites usam os callbacks/runtime originais. CPUState e suas assinaturas públicas foram preservados.

O primeiro teste detectou que endereços físicos devem continuar no callback externo deste runtime. Essa hipótese foi corrigida antes da promoção do binário. native_ram_contracts passou em 1.624 combinações com a chave ligada/desligada, tamanhos de RAM pequenos, aliases, acessos unaligned/end-of-range, MEM2, callbacks que alteram registradores, reservas e journal. Compara os bytes completos e CPUState com a API original. O alvo separado permite testar o adaptador sem recompilar os chunks.

A chave host ocupa o quinto campo opcional de runtime_tuning.cfg: quantum, workers, packed_copy, skinning, ram_inline. Os quatro campos anteriores continuam aceitos; na versão experimental ram_inline assumia 1 quando ausente; após a comparação sem ganho, o padrão passou a 0. A mudança é aplicada entre frames e não altera PAD ou memória guest. tools/compare_native_ram.py usa sequência A/B/B/A na mesma luta, filtra scene=4 e o marcador [Native RAM], salva os dados e restaura o arquivo original em finally. O custo CPU por dispatch é estimado subtraindo render, copy e decode do timer total; não é um contador de ciclos.

Build completo Release saída 0 sem warnings, CTest final 4/4, inventário 203 objetos /GL e 10.842 nomes. Os 447 vértices reais continuam byte a byte iguais. Artefato validado promovido com SHA-256 7BD634527365E8352FAF781FB05025549FB28C7FA4AB7A90CEBCD94B9B4C9686. Execução: runtime_native_ram.log, mapa build_test/native_ram_active.map. Configuração inicial 1024 1 1 1 (RAM inline=1). A/B e ganho de FPS ainda pendentes; não se declara 60 FPS em combate.


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
