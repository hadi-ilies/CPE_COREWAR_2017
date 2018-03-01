/*
** EPITECH PROJECT, 2018
** init_struct
** File description:
** init_struct
*/

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
	else {
		free(cor);
		return (NULL);
	}
	return (my_strcat(cor, "cor"));
}

int create_champ_file(char *path)
{
	char *champ_name = get_champ_name(path);
	int fd = 0;

	if (champ_name == NULL)
		return (-1);
	fd = open(champ_name, FLAGS, MODE);
	free(champ_name);
	return (fd);
}

bool init_struct(asm_t *asm_s, char *path)
{
	if ((asm_s->asm_fd = open(path, O_RDONLY)) < 0)
		return (false);
	if ((asm_s->champ_fd = create_champ_file(path)) < 0)
		return (false);
	my_memset(&asm_s->header, 0, sizeof(header_t));
	asm_s->line_err = NULL;
	asm_s->asm_code = NULL;
	asm_s->champ_code = NULL;
	PROG_SIZE = 0;
	return (true);
}
