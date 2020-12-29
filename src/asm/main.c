/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:38:28 by qweissna          #+#    #+#             */
/*   Updated: 2020/11/07 16:38:31 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_cor(char *name, int *fd)
{
	char	*filename;
	char	*flnm;
	int		i;

	i = 0;
	if (!(filename = (char*)malloc(sizeof(char) * (ft_strlen(name) + 3))))
		common_err(MAL);
	while (name[i] != '.')
	{
		filename[i] = name[i];
		i++;
	}
	filename[i] = '\0';
	flnm = ft_strjoin(filename, ".cor");
	ft_strdel(&filename);
	(*fd) = open(flnm, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_strdel(&flnm);
}

int		process_champ(char *name)
{
	t_asm *champ;

	if (!(champ = (t_asm *)malloc(sizeof(t_asm))))
		common_err(MAL);
	champ = init_asm(champ);
	raw_file(name, champ);
	call_process(LEX_AN);
	clean_tokens(champ);
	call_process(LEX_AN_G);
	close(champ->fd);
	analitics(champ);
	create_cor(name, &champ->fd);
	translate(champ);
	close(champ->fd);
	free_asm(&champ);
	call_process(ENJOY);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2 && check_format(av[1]))
	{
		process_champ(av[1]);
		funny();
	}
	else
		print_usage();
	return (0);
}
