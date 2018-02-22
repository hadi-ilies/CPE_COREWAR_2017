/*
** EPITECH PROJECT, 2017
** my
** File description:
** my
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>

ssize_t my_putchar(char c);
void my_put_nbr(int nb);
ssize_t my_putnb_base(int nb, char *base);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(char const *format, ...);
char *get_next_line(int fd);
int my_strcmp(char const *str_a, char const *str_b);
int my_strncmp(char *str1, char *str2, size_t n);
char *my_strcat(char *recept, char *new);
char *my_strdup(char const *src);
char *my_strndup(char const *src, size_t n);
size_t my_tablen(char **tab);
void my_free_tab(char **tab);
char **my_strcat_to_tab(char **tab, char *new_line);
bool my_atoi(int *nb, char *str);
void *my_memset(void *s, int c, size_t n);

char **get_labels(char **tab);
