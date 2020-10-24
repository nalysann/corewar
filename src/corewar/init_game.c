#include "corewar.h"
#include "libft.h"
#include "utils.h"

static void			create_arena(t_data *data)
{
	int i;
	int s_point;

	i = 0;
	data->arena = (char *)ft_memalloc(MEM_SIZE);
	if (!data->arena)
		exit_with_error(ALLOC_MSG, E_ALLOC);
	ft_bzero(data->arena, MEM_SIZE);
	s_point = MEM_SIZE / data->players_amount;
	while (i < data->players_amount)
	{
		data->players[i]->starting_point = s_point * i;
		ft_memcpy(data->arena + s_point * i,
				  data->players[i]->exec_code,
				  data->players[i]->exec_size);
		++i;
	}
}

static void			champs_introduction(t_data *data)
{
	int	i;

	i = 0;
	ft_putendl("Introducing contestants...");
	while (i < data->players_amount)
	{
		ft_putstr("* Player ");
		ft_putnbr(data->players[i]->id);
		ft_putstr(", weighing ");
		ft_putnbr((int)data->players[i]->exec_size);
		ft_putstr(" bytes, \"");
		ft_putstr(data->players[i]->name);
		ft_putstr("\" (\"");
		ft_putstr(data->players[i]->comment);
		ft_putstr("\") !\n");
		++i;
	}
}

static void			carriages_init(t_data *data)
{
	t_carriage	*new;
	int			i;

	i = 0;
	while (i < data->players_amount)
	{
		++data->cars_amount;
		new = create_carriage(data->cars_amount, data->players[i]->starting_point);
		new->next = data->carriage_list;
		data->carriage_list = new;
		++i;
	}
}


void init_game(t_data *data) {
	create_arena(data);
	carriages_init(data);
	champs_introduction(data);
}
