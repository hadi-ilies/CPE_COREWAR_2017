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

bool parse_label(char *line, ssize_t *pos)
{
	for (; *line != '\0'; line += get_next_arg(line)) {
		if (*line == 'r')
			*pos += 1;
		else if (*line == DIRECT_CHAR)
			*pos += 4;
		else if (IS_NUM(*line) || *line == LABEL_CHAR)
			*pos += 2;
		else
			return (false);
	}
	return (true);
}

ssize_t get_pos_label(char **tab, size_t nline)
{
	ssize_t pos = 0;
	size_t i = 0;
	size_t j = 0;
	char *line;

	if (tab == NULL)
		return (-1);
	for (; tab[i] != NULL && i < nline - 2; i++) {
		line = tab[i];
		if (is_label(line))
			j += get_next_arg(line);
		pos += need_coding_byte(line);
		j += get_next_arg(line);
		if (parse_label(line + j, &pos) == false)
			return (-1);
	}
	return (i == 0 ? pos + i : pos + i - 1);
}
