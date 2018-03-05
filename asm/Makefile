##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	$(SRC_DIR)main.c	\
			$(SRC_DIR)h_option.c	\
			$(SRC_DIR)init_struct.c	\
			$(SRC_DIR)get_str_entrecote.c	\
			$(SRC_DIR)fill_header.c	\
			$(SRC_DIR)compile_asm.c	\
			$(SRC_DIR)parser_instruction.c	\
			$(LABEL_DIR)get_labels.c	\
			$(LABEL_DIR)get_pos_label.c	\
			$(LABEL_DIR)is_valid_label_char.c	\
			$(LABEL_DIR)get_sub_label.c	\
			$(PARSER_DIR)get_next_arg.c	\
			$(PARSER_DIR)get_id_instruct.c	\
			$(PARSER_DIR)need_coding_byte.c	\
			$(PARSER_DIR)check_nbr_arg.c	\
			$(PARSER_DIR)is_dir.c	\
			$(PARSER_DIR)is_ind.c	\
			$(PARSER_DIR)is_reg.c	\
			$(SRC_DIR)my_instruct_cat.c	\
			$(SRC_DIR)write_binary_code.c

SRC		+=	$(COMMON_DIR)$(SRC_DIR)op.c

SRC_DIR		=	src/
PARSER_DIR	=	$(SRC_DIR)parser/
LABEL_DIR	=	$(SRC_DIR)label/

LIB_DIR		=	../lib/

INC_DIR		=	include/
COMMON_DIR	=	../common/
COMMON_INC_DIR	=	$(COMMON_DIR)include/

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror

CFLAGS		+=	-I $(INC_DIR) -I $(COMMON_INC_DIR)

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
