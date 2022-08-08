/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:33:47 by tgrivel           #+#    #+#             */
/*   Updated: 2022/08/08 17:34:41 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	unlock(pthread_mutex_t *a, pthread_mutex_t *b)
{
	pthread_mutex_unlock(a);
	if (b)
		pthread_mutex_unlock(b);
	return (1);
}

static int	lock_fork(t_philo *philo)
{
	if (philo->number % 2 == 1)
	{
		pthread_mutex_lock(philo->mine);
		msg_philo(" has taken a fork\n", philo, time_now(&(philo->info->start)));
		if (ifdead(philo))
			return (unlock(philo->mine, 0));
		pthread_mutex_lock(philo->left);
		msg_philo(" has taken a fork\n", philo, time_now(&(philo->info->start)));
		if (ifdead(philo))
			return (unlock(philo->mine, philo->left));
	}
	else
	{
		pthread_mutex_lock(philo->left);
		msg_philo(" has taken a fork\n", philo, time_now(&(philo->info->start)));
		if (ifdead(philo))
			return (unlock(philo->left, 0));
		pthread_mutex_lock(philo->mine);
		msg_philo(" has taken a fork\n", philo, time_now(&(philo->info->start)));
		if (ifdead(philo))
			return (unlock(philo->left, philo->mine));
	}
	return (0);
}

int	p_eat(t_philo *philo)
{
	int	now;

	if (lock_fork(philo))
		return (1);
	now = time_now(&(philo->info->start));
	pthread_mutex_lock(philo->info->print_msg);
	philo->last_eat = now;
	pthread_mutex_unlock(philo->info->print_msg);
	msg_philo(" is eating\n", philo, now);
	my_sleep(philo, philo->info->args[2]);
	unlock(philo->mine, philo->left);
	return (0);
}
