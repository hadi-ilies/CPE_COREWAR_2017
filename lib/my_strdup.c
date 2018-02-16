/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *my_strdup(char const *src)
{
	char *dest;
	int i = 0;

	if (src == NULL)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * my_strlen(src))))
		return (NULL);
	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
