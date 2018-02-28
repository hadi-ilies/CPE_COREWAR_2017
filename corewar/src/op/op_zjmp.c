/*
** EPITECH PROJECT, 2018
** zjmp
** File description:
** zjmp
*/

#include "player.h"

/*void my_putshort_bin(short nb)
{
	my_printf("%d", nb & 0b1000000000000000 ? 1 : 0);
	my_printf("%d", nb & 0b0100000000000000 ? 1 : 0);
	my_printf("%d", nb & 0b0010000000000000 ? 1 : 0);
	my_printf("%d", nb & 0b0001000000000000 ? 1 : 0);

	my_printf("%d", nb & 0b0000100000000000 ? 1 : 0);
	my_printf("%d", nb & 0b0000010000000000 ? 1 : 0);
	my_printf("%d", nb & 0b0000001000000000 ? 1 : 0);
	my_printf("%d", nb & 0b0000000100000000 ? 1 : 0);

	my_printf("%d", nb & 0b0000000010000000 ? 1 : 0);
	my_printf("%d", nb & 0b0000000001000000 ? 1 : 0);
	my_printf("%d", nb & 0b0000000000100000 ? 1 : 0);
	my_printf("%d", nb & 0b0000000000010000 ? 1 : 0);

	my_printf("%d", nb & 0b0000000000001000 ? 1 : 0);
	my_printf("%d", nb & 0b0000000000000100 ? 1 : 0);
	my_printf("%d", nb & 0b0000000000000010 ? 1 : 0);
	my_printf("%d", nb & 0b0000000000000001 ? 1 : 0);
}*/

void op_zjmp(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	// 09 ff ff ff fb
	int num = tab[player[player_num].offset + 1];

	(void)nb_player;
	num <<= 8;
	num = tab[player[player_num].offset + 2];
	num <<= 8;
	num = tab[player[player_num].offset + 3];
	num <<= 8;
	num = tab[player[player_num].offset + 4];
	if (player[player_num].carry)
		player[player_num].offset += num;
	else
		player[player_num].offset += DIR_SIZE + 1;
}
