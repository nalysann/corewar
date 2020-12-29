/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:17:04 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 14:17:05 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void ch_lldi(t_carriage *car, t_data *data) {
	int	args[3];
	int	values[2];
	int	i;
	int	res;

	get_args(args, car, data);
	i = 0;
	while (i < 2)
	{
		if (car->args[i] == 1)
			values[i] = car->reg[args[i] - 1];
		else if (car->args[i] == 2)
			values[i] = args[i];
		else if (car->args[i] == 4)
			values[i] = get_ind_value(args[i], car->position, data->arena, 0);
		++i;
	}
	res = get_ind_value(values[0] + values[1], car->position, data->arena, 1);
	car->reg[args[2] - 1] = res;
	car->carry = res == 0 ? 1 : 0;
}
