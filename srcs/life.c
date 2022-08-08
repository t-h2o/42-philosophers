/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:06:45 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/08 16:29:25 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	msg_philo(char *msg, t_philo *philo, int time)
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

// lock
// timestamp_in_ms X has taken a fork
// timestamp_in_ms X is eating
// eat
// unlock

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
