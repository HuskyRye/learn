/*
	Date: 2018.3.16
	Author: 刘臣轩
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct wordtree {
    char* word;
    struct wordtree* left;
    struct wordtree* right;
};

struct tnode {
    struct wordtree* words;
    struct tnode* left;
    struct tnode* right;
};

int getword(char*, int);

struct tnode* addtree(struct tnode* node, char* word, int num);
void treeprint(struct tnode* root);

int main(int argc, char* argv[])
{
    char word[MAXWORD];
    int num = (--argc && *(argv[1]) == '-') ? atoi(argv[1] + 1) : 6;
    struct tnode* root = NULL;
    printf("num = %d\n", num);
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtree(root, word, num);
    }
    treeprint(root);
    return 0;
}

struct wordtree* addword(struct wordtree* node, char* word);

struct tnode* addtree(struct tnode* p, char* w, int num)
{
    int cond;
    if (p == NULL) {
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->left = p->right = NULL;
        p->words = addword(p->words, w);
    } else if ((cond = strncmp(p->words->word, w, num)) == 0)
        addword(p->words, w);
    else if (cond > 0)
        p->left = addtree(p->left, w, num);
    else
        p->right = addtree(p->right, w, num);
    return p;
}

struct wordtree* addword(struct wordtree* p, char* word)
{
    int cond;
    if (p == NULL) {
        p = (struct wordtree*)malloc(sizeof(struct wordtree));
        p->left = p->right = NULL;
        p->word = strdup(word);
    } else if ((cond = strcmp(p->word, word)) > 0)
        p->left = addword(p->left, word);
    else if (cond < 0)
        p->right = addword(p->right, word);
    return p;
}

void wordsprint(struct wordtree* root);

void treeprint(struct tnode* p)
{
    if (p != NULL) {
        treeprint(p->left);
        wordsprint(p->words);
        putchar('\n');
        treeprint(p->right);
    }
}

void wordsprint(struct wordtree* p)
{
    if (p != NULL) {
        wordsprint(p->left);
        printf("%s\n", p->word);
        wordsprint(p->right);
    }
}

int getch();
void ungetch(int c);

int comment();

int getword(char* word, int lim)
{
    int c;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *(word++) = c;
    if (isalpha(c) || c == '#' || c == '_') {
        for (; --lim; ++word) {
            *word = getch();
            if (!(isalnum(*word) || *word == '_')) {
                ungetch(*word);
                break;
            }
        }
    } else if (c == '\'' || c == '\"') {
        int d;
        while ((d = getch()) != c) {
            if (d == '\\') // escape \' and \"
                getch();
        }
    } else if (c == '/') {
        int d = getch();
        if (d == '*')
            comment();
        else
            ungetch(d);
    }
    *word = '\0';
    return c;
}

int comment()
{
    int c;
    while ((c = getch() != EOF)) {
        if (c == '*') {
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
        }
    }
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
