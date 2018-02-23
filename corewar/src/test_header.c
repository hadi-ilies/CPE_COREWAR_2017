/*
** EPITECH PROJECT, 2018
** test_header
** File description:
** test_header
*/

#include <unistd.h>
#include <fcntl.h>
#include "prototype.h"
#include "op.h"

bool test_header(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	int corewar_exec_magic;

	if (fd == -1)
		return (false);
	if (read(fd, &corewar_exec_magic, sizeof(int)) != sizeof(int)) {
		close(fd);
		return (false);
	}
	close(fd);
	if (corewar_exec_magic == COREWAR_EXEC_MAGIC)
		return (true);
	return (false);
}
