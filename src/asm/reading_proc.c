/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:38:50 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:38:53 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t	file_size(int fd)
{
	size_t	sz;
	off_t	currentpos;

	sz = 0;
	currentpos = lseek(fd, (size_t)0, SEEK_CUR);
	sz = lseek(fd, (size_t)0, SEEK_END);
	lseek(fd, currentpos, SEEK_SET);
	return (sz);
}

void	raw_file(char *name, t_asm *champ)
{
	int re;
	int sz;

	re = 0;
	call_process(OPEN_FL);
	if ((champ->fd = open(name, O_RDONLY)) < 0)
		common_err("Couldn't open file");
	sz = file_size(champ->fd);
	if (!(champ->raw = (char*)malloc(sizeof(char) * (sz + 1))))
		common_err(MAL);
	if (!(champ->clean = (char*)malloc(sizeof(char) * (sz + 1))))
		common_err(MAL);
	if ((re = read(champ->fd, champ->raw, sz)) <= 0)
		common_err("Couldn't read file");
	champ->raw[sz] = '\0';
	if (champ->raw[sz - 1] != '\n')
		common_err("No \\n at the end");
	call_process(OK_FL);
}

void	new_to_list(t_lex **list, t_lex *new)
{
	t_lex *tmp;

	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*list = new;
}

void	tok_des(t_asm *champ, int *i, int *j, char *tmp)
{
	if (tmp[(*i)] == COM_H || tmp[(*i)] == COMMENT_CHAR)
		while (tmp[(*i) + 1] != '\n')
			(*i)++;
	else if (tmp[(*i)] == '"')
	{
		(*j) = (*i);
		(*i) = count_comment(tmp, (*i));
		n_line((*i), (*j), tmp, champ);
		if (tmp[(*i)] == COM_H || tmp[(*i)] == COMMENT_CHAR)
			(*i)--;
	}
	else if (tmp[(*i)] == SEPARATOR_CHAR)
		add_new_token(get_token(tmp, (*i), (*i) + 1), \
			&champ->tk_list, champ->line);
	else
		n_line((*i), (*j), tmp, champ);
}

void	clean_tokens(t_asm *champ)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = champ->raw;
	i = 0;
	j = 0;
	while (tmp[i])
	{
		j = i;
		while (!ft_isspace(tmp[i]))
		{
			if (stop_tok(tmp[i]))
			{
				add_new_token(get_token(tmp, j, i), \
					&champ->tk_list, champ->line);
				break ;
			}
			i++;
		}
		tok_des(champ, &i, &j, tmp);
		i++;
	}
	add_end_doc(&champ->tk_list);
}
