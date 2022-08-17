/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:03:37 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/17 21:57:50 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	free_destroy(t_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < info->args[0])
	{
		pthread_mutex_destroy((philos[i]).mine);
		free((philos[i]).mine);
		pthread_mutex_destroy((philos[i]).data_philo);
		free((philos[i]).data_philo);
	}
	pthread_mutex_destroy(info->print_msg);
	pthread_mutex_destroy(info->data_died);
	free(info->print_msg);
	free(info->data_died);
	free(philos);
}
