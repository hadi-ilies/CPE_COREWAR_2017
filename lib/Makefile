##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefine
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_printf.c	\
		get_next_line.c	\
		my_strcmp.c	\
		my_strncmp.c	\
		my_strcat.c	\
		my_strdup.c	\
		my_free_tab.c	\
		my_strcat_to_tab.c	\
		my_tablen.c	\
		my_atoi.c	\
		my_memset.c

COMMON_DIR	=	common/

INC_DIR	=	../$(COMMON_DIR)include/

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -I $(INC_DIR)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
