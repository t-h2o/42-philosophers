/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:27:57 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/17 17:02:09 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

//	set start time
void
	time_start(struct timeval *start)
{
	gettimeofday(start, 0);
}

int	ifdead(t_philo *philo)
{
	pthread_mutex_lock(philo->info->data_died);
	if (philo->info->died == 1)
	{
		pthread_mutex_unlock(philo->info->data_died);
		return (1);
	}
	pthread_mutex_unlock(philo->info->data_died);
	return (0);
}

//	return current time [ms]
int
	time_now(struct timeval *start)
{
	unsigned int	now;
	struct timeval	time;

	gettimeofday(&time, 0);
	now = (unsigned int)(((time.tv_sec - start->tv_sec) * 1000) \
		+ ((time.tv_usec - start->tv_usec) / 1000));
	return ((int)now);
}

int
	my_sleep(t_philo *philo, int time)
{
	int	begin;
	int	now;

	begin = time_now(&(philo->info->start));
	now = begin;
	while (now - begin < time)
	{
		usleep(100);
		now = time_now(&(philo->info->start));
		if (ifdead(philo))
			return (1);
	}
	return (0);
}
