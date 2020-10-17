#include "corewar.h"
#include "libft.h"
#include "utils.h"

int ft_isnumber(char *str) {
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void check_extension(char *filename, char *old) {
	size_t	length;
	size_t	extension_length;

	length = ft_strlen(filename);
	extension_length = ft_strlen(old);
	if (length < (extension_length + 1) || ft_strcmp(&filename[length - extension_length], old) != 0)
		exit_with_error(WRONG_FILE_EXTENSION_MSG, E_INPUT);
}


void debug_data(t_data *data) {
	ft_printf("players_amount = %d\n", data->players_amount);
	ft_printf("a_flag = %d\n", data->a_flag);
	ft_printf("n_flags = %d\n", data->n_flags);
	ft_printf("d_flag = %d\n", data->d_flag);
	ft_printf("d_cycles = %d\n", data->d_cycles);
	ft_printf("cars_amount = %d\n", data->cars_amount);
	ft_printf("last_player_alive = %d\n", data->last_player_alive);
	ft_printf("cycles_to_die = %d\n", data->cycles_to_die);
	ft_printf("game_cycles = %d\n", data->game_cycles);
	ft_printf("live_ops = %d\n", data->live_ops);
	ft_printf("checks_performed = %d\n", data->checks_performed);
}
