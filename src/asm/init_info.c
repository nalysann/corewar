/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:38:11 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:38:18 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lex	*init_tok(void)
{
	t_lex *new;

	if (!(new = (t_lex*)malloc(sizeof(t_lex))))
		common_err(MAL);
	new->token = NULL;
	new->type = -1;
	new->position = -1;
	new->operator = -1;
	new->byte = -1;
	new->next = NULL;
	return (new);
}

t_label	*init_label(void)
{
	t_label *new;

	if (!(new = (t_label*)malloc(sizeof(t_label))))
		common_err(MAL);
	new->name = NULL;
	new->cur = -1;
	new->next = NULL;
	return (new);
}

t_asm	*init_asm(t_asm *champ)
{
	champ->fd = 0;
	champ->raw = NULL;
	champ->clean = NULL;
	champ->tk_list = NULL;
	champ->line = 1;
	champ->ll = NULL;
	champ->full_size = 0;
	if (!(champ->name = (char*)malloc(sizeof(char) * (PROG_NAME_LENGTH + 1))))
		common_err(MAL);
	if (!(champ->comment = (char*)malloc(sizeof(char) * (COMMENT_LENGTH + 1))))
		common_err(MAL);
	return (champ);
}
