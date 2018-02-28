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

int my_wordlen(char *str, char c)
{
	int i = 0;

	for (; str[i] != '\0' && str[i] != c; i++);
	return (i);
}

int need_coding(char *line)
{
	if (!my_strncmp(line, "live", 4))
		return (1);
	if (!my_strncmp(line, "zjmp", 4))
		return (1);
	if (!my_strncmp(line, "fork", 4))
		return (1);
	if (!my_strncmp(line, "lfork", 5))
		return (1);
	return (2);
}

char get_id_instruct(inst_t *inst)
{
	char *mnemo;

	for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
		mnemo = op_tab[i].mnemonique;
		if (!my_strncmp(inst->line, mnemo, my_wordlen(inst->line, ' '))) {
			inst->pos = need_coding(inst->line);
			inst->line += get_next_arg(inst->line);
			return (op_tab[i].code);
		}
	}
	return (-1);
}
