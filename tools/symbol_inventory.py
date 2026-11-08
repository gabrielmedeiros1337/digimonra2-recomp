#!/usr/bin/env python3
"""
symbol_inventory.py - Inventário de símbolos para Digimon Rumble Arena 2 recomp (MSVC/Windows)
Lê .obj via dumpbin /SYMBOLS, agrupa por módulo, categoriza e reporta.
"""
import subprocess
import sys
import os
import re
import argparse
import shutil
from pathlib import Path
from collections import defaultdict

DUMPBIN = r"C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\bin\Hostx64\x64\dumpbin.exe"
OBJ_DIR = r"build_test\digimon_test.dir\Release"
REPORT  = "symbol_inventory_report.txt"
LINK_MAP = r"build_test\Release\digimon_test.map"
EXECUTABLE = r"build_test\Release\digimon_test.exe"

def run_dumpbin(obj_path):
    try:
        result = subprocess.run(
            [DUMPBIN, "/SYMBOLS", obj_path],
            capture_output=True, text=True, errors="replace"
        )
        return result.stdout
    except Exception as e:
        return f"ERROR: {e}"

def categorize(name):
    if name.startswith('__imp_'): return categorize(name[6:])
    if re.match(r'^func_[89][0-9A-Fa-f]{7}$', name): return "GENERATED_FUNC"
    if re.match(r'^lbl_[89][0-9A-Fa-f]{7}$', name):  return "GENERATED_LABEL"
    if re.match(r'^loop_[89][0-9A-Fa-f]{7}$', name): return "GENERATED_LOOP"
    if re.match(r'^dolrecomp_', name):                return "RUNTIME_DOLRECOMP"
    if re.match(r'^ppc_', name):                      return "RUNTIME_PPC"
    if re.match(r'^mem_(read|write)', name):          return "RUNTIME_MEM"
    if re.match(r'^cpu_', name):                      return "RUNTIME_CPU"
    if re.match(r'^__', name):                        return "COMPILER_HELPER"
    if re.match(r'^SDL_|^SDL2', name):                return "HOST_SDL2"
    if re.match(r'^gl[A-Z]|^GL_', name):              return "HOST_GL"
    for sdk in ['GX','VI','AI','PAD','DVD','CARD','AX','OS','AR','DSP']:
        if re.match(r'^' + sdk, name):               return f"SDK_{sdk}"
    if re.match(r'^video_|^audio_|^gx_pipe_|^input_|^dol_|^dvd_', name): return "HLE_PLATFORM"
    return "UNKNOWN"

def main():
    global DUMPBIN, OBJ_DIR, REPORT, LINK_MAP, EXECUTABLE
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build-dir', type=Path, help='CMake binary directory')
    parser.add_argument('--config', default='Release')
    parser.add_argument('--dumpbin', type=Path)
    parser.add_argument('--report', type=Path)
    args = parser.parse_args()
    if args.build_dir:
        base = args.build_dir.resolve()
        OBJ_DIR = str(base / 'digimon_test.dir' / args.config)
        LINK_MAP = str(base / args.config / 'digimon_test.map')
        EXECUTABLE = str(base / args.config / 'digimon_test.exe')
    if args.report:
        REPORT = str(args.report)
    candidates = [str(args.dumpbin)] if args.dumpbin else [shutil.which('dumpbin'), DUMPBIN]
    if not any(p and os.path.isfile(p) for p in candidates):
        vswhere = Path(os.environ.get('ProgramFiles(x86)', 'C:/Program Files (x86)')) / 'Microsoft Visual Studio/Installer/vswhere.exe'
        if vswhere.is_file():
            result = subprocess.run([str(vswhere), '-latest', '-products', '*', '-requires', 'Microsoft.VisualStudio.Component.VC.Tools.x86.x64', '-find', 'VC/Tools/MSVC/**/bin/Hostx64/x64/dumpbin.exe'], capture_output=True, text=True)
            candidates.extend(result.stdout.splitlines())
    DUMPBIN = next((p for p in candidates if p and os.path.isfile(p)), '')
    if not DUMPBIN:
        raise SystemExit('dumpbin.exe not found. Use a VS x64 Native Tools terminal or --dumpbin <path>.')
    if not os.path.isdir(OBJ_DIR):
        print(f"OBJ_DIR não encontrado: {OBJ_DIR}")
        sys.exit(1)

    objs = [f for f in os.listdir(OBJ_DIR) if f.endswith('.obj')]
    print(f"Encontrados {len(objs)} arquivos .obj em {OBJ_DIR}")

    # defined[name] = list of modules defining it
    defined   = defaultdict(list)
    # undefined[name] = list of modules referencing it
    undefined = defaultdict(list)
    opaque = []

    for obj_name in sorted(objs):
        obj_path = os.path.join(OBJ_DIR, obj_name)
        module   = obj_name.replace('.obj', '')
        out      = run_dumpbin(obj_path)
        found_symbols = False
        
        for line in out.splitlines():
            # MSVC dumpbin /SYMBOLS output lines look like:
            # 000 00000000 UNDEF  notype ()    External | _name
            # 001 00000000 SECT1  notype ()    External | _name
            m = re.search(r'\|\s+(\S+)\s*$', line)
            if not m:
                continue
            found_symbols = True
            sym = m.group(1)  # x64: preserve compiler/import prefixes
            
            if 'UNDEF' in line and 'External' in line:
                undefined[sym].append(module)
            elif 'External' in line and 'UNDEF' not in line:
                defined[sym].append(module)
        if not found_symbols and 'ANONYMOUS OBJECT' in out:
            opaque.append(module)

    linked = {}
    if os.path.isfile(LINK_MAP):
        with open(LINK_MAP, encoding='utf-8', errors='replace') as f:
            for line in f:
                match = re.match(r'\s+[0-9A-Fa-f]{4}:[0-9A-Fa-f]{8}\s+(\S+)\s+([0-9A-Fa-f]{16})\b', line)
                if match:
                    linked[match[1]] = match[2]
    if opaque and not {'main', 'func_80003100'}.issubset(linked):
        raise SystemExit('Objetos /GL exigem mapa final válido; recompile o target com /MAP.')
    imports = []
    if os.path.isfile(EXECUTABLE):
        result = subprocess.run([DUMPBIN, '/IMPORTS', EXECUTABLE], capture_output=True, text=True, errors='replace')
        if result.returncode:
            raise SystemExit('dumpbin /IMPORTS falhou no executável final.')
        imports = sorted(set(re.findall(r'^\s+(\S+\.dll)\s*$', result.stdout, re.I | re.M)))

    # Find multidefined and truly undefined
    multidefined = {s: mods for s, mods in defined.items() if len(mods) > 1}
    truly_undef  = {s: refs for s, refs in undefined.items() if s not in defined}

    lines = []
    lines.append("=" * 70)
    lines.append("INVENTÁRIO DE SÍMBOLOS - Digimon Rumble Arena 2 Recomp")
    lines.append("=" * 70)
    lines.append(f"Total de .obj analisados: {len(objs)}")
    lines.append(f"Objetos /GL sem tabela COFF legível por /SYMBOLS: {len(opaque)}")
    if opaque:
        lines.append('Contagens pré-link indisponíveis para /GL; zero símbolos COFF não comprova resolução.')
    else:
        lines.append(f"Símbolos DEFINIDOS únicos: {len(defined)}")
        lines.append(f"MULTIDEFINIDOS/COMDAT pré-link: {len(multidefined)}")
        lines.append(f"Referências externas pré-link (incluem imports): {len(truly_undef)}")
    lines.append(f"Símbolos no mapa do executável ligado: {len(linked)}")
    lines.append(f"DLLs de importação no executável: {', '.join(imports)}")
    lines.append('O linker determina resolução final; COMDATs e imports pré-link não são erros de link.')
    if linked:
        lines.append('--- MAPA FINAL POR CATEGORIA ---')
        linked_categories = defaultdict(int)
        for name in linked:
            linked_categories[categorize(name)] += 1
        for category, count in sorted(linked_categories.items()):
            lines.append(f'  {category}: {count}')
    lines.append("")

    # Count by category
    cat_undef = defaultdict(int)
    for s in truly_undef:
        cat_undef[categorize(s)] += 1
    
    if truly_undef:
        lines.append("--- INDEFINIDOS POR CATEGORIA ---")
        for cat, count in sorted(cat_undef.items(), key=lambda x: -x[1]):
            lines.append(f"  {cat}: {count}")
        lines.append("")
        lines.append("--- LISTA DE INDEFINIDOS ---")
        for sym, refs in sorted(truly_undef.items()):
            cat = categorize(sym)
            lines.append(f"  [{cat}] {sym}")
            for r in refs[:3]:
                lines.append(f"      ref: {r}")
        lines.append("")
    elif not opaque:
        lines.append("✓ Nenhum símbolo indefinido encontrado!")
        lines.append("")

    if multidefined:
        lines.append("--- MULTIDEFINIDOS ---")
        for sym, mods in sorted(multidefined.items()):
            lines.append(f"  {sym}  ({len(mods)} defs)")
            for m in mods[:4]:
                lines.append(f"    in: {m}")
        lines.append("")
    elif not opaque:
        lines.append("✓ Nenhum símbolo multidefinido encontrado!")
        lines.append("")

    report_text = "\n".join(lines)
    print(report_text)
    with open(REPORT, 'w', encoding='utf-8') as f:
        f.write(report_text)
    print(f"\nRelatório salvo em: {REPORT}")

if __name__ == "__main__":
    main()
