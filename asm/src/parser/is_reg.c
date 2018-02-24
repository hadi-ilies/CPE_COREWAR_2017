/*
** EPITECH PROJECT, 2018
** is_reg
** File description:
** is_reg
*/

#include "op.h"
#include "my.h"

/*
** Returns the number of the register written after the 'r' if it is valid
*/

int is_valid_reg(char *reg)
{
	int nb = 0;

	if (my_atoi(&nb, reg) == false)
		return (false);
	return (nb > 0 && nb < REG_NUMBER)) ? nb : -1);
}

bool is_correct_arg(char *reg, int id, int nparam)
{
	return ((op_tab[(int)id].type[nparam] & T_REG) == 1);
}

char is_reg(char **line, char id, int nparam)
{
	int i = 0;
	char *tmp;
	char nb;

	for (; IS_NUM(*line[i]); i++);
	tmp = my_strndup(*line, i);
	*line += i;
	if (tmp == NULL || (nb = is_valid_reg(tmp)) == -1)
		return (-1);
	if (!is_correct_arg(tmp))
		return (-1);
	return (nb);
}
