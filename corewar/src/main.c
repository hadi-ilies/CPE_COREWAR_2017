/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <stdio.h> // tmp
#include <stdlib.h> // tmp
#include "my.h"
#include "op.h"
#include "player.h"
#include "prototype.h"

int main(int nb_arg, char **arg_tab)
{
	size_t nbr_cycle = CYCLE_TO_DIE;
	size_t nb_player = get_nb_player(nb_arg, arg_tab);
	player_t *player = malloc(sizeof(player_t) * nb_player);
	char tab[MEM_SIZE] = {0};
	size_t num = 0;
	size_t address = 0;
	size_t player_index = 0;

	if (player == NULL)
		return (84);
	if (nb_player > MAX_NB_PLAYER)
		return (84);
	for (size_t i = 0; i < MEM_SIZE; i++)
		tab[i] = 0;
	if (nb_arg == 1 || (nb_arg >= 1 && !my_strcmp(arg_tab[1], "-h"))) {
		help(arg_tab[0]);
		return (0);
	}
	for (size_t i = 1; (int)i < nb_arg; i++) {
		if (!my_strcmp(arg_tab[i], "-dump") && nb_arg > (int)i + 1) {
			int tmp;

			if (!my_atoi(&tmp, arg_tab[++i]) || nbr_cycle <= 0)
				return (84);
			nbr_cycle = tmp;
			printf("dump : %ld\n", nbr_cycle);
		}
		else if (!my_strcmp(arg_tab[i], "-n") && nb_arg > (int)i + 1) {
			int tmp;

			if (my_atoi(&tmp, arg_tab[++i]) == false || tmp < 0)
				return (84);
			num = tmp;
		}
		else if (!my_strcmp(arg_tab[i], "-a") && nb_arg > (int)i + 1) {
			int tmp;

			if (my_atoi(&tmp, arg_tab[++i]) == false || tmp < 0 || tmp >= MEM_SIZE)
				return (84);
			address = tmp;
		}
		else {
			printf("num : %ld\n", num);
			printf("address : %ld\n", address);
			player[i].offset = address;
			printf(".cor : %s\n", arg_tab[i]);
			if ((int)i >= nb_arg)
				return (84);
			/*if (test_header(arg_tab[i]) == false)
			  return (84);*/
			if (cor_to_tab(tab, arg_tab[i], address) == false)
				return (84);
			player[player_index++] = player_create(num, address, arg_tab[i]);
			num++;
			address += MEM_SIZE / nb_player;
			address >= MEM_SIZE ? address -= MEM_SIZE : 0;
		}
	}
	corewar(tab, nb_player, player);
	for (size_t i = 0; i < nb_player; i++)
		player_destroy(player + i);
	free(player);
	return (0);
}
