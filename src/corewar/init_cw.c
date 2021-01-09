/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:06:50 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 10:06:51 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

#include "libft.h"

static int		parse_flags(char *str, t_corewar *cw)
{
	int		ret;

	ret = 2;
	if (str[0] == '-')
	{
		if (!cw->d_flag && ft_strequ(str + 1, "d"))
			cw->d_flag = 1;
		else if (ft_strequ(str + 1, "n"))
			++cw->n_flags;
		else if (!cw->a_flag && ft_strequ(str + 1, "a"))
		{
			cw->a_flag = 1;
			ret = 1;
		}
		else
			exit_with_error(INVALID_FLAG_MSG, E_INPUT);
	}
	else
		return (0);
	return (ret);
}

static void		parse_args(int argc, char *argv[], t_corewar *cw)
{
	int		ret;

	cw->num_players = 0;
	while (argc != 0)
	{
		if ((ret = parse_flags(*argv, cw)))
		{
			if (ret == 2 && !--argc)
				exit_with_error(MISSING_ARG, E_INPUT);
			++argv;
		}
		else
		{
			check_cor_extension(*argv, ".cor");
			++cw->num_players;
		}
		--argc;
		++argv;
	}
}

static int		handle_d_flag(char *argv[])
{
	while (!ft_strnequ(*argv, "-d", 2))
		++argv;
	++argv;
	if (!(*argv) || !ft_isnumber(*argv))
		exit_with_error(D_FLAG_MSG, E_INPUT);
	return (ft_atoi(*argv));
}

static void		create_players(t_corewar *cw)
{
	int		i;

	i = 0;
	cw->players = (t_player**)ft_memalloc(sizeof(t_player*) * cw->num_players);
	if (cw->players == NULL)
		exit_with_error(ALLOC_MSG, E_ALLOC);
	while (i < cw->num_players)
	{
		cw->players[i] = (t_player *)ft_memalloc(sizeof(t_player));
		if (cw->players[i] == NULL)
			exit_with_error(ALLOC_MSG, E_ALLOC);
		++i;
	}
}

void			init_cw(int argc, char *argv[], t_corewar *cw)
{
	cw->a_flag = 0;
	cw->d_flag = 0;
	cw->n_flags = 0;
	parse_args(argc - 1, argv + 1, cw);
	if (cw->num_players > MAX_PLAYERS || cw->num_players <= 0)
		exit_with_error(NUM_PLAYERS_MSG, E_INPUT);
	cw->dump_cycles = (cw->d_flag ? handle_d_flag(argv) : 0);
	cw->last_player_alive = cw->num_players;
	cw->cycles_to_die = CYCLE_TO_DIE;
	cw->num_cycles = 0;
	cw->num_live = 0;
	cw->num_checks = 0;
	cw->arena = NULL;
	cw->num_cars = 0;
	cw->car_list = NULL;
	create_players(cw);
	init_players(argv, cw);
	init_session(cw);
}
