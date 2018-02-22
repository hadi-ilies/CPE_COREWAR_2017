/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar
*/

#include "prototype.h"

//typedef void (*op)(char *tab, player_t *player) op_t;

void loop_coorwar(char *tab, size_t nb_player, player_t *player, int *i)
{
	if (player[i].cycle == 0) {
		op_tab[player[i]->offset].function(tab, player);
		player[i].cycle = op_tab[player[i]->offset].nbr_cycles;
		player[i]->offset++; //
		if (player[i]->offset >= MEM_SIZE)
			player[i]->offset = 0;
	}
}

int corewar(char *tab, size_t nb_player, player_t *player)
{
	(void)tab;
	(void)nb_player;
	(void)player;

	while (1) {
		for (int i = 0; i < nb_player; i++) {
			loop_coorwar(tab, nb_player, player, &i);
			player[i].cycle--;
		}
	}
	return (0);
}
