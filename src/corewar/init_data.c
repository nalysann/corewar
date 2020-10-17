#include "corewar.h"
#include "libft.h"
#include "utils.h"

static int		check_flag(char *argv, t_data *data)
{
	int ret;

	ret = 2;
	if (argv[0] == CHAR_MINUS)
	{
		if (!data->d_flag && ft_strequ(&argv[1], "d"))
			data->d_flag = 1;
		else if (!data->d_flag && ft_strequ(&argv[1], "dump"))
			data->d_flag = 2;
		else if (ft_strequ(&argv[1], "n"))
			++data->n_flags;
		else if (!data->a_flag && ft_strequ(&argv[1], "a"))
		{
			data->a_flag = 1;
			ret = 1;
		}
		else
			exit_with_error(WRONG_FLAG, E_INPUT);
	}
	else
		return (0);
	return (ret);
}

static void		parse_args(int argc, char **argv, t_data *data)
{
	int		amount;
	int		ret;

	amount = 0;
	while (argc)
	{
		if ((ret = check_flag(*argv, data)))
		{
			if (ret == 2 && !--argc)
				exit_with_error(NO_FLAGS_ARGS, E_INPUT);
			++argv;
		}
		else
		{
			check_extension(*argv, ".cor");
			++amount;
		}
		--argc;
		++argv;
	}
	data->players_amount = amount;
}

static int		manage_d_flag(char **argv)
{
	while (!ft_strnequ(*argv, "-d", 2))
		++argv;
	++argv;
	if (!(*argv) || !ft_isnumber(*argv))
		exit_with_error(WRONG_D_FLAG_USAGE, E_INPUT);
	return (ft_atoi(*argv));
}

void init_data(int argc, char **argv, t_data *data) {
	data->a_flag = 0;
	data->d_flag = 0;
	data->n_flags = 0;
	data->cars_amount = 0;
	parse_args(argc - 1, argv + 1, data);
	if (data->players_amount > MAX_PLAYERS || data->players_amount == 0)
		exit_with_error(WRONG_PLAYERS_AMOUNT, E_INPUT);
	data->last_player_alive = data->players_amount;
	data->d_cycles = data->d_flag ? manage_d_flag(argv) : 0;
	data->cycles_to_die = CYCLE_TO_DIE;
	data->game_cycles = 0;
	data->live_ops = 0;
	data->checks_performed = 0;
	data->arena = NULL;
	data->carriage_list = NULL;
}
