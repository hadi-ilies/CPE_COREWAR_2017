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
	int nbr_cycle = CYCLE_TO_DIE;
	int n = 1;
	size_t nb_player = get_nb_player(nb_arg, arg_tab);
	player_t *player = malloc(sizeof(player_t) * nb_player);
	char *tab = malloc(sizeof(char) * MEM_SIZE);

	printf("nb_player : %ld\n", nb_player);
	if (nb_player > MAX_NB_PLAYER)
		return (84);
	for (size_t i = 0; i < MEM_SIZE; i++)
		tab[i] = 0;
	if (nb_arg == 1 || (nb_arg >= 1 && !my_strcmp(arg_tab[1], "-h"))) {
		help(arg_tab[0]);
		return (0);
	}
	//for (size_t i = 0; i < nb_arg; i++)
	if (!my_strcmp(arg_tab[1], "-dump") && nb_arg > 1 + 1) {
		if (!my_atoi(&nbr_cycle, arg_tab[2]) || nbr_cycle <= 0)
			return (84);
		printf("nb : %d\n", nbr_cycle);
		n += 2;
	}
	printf("ok0\n");
	for (size_t i = 0; n < nb_arg; i++) {
		size_t num = i;
		size_t address = MEM_SIZE / nb_player * num;

		printf("address : %ld\n", address);
		if (!my_strcmp(arg_tab[n], "-n") && nb_arg > n + 1) {
			int tmp;

			if (my_atoi(&tmp, arg_tab[n + 1]) == false && tmp >= 0)
				return (84);
			num = tmp;
			n += 2;
		}
		printf("ok\n");
		if (!my_strcmp(arg_tab[n], "-a") && nb_arg > n + 1) {
			int tmp;

			if (my_atoi(&tmp, arg_tab[n + 1]) == false && tmp >= 0)
				return (84);
			address = tmp;
			n += 2;
		}
		printf(".cor : %s\n", arg_tab[n]);
		if (arg_tab[n] == NULL)
			return (84);
		printf("ok4\n");
		/*if (test_header(arg_tab[n]) == false)
		  return (84);*/
		printf("ok5\n");
		if (cor_to_tab(tab, arg_tab[n], address) == false)
			return (84);
		printf("ok6\n");
		n++;
	}
	corewar(tab, nb_player, player);
	free(tab);
	free(player);
	return (0);
}
