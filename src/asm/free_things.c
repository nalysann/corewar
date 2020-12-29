/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:37:55 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:37:57 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_lab(t_label **ll)
{
	t_label *tmp;
	t_label *del;

	tmp = *ll;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		ft_strdel(&(del->name));
		free(del);
		del = NULL;
	}
	*ll = NULL;
}

void	free_lex(t_lex **tk)
{
	t_lex *tmp;
	t_lex *del;

	tmp = (*tk);
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		ft_strdel(&(del->token));
		free(del);
		del = NULL;
	}
	*tk = NULL;
}

void	free_asm(t_asm **as)
{
	ft_strdel(&((*as)->raw));
	ft_strdel(&((*as)->clean));
	free_lex(&(*as)->tk_list);
	free_lab(&(*as)->ll);
	ft_strdel(&(*as)->name);
	ft_strdel(&(*as)->comment);
	ft_memdel((void **)as);
}
