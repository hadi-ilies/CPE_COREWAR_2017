/*
** EPITECH PROJECT, 2018
** check_args
** File description:
** check_args
*/

#include "asm.h"
#include "op.h"

/*
** Vérifie si les arguments passés sont bons en fonction du premier caractère
** après la virgule
** Une fois que les arguments sont correctes, on calcule le coding byte et
** on écrit les arguments dans la chaine 'instruct'
*/

char check_args(char **line, char *instruct)
{
	char *reg;
	char *dir;
	char *ind;
	char coding_byte = 0;

	if (**line == 'r')
		if ((reg = is_reg(line)) == NULL)
			return (-1);
	if (**line == DIRECT_CHAR)
		if ((dir = is_dir(line)) == NULL)
			return (-1);
//	if (**line == )
	return (coding_byte);
}
