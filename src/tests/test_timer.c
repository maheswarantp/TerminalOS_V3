#include <tests/test_timer.h>


void test_timer()
{

    printf("Testing the timing mechanism \n");
    int i = 0;
    for(int i = 0; i < 10; i++)
    {
        // printf("Count : %d\n", i);         // this breaks sleep after one iter due to some reason

        // something to do with the way integers are converted to ascii probably
        printf("hello\n");
        sleep(1000);
    }


    // Also fails
    // int i = 0;
    // while(i < 10)
    // {
    //     printf("Count : %d\n", i);
    //     sleep(1000);
    //     i = i + 1;
    // }


}