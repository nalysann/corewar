/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:38:42 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:38:44 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		pattern(char *t)
{
	int i;

	i = 0;
	while (i < 17)
	{
		if (!ft_strcmp(t, g_op_tab[i].name))
			return (g_op_tab[i].op);
		i++;
	}
	return (i);
}

void	call_process(char *pro)
{
	ft_putendl_fd(GRE, 0);
	ft_putendl_fd(pro, 0);
	ft_putendl_fd(RES, 0);
}

void	funny(void)
{
	ft_putendl_fd(MAG, 0);
	ft_putendl_fd(" ____  _ ", 0);
	ft_putendl_fd("|___ \\/ |", 0);
	ft_putendl_fd("  __) | |", 0);
	ft_putendl_fd(" / __/| |", 0);
	ft_putstr_fd(GRE, 0);
	ft_putendl_fd("|_____|_| qweissna for", 0);
	ft_putendl_fd(BLU, 0);
	ft_putendl_fd(" _  _  ____", 0);
	ft_putendl_fd("| || ||___ \\ ", 0);
	ft_putendl_fd("| || |_ __) |", 0);
	ft_putendl_fd("|__   _/ __/ ", 0);
	ft_putstr_fd(GRE, 0);
	ft_putendl_fd("   |_||_____| COREWAR project 2020", 0);
	ft_putendl_fd(RES, 0);
}
