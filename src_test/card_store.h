#ifndef CARD_STORE_H
#define CARD_STORE_H
#include <stdint.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif
#define CARD_BLOCK_SIZE 8192u
#define CARD_FILE_COUNT 127
void card_store_init(const char* directory);
void card_store_shutdown(void);
/* Enable before mounting. Successful writes remain in memory until shutdown. */
void card_store_set_volatile(bool enabled);
int card_store_mount(void);
int card_store_format(void);
int card_store_free(int* bytes,int* files);
int card_store_find(const uint8_t id[6],const char* name);
int card_store_create(const uint8_t id[6],const char* name,uint32_t size);
int card_store_delete(int file);
int card_store_get(int file,uint8_t dir[64],uint32_t* size);
int card_store_set(int file,const uint8_t dir[64]);
int card_store_transfer(int file,void* data,uint32_t size,uint32_t offset,bool write);
#ifdef __cplusplus
}
#endif
#endif
