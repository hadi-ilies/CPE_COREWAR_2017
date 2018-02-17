/*
** EPITECH PROJECT, 2018
** my_write
** File description:
** my_write
*/

#include <stdbool.h>
#include <unistd.h>

bool my_write(int fd, const void *buf)
{
	return ((write(fd, buf, sizeof(buf)) == sizeof(buf)) ? true : false);
}
