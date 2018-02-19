/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** my_strncmp.c
*/

#include "prototype.h"

bool my_strncmp(char *str1, char *str2, size_t n)
{
	char tmp;
	bool result;

	if (my_strlen(str1) < my_strlen(str2))
		return (0);
	tmp = str1[n];
	str1[n] = '\0';
	result = my_strcmp(str1, str2);
	str1[n] = tmp;
	return (result);
}
