/*
** EPITECH PROJECT, 2018
** write_header
** File description:
** write_header
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"

void my_memset(char *str, int max)
{
	for (int i = 0; i < max; i++)
		str[i] = 0;
}

bool fill_name_header(asm_t *asm_s)
{
	int i = 0;
	char *name = get_str_entrecote(PROG_CODE[0]);

	if (name == NULL || strncmp(PROG_CODE[0], NAME_CMD_STRING, 5))
		return (false);
	my_memset(asm_s->header.prog_name, COMMENT_LEN);
	for (i = 0; name[i] != '\0'; i++)
		asm_s->header.prog_name[i] = name[i];
	asm_s->err_line++;
	free(name);
	return (true);
}

bool fill_comment_header(asm_t *asm_s)
{
	int i = 0;
	char *comment = get_str_entrecote(PROG_CODE[1]);

	if (comment == NULL || strncmp(PROG_CODE[1], COMMENT_CMD_STRING, 8))
		return (false);
	my_memset(asm_s->header.comment, COMMENT_LEN);
	for (i = 0; comment[i] != '\0'; i++)
		asm_s->header.comment[i] = comment[i];
	asm_s->err_line++;
	free(comment);
	return (true);
}

int file_len(char **tab)
{
	int size = 0;

	if (tab == NULL)
		return (-1);
	for (int i = 0; tab[i] != NULL; i++)
		size += my_strlen(tab[i]);
	return (size);
}

/*
** In the header of .cor : COREWAR_EXEC_MAGIC, NAME, PROG_SIZE - HEADER_SIZE, COMMENT
** PS : A confirmer auprès d'un AER ou d'un mec fort qui a réussi l'ASM
*/

bool write_header(asm_t *asm_s)
{
	asm_s->header.magic = REV_ENDIAN(COREWAR_EXEC_MAGIC);
	PROG_SIZE = REV_ENDIAN(file_len(PROG_CODE) - sizeof(header_t));
	PROG_SIZE = (PROG_SIZE < 0) ? 0 : PROG_SIZE;
	if (!fill_name_header(asm_s) || !fill_comment_header(asm_s))
		return (false);
	write(asm_s->champ_fd, &asm_s->header, sizeof(header_t));
	return (true);
}
