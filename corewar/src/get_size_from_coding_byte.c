/*
** EPITECH PROJECT, 2018
** get_size_from_coding_byte
** File description:
** get_size_from_coding_byte
*/

#include "prototype.h"

ssize_t get_size_from_type(char type)
{
	if (type == T_REG)
		return (1);
	if (type == T_IND)
		return (IND_SIZE);
	if (type == T_DIR)
		return (DIR_SIZE);
	return (-1);
}

ssize_t get_size_from_coding_byte(char code, char coding_byte, char arg_num)
{
	char type = get_type_from_coding_byte(code, coding_byte, arg_num);

	return (get_size_from_type(type));
}
