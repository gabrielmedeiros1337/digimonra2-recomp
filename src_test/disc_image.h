#ifndef DISC_IMAGE_H
#define DISC_IMAGE_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct DiscImage DiscImage;
DiscImage* disc_image_open(const char* path,char* error,size_t capacity);
bool disc_image_read(DiscImage* image,uint64_t offset,void* destination,size_t size);
void disc_image_close(DiscImage* image);
/* Checks disc identity and SHA-256 of its DOL against the statically compiled revision. */
bool disc_image_validate_game(DiscImage* image,char* error,size_t capacity);
bool disc_image_dol(DiscImage* image,void** data,size_t* size);
#ifdef __cplusplus
}
#endif
#endif
