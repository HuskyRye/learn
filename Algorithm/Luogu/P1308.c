#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char word[11];
    char article[1000001];
    // scanf("%s\n", word);
    // scanf("%s[^\n]", article);
    gets(word);
    gets(article);
    
    

    int word_len = strlen(word);
    int article_len = strlen(article);

    int i = 0;
    int place = -1;

    //tolower
    for (i = 0; i < article_len; ++i)
    {
        article[i] = tolower(article[i]);
    }
    for (i = 0; i < word_len; ++i)
    {
        word[i] = tolower(word[i]);
    }

    int num = 0;
    char *p = strstr(article, word);
    while (p != NULL)
    {
        if ( ((p == article) || (*(p - 1)) == ' ') && ( (*(p + word_len) == '\0') || (*(p + word_len) == ' ')) )
        {
            num += 1;
            if (num == 1)
            {
                place = p - article;
            }
        }
        p += word_len;
        p = strstr(p, word);
    }
    if (num == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d %d", num, place);
    }
    return 0;
}