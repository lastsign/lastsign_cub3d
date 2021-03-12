/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 20:21:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/20 23:59:21 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parser(t_all *all, char *line)
{
	if (!ft_memcmp("R ", line, 2))
		try_parse_resolution(all, line + 2);
	else if (!ft_memcmp("NO ", line, 3))
		try_parse_north_texture(all, line + 3, ".xpm");
	else if (!ft_memcmp("SO ", line, 3))
		try_parse_south_texture(all, line + 3, ".xpm");
	else if (!ft_memcmp("WE ", line, 3))
		try_parse_west_texture(all, line + 3, ".xpm");
	else if (!ft_memcmp("EA ", line, 3))
		try_parse_east_texture(all, line + 3, ".xpm");
	else if (!ft_memcmp("S ", line, 2))
		try_parse_sprite_texture(all, line + 2, ".xpm");
	else if (!ft_memcmp("F ", line, 2))
		try_parse_floor_celling_color(all, line + 2, 1);
	else if (!ft_memcmp("C ", line, 2))
		try_parse_floor_celling_color(all, line + 2, 2);
	return (0);
}

void	ft_read_file(t_all *all, char *line, t_list **head, int fd)
{
	t_list *temp;

	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(head, ft_lstnew(line));
		ft_parser(all, line);
	}
	ft_lstadd_back(head, ft_lstnew(line));
	ft_parser(all, line);
	if (all->parse.n_elem == 8)
	{
		temp = *head;
		try_parse_map(all, &temp, 0, 0);
		try_init_win(all);
		get_info_of_text(all);
		ft_free_list(head);
	}
	else
		ft_error_mes("wrong number elements in file\n", all);
}

int		ft_check_filename(t_all *all, char *path, char *expns, t_list **head)
{
	int		len;
	int		fd;
	char	*line;

	line = NULL;
	len = ft_strlen(path);
	if (len > 4)
	{
		if (path[len - 1] == expns[3] && path[len - 2] == expns[2] &&
				path[len - 3] == expns[1] && path[len - 4] == expns[0])
		{
			if ((fd = open(path, O_RDONLY)) < 0)
				ft_error_mes("no such file", all);
			ft_read_file(all, line, head, fd);
			close(fd);
			return (0);
		}
		else
			ft_error_mes("expansion of file is wrong\n", all);
	}
	else
		ft_error_mes("expansion of file is wrong\n", all);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_list	*head;

	head = NULL;
	ft_reset_t(&all);
	if (argc == 2 || argc == 3)
	{
		if (!ft_check_filename(&all, argv[1], ".cub", &head))
			if (argc == 3)
			{
				if (!ft_memcmp(argv[2], "--save", 7))
					render_screen(&all);
				else
					ft_error_mes("wrong third argument of program\n", &all);
			}
	}
	else
		ft_error_mes("wrong number of program arguments\n", &all);
	mlx_hook(all.win.win, 17, (1L << 17), &my_close, &all);
	mlx_hook(all.win.win, 2, (1L << 0), &button_pressed, &all);
	mlx_hook(all.win.win, 3, (1L << 1), &button_unpressed, &all);
	mlx_loop_hook(all.win.mlx, &butn_handler, &all);
	mlx_loop(all.win.mlx);
	return (0);
}
