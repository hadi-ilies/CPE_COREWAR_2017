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

char *is_ind(char **line, char id, int nparam)
{
	int i = 0;
	char *nb;

	if (!IS_CORRECT_PARAM(id, nparam, T_IND))
		return (NULL);
	for (; IS_NUM(*line[i]); i++);
	nb = my_strndup(*line, i);
	*line += i;
	if (nb == NULL)
		return (NULL);
	return (nb);
}
