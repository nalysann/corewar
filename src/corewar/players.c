#include "corewar.h"
#include "utils.h"
#include "libft.h"

static void	player_init(int id, char *filename, t_player *player)
{
	if (!filename)
		exit_with_error(OPEN_FILE_MSG, E_NONE);
	player->id = id;
	player->filename = filename;
	ft_bzero(player->name, PROG_NAME_LENGTH + 1);
	ft_bzero(player->comment, COMMENT_LENGTH + 1);
	player->exec_size = 0;
	player->exec_code = NULL;
	player->starting_point = 0;
}

static int	is_duplicate(int id, t_data *data)
{
	int i;

	i = 0;
	while (i < data->players_amount)
	{
		if (data->players[i]->id == id)
			return (1);
		++i;
	}
	return (0);
}

static void	manage_n_flags(char **argv, t_data *data)
{
	int players_left;
	int id;

	players_left = data->n_flags;
	while (players_left)
	{
		while (!ft_strequ(*argv, "-n"))
			++argv;
		++argv;
		if (!(*argv) || !(ft_isnumber(*argv)))
			exit_with_error(WRONG_N_FLAG_USAGE, E_INPUT);
		id = ft_atoi(*argv);
		if (id <= 0 || id > data->players_amount)
			exit_with_error(WRONG_N_FLAG_USAGE_ID, E_INPUT);
		if (is_duplicate(id, data))
			exit_with_error(WRONG_N_FLAG_USAGE_DUP, E_INPUT);
		++argv;
		player_init(id, *argv, data->players[id - 1]);
		--players_left;
	}
}

void		add_players(int players_left, char **argv, t_data *data)
{
	int id;

	id = 1;
	while (players_left)
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
			while (is_duplicate(id, data))
				++id;
			player_init(id, *argv, data->players[id - 1]);
			--players_left;
			++argv;
		}
	}
}

void players_init(char **argv, t_data *data)
{
	int i;
	int players_left;

	i = 0;
	++argv;
	players_left = data->players_amount;
	while (i < data->players_amount)
	{
		data->players[i]->id = 0;
		i++;
	}
	if (data->n_flags)
	{
		manage_n_flags(argv, data);
		players_left -= data->n_flags;
	}
	if (players_left)
		add_players(players_left, argv, data);
}
