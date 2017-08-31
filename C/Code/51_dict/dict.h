#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct dict
{
	char *key;
	char *content;
};

void format_string(char *str);
int open_dict(struct dict **p, const char *dict_filename);
int search_dict(const struct dict *p, int size, const char *key, char *content);
void free_dict(struct dict *p, int size);
int get_dict_size(FILE *fp);
