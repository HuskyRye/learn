/*
	Date: 2018.2.28
	Author: 刘臣轩
*/

#include <stdbool.h>
#include <stdio.h>

#define TABINC 8
#define MAXLINE 100

void settab(int argc, char* argv[], bool* tab);
void detab(bool* tab);
void entab(bool* tab);
bool tabpos(int pos, bool* tab);

int main(int argc, char* argv[])
{
    bool tab[MAXLINE + 1];
    settab(argc, argv, tab);
    detab(tab);
    entab(tab);
    return 0;
}

#include <stdlib.h>

void settab(int argc, char* argv[], bool* tab)
{
    int pos;
    if (argc <= 1) {
        for (int i = 1; i <= MAXLINE; ++i) {
            if (i % TABINC == 0)
                tab[i] = true;
            else
                tab[i] = false;
        }
    } else {
        for (int i = 0; i <= MAXLINE; ++i)
            tab[i] = false;
        while (--argc > 0) {
            pos = atoi(*(++argv));
            if (pos > 0 && pos <= MAXLINE)
                tab[pos] = true;
        }
    }
}

bool tabpos(int pos, bool* tab)
{
    if (pos > MAXLINE)
        return true;
    else
        return tab[pos];
}

void detab(bool* tab)
{
    int c;
    int pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            do {
                putchar(' ');
                ++pos;
            } while (!tabpos(pos, tab));
        } else if (c == '\n') {
            putchar(c);
            pos = 0;
        } else {
            putchar(c);
            ++pos;
        }
    }
}

void entab(bool* tab)
{
    int c;
    int pos = 0;
    int nb = 0;
    int nt = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++pos;
            if (!tabpos(pos, tab))
                ++nb;
            else {
                nb = 0;
                ++nt;
            }
        } else {
            for (; nt > 0; --nt)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            for (; nb > 0; --nb)
                putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while (!tabpos(pos, tab))
                    ++pos;
        }
    }
}
