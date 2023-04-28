/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:43:26 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/20 13:12:59 by abrochie         ###   ########.fr       */
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

int	ft_line_empty(char *str)
{
	if (str[0] == '\n')
		return (-1);
	return (0);
}

int	ft_first_line(char *str)
{
	int		fd;
	char	*line;

	fd = open_file(str);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_file_is_empty();
		return (-1);
	}
	if (ft_line_empty(line) == -1)
	{
		free(line);
		close(fd);
		ft_error_start_by_nl();
		return (-1);
	}
	free(line);
	close(fd);
	return (0);
}
