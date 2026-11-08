/* GC-only RVZ reader based on the pinned Dolphin docs/WiaAndRvz.md.
 * No Wii partition emulation. Compression libraries retain their own licenses.
 */
#include "disc_image.h"
#include "game_revision.h"
#include "portable_config.h"
#include <windows.h>
#include <bcrypt.h>
#include <bzlib.h>
#include <lzma.h>
#include <zstd.h>
#include <array>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>
using U8=uint8_t;using U32=uint32_t;using U64=uint64_t;
static U32 be32(const U8* p){return (U32(p[0])<<24)|(U32(p[1])<<16)|(U32(p[2])<<8)|p[3];}
static U64 be64(const U8* p){return U64(be32(p))<<32|be32(p+4);}
static bool digest(const U8* p,size_t n,LPCWSTR algorithm,U8* out,ULONG count){
    BCRYPT_ALG_HANDLE a=nullptr;if(n>ULONG_MAX||BCryptOpenAlgorithmProvider(&a,algorithm,nullptr,0)<0)return false;
    NTSTATUS s=BCryptHash(a,nullptr,0,const_cast<U8*>(p),ULONG(n),out,count);BCryptCloseAlgorithmProvider(a,0);return s>=0;
}
struct DiscImage {
    FILE* file=nullptr;U64 length=0,logical=0;int kind=0;U32 chunk=0,codec=0;std::array<U8,0xdc> h{};
    struct Raw{U64 offset,size;U32 group,count;};struct Group{U64 offset;U32 size,packed;};
    std::vector<Raw> raw;std::vector<Group> groups;std::vector<U64> ciso;
    struct Cache{U32 group=UINT32_MAX;U64 age=0;std::vector<U8> bytes;};std::array<Cache,4> cache;U64 age=0;
    ~DiscImage(){if(file)fclose(file);}
    bool read_file(U64 at,void* dst,size_t n){return at<=length&&n<=length-at&&_fseeki64(file,at,SEEK_SET)==0&&fread(dst,1,n,file)==n;}
    bool decompress(U64 at,U32 stored,size_t expected,U32 method,std::vector<U8>& out){
        if(expected>64*1024*1024||stored>64*1024*1024)return false;
        std::vector<U8> in(stored);out.resize(expected);if(!read_file(at,in.data(),stored))return false;
        if(method==0){if(stored!=expected)return false;out=std::move(in);return true;}
        if(method==2){unsigned int len=(unsigned int)expected;return BZ2_bzBuffToBuffDecompress((char*)out.data(),&len,(char*)in.data(),stored,0,0)==BZ_OK && len==expected;}
        if(method==5){size_t n=ZSTD_decompress(out.data(),expected,in.data(),stored);return !ZSTD_isError(n)&&n==expected;}
        if(method==3||method==4){
            lzma_filter filters[2]={{method==3?LZMA_FILTER_LZMA1:LZMA_FILTER_LZMA2,nullptr},{LZMA_VLI_UNKNOWN,nullptr}};
            if(h[0xd4]!=(method==3?5:1)||lzma_properties_decode(&filters[0],nullptr,h.data()+0xd5,h[0xd4])!=LZMA_OK)return false;
            /* Hard cap dictionary allocation for hostile input. */
            bool ok=lzma_raw_decoder_memusage(filters)<=256ull*1024*1024;size_t ip=0,op=0;
            if(ok)ok=lzma_raw_buffer_decode(filters,nullptr,in.data(),&ip,in.size(),out.data(),&op,out.size())==LZMA_OK && ip==in.size()&&op==out.size();
            free(filters[0].options);return ok;
        }return false;
    }
    bool unpack(const std::vector<U8>& in,std::vector<U8>& out,size_t expected,U64 offset){
        out.clear();out.reserve(expected);size_t p=0;
        while(p<in.size()){
            if(in.size()-p<4)return false;U32 word=be32(in.data()+p);p+=4;size_t n=word&0x7fffffff;
            if(n>expected-out.size())return false;
            if(!(word&0x80000000)){if(n>in.size()-p)return false;out.insert(out.end(),in.begin()+p,in.begin()+p+n);p+=n;}
            else{
                if(in.size()-p<68)return false;std::array<U32,521> b{};
                for(int i=0;i<17;i++)b[i]=be32(in.data()+p+i*4);p+=68;
                for(int i=17;i<521;i++)b[i]=(b[i-17]<<23)^(b[i-16]>>9)^b[i-1];
                auto step=[&](){for(int i=0;i<32;i++)b[i]^=b[i+489];for(int i=32;i<521;i++)b[i]^=b[i-32];};
                for(int i=0;i<4;i++)step();size_t pos=0,skip=(offset+out.size())%0x8000;
                for(size_t i=0;i<skip+n;i++){if(pos==521*4){step();pos=0;}U32 v=b[pos/4];const int shift[]={24,18,8,0};U8 byte=U8(v>>shift[pos%4]);pos++;if(i>=skip)out.push_back(byte);}
            }
        }return out.size()==expected;
    }
    bool read(U64 at,void* dest,size_t n){
        if(at>logical||n>logical-at||(!dest&&n))return false;U8* dst=(U8*)dest;
        if(kind==0)return read_file(at,dest,n);
        while(n){
            if(kind==1){U64 i=at/chunk;if(i>=ciso.size())return false;size_t within=size_t(at%chunk),take=std::min(n,size_t(chunk)-within);if(ciso[i]){if(!read_file(ciso[i]+within,dst,take))return false;}else memset(dst,0,take);at+=take;dst+=take;n-=take;continue;}
            if(at<0x80){size_t take=std::min(n,size_t(0x80-at));memcpy(dst,h.data()+0x10+at,take);dst+=take;at+=take;n-=take;continue;}
            auto it=std::upper_bound(raw.begin(),raw.end(),at,[](U64 a,const Raw& r){return a<r.offset;});if(it==raw.begin())return false;--it;
            if(at>=it->offset+it->size)return false;U64 relative=at-it->offset;U32 index=it->group+U32(relative/chunk);if(index>=groups.size()||relative/chunk>=it->count)return false;
            size_t bytes=size_t(std::min(U64(chunk),it->size-relative/chunk*chunk));Cache* cached=nullptr;
            for(auto& c:cache)if(c.group==index){cached=&c;break;}
            if(!cached){cached=&*std::min_element(cache.begin(),cache.end(),[](const Cache& a,const Cache& b){return a.age<b.age;});cached->group=UINT32_MAX;auto& g=groups[index];U32 size=g.size&0x7fffffff;
                if(!size)cached->bytes.assign(bytes,0);
                else{std::vector<U8> decompressed;if(!decompress(g.offset,size,g.packed?g.packed:bytes,(g.size&0x80000000)?codec:0,decompressed))return false;
                    if(g.packed){if(!unpack(decompressed,cached->bytes,bytes,it->offset+relative/chunk*chunk))return false;}else cached->bytes=std::move(decompressed);}
                cached->group=index;
            }cached->age=++age;
            size_t within=size_t(relative%chunk),take=std::min(n,bytes-within);memcpy(dst,cached->bytes.data()+within,take);at+=take;dst+=take;n-=take;
        }return true;
    }
};
static DiscImage* error(DiscImage* i,char* e,size_t cap,const char* why){if(e&&cap)snprintf(e,cap,"%s",why);delete i;return nullptr;}
DiscImage* disc_image_open(const char* path,char* e,size_t cap){
    DiscImage* d=new DiscImage;d->file=portable_fopen(path,"rb");if(!d->file)return error(d,e,cap,"Cannot open disc image.");
    _fseeki64(d->file,0,SEEK_END);auto end=_ftelli64(d->file);if(end<0)return error(d,e,cap,"Cannot determine image size.");d->logical=d->length=U64(end);
    U8 header[0x48];if(!d->read_file(0,header,sizeof(header)))return error(d,e,cap,"Truncated image header.");
    if(!memcmp(header,"CISO",4)){
        d->kind=1;d->chunk=U32(header[4])|(U32(header[5])<<8)|(U32(header[6])<<16)|(U32(header[7])<<24);
        if(d->chunk<512||d->chunk>64*1024*1024||(d->chunk&(d->chunk-1)))return error(d,e,cap,"Invalid CISO block size.");
        std::vector<U8> map(0x7ff8);if(!d->read_file(8,map.data(),map.size()))return error(d,e,cap,"Truncated CISO map.");U64 pos=0x8000;
        for(U8 present:map){if(present>1)return error(d,e,cap,"Invalid CISO map entry.");d->ciso.push_back(present?pos:0);if(present)pos+=d->chunk;}
        /* Truncated data is reported at the exact read, including DVD async errors. */d->logical=U64(d->chunk)*map.size();
    }else if(!memcmp(header,"RVZ\1",4)){
        d->kind=2;U8 sha[20];U32 hs=be32(header+12);
        if(be32(header+8)>0x01000000||hs!=0xdc||!digest(header,0x34,BCRYPT_SHA1_ALGORITHM,sha,20)||memcmp(sha,header+0x34,20)||be64(header+0x2c)!=d->length||!d->read_file(0x48,d->h.data(),hs)||!digest(d->h.data(),hs,BCRYPT_SHA1_ALGORITHM,sha,20)||memcmp(sha,header+16,20))return error(d,e,cap,"Invalid RVZ version, size or header checksum.");
        auto& h=d->h;d->logical=be64(header+0x24);d->codec=be32(h.data()+4);d->chunk=be32(h.data()+12);
        if(be32(h.data())!=1||be32(h.data()+0x90)!=0||d->codec==1||d->codec>5||d->chunk<0x8000||d->chunk>64*1024*1024||(d->chunk<0x200000?(d->chunk&(d->chunk-1)):(d->chunk%0x200000)))return error(d,e,cap,"Unsupported RVZ (GameCube only) or invalid chunk size.");
        U32 nr=be32(h.data()+0xb4),ng=be32(h.data()+0xc4);if(!nr||nr>4096||!ng||ng>1000000)return error(d,e,cap,"Invalid RVZ table counts.");
        std::vector<U8> table;if(!d->decompress(be64(h.data()+0xb8),be32(h.data()+0xc0),size_t(nr)*24,d->codec,table))return error(d,e,cap,"Cannot decompress RVZ raw table.");
        for(U32 i=0;i<nr;i++){const U8* p=table.data()+i*24;U64 at=be64(p),size=be64(p+8),pad=at%0x8000;U32 gi=be32(p+16),count=be32(p+20);if(at>d->logical||size>d->logical-at||gi>=ng||count>ng-gi)return error(d,e,cap,"RVZ range outside image.");d->raw.push_back({at-pad,size+pad,gi,count});}
        std::sort(d->raw.begin(),d->raw.end(),[](const DiscImage::Raw& a,const DiscImage::Raw& b){return a.offset<b.offset;});
        for(size_t i=1;i<d->raw.size();i++)if(d->raw[i].offset<d->raw[i-1].offset+d->raw[i-1].size)return error(d,e,cap,"Overlapping RVZ raw ranges.");
        if(!d->decompress(be64(h.data()+0xc8),be32(h.data()+0xd0),size_t(ng)*12,d->codec,table))return error(d,e,cap,"Cannot decompress RVZ group table.");
        for(U32 i=0;i<ng;i++){const U8* p=table.data()+i*12;U64 at=U64(be32(p))*4;U32 size=be32(p+4),packed=be32(p+8);if(at>d->length||(size&0x7fffffff)>d->length-at)return error(d,e,cap,"RVZ group outside file.");d->groups.push_back({at,size,packed});}
    }else if(!memcmp(header,"WIA\1",4))return error(d,e,cap,"WIA is not supported; use ISO, CISO or RVZ.");
    if(e&&cap)*e=0;return d;
}
bool disc_image_read(DiscImage* d,U64 at,void* p,size_t n){try{return d&&d->read(at,p,n);}catch(...){return false;}}
void disc_image_close(DiscImage* d){delete d;}
bool disc_image_dol(DiscImage* d,void** data,size_t* size){
    U8 at[4],h[256];if(!disc_image_read(d,0x420,at,4))return false;U64 base=be32(at);if(!disc_image_read(d,base,h,256))return false;U64 length=256;
    for(int i=0;i<18;i++){U32 off=be32(h+i*4),n=be32(h+0x90+i*4);if(n){if(off<256||U64(off)+n>32*1024*1024)return false;length=std::max(length,U64(off)+n);}}
    void* p=malloc(size_t(length));if(!p)return false;if(!disc_image_read(d,base,p,size_t(length))){free(p);return false;}*data=p;*size=size_t(length);return true;
}
bool disc_image_validate_game(DiscImage* d,char* e,size_t cap){
    U8 id[0x20];void* dol=nullptr;size_t size=0;
    if(!disc_image_read(d,0,id,sizeof(id))||be32(id+0x1c)!=0xc2339f3d||!disc_image_dol(d,&dol,&size)){if(e&&cap)snprintf(e,cap,"Invalid GameCube image / DOL.");return false;}
    U8 sha[32];bool ok=digest((U8*)dol,size,BCRYPT_SHA256_ALGORITHM,sha,32);free(dol);
    /* Generated from the exact source DOL used by this static recompile. */
    static const U8 expected[32]={DOL_SHA256_BYTES};
    ok=ok&&!memcmp(sha,expected,32);if(!ok&&e&&cap)snprintf(e,cap,"Unsupported game revision. This build requires the original USA DOL (see README).");return ok;
}
