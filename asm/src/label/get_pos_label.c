/*
** EPITECH PROJECT, 2018
** get_pos_label
** File description:
** get_pos_label
*/

#include "asm.h"
#include "my.h"

/*
** Get the position of the instruction from the beginning of the code in bytes
*/

bool is_label(char *line)
{
	for (size_t i = 0; line[i] != '\0'; i++)
		if (line[i + 1] == LABEL_CHAR && line[i] != DIRECT_CHAR)
			return (true);
	return (false);
}

size_t get_pos_label(char **tab, size_t nline)
{
	size_t pos = 0;

	for (size_t i = 2; tab[i] != NULL && i < nline; i++) {
		i = (is_label(tab[i])) ? get_next_arg(tab[i]) : i;
		pos += need_coding_byte(tab[i]);
		i = get_next_arg(tab[i]);
		if (tab[i][0] == 'r') {
			i = get_next_arg(tab[i]);
			pos++;
		} else if (IS_NUM(tab[i][0]) || tab[i][0] == LABEL_CHAR) {
			i = get_next_arg(tab[i]);
			pos += 2;
		} else if (tab[i][0] == DIRECT_CHAR) {
			i = get_next_arg(tab[i]);
			pos += 4;
		} else
			return (-1);
	}
	return (pos);
}
