#include "disasm.h"
#include "op.h"
#include "utils.h"
#include "../libft/include/libft.h"

void		write_head_elem(char *elem, int cons, int write_fd, int read_fd)
{
	char	c;
	int		i;

	write(write_fd, elem, ft_strlen(elem));
	write(write_fd, " \"", 2);
	i = 0;
	read(read_fd, &c, 1);
	while (c != '\0' && i++ < cons)
	{
		write(write_fd, &c, 1);
		read(read_fd, &c, 1);
	}
	write(write_fd, "\"\n", 2);
	while (i++ < cons)
		read(read_fd, &c, 1);
}

void		read_value(t_dis *dis, int rd_fd)
{
	dis->value = dis->value << 8;
	read(rd_fd, &dis->c, 1);
	dis->value = dis->value | dis->c;
}

void		read_first_value(t_dis *dis, int rd_fd)
{
	read(rd_fd, &dis->c, 1);
	dis->value = dis->c;
}

void		write_label(int *output, t_dis *dis, int rd_fd, int wr_fd)
{
	char	p;

	p = DIRECT_CHAR;
	write(wr_fd, "%", 1);
	if (dis->dir_size == 2)
	{
		read_first_value(dis, rd_fd);
		read_value(dis, rd_fd);
		*output = (int16_t)dis->value;
	}
	else if (dis->dir_size == 4)
	{
		read_first_value(dis, rd_fd);
		read_value(dis, rd_fd);
		read_value(dis, rd_fd);
		read_value(dis, rd_fd);
		*output = dis->value;
	}
}

static int	ft_numlen(int n, int minus)
{
	int numlen;

	numlen = 1;
	while ((n /= 10))
		numlen++;
	return (numlen + minus);
}

char		*ft_itoa_1(int n)
{
	char	*str;
	int		numlen;
	int		minus;
	int		digit;

	minus = (n < 0) ? 1 : 0;
	numlen = ft_numlen(n, minus);
	if ((str = ft_strnew((size_t)numlen)))
	{
		str[numlen--] = '\0';
		while (numlen >= minus)
		{
			digit = n % 10;
			str[numlen--] = (char)((digit < 0 ? -digit : digit) + '0');
			n /= 10;
		}
		if (minus)
			str[0] = '-';
	}
	return (str);
}

void		write_arg(int wr_fd, t_dis *dis, int rd_fd, int arg)
{
	char	*to_wr;
	int		output;

	dis->value = 0;
	output = 0;
	if (arg == 1)
	{
		write(wr_fd, "r", 1);
		read(rd_fd, &dis->c, 1);
		output = dis->c;
	}
	else if (arg == 2)
		write_label(&output, dis, rd_fd, wr_fd);
	else if (arg == 3)
	{
		read_first_value(dis, rd_fd);
		read_value(dis, rd_fd);
		output = (int16_t)dis->value;
	}
	to_wr = ft_itoa_1(output);
	write(wr_fd, to_wr, ft_strlen(to_wr));
	free(to_wr);
}

static void	disassemble_header(int write_fd, int read_fd)
{
	char	c;
	int		i;

	i = 0;
	while (i++ < 4)
		read(read_fd, &c, 1);
	write_head_elem(NAME_CMD_STRING, PROG_NAME_LENGTH, write_fd, read_fd);
	i = 0;
	while (i++ < 7)
		read(read_fd, &c, 1);
	write_head_elem(COMMENT_CMD_STRING, COMMENT_LENGTH, write_fd, read_fd);
	write(write_fd, "\n", 1);
	i = 0;
	while (i++ < 3)
		read(read_fd, &c, 1);
}

static void	disassemble_cmd(int write_fd, int read_fd)
{
	int		ans;
	t_dis	cmd;

	while ((ans = read(read_fd, &cmd.c, 1)) > 0)
	{
		cmd.arg1 = 0;
		cmd.arg2 = 0;
		cmd.arg3 = 0;
		write(write_fd, find_cmd(&cmd), ft_strlen(cmd.cmd_name));
		write(write_fd, " ", 1);
		check_arg_type(&cmd, read_fd);
		write_arg(write_fd, &cmd, read_fd, cmd.arg1);
		if (cmd.arg2)
		{
			write(write_fd, ", ", 2);
			write_arg(write_fd, &cmd, read_fd, cmd.arg2);
		}
		if (cmd.arg3)
		{
			write(write_fd, ", ", 2);
			write_arg(write_fd, &cmd, read_fd, cmd.arg3);
		}
		write(write_fd, "\n", 1);
	}
}

void disassemble(int write_fd, int read_fd) {
	disassemble_header(write_fd, read_fd);
	disassemble_cmd(write_fd, read_fd);
}
