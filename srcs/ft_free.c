/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:36:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/13 13:36:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_all *all)
{
	int i;

	i = -1;
	(all->plr) ? free(all->plr) : NULL;
	(all->rayc->buf) ? free(all->rayc->buf) : NULL;
	(all->rayc) ? free(all->rayc) : NULL;
	(all->so) ? free(all->so) : NULL;
	(all->no) ? free(all->no) : NULL;
	(all->we) ? free(all->we) : NULL;
	(all->ea) ? free(all->ea) : NULL;
	(all->s) ? free(all->s) : NULL;
	while (all->map && all->map[++i])
		free(all->map[i]);
	(all->map) ? free(all->map) : NULL;
	i = -1;
	while (all->parse.map_check && all->parse.map_check[++i])
		free(all->parse.map_check[i]);
	(all->parse.map_check) ? free(all->parse.map_check) : NULL;
}

void	ft_free_list(t_list **head)
{
	t_list *temp;

	while (head && *head && *((char*)(*head)->content) != ' ' &&
	*((char*)(*head)->content) != '1')
	{
		temp = *head;
		(*head) = (*head)->next;
		if (temp->content)
			free(temp->content);
		free(temp);
	}
}

void	ft_free_array(char **rgb)
{
	int j;

	j = 0;
	while (rgb && rgb[j])
		free(rgb[j++]);
	free(rgb);
}
