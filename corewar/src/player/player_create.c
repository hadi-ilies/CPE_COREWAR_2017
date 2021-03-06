/*
** EPITECH PROJECT, 2018
** player_create
** File description:
** player_create
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "player.h"

void get_name(char name[], char *file_name)
{
	int fd = open(file_name, O_RDONLY);

	for (size_t i = 0; i < PROG_NAME_LEN + 1; i++)
		name[i] = '\0';
	if (fd == -1 || name == NULL || lseek(fd, sizeof(int), SEEK_SET) == -1)
		return;
	read(fd, name, sizeof(char) * PROG_NAME_LEN + 1);
	close(fd);
}

player_t player_create(size_t num, size_t offset, char *file_name, size_t nb_c)
{
	player_t player;

	player.num = num;
	get_name(player.name, file_name);
	for (size_t i = 0; i < REG_NUMBER; i++)
		for (size_t j = 0; j < REG_SIZE; j++)
			player.reg[i][j] = 0;
	set_reg(player.reg[0], num);
	player.offset = offset;
	player.carry = false;
	player.live = false;
	player.cycle = 0;
	player.cycle_live = nb_c;
	return (player);
}
