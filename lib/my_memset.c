/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** my_memset
*/

#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
	size_t i = 0;
	char *ptr = s;

	while (i < n) {
		ptr[i] = (char) c;
		i++;
	}
	return (s);
}
