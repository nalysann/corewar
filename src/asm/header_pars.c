/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:38:03 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:38:05 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	comment_deal(t_lex **ptr, int *k)
{
	(*ptr) = (*ptr)->next;
	if ((*ptr)->type == MEAN)
	{
		if ((ft_strlen((*ptr)->token) - 2) > COMMENT_LENGTH)
			common_err("too long comment");
		(*ptr) = (*ptr)->next;
	}
	else
		common_err("after .comment should be string");
	if ((*ptr)->type == NEXT)
		(*ptr) = (*ptr)->next;
	else
		common_err("after command should be new line");
	k[1]++;
}

void	name_deal(t_lex **ptr, int *k)
{
	(*ptr) = (*ptr)->next;
	if ((*ptr)->type == MEAN)
	{
		if ((ft_strlen((*ptr)->token) - 2) > PROG_NAME_LENGTH)
			common_err("too long name");
		(*ptr) = (*ptr)->next;
	}
	else
		common_err("after .name should be string");
	if ((*ptr)->type == NEXT)
		(*ptr) = (*ptr)->next;
	else
		common_err("after command should be new line");
	k[0]++;
}

void	verify_header(t_lex **ptr)
{
	int k[2];

	k[0] = 0;
	k[1] = 0;
	if ((*ptr)->type == NAME)
		name_deal(ptr, k);
	else if ((*ptr)->type == COMT)
		comment_deal(ptr, k);
	else
		common_err("bad header");
	if ((*ptr)->type == COMT)
		comment_deal(ptr, k);
	else if ((*ptr)->type == NAME)
		name_deal(ptr, k);
	else
		common_err("bad header");
	if (k[0] != 1 || k[1] != 1)
		common_err(".name and .comment should use only 1");
}

t_type	check_head(char *t)
{
	if (t[0] == '.')
	{
		if (!ft_strncmp(t, ".name", 5) && t[5] == '\0')
			return (NAME);
		else if (!ft_strncmp(t, ".comment", 8) && t[8] == '\0')
			return (COMT);
	}
	else if (t[0] == '"')
		return (MEAN);
	return (ERR);
}
