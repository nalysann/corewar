/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:37:38 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:37:42 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	convert_big(int fd, unsigned len, unsigned char *content)
{
	while (len)
	{
		len--;
		write(fd, &content[len], 1);
	}
}

void	convert_header(t_asm *a)
{
	char	*empty;
	int		z;

	z = 0;
	define_head(a->tk_list, a);
	write(a->fd, a->name, ft_strlen(a->name));
	empty = (char*)malloc(sizeof(char) * (PROG_NAME_LENGTH - \
		ft_strlen(a->name) + 1));
	ft_bzero(empty, PROG_NAME_LENGTH - ft_strlen(a->name) + 1);
	write(a->fd, empty, (PROG_NAME_LENGTH - ft_strlen(a->name)));
	write(a->fd, (unsigned char*)(&z), sizeof(int));
	ft_strdel(&empty);
	convert_big(a->fd, sizeof(int), (unsigned char*)(&a->full_size));
	write(a->fd, a->comment, ft_strlen(a->comment));
	empty = (char*)malloc(sizeof(char) * \
		(COMMENT_LENGTH - ft_strlen(a->comment) + 1));
	ft_bzero(empty, COMMENT_LENGTH - ft_strlen(a->comment) + 1);
	write(a->fd, empty, (COMMENT_LENGTH - ft_strlen(a->comment)));
	write(a->fd, (unsigned char*)(&z), sizeof(int));
	ft_strdel(&empty);
}

void	oct(unsigned char *arg_ty, t_lex *t, int num)
{
	t_lex	*tmp;
	int		i;

	tmp = t;
	i = 1;
	while (i <= num)
	{
		if (tmp->type != COMMA)
		{
			(*arg_ty) |= (get_code(tmp->type) << 2 * (4 - i));
			i++;
		}
		tmp = tmp->next;
	}
}

void	convert_body(t_asm *a)
{
	t_lex	*t;
	t_label	*lab;

	t = a->tk_list;
	lab = a->ll;
	while (t->type != OPER && t->type != LABEL && t->type != END)
		t = t->next;
	while (t->type != END)
	{
		if (t->type == OPER)
			convert_operation(t, a->fd, lab, t->byte);
		t = t->next;
	}
}

void	translate(t_asm *a)
{
	int c;

	c = COREWAR_EXEC_MAGIC;
	call_process(CON_ST);
	convert_big(a->fd, sizeof(int), (unsigned char *)(&c));
	convert_header(a);
	convert_body(a);
	call_process(CON_OK);
}
