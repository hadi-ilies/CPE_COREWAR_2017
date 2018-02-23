/*
** EPITECH PROJECT, 2018
** get_id_instruct
** File description:
** get_id_instruct
*/

#include "asm.h"

/*
** Returns the id of the instruction on the line. If a label is declared
** on the line, we move the pointer to erase it and get the instruction,
** if it exists
*/

char get_id_instruct(asm_t *asm_s, int nline)
{
	int i = 0;
	char *line = ASM_CODE[nline];
	char *mnemo = NULL;

	if (line == NULL)
		return (-1);
	while (ASM_LABELS[i].label != NULL && ASM_LABELS[i].line != nline)
		i++;
	if (ASM_LABELS[i].line == nline)
		line += my_strlen(ASM_LABELS[i].label);
	line += clean_str(line);
	for (int i = 0; op_tab[i].mnemonic != NULL; i++) {
		mnemo = op_tab[i].mnemonique;
		if (!my_strncmp(mnemo, line, my_strlen(mnemo)))
			return (op_tab[0].code);
	}
	return (-1);
}
