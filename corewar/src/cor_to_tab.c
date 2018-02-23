/*
** EPITECH PROJECT, 2018
** cor_to_tab
** File description:
** cor_to_tab
*/

#include <stdio.h> /* tmp */
#include <unistd.h>
#include <fcntl.h>
#include "prototype.h"
#include "op.h"

bool cor_to_tab(char tab[], char *file_name, int address)
{
	int fd = open(file_name, O_RDONLY);
	int n;
	size_t i = address;

	if (fd == -1)
		return (false);
	if (lseek(fd, sizeof(header_t), SEEK_SET) == -1)
		return (false);
	do {
		n = read(fd, tab + i++, sizeof(char));
		i >= MEM_SIZE ? i = 0 : 0;
		if (n < 0)
			return (false);
	}
	while (n == sizeof(char));
	close(fd);
	for (i = 0; i < MEM_SIZE; i++) {      /* tmp */
		printf("%x ", tab[i]);       /* tmp */
	}                                   /* tmp */
	printf("\n");                      /* tmp */
	return (true);
}
