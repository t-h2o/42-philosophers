/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:06:45 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/03 14:59:54 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	msg_philo(char *msg, t_philo *philo, t_info *info)
{
	static int	died = 0;

	if (died == 0)
	{
		pthread_mutex_lock(info->print_msg);
		putnbr_fd(time_now(&(info->start)), 1);
		putstr_fd(" ", 1);
		putnbr_fd(philo->number, 1);
		putstr_fd(msg, 1);
		died = philo->died;
		pthread_mutex_unlock(info->print_msg);
	}
}

// lock
// timestamp_in_ms X has taken a fork
// timestamp_in_ms X is eating
// eat
// unlock
void	p_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->mine);
	pthread_mutex_lock(philo->left);
	msg_philo(" has taken fork\n", philo, philo->info);
	msg_philo(" is eating\n", philo, philo->info);
	usleep(philo->info->args[2] * 1000);
	pthread_mutex_unlock(philo->mine);
	pthread_mutex_unlock(philo->left);
}

// timestamp_in_ms X is sleeping
void	p_sleep(t_philo *philo)
{
	int	begin;
	int	now;

	msg_philo(" is sleeping\n", philo, philo->info);
	begin = time_now(&(philo->info->start));
	now = 0;
	while (now < begin + philo->info->args[3])
	{
		now = time_now(&(philo->info->start));
		if (philo->last_eat + now > philo->info->args[1])
		{
			philo->died = 1;
			msg_philo(" is died\n", philo, philo->info);
		}
	}
}

// timestamp_in_ms X is thinking
void	p_think(t_philo *philo)
{
	msg_philo(" is thinking\n", philo, philo->info);
}

// timestamp_in_ms X died
