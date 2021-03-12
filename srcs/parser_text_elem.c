/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_text_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:11:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/15 21:11:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	try_parse_north_texture(t_all *all, char *path, char *exp)
{
	int len;

	while (*path != '\0' && *path == ' ')
		path++;
	len = ft_strlen(path);
	if (len > 4)
	{
		if (path[len - 1] == exp[3] && path[len - 2] == exp[2] &&
			path[len - 3] == exp[1] && path[len - 4] == exp[0])
			all->parse.txtr_no = path;
		else
			ft_error_mes("wrong expansion of file", all);
	}
	else
		ft_error_mes("wrong line with north textures", all);
	all->parse.n_elem++;
}

void	try_parse_south_texture(t_all *all, char *path, char *exp)
{
	int len;

	while (*path != '\0' && *path == ' ')
		path++;
	len = ft_strlen(path);
	if (len > 4)
	{
		if (path[len - 1] == exp[3] && path[len - 2] == exp[2] &&
			path[len - 3] == exp[1] && path[len - 4] == exp[0])
			all->parse.txtr_so = path;
		else
			ft_error_mes("wrong expansion of file", all);
	}
	else
		ft_error_mes("wrong line with south textures", all);
	all->parse.n_elem++;
}

void	try_parse_west_texture(t_all *all, char *path, char *exp)
{
	int len;

	while (*path != '\0' && *path == ' ')
		path++;
	len = ft_strlen(path);
	if (len > 4)
	{
		if (path[len - 1] == exp[3] && path[len - 2] == exp[2] &&
			path[len - 3] == exp[1] && path[len - 4] == exp[0])
			all->parse.txtr_we = path;
		else
			ft_error_mes("wrong expansion of file", all);
	}
	else
		ft_error_mes("wrong line with west textures", all);
	all->parse.n_elem++;
}

void	try_parse_east_texture(t_all *all, char *path, char *exp)
{
	int len;

	while (*path != '\0' && *path == ' ')
		path++;
	len = ft_strlen(path);
	if (len > 4)
	{
		if (path[len - 1] == exp[3] && path[len - 2] == exp[2] &&
			path[len - 3] == exp[1] && path[len - 4] == exp[0])
			all->parse.txtr_ea = path;
		else
			ft_error_mes("wrong expansion of file", all);
	}
	else
		ft_error_mes("wrong line with east textures", all);
	all->parse.n_elem++;
}

void	try_parse_sprite_texture(t_all *all, char *path, char *exp)
{
	int len;

	while (*path != '\0' && *path == ' ')
		path++;
	len = ft_strlen(path);
	if (len > 4)
	{
		if (path[len - 1] == exp[3] && path[len - 2] == exp[2] &&
			path[len - 3] == exp[1] && path[len - 4] == exp[0])
			all->parse.txtr_s = path;
		else
			ft_error_mes("wrong expansion of file", all);
	}
	else
		ft_error_mes("wrong line with east textures", all);
	all->parse.n_elem++;
}
