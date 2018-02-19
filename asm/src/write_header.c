/*
** EPITECH PROJECT, 2018
** write_header
** File description:
** write_header
*/

#include <string.h>
#include <unistd.h>
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

size_t file_size(char **tab)
{
	size_t size = 0;

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
	asm_s->header.magic = COREWAR_EXEC_MAGIC;
	asm_s->header.prog_size = file_size(asm_s->prog_code) - sizeof(header_t);
	if (!init_header_struct(asm_s))
		return (false);
	write(asm_s->champ_fd, &asm_s->header, sizeof(header_t));
	return (true);
}
