#include "../../include/cub3d.h"

int	ft_iswhitespace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}
