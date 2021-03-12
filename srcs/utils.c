/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:21:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/15 21:21:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	t_win	*data;
	char	*dst;

	data = &all->win;
	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	recovery(t_all *all, int i, int n)
{
	t_txtr	temp;
	int		k;
	int		l;
	int		r;

	k = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && all->s[l].dis < all->s[k].dis)
		k = l;
	if (r < n && all->s[r].dis < all->s[k].dis)
		k = r;
	if (k != i)
	{
		temp = all->s[i];
		all->s[i] = all->s[k];
		all->s[k] = temp;
		recovery(all, k, n);
	}
}

void	heap_sort(t_all *all, int n)
{
	t_txtr	temp;
	int		i;
	int		d;

	i = n / 2 - 1;
	while (i >= 0)
	{
		recovery(all, i, n);
		i--;
	}
	d = n - 1;
	while (d > 0)
	{
		temp = all->s[0];
		all->s[0] = all->s[d];
		all->s[d] = temp;
		recovery(all, 0, d);
		d--;
	}
}

int		ft_error_mes(char *str, t_all *all)
{
	ft_putstr_fd("Error, ", 2);
	ft_putstr_fd(str, 2);
	ft_free(all);
	exit(-1);
}

int		try_init_win(t_all *all)
{
	all->win.win = mlx_new_window(all->win.mlx,
		all->rayc->w, all->rayc->h, "cub3D");
	all->win.img = mlx_new_image(all->win.mlx,
		all->rayc->w, all->rayc->h);
	all->win.addr = mlx_get_data_addr(all->win.img,
		&all->win.bpp, &all->win.line_l, &all->win.en);
	return (0);
}
