/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_oct_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:20:38 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/29 18:51:10 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*gen_help(t_printf *lstprf, int len, unsigned long long in)
{
	char			*retn;
	char			*temp;
	char			*prefix;

	prefix = NULL;
	temp = NULL;
	retn = NULL;
	lstprf->flag & F_PREC && len > lstprf->prec ? lstprf->flag &= ~F_ZERO : 0;
	if (lstprf->flag & F_HASH && in && (prefix = ft_strdup("0")))
		len += 1;
	if (lstprf->flag & F_PREC && lstprf->prec > len)
		temp = ft_strnewc(lstprf->prec - len, '0');
	else if (lstprf->flag & F_ZERO && lstprf->width > len)
		temp = ft_strnewc(lstprf->width - len, '0');
	if (prefix && temp)
		retn = ft_strjoin(prefix, temp);
	if (retn)
	{
		free(prefix);
		free(temp);
		return (retn);
	}
	return (prefix ? prefix : temp);
}

static int			ft_gen_oct(unsigned long long in, t_printf *lstprf)
{
	char			*addpart;
	char			*prefix;
	char			*retn;
	int				len;

	(!in && lstprf->flag & F_PREC && !lstprf->prec && \
		!(lstprf->flag & F_HASH)) ? addpart = ft_strdup("") : \
		(addpart = ft_ulltoa_base(in, 8));
	prefix = gen_help(lstprf, ft_strlen(addpart), in);
	retn = ft_strjoin(prefix ? prefix : "", addpart);
	ft_strdel(&prefix);
	ft_strdel(&addpart);
	if ((len = ft_strlen(retn)) >= lstprf->width)
		write(lstprf->fd, retn, len);
	else
	{
		addpart = ft_strnewc(lstprf->width, ' ');
		(lstprf->flag & F_MINUS) ? ft_memcpy(addpart, retn, len) : \
			ft_strcpy(addpart + lstprf->width - len, retn);
		write(lstprf->fd, addpart, lstprf->width);
		ft_strdel(&addpart);
	}
	ft_strdel(&retn);
	return (len > lstprf->width ? len : lstprf->width);
}

int					ft_oct_type(t_printf *lstprf)
{
	unsigned long long	retn;

	lstprf->str++;
	if (lstprf->flag & L_HH)
		retn = (unsigned char)va_arg(lstprf->args, int);
	else if (lstprf->flag & L_H)
		retn = (unsigned short)va_arg(lstprf->args, int);
	else if (lstprf->flag & L_L)
		retn = va_arg(lstprf->args, unsigned long);
	else if (lstprf->flag & L_LL)
		retn = va_arg(lstprf->args, unsigned long long);
	else
		retn = va_arg(lstprf->args, unsigned int);
	return (ft_gen_oct(retn, lstprf));
}
