/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "op.h"

void help(char *exe)
{
	my_printf("USAGE\n\t%s [-dump nbr_cycle] [[-n prog_number] [-a l", exe);
	my_printf("oad_address] prog_name] ...\n\nDESCRIPTION\n\t-dump nbr_c");
	my_printf("ycle\tdumps the memory after the nbr_cycle execution (if t");
	my_printf("he round isn't\n\t\t\talready over) with the following for");
	my_printf("mat:  32 bytes/line in\n\t\t\thexadecimal (A0BCDEFE1DD3...");
	my_printf(")\n\t-n prog_number\tsets the next program's number.  By d");
	my_printf("efault, the first free number\n\t\t\tin the parameter orde");
	my_printf("r\n\t-a load_address\tsets the next program's loading addr");
	my_printf("ess.  When no address is\n\t\t\tspecified, optimize the ad");
	my_printf("dresses so that the processes are as far\n\t\t\taway from ");
	my_printf("each other as possible.  The addresses are MEM_SIZE modulo");
	my_printf("\n");
}

int main(int nb_arg, char **arg_tab)
{
	int nbr_cycle = CYCLE_TO_DIE;
	int n = 1;

	if (nb_arg == 1 || (nb_arg >= 1 && !my_strcmp(arg_tab[1], "-h"))) {
		help(arg_tab[0]);
		return (0);
	}
	if (!my_strcmp(arg_tab[1], "-dump") && nb_arg > 1 + 1) {
		if (!my_atoi(&nbr_cycle, arg_tab[2]) || nbr_cycle <= 0)
			return (84);
		printf("nb : %d\n", nbr_cycle);
		n += 2;
	}
	exit(0);
	while (1) {
		if (!my_strcmp(arg_tab[n], "-n") && nb_arg > n + 1) {
			//
			printf("-n %s\n", arg_tab[n + 1]);
			n += 2;
		}
		if (!my_strcmp(arg_tab[n], "-a") && nb_arg > n + 1) {
			//
			printf("-a %s\n", arg_tab[n + 1]);
			n += 2;
		}
		//
		n++;
	}
	return (0);
}
