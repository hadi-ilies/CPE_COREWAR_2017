/*
** EPITECH PROJECT, 2018
** zjmp
** File description:
** zjmp
*/

#include "player.h"

void op_zjmp(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	int num = tab[++player[player_num].offset];

	(void)nb_player;
	my_printf("num bin : [%b]\n", num);
	player[player_num].offset++;
	num <<= 8;
	num = tab[player[player_num].offset++];
	printf("num : %d\n", num);
	//if (player[player_num].carry)
	player[player_num].offset += -5;
	player[player_num].cycle = 20;
}
