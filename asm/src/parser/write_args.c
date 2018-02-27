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

char is_valid_coding_byte(char coding_byte, char id)
{
	char valid_coding_byte = coding_byte;

	(void) id;
	return (valid_coding_byte);
}

char write_args(char *line, char id, char *instruct)
{
	int nparam = 0;
	char coding_byte = 0;
	short ind;
	int dir;

	while (*line != '\0') {
		if (*line == 'r') {
			if ((*instruct = is_reg(line, id, nparam)) == -1)
				return (-1);
			instruct++;
			coding_byte = (coding_byte + 1) << 2;
			nparam++;
		}
		if (*line == DIRECT_CHAR) {
			if ((dir = is_dir(line, id, nparam)) == -1)
				return (-1);
			coding_byte = (coding_byte + 2) << 2;
			nparam++;
		}
		if (IS_NUM(*line) || *line == LABEL_CHAR) {
			if ((ind = is_ind(line, id, nparam)) == -1)
				return (-1);
			coding_byte = (coding_byte + 3) << 2;
			nparam++;
		}
	}
	return (is_valid_coding_byte(coding_byte << 2, id));
}
