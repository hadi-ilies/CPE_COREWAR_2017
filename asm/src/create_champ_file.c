/*
** EPITECH PROJECT, 2018
** create_champ_file
** File description:
** create_champ_file
*/

#include <fcntl.h>
#include <stdlib.h>
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
