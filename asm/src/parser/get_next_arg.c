/*
** EPITECH PROJECT, 2018
** get_next_arg
** File description:
** get_next_arg
*/

#include <stddef.h>

size_t get_next_arg(char *line)
{
	size_t i = 0;

	while (line[i] != '\0' && line[i] != ' ')
		i++;
	return (line[i] == '\0' ? i : i + 1);
}
