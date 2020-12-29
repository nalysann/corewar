/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:18:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 14:18:21 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"



void ch_xor(t_carriage *car, t_data *data) {
	int args[3];
	int values[2];
	int res;
	int i;

	i = 0;
	get_args(args, car, data);
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
	res = values[0] ^ values[1];
	car->reg[args[2] - 1] = res;
	car->carry = res ? 0 : 1;
}
