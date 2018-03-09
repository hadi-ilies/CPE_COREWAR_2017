/*
** EPITECH PROJECT, 2018
** parser_instruction
** File description:
** parser_instruction
*/

#include "asm.h"
#include "my.h"

/*
** 'instruct' is composed of code, coding byte, and 3 parameters max
**  Exemple with hexdump -C :
**
** .s		sti   r1 %:live   %1
** .cor		0b 68 01 00 0f 00 01
*/

bool write_instruct(inst_t *instruct, asm_t *asm_s)
{
	if ((instruct->instruct[0] = get_id_instruct(instruct)) < 0)
		return (false);
	if (check_nbr_arg(instruct->instruct[0], LINE) == false)
		return (false);
	for (; *LINE != '\0'; LINE += get_next_arg(LINE)) {
		if (*LINE == 'r') {
			if (is_reg(LINE, instruct) == false)
				return (false);
		} else if (*LINE == DIRECT_CHAR) {
			if (is_dir(LINE, instruct, asm_s) == false)
				return (false);
		} else if (IS_NUM(*LINE) || *LINE == LABEL_CHAR) {
			if (is_ind(LINE, instruct, asm_s) == false)
				return (false);
		} else
			return (false);
	}
	return (true);
}

int stall_left_coding_byte(int id)
{
	if (id == 2)
		return (2);
	if (id == 3)
		return (2);
	if (id == 13)
		return (2);
	return (0);
}

bool parser_instruction(asm_t *asm_s)
{
	for (size_t i = 2; ASM_CODE[i] != NULL; i++) {
		inst_t inst = {ASM_CODE[i],{'\0'},false, {false},0, 0};

		asm_s->line_err = inst.line;
		if (!write_instruct(&inst, asm_s))
			return (false);
		inst.instruct[1] <<= stall_left_coding_byte(inst.instruct[0]);
		if (!(CHAMP_CODE = my_instruct_cat(asm_s, &inst)))
			return (false);
		PROG_SIZE += inst.pos;
	}
	return (true);
}
