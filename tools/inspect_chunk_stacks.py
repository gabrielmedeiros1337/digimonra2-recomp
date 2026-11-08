"""Read x64 PE unwind records and prologue calls for production PPC chunks."""
from pathlib import Path
import argparse,bisect,hashlib,json,re,struct

def inspect(executable,mapfile):
    data=executable.read_bytes();pe=struct.unpack_from('<I',data,60)[0];opt=pe+24
    image=struct.unpack_from('<Q',data,opt+24)[0]
    sh=opt+struct.unpack_from('<H',data,pe+20)[0];sections=[]
    for i in range(struct.unpack_from('<H',data,pe+6)[0]):
        at=sh+i*40;virtual,rva,size,raw=struct.unpack_from('<IIII',data,at+8)
        sections.append((rva,max(size,virtual),raw))
    def offset(rva):
        for start,size,raw in sections:
            if start<=rva<start+size:return raw+rva-start
        raise ValueError('Unmapped RVA '+hex(rva))
    table,size=struct.unpack_from('<II',data,opt+112+3*8);at=offset(table)
    functions=[struct.unpack_from('<III',data,at+n) for n in range(0,size,12)]
    by_start={f[0]:f for f in functions}
    def allocation(unwind,seen=None):
        seen=set() if seen is None else seen
        if unwind in seen:raise ValueError('Cyclic unwind chain')
        seen.add(unwind);p=offset(unwind);flags=data[p]>>3;count=data[p+2];slot=0;total=0
        while slot<count:
            op=data[p+5+slot*2]&15;info=data[p+5+slot*2]>>4;slot+=1
            if op==0:total+=8
            elif op==1:
                if info==0:total+=struct.unpack_from('<H',data,p+4+slot*2)[0]*8;slot+=1
                elif info==1:total+=struct.unpack_from('<I',data,p+4+slot*2)[0];slot+=2
                else:raise ValueError('Bad ALLOC_LARGE')
            elif op==2:total+=8+info*8
            elif op in (4,8):slot+=1
            elif op in (5,9):slot+=2
            elif op==10:total+=40+info*8
            elif op not in (3,6,7):raise ValueError('Unknown unwind opcode '+str(op))
        if flags&4:
            chain=p+4+((count+1)&~1)*2
            total+=allocation(struct.unpack_from('<III',data,chain)[2],seen)
        return total
    symbols={}
    for name,address in re.findall(r'^\s*[0-9A-Fa-f]{4}:[0-9A-Fa-f]+\s+(\S+)\s+([0-9A-Fa-f]{16})\b',mapfile.read_text(errors='replace'),re.M):
        symbols[name]=int(address,16)
    probe=symbols.get('__chkstk');rows=[];missing=[]
    for name,address in symbols.items():
        if not re.fullmatch(r'(?:func|loop)_[89][0-9A-Fa-f]{7}(?:_region_[0-9A-Fa-f]+)?',name):continue
        rva=address-image;fn=by_start.get(rva)
        if fn:
            stack=allocation(fn[2]);begin=offset(rva);code=data[begin:begin+min(fn[1]-rva,128)]
        else:
            # Leaf functions with no stack/nonvolatile state need no unwind entry.
            stack=0;begin=offset(rva);code=data[begin:begin+32];missing.append(name)
        calls=bool(probe and any(code[i]==0xE8 and address+i+5+struct.unpack_from('<i',code,i+1)[0]==probe for i in range(max(0,len(code)-4))))
        rows.append(dict(name=name,va=hex(address),stack_bytes=stack,chkstk=calls))
    public=[r for r in rows if re.fullmatch(r'func_[89][0-9A-Fa-f]{7}',r['name'])]
    result=dict(executable=str(executable),sha256=hashlib.sha256(data).hexdigest().upper(),public_chunks=len(public),
        functions=len(rows),public_max_bytes=max((r['stack_bytes'] for r in public),default=0),
        production_max_bytes=max((r['stack_bytes'] for r in rows),default=0),chkstk_prologues=sum(r['chkstk'] for r in rows),
        stack_reserve_bytes=struct.unpack_from('<Q',data,opt+72)[0],leaf_without_unwind=len(missing),
        functions_by_stack=sorted(rows,key=lambda r:r['stack_bytes'],reverse=True))
    return result

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--exe',type=Path,required=True);p.add_argument('--map',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True);p.add_argument('--max-frame',type=int);a=p.parse_args()
    result=inspect(a.exe,a.map);a.output.write_text(json.dumps(result,indent=2))
    print(json.dumps({k:v for k,v in result.items() if k!='functions_by_stack'},indent=2));print(json.dumps(result['functions_by_stack'][:5],indent=2))
    if a.max_frame is not None:
        if result['public_chunks']!=185 or result['production_max_bytes']>a.max_frame or result['chkstk_prologues']:
            raise SystemExit('Production chunk stack/probe invariant failed')
if __name__=='__main__':main()
