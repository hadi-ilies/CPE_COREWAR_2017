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

void player_play(char *tab, player_t *player)
{
	if (player->cycle == 0) {
		if (tab[player->offset] == 1) {
			size_t num = tab[++player->offset];

			player->offset++;
			num <<= 8;
			num += tab[player->offset++];
			num <<= 8;
			num += tab[player->offset++];
			num <<= 8;
			num += tab[player->offset++];
			printf("player_num : %ld\n", num);
			printf("Le joueur %ld (%s) est en vie.\n", num, player[num].name);
			return;
		}
		else
			player->offset++;
		if (player->offset >= MEM_SIZE)
			player->offset = 0;
	}
	player->cycle--;
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
			player_play(tab, player + i);
		adjust_player_cycle(nb_player, player);
		return (0); /* tmp */
	}
	return (0);
}
