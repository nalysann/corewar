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

# include "corewar.h"

# define ALLOC_MSG					"ERROR: Memory allocation failed"
# define INVALID_FLAG_MSG			"ERROR: Invalid flag"
# define MISSING_ARG				"ERROR: Flag argument missing"
# define EXTENSION_MSG				"ERROR: Invalid file extension"
# define NUM_PLAYERS_MSG			"ERROR: Invalid number of players"
# define D_FLAG_MSG					"ERROR: Invalid usage of '-d' or '-dump'"
# define N_FLAG_MSG					"ERROR: Invalid usage of '-n'"
# define N_FLAG_ID_MSG				"ERROR: Invalid player id"
# define N_FLAG_DUPLICATE_MSG		"ERROR: Duplicate player id"
# define FILE_MSG					"ERROR: Invalid champion file"
# define READ_MSG					"ERROR: Reading error"
# define CHAMPION_SIZE_MSG			"ERROR: Invalid champion size"
# define HEADER_MSG					"ERROR: Invalid magic header"
# define NULLS_MSG					"ERROR: Invalid nulls"

# define E_NONE			0
# define E_ALLOC		1
# define E_INPUT		2
# define E_USAGE		3

void	check_cor_extension(const char *filename, const char *extension);
int		fix_pos(int pos);
int		ft_isnumber(const char *str);
int		get_int(const char *bytearray, int size);
void	set_int(char *arena, int start_pos, int num);

#endif
