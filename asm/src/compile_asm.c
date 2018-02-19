/*
** EPITECH PROJECT, 2018
** compile_asm
** File description:
** compile_asm
*/

#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "my.h"

bool compile_asm(asm_t *asm_s)
{
	char *line;

	while ((line = get_next_line(asm_s->asm_fd)) != NULL) {
		PROG_CODE = my_strcat_to_tab(PROG_CODE, line);
		asm_s->err_line++;
	}
	return (true);
}
