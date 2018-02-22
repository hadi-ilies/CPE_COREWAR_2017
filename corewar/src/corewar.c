/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar
*/

#include "prototype.h"

//typedef void (*op)(char *tab, player_t *player) op_t;

void player_play(char *tab, player_t *player)
{
	if (player->cycle == 0) {
		//op_tab[player->offset].function(tab, player);
		player->cycle = op_tab[player->offset].nbr_cycles;
		player->offset++; //
		if (player->offset >= MEM_SIZE)
			player->offset = 0;
	}
	player->cycle--;
}

int corewar(char *tab, size_t nb_player, player_t *player)
{
	while (1) {
		for (size_t i = 0; i < nb_player; i++)
			player_play(tab, player + i);
		for (size_t i = 0; i < nb_player; i++)
	}
	return (0);
}
