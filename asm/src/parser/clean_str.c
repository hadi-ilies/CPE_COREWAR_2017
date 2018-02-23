/*
** EPITECH PROJECT, 2018
** clean_str
** File description:
** clean_str
*/

#include <stddef.h>

size_t clean_str(char *line)
{
	size_t i = 0;

	if (line == NULL)
		return (0);
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}
