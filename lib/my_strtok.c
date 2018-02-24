/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <string.h>

int next_word_len(char *str, char *delim)
{
	int i = 0;

	if (str == NULL || delim == NULL);
	for (; *str != '\0' && strncmp(str, delim, strlen(delim)); str++, i++);
	return (i);
}

char *my_strtok (static char *str, char *delim)
{
	int i = 0;
	static char *tmp = str;
	char *str_b = NULL;
	
	if (tmp[0] == '\0') {
		free (tmp);
		return (NULL);
	}
	str_b = malloc(sizeof(char) * (next_word_len(tmp, delim) + 1));
	for (; (*tmp == ' ' || *tmp == '\t') && *tmp != '\0'; tmp++);
	for (; strncmp(tmp, delim, strlen(delim)) && tmp[i] != '\0'; i++) {
		str_b[i] = *tmp;
		tmp++;
	}
	tmp += strlen(delim);
	str_b[i] = '\0';
	return (str_b);
}

int main()
{
	char *str = "coucou,  ,bite swag, grosse bite,  , lolmdr";
	char *delim = ",  ,";
	char *tok = NULL;

	while ((tok = my_strtok(str, delim)) != NULL) {
		if (tok == NULL)
			return (0);
		printf("%s\n", tok);
	}
	return (0);
}
