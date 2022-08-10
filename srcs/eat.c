/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:33:47 by tgrivel           #+#    #+#             */
/*   Updated: 2022/08/10 18:44:34 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// Unlock the mutex a or/and b
static int	unlock(pthread_mutex_t *a, pthread_mutex_t *b)
{
	if (a)
		pthread_mutex_unlock(a);
	if (b)
		pthread_mutex_unlock(b);
	return (1);
}

// Lock the fork mine and left:
// if the philosopher is odd
//   1. mine
//   2. left
// if the philosopher is even
//   1. left
//   2. mine
// With that, we avoid the deadlock !
static int	lock_fork(t_philo *philo)
{
	if (philo->number % 2 == 1)
	{
		pthread_mutex_lock(philo->mine);
		msg_philo(" has taken a fork\n", philo, time_now(&(philo->info->start)));
		if (ifdead(philo) || philo->left == 0)
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

// Philosopher eat
// 1. Lock the mine and left forks
// 2. Eat
// 3. Wait the time's meal
// 4. Unlock the both forks
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
