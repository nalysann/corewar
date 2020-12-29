/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:55:57 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 17:55:59 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label_pos(char *name, t_label *lab, int pos)
{
	t_label *tmp;
	int		min;

	tmp = lab;
	min = (name[0] == LABEL_CHAR) ? 1 : 2;
	while (tmp)
	{
		if ((ft_strlen(tmp->name) - 1) == (ft_strlen(name) - min))
			if (!ft_strncmp(name + min, tmp->name, ft_strlen(tmp->name) - 1))
				return ((int)tmp->cur - pos);
		tmp = tmp->next;
	}
	return (0);
}

int		get_code(int ty)
{
	if (ty == T_DIR)
		return (DIR_CODE);
	else if (ty == IDIR)
		return (IND_CODE);
	else
		return (REG_CODE);
}

void	copy_till_n(t_lex *l, char *cont)
{
	int c;
	int p;

	c = 0;
	p = 1;
	while (l->token[p] != '"')
	{
		cont[c] = l->token[p];
		c++;
		p++;
	}
	cont[c] = '\0';
}

void	define_head(t_lex *l, t_asm *h)
{
	int i;

	i = 0;
	while (i != 2)
	{
		if (l->type == NAME)
		{
			l = l->next;
			copy_till_n(l, h->name);
			i++;
		}
		if (l->type == COMT)
		{
			l = l->next;
			copy_till_n(l, h->comment);
			i++;
		}
		l = l->next;
	}
}
