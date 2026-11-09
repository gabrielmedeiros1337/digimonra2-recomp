# Digimon Rumble Arena 2 — PC Port

Port nativo para PC (Windows e Linux x86_64) de **Digimon Rumble Arena 2** (GameCube USA - `GD6E01`), desenvolvido via recompilação estática do código de máquina PowerPC Gekko para C/C++ nativo, com backend gráfico desacoplado em OpenGL 3.3, subsistema de entrada/áudio SDL2 e execução cravada a **60 FPS nativos**.

Desenvolvido individualmente por **Gabriel Medeiros** ([gabrielmedeiros1337](https://github.com/gabrielmedeiros1337)).

---

## 🇧🇷 Português (PT-BR)

### 🎮 Principais Recursos

* **Execução Nativa a 60 FPS:** Pipeline gráfico GX desacoplado em thread de renderização dedicada assíncrona, eliminando gargalos de emulação tradicional.
* **Launcher Integrado Bilíngue:** Interface gráfica leve com suporte a alternância em tempo real entre Português (PT-BR) e Inglês (EN).
* **Escalonamento de Resolução Interna 3D (EFB Scale):** Renderização geométrica de alta precisão processada na GPU: 1x Nativa (640x528), 1.5x (720p), 2x HD (1080p), 3x Quad HD e 4x Ultra HD (4K).
* **Widescreen Real 16:9:** Expansão real de campo de visão horizontal (Hor+ FOV) sem esticar modelos 3D ou distorcer a interface (HUD 1:1), além do modo 4:3 clássico.
* **Modos de Exibição:** Janela, Tela Cheia sem bordas e Tela Cheia exclusiva, com atalho `Alt + Enter` e suporte a VSync.
* **Multijogador para até 4 Jogadores:** Suporte plug-and-play a gamepads DirectInput, XInput, controles de Xbox/PlayStation/Switch e teclado mapeável.
* **Memory Card Portátil & Unlock All:** Sistema de save isolado em `saves/MemoryCardA.card` e interruptor dinâmico *Unlock All* na aba Opções (libera temporariamente todos os 8 Digimons secretos, 2 arenas extras e modos sem modificar o arquivo de save original).
* **Ampla Compatibilidade de Imagens:** Leitura direta de dumps originais nos formatos `.iso`, `.gcm`, `.ciso`, `.nkit.iso` e `.rvz` (com compressão Zstandard, LZMA ou bzip2).

---

### 📋 Requisitos de Sistema

| Componente | Requisitos Mínimos (60 FPS / Nativo & 720p) | Requisitos Recomendados (60 FPS / 1080p até 4K) |
| :--- | :--- | :--- |
| **Sistema Operacional** | Windows 10/11 (64-bit) ou Linux x86_64 (Ubuntu 20.04+, SteamOS) | Windows 10/11 (64-bit) ou Linux / SteamOS (Steam Deck) |
| **Processador (CPU)** | Intel Core 2 Duo / Core i3 de 2ª geração ou AMD Athlon / FX equivalente | Intel Core i3 / i5 de 6ª geração, AMD Ryzen 3 ou superior |
| **Memória RAM** | 2 GB de RAM | 4 GB de RAM |
| **Placa de Vídeo (GPU)** | Gráficos integrados com suporte a OpenGL 3.3 (Intel HD Graphics 4000, Radeon HD 5000, GeForce 8800 GT) | Placa dedicada (GeForce GTX 750 / 1050, Radeon RX 550) ou iGPU moderna (Intel Iris Xe / AMD Vega) |
| **Armazenamento** | ~100 MB para o port + espaço para a sua cópia do jogo (.iso/.ciso/.rvz ~700 MB a 1.4 GB) | SSD para carregamento instantâneo |
| **Entrada** | Teclado ou qualquer controle USB / Bluetooth (DirectInput / XInput) | Controle de Xbox, PlayStation ou Switch Pro |

---

### 📥 Como Jogar (Instalação pelo Release)

1. Baixe o pacote correspondente ao seu sistema operacional na aba **[Releases](../../releases/latest)**:
   * **Windows:** `DigimonRA2_PC.zip`
   * **Linux:** `DigimonRA2_PC_Linux_x64.tar.gz`
2. Extraia o pacote para uma pasta com permissões de gravação normais.
3. No Windows, verifique se possui o [Microsoft Visual C++ Redistributable x64](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist) instalado.
4. Execute o inicializador do jogo:
   * **Windows:** dê dois cliques em `DigimonRA2.exe`.
   * **Linux:** execute `./DigimonRA2` ou `python3 tools/linux_launcher.py`.
5. Na aba **Jogar**, clique em **Procurar...** e selecione o seu dump original americano (GameCube USA - ID `GD6E01` / `GD6EB2`). Formatos aceitos: `.iso`, `.ciso`, `.rvz`, `.gcm`, `.nkit.iso`.
6. Configure seus controles e preferências gráficas nas abas **Controles** e **Opções**.
7. Clique no botão **JOGAR**!

---

### 🕹️ Mapeamento Padrão de Controles (Teclado)

| Botão GameCube | Teclado Padrão |
| :--- | :--- |
| **A / B / X / Y** | Z / X / C / V |
| **Z / Start** | Tab / Enter |
| **L / R** | Q / E |
| **Analógico Principal** | W / A / S / D |
| **D-Pad** | Setas Direcionais |
| **C-Stick** | I / K / J / L |
| **Alternar Tela Cheia** | Alt + Enter |
| **Sair do Jogo** | Esc |

> Todos os botões e eixos podem ser remapeados individualmente pela aba **Controles** do Launcher.

---

### 🛠️ Compilação a partir do Código-Fonte

#### Windows (Visual Studio / MSVC)
```powershell
# 1. Clonar o repositório
git clone https://github.com/gabrielmedeiros1337/digimonra2-recomp.git
cd digimonra2-recomp

# 2. Configurar o projeto com CMake
cmake -S . -B build -G "Visual Studio 17 2022" -A x64

# 3. Compilar em modo Release
cmake --build build --config Release --parallel

# 4. Gerar o pacote de distribuição limpo
cmake --build build --config Release --target package_release
```
O pacote portátil completo será montado em `DigimonRA2_PC/`.

#### Linux (GCC / Clang + CMake + Ninja)
```bash
# 1. Instalar dependências no Ubuntu/Debian
sudo apt-get update
sudo apt-get install -y build-essential cmake ninja-build libsdl2-dev libgl1-mesa-dev python3 python3-tk

# 2. Configurar e compilar
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --target digimon_test --config Release

# 3. Gerar o pacote portátil Linux
python3 tools/package_linux.py --source . --binary-dir build --output DigimonRA2_PC_Linux
```

---

### ⚖️ Aviso Legal & Créditos

* Este software é um projeto independente voltado à pesquisa técnica e preservação de software.
* **Nenhum arquivo binário, imagem de disco (ROM/ISO), textura ou áudio protegido por direitos autorais acompanha este repositório ou os executáveis de lançamento.** É expressamente obrigatório fornecer uma cópia legalmente adquirida do jogo original.
* *Digimon Rumble Arena 2* © Bandai / Bandai Namco Entertainment Inc. Todos os direitos reservados.
* Desenvolvimento e engenharia reversa do port por **Gabriel Medeiros** ([gabrielmedeiros1337](https://github.com/gabrielmedeiros1337)).

---

### 📄 Licença

Este projeto é distribuído sob os termos da licença **GNU General Public License v3.0 (GPLv3)**. Consulte o arquivo [`LICENSE`](LICENSE) para o texto completo da licença.

Forks, melhorias e modificações são totalmente permitidos e encorajados sob os termos da GPLv3, desde que a autoria e os créditos originais a **Gabriel Medeiros** ([gabrielmedeiros1337](https://github.com/gabrielmedeiros1337)) sejam expressa e integralmente mantidos em qualquer redistribuição, pacote ou obra derivada.

---

## 🇺🇸 English (EN)

### 🎮 Key Features

* **Native 60 FPS Performance:** Decoupled GX rendering pipeline running on an asynchronous dedicated worker thread, removing traditional emulation overhead.
* **Integrated Bilingual Launcher:** Lightweight UI with instant real-time language switching between English (EN) and Portuguese (PT-BR).
* **Internal 3D Resolution Scaling (EFB Scale):** GPU-accelerated sub-pixel geometric rendering: 1x Native (640x528), 1.5x (720p), 2x HD (1080p), 3x Quad HD, and 4x Ultra HD (4K).
* **Real 16:9 Widescreen:** Genuine horizontal field of view expansion (Hor+ FOV) without stretching 3D character models or distorting HUD/menus (1:1 aspect preserved), alongside original 4:3 mode.
* **Display Modes:** Windowed, Borderless Desktop, and Exclusive Fullscreen with `Alt + Enter` hotkey and optional VSync support.
* **Up to 4-Player Local Multiplayer:** Seamless plug-and-play support for DirectInput, XInput, Xbox, PlayStation, Switch gamepads, and fully customizable keyboard controls.
* **Portable Memory Card & Dynamic Unlock All:** Dedicated save file located at `saves/MemoryCardA.card` and an instant *Unlock All* toggle in the Options tab (temporarily unlocks all 8 secret Digimon, 2 hidden stages, and rules without altering the original save file).
* **Broad Image Format Compatibility:** Direct out-of-the-box loading for original GameCube USA dumps in `.iso`, `.gcm`, `.ciso`, `.nkit.iso`, and `.rvz` formats (with Zstandard, LZMA, or bzip2 compression).

---

### 📋 System Requirements

| Component | Minimum Requirements (60 FPS / Native & 720p) | Recommended Requirements (60 FPS / 1080p up to 4K) |
| :--- | :--- | :--- |
| **Operating System** | Windows 10/11 (64-bit) or Linux x86_64 (Ubuntu 20.04+, SteamOS) | Windows 10/11 (64-bit) or Linux / SteamOS (Steam Deck) |
| **Processor (CPU)** | Intel Core 2 Duo / 2nd Gen Core i3 or AMD Athlon / FX equivalent | Intel 6th Gen Core i3 / i5, AMD Ryzen 3 or higher |
| **Memory (RAM)** | 2 GB RAM | 4 GB RAM |
| **Graphics (GPU)** | Integrated graphics with OpenGL 3.3 support (Intel HD Graphics 4000, Radeon HD 5000, GeForce 8800 GT) | Dedicated GPU (GeForce GTX 750 / 1050, Radeon RX 550) or modern iGPU (Intel Iris Xe / AMD Vega) |
| **Storage** | ~100 MB for the port + disk space for your game dump (.iso/.ciso/.rvz ~700 MB to 1.4 GB) | SSD for near-instantaneous load times |
| **Input** | Keyboard or any USB / Bluetooth controller (DirectInput / XInput) | Xbox, PlayStation, or Switch Pro Controller |

---

### 📥 How to Play (Release Installation)

1. Download the package for your operating system from the **[Releases](../../releases/latest)** section:
   * **Windows:** `DigimonRA2_PC.zip`
   * **Linux:** `DigimonRA2_PC_Linux_x64.tar.gz`
2. Extract the archive into a folder with standard read/write permissions.
3. On Windows, make sure you have the [Microsoft Visual C++ Redistributable x64](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist) installed.
4. Launch the application:
   * **Windows:** Double-click `DigimonRA2.exe`.
   * **Linux:** Run `./DigimonRA2` or `python3 tools/linux_launcher.py`.
5. On the **Play** tab, click **Browse...** and select your legally obtained GameCube USA dump (ID `GD6E01` / `GD6EB2`). Supported formats: `.iso`, `.ciso`, `.rvz`, `.gcm`, `.nkit.iso`.
6. Configure controller bindings and visual preferences under the **Controls** and **Options** tabs.
7. Click **PLAY**!

---

### 🕹️ Default Keyboard Bindings

| GameCube Input | Default Key |
| :--- | :--- |
| **A / B / X / Y** | Z / X / C / V |
| **Z / Start** | Tab / Enter |
| **L / R** | Q / E |
| **Control Stick** | W / A / S / D |
| **D-Pad** | Arrow Keys |
| **C-Stick** | I / K / J / L |
| **Toggle Fullscreen** | Alt + Enter |
| **Exit Game** | Esc |

> All buttons, sticks, and triggers can be freely remapped under the **Controls** tab for both keyboard and physical gamepads.

---

### 🛠️ Building from Source Code

#### Windows (Visual Studio / MSVC)
```powershell
# 1. Clone the repository
git clone https://github.com/gabrielmedeiros1337/digimonra2-recomp.git
cd digimonra2-recomp

# 2. Configure project with CMake
cmake -S . -B build -G "Visual Studio 17 2022" -A x64

# 3. Build in Release configuration
cmake --build build --config Release --parallel

# 4. Generate the clean portable distribution package
cmake --build build --config Release --target package_release
```
The portable package will be created in `DigimonRA2_PC/`.

#### Linux (GCC / Clang + CMake + Ninja)
```bash
# 1. Install dependencies on Ubuntu/Debian
sudo apt-get update
sudo apt-get install -y build-essential cmake ninja-build libsdl2-dev libgl1-mesa-dev python3 python3-tk

# 2. Configure and build
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --target digimon_test --config Release

# 3. Generate Linux portable package
python3 tools/package_linux.py --source . --binary-dir build --output DigimonRA2_PC_Linux
```

---

### ⚖️ Disclaimer & Credits

* This software is an independent open-source static recompilation intended for software preservation and technical study.
* **No copyrighted assets, ROM images, ISOs, audio tracks, or proprietary game code are distributed within this repository or release packages.** Users must provide their own legally acquired GameCube game dump.
* *Digimon Rumble Arena 2* © Bandai / Bandai Namco Entertainment Inc. All rights reserved.
* Port development and static recompilation engineering by **Gabriel Medeiros** ([gabrielmedeiros1337](https://github.com/gabrielmedeiros1337)).

---

### 📄 License

This project is licensed under the terms of the **GNU General Public License v3.0 (GPLv3)**. See the [`LICENSE`](LICENSE) file for the full license text.

Forks, enhancements, and modifications are welcomed and permitted under the GPLv3, provided that original authorship and credits to **Gabriel Medeiros** ([gabrielmedeiros1337](https://github.com/gabrielmedeiros1337)) are fully and visibly preserved in any redistribution, package, or derivative work.
