/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** get_int.c
*/

#include <stdlib.h>
#include "prototype.h"

int get_int1(char tab[], player_t *player, vector3c_t *prm)
{
	int nb = 0;
	char *arg = get_arg(tab, player, prm);
	char type = get_type_from_coding_byte(prm->c, prm->cb, prm->an);
	ssize_t size = get_size_from_coding_byte(prm->c, prm->cb, prm->an);

	if (type == T_REG) {
		for (size_t i = 0; i < REG_SIZE; i++) {
			nb <<= 8;
			nb += player->reg[arg[0] - 1][i];
		}
		return (nb);
	}
	for (size_t i = 0; i < (size_t)size; i++) {
		nb <<= 8;
		nb += arg[i];
	}
	free(prm);
	return (nb);
}

int get_int2(char tab[], player_t *player, vector3c_t *prm)
{
	int nb = 0;
	char *arg = get_arg(tab, player, prm);
	char type = get_type_from_coding_byte(prm->c, prm->cb, prm->an);
	ssize_t size = get_size_from_coding_byte(prm->c, prm->cb, prm->an);

	if (type == T_REG)
		return (arg[0] - 1);
	for (size_t i = 0; i < (size_t)size; i++) {
		nb <<= 8;
		nb += arg[i];
	}
	free(prm);
	return (nb);
}
