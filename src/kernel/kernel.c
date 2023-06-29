#include <kernel.h>

void print_memory_map(multiboot_info_t* mbd, uint32_t magic)
{
    // Multiboot check
    if(magic != MULTIBOOT_BOOTLOADER_MAGIC) {
        printf("invalid magic number!\n");
        qemu_printf("invalid magic number!\n");
    }
 
    /* Check bit 6 to see if we have a valid memory map */
    if(!(mbd->flags >> 6 & 0x1)) {
        printf("invalid memory map given by GRUB bootloader\n");
        qemu_printf("invalid memory map given by GRUB bootloader\n");
    }
    printf("Total Memory from BIOS is as follows: \n");
    printf("Lower: %x | Higher: %x | Total: %x \n", mbd->mem_lower, mbd->mem_upper, 1024 + mbd->mem_lower + (mbd->mem_upper * 64));
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
    // COM1
    if(init_serial())
        qemu_printf("Serial Init                \033[0;32m[OK]\033[0;37m\n");
    clear_screen();
    init_gdt();
    qemu_printf("GDT Init                   \033[0;32m[OK]\033[0;37m\n");
    initialize_isr();
    qemu_printf("ISR init                   \033[0;32m[OK]\033[0;37m\n");

    asm volatile("sti");
    init_timer(1000);
    qemu_printf("Timer Init                 \033[0;32m[OK]\033[0;37m\n");
    init_keyboard();
    qemu_printf("Keyboard Init              \033[0;32m[OK]\033[0;37m\n");

    print_memory_map(mbd, magic);    


    // change_color(WHITE);
    // change_background_color(GREEN);
    // boot_screen();

}