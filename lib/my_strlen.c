/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** task03
*/

#include <stddef.h>

size_t my_strlen(char const *str)
{
	size_t i = 0;

	if (!str)
		return (0);
	for (; str[i] != '\0'; i++);
	return (i);
}
