/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:16:32 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 11:16:34 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void				get_op_args(char byte, char *args)
{
	int i;
	int shift;

	i = 0;
	while (i < 4)
	{
		shift = 6 - 2 * i;
		args[i] = (byte & (3 << shift)) >> shift;
		if (args[i] == 3)
			args[i] = 4;
		++i;
	}
}

static int				check_reg(t_carriage *car, char *arena)
{
	unsigned char reg_byte;

	reg_byte = arena[(car->position + car->step - 1) % MEM_SIZE];
	if (reg_byte < 1 || reg_byte > 16)
		return (0);
	return (1);
}

static int				check_args(t_carriage *car, char *args, char *arena)
{
	int		i;
	int		correct;

	i = 0;
	correct = 1;
	while (i < car->op->args_amount)
	{
		if (args[i] == 1)
			++car->step;
		else if (args[i] == 2)
			car->step += car->op->dir_size == 0 ? 4 : 2;
		else if (args[i] == 4)
			car->step += 2;
		if (!(car->op->args[i] & args[i]) ||
			(args[i] == 1 && !check_reg(car, arena)))
			correct = 0;
		++i;
	}
	while (i < 4)
		if (args[i++])
			correct = 0;
	return (correct);
}

int validate_op(t_data *data, t_carriage *car) {
	if (car->op->arg_code)
	{
		get_op_args(data->arena[(car->position + 1) % MEM_SIZE], car->args);
		++car->step;
	}
	else
	{
		car->step += car->op->dir_size == 0 ? 4 : 2;
		car->args[0] = 2;
		return (1);
	}
	if (!check_args(car, car->args, data->arena))
		return (0);
	return (1);
}
