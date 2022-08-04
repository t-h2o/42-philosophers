/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:55:23 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/04 16:51:41 by melogr@phy       ###   ########.fr       */
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
	t_info	info;

	philos = 0;
	if (parsing(argc, argv, info.args))
		return (1);
	if (start_philo(&info, &philos))
	{
		free(philos);
		return (2);
	}
	if (end_philo(info.args[0], philos))
	{
		free(philos);
		return (3);
	}
	free_destroy(&info, philos);
	return (0);
}
