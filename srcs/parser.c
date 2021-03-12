/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:53:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/09 13:53:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_arg(t_list **head)
{
	return (!ft_memcmp((*head)->content, "WE ", 3) ||
		!ft_memcmp((*head)->content, "SO ", 3) ||
		!ft_memcmp((*head)->content, "NO ", 3) ||
		!ft_memcmp((*head)->content, "EA ", 3) ||
		!ft_memcmp((*head)->content, "S ", 2) ||
		!ft_memcmp((*head)->content, "", 1) ||
		!ft_memcmp((*head)->content, "C ", 2) ||
		!ft_memcmp((*head)->content, "R ", 2) ||
		!ft_memcmp((*head)->content, "F ", 2));
}

void	valid_map(t_all *all, char **map, t_list **head)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if (!(all->parse.map_check[i] =
			malloc(all->parse.len_m + 1 * sizeof(char))))
			ft_error_mes("malloc didn't allocate memory\n", all);
		ft_memcpy(all->parse.map_check[i], map[i], j);
		while (j < all->parse.len_m)
			all->parse.map_check[i][j++] = ' ';
		all->parse.map_check[i][j] = '\0';
		i++;
	}
	j = 0;
	i = ft_lstsize(*head);
	if (!(all->parse.map_check[i] =
		malloc(all->parse.len_m + 1 * sizeof(char))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	while (j < all->parse.len_m)
		all->parse.map_check[i][j++] = ' ';
	all->parse.map_check[i][j] = '\0';
}

void	create_map(t_all *all, t_list **head, char ***map)
{
	char	**ful;
	int		i;
	int		j;
	t_list	*temp;

	while (check_arg(head))
		(*head) = (*head)->next;
	i = 0;
	temp = *head;
	if (!(*map = ft_calloc(ft_lstsize(temp) + 1, sizeof(char *))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	if (!(ful = ft_calloc(ft_lstsize(temp) + 2, sizeof(char *))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	all->map = *map;
	all->parse.map_check = ful;
	while (temp)
	{
		j = ft_strlen((char *)temp->content);
		all->parse.len_m = (all->parse.len_m < j) ? j : all->parse.len_m;
		all->map[i++] = temp->content;
		temp = temp->next;
	}
	valid_map(all, *map, head);
}

void	sprite_srart_pos(t_all *all, char **map)
{
	int i;
	int u;
	int j;

	if (!(all->s = (t_txtr*)malloc(sizeof(t_txtr) * (all->rayc->n_spr + 1))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	i = -1;
	u = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == '2')
			{
				all->s[u].y = (double)i + 0.5;
				all->s[u].x = (double)j + 0.5;
				u++;
			}
	}
}

int		try_parse_map(t_all *all, t_list **head, int i, int j)
{
	char	**map;

	create_map(all, head, &map);
	while (map[i])
	{
		valid_deap_map(all, map, i);
		j = 0;
		while (map[i][j] != '\0')
		{
			valid_plr_and_sprt(all, map, i, j);
			if ((map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'W' || map[i][j] == 'E') && all->parse.n_plr < 1)
				plr_start_pos(all, map, i, j);
			else if (all->parse.n_plr == 1 &&
			(map[i][j] == 'N' || map[i][j] == 'S' ||
			map[i][j] == 'W' || map[i][j] == 'E'))
				ft_error_mes("invalid map", all);
			j++;
		}
		i++;
	}
	(all->parse.n_plr == 0) ? ft_error_mes("no player", all) : 0;
	sprite_srart_pos(all, map);
	all->parse.n_elem++;
	return (0);
}
