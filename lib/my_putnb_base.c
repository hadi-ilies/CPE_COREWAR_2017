/*
** EPITECH PROJECT, 2018
** my_putnb_base
** File description:
** my_putnb_base
*/

#include "my.h"

ssize_t my_putnb_base(int nb, char *base)
{
	if (nb / 10 > 0)
		my_putnb_base(nb / 10, base);
	my_putchar(nb % 10 + *base);
	return (23);
}
