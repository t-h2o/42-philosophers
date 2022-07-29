/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:54:48 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/29 14:14:38 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	*life(void *arg)
{
	t_philo	*me;

	me = arg;
	putnbr_fd(me->number, 1);
	putstr_fd(": I'm alive\n", 1);
	return (0);
}

int	init_philo(int nphilo)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * nphilo);
	if (philos == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (2);
	}
	i = -1;
	while (++i < nphilo)
	{
		pthread_create(&((philos[i]).philo), 0, &life, &(philos[i]));
		(philos[i]).number = i;
	}
	i = 0;
	while (i < nphilo)
	{
		pthread_join((philos[i++]).philo, 0);
	}
	free(philos);
	return (0);
}
