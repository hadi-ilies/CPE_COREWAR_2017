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

bool get_sub_label(char *buf, asm_t *asm_s, int *dir, short *ind)
{
	int pos_def = 0;
	int pos_call = PROG_SIZE;

	if ((pos_def = get_pos(buf, asm_s->labels)) == -1)
		return (false);
	if (dir != NULL)
		*dir = pos_def - pos_call - 1;
	if (ind != NULL)
		*ind = pos_def - pos_call - 1;
	return (true);
}
