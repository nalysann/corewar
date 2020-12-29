#include "corewar.h"
#include "utils.h"

void ch_sti(t_carriage *car, t_data *data) {
	int	args[3];
	int values[3];
	int i;
	int pos;

	get_args(args, car, data);
	i = 0;
	while (i < 3)
	{
		if (car->args[i] == 1)
			values[i] = car->reg[args[i] - 1];
		else if (car->args[i] == 2)
			values[i] = args[i];
		else if (car->args[i] == 4)
			values[i] = get_ind_value(args[i], car->position, data->arena, 0);
		++i;
	}
	pos = (values[1] + values[2]) % IDX_MOD + car->position;
	set_int(data->arena, pos, values[0]);
}
