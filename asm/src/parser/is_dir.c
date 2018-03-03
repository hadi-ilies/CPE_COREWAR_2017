/*
** EPITECH PROJECT, 2018
** is_dir
** File description:
** is_dir
*/

#include <byteswap.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

/*
** Return the value written after DIRECT_CHAR ('%') if it is valid
*/

bool put_int_instruct(inst_t *inst, int dir, char *buf)
{
	char tmp = 0;
	int i = inst->pos + sizeof(int);
	short s_dir = dir;
	int rev_dir = bswap_32(dir);

	if (inst->is_index[inst->nparam]) {
		i = inst->pos + sizeof(short);
		rev_dir = bswap_16(s_dir);
	}
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
	(inst->nparam)++;
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
		if (!get_sub_label(buf, asm_s, &dir, NULL))
			return (false);
	}
	else
		return (false);
	return (put_int_instruct(inst, dir, buf));
}
