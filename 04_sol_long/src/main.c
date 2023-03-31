#include "so_long.h"

int	ft_validate_filename(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.' && file[i] != '\0')
		i++;
	if (file[i] == '\0')
		return (-1);
	if (file[i + 1] == 'b' && file[i + 2] == 'e' && file[i + 3] == 'r'
		&& file[i + 4] == '\0')
		return (0);
	return (-1);
}

int	ft_check_file_extension(char *file)
{
	if (ft_validate_filename(file) == -1)
	{
        ft_extension_error();
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		file_size;
	t_map	map;

	file_size = 0;
	if (ac < 2)
	{
		ft_no_map_error();
		return (-1);
	}
	if (ac > 2)
	{
        ft_to_many_map_error();
		return (-1);
	}
	if (ac == 2)
	{
		if (ft_check_file_extension(av[1]) == -1)
			return (-1);
		ft_open_for_validation(av[1], &file_size, &map);
		map.map = ft_create_bi_array(av[1], file_size, &map);
		ft_render_map(&map);
		free(map.map);
	}
	return (0);
}