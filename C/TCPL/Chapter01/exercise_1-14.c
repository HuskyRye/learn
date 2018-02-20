/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>
#include <ctype.h>

#define MAXHIST	15
#define MAXCHAR	128

int main()
{
	int nc[MAXCHAR] = { 0 };	// numbers of chars

	int c;
	while ((c = getchar()) != EOF) {
		if (c < MAXCHAR)
			++nc[c];
	}

	int maxvalue = 0;
	for (int i = 1; i < MAXCHAR; ++i)
		if (nc[i] > maxvalue)
			maxvalue = nc[i];

	for (int i = 1; i < MAXCHAR; ++i) {
		if (isprint(i))
			printf("%4d - %c - %3d : ", i, i, nc[i]);
		else
			printf("%4d -   - %3d : ", i, nc[i]);
		int len = 0;
		if (nc[i] > 0) {
			if ((len = nc[i] * MAXHIST / maxvalue) == 0)
				len = 1;
		}
		for (int j = len; j > 0; --j)
			putchar('*');
		putchar('\n');
	}
}
