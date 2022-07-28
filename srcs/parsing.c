/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:13:54 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/28 16:43:19 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	parsing(int argc)
{
	if (argc < 5 || 6 < argc)
	{
		print_error("Error: Philo: Usage: Bad number of arguments\n");
		return (1);
	}
	return (0);
}
