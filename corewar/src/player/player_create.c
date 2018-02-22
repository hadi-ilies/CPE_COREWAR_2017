/*
** EPITECH PROJECT, 2018
** player_create
** File description:
** player_create
*/

#include "player.h"

char *get_name(char *name_file)
{
	char *name;

	//
	return (name);
}

player_t player_create(size_t num, size_t offset, char *name_file)
{
	player_t player;

	player.num = num;
	player.name = get_name(name_file);
	for (size_t i = 0; i < REG_NUMBER; i++)
		player.reg[i] = 0;
	player.offset = offset;
	player.carry = false;
	player.alive = false;
	player.cycle = 0;
	return (player);
}
