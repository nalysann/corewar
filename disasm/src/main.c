#include "disasm.h"
#include "utils.h"
#include <fcntl.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		write_fd;
	int		read_fd;
	char	*filename;

	if (argc != 2)
		ft_throw(ARGS_MSG, E_INPUT);
	if ((read_fd = open(argv[1], O_RDONLY)) == -1)
		ft_throw(OPEN_FILE_MSG, E_INPUT);
	check_extension(argv[1], OLD_CHAMPION_EXTENSION);
	filename = change_extension(argv[1], OLD_CHAMPION_EXTENSION, NEW_CHAMPION_EXTENSION);
//	TODO CHECK ERROR
	write_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	disassemble(write_fd, read_fd);
}