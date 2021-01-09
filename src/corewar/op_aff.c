/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:12:21 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 09:12:22 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	op_aff(t_carriage *car, t_corewar *cw)
{
	int		args[1];

	get_args(args, car, cw);
	if (cw->a_flag)
	{
		ft_putchar((char)car->reg[args[0] - 1]);
	}
}
