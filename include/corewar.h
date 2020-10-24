#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"

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

void					init_data(int argc, char **argv, t_data *data);
void					players_init(char **argv, t_data *data);
void					parse_players(t_data *data);
void					init_game(t_data *data);
void					delete_carriages(int to_delete, t_data *data);
t_carriage				*create_carriage(int id, int pos);
void					display_arena(char *arena, int octets_num);
int						validate_op(t_data *data, t_carriage *car);
int						get_ind_value(int arg, int car_pos, char *arena, int flag_l);
void					get_args(int *args, t_carriage *car, t_data *data);
void					game(t_data *data);
void					finish(t_data *data);


void					ch_add(t_carriage *car, t_data *cw);
void					ch_aff(t_carriage *car, t_data *data);
void					ch_and(t_carriage *car, t_data *data);
void					ch_fork(t_carriage *car, t_data *data);
void					ch_ld(t_carriage *car, t_data *data);
void					ch_ldi(t_carriage *car, t_data *data);
void					ch_lfork(t_carriage *car, t_data *data);
void					ch_live(t_carriage *car, t_data *data);
void					ch_lld(t_carriage *car, t_data *data);
void					ch_lldi(t_carriage *car, t_data *data);
void					ch_or(t_carriage *car, t_data *data);
void					ch_st(t_carriage *car, t_data *data);
void					ch_sti(t_carriage *car, t_data *data);
void					ch_xor(t_carriage *car, t_data *data);
void					ch_sub(t_carriage *car, t_data *data);
void					ch_zjmp(t_carriage *car, t_data *data);



#endif
