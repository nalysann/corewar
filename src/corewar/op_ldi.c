/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:04:03 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 09:04:04 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ldi(t_carriage *car, t_corewar *cw)
{
	int		args[3];
	int		values[2];
	int		i;
	int		res;

	get_args(args, car, cw);
	i = 0;
	while (i < 2)
	{
		if (car->args[i] == T_REG)
			values[i] = car->reg[args[i] - 1];
		else if (car->args[i] == T_DIR)
			values[i] = args[i];
		else
			values[i] = get_ind_arg(args[i], car->pos, cw->arena, 0);
		++i;
	}
	res = get_ind_arg(values[0] + values[1], car->pos, cw->arena, 0);
	car->reg[args[2] - 1] = res;
}
