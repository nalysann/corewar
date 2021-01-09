/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:26:00 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 13:26:01 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_op_args(char byte, char *args)
{
	int		i;
	int		shift;

	i = 0;
	while (i < 4)
	{
		shift = 6 - 2 * i;
		args[i] = (byte & (3 << shift)) >> shift;
		if (args[i] == 3)
		{
			args[i] = 4;
		}
		++i;
	}
}

static int		check_register(t_carriage *car, const char *arena)
{
	unsigned char	reg_id;

	reg_id = arena[(car->pos + car->step - 1) % MEM_SIZE];
	if (reg_id < 1 || reg_id > REG_NUMBER)
	{
		return (0);
	}
	return (1);
}

static int		check_args(t_carriage *car, const char *args, char *arena)
{
	int		i;
	int		is_valid;

	i = 0;
	is_valid = 1;
	while (i < car->op->num_args)
	{
		if (args[i] == T_REG)
			++car->step;
		else if (args[i] == T_DIR)
			car->step += (car->op->dir_size == 0 ? 4 : 2);
		else if (args[i] == T_IND)
			car->step += 2;
		if (!(car->op->args[i] & args[i]) ||
			(args[i] == T_REG && !check_register(car, arena)))
			is_valid = 0;
		++i;
	}
	while (i < 4)
		if (args[i++])
			is_valid = 0;
	return (is_valid);
}

int				check_op(t_corewar *cw, t_carriage *car)
{
	if (car->op->arg_code != 0)
	{
		get_op_args(cw->arena[(car->pos + 1) % MEM_SIZE], car->args);
		++car->step;
	}
	else
	{
		car->step += (car->op->dir_size == 0 ? 4 : 2);
		car->args[0] = 2;
		return (1);
	}
	if (!check_args(car, car->args, cw->arena))
	{
		return (0);
	}
	return (1);
}
