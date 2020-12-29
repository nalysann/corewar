/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:37:31 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:37:33 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		sz_type(t_lex **t, int k)
{
	int u;

	u = 2;
	if ((*t)->type == TREG)
		return (1);
	if ((*t)->type == IDIR)
		return (IND_SIZE);
	if ((*t)->type == TDIR)
	{
		!g_op_tab[k].tdir_size ? u += 2 : 0;
		return (u);
	}
	err_tok("Error arg ", (*t));
	return (-1);
}

int		no_continue(t_lex **ptr)
{
	t_lex *tmp;

	tmp = (*ptr);
	if (tmp->type != LABEL && tmp->type != OPER)
		return (1);
	if (tmp->type == LABEL)
	{
		while (tmp)
		{
			if (tmp->type == OPER)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

void	look_line(t_lex **t, int *sz)
{
	int i;
	int c;
	int k;

	k = (*t)->operator;
	i = g_op_tab[k].nb_arg;
	(*t) = (*t)->next;
	c = 0;
	while (c < i)
	{
		if (g_op_tab[k].arg_type[c] & (*t)->type)
			line_helper(t, sz, &c, &k);
		else
			err_tok("Bad operation argument ", (*t));
		if (!c)
			err_tok("No valid arg after operation ", (*t));
		if ((*t)->type == COMMA && c != i)
			(*t) = (*t)->next;
		else if (c != i)
			err_tok("Invalid args number ", (*t));
	}
	if ((*t)->type != NEXT)
		err_tok("One line should = one operation ", (*t));
}

void	add_to_labl(t_label **l, t_label *new)
{
	t_label *p;

	if (l)
	{
		if (*l)
		{
			p = (*l);
			while (p->next)
				p = p->next;
			p->next = new;
		}
		else
			*l = new;
	}
}

void	analitics(t_asm *c)
{
	t_lex *ptr;

	ptr = c->tk_list;
	call_process(SYN_AN);
	verify_header(&ptr);
	if (no_continue(&ptr))
		common_err("There are no operations after header");
	verify_champ(&ptr, &c->ll, &(c->full_size));
	verify_t(&c->tk_list, &c->ll);
	call_process(SYN_AN_G);
}
