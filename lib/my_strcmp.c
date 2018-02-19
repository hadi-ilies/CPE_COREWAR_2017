/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_strcmp(char const *str_a, char const *str_b)
{
	if (!str_a || !str_b)
		return (-1);
	if (my_strlen(str_a) != my_strlen(str_b))
		return (1);
	for (int i = 0; str_a[i] != '\0'; i++)
		if (str_a[i] != str_b[i])
			return (1);
	return (0);
}
