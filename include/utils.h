/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:14:45 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 11:14:52 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define NULL_MSG					NULL
# define ALLOC_MSG					"ERROR: Memory allocation failed"
# define ARGS_MSG					"ERROR: No args"
# define OPEN_FILE_MSG				"ERROR: Can\'t open file with champion"
# define WRONG_FILE_EXTENSION_MSG	"ERROR: Wrong file extension"
# define NO_FLAGS_ARGS "ERROR: No flags arguments"
# define WRONG_FLAG "ERROR: Wrong flag"
# define WRONG_D_FLAG_USAGE "ERROR: Wrong usage of '-dump' or '-d'"
# define WRONG_PLAYERS_AMOUNT "ERROR: Wrong players amount"
# define WRONG_N_FLAG_USAGE "ERROR: Wrong usage of '-n'"
# define WRONG_N_FLAG_USAGE_ID "ERROR: Wrong id used with '-n'"
# define WRONG_N_FLAG_USAGE_DUP "ERROR: Duplicate id used with '-n'"

# define E_NONE			0
# define E_ALLOC		1
# define E_INPUT		2
# include "corewar.h"
# define CHAR_MINUS '-'

int		ft_isnumber(char *str);
void	debug_data(t_data *data);
void	check_extension(char *filename, char *old);
int		check_pos(int pos);
int		get_int(char *bytes, int size);
void	set_int(char *arena, int start_pos, int num);



#endif
