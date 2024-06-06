#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i =0;
    for(i = 0; i < 10; i++)
    {
        printf("[ %02d ] This is for patch learn testing\n", i + 1);
        sleep(10);
    }

    return 0;
}
