/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(char *str1, char *str2, size_t n)
{
	char tmp;
	bool result;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	if (my_strlen(str1) < my_strlen(str2))
		return (1);
	tmp = str1[n];
	str1[n] = '\0';
	result = my_strcmp(str1, str2);
	str1[n] = tmp;
	return (result);
}
