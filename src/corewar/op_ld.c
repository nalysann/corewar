/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 08:50:23 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 08:50:25 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_carriage *car, t_corewar *cw)
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
		res = get_ind_arg(args[0], car->pos, cw->arena, 0);
	}
	car->reg[args[1] - 1] = res;
	car->carry = (res == 0);
}
