/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:32:42 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/04 16:48:45 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_char;
	unsigned char	*s_char;

	c_char = (unsigned char)c;
	s_char = (unsigned char *)s;
	while (n--)
	{
		if (*s_char == c_char)
			return ((void *)s_char);
		s_char++;
	}
	return (0);
}

/*

   size_t	i;

	i = 0;
	while (n--)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)&(((char *)s)[i]));
		i++;
	}
	return (0);

*/
