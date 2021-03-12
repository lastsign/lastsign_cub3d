/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:13:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/01 20:13:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *prev_tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	prev_tmp = *lst;
	while (prev_tmp != NULL)
	{
		tmp = prev_tmp;
		prev_tmp = prev_tmp->next;
		(*del)(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
