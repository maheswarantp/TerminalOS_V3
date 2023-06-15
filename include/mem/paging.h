#ifndef __PAGING__
#define __PAGING__

#include <ports.h>
#include <lib/string.h>
#include <types.h>


// extern assembly functions for enabling paging
extern void loadPageDirectory(unsigned int *page_directory);
extern void enablePaging();

void fill_first_page_table(uint32_t *first_page_table);

void make_page_directory_blank(uint32_t *page_directory);

void init_paging();

#endif