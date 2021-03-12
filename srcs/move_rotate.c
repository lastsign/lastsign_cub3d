/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:19:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/15 21:19:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forw_back(t_all *all, t_plr *p, double m_s)
{
	if (all->butn->w == 1)
	{
		if (all->map[(int)p->y][(int)(p->x + p->dir_x * 0.11)] != '1')
			p->x += p->dir_x * m_s;
		if (all->map[(int)(p->y + p->dir_y * 0.11)][(int)p->x] != '1')
			p->y += p->dir_y * m_s;
	}
	if (all->butn->s == 1)
	{
		if (all->map[(int)p->y][(int)(p->x - p->dir_x * 0.11)] != '1')
			p->x -= p->dir_x * m_s;
		if (all->map[(int)(p->y - p->dir_y * 0.11)][(int)p->x] != '1')
			p->y -= p->dir_y * m_s;
	}
}

void	move_right_left(t_all *all, t_plr *p, double m_s)
{
	if (all->butn->a == 1)
	{
		if (all->map[(int)p->y][(int)(p->x - all->rayc->pln_x * 0.11)] != '1')
			p->x -= all->rayc->pln_x * m_s;
		if (all->map[(int)(p->y - all->rayc->pln_y * 0.11)][(int)p->x] != '1')
			p->y -= all->rayc->pln_y * m_s;
	}
	if (all->butn->d == 1)
	{
		if (all->map[(int)p->y][(int)(p->x + all->rayc->pln_x * 0.11)] != '1')
			p->x += all->rayc->pln_x * m_s;
		if (all->map[(int)(p->y + all->rayc->pln_y * 0.11)][(int)p->x] != '1')
			p->y += all->rayc->pln_y * m_s;
	}
}

void	rot_right_left(t_all *all, t_plr *p, double r_s)
{
	if (all->butn->l == 1)
	{
		all->plr->olddir_x = p->dir_x;
		all->rayc->oldplnx = all->rayc->pln_x;
		p->dir_x = p->dir_x * cos(-r_s) - p->dir_y * sin(-r_s);
		p->dir_y = p->olddir_x * sin(-r_s) + p->dir_y * cos(-r_s);
		all->rayc->pln_x = all->rayc->pln_x * cos(-r_s) -
			all->rayc->pln_y * sin(-r_s);
		all->rayc->pln_y = all->rayc->oldplnx * sin(-r_s) +
			all->rayc->pln_y * cos(-r_s);
	}
	if (all->butn->r == 1)
	{
		p->olddir_x = p->dir_x;
		all->rayc->oldplnx = all->rayc->pln_x;
		p->dir_x = p->dir_x * cos(r_s) - p->dir_y * sin(r_s);
		p->dir_y = p->olddir_x * sin(r_s) + p->dir_y * cos(r_s);
		all->rayc->pln_x = all->rayc->pln_x * cos(r_s) -
			all->rayc->pln_y * sin(r_s);
		all->rayc->pln_y = all->rayc->oldplnx * sin(r_s) +
			all->rayc->pln_y * cos(r_s);
	}
}

int		butn_handler(t_all *all)
{
	move_forw_back(all, all->plr, all->rayc->m_speed);
	move_right_left(all, all->plr, all->rayc->m_speed);
	rot_right_left(all, all->plr, all->rayc->r_speed);
	if (all->butn->e == 1)
		exit(0);
	mlx_destroy_image(all->win.mlx, all->win.img);
	all->win.img = mlx_new_image(all->win.mlx, all->rayc->w, all->rayc->h);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp,
		&all->win.line_l, &all->win.en);
	ft_raycaster(all);
	return (0);
}
