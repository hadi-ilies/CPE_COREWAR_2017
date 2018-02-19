/*
** EPITECH PROJECT, 2018
** write_header
** File description:
** write_header
*/

#include <string.h>
#include "asm.h"
#include "my.h"

void fill_rest_0(char *str, int i, int max)
{
	for (; i < max; i++)
		str[i] = 0;
}

bool init_header_struct(asm_t *asm_s)
{
	int i = 0;
	char *name = get_str_entrecote(PROG_CODE[0]);
	char *comment = get_str_entrecote(PROG_CODE[1]);

	if (name == NULL || comment == NULL)
		return (false);
	for (; name[i] != '\0'; i++)
		asm_s->header.prog_name[i] = name[i];
	fill_rest_0(asm_s->header.prog_name, i, PROG_NAME_LEN);
	asm_s->err_line++;
	if (!strncmp(asm_s->header.prog_name, NAME_CMD_STRING, 5))
		return (false);
	for (i = 0; comment[i] != '\0'; i++)
		asm_s->header.comment[i] = comment[i];
	fill_rest_0(asm_s->header.prog_name, i, COMMENT_LEN);
	asm_s->err_line++;
	if (!strncmp(asm_s->header.comment, COMMENT_CMD_STRING, 8))
		return (false);
	return (true);
}

bool write_string(asm_t *asm_s, char *str, int max)
{
	int b = 0;

	if (my_write(asm_s->champ_fd, str) == false)
		return (false);
	for (int i = max - my_strlen(str); i >= 0; i--)
		if (my_write(asm_s->champ_fd, &b) == false)
			return (false);
	return (true);
}

/*
** In the header of .cor : COREWAR_EXEC_MAGIC, NAME, PROG_SIZE - HEADER_SIZE, COMMENT
** PS : A confirmer auprès d'un AER ou d'un mec fort qui a réussi l'ASM
*/

bool write_header(asm_t *asm_s)
{
	asm_s->header.magic = COREWAR_EXEC_MAGIC;
	asm_s->header.prog_size = my_tablen(asm_s->prog_code);
	if (!init_header_struct(asm_s))
		return (false);
	if (!WRITE_NUMBER(asm_s->champ_fd, &asm_s->header.magic))
		return (false);
	if (!write_string(asm_s, asm_s->header.prog_name, PROG_NAME_LEN))
		return (false);
	if (!WRITE_NUMBER(asm_s->champ_fd, ADD_PROG_SIZE - sizeof(header_t)))
		return (false);
	if (!write_string(asm_s, asm_s->header.comment, COMMENT_LEN))
		return (false);
	return (true);
}
