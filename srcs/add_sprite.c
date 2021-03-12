/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:22:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/15 21:22:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_sp(t_all *all, t_rcstr *r, int y)
{
	while (r->d_x < r->s_drwex)
	{
		r->tex_x = (int)(256 * (r->d_x - (-r->spritw / 2 + r->s_scrx)) *
			all->s[y].w / r->spritw) / 256;
		if (r->t_rnsfy > 0 && r->d_x > 0 && r->d_x < r->w &&
		r->t_rnsfy < r->buf[r->d_x])
		{
			r->d_y = r->s_drwsy;
			r->color = 0;
			while (r->d_y < r->s_drwey)
			{
				r->d = r->d_y * 256 - r->h * 128 + r->sprith * 128;
				r->tex_y = ((r->d * all->s[y].h) / r->sprith) / 256;
				r->color = (*(int*)(all->s[y].addr + ((r->tex_x +
					(r->tex_y * all->s[y].w)) * (all->s[y].bpp / 8))));
				((r->color & 0xFFFFFF) != 0) ?
				my_mlx_pixel_put(all, r->d_x, r->d_y, r->color) : NULL;
				(r->d_y)++;
			}
		}
		(r->d_x)++;
	}
}

void	ft_sprite_cast(t_all *all, t_rcstr *r, t_plr *plr, int y)
{
	r->sprit_x = (all->s)[y].x - plr->x;
	r->sprit_y = (all->s)[y].y - plr->y;
	r->inv_det = 1.0 / (r->pln_x * plr->dir_y - plr->dir_x * r->pln_y);
	r->t_rnsfx = r->inv_det * (plr->dir_y * r->sprit_x - plr->dir_x *
		r->sprit_y);
	r->t_rnsfy = r->inv_det * (-r->pln_y * r->sprit_x + r->pln_x * r->sprit_y);
	r->s_scrx = (int)((r->w / 2) * (1 + r->t_rnsfx / r->t_rnsfy));
	r->sprith = abs((int)((r->h) / (r->t_rnsfy)));
	r->s_drwsy = -r->sprith / 2 + r->h / 2;
	r->s_drwsy = (r->s_drwsy < 0) ? 0 : r->s_drwsy;
	r->s_drwey = r->sprith / 2 + r->h / 2;
	r->s_drwey = (r->s_drwey >= r->h) ? r->h : r->s_drwey;
	r->spritw = abs((int)((r->h) / (r->t_rnsfy)));
	r->s_drwsx = -r->spritw / 2 + r->s_scrx;
	r->s_drwsx = (r->s_drwsx < 0) ? 0 : r->s_drwsx;
	r->s_drwex = r->spritw / 2 + r->s_scrx;
	r->s_drwex = (r->s_drwex >= r->w) ? r->w : r->s_drwex;
	r->d_x = r->s_drwsx;
}

void	ft_draw_sprites(t_all *all, t_rcstr *r, t_plr *plr)
{
	int y;

	y = -1;
	while (++y < r->n_spr)
		all->s[y].dis = pow((plr->x - all->s[y].x), 2) +
		pow((plr->y - all->s[y].y), 2);
	heap_sort(all, r->n_spr);
	y = 0;
	while (y < r->n_spr)
	{
		ft_sprite_cast(all, r, plr, y);
		ft_draw_sp(all, r, y);
		y++;
	}
}
