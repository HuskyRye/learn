#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define NUMBER  '0' //标识找到一个数
#define NAME    'n'
#define MAXVAL 100  //栈vol的最大深度
#pragma once

extern int sp;
extern double val[MAXVAL];

int getch();

int getop(char[]);
void push(double);
double pop(void);

void clear();
void mathfnc(char s[]);
