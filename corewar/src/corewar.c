/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar
*/

#include <stdio.h> /* tmp */
#include "prototype.h"

//op_tab[player->offset].function(tab, player);
//player->cycle = op_tab[player->offset].nbr_cycles;

void play(char *tab, player_t *player, size_t nb_player, size_t player_num)
{
	if (player[player_num].cycle == 0) {
		if (tab[player[player_num].offset] == 1) {
			size_t num = tab[++player[player_num].offset];

			player[player_num].offset++;
			num <<= 8;
			num += tab[player[player_num].offset++];
			num <<= 8;
			num += tab[player[player_num].offset++];
			num <<= 8;
			num += tab[player[player_num].offset++];
			printf("player_num : %ld\n", num);
			for (size_t i = 0; i < nb_player; i++)
				if (num == player[i].num)
					printf("Le joueur %ld (%s) est en vie.\n", num, player[i].name);
			player[player_num].cycle += 10;
		}
		else
			player[player_num].offset++;
		if (player[player_num].offset >= MEM_SIZE)
			player[player_num].offset = 0;
	}
	player[player_num].cycle--;
}

void adjust_player_cycle(size_t nb_player, player_t *player)
{
	size_t min = player[0].cycle;

	for (size_t i = 1; i < nb_player; i++)
		if (player[i].cycle < min)
			min = player[i].cycle;
	for (size_t i = 0; i < nb_player; i++)
		player[i].cycle -= min;
}

int corewar(char *tab, size_t nb_player, player_t *player)
{
	player[0].offset += 15;
	player[1].offset += 15;
	while (1) {
		for (size_t i = 0; i < nb_player; i++)
			play(tab, player, nb_player, i);
		adjust_player_cycle(nb_player, player);
		return (0); /* tmp */
	}
	return (0);
}
