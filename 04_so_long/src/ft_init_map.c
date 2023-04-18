/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:39:10 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/13 15:40:02 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 1);
		exit(1);
	}
	return (fd);
}

void	ft_init_map(char *file, t_file *map)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open_file(file);
	temp = ft_strdup("");
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin_gnl(temp, line);
		free(line);
		map->n_rows++;
	}
	map->map = ft_split(temp, '\n');
	free(temp);
	close(fd);
	return ;
}
