/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** offset_move.c
*/

#include "player.h"

void offset_move(size_t *offset, int move)
{
	if ((int)(*offset + move) < 0)
		*offset += MEM_SIZE;
	*offset += move;
	if (*offset + move >= MEM_SIZE)
		*offset -= MEM_SIZE;
}
