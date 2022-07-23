/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:24:41 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/04 16:34:46 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int
	ft_isblank(char c)
{
	if (c == '\t'
		|| c == '\v'
		|| c == '\r'
		|| c == '\n'
		|| c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		nb;
	int		neg;

	while (ft_isblank(*str))
		str++;
	neg = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	nb = 0;
	while (ft_isdigit(*str))
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (neg)
		return (nb * -1);
	return (nb);
}
