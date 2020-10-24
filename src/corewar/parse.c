#include "corewar.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "utils.h"

static int			read_ints(int fd, int size)
{
	char	buf[size];

	if (read(fd, buf, size) != size)
		exit_with_error("Failed reading", 0);
	return (get_int(buf, 4));
}

static void			read_chars(int fd, int size, char *dest, int last)
{
	char	buf[size];
	int		i;

	i = 0;
	if (read(fd, buf, size) != size)
		exit_with_error("Failed reading", 0);
	while (i < size)
	{
		dest[i] = buf[i];
		++i;
	}
	if (last)
		if (read(fd, buf, 1))
			exit_with_error("Champion size is not the same as declared", 0);
}

static void			check_nulls(int fd, int size)
{
	char	buf[size];
	int		i;

	i = 0;
	if (read(fd, buf, size) != size)
		exit_with_error("Failed reading", 0);
	while (i < size)
	{
		if (buf[i])
			exit_with_error("Skipped nulls checkpoint", 0);
		++i;
	}
}


static void		parse_player(int fd, t_player *player) {
	if (read_ints(fd, (int)sizeof(int)) != COREWAR_EXEC_MAGIC)
		exit_with_error("Wrong magic header", 0);
	read_chars(fd, PROG_NAME_LENGTH, player->name, 0);
	check_nulls(fd, (int)sizeof(int));
	player->exec_size = read_ints(fd, (int)sizeof(int));
	if (player->exec_size < 0 || player->exec_size > CHAMP_MAX_SIZE)
		exit_with_error("Wrong champion size", 0);
	read_chars(fd, COMMENT_LENGTH, player->comment, 0);
	check_nulls(fd, (int)sizeof(int));
	player->exec_code = (char *)ft_memalloc(player->exec_size);
	if (!player->exec_code)
		exit_with_error("Memory error", 0);
	ft_bzero(player->exec_code, player->exec_size);
	read_chars(fd, player->exec_size, player->exec_code, 1);
}

void			parse_players(t_data *data)
{
	int		i;
	int		fd;

	i = 0;
	while (i < data->players_amount)
	{
		if ((fd = open(data->players[i]->filename, O_RDONLY)) == -1)
			exit_with_error(OPEN_FILE_MSG, E_INPUT);
		parse_player(fd, data->players[i]);
		close(fd);
		i++;
	}




}

