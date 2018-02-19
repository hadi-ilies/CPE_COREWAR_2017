/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** my_strcmp.c
*/

#include "prototype.h"

bool my_strcmp(char *str1, char *str2)
{
	for (size_t i = 0; str1[i] == str2[i]; i++) {
		if (str1[i] == '\0')
			return (true);
	}
	return (false);
}
