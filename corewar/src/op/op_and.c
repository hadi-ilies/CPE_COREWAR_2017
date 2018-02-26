/*
** EPITECH PROJECT, 2018
** and
** File description:
** and
*/

#include "player.h"

void op_and(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	//06 64 01 00 00 00 00 01

	char *r1 = NULL;
	char *r2 = NULL;
	char *r3 = NULL;
	bool *carry = &player[player_num].carry;
	size_t type_1 = get_type_from_conding_byte(&r1, 0);
	size_t type_2 = get_type_from_conding_byte(&r1, 1);
	size_t type_3 = get_type_from_conding_byte(&r1, 2);

	if (type_1 == T_REG)
		(*r1) = &tab[player[player_num].offset + 1];
	if (type_2 == T_REG)
		(*r2) = &player[player_num.offset + 2];
	(*r3) = (*r1) & (*r2);
	if ((*registre_3) == 0)
		(*carry) = ((*carry) ? false : true);
	player[player_num].offset += 4;
}
