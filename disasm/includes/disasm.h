#ifndef DISASM_DISASM_H
# define DISASM_DISASM_H

# include "../libft/include/libft.h"
# include "unistd.h"
# define			OLD_CHAMPION_EXTENSION ".cor"
# define			NEW_CHAMPION_EXTENSION ".s"

typedef struct		s_dis
{
	char			*cmd_name;
	unsigned int	arg_type;
	unsigned char	c;
	unsigned int	value;
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	arg3;
	unsigned int	dir_size;
}					t_dis;


void		disassemble(int write_fd, int read_fd);

#endif
