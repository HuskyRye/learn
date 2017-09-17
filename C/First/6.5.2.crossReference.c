#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct linklist 
{
    int lnum;
    struct linklist *p;
}linklist;

typedef struct tnode
{
    char *word;
    linklist *lines;
    struct tnode *left;
    struct tnode *right;
}tnode;

tnode *addtree(tnode *p, char *word, int linenum);
linklist *addline(int linenum);
void printtree(tnode *root);
void printline(linklist *link);
void freetree(tnode *root);

int main()
{
    tnode *root = NULL;
    char word[100];
    int linenum = 1;
    while (scanf("%s", word) == 1)
    {
        root = addtree(root, word, linenum);
        if (getchar() == '\n')
        {
            linenum++;
        }
    }
    printtree(root);
    freetree(root);
    root = NULL;
    system("pause");
    return 0;
}

tnode *addtree(tnode *p, char *word, int linen)
{
    int n;
    if (p == NULL)
    {
        p = (tnode *)malloc(sizeof(tnode));
        p->word = (char *)malloc(sizeof(word) + 1);
        strcpy(p->word, word);
        p->lines = (linklist *)malloc(sizeof(linklist));
        p->lines->lnum = linen;
        p->lines->p = NULL;
        p->left = NULL;
        p->right = NULL;
    }
    else if ((n = strcmp(word, p->word)) == 0)
    {
        p->lines->p = addline(linen);
    }
    else if (n < 0)
    {
        p->left = addtree(p->left, word, linen);
    }
    else
    {
        p->right = addtree(p->right, word, linen);
    }
    return p;
}

linklist *addline(int linenum)
{
    linklist *tmp = (linklist *)malloc(sizeof(linklist));
    tmp->lnum = linenum;
    tmp->p = NULL;
    return tmp;
}

void printtree(tnode *p)
{
    if (p != NULL)
    {
        printtree(p->left);
        printf("%10s: ", p->word);
        printline(p->lines);
        putchar('\n');
        printtree(p->right);
    }
}

void printline(linklist *link)
{
    if (link == NULL)
    {
        return;
    }
    printf("%d ", link->lnum);
    printline(link->p);
}


void freetree(tnode *p)
{

}