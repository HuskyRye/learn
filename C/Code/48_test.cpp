#include <stdio.h>
#include <stdlib.h>

struct Test
{
    int a;
    void setA(int x)
    {
        a = x;
    }
    int getA()
    {
        return a;
    }
};

int main(int argc, char *argv[])
{
    Test obj;
    obj.setA(10);
    printf("a = %d\n", obj.getA());

    //system("pause");
    return 0;
}