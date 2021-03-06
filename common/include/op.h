/*
** EPITECH PROJECT, 2018
** op
** File description:
** op
*/

#pragma once

#define MEM_SIZE                (6*1024)
#define IDX_MOD                 512   /* modulo of the index < */
#define MAX_ARGS_NUMBER         4     /* this may not be changed 2^*IND_SIZE */
#define MAX_NB_PLAYER           4

#define COMMENT_CHAR            '#'
#define LABEL_CHAR              ':'
#define DIRECT_CHAR             '%'
#define SEPARATOR_CHAR          ','

#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING         ".name"
#define COMMENT_CMD_STRING      ".comment"

#define REG_NUMBER      16

typedef char args_type_t;

#define T_ALL		(T_REG | T_DIR | T_IND)
#define T_REG           1
#define T_DIR           2
#define T_IND           4
#define T_LAB           8

typedef struct
{
	char         *mnemonique;
	char         nbr_args;
	args_type_t  type[MAX_ARGS_NUMBER];
	char         code;
	int          nbr_cycles;
	char         *comment;
} op_t;

#define IND_SIZE        2
#define DIR_SIZE        4
#define REG_SIZE        DIR_SIZE

extern const op_t op_tab[];

/*
** header
*/

#define PROG_NAME_LEN	128
#define COMMENT_LEN	2048
#define COREWAR_EXEC_MAGIC	0xea83f3        /* why not */

typedef struct
{
	int	magic;
	char	prog_name[PROG_NAME_LEN + 1];
	int	prog_size;
	char	comment[COMMENT_LEN + 1];
} header_t;

/*
** live
*/

#define CYCLE_TO_DIE    1536    /* number of cycle before beig declared dead */
#define CYCLE_DELTA     5
#define NBR_LIVE        40
