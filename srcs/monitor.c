/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:09:50 by tgrivel           #+#    #+#             */
/*   Updated: 2022/08/08 20:37:19 by melogr@phy       ###   ########.fr       */
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

static int	check_dead(t_philo *philo)
{
	int		now;

	pthread_mutex_lock(philo->info->print_msg);
	now = time_now(&(philo->info->start));
	if (now - philo->last_eat > philo->info->args[1])
	{
		pthread_mutex_unlock(philo->info->print_msg);
		msg_philo_died(" is died\n", philo, now);
		return (1);
	}
	else
		pthread_mutex_unlock(philo->info->print_msg);
	return (0);

}
static void	*monitor_dead(void *args)
{
	t_philo	*philos;
	int		i;
	int		nphilos;

	philos = args;
	nphilos = get_n_philos(philos);
	while (1)
	{
		i = -1;
		while (++i < nphilos)
		{
			if (check_dead(&(philos[i])))
			{
				return (0);
			}
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
