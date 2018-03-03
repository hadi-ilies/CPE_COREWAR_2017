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
				return (-1);
		} else if (*LINE == DIRECT_CHAR) {
			if (is_dir(LINE, instruct, asm_s) == false)
				return (-1);
		} else if (IS_NUM(*LINE) || *LINE == LABEL_CHAR) {
			if (is_ind(LINE, instruct, asm_s) == false)
				return (-1);
		} else
			return (false);
	}
	return (true);
}

bool parser_instruction(asm_t *asm_s)
{
	for (size_t i = 2; ASM_CODE[i] != NULL; i++) {
		inst_t instruct = {ASM_CODE[i],	{'\0'},	false, {false},	0, 0};

		asm_s->line_err = instruct.line;
		if (!write_instruct(&instruct, asm_s))
			return (false);
		if (!(CHAMP_CODE = my_instruct_cat(asm_s, &instruct)))
			return (false);
		PROG_SIZE += instruct.pos;
	}
	return (true);
}
