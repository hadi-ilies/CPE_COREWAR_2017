/*
** EPITECH PROJECT, 2018
** full_error
** File description:
** full_error
*/

#include <stddef.h>
#include "full_error.h"

void *malloc_error(size_t size)
{
	static size_t i = NB_MALLOC_PASS;

	if (i == 0)
		return (NULL);
	i--;
	return (malloc(size));
}

int open_error(const char *pathname, int flags)
{
	static size_t i = NB_OPEN_PASS;

	if (i == 0)
		return (-1);
	i--;
	return (open(pathname, flags));
}
