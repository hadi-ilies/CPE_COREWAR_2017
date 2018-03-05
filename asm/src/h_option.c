/*
** EPITECH PROJECT, 2018
** h_option
** File description:
** h_option
*/

#include "my.h"

void error_message(char *binary_name)
{
	my_printf("USAGE\n\t%s file_name[.s]\n\n", binary_name);
	my_printf("DESCRIPTION\n\tfile_name\tfile in assembly language to be\
	converted into\n\t\t\tfile_name.cor file, an executable in the Virtual\
	\n\t\t\tMachine\n");
}

bool h_option(int argc, char **argv)
{
	if (argc != 2) {
		error_message(argv[0]);
		return (false);
	}
	if (my_strcmp(argv[1], "-h"))
		return (true);
	error_message(argv[0]);
	return (false);
}
