/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:09:43 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 09:09:44 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lldi(t_carriage *car, t_corewar *cw)
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
		else if (car->args[i] == T_IND)
			values[i] = get_ind_arg(args[i], car->pos, cw->arena, 0);
		++i;
	}
	res = get_ind_arg(values[0] + values[1], car->pos, cw->arena, 1);
	car->reg[args[2] - 1] = res;
	car->carry = (res == 0);
}
