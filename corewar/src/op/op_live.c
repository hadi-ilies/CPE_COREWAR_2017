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
	int num = tab[player[player_num].offset + 1];

	num <<= 8;
	num += tab[player[player_num].offset + 2];
	num <<= 8;
	num += tab[player[player_num].offset + 3];
	num <<= 8;
	num += tab[player[player_num].offset + 4];
	for (size_t i = 0; i < nb_player; i++)
		if ((size_t)num == player[i].num) {
			my_printf("Le joueur %d (", num);
			my_printf("%s) est en vie.\n", player[i].name);
		}
	player[player_num].offset += 5;
}
