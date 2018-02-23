/*
** EPITECH PROJECT, 2018
** op
** File description:
** op
*/

#include "op.h"
#include "op_functions.h"

op_t op_tab[] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", op_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", op_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", op_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", op_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", op_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
	 "et (and  r1, r2, r3   r1&r2 -> r3", op_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
	 "ou  (or   r1, r2, r3   r1 | r2 -> r3", op_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
	 "ou (xor  r1, r2, r3   r1^r2 -> r3", op_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", op_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
	 "load index", op_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
	 "store index", op_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", op_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", op_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
	 "long load index", op_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", op_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", op_aff},
	{0, 0, {0}, 0, 0, 0, NULL}
};
