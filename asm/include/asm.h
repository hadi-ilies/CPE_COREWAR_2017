/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** asm.h
*/

#pragma once

#include <stdbool.h>
#include "op.h"

#define FLAGS		(O_CREAT | O_WRONLY | O_TRUNC | O_APPEND)
#define MODE		(S_IROTH | S_IWGRP | S_IRUSR | S_IWUSR | S_IRGRP)
#define PROG_CODE	asm_s->prog_code
#define PROG_SIZE	asm_s->header.prog_size

#define WRITE_NUMBER(fd, number) my_write(fd, number)
#define REV_ENDIAN(x)							\
	((((x) & 0xFF000000) >> 24) | (((x) & 0x00FF0000) >> 8)		\
	 | (((x) & 0x0000FF00) << 8) | (((x) & 0x000000FF) << 24))

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
void erase_comment(char *line);
bool write_header(asm_t *asm_s);
