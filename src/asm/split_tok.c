/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:59:36 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 17:59:39 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_new_token(char *token, t_lex **list, int line)
{
	t_lex *new;

	if (token == NULL)
		return ;
	new = init_tok();
	new->token = ft_strdup(token);
	new->type = find_type(token);
	new->position = line;
	if (new->type == ERR)
		err_tok("There is no type for token ", new);
	new->operator = ini_op_n(token, new->type);
	new_to_list(list, new);
	ft_strdel(&token);
}

void	add_new_command(t_lex **list)
{
	t_lex *tmp;
	t_lex *new;

	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		if (ft_strcmp(tmp->token, "\n"))
		{
			new = init_tok();
			new->token = ft_strdup("\n");
			new->type = NEXT;
			new->position = 0;
			tmp->next = new;
		}
	}
}

void	add_end_doc(t_lex **list)
{
	t_lex *tmp;
	t_lex *new;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	new = init_tok();
	new->token = ft_strdup("\0");
	new->type = END;
	if (*list)
		tmp->next = new;
}

char	*get_token(char *file, int st, int en)
{
	char	*token;
	int		i;

	i = 0;
	if (st == en)
		return (NULL);
	if (!(token = (char*)malloc(sizeof(char) * (en - st + 1))))
		common_err(MAL);
	while (st != en)
	{
		token[i] = file[st];
		st++;
		i++;
	}
	token[i] = '\0';
	return (token);
}

void	n_line(int i, int j, char *tmp, t_asm *champ)
{
	add_new_token(get_token(tmp, j, i), &champ->tk_list, champ->line);
	if (tmp[i] == '\n')
	{
		champ->line++;
		add_new_command(&champ->tk_list);
	}
}
