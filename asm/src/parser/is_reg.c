/*
** EPITECH PROJECT, 2018
** is_reg
** File description:
** is_reg
*/

#include "op.h"
#include "my.h"

int is_valid_reg(char *reg)
{
	int nb = 0;

	if (my_atoi(&nb, reg) == false)
		return (false);
	return (nb > 0 && nb < REG_NUMBER)) ? nb : -1);
}

bool is_correct_arg(char *reg)
{
	return ((op_tab[index].type[index2] & T_REG) == 1);
}

char is_reg(char **line)
{
	int i = 0;
	char reg = 0;
	char *tmp;

	if (**line != 'r')
		return (-1);
	*line += 1;
	for (; IS_NUM(*line[i]); i++);
	tmp = my_linendup(*line, i);
	*line += i;
	if (tmp == NULL || (reg = is_reg_in_range(tmp)) == -1)
		return (-1);
	if (!is_correct_arg(tmp))
		return (-1);
	return (reg);
}
