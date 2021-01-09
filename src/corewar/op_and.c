/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 08:59:10 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 08:59:11 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_and(t_carriage *car, t_corewar *cw)
{
	int		args[3];
	int		values[2];
	int		res;
	int		i;

	i = 0;
	get_args(args, car, cw);
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
	res = values[0] & values[1];
	car->reg[args[2] - 1] = res;
	car->carry = (res == 0);
}
