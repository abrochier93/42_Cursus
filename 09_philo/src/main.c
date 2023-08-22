/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:42:15 by abrochie          #+#    #+#             */
/*   Updated: 2023/05/26 15:12:46 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	freeall(t_info *data)
{
	int	i;

	i = -1;
	free(data->stop);
	while (++i < data->n_philo)
	{
		pthread_mutex_destroy(&data->philo[i].fork_l);
		pthread_mutex_destroy(data->philo[i].fork_r);
	}
	free(data->philo);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->m_stop);
	pthread_mutex_destroy(&data->m_eat);
	pthread_mutex_destroy(&data->dead);
}

int	main(int ac, char **av)
{
	t_info	data;

	if (ac != 5 && ac != 6)
		return (0);
	if (var_init(&data, av) == 1)
	{
		free(data.philo);
		return (0);
	}
	philo_init(&data);
	freeall(&data);
}
