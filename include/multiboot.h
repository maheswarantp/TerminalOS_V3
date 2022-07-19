#include <types.h>

typedef struct multiboot_header
{
 uint32_t magic;
 uint32_t flags;
 uint32_t checksum;
 uint32_t header_addr;
 uint32_t load_addr;
 uint32_t load_end_addr;
 uint32_t bss_end_addr;
 uint32_t entry_addr;
} multiboot_header_t;

/*
u32	magic	required
4	u32	flags	required
8	u32	checksum	required
12	u32	header_addr	if flags[16] is set
16	u32	load_addr	if flags[16] is set
20	u32	load_end_addr	if flags[16] is set
24	u32	bss_end_addr	if flags[16] is set
28	u32	entry_addr	if flags[16] is set
32	u32	mode_type	if flags[2] is set
36	u32	width	if flags[2] is set
40	u32	height	if flags[2] is set
44	u32	depth	if flags[2] is set



*/