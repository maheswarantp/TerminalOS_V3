#include <mem/paging.h>

// Page directory
uint32_t page_directory[1024] __attribute__((aligned(4096)));

// First page table
uint32_t first_page_table[1024] __attribute__((aligned(4096)));


void make_page_directory_blank(uint32_t *page_directory)
{
    for(int i = 0; i < 1024; i++)
        page_directory[i] = 0x00000002;
}

void fill_first_page_table(uint32_t *first_page_table)
{
    for(int i = 0; i < 1024; i++)
        first_page_table[i] = (i * 0x1000) | 3;
}

void init_paging()
{
    make_page_directory_blank(page_directory);
    fill_first_page_table(first_page_table);
    page_directory[0]  = ((unsigned int)first_page_table) | 3;

    loadPageDirectory(page_directory);
    enablePaging();
}