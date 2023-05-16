/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:37:44 by abrochie          #+#    #+#             */
/*   Updated: 2023/05/16 16:27:01 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct l_philo
{
	int				n;
	int				m_count;
	pthread_t		thread;
	long int		last_eat;
	struct l_info	*info;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
}		t_philo;

typedef struct l_info
{
	int				philo_eat;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				stop;
	long int		t_start;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	dead;
}		t_info;

int			ft_atoi(const char *str);
int			ft_isdigit(int character);
void		ft_usleep(int ms);
int			is_dead(t_philo *philo, int nb);
void		print(t_philo *philo, char *str);
long long	timestamp(void);
int			var_init(t_info *data, char **av);
int			check_num(char **str);
int			philo_init(t_info *data);
void		freeall(t_info *data);
void		*philo_life(void *phi);
void		philo_eat(t_philo *philo);
void		take_fork(t_philo *philo);
void		*check_death(void *phi);

#endif