/*
** EPITECH PROJECT, 2018
** get_str_entrecote
** File description:
** get_str_entrecote
*/

#include <stdlib.h>
#include "my.h"

int get_cote_number(char *str)
{
	int cote_de_porc = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\"')
			cote_de_porc++;
	}
	return (cote_de_porc);
}

bool is_les_cote_valide(char *str)
{
	if (get_cote_number(str) != 2 || str[my_strlen(str) - 1] != '\"')
		return (false);
	return (true);
}

char *get_str_entrecote(char *str)
{
	size_t i = 0;
	char *tmp;

	if (str == NULL || !is_les_cote_valide(str))
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
