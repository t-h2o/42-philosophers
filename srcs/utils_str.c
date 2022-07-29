/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:16:49 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/29 14:07:54 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	putnbr_fd(int number, int fd)
{
	char	digit;

	if (number >= 10)
	{
		putnbr_fd(number / 10, fd);
		putnbr_fd(number % 10, fd);
	}
	else
	{
		digit = number + '0';
		write(fd, &digit, 1);
	}
}

// Print str (string) in fd (file descriptor)
void	putstr_fd(char *str, int fd)
{
	if (str == 0)
		return ;
	while (*str)
		write(fd, str++, 1);
}
