/*
** EPITECH PROJECT, 2018
** is_ind
** File description:
** is_ind
*/

#include "asm.h"
#include "my.h"

/*
** Write the value written after a number or a LABEL_CHAR (':') if it is valid
*/

bool put_short_instruct(inst_t *inst, short ind, char *buf)
{
	char tmp = 0;
	int i = inst->pos + sizeof(ind);
	int rev_ind = REV_ENDIAN_SHORT(ind);

	if (i == END_INSTRUCT)
		return (false);
	while (inst->pos < i) {
		tmp = rev_ind & 255;
		inst->instruct[i] = tmp;
		rev_ind = rev_ind >> 8;
		(inst->pos)++;
	}
	if (inst->pos >= END_INSTRUCT)
		return (false);
	if (inst->need_coding_byte)
		inst->instruct[1] = (inst->instruct[1] + 3) << 2;
	free(buf);
	return (true);
}

bool is_ind(char *line, inst_t *inst, asm_t *asm_s)
{
	int i = 0;
	short ind = 0;
	int int_ind = 0;
	char *buf;

	(void) asm_s;
	if (!IS_CORRECT_PARAM(inst->instruct[0] - 1, inst->nparam, T_IND))
		return (-1);
	if (IS_NUM(line[i])) {
		for (; IS_NUM(line[i]); i++);
		buf = my_strndup(line, i);
		if (!(buf = my_strndup(line, i)) || !my_atoi(&int_ind, buf))
			return (-1);
		ind = int_ind;
	} else if (line[1] == LABEL_CHAR) {
		for (; IS_LABEL_CHAR(line[i + 1]); i++);
		if (!(buf = my_strndup(line + 1, i)))
			return (false);
		//récupérer la déclaration du label en question et soustraire
		//leur "distance"
	} else
		return (false);
	(inst->nparam)++;
	return (put_short_instruct(inst, ind, buf));
}
