/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:58:37 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 14:24:12 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char
	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle || !needle)
		return ((char *)haystack);
	while (needle[i] && n > j && ft_strlen(haystack))
	{
		while (needle[i] == haystack[i + j] && n > i + j)
		{
			if (!needle[i + 1])
				return (&((char *)haystack)[j]);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
