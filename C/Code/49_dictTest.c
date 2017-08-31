#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1

struct dict
{
	char *key;
	char *content;
};

void get_dict(struct dict **tmp)
{
	*tmp = (struct dict *)malloc(MAX * sizeof(struct dict));
	if (*tmp == NULL)
	{
		return;
	}

	(*tmp)[0].key = (char *)malloc(strlen("a") + 1);
	strcpy((*(*tmp + 0)).key, "a");

	(*(*tmp + 0)).content = (char *)malloc(strlen("第一个单词的解析") + 1);
	strcpy((*(*tmp + 0)).content, "第一个单词的解析");
}

void print_dict(struct dict *p)
{
	int i = 0;
	for (i = 0; i < MAX; ++i)
	{
		//printf("[%s]%s\n", p[i].key, p[i].content);
		printf("[%s]%s\n", (*(p + i)).key, (*(p + i)).content);
	}
}

void free_dict(struct dict *p)
{
	int i = 0;
	for (i = 0; i < MAX; ++i)
	{
		if ((*(p + i)).key != NULL)
		{
			free((*(p + i)).key);
			(*(p + i)).key = NULL;
		}
		if ((*(p + i)).content != NULL)
		{
			free((*(p + i)).content);
			(*(p + i)).content = NULL;
		}
	}
	free(p);
	p = NULL;
}

int search_dict(struct dict *p, char *key, char *content)
{
	int i;
	for (i = 0; i < MAX; ++i)
	{
		if (strcmp(key, (*(p + i)).key) == 0)
		{
			strcpy(content, (*(p + i)).content);
			return 1;
		}
	}
	return 0;
}

int main()
{
	struct dict *p = NULL;
	get_dict(&p);
	print_dict(p);

	char key[1024];
	char content[1024];
	while (printf("请输入需要查询的单词:") && (scanf("%s", key)))
	{
		int flag = search_dict(p, key, content);
		if (flag == 0)
		{
			printf("no such word\n");
		}
		else
		{
			printf("[%s]解析为：\n%s\n", key, content);
		}
	}
	free_dict(p);
	return 0;
}
