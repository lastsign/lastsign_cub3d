/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:09:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/09 22:09:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_info_of_other_text(t_all *all)
{
	int i;

	if (!(all->ea->img = mlx_xpm_file_to_image(all->win.mlx,
		all->parse.txtr_ea,
		&all->ea->w, &all->ea->h)))
		ft_error_mes("no such file", all);
	if (!(all->ea->addr = mlx_get_data_addr(all->ea->img, &all->ea->bpp,
											&all->ea->line_l, &all->ea->en)))
		ft_error_mes("failure texture", all);
	i = -1;
	while (++i < all->rayc->n_spr)
	{
		if (!(all->s[i].img = mlx_xpm_file_to_image(all->win.mlx,
			all->parse.txtr_s, &all->s[i].w, &all->s[i].h)))
			ft_error_mes("no such file", all);
		if (!(all->s[i].addr = mlx_get_data_addr(all->s[i].img, &all->s[i].bpp,
			&all->s[i].line_l, &all->s[i].en)))
			ft_error_mes("failure texture", all);
	}
}

int		get_info_of_text(t_all *all)
{
	if (!(all->so->img = mlx_xpm_file_to_image(all->win.mlx,
		all->parse.txtr_so, &all->so->w, &all->so->h)))
		ft_error_mes("no such file", all);
	if (!(all->so->addr = mlx_get_data_addr(all->so->img, &all->so->bpp,
		&all->so->line_l, &all->so->en)))
		ft_error_mes("failure texture", all);
	if (!(all->no->img = mlx_xpm_file_to_image(all->win.mlx,
		all->parse.txtr_no, &all->no->w, &all->no->h)))
		ft_error_mes("no such file", all);
	if (!(all->no->addr = mlx_get_data_addr(all->no->img, &all->no->bpp,
		&all->no->line_l, &all->no->en)))
		ft_error_mes("failure texture", all);
	if (!(all->we->img = mlx_xpm_file_to_image(all->win.mlx,
		all->parse.txtr_we, &all->we->w, &all->we->h)))
		ft_error_mes("no such file", all);
	if (!(all->we->addr = mlx_get_data_addr(all->we->img, &all->we->bpp,
		&all->we->line_l, &all->we->en)))
		ft_error_mes("failure texture", all);
	get_info_of_other_text(all);
	return (0);
}
