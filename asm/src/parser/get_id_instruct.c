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

char get_id_instruct(label_t *labels, char **line)
{
	int i = 0;
	char *mnemo = NULL;

	if (line == NULL)
		return (-1);
	while (labels[i].label != NULL && labels[i].line != nline)
		i++;
	if (labels[i].line == nline)
		*line += my_strlen(labels[i].label);
	*line += clean_str(line);
	for (int i = 0; op_tab[i].mnemonic != NULL; i++) {
		mnemo = op_tab[i].mnemonique;
		if (!my_strncmp(mnemo, *line, my_strlen(mnemo))) {
			*line += my_strlen(mnemo);
			return (op_tab[0].code);
		}
	}
	return (-1);
}
