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
	if (cor[i - 2] == '.' && cor[i - 1] == 's')
		cor[i - 1] = '\0';
	else
		return (NULL);
	return (my_strcat(cor, "cor"));
}

int create_champ_file(char *path)
{
	char *champ_name = get_champ_name(path);
	int fd = open(champ_name, FLAGS, MODE);

	free(champ_name);
	return (fd);
}

bool init_struct(asm_t *asm_s, char *path)
{
	if ((asm_s->asm_fd = open(path, O_RDONLY)) < 0)
		return (false);
	if ((asm_s->champ_fd = create_champ_file(path)) < 0)
		return (false);
	asm_s->err_line = 0;
	asm_s->prog_code = NULL;
	return (true);
}
