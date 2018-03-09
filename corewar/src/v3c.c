/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** v3c.c
*/

#include <stdlib.h>
#include "prototype.h"

vector3c_t *v3c(char code, char coding_byte, char arg_num)
{
	vector3c_t *v3c = malloc(sizeof(vector3c_t));

	if (v3c == NULL)
		return (NULL);
	v3c->c = code;
	v3c->cb = coding_byte;
	v3c->an = arg_num;
	return (v3c);
}
