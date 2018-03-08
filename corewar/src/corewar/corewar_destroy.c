/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar_destroy.c
*/

#include <stdlib.h>
#include "corewar.h"

void corewar_destroy(corewar_t *core)
{
	free(core->player);
}
