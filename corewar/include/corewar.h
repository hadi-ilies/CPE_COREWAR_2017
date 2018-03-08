/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar
*/

#pragma once

#include "op.h"
#include "player.h"

typedef struct {
	char tab[MEM_SIZE];
	size_t nbr_cycle;
	size_t nb_put_live;
	size_t nb_player;
	player_t *player;
} corewar_t;

corewar_t corewar_create(size_t nb_player);
void corewar_destroy(corewar_t *core);
