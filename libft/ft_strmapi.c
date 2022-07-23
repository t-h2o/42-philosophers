/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:58:55 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 15:24:03 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char
	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s)
		return (0);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (len--)
	{
		str[i] = (*f)(i, s[i]);
		i ++;
	}
	str[i] = 0;
	return (str);
}
