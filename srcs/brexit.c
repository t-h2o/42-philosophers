/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:46:29 by nasackers         #+#    #+#             */
/*   Updated: 2022/07/26 23:19:21 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

//	Print message and exit.
void
	error_exit(char *s, int value)
{
	ft_putstr_fd(s, 2);
	exit(value);
}
