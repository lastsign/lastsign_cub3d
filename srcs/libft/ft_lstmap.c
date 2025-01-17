/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:56:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/01 20:56:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *temp;

	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if ((temp = ft_lstnew(f(lst->content))))
			ft_lstadd_back(&new, temp);
		else
			ft_lstclear(&new, del);
		lst = lst->next;
	}
	return (new);
}
