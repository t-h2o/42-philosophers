/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:16:56 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/29 14:43:24 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	start_philo(int nphilo, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < nphilo)
	{
		pthread_join((philos[i++]).philo, 0);
	}
	return (0);
}
