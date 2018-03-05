/*
** EPITECH PROJECT, 2018
** get_id_instruct
** File description:
** get_id_instruct
*/

#include "asm.h"
#include "my.h"

/*
** Check if the instruction has a coding byte.
** Check if it takes indexes as parameters)
** Move the pointer to the first parameterMove the
** Returns the id of the instruction on the line.
*/

int my_wordlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0' && str[i] != ' '; i++);
	return (i);
}

void is_index(bool index[MAX_ARGS_NUMBER], char *mnemo)
{
	if (!my_strcmp(mnemo, "zjmp"))
		index[0] = true;
	if (!my_strcmp(mnemo, "ldi")) {
		index[0] = true;
		index[1] = true;
	}
	if (!my_strcmp(mnemo, "lldi")) {
		index[0] = true;
		index[1] = true;
	}
	if (!my_strcmp(mnemo, "sti")) {
		index[1] = true;
		index[2] = true;
	}
	if (!my_strcmp(mnemo, "fork"))
		index[0] = true;
}

char get_id_instruct(inst_t *inst)
{
	char *mnemo;

	for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
		mnemo = op_tab[i].mnemonique;
		if (!my_strncmp(inst->line, mnemo, my_wordlen(inst->line))) {
			inst->need_coding_byte = need_coding_byte(inst->line);
			inst->pos = (inst->need_coding_byte ? 2 : 1);
			inst->line += get_next_arg(inst->line);
			is_index(inst->is_index, mnemo);
			return (op_tab[i].code);
		}
	}
	return (-1);
}
