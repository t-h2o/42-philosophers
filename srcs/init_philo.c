/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:54:48 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/29 13:26:09 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	*life(void *arg)
{
	(void) arg;
	putstr_fd("I'm alive\n", 1);
	return (0);
}

int	init_philo(int nphilo)
{
	pthread_t	*philos;
	int			i;

	philos = malloc(sizeof(pthread_t) * nphilo);
	if (philos == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (2);
	}
	i = 0;
	while (i < nphilo)
	{
		pthread_create(&(philos[i++]), 0, &life, 0);
	}
	i = 0;
	while (i < nphilo)
	{
		pthread_join(philos[i++], 0);
	}
	free(philos);
	return (0);
}
