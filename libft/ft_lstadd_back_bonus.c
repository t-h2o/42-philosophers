/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:50:06 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/08 14:39:53 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./libft.h"

void
	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (alst)
	{
		if (*alst)
		{
			ptr = ft_lstlast(*alst);
			ptr->next = new;
		}
		else
			*alst = new;
	}
}
