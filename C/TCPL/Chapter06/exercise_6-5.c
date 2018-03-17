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

#define MAXWLEN 100 // max len of a word
#define HASHSIZE 101

static struct nlist* hashtab[HASHSIZE];

struct nlist* install(char* name, char* defn);
struct nlist* lookup(char* s);
void listprint(struct nlist* root);
void undef(char* name);

void test()
{
    printf("lookup for IN = %p\n", lookup("IN"));
    printf("lookup for dfg = %p\n", lookup("dfg"));
    printf("lookup for sdaklg = %p\n", lookup("sdaklg"));
    printf("lookup for NULL = %p\n", lookup("NULL"));
    for (int i = 0; i < HASHSIZE; ++i)
        if (hashtab[i] != NULL) {
            printf("hashval = %d\n  ", i);
            listprint(hashtab[i]);
        }
}

int main()
{
    install("IN", "1");
    install("dfg", "hehe");
    install("sdaklg", "heihei");
    test();
    undef("sdaklg");
    test();
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
