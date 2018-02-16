/*
** EPITECH PROJECT, 2018
** open_asm
** File description:
** open_asm
*/

#include <fcntl.h>

int open_asm(char *path)
{
	return (open(path, O_RDONLY));
}
