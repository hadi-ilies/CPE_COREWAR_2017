/*
** EPITECH PROJECT, 2018
** op_functions
** File description:
** op_functions
*/

#pragma once

#include "player.h"

typedef void (*op_function_t)(char *, player_t *, size_t, size_t);

void op_live(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_ld(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_st(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_add(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_sub(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_and(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_or(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_xor(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_zjmp(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_ldi(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_sti(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_fork(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_lld(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_lldi(char tab[], player_t *player, size_t nb_player, size_t player_num);
void op_lfork(char tab[], player_t *player, size_t nb_player,
	size_t player_num);
void op_aff(char tab[], player_t *player, size_t nb_player, size_t player_num);

static op_function_t op_function[] = {
	op_live,
	op_ld,
	op_st,
	op_add,
	op_sub,
	op_and,
	op_or,
	op_xor,
	op_zjmp,
	op_ldi,
	op_sti,
	op_fork,
	op_lld,
	op_lldi,
	op_lfork,
	op_aff
};
