/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:15:13 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 11:15:15 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void ch_aff(t_carriage *car, t_data *data) {
	int	args[1];

	get_args(args, car, data);
	if (data->a_flag)
		ft_putchar((char)car->reg[args[0] - 1]);
}
