/*
** EPITECH PROJECT, 2018
** get
** File description:
** get
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
