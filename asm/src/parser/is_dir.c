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

int is_dir(char *line, char id, int nparam)
{
	int i = 0;
	int dir = 0;
	char *nb;

	if (!IS_CORRECT_PARAM(id - 1, nparam, T_DIR))
		return (-1);
	*line += 1;
	if (*line == LABEL_CHAR)
		for (; IS_NUM(line[i]); i++);
	nb = my_strndup(line, i);
	*line += (i + 1);
	if (nb == NULL)
		return (-1);
	if (my_atoi(&dir, nb) == false)
		return (-1);
	free(nb);
	return (dir);
}
