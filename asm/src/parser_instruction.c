/*
** EPITECH PROJECT, 2018
** parser_instruction
** File description:
** parser_instruction
*/

#include "asm.h"
#include "my.h"

void write_instruct(char *instruct, char id, char coding_byte)
{
	instruct[0] = id;
	instruct[1] = coding_byte;
}

bool parser_instruction(asm_t *asm_s)
{
	char id = 0;
	char *line = NULL;
	char coding_byte = 0;
	char instruct[2 + (MAX_ARGS_NUMBER * SIZE_ARG_MAX(T_REG, T_DIR, T_IND))];

	for (size_t i = 2; ASM_CODE[i] != NULL; i++) {
		line = ASM_CODE[i];
		id = get_id_instruct(ASM_LABELS, &line, i);
		if (check_nbr_arg(id, line) == false)
			return (false);
		if (*line != ' ' && *line != '\t')
			return (false);
		else
			line += clean_str(line);
		if ((coding_byte = check_args(&line, instruct)) == -1)
			return (false);
		write_instruct(instruct, id, coding_byte);
		if (my_strcat(CHAMP_CODE, instruct) == NULL)
			return (false);
	}
	return (true);
}
