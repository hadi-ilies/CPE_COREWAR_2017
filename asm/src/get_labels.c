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

int get_len_label(char *line)
{
	for (int j = 0; line[j] != '\0'; j++)
		if (line[j + 1] == LABEL_CHAR && line[j] != DIRECT_CHAR)
			return (j + 1);
	return (-1);
}

int get_label_nb(char **tab)
{
	int nb = 0;

	if (tab == NULL)
		return (0);
	for (int i = 0; tab[i] != NULL; i++)
		if (get_len_label(tab[i]) > 0)
			nb++;
	return (nb);
}

bool is_valid_char(char c)
{
	for (int i = 0; LABEL_CHARS[i] != '\0'; i++)
		if (c == LABEL_CHARS[i])
			return (true);
	return (false);
}

char *get_valid_label(char *line, int len)
{
	for (int i = 0; line[i] != '\0' && i < len; i++)
		if (!is_valid_char(line[i]))
			return (NULL);
	return (my_strndup(line, len));
}

label_t *get_labels(char **tab)
{
	int len = 0;
	int k = 0;
	label_t *labels;
	int nb_label = get_label_nb(tab);

	if (tab == NULL || nb_label == 0)
		return (NULL);
	if ((labels = malloc(sizeof(label_t) * (nb_label + 1))) == NULL)
		return (NULL);
	for (int i = 0; tab[i] != NULL; i++) {
		if ((len = get_len_label(tab[i])) != -1) {
			labels[k].line = i;
			labels[k].label = get_valid_label(tab[i], len);
			if (labels[k].label == NULL)
				return (NULL);
			k++;
		}
	}
	labels[k].label = NULL;
	labels[k].line = 0;
	return (labels);
}
