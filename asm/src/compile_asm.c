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
	char *line = NULL;

	while ((line = get_next_line(asm_s->asm_fd)) != NULL) {
//		printf("%s\n", line);
		asm_s->err_line++;
	}
	return (true);
}
