/*
** EPITECH PROJECT, 2018
** prototype
** File description:
** prototype
*/

#pragma once

#include "player.h"

void help(char *exe);
int corewar(char tab[], size_t nb_player, player_t *player);
size_t get_nb_player(int nb_arg, char **arg_tab);
bool cor_to_tab(char tab[], char *file_name, int address);
size_t get_type_from_coding_byte(char coding_byte, size_t arg_num);
