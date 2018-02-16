/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** asm.h
*/

#pragma once

#define MODE (O_CREAT | O_WRONLY | O_TRUNC | O_APPEND)
#define RIGHTS (S_IROTH | S_IWGRP | S_IRUSR | S_IWUSR | S_IRGRP)

typedef struct
{
	int src_fd;
	int dest_fd;
} asm_t;

void h_option(char *binary_name, char *arg);
