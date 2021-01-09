/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:11:09 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 09:11:11 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

void	op_lfork(t_carriage *car, t_corewar *cw)
{
	int			args[1];
	int			pos;
	int			i;
	t_carriage	*new_car;

	get_args(args, car, cw);
	pos = fix_pos(car->pos + args[0]);
	new_car = create_carriage(++cw->num_cars, pos);
	i = 0;
	while (i < REG_NUMBER)
	{
		new_car->reg[i] = car->reg[i];
		++i;
	}
	new_car->carry = car->carry;
	new_car->last_cycle_live = car->last_cycle_live;
	new_car->next = cw->car_list;
	cw->car_list = new_car;
}
