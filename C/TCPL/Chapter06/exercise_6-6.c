/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
    struct nlist* next;
    char* name;
    char* defn;
};

#define MAXWLEN 100 /* max len of a word */
#define HASHSIZE 101

static struct nlist* hashtab[HASHSIZE];

int getword(char* word, int limit);
struct nlist* install(char* name, char* defn);
struct nlist* lookup(char* s);
void listprint(struct nlist* root);
void undef(char* name);

void skipblanks();

int main()
{
    char word[MAXWLEN];
    char defn[MAXWLEN];
    struct nlist* np;
    while (getword(word, MAXWLEN) != EOF) {
        if (strcmp(word, "#define") == 0) {
            skipblanks();
            getword(word, MAXWLEN);
            skipblanks();
            getword(defn, MAXWLEN);
            install(word, defn);
        } else if (strcmp(word, "#undef") == 0) {
            skipblanks();
            getword(word, MAXWLEN);
            undef(word);
        } else {
            if ((np = lookup(word)) != NULL)
                printf("%s", np->defn);
            else
                printf("%s", word);
        }
        word[0] = '\0';
    }
    return 0;
}

unsigned hash(char* s);

void listprint(struct nlist* root)
{
    for (; root != NULL; root = root->next)
        printf("#define %s %s\n", root->name, root->defn);
}

struct nlist* install(char* name, char* defn)
{
    struct nlist* np = lookup(name);
    if (np == NULL) {
        np = (struct nlist*)malloc(sizeof(struct nlist));
        if (np == NULL)
            return NULL;
        if ((np->name = strdup(name)) == NULL) {
            free(np);
            return NULL;
        }
        unsigned hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free(np->defn);
    if ((np->defn = strdup(defn)) == NULL) {
        free(np->name);
        free(np);
        return NULL;
    } else
        return np;
}

struct nlist* lookup(char* s)
{
    struct nlist* np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

void undef(char* name)
{
    unsigned hashval = hash(name);
    struct nlist* prev = NULL;
    struct nlist* np;
    for (np = hashtab[hashval]; np != NULL; np = np->next) {
        if (strcmp(name, np->name) == 0)
            break;
        prev = np;
    }
    if (np != NULL) {
        if (prev == NULL)
            hashtab[hashval] = np->next;
        else
            prev->next = np->next;
        free(np->name);
        free(np->defn);
        free(np);
    }
}

unsigned hash(char* s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; ++s)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

int getch();
void ungetch(int c);

int comment();

int getword(char* w, int lim)
{
    int c = getch();
    if (c != EOF)
        *(w++) = c;
    if (isalnum(c) || c == '#' || c == '_') {
        for (; --lim > 0; ++w) {
            *w = getch();
            if (!(isalnum(*w) || *w == '_')) {
                ungetch(*w);
                break;
            }
        }
    } else if (c == '\'' || c == '\"') {
        putchar(c);
        int d;
        while ((d = getch()) != c) {
            putchar(d);
            if (d == '\\')
                putchar(getch());
        }
        putchar(d);
        --w;
    } else if (c == '/') {
        int d = getch();
        if (d == '*') {
            c = comment();
            --w;
        } else
            ungetch(d);
    }
    *w = '\0';
    return c;
}

int comment()
{
    int c;
    while ((c = getch()) != EOF) {
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

void skipblanks()
{
    int c;
    while (isspace(c = getch()))
        ;
    ungetch(c);
}
