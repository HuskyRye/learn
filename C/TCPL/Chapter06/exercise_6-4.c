/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWLEN 100 // max len of a word
#define MAXWORDS 1000 // max number of words

struct tnode {
    char* word;
    int cound;
    struct tnode* left;
    struct tnode* right;
};

int getword(char* word, int limit);

struct tnode* addtree(struct tnode* p, char* w);
void treeprint(struct tnode* root);
void treestore(struct tnode* root);
void quicksort(int left, int right);

struct tnode* list[MAXWORDS];
int listp = 0;

int main()
{
    char word[MAXWLEN];
    struct tnode* root = NULL;
    while (getword(word, MAXWLEN) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treestore(root);
    quicksort(0, listp - 1);
    for (int i = 0; i < listp; ++i)
        printf("%2d: %s\n", list[i]->cound, list[i]->word);
    return 0;
}

void quicksort(int left, int right)
{
    if (left >= right)
        return;
    struct tnode* temp = list[left];
    int i = left;
    int j = right;
    while (i != j) {
        while (list[j]->cound <= temp->cound && i < j)
            --j;
        while (list[i]->cound >= temp->cound && i < j)
            ++i;
        if (i < j) {
            struct tnode* t = list[i];
            list[i] = list[j];
            list[j] = t;
        }
    }
    list[left] = list[i];
    list[i] = temp;
    quicksort(left, i - 1);
    quicksort(i + 1, right);
}

void treestore(struct tnode* root)
{
    if (root != NULL) {
        treestore(root->left);
        if (listp < MAXWORDS)
            list[listp++] = root;
        treestore(root->right);
    }
}

struct tnode* addtree(struct tnode* p, char* w)
{
    int cond;
    if (p == NULL) {
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->cound = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        ++p->cound;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

int getch();
void ungetch(int c);

int getword(char* w, int lim)
{
    int c;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *(w++) = c;
    if (isalpha(c)) {
        for (; --lim > 0; ++w) {
            *w = getch();
            if (!isalpha(*w)) {
                ungetch(*w);
                break;
            }
        }
    }
    *w = '\0';
    return c;
}

#define BUFLEN 100
char buf[BUFLEN];
int bufp = 0;

int getch()
{
    return (bufp == 0) ? getchar() : buf[--bufp];
}
void ungetch(int c)
{
    if (bufp >= BUFLEN)
        printf("error: too many characters for ungetch\n");
    else
        buf[bufp++] = c;
}
