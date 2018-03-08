/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** set_reg.c
*/

#include "player.h"

void set_reg(char reg[REG_SIZE], int nb)
{
	reg[0] = (nb & 0xff000000) >> 8 * 3;
	reg[1] = (nb & 0x00ff0000) >> 8 * 2;
	reg[2] = (nb & 0x0000ff00) >> 8 * 1;
	reg[3] = (nb & 0x000000ff) >> 8 * 0;
}
