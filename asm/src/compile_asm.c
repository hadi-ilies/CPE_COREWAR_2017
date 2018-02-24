/*
** EPITECH PROJECT, 2018
** compile_asm
** File description:
** compile_asm
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

bool stock_line_in_tab(asm_t *asm_s, char *line)
{
	asm_s->err_line++;
	if (*line != '\0') {
		line = make_str_clean_again(line, DELIM);
		ASM_CODE = my_strcat_to_tab(ASM_CODE, line);
		if (ASM_CODE == NULL)
			return (false);
	}
	else
		free(line);
	return (true);
}

bool compile_asm(asm_t *asm_s)
{
	char *line;

	while ((line = get_next_line(asm_s->asm_fd)) != NULL) {
		erase_comment(line, asm_s->err_line);
		if (stock_line_in_tab(asm_s, line) == false)
			return (false);
	}
	ASM_LABELS = get_labels(ASM_CODE);
	if (parser_instruction(asm_s) == false)
		return (false);
	return (true);
}
