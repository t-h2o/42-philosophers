/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:59:52 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 15:21:55 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char
	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*str;

	s_len = ft_strlen(s);
	str = (char *)malloc(s_len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, s_len + 1);
	return (str);
}	
