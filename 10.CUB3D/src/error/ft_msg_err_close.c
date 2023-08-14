#include "../../include/cub3d.h"

int	ft_msg_err_close(char *error, int *fd)
{
	write(2, "Error : ", 9);
	write(2, error, strlen(error));
	write(2, "\n", 1);
	exit(1);
	close(*fd);
	return (0);
}
