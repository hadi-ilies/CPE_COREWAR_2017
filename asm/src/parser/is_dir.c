/*
** EPITECH PROJECT, 2018
** is_dir
** File description:
** is_dir
*/

#include "asm.h"
#include "my.h"

/*
** Return the value written after DIRECT_CHAR ('%') if it is valid
*/

bool put_int_instruct(inst_t *inst, int dir, char *buf)
{
	char tmp = 0;
	int i = inst->pos + sizeof(dir);
	int rev_dir = REV_ENDIAN(dir);

	(inst->nparam)++;
	while (inst->pos < i) {
		tmp = rev_dir & 255;
		inst->instruct[inst->pos] = tmp;
		rev_dir = rev_dir >> 8;
		(inst->pos)++;
	}
	if (inst->pos >= END_INSTRUCT)
		return (false);
	if (inst->need_coding_byte)
		inst->instruct[1] = (inst->instruct[1] + 2) << 2;
	free(buf);
	return (true);
}

bool is_dir(char *line, inst_t *inst, asm_t *asm_s)
{
	int i = 0;
	int dir = 0;
	char *buf = NULL;

	if (!IS_CORRECT_PARAM(inst->instruct[0] - 1, inst->nparam, T_DIR))
		return (false);
	if (line[1] != LABEL_CHAR) {
		for (; IS_NUM(line[i + 1]); i++);
		if (!(buf = my_strndup(line + 1, i)) || !my_atoi(&dir, buf))
			return (false);
	} else if (line[1] == LABEL_CHAR) {
		for (; IS_LABEL_CHAR(line[i + 2]); i++);
		if (!(buf = my_strndup(line + 2, i)))
			return (false);
		dir = get_sub_label(buf, asm_s);
	} else
		return (false);
	return (put_int_instruct(inst, dir, buf));
}
