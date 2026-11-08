DIGIMON RUMBLE ARENA 2 — PC NATIVO

Abra DigimonRA2.exe. Clique em Procurar, selecione seu dump original USA,
configure as quatro portas e clique em JOGAR. Não há ROM, DOL ou assets do
jogo neste pacote. O DOL é carregado diretamente da sua imagem de disco.

REQUISITOS
Windows 10/11 x64, OpenGL e o Microsoft Visual C++ Redistributable x64 atual.
SDL2.dll deve ficar ao lado dos executáveis. Use uma pasta com permissão de
escrita; configurações e saves ficam junto do jogo, nunca no AppData.

IMAGENS
ISO e CISO GameCube; NKit ISO de GameCube com FST reconstruída; RVZ GameCube
com compressão None, bzip2, LZMA, LZMA2 ou Zstandard e padding RVZ.
Imagens Wii e outras revisões do jogo não são compatíveis com este recomp.
É conferido o SHA-256 do DOL original USA:
e6ae9c48adb764492609a80632da4d014b89d0f285be92c0c5af012d1b1f889e
O launcher valida os bytes, não apenas a extensão do arquivo.

CONTROLES
Cada dispositivo físico ocupa uma porta, livremente escolhida de 1 a 4.
As três opções fixas são Desconectado, Teclado e Controle (automático).
Controle automático usa o próximo dispositivo disponível, sem duplicá-lo
em outra porta. Os controles detectados também aparecem pelo nome, para
atribuição específica. Se conectar depois de abrir, clique em Atualizar.
Controles iguais são identificados pelo GUID SDL e sua ordem de conexão;
reconecte-os na mesma ordem ou reatribua as portas no launcher.
Para controles sem mapeamento SDL, o modo joystick usa botões 1–8 e eixos
1–4; o layout varia conforme o driver. XInput usa o mapeamento SDL padrão.

Teclado padrão (pode ser remapeado no launcher):
A=Z, B=X, X=C, Y=V, Z=Tab, Start=Enter, L=Q, R=E.
Analógico=WASD; D-Pad=setas; C-Stick=I/K/J/L.
Esc fecha o jogo e é reservado. No editor de teclas, Esc cancela e Delete
remove o vínculo. O teclado só controla uma porta; desmarcar sua opção
ignora completamente o teclado no PAD. Nenhum botão é pressionado sozinho.
Em controle SDL: A/B/X/Y correspondentes; Start=Start; Z=ombro direito ou
Back; L=ombro esquerdo/gatilho esquerdo; R=gatilho direito; sticks e D-Pad.

SAVE PORTÁTIL
Slot A: saves/MemoryCardA.card. Slot B permanece desconectado.
É um container HLE próprio de 128 Mbit, com diretório/metadados CARD,
blocos de 8192 bytes e checksum de integridade; não é uma imagem .raw/.gcp.
Guarde uma cópia de toda a pasta saves/ para transportar seu progresso.
Cada escrita e mudança de metadados usa arquivo temporário, flush em disco
e substituição atômica antes de informar sucesso ao jogo. Cartão corrompido
é reportado como erro e nunca formatado automaticamente. Uma segunda
instância não pode escrever no mesmo cartão simultaneamente.
Fechar a janela não substitui o comando de salvar do próprio jogo.

CONFIGURAÇÕES E DIAGNÓSTICO
config/launcher_config.json guarda imagem, portas e teclas.
config/runtime_tuning.cfg e dispatch_chain.cfg preservam a base de performance.
Não altere esses dois arquivos para configurar controles.
O launcher mantém config/runtime.log e uma execução anterior; estes logs
são criados ao rodar, não distribuídos no pacote. Em caso de falha, envie o log.

DEPENDÊNCIAS
Consulte LICENSES/ e THIRD_PARTY_NOTICES.txt. Este projeto não é afiliado
aos detentores da marca Digimon. Use seu próprio dump do jogo.
