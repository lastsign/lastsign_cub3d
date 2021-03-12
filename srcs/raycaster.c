/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:38:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/06 18:38:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_ray(t_all *all, t_rcstr *r, t_plr *plr, int num_ray)
{
	r->cmr_x = 2 * num_ray / (double)(all->rayc->w) - 1;
	r->r_dir_x = plr->dir_x + r->pln_x * r->cmr_x;
	r->r_dir_y = plr->dir_y + r->pln_y * r->cmr_x;
	r->map_x = (int)plr->x;
	r->map_y = (int)plr->y;
	if (r->r_dir_y == 0)
		r->d_dist_x = 0;
	else
		r->d_dist_x = (r->r_dir_x == 0) ? 1 : fabs(1 / r->r_dir_x);
	if (r->r_dir_x == 0)
		r->d_dist_y = 0;
	else
		r->d_dist_y = (r->r_dir_y == 0) ? 1 : fabs(1 / r->r_dir_y);
	r->hit = 0;
}

void	ft_init_side(t_rcstr *r, t_plr *plr)
{
	if (r->r_dir_x < 0)
	{
		r->stp_x = -1;
		r->s_dist_x = (plr->x - r->map_x) * r->d_dist_x;
	}
	else
	{
		r->stp_x = 1;
		r->s_dist_x = (1.0 + r->map_x - plr->x) * r->d_dist_x;
	}
	if (r->r_dir_y < 0)
	{
		r->stp_y = -1;
		r->s_dist_y = (plr->y - r->map_y) * r->d_dist_y;
	}
	else
	{
		r->stp_y = 1;
		r->s_dist_y = (1.0 + r->map_y - plr->y) * r->d_dist_y;
	}
}

void	ft_performdda(t_all *all, t_rcstr *r, t_plr *plr)
{
	while (r->hit == 0)
	{
		if (r->s_dist_x < r->s_dist_y)
		{
			r->s_dist_x += r->d_dist_x;
			r->map_x += r->stp_x;
			r->side = (r->r_dir_x < 0) ? 2 : 3;
		}
		else
		{
			r->s_dist_y += r->d_dist_y;
			r->map_y += r->stp_y;
			r->side = (r->r_dir_y < 0) ? 0 : 1;
		}
		if (all->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
	if (r->side > 1)
		r->p_wall_dist = (r->map_x - plr->x + (1 - r->stp_x) / 2) / r->r_dir_x;
	else
		r->p_wall_dist = (r->map_y - plr->y + (1 - r->stp_y) / 2) / r->r_dir_y;
}

void	ft_raycaster(t_all *all)
{
	int		x;
	t_plr	*plr;
	t_rcstr	*r;

	x = 0;
	plr = all->plr;
	r = all->rayc;
	while (x < all->rayc->w)
	{
		ft_calc_ray(all, r, plr, x);
		ft_init_side(r, plr);
		ft_performdda(all, r, plr);
		ft_calc_heightvline(all, r, plr, x);
		ft_draw_vertical(all, r, x);
		x++;
	}
	ft_draw_sprites(all, r, plr);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
}
