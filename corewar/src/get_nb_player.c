/*
** EPITECH PROJECT, 2018
** get_nb_player
** File description:
** get_nb_player
*/

#include "prototype.h"

size_t get_nb_player(int nb_arg, char **arg_tab)
{
	size_t nb_player = nb_arg - 1;

	for (int i = 0; i < nb_arg; i++) {
		if (!my_strcmp(arg_tab[i], "-dump"))
			nb_player -= 2;
		if (!my_strcmp(arg_tab[i], "-n"))
			nb_player -= 2;
		if (!my_strcmp(arg_tab[i], "-a"))
			nb_player -= 2;
	}
	return (nb_player);
}
