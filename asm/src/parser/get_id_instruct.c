/*
** EPITECH PROJECT, 2018
** get_id_instruct
** File description:
** get_id_instruct
*/

#include "asm.h"
#include "my.h"

/*
** Returns the id of the instruction on the line. If a label is declared
** on the line, we move the pointer to erase it and get the instruction,
** if it exists
*/

int my_wordlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0' && str[i] != ' '; i++);
	return (i);
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
			return (op_tab[i].code);
		}
	}
	return (-1);
}
