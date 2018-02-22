/*
** EPITECH PROJECT, 2018
** full_error
** File description:
** full_error
*/

#pragma once

#define NB_MALLOC_PASS 0
#define malloc malloc_error
void *malloc_error(size_t size);

#define NB_OPEN_PASS 0
#define open open_error
int open_error(const char *pathname, int flags);
