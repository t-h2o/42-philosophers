/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:17:09 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 12:55:25 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ptr;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (len--)
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = 0;
	return (ptr);
}
