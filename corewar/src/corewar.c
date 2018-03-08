/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar
*/

#include "prototype.h"
#include "op.h"
#include "my.h"
#include "op_functions.h"

void play2(corewar_t *core, size_t pl_n)
{
	player_t **pl = &core->player;
	size_t *nb_pl = &core->nb_player;
	player_t player = core->player[pl_n];
	bool tmp = true;

	for (size_t i = 0; op_function[i].code != 0; i++)
		if (core->tab[player.offset] == op_function[i].code) {
			op_function[i].code == 1 ? core->nb_put_live++ : 0;
			op_function[i].function(core->tab, *pl, *nb_pl, pl_n);
			player.cycle = op_tab[i].nbr_cycles;
			tmp = false;
			break;
		}
	tmp ? offset_move(&player.offset, 1) : 0;
}

void play(corewar_t *core, size_t player_num)
{
	if (core->player[player_num].cycle == 0)
		play2(core, player_num);
	core->player[player_num].cycle ? core->player[player_num].cycle-- : 0;
	if (core->player[player_num].cycle_live)
		core->player[player_num].cycle_live--;
	if (core->player[player_num].live)
		if (core->player[player_num].cycle_live)
			core->player[player_num].cycle_live = core->nbr_cycle;
	core->player[player_num].live = false;
}

size_t nb_player_alive(size_t nb_player, player_t *player)
{
	size_t nb = 0;

	for (size_t i = 0; i < nb_player; i++)
		if (player[i].cycle_live)
			nb++;
	return (nb);
}

player_t get_player_win(size_t nb_player, player_t *player)
{
	for (size_t i = 0; i < nb_player; i++)
		if (player[i].cycle_live)
			return (player[i]);
	return (*player);
}

void sub_nbr_cycle(corewar_t *core)
{
	if (core->nb_put_live >= NBR_LIVE) {
		core->nb_put_live -= NBR_LIVE;
		if (CYCLE_DELTA > core->nbr_cycle)
			core->nbr_cycle = 0;
		else
			core->nbr_cycle -= CYCLE_DELTA;
	}
}

bool test_win(size_t nb_player, player_t *player)
{
	if (nb_player_alive(nb_player, player) <= 1) {
		player_t player_won = player[0];

		if (nb_player_alive(nb_player, player) == 1)
			player_won = get_player_win(nb_player, player);
		my_printf("The player %d(", player_won.num);
		my_printf("%s) has won.\n", player_won.name);
		return (true);
	}
	return (false);
}

int corewar(corewar_t *core)
{
	while (!test_win(core->nb_player, core->player)) {
		for (size_t i = 0; i < core->nb_player; i++)
			play(core, i);
		sub_nbr_cycle(core);
	}
	return (0);
}
