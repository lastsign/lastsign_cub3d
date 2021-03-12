/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:39:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/16 15:39:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		button_pressed(int key, t_all *all)
{
	if (key == 0)
		all->butn->a = 1;
	else if (key == 1)
		all->butn->s = 1;
	else if (key == 2)
		all->butn->d = 1;
	else if (key == 13)
		all->butn->w = 1;
	else if (key == 123)
		all->butn->l = 1;
	else if (key == 124)
		all->butn->r = 1;
	else if (key == 53)
		all->butn->e = 1;
	return (0);
}

int		button_unpressed(int key, t_all *all)
{
	if (key == 0)
		all->butn->a = 0;
	else if (key == 1)
		all->butn->s = 0;
	else if (key == 2)
		all->butn->d = 0;
	else if (key == 13)
		all->butn->w = 0;
	else if (key == 123)
		all->butn->l = 0;
	else if (key == 124)
		all->butn->r = 0;
	else if (key == 53)
		all->butn->e = 0;
	return (0);
}
