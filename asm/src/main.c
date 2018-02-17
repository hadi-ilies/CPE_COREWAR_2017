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
	if (!compile_asm(&asm_s)) {
		my_printf("%s, %s, Line : %d", *argv, argv[1], asm_s.err_line);
		return (EXIT_FAILURE);
	}
	if (write_header(&asm_s) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
