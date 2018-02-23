/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

bool is_valid_char(char c)
{
	for (int i = 0; LABEL_CHARS[i] != '\0'; i++)
		if (c == LABEL_CHARS[i])
			return (true);
	return (false);
}

bool is_valid_label(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (!is_valid_char(str[i]))
			return (false);
	return (true);
}

int is_label(char *str)
{
	for (int j = 0; str[j] != '\0'; j++)
		if (str[j + 1] == LABEL_CHAR && str[j] != '%' && j > 0)
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

label_t *get_labels(char **tab)
{
	int pos = 0;
	label_t *labels;
	int k = 0;

	if (tab == NULL)
		return (NULL);
	labels = malloc(sizeof(label_t) * (get_label_nb(tab) + 1));
	if (labels == NULL)
		return (NULL);
	for (int i = 0; tab[i] != NULL; i++)
		if ((pos = is_label(tab[i])) != -1) {
			labels[k].label = my_strndup(tab[i], pos);
			labels[k].line = i;
			if (labels[k].label == NULL )
				return (NULL);
			if (!is_valid_label(labels[k].label))
				return (NULL);
			k++;
		}
	labels[k].label = NULL;
	labels[k].line = 0;
	return (labels);
}
