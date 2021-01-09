/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 08:47:58 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 08:48:00 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_carriage *car, t_corewar *cw)
{
	int		args[1];
	int		num;

	car->last_cycle_live = cw->num_cycles;
	get_args(args, car, cw);
	num = -args[0];
	if (0 < num && num <= cw->num_players)
	{
		cw->last_player_alive = num;
	}
	++cw->num_live;
}
