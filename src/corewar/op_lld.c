/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:08:41 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 09:08:42 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_carriage *car, t_corewar *cw)
{
	int		args[2];
	int		res;

	get_args(args, car, cw);
	if (car->args[0] == T_DIR)
	{
		res = args[0];
	}
	else
	{
		res = get_ind_arg(args[0], car->pos, cw->arena, 1);
	}
	car->reg[args[1] - 1] = res;
	car->carry = (res == 0);
}
