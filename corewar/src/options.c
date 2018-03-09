/*
** EPITECH PROJECT, 2018
** options
** File description:
** options
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

void n_option(char **arg_tab, int *i, size_t *num)
{
	if (!my_strcmp(arg_tab[*i], "-n")) {
		*num = get_num(arg_tab, *i);
		(*i) += 1;
	}
}

void a_option(char **arg_tab, int *i, size_t *address)
{
	if (!my_strcmp(arg_tab[*i], "-a")) {
		*address = get_address(arg_tab, *i);
		(*i) += 1;
	}
}

void dump_option(corewar_t *core, char **arg_tab, int *i)
{
	if (!my_strcmp(arg_tab[*i], "-dump")) {
		core->nbr_cycle = get_dump(arg_tab, *i);
		(*i) += 1;
	}
}

int insert_adress(char **arg_tab, corewar_t *core)
{
	int nb_arg = get_nb_arg(arg_tab);
	size_t num = 1;
	size_t address = 0;
	size_t pi = 0;

	for (int i = 1; i < nb_arg; i++) {
		if (nb_arg > i + 1) {
			dump_option(core, arg_tab, &i);
			n_option(arg_tab, &i, &num);
			a_option(arg_tab, &i, &address);
		}
		if (i >= nb_arg || !test_header(arg_tab[i]) ||
		    !cor_to_tab(core->tab, arg_tab[i], address))
			return (84);
		else {
			core->player[pi++] = CREATE_PLAYER;
			incre_address(&num, &address, core);
		}
	}
	return (0);
}
