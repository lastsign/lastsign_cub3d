/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resol_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:52:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/15 21:52:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	try_parse_color_util(t_all *all, char **rgb, int j)
{
	int		len;

	j = 0;
	while (rgb[1][j] != '\0' && rgb[1][j] == ' ')
		j++;
	len = ft_strlen(rgb[1] + j);
	while (ft_isdigit(rgb[1][j]))
		j++;
	if (rgb[1][j] != '\0' || len > 3 || len == 0)
		ft_error_mes("color element is wrong", all);
	else if (rgb[1][j] == '\0')
		((all->parse.g = ft_atoi(rgb[1])) > 255) ?
		ft_error_mes("color element is wrong", all) : 0;
	j = 0;
	while (rgb[2][j] != '\0' && rgb[2][j] == ' ')
		j++;
	len = ft_strlen(rgb[2] + j);
	while (ft_isdigit(rgb[2][j]))
		j++;
	if (rgb[2][j] != '\0' || len > 3 || len == 0)
		ft_error_mes("color element is wrong", all);
	else if (rgb[2][j] == '\0')
		((all->parse.b = ft_atoi(rgb[2])) > 255) ?
		ft_error_mes("color element is wrong", all) : 0;
}

int		try_parse_floor_celling_color(t_all *all, char *color, int isf)
{
	int		j;
	char	**rgb;
	int		len;

	if (!(rgb = ft_split(color, ',')))
		ft_error_mes("malloc didn't allocate memory\n", all);
	j = 0;
	while (rgb[0][j] != '\0' && rgb[0][j] == ' ')
		j++;
	len = ft_strlen(rgb[0] + j);
	while (ft_isdigit(rgb[0][j]))
		j++;
	if (rgb[0][j] != '\0' || len > 3 || len == 0)
		ft_error_mes("color element is wrong", all);
	else if (rgb[0][j] == '\0')
		((all->parse.r = ft_atoi(rgb[0])) > 255) ?
		ft_error_mes("color element is wrong", all) : 0;
	try_parse_color_util(all, rgb, 0);
	(isf == 1) ? all->rayc->floor = (int)(0 << 24 | all->parse.r << 16
		| all->parse.g << 8 | all->parse.b) : 0;
	(isf == 2) ? all->rayc->ceilling = (int)(0 << 24 | all->parse.r << 16
		| all->parse.g << 8 | all->parse.b) : 0;
	all->parse.n_elem++;
	ft_free_array(rgb);
	return (0);
}

void	try_parse_resol_util(t_all *all, char *res, int i, int h)
{
	while (res[i] != '\0' && ft_isdigit(res[i]))
		i++;
	while (res[i] != '\0' && res[i] == ' ')
		i++;
	(!ft_isdigit(res[i])) ? ft_error_mes("wrong resolution\n", all) : 0;
	if (ft_strlen(res + i) > 4)
		all->rayc->h = h;
	else
		all->rayc->h = ft_atoi(res + i);
	while (res[i] != '\0' && ft_isdigit(res[i]))
		i++;
	(res[i] != '\0') ? ft_error_mes("wrong line with resotution\n", all) : 0;
	if (all->rayc->h == 0 && all->rayc->w == 0)
		ft_error_mes("no resolution\n", all);
	all->rayc->h = (all->rayc->h > h) ? h : all->rayc->h;
	all->rayc->h = (all->rayc->h == 0) ? h : all->rayc->h;
}

int		try_parse_resolution(t_all *all, char *res)
{
	int	i;
	int	len;
	int w;
	int h;

	i = 0;
	len = 0;
	mlx_get_screen_size(all->win.mlx, &w, &h);
	while (res[i] != '\0' && res[i] == ' ')
		i++;
	(!ft_isdigit(res[i])) ? ft_error_mes("wrong resolution\n", all) : 0;
	while (ft_isdigit(res[len]))
		len++;
	if (len - i <= 4)
		all->rayc->w = ft_atoi(res + i);
	else
		all->rayc->w = w;
	try_parse_resol_util(all, res, i, h);
	all->rayc->w = (all->rayc->w > w) ? w : all->rayc->w;
	all->rayc->w = (all->rayc->w == 0) ? w : all->rayc->w;
	if (!(all->rayc->buf = malloc(sizeof(double) * all->rayc->w)))
		ft_error_mes("malloc didn't allocate memory\n", all);
	all->parse.n_elem++;
	return (0);
}
