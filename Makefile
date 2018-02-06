##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

COREWAR_DIR	=	corewar/

ASM_DIR	=	asm/

all:
		@make -C $(ASM_DIR)
		@make -C $(COREWAR_DIR)

asm:
		@make -C $(ASM_DIR)

corewar:
		@make -C $(COREWAR_DIR)

clean:
		@make clean -C $(ASM_DIR)
		@make clean -C $(COREWAR_DIR)

fclean:		clean
		@make fclean -C $(ASM_DIR)
		@make fclean -C $(COREWAR_DIR)

re:		fclean all

.PHONY:	all corewar asm re clean fclean
