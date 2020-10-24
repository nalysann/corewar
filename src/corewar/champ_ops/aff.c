#include "corewar.h"
#include "libft.h"

void ch_aff(t_carriage *car, t_data *data) {
	int	args[1];

	get_args(args, car, data);
	if (data->a_flag)
		ft_putchar((char)car->reg[args[0] - 1]);
}
