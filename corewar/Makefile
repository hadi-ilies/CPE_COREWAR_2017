##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME		=	corewar

SRC_DIR		=	src/
INC_DIR		=	include/
COMMON_DIR	=	../common/
LIB_DIR		=	../lib/
PLAY_DIR	=	$(COMMON_DIR)$(SRC_DIR)player/
OP_DIR		=	$(SRC_DIR)op/
COMMON_SRC_DIR	=	$(COMMON_DIR)$(SRC_DIR)
COMMON_INC_DIR	=	$(COMMON_DIR)$(INC_DIR)

SRC		=	$(SRC_DIR)main.c \
			$(SRC_DIR)help.c \
			$(SRC_DIR)corewar.c \
			$(SRC_DIR)get_nb_player.c \
			$(SRC_DIR)test_header.c \
			$(SRC_DIR)cor_to_tab.c \
			$(PLAY_DIR)player_create.c \
			$(PLAY_DIR)player_destroy.c \
			$(OP_DIR)live.c \
			$(OP_DIR)ld.c \
			$(OP_DIR)st.c \
			$(OP_DIR)add.c \
			$(OP_DIR)sub.c \
			$(OP_DIR)and.c \
			$(OP_DIR)or.c \
			$(OP_DIR)xor.c \
			$(OP_DIR)zjmp.c \
			$(OP_DIR)ldi.c \
			$(OP_DIR)sti.c \
			$(OP_DIR)fork.c \
			$(OP_DIR)lld.c \
			$(OP_DIR)lldi.c \
			$(OP_DIR)lfork.c \
			$(OP_DIR)aff.c \
			$(COMMON_DIR)$(SRC_DIR)op.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I $(INC_DIR)
CFLAGS          +=	-I $(COMMON_INC_DIR)
CFLAGS		+=	-W -Wall -Wextra -g
CFLAGS		+=	-fdiagnostics-color

LDFLAGS		=	-L $(LIB_DIR) -lmy


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
