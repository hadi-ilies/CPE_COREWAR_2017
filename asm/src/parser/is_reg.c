/*
** EPITECH PROJECT, 2018
** is_reg
** File description:
** is_reg
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

/*
** Write the number of the register written after the 'r' if it is valid
*/

char is_valid_reg(char *reg)
{
	int nb = 0;

	if (reg == NULL)
		return (-1);
	if (my_atoi(&nb, reg) == false)
		return (false);
	free(reg);
	return ((nb > 0 && nb < REG_NUMBER) ? nb : -1);
}

bool is_reg(char *line, inst_t *inst)
{
	int i = 0;
	char nb;

	if (!IS_CORRECT_PARAM(inst->instruct[0] - 1, inst->nparam, T_REG))
		return (false);
	for (; IS_NUM(line[i + 1]); i++);
	if ((nb = is_valid_reg(my_strndup(line + 1, i))) == -1)
		return (false);
	inst->nparam++;
	inst->instruct[inst->pos] = nb;
	inst->pos++;
	if (inst->pos >= END_INSTRUCT)
		return (false);
	if (inst->need_coding_byte)
		inst->instruct[1] = (inst->instruct[1] + 1) << 2;
	return (true);
}
