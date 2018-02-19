/*
** EPITECH PROJECT, 2017
** my
** File description:
** my
*/

#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(char const *format, ...);
char *get_next_line(int fd);
char *my_strcat(char *recept, char *new);
char *my_strdup(char const *src);
bool my_write(int fd, const void *buf);
size_t my_tablen(char **tab);
void my_free_tab(char **tab);
char **my_strcat_to_tab(char **tab, char *new_line);