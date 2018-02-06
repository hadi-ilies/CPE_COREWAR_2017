/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stddef.h>
#include "proto.h"

void what_modulo(const char *format, size_t i, va_list arg)
{
	if (format[i + 1] == 'd') {
		my_put_nbr(va_arg(arg, int));
		return;
	}
	if (format[i + 1] == 's') {
		my_putstr(va_arg(arg, char *));
		return;
	}
	if (format[i + 1] == 'c') {
		my_putchar(va_arg(arg, int));
		return;
	}
}

int my_printf(const char *format, ...)
{
	va_list arg_list;
	size_t i = 0;

	va_start(arg_list, format);
	while (format[i] != '\0') {
		if (format[i] == '%') {
			what_modulo(format, i, arg_list);
			i++;
		}
		else
			my_putchar(format[i]);
		i++;
	}
	va_end(arg_list);
	return (0);
}
