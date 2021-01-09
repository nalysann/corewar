/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:05:40 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 12:05:41 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include "libft.h"

#include <stdlib.h>

static void		free_cw(t_corewar *cw)
{
	t_carriage	*car;
	t_carriage	*tmp;
	int			i;

	car = cw->car_list;
	while (car != NULL)
	{
		tmp = car;
		car = car->next;
		free(car);
	}
	i = 0;
	while (i < cw->num_players)
	{
		free(cw->players[i]->code);
		free(cw->players[i]);
		++i;
	}
	free(cw->players);
	free(cw->arena);
}

void			end_cw(t_corewar *cw)
{
	t_player	*winner;

	winner = NULL;
	if (cw->car_list == NULL)
	{
		winner = cw->players[cw->last_player_alive - 1];
		ft_putstr("Contestant ");
		ft_putnbr(winner->id);
		ft_putstr(", \"");
		ft_putstr(winner->name);
		ft_putstr("\", has won !\n");
	}
	free_cw(cw);
}
