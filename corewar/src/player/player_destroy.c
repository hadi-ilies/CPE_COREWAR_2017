/*
** EPITECH PROJECT, 2018
** player_destroy
** File description:
** player_destroy
*/

#include <stdlib.h>
#include "player.h"

void player_destroy(player_t *player)
{
	free(player->name);
}
