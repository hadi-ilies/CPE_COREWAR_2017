/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "player.h"

void op_live(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
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
	player[player_num].cycle = 10;
}
