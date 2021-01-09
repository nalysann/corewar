/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 08:57:55 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 08:57:57 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_carriage *car, t_corewar *cw)
{
	int		args[3];
	int		res;

	get_args(args, car, cw);
	res = car->reg[args[0] - 1] - car->reg[args[1] - 1];
	car->reg[args[2] - 1] = res;
	car->carry = (res == 0);
}
