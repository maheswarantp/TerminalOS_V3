#ifndef __HDD__
#define __HDD__

#include <ports.h>
#include <lib/string.h>
#include <types.h>

void read_sectors(uint16_t* target, uint32_t lba, uint32_t sector_count);

#endif