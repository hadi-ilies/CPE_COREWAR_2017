##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	$(SRC_DIR)main.c

SRC             +=      ../$(COMMON_DIR)$(SRC_DIR)op.c

COMMON_DIR	=	common/

SRC_DIR		=	src/

LIB_DIR		=	../lib/

COMMON_INC_DIR          =       ../$(COMMON_DIR)include/

INC_DIR		=	../include/

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror -g -fdiagnostics-color

CFLAGS          +=  -I $(INC_DIR) -I $(COMMON_INC_DIR)

LDFLAGS		=	-L $(LIB_DIR) -lmy

NAME		=	corewar

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
