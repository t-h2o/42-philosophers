/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:58:17 by tgrivel           #+#    #+#             */
/*   Updated: 2021/10/27 17:02:21 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int
	ft_isuppercase(int c)
{
		return (c >= 'A' && c <= 'Z');
}

int
	ft_tolower(int c)
{
	if (ft_isuppercase(c))
		c += 'a' - 'A';
	return (c);
}
