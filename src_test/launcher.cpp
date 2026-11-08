#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <windows.h>
#include <commdlg.h>
#include <shellapi.h>
#include <objidl.h>
#include <gdiplus.h>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include "portable_config.h"
#include "disc_image.h"
extern "C" {
#include "input_devices.h"
}
namespace fs=std::filesystem;
static LauncherConfig config;
static HWND main_window,image_edit,ports[4],keyboard_check,keyboard_port,key_buttons[KEY_BIND_COUNT],status_label,play_button;
static HWND vsync_check,window_mode_choice,window_res_choice,internal_res_choice,aspect_ratio_choice;
static std::vector<HWND> page_controls[4];
static int building_page=-1,active_page=0;
static HWND tab_buttons[4];
static ULONG_PTR gdiplus_token;
static IStream* agumon_stream;
static Gdiplus::Image* agumon;
static void update_keys();
static HFONT font,heading,small_font;static HBRUSH background,panel;static int scale=96,capture=-1;
static InputDevice devices[INPUT_DEVICE_MAX];static int device_count;static std::vector<std::string> choices;
static fs::path root;static HANDLE game=nullptr;
static constexpr COLORREF bg=RGB(12,19,32),surface=RGB(24,37,56),blue=RGB(34,126,231),text=RGB(230,240,254),muted=RGB(153,179,210);
static int px(int n){return MulDiv(n,scale,96);}
static std::wstring wide(const char* p){int n=MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,p,-1,nullptr,0);if(!n)return L"";std::wstring s(n,0);MultiByteToWideChar(CP_UTF8,0,p,-1,s.data(),n);s.resize(n-1);return s;}
static std::string utf8(const std::wstring& s){int n=WideCharToMultiByte(CP_UTF8,0,s.c_str(),int(s.size()),nullptr,0,nullptr,nullptr);std::string p(n,0);WideCharToMultiByte(CP_UTF8,0,s.c_str(),int(s.size()),p.data(),n,nullptr,nullptr);return p;}
static std::string path8(const fs::path& p){auto u=p.u8string();return std::string(reinterpret_cast<const char*>(u.data()),u.size());}
static void message(const std::wstring& s){MessageBoxW(main_window,s.c_str(),L"Digimon Rumble Arena 2",MB_OK|MB_ICONINFORMATION);}
static HWND control(const wchar_t* cls,const wchar_t* label,int style,int id,int x,int y,int w,int h){HWND c=CreateWindowExW(0,cls,label,WS_CHILD|WS_VISIBLE|style,px(x),px(y),px(w),px(h),main_window,(HMENU)(INT_PTR)id,GetModuleHandleW(nullptr),nullptr);SendMessageW(c,WM_SETFONT,(WPARAM)font,TRUE);if(building_page>=0)page_controls[building_page].push_back(c);return c;}
static HWND button(const wchar_t* label,int id,int x,int y,int w,int h){return control(L"BUTTON",label,BS_OWNERDRAW|WS_TABSTOP,id,x,y,w,h);}
static void label(const wchar_t* value,int x,int y,int w,int h){control(L"STATIC",value,0,0,x,y,w,h);}
static void update_keys(){for(int i=0;i<KEY_BIND_COUNT;i++){std::wstring s=wide(launcher_key_names[i])+L"   ·   "+wide(SDL_GetScancodeName((SDL_Scancode)config.keys[i]));if(!config.keys[i])s=wide(launcher_key_names[i])+L"   ·   —";if(capture==i)s=L"Pressione uma tecla...";SetWindowTextW(key_buttons[i],s.c_str());}}
static void show_page(int page){
 if(page<0||page>3)return;capture=-1;update_keys();active_page=page;
 for(int i=0;i<4;i++){for(HWND child:page_controls[i])ShowWindow(child,i==page?SW_SHOW:SW_HIDE);InvalidateRect(tab_buttons[i],nullptr,TRUE);}
 InvalidateRect(main_window,nullptr,TRUE);SetFocus(tab_buttons[page]);
}
static void load_agumon(HINSTANCE instance){
 Gdiplus::GdiplusStartupInput startup;if(Gdiplus::GdiplusStartup(&gdiplus_token,&startup,nullptr)!=Gdiplus::Ok)return;
 HRSRC resource=FindResourceW(instance,MAKEINTRESOURCEW(101),RT_RCDATA);if(!resource)return;
 DWORD bytes=SizeofResource(instance,resource);void* data=LockResource(LoadResource(instance,resource));if(!data||!bytes)return;
 HGLOBAL copy=GlobalAlloc(GMEM_MOVEABLE,bytes);if(!copy)return;void* target=GlobalLock(copy);if(!target){GlobalFree(copy);return;}memcpy(target,data,bytes);GlobalUnlock(copy);
 if(CreateStreamOnHGlobal(copy,TRUE,&agumon_stream)!=S_OK){GlobalFree(copy);return;}
 agumon=Gdiplus::Image::FromStream(agumon_stream);
 if(agumon->GetLastStatus()!=Gdiplus::Ok){delete agumon;agumon=nullptr;}
}
static void read_controls(){
 wchar_t path[LAUNCHER_PATH_MAX];GetWindowTextW(image_edit,path,LAUNCHER_PATH_MAX);auto p=utf8(path);strncpy_s(config.image_path,p.c_str(),_TRUNCATE);
 config.window_mode=int(SendMessageW(window_mode_choice,CB_GETCURSEL,0,0));
 config.window_resolution=int(SendMessageW(window_res_choice,CB_GETCURSEL,0,0));
 config.internal_resolution=int(SendMessageW(internal_res_choice,CB_GETCURSEL,0,0));
 config.aspect_ratio=int(SendMessageW(aspect_ratio_choice,CB_GETCURSEL,0,0));
 config.vsync=SendMessageW(vsync_check,BM_GETCHECK,0,0)==BST_CHECKED;
 config.keyboard_enabled=SendMessageW(keyboard_check,BM_GETCHECK,0,0)==BST_CHECKED;config.keyboard_port=int(SendMessageW(keyboard_port,CB_GETCURSEL,0,0));
 for(int i=0;i<4;i++){int selected=int(SendMessageW(ports[i],CB_GETCURSEL,0,0));if(selected>=0&&selected<int(choices.size()))strcpy_s(config.ports[i],choices[selected].c_str());}
}
static bool save(){read_controls();char error[256];auto path=path8(root/L"config/launcher_config.json");if(!launcher_config_save(path.c_str(),&config,error,sizeof(error))){message(wide(error));return false;}return true;}
static void refresh_devices(bool initial=false){
 if(!initial)read_controls();device_count=input_devices_list(devices);choices={"none","keyboard","auto"};for(int i=0;i<device_count;i++)choices.push_back(devices[i].id);
 for(int p=0;p<4;p++){
  if(strcmp(config.ports[p],"none")&&strcmp(config.ports[p],"keyboard")&&std::find(choices.begin(),choices.end(),config.ports[p])==choices.end())choices.push_back(config.ports[p]);
 }
 for(int p=0;p<4;p++){
  SendMessageW(ports[p],CB_RESETCONTENT,0,0);int selected=0;
  for(size_t i=0;i<choices.size();i++){
   std::wstring s=i==0?L"Nenhum (desconectado)":i==1?L"Teclado":i==2?L"Controle (automático)":i<size_t(device_count+3)?wide(devices[i-3].name):L"Controle desconectado (salvo)";
   SendMessageW(ports[p],CB_ADDSTRING,0,(LPARAM)s.c_str());if(choices[i]==config.ports[p])selected=int(i);
  }SendMessageW(ports[p],CB_SETCURSEL,selected,0);SendMessageW(ports[p],CB_SETDROPPEDWIDTH,px(360),0);
 }
}
static void normalize_assignment(int changed){
 read_controls();int selected=int(SendMessageW(ports[changed],CB_GETCURSEL,0,0));
 if(changed==config.keyboard_port&&selected!=1){config.keyboard_enabled=false;SendMessageW(keyboard_check,BM_SETCHECK,BST_UNCHECKED,0);}
 if(selected<=0||selected==2)return;
 for(int i=0;i<4;i++)if(i!=changed&&!strcmp(config.ports[i],config.ports[changed])){SendMessageW(ports[i],CB_SETCURSEL,0,0);strcpy_s(config.ports[i],"none");}
 if(selected==1){config.keyboard_port=changed;config.keyboard_enabled=true;SendMessageW(keyboard_port,CB_SETCURSEL,changed,0);SendMessageW(keyboard_check,BM_SETCHECK,BST_CHECKED,0);}
}
static void refresh_save(){auto p=path8(root/L"saves/MemoryCardA.card");bool exists=portable_exists(p.c_str());SetWindowTextW(status_label,exists?L"●  Slot A: save detectado em saves/MemoryCardA.card":L"○  Slot A: novo cartão portátil será criado ao iniciar o jogo");}
static void browse(){
 wchar_t path[LAUNCHER_PATH_MAX]={};GetWindowTextW(image_edit,path,LAUNCHER_PATH_MAX);
 OPENFILENAMEW o={sizeof(o)};o.hwndOwner=main_window;o.lpstrFilter=L"Imagens GameCube (*.iso;*.ciso;*.nkit.iso;*.rvz)\0*.iso;*.ciso;*.nkit.iso;*.rvz\0\0";o.lpstrFile=path;o.nMaxFile=LAUNCHER_PATH_MAX;o.Flags=OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_NOCHANGEDIR;o.lpstrTitle=L"Selecione seu dump original de Digimon Rumble Arena 2 (USA)";
 if(GetOpenFileNameW(&o)){auto path_utf8=utf8(path);char error[256];DiscImage* disc=disc_image_open(path_utf8.c_str(),error,sizeof(error));bool ok=disc&&disc_image_validate_game(disc,error,sizeof(error));disc_image_close(disc);if(!ok){message(wide(error));return;}SetWindowTextW(image_edit,path);save();}
}
/* Standard Windows command line quoting; filenames are never passed to a shell. */
static std::wstring quote(const std::wstring& s){std::wstring out=L"\"";size_t slash=0;for(wchar_t c:s){if(c==L'\\'){slash++;continue;}if(c==L'\"'){out.append(slash*2+1,L'\\');out+=c;}else{out.append(slash,L'\\');out+=c;}slash=0;}out.append(slash*2,L'\\');return out+L"\"";}
static void play(){
 if(game)return;if(!save())return;
 fs::path image=fs::path(std::u8string(reinterpret_cast<const char8_t*>(config.image_path)));if(image.is_relative())image=root/image;
 auto p=path8(image);char error[256];DiscImage* d=disc_image_open(p.c_str(),error,sizeof(error));bool ok=d&&disc_image_validate_game(d,error,sizeof(error));disc_image_close(d);if(!ok){message(wide(error));return;}
 if(!config.keyboard_enabled)for(int i=0;i<4;i++)if(!strcmp(config.ports[i],"keyboard"))strcpy_s(config.ports[i],"none");
 bool connected=false;for(int i=0;i<4;i++)connected|=strcmp(config.ports[i],"none")!=0;if(!connected){message(L"Selecione ao menos um controle, ou habilite o teclado.");return;}
 auto exe=root/L"digimon_test.exe";if(!fs::exists(exe)){message(L"digimon_test.exe não foi encontrado ao lado do launcher.");return;}
 auto cfg=path8(root/L"config");portable_mkdirs(cfg.c_str());
 auto log=root/L"config/runtime.log",old=root/L"config/runtime.previous.log";
 if(fs::exists(log)){std::error_code ec;fs::remove(old,ec);ec.clear();fs::rename(log,old,ec);}
 SECURITY_ATTRIBUTES sa={sizeof(sa),nullptr,TRUE};HANDLE output=CreateFileW(log.c_str(),GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,&sa,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr);HANDLE input=CreateFileW(L"NUL",GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,&sa,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
 if(output==INVALID_HANDLE_VALUE||input==INVALID_HANDLE_VALUE){if(output!=INVALID_HANDLE_VALUE)CloseHandle(output);if(input!=INVALID_HANDLE_VALUE)CloseHandle(input);message(L"Não foi possível abrir o log portátil em config/.");return;}
 std::wstring command=quote(exe.native())+L" --portable --disc "+quote(image.native());STARTUPINFOW si={sizeof(si)};si.dwFlags=STARTF_USESTDHANDLES;si.hStdOutput=si.hStdError=output;si.hStdInput=input;PROCESS_INFORMATION pi{};
 BOOL created=CreateProcessW(exe.c_str(),command.data(),nullptr,nullptr,TRUE,CREATE_NO_WINDOW,nullptr,root.c_str(),&si,&pi);DWORD failure=GetLastError();CloseHandle(output);CloseHandle(input);
 if(!created){message(L"Não foi possível iniciar o jogo. Erro Windows: "+std::to_wstring(failure));return;}
 CloseHandle(pi.hThread);game=pi.hProcess;EnableWindow(play_button,FALSE);SetWindowTextW(play_button,L"EM EXECUÇÃO");ShowWindow(main_window,SW_MINIMIZE);
}
static SDL_Scancode scancode(WPARAM vk,LPARAM flags){
 if(vk>='A'&&vk<='Z')return SDL_GetScancodeFromKey(SDLK_a+int(vk-'A'));if(vk>='0'&&vk<='9')return SDL_GetScancodeFromKey(SDLK_0+int(vk-'0'));
 if(vk>=VK_F1&&vk<=VK_F12)return SDL_Scancode(SDL_SCANCODE_F1+vk-VK_F1);if(vk>=VK_NUMPAD0&&vk<=VK_NUMPAD9)return SDL_Scancode(vk==VK_NUMPAD0?SDL_SCANCODE_KP_0:SDL_SCANCODE_KP_1+vk-VK_NUMPAD1);
 switch(vk){case VK_RETURN:return (flags&(1<<24))?SDL_SCANCODE_KP_ENTER:SDL_SCANCODE_RETURN;case VK_SPACE:return SDL_SCANCODE_SPACE;case VK_TAB:return SDL_SCANCODE_TAB;case VK_BACK:return SDL_SCANCODE_BACKSPACE;case VK_UP:return SDL_SCANCODE_UP;case VK_DOWN:return SDL_SCANCODE_DOWN;case VK_LEFT:return SDL_SCANCODE_LEFT;case VK_RIGHT:return SDL_SCANCODE_RIGHT;case VK_HOME:return SDL_SCANCODE_HOME;case VK_END:return SDL_SCANCODE_END;case VK_INSERT:return SDL_SCANCODE_INSERT;case VK_PRIOR:return SDL_SCANCODE_PAGEUP;case VK_NEXT:return SDL_SCANCODE_PAGEDOWN;case VK_SHIFT:return ((flags>>16)&0xff)==0x36?SDL_SCANCODE_RSHIFT:SDL_SCANCODE_LSHIFT;case VK_CONTROL:return (flags&(1<<24))?SDL_SCANCODE_RCTRL:SDL_SCANCODE_LCTRL;case VK_MENU:return (flags&(1<<24))?SDL_SCANCODE_RALT:SDL_SCANCODE_LALT;case VK_OEM_1:return SDL_SCANCODE_SEMICOLON;case VK_OEM_PLUS:return SDL_SCANCODE_EQUALS;case VK_OEM_COMMA:return SDL_SCANCODE_COMMA;case VK_OEM_MINUS:return SDL_SCANCODE_MINUS;case VK_OEM_PERIOD:return SDL_SCANCODE_PERIOD;case VK_OEM_2:return SDL_SCANCODE_SLASH;case VK_OEM_3:return SDL_SCANCODE_GRAVE;case VK_OEM_4:return SDL_SCANCODE_LEFTBRACKET;case VK_OEM_5:return SDL_SCANCODE_BACKSLASH;case VK_OEM_6:return SDL_SCANCODE_RIGHTBRACKET;case VK_OEM_7:return SDL_SCANCODE_APOSTROPHE;case VK_CAPITAL:return SDL_SCANCODE_CAPSLOCK;case VK_MULTIPLY:return SDL_SCANCODE_KP_MULTIPLY;case VK_ADD:return SDL_SCANCODE_KP_PLUS;case VK_SUBTRACT:return SDL_SCANCODE_KP_MINUS;case VK_DIVIDE:return SDL_SCANCODE_KP_DIVIDE;case VK_DECIMAL:return SDL_SCANCODE_KP_DECIMAL;default:return SDL_SCANCODE_UNKNOWN;}
}
static LRESULT CALLBACK procedure(HWND hwnd,UINT msg,WPARAM w,LPARAM l){
 switch(msg){
 case WM_CTLCOLORSTATIC:case WM_CTLCOLOREDIT:case WM_CTLCOLORLISTBOX:SetTextColor((HDC)w,text);SetBkColor((HDC)w,msg==WM_CTLCOLORSTATIC?bg:surface);return (LRESULT)(msg==WM_CTLCOLORSTATIC?background:panel);
 case WM_PAINT:{PAINTSTRUCT paint;HDC dc=BeginPaint(hwnd,&paint);if(active_page==3){Gdiplus::Graphics graphics(dc);if(agumon){graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);float fit=std::min(float(px(324))/agumon->GetWidth(),float(px(370))/agumon->GetHeight());float w=agumon->GetWidth()*fit,h=agumon->GetHeight()*fit;graphics.DrawImage(agumon,Gdiplus::RectF(float(px(638))+(px(324)-w)/2,float(px(210))+(px(370)-h)/2,w,h));}}EndPaint(hwnd,&paint);return 0;}
 case WM_ERASEBKGND:{RECT r;GetClientRect(hwnd,&r);FillRect((HDC)w,&r,background);return 1;}
 case WM_DRAWITEM:{auto* d=(DRAWITEMSTRUCT*)l;FillRect(d->hDC,&d->rcItem,background);COLORREF color=(d->CtlID==100||(d->CtlID>=500&&d->CtlID<504&&int(d->CtlID)-500==active_page))?blue:surface;HBRUSH b=CreateSolidBrush(color);HPEN pen=CreatePen(PS_SOLID,1,(d->itemState&ODS_FOCUS)?text:RGB(45,76,111));SelectObject(d->hDC,b);SelectObject(d->hDC,pen);RoundRect(d->hDC,d->rcItem.left,d->rcItem.top,d->rcItem.right,d->rcItem.bottom,px(8),px(8));wchar_t value[256];GetWindowTextW(d->hwndItem,value,256);SetBkMode(d->hDC,TRANSPARENT);SetTextColor(d->hDC,(d->itemState&ODS_DISABLED)?muted:text);SelectObject(d->hDC,font);RECT r=d->rcItem;DrawTextW(d->hDC,value,-1,&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS);SelectObject(d->hDC,GetStockObject(NULL_BRUSH));SelectObject(d->hDC,GetStockObject(NULL_PEN));DeleteObject(b);DeleteObject(pen);return TRUE;}
 case WM_COMMAND:{int id=LOWORD(w),notification=HIWORD(w);
  if(id>=500&&id<504)show_page(id-500);else if(id==400)ShellExecuteW(hwnd,L"open",L"https://github.com/gabrielmedeiros1337/digimonra2-recomp",nullptr,nullptr,SW_SHOWNORMAL);else if(id==100)play();else if(id==101)browse();else if(id==102)save();else if(id==103){auto p=path8(root/L"saves");portable_mkdirs(p.c_str());ShellExecuteW(hwnd,L"open",(root/L"saves").c_str(),nullptr,nullptr,SW_SHOWNORMAL);}else if(id==104){SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER|SDL_INIT_JOYSTICK);SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER|SDL_INIT_JOYSTICK);refresh_devices();}
  else if(id>=200&&id<204&&notification==CBN_SELCHANGE)normalize_assignment(id-200);
  else if(id==211&&notification==CBN_SELCHANGE){read_controls();for(int i=0;i<4;i++)if(!strcmp(config.ports[i],"keyboard"))SendMessageW(ports[i],CB_SETCURSEL,0,0);SendMessageW(ports[config.keyboard_port],CB_SETCURSEL,1,0);}
  else if(id>=300&&id<300+KEY_BIND_COUNT){capture=id-300;update_keys();SetFocus(hwnd);}
  return 0;
 }
 case WM_KEYDOWN:case WM_SYSKEYDOWN:if(capture>=0){if(w==VK_ESCAPE){capture=-1;update_keys();return 0;}SDL_Scancode key=w==VK_DELETE?SDL_SCANCODE_UNKNOWN:scancode(w,l);if(key||w==VK_DELETE){config.keys[capture]=key;capture=-1;update_keys();}return 0;}break;
 case WM_TIMER:{SDL_Event event;bool changed=false;while(SDL_PollEvent(&event))changed|=event.type==SDL_JOYDEVICEADDED||event.type==SDL_JOYDEVICEREMOVED;if(changed)refresh_devices();if(game&&WaitForSingleObject(game,0)==WAIT_OBJECT_0){DWORD code=0;GetExitCodeProcess(game,&code);CloseHandle(game);game=nullptr;EnableWindow(play_button,TRUE);SetWindowTextW(play_button,L"JOGAR");ShowWindow(hwnd,SW_RESTORE);if(code)message(L"O jogo encerrou com código "+std::to_wstring(code)+L". Consulte config/runtime.log.");}refresh_save();return 0;}
 case WM_CLOSE:if(!save())return 0;DestroyWindow(hwnd);return 0;
 case WM_DESTROY:PostQuitMessage(0);return 0;
 }return DefWindowProcW(hwnd,msg,w,l);
}
int WINAPI wWinMain(HINSTANCE instance,HINSTANCE,LPWSTR,int){
 SetProcessDPIAware();SDL_SetMainReady();if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER|SDL_INIT_EVENTS)!=0){MessageBoxA(nullptr,SDL_GetError(),"SDL",MB_ICONERROR);return 1;}
 char base[LAUNCHER_PATH_MAX];if(!portable_executable_root(base,sizeof(base)))return 1;root=fs::path(std::u8string(reinterpret_cast<const char8_t*>(base)));char error[256];auto cfg=path8(root/L"config/launcher_config.json");bool loaded=launcher_config_load(cfg.c_str(),&config,error,sizeof(error));
 background=CreateSolidBrush(bg);panel=CreateSolidBrush(surface);HDC screen=GetDC(nullptr);scale=GetDeviceCaps(screen,LOGPIXELSX);ReleaseDC(nullptr,screen);
 font=CreateFontW(-px(15),0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,0,0,CLEARTYPE_QUALITY,0,L"Segoe UI");heading=CreateFontW(-px(30),0,0,0,FW_BOLD,FALSE,FALSE,FALSE,DEFAULT_CHARSET,0,0,CLEARTYPE_QUALITY,0,L"Segoe UI");small_font=CreateFontW(-px(13),0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,0,0,CLEARTYPE_QUALITY,0,L"Segoe UI");
 WNDCLASSW wc{};wc.lpfnWndProc=procedure;wc.hInstance=instance;wc.hCursor=LoadCursor(nullptr,IDC_ARROW);wc.hIcon=LoadIcon(nullptr,IDI_APPLICATION);wc.lpszClassName=L"DigimonRA2Launcher";wc.hbrBackground=background;RegisterClassW(&wc);
 RECT r={0,0,px(1020),px(710)};DWORD style=WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX;AdjustWindowRect(&r,style,FALSE);main_window=CreateWindowW(wc.lpszClassName,L"Digimon Rumble Arena 2 • PC Launcher",style,CW_USEDEFAULT,CW_USEDEFAULT,r.right-r.left,r.bottom-r.top,nullptr,nullptr,instance,nullptr);
 HWND title=control(L"STATIC",L"DIGIMON RUMBLE ARENA 2",0,0,32,24,950,45);SendMessageW(title,WM_SETFONT,(WPARAM)heading,TRUE);label(L"PC NATIVE  /  Seus controles. Seu cartão. Sua arena.",34,74,900,24);
 const wchar_t* tabs[]={L"Jogar",L"Controles",L"Opções",L"Créditos"};
 for(int i=0;i<4;i++)tab_buttons[i]=button(tabs[i],500+i,34+i*240,116,228,42);
 building_page=0;
 label(L"SUA PRÓXIMA BATALHA COMEÇA AQUI",34,200,920,30);
 label(L"Selecione seu dump original de Digimon Rumble Arena 2 (USA).",34,247,920,24);
 image_edit=control(L"EDIT",wide(config.image_path).c_str(),ES_AUTOHSCROLL|WS_BORDER|WS_TABSTOP,110,34,288,746,38);
 button(L"Procurar...",101,794,288,190,38);
 label(L"ISO / CISO / NKit ISO / RVZ",34,345,920,24);
 label(L"Seu jogo original é necessário. O pacote não inclui dump nem assets do jogo.",34,380,920,24);
 play_button=button(L"JOGAR",100,34,448,300,64);
 status_label=control(L"STATIC",L"",0,0,34,555,920,24);
 button(L"Abrir pasta de saves",103,34,598,240,36);
 building_page=1;
 label(L"CONTROLES  ·  Uma porta por dispositivo",34,198,700,24);button(L"Atualizar",104,858,193,126,32);
 for(int i=0;i<4;i++){std::wstring name=L"JOGADOR "+std::to_wstring(i+1);label(name.c_str(),34+i*240,247,220,24);ports[i]=control(L"COMBOBOX",L"",CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,200+i,34+i*240,276,228,230);}
 keyboard_check=control(L"BUTTON",L"Habilitar controle por Teclado",BS_AUTOCHECKBOX|WS_TABSTOP,210,34,329,320,28);SendMessageW(keyboard_check,BM_SETCHECK,config.keyboard_enabled?BST_CHECKED:BST_UNCHECKED,0);
 label(L"Porta do teclado:",372,333,140,24);keyboard_port=control(L"COMBOBOX",L"",CBS_DROPDOWNLIST|WS_TABSTOP,211,510,327,140,150);for(int i=1;i<=4;i++){std::wstring name=L"Jogador "+std::to_wstring(i);SendMessageW(keyboard_port,CB_ADDSTRING,0,(LPARAM)name.c_str());}SendMessageW(keyboard_port,CB_SETCURSEL,config.keyboard_port,0);
 label(L"TECLAS  ·  Clique e pressione uma tecla. Esc cancela; Delete limpa.",34,383,950,24);
 for(int i=0;i<KEY_BIND_COUNT;i++)key_buttons[i]=button(L"",300+i,34+(i/5)*240,421+(i%5)*33,228,28);
 label(L"Teclado desabilitado = nenhum botão de teclado chega ao PAD. Esc fecha o jogo.",34,607,950,24);
 building_page=2;
 label(L"OPÇÕES DE APRESENTAÇÃO E VÍDEO",34,168,920,26);
 label(L"RESOLUÇÃO DA JANELA / TELA",34,196,920,18);
 window_res_choice=control(L"COMBOBOX",L"",CBS_DROPDOWNLIST|WS_TABSTOP,412,34,216,570,220);
 const wchar_t* win_resolutions[]={
     L"640x480 (Padrão GameCube 4:3)",
     L"1280x720 (HD 720p)",
     L"1366x768 (Notebook HD / 768p)",
     L"1600x900 (HD+ / 900p)",
     L"1920x1080 (Full HD 1080p)",
     L"2560x1440 (Quad HD 1440p)",
     L"3840x2160 (4K UHD)"
 };
 for(auto r:win_resolutions)SendMessageW(window_res_choice,CB_ADDSTRING,0,(LPARAM)r);
 SendMessageW(window_res_choice,CB_SETCURSEL,config.window_resolution>=0&&config.window_resolution<7?config.window_resolution:1,0);

 label(L"RESOLUÇÃO INTERNA 3D (EFB SCALE)",34,254,920,18);
 internal_res_choice=control(L"COMBOBOX",L"",CBS_DROPDOWNLIST|WS_TABSTOP,413,34,274,570,220);
 const wchar_t* internal_resolutions[]={
     L"1x Nativa (640x528 - Padrão GameCube)",
     L"1.5x (~720p / 768p Notebooks - 960x792)",
     L"2x (HD - 1280x1056)",
     L"3x (Full HD 1080p - 1920x1584)",
     L"4x (Quad HD 1440p - 2560x2112)"
 };
 for(auto r:internal_resolutions)SendMessageW(internal_res_choice,CB_ADDSTRING,0,(LPARAM)r);
 SendMessageW(internal_res_choice,CB_SETCURSEL,config.internal_resolution>=0&&config.internal_resolution<5?config.internal_resolution:0,0);

 label(L"PROPORÇÃO DE TELA (ASPECT RATIO)",34,312,920,18);
 aspect_ratio_choice=control(L"COMBOBOX",L"",CBS_DROPDOWNLIST|WS_TABSTOP,414,34,332,570,180);
 const wchar_t* aspect_ratios[]={
     L"4:3 (Padrão GameCube)",
     L"16:9 (Widescreen Real)"
 };
 for(auto ar:aspect_ratios)SendMessageW(aspect_ratio_choice,CB_ADDSTRING,0,(LPARAM)ar);
 SendMessageW(aspect_ratio_choice,CB_SETCURSEL,config.aspect_ratio==1?1:0,0);

 label(L"MODO DE JANELA / TELA",34,370,920,18);
 window_mode_choice=control(L"COMBOBOX",L"",CBS_DROPDOWNLIST|WS_TABSTOP,411,34,390,570,180);
 const wchar_t* modes[]={L"Janela (padrão)",L"Tela cheia sem bordas",L"Tela cheia exclusiva"};
 for(auto mode:modes)SendMessageW(window_mode_choice,CB_ADDSTRING,0,(LPARAM)mode);SendMessageW(window_mode_choice,CB_SETCURSEL,config.window_mode,0);

 label(L"Alt+Enter alterna entre janela e tela cheia mantendo o aspect ratio configurado.",34,432,950,20);
 vsync_check=control(L"BUTTON",L"Ativar VSync",BS_AUTOCHECKBOX|WS_TABSTOP,410,34,458,500,28);SendMessageW(vsync_check,BM_SETCHECK,config.vsync?BST_CHECKED:BST_UNCHECKED,0);
 label(L"VSync desligado por padrão. Renderização 3D em alta resolução 100% acelerada na GPU.",34,490,950,20);
 label(L"Efeitos visuais, HUD 2D e sombras preservados sem perda de 60 FPS.",34,514,950,20);
 building_page=3;
 label(L"OBRIGADO POR BAIXAR!",34,212,570,36);
 label(L"Que bom ter você de volta à arena.",34,264,570,28);
 label(L"Este port é construído com dedicação pela comunidade.",34,309,570,26);
 label(L"Código, novidades e contribuições no GitHub:",34,363,570,26);
 button(L"github.com/gabrielmedeiros1337/digimonra2-recomp",400,34,410,568,48);
 label(L"Criado por Gabriel Medeiros e colaboradores do projeto.",34,489,570,26);
 label(L"Um Agumon para acompanhar suas próximas batalhas!",34,534,570,26);
 label(L"Digimon pertence aos seus respectivos detentores.",34,588,920,24);
 building_page=-1;
 button(L"Salvar ajustes",102,794,661,190,34);
 label(L"DIGIMON RA2  /  PC NATIVO",34,666,650,24);
 load_agumon(instance);show_page(0);
 refresh_devices(true);update_keys();refresh_save();ShowWindow(main_window,SW_SHOW);SetTimer(main_window,1,400,nullptr);if(!loaded)message(wide(error));
 MSG m;while(GetMessageW(&m,nullptr,0,0)>0){if(capture>=0&&(m.message==WM_KEYDOWN||m.message==WM_SYSKEYDOWN)){procedure(main_window,m.message,m.wParam,m.lParam);continue;}if(!IsDialogMessageW(main_window,&m)){TranslateMessage(&m);DispatchMessageW(&m);}}
 if(game)CloseHandle(game);delete agumon;if(agumon_stream)agumon_stream->Release();if(gdiplus_token)Gdiplus::GdiplusShutdown(gdiplus_token);DeleteObject(font);DeleteObject(heading);DeleteObject(small_font);DeleteObject(background);DeleteObject(panel);SDL_Quit();return 0;
}
