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
#include <cmath>
#include "portable_config.h"
#include "disc_image.h"
extern "C" {
#include "input_devices.h"
}

namespace fs = std::filesystem;

// Localization strings table
struct LocStrings {
    const wchar_t* lang_btn;
    const wchar_t* window_title;
    const wchar_t* header_subtitle;
    const wchar_t* tabs[4];
    const wchar_t* card_game_image;
    const wchar_t* card_memory_card;
    const wchar_t* card_play;
    const wchar_t* card_ports;
    const wchar_t* card_keyboard;
    const wchar_t* card_video;
    const wchar_t* card_engine;
    const wchar_t* card_credits;
    const wchar_t* card_mascot;

    // Page 0
    const wchar_t* lbl_image_path;
    const wchar_t* btn_browse;
    const wchar_t* lbl_formats;
    const wchar_t* lbl_card_status;
    const wchar_t* btn_open_saves;
    const wchar_t* lbl_card_hint;
    const wchar_t* card_active;
    const wchar_t* card_new;
    const wchar_t* btn_play;
    const wchar_t* btn_running;
    const wchar_t* lbl_play_sub;

    // Page 1
    const wchar_t* lbl_controls_hint;
    const wchar_t* btn_refresh_devices;
    const wchar_t* port_name_fmt;
    const wchar_t* dev_none;
    const wchar_t* dev_keyboard;
    const wchar_t* dev_auto;
    const wchar_t* dev_saved_disconnected;
    const wchar_t* chk_keyboard_enable;
    const wchar_t* lbl_keyboard_port;
    const wchar_t* player_fmt;
    const wchar_t* lbl_bindings_hint;
    const wchar_t* press_key;
    const wchar_t* lbl_bindings_note;

    // Page 2
    const wchar_t* lbl_win_res;
    const wchar_t* win_res[7];
    const wchar_t* lbl_int_res;
    const wchar_t* int_res[5];
    const wchar_t* lbl_aspect_ratio;
    const wchar_t* aspect_ratios[2];
    const wchar_t* lbl_win_mode;
    const wchar_t* win_modes[3];
    const wchar_t* chk_vsync;
    const wchar_t* lbl_vsync_hint;
    const wchar_t* chk_unlock;
    const wchar_t* lbl_unlock_hint;
    const wchar_t* lbl_hotkey_hint;
    const wchar_t* lbl_widescreen_hint;
    const wchar_t* opt_bullets[3];
    const wchar_t* btn_save_options;

    // Page 3
    const wchar_t* cred_title;
    const wchar_t* cred_subtitle;
    const wchar_t* cred_role;
    const wchar_t* cred_author;
    const wchar_t* cred_bullets[4];
    const wchar_t* cred_copyright;
    const wchar_t* cred_disclaimer;

    // Bottom bar
    const wchar_t* btn_save_bottom;

    // Messages & Dialogs
    const wchar_t* msg_no_controller;
    const wchar_t* msg_no_exe;
    const wchar_t* msg_no_log;
    const wchar_t* msg_launch_error;
    const wchar_t* msg_exit_code;
    const wchar_t* dlg_browse_title;
    const wchar_t* dlg_browse_filter;
};

static const wchar_t filter_pt[] = L"Imagens GameCube (*.iso;*.ciso;*.nkit.iso;*.rvz)\0*.iso;*.ciso;*.nkit.iso;*.rvz\0";
static const wchar_t filter_en[] = L"GameCube Disc Images (*.iso;*.ciso;*.nkit.iso;*.rvz)\0*.iso;*.ciso;*.nkit.iso;*.rvz\0";

static const LocStrings strings_pt = {
    L"🌐 Idioma: PT-BR",
    L"Digimon Rumble Arena 2 • PC Launcher",
    L"PC Port · Recompilação Estática",
    { L"Jogar", L"Controles", L"Opções", L"Créditos" },
    L"IMAGEM DO DISCO (GAMECUBE USA)",
    L"MEMORY CARD (SLOT A)",
    L"INICIAR PARTIDA",
    L"MAPEAMENTO DE PORTAS PAD (CONTROLES)",
    L"CONFIGURAÇÃO DE TECLAS DO TECLADO",
    L"CONFIGURAÇÕES DE VÍDEO & APRESENTAÇÃO",
    L"MOTOR GRÁFICO & SISTEMA",
    L"CRÉDITOS & DESENVOLVIMENTO",
    L"MASCOTE",

    // Page 0
    L"Arquivo do Jogo (ISO / CISO / NKit / RVZ):",
    L"Procurar...",
    L"É necessário fornecer sua própria cópia original (USA). Nenhum asset ou ISO acompanha este pacote.",
    L"Status do Cartão de Memória:",
    L"Abrir pasta de saves",
    L"Armazenamento portátil localizado em saves/MemoryCardA.card (compatível e transferível)",
    L"●  [ATIVO] saves/MemoryCardA.card detectado (leitura e gravação prontas)",
    L"○  [NOVO] saves/MemoryCardA.card será inicializado ao iniciar o jogo",
    L"JOGAR",
    L"EM EXECUÇÃO",
    L"Aceleração gráfica OpenGL por hardware  ·  Taxa de quadros cravada em 60 FPS",

    // Page 1
    L"Selecione um controle físico para cada porta virtual do GameCube, ou configure o teclado.",
    L"Atualizar dispositivos",
    L"PORTA %d (JOGADOR %d)",
    L"Nenhum (desconectado)",
    L"Teclado",
    L"Controle (automático)",
    L"Controle desconectado (salvo)",
    L"Habilitar controle por Teclado",
    L"Porta atribuída ao teclado:",
    L"Jogador %d",
    L"Clique sobre uma ação e pressione a nova tecla. Pressione Esc para cancelar ou Delete para limpar.",
    L"Pressione uma tecla...",
    L"Quando o teclado estiver desabilitado, nenhum comando chega ao jogo. A tecla Esc encerra a partida.",

    // Page 2
    L"Resolução da Janela / Tela:",
    {
        L"640x480 (Padrão GameCube 4:3)",
        L"1280x720 (HD 720p)",
        L"1366x768 (Notebook HD / 768p)",
        L"1600x900 (HD+ / 900p)",
        L"1920x1080 (Full HD 1080p)",
        L"2560x1440 (Quad HD 1440p)",
        L"3840x2160 (4K UHD)"
    },
    L"Resolução Interna 3D (Escala EFB na GPU):",
    {
        L"1x Nativa (640x528 - Padrão GameCube)",
        L"1.5x (~720p / 768p Notebooks - 960x792)",
        L"2x (HD - 1280x1056)",
        L"3x (Full HD 1080p - 1920x1584)",
        L"4x (Quad HD 1440p - 2560x2112)"
    },
    L"Proporção de Tela (Aspect Ratio):",
    {
        L"4:3 (Padrão GameCube)",
        L"16:9 (Widescreen Real)"
    },
    L"Modo de Exibição:",
    {
        L"Janela (padrão)",
        L"Tela cheia sem bordas",
        L"Tela cheia exclusiva"
    },
    L"Ativar Sincronização Vertical (VSync)",
    L"VSync sincroniza a taxa de quadros com a taxa de atualização do monitor.",
    L"Desbloquear Tudo (Personagens e Fases)",
    L"Libera tudo; saves nesta sessão são temporários. Reinicie para aplicar.",
    L"Atalho: Alt + Enter alterna entre Janela e Tela Cheia em tempo real.",
    L"O modo 16:9 Widescreen Real expande a visão horizontal mantendo o HUD 1:1.",
    {
        L"• Renderização gráfica de precisão com pipeline GX convertido para shaders OpenGL modernos.",
        L"• Execução contínua a 60 FPS com sincronização de FIFO e decodificação assíncrona.",
        L"• Configurações salvas automaticamente no arquivo portátil config/launcher_config.json."
    },
    L"Salvar configurações",

    // Page 3
    L"DIGIMON RUMBLE ARENA 2 — PC PORT",
    L"Recompilação Estática & Execução Nativa",
    L"Desenvolvimento e Engenharia:",
    L"Gabriel Medeiros (gabrielmedeiros1337)",
    {
        L"• Recompilação estática dos 185 chunks PowerPC para código nativo x86/x64.",
        L"• Pipeline gráfico GX desacoplado em multithreading com backend OpenGL.",
        L"• Suporte nativo a 4 controles DirectInput/XInput e saves portáteis.",
        L"• Resolução interna EFB até 4K e modo 16:9 Widescreen Hor+."
    },
    L"Digimon Rumble Arena 2 © Bandai / Bandai Namco. Todos os direitos reservados.",
    L"Software independente sem fins comerciais voltado à preservação técnica.",

    // Bottom bar
    L"Salvar Ajustes",

    // Messages & Dialogs
    L"Selecione ao menos um controle físico ou habilite o teclado virtual.",
    L"digimon_test.exe não foi encontrado ao lado do launcher.",
    L"Não foi possível abrir o log em config/runtime.log.",
    L"Não foi possível iniciar o jogo. Erro Windows: ",
    L"O jogo encerrou com código %d. Consulte config/runtime.log.",
    L"Selecione o arquivo de disco do Digimon Rumble Arena 2 (USA)",
    filter_pt
};

static const LocStrings strings_en = {
    L"🌐 Language: EN",
    L"Digimon Rumble Arena 2 • PC Launcher",
    L"PC Port · Static Recompilation",
    { L"Play", L"Controls", L"Options", L"Credits" },
    L"DISC IMAGE (GAMECUBE USA)",
    L"MEMORY CARD (SLOT A)",
    L"START GAME",
    L"PAD PORT MAPPING (CONTROLLERS)",
    L"KEYBOARD KEY BINDINGS",
    L"VIDEO & PRESENTATION SETTINGS",
    L"GRAPHICS ENGINE & SYSTEM",
    L"CREDITS & DEVELOPMENT",
    L"MASCOT",

    // Page 0
    L"Game Disc Image (ISO / CISO / NKit / RVZ):",
    L"Browse...",
    L"A legally obtained original dump (USA) is required. No game assets or ISOs are included.",
    L"Memory Card Status:",
    L"Open saves folder",
    L"Portable storage located at saves/MemoryCardA.card (compatible and transferable)",
    L"●  [ACTIVE] saves/MemoryCardA.card detected (read and write ready)",
    L"○  [NEW] saves/MemoryCardA.card will be initialized on game launch",
    L"PLAY",
    L"RUNNING",
    L"Hardware-accelerated OpenGL graphics  ·  Frame rate locked at 60 FPS",

    // Page 1
    L"Select a physical controller for each virtual GameCube port, or configure the keyboard.",
    L"Refresh devices",
    L"PORT %d (PLAYER %d)",
    L"None (Disconnected)",
    L"Keyboard",
    L"Controller (Auto)",
    L"Disconnected controller (saved)",
    L"Enable Keyboard Input",
    L"Port assigned to keyboard:",
    L"Player %d",
    L"Click an action and press a new key. Press Esc to cancel or Delete to clear.",
    L"Press any key...",
    L"When keyboard is disabled, no keyboard input reaches the game. Press Esc in-game to exit.",

    // Page 2
    L"Window / Screen Resolution:",
    {
        L"640x480 (GameCube Standard 4:3)",
        L"1280x720 (HD 720p)",
        L"1366x768 (Laptop HD / 768p)",
        L"1600x900 (HD+ / 900p)",
        L"1920x1080 (Full HD 1080p)",
        L"2560x1440 (Quad HD 1440p)",
        L"3840x2160 (4K UHD)"
    },
    L"Internal 3D Resolution (GPU EFB Scale):",
    {
        L"1x Native (640x528 - GameCube Standard)",
        L"1.5x (~720p / 768p Laptops - 960x792)",
        L"2x (HD - 1280x1056)",
        L"3x (Full HD 1080p - 1920x1584)",
        L"4x (Quad HD 1440p - 2560x2112)"
    },
    L"Aspect Ratio:",
    {
        L"4:3 (GameCube Standard)",
        L"16:9 (Real Widescreen)"
    },
    L"Display Mode:",
    {
        L"Windowed (default)",
        L"Borderless Fullscreen",
        L"Exclusive Fullscreen"
    },
    L"Enable Vertical Sync (VSync)",
    L"VSync synchronizes frame rate with monitor refresh rate.",
    L"Unlock All (Characters & Stages)",
    L"Unlocks everything; saves in this session are temporary. Restart to apply.",
    L"Shortcut: Alt + Enter toggles between Windowed and Fullscreen in real time.",
    L"Real 16:9 Widescreen expands horizontal FOV while preserving 1:1 HUD.",
    {
        L"• Precision graphics rendering with GX pipeline converted to modern OpenGL shaders.",
        L"• Steady 60 FPS execution with FIFO synchronization and asynchronous decoding.",
        L"• Settings automatically saved to portable config/launcher_config.json."
    },
    L"Save settings",

    // Page 3
    L"DIGIMON RUMBLE ARENA 2 — PC PORT",
    L"Static Recompilation & Native Execution",
    L"Development & Engineering:",
    L"Gabriel Medeiros (gabrielmedeiros1337)",
    {
        L"• Static recompilation of 185 PowerPC chunks into native x86/x64 code.",
        L"• Decoupled multithreaded GX graphics pipeline with OpenGL backend.",
        L"• Native support for 4 DirectInput/XInput controllers and portable saves.",
        L"• Internal EFB resolution up to 4K and Hor+ 16:9 Real Widescreen mode."
    },
    L"Digimon Rumble Arena 2 © Bandai / Bandai Namco. All rights reserved.",
    L"Independent non-commercial software focused on technical preservation.",

    // Bottom bar
    L"Save Settings",

    // Messages & Dialogs
    L"Select at least one physical controller or enable the virtual keyboard.",
    L"digimon_test.exe was not found next to the launcher.",
    L"Could not open log in config/runtime.log.",
    L"Could not start the game. Windows Error: ",
    L"The game exited with code %d. See config/runtime.log.",
    L"Select Digimon Rumble Arena 2 (USA) disc image",
    filter_en
};

static LauncherConfig config;

static bool is_en() {
    return _stricmp(config.language, "en") == 0 || _stricmp(config.language, "en-US") == 0;
}

static const LocStrings& loc() {
    return is_en() ? strings_en : strings_pt;
}

static HWND main_window, image_edit, ports[4], keyboard_check, keyboard_port;
static HWND key_buttons[KEY_BIND_COUNT], status_label, play_button;
static HWND vsync_check, unlock_check, window_mode_choice, window_res_choice, internal_res_choice, aspect_ratio_choice;
static HWND author_label;
static std::vector<HWND> page_controls[4];
static int building_page = -1, active_page = 0;
static HWND tab_buttons[4];
static ULONG_PTR gdiplus_token;
static IStream* agumon_stream;
static Gdiplus::Image* agumon;
static void update_keys();
static void apply_language();

// Dynamic handles for localization updates
static HWND lang_button;
static HWND lbl_image_path, browse_button, lbl_formats, lbl_card_title, open_saves_button, lbl_card_hint, lbl_play_sub;
static HWND lbl_controls_hint, refresh_dev_button, lbl_port_titles[4], lbl_kb_port_title, lbl_bindings_hint, lbl_bindings_note;
static HWND lbl_win_res_title, lbl_int_res_title, lbl_aspect_title, lbl_win_mode_title;
static HWND lbl_vsync_hint, lbl_unlock_hint, lbl_hotkey_hint, lbl_widescreen_hint, lbl_opt_bullets[3], save_opt_button;
static HWND lbl_cred_title, lbl_cred_subtitle, lbl_cred_role, lbl_cred_bullets[4], lbl_cred_copyright, lbl_cred_disclaimer;
static HWND save_bottom_button;

static HFONT font, tab_font, play_font, heading_card, title_font, subtitle_font, small_font;
static HBRUSH background, card_brush, edit_brush;
static int scale = 96, capture = -1;
static InputDevice devices[INPUT_DEVICE_MAX];
static int device_count;
static std::vector<std::string> choices;
static fs::path root;
static HANDLE game = nullptr;

static constexpr COLORREF col_bg = RGB(7, 12, 22);
static constexpr COLORREF col_card = RGB(13, 22, 36);
static constexpr COLORREF col_card_border = RGB(0, 160, 220);
static constexpr COLORREF col_cyan = RGB(0, 216, 255);
static constexpr COLORREF col_text = RGB(220, 235, 252);
static constexpr COLORREF col_muted = RGB(135, 162, 192);
static constexpr COLORREF col_green = RGB(0, 230, 128);
static constexpr COLORREF col_amber = RGB(255, 190, 30);
static constexpr COLORREF col_gold = RGB(255, 215, 0);
static constexpr COLORREF col_orange = RGB(255, 140, 0);

static int px(int n) {
    return MulDiv(n, scale, 96);
}

static std::wstring wide(const char* p) {
    int n = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, p, -1, nullptr, 0);
    if (!n) return L"";
    std::wstring s(n, 0);
    MultiByteToWideChar(CP_UTF8, 0, p, -1, s.data(), n);
    s.resize(n - 1);
    return s;
}

static std::string utf8(const std::wstring& s) {
    int n = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), int(s.size()), nullptr, 0, nullptr, nullptr);
    std::string p(n, 0);
    WideCharToMultiByte(CP_UTF8, 0, s.c_str(), int(s.size()), p.data(), n, nullptr, nullptr);
    return p;
}

static std::string path8(const fs::path& p) {
    auto u = p.u8string();
    return std::string(reinterpret_cast<const char*>(u.data()), u.size());
}

static void message(const std::wstring& s) {
    MessageBoxW(main_window, s.c_str(), L"Digimon Rumble Arena 2", MB_OK | MB_ICONINFORMATION);
}

static HWND control(const wchar_t* cls, const wchar_t* label_text, int style, int id, int x, int y, int w, int h) {
    HWND c = CreateWindowExW(0, cls, label_text, WS_CHILD | WS_VISIBLE | style,
        px(x), px(y), px(w), px(h), main_window, (HMENU)(INT_PTR)id, GetModuleHandleW(nullptr), nullptr);
    SendMessageW(c, WM_SETFONT, (WPARAM)font, TRUE);
    if (building_page >= 0) page_controls[building_page].push_back(c);
    return c;
}

static HWND button(const wchar_t* label_text, int id, int x, int y, int w, int h) {
    return control(L"BUTTON", label_text, BS_OWNERDRAW | WS_TABSTOP, id, x, y, w, h);
}

static HWND label(const wchar_t* value, int x, int y, int w, int h, HFONT custom_font = nullptr, int extra_style = 0) {
    HWND c = control(L"STATIC", value, extra_style, 0, x, y, w, h);
    if (custom_font) SendMessageW(c, WM_SETFONT, (WPARAM)custom_font, TRUE);
    return c;
}

static void update_keys() {
    for (int i = 0; i < KEY_BIND_COUNT; i++) {
        std::wstring s = wide(launcher_key_names[i]) + L"   ·   " + wide(SDL_GetScancodeName((SDL_Scancode)config.keys[i]));
        if (!config.keys[i]) s = wide(launcher_key_names[i]) + L"   ·   —";
        if (capture == i) s = loc().press_key;
        SetWindowTextW(key_buttons[i], s.c_str());
    }
}

static void show_page(int page) {
    if (page < 0 || page > 3) return;
    capture = -1;
    update_keys();
    active_page = page;
    for (int i = 0; i < 4; i++) {
        for (HWND child : page_controls[i])
            ShowWindow(child, i == page ? SW_SHOW : SW_HIDE);
        InvalidateRect(tab_buttons[i], nullptr, TRUE);
    }
    InvalidateRect(main_window, nullptr, TRUE);
    SetFocus(tab_buttons[page]);
}

static void load_agumon(HINSTANCE instance) {
    Gdiplus::GdiplusStartupInput startup;
    if (Gdiplus::GdiplusStartup(&gdiplus_token, &startup, nullptr) != Gdiplus::Ok) return;
    HRSRC resource = FindResourceW(instance, MAKEINTRESOURCEW(101), RT_RCDATA);
    if (!resource) return;
    DWORD bytes = SizeofResource(instance, resource);
    void* data = LockResource(LoadResource(instance, resource));
    if (!data || !bytes) return;
    HGLOBAL copy = GlobalAlloc(GMEM_MOVEABLE, bytes);
    if (!copy) return;
    void* target = GlobalLock(copy);
    if (!target) { GlobalFree(copy); return; }
    memcpy(target, data, bytes);
    GlobalUnlock(copy);
    if (CreateStreamOnHGlobal(copy, TRUE, &agumon_stream) != S_OK) { GlobalFree(copy); return; }
    agumon = Gdiplus::Image::FromStream(agumon_stream);
    if (agumon->GetLastStatus() != Gdiplus::Ok) {
        delete agumon;
        agumon = nullptr;
    }
}

static void read_controls() {
    wchar_t path[LAUNCHER_PATH_MAX];
    GetWindowTextW(image_edit, path, LAUNCHER_PATH_MAX);
    auto p = utf8(path);
    strncpy_s(config.image_path, p.c_str(), _TRUNCATE);
    config.window_mode = int(SendMessageW(window_mode_choice, CB_GETCURSEL, 0, 0));
    config.window_resolution = int(SendMessageW(window_res_choice, CB_GETCURSEL, 0, 0));
    config.internal_resolution = int(SendMessageW(internal_res_choice, CB_GETCURSEL, 0, 0));
    config.aspect_ratio = int(SendMessageW(aspect_ratio_choice, CB_GETCURSEL, 0, 0));
    config.vsync = SendMessageW(vsync_check, BM_GETCHECK, 0, 0) == BST_CHECKED;
    config.unlock_all = SendMessageW(unlock_check, BM_GETCHECK, 0, 0) == BST_CHECKED;
    config.keyboard_enabled = SendMessageW(keyboard_check, BM_GETCHECK, 0, 0) == BST_CHECKED;
    config.keyboard_port = int(SendMessageW(keyboard_port, CB_GETCURSEL, 0, 0));
    for (int i = 0; i < 4; i++) {
        int selected = int(SendMessageW(ports[i], CB_GETCURSEL, 0, 0));
        if (selected >= 0 && selected < int(choices.size()))
            strcpy_s(config.ports[i], choices[selected].c_str());
    }
}

static bool save() {
    read_controls();
    char error[256];
    auto path = path8(root / L"config/launcher_config.json");
    if (!launcher_config_save(path.c_str(), &config, error, sizeof(error))) {
        message(wide(error));
        return false;
    }
    return true;
}

static void refresh_devices(bool initial = false) {
    if (!initial) read_controls();
    device_count = input_devices_list(devices);
    choices = { "none", "keyboard", "auto" };
    for (int i = 0; i < device_count; i++) choices.push_back(devices[i].id);
    for (int p = 0; p < 4; p++) {
        if (strcmp(config.ports[p], "none") && strcmp(config.ports[p], "keyboard") &&
            std::find(choices.begin(), choices.end(), config.ports[p]) == choices.end()) {
            choices.push_back(config.ports[p]);
        }
    }
    for (int p = 0; p < 4; p++) {
        SendMessageW(ports[p], CB_RESETCONTENT, 0, 0);
        int selected = 0;
        for (size_t i = 0; i < choices.size(); i++) {
            std::wstring s = i == 0 ? loc().dev_none :
                i == 1 ? loc().dev_keyboard :
                i == 2 ? loc().dev_auto :
                i < size_t(device_count + 3) ? wide(devices[i - 3].name) :
                loc().dev_saved_disconnected;
            SendMessageW(ports[p], CB_ADDSTRING, 0, (LPARAM)s.c_str());
            if (choices[i] == config.ports[p]) selected = int(i);
        }
        SendMessageW(ports[p], CB_SETCURSEL, selected, 0);
        SendMessageW(ports[p], CB_SETDROPPEDWIDTH, px(360), 0);
    }
}

static void normalize_assignment(int changed) {
    read_controls();
    int selected = int(SendMessageW(ports[changed], CB_GETCURSEL, 0, 0));
    if (changed == config.keyboard_port && selected != 1) {
        config.keyboard_enabled = false;
        SendMessageW(keyboard_check, BM_SETCHECK, BST_UNCHECKED, 0);
    }
    if (selected <= 0 || selected == 2) return;
    for (int i = 0; i < 4; i++) {
        if (i != changed && !strcmp(config.ports[i], config.ports[changed])) {
            SendMessageW(ports[i], CB_SETCURSEL, 0, 0);
            strcpy_s(config.ports[i], "none");
        }
    }
    if (selected == 1) {
        config.keyboard_port = changed;
        config.keyboard_enabled = true;
        SendMessageW(keyboard_port, CB_SETCURSEL, changed, 0);
        SendMessageW(keyboard_check, BM_SETCHECK, BST_CHECKED, 0);
    }
}

static void refresh_save() {
    auto p = path8(root / L"saves/MemoryCardA.card");
    bool exists = portable_exists(p.c_str());
    SetWindowTextW(status_label, exists ? loc().card_active : loc().card_new);
}

static void browse() {
    wchar_t path[LAUNCHER_PATH_MAX] = {};
    GetWindowTextW(image_edit, path, LAUNCHER_PATH_MAX);
    OPENFILENAMEW o = { sizeof(o) };
    o.hwndOwner = main_window;
    o.lpstrFilter = loc().dlg_browse_filter;
    o.lpstrFile = path;
    o.nMaxFile = LAUNCHER_PATH_MAX;
    o.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    o.lpstrTitle = loc().dlg_browse_title;
    if (GetOpenFileNameW(&o)) {
        auto path_utf8 = utf8(path);
        char error[256];
        DiscImage* disc = disc_image_open(path_utf8.c_str(), error, sizeof(error));
        bool ok = disc && disc_image_validate_game(disc, error, sizeof(error));
        disc_image_close(disc);
        if (!ok) {
            message(wide(error));
            return;
        }
        SetWindowTextW(image_edit, path);
        save();
    }
}

static std::wstring quote(const std::wstring& s) {
    std::wstring out = L"\"";
    size_t slash = 0;
    for (wchar_t c : s) {
        if (c == L'\\') {
            slash++;
            continue;
        }
        if (c == L'\"') {
            out.append(slash * 2 + 1, L'\\');
            out += c;
        } else {
            out.append(slash, L'\\');
            out += c;
        }
        slash = 0;
    }
    out.append(slash * 2, L'\\');
    return out + L"\"";
}

static void play() {
    if (game) return;
    if (!save()) return;
    fs::path image = fs::path(std::u8string(reinterpret_cast<const char8_t*>(config.image_path)));
    if (image.is_relative()) image = root / image;
    auto p = path8(image);
    char error[256];
    DiscImage* d = disc_image_open(p.c_str(), error, sizeof(error));
    bool ok = d && disc_image_validate_game(d, error, sizeof(error));
    disc_image_close(d);
    if (!ok) {
        message(wide(error));
        return;
    }
    if (!config.keyboard_enabled) {
        for (int i = 0; i < 4; i++) {
            if (!strcmp(config.ports[i], "keyboard")) strcpy_s(config.ports[i], "none");
        }
    }
    bool connected = false;
    for (int i = 0; i < 4; i++) connected |= strcmp(config.ports[i], "none") != 0;
    if (!connected) {
        message(loc().msg_no_controller);
        return;
    }
    auto exe = root / L"digimon_test.exe";
    if (!fs::exists(exe)) {
        message(loc().msg_no_exe);
        return;
    }
    auto cfg = path8(root / L"config");
    portable_mkdirs(cfg.c_str());
    auto log = root / L"config/runtime.log", old = root / L"config/runtime.previous.log";
    if (fs::exists(log)) {
        std::error_code ec;
        fs::remove(old, ec);
        ec.clear();
        fs::rename(log, old, ec);
    }
    SECURITY_ATTRIBUTES sa = { sizeof(sa), nullptr, TRUE };
    HANDLE output = CreateFileW(log.c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
        &sa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    HANDLE input = CreateFileW(L"NUL", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
        &sa, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (output == INVALID_HANDLE_VALUE || input == INVALID_HANDLE_VALUE) {
        if (output != INVALID_HANDLE_VALUE) CloseHandle(output);
        if (input != INVALID_HANDLE_VALUE) CloseHandle(input);
        message(loc().msg_no_log);
        return;
    }
    std::wstring command = quote(exe.native()) + L" --portable --disc " + quote(image.native());
    if (config.unlock_all) {
        command += L" --unlock-all";
    } else {
        command += L" --no-unlock-all";
    }
    STARTUPINFOW si = { sizeof(si) };
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdOutput = si.hStdError = output;
    si.hStdInput = input;
    PROCESS_INFORMATION pi{};
    BOOL created = CreateProcessW(exe.c_str(), command.data(), nullptr, nullptr, TRUE,
        CREATE_NO_WINDOW, nullptr, root.c_str(), &si, &pi);
    DWORD failure = GetLastError();
    CloseHandle(output);
    CloseHandle(input);
    if (!created) {
        message(std::wstring(loc().msg_launch_error) + std::to_wstring(failure));
        return;
    }
    CloseHandle(pi.hThread);
    game = pi.hProcess;
    EnableWindow(play_button, FALSE);
    SetWindowTextW(play_button, loc().btn_running);
    ShowWindow(main_window, SW_MINIMIZE);
}

static SDL_Scancode scancode(WPARAM vk, LPARAM flags) {
    if (vk >= 'A' && vk <= 'Z') return SDL_GetScancodeFromKey(SDLK_a + int(vk - 'A'));
    if (vk >= '0' && vk <= '9') return SDL_GetScancodeFromKey(SDLK_0 + int(vk - '0'));
    if (vk >= VK_F1 && vk <= VK_F12) return SDL_Scancode(SDL_SCANCODE_F1 + vk - VK_F1);
    if (vk >= VK_NUMPAD0 && vk <= VK_NUMPAD9) return SDL_Scancode(vk == VK_NUMPAD0 ? SDL_SCANCODE_KP_0 : SDL_SCANCODE_KP_1 + vk - VK_NUMPAD1);
    switch (vk) {
    case VK_RETURN: return (flags & (1 << 24)) ? SDL_SCANCODE_KP_ENTER : SDL_SCANCODE_RETURN;
    case VK_SPACE: return SDL_SCANCODE_SPACE;
    case VK_TAB: return SDL_SCANCODE_TAB;
    case VK_BACK: return SDL_SCANCODE_BACKSPACE;
    case VK_UP: return SDL_SCANCODE_UP;
    case VK_DOWN: return SDL_SCANCODE_DOWN;
    case VK_LEFT: return SDL_SCANCODE_LEFT;
    case VK_RIGHT: return SDL_SCANCODE_RIGHT;
    case VK_HOME: return SDL_SCANCODE_HOME;
    case VK_END: return SDL_SCANCODE_END;
    case VK_INSERT: return SDL_SCANCODE_INSERT;
    case VK_PRIOR: return SDL_SCANCODE_PAGEUP;
    case VK_NEXT: return SDL_SCANCODE_PAGEDOWN;
    case VK_SHIFT: return ((flags >> 16) & 0xff) == 0x36 ? SDL_SCANCODE_RSHIFT : SDL_SCANCODE_LSHIFT;
    case VK_CONTROL: return (flags & (1 << 24)) ? SDL_SCANCODE_RCTRL : SDL_SCANCODE_LCTRL;
    case VK_MENU: return (flags & (1 << 24)) ? SDL_SCANCODE_RALT : SDL_SCANCODE_LALT;
    case VK_OEM_1: return SDL_SCANCODE_SEMICOLON;
    case VK_OEM_PLUS: return SDL_SCANCODE_EQUALS;
    case VK_OEM_COMMA: return SDL_SCANCODE_COMMA;
    case VK_OEM_MINUS: return SDL_SCANCODE_MINUS;
    case VK_OEM_PERIOD: return SDL_SCANCODE_PERIOD;
    case VK_OEM_2: return SDL_SCANCODE_SLASH;
    case VK_OEM_3: return SDL_SCANCODE_GRAVE;
    case VK_OEM_4: return SDL_SCANCODE_LEFTBRACKET;
    case VK_OEM_5: return SDL_SCANCODE_BACKSLASH;
    case VK_OEM_6: return SDL_SCANCODE_RIGHTBRACKET;
    case VK_OEM_7: return SDL_SCANCODE_APOSTROPHE;
    case VK_CAPITAL: return SDL_SCANCODE_CAPSLOCK;
    case VK_MULTIPLY: return SDL_SCANCODE_KP_MULTIPLY;
    case VK_ADD: return SDL_SCANCODE_KP_PLUS;
    case VK_SUBTRACT: return SDL_SCANCODE_KP_MINUS;
    case VK_DIVIDE: return SDL_SCANCODE_KP_DIVIDE;
    case VK_DECIMAL: return SDL_SCANCODE_KP_DECIMAL;
    default: return SDL_SCANCODE_UNKNOWN;
    }
}

static void draw_cyber_grid(HDC dc, int width, int height) {
    HPEN hex_pen = CreatePen(PS_SOLID, 1, RGB(11, 20, 32));
    HPEN old_pen = (HPEN)SelectObject(dc, hex_pen);
    HBRUSH old_brush = (HBRUSH)SelectObject(dc, GetStockObject(NULL_BRUSH));

    int r = px(28);
    int dx = px(48);
    int dy = px(42);

    static const float cos_table[6] = { 0.8660254f, 0.0f, -0.8660254f, -0.8660254f, 0.0f, 0.8660254f };
    static const float sin_table[6] = { -0.5f, -1.0f, -0.5f, 0.5f, 1.0f, 0.5f };

    for (int y = -r; y < height + r; y += dy) {
        int row = (y + r) / dy;
        int x_offset = (row % 2) ? dx / 2 : 0;
        for (int x = -dx + x_offset; x < width + dx; x += dx) {
            POINT pts[7];
            for (int i = 0; i < 6; i++) {
                pts[i].x = x + (int)(r * cos_table[i]);
                pts[i].y = y + (int)(r * sin_table[i]);
            }
            pts[6] = pts[0];
            Polyline(dc, pts, 7);
        }
    }

    SelectObject(dc, old_pen);
    SelectObject(dc, old_brush);
    DeleteObject(hex_pen);
}

static void draw_chamfer_card(HDC dc, int x, int y, int w, int h, int c, COLORREF fill, COLORREF border, const wchar_t* title = nullptr) {
    POINT pts[8] = {
        { x + c, y },
        { x + w - c, y },
        { x + w, y + c },
        { x + w, y + h - c },
        { x + w - c, y + h },
        { x + c, y + h },
        { x, y + h - c },
        { x, y + c }
    };
    HBRUSH brush = CreateSolidBrush(fill);
    HPEN pen = CreatePen(PS_SOLID, 1, border);
    HBRUSH old_brush = (HBRUSH)SelectObject(dc, brush);
    HPEN old_pen = (HPEN)SelectObject(dc, pen);

    Polygon(dc, pts, 8);

    // Decorative Digivice tech corners
    HPEN accent_pen = CreatePen(PS_SOLID, 2, col_cyan);
    SelectObject(dc, accent_pen);
    MoveToEx(dc, x + c + px(4), y, nullptr);
    LineTo(dc, x + c, y);
    LineTo(dc, x, y + c);
    LineTo(dc, x, y + c + px(4));

    MoveToEx(dc, x + w - c - px(4), y + h, nullptr);
    LineTo(dc, x + w - c, y + h);
    LineTo(dc, x + w, y + h - c);
    LineTo(dc, x + w, y + h - c - px(4));

    if (title && wcslen(title) > 0) {
        SelectObject(dc, heading_card);
        SetBkMode(dc, TRANSPARENT);
        SetTextColor(dc, col_cyan);
        RECT tr = { x + c + px(8), y + px(8), x + w - c, y + px(28) };
        DrawTextW(dc, title, -1, &tr, DT_LEFT | DT_TOP | DT_SINGLELINE);

        HPEN div_pen = CreatePen(PS_SOLID, 1, RGB(22, 45, 70));
        SelectObject(dc, div_pen);
        MoveToEx(dc, x + c + px(8), y + px(30), nullptr);
        LineTo(dc, x + w - c - px(8), y + px(30));
        DeleteObject(div_pen);
    }

    SelectObject(dc, old_pen);
    SelectObject(dc, old_brush);
    DeleteObject(pen);
    DeleteObject(brush);
    DeleteObject(accent_pen);
}

static void draw_header(HDC dc, int width) {
    SelectObject(dc, title_font);
    SetBkMode(dc, TRANSPARENT);
    // Title shadow
    SetTextColor(dc, RGB(4, 7, 12));
    RECT tr_sh = { px(36), px(20), px(700), px(58) };
    DrawTextW(dc, L"DIGIMON RUMBLE ARENA 2", -1, &tr_sh, DT_LEFT | DT_TOP | DT_SINGLELINE);
    // Title
    SetTextColor(dc, RGB(255, 255, 255));
    RECT tr = { px(34), px(18), px(700), px(56) };
    DrawTextW(dc, L"DIGIMON RUMBLE ARENA 2", -1, &tr, DT_LEFT | DT_TOP | DT_SINGLELINE);

    // Subtitle (localized)
    SelectObject(dc, subtitle_font);
    SetTextColor(dc, col_cyan);
    RECT sub_tr = { px(36), px(58), px(700), px(82) };
    DrawTextW(dc, loc().header_subtitle, -1, &sub_tr, DT_LEFT | DT_TOP | DT_SINGLELINE);

    // Horizontal cyber divider
    HPEN line_pen = CreatePen(PS_SOLID, 2, col_cyan);
    SelectObject(dc, line_pen);
    MoveToEx(dc, px(34), px(94), nullptr);
    LineTo(dc, px(986), px(94));
    DeleteObject(line_pen);

    HPEN line_dark = CreatePen(PS_SOLID, 1, RGB(12, 38, 58));
    SelectObject(dc, line_dark);
    MoveToEx(dc, px(34), px(97), nullptr);
    LineTo(dc, px(986), px(97));
    DeleteObject(line_dark);
}

static void draw_page_cards(HDC dc) {
    const auto& l = loc();
    if (active_page == 0) {
        draw_chamfer_card(dc, px(34), px(162), px(952), px(136), px(8), col_card, col_card_border, l.card_game_image);
        draw_chamfer_card(dc, px(34), px(312), px(952), px(126), px(8), col_card, col_card_border, l.card_memory_card);
        draw_chamfer_card(dc, px(34), px(452), px(952), px(174), px(8), col_card, RGB(26, 48, 74), l.card_play);
    } else if (active_page == 1) {
        draw_chamfer_card(dc, px(34), px(162), px(952), px(178), px(8), col_card, col_card_border, l.card_ports);
        draw_chamfer_card(dc, px(34), px(354), px(952), px(272), px(8), col_card, col_card_border, l.card_keyboard);
    } else if (active_page == 2) {
        draw_chamfer_card(dc, px(34), px(162), px(952), px(280), px(8), col_card, col_card_border, l.card_video);
        draw_chamfer_card(dc, px(34), px(456), px(952), px(170), px(8), col_card, col_card_border, l.card_engine);
    } else if (active_page == 3) {
        draw_chamfer_card(dc, px(34), px(162), px(580), px(464), px(8), col_card, col_card_border, l.card_credits);
        draw_chamfer_card(dc, px(634), px(162), px(352), px(464), px(8), col_card, col_card_border, l.card_mascot);
    }
}

static void draw_chamfer_button(DRAWITEMSTRUCT* d) {
    int id = d->CtlID;
    bool is_play = (id == 100);
    bool is_lang = (id == 600);
    bool is_tab = (id >= 500 && id < 504);
    bool is_active_tab = is_tab && (id - 500 == active_page);
    bool is_disabled = (d->itemState & ODS_DISABLED) != 0;
    bool is_pressed = (d->itemState & ODS_SELECTED) != 0;
    bool is_focus = (d->itemState & ODS_FOCUS) != 0;

    RECT r = d->rcItem;
    int w = r.right - r.left;
    int h = r.bottom - r.top;
    int x = r.left;
    int y = r.top;
    int c = is_play ? px(8) : is_tab ? px(6) : px(5);

    POINT pts[8] = {
        { x + c, y },
        { x + w - c, y },
        { x + w, y + c },
        { x + w, y + h - c },
        { x + w - c, y + h },
        { x + c, y + h },
        { x, y + h - c },
        { x, y + c }
    };

    COLORREF fill, border, text_clr;
    HFONT use_font = font;

    if (is_play) {
        use_font = play_font;
        if (is_disabled) {
            fill = RGB(36, 44, 56);
            border = RGB(55, 68, 85);
            text_clr = RGB(130, 145, 165);
        } else if (is_pressed) {
            fill = RGB(220, 110, 0);
            border = col_gold;
            text_clr = RGB(10, 15, 24);
        } else {
            fill = col_orange;
            border = is_focus ? col_cyan : col_gold;
            text_clr = RGB(10, 15, 24);
        }
    } else if (is_lang) {
        use_font = subtitle_font;
        fill = is_pressed ? RGB(20, 48, 76) : RGB(10, 24, 40);
        border = is_focus ? col_cyan : RGB(0, 180, 240);
        text_clr = col_cyan;
    } else if (is_active_tab) {
        use_font = tab_font;
        fill = col_orange;
        border = col_gold;
        text_clr = RGB(10, 15, 24);
    } else if (is_tab) {
        use_font = tab_font;
        fill = is_pressed ? RGB(20, 36, 56) : RGB(14, 25, 40);
        border = is_focus ? col_cyan : RGB(28, 56, 84);
        text_clr = RGB(175, 205, 235);
    } else if (id >= 300 && id < 300 + KEY_BIND_COUNT) {
        use_font = small_font;
        int key_idx = id - 300;
        if (capture == key_idx) {
            fill = RGB(24, 52, 80);
            border = col_cyan;
            text_clr = col_cyan;
        } else if (config.keys[key_idx]) {
            fill = is_pressed ? RGB(24, 46, 72) : RGB(16, 28, 44);
            border = is_focus ? col_cyan : RGB(30, 60, 92);
            text_clr = col_text;
        } else {
            fill = RGB(12, 20, 32);
            border = RGB(22, 40, 60);
            text_clr = col_muted;
        }
    } else {
        fill = is_pressed ? RGB(24, 46, 72) : RGB(16, 30, 48);
        border = is_focus ? col_cyan : RGB(0, 160, 224);
        text_clr = is_disabled ? col_muted : RGB(225, 242, 255);
    }

    HBRUSH brush = CreateSolidBrush(fill);
    HPEN pen = CreatePen(PS_SOLID, (is_play || is_active_tab) ? 2 : 1, border);
    HBRUSH old_brush = (HBRUSH)SelectObject(d->hDC, brush);
    HPEN old_pen = (HPEN)SelectObject(d->hDC, pen);

    Polygon(d->hDC, pts, 8);

    if (is_play && !is_disabled) {
        HPEN hl_pen = CreatePen(PS_SOLID, 1, RGB(255, 220, 120));
        SelectObject(d->hDC, hl_pen);
        MoveToEx(d->hDC, x + c + px(2), y + px(2), nullptr);
        LineTo(d->hDC, x + w - c - px(2), y + px(2));
        DeleteObject(hl_pen);
    }

    wchar_t label_buf[256];
    GetWindowTextW(d->hwndItem, label_buf, 256);
    SetBkMode(d->hDC, TRANSPARENT);
    SetTextColor(d->hDC, text_clr);
    SelectObject(d->hDC, use_font);
    RECT tr = d->rcItem;
    DrawTextW(d->hDC, label_buf, -1, &tr, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);

    SelectObject(d->hDC, old_pen);
    SelectObject(d->hDC, old_brush);
    DeleteObject(pen);
    DeleteObject(brush);
}

static void apply_language() {
    const auto& l = loc();
    SetWindowTextW(main_window, l.window_title);
    SetWindowTextW(lang_button, l.lang_btn);
    for (int i = 0; i < 4; i++) {
        SetWindowTextW(tab_buttons[i], l.tabs[i]);
    }

    // Page 0
    SetWindowTextW(lbl_image_path, l.lbl_image_path);
    SetWindowTextW(browse_button, l.btn_browse);
    SetWindowTextW(lbl_formats, l.lbl_formats);
    SetWindowTextW(lbl_card_title, l.lbl_card_status);
    SetWindowTextW(open_saves_button, l.btn_open_saves);
    SetWindowTextW(lbl_card_hint, l.lbl_card_hint);
    if (!game) SetWindowTextW(play_button, l.btn_play);
    else SetWindowTextW(play_button, l.btn_running);
    SetWindowTextW(lbl_play_sub, l.lbl_play_sub);
    refresh_save();

    // Page 1
    SetWindowTextW(lbl_controls_hint, l.lbl_controls_hint);
    SetWindowTextW(refresh_dev_button, l.btn_refresh_devices);
    for (int i = 0; i < 4; i++) {
        wchar_t buf[64];
        swprintf_s(buf, l.port_name_fmt, i + 1, i + 1);
        SetWindowTextW(lbl_port_titles[i], buf);
    }
    SetWindowTextW(keyboard_check, l.chk_keyboard_enable);
    SetWindowTextW(lbl_kb_port_title, l.lbl_keyboard_port);
    int cur_kp = int(SendMessageW(keyboard_port, CB_GETCURSEL, 0, 0));
    SendMessageW(keyboard_port, CB_RESETCONTENT, 0, 0);
    for (int i = 1; i <= 4; i++) {
        wchar_t buf[32];
        swprintf_s(buf, l.player_fmt, i);
        SendMessageW(keyboard_port, CB_ADDSTRING, 0, (LPARAM)buf);
    }
    SendMessageW(keyboard_port, CB_SETCURSEL, cur_kp >= 0 ? cur_kp : config.keyboard_port, 0);
    SetWindowTextW(lbl_bindings_hint, l.lbl_bindings_hint);
    update_keys();
    SetWindowTextW(lbl_bindings_note, l.lbl_bindings_note);
    refresh_devices();

    // Page 2
    SetWindowTextW(lbl_win_res_title, l.lbl_win_res);
    int cur_win_res = int(SendMessageW(window_res_choice, CB_GETCURSEL, 0, 0));
    SendMessageW(window_res_choice, CB_RESETCONTENT, 0, 0);
    for (auto str : l.win_res) SendMessageW(window_res_choice, CB_ADDSTRING, 0, (LPARAM)str);
    SendMessageW(window_res_choice, CB_SETCURSEL, cur_win_res >= 0 ? cur_win_res : config.window_resolution, 0);

    SetWindowTextW(lbl_int_res_title, l.lbl_int_res);
    int cur_int_res = int(SendMessageW(internal_res_choice, CB_GETCURSEL, 0, 0));
    SendMessageW(internal_res_choice, CB_RESETCONTENT, 0, 0);
    for (auto str : l.int_res) SendMessageW(internal_res_choice, CB_ADDSTRING, 0, (LPARAM)str);
    SendMessageW(internal_res_choice, CB_SETCURSEL, cur_int_res >= 0 ? cur_int_res : config.internal_resolution, 0);

    SetWindowTextW(lbl_aspect_title, l.lbl_aspect_ratio);
    int cur_aspect = int(SendMessageW(aspect_ratio_choice, CB_GETCURSEL, 0, 0));
    SendMessageW(aspect_ratio_choice, CB_RESETCONTENT, 0, 0);
    for (auto str : l.aspect_ratios) SendMessageW(aspect_ratio_choice, CB_ADDSTRING, 0, (LPARAM)str);
    SendMessageW(aspect_ratio_choice, CB_SETCURSEL, cur_aspect >= 0 ? cur_aspect : config.aspect_ratio, 0);

    SetWindowTextW(lbl_win_mode_title, l.lbl_win_mode);
    int cur_win_mode = int(SendMessageW(window_mode_choice, CB_GETCURSEL, 0, 0));
    SendMessageW(window_mode_choice, CB_RESETCONTENT, 0, 0);
    for (auto str : l.win_modes) SendMessageW(window_mode_choice, CB_ADDSTRING, 0, (LPARAM)str);
    SendMessageW(window_mode_choice, CB_SETCURSEL, cur_win_mode >= 0 ? cur_win_mode : config.window_mode, 0);

    SetWindowTextW(vsync_check, l.chk_vsync);
    SetWindowTextW(lbl_vsync_hint, l.lbl_vsync_hint);
    SetWindowTextW(unlock_check, l.chk_unlock);
    SetWindowTextW(lbl_unlock_hint, l.lbl_unlock_hint);
    SetWindowTextW(lbl_hotkey_hint, l.lbl_hotkey_hint);
    SetWindowTextW(lbl_widescreen_hint, l.lbl_widescreen_hint);
    for (int i = 0; i < 3; i++) SetWindowTextW(lbl_opt_bullets[i], l.opt_bullets[i]);
    SetWindowTextW(save_opt_button, l.btn_save_options);

    // Page 3
    SetWindowTextW(lbl_cred_title, l.cred_title);
    SetWindowTextW(lbl_cred_subtitle, l.cred_subtitle);
    SetWindowTextW(lbl_cred_role, l.cred_role);
    SetWindowTextW(author_label, l.cred_author);
    for (int i = 0; i < 4; i++) SetWindowTextW(lbl_cred_bullets[i], l.cred_bullets[i]);
    SetWindowTextW(lbl_cred_copyright, l.cred_copyright);
    SetWindowTextW(lbl_cred_disclaimer, l.cred_disclaimer);

    // Bottom
    SetWindowTextW(save_bottom_button, l.btn_save_bottom);

    InvalidateRect(main_window, nullptr, TRUE);
}

static LRESULT CALLBACK procedure(HWND hwnd, UINT msg, WPARAM w, LPARAM l) {
    switch (msg) {
    case WM_CTLCOLORSTATIC: {
        HWND c = (HWND)l;
        if (c == status_label) {
            auto p = path8(root / L"saves/MemoryCardA.card");
            bool exists = portable_exists(p.c_str());
            SetTextColor((HDC)w, exists ? col_green : col_amber);
            SetBkColor((HDC)w, col_card);
            return (LRESULT)card_brush;
        }
        if (c == author_label) {
            SetTextColor((HDC)w, col_cyan);
            SetBkColor((HDC)w, col_card);
            return (LRESULT)card_brush;
        }
        SetTextColor((HDC)w, col_text);
        SetBkColor((HDC)w, col_card);
        return (LRESULT)card_brush;
    }
    case WM_CTLCOLOREDIT:
        SetTextColor((HDC)w, RGB(240, 248, 255));
        SetBkColor((HDC)w, RGB(9, 16, 26));
        return (LRESULT)edit_brush;
    case WM_CTLCOLORLISTBOX:
        SetTextColor((HDC)w, RGB(230, 242, 255));
        SetBkColor((HDC)w, col_card);
        return (LRESULT)card_brush;
    case WM_ERASEBKGND:
        return 1;
    case WM_PAINT: {
        PAINTSTRUCT paint;
        HDC hdc = BeginPaint(hwnd, &paint);
        RECT r;
        GetClientRect(hwnd, &r);
        int width = r.right - r.left;
        int height = r.bottom - r.top;

        HDC mem_dc = CreateCompatibleDC(hdc);
        HBITMAP mem_bmp = CreateCompatibleBitmap(hdc, width, height);
        HBITMAP old_bmp = (HBITMAP)SelectObject(mem_dc, mem_bmp);

        FillRect(mem_dc, &r, background);
        draw_cyber_grid(mem_dc, width, height);
        draw_header(mem_dc, width);
        draw_page_cards(mem_dc);

        if (active_page == 3 && agumon) {
            Gdiplus::Graphics graphics(mem_dc);
            graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
            float box_x = (float)px(650);
            float box_y = (float)px(204);
            float box_w = (float)px(320);
            float box_h = (float)px(404);
            float fit = std::min(box_w / agumon->GetWidth(), box_h / agumon->GetHeight());
            float img_w = agumon->GetWidth() * fit;
            float img_h = agumon->GetHeight() * fit;
            float img_x = box_x + (box_w - img_w) / 2.0f;
            float img_y = box_y + (box_h - img_h) / 2.0f;
            graphics.DrawImage(agumon, Gdiplus::RectF(img_x, img_y, img_w, img_h));
        }

        BitBlt(hdc, 0, 0, width, height, mem_dc, 0, 0, SRCCOPY);

        SelectObject(mem_dc, old_bmp);
        DeleteObject(mem_bmp);
        DeleteDC(mem_dc);
        EndPaint(hwnd, &paint);
        return 0;
    }
    case WM_DRAWITEM:
        draw_chamfer_button((DRAWITEMSTRUCT*)l);
        return TRUE;
    case WM_COMMAND: {
        int id = LOWORD(w), notification = HIWORD(w);
        if (id >= 500 && id < 504) show_page(id - 500);
        else if (id == 600) {
            if (is_en()) {
                strcpy_s(config.language, "pt-BR");
            } else {
                strcpy_s(config.language, "en");
            }
            save();
            apply_language();
        }
        else if (id == 400) ShellExecuteW(hwnd, L"open", L"https://github.com/gabrielmedeiros1337/digimonra2-recomp", nullptr, nullptr, SW_SHOWNORMAL);
        else if (id == 100) play();
        else if (id == 101) browse();
        else if (id == 102) save();
        else if (id == 103) {
            auto p = path8(root / L"saves");
            portable_mkdirs(p.c_str());
            ShellExecuteW(hwnd, L"open", (root / L"saves").c_str(), nullptr, nullptr, SW_SHOWNORMAL);
        } else if (id == 104) {
            SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK);
            SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK);
            refresh_devices();
        } else if (id >= 200 && id < 204 && notification == CBN_SELCHANGE) {
            normalize_assignment(id - 200);
        } else if (id == 211 && notification == CBN_SELCHANGE) {
            read_controls();
            for (int i = 0; i < 4; i++) {
                if (!strcmp(config.ports[i], "keyboard"))
                    SendMessageW(ports[i], CB_SETCURSEL, 0, 0);
            }
            SendMessageW(ports[config.keyboard_port], CB_SETCURSEL, 1, 0);
        } else if (id >= 300 && id < 300 + KEY_BIND_COUNT) {
            capture = id - 300;
            update_keys();
            SetFocus(hwnd);
        }
        return 0;
    }
    case WM_KEYDOWN: case WM_SYSKEYDOWN:
        if (capture >= 0) {
            if (w == VK_ESCAPE) {
                capture = -1;
                update_keys();
                return 0;
            }
            SDL_Scancode key = (w == VK_DELETE) ? SDL_SCANCODE_UNKNOWN : scancode(w, l);
            if (key || w == VK_DELETE) {
                config.keys[capture] = key;
                capture = -1;
                update_keys();
            }
            return 0;
        }
        break;
    case WM_TIMER: {
        SDL_Event event;
        bool changed = false;
        while (SDL_PollEvent(&event))
            changed |= (event.type == SDL_JOYDEVICEADDED || event.type == SDL_JOYDEVICEREMOVED);
        if (changed) refresh_devices();
        if (game && WaitForSingleObject(game, 0) == WAIT_OBJECT_0) {
            DWORD code = 0;
            GetExitCodeProcess(game, &code);
            CloseHandle(game);
            game = nullptr;
            EnableWindow(play_button, TRUE);
            SetWindowTextW(play_button, loc().btn_play);
            ShowWindow(hwnd, SW_RESTORE);
            if (code) {
                wchar_t buf[256];
                swprintf_s(buf, loc().msg_exit_code, code);
                message(buf);
            }
        }
        refresh_save();
        return 0;
    }
    case WM_CLOSE:
        if (!save()) return 0;
        DestroyWindow(hwnd);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, w, l);
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE, LPWSTR, int) {
    SetProcessDPIAware();
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0) {
        MessageBoxA(nullptr, SDL_GetError(), "SDL", MB_ICONERROR);
        return 1;
    }
    char base[LAUNCHER_PATH_MAX];
    if (!portable_executable_root(base, sizeof(base))) return 1;
    root = fs::path(std::u8string(reinterpret_cast<const char8_t*>(base)));
    char error[256];
    auto cfg = path8(root / L"config/launcher_config.json");
    bool loaded = launcher_config_load(cfg.c_str(), &config, error, sizeof(error));

    HDC screen = GetDC(nullptr);
    scale = GetDeviceCaps(screen, LOGPIXELSX);
    ReleaseDC(nullptr, screen);

    background = CreateSolidBrush(col_bg);
    card_brush = CreateSolidBrush(col_card);
    edit_brush = CreateSolidBrush(RGB(9, 16, 26));

    font = CreateFontW(-px(14), 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, L"Segoe UI");
    tab_font = CreateFontW(-px(15), 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, L"Segoe UI");
    play_font = CreateFontW(-px(24), 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, L"Segoe UI");
    heading_card = CreateFontW(-px(14), 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, L"Segoe UI");
    title_font = CreateFontW(-px(30), 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, L"Segoe UI");
    subtitle_font = CreateFontW(-px(14), 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, L"Segoe UI");
    small_font = CreateFontW(-px(12), 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 0, 0, CLEARTYPE_QUALITY, 0, L"Segoe UI");

    HICON app_icon = LoadIconW(instance, MAKEINTRESOURCEW(1));
    if (!app_icon) app_icon = LoadIconW(nullptr, IDI_APPLICATION);
    HICON app_icon_sm = (HICON)LoadImageW(instance, MAKEINTRESOURCEW(1), IMAGE_ICON,
        GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
    if (!app_icon_sm) app_icon_sm = app_icon;

    WNDCLASSEXW wc{};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = procedure;
    wc.hInstance = instance;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hIcon = app_icon;
    wc.hIconSm = app_icon_sm;
    wc.lpszClassName = L"DigimonRA2Launcher";
    wc.hbrBackground = background;
    RegisterClassExW(&wc);

    RECT r = { 0, 0, px(1020), px(710) };
    DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
    AdjustWindowRect(&r, style, FALSE);
    main_window = CreateWindowW(wc.lpszClassName, loc().window_title,
        style, CW_USEDEFAULT, CW_USEDEFAULT, r.right - r.left, r.bottom - r.top, nullptr, nullptr, instance, nullptr);

    if (app_icon) SendMessageW(main_window, WM_SETICON, ICON_BIG, (LPARAM)app_icon);
    if (app_icon_sm) SendMessageW(main_window, WM_SETICON, ICON_SMALL, (LPARAM)app_icon_sm);

    // Header Language Toggle Button (stays visible on all tabs)
    lang_button = button(loc().lang_btn, 600, 814, 26, 172, 34);

    for (int i = 0; i < 4; i++)
        tab_buttons[i] = button(loc().tabs[i], 500 + i, 34 + i * 242, 108, 228, 38);

    // ================= PAGE 0: JOGAR / PLAY =================
    building_page = 0;
    lbl_image_path = label(loc().lbl_image_path, 54, 194, 600, 20);
    image_edit = control(L"EDIT", wide(config.image_path).c_str(), ES_AUTOHSCROLL | WS_BORDER | WS_TABSTOP, 110, 54, 218, 720, 32);
    browse_button = button(loc().btn_browse, 101, 788, 218, 178, 32);
    lbl_formats = label(loc().lbl_formats, 54, 260, 900, 20, small_font);

    lbl_card_title = label(loc().lbl_card_status, 54, 344, 400, 20);
    status_label = control(L"STATIC", L"", 0, 0, 54, 368, 710, 24);
    open_saves_button = button(loc().btn_open_saves, 103, 778, 364, 188, 34);
    lbl_card_hint = label(loc().lbl_card_hint, 54, 402, 900, 20, small_font);

    play_button = button(loc().btn_play, 100, 276, 482, 468, 64);
    lbl_play_sub = label(loc().lbl_play_sub, 54, 574, 912, 22, small_font, SS_CENTER);

    // ================= PAGE 1: CONTROLES / CONTROLS =================
    building_page = 1;
    lbl_controls_hint = label(loc().lbl_controls_hint, 54, 192, 720, 20, small_font);
    refresh_dev_button = button(loc().btn_refresh_devices, 104, 788, 186, 178, 30);
    for (int i = 0; i < 4; i++) {
        wchar_t buf[64];
        swprintf_s(buf, loc().port_name_fmt, i + 1, i + 1);
        lbl_port_titles[i] = label(buf, 54 + i * 232, 226, 214, 20, small_font);
        ports[i] = control(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP, 200 + i, 54 + i * 232, 248, 214, 200);
    }
    keyboard_check = control(L"BUTTON", loc().chk_keyboard_enable, BS_AUTOCHECKBOX | WS_TABSTOP, 210, 54, 298, 260, 26);
    SendMessageW(keyboard_check, BM_SETCHECK, config.keyboard_enabled ? BST_CHECKED : BST_UNCHECKED, 0);
    lbl_kb_port_title = label(loc().lbl_keyboard_port, 310, 300, 170, 20, small_font);
    keyboard_port = control(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP, 211, 490, 296, 160, 140);
    for (int i = 1; i <= 4; i++) {
        wchar_t buf[32];
        swprintf_s(buf, loc().player_fmt, i);
        SendMessageW(keyboard_port, CB_ADDSTRING, 0, (LPARAM)buf);
    }
    SendMessageW(keyboard_port, CB_SETCURSEL, config.keyboard_port, 0);

    lbl_bindings_hint = label(loc().lbl_bindings_hint, 54, 384, 900, 20, small_font);
    for (int i = 0; i < KEY_BIND_COUNT; i++)
        key_buttons[i] = button(L"", 300 + i, 54 + (i / 5) * 232, 414 + (i % 5) * 34, 214, 28);
    lbl_bindings_note = label(loc().lbl_bindings_note, 54, 592, 900, 20, small_font);

    // ================= PAGE 2: OPÇÕES / OPTIONS =================
    building_page = 2;
    lbl_win_res_title = label(loc().lbl_win_res, 54, 194, 420, 20, small_font);
    window_res_choice = control(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP, 412, 54, 216, 420, 220);
    for (auto r_str : loc().win_res) SendMessageW(window_res_choice, CB_ADDSTRING, 0, (LPARAM)r_str);
    SendMessageW(window_res_choice, CB_SETCURSEL, config.window_resolution >= 0 && config.window_resolution < 7 ? config.window_resolution : 1, 0);

    lbl_int_res_title = label(loc().lbl_int_res, 54, 268, 420, 20, small_font);
    internal_res_choice = control(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP, 413, 54, 290, 420, 220);
    for (auto ir : loc().int_res) SendMessageW(internal_res_choice, CB_ADDSTRING, 0, (LPARAM)ir);
    SendMessageW(internal_res_choice, CB_SETCURSEL, config.internal_resolution >= 0 && config.internal_resolution < 5 ? config.internal_resolution : 0, 0);

    lbl_aspect_title = label(loc().lbl_aspect_ratio, 54, 342, 420, 20, small_font);
    aspect_ratio_choice = control(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP, 414, 54, 364, 420, 180);
    for (auto ar : loc().aspect_ratios) SendMessageW(aspect_ratio_choice, CB_ADDSTRING, 0, (LPARAM)ar);
    SendMessageW(aspect_ratio_choice, CB_SETCURSEL, config.aspect_ratio == 1 ? 1 : 0, 0);

    lbl_win_mode_title = label(loc().lbl_win_mode, 518, 194, 448, 20, small_font);
    window_mode_choice = control(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP, 411, 518, 216, 448, 180);
    for (auto mode : loc().win_modes) SendMessageW(window_mode_choice, CB_ADDSTRING, 0, (LPARAM)mode);
    SendMessageW(window_mode_choice, CB_SETCURSEL, config.window_mode, 0);

    vsync_check = control(L"BUTTON", loc().chk_vsync, BS_AUTOCHECKBOX | WS_TABSTOP, 410, 518, 252, 448, 24);
    SendMessageW(vsync_check, BM_SETCHECK, config.vsync ? BST_CHECKED : BST_UNCHECKED, 0);

    lbl_vsync_hint = label(loc().lbl_vsync_hint, 518, 278, 448, 18, small_font);

    unlock_check = control(L"BUTTON", loc().chk_unlock, BS_AUTOCHECKBOX | WS_TABSTOP, 415, 518, 304, 448, 24);
    SendMessageW(unlock_check, BM_SETCHECK, config.unlock_all ? BST_CHECKED : BST_UNCHECKED, 0);

    lbl_unlock_hint = label(loc().lbl_unlock_hint, 518, 330, 448, 18, small_font);

    lbl_hotkey_hint = label(loc().lbl_hotkey_hint, 518, 360, 448, 18, small_font);
    lbl_widescreen_hint = label(loc().lbl_widescreen_hint, 518, 384, 448, 18, small_font);

    lbl_opt_bullets[0] = label(loc().opt_bullets[0], 54, 496, 900, 20, small_font);
    lbl_opt_bullets[1] = label(loc().opt_bullets[1], 54, 524, 900, 20, small_font);
    lbl_opt_bullets[2] = label(loc().opt_bullets[2], 54, 552, 900, 20, small_font);
    save_opt_button = button(loc().btn_save_options, 102, 756, 574, 210, 36);

    // ================= PAGE 3: CRÉDITOS / CREDITS =================
    building_page = 3;
    lbl_cred_title = label(loc().cred_title, 54, 200, 540, 24, heading_card);
    lbl_cred_subtitle = label(loc().cred_subtitle, 54, 226, 540, 20, small_font);

    lbl_cred_role = label(loc().cred_role, 54, 258, 540, 20, small_font);
    author_label = label(loc().cred_author, 54, 280, 540, 24, heading_card);

    lbl_cred_bullets[0] = label(loc().cred_bullets[0], 54, 320, 540, 20, small_font);
    lbl_cred_bullets[1] = label(loc().cred_bullets[1], 54, 344, 540, 20, small_font);
    lbl_cred_bullets[2] = label(loc().cred_bullets[2], 54, 368, 540, 20, small_font);
    lbl_cred_bullets[3] = label(loc().cred_bullets[3], 54, 392, 540, 20, small_font);

    button(L"github.com/gabrielmedeiros1337/digimonra2-recomp", 400, 54, 432, 540, 38);

    lbl_cred_copyright = label(loc().cred_copyright, 54, 568, 540, 20, small_font);
    lbl_cred_disclaimer = label(loc().cred_disclaimer, 54, 592, 540, 20, small_font);

    building_page = -1;

    // Bottom bar (visible across all tabs)
    save_bottom_button = button(loc().btn_save_bottom, 102, 798, 648, 188, 36);

    load_agumon(instance);
    show_page(0);
    apply_language();

    ShowWindow(main_window, SW_SHOW);
    SetTimer(main_window, 1, 400, nullptr);
    if (!loaded) message(wide(error));

    MSG m;
    while (GetMessageW(&m, nullptr, 0, 0) > 0) {
        if (capture >= 0 && (m.message == WM_KEYDOWN || m.message == WM_SYSKEYDOWN)) {
            procedure(main_window, m.message, m.wParam, m.lParam);
            continue;
        }
        if (!IsDialogMessageW(main_window, &m)) {
            TranslateMessage(&m);
            DispatchMessageW(&m);
        }
    }

    if (game) CloseHandle(game);
    delete agumon;
    if (agumon_stream) agumon_stream->Release();
    if (gdiplus_token) Gdiplus::GdiplusShutdown(gdiplus_token);

    DeleteObject(font);
    DeleteObject(tab_font);
    DeleteObject(play_font);
    DeleteObject(heading_card);
    DeleteObject(title_font);
    DeleteObject(subtitle_font);
    DeleteObject(small_font);
    DeleteObject(background);
    DeleteObject(card_brush);
    DeleteObject(edit_brush);
    SDL_Quit();
    return 0;
}
