/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:01:45 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/04 16:53:07 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_char != *s2_char)
			return (*s1_char - *s2_char);
		s1_char++;
		s2_char++;
	}
	return (0);
}	
