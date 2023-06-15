#include <tests/test_timer.h>


void test_timer()
{

    printf("Testing the timing mechanism \n");
    int i = 0;
    for(int i = 0; i < 10; i++)
    {
        printf("Count : %d\n", i);
        sleep(1000);
    }
}