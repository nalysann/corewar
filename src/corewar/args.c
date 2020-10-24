#include "corewar.h"
#include "op.h"
#include "utils.h"

static int		get_arg_size(unsigned char arg, t_op *op)
{
	if (arg == 1)
		return (1);
	else if (arg == 2)
		return (op->dir_size == 0 ? 4 : 2);
	else if (arg == 4)
		return (IND_SIZE);
	return (0);
}

static void		get_arg_bytes(char *bytes, int size, char *arena, int byte_pos)
{
	int i;

	i = 0;
	while (i < size)
	{
		bytes[i] = arena[(byte_pos + i) % MEM_SIZE];
		++i;
	}
	while (i < 4)
		bytes[i++] = 0;
}

static int		get_arg_pos(int arg_i, t_carriage *car)
{
	int	step;
	int	i;

	step = car->op->arg_code + 1;
	i = 0;
	while (i < arg_i)
	{
		step += get_arg_size(car->args[i], car->op);
		++i;
	}
	return (car->position + step);
}

int get_ind_value(int arg, int car_pos, char *arena, int flag_l) {
	int		pos;
	char	bytes[4];
	int		res;

	if (!flag_l)
		arg %= IDX_MOD;
	pos = check_pos(car_pos + arg);
	get_arg_bytes(bytes, 4, arena, pos);
	res = get_int(bytes, 4);
	return (res);
}

void get_args(int *args, t_carriage *car, t_data *data) {
	int		i;
	int		pos;
	char	bytes[4];

	i = 0;
	while (i < car->op->args_amount)
	{
		pos = check_pos(get_arg_pos(i, car));
		get_arg_bytes(bytes, get_arg_size(car->args[i], car->op),
					  data->arena, pos);
		if (car->args[i] == 1)
			args[i] = data->arena[pos];
		else if (car->args[i] == 2)
			args[i] = get_int(bytes, car->op->dir_size == 0 ? 4 : 2);
		else if (car->args[i] == 4)
			args[i] = get_int(bytes, 2);
		++i;
	}
}

