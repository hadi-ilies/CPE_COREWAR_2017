/*
** EPITECH PROJECT, 2018
** get_id_instruct
** File description:
** get_id_instruct
*/

#include "asm.h"
#include "my.h"

/*
** Returns the id of the instruction on the line. If a label is declared
** on the line, we move the pointer to erase it and get the instruction,
** if it exists
*/

char get_id_instruct(label_t *labels, char **line, size_t nline)
{
	int i = 0;
	char *mnemo = NULL;

	if (line == NULL)
		return (-1);
	for (;labels[i].label != NULL && labels[i].line != nline; i++);
	if (labels[i].line == nline)
		*line += my_strlen(labels[i].label) + 1;
	for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
		mnemo = op_tab[i].mnemonique;
		if (!my_strncmp(*line, mnemo, my_strlen(mnemo))) {
			*line += my_strlen(mnemo) + 1;
			return (op_tab[0].code);
		}
	}
	return (-1);
}
