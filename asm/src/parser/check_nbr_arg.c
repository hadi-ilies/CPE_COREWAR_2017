/*
** EPITECH PROJECT, 2018
** check_nbr_arg
** File description:
** check_nbr_arg
*/

#include <stdbool.h>
#include <stdlib.h>
#include "op.h"

bool check_nbr_arg(char id, char *line)
{
	int i = 0;
	int nb_arg = 0;

	if (id < 0 || line == NULL)
		return (false);
	while (line[i] != '\0') {
		if (line[i] == SEPARATOR_CHAR)
			nb_arg++;
		i++;
	}
	if (op_tab[ (int) id].nbr_args != nb_arg + 1)
		return (false);
	return (true);
}
