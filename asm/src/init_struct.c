/*
** EPITECH PROJECT, 2018
** init_struct
** File description:
** init_struct
*/

#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"
#include "my.h"

bool init_struct(asm_t *asm_s, char *path)
{
	if ((asm_s->asm_fd = open(path, O_RDONLY)) < 0)
		return (false);
	my_memset(&asm_s->header, 0, sizeof(header_t));
	asm_s->line_err = NULL;
	asm_s->asm_code = NULL;
	asm_s->champ_code = NULL;
	PROG_SIZE = 0;
	return (true);
}
