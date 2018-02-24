/*
** EPITECH PROJECT, 2018
** write_args
** File description:
** write_args
*/

#include "asm.h"
#include "op.h"

/*
** Vérifie si les arguments passés sont bons en fonction du premier caractère
** après la virgule
** Une fois que les arguments sont correctes, on calcule le coding byte et
** on écrit les arguments dans la chaine 'instruct'
*/

char write_args(char **line, char *instruct)
{
	int nparam = 0;
	char coding_byte = 0;
	char *dir;
	char *ind;

	while (**line != '\0') {
		if (**line == 'r') {
			if ((instruct[3] = is_reg(line)) == -1)
				return (-1);
		}
		if (**line == DIRECT_CHAR)
			if ((dir = is_dir(line)) == NULL)
				return (-1);
//	if (**line == )
	}
	return (coding_byte);
}
