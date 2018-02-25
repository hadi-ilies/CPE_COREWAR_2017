/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** asm.h
*/

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include "op.h"

#define FLAGS		(O_CREAT | O_WRONLY | O_TRUNC | O_APPEND)
#define MODE		(S_IROTH | S_IWGRP | S_IRUSR | S_IWUSR | S_IRGRP)
#define SIZE_ARG_MAX    BIGGEST(REG_SIZE, DIR_SIZE, IND_SIZE)

#define PROG_SIZE	asm_s->header.prog_size
#define ASM_CODE	asm_s->asm_code
#define ASM_LABELS	asm_s->labels
#define CHAMP_CODE	asm_s->champ_code

#define IS_NUM(x)		(x >= '0' && x <= '9')
#define BIGGEST(x, y, z)	(x > y ? (x > z ? x : z) : (y > z ? y : z))
#define REV_ENDIAN(x)							\
	((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) |	\
	 (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
#define IS_CORRECT_PARAM(x, y, z)	((op_tab[(int)x].type[y] & z) == 1)

extern const char DELIM[3];

typedef struct
{
	char	*label;
	size_t	line;
} label_t;

typedef struct
{
	header_t	header;
	int		asm_fd;
	int		champ_fd;
	char		*line_err;
	char		**asm_code;
	label_t		*labels;
	char		*champ_code;
} asm_t;

bool h_option(int argc, char **argv);
bool init_struct(asm_t *asm_s, char *path);
bool compile_asm(asm_t *asm_s);
char *get_str_entrecote(char *str);
void erase_comment(char *line, size_t error_line);
bool fill_header(asm_t *asm_s);
bool write_binary_code(asm_t *asm_s);

label_t *get_labels(char **tab);

size_t clean_str(char *line);

bool parser_instruction(asm_t *asm_s);
char get_id_instruct(label_t *labels, char **line, size_t i);
bool check_nbr_arg(char id, char *line);
char write_args(char **line, char id, char *instruct);

char is_reg(char **line, char id, int nparam);
char *is_dir(char **line, char id, int nparam);
char *is_ind(char **line, char id, int nparam);
