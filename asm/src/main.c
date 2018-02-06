/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "asm.h"
#include "project.h"
#include "proto.h"

void print_help(char *binary)
{
	my_printf("USAGE\n\t%s file_name[.s]\n\n", binary);
	my_printf("DESCRIPTION\n\tfile_name\tfile in assembly language to be\
	converted into\n\t\t\tfile_name.cor file, an executable in the Virtual\
	\n\t\t\tMachine\n");
	exit(0);
}

void error(int argc, char **argv)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (!strcmp(argv[1], "-h"))
		print_help(argv[0]);
}

int main(int argc, char **argv)
{
	error(argc, argv);
	return (0);
}
