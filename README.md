# Digimon Rumble Arena 2 - PC Port / Recompilation

Port nativo / recompilação estática de **Digimon Rumble Arena 2 (GameCube)** para PC (Windows x64).

Baseado no framework de recompilação estática de DOLs do GameCube (**DolRecomp** / **ModernGekko**), com camada HLE customizada em C puro sobre **SDL2**.

---

## 🎮 Status Atual

- **Recompilação de Código**: Chunks C de todo o binário DOL gerados e compilando nativamente em 64-bit (`recompiled_code/generated/`).
- **Pipeline Gráfico (GX)**: Emulação de GX FIFO / display lists com renderização via SDL2 e processamento de vértices/quads/triângulos.
- **Entrada (Input)**: Suporte completo a teclado e controle físico (`SDL_GameController`) com detecção de borda (edge detection), deadzone analógica calibrada e mapeamento para GameCube PADStatus.
- **Áudio**: Pipeline de áudio SDL2 inicializado em 48kHz estéreo Big-Endian PCM com integração aos registradores AI.
- **Armazenamento / VFS**: Sistema de arquivos virtual de DVD (`dvd_vfs`) com suporte direto à leitura de imagens `.ciso` e stubs HLE completos de Memory Card (`CARD`).

---

## 🛠️ Como Compilar

### Pré-requisitos
- **Visual Studio 2022** (com suporte a C/C++ Desktop)
- **CMake 3.20+**
- **Git**

### Passo a Passo

1. **Clonar o repositório com submódulos**:
   ```bash
   git clone --recursive https://github.com/gabrielmedeiros1337/digimonra2-recomp.git
   cd digimonra2-recomp
   ```

2. **Configurar o projeto com CMake**:
   ```bash
   cmake -B build -DCMAKE_BUILD_TYPE=Release
   ```

3. **Compilar o executável**:
   ```bash
   cmake --build build --config Release
   ```

O executável `digimon_test.exe` será gerado em `build/Release/`.

---

## 🚀 Como Executar

1. Copie o arquivo `SDL2.dll` da pasta `third_party/SDL2/lib/x64/` para a mesma pasta do executável.
2. Coloque a imagem do jogo no formato `.ciso` ou `.iso` (ex: `Digimon Rumble Arena 2 (USA).ciso`) na pasta raiz ou junto ao executável.
3. Execute `digimon_test.exe`.

### Controles (Teclado Padrão)
- **A**: `Z` ou `J`
- **B**: `X` ou `K`
- **X**: `A` ou `C`
- **Y**: `S` ou `V`
- **Start**: `Enter` ou `Espaço`
- **D-Pad / Analógico**: `Setas` ou `W/A/S/D`
- **L / R**: `Q` / `E` ou `Shift`
- **Z**: `Tab`

*(Controles USB/Bluetooth compatíveis com XInput/DirectInput são mapeados automaticamente via SDL_GameController).*

---

## 📁 Estrutura de Pastas

```
├── src_test/               # Camada HLE, runtime do GameCube e harness principal
│   ├── test_main.c         # Loop principal, hooks de sistema e despachante
│   ├── gx_pipe.c / .h      # Pipeline gráfico GX e decodificação FIFO
│   ├── input.c / .h        # Captura de teclado e controle via SDL2
│   ├── video_audio.c / .h  # Framebuffer XFB, temporização VI e áudio PCM
│   ├── dvd_vfs.c / .h      # Leitura virtual do disco e sistema de arquivos
│   └── dol_loader.c / .h   # Carregamento e mapeamento de memória
├── recompiled_code/        # Código estático descompilado do jogo
│   └── generated/          # Chunks C gerados pelo DolRecomp
├── third_party/            # Bibliotecas de terceiros (SDL2)
├── tools/                  # Utilitários de recompilação (DolRecomp, DTK)
├── ModernGekko-Template/   # Submódulo com o núcleo da CPU PowerPC (DolRecomp)
└── CMakeLists.txt          # Script de build principal
```

---

## ⚖️ Aviso Legal
Este projeto não contém assets protegidos por direitos autorais, ROMs, imagens de disco ou arquivos proprietários da Bandai ou Nintendo. Para executar, o usuário deve fornecer sua própria cópia legal do jogo.
