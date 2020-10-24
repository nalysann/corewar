#include "corewar.h"
#include "libft.h"
#include "stdlib.h"

static void		announce_winner(t_player *winner)
{
	ft_putstr("Contestant ");
	ft_putnbr(winner->id);
	ft_putstr(", \"");
	ft_putstr(winner->name);
	ft_putstr("\", has won !\n");
}

static void		free_data(t_data *data)
{
	t_carriage	*car;
	t_carriage	*next;
	int			i;

	car = data->carriage_list;
	while (car)
	{
		next = car->next;
		free(car);
		car = next;
	}
	i = 0;
	while (i < data->players_amount)
	{
		free(data->players[i]->exec_code);
		free(data->players[i]);
		++i;
	}
	free(data->players);
	free(data->arena);
}

void finish(t_data *data) {
	if (!data->carriage_list)
		announce_winner(data->players[data->last_player_alive - 1]);
	free_data(data);
}
