#include <kernel.h>

int main()
{
    clear_screen();    

    init_gdt();
    isr_install();

    asm volatile("sti");
    // init_timer(1);
    // printf("Sleep test start\n");
    // sleep(1000);
    // printf("Sleep test end");

    init_keyboard();

    return 0;
}