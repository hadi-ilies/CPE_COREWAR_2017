/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar_create.c
*/

#include <stdlib.h>
#include "corewar.h"

corewar_t corewar_create(size_t nb_player)
{
	corewar_t core = {.nb_player = nb_player};

	core.player = malloc(sizeof(player_t) * core.nb_player);
	core.player == NULL ? core.nb_player = nb_player : 0;
	return (core);
}
