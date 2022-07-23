/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:01:25 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/05 20:45:06 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	
	*ft_lstnew(void *content)
{
	t_list	*ptr;
	
	ptr = (t_list *)malloc(sizeof(*ptr));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}
