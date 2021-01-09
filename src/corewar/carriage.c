/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:16:32 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 09:16:34 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

#include "libft.h"

#include <stdlib.h>

t_carriage	*create_carriage(int id, int pos)
{
	t_carriage	*car;
	int			i;

	car = (t_carriage *)ft_memalloc(sizeof(t_carriage));
	if (car == NULL)
		exit_with_error(ALLOC_MSG, E_ALLOC);
	car->id = id;
	car->carry = 0;
	car->last_cycle_live = -1;
	car->sleep_cycles = 0;
	car->step = 0;
	car->pos = pos;
	car->reg[0] = -id;
	car->needs_deletion = 0;
	car->op_id = -1;
	car->op = NULL;
	i = 1;
	while (i < REG_NUMBER)
		car->reg[i++] = 0;
	i = 0;
	while (i < 4)
		car->args[i++] = 0;
	return (car);
}

void		delete_carriages(int needs_deletion, t_corewar *cw)
{
	t_carriage	*prev;
	t_carriage	*cur;

	prev = NULL;
	cur = cw->car_list;
	while (needs_deletion)
	{
		if (cur->needs_deletion)
		{
			if (prev != NULL)
				prev->next = cur->next;
			else
				cw->car_list = cur->next;
			free(cur);
			cur = (prev != NULL ? prev->next : cw->car_list);
			--needs_deletion;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
