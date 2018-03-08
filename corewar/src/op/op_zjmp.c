/*
** EPITECH PROJECT, 2018
** zjmp
** File description:
** zjmp
*/

#include "player.h"

void op_zjmp(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	// 09 ff fb
	short num = tab[player[player_num].offset + 1];

	(void)nb_player;
	num <<= 8;
	num = tab[player[player_num].offset + 2];
	if (player[player_num].carry)
		offset_move(&player[player_num].offset, num % IDX_MOD);
	else
		player[player_num].offset += 3;
}
