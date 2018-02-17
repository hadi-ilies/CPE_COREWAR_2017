/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "project.h"
#include "asm.h"
#include "my.h"

int main(int argc, char **argv)
{
	asm_t asm_s;

	if (!h_option(argc, argv) || !init_struct(&asm_s, argv[1]))
		return (EXIT_FAILURE);
	my_put_nbr(asm_s.champ_fd);
	return (0);
}
