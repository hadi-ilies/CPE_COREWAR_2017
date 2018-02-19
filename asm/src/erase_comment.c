/*
** EPITECH PROJECT, 2018
** erase_comment
** File description:
** erase_comment
*/

#include <stddef.h>

void erase_comment(char *line)
{
	size_t i = 0;

	if (line == NULL)
		return;
	for (;line[i] != '#' && line[i] != '\0'; i++);
	line[i] = '\0';
}
