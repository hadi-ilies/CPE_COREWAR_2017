/*
** EPITECH PROJECT, 2018
** parser_instruction
** File description:
** parser_instruction
*/

#include "asm.h"
#include "my.h"

char *write_instruct(char id, char coding_byte)
{
	char *instruct = malloc(sizeof(char) * (1));

	if (instruct == NULL)
		return (NULL);
	return (instruct);
}

bool parser_instruction(asm_t *asm_s)
{
	char id = 0;
	char *line = NULL;
	char instruct[2 + (MAX_ARGS_NUMBER * SIZE_ARG_MAX(T_REG, T_DIR, T_INC))];

	for (int i = 2; ASM_CODE[i] != NULL; i++) {
		line = ASM_CODE[i]; // ptr sur début ligne
		id = get_id_instruct(ASM_LABELS, &line); // ptr sur le char après l'instruct
		if (check_nbr_arg(id, line) == false)
			return (false);
		if (*line != ' ' && *line != '\t')
			return (false);
		else
			line += clean_str(line); // ptr sur la 1er char du 1er arg
		if (check_args(&line, instruct, ) == false)
			return (false);
		instruct = write_instruct(id, coding_byte, );
		if (my_strcat(CHAMP_CODE, instruct) == NULL)
			return (false);
	}
	return (true);
}
