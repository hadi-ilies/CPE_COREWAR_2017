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

#define CREATE_PLAYER player_create(num, address, arg_tab[i], core->nbr_cycle)

typedef struct {
	char c;
	char cb;
	char an;
} vector3c_t;

void incre_address(size_t *num, size_t *address, corewar_t *core);
int insert_adress(char **arg_tab, corewar_t *core);
void n_option(char **arg_tab, int *i, size_t *num);
void a_option(char **arg_tab, int *i, size_t *address);
void dump_option(corewar_t *core, char **arg_tab, int *i);
size_t get_dump(char **arg_tab, int i);
size_t get_num(char **arg_tab, int i);
size_t get_address(char **arg_tab, int i);
int get_nb_arg(char **arg_tab);
void play(corewar_t *core, size_t player_num);
void play2(corewar_t *core, size_t pl_n);
void help(char *exe);
bool test_header(char *file_name);
int corewar(corewar_t *core);
size_t get_nb_player(int nb_arg, char **arg_tab);
bool cor_to_tab(char tab[], char *file_name, int address);
char get_type_from_coding_byte(char code, char coding_byte, char arg_num);
ssize_t get_size_from_coding_byte(char code, char coding_byte, char arg_num);
char get_char(char tab[], player_t *player);
char *get_arg(char tab[], player_t *player, vector3c_t *prm);
int get_int1(char tab[], player_t *player, vector3c_t *prm);
int get_int2(char tab[], player_t *player, vector3c_t *prm);
vector3c_t *v3c(char code, char coding_byte, char arg_num);
