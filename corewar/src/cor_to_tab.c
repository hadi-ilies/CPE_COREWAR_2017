/*
** EPITECH PROJECT, 2018
** cor_to_tab
** File description:
** cor_to_tab
*/

#include <unistd.h>
#include <fcntl.h>
#include "prototype.h"

bool cor_to_tab(char *tab, char *file_name, int address)
{
	int fd = open(file_name, O_RDONLY);
	int n;
	size_t i = 0;

	if (fd == -1)
		return (false);
	if (lseek(fd, sizeof(header_t), SEEK_SET) == -1)
		return (false);
	do {
		n = read(fd, tab + address + i++, sizeof(char));
		if (n < 0) {
			close(fd);
			return (false);
		}
	}
	while (n == sizeof(char));
	close(fd);
	for (i = 0; i < MEM_SIZE; i++) {         /* tmp */
		my_printf("%x ", tab[i]);       /* tmp */
	}                                      /* tmp */
	my_printf("\n");                      /* tmp */
	return (true);
}
