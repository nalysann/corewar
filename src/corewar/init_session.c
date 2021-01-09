/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:22:39 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 11:22:40 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

#include "libft.h"

static void		create_arena(t_corewar *cw)
{
	int		i;
	int		pos;

	i = 0;
	cw->arena = (char *)ft_memalloc(MEM_SIZE);
	if (cw->arena == NULL)
	{
		exit_with_error(ALLOC_MSG, E_ALLOC);
	}
	ft_bzero(cw->arena, MEM_SIZE);
	pos = MEM_SIZE / cw->num_players;
	while (i < cw->num_players)
	{
		cw->players[i]->start = pos * i;
		ft_memcpy(cw->arena + pos * i,
			cw->players[i]->code,
			cw->players[i]->size);
		++i;
	}
}

static void		init_cars(t_corewar *cw)
{
	int			i;
	t_carriage	*new_car;

	i = 0;
	while (i < cw->num_players)
	{
		++cw->num_cars;
		new_car = create_carriage(cw->num_cars, cw->players[i]->start);
		new_car->next = cw->car_list;
		cw->car_list = new_car;
		++i;
	}
}

static void		introduce_champions(t_corewar *cw)
{
	int		i;

	i = 0;
	ft_putendl("Introducing contestants...");
	while (i < cw->num_players)
	{
		ft_putstr("* Player ");
		ft_putnbr(cw->players[i]->id);
		ft_putstr(", weighing ");
		ft_putnbr(cw->players[i]->size);
		ft_putstr(" bytes, \"");
		ft_putstr(cw->players[i]->name);
		ft_putstr("\" (\"");
		ft_putstr(cw->players[i]->comment);
		ft_putstr("\") !\n");
		++i;
	}
}

void			init_session(t_corewar *cw)
{
	create_arena(cw);
	init_cars(cw);
	introduce_champions(cw);
}
