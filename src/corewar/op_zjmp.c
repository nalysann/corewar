/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:02:53 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 09:02:54 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

void	op_zjmp(t_carriage *car, t_corewar *cw)
{
	int		args[1];

	if (car->carry)
	{
		get_args(args, car, cw);
		car->pos = fix_pos(car->pos + args[0] % IDX_MOD);
		car->step = 0;
	}
}
