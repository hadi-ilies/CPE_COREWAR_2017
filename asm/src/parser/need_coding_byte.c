/*
** EPITECH PROJECT, 2018
** need_coding_byte
** File description:
** need_coding_byte
*/

#include "my.h"

bool need_coding_byte(char *line)
{
	if (!my_strncmp(line, "live", 4))
		return (false);
	if (!my_strncmp(line, "zjmp", 4))
		return (false);
	if (!my_strncmp(line, "fork", 4))
		return (false);
	if (!my_strncmp(line, "lfork", 5))
		return (false);
	return (true);
}
