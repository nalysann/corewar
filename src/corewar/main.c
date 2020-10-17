#include "corewar.h"
#include "libft.h"
#include "utils.h"

int main(int ac, char *av[])
{
	t_data data;

	if (ac == 1)
		exit_with_error(ARGS_MSG, E_NONE);
	init_data(ac, av, &data);
	debug_data(&data);
	return (0);
}