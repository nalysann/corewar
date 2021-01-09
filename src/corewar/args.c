/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:16:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 11:16:22 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

static int		get_arg_size(unsigned char arg, const t_op *op)
{
	if (arg == T_REG)
	{
		return (1);
	}
	else if (arg == T_DIR)
	{
		return (op->dir_size == 0 ? 4 : 2);
	}
	else if (arg == T_IND)
	{
		return (IND_SIZE);
	}
	return (0);
}

static void		get_arg_bytearray(char *bytearray, int size, const char *arena,
									int pos)
{
	int		i;

	i = 0;
	while (i < size)
	{
		bytearray[i] = arena[(pos + i) % MEM_SIZE];
		++i;
	}
	while (i < 4)
	{
		bytearray[i++] = 0;
	}
}

static int		get_arg_pos(int arg_index, const t_carriage *car)
{
	int		step;
	int		i;

	step = car->op->arg_code + 1;
	i = 0;
	while (i < arg_index)
	{
		step += get_arg_size(car->args[i], car->op);
		++i;
	}
	return (car->pos + step);
}

int				get_ind_arg(int arg, int car_pos, const char *arena, int l_flag)
{
	int		pos;
	char	bytearray[4];
	int		res;

	if (!l_flag)
	{
		arg %= IDX_MOD;
	}
	pos = fix_pos(car_pos + arg);
	get_arg_bytearray(bytearray, 4, arena, pos);
	res = get_int(bytearray, 4);
	return (res);
}

void			get_args(int *args, t_carriage *car, t_corewar *cw)
{
	int		i;
	int		pos;
	char	bytearray[4];

	i = 0;
	while (i < car->op->num_args)
	{
		pos = fix_pos(get_arg_pos(i, car));
		get_arg_bytearray(bytearray, get_arg_size(car->args[i], car->op),
					cw->arena, pos);
		if (car->args[i] == T_REG)
		{
			args[i] = cw->arena[pos];
		}
		else if (car->args[i] == T_DIR)
		{
			args[i] = get_int(bytearray, (car->op->dir_size == 0 ? 4 : 2));
		}
		else if (car->args[i] == T_IND)
		{
			args[i] = get_int(bytearray, 2);
		}
		++i;
	}
}
