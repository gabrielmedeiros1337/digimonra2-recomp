"""Bound MSVC optimization units, preserving original guest control flow.

Private void leaves accept an entry PC and an out flow tag. Original returns
(including adapter macros) leave flow0; an inter-region goto writes its private
entry address; return_dispatch sets flow1. CPUState.pc is never used as scratch.
No CPUState fields, guest timing, arithmetic or budget debits are added/removed.
"""
import re

FUNCTION=re.compile(r'^(?P<head>(?:static\s+)?void\s+(?P<name>\w+)\(CPUState\*\s+ctx\))\s*\{',re.M)
LABEL=re.compile(r'^(label_([0-9A-Fa-f]{8})|return_dispatch_[0-9A-Fa-f]{8}):',re.M)
SWITCH=re.compile(r'\s*switch\s*\(ctx->pc\)\s*\{(?P<cases>(?:\s*case\s+0x[0-9A-Fa-f]+u:\s*goto\s+label_[0-9A-Fa-f]+;)*)(?:\s*default:\s*return;)\s*\}\s*',re.S)
CASE=re.compile(r'case\s+(0x[0-9A-Fa-f]+)u:\s*goto\s+label_([0-9A-Fa-f]+);')

def braces(text,start):
    depth=1;at=start
    while at<len(text) and depth:
        if text[at]=='{':depth+=1
        elif text[at]=='}':depth-=1
        at+=1
    if depth:raise ValueError('Unbalanced chunk function')
    return at

def cases(text):
    result=[]
    for pc,label in CASE.findall(text):
        if int(pc,16)!=int(label,16):raise ValueError('Nonidentity entry mapping')
        result.append(int(pc,16))
    return result

def validation(pcs,expression):
    return 'switch('+expression+') {\n'+''.join(f'case 0x{x:08X}u:\n' for x in pcs)+'break;\ndefault:return;\n}\n'

def transform(text,shift=7):
    edits=[];stats={'functions':0,'leaves':0,'preserved_small':0}
    for fn in FUNCTION.finditer(text):
        end=braces(text,fn.end());body=text[fn.end():end-1];labels=list(LABEL.finditer(body))
        if not labels:continue
        ordinary=[m for m in labels if m[2]]
        if not ordinary:continue
        addresses=[int(m[2],16) for m in ordinary]
        if addresses!=sorted(set(addresses)):raise ValueError('Nonmonotonic/duplicate labels in '+fn['name'])
        if addresses[0]>>shift==addresses[-1]>>shift:
            stats['preserved_small']+=1;continue
        prefix=body[:ordinary[0].start()]
        entry=SWITCH.fullmatch(prefix)
        if prefix.strip() and not entry:raise ValueError('Unsupported entry prologue '+fn['name'])
        entry_pcs=cases(entry['cases']) if entry else None
        footer_labels=[m for m in labels if not m[2]]
        return_pcs=None;body_end=len(body)
        if footer_labels:
            if len(footer_labels)!=1:raise ValueError('Multiple return dispatchers')
            footer=footer_labels[0];body_end=footer.start()
            tail=body[footer.end():]
            guard=re.match(r'\s*if \(ctx->downcount <= -\(s64\)DOLRECOMP_C_LOOP_CYCLE_BUDGET\) return;',tail)
            if not guard:raise ValueError('Unsupported return budget guard '+fn['name'])
            switch=SWITCH.fullmatch(tail[guard.end():])
            if not switch:raise ValueError('Unsupported return dispatcher '+fn['name'])
            return_pcs=cases(switch['cases'])
        ordinary=[m for m in ordinary if m.start()<body_end]
        groups=[]
        for m in ordinary:
            key=int(m[2],16)>>shift
            if not groups or groups[-1][0]!=key:groups.append((key,[]))
            groups[-1][1].append(m)
        # Generated declarations live in instruction-local braces. Cross-region
        # values are carried in CPUState, never in a leaf's C automatic locals.
        code=body[ordinary[0].start():body_end];depth=0
        for line in code.splitlines():
            clean=re.sub(r'//.*','',line)
            if depth==0 and re.match(r'\s*(?:const\s+)?(?:u\d+|s\d+|f\d+|bool)\s+\w+',clean):
                raise ValueError('Live top-level automatic requires audit in '+fn['name'])
            depth+=clean.count('{')-clean.count('}')
        if depth:raise ValueError('Unbalanced region source')
        out=[];mapping={};name=fn['name']
        for index,(key,members) in enumerate(groups):
            start=members[0].start();finish=groups[index+1][1][0].start() if index+1<len(groups) else body_end
            region=body[start:finish];local={m[1] for m in members}
            def outgoing(match):
                label=match[1]
                if label in local:return match[0]
                if label.startswith('return_dispatch_'):
                    if return_pcs is None:raise ValueError('Missing return dispatch')
                    return 'do {*flow=1;return;} while(0);'
                return 'do {*flow=0x'+label[6:]+'u;return;} while(0);'
            region=re.sub(r'goto\s+(label_[0-9A-Fa-f]{8}|return_dispatch_[0-9A-Fa-f]{8});',outgoing,region)
            if index+1<len(groups):
                region+='\n*flow=0x'+groups[index+1][1][0][2]+'u;\n'
            leaf=f'{name}_region_{key:08X}';mapping[key]=leaf
            # noinline is intentional: inlining these leaves recreates the
            # optimizer bailout and giant stack frame this pass removes.
            out.append('#ifdef _MSC_VER\n__declspec(noinline)\n#else\n__attribute__((noinline))\n#endif\n'
                f'static void {leaf}(CPUState* ctx_abi,u32 entry,unsigned* flow) {{\n'
                'CPUState* CHUNK_RESTRICT ctx=ctx_abi;\n'
                'u8* const ram_base=ctx->ram;const u32 ram_size=ctx->ram_size;\n'
                'switch(entry){\n'+''.join(f'case 0x{int(m[2],16):08X}u:goto {m[1]};\n' for m in members)+
                'default:return;\n}\n'+region+'\n}\n')
        low=min(mapping);high=max(mapping);table=','.join(mapping.get(k,'0') for k in range(low,high+1))
        wrapper=fn['head']+' {\n'
        wrapper+='u32 entry=ctx->pc;\n'+validation(entry_pcs,'entry') if entry_pcs is not None else f'u32 entry=0x{addresses[0]:08X}u;\n'
        wrapper+='static void (*const regions[])(CPUState*,u32,unsigned*)={'+table+'};\n'
        wrapper+=f'for(;;){{u32 index=(entry>>{shift})-0x{low:X}u;unsigned flow=0;\n'
        wrapper+='if(index>=sizeof(regions)/sizeof(regions[0]) || !regions[index])return;\n'
        wrapper+='regions[index](ctx,entry,&flow);\nif(!flow)return;\n'
        if return_pcs is not None:
            wrapper+='if(flow==1){\nif(ctx->downcount<=-(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET)return;\n'+validation(return_pcs,'ctx->pc')+'entry=ctx->pc;\n}else entry=flow;\n'
        else:wrapper+='entry=flow;\n'
        wrapper+='}\n}\n'
        out.append(wrapper);edits.append((fn.start(),end,'\n'.join(out)))
        stats['functions']+=1;stats['leaves']+=len(groups)
    parts=[];last=0
    for a,b,replacement in edits:parts.extend((text[last:a],replacement));last=b
    parts.append(text[last:]);return ''.join(parts),stats

def self_test():
    source='void f(CPUState* ctx){switch(ctx->pc){case 0x80001000u:goto label_80001000;default:return;}\nlabel_80001000:\n{u32 a=3;ctx->gpr[0]=a;}\ngoto label_80001080;\nlabel_80001080:\nctx->pc=0x80001000u;goto return_dispatch_80001000;\nreturn_dispatch_80001000:\nif (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;switch(ctx->pc){case 0x80001000u:goto label_80001000;default:return;}}'
    out,stats=transform(source);assert stats['leaves']==2 and '*flow=1' in out and '*flow=0x80001080u' in out
    assert 'u32 entry=ctx->pc;' in out and 'ctx->downcount<=' in out
    try:transform(source.replace('{u32 a=3;ctx->gpr[0]=a;}','u32 a=3;'))
    except ValueError:pass
    else:raise AssertionError('Escaping C local accepted')

def write_contracts(path):
    control='''void control_original(CPUState* ctx){
switch(ctx->pc){
case 0x80001000u:goto label_80001000;
case 0x80001080u:goto label_80001080;
case 0x80001100u:goto label_80001100;
case 0x80001180u:goto label_80001180;
case 0x80001200u:goto label_80001200;
case 0x80001280u:goto label_80001280;
default:return;}
label_80001000:
ctx->downcount-=9;
{u32 v=ctx->gpr[3]+ctx->gpr[4];ctx->gpr[3]=v;}
label_80001080:
mem_write32(ctx,0xCC005010u,ctx->pc);
if(ctx->gpr[7]&1u)goto label_80001280;
ctx->pc=0x80001100u;goto return_dispatch_80001000;
label_80001100:
ctx->downcount-=5;
if(!ppc_fp_available_inline(ctx,0x80001100u))return;
ppc_fadds(ctx,0,1,2);
mem_write32(ctx,0x80000000u+(ctx->gpr[9]&31u)*4u,ctx->gpr[3]);
ctx->pc=0x80001180u;goto return_dispatch_80001000;
label_80001180:
ctx->gpr[3]^=mem_read32(ctx,0x80000000u+(ctx->gpr[9]&31u)*4u);
ctx->timebase+=3;
ctx->pc=0x80001200u;goto return_dispatch_80001000;
label_80001200:
ctx->downcount-=7;
if(ctx->ctr){ctx->ctr--;if(ctx->downcount<=-(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET){ctx->pc=0x80001200u;return;}goto label_80001000;}
ctx->pc=ctx->lr;return;
label_80001280:
if(ctx->gpr[8]&1u){ctx->pc=ctx->gpr[10];return;}
goto label_80001200;
return_dispatch_80001000:
if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
switch(ctx->pc){
case 0x80001100u:goto label_80001100;
case 0x80001180u:goto label_80001180;
case 0x80001200u:goto label_80001200;
default:return;}}
static void helper_original(CPUState* ctx){
label_80002000:
ctx->downcount-=3;
ctx->gpr[15]+=ctx->pc;
label_80002080:
mem_write32(ctx,0xCC005010u,ctx->pc);
{u32 value=ctx->gpr[15];ctx->gpr[16]=value^0xAA55AA55u;}
label_80002100:
if(ctx->ctr){ctx->ctr--;if(ctx->downcount<=-(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET)return;goto label_80002000;}
ctx->pc=ctx->lr;
}
void helper_call_original(CPUState* ctx){helper_original(ctx);}
'''
    generated=[]
    for shift in (6,7,8):
        variant=control.replace('_original',f'_region{shift}')
        code,_=transform(variant,shift);generated.append(code)
    code='#include "cpu/cpu.h"\n#include "chunk_memory.h"\n#define DOLRECOMP_C_LOOP_CYCLE_BUDGET 256\n'+control+'\n'+'\n'.join(generated)
    code+='\ntypedef void (*SegmentCase)(CPUState*);\n'
    code+='SegmentCase segment_cases[2][4]={{control_original,control_region6,control_region7,control_region8},{helper_call_original,helper_call_region6,helper_call_region7,helper_call_region8}};\n'
    # Original guest code needs no RAM aliases; transformed leaves provide them.
    if not path.exists() or path.read_text()!=code:path.write_text(code)
