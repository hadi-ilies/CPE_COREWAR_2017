/*
** EPITECH PROJECT, 2018
** aff
** File description:
** aff
*/

#include "prototype.h"

void op_sti(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	char coding_byte = tab[player[player_num].offset + 1];

	(void)nb_player;
	printf("qfsqf : %ld\n", get_type_from_coding_byte(coding_byte, 0));
	printf("qfsqf : %ld\n", get_type_from_coding_byte(coding_byte, 1));
	printf("qfsqf : %ld\n\n", get_type_from_coding_byte(coding_byte, 2));
}
