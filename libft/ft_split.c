/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:00:07 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/04 17:49:55 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t
	give_word(const char *s1, char c)
{
	size_t	nb_wrd;

	while (*s1 && *s1 == c)
		s1++;
	nb_wrd = 0;
	while (*s1)
	{
		nb_wrd++;
		while (*s1 && *s1 != c)
			s1++;
		while (*s1 && *s1 == c)
			s1++;
	}
	return (nb_wrd);
}

static size_t
	give_size(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void
	ft_free(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return ;
}

char
	**ft_split(char const *s, char c)
{
	char		**tab;
	int			i;
	size_t		nb_wrd;
	size_t		len;

	if (!s)
		return (0);
	nb_wrd = give_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_wrd + 1));
	if (!tab)
		return (0);
	i = 0;
	while (i < (int)nb_wrd)
	{
		while (*s && *s == c)
			s++;
		len = give_size((char *)s, c);
		tab[i] = ft_substr((char *)s, 0, len);
		if (!tab[i])
			ft_free(tab, i);
		s = s + len;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
