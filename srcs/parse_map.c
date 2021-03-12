/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:00:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/15 22:00:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		try_check_fullness(t_all *all, int p_y, int p_x)
{
	if (p_x < 0 || p_y < 0 || all->parse.map_check[p_y][p_x] == ' ' ||
		all->parse.map_check[p_y][p_x] == '\0')
		ft_error_mes("map invalid", all);
	if (all->parse.map_check[p_y][p_x] == '1' ||
		all->parse.map_check[p_y][p_x] == '.')
		return (1);
	all->parse.map_check[p_y][p_x] = '.';
	return (try_check_fullness(all, p_y + 1, p_x) &&
			try_check_fullness(all, p_y, p_x + 1) &&
			try_check_fullness(all, p_y - 1, p_x) &&
			try_check_fullness(all, p_y, p_x - 1));
}

void	plr_start_pos(t_all *all, char **map, int i, int j)
{
	all->parse.n_plr = 1;
	all->plr->x = (float)j + 0.5;
	all->plr->y = (float)i + 0.5;
	if (map[i][j] == 'N')
	{
		all->rayc->pln_x = tan(M_PI * 66 / 360);
		all->plr->dir_y = -1;
	}
	if (map[i][j] == 'S')
	{
		all->rayc->pln_x = -tan(M_PI * 66 / 360);
		all->plr->dir_y = 1;
	}
	if (map[i][j] == 'W')
	{
		all->rayc->pln_y = -tan(M_PI * 66 / 360);
		all->plr->dir_x = -1;
	}
	if (map[i][j] == 'E')
	{
		all->rayc->pln_y = tan(M_PI * 66 / 360);
		all->plr->dir_x = 1;
	}
	map[i][j] = '0';
}

void	valid_plr_and_sprt(t_all *all, char **map, int i, int j)
{
	if (ft_strchr("02NSWE", map[i][j]) &&
		all->parse.map_check[i][j] != '.')
		if (!try_check_fullness(all, i, j))
			ft_error_mes("invalid map", all);
	if (!(map[i][j] == ' ' || map[i][j] == '0' || map[i][j] == '1' ||
		map[i][j] == '2' || map[i][j] == 'S' || map[i][j] == 'N' ||
		map[i][j] == 'W' || map[i][j] == 'E'))
		ft_error_mes("invalid map", all);
	if (map[i][j] == '2')
		all->rayc->n_spr++;
}

void	valid_deap_map(t_all *all, char **map, int i)
{
	if (!ft_memcmp(map[i], "", 1) && all->rayc->d != 1)
		all->rayc->d = 1;
	else if (!ft_memcmp(map[i], "", 1) && all->rayc->d == 1)
		ft_error_mes("invalid map", all);
	else if (ft_memcmp(map[i], "", 1) && all->rayc->d == 1)
		ft_error_mes("invalid map", all);
}
