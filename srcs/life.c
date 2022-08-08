/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:06:45 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/08 17:36:35 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	msg_philo(char *msg, t_philo *philo, int time)
{
	pthread_mutex_lock(philo->info->print_msg);
	if (philo->info->died == 0)
	{
		putnbr_fd(time, 1);
		putstr_fd(" ", 1);
		putnbr_fd(philo->number, 1);
		putstr_fd(msg, 1);
	}
	pthread_mutex_unlock(philo->info->print_msg);
}

// timestamp_in_ms X is sleeping
int	p_sleep(t_philo *philo)
{
	int	begin;
	int	now;

	begin = time_now(&(philo->info->start));
	now = begin;
	msg_philo(" is sleeping\n", philo, begin);
	while (now - begin < philo->info->args[3])
	{
		usleep(100);
		now = time_now(&(philo->info->start));
		if (ifdead(philo))
			return (0);
	}
	return (0);
}

// timestamp_in_ms X is thinking
void	p_think(t_philo *philo)
{
	msg_philo(" is thinking\n", philo, time_now(&(philo->info->start)));
}

// timestamp_in_ms X died
