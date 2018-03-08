/*
** EPITECH PROJECT, 2018
** add.c
** File description:
** add.c
*/

#include "player.h"

void op_add(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	char *registre_1 = &tab[player[player_num].offset + 1];
	char *registre_2 = &tab[player[player_num].offset + 2];
	char *registre_3 = &tab[player[player_num].offset + 3];
	bool *carry = &player[player_num].carry;

	(void)nb_player;
	(*registre_3) = (*registre_1) + (*registre_2);
	if ((*registre_3) == 0)
		*carry = true;
	else
		*carry = false;
	player[player_num].offset += 4;
}
