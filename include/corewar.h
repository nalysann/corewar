#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
typedef struct			s_op
{
	char				*name;
	int					args_amount;
	int					args[3];
	int					id;
	int					cycles;
	char				*description;
	int					arg_code;
	int					dir_size;
}						t_op;

typedef struct			s_player
{
	int					id;
	char				*filename;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	int					exec_size;
	char				*exec_code;
	int					starting_point;
}						t_player;

typedef struct			s_carriage
{
	int					id;
	int					carry;
	unsigned char		op_i;
	int					last_cycle_live;
	int					cycles_till_op;
	int					position;
	int					step;
	int					reg[REG_NUMBER];
	int					to_delete;
	char				args[4];
	t_op				*op;
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_data
{
	int					players_amount;
	int					a_flag;
	int					n_flags;
	int					d_flag;
	int					d_cycles;
	int					cars_amount;
	int					last_player_alive;
	int					cycles_to_die;
	int					game_cycles;
	int					live_ops;
	int					checks_performed;
	char				*arena;
	t_player			**players;
	t_carriage			*carriage_list;
}						t_data;

#endif
