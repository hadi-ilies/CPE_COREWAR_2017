/*
** EPITECH PROJECT, 2018
** get_sub_label
** File description:
** get_sub_label
*/

#include "asm.h"
#include "my.h"

int get_pos(char *name, label_t *labels)
{
	int i = 0;

	while (labels[i].label != NULL) {
		if (!my_strcmp(labels[i].label, name))
			return (labels[i].pos);
		i++;
	}
	return (-1);
}

int get_sub_label(char *buf, inst_t *inst, asm_t *asm_s)
{
	int pos_label = 0;
	int pos_call = PROG_SIZE;

	(void) inst;
	if ((pos_label = get_pos(buf, asm_s->labels)) == -1)
		return (-1);
#include <stdio.h>
	printf("pos_label : %d\n", pos_label);
	printf("pos_call : %d\n", pos_call);
	return (pos_label - pos_call);
}
