/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** __DESCRIPTION__
*/

#include "asm.h"
#include "my.h"

bool already_exist(label_t *labels, char *str, int len, int nb_label)
{
	for (int i = 0; i < nb_label; i++)
		if (!my_strncmp(str, labels[i].label, len))
			return (true);
	return (false);
}
