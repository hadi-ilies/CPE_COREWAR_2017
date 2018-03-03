/*
** EPITECH PROJECT, 2018
** write_binary_code
** File description:
** write_binary_code
*/

#include <byteswap.h>
#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"
#include "my.h"

char *get_champ_name(char *path)
{
	int i = 0;
	char *cor = my_strdup(path);

	if (cor == NULL)
		return (NULL);
	i = my_strlen(cor);
	if (i > 2 && cor[i - 2] == '.' && cor[i - 1] == 's')
		cor[i - 1] = '\0';
	return (my_strcat(cor, "cor"));
}

int create_champ_file(char *path)
{
	int fd = 0;
	char *champ_name = get_champ_name(path);

	if (champ_name == NULL)
		return (-1);
	fd = open(champ_name, FLAGS, MODE);
	free(champ_name);
	return (fd);
}

bool write_binary_code(asm_t *asm_s, char *path)
{
	int len = bswap_32(PROG_SIZE);

	if ((asm_s->champ_fd = create_champ_file(path)) < 0)
		return (false);
	if (write(asm_s->champ_fd, &asm_s->header, sizeof(header_t)) < 0)
		return (false);
	if (write(asm_s->champ_fd, asm_s->champ_code, len) != len)
		return (false);
	free(asm_s->champ_code);
	return (true);
}
