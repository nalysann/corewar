#include "corewar.h"
#include "utils.h"

void ch_st(t_carriage *car, t_data *data) {
	int args[2];
	int value;

	get_args(args, car, data);
	value = car->reg[args[0] - 1];
	if (car->args[1] == 1)
		car->reg[args[1] - 1] = value;
	else
		set_int(data->arena, args[1] % IDX_MOD + car->position, value);
}