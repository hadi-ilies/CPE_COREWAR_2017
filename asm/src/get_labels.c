/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "my.h"

int is_label(char *str)
{
	for (int j = 0; str[j] != '\0'; j++)
		if (str[j + 1] == ':' && str[j] != '%' && j > 0)
			return (j + 1);
	return (-1);
}

int get_label_nb(char **tab)
{
	int nb = 0;

	for (int i = 0; tab[i] != NULL; i++)
		if (is_label(tab[i]) > 0)
			nb++;
	return (nb);
}

char **get_labels(char **tab)
{
	int pos = 0;
	char **labels;
	int k = 0;

	if (tab == NULL)
		return (NULL);
	if ((labels = malloc(sizeof(char *) * (get_label_nb(tab) + 1))) == NULL)
		return (NULL);
	for (int i = 0; tab[i] != NULL; i++)
		if ((pos = is_label(tab[i])) != -1) {
			labels[k] = my_strndup(tab[i], pos);
			if (labels[k] == NULL)
				return (NULL);
			k++;
		}
	labels[k] = NULL;
	return (labels);
}
