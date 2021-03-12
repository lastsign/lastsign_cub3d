/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:43:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/24 01:07:22 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_sides(t_all *all, int text_h, int text_w)
{
	t_rcstr *r;

	r = all->rayc;
	all->parse.w = text_w;
	all->parse.h = text_h;
	r->wallx -= floor(r->wallx);
	r->tex_x = (int)(r->wallx * (double)text_w);
	if (r->side == 1 || r->side == 2)
		r->tex_x = text_w - r->tex_x - 1;
	r->step = 1.0 * text_h / r->l_height;
	r->tex_pos = (r->d_start - r->h / 2 + r->l_height / 2) * r->step;
}

void	ft_calc_heightvline(t_all *all, t_rcstr *r, t_plr *plr, int x)
{
	int	y;

	r->l_height = (int)(all->rayc->h / r->p_wall_dist);
	r->d_start = -(r->l_height) / 2 + all->rayc->h / 2;
	r->d_start = (r->d_start < 0) ? 0 : r->d_start;
	r->d_end = r->l_height / 2 + all->rayc->h / 2;
	r->d_end = (r->d_end >= all->rayc->h) ? all->rayc->h - 1 : r->d_end;
	y = 0;
	while (y < all->rayc->d_start)
		my_mlx_pixel_put(all, x, y++, r->ceilling);
	if (r->side == 0)
		ft_init_sides(all, all->no->h, all->no->w);
	else if (r->side == 1)
		ft_init_sides(all, all->so->h, all->so->w);
	else if (r->side == 2)
		ft_init_sides(all, all->we->h, all->we->w);
	else if (r->side == 3)
		ft_init_sides(all, all->ea->h, all->ea->w);
	if (r->side == 2 || r->side == 3)
		r->wallx = plr->y + r->p_wall_dist * r->r_dir_y;
	else
		r->wallx = plr->x + r->p_wall_dist * r->r_dir_x;
}

void	ft_draw_vertical(t_all *all, t_rcstr *r, int x)
{
	int	y;

	y = r->d_start;
	while (y < r->d_end)
	{
		r->tex_y = (int)r->tex_pos & (all->parse.h - 1);
		r->tex_pos += r->step;
		if (r->side == 0)
			r->color = (*(int*)(all->no->addr + ((r->tex_x +
					(r->tex_y * all->no->w)) * (all->no->bpp / 8))));
		else if (r->side == 1)
			r->color = (*(int*)(all->so->addr + ((r->tex_x +
					(r->tex_y * all->so->w)) * (all->so->bpp / 8))));
		else if (r->side == 2)
			r->color = (*(int*)(all->we->addr + ((r->tex_x +
					(r->tex_y * all->we->w)) * (all->we->bpp / 8))));
		else if (r->side == 3)
			r->color = (*(int*)(all->ea->addr + ((r->tex_x +
					(r->tex_y * all->ea->w)) * (all->ea->bpp / 8))));
		my_mlx_pixel_put(all, x, y++, r->color);
	}
	while (y < all->rayc->h)
		my_mlx_pixel_put(all, x, y++, r->floor);
	all->rayc->buf[x] = r->p_wall_dist;
}

int		my_close(t_all *all)
{
	if (all)
		exit(0);
	return (0);
}
