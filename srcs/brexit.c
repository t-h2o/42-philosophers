/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:46:29 by nasackers         #+#    #+#             */
/*   Updated: 2022/04/08 13:37:25 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

//	Print in the standard error an error message.
static void
	print_msg(char *s)
{
	if (s == 0)
		return ;
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
	write(2, "\n", 1);
}

//	Print message and exit.
void
	error_exit(char *s, int value)
{
	print_msg(s);
	exit(value);
}
