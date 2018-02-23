/*
** EPITECH PROJECT, 2018
** op_functions
** File description:
** op_functions
*/

#pragma once

#include "player.h"

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

typedef struct {
	char code;
	void (*function)(char *, player_t *, size_t, size_t);
} op_function_t;

extern op_function_t op_function[];
