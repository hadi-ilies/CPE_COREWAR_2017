/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar
*/

#include <stdio.h> /* tmp */
#include "prototype.h"
#include "op.h"
#include "my.h"
#include "op_functions.h"

void play(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	if (player[player_num].cycle == 0) {
		bool tmp = true;

		for (size_t i = 0; op_function[i].code != 0; i++)
			if (tab[player[player_num].offset] == op_function[i].code) {
				//printf("code : %d\n", op_function[i].code);
				op_function[i].function(tab, player, nb_player, player_num);
				player[player_num].cycle = op_tab[i].nbr_cycles;
				tmp = false;
				break;
			}
		tmp ? player[player_num].offset++ : 0;
		if (player[player_num].offset >= MEM_SIZE)
			player[player_num].offset = 0;
	}
	player[player_num].cycle > 0 ? player[player_num].cycle-- : 0;
}

int corewar(corewar_t *core, size_t nb_player, player_t *player)
{
	while (1) {
		for (size_t i = 0; i < nb_player; i++)
			play(core->tab, player, nb_player, i);
		usleep(10000);
	}
	return (0);
}
