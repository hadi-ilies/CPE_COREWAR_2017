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

char *get_name(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	int n;
	char *name = malloc(sizeof(char) * (PROG_NAME_LEN + 1));

	if (fd == -1 || name == NULL || lseek(fd, sizeof(int), SEEK_SET) == -1)
		return (NULL);
	n = read(fd, name, sizeof(char) * PROG_NAME_LEN + 1);
	close(fd);
	if (n < 0)
		return (NULL);
	return (name);
}

player_t player_create(size_t num, size_t offset, char *file_name)
{
	player_t player;

	player.num = num;
	//player.name = get_name(file_name);
	for (size_t i = 0; i < REG_NUMBER; i++)
		player.reg[i] = 0;
	player.offset = offset;
	player.carry = false;
	player.alive = false;
	player.cycle = 0;
	return (player);
}
