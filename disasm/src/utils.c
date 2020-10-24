# include "utils.h"
# include "op2.h"
#include "../libft/include/libft.h"

char *change_extension(char *filename, char *old, char *new) {
	char	*basename;

	basename = ft_strsub(filename, 0, ft_strlen(filename) - ft_strlen(old));
	if (!basename)
		exit_with_error(ALLOC_MSG, E_ALLOC);
	if (!(filename = ft_strjoin(basename, new)))
		exit_with_error(ALLOC_MSG, E_ALLOC);
	ft_strdel(&basename);
	return (filename);
}

void check_extension(char *filename, char *old) {
	size_t	length;

	length = ft_strlen(filename);
	if (length < 5 || ft_strcmp(&filename[length - 4], old) != 0)
		exit_with_error(WRONG_FILE_EXTENSION_MSG, E_INPUT);
}

char		*find_cmd(t_dis *dis)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (g_op_tab[i].code == dis->c)
			break ;
		i++;
	}
	dis->arg_type = (int)g_op_tab[i].args_types_code;
	dis->cmd_name = g_op_tab[i].name;
	dis->dir_size = g_op_tab[i].t_dir_size;
	return (g_op_tab[i].name);
}

void check_arg_type(t_dis *dis, int rd_fd) {
	int i;

	i = 0;
	if (dis->arg_type == 1)
	{
		read(rd_fd, &dis->c, 1);
		dis->arg1 = dis->c >> 6;
		dis->arg2 = dis->c >> 4 & 3;
		dis->arg3 = dis->c >> 2 & 3;
	}
	else
	{
		while (i < 16)
		{
			if (g_op_tab[i].code == dis->c)
				break ;
			i++;
		}
		dis->arg1 = g_op_tab[i].args_types[0];
	}
}
