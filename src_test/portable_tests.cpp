#include "portable_config.h"
#include "disc_image.h"
#include "card_store.h"
#include <windows.h>
#include <bcrypt.h>
#include <bzlib.h>
#include <lzma.h>
#include <zstd.h>
#include <filesystem>
#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <cstdio>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL portable line %d: %s\n",__LINE__,#x);return 1;}}while(0)
namespace fs=std::filesystem;
using Byte=unsigned char;using Bytes=std::vector<Byte>;
static void put32(Bytes& b,size_t at,uint32_t v){for(int i=0;i<4;i++)b[at+i]=Byte(v>>(24-i*8));}
static void put64(Bytes& b,size_t at,uint64_t v){put32(b,at,uint32_t(v>>32));put32(b,at+4,uint32_t(v));}
static void sha(const Byte* p,size_t n,Byte* out){BCRYPT_ALG_HANDLE a=nullptr;BCryptOpenAlgorithmProvider(&a,BCRYPT_SHA1_ALGORITHM,nullptr,0);BCryptHash(a,nullptr,0,const_cast<Byte*>(p),ULONG(n),out,20);BCryptCloseAlgorithmProvider(a,0);}
static Bytes compress(const Bytes& b,int codec){
 if(!codec)return b;Bytes out(b.size()*2+4096);
 if(codec==5){size_t n=ZSTD_compress(out.data(),out.size(),b.data(),b.size(),3);if(ZSTD_isError(n))return {};out.resize(n);}
 if(codec==2){unsigned n=(unsigned)out.size();if(BZ2_bzBuffToBuffCompress((char*)out.data(),&n,(char*)b.data(),(unsigned)b.size(),1,0,30)!=BZ_OK)return {};out.resize(n);}
 if(codec==3||codec==4){lzma_options_lzma options{};lzma_lzma_preset(&options,1);options.dict_size=1<<20;lzma_filter filters[]={{codec==3?LZMA_FILTER_LZMA1:LZMA_FILTER_LZMA2,&options},{LZMA_VLI_UNKNOWN,nullptr}};size_t n=0;if(lzma_raw_buffer_encode(filters,nullptr,b.data(),b.size(),out.data(),&n,out.size())!=LZMA_OK)return {};out.resize(n);}
 return out;
}
static Bytes rvz_fixture(const Bytes& raw,int codec,bool packing){
 constexpr size_t chunk=32768;Bytes h(0xdc),file(0x48+0xdc);memcpy(file.data(),"RVZ\1",4);put32(file,4,0x01000000);put32(file,8,0x00030000);put32(file,12,0xdc);put64(file,0x24,raw.size());
 put32(h,0,1);put32(h,4,codec);put32(h,12,chunk);memcpy(h.data()+16,raw.data(),0x80);
 if(codec==3){h[0xd4]=5;h[0xd5]=93;h[0xd6]=0;h[0xd7]=0;h[0xd8]=16;h[0xd9]=0;}if(codec==4){h[0xd4]=1;h[0xd5]=16;}
 Bytes ranges(24);put64(ranges,0,0x80);put64(ranges,8,raw.size()-0x80);put32(ranges,16,0);put32(ranges,20,2);Bytes compressed=compress(ranges,codec);put32(h,0xb4,1);put64(h,0xb8,file.size());put32(h,0xc0,uint32_t(compressed.size()));file.insert(file.end(),compressed.begin(),compressed.end());
 Bytes groups(24);
 for(int i=0;i<2;i++){
  while(file.size()%4)file.push_back(0);put32(groups,i*12,uint32_t(file.size()/4));Bytes bytes(raw.begin()+i*chunk,raw.begin()+(i+1)*chunk);
  if(packing){Bytes p(4);put32(p,0,uint32_t(bytes.size()));p.insert(p.end(),bytes.begin(),bytes.end());bytes=std::move(p);put32(groups,i*12+8,uint32_t(bytes.size()));}
  compressed=compress(bytes,codec);put32(groups,i*12+4,uint32_t(compressed.size())|(codec?0x80000000u:0));file.insert(file.end(),compressed.begin(),compressed.end());
 }
 compressed=compress(groups,codec);put32(h,0xc4,2);put64(h,0xc8,file.size());put32(h,0xd0,uint32_t(compressed.size()));file.insert(file.end(),compressed.begin(),compressed.end());
 memcpy(file.data()+0x48,h.data(),h.size());sha(h.data(),h.size(),file.data()+16);put64(file,0x2c,file.size());sha(file.data(),0x34,file.data()+0x34);return file;
}
int main(int argc,char** argv){
 char error[512];
 if(argc==2){DiscImage* d=disc_image_open(argv[1],error,sizeof(error));CHECK(d);CHECK(disc_image_validate_game(d,error,sizeof(error)));void* dol=nullptr;size_t size=0;CHECK(disc_image_dol(d,&dol,&size)&&size==3525376);free(dol);disc_image_close(d);puts("Original image identity and embedded DOL passed");return 0;}
 auto dir=fs::current_path()/std::to_string(GetCurrentProcessId());fs::create_directory(dir);fs::current_path(dir);
 LauncherConfig a,b;launcher_config_defaults(&a);strcpy_s(a.image_path,"C:/Jogos/日本語 e ação/jogo.rvz");a.keyboard_enabled=false;a.keyboard_port=3;strcpy_s(a.ports[0],"none");strcpy_s(a.ports[3],"keyboard");a.keys[0]=80;
 CHECK(!a.vsync&&a.window_mode==0&&a.window_resolution==1&&a.internal_resolution==0&&a.aspect_ratio==0);a.vsync=true;a.window_mode=2;a.window_resolution=4;a.internal_resolution=3;a.aspect_ratio=1;
 CHECK(launcher_config_save("launcher.json",&a,error,sizeof(error)));CHECK(launcher_config_load("launcher.json",&b,error,sizeof(error)));CHECK(!strcmp(a.image_path,b.image_path)&&!b.keyboard_enabled&&b.keyboard_port==3&&b.keys[0]==80&&b.vsync&&b.window_mode==2&&b.window_resolution==4&&b.internal_resolution==3&&b.aspect_ratio==1);
 {const char* legacy=R"({"image_path":"","keyboard_enabled":true,"keyboard_port":0,"ports":["keyboard","none","none","none"],"keys":[29,27,6,25,43,40,20,8,26,22,4,7,82,81,80,79,12,14,13,15]})";CHECK(portable_write_atomic("launcher.json",legacy,strlen(legacy)));CHECK(launcher_config_load("launcher.json",&b,error,sizeof(error))&&!b.vsync&&b.window_mode==0&&b.window_resolution==1&&b.internal_resolution==0&&b.aspect_ratio==0);}

 CHECK(portable_write_atomic("launcher.json","{bad",4));CHECK(!launcher_config_load("launcher.json",&b,error,sizeof(error)));CHECK(launcher_config_load("missing.json",&b,error,sizeof(error))&&b.keyboard_enabled);
 Bytes raw(65536);for(size_t i=0;i<raw.size();i++)raw[i]=Byte((i*71+i/17)%251);memcpy(raw.data(),"GDEE78",6);
 CHECK(portable_write_atomic("fixture.iso",raw.data(),raw.size()));DiscImage* d=disc_image_open("fixture.iso",error,sizeof(error));CHECK(d);std::array<Byte,500> read{};CHECK(disc_image_read(d,32612,read.data(),read.size())&&!memcmp(read.data(),raw.data()+32612,read.size()));CHECK(!disc_image_read(d,65530,read.data(),7));CHECK(!disc_image_validate_game(d,error,sizeof(error)));disc_image_close(d);
 Bytes ciso(0x8000+32768);memcpy(ciso.data(),"CISO",4);ciso[6]=0;ciso[5]=0x80;ciso[8]=1;memcpy(ciso.data()+0x8000,raw.data(),32768);CHECK(portable_write_atomic("fixture.ciso",ciso.data(),ciso.size()));d=disc_image_open("fixture.ciso",error,sizeof(error));CHECK(d);CHECK(disc_image_read(d,32760,read.data(),16));CHECK(!memcmp(read.data(),raw.data()+32760,8));for(int i=8;i<16;i++)CHECK(read[i]==0);disc_image_close(d);
 for(int codec:{0,2,3,4,5})for(bool packed:{false,true}){
  Bytes f=rvz_fixture(raw,codec,packed);CHECK(portable_write_atomic("fixture.rvz",f.data(),f.size()));d=disc_image_open("fixture.rvz",error,sizeof(error));if(!d)fprintf(stderr,"RVZ codec %d packed %d: %s\n",codec,packed,error);CHECK(d);Bytes decoded(raw.size());CHECK(disc_image_read(d,0,decoded.data(),decoded.size()));CHECK(decoded==raw);for(int k=0;k<20;k++)CHECK(disc_image_read(d,k*3000,read.data(),read.size())&&!memcmp(read.data(),raw.data()+k*3000,read.size()));disc_image_close(d);
  f[0x48+4]^=1;CHECK(portable_write_atomic("fixture.rvz",f.data(),f.size()));CHECK(!disc_image_open("fixture.rvz",error,sizeof(error)));
 }
 card_store_init("saves");CHECK(card_store_mount()==0);int free_bytes=0,free_files=0;CHECK(card_store_free(&free_bytes,&free_files)==0&&free_files==127);const Byte id[6]={'G','D','E','E','7','8'};
 CHECK(card_store_create(id,"../unsafe",8193)==-128);int slot=card_store_create(id,"DRA2SAVE",16384);CHECK(slot==0);CHECK(card_store_create(id,"DRA2SAVE",8192)==-7);CHECK(card_store_create(id,"oversized",16777216)==-9);
 CHECK(card_store_transfer(slot,raw.data(),8192,8192,true)==0);std::array<Byte,64> metadata{};CHECK(card_store_get(slot,metadata.data(),nullptr)==0);metadata[7]=2;metadata[0x2c]=0x12;CHECK(card_store_set(slot,metadata.data())==0);card_store_shutdown();
 card_store_init("saves");CHECK(card_store_mount()==0&&card_store_find(id,"DRA2SAVE")==0);Bytes saved(8192);CHECK(card_store_transfer(0,saved.data(),8192,8192,false)==0&&!memcmp(saved.data(),raw.data(),8192));CHECK(card_store_transfer(0,saved.data(),8192,16384,false)==-128);std::array<Byte,64> after{};CHECK(card_store_get(0,after.data(),nullptr)==0&&after==metadata);card_store_shutdown();
 FILE* f=portable_fopen("saves/MemoryCardA.card","r+b");CHECK(f);CHECK(_fseeki64(f,-1,SEEK_END)==0);fputc(0xee,f);fclose(f);card_store_init("saves");CHECK(card_store_mount()==-6);CHECK(card_store_format()==0);CHECK(card_store_free(&free_bytes,&free_files)==0&&free_files==127);card_store_shutdown();
 for(const char* name:{"fixture.iso","fixture.ciso","fixture.rvz","launcher.json","saves/MemoryCardA.card","saves/MemoryCardA.lock"})fs::remove(name);fs::remove("saves");fs::current_path(dir.parent_path());fs::remove(dir);
 puts("Portable config, all RVZ codecs/packing, CISO boundaries and durable CARD reopen/corruption passed");return 0;
}
