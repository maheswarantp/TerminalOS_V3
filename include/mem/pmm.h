#ifndef __PMM__
#define __PMM__

#include <types.h>
#include <lib/string.h>
#include <lib/bit.h>

#define PMMNGR_BLOCKS_PER_BYTE          8
#define PMMNGR_BLOCK_SIZE               4096
#define PMMNGR_BLOCK_ALIGN              PMMNGR_BLOCK_SIZE


void mmap_set(uint32_t bit);
void mmap_unset(uint32_t bit);
boolean mmap_test(uint32_t bit);
uint32_t returnMemoryMap();

uint32_t pmmngr_get_memory_size ();
uint32_t pmmngr_get_block_count ();
uint32_t pmmngr_get_use_block_count ();
uint32_t pmmngr_get_free_block_count ();
uint32_t pmmngr_get_block_size ();

#endif