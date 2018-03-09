/*
** EPITECH PROJECT, 2018
** aff
** File description:
** aff
*/

#include "player.h"
#include "prototype.h"

void op_or(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	char code = get_char(tab, &player[player_num]);
	char cb = get_char(tab, &player[player_num]);
	int nb1 = get_int1(tab, &player[player_num], v3c(code, cb, 0));
	int nb2 = get_int1(tab, &player[player_num], v3c(code, cb, 1));
	int nb3 = get_int2(tab, &player[player_num], v3c(code, cb, 2));

	(void)nb_player;
	for (size_t i = 0; i < REG_SIZE - 1; i++)
		player[player_num].reg[nb3][i] = 0;
	player[player_num].reg[nb3][REG_SIZE - 1] = (char)(nb1 | nb2);
	player[player_num].carry = (nb1 | nb2 ? false : true);
}
