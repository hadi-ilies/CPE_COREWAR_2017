/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** asm.h
*/

#pragma once

typedef struct
{
	int src_fd;
	int dest_fd;
} asm_t;

void h_option(char *binary_name, char *arg);
