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
		my_printf("\033[0;34m%s, %s\n\033[1;36m", argv[0], argv[1]);
		my_printf("Error : \n\033[0;31m%s\n \033[00m", asm_s.line_err);
		return (EXIT_FAILURE);
	}
	if (fill_header(&asm_s, argv) == false)
		return (EXIT_FAILURE);
	if (write_binary_code(&asm_s, argv[1]) == false)
		return (EXIT_FAILURE);
	my_free_tab(asm_s.asm_code);
	return (EXIT_SUCCESS);
}
