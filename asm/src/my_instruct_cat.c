/*
** EPITECH PROJECT, 2018
** my_instruct_cat
** File description:
** my_instruct_cat
*/

#include <stdlib.h>
#include "asm.h"

char *my_instruct_cat(asm_t *asm_s, inst_t *inst)
{
	int i = 0;
	int j = 0;
	char *new = malloc(sizeof(char) * (PROG_SIZE + inst->pos));

	if (new == NULL)
		return (NULL);
	if (CHAMP_CODE != NULL)
		while (i < PROG_SIZE) {
			new[i] = CHAMP_CODE[i];
			i++;
		}
	while (j < inst->pos) {
		new[i] = inst->instruct[j];
		i++;
		j++;
	}
	return (new);
}
