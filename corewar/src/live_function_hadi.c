/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "op.h"
//#include "live.h"

bool live(int is_alive)
{
	if (is_alive == 0) {
		my_printf("i'am alive\n");
		return (true);
	} else {
		my_printf("i'am dead\n");
		return (false);
	}
}
