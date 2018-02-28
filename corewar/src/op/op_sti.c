/*
** EPITECH PROJECT, 2018
** op_sti
** File description:
** op_sti
*/

#include "prototype.h"

void op_sti(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	//0b 68 01 00 00 00 13 00 00 00 01
	char coding_byte = tab[player[player_num].offset + 1];
	size_t reg = tab[player[player_num].offset + 2] - 1;
	short arg1_short = 0;
	int arg1_int = 0;
	short arg2_short = 0;
	int arg2_int = 0;
	size_t d = 3;
	int add = 0;

	printf("%d ", (char)reg);
	(void)nb_player;
	if (get_type_from_coding_byte(coding_byte, 1) == T_DIR) {
		arg1_int += tab[player[player_num].offset + d];
		arg1_int <<= 8;
		arg1_int += tab[player[player_num].offset + d + 1];
		arg1_int <<= 8;
		arg1_int += tab[player[player_num].offset + d + 2];
		arg1_int <<= 8;
		arg1_int += tab[player[player_num].offset + d + 3];
		d += 4;
		printf("%d ", arg1_int);
		add += arg1_int;
	}
	else {
		arg1_short += tab[player[player_num].offset + d];
		arg1_short <<= 8;
		arg1_short += tab[player[player_num].offset + d + 1];
		d += 2;
		printf("%d ", arg1_short);
		add += (int)arg1_short;
	}
	if (get_type_from_coding_byte(coding_byte, 2) == T_DIR) {
		arg2_int += tab[player[player_num].offset + d];
		arg2_int <<= 8;
		arg2_int += tab[player[player_num].offset + d + 1];
		arg2_int <<= 8;
		arg2_int += tab[player[player_num].offset + d + 2];
		arg2_int <<= 8;
		arg2_int += tab[player[player_num].offset + d + 3];
		d += 4;
		printf("%d ", arg2_int);
		add += arg2_int;
	}
	else {
		arg2_short += tab[player[player_num].offset + d];
		arg2_short <<= 8;
		arg2_short += tab[player[player_num].offset + d + 1];
		d += 2;
		printf("%d ", arg2_short);
		add += (int)arg2_short;
	}
	printf("| add : %d\n", add);
	tab[player[player_num].offset + add + 3] = player[player_num].reg[reg];
	for (size_t i = 0; i < MEM_SIZE; i++) {      /* tmp */
		printf("%x ", tab[i]);              /* tmp */
	}                                          /* tmp */
	printf("\n");                             /* tmp */
	//exit(0);
	player[player_num].offset += d;
}
