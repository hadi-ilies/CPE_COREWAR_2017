/*
** EPITECH PROJECT, 2018
** write_header
** File description:
** write_header
*/

#include "asm.h"
#include "my.h"

bool init_header_struct(asm_t *asm_s)
{
	asm_s->header.magic = COREWAR_EXEC_MAGIC;
	asm_s->header.prog_name = get_next_line(asm_s->asm_fd);
	if (asm_s->header.prog_name == false)
		return (false);
	if (!strncmp(asm_s->header.prog_name, NAME_CMD_STRING, 5))
		return (false);
	asm_s->err_line++;
	asm_s->header.prog_size = my_strlen(prog_code);
	asm_s->header.comment = get_next_line(asm_s->asm_fd);
	if (asm_s->header.comment == false)
		return (false);
	if (!strncmp(asm_s->header->comment, COMMENT_CMD_STRING, 8))
		return (false);
	asm_s->err_line++;
	return (true);
}

bool write_magic(asm_t *asm_s)
{
	return (my_write(asm_s->champ_fd, &asm_s->header.magic));
}

bool write_string(asm_t *asm_s, char *str)
{
	int i = 0;

	if (my_write(asm_s->champ_fd, str) == false)
		return (false);
	i = PROG_NAME_LEN - my_strlen(str);
	while (--zero_nbr >= 0) {
		my_fputchar(fd, 0);
		i--;
	}
	return (RET_SUCCESS);
	return (true);
}

bool write_header(asm_t *asm_s)
{
	if (!init_header_struct(asm_s))
		return (false);
	if (!write_magic(asm_s) ||
	    !write_string(asm_s, asm_s->header.prog_name))
		return (false);
	return (true);
}
