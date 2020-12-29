/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:36:30 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:36:35 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"
# include "op.h"

/*
**TREG- r+[number 1-16]
**TDIR- % + :label or [any number]
**MEAN- значение имени или коммент in header
**IDIR- [number] or :label
**COMT comment header
*/
typedef	enum
{
	LABEL,
	TREG,
	TDIR,
	MEAN,
	IDIR,
	NAME,
	COMT,
	OPER,
	COMMA,
	NEXT,
	END,
	ERR
}	t_type;

typedef enum
{
	INVALID,
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
}	t_ops;

/*
**code_arg - код типа аргумента
**tdir_size - размер тдир - 2 или 4
*/
typedef struct		s_op
{
	char			name[5];
	int				nb_arg;
	char			arg_type[3];
	int				op;
	int				cycle;
	char			definition[40];
	int				code_arg;
	int				tdir_size;
}					t_op;

# define RES "\e[0m"
# define RD "\e[0;31m"
# define GRE "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"

# define OPEN_FL "==START READING FILE=="
# define OK_FL "==OK FILE=="
# define LEX_AN "==LEXICAL ANALYSE START=="
# define LEX_AN_G "==LEXICAL ANALYSE SUCCESS=="
# define SYN_AN "==SYNTAX ANALYSE START=="
# define SYN_AN_G "==SYNTAX ANALYSE SUCCESS=="
# define CON_ST "==MAGIC BEGINS!!! CONVERT TO BYTECODE!!!=="
# define CON_OK "==CONVERT OK=="
# define ENJOY "\e[0;45m==CONGRATS! ENJOY YOUR GAME!! MAY THE 42 BE WITH U!!!=="
# define FAIL_STOP "==FAILED!!! STOP PROCESS!!!=="
# define MAL "Malloc error"

/*
**position-line token
*/
typedef struct		s_lex
{
	char			*token;
	t_type			type;
	int				position;
	unsigned int	byte;
	int				operator;
	struct s_lex	*next;
}					t_lex;

typedef struct		s_label
{
	char			*name;
	unsigned int	cur;
	struct s_label	*next;
}					t_label;

/*
**tk_list = token list
**ll = label list
*/
typedef struct		s_asm
{
	int				fd;
	char			*raw;
	char			*clean;
	t_lex			*tk_list;
	char			*name;
	char			*comment;
	int				line;
	t_op			pattern[17];
	t_label			*ll;
	int				full_size;
}					t_asm;

/*
**utils.c
*/
int					check_format(char *name);
void				print_usage();
int					ini_op_n(char *t, t_type type);
void				label_helper(t_lex **ptr, t_label **l, int *sz);
void				line_helper(t_lex **t, int *sz, int *c, int *k);

/*
**main.c
*/
int					process_champ(char *name);
void				create_cor(char *name, int *fd);

/*
**reading_proc.c
*/
void				clean_tokens(t_asm *champ);
void				tok_des(t_asm *champ, int *i, int *j, char *tmp);
void				new_to_list(t_lex **list, t_lex *new);
void				raw_file(char *name, t_asm *champ);
size_t				file_size(int fd);

/*
**split_tok.c
*/
void				n_line(int i, int j, char *tmp, t_asm *champ);
char				*get_token(char *file, int st, int en);
void				add_end_doc(t_lex **list);
void				add_new_command(t_lex **list);
void				add_new_token(char *token, t_lex **list, int line);

/*
**init_info.c
*/
t_asm				*init_asm(t_asm *champ);
t_lex				*init_tok(void);
t_label				*init_label(void);

/*
**utils3.c
*/
int					stop_tok(char i);
int					count_comment(char *file, int i);

/*
**operation.c
*/
int					pattern(char *t);
void				call_process(char *pro);
void				funny(void);

/*
**analyze_order.c
*/
void				analitics(t_asm *champ);
void				add_to_labl(t_label **l, t_label *new);
void				look_line(t_lex **t, int *sz);
int					no_continue(t_lex **ptr);
int					sz_type(t_lex **t, int k);

/*
**analyze_lex.c
*/
t_type				find_type(char *t);
t_type				check_oper(char *t);
t_type				check_reg(char *t);
t_type				check_tdir(char *t);
t_type				check_idir(char *t);

/*
**header_pars.c
*/
t_type				check_head(char *t);
void				verify_header(t_lex **ptr);
void				name_deal(t_lex **ptr, int *k);
void				comment_deal(t_lex **ptr, int *k);

/*
**verify_things.c
*/
void				valid_label(t_lex *ptr, t_label **l, int sz);
void				check_name_repeat(char *token, t_label **l);
void				verify_champ(t_lex **ptr, t_label **l, int *sz);
void				verify_t(t_lex **tlist, t_label **l);
int					verify_label(char *name, t_label **list);

/*
**convert_token.c
*/
void				convert_operation(t_lex *t, int fd, t_label *lab, int pos);
void				cvrt_one(t_lex *t, int fd);
void				cvrt_treg(t_lex *t, int fd);
void				cvrt_tdir_sz(t_lex *t, int fd, t_label *lab, int pos);
void				cvrt_idir_tdir(t_lex *t, int fd, t_label *lab, int pos);

/*
**utils2.c
*/
int					get_label_pos(char *name, t_label *lab, int pos);
void				define_head(t_lex *l, t_asm *h);
void				copy_till_n(t_lex *l, char *cont);
int					get_code(int ty);

/*
**error_manager.c
*/
void				common_err(char *e);
void				err_tok(char *e, t_lex *t);
void				err_chr(char *e, char *t);

/*
**convert.c
*/
void				translate(t_asm *a);
void				convert_body(t_asm *a);
void				oct(unsigned char *arg_ty, t_lex *t, int num);
void				convert_header(t_asm *a);
void				convert_big(int fd, unsigned len, unsigned char *content);

/*
**free_things.c
*/
void				free_asm(t_asm **as);
void				free_lex(t_lex **tk);
void				free_lab(t_label **ll);

#endif
