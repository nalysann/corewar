#include "corewar.h"

void ch_sub(t_carriage *car, t_data *data) {
	int args[3];
	int res;

	get_args(args, car, data);
	res = car->reg[args[0] - 1] - car->reg[args[1] - 1];
	car->reg[args[2] - 1] = res;
	car->carry = res ? 0 : 1;
}
