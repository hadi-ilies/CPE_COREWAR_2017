/*
** EPITECH PROJECT, 2018
** parser_instruction
** File description:
** parser_instruction
*/

#include "asm.h"
#include "my.h"

bool parser_instruction(asm_t *asm_s)
{
	char mnemonic = 0;

	for (int i = 2; ASM_CODE[i] != NULL) {
		mnemonic = get_mneminic_instruct(asm_s, i);
		i++;
	}
	return (true);
}
