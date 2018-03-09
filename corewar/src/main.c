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
