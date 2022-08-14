/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:09:50 by tgrivel           #+#    #+#             */
/*   Updated: 2022/08/14 09:34:11 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// Print a philopher message and set to 1 info.died
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

// Check if a philopher had died with last_eat time and the time now
static int	check_dead(t_philo *philos)
{
	int	now;
	int	i;

	pthread_mutex_lock(philos->info->print_msg);
	i = -1;
	while (++i < philos[0].info->args[0])
	{
		now = time_now(&(philos[i].info->start));
		if (now - philos[i].last_eat > philos[i].info->args[1])
		{
			pthread_mutex_unlock(philos[i].info->print_msg);
			msg_philo_died(" is died\n", &(philos[i]), now);
			return (1);
		}
	}
	pthread_mutex_unlock(philos->info->print_msg);
	return (0);
}

// Check if all philopher had finished with a bool data
static int	check_finish(t_philo *philos)
{
	int		i;

	i = -1;
	while (++i < philos->info->args[0])
	{
		pthread_mutex_lock(philos[i].data_philo);
		if (philos[i].count != -1 && philos[i].count > 0)
		{
			pthread_mutex_unlock(philos[i].data_philo);
			return (0);
		}
		if (philos[i].count != -1 && philos[i].count > 0)
		pthread_mutex_unlock(philos[i].data_philo);
	}
	return (1);
}

// Monitor:
// 1. if a philospher had died
// 2. if the simulation had finished
static void	*monitor_thread(void *args)
{
	t_philo	*philos;

	philos = args;
	while (1)
	{
		if (check_dead(philos))
			return (0);
		if (check_finish(philos))
			return (0);
		usleep(100);
	}
	return (0);
}

// Start the thread monitor
int	monitor(t_philo *philos, t_info *info)
{
	if (pthread_create(&(info->monitor[0]), 0, &monitor_thread, philos))
	{
		print_error("Error: Philo: System: pthread_join\n");
		return (1);
	}
	return (0);
}
