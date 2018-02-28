/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar
*/

#pragma once

typedef struct {
	char tab[];
	size_t nbr_cycle;
} corewar_t;

corewar_t corewar_create(void);
void corewar_destroy(corewar_t *corewar);
