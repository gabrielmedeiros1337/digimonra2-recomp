# CLAUDE.md — Digimon Rumble Arena 2 Recomp

## Regras para edição

- **NÃO edite** `recompiled_code/generated/` (código gerado pelo recompiler)
- **NÃO refatore** tipos, assinaturas, representação de memória guest
- Endereços guest são **u32**, nunca ponteiros host — use `mem_read32`/`mem_write32`
- Correções vão em: `src_test/`, `CMakeLists.txt`, runtime se necessário
- Só declare algo resolvido após ver build + inventário confirmar

## Comandos de build

```powershell
# Build incremental:
& "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build ".\build_test" --config Release

# Build limpo:
& "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build ".\build_test" --config Release --clean-first

# Inventário de símbolos:
python tools/symbol_inventory.py

# Executar (input físico; confirmar os prompts na janela):
.\build_test\Release\digimon_test.exe
```

## Convenções do projeto

- Funções geradas: `void func_80XXXXXX(CPUState* ctx)`
- Acesso à RAM guest: `mem_read32(ctx, addr)` / `mem_write32(ctx, addr, val)`
- SDK substituído por hooks de PC em `src_test/test_main.c`
- SDL2 em `third_party/SDL2/`, linkado via `SDL2.lib` + `SDL2main.lib`
