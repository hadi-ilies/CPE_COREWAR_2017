/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

int get_len_label(char *line)
{
	for (int j = 0; line[j] != '\0'; j++)
		if (line[j + 1] == LABEL_CHAR && line[j] != DIRECT_CHAR)
			return (j + 1);
	return (-1);
}

int get_nlabel(char **tab)
{
	int nb = 0;

	if (tab == NULL)
		return (0);
	for (int i = 0; tab[i] != NULL; i++)
		if (get_len_label(tab[i]) > 0)
			nb++;
	return (nb);
}

char *get_valid_label(char *line, int len)
{
	for (int i = 0; line[i] != '\0' && i < len; i++)
		if (is_valid_label_char(line[i]) == false)
			return (NULL);
	return (my_strndup(line, len));
}

char *erase_label(char *line, char *label)
{
	char *new = my_strdup(line + my_strlen(label) + 2);

	if (new == NULL)
		return (NULL);
	free(line);
	return (new);
}

label_t *get_labels(char **tab)
{
	int len = 0;
	int k = 0;
	label_t *labels;

	if (!tab || !(labels = malloc(sizeof(label_t) * (get_nlabel(tab) + 1))))
		return (NULL);
	for (size_t i = 0; tab[i] != NULL; i++) {
		if ((len = get_len_label(tab[i])) != -1) {
			if (!(labels[k].label = get_valid_label(tab[i], len)))
				return (NULL);
			if ((labels[k].pos = get_pos_label(tab + 2, i)) == -1)
				return (NULL);
			if (!(tab[i] = erase_label(tab[i], labels[k].label)))
				return (NULL);
			k++;
		}
	}
	labels[k].label = NULL;
	labels[k].pos = 0;
	return (labels);
}
