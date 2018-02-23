/*
** EPITECH PROJECT, 2018
** get_mnemonic_instruc
** File description:
** get_mnemonic_instruc
*/

#include "asm.h"

/*
** Returns the mnemonic of the statement on the line. If a label is declared
** on the line, we move the pointer to erase it and get the instruction,
** if it exists
*/

char get_mnemonic_instruc(asm_t *asm_s, int nline)
{
	int i = 0;
	char mnemonic = 0;
	char *line = ASM_CODE[nline];

	while (ASM_LABELS[i].label != NULL && ASM_LABELS[i].line != nline)
		i++;
	if (ASM_LABELS[i].line == nline)
		line += my_strlen(ASM_LABELS[i].label);
	return (mnemonic);
}
