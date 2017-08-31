#include <stdio.h>

int main()
{
    printf("a\n");
    //fclose(stdout);   //关闭标准输出文件指针
    printf("b\n");

    //打印库函数调用失败的原因
    perror("mike");
    fclose(stderr);
    perror("jiang");

    int a;
    printf("a:\n");
    fclose(stdin);
    scanf("%d", &a);
    printf("a = %d\n", a);

    printf("a\n");
    fclose(stdout);
    //stdout = fopen("E:/C/C语言基础/test.txt", "w");

    system("pause");
    return 0;
}
