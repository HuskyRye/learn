#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
typedef struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
}nlist;

static nlist *hashtab[HASHSIZE];
unsigned hash(char *s);
nlist *lookup(char *s);
nlist *install(char *name, char *defn);
void freelist(nlist *p);
void freehashtab(nlist *hashtab[]);
void undef(char *s);

int main()
{
    system("pause");
    return 0;
}

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

nlist *lookup(char *s)
{
    nlist *p;
    for (p = hashtab[hash(s)]; p != NULL; p = p->next)
    {
        if (strcmp(s, p->name) == 0)
        {
            return p;
        }
    }
    return NULL;
}

nlist *install(char *name, char *defn)
{
    nlist *p;
    unsigned hashval;
    if ((p = lookup(name)) == NULL)
    {
        p = (nlist *)malloc(sizeof(nlist));
        if (p == NULL)
        {
            return NULL;
        }
        if ((p->name = strdup(name)) == NULL)
        {
            return NULL;
        }
        hashval = hash(name);
        p->next = hashtab[hashval];
        hashtab[hashval] = p;
    }
    else
    {
        if (p->defn != NULL)
        {
            free(p->defn);
            p->defn = NULL;
        }
    }
    if ((p->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }
    return p;
}

void undef(char *s)
{
    nlist *p, *tmp;
    for (p = hashtab[hash(s)]; p != NULL; p = p->next)
    {
        if (strcmp(s, p->next->name) == 0)
        {
            break;
        }
    }
    tmp = p->next;
    p->next = tmp->next;
    if (tmp == NULL)
    {
        return;
    }
    if (tmp->name != NULL)
    {
        free(tmp->name);
        tmp->name = NULL;
    }
    if (tmp->defn != NULL)
    {
        free(tmp->defn);
        tmp->defn = NULL;
    }

}

void freelist(nlist *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }
    if (p->defn != NULL)
    {
        free(p->defn);
        p->defn = NULL;
    }
    if (p->next != NULL)
    {
        freelist(next);
    }
    free(p);
}

void freehashtab(nlist *hashtab[])
{
    int i;
    for (i = 0; i < HASHSIZE; ++i)
    {
        freelist(hashtab[i]);
        hashtab[i] = NULL;
    }
}