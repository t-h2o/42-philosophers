/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:06:45 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/03 14:14:01 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	msg_philo(int nphilo, char *msg, t_info *info)
{
	pthread_mutex_lock(info->print_msg);
	putnbr_fd(time_now(&(info->start)), 1);
	putstr_fd(" ", 1);
	putnbr_fd(nphilo, 1);
	putstr_fd(msg, 1);
	pthread_mutex_unlock(info->print_msg);
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
	msg_philo(philo->number, " has taken fork\n", philo->info);
	msg_philo(philo->number, " is eating\n", philo->info);
	usleep(philo->info->args[2] * 1000);
	pthread_mutex_unlock(philo->mine);
	pthread_mutex_unlock(philo->left);
}

// timestamp_in_ms X is sleeping
void	p_sleep(t_philo *philo)
{
	msg_philo(philo->number, " is sleeping\n", philo->info);
	usleep(philo->info->args[3] * 1000);
}

// timestamp_in_ms X is thinking
void	p_think(t_philo *philo)
{
	msg_philo(philo->number, " is thinking\n", philo->info);
	usleep(philo->info->args[3] * 1000);
}

// timestamp_in_ms X died
