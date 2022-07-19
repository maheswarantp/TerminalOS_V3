#include <kernel.h>

int main()
{
    clear_screen();

    printf("Hello World!!");
    printf("\n\n\n\n");
    printf("Testing decimal integers....\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", i);
    printf("\nTesting hexa-decimal integers....\n");
    for(int i = 0; i < 0xf; i++)
        printf("%x ", i);
    printf("\nTesting Complete....\n");
    
    
    return 0;
}