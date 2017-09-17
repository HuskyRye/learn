#include <stdio.h>

#define MAXCOL 10		//maximum column of input
#define TABING 8

char line[MAXCOL];		//input line

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

int main()
{
	int c, pos;
	pos = 0;
	while((c = getchar()) != EOF)
	{
		line[pos] = c;
		if(c == '\t')
		{
			//expand tab
			pos = exptab(pos);
		}
		else if(c == '\n')
		{
			//print current input line
			printl(pos);
			pos = 0; 
		}
		else if(++pos == MAXCOL)
		{ 
			pos = findblnk(pos);
			printl(pos);
			pos = newpos(pos); 
		}
	}
	return 0;	
}

/*expand tab into blanks*/
int exptab(int pos)
{
	line[pos] = ' ';		//tab is at least one blank
	for(++pos; pos < MAXCOL && pos % TABING != 0; ++pos)
	{
		line[pos] = ' ';
	}
	if(pos < MAXCOL)
	{
		return pos;
	}
	else
	{
		printl(pos);
		return 0; 
	}
		
}

/*find blank's postition*/
//return_min  = 1;
int findblnk(int pos)
{
	while(pos > 0 && line[pos] != ' ')
	{
		--pos;
	}	
	if(pos == 0)			//no blank in the line
		return MAXCOL;	
	else					//at least one blank
		return pos +1;		//position after the blank
}

int newpos(int pos)
{
	int i, j;
	if(pos == 0 || pos == MAXCOL)
		return 0;			//nothing to rearrange
	else
	{
		i = 0;
		for(j = pos; j < MAXCOL; ++j)
		{
			line [i] = line[j];
			++i;
		}
		return i;			//new position in line
	}
}

/*print line until pos column*/
void printl(int pos)
{
	int i;
	for(i = 0; i < pos; ++i)
	{
		putchar(line[i]);
	}
	putchar('\n');
}

