#include "corewar.h"
#include "utils.h"
#include "libft.h"
#include "stdlib.h"

t_carriage *create_carriage(int id, int pos) {
	t_carriage	*car;
	int			i;

	car = (t_carriage *)ft_memalloc(sizeof(t_carriage));
	if (!car)
		exit_with_error(ALLOC_MSG, E_ALLOC);
	car->id = id;
	car->carry = 0;
	car->op_i = -1;
	car->op = NULL;
	car->cycles_till_op = 0;
	car->last_cycle_live = -1;
	car->step = 0;
	car->position = pos;
	car->reg[0] = -id;
	car->to_delete = 0;
	i = 1;
	while (i < REG_NUMBER)
		car->reg[i++] = 0;
	i = 0;
	while (i < 4)
		car->args[i++] = 0;
	return (car);
}

void delete_carriages(int to_delete, t_data *data) {
	t_carriage	*prev;
	t_carriage	*cur;

	prev = NULL;
	cur = data->carriage_list;
	while (to_delete)
	{
		if (cur->to_delete)
		{
			if (prev)
				prev->next = cur->next;
			else
				data->carriage_list = cur->next;
			free(cur);
			cur = prev ? prev->next : data->carriage_list;
			--to_delete;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
