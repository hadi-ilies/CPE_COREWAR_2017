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
CORE_DIR	=	$(SRC_DIR)corewar/
PLAY_DIR	=	$(SRC_DIR)player/
OP_DIR		=	$(SRC_DIR)op/
COMMON_SRC_DIR	=	$(COMMON_DIR)$(SRC_DIR)
COMMON_INC_DIR	=	$(COMMON_DIR)$(INC_DIR)

SRC		=	$(SRC_DIR)main.c \
			$(SRC_DIR)options.c \
			$(SRC_DIR)play.c \
			$(SRC_DIR)get_para.c \
			$(SRC_DIR)help.c \
			$(SRC_DIR)corewar.c \
			$(SRC_DIR)get_nb_player.c \
			$(SRC_DIR)test_header.c \
			$(SRC_DIR)cor_to_tab.c \
			$(SRC_DIR)get_type_from_coding_byte.c \
			$(SRC_DIR)get_size_from_coding_byte.c \
			$(SRC_DIR)get_arg.c \
			$(SRC_DIR)get_int.c \
			$(SRC_DIR)v3c.c \
			$(CORE_DIR)corewar_create.c \
			$(CORE_DIR)corewar_destroy.c \
			$(PLAY_DIR)player_create.c \
			$(PLAY_DIR)set_reg.c \
			$(PLAY_DIR)offset_move.c \
			$(OP_DIR)op_live.c \
			$(OP_DIR)op_ld.c \
			$(OP_DIR)op_st.c \
			$(OP_DIR)op_add.c \
			$(OP_DIR)op_sub.c \
			$(OP_DIR)op_and.c \
			$(OP_DIR)op_or.c \
			$(OP_DIR)op_xor.c \
			$(OP_DIR)op_zjmp.c \
			$(OP_DIR)op_ldi.c \
			$(OP_DIR)op_sti.c \
			$(OP_DIR)op_fork.c \
			$(OP_DIR)op_lld.c \
			$(OP_DIR)op_lldi.c \
			$(OP_DIR)op_lfork.c \
			$(OP_DIR)op_aff.c \
			$(COMMON_DIR)$(SRC_DIR)op.c \
			$(SRC_DIR)op_functions.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I $(INC_DIR)
CFLAGS          +=	-I $(COMMON_INC_DIR)
CFLAGS		+=	-W -Wall -Wextra
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
