#include <kernel.h>

void print_memory_map(multiboot_info_t* mbd, uint32_t magic)
{
    // Multiboot check
    if(magic != MULTIBOOT_BOOTLOADER_MAGIC) {
        printf("invalid magic number!");
    }
 
    /* Check bit 6 to see if we have a valid memory map */
    if(!(mbd->flags >> 6 & 0x1)) {
        printf("invalid memory map given by GRUB bootloader");
    }
 
    /* Loop through the memory map and display the values */
    int i;
    for(i = 0; i < mbd->mmap_length; 
        i += sizeof(multiboot_memory_map_t)) 
    {
        multiboot_memory_map_t* mmmt = 
            (multiboot_memory_map_t*) (mbd->mmap_addr + i);
 
        printf("Start Addr: %x | Length: %x | Size: %x | Type: ",
            mmmt->addr, mmmt->len, mmmt->size);


        if(mmmt->type == MULTIBOOT_MEMORY_AVAILABLE)
            printf("AVAILABLE\n");
        else if(mmmt->type == MULTIBOOT_MEMORY_RESERVED)
            printf("RESERVED\n");
        else if(mmmt->type == MULTIBOOT_MEMORY_ACPI_RECLAIMABLE)
            printf("ACPI_RECLAIMABLE\n");
        else if(mmmt->type == MULTIBOOT_MEMORY_NVS)
            printf("NVS\n");
        else if(mmmt->type == MULTIBOOT_MEMORY_BADRAM)
            printf("BADRAM\n");

    }

}


int main(multiboot_info_t* mbd, uint32_t magic)
{
    clear_screen();

    // print_memory_map(mbd, magic);

    // printf("Hello World!!!\n");

    init_gdt();
    initialize_isr();
    
    
    asm volatile("sti");
    init_timer(1000);

    // init_keyboard();


    // HDD
    uint8_t sector[256];
    read_sectors(sector, 2048, 1);

    // printf("%x ", sector[0]);
    // printf("%x ", sector[1]);
    // printf("%x ", sector[2]);
    // printf("%x ", sector[3]);
    // printf("%x ", sector[4]);
    // printf("%x ", sector[5]);
    // printf("%x ", sector[6]);
    // printf("%x ", sector[254]);

    for(uint8_t i = 0; i < 200; i++)
        printf("%x ", sector[i]);




    // init_paging();


    // printf("Paging Enabled???\n");
    // Test timer
    // test_timer();

    // Test speaker
    // test_speaker(3000);



}