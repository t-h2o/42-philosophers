/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:38:08 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/09 00:38:34 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// timestamp_in_ms X is thinking
void	p_think(t_philo *philo)
{
	msg_philo(" is thinking\n", philo, time_now(&(philo->info->start)));
}
