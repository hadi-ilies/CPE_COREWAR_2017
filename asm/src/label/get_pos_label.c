/*
** EPITECH PROJECT, 2018
** get_pos_label
** File description:
** get_pos_label
*/

#include <stdlib.h>
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

bool is_an_index(int nparam, char *mnemo)
{
	if (!my_strncmp(mnemo, "zjmp", 4) && nparam == 0)
		return (true);
	if (!my_strncmp(mnemo, "ldi", 3) && (nparam == 0 || nparam == 1))
		return (true);
	if (!my_strncmp(mnemo, "lldi", 3) && (nparam == 0 || nparam == 1))
		return (true);
	if (!my_strncmp(mnemo, "sti", 3) && (nparam == 1 || nparam == 2))
		return (true);
	if (!my_strncmp(mnemo, "fork", 4) && nparam == 0)
		return (true);
	return (false);
}

bool parse_label(char *line, int j, ssize_t *pos)
{
	int nparam = 0;
	char *mnemo = my_strndup(line, j);

	if (mnemo == NULL)
		return (false);
	line += j;
	for (; *line != '\0'; line += get_next_arg(line)) {
		if (*line == 'r')
			*pos += 1;
		if (*line == DIRECT_CHAR)
			*pos += (is_an_index(nparam, mnemo) ? 2 : 4);
		if (IS_NUM(*line) || *line == LABEL_CHAR)
			*pos += 2;
		if (ERROR(*line))
			return (false);
		nparam++;
	}
	free(mnemo);
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
		j = 0;
		line = tab[i];
		if (is_label(line))
			j += get_next_arg(line);
		pos += need_coding_byte(line);
		j += get_next_arg(line);
		if (parse_label(line, j, &pos) == false)
			return (-1);
	}
	return (pos + i + 1);
}
