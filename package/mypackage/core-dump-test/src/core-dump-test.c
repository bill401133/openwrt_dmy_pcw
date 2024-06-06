#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i =0;
    for(i = 0; i < 10; i++)
    {
        printf("[ %02d ] This is for core dump testing\n", i + 1);
        sleep(1);
    }

    int *tmp = NULL;
    *tmp = i;

    return 0;
}
