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

bool put_int_instruct(inst_t *instruct, int dir, char *buf)
{
	char tmp = 0;
	int i = instruct->pos + sizeof(dir);
	int rev_dir = REV_ENDIAN(dir);

	while (instruct->pos < i) {
		tmp = rev_dir & 255;
		instruct->instruct[instruct->pos] = tmp;
		rev_dir = rev_dir >> 8;
		(instruct->pos)++;
	}
	if (instruct->pos >= END_INSTRUCT)
		return (false);
	free(buf);
	return (true);
}

bool is_dir(char *line, inst_t *inst, asm_t *asm_s)
{
	int i = 0;
	int dir = 0;
	char *buf = NULL;

	(void) asm_s;
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
		dir = 15;
		//récupérer la déclaration du label en question et soustraire
		//leur "distance"
	} else
		return (false);
	(inst->nparam)++;
	return (put_int_instruct(inst, dir, buf));
}
