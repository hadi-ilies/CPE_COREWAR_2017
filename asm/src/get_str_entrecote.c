/*
** EPITECH PROJECT, 2018
** get_str_entrecote
** File description:
** get_str_entrecote
*/

#include <stdlib.h>
#include "my.h"

char *get_str_entrecote(char *str)
{
	size_t i = 0;
	char *tmp;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\"' && str[i] != '\0'; i++);
	if (str[i] == '\0' || str[my_strlen(str) - 1] != '\"')
		return (NULL);
	tmp = my_strdup(str + i + 1);
	if (tmp == NULL)
		return (NULL);
	for (i = 0; tmp[i] != '\"' && tmp[i] != '\0'; i++);
	if (tmp[i] == '\0')
		return (NULL);
	tmp[i] = '\0';
	return (tmp);
}
