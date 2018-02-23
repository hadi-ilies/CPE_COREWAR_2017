/*
** EPITECH PROJECT, 2018
** get_type_from_coding_byte
** File description:
** get_type_from_coding_byte
*/

#include "prototype.h"

size_t get_type_from_coding_byte(char coding_byte, size_t arg_num)
{
	coding_byte >>= 6 - arg_num * 2;
	coding_byte &= 0b11;
	if (coding_byte == 0b01)
		return (T_REG);
	if (coding_byte == 0b10)
		return (T_DIR);
	if (coding_byte == 0b11)
		return (T_IND);
	return (0);
}
