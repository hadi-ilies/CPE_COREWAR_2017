/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** asm.h
*/

#pragma once

#include <stdbool.h>
#include "op.h"

#define FLAGS	(O_CREAT | O_WRONLY | O_TRUNC | O_APPEND)
#define MODE	(S_IROTH | S_IWGRP | S_IRUSR | S_IWUSR | S_IRGRP)
#define ADD_PROG_SIZE	&asm_s->header.prog_size
#define PROG_CODE asm_s->prog_code

#define WRITE_NUMBER(fd, number) my_write(fd, number)

typedef struct
{
	header_t	header;
	int		asm_fd;
	int		champ_fd;
	size_t		err_line;
	char		**prog_code;
} asm_t;

bool h_option(int argc, char **argv);
bool init_struct(asm_t *asm_s, char *path);
bool compile_asm(asm_t *asm_s);
char *get_str_entrecote(char *str);
bool write_header(asm_t *asm_s);
