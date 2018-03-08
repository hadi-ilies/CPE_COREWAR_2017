/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "player.h"
#include "my.h"

void op_live(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	// 01 00 00 00 01
	int num = tab[player[player_num].offset + 1];

	num <<= 8;
	num += tab[player[player_num].offset + 2];
	num <<= 8;
	num += tab[player[player_num].offset + 3];
	num <<= 8;
	num += tab[player[player_num].offset + 4];
	for (size_t i = 0; i < nb_player; i++)
		if ((size_t)num == player[i].num) {
			player[i].live = true;
			my_printf("The player %d(", num);
			my_printf("%s) is alive.\n", player[i].name);
			break;
		}
	player[player_num].offset += 5;
}
