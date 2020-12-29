/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:31:35 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/07/27 22:31:57 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_forward_list	*ft_lstappend_frwd(t_forward_list *head, t_forward_list *new)
{
	t_forward_list *ptr;

	ptr = head;
	if (new && head)
		if (head)
		{
			while ((head)->next)
				head = (head)->next;
			(head)->next = new;
			return (ptr);
		}
	return (new);
}
