/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:48:55 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/24 17:50:07 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	format_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			str[i] = ' ';
			i++;
			while (str[i])
			{
				if (str[i] == ' ')
					str[i] = '	';
				if (str[i] == '\'' || str[i] == '\"')
				{
					str[i] = ' ';
					break ;
				}
				i++;
			}
		}
		i++;
	}
}

int	main(int ac, char **ag, char **envp)
{
	int	f1;
	int	f2;

	if (ac != 5)
		return (ft_putstr("Invalid number of arguments.", 0));
	if (check_empty(ag[2]) || check_empty(ag[3]))
		return (1);
	if (get_path(envp) == NULL && get_path(envp) == NULL)
		return(1);
	f1 = open(ag[1], O_RDONLY);
	f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		return (ft_putstr(strerror(errno), ag[1]));
	if (f2 < 0)
		return (ft_putstr(strerror(errno), ag[4]));
	format_args(ag[2]);
	format_args(ag[3]);
	pipex(f1, f2, ag, envp);
	if (close(f1) < 0 || close(f2) < 0)
		return (ft_putstr(strerror(errno), 0));
	return (0);
}
