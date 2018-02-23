/*
** EPITECH PROJECT, 2018
** help
** File description:
** help
*/

#include "prototype.h"
#include "my.h"

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
