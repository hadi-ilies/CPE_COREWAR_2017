/*
** EPITECH PROJECT, 2018
** get_type_from_coding_byte
** File description:
** get_type_from_coding_byte
*/

#include <stdbool.h>
#include "prototype.h"

bool zarbi(char code)
{
	if (code == 10 || code == 11 || code == 14)
		return (true);
	return (false);
}

char get_type_from_coding_byte(char code, char coding_byte, char arg_num)
{
	coding_byte >>= 6 - arg_num * 2;
	coding_byte &= 0b11;
	if (coding_byte == 0b01)
		return (T_REG);
	if (coding_byte == 0b10 && zarbi(code))
		return (T_IND);
	if (coding_byte == 0b10)
		return (T_DIR);
	if (coding_byte == 0b11)
		return (T_IND);
	return (0);
}
