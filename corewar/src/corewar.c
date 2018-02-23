/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** corewar
*/

#include <stdio.h> /* tmp */
#include "prototype.h"
#include "op.h"
#include "my.h"

void play(char tab[], player_t *player, size_t nb_player, size_t player_num)
{
	if (player[player_num].cycle == 0) {
		if (tab[player[player_num].offset] == 1) {

		}
		else if (tab[player[player_num].offset] == 2) {
			//
		}
		else if (tab[player[player_num].offset] == 3) {
			//
		}
		else if (tab[player[player_num].offset] == 4) {
			//
		}
		else if (tab[player[player_num].offset] == 5) {
			//
		}
		else if (tab[player[player_num].offset] == 6) {
			///
		}
		else if (tab[player[player_num].offset] == 7) {
			//
		}
		else if (tab[player[player_num].offset] == 8) {
			//
		}
		else if (tab[player[player_num].offset] == 9) {

		}
		else if (tab[player[player_num].offset] == 10) {
			//
		}
		else if (tab[player[player_num].offset] == 11) {
			///
		}
		else if (tab[player[player_num].offset] == 12) {
			//
		}
		else if (tab[player[player_num].offset] == 13) {
			//
		}
		else if (tab[player[player_num].offset] == 14) {
			//
		}
		else if (tab[player[player_num].offset] == 15) {
			//
		}
		else if (tab[player[player_num].offset] == 16) {
			//
		}
		else
			player[player_num].offset++;
		if (player[player_num].offset >= MEM_SIZE)
			player[player_num].offset = 0;
	}
	player[player_num].cycle--;
}

void adjust_player_cycle(size_t nb_player, player_t *player)
{
	size_t min = player[0].cycle;

	for (size_t i = 1; i < nb_player; i++)
		if (player[i].cycle < min)
			min = player[i].cycle;
	for (size_t i = 0; i < nb_player; i++)
		player[i].cycle -= min;
}

int corewar(char *tab, size_t nb_player, player_t *player)
{
	player[0].offset += 15;
	player[1].offset += 15;
	while (1) {
		for (size_t i = 0; i < nb_player; i++)
			play(tab, player, nb_player, i);
		adjust_player_cycle(nb_player, player);
		//return (0); /* tmp */
	}
	return (0);
}
