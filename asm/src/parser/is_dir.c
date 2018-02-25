/*
** EPITECH PROJECT, 2018
** is_dir
** File description:
** is_dir
*/

#include "asm.h"
#include "my.h"

/*
** Returns the value written after DIRECT_CHAR ('%') if it is valid
*/

char *is_dir(char **line, char id, int nparam)
{
	int i = 0;
	char *nb;

	if (!IS_CORRECT_PARAM(id, nparam, T_DIR))
		return (NULL);
	(*line)++;
	for (; IS_NUM(*line[i]); i++);
	nb = my_strndup(*line, i);
	*line += i;
	if (nb == NULL)
		return (NULL);
	return (nb);
}
