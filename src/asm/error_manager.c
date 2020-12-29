/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:37:47 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:37:49 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	err_chr(char *e, char *t)
{
	ft_putstr_fd(YEL, 2);
	ft_putstr_fd(e, 2);
	ft_putstr_fd(RD, 2);
	ft_putstr_fd(t, 2);
	ft_putendl_fd(RES, 2);
	common_err(FAIL_STOP);
}

void	err_tok(char *e, t_lex *t)
{
	ft_putstr_fd(YEL, 2);
	ft_putstr_fd(e, 2);
	ft_putstr_fd(RD, 2);
	ft_putstr_fd(t->token, 2);
	ft_putstr_fd(YEL, 2);
	ft_putstr_fd(" at line ", 2);
	ft_putstr_fd(RD, 2);
	ft_putnbr_fd(t->position, 2);
	ft_putendl_fd(RES, 2);
	common_err(FAIL_STOP);
}

void	common_err(char *e)
{
	ft_putendl_fd(RD, 2);
	ft_putendl_fd(e, 2);
	ft_putendl_fd(RES, 2);
	exit(-1);
}
