/*
** EPITECH PROJECT, 2018
** is_reg
** File description:
** is_reg
*/

#include "asm.h"
#include "my.h"

/*
** Write the number of the register written after the 'r' if it is valid
*/

char is_valid_reg(char *reg)
{
	int nb = 0;

	if (my_atoi(&nb, reg) == false)
		return (false);
	return ((nb > 0 && nb < REG_NUMBER) ? nb : -1);
}

bool is_reg(char *line, inst_t *inst, asm_t *asm_s)
{
	int i = 0;
	char *tmp;
	char nb;

	(void) asm_s;
	if (!IS_CORRECT_PARAM(inst->instruct[0] - 1, inst->nparam, T_REG))
		return (false);
	line++;
	for (; IS_NUM(line[i]); i++);
	tmp = my_strndup(line, i);
	if (tmp == NULL || (nb = is_valid_reg(tmp)) == -1)
		return (false);
	free(tmp);
	(inst->nparam)++;
	if (i == END_INSTRUCT)
		return (false);
	inst->instruct[inst->pos] = nb;
	inst->pos++;
	if (inst->pos >= END_INSTRUCT)
		return (false);
	return (true);
}
