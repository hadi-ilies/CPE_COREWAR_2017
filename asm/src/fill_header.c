/*
** EPITECH PROJECT, 2018
** write_header
** File description:
** write_header
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"

bool fill_name_header(asm_t *asm_s)
{
	int i = 0;
	char *name = get_str_entrecote(ASM_CODE[0]);

	if (name == NULL || my_strncmp(ASM_CODE[0], NAME_CMD_STRING, 5))
		return (false);
	my_memset(asm_s->header.prog_name, 0, PROG_NAME_LEN);
	for (i = 0; name[i] != '\0'; i++)
		asm_s->header.prog_name[i] = name[i];
	asm_s->line_err = ASM_CODE[0];
	free(name);
	return (true);
}

bool fill_comment_header(asm_t *asm_s)
{
	int i = 0;
	char *comment = get_str_entrecote(ASM_CODE[1]);

	if (comment == NULL || my_strncmp(ASM_CODE[1], COMMENT_CMD_STRING, 8))
		return (false);
	my_memset(asm_s->header.comment, 0, COMMENT_LEN);
	for (i = 0; comment[i] != '\0'; i++)
		asm_s->header.comment[i] = comment[i];
	asm_s->line_err = ASM_CODE[1];
	free(comment);
	return (true);
}

/*
** In the header of .cor : COREWAR_EXEC_MAGIC, NAME, ASM_SIZE - HEADER_SIZE
** , COMMENT
** PS : A confirmer auprès d'un AER ou d'un mec fort qui a réussi l'ASM
*/

bool fill_header(asm_t *asm_s)
{
	asm_s->header.magic = REV_ENDIAN(COREWAR_EXEC_MAGIC);
	if (!fill_name_header(asm_s) || !fill_comment_header(asm_s))
		return (false);
	return (true);
}
