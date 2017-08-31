#include <stdio.h>

union Test {
    unsigned char a;
    unsigned short b;
    unsigned int c;
};

int main()
{
    union Test obj;
    printf("%p, %p, %p, %p\n", &obj, &obj.a, &obj.b, &obj.c);
    obj.c = 0x44332211;
    printf("obj.a = %x\n", obj.a);
    printf("obj.b = %x\n", obj.b);
    printf("obj.c = %x\n", obj.c);

    obj.a = 0xaa;
    printf("obj.a = %x\n", obj.a);
    printf("obj.b = %x\n", obj.b);
    printf("obj.c = %x\n", obj.c);

    system("pause");
    return 0;
}