/*
** EPITECH PROJECT, 2018
** op_sti
** File description:
** op_sti
*/

#include "prototype.h"

void op_sti(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	//0b 68 01 00 0f 00 01
	size_t i_code = player[player_num].offset;
	char code = get_char(tab, &player[player_num]);
	char cb = get_char(tab, &player[player_num]);
	int nb1 = get_int2(tab, &player[player_num], v3c(code, cb, 0));
	int nb2 = get_int1(tab, &player[player_num], v3c(code, cb, 1));
	int nb3 = get_int1(tab, &player[player_num], v3c(code, cb, 2));
	int nb = 0;

	(void)nb_player;
	nb = (nb2 + nb3) % IDX_MOD;
	offset_move(&i_code, nb);
	for (size_t i = 0; i < REG_SIZE; i++) {
		tab[i_code] = player[player_num].reg[nb1][i];
		offset_move(&i_code, 1);
	}
}
