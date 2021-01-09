/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_cw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:36:02 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 11:36:03 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

#include "libft.h"

extern t_op			g_op_tab[17];
extern void			(*g_ops[16])(t_carriage *car, t_corewar *cw);

static void			get_op_code(char *arena, t_carriage *car)
{
	car->op_id = arena[car->pos];
	if (1 <= car->op_id && car->op_id <= 16)
	{
		car->op = &g_op_tab[car->op_id - 1];
		car->sleep_cycles = car->op->num_cycles;
	}
	else
	{
		car->sleep_cycles = 0;
	}
}

static void			execute_op(t_corewar *cw, t_carriage *car)
{
	++car->step;
	if (car->op != NULL && check_op(cw, car))
	{
		g_ops[car->op_id - 1](car, cw);
	}
	car->pos = fix_pos(car->pos + car->step);
	car->step = 0;
	car->op = NULL;
}

static void			run_cycle(t_corewar *cw)
{
	t_carriage	*car;

	car = cw->car_list;
	while (car != NULL)
	{
		if (car->op == NULL)
		{
			get_op_code(cw->arena, car);
		}
		if (car->sleep_cycles > 0)
		{
			--car->sleep_cycles;
		}
		if (car->sleep_cycles == 0)
		{
			execute_op(cw, car);
		}
		car = car->next;
	}
}

static void			perform_check(t_corewar *cw)
{
	int			num_delete;
	t_carriage	*car;

	++cw->num_checks;
	car = cw->car_list;
	num_delete = 0;
	while (car != NULL)
	{
		if (car->last_cycle_live <= cw->num_cycles - cw->cycles_to_die ||
			cw->cycles_to_die <= 0)
		{
			++num_delete;
			car->needs_deletion = 1;
		}
		car = car->next;
	}
	if (num_delete > 0)
		delete_carriages(num_delete, cw);
	if (cw->num_live >= NBR_LIVE || cw->num_checks == MAX_CHECKS)
	{
		cw->num_checks = 0;
		cw->cycles_to_die -= CYCLE_DELTA;
	}
	cw->num_live = 0;
}

void				play_cw(t_corewar *cw)
{
	int		cur_cycle;

	cur_cycle = 1;
	cw->num_cycles = 1;
	while (cw->car_list != NULL)
	{
		run_cycle(cw);
		if (cw->d_flag && cw->num_cycles == cw->dump_cycles)
		{
			display_arena(cw->arena);
			return ;
		}
		if (cur_cycle == cw->cycles_to_die || cw->cycles_to_die <= 0)
		{
			perform_check(cw);
			cur_cycle = 0;
		}
		++cur_cycle;
		++cw->num_cycles;
	}
}
