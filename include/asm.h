/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** asm.h
*/

#pragma once

#include <stdbool.h>

#define FLAGS (O_CREAT | O_WRONLY | O_TRUNC | O_APPEND)
#define MODE (S_IROTH | S_IWGRP | S_IRUSR | S_IWUSR | S_IRGRP)

typedef struct
{
	int asm_fd;
	int champ_fd;
} asm_t;

bool h_option(char *binary_name, char *arg);
int create_champ_file(char *path);
int open_asm(char *path);
