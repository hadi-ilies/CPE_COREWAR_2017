/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *concat(char *recept, char *new)
{
	int i = 0;
	int j = 0;
	int len_recept = (recept) ? my_strlen(recept) : 0;
	int len_new = (new) ? my_strlen(new) : 0;
	char *new_str = malloc(sizeof(char) * (len_recept + len_new + 1));

	if (new_str == NULL)
		return (NULL);
	while (recept && i < len_recept) {
		new_str[i] = recept[i];
		i++;
	}
	while (j < len_new) {
		new_str[i] = new[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free(recept);
	return (new_str);
}

char *my_strdu(char *src, size_t n, char *tofree)
{
	size_t i = 0;
	char *new_str = malloc(sizeof(char) * (my_strlen(src) + 1));

	if (new_str == NULL)
		return (NULL);
	while (i < n && src[i] != '\0') {
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	free(tofree);
	return (new_str);
}

ssize_t check_back_n(char *str)
{
	int j = 0;

	if (str == NULL)
		return (-1);
	while (str[j] != '\0') {
		if (str[j] == '\n')
			return (j);
		j++;
	}
	return (-1);
}

char *get_next_line(int fd)
{
	ssize_t size = 0;
	ssize_t pos_back_n = 0;
	char buffer[BUFSIZ + 1];
	static char *tmp = NULL;
	char *rest_line = NULL;

	if ((pos_back_n = check_back_n(tmp)) == -1) {
		if ((size = read(fd, buffer, BUFSIZ)) > 0) {
			if (*buffer == '\0')
				return (NULL);
			buffer[size] = '\0';
			tmp = concat(tmp, buffer);
			return (get_next_line(fd));
		}
		if (tmp == NULL || tmp[0] == '\0')
			return (NULL);
		rest_line = my_strdu(tmp, my_strlen(tmp), tmp);
		tmp = NULL;
		return (rest_line);
	}
	rest_line = my_strdu(tmp, pos_back_n, NULL);
	tmp = my_strdu(tmp + pos_back_n + 1, my_strlen(tmp + pos_back_n), tmp);
	return (rest_line);
}
