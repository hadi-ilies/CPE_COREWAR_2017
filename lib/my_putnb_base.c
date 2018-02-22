/*
** EPITECH PROJECT, 2018
** my_putnb_base
** File description:
** my_putnb_base
*/

#include "my.h"

ssize_t my_putnb_base(int nb, char *base)
{
	ssize_t size = 0;

	if (base == NULL)
		return (-1);
	if (nb / my_strlen(base) > 0)
		size += my_putnb_base(nb / my_strlen(base), base);
	size += my_putchar(base[nb % my_strlen(base)]);
	return (size);
}
