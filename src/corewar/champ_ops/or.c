#include "corewar.h"

void ch_or(t_carriage *car, t_data *data) {
	int	args[3];
	int	values[2];
	int	res;
	int	i;

	get_args(args, car, data);
	i = 0;
	while (i < 2)
	{
		if (car->args[i] == 1)
			values[i] = car->reg[args[i] - 1];
		else if (car->args[i] == 2)
			values[i] = args[i];
		else if (car->args[i] == 4)
			values[i] = get_ind_value(args[i], car->position, data->arena, 0);
		++i;
	}
	res = values[0] | values[1];
	car->reg[args[2] - 1] = res;
	car->carry = res ? 0 : 1;
}
