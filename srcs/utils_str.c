/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:16:49 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/28 16:30:55 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// Print str (string) in fd (file descriptor)
void	putstr_fd(char *str, int fd)
{
	if (str == 0)
		return ;
	while (*str)
		write(fd, str++, 1);
}
