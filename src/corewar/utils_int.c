/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:33:13 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 11:33:14 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cop.h"
#include "utils.h"

#include <stddef.h>

static int	get_short(const char *bytearray)
{
	int		i;
	short	number;

	i = 0;
	number = 0;
	while (i < 2)
	{
		number |= bytearray[i] << 8 * (1 - i);
		++i;
	}
	return (number);
}

int			get_int(const char *bytearray, int size)
{
	int		i;
	int		number;

	i = 0;
	number = 0;
	if (size == 2)
	{
		number = get_short(bytearray);
	}
	else
	{
		while (i < 4)
		{
			number |= (unsigned char)bytearray[i] << 8 * (3 - i);
			++i;
		}
	}
	return (number);
}

int			fix_pos(int pos)
{
	if (pos < 0)
	{
		return (MEM_SIZE - (-pos % MEM_SIZE));
	}
	else if (pos >= MEM_SIZE)
	{
		return (pos % MEM_SIZE);
	}
	return (pos);
}

void		set_int(char *arena, int pos, int num)
{
	pos = fix_pos(pos);
	arena[pos] = (num & 0xff000000) >> 24;
	arena[(pos + 1) % MEM_SIZE] = (num & 0x00ff0000) >> 16;
	arena[(pos + 2) % MEM_SIZE] = (num & 0x0000ff00) >> 8;
	arena[(pos + 3) % MEM_SIZE] = (num & 0x000000ff);
}
