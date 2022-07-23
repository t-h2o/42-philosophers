/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:49:07 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 15:23:30 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char
	*ft_strtrim(const char *s, const char *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s || !set)
		return (0);
	start = 0;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	end = ft_strlen(s);
	while (end > start && ft_strchr(set, s[end - 1]))
		end--;
	str = (char *)malloc(end - start + 1);
	if (!str)
		return (0);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
/* remove set char at the top and botom of s1
 * strtim doesn't remove set char in the middle
 */
