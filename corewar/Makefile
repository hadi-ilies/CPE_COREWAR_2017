##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	$(SRC_DIR)main.c \
			$(SRC_DIR)help.c \
			$(SRC_DIR)corewar.c \
			$(SRC_DIR)get_nb_player.c \
			$(SRC_DIR)test_header.c \
			$(SRC_DIR)cor_to_tab.c \

SRC             +=      ../$(COMMON_DIR)$(SRC_DIR)op.c

COMMON_DIR	=	common/

SRC_DIR		=	src/

LIB_DIR		=	../lib/

COMMON_INC_DIR	=	../$(COMMON_DIR)include/

INCLUDE		=	include/

INC_DIR		=	../include/

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -g -fdiagnostics-color

CFLAGS          +=	-I $(INC_DIR) -I $(COMMON_INC_DIR) -I $(INCLUDE)

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
