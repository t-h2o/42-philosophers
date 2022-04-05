/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:15:04 by nasackers         #+#    #+#             */
/*   Updated: 2022/04/05 11:38:09 by nasackers        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void
	putnbr(int n)
{
	if (n < 0)
		return ;
	char	c;
	if (n > 10)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else if (10 > n)
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

static void
	print_str(char *s)
{
	if (s == 0)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

static void
	tabulation(int n)
{
	if (n > 99)
		write(1, " ", 1);
	else if (n > 9)
		write(1, "  ", 2);
	else
		write(1, "   ", 3);
}
void
	msg_philo(char *msg, int id)
{
	write(1, "philo", 5);
	tabulation(id);
	putnbr(id);
	write(1, " : ", 3);
	print_str(msg);
	write(1, "\n", 1);
}
