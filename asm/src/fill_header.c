/*
** EPITECH PROJECT, 2018
** write_header
** File description:
** write_header
*/

#include <byteswap.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

bool fill_name_header(asm_t *asm_s)
{
	int i = 0;
	char *name = get_str_entrecote(ASM_CODE[0]);

	asm_s->line_err = ASM_CODE[0];
	if (name == NULL || my_strncmp(ASM_CODE[0], NAME_CMD_STRING, 5))
		return (false);
	my_memset(asm_s->header.prog_name, 0, PROG_NAME_LEN);
	for (i = 0; name[i] != '\0'; i++)
		asm_s->header.prog_name[i] = name[i];
	free(name);
	return (true);
}

bool fill_comment_header(asm_t *asm_s)
{
	int i = 0;
	char *comment = get_str_entrecote(ASM_CODE[1]);

	asm_s->line_err = ASM_CODE[1];
	if (comment == NULL || my_strncmp(ASM_CODE[1], COMMENT_CMD_STRING, 8))
		return (false);
	my_memset(asm_s->header.comment, 0, COMMENT_LEN);
	for (i = 0; comment[i] != '\0'; i++)
		asm_s->header.comment[i] = comment[i];
	free(comment);
	return (true);
}

/*
** In the header of .cor : COREWAR_EXEC_MAGIC, NAME, ASM_SIZE, COMMENT
*/

bool fill_header(asm_t *asm_s, char **argv)
{
	PROG_SIZE = bswap_32(PROG_SIZE);
	asm_s->header.magic = bswap_32(COREWAR_EXEC_MAGIC);
	if (!fill_name_header(asm_s) || !fill_comment_header(asm_s)) {
		my_printf("\033[0;34m%s, %s\n\033[1;36m", argv[0], argv[1]);
		my_printf("Line : \n\033[0;31m%s\n \033[00m", asm_s->line_err);
		return (false);
	}
	return (true);
}
