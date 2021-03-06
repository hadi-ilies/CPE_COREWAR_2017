/*
** EPITECH PROJECT, 2018
** my_free_tab
** File description:
** my_free_tab
*/

#include <stddef.h>
#include <stdlib.h>

void my_free_tab(char **tab)
{
	if (tab == NULL)
		return;
	for (size_t i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
}
