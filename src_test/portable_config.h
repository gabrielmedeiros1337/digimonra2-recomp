#ifndef PORTABLE_CONFIG_H
#define PORTABLE_CONFIG_H
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
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
