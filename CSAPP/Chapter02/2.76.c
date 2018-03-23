/*
	Date: 2018.3.23
	Author: 刘臣轩
*/

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* calloc(size_t nmemb, size_t size);

int main()
{
    void* p = calloc(0x1234, sizeof(int));
    assert(p != NULL);
    free(p);

    p = calloc(UINT_MAX, 1);
    assert(p == NULL);

    p = calloc(UINT_MAX, 2);
    assert(p == NULL);
    return 0;
}

void* calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;
    size_t buf_size = nmemb * size;
    if (nmemb && buf_size / nmemb == size) {
        void* p = malloc(buf_size);
        if (p == NULL)
            return NULL;
        memset(p, 0, buf_size);
        return p;
    }
    return NULL;
}
