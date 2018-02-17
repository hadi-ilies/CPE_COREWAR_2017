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
	char *name = get_next_line(asm_s->asm_fd);
	char *comment = get_next_line(asm_s->asm_fd);

	if (name == NULL) {
		my_putstr("name\n");
		return (false);
	}
	if (comment == NULL) {
		my_putstr("comment\n");
		return (false);
	}
	for (; name[i] != '\0'; i++)
		asm_s->header.prog_name[i] = name[i];
	fill_rest_0(asm_s->header.prog_name, i, PROG_NAME_LEN);
	asm_s->err_line++;
	if (!strncmp(asm_s->header.prog_name, NAME_CMD_STRING, 5))
		return (false);
	for (i = 0; comment[i] != '\0'; i++)
		asm_s->header.comment[i] = name[i];
	fill_rest_0(asm_s->header.prog_name, i, COMMENT_LEN);
	asm_s->err_line++;
	if (!strncmp(asm_s->header.comment, COMMENT_CMD_STRING, 8))
		return (false);
	return (true);
}

bool write_number(int fd, size_t *number)
{
	return (my_write(fd, number));
}

bool write_string(asm_t *asm_s, char *str, int max)
{
	if (my_write(asm_s->champ_fd, str) == false)
		return (false);
	for (int i = max - my_strlen(str); i >= 0; i--)
		if (my_write(asm_s->champ_fd, 0) == false)
			return (false);
	return (true);
}

/*
** In the header of .cor : COREWAR_EXEC_MAGIC, NAME, COMMENT, SIZE
** PS : A confirmer auprès de Freddou
*/

bool write_header(asm_t *asm_s)
{
	asm_s->header.magic = COREWAR_EXEC_MAGIC;
	asm_s->header.prog_size = my_strlen(asm_s->prog_code);
	if (!init_header_struct(asm_s))
		return (false);
	if (!write_number(asm_s->champ_fd, &asm_s->header.magic))
		return (false);
	if (!write_string(asm_s, asm_s->header.prog_name, PROG_NAME_LEN))
		return (false);
	if (!write_number(asm_s->champ_fd, &asm_s->header.prog_size))
		return (false);
	if (!write_string(asm_s, asm_s->header.comment, COMMENT_LEN))
		return (false);
	return (true);
}
