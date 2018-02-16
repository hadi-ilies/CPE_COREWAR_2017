/*
** EPITECH PROJECT, 2017
** proto
** File description:
** proto
*/

#pragma once

#include <stdarg.h>

void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(char const *format, ...);
char *get_next_line(int fd);
char *my_strcat(char *recept, char *new);
char *my_strdup(char const *src);
