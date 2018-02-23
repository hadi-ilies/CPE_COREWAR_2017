##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

COREWAR_DIR	=	corewar/

ASM_DIR		=	asm/

all:
		@make -C $(ASM_DIR) --no-print-directory
		@make -C $(COREWAR_DIR) --no-print-directory

asm:
		@make -C $(ASM_DIR) --no-print-directory

corewar:
		@make -C $(COREWAR_DIR) --no-print-directory

clean:
		@make clean -C $(ASM_DIR) --no-print-directory
		@make clean -C $(COREWAR_DIR) --no-print-directory

fclean:		clean
		@make fclean -C $(ASM_DIR) --no-print-directory
		@make fclean -C $(COREWAR_DIR) --no-print-directory

re:		fclean all

.PHONY:	all corewar asm re clean fclean
