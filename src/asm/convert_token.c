/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:54:23 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 17:54:25 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	cvrt_idir_tdir(t_lex *t, int fd, t_label *lab, int pos)
{
	unsigned short	x;

	if (t->token[1] == LABEL_CHAR || t->token[0] == LABEL_CHAR)
		x = (unsigned short)get_label_pos(t->token, lab, pos);
	else if (t->token[0] == DIRECT_CHAR)
		x = (unsigned short)ft_atoi(t->token + 1);
	else
		x = (unsigned short)ft_atoi(t->token);
	convert_big(fd, sizeof(x), (unsigned char*)(&x));
}

void	cvrt_tdir_sz(t_lex *t, int fd, t_label *lab, int pos)
{
	unsigned int	j;

	if (t->token[1] == LABEL_CHAR)
		j = (unsigned int)get_label_pos(t->token, lab, pos);
	else
		j = (unsigned int)ft_atoi(t->token + 1);
	convert_big(fd, sizeof(j), (unsigned char*)(&j));
}

void	cvrt_treg(t_lex *t, int fd)
{
	unsigned char	k;
	int				reg;

	reg = ft_atoi(t->token + 1);
	k = (unsigned char)reg;
	convert_big(fd, sizeof(k), (unsigned char*)(&k));
}

void	cvrt_one(t_lex *t, int fd)
{
	unsigned char	k;

	k = 0;
	oct(&k, t->next, g_op_tab[t->operator].nb_arg);
	convert_big(fd, sizeof(k), (unsigned char*)(&k));
}

void	convert_operation(t_lex *t, int fd, t_label *lab, int pos)
{
	unsigned char	k;
	int				c;

	k = (unsigned char)(t->operator);
	convert_big(fd, sizeof(k), (unsigned char*)(&k));
	k = (unsigned char)g_op_tab[t->operator].code_arg;
	c = g_op_tab[t->operator].tdir_size;
	if (k)
		cvrt_one(t, fd);
	while (t->type != NEXT)
	{
		if (t->type == TREG)
			cvrt_treg(t, fd);
		else if (t->type == TDIR && !c)
			cvrt_tdir_sz(t, fd, lab, pos);
		else if (t->type == TDIR || t->type == IDIR)
			cvrt_idir_tdir(t, fd, lab, pos);
		t = t->next;
	}
}
