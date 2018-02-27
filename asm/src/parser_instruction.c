/*
** EPITECH PROJECT, 2018
** parser_instruction
** File description:
** parser_instruction
*/

#include <stdio.h>
#include "asm.h"
#include "my.h"

/*
** 'instruct' is composed of code, coding byte, and 3 parameters max
**  Exemple with hexdump -C :
**
** .s		sti   r1 %:live   %1
** .cor		0b 68 01 00 0f 00 01
*/

bool write_instruct(size_t i, char *line, char *instruct, label_t *labels)
{
	int nparam = 0;
	char reg = 0;
	short ind = 0;
	int dir = 0;

	if ((instruct[0] = get_id_instruct(labels, &line, i)) < 0)
		return (false);
	if (check_nbr_arg(instruct[0], line) == false)
		return (false);
	for (int i = 0; line[i] != '\0'; i++) {
		if ((reg = is_reg(line + i, instruct[0], nparam)) == -1)
			return (-1);
		if ((dir = is_dir(line + i, instruct[0], nparam)) == -1)
			return (-1);
		if ((ind = is_ind(line + i, instruct[0], nparam)) == -1)
			return (-1);
	}
//	if ((instruct[1] = write_args(line, instruct[0], instruct + 2)) == -1)
//		return (false);
	return (true);
}

bool parser_instruction(asm_t *asm_s)
{
	char *line = NULL;
	char instruct[2 + (MAX_ARGS_NUMBER * SIZE_ARG_MAX)] = {0};

	for (size_t i = 2; ASM_CODE[i] != NULL; i++) {
		line = ASM_CODE[i];
		asm_s->line_err = line;
		if (write_instruct(i, line, instruct, ASM_LABELS) == false)
			return (false);
		PROG_SIZE += my_strlen(instruct);
		if (my_strcat(CHAMP_CODE, instruct) == NULL)
			return (false);
	}
	return (true);
}
