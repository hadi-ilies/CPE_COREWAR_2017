/*
** EPITECH PROJECT, 2018
** compile_asm
** File description:
** compile_asm
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

bool compile_asm(asm_t *asm_s)
{
	char *line;

	while ((line = get_next_line(asm_s->asm_fd)) != NULL) {
		erase_comment(line, asm_s->err_line);
		if (*line != '\0')
			ASM_CODE = my_strcat_to_tab(ASM_CODE, line);
		else
			free(line);
		asm_s->err_line++;
	}
	game->labels = get_labels(ASM_CODE);
	if (parser_instruction(asm_s) == false)
		return (false);
	return (true);
}
