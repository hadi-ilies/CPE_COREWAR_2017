/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(char const *src, size_t n)
{
	char *dest;
	size_t i = 0;

	if (src == NULL || n <= 0)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	for (; src[i] != '\0' && i != n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
