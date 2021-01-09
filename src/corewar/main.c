/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:17:12 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 14:17:13 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "utils.h"

#include "libft.h"

int		main(int argc, char *argv[])
{
	t_corewar	cw;

	if (argc == 1)
	{
		ft_putendl_fd("Usage: ./corewar [-a] [-d N] "
						"[[-n N] <champion.cor>] [...]", 2);
		ft_putendl_fd("    -a : print output from \"aff\" operation", 2);
		ft_putendl_fd("    -d N : dump the memory after N cycles and exit", 2);
		ft_putendl_fd("    -n N : set a custom player number", 2);
		exit(E_USAGE);
	}
	init_cw(argc, argv, &cw);
	play_cw(&cw);
	end_cw(&cw);
	exit(EXIT_SUCCESS);
}
