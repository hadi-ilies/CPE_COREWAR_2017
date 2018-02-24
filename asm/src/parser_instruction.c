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

bool write_instruct(size_t i, char **line, char *instruct, label_t *labels)
{
	if ((instruct[0] = get_id_instruct(labels, line, i)) < 0)
		return (false);
	if (check_nbr_arg(instruct[0], *line) == false)
		return (false);
	if ((instruct[1] = write_args(line, instruct)) == -1)
		return (false);
	return (true);
}

bool parser_instruction(asm_t *asm_s)
{
	char *line = NULL;
	char instruct[2 + (MAX_ARGS_NUMBER * SIZE_ARG_MAX)] = {0};

	for (size_t i = 2; ASM_CODE[i] != NULL; i++) {
		line = ASM_CODE[i];
		if (write_instruct(i, &line, instruct, ASM_LABELS) == false)
			return (false);
		if (my_strcat(CHAMP_CODE, instruct) == NULL)
			return (false);
	}
	return (true);
}
