/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** task07
*/

#include "my.h"

void my_put_nbr(int nb)
{
	if (nb == -2147483648) {
		my_putstr("-2147483648");
		return;
	}
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	if (nb > 9)
		my_put_nbr(nb / 10);
	my_putchar(nb % 10 + '0');
}
