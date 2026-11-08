#include "portable_config.h"
#include <SDL_scancode.h>
#include <windows.h>
#include <filesystem>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include "picojson.h"
namespace fs=std::filesystem;
static fs::path path8(const char* s){return fs::path(std::u8string(reinterpret_cast<const char8_t*>(s)));}
const char* const launcher_key_names[KEY_BIND_COUNT]={"A","B","X","Y","Z","Start","L","R","Stick Up","Stick Down","Stick Left","Stick Right","D-Pad Up","D-Pad Down","D-Pad Left","D-Pad Right","C-Stick Up","C-Stick Down","C-Stick Left","C-Stick Right"};
void launcher_config_defaults(LauncherConfig* c){
    memset(c,0,sizeof(*c));c->keyboard_enabled=true;
    strcpy_s(c->ports[0],"keyboard");for(int i=1;i<4;i++)strcpy_s(c->ports[i],"none");
    const int keys[KEY_BIND_COUNT]={SDL_SCANCODE_Z,SDL_SCANCODE_X,SDL_SCANCODE_C,SDL_SCANCODE_V,SDL_SCANCODE_TAB,SDL_SCANCODE_RETURN,SDL_SCANCODE_Q,SDL_SCANCODE_E,SDL_SCANCODE_W,SDL_SCANCODE_S,SDL_SCANCODE_A,SDL_SCANCODE_D,SDL_SCANCODE_UP,SDL_SCANCODE_DOWN,SDL_SCANCODE_LEFT,SDL_SCANCODE_RIGHT,SDL_SCANCODE_I,SDL_SCANCODE_K,SDL_SCANCODE_J,SDL_SCANCODE_L};
    memcpy(c->keys,keys,sizeof(keys));
}
FILE* portable_fopen(const char* p,const char* mode){try{std::wstring m;while(*mode)m+=wchar_t(*mode++);return _wfopen(path8(p).c_str(),m.c_str());}catch(...){return nullptr;}}
bool portable_mkdirs(const char* p){try{std::error_code e;fs::create_directories(path8(p),e);return !e && fs::is_directory(path8(p));}catch(...){return false;}}
bool portable_exists(const char* p){try{return fs::is_regular_file(path8(p));}catch(...){return false;}}
bool portable_executable_root(char* out,size_t cap){wchar_t p[32768];DWORD n=GetModuleFileNameW(nullptr,p,32768);if(!n||n>=32768)return false;auto s=fs::path(p).parent_path().u8string();if(s.size()+1>cap)return false;memcpy(out,s.c_str(),s.size()+1);return true;}
bool portable_write_atomic(const char* p,const void* data,size_t size){
    try{
        fs::path dest=path8(p), temp=dest;temp+=L".tmp";
        std::error_code ec;if(!dest.parent_path().empty()){fs::create_directories(dest.parent_path(),ec);if(ec)return false;}
        HANDLE h=CreateFileW(temp.c_str(),GENERIC_WRITE,0,nullptr,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr);
        if(h==INVALID_HANDLE_VALUE)return false;
        const char* bytes=static_cast<const char*>(data);size_t at=0;bool ok=true;
        while(at<size){DWORD written=0;DWORD count=DWORD((size-at)>0x40000000?0x40000000:(size-at));if(!WriteFile(h,bytes+at,count,&written,nullptr)||written!=count){ok=false;break;}at+=written;}
        if(ok)ok=FlushFileBuffers(h)!=0;CloseHandle(h);
        if(ok)ok=MoveFileExW(temp.c_str(),dest.c_str(),MOVEFILE_REPLACE_EXISTING|MOVEFILE_WRITE_THROUGH)!=0;
        if(!ok)DeleteFileW(temp.c_str());return ok;
    }catch(...){return false;}
}
static bool fail(char* e,size_t cap,const char* message){if(e&&cap)snprintf(e,cap,"%s",message);return false;}
bool launcher_config_load(const char* p,LauncherConfig* c,char* error,size_t cap){
    launcher_config_defaults(c);if(error&&cap)*error=0;
    FILE* f=portable_fopen(p,"rb");if(!f){if(!portable_exists(p))return true;return fail(error,cap,"Cannot open configuration.");}
    std::string text;char block[4096];size_t n;while((n=fread(block,1,sizeof(block),f))!=0){text.append(block,n);if(text.size()>65536){fclose(f);return fail(error,cap,"Configuration exceeds 64 KiB.");}}bool io=ferror(f)==0;fclose(f);if(!io)return fail(error,cap,"Cannot read configuration.");
    picojson::value root;std::string err=picojson::parse(root,text);if(!err.empty()||!root.is<picojson::object>())return fail(error,cap,"Invalid launcher JSON.");
    LauncherConfig v=*c;
    auto& o=root.get<picojson::object>();
    if(o.count("vsync")){if(!o["vsync"].is<bool>())return fail(error,cap,"Invalid VSync setting.");v.vsync=o["vsync"].get<bool>();}
    auto get=[&](const char* key)->const picojson::value&{static picojson::value nil;auto it=o.find(key);return it==o.end()?nil:it->second;};
    if(!get("image_path").is<std::string>()||get("image_path").get<std::string>().size()>=sizeof(v.image_path))return fail(error,cap,"Invalid image_path.");
    strcpy_s(v.image_path,get("image_path").get<std::string>().c_str());
    if(!get("keyboard_enabled").is<bool>()||!get("keyboard_port").is<double>())return fail(error,cap,"Invalid keyboard settings.");
    v.keyboard_enabled=get("keyboard_enabled").get<bool>();double port=get("keyboard_port").get<double>();if(port<0||port>3||floor(port)!=port)return fail(error,cap,"Invalid keyboard port.");v.keyboard_port=int(port);
    if(!get("ports").is<picojson::array>()||get("ports").get<picojson::array>().size()!=4)return fail(error,cap,"Expected four controller ports.");
    for(int i=0;i<4;i++){auto& s=get("ports").get<picojson::array>()[i];if(!s.is<std::string>()||s.get<std::string>().size()>=80)return fail(error,cap,"Invalid controller identifier.");strcpy_s(v.ports[i],s.get<std::string>().c_str());}
    if(!get("keys").is<picojson::array>()||get("keys").get<picojson::array>().size()!=KEY_BIND_COUNT)return fail(error,cap,"Invalid keyboard bindings.");
    for(int i=0;i<KEY_BIND_COUNT;i++){auto& k=get("keys").get<picojson::array>()[i];if(!k.is<double>()||k.get<double>()<0||k.get<double>()>=double(SDL_NUM_SCANCODES)||floor(k.get<double>())!=k.get<double>())return fail(error,cap,"Invalid scancode.");v.keys[i]=int(k.get<double>());}
    *c=v;return true;
}
bool launcher_config_save(const char* p,const LauncherConfig* c,char* e,size_t cap){
    picojson::object o;o["version"]=picojson::value(1.0);o["image_path"]=picojson::value(std::string(c->image_path));o["keyboard_enabled"]=picojson::value(c->keyboard_enabled);o["keyboard_port"]=picojson::value(double(c->keyboard_port));
    o["vsync"]=picojson::value(c->vsync);
    picojson::array ports,keys;for(auto& s:c->ports)ports.emplace_back(std::string(s));for(int k:c->keys)keys.emplace_back(double(k));o["ports"]=picojson::value(ports);o["keys"]=picojson::value(keys);
    std::string text=picojson::value(o).serialize(true);if(!portable_write_atomic(p,text.data(),text.size()))return fail(e,cap,"Cannot save configuration (check folder permissions).");return true;
}
