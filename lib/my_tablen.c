/*
** EPITECH PROJECT, 2018
** my_tablen
** File description:
** my_tablen
*/

#include <stddef.h>

size_t my_tablen(char **tab)
{
	size_t i = 0;

	if (tab == NULL)
		return (0);
	for (; tab[i] != NULL; i++);
	return (i);
}
