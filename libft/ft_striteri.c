/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:59:40 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/04 18:38:29 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void
	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f (i, &s[i]);
		i++;
	}
	return ;
}
