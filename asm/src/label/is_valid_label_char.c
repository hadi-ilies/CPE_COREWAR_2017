/*
** EPITECH PROJECT, 2018
** is_valid_label_char
** File description:
** is_valid_label_char
*/

#include "asm.h"

bool is_valid_label_char(char c)
{
	for (int i = 0; LABEL_CHARS[i] != '\0'; i++)
		if (c == LABEL_CHARS[i])
			return (true);
	return (false);
}
