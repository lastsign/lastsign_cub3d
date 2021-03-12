/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_make_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:39:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/15 19:39:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_screen(unsigned char *i_head, unsigned char *f_head, t_all *all)
{
	int fd;
	int size;
	int i;

	i = 0;
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT, 0777)) < 0)
		ft_error_mes("can't create image\n", all);
	write(fd, f_head, 14);
	write(fd, i_head, 40);
	size = all->rayc->w * all->win.bpp / 8;
	while (i < all->rayc->h)
	{
		write(fd, all->win.addr + i * all->win.line_l, size);
		i++;
	}
	close(fd);
}

void	get_bmp_header(unsigned char *i_head, unsigned char *f_head, t_all *all)
{
	int size;

	size = 14 + 40 + all->rayc->w * all->rayc->h * all->win.bpp / 8;
	f_head[0] = 'B';
	f_head[1] = 'M';
	f_head[2] = (unsigned char)size;
	f_head[3] = (unsigned char)(size >> 8);
	f_head[4] = (unsigned char)(size >> 16);
	f_head[5] = (unsigned char)(size >> 24);
	f_head[10] = (unsigned char)54;
	i_head[0] = (unsigned char)40;
	i_head[4] = (unsigned char)all->rayc->w;
	i_head[5] = (unsigned char)(all->rayc->w >> 8);
	i_head[6] = (unsigned char)(all->rayc->w >> 16);
	i_head[7] = (unsigned char)(all->rayc->w >> 24);
	i_head[8] = (unsigned char)(-all->rayc->h);
	i_head[9] = (unsigned char)(-all->rayc->h >> 8);
	i_head[10] = (unsigned char)(-all->rayc->h >> 16);
	i_head[11] = (unsigned char)(-all->rayc->h >> 24);
	i_head[12] = (unsigned char)1;
	i_head[14] = (unsigned char)(all->win.bpp);
}

void	render_screen(t_all *all)
{
	unsigned char file_head[14];
	unsigned char info_head[40];

	ft_bzero(info_head, 40);
	ft_bzero(file_head, 14);
	all->parse.screen = 1;
	ft_raycaster(all);
	get_bmp_header(info_head, file_head, all);
	create_screen(info_head, file_head, all);
	ft_putstr_fd("Screenshot is ready\n", 1);
	exit(1);
}
