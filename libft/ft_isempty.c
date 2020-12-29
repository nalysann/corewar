/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:46:33 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 18:46:35 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isempty(char *line)
{
	int i;

	i = 0;
	if (!line || line[i] == '\0')
		return (0);
	while (line[i])
	{
		if (ft_isgraph(line[i]))
			return (1);
		i++;
	}
	return (0);
}
