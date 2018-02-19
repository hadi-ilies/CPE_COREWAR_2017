/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"

void help(char *exe)
{
	my_printf("USAGE\n%s [-dump nbr_cycle] [[-n prog_number] [-a loa", exe);
	my_printf("ad_address] prog_name] ...\n\nDESCRIPTION\n\t-dump nbr_cyc");
	my_printf("le\tdumps the memory after the nbr_cycle execution (if the");
	my_printf(" round isn't\n\t\t\talready over) with the following forma");
	my_printf("t:  32 bytes/line in\n\t\t\thexadecimal (A0BCDEFE1DD3...)");
	my_printf("\n\t-n prog_number\tsets the next program's number.  By de");
	my_printf("fault, the first free number\n\t\t\tin the parameter order");
	my_printf("\n\t-a load_address\tsets the next program's loading addre");
	my_printf("ss.  When no address is\n\t\t\tspecified, optimize the add");
	my_printf("resses so that the processes are as far\n\t\t\taway from e");
	my_printf("ach other as possible.  The addresses are MEM_SIZE modulo");
	my_printf("\n");
}

int main(int nb_arg, char **arg_tab)
{
	if (nb_arg >= 1 && !my_strcmp(arg_tab[1], "-h")) {
		help(arg_tab[0]);
		return (0);
	}
	return (0);
}
