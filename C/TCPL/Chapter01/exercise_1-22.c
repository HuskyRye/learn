/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];

int exptab(int pos);
void printl(int pos);
int findblank(int pos);
int newpos(int pos);

int main()
{
    int c;
    int pos = 0;
    while ((c = getchar()) != EOF) {
        line[pos] = c;
        if (c == '\t')
            pos = exptab(pos);
        else if (c == '\n') {
            printl(pos);
            pos = 0;
        } else {
            ++pos;
            if (pos >= MAXCOL) {
                pos = findblank(pos);
                printl(pos);
                pos = newpos(pos);
            }
        }
    }
    return 0;
}

int findblank(int pos)
{
    while (pos > 0 && line[pos] != ' ')
        --pos;
    return (pos == 0 ? MAXCOL : pos + 1);
}

void printl(int pos)
{
    for (int i = 0; i < pos; ++i)
        putchar(line[i]);
    if (pos > 0)
        putchar('\n');
}

int newpos(int pos)
{
    int i = 0;
    for (int j = pos; j < MAXCOL; ++j, ++i)
        line[i] = line[j];
    return i;
}

int exptab(int pos)
{
    line[pos] = ' ';
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
        line[pos] = ' ';
    if (pos < MAXCOL)
        return pos;
    else {
        printl(pos);
        return 0;
    }
}
