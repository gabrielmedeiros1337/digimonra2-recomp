# Validação do envio ao GitHub — 2026-11-08

O código funcional anterior é `fe740c6`. O commit `b413612` organiza as
dependências e documenta a instalação; não modifica CPU, GX, timing, chunks
ou os scripts de otimização. Nenhuma opção de otimização foi alterada.

## Clone independente

Foi criado um clone local novo, sem hardlinks e sem a antiga pasta
`ModernGekko-Template`. A validação não usou o DOL, a imagem do jogo, os
arquivos ignorados ou o cache de build do checkout de desenvolvimento.

- `python tools/verify_dependencies.py`: **407 arquivos conferidos**.
- CMake/MSVC, Visual Studio 18 2026, x64, Release, PGO OFF: **saída 0**.
- CTest: **24/24 aprovados**, incluindo o contrato de integridade das dependências.
- Inventário: **219 objetos /GL e 117.738 símbolos no mapa final**.
- Pilha dos 185 chunks públicos: **máximo 72 bytes**.
- Pilha das regiões internas: **máximo 168 bytes**, **zero `__chkstk`**.
- `package_release`: **saída 0**, allowlist de 15 artefatos copiados, sem
  dump, DOL, mapas, PDB, logs ou saves do desenvolvedor.

O build limpo mostra os avisos D9025 já existentes quando `/Ob3` substitui
`/Ob2` na unidade da CPU; a opção efetiva da base foi preservada. Não houve
erro de compilação ou link. Os contratos não substituem uma medição de FPS
em cada computador nem uma nova sessão manual de combate.

## Preservação da base

Os arquivos do snapshot foram copiados byte a byte das dependências da
build validada; o manifesto registra origens, commits e SHA-256. Atributos
Git preservam esses bytes também em um clone Windows.

O checkout histórico local e a tag `v1.0-stable-60fps` foram preservados.
O SHA-256 do executável congelado `build_test/Release/digimon_test.exe`
permaneceu:

```text
ecea9f470b2affe7b207c80899cdebc74da7040f8b19a87757148c9a5b2c9959
```

O envio publica fontes, dependências e instruções na branch `main`.
O pacote de executáveis continua sendo gerado localmente pelo CMake;
não se publica uma imagem do jogo nem um save de usuário.
