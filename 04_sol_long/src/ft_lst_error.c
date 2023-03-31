#include "so_long.h"

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_no_map_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("Please provide a map.\n");
}

void	ft_to_many_map_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("Please provide only one map.\n");
}

void	ft_extension_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("Provide a .ber file.\n");
}

void	ft_walls_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("You're map is not surrounded by walls.\n");
}

void	ft_chars_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("Map can only contain 1, 0, C, P, and E.\n");
}

void	ft_rectangular_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("Map must be rectangular in shape.\n");
}

void	ft_file_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("No such file or directory.\n");
}

void	ft_exit_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("Map must have at least one exit.\n");
}

void	ft_player_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("Map must have at least one player.\n");
}

void	ft_collectible_error(void)
{
	ft_put_str("Error\n");
	ft_put_str("Map must have at least one collectible.\n");
}

		