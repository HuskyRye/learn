#include <stdio.h>

#define MAXLEN	11
#define MAXHIST	15
#define IN		1
#define OUT		0

int main()
{
	int wl[MAXLEN] = { 0 };
	int overflow = 0;

	int c;
	int state = OUT;
	int nc = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXLEN)
					++wl[nc];
				else
					++overflow;
				nc = 0;
			}
		} else if (state == OUT) {
			state = IN;
			nc = 1;
		} else
			++nc;
	}

	int maxvalue = 0;
	for (int i = 1; i < MAXLEN; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];

	int hl[MAXLEN] = { 0 };
	for (int i = 1; i < MAXLEN; ++i) {
		printf("%3d - %3d : ", i, wl[i]);
		if (wl[i] > 0)
			if ((hl[i] = wl[i] * MAXHIST / maxvalue) == 0)
				hl[i] = 1;
		for (int j = hl[i]; j > 0; --j)
			putchar('*');
		putchar('\n');
	}

	for (int i = MAXHIST; i > 0; --i) {
		for (int j = 1; j < MAXLEN; ++j) {
			if (hl[j] >= i)
				printf("  * ");
			else
				printf("    ");
		}
		putchar('\n');
	}
	for (int i = 1; i < MAXLEN; ++i)
		printf("%3d ", i);
	putchar('\n');
	for (int i = 1; i < MAXLEN; ++i)
		printf("%3d ", wl[i]);
	putchar('\n');

	if (overflow > 0)
		printf("There are %d words longer than %d\n", overflow, MAXLEN);
}
