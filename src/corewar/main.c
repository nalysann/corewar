#include "corewar.h"
#include "libft.h"
#include "utils.h"

int main(int ac, char *av[])
{
	t_data data;

	if (ac == 1)
		exit_with_error(ARGS_MSG, E_NONE);
	init_data(ac, av, &data);
	players_init(av, &data);
	parse_players(&data);
	init_game(&data);
	game(&data);
	finish(&data);
	return (0);
}