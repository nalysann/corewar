#include "corewar.h"
#include "utils.h"

void ch_fork(t_carriage *car, t_data *data) {
	t_carriage		*new;
	int				args[1];
	int				pos;
	int				i;

	get_args(args, car, data);
	pos = check_pos(car->position + (args[0] % IDX_MOD));
	new = create_carriage(++data->cars_amount, pos);
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = car->reg[i];
		++i;
	}
	new->carry = car->carry;
	new->last_cycle_live = car->last_cycle_live;
	new->next = data->carriage_list;
	data->carriage_list = new;
}
