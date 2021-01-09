/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:42:20 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 10:42:23 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

#include "libft.h"

static void		init_player(int id, char *filename, t_player *player)
{
	if (filename == NULL)
		exit_with_error(FILE_MSG, E_NONE);
	player->id = id;
	player->filename = filename;
	ft_bzero(player->name, PROG_NAME_LENGTH + 1);
	ft_bzero(player->comment, COMMENT_LENGTH + 1);
	player->size = 0;
	player->code = NULL;
	player->start = 0;
}

static int		is_duplicate(int id, t_corewar *cw)
{
	int		i;

	i = 0;
	while (i < cw->num_players)
	{
		if (cw->players[i]->id == id)
			return (1);
		++i;
	}
	return (0);
}

static void		handle_n_flags(char *argv[], t_corewar *cw)
{
	int		num_players;
	int		id;

	num_players = cw->n_flags;
	while (num_players > 0)
	{
		while (!ft_strequ(*argv, "-n"))
			++argv;
		++argv;
		if (!(*argv) || !(ft_isnumber(*argv)))
			exit_with_error(N_FLAG_ID_MSG, E_INPUT);
		id = ft_atoi(*argv);
		if (id <= 0 || id > cw->num_players)
			exit_with_error(N_FLAG_ID_MSG, E_INPUT);
		if (is_duplicate(id, cw))
			exit_with_error(N_FLAG_DUPLICATE_MSG, E_INPUT);
		++argv;
		init_player(id, *argv, cw->players[id - 1]);
		--num_players;
	}
}

void			add_players(int num_players, char *argv[], t_corewar *cw)
{
	int		id;

	id = 1;
	while (num_players > 0)
	{
		if ((*argv)[0] == '-')
		{
			if ((*argv)[1] == 'n')
				argv += 3;
			else if ((*argv)[1] == 'a')
				argv += 1;
			else
				argv += 2;
		}
		else
		{
			while (is_duplicate(id, cw))
				++id;
			init_player(id, *argv, cw->players[id - 1]);
			--num_players;
			++argv;
		}
	}
}

void			init_players(char *argv[], t_corewar *cw)
{
	int		i;
	int		num_players;

	i = 0;
	++argv;
	num_players = cw->num_players;
	while (i < cw->num_players)
	{
		cw->players[i]->id = 0;
		++i;
	}
	if (cw->n_flags)
	{
		handle_n_flags(argv, cw);
		num_players -= cw->n_flags;
	}
	if (num_players > 0)
	{
		add_players(num_players, argv, cw);
	}
	parse_players(cw);
}
