/*
** EPITECH PROJECT, 2018
** corewar2
** File description:
** corewar2
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
