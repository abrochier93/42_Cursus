#include "so_long.h"

void	ft_player_error(void)
{
	ft_putstr("Error\n");
	ft_putstr("Player number is NOT valid.\n");
}

void	ft_no_collectible(void)
{
	ft_putstr("Error\n");
	ft_putstr("There is NO collectible.\n");
}

void	ft_no_exit(void)
{
	ft_putstr("Error\n");
	ft_putstr("There is NO exit.\n");
}

void	ft_foreign_char(void)
{
	ft_putstr("Error\n");
	ft_putstr("There is at least one foreign char.\n");
}

void	ft_is_not_rectangle(void)
{
	ft_putstr("Error\n");
	ft_putstr("The map is NOT a rectangle.\n");
}

void	ft_is_not_close(void)
{
	ft_putstr("Error\n");
	ft_putstr("The map is NOT close by wall.\n");
}

void	ft_no_path(void)
{
	ft_putstr("Error\n");
	ft_putstr("The atual path do NOT permit to end the game.\n");
}
    
