/*
** EPITECH PROJECT, 2018
** h_option
** File description:
** h_option
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

bool h_option(char *binary_name, char *arg)
{
	int i = my_strlen(arg);

	if (strcmp(arg, "-h") || (arg[i - 1] == 's' && arg[i - 2] == '.'))
		return (true);
	my_printf("USAGE\n\t%s file_name[.s]\n\n", binary_name);
	my_printf("DESCRIPTION\n\tfile_name\tfile in assembly language to be\
	converted into\n\t\t\tfile_name.cor file, an executable in the Virtual\
	\n\t\t\tMachine\n");
	return (false);
}
