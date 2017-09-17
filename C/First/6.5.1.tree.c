#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
}tnode;

tnode *addtree(tnode *p, char *word);
void printtree(tnode *root);
void freetree(tnode *root);

int main()
{
    tnode *root = NULL;
    char word[100];
    while (scanf("%s", word) == 1)
    {
        root = addtree(root, word);
    }
    printtree(root);
    freetree(root);
    root = NULL;
    system("pause");
    return 0;
}

tnode *addtree(tnode *p, char *word)
{
    int n;
    if (p == NULL)
    {
        p = (tnode *)malloc(sizeof(tnode));
        p->word = (char *)malloc(sizeof(word) + 1);
        strcpy(p->word, word);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
    }
    else if ((n = strcmp(word, p->word)) == 0)
    {
        p->count++;
    }
    else if (n < 0)
    {
        p->left = addtree(p->left, word);
    }
    else
    {
        p->right = addtree(p->right, word);
    }
    return p;
}

void printtree(tnode *p)
{
    if (p != NULL)
    {
        printtree(p->left);
        printf("%4d %s\n", p->count, p->word);
        printtree(p->right);
    }
}

void freetree(tnode *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->left != NULL)
    {
        freetree(p->left);
        p->left = NULL;
    }
    if (p->right != NULL)
    {
        freetree(p->right);
        p->right = NULL;
    }
    if (p->word != NULL)
    {
        free(p->word);
        p->word = NULL;
    }
    free(p);
}