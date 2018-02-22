/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>

ssize_t my_putchar(char c)
{
	return (write(1, &c, 1));
}
