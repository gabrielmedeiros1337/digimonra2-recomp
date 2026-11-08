# Digimon Rumble Arena 2 — PC Port

Port nativo para PC de **Digimon Rumble Arena 2** (GameCube) baseado em recompilação estática, executando em código nativo x86-64 com renderização acelerada por GPU em OpenGL, áudio DSP e taxa de quadros a **60 FPS estáveis**.

O projeto visa preservar e modernizar o clássico para computadores modernos, com suporte a telas widescreen, alta resolução interna e suporte completo a controles.

---

## 🎮 Funcionalidades

* **Taxa de Quadros:** Motor de física e renderização rodando a 60 FPS cravados.
* **Resolução da Janela e Tela:** Suporte a resoluções de 640x480 até 4K UHD (3840x2160).
* **Resolução Interna 3D (EFB Scale):** Renderização geométrica em alta definição processada na GPU (1x Nativa, 1.5x, 2x HD, 3x Full HD e 4x Quad HD).
* **Widescreen Real 16:9:** Expansão real de campo de visão horizontal (Hor+ FOV) sem esticar os modelos 3D dos Digimons, com Frustum Culling da CPU ajustado e compensação de aspect ratio 1:1 para o HUD e menus 2D.
* **Modos de Exibição:** Modo Janela, Tela Cheia sem bordas e Tela Cheia exclusiva, com atalho `Alt+Enter` e VSync opcional.
* **Suporte a Controles:** Até 4 jogadores simultâneos com suporte nativo a controles XInput, DirectInput e teclado totalmente remapeável.
* **Memory Card Portátil:** Sistema de save emulado independente no Slot A (`saves/MemoryCardA.card`).
* **Launcher Integrado:** Interface gráfica amigável para configuração de controles, gráficos e inicialização rápida.

---

## 📥 Como Jogar

1. Acesse a aba **[Releases](../../releases/latest)** e baixe o arquivo `DigimonRA2_PC.zip`.
2. Extraia o conteúdo do arquivo ZIP para uma pasta no seu computador.
3. Certifique-se de ter o [Microsoft Visual C++ Redistributable x64](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist) instalado no Windows.
4. Execute o **`DigimonRA2.exe`**.
5. Na aba **Jogar**, clique em **Selecionar ISO...** e aponte para a sua imagem de disco original de GameCube (revisão USA). Formatos suportados: `.iso`, `.ciso`, `.gcm`, `.rvz`.
6. Na aba **Opções**, escolha a sua resolução e proporção de tela preferidas.
7. Clique em **JOGAR**!

---

## 🕹️ Controles Padrão (Teclado)

| Ação GameCube | Teclado |
| :--- | :--- |
| **A / B / X / Y** | Z / X / C / V |
| **Z / Start** | Tab / Enter |
| **L / R** | Q / E |
| **Analógico (Mover)** | W / A / S / D |
| **D-Pad** | Setas direcionais |
| **C-Stick** | I / J / K / L |
| **Alternar Tela Cheia** | Alt + Enter |
| **Sair do Jogo** | Esc |

> Os botões podem ser livremente remapeados na aba **Controles** do Launcher para teclado ou gamepads.

---

## 🛠️ Compilação a partir do Código-Fonte

### Pré-requisitos

* **Sistema:** Windows 10/11 x64
* **Compilador:** Visual Studio 2022 ou 2026 com o workload *Desenvolvimento para desktop com C++* (MSVC x64)
* **CMake:** Versão 3.22 ou superior
* **Python:** Versão 3.10 ou superior
* **Git for Windows**

### Passo a Passo

1. **Clonar o repositório:**
   ```powershell
   git clone https://github.com/gabrielmedeiros1337/digimonra2-recomp.git
   cd digimonra2-recomp
   ```

2. **Gerar os arquivos de projeto:**
   ```powershell
   cmake -S . -B build -G "Visual Studio 17 2022" -A x64
   ```
   *(Caso utilize o Visual Studio 2026, altere o gerador para `"Visual Studio 18 2026"`).*

3. **Compilar a versão Release:**
   ```powershell
   cmake --build build --config Release --parallel
   ```

4. **Gerar o pacote portátil de distribuição:**
   ```powershell
   cmake --build build --config Release --target package_release
   ```
   O pacote portátil configurado será gerado na pasta `DigimonRA2_PC/`.

---

## 📁 Estrutura do Projeto

* `src_test/` — Implementação do motor principal: subsistemas HLE (áudio DSP, memory card, DVD VFS), pipeline gráfico GX/OpenGL e Launcher SDL2.
* `recompiled_code/` — Chunks recompilados estaticamente da lógica do jogo original (PPC750CL).
* `distribution/` — Configurações padrão, assets e textos de distribuição.
* `tools/` — Scripts utilitários de inspeção e empacotamento da release.
* `third_party/` — Dependências e bibliotecas integradas (SDL2, runtime DolRecomp, codecs de descompressão).

---

## ⚖️ Avisos Legais

Este projeto é uma recompilação estática não oficial, criada para fins educacionais, de pesquisa e preservação de software.

* O projeto **NÃO contém ROMs, ISOs, arquivos DOL originais, músicas ou assets protegidos por direitos autorais**.
* Para jogar, o usuário deve possuir e fornecer uma cópia legalmente adquirida de **Digimon Rumble Arena 2** para Nintendo GameCube.
* Digimon e todos os personagens, marcas e nomes relacionados são propriedades intelectuais registradas de Bandai Namco Entertainment, Toei Animation e suas respectivas detentoras. Este projeto não possui afiliação, patrocínio ou endosso de nenhuma dessas empresas.
