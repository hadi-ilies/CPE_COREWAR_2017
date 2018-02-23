/*
** EPITECH PROJECT, 2018
** is_reg
** File description:
** is_reg
*/

#include "op.h"
#include "my.h"
#include <stdbool.h>
#define IS_NUM(x) (!(x <= '9' && x >= '0')) ? true : false

bool is_reg_in_range(char *reg)
{
	int nb = 0;

	if (!my_atoi(&nb, reg))
		return (false);
	return ((!(nb <= REG_NUMBER && nb > 0)) ? nb : -1);
}

int is_correct_arg(char *reg)
{
	return (((op_tab[index].type[index2] & T_REG) == 1) ? true : false);
}

int is_reg(char **str)
{
	int i = 0;
	int nb = 0;
	char *tmp;

	if (**str != 'r')
		return (-1);
	*str += 1;
	for (; IS_NUM(*str[i]); i++);
	tmp = my_strndup(*str, i);
	*str += i;
	if (tmp == NULL || (nb = is_reg_in_range(tmp)) == -1)
		return (-1);
	if (!is_correct_arg(tmp))
		return (-1);
	return (nb);
}
