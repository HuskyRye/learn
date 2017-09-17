#include <stdio.h>
#define MAXHIST 15		//max length of histogram
#define MAXWORD 11		//max length of a word
#define IN 1			//inside a word
#define OUT 0			//outside a word

int main()
{
	int c, state, nc;	//number of chat
	int i, j;
	int ovflow;
	int maxvalue;
	int len;			//length of each bar;
	int wl[MAXWORD];
	
 	maxvalue = 0; 
	state = OUT;
	nc = 0;
	ovflow = 0;
	for(i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	
	while((c = getchar()) != EOF)
	{
		if(c ==' ' || c == '\n' || c == '\t')
		{
			state = OUT;
			if(nc > 0)
				if(nc < MAXWORD)
					++wl[nc];
				else					
					++ovflow;
			nc = 0;		
		}
		else if(state == OUT)
		{
			state = IN;
			++nc;
		}
		else
			++nc;
	}
	
	for(i = 1; i < MAXWORD; ++i)
	{
		if(wl[i] > maxvalue)
			maxvalue = wl[i];
	}
	
	/*水平输出*/
	for(i = 1; i < MAXWORD; ++i)
	{
		printf("%5d - %5d : ", i, wl[i]);
		if(wl[i] > 0)
		{
			if((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
			len = 0;
		while(len > 0)
		{
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if(ovflow > 0)
		printf("There are %d word >= %d\n", ovflow, MAXWORD);
	putchar('\n');
			
	//竖直输出
	for(i = MAXHIST; i > 1; --i)
	{
		for(j = 1; j < MAXWORD; ++j)
		{
			if(wl[j] * MAXHIST / maxvalue >= i)
				printf("   * ");
			else
				printf("     ");
		}

		putchar('\n');	
	}

	for(j = 1; j < MAXWORD; ++j)
	{
		if((wl[j] > 0 && wl[j] * MAXHIST / maxvalue <= 0) || wl[j] * MAXHIST / maxvalue >= 1)
			printf("   * ");	
		else
			printf("     ");
	}
	putchar('\n');
	
	for(i = 1; i < MAXWORD; ++i)
		printf("%4d ", i);
	putchar('\n');
	for(i = 1; i < MAXWORD; ++i)
		printf("%4d ",wl[i]);
	putchar('\n');
	if(ovflow > 0)
		printf("There are %d word >= %d\n", ovflow, MAXWORD);
	
}
