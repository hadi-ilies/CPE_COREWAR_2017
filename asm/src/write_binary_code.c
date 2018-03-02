/*
** EPITECH PROJECT, 2018
** write_binary_code
** File description:
** write_binary_code
*/

#include "asm.h"
#include "my.h"

bool write_binary_code(asm_t *asm_s)
{
	ssize_t len = REV_ENDIAN(PROG_SIZE);

	if (write(asm_s->champ_fd, &asm_s->header, sizeof(header_t)) < 0)
		return (false);
	if (write(asm_s->champ_fd, asm_s->champ_code, len) != len)
		return (false);
	return (true);
}
