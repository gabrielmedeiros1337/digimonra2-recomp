# Camada portátil: launcher, controles, CARD e distribuição

Base: tag local `v1.0-stable-60fps`, commit
`2e912fd8742feee44776ac730680e0de8e8fc8b0`. Desenvolvimento isolado na branch
`codex/launcher-portable-save`, build em `build_test/usability/`.

## Limites da alteração

Os fontes de chunks, scripts de segmentação/dead stores, runtime CPU, headers
de RAM, GX, arenas, worker CPU, orçamento guest e pacer permanecem iguais à tag.
O `CMakeLists.txt` inclui `cmake/Usability.cmake`; as opções de compilação da
base, PGO OFF e checagem pós-link da pilha são preservadas.

`test_main.c` recebe apenas inicialização portátil, configuração de input,
entradas CARD no dispatcher e seleção do caminho dos dois arquivos de tuning.
O loop de execução continua o mesmo. Não há botões automáticos.

O executável congelado em `build_test/Release/` e o snapshot em
`build_test/stable_release/v1.0-stable-60fps/` não são substituídos por este build.

## Inicialização e launcher

`DigimonRA2.exe` é uma GUI Win32/GDI com tema azul/escuro, sem navegador,
serviço residente, Dear ImGui ou dependência de assets comerciais para a UI.
SDL2 fornece enumeração de dispositivos e identificação de teclas. O launcher
cria o processo `digimon_test.exe --portable --disc <imagem>` diretamente via
`CreateProcessW`, sem shell e com quoting Windows. Diretório de trabalho e
configuração são relativos à pasta dos executáveis.

O launcher valida o DOL da imagem pelo SHA-256 antes de iniciar. A revisão
suportada é a USA com hash
`e6ae9c48adb764492609a80632da4d014b89d0f285be92c0c5af012d1b1f889e`.
O core repete a validação para impedir que uma invocação direta ignore isso.
O DOL é lido para memória e passado ao mesmo carregador/boot existente. Não há
extração persistente nem cópia de DOL no pacote.

Os argumentos antigos `<main.dol> <disco>` e os modos de contratos continuam
disponíveis para desenvolvimento.

## Discos

`disc_image.cpp` implementa leitura virtual em offsets de disco:

| Formato | Tratamento |
|---|---|
| ISO | Leitura raw com offsets de 64 bits e validação de limites |
| CISO GameCube | Mapa de blocos presentes/ausentes; ausentes retornam zero |
| NKit ISO GameCube | Rota raw/FST relocada, como FileBlob no Dolphin; não é NKit GCZ |
| RVZ GameCube | Tabelas raw/groups, header SHA-1, cache LRU de quatro grupos, padding PRNG e codecs None/bzip2/LZMA/LZMA2/Zstandard |

A especificação usada é o documento `docs/WiaAndRvz.md` do Dolphin já pinado no
vendor. A implementação não inclui partições Wii. O limite de grupo/metadata
descomprimido é 64 MiB; uso de memória do decoder LZMA é limitado a 256 MiB.
Formatos/revisões inválidos são rejeitados antes do boot. Falhas/truncamento
durante leitura de assets continuam chegando como erro DVD, não como sucesso.

O worker e a publicação assíncrona DVD existentes são mantidos. O mutex da
camada DVD também serializa o cache/seek do leitor; o worker não escreve RAM
guest nem executa callbacks por conta própria.

## Controles

`input_devices.c` fornece nomes e IDs `GUID SDL:ordinal` para dispositivos.
`input.c` abre até quatro dispositivos independentes, trata hotplug e mantém
o mesmo snapshot imutável de PAD entregue ao worker CPU.

Cada porta recebe `none`, `keyboard` ou um dispositivo. Dispositivo duplicado
é removido da outra porta no launcher; o runtime também impede duplicidade.
Dispositivos idênticos sem identificador serial distinguem-se pela ordem de
conexão. A escolha é persistida em `config/launcher_config.json`.

A opção fixa **Controle (automático)** (`auto`) ocupa o próximo dispositivo
livre; atribuições explícitas de dispositivos têm prioridade. Várias portas
podem usar `auto`, mas um dispositivo nunca é compartilhado. O botão Atualizar
reinicializa apenas a enumeração joystick/GameController do launcher, útil
para controles conectados depois de sua abertura. A configuração de teclado
é desabilitada ao retirar o teclado da porta que lhe estava atribuída.

O teclado exige a checkbox habilitada **e** a porta escolhida atribuída a
`keyboard`. Sem foco na janela do jogo, os botões ficam soltos; desabilitado,
não participa do PAD. A porta desconectada produz `PADStatus.err = -1` e não
entra na máscara de controladores conectados.

Todos os vinte vínculos são editáveis: A/B/X/Y/Z/Start/L/R e quatro direções
para analógico, D-Pad e C-Stick. Padrão: Z/X/C/V/Tab/Enter/Q/E; WASD; setas;
I/K/J/L. O helper legado de teclas extras permanece apenas como contrato
compatível; não injeta os antigos atalhos 7/8/9 no input configurado.

GameController usa o mapeamento SDL (incluindo XInput); controles não mapeados
usam joystick, oito botões, quatro eixos e hat. Os limites desse layout bruto
estão no README do pacote.

## Save Slot A

`card_hle.c` intercepta entradas públicas CARD da revisão USA. Os principais
endereços são:

| Serviço | Endereço |
|---|---|
| Init / ProbeEx / Mount | `802A8A70` / `802AA8D4` / `802AB138` |
| Check / FreeBlocks | `802AA728` / `802A8D60` |
| Open / Close / Create | `802ABF28` / `802AC0A0` / `802AC44C` |
| Read / Write | `802AC8C4` / `802ACCCC` |
| Delete / GetStatus / SetStatus | `802AD03C` / `802AD27C` / `802AD51C` |
| MountAsync / ReadAsync / WriteAsync | `802AAF98` / `802AC77C` / `802ACBB8` |

Também há OpenByNumber, DeleteByNumber, CreateAsync, CheckExAsync, Unmount,
GetResultCode, GetMemSize, GetSectorSize, Probe e Format. A lista de chamadas
diretas do código do jogo para a região CARD foi conferida no DOL, incluindo
o wrapper síncrono `CARDCheck` em `802AA728`.

`CARDFileInfo` tem 20 bytes; `CARDStat` tem 108 bytes, com banner, TLUT e oito
offsets de ícones calculados conforme o SDK. Nomes/dados permanecem em bytes
guest; inteiros de estruturas são big-endian. Os callbacks assíncronos usam
a fila existente, com **r3 = canal, r4 = resultado**, sem alterar o mecanismo
de preservação de contexto/callbacks. Slot B retorna desconectado.

`card_store.cpp` persiste `saves/MemoryCardA.card`: container próprio HLE
versionado, capacidade lógica de 128 Mbit, 127 entradas de diretório de
64 bytes, dados em múltiplos de 8192 bytes e CRC-32. Não é `.raw`/`.gcp` e não
deve ser importado como raw em outro emulador.

Cada create/write/delete/status/format grava um temporário, chama
`FlushFileBuffers` e troca o arquivo com `MoveFileExW(...WRITE_THROUGH)` antes
de informar sucesso. Falha de I/O restaura o estado em memória. Um lock de
arquivo impede duas instâncias de escreverem simultaneamente. Cartão inválido
retorna BROKEN; somente um comando Format do jogo pode apagá-lo. Saves não são
incluídos no pacote nem substituídos pelo script de empacotamento.

## Build e pacote

```powershell
cmake -S . -B build_test/usability -A x64 -DDIGIMON_PGO_MODE=OFF
cmake --build build_test/usability --config Release --parallel 3
ctest --test-dir build_test/usability -C Release --output-on-failure
cmake --build build_test/usability --config Release --target package_release
```

No ambiente atual, CMake/CTest estão na instalação do Visual Studio 18, fora
do PATH. Use o caminho completo se necessário.

`tools/package_release.py` usa allowlist explícita. A saída `DigimonRA2_PC/`
contém launcher, core, SDL2, coeficientes DSP, README, licenças, manifesto,
defaults em `config/` e `saves/` vazio. Não copia mapas, PDB, fontes, logs,
ROM/DOL nem saves do desenvolvedor. A redistribuição do runtime VC++ x64 é
pré-requisito documentado; não se copiam DLLs arbitrárias do System32.

Reempacotar preserva configurações e saves existentes, mas recusa uma pasta
desconhecida ou com artefatos inesperados. O manifesto identifica commit,
estado modificado e hashes dos arquivos efetivamente empacotados.

## Verificação

Os contratos novos cobrem JSON/Unicode, teclado desabilitado/foco/porta,
joystick SDL virtual em porta independente, ABI CARD, callbacks, dados e
metadados persistidos após reabertura, corrupção/capacidade/limites, allowlist
do pacote e preservação de saves/config. Os fixtures RVZ cobrem cinco codecs,
packing literal, acesso aleatório e leitura cruzando grupos. A identidade e o
DOL foram conferidos também na CISO original local.

O teste visual de um save criado e recarregado pelos menus do jogo depende
dos botões físicos do usuário. Não há automação de prompts ou combate.

### Resultado da validação desta revisão

- Build Release isolado: saída 0; PGO OFF.
- CTest: **22/22**, incluindo as 19 suítes anteriores e três suítes novas.
- Inventário final: 218 objetos /GL, 117.714 símbolos no mapa; imports
  conferidos no executável final (relatório em `build_test/usability_symbol_inventory.txt`).
- 185 chunks públicos: pilha máxima 72 bytes; regiões internas: máximo
  168 bytes; zero prólogos `__chkstk`.
- SHA-256 do executável congelado continua
  `ecea9f470b2affe7b207c80899cdebc74da7040f8b19a87757148c9a5b2c9959`.
- Pacote inicial: 18 arquivos, aproximadamente 52,51 MiB, sem dump/DOL/save,
  com os 15 artefatos copiados conferidos pelo manifesto SHA-256.
- Launcher verificado visualmente; captura de tecla A foi alterada para H
  e conferida na UI. O padrão distribuído permanece Z.

Atualização de controles: seleção fixa Controle (automático), prioridade de
atribuições explícitas e detecção Ultimate C / XInput slot 1 conferidas;
22/22 contratos reaprovados após a alteração.

No teste manual em portable_smoke, o usuario atribuiu o Ultimate C Wired
Controller ao P1 e desabilitou o teclado. O jogo criou uma entrada CARD de
8192 bytes; payload nao-zero e CRC do container foram conferidos no disco.
A confirmacao de carregar progresso apos reiniciar ainda depende do usuario.

## Launcher em abas

Jogar, Controles, Opções e Créditos usam grupos de controles Win32 separados,
sem recriar a configuração ou perder vínculos ao mudar de aba. A imagem
`distribution/assets/agumon.jpg`, fornecida pelo usuário, fica embutida no
recurso RCDATA do executável e é desenhada por GDI+ somente no launcher.
O link dos créditos abre o repositório no navegador padrão.

A opção JSON `vsync` é um booleano opcional: configurações anteriores continuam
válidas e usam OFF. Ao iniciar o core, apenas a solicitação inicial de VSync
SDL/OpenGL recebe esse valor. O orçamento, pacer e limite guest de 60 FPS não
são alterados. FSR aparece como indisponível: não há shader FSR no backend.

## Transparência e modos de tela

O recorte `distribution/assets/agumon-transparent.png` tem alpha RGBA real,
incorporado como RCDATA. O painel branco atrás da imagem foi removido; GDI+
compõe o PNG sobre o tema escuro. O original JPG foi preservado. O prompt e
método de edição ficam no arquivo `.prompt.txt` ao lado do PNG.

`window_mode` é um inteiro opcional no JSON: 0=janela (padrão e migração),
1=sem bordas desktop, 2=exclusiva. `display_mode.c` mantém as coordenadas e o
tamanho de janela, usa SDL_WINDOW_FULLSCREEN_DESKTOP ou SDL_WINDOW_FULLSCREEN
conforme a escolha, e seleciona o modo atual do monitor para exclusiva.
Alt+Enter é tratado nas duas bombas de eventos da thread principal, ignora
repetição e alterna para janela/restaura o último modo de tela cheia. Iniciar
em janela define sem bordas como destino inicial do atalho.
O Enter desse atalho é suprimido no PAD até ser solto; não confirma prompts.
Não foram alterados chunks, GX, orçamento, pacer ou filas de renderização.

Validação: 23/23 CTest, incluindo transições SDL janela/sem bordas/exclusiva,
restauração de dimensões, repetição do atalho e configurações legadas sem
`window_mode`. O monitor/driver continua responsável pelo suporte a FreeSync.

## Publicação reproduzível

As referências históricas a `ModernGekko-Template/` acima descrevem o checkout
local original. O build atual usa o snapshot idêntico em
`third_party/recomp-deps/`, sem submódulos. O SDL2 x64 necessário também é
versionado. Consulte o README e `PUBLISH_VALIDATION.md`: o clone independente
compilou, passou no inventário/pilha e nos 24 testes, incluindo integridade
do snapshot. A build congelada original não foi substituída.
