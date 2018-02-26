/*
** EPITECH PROJECT, 2018
** make_str_clean_again
** File description:
** make_str_clean_again
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"

const char DELIM[4] = {' ', '\t', SEPARATOR_CHAR, '\0'};

bool is_delim(char c, const char *delim)
{
	while (*delim != '\0') {
		if (c == *delim)
			return (true);
		delim++;
	}
	return (false);
}

size_t len_clean_str(char *str, const char *delim)
{
	size_t i = 0;
	size_t size = 0;
	bool tmp = false;

	if (str == NULL || delim == NULL)
		return (-1);
	for (; str[i] != '\0'; i++)
		if (!is_delim(str[i], delim)) {
			size++;
			tmp = true;
		}
		else if (tmp == true) {
			size++;
			tmp = false;
		}
	return (size);
}

char *make_str_clean_again(char *str, const char *delim)
{
	size_t j = 0;
	bool tmp = false;
	char *clean_str;

	if (str == NULL || delim == NULL)
		return (NULL);
	clean_str = malloc(sizeof(char) * (len_clean_str(str, delim) + 1));
	if (clean_str == NULL)
		return (NULL);
	for (size_t i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], delim)) {
			clean_str[j++] = str[i];
			tmp = true;
		} else if (tmp == true) {
			clean_str[j++] = ' ';
			tmp = false;
		}
	clean_str[(clean_str[j - 1] == ' ') ? j - 1 : j] = '\0';
	free(str);
	return (clean_str);
}
