/*
** EPITECH PROJECT, 2018
** is_reg
** File description:
** is_reg
*/

#include "asm.h"
#include "my.h"

/*
** Returns the number of the register written after the 'r' if it is valid
*/

int is_valid_reg(char *reg)
{
	int nb = 0;

	if (my_atoi(&nb, reg) == false)
		return (false);
	return ((nb > 0 && nb < REG_NUMBER) ? nb : -1);
}

char is_reg(char *line, char id, int nparam)
{
	int i = 0;
	char *tmp;
	char nb;

	if (!IS_CORRECT_PARAM(id - 1, nparam, T_REG))
		return (-1);
	*line += 1;
	for (; IS_NUM(line[i]); i++);
	tmp = my_strndup(line, i);
	*line += (i + 1);
	if (tmp == NULL || (nb = is_valid_reg(tmp)) == -1)
		return (-1);
	free(tmp);
	return (nb);
}
