/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:15:04 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 11:15:05 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void ch_add(t_carriage *car, t_data *cw) {
	int args[3];
	int res;

	get_args(args, car, cw);
	res = car->reg[args[0] - 1] + car->reg[args[1] - 1];
	car->reg[args[2] - 1] = res;
	car->carry = res ? 0 : 1;
}
