/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:14:51 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 18:14:53 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		count_comment(char *file, int i)
{
	int k;

	k = i + 1;
	while (file[k] != '"')
		k++;
	return (k + 1);
}

int		stop_tok(char i)
{
	if (i == COM_H || i == COMMENT_CHAR || i == '"' || i == SEPARATOR_CHAR)
		return (1);
	return (0);
}
