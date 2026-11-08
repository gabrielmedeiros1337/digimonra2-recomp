"""Exclusive GAME sampling totals and optional guest/native inclusive estimates.
Times are sample fractions scaled to a separate QPC GAME mean, never exact per-function timers.
"""
import argparse,bisect,collections,json,re,struct
from pathlib import Path

def main():
 p=argparse.ArgumentParser();p.add_argument('--exe',type=Path);p.add_argument('--profile',type=Path,required=True);p.add_argument('--timing',type=Path,required=True);p.add_argument('--map',type=Path);p.add_argument('--stacks',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
 d=json.loads(a.profile.read_text());t=json.loads(a.timing.read_text());game=t['summary']['cpu_game_logic_ms']['mean']
 starts=set(json.loads(Path('build_test/guest_function_starts.json').read_text()))
 dol=Path('extracted/sys/main.dol').read_bytes();sections=[]
 for i in range(7):
  off=struct.unpack_from('>I',dol,i*4)[0];addr=struct.unpack_from('>I',dol,0x48+i*4)[0];size=struct.unpack_from('>I',dol,0x90+i*4)[0]
  if off and size:
   sections.append((addr,addr+size,off))
   for j in range(0,size-3,4):
    op=struct.unpack_from('>I',dol,off+j)[0]
    if op&0xFFFF8000==0x94218000:starts.add(addr+j)
 starts=sorted(starts)
 def entry(pc):
  if not any(lo<=pc<hi for lo,hi,_ in sections):return None
  i=bisect.bisect_right(starts,pc)-1
  return f'{starts[i]:08X}' if i>=0 else None
 rows=[r for r in d['guest_samples'] if r['frame_stage']==1 and r['frame_active']]
 total=sum(r['count'] for r in rows)
 if not total:raise ValueError('No exclusive GAME samples')
 exclusive=collections.Counter();host=collections.Counter()
 for r in rows:
  e=entry(int(r['pc'],16));exclusive[e or 'unmapped_pc']+=r['count'];host[r['symbol']]+=r['count']
 inclusive=collections.Counter();chain_samples=0;truncated=0
 for r in d.get('guest_chains',[]):
  chain_samples+=r['count'];truncated+=r['count']*r['truncated']
  for e in set(filter(None,(entry(int(pc,16)) for pc in r['pcs']))):inclusive[e]+=r['count']
 def guest_table(order):
  return [dict(entry=e,exclusive_samples=exclusive[e],exclusive_ms=exclusive[e]/total*game,inclusive_samples=inclusive[e] if chain_samples else None,inclusive_ms=inclusive[e]/chain_samples*game if chain_samples else None) for e in order[:15]]
 result=dict(game_qpc_mean_ms=game,game_samples=total,guest_exclusive_top15=guest_table([k for k,v in exclusive.most_common()]),guest_inclusive_top15=guest_table([k for k,v in inclusive.most_common()]) if chain_samples else None,guest_chain_samples=chain_samples,truncated_chain_samples=truncated,host_exclusive_top15=[dict(symbol=s,samples=c,exclusive_ms=c/total*game) for s,c in host.most_common(15)],note='Per-function ms are sampling estimates. Guest PC attribution may retain the caller during native HLE. Candidate entries inferred from DOL BL/data targets and stwu prologues. Inclusive guest stacks may truncate, omit tail calls or be ambiguous during prologues. Inclusive values overlap; never sum them.')
 result['guest_exclusive_top15_coverage_ms']=sum(r['exclusive_ms'] for r in result['guest_exclusive_top15']);result['remaining_guest_exclusive_ms']=game-result['guest_exclusive_top15_coverage_ms']
 if a.stacks:
  if not a.map:raise ValueError('--stacks requires --map')
  text=a.map.read_text(errors='replace');preferred=int(re.search(r'Preferred load address is\s+([0-9A-Fa-f]+)',text)[1],16)
  symbols=sorted((int(m[2],16)-preferred,m[1]) for m in re.finditer(r'^\s+[0-9A-Fa-f]{4}:[0-9A-Fa-f]{8}\s+(\S+)\s+([0-9A-Fa-f]{16})\s+f\s',text,re.M));offsets=[s[0] for s in symbols];modules=[];native_ex=collections.Counter();native_inc=collections.Counter();n=0
  lines=a.stacks.read_text().splitlines()
  if not any(line.startswith('F exclusive_stage=GAME') for line in lines):raise ValueError('Native stacks must be filtered to exclusive GAME')
  for line in lines:
   if line.startswith('M '):
    _,base,size,path=line.split(' ',3);modules.append((int(base,16),int(base,16)+int(size,16),Path(path).name))
  def label(pc):
   for lo,hi,name in modules:
    if lo<=pc<hi:
     if name.lower()=='digimon_test.exe':
      i=bisect.bisect_right(offsets,pc-lo)-1
      if i>=0:return name+'!'+symbols[i][1]
     return name+'+0x'+format(pc-lo,'X')
   return 'unknown_native'
  for line in lines:
   if not line.startswith('S '):continue
   pcs=[int(x,16) for x in line.split()[1:]];labels=[label(x) for x in pcs];n+=1;native_ex[labels[0]]+=1
   for s in set(labels):native_inc[s]+=1
  result['native_stack_samples']=n
  result['native_inclusive_top15']=[dict(symbol=s,exclusive_ms=native_ex[s]/n*game,inclusive_ms=c/n*game) for s,c in native_inc.most_common(15)] if n else []

 result['guest_exclusive_all']=guest_table([k for k,v in exclusive.most_common()])
 # Keep every entry in the machine-readable accounting, not only the table.
 result['guest_exclusive_all']=[dict(entry=e,samples=c,exclusive_ms=c/total*game,exclusive_percent=c/total*100,inclusive_samples=inclusive[e] if chain_samples else None,inclusive_ms=inclusive[e]/chain_samples*game if chain_samples else None) for e,c in exclusive.most_common()]
 categories=collections.Counter()
 for r in rows:
  name=r['symbol'].split('!')[-1]
  if name.startswith(('func_','loop_')):category='chunks PPC (includes inlined math/memory)'
  elif name.startswith(('mem_read','mem_write','resolve_addr','clear_matching_reservation')):category='runtime memory (non-inlined)'
  elif name.startswith(('ppc_','dolrecomp_f32','dolrecomp_f64','hot_')):category='runtime PPC / float conversion (non-inlined)'
  elif name.startswith(('dolrecomp_','platform_execute','platform_continue')):category='dispatcher / replacement lookup'
  elif name.startswith(('gx_pipe_write_fifo','consume_linked')):category='FIFO producer'
  elif name.startswith(('ax_','audio_')):category='AX/audio native'
  elif name.startswith(('handle_external','locked_cache_')):category='MMIO / locked cache'
  elif not r['symbol'].startswith('digimon_test.exe!'):category='host DLL / system (caller unresolved)'
  else:category='other native host/HLE'
  categories[category]+=r['count']
 result['exclusive_categories']=[dict(category=k,samples=v,estimated_ms=v/total*game) for k,v in categories.most_common()]
 if a.exe:
  # PE32+ unwind records encode exact native prologue byte spans. This does
  # not identify epilogues or restore inlined guest function boundaries.
  blob=a.exe.read_bytes();pe=struct.unpack_from('<I',blob,0x3C)[0]
  if blob[pe:pe+4]!=b'PE\0\0':raise ValueError('Invalid PE')
  count=struct.unpack_from('<H',blob,pe+6)[0];opt_size=struct.unpack_from('<H',blob,pe+20)[0];opt=pe+24
  if struct.unpack_from('<H',blob,opt)[0]!=0x20B:raise ValueError('Expected PE32+')
  sections=[]
  for i in range(count):
   sec=opt+opt_size+i*40;virtual,base,size,off=struct.unpack_from('<4I',blob,sec+8);sections.append((base,base+max(virtual,size),off))
  def file_offset(rva):
   for lo,hi,off in sections:
    if lo<=rva<hi:return off+rva-lo
   raise ValueError('Unmapped PE RVA')
  pdata_rva,pdata_size=struct.unpack_from('<II',blob,opt+112+3*8);at=file_offset(pdata_rva);prologues=[]
  for i in range(pdata_size//12):
   begin,end,unwind=struct.unpack_from('<III',blob,at+i*12)
   if not begin or not unwind:continue
   offset=file_offset(unwind);version=blob[offset]&7
   if version==1:prologues.append((begin,begin+blob[offset+1]))
  prologues.sort();begins=[x[0] for x in prologues]
  rvas={r['address']:int(r['rva'],16) for r in d['raw'] if r['module'].lower()=='digimon_test.exe'}
  hits=0
  for r in rows:
   rva=rvas.get(r['rip'])
   if rva is None:continue
   i=bisect.bisect_right(begins,rva)-1
   if i>=0 and rva<prologues[i][1]:hits+=r['count']
  result['native_prologue_samples']=hits;result['native_prologue_estimated_ms']=hits/total*game
  result['native_prologue_note']='PE unwind SizeOfProlog ranges; excludes epilogues. Requires executable matching this profile; hash verified externally.'
 a.output.write_text(json.dumps(result,indent=2));print(json.dumps(result,indent=2))
if __name__=='__main__':main()
