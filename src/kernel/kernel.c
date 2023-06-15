#include <kernel.h>

int main()
{
    clear_screen();
    printf("Hello World!!!\n");

    init_gdt();
    initialize_isr();

    // Test timer
    test_timer();

    // Test speaker
    test_speaker(3000);
}