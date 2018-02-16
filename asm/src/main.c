/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "asm.h"
#include "project.h"
#include "my.h"

int main(int argc, char **argv)
{
	asm_t asm_s;

	if (argc != 2 || !h_option(argv[0], argv[1]))
		return (EXIT_FAILURE);
	if ((asm_s.asm_fd = open_asm(argv[1])) < 0)
		return (EXIT_FAILURE);
	asm_s.champ_fd = create_champ_file(argv[1]);
	my_put_nbr(asm_s.champ_fd);
	return (0);
}
