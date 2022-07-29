/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:55:23 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/29 15:14:35 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// 0. parse arguments
// 1. init philo
// 2. init supervisor
// 3. start time
// 4. start simulation
//
//  TIMES
//  times[0] : number of philosophers
//  times[1] : time to die
//  times[2] : time to eat
//  times[3] : time to sleep
// ?times[4] : number of times each philosopher must eat
int	main(int argc, char **argv)
{
	t_philo	*philos;
	int		infos[5];

	putstr_fd("philo\n", 1);
	philos = 0;
	if (parsing(argc, argv, infos))
		return (1);
	if (init_philo(infos[0], &philos))
	{
		free(philos);
		return (2);
	}
	if (start_philo(infos[0], philos))
	{
		free(philos);
		return (3);
	}
	free(philos->locker);
	free(philos);
	return (0);
}
