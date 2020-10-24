#include "corewar.h"
#include "utils.h"

void ch_zjmp(t_carriage *car, t_data *data) {
	int	args[1];

	if (car->carry)
	{
		get_args(args, car, data);
		car->position = check_pos(car->position + args[0] % IDX_MOD);
		car->step = 0;
	}
}
