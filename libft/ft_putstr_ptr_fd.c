/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:49:56 by denis             #+#    #+#             */
/*   Updated: 2020/07/20 23:50:09 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_ptr_fd(const int fd, char const *start, char const *finish)
{
	if (start && finish && finish > start && fd > 0)
		return (write(fd, start, finish - start));
	return (0);
}
