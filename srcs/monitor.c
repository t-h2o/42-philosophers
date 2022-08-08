/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:09:50 by tgrivel           #+#    #+#             */
/*   Updated: 2022/08/08 16:23:45 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	get_n_philos(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(philo->info->print_msg);
	ret = philo->info->args[0];
	pthread_mutex_unlock(philo->info->print_msg);
	return (ret);
}

static void	msg_philo_died(char *msg, t_philo *philo, int time)
{
	pthread_mutex_lock(philo->info->print_msg);
	if (philo->info->died == 0)
	{
		putnbr_fd(time, 1);
		putstr_fd(" ", 1);
		putnbr_fd(philo->number, 1);
		putstr_fd(msg, 1);
		philo->info->died = 1;
	}
	pthread_mutex_unlock(philo->info->print_msg);
}

static void	*monitor_dead(void *args)
{
	t_philo	*philos;
	int		i;
	int		now;
	int		nphilos;

	philos = args;
	nphilos = get_n_philos(philos);
	while (1)
	{
		i = -1;
		while (++i < nphilos)
		{
			pthread_mutex_lock(philos->info->print_msg);
			now = time_now(&(philos->info->start));
			if (now - (philos[i]).last_eat > philos->info->args[1])
			{
				pthread_mutex_unlock(philos->info->print_msg);
				msg_philo_died(" is died\n", &(philos[i]), now);
				return (0);
			}
			else
				pthread_mutex_unlock(philos->info->print_msg);
		}
		usleep(100);
	}
	return (0);
}

int	monitor(t_philo *philos, t_info *info)
{
	pthread_mutex_lock(info->print_msg);
	if (pthread_create(&(info->monitor[0]), 0, &monitor_dead, philos))
	{
		print_error("Error: Philo: System: pthread_join\n");
		pthread_mutex_unlock(info->print_msg);
		return (1);
	}
	pthread_mutex_unlock(info->print_msg);
	return (0);
}
