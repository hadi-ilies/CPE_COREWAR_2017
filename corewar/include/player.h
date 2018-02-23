/*
** EPITECH PROJECT, 2018
** player
** File description:
** player
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include "macros.h"

typedef struct {
	size_t num;
	char name[PROG_NAME_LEN + 1];
	char reg[REG_NUMBER];
	size_t offset;
	bool carry;
	bool alive;
	size_t cycle;
} player_t;

player_t player_create(size_t num, size_t offset, char *file_name);
void player_destroy(player_t *player);
