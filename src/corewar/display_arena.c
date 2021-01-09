/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:16:40 by nalysann          #+#    #+#             */
/*   Updated: 2021/01/09 12:16:41 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include "libft.h"

static void		get_hex(int n, int *len, char *buf, int i)
{
	int		c;

	if (n >= 16)
	{
		++*len;
		get_hex(n / 16, len, buf, i - 1);
	}
	c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	buf[i] = c;
}

static void		print_hex(char *buf, int len, int width)
{
	int i;

	i = 0;
	while (i + len < width)
	{
		ft_putchar('0');
		++i;
	}
	while (i < width)
	{
		ft_putchar(buf[i++]);
	}
}

static void		print_bytes(char *arena, int num_bytes)
{
	int		i;
	int		len;
	char	buf[2];

	i = 0;
	while (i < num_bytes)
	{
		len = 1;
		ft_bzero(buf, 2);
		get_hex((unsigned char)*arena, &len, buf, 1);
		print_hex(buf, len, 2);
		ft_putchar(' ');
		++arena;
		++i;
	}
}

void			display_arena(char *arena)
{
	int		pos;
	int		len;
	char	buf[4];
	int		num_bytes;

	num_bytes = 64;
	pos = 0;
	while (pos < MEM_SIZE)
	{
		ft_bzero(buf, 4);
		len = 1;
		ft_putstr("0x");
		get_hex(pos, &len, buf, 3);
		print_hex(buf, len, 4);
		ft_putstr(" : ");
		print_bytes(arena, num_bytes);
		ft_putchar('\n');
		pos += num_bytes;
		arena += num_bytes;
	}
}
