/*
	Date: 2018.3.16
	Author: 刘臣轩
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct linklist {
    int linenum;
    struct linklist* next;
};

struct tnode {
    char* word;
    struct linklist* lines;
    struct tnode* left;
    struct tnode* right;
};

int getword(char* word, int limit);
int noiseword(char* word);
struct tnode* addtree(struct tnode* p, char* w, int lnum);
void treeprint(struct tnode* root);

int main()
{
    char word[MAXWORD];
    int lnum = 1;
    struct tnode* root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && noiseword(word) == -1)
            root = addtree(root, word, lnum);
        else if (word[0] == '\n')
            ++lnum;
    }
    treeprint(root);
    return 0;
}

void treeprint(struct tnode* root)
{
    if (root != NULL) {
        treeprint(root->left);
        printf("%10s:", root->word);
        for (struct linklist* p = root->lines; p != NULL; p = p->next)
            printf(" %4d", p->linenum);
        putchar('\n');
        treeprint(root->right);
    }
}

void addlnum(struct linklist* p, int lnum);

struct tnode* addtree(struct tnode* p, char* w, int lnum)
{
    int cond;
    if (p == NULL) {
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->left = p->right = NULL;
        p->lines = (struct linklist*)malloc(sizeof(struct linklist));
        p->lines->linenum = lnum;
        p->lines->next = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        addlnum(p->lines, lnum);
    else if (cond < 0)
        p->left = addtree(p->left, w, lnum);
    else
        p->right = addtree(p->right, w, lnum);
    return p;
}

void addlnum(struct linklist* p, int lnum)
{
    while (p->next != NULL && p->linenum != lnum)
        p = p->next;
    if (p->linenum != lnum) {
        p->next = (struct linklist*)malloc(sizeof(struct linklist));
        p->next->linenum = lnum;
        p->next->next = NULL;
    }
}

int noiseword(char* word)
{
    static char* noise[] = {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"
    };
    int low = 0;
    int high = sizeof(noise) / sizeof(char*) - 1;
    int mid;
    int cond;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, noise[mid])) < 0)
            high = low - 1;
        else if (cond > 0)
            low = high + 1;
        else
            return mid;
    }
    return -1;
}

int getch();
void ungetch(int c);

int getword(char* w, int lim)
{
    int c;
    while (isspace(c = getch()) && c != '\n')
        ;
    if (c != EOF)
        *(w++) = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; ++w) {
        *w = getch();
        if (!isalpha(*w)) {
            ungetch(*w);
            break;
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
