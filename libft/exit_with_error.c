/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:10:53 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 15:11:09 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	exit_with_error(const char *error_message, int error_code)
{
	if (error_message != NULL)
	{
		ft_putstr_fd(RRED, STDERR_FILENO);
		ft_putstr_fd(error_message, STDERR_FILENO);
		ft_putendl_fd(RRESET, STDERR_FILENO);
	}
	exit(error_code);
}
