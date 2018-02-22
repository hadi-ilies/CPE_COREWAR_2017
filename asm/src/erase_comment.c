/*
** EPITECH PROJECT, 2018
** erase_comment
** File description:
** erase_comment
*/

#include <stddef.h>

void erase_comment(char *line, size_t error_line)
{
	size_t i = 0;

	if (line == NULL || error_line < 3)
		return;
	for (;line[i] != '#' && line[i] != '\0'; i++);
	line[i] = '\0';
}
