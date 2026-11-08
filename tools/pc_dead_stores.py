"""Conservative PC DSE on BUILD COPIES; never edits generated inputs.

A store is dead only if the next unconditional store in the same lexical
scope dominates every normal continuation, with no PC observer in between.
Unknown memory calls and outgoing control transfers are barriers. Rewritten
RAM helpers defer CIA materialization to their cold MMIO/runtime arm.
The one permitted early return is FP-unavailable: its helper overwrites PC
and uses an explicit CIA, so the old PC is not observable on either path.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
from bisect import bisect_right
import chunk_segments

STORE = re.compile(r"^    ctx->pc = (0x[0-9a-fA-F]+u?);\s*$", re.M)
GUARD = re.compile(r"if\s*\(!ppc_fp_available_inline\(ctx,\s*0x[0-9a-fA-F]+u?\)\)\s*return;")
# Audited register/FPSCR-only helpers: no PC reads, callbacks or guest memory.
PURE = set('ppc_fadds ppc_fsubs ppc_fmuls ppc_fdivs ppc_fadd ppc_fsub ppc_fmul ppc_fdiv ppc_frsp ppc_record_cr1 dolrecomp_f32_from_bits dolrecomp_f32_to_bits dolrecomp_f64_from_bits dolrecomp_f64_to_bits dolrecomp_ps_from_bits dolrecomp_ps_to_bits'.split())
PURE.update(f'chunk_{op}{bits}' for op in ('read','write') for bits in (8,16,32,64))
ADAPTED_CIA = set('8024BC48 8024C014 8024C244 8024C500 8024C508 8024C518 802B4D08 8029D88C 8028BEDC 8028BF58'.split())
ADAPTERS=sorted((Path(__file__).resolve().parent.parent/'src_test').glob('*adapter.h'))
for adapter in ADAPTERS:
    ADAPTED_CIA.update(x.upper() for x in re.findall(r'0x(80[0-9A-Fa-f]{6})',adapter.read_text()))
HOOKED = {int(x,16) for x in ADAPTED_CIA}
HOOKED.update(int(x,16) for x in re.findall(r'case\s+(0x[0-9A-Fa-f]+)u?\s*:',
    (Path(__file__).resolve().parent.parent/'src_test/test_main.c').read_text(encoding='utf-8')))
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
        if a[1].removeprefix('0x').rstrip('u').upper() not in ADAPTED_CIA and pure_segment(body):
            edits.append((a.start(), a.end()))
            examples.append((text[a.start():b.end()], body+'\n'+b.group(0)))
    fragments=[];previous=0
    for a,b in edits: fragments.append(text[previous:a]);previous=b
    fragments.append(text[previous:]);out=''.join(fragments)
    return out, len(stores), examples

MEMORY = re.compile(r'\bmem_(read|write)(8|16|32|64)\s*\(\s*ctx\s*,')
INSTRUCTION = re.compile(r'// ([0-9A-Fa-f]{8}):')
def rewrite_memory(text):
    """CIA comes from the instruction, never an inferred previous PC value."""
    instructions=list(INSTRUCTION.finditer(text));index=0;edits=[]
    for call in MEMORY.finditer(text):
        while index+1<len(instructions) and instructions[index+1].start()<call.start():index+=1
        if not instructions or instructions[index].start()>call.start():continue
        cia=instructions[index][1].upper()
        if cia in ADAPTED_CIA:continue # Original macro may invoke an HLE tail.
        at=call.end();depth=1
        while at<len(text) and depth:
            if text[at]=='(':depth+=1
            if text[at]==')':depth-=1
            at+=1
        if depth:raise ValueError('Unbalanced memory call')
        args=text[call.end():at-1]
        if re.search(r'\bmem_(?:read|write)\d+\s*\(',args):raise ValueError('Nested memory call requires explicit sequencing')
        replacement=f'chunk_{call[1]}{call[2]}(ctx, ram_base, ram_size, {args}, 0x{cia}u)'
        edits.append((call.start(),at,replacement))
    result=[];previous=0
    for a,b,value in edits:result.extend((text[previous:a],value));previous=b
    result.append(text[previous:]);return ''.join(result),len(edits)

FUNCTION = re.compile(r'^(?P<head>(?:static\s+)?void\s+\w+\(CPUState\*)\s+ctx\)\s*\{',re.M)
def qualify_functions(text):
    edits=[];count=0
    for function in FUNCTION.finditer(text):
        depth=1;end=function.end()
        while end<len(text) and depth:
            if text[end]=='{':depth+=1
            if text[end]=='}':depth-=1
            end+=1
        if depth:raise ValueError('Unbalanced chunk function')
        body=text[function.end():end-1];locals=''
        if re.search(r'\bchunk_(?:read|write)\d+\(',body):
            # The RAM no-alias contract is scoped inside each leaf helper,
            # not across HLE callbacks which may access RAM through ctx->ram.
            locals='\n    u8* const ram_base=ctx->ram;const u32 ram_size=ctx->ram_size;'
        # MSVC treats __restrict in a function-pointer parameter as a distinct
        # extension type. Keep the public dispatcher ABI and restrict the sole
        # local context alias instead; ctx_abi is not used after this binding.
        edits.append((function.start(),function.end(),function['head']+' ctx_abi) {\n    CPUState* CHUNK_RESTRICT ctx=ctx_abi;'+locals));count+=1
    parts=[];previous=0
    for a,b,value in edits:parts.extend((text[previous:a],value));previous=b
    parts.append(text[previous:]);return ''.join(parts),count

def consolidate_cycles(text):
    pattern=re.compile(r'(ctx->downcount -= (\d+);)([ \t\r\n]+)ctx->downcount -= (\d+);')
    count=0
    while True:
        text,n=pattern.subn(lambda m:'ctx->downcount -= '+str(int(m[2])+int(m[4]))+';',text);count+=n
        if not n:return text,count

def audit_cycle_guards(text):
    """Read-only audit: never relax a safepoint or move cost across a label.

    Generated debits may be entered through the PC dispatcher or an internal
    label. Even forward-only blocks are not guaranteed single-entry regions.
    Keep their costs; only consolidate adjacent unconditional debits above.
    """
    pattern=re.compile(r'if \(ctx->downcount <= -\(s64\)DOLRECOMP_C_LOOP_CYCLE_BUDGET\) \{\s*ctx->pc = 0x([0-9A-Fa-f]+)u;\s*return;\s*\}\s*goto label_([0-9A-Fa-f]+);')
    instructions=list(INSTRUCTION.finditer(text));index=0;backward=forward=0
    for guard in pattern.finditer(text):
        while index+1<len(instructions) and instructions[index+1].start()<guard.start():index+=1
        if instructions and instructions[index].start()<guard.start():
            if int(guard[2],16)<=int(instructions[index][1],16):backward+=1
            else:forward+=1
    return dict(backedge_guards=backward,forward_edge_guards=forward,
        entry_guards=text.count('if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;'))

def direct_edges(text,owner,starts,end,hooks):
    """Constant cross-chunk b/bl only; hooks and dynamic edges keep dispatch.

    The runtime gate accounts TB/safepoints and bounds C call depth. This does
    not assume that the compiler can turn a huge chunk frame into a tail jump.
    """
    instructions=list(re.finditer(r'// ([0-9A-Fa-f]{8}):\s*(b|bl|ba|bla)\s+(0x[0-9A-Fa-f]+)\b',text))
    index=0;edits=[]
    for edge in re.finditer(r'ctx->pc = (0x[0-9A-Fa-f]+)u;\s*(return;)',text):
        while index+1<len(instructions) and instructions[index+1].start()<edge.start():index+=1
        if not instructions or instructions[index].start()>edge.start():continue
        ins=instructions[index];target=int(edge[1],16)
        if edge.start()-ins.end()>240 or target!=int(ins[3],16) or target in hooks or target&3:continue
        # Reject intervening instruction comments, guards or control flow.
        between=text[ins.end():edge.start()]
        if re.search(r'// [0-9A-Fa-f]{8}:|\b(if|goto|return|switch)\b',between):continue
        slot=bisect_right(starts,target)-1
        if slot<0 or target>=end or starts[slot]==owner:continue
        edits.append((edge.start(2),edge.end(2),f'CHUNK_DIRECT(ctx,func_{starts[slot]:08X});'))
    parts=[];previous=0
    for a,b,value in edits:parts.extend((text[previous:a],value));previous=b
    parts.append(text[previous:]);return ''.join(parts),len(edits)

def self_test():
    chunk_segments.self_test()
    head='    ctx->pc = 0x80001000u;\n'; tail='    ctx->pc = 0x80001004u;\n'
    for body in ['ctx->gpr[3] += 1;','label_80001000:\nctx->gpr[3] += 1;','if(ctx->gpr[4]) {ctx->cr=0;}','if (!ppc_fp_available_inline(ctx, 0x80001000u)) return;\nppc_fadds(ctx,1,2,3);']:
        assert len(transform(head+body+'\n'+tail)[2]) == 1
    for body in ['mem_write32(ctx,ea,1);','ctx->gpr[2]=mem_read32(ctx,ea);','return;','goto label_80001000;','ctx->gpr[3]=ctx->pc;','ppc_host_call(ctx,0);','}\nvoid next(CPUState* ctx){','if(ctx->cr){ctx->pc=0;return;}','if (!ppc_fp_available_inline(ctx, 0x8024BC48u)) return;','CPUState* alias=ctx; alias->gpr[3]=alias->pc;','ctx->gpr[3]=*pointer;','ctx->gpr[3]=alias[0];']:
        assert not transform(head+body+'\n'+tail)[2], body
    sample=head+'// 80001000: lwz r3,0(r4)\nctx->gpr[3]=mem_read32(ctx, ctx->gpr[4]);\n'+tail
    rewritten,n=rewrite_memory(sample);assert n==1 and len(transform(rewritten)[2])==1
    assert not transform(rewritten+'\n')[0].startswith(head)
    assert rewrite_memory('// 8023DA80: stw r11,0(r9)\nmem_write32(ctx,ctx->gpr[9],ctx->gpr[11]);')[1]==0
    assert consolidate_cycles('ctx->downcount -= 3;\nctx->downcount -= 5;')==('ctx->downcount -= 8;',1)
    assert consolidate_cycles('ctx->downcount -= 3;\nlabel_80001000:\nctx->downcount -= 5;')[1]==0
    branch='// 80001004: bl 0x80002020\n{ctx->lr=0x80001008u;ctx->pc = 0x80002020u; return;}'
    assert direct_edges(branch,0x80001000,[0x80001000,0x80002000],0x80003000,set())[1]==1
    assert direct_edges(branch,0x80001000,[0x80001000,0x80002000],0x80003000,{0x80002020})[1]==0
    assert direct_edges(branch,0x80002000,[0x80001000,0x80002000],0x80003000,set())[1]==0
    assert direct_edges(branch.replace('bl 0x','bctr 0x'),0x80001000,[0x80001000,0x80002000],0x80003000,set())[1]==0

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--source',type=Path);p.add_argument('--output',type=Path);p.add_argument('--self-test',action='store_true');a=p.parse_args()
    self_test()
    if a.self_test: print('PC DSE safety contracts passed');return
    if not a.source or not a.output: p.error('source/output required')
    if a.output.resolve().is_relative_to(a.source.resolve()): p.error('output must be outside generated inputs')
    script_hash=hashlib.sha256(Path(__file__).read_bytes()+Path(chunk_segments.__file__).read_bytes()).hexdigest()
    adapter_hash=hashlib.sha256(b''.join(p.read_bytes() for p in ADAPTERS)).hexdigest()
    hook_hash=hashlib.sha256(str(sorted(HOOKED)).encode()).hexdigest()
    sources=sorted(a.source.glob('*.c'));audit=a.output/'pc_dse_audit.json'
    starts=sorted(int(re.search(r'_([0-9A-Fa-f]{8})$',p.stem)[1],16) for p in sources)
    header=(a.source.parent/'generated.h').read_text()
    span=re.search(r'u32 offset = address - (0x[0-9A-Fa-f]+)u;\s*if \(offset < (0x[0-9A-Fa-f]+)u',header)
    if not span:raise ValueError('Cannot validate direct-edge code bounds against generated dispatch table')
    code_end=int(span[1],16)+int(span[2],16)
    if audit.exists():
        old=json.loads(audit.read_text());inputs=old.get('inputs',[])
        if old.get('script_sha256')==script_hash and old.get('guard_adapter_sha256')==adapter_hash and old.get('direct_hook_sha256')==hook_hash and len(sources)==len(inputs) and (a.output/'pc_dse_reference.c').exists() and (a.output/'segment_reference.c').exists() and all(
            source.name==record['file'] and hashlib.sha256(source.read_bytes()).hexdigest()==record['input_sha256'] and (a.output/source.name).exists()
            and hashlib.sha256((a.output/source.name).read_bytes()).hexdigest()==record.get('output_sha256')
            for source,record in zip(sources,inputs)):
            print(json.dumps({k:v for k,v in old.items() if k!='inputs'}));return
    a.output.mkdir(parents=True,exist_ok=True);report=[];cases=[]
    for source in sources:
        raw=source.read_bytes();text=raw.decode().replace('\r\n','\n').replace('\r','\n')
        text,memory_calls=rewrite_memory(text);out,count,examples=transform(text);out,regions=chunk_segments.transform(out);out,functions=qualify_functions(out);out,cycles=consolidate_cycles(out)
        owner=int(re.search(r'_([0-9A-Fa-f]{8})$',source.stem)[1],16)
        direct=0 # Cross-chunk transfers always return to the flat executor.
        # Generated source uses a relative include; the build copy uses include-dir resolution.
        out=out.replace('#include "../generated.h"', '#include "generated.h"')
        out='#include "chunk_memory.h"\n'+out
        target=a.output/source.name
        encoded=out.encode()
        if not target.exists() or target.read_bytes()!=encoded: target.write_bytes(encoded)
        report.append(dict(file=source.name,input_sha256=hashlib.sha256(raw).hexdigest(),output_sha256=hashlib.sha256(encoded).hexdigest(),stores=count,removed=len(examples),memory_calls=memory_calls,restrict_functions=functions,cycles_merged=cycles,direct_edges=direct,regions=regions,cycle_guards=audit_cycle_guards(text)))
        # Deterministic spread through every translation unit; no cherry-picked opcode.
        for i in range(min(3,len(examples))): cases.append(examples[(i*len(examples))//3])
    test=['#include "full_bits_reference.h"','#include "chunk_memory.h"','typedef void (*PCSnippet)(CPUState*);']
    for i,(before,after) in enumerate(cases):
        prolog='u8* const ram_base=ctx->ram;const u32 ram_size=ctx->ram_size;'
        test += [f'static void original_{i}(CPUState* ctx){{\n{prolog}\n{before}\n}}',f'static void compact_{i}(CPUState* ctx_abi){{\nCPUState* CHUNK_RESTRICT ctx=ctx_abi;\n{prolog}\n{after}\n}}']
    test += ['PCSnippet pc_original[]={'+','.join(f'original_{i}' for i in range(len(cases)))+'};','PCSnippet pc_compact[]={'+','.join(f'compact_{i}' for i in range(len(cases)))+'};',f'unsigned pc_case_count={len(cases)};']
    (a.output/'pc_dse_reference.c').write_text('\n'.join(test))
    chunk_segments.write_contracts(a.output/'segment_reference.c')
    total=dict(files=len(report),stores=sum(r['stores'] for r in report),removed=sum(r['removed'] for r in report),memory_calls=sum(r['memory_calls'] for r in report),restrict_functions=sum(r['restrict_functions'] for r in report),cycles_merged=sum(r['cycles_merged'] for r in report),direct_edges=sum(r['direct_edges'] for r in report),reference_cases=len(cases),script_sha256=script_hash,guard_adapter_sha256=adapter_hash,direct_hook_sha256=hook_hash,inputs=report)
    (a.output/'pc_dse_audit.json').write_text(json.dumps(total,indent=2));print(json.dumps({k:v for k,v in total.items() if k!='inputs'}))

if __name__=='__main__':main()
