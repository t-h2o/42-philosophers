/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:54:48 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/03 14:10:18 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// Nothing
// while (1)
//   eat
//   sleep
//   think
static void	*life(void *arg)
{
	t_philo	*me;

	me = arg;
	p_eat(me);
	p_sleep(me);
	p_think(me);
	return (0);
}

// Create a mutex
static pthread_mutex_t	*crt_mutex(void)
{
	pthread_mutex_t	*locker;

	locker = malloc(sizeof(pthread_mutex_t) * 1);
	if (locker == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (0);
	}
	pthread_mutex_init(locker, 0);
	return (locker);
}

static int	init_philo(t_info *info, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * info->args[0]);
	if (*philos == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (2);
	}
	i = -1;
	while (++i < info->args[0])
	{
		((*philos)[i]).number = i + 1;
		((*philos)[i]).info = info;
		((*philos)[i]).mine = crt_mutex();
		if (((*philos)[i]).mine == 0)
			return (2);
		if (i != 0)
			((*philos)[i]).left = ((*philos)[i - 1]).mine;
	}
	((*philos)[0]).left = ((*philos)[i - 1]).mine;
	return (0);
}

int	start_philo(t_info *info, t_philo **philos)
{
	int	i;

	if (init_philo(info, philos))
		return (2);
	info->print_msg = crt_mutex();
	if (info->print_msg == 0)
		return (2);
	time_start(&(info->start));
	i = -1;
	while (++i < info->args[0])
	{
		if (pthread_create(&(((*philos)[i]).philo), 0, &life, &((*philos)[i])))
		{
			print_error("Error: Philo: System: pthread_join\n");
			return (1);
		}
	}
	return (0);
}
