/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** get_arg.c
*/

#include <stdlib.h>
#include "prototype.h"

char get_char(char tab[], player_t *player)
{
	char nb = tab[player->offset];

	offset_move(&player->offset, 1);
	return (nb);
}

char *get_reg(char tab[], player_t *player)
{
	char *nb = malloc(sizeof(char) * 1);

	if (nb == NULL)
		return (NULL);
	for (size_t i = 0; i < 1; i++)
		nb[i] = get_char(tab, player);
	return (nb);
}

char *get_ind(char tab[], player_t *player)
{
	char *nb = malloc(sizeof(char) * IND_SIZE);

	if (nb == NULL)
		return (NULL);
	for (size_t i = 0; i < IND_SIZE; i++)
		nb[i] = get_char(tab, player);
	return (nb);
}

char *get_dir(char tab[], player_t *player)
{
	char *nb = malloc(sizeof(char) * DIR_SIZE);

	if (nb == NULL)
		return (NULL);
	for (size_t i = 0; i < DIR_SIZE; i++)
		nb[i] = get_char(tab, player);
	return (nb);
}

char *get_arg(char tab[], player_t *player, vector3c_t *prm)
{
	char *arg = NULL;

	if (prm == NULL)
		return (NULL);
	if (get_type_from_coding_byte(prm->c, prm->cb, prm->an) == T_REG)
		arg = get_reg(tab, player);
	if (get_type_from_coding_byte(prm->c, prm->cb, prm->an) == T_IND)
		arg = get_ind(tab, player);
	if (get_type_from_coding_byte(prm->c, prm->cb, prm->an) == T_DIR)
		arg = get_dir(tab, player);
	return (arg);
}
