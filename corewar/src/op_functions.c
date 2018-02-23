/*
** EPITECH PROJECT, 2018
** op_functions
** File description:
** op_functions
*/

#include "op_functions.h"

op_function_t op_function[] = {
	{1, op_live},
	{2, op_ld},
	{3, op_st},
	{4, op_add},
	{5, op_sub},
	{6, op_and},
	{7, op_or},
	{8, op_xor},
	{9, op_zjmp},
	{10, op_ldi},
	{11, op_sti},
	{12, op_fork},
	{13, op_lld},
	{14, op_lldi},
	{15, op_lfork},
	{16, op_aff},
	{0, NULL}
};
