/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:58:46 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 10:58:48 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

static int			read_ints(int fd, int size)
{
	char	buf[size];

	if (read(fd, buf, size) != size)
	{
		exit_with_error(READ_MSG, E_INPUT);
	}
	return (get_int(buf, sizeof(int)));
}

static void			read_chars(int fd, int size, char *dst, int last)
{
	char	buf[size];
	int		i;

	i = 0;
	if (read(fd, buf, size) != size)
	{
		exit_with_error(READ_MSG, E_INPUT);
	}
	while (i < size)
	{
		dst[i] = buf[i];
		++i;
	}
	if (last && read(fd, buf, 1))
	{
		exit_with_error(CHAMPION_SIZE_MSG, E_INPUT);
	}
}

static void			read_nulls(int fd, int size)
{
	char	buf[size];
	int		i;

	i = 0;
	if (read(fd, buf, size) != size)
	{
		exit_with_error(READ_MSG, E_INPUT);
	}
	while (i < size)
	{
		if (buf[i] != 0)
		{
			exit_with_error(NULLS_MSG, E_INPUT);
		}
		++i;
	}
}

static void			parse_player(int fd, t_player *player)
{
	int tmp;
	if ((tmp = read_ints(fd, (int)sizeof(int))) != COREWAR_EXEC_MAGIC)
	{
		ft_printf("%d\n", tmp);
		exit_with_error(HEADER_MSG, E_INPUT);
	}
	read_chars(fd, PROG_NAME_LENGTH, player->name, 0);
	read_nulls(fd, (int)sizeof(int));
	player->size = read_ints(fd, (int)sizeof(int));
	if (player->size < 0 || player->size > CHAMP_MAX_SIZE)
	{
		exit_with_error(CHAMPION_SIZE_MSG, E_INPUT);
	}
	read_chars(fd, COMMENT_LENGTH, player->comment, 0);
	read_nulls(fd, (int)sizeof(int));
	player->code = (char *)ft_memalloc(player->size);
	if (player->code == NULL)
	{
		exit_with_error(ALLOC_MSG, E_ALLOC);
	}
	ft_bzero(player->code, player->size);
	read_chars(fd, player->size, player->code, 1);
}

void				parse_players(t_corewar *cw)
{
	int		i;
	int		fd;

	i = 0;
	while (i < cw->num_players)
	{
		if ((fd = open(cw->players[i]->filename, O_RDONLY)) < 0)
			exit_with_error(FILE_MSG, E_INPUT);
		parse_player(fd, cw->players[i]);
		close(fd);
		++i;
	}
}
