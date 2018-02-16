/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** task02
*/

#include "my.h"

void my_putstr(char const *str)
{
	int a = 0;

	while (str[a] != '\0') {
		my_putchar(str[a]);
		a++;
	}
}
