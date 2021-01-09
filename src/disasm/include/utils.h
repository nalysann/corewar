#ifndef DISASM_UTILS_H
#define DISASM_UTILS_H

#include "disasm.h"

# define NULL_MSG					NULL
# define ALLOC_MSG					"ERROR: Memory allocation failed"
# define ARGS_MSG					"ERROR: Args more or less than 1"
# define OPEN_FILE_MSG				"ERROR: Can\'t open file with champion"
# define WRONG_FILE_EXTENSION_MSG	"ERROR: Wrong file extension"

# define E_NONE			0
# define E_ALLOC		1
# define E_INPUT		2


void	check_extension(char *filename, char *old);
char	*change_extension(char *filename, char *old, char *new);
char	*find_cmd(t_dis *dis);
void	check_arg_type(t_dis *dis, int rd_fd);

#endif
