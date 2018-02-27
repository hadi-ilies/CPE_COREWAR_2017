/*
** EPITECH PROJECT, 2018
** is_ind
** File description:
** is_ind
*/

#include "asm.h"
#include "my.h"

/*
** Returns the value if it is valid
*/

short is_ind(char *line, char id, int nparam)
{
	int i = 0;
	short ind = 0;
	int int_ind = 0;
	char *nb;

	if (!IS_CORRECT_PARAM(id, nparam, T_IND))
		return (-1);
	for (; IS_NUM(line[i]); i++);
	nb = my_strndup(line, i);
	*line += i;
	if (nb == NULL)
		return (-1);
	if (my_atoi(&int_ind, nb) == false)
		return (-1);
	ind = int_ind;
	free(nb);
	return (ind);
}
