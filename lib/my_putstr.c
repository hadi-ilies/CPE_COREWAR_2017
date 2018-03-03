/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** task02
*/

#include "my.h"

size_t my_putstr(char const *str)
{
	size_t a = 0;

	if (str == NULL)
		return (my_putstr("(nil)\n"));
	while (str[a] != '\0') {
		my_putchar(str[a]);
		a++;
	}
	return (a);
}
