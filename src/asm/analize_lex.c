/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_lex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:37:22 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:37:24 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_type	check_idir(char *t)
{
	int i;

	i = 0;
	if (t[0] != LABEL_CHAR)
	{
		if (t[0] == '-')
			i = 1;
		while (t[i])
		{
			if (ft_isdigit(t[i]))
				i++;
			else
				return (ERR);
		}
	}
	return (IDIR);
}

t_type	check_tdir(char *t)
{
	int i;

	i = 1;
	if (t[1] == LABEL_CHAR || ft_atoi(t + 1) || t[1] == '0')
	{
		if (t[1] != LABEL_CHAR)
		{
			if (t[1] == '-')
				i = 2;
			while (t[i])
			{
				if (ft_isdigit(t[i]))
					i++;
				else
					return (ERR);
			}
		}
		return (TDIR);
	}
	return (ERR);
}

t_type	check_reg(char *t)
{
	char	*tmp;
	int		i;

	tmp = t + 1;
	i = 0;
	if (ft_atoi(tmp) < (REG_NUMBER + 1) && ft_atoi(tmp) > 0)
	{
		while (tmp[i])
		{
			if (ft_isdigit(tmp[i]))
				i++;
			else
				err_chr("Register has bad symbol ", tmp);
		}
		return (TREG);
	}
	return (ERR);
}

t_type	check_oper(char *t)
{
	int i;

	i = pattern(t);
	if (i && i < 17)
		return (OPER);
	else
		return (ERR);
}

t_type	find_type(char *t)
{
	if (t[0] == '.' || t[0] == '"')
		return (check_head(t));
	else if (t[ft_strlen(t) - 1] == LABEL_CHAR)
		return (LABEL);
	else if (t[0] == LABEL_CHAR || ft_atoi(t) || t[0] == '0')
		return (check_idir(t));
	else if (t[0] == DIRECT_CHAR)
		return (check_tdir(t));
	else if (t[0] == 'r')
		return (check_reg(t));
	else if (!ft_strcmp(t, ","))
		return (COMMA);
	else
		return (check_oper(t));
}
