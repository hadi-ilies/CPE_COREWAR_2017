/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <string.h>
#include "asm.h"
#include "project.h"
#include "my.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	h_option(argv[0], argv[1]);
	return (0);
}
