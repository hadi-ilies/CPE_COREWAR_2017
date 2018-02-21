/*
** EPITECH PROJECT, 2018
** prototype
** File description:
** prototype
*/

#pragma once

#include "player.h"
#include "my.h"

void help(char *exe);
int corewar(char *tab, size_t nb_player, player_t *player);
size_t get_nb_player(int nb_arg, char **arg_tab);
bool cor_to_tab(char *tab, char *file_name, int address);
