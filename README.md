# Digimon Rumble Arena 2 — PC Port

Sua arena de volta ao PC: launcher nativo, controles configuráveis e combate a **60 FPS nativos** no hardware validado. O desempenho pode variar conforme o computador.

## Como jogar — apenas 3 passos

1. Vá em **[Releases](../../releases/latest)** e baixe o arquivo ZIP.
2. Extraia o ZIP inteiro em uma pasta com permissão de escrita e abra **`DigimonRA2.exe`** dentro de `DigimonRA2_PC/`.
3. Clique em **Procurar**, selecione sua **ISO/CISO/RVZ de Digimon Rumble Arena 2 (USA / GameCube)**, configure os controles ou teclado e clique em **JOGAR**!

**Não precisa instalar Visual Studio, CMake ou Python para jogar.** Windows 10/11 x64 e driver gráfico OpenGL do fabricante são necessários. As DLLs do runtime C++ acompanham o pacote.

## Pronto para a batalha

- **4 controles XInput/DInput**, com atribuição por jogador, mais **teclado remapeável**.
- **Memory Card portátil:** as gravações feitas pelo jogo são persistidas automaticamente em `saves/`. Faça backup dessa pasta; fechar o jogo não substitui o comando de salvar.
- **Janela, tela cheia sem bordas e exclusiva**, com **Alt+Enter** e VSync opcional.
- Apresentação na resolução do monitor; a **resolução interna permanece nativa**. FSR e resolução interna HD não estão implementados.
- Coloque seu dump em `games/` se quiser manter tudo organizado, ou selecione-o em qualquer pasta.

O pacote **não inclui o jogo**. É necessário fornecer seu próprio dump da versão USA compatível. Não funciona com a versão Wii ou DOL modificado. O cartão `.card` é próprio deste port, não um `.raw` de outro emulador.

Teclas padrão: **Z/X/C/V** = A/B/X/Y, **Enter** = Start, **WASD** = analógico, **setas** = D-Pad, **Q/E** = L/R, **Tab** = Z. **Esc** fecha o jogo.

Obrigado por baixar e voltar à arena com a gente!

<details>
<summary>Instruções avançadas para Desenvolvedores (Compilação)</summary>

# Digimon Rumble Arena 2 — PC nativo

Recompilação estática da versão **GameCube USA** para **Windows x64**, com
SDL2/OpenGL e subsistemas HLE. O código recompilado já está incluído: você
fornece seu próprio dump original para carregar o DOL e os arquivos do jogo.

## Recursos

- Launcher com abas Jogar, Controles, Opções e Créditos.
- Quatro portas: desconectado, teclado, controle automático ou dispositivo
  SDL específico; teclado remapeável e detecção de controles conectados.
- Leitura de ISO, CISO, NKit ISO e RVZ de GameCube.
- Save portátil no Slot A, com escrita atômica e flush imediato.
- Janela (padrão), tela cheia sem bordas e exclusiva; atalho Alt+Enter.
- VSync opcional, desligado por padrão. FreeSync depende do monitor/driver.
- Áudio, modelos e combate validados pelo usuário, perto de 60 FPS no
  hardware dos testes. A taxa não é garantida para qualquer computador.
- Resolução interna nativa. FSR e renderização interna 720p/1080p **não estão
  implementados**; tela cheia amplia a apresentação da imagem nativa.

## Instalar um pacote compilado

Este commit publica os fontes. O pacote é gerado pelo target `package_release`
descrito abaixo; o ZIP de fontes do GitHub não contém o jogo instalado.
Se você recebeu a pasta compilada `DigimonRA2_PC/`:

1. Use **Windows 10/11 x64**, GPU com driver OpenGL do fabricante e uma pasta
   com permissão de escrita. Extraia o ZIP antes de executar.
2. Instale o [Visual C++ Redistributable x64](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist).
   A versão deve ser pelo menos tão recente quanto o MSVC usado no build.
3. Mantenha `SDL2.dll`, `digimon_test.exe` e `dsp_coef.bin` junto do launcher.
4. Abra **`DigimonRA2.exe`** e escolha **Jogar → Procurar** para selecionar seu dump USA.
5. Na aba **Controles**, atribua P1 e configure P2–P4. Um dispositivo físico
   não ocupa duas portas; o teclado controla apenas a porta escolhida.
6. Em **Opções**, escolha modo de tela e VSync; aplicam-se na próxima abertura.
7. Clique **JOGAR** e confirme os prompts com seus botões físicos.

Não é preciso instalar Dolphin ou colocar um `main.dol` separado no pacote:
o DOL é lido diretamente da imagem original selecionada.

## Compilar e instalar a partir deste repositório

### Pré-requisitos

| Componente | Requisito |
|---|---|
| Sistema | Windows 10/11 x64 |
| Visual Studio | 2026, ambiente validado; workload **Desenvolvimento para desktop com C++**, MSVC x64, Windows SDK e ferramentas CMake |
| CMake | **4.2+ para VS 2026**; o gerador VS 2022 requer CMake 3.21+ |
| Python | 3.10+; validação feita com Python 3.12 |
| Git | Git for Windows |
| Jogo | Dump próprio de Digimon Rumble Arena 2 **USA / GameCube** |

Instaladores oficiais: [Visual Studio](https://visualstudio.microsoft.com/downloads/),
[workload C++](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation),
[CMake](https://cmake.org/download/), [Python](https://www.python.org/downloads/windows/)
e [Git](https://git-scm.com/downloads/win).
Coloque Git, Python e CMake no PATH e reabra o terminal após instalar.

### 1. Clonar e conferir as dependências

```powershell
git clone https://github.com/gabrielmedeiros1337/digimonra2-recomp.git
cd digimonra2-recomp
python tools/verify_dependencies.py
```

**Não precisa usar `--recursive` nem inicializar submódulos.** Os fontes exatos
do runtime e codecs ficam em `third_party/recomp-deps/`, com hashes, origens e
licenças. O SDL2 x64 também está incluído. O build não depende dos commits
locais da antiga árvore ModernGekko nem de baixar um emulador inteiro.

### 2. Configurar Release x64

Com Visual Studio 2026:

```powershell
cmake -S . -B build_test/usability -G "Visual Studio 18 2026" -A x64 -DDIGIMON_PGO_MODE=OFF
```

Para VS 2022, use `"Visual Studio 17 2022"` em um **diretório de build novo**.
Esse toolset não foi validado nesta rodada. Não misture geradores na mesma pasta.

### 3. Compilar

```powershell
cmake --build build_test/usability --config Release --parallel 3
```

A primeira compilação pode levar alguns minutos. Não meça o FPS do jogo
enquanto o compilador/linker estiver trabalhando. Os executáveis ficam em
`build_test/usability/Release/`.

### 4. Verificar

```powershell
ctest --test-dir build_test/usability -C Release --output-on-failure
python tools/symbol_inventory.py --build-dir build_test/usability --report build_test/usability/symbol_inventory_report.txt
```

O build verifica automaticamente a pilha dos chunks após o link. Os contratos
cobrem CPU, áudio, gráficos, input, save, modos de tela, pacote e integridade
das dependências. O inventário localiza `dumpbin` pelo PATH/Visual Studio;
também aceita `--dumpbin <caminho>`.

### 5. Gerar a pasta limpa e jogar

```powershell
cmake --build build_test/usability --config Release --target package_release
.\DigimonRA2_PC\DigimonRA2.exe
```

O target cria **`DigimonRA2_PC/` na raiz**, contendo executáveis, SDL2,
coeficientes DSP, defaults, README, licenças e manifesto. Não copia dump, DOL,
logs, mapas, PDB ou saves pessoais. Reempacotar preserva configurações e saves
que já existam na pasta de saída.

Para distribuir, gere uma pasta nova a partir dos defaults e compacte-a
inteira. Uma instalação já usada pode conter seus caminhos, logs e saves;
confira esses dados antes de publicá-la.

## Dump compatível

É exigido o DOL original USA, conferido pelo SHA-256:

```text
e6ae9c48adb764492609a80632da4d014b89d0f285be92c0c5af012d1b1f889e
```

| Formato | Suporte |
|---|---|
| `.iso` | GameCube raw |
| `.ciso` | Mapa de blocos GameCube |
| `.nkit.iso` | GameCube com FST reconstruída; não é NKit GCZ |
| `.rvz` | GameCube, None/bzip2/LZMA/LZMA2/Zstandard e padding RVZ |

Wii, outras revisões e DOL modificado não são aceitos por esta build estática.
RVZ tem limite de 64 MiB por grupo/metadados. Não há ROM, imagem de disco ou
DOL original no repositório/pacote: forneça seu próprio dump.

## Controles e atalhos

| GameCube | Teclado padrão |
|---|---|
| A / B / X / Y | Z / X / C / V |
| Z / Start | Tab / Enter |
| L / R | Q / E |
| Analógico | W / S / A / D |
| D-Pad | Setas |
| C-Stick | I / K / J / L |
| Alternar janela/tela cheia | Alt+Enter |
| Fechar o jogo | Esc |

Remapeie as vinte ações em Controles. Esc cancela a captura e Delete limpa
o vínculo. Desabilitar o teclado impede seus botões de chegar ao PAD.
Joysticks sem mapeamento SDL usam o layout bruto descrito no README do pacote.
Nenhum botão é pressionado automaticamente.

## Saves e atualização

- Slot A: **`saves/MemoryCardA.card`**, ao lado do executável utilizado.
- É um container HLE próprio; **não é `.raw`/`.gcp` de outro emulador**.
- Use o comando de salvar do jogo; fechar a janela não cria progresso ainda não salvo.
- Para transportar ou guardar progresso, copie `saves/` inteira com o jogo
  fechado. Faça backup antes de atualizar.
- Pastas de desenvolvimento e `DigimonRA2_PC/` são instalações separadas,
  cada uma com seu próprio save/config.
- Configuração: `config/launcher_config.json`; log: `config/runtime.log`.

## Problemas comuns

- **Comando não reconhecido:** ajuste o PATH ou use o terminal de ferramentas
  do Visual Studio e reabra o terminal.
- **MSVC/SDK ausente:** instale o workload C++ completo. VS Code sozinho não
  fornece compilador, linker, SDK ou resource compiler.
- **DLL ausente:** extraia a pasta inteira e instale o VC++ Redistributable x64.
- **Controle não aparece:** reconecte e clique Atualizar, ou escolha Controle
  (automático). Dispositivos iguais sem serial dependem da ordem de conexão.
- **Dump rejeitado:** confira a revisão USA e a integridade do seu dump.
- **Falha gráfica:** confira o driver OpenGL do fabricante e o log.
- **Cache de build antigo:** use uma pasta CMake nova ou um clone novo;
  não reutilize cache com caminhos antigos das dependências.

## Arquitetura e licenças

`src_test/` contém HLE, launcher e backend; `recompiled_code/generated/`
contém o código estático protegido; `tools/` contém os pós-processadores e
verificações; `third_party/recomp-deps/` guarda o runtime e codecs reproduzíveis.

Veja [STABLE_BUILD_NOTES.md](docs/reports/STABLE_BUILD_NOTES.md),
[USABILITY_RELEASE_NOTES.md](docs/reports/USABILITY_RELEASE_NOTES.md) e
[third_party/DEPENDENCIES.md](third_party/DEPENDENCIES.md).
As implementações CPU/GX/timing/chunks foram mantidas na organização das
dependências; os arquivos do snapshot são conferidos por SHA-256.

As dependências preservam suas licenças nos diretórios e no pacote. A ilustração
do Agumon foi fornecida pelo usuário. Este projeto não é afiliado aos detentores
de Digimon; não redistribua seu dump junto do pacote.


Relatórios históricos: [docs/reports](docs/reports/).

</details>
