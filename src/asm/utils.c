/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:38:59 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:39:02 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_format(char *name)
{
	int len;

	len = ft_strlen(name);
	if (name[len - 1] == 's' && name[len - 2] == '.')
		return (1);
	return (0);
}

void	line_helper(t_lex **t, int *sz, int *c, int *k)
{
	(*sz) += sz_type(t, (*k));
	(*t) = (*t)->next;
	(*c)++;
}

void	label_helper(t_lex **ptr, t_label **l, int *sz)
{
	if (no_continue(ptr))
		err_tok("No operation after ", (*ptr));
	valid_label((*ptr), &(*l), *sz);
	(*ptr) = (*ptr)->next;
}

int		ini_op_n(char *t, t_type type)
{
	if (type != OPER || !t)
		return (-1);
	return (pattern(t));
}

void	print_usage(void)
{
	ft_putendl_fd("usage: ./asm [ {program_name}.s ]", 2);
}
