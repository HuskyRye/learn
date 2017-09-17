#include <stdio.h>

#define BUFSIZE 100

static int buf[BUFSIZE];
static int bufp = 0;

//取一个字符
int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
