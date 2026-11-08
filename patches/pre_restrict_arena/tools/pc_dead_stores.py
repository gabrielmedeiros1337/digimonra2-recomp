"""Conservative PC DSE on BUILD COPIES; never edits generated inputs.

A store is dead only if the next unconditional store in the same lexical
scope dominates every normal continuation, with no PC observer in between.
Memory, MMIO, unknown calls and outgoing control transfers are barriers.
The one permitted early return is FP-unavailable: its helper overwrites PC
and uses an explicit CIA, so the old PC is not observable on either path.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re

STORE = re.compile(r"^    ctx->pc = (0x[0-9a-fA-F]+u?);\s*$", re.M)
GUARD = re.compile(r"if\s*\(!ppc_fp_available_inline\(ctx,\s*0x[0-9a-fA-F]+u?\)\)\s*return;")
# Audited register/FPSCR-only helpers: no PC reads, callbacks or guest memory.
PURE = set('ppc_fadds ppc_fsubs ppc_fmuls ppc_fdivs ppc_fadd ppc_fsub ppc_fmul ppc_fdiv ppc_frsp ppc_record_cr1 dolrecomp_f32_from_bits dolrecomp_f32_to_bits dolrecomp_f64_from_bits dolrecomp_f64_to_bits dolrecomp_ps_from_bits dolrecomp_ps_to_bits'.split())
ADAPTED_CIA = set('8024BC48 8024C014 8024C244 8024C500 8024C508 8024C518 802B4D08 8029D88C 8028BEDC 8028BF58'.split())
ADAPTERS=sorted((Path(__file__).resolve().parent.parent/'src_test').glob('*adapter.h'))
for adapter in ADAPTERS:
    ADAPTED_CIA.update(x.upper() for x in re.findall(r'0x(80[0-9A-Fa-f]{6})',adapter.read_text()))
CASTS = set('if sizeof u8 s8 u16 s16 u32 s32 u64 s64 f32 f64 int unsigned float double bool'.split())

def pure_segment(body):
    body = re.sub(r'//[^\n]*|/\*.*?\*/', '', body, flags=re.S)
    if any(cia in body for cia in ADAPTED_CIA): return False
    body = GUARD.sub('', body)
    # Incoming edges at a label do not observe an earlier store. Keep every
    # outgoing edge/return; never move operations or remove labels themselves.
    body = re.sub(r'^label_[0-9A-Fa-f]+:\s*', '', body, flags=re.M)
    if re.search(r'ctx->pc|\b(return|goto|break|continue|switch|case|default|for|while|do|asm|volatile)\b', body):
        return False
    # No escape into a different function/block, even if braces balance later.
    depth = 0
    for ch in body:
        if ch == '{': depth += 1
        if ch == '}':
            depth -= 1
            if depth < 0: return False
    if depth: return False
    if re.search(r'\b[A-Za-z_]\w*\s*:', body): return False
    calls = set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', body))
    if calls - PURE - CASTS: return False
    # Disallow aliasing through arbitrary context pointers or host dereferences.
    fields = set(re.findall(r'ctx->(\w+)', body))
    if fields - set('gpr fpr ps1 cr xer ctr lr fpscr downcount'.split()): return False
    if '->' in body.replace('ctx->',''): return False
    for match in re.finditer(r'\bctx\b(?!->)',body):
        caller=re.search(r'(\w+)\s*\(\s*$',body[:match.start()])
        if not caller or caller[1] not in PURE:return False
    # Context register arrays have constant indices. Reject arbitrary aliases,
    # local/global pointer indexing or unrecognized host memory operations.
    registers=re.sub(r'ctx->(?:gpr|fpr|ps1)\[\d+\]','reg',body)
    if '[' in registers or ']' in registers:return False
    if re.search(r'(?:^|[=(,;])\s*\*\s*\w',body,re.M):return False
    if re.search(r'\*\s*\(|\b(?:mem_|ppc_psq_|dolrecomp_run)', body): return False
    return True

def transform(text):
    stores = list(STORE.finditer(text)); edits=[]; examples=[]
    for a,b in zip(stores, stores[1:]):
        body=text[a.end():b.start()]
        if pure_segment(body):
            edits.append((a.start(), a.end()))
            examples.append((text[a.start():b.end()], body+'\n'+b.group(0)))
    fragments=[];previous=0
    for a,b in edits: fragments.append(text[previous:a]);previous=b
    fragments.append(text[previous:]);out=''.join(fragments)
    return out, len(stores), examples

def self_test():
    head='    ctx->pc = 0x80001000u;\n'; tail='    ctx->pc = 0x80001004u;\n'
    for body in ['ctx->gpr[3] += 1;','label_80001000:\nctx->gpr[3] += 1;','if(ctx->gpr[4]) {ctx->cr=0;}','if (!ppc_fp_available_inline(ctx, 0x80001000u)) return;\nppc_fadds(ctx,1,2,3);']:
        assert len(transform(head+body+'\n'+tail)[2]) == 1
    for body in ['mem_write32(ctx,ea,1);','ctx->gpr[2]=mem_read32(ctx,ea);','return;','goto label_80001000;','ctx->gpr[3]=ctx->pc;','ppc_host_call(ctx,0);','}\nvoid next(CPUState* ctx){','if(ctx->cr){ctx->pc=0;return;}','if (!ppc_fp_available_inline(ctx, 0x8024BC48u)) return;','CPUState* alias=ctx; alias->gpr[3]=alias->pc;','ctx->gpr[3]=*pointer;','ctx->gpr[3]=alias[0];']:
        assert not transform(head+body+'\n'+tail)[2], body

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--source',type=Path);p.add_argument('--output',type=Path);p.add_argument('--self-test',action='store_true');a=p.parse_args()
    self_test()
    if a.self_test: print('PC DSE safety contracts passed');return
    if not a.source or not a.output: p.error('source/output required')
    if a.output.resolve().is_relative_to(a.source.resolve()): p.error('output must be outside generated inputs')
    script_hash=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    adapter_hash=hashlib.sha256(b''.join(p.read_bytes() for p in ADAPTERS)).hexdigest()
    sources=sorted(a.source.glob('*.c'));audit=a.output/'pc_dse_audit.json'
    if audit.exists():
        old=json.loads(audit.read_text());inputs=old.get('inputs',[])
        if old.get('script_sha256')==script_hash and old.get('guard_adapter_sha256')==adapter_hash and len(sources)==len(inputs) and (a.output/'pc_dse_reference.c').exists() and all(
            source.name==record['file'] and hashlib.sha256(source.read_bytes()).hexdigest()==record['input_sha256'] and (a.output/source.name).exists()
            and hashlib.sha256((a.output/source.name).read_bytes()).hexdigest()==record.get('output_sha256')
            for source,record in zip(sources,inputs)):
            print(json.dumps({k:v for k,v in old.items() if k!='inputs'}));return
    a.output.mkdir(parents=True,exist_ok=True);report=[];cases=[]
    for source in sources:
        raw=source.read_bytes();text=raw.decode().replace('\r\n','\n').replace('\r','\n');out,count,examples=transform(text)
        # Generated source uses a relative include; the build copy uses its absolute original.
        out=out.replace('#include "../generated.h"', '#include "'+(a.source.parent/'generated.h').resolve().as_posix()+'"')
        target=a.output/source.name
        encoded=out.encode()
        if not target.exists() or target.read_bytes()!=encoded: target.write_bytes(encoded)
        report.append(dict(file=source.name,input_sha256=hashlib.sha256(raw).hexdigest(),output_sha256=hashlib.sha256(encoded).hexdigest(),stores=count,removed=len(examples)))
        # Deterministic spread through every translation unit; no cherry-picked opcode.
        for i in range(min(3,len(examples))): cases.append(examples[(i*len(examples))//3])
    test=['#include "full_bits_reference.h"','typedef void (*PCSnippet)(CPUState*);']
    for i,(before,after) in enumerate(cases):
        test += [f'static void original_{i}(CPUState* ctx){{\n{before}\n}}',f'static void compact_{i}(CPUState* ctx){{\n{after}\n}}']
    test += ['PCSnippet pc_original[]={'+','.join(f'original_{i}' for i in range(len(cases)))+'};','PCSnippet pc_compact[]={'+','.join(f'compact_{i}' for i in range(len(cases)))+'};',f'unsigned pc_case_count={len(cases)};']
    (a.output/'pc_dse_reference.c').write_text('\n'.join(test))
    total=dict(files=len(report),stores=sum(r['stores'] for r in report),removed=sum(r['removed'] for r in report),reference_cases=len(cases),script_sha256=script_hash,guard_adapter_sha256=adapter_hash,inputs=report)
    (a.output/'pc_dse_audit.json').write_text(json.dumps(total,indent=2));print(json.dumps({k:v for k,v in total.items() if k!='inputs'}))

if __name__=='__main__':main()
