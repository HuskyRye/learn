#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pointerFunction
int *fun2()
{
    int *p = (int *)malloc(sizeof(int));
    return p;
}

int fun(int a)
{
    printf("a = %d\n", a);
    return 0;
}

void add()
{
    printf("add\n");
}
void minus()
{
    printf("minus\n");
}
void multiply()
{
    printf("multiply\n");
}
void divide()
{
    printf("divide\n");
}
void myexit()
{
    exit(0);
}

int main()
{
    //functionPoiner

    //way1
    typedef int FUN(int a);
    FUN *p1 = fun;

    fun(5);
    p1(6);

    //way2
    typedef int (*PFUN)(int a);
    PFUN p2 = fun;
    p2(7);

    //way3
    int (*p3)(int a) = fun;
    p3(8);

    void (*p[5])() = {add, minus, multiply, divide, myexit};
    char *buf[] = {"add", "minus", "multiply", "divide", "exit"};
    char cmd[10];
    int i = 0;
    while (1)
    {
        printf("cmd: ");
        scanf("%s", cmd);
        for (i = 0; i < 5; ++i)
        {
            if (strcmp(cmd, buf[i]) == 0)
            {
                p[i]();
                break;
            }
        }
    }

    system("pause");
    return 0;
}