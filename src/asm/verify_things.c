/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:14:52 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 17:14:55 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		verify_label(char *name, t_label **list)
{
	t_label *l;

	l = (*list);
	if (!l)
		err_chr("No such label ", name);
	if (l->name)
	{
		while (l)
		{
			if (!ft_strncmp(l->name, name, (ft_strlen(l->name) - 1)))
				return (1);
			l = l->next;
		}
		err_chr("No such label ", name);
	}
	return (0);
}

void	verify_t(t_lex **tlist, t_label **l)
{
	t_lex *t;

	t = (*tlist);
	while (t->type != END)
	{
		if (t->type == IDIR)
		{
			if (t->token[0] == LABEL_CHAR)
				verify_label(t->token + 1, l);
		}
		else if (t->type == TDIR)
		{
			if (t->token[1] == LABEL_CHAR)
				verify_label(t->token + 2, l);
		}
		t = t->next;
	}
}

void	check_name_repeat(char *token, t_label **l)
{
	int		i;
	t_label	*tmp;

	i = 0;
	tmp = (*l);
	while (token[i] && ft_strchr(LABEL_CHARS, token[i]))
		i++;
	if (token[i + 1] != '\0')
		err_chr("Forbidden char in ", token);
	if (l)
	{
		if (*l)
		{
			while (tmp)
			{
				if (!ft_strcmp(token, tmp->name))
					err_chr("Label already exist, double ", tmp->name);
				tmp = tmp->next;
			}
		}
	}
}

void	valid_label(t_lex *ptr, t_label **l, int sz)
{
	t_label *new;

	check_name_repeat(ptr->token, l);
	new = init_label();
	new->name = ft_strdup(ptr->token);
	new->cur = sz;
	add_to_labl(l, new);
}

void	verify_champ(t_lex **ptr, t_label **l, int *sz)
{
	int i;

	i = 0;
	while ((*ptr)->type != END)
	{
		while ((*ptr)->type != NEXT)
		{
			if ((*ptr)->type == LABEL)
				label_helper(ptr, l, sz);
			else if ((*ptr)->type == OPER)
			{
				(*ptr)->byte = *sz;
				(*sz) += 1;
				if (g_op_tab[(*ptr)->operator].code_arg)
					(*sz) += 1;
				look_line(ptr, sz);
			}
			else if ((*ptr)->type == NEXT)
				break ;
			else
				err_tok("Bad token type ", (*ptr));
		}
		i++;
		(*ptr) = (*ptr)->next;
	}
}
