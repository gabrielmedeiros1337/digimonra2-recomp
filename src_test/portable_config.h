#ifndef PORTABLE_CONFIG_H
#define PORTABLE_CONFIG_H
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#ifndef _WIN32
#include <string.h>
#include <strings.h>
#define strcpy_s(dst, src) strncpy((dst), (src), sizeof(dst) - 1)
#define _stricmp strcasecmp
#endif
#ifdef __cplusplus
extern "C" {
#endif
#define LAUNCHER_PATH_MAX 4096
#define KEY_BIND_COUNT 20
typedef struct {
    char image_path[LAUNCHER_PATH_MAX];
    bool keyboard_enabled;
    int keyboard_port;
    /* "none", "keyboard", "auto", or SDL GUID + ':' + ordinal of identical GUIDs. */
    char ports[4][80];
    int keys[KEY_BIND_COUNT];
    bool vsync; /* Opt-in presentation setting; default OFF keeps the stable baseline. */
    int window_mode; /* 0 windowed, 1 borderless desktop, 2 exclusive fullscreen. */
    int window_resolution; /* 0: 640x480, 1: 1280x720, 2: 1366x768, 3: 1600x900, 4: 1920x1080, 5: 2560x1440, 6: 3840x2160 */
    int internal_resolution; /* 0: 1x (640x528), 1: 1.5x (960x792), 2: 2x (1280x1056), 3: 3x (1920x1584), 4: 4x (2560x2112) */
    int aspect_ratio; /* 0: 4:3 (Padrão GameCube), 1: 16:9 (Widescreen Real) */
    bool unlock_all; /* Unlock all secret characters, stages and modes dynamically */
    char language[16]; /* "pt-BR" or "en" */
} LauncherConfig;
extern const char* const launcher_key_names[KEY_BIND_COUNT];
void launcher_config_defaults(LauncherConfig* config);
bool launcher_config_load(const char* path, LauncherConfig* config, char* error, size_t capacity);
bool launcher_config_save(const char* path, const LauncherConfig* config, char* error, size_t capacity);
/* All paths below are UTF-8. Writes are atomic and durable before success. */
FILE* portable_fopen(const char* path, const char* mode);
bool portable_write_atomic(const char* path, const void* data, size_t size);
bool portable_mkdirs(const char* path);
bool portable_exists(const char* path);
bool portable_executable_root(char* path, size_t capacity);
#ifdef __cplusplus
}
#endif
#endif
