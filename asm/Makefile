##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	$(SRC_DIR)main.c	\
			$(SRC_DIR)h_option.c	\
			$(SRC_DIR)init_struct.c	\
			$(SRC_DIR)op.c	\
			$(SRC_DIR)write_header.c	\
			$(SRC_DIR)compile_asm.c	\
			$(SRC_DIR)parsing.c

SRC_DIR		=	src/

LIB_DIR		=	../lib/

INC_DIR		=	../include/

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror -I $(INC_DIR) -fdiagnostics-color -g

LDFLAGS		=	-L $(LIB_DIR) -lmy

NAME		=	asm

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -C $(LIB_DIR) --no-print-directory
		@gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		@rm -f $(OBJ)
		@make clean -C $(LIB_DIR) --no-print-directory

fclean:		clean
		@rm -f $(NAME)
		@make fclean -C $(LIB_DIR) --no-print-directory

re:		fclean all

.PHONY:	all re clean fclean
