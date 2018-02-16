/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *recept, char *new)
{
	int i = 0;
	int j = 0;
	int len_recept = (recept) ? my_strlen(recept) : 0;
	int len_new = (new) ? my_strlen(new) : 0;
	char *new_str = malloc(sizeof(char) * (len_recept + len_new + 1));

	if (new_str == NULL)
		return (NULL);
	while (recept && i < len_recept) {
		new_str[i] = recept[i];
		i++;
	}
	while (j < len_new) {
		new_str[i] = new[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free(recept);
	return (new_str);
}
