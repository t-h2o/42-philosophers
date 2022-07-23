/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:59:27 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 14:56:49 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t
	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (n < dest_len + 1)
		return (src_len + n);
	i = 0;
	while (i < (n - dest_len - 1) && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len != n)
		dest[dest_len + i] = 0;
	return (src_len + dest_len);
}
/*
	size_t	i;
	size_t	dest_len;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (n-- && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
*/
