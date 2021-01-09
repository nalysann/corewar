/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:05:09 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 09:05:11 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

void	op_sti(t_carriage *car, t_corewar *cw)
{
	int		args[3];
	int		values[3];
	int		i;
	int		pos;

	get_args(args, car, cw);
	i = 0;
	while (i < 3)
	{
		if (car->args[i] == T_REG)
			values[i] = car->reg[args[i] - 1];
		else if (car->args[i] == T_DIR)
			values[i] = args[i];
		else if (car->args[i] == T_IND)
			values[i] = get_ind_arg(args[i], car->pos, cw->arena, 0);
		++i;
	}
	pos = (values[1] + values[2]) % IDX_MOD + car->pos;
	set_int(cw->arena, pos, values[0]);
}
