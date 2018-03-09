/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "op.h"
#include "player.h"
#include "corewar.h"
#include "prototype.h"

void incre_address(size_t *num, size_t *address, corewar_t *core)
{
	(*num)++;
	(*address) += MEM_SIZE / core->nb_player;
	(*address) >= MEM_SIZE ? (*address) -= MEM_SIZE : 0;
}

int insert_adress(char **arg_tab, corewar_t *core)
{
	int nb_arg = get_nb_arg(arg_tab);
	size_t num = 1;
	size_t address = 0;
	size_t pi = 0;

	for (int i = 1; i < nb_arg; i++) {
		if (!my_strcmp(arg_tab[i], "-dump") && nb_arg > i + 1)
			core->nbr_cycle = get_dump(arg_tab, &i);
		COND_AD
		num = get_num(arg_tab, &i);
		else if (!my_strcmp(arg_tab[i], "-a") && nb_arg > i + 1)
			address = get_address(arg_tab, &i);
		else {
			if (COND)
				return (84);
			C_P;
			incre_address(&num, &address, core);
		}
	}
	return (0);
}

int main(int nb_arg, char **arg_tab)
{
	corewar_t core;

	if (nb_arg == 1 || (nb_arg >= 1 && !my_strcmp(arg_tab[1], "-h"))) {
		help(arg_tab[0]);
		return (0);
	}
	core = corewar_create(get_nb_player(nb_arg, arg_tab));
	core.nbr_cycle = CYCLE_TO_DIE;
	core.nb_put_live = 0;
	if (core.nb_player < 2 || core.nb_player > MAX_NB_PLAYER)
		return (84);
	if (core.player == NULL)
		return (84);
	if (insert_adress(arg_tab, &core) == 84)
		return (84);
	corewar(&core);
	corewar_destroy(&core);
	return (0);
}
