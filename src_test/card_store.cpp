#include "card_store.h"
#include "portable_config.h"
#include <windows.h>
#include <array>
#include <vector>
#include <string>
#include <cstring>
static constexpr uint32_t capacity=(2048u-5u)*CARD_BLOCK_SIZE;
struct Entry{std::array<uint8_t,64> dir{};std::vector<uint8_t> data;};
static std::array<Entry,CARD_FILE_COUNT> entries;
static std::string card_path,lock_path;static HANDLE card_lock=INVALID_HANDLE_VALUE;static bool mounted=false;
static uint32_t crc(const uint8_t* p,size_t n){uint32_t c=~0u;for(size_t i=0;i<n;i++){c^=p[i];for(int b=0;b<8;b++)c=(c>>1)^(0xedb88320u&uint32_t(-int(c&1)));}return ~c;}
static void put(std::vector<uint8_t>& b,uint32_t v){for(int i=3;i>=0;i--)b.push_back(uint8_t(v>>(i*8)));}
static uint32_t get(const uint8_t* p){return uint32_t(p[0])<<24|uint32_t(p[1])<<16|uint32_t(p[2])<<8|p[3];}
static bool commit(){
 std::vector<uint8_t> b={'D','R','A','2','C','A','R','D'};put(b,1);put(b,0);
 for(const auto& e:entries){put(b,uint32_t(e.data.size()));b.insert(b.end(),e.dir.begin(),e.dir.end());b.insert(b.end(),e.data.begin(),e.data.end());}
 uint32_t c=crc(b.data()+16,b.size()-16);for(int i=0;i<4;i++)b[12+i]=uint8_t(c>>(24-i*8));
 return portable_write_atomic(card_path.c_str(),b.data(),b.size());
}
void card_store_init(const char* directory){card_store_shutdown();card_path=std::string(directory)+"/MemoryCardA.card";lock_path=std::string(directory)+"/MemoryCardA.lock";}
void card_store_shutdown(void){mounted=false;for(auto& e:entries)e=Entry{};if(card_lock!=INVALID_HANDLE_VALUE){CloseHandle(card_lock);card_lock=INVALID_HANDLE_VALUE;}}
int card_store_mount(){
 if(mounted)return 0;if(card_path.empty())return -5;
 auto at=card_path.find_last_of("/\\");if(!portable_mkdirs(card_path.substr(0,at).c_str()))return -5;
 if(card_lock==INVALID_HANDLE_VALUE){int n=MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,lock_path.c_str(),-1,nullptr,0);if(!n)return -5;std::vector<wchar_t> p(n);MultiByteToWideChar(CP_UTF8,0,lock_path.c_str(),-1,p.data(),n);card_lock=CreateFileW(p.data(),GENERIC_READ|GENERIC_WRITE,0,nullptr,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr);if(card_lock==INVALID_HANDLE_VALUE)return -1;}
 for(auto& e:entries)e=Entry{};
 if(!portable_exists(card_path.c_str())){if(!commit())return -5;mounted=true;return 0;}
 FILE* f=portable_fopen(card_path.c_str(),"rb");if(!f)return -5;_fseeki64(f,0,SEEK_END);auto size=_ftelli64(f);rewind(f);if(size<16+CARD_FILE_COUNT*68||size>capacity+16+CARD_FILE_COUNT*68){fclose(f);return -6;}
 std::vector<uint8_t> b(size_t(size),0);bool ok=fread(b.data(),1,b.size(),f)==b.size();fclose(f);
 if(!ok)return -5;if(memcmp(b.data(),"DRA2CARD",8)||get(b.data()+8)!=1||get(b.data()+12)!=crc(b.data()+16,b.size()-16))return -6;
 size_t p=16;uint32_t total=0;std::array<Entry,CARD_FILE_COUNT> loaded;
 for(auto& e:loaded){if(b.size()-p<68)return -6;uint32_t n=get(b.data()+p);p+=4;if(n%CARD_BLOCK_SIZE||n>capacity-total||n>b.size()-p-64)return -6;total+=n;memcpy(e.dir.data(),b.data()+p,64);p+=64;e.data.assign(b.begin()+p,b.begin()+p+n);p+=n;}
 if(p!=b.size())return -6;entries=std::move(loaded);mounted=true;return 0;
}
int card_store_format(){if(card_lock==INVALID_HANDLE_VALUE){int result=card_store_mount();if(result!=0&&result!=-6)return result;}auto previous=entries;for(auto& e:entries)e=Entry{};if(!commit()){entries=std::move(previous);return -5;}mounted=true;return 0;}
int card_store_free(int* bytes,int* files){if(!mounted)return -3;uint32_t used=0;int count=0;for(auto& e:entries){used+=uint32_t(e.data.size());count+=!e.data.empty();}if(bytes)*bytes=int(capacity-used);if(files)*files=CARD_FILE_COUNT-count;return 0;}
int card_store_find(const uint8_t id[6],const char* name){if(!mounted)return -3;for(int i=0;i<CARD_FILE_COUNT;i++)if(!entries[i].data.empty()&&!memcmp(entries[i].dir.data(),id,6)&&!strncmp((const char*)entries[i].dir.data()+8,name,32))return i;return -4;}
int card_store_create(const uint8_t id[6],const char* name,uint32_t size){
 if(!mounted)return -3;size_t len=strlen(name);if(!len||len>32||!size||size%CARD_BLOCK_SIZE)return -128;
 if(card_store_find(id,name)>=0)return -7;int bytes=0,files=0;card_store_free(&bytes,&files);if(!files)return -8;if(size>uint32_t(bytes))return -9;
 int i=0;while(!entries[i].data.empty())i++;auto& e=entries[i];e=Entry{};memcpy(e.dir.data(),id,6);memcpy(e.dir.data()+8,name,len);e.dir[0x34]=4;e.dir[0x36]=0;e.dir[0x37]=5;e.dir[0x38]=uint8_t((size/CARD_BLOCK_SIZE)>>8);e.dir[0x39]=uint8_t(size/CARD_BLOCK_SIZE);memset(e.dir.data()+0x2c,0xff,4);memset(e.dir.data()+0x3c,0xff,4);e.dir[0x33]=1;e.data.resize(size);
 if(!commit()){e=Entry{};return -5;}return i;
}
int card_store_get(int file,uint8_t dir[64],uint32_t* size){if(!mounted)return -3;if(file<0||file>=CARD_FILE_COUNT)return -128;auto& e=entries[file];if(e.data.empty())return -4;if(dir)memcpy(dir,e.dir.data(),64);if(size)*size=uint32_t(e.data.size());return 0;}
int card_store_set(int file,const uint8_t dir[64]){int r=card_store_get(file,nullptr,nullptr);if(r)return r;auto previous=entries[file].dir;memcpy(entries[file].dir.data(),dir,64);if(!commit()){entries[file].dir=previous;return -5;}return 0;}
int card_store_delete(int file){int r=card_store_get(file,nullptr,nullptr);if(r)return r;auto previous=std::move(entries[file]);entries[file]=Entry{};if(!commit()){entries[file]=std::move(previous);return -5;}return 0;}
int card_store_transfer(int file,void* data,uint32_t n,uint32_t offset,bool write){int r=card_store_get(file,nullptr,nullptr);if(r)return r;auto& e=entries[file];if(offset>e.data.size()||n>e.data.size()-offset||(!data&&n))return -128;
 if(!write){if(n)memcpy(data,e.data.data()+offset,n);return 0;}std::vector<uint8_t> previous(e.data.begin()+offset,e.data.begin()+offset+n);if(n)memcpy(e.data.data()+offset,data,n);if(!commit()){if(n)memcpy(e.data.data()+offset,previous.data(),n);return -5;}return 0;}
