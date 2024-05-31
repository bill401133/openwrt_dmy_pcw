#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i = 0;
    FILE *fp;

    // 打开文件
    fp = fopen("/dev/console", "w+");

    // 输出重定向
    fprintf(fp, "\thello everyone~~\n");
    for (i = 0; i < 100; i++)
    {
        fprintf(fp,"[ %02d ] This is an self-start program Test %d\n", i, i);
        sleep(1);
    }

    // 关闭文件
    fclose(fp);
    return 0;
}
