/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:54:48 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/29 17:28:37 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	*life(void *arg)
{
	t_philo	*me;

	me = arg;
	pthread_mutex_lock(me->locker);
	sleep(1);
	me->infos[3] += 5;
	putnbr_fd(me->infos[3], 1);
	putstr_fd(": ", 1);
	putnbr_fd(me->number, 1);
	putstr_fd(": I'm alive\n", 1);
	pthread_mutex_unlock(me->locker);
	return (0);
}

int	init_philo(int infos[5], t_philo **philos)
{
	int				i;
	pthread_mutex_t	*locker;

	locker = malloc(sizeof(pthread_mutex_t) * 1);
	if (locker == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (2);
	}
	pthread_mutex_init(locker, 0);
	*philos = malloc(sizeof(t_philo) * infos[0]);
	if (*philos == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (2);
	}
	i = -1;
	while (++i < infos[0])
	{
		((*philos)[i]).number = i + 1;
		((*philos)[i]).locker = locker;
		((*philos)[i]).infos = infos;
		if (pthread_create(&(((*philos)[i]).philo), 0, &life, &((*philos)[i])))
		{
			print_error("Error: Philo: System: pthread_join\n");
			return (1);
		}
	}
	return (0);
}
