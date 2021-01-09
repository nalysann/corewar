/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:18:15 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 14:18:17 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include "libft.h"

void	check_cor_extension(const char *filename, const char *extension)
{
	size_t	filename_length;
	size_t	extension_length;

	filename_length = ft_strlen(filename);
	extension_length = ft_strlen(extension);
	if (filename_length < (extension_length + 1) ||
	ft_strcmp(filename + filename_length - extension_length, extension) != 0)
		exit_with_error(EXTENSION_MSG, E_INPUT);
}

int		ft_isnumber(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
}
