/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:17:09 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 11:17:11 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void ch_ld(t_carriage *car, t_data *data) {
	int	args[2];
	int	res;

	get_args(args, car, data);
	if (car->args[0] == 2)
		res = args[0];
	else
		res = get_ind_value(args[0], car->position, data->arena, 0);
	car->reg[args[1] - 1] = res;
	car->carry = res ? 0 : 1;
}
