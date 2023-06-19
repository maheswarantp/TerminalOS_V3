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

    init_keyboard();


    // Set and Unset bits
    // int i = 0x0000;
    // print_binary(i);
    // printf("\n");
    // i = setBit(i, 13);
    // print_binary(i);
    // printf("\n");
    // i = unsetBit(i, 13);
    // print_binary(i);
    // printf("\n");

    // init_paging();


    // printf("Paging Enabled???\n");
    // Test timer
    // test_timer();

    // Test speaker
    // test_speaker(1000);

}