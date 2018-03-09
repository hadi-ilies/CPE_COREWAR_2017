/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "player.h"
#include "my.h"

static int get_num(char tab[], player_t *player, size_t player_num)
{
	int num = 0;

	num += tab[player[player_num].offset];
	offset_move(&player[player_num].offset, 1);
	num <<= 8;
	num += tab[player[player_num].offset];
	offset_move(&player[player_num].offset, 1);
	num <<= 8;
	num += tab[player[player_num].offset];
	offset_move(&player[player_num].offset, 1);
	num <<= 8;
	num += tab[player[player_num].offset];
	offset_move(&player[player_num].offset, 1);
	return (num);
}

void op_live(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	int num;

	offset_move(&player[player_num].offset, 1);
	num = get_num(tab, player, player_num);
	for (size_t i = 0; i < nb_player; i++)
		if ((size_t)num == player[i].num) {
			player[i].live = true;
			my_printf("The player %d(", num);
			my_printf("%s) is alive.\n", player[i].name);
			break;
		}
}
