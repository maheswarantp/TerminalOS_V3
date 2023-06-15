#include <kernel.h>

int main()
{
    clear_screen();
    printf("Hello World!!!\n");

    init_gdt();
    initialize_isr();

    __asm__ __volatile__("sti");
    init_timer(1000);
    printf("Hello World!!!\n");
    sleep(5000);
    printf("Bie World!!!\n");
}