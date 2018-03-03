/*
** EPITECH PROJECT, 2018
** write_binary_code
** File description:
** write_binary_code
*/

#include <byteswap.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

bool write_binary_code(asm_t *asm_s)
{
	int len = bswap_32(PROG_SIZE);

	if (write(asm_s->champ_fd, &asm_s->header, sizeof(header_t)) < 0)
		return (false);
	if (write(asm_s->champ_fd, asm_s->champ_code, len) != len)
		return (false);
	free(asm_s->champ_code);
	return (true);
}
