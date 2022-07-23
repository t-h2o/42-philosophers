/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:59:13 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 15:03:51 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t
	ft_strlcpy(char *dest, const char *src, size_t n)
{
	const char	*src_start;

	src_start = src;
	if (n > 1)
	{
		while (*src && n > 1)
		{
			*dest++ = *src++;
			n--;
		}
	}
	if (n >= 1)
		*dest = 0;
	while (*src)
		src++;
	return (src - src_start);
}
