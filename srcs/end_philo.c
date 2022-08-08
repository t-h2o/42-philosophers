/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:16:56 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/08 16:24:01 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	end_philo(int nphilo, t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < nphilo)
	{
		if (pthread_join((philos[i++]).philo, 0))
		{
			print_error("Error: Philo: System: pthread_join\n");
			return (1);
		}
	}
	if (pthread_join(info->monitor[0], 0))
	{
		print_error("Error: Philo: System: pthread_join\n");
		return (1);
	}
	return (0);
}
