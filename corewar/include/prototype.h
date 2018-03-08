/*
** EPITECH PROJECT, 2018
** prototype
** File description:
** prototype
*/

#pragma once

#include <stdlib.h>
#include "corewar.h"
#include "player.h"

typedef struct {
	char c;
	char cb;
	char an;
} vector3c_t;

void help(char *exe);
int corewar(corewar_t *core, size_t nb_player, player_t *player);
size_t get_nb_player(int nb_arg, char **arg_tab);
bool cor_to_tab(char tab[], char *file_name, int address);
char get_type_from_coding_byte(char code, char coding_byte, char arg_num);
ssize_t get_size_from_coding_byte(char code, char coding_byte, char arg_num);
char get_char(char tab[], player_t *player);
char *get_arg(char tab[], player_t *player, vector3c_t *prm);
int get_int1(char tab[], player_t *player, vector3c_t *prm);
int get_int2(char tab[], player_t *player, vector3c_t *prm);
vector3c_t *v3c(char code, char coding_byte, char arg_num);
