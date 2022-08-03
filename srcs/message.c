/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:06:45 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/04 01:40:36 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	msg_philo(char *msg, t_philo *philo, int time)
{
	pthread_mutex_lock(philo->info->print_msg);
	putnbr_fd(time, 1);
	putstr_fd(" ", 1);
	putnbr_fd(philo->number, 1);
	putstr_fd(msg, 1);
	pthread_mutex_unlock(philo->info->print_msg);
}

// lock
// timestamp_in_ms X has taken a fork
// timestamp_in_ms X is eating
// eat
// unlock
void	p_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->mine);
	msg_philo(" has taken a fork\n", philo, time_now(&(philo->info->start)));
	pthread_mutex_lock(philo->left);
	msg_philo(" has taken a fork\n", philo, time_now(&(philo->info->start)));
	msg_philo(" is eating\n", philo, time_now(&(philo->info->start)));
	usleep(philo->info->args[2] * 1000);
	pthread_mutex_unlock(philo->mine);
	pthread_mutex_unlock(philo->left);
}

// timestamp_in_ms X is sleeping
void	p_sleep(t_philo *philo)
{
	msg_philo(" is sleeping\n", philo, time_now(&(philo->info->start)));
	usleep(philo->info->args[3] * 1000);
}

// timestamp_in_ms X is thinking
void	p_think(t_philo *philo)
{
	msg_philo(" is thinking\n", philo, time_now(&(philo->info->start)));
	usleep(philo->info->args[3] * 1000);
}

// timestamp_in_ms X died
