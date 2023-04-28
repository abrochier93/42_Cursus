/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:42:00 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/20 13:13:32 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	open_file(char *path)
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

int	ft_line_contains_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}

int	ft_last_line(char *str)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open_file(str);
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_line_contains_nl(line) == -1)
		{
			ft_error_finish_by_nl();
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
