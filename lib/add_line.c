#include <stdlib.h>
#include "my.h"

int tablen(char **tab)
{
	int i = 0;

	for (; tab[i] != NULL; i++);
	return (i);
}

char **add_new_line(char *new_line, char **tab)
{
	int i = 0;
	char **tmp = malloc(sizeof(char *) * tablen(tab));

	for (int i = 0; tab[i] != NULL; i++) {
		tmp[i] = malloc(sizeof(char) * my_strlen(tab[i]));
		tmp[i] = tab[i];
	}
	tmp[i] = new_line;
	tmp[++i] = NULL;
	free(tab);
	return (tmp);
}
