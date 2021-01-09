/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:14:24 by nalysann          #+#    #+#             */
/*   Updated: 2020/12/29 11:14:26 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "cop.h"

typedef struct	s_player
{
	int		id;
	char	*filename;
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	int		size;
	char	*code;
	int		start;
}				t_player;

typedef struct	s_carriage
{
	int					id;
	int					carry;
	int					last_cycle_live;
	int					sleep_cycles;
	int					pos;
	int					step;
	int					reg[REG_NUMBER];
	int					needs_deletion;
	char				args[4];
	int					op_id;
	t_op				*op;
	struct s_carriage	*next;
}				t_carriage;

typedef struct	s_corewar
{
	int			a_flag;
	int			n_flags;
	int			d_flag;
	int			dump_cycles;
	int			last_player_alive;
	int			cycles_to_die;
	int			num_cycles;
	int			num_live;
	int			num_checks;
	char		*arena;
	int			num_players;
	t_player	**players;
	int			num_cars;
	t_carriage	*car_list;
}				t_corewar;

void			init_cw(int argc, char *argv[], t_corewar *cw);
void			init_players(char *argv[], t_corewar *cw);
void			parse_players(t_corewar *cw);
void			init_session(t_corewar *cw);
t_carriage		*create_carriage(int id, int pos);
void			play_cw(t_corewar *cw);
void			display_arena(char *arena);
void			delete_carriages(int num_delete, t_corewar *cw);
int				check_op(t_corewar *cw, t_carriage *car);
int				get_ind_arg(int arg, int car_pos, const char *arena,
								int l_flag);
void			get_args(int *args, t_carriage *car, t_corewar *cw);
void			end_cw(t_corewar *cw);

void			op_live(t_carriage *car, t_corewar *cw);
void			op_ld(t_carriage *car, t_corewar *cw);
void			op_st(t_carriage *car, t_corewar *cw);
void			op_add(t_carriage *car, t_corewar *cw);
void			op_sub(t_carriage *car, t_corewar *cw);
void			op_and(t_carriage *car, t_corewar *cw);
void			op_or(t_carriage *car, t_corewar *cw);
void			op_xor(t_carriage *car, t_corewar *cw);
void			op_zjmp(t_carriage *car, t_corewar *cw);
void			op_ldi(t_carriage *car, t_corewar *cw);
void			op_sti(t_carriage *car, t_corewar *cw);
void			op_fork(t_carriage *car, t_corewar *cw);
void			op_lld(t_carriage *car, t_corewar *cw);
void			op_lldi(t_carriage *car, t_corewar *cw);
void			op_lfork(t_carriage *car, t_corewar *cw);
void			op_aff(t_carriage *car, t_corewar *cw);

#endif
