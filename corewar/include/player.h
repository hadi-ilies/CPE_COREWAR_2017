/*
** EPITECH PROJECT, 2018
** player
** File description:
** player
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include "op.h"

typedef struct {
	size_t num;
	char name[PROG_NAME_LEN + 1];
	char reg[REG_NUMBER][REG_SIZE];
	size_t offset;
	bool carry;
	bool alive;
	size_t cycle;
} player_t;

player_t player_create(size_t num, size_t offset, char *file_name);
void player_destroy(player_t *player);
void set_reg(char reg[REG_SIZE], int nb);
void offset_move(size_t *offset, int move);
