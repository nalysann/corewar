/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:16:47 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 14:16:48 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void ch_live(t_carriage *car, t_data *data) {
	int	args[1];

	car->last_cycle_live = data->game_cycles;
	get_args(args, car, data);
	if (-args[0] > 0 && -args[0] <= data->players_amount)
		data->last_player_alive = -args[0];
	++data->live_ops;
}
