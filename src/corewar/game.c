/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:16:45 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 11:16:45 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"
#include "libft.h"
#include "op.h"

extern t_op g_op_tab[17];
extern void (*g_champ_ops[16])(t_carriage *car, t_data *data);

static void			check(t_data *data)
{
	int			cars_to_delete;
	t_carriage	*car;

	++data->checks_performed;
	car = data->carriage_list;
	cars_to_delete = 0;
	while (car)
	{
		if (car->last_cycle_live <= data->game_cycles - data->cycles_to_die ||
			data->cycles_to_die <= 0)
		{
			++cars_to_delete;
			car->to_delete = 1;
		}
		car = car->next;
	}
	if (cars_to_delete)
		delete_carriages(cars_to_delete, data);
	if (data->live_ops >= NBR_LIVE || data->checks_performed == MAX_CHECKS)
	{
		data->checks_performed = 0;
		data->cycles_to_die -= CYCLE_DELTA;
	}
	data->live_ops = 0;
}

static void			get_op_code(char *arena, t_carriage *car)
{
	car->op_i = arena[car->position];
	if (car->op_i >= 1 && car->op_i <= 0x10)
	{
		car->op = &g_op_tab[car->op_i - 1];
		car->cycles_till_op = car->op->cycles;
	}
	else
		car->cycles_till_op = 0;
}

static void			execute_op(t_data *data, t_carriage *car)
{
	++car->step;
	if (car->op && validate_op(data, car))
		g_champ_ops[car->op_i - 1](car, data);
	car->position = check_pos(car->position + car->step);
	car->step = 0;
	car->op = NULL;
}

static void			main_cycle(t_data *data)
{
	t_carriage	*car;

	car = data->carriage_list;
	while (car)
	{
		if (!car->op)
			get_op_code(data->arena, car);
		if (car->cycles_till_op > 0)
			--car->cycles_till_op;
		if (car->cycles_till_op == 0)
			execute_op(data, car);
		car = car->next;
	}
}

void				game(t_data *data)
{
	int	loop_iter;

	loop_iter = 1;
	data->game_cycles = 1;
	while (data->carriage_list)
	{
		main_cycle(data);
		if (data->d_flag && data->game_cycles == data->d_cycles)
		{
			display_arena(data->arena, 32 * data->d_flag);
			return ;
		}
		if (loop_iter == data->cycles_to_die || data->cycles_to_die <= 0)
		{
			check(data);
			loop_iter = 0;
		}
		++loop_iter;
		++data->game_cycles;
	}
}
