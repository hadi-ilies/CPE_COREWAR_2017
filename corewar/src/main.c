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

size_t get_dump(char **arg_tab, int *i)
{
	int tmp;

	*i += 1;
	if (!my_atoi(&tmp, arg_tab[*i]) || tmp <= 0)
		return (84);
	return (tmp);
}

size_t get_num(char **arg_tab, int *i)
{
	int tmp;

	*i += 1;
	if (my_atoi(&tmp, arg_tab[*i]) == false || tmp < 0)
		return (84);
	return (tmp);
}

size_t get_address(char **arg_tab, int *i)
{
	int tmp;

	*i += 1;
	if (my_atoi(&tmp, arg_tab[*i]) == false || tmp < 0 || tmp >= MEM_SIZE)
		return (84);
	return (tmp);
}

int get_nb_arg(char **arg_tab)
{
	int i = 0;

	for (; arg_tab[i] != NULL; i++);
	return (i);
}

int main2(char **arg_tab, corewar_t *core)
{
	int nb_arg = get_nb_arg(arg_tab);
	size_t num = 1;
	size_t address = 0;
	size_t pi = 0;

	for (int i = 1; i < nb_arg; i++) {
		if (!my_strcmp(arg_tab[i], "-dump") && nb_arg > i + 1)
			core->nbr_cycle = get_dump(arg_tab, &i);
		else if (!my_strcmp(arg_tab[i], "-n") && nb_arg > i + 1)
			num = get_num(arg_tab, &i);
		else if (!my_strcmp(arg_tab[i], "-a") && nb_arg > i + 1)
			address = get_address(arg_tab, &i);
		else {
			if ((int)i >= nb_arg)
				return (84);
			if (test_header(arg_tab[i]) == false)
				return (84);
			if (cor_to_tab(core->tab, arg_tab[i], address) == false)
				return (84);
			core->player[pi++] = player_create(num, address, arg_tab[i], core->nbr_cycle);
			num++;
			address += MEM_SIZE / core->nb_player;
			address >= MEM_SIZE ? address -= MEM_SIZE : 0;
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
	if (main2(arg_tab, &core) == 84)
		return (84);
	corewar(&core);
	corewar_destroy(&core);
	return (0);
}
