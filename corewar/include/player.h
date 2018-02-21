/*
** EPITECH PROJECT, 2018
** player
** File description:
** player
*/

#pragma once

#include <stdbool.h>
#include "op.h"

typedef struct {
	size_t num;
	char *name;
	char reg[REG_NUMBER];
	size_t offset;
	bool carry;
} player_t;
