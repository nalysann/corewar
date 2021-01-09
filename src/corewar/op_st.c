/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 08:53:42 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 08:53:45 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

void	op_st(t_carriage *car, t_corewar *cw)
{
	int		args[2];
	int		value;

	get_args(args, car, cw);
	value = car->reg[args[0] - 1];
	if (car->args[1] == T_REG)
	{
		car->reg[args[1] - 1] = value;
	}
	else
	{
		set_int(cw->arena, args[1] % IDX_MOD + car->pos, value);
	}
}
