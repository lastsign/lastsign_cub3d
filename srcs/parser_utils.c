/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:55:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/12/09 13:55:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_inti_rayc(t_all *all)
{
	all->rayc->d_end = 0;
	all->rayc->d_start = 0;
	all->rayc->r_speed = 0.04;
	all->rayc->m_speed = 0.10;
	all->rayc->pln_x = 0;
	all->rayc->pln_y = 0;
	all->rayc->oldplnx = 0;
	all->rayc->oldplny = 0;
	all->rayc->l_height = 0;
	all->rayc->p_wall_dist = 0;
	all->rayc->cmr_x = 0;
	all->rayc->s_dist_x = 0;
	all->rayc->map_x = 0;
	all->rayc->hit = 0;
	all->rayc->d_dist_x = 0;
	all->rayc->d_dist_y = 0;
	all->rayc->side = 0;
	all->rayc->s_dist_y = 0;
	all->rayc->r_dir_x = 0;
	all->rayc->r_dir_y = 0;
	all->rayc->map_y = 0;
	all->rayc->stp_x = 0;
	all->rayc->stp_y = 0;
	all->rayc->w = 0;
	all->rayc->h = 0;
}

void	ft_init_rayc_no(t_all *all)
{
	all->rayc->floor = 0;
	all->rayc->ceilling = 0;
	all->rayc->n_spr = 0;
	all->rayc->sprit_x = 0;
	all->rayc->sprit_y = 0;
	all->rayc->inv_det = 0;
	all->rayc->t_rnsfx = 0;
	all->rayc->t_rnsfy = 0;
	all->rayc->s_scrx = 0;
	all->rayc->sprith = 0;
	all->rayc->spritw = 0;
	all->rayc->s_drwsy = 0;
	all->rayc->s_drwey = 0;
	all->rayc->s_drwsx = 0;
	all->rayc->s_drwex = 0;
	all->rayc->d_x = 0;
	all->rayc->d_y = 0;
	all->rayc->d = 0;
	all->no->w = 0;
	all->no->bpp = 0;
	all->no->h = 0;
	all->no->addr = 0;
	all->no->line_l = 0;
	all->no->img = 0;
	all->no->en = 0;
}

void	ft_init_so_we_ea(t_all *all)
{
	all->win.mlx = mlx_init();
	all->so->w = 0;
	all->so->bpp = 0;
	all->so->h = 0;
	all->so->addr = 0;
	all->so->line_l = 0;
	all->so->img = 0;
	all->so->en = 0;
	all->we->w = 0;
	all->we->bpp = 0;
	all->we->h = 0;
	all->we->addr = 0;
	all->we->line_l = 0;
	all->we->img = 0;
	all->we->en = 0;
	all->ea->w = 0;
	all->ea->bpp = 0;
	all->ea->h = 0;
	all->ea->addr = 0;
	all->ea->line_l = 0;
	all->ea->img = 0;
	all->ea->en = 0;
}

void	ft_init_s_parse_plr(t_all *all)
{
	all->no->w = 0;
	all->no->bpp = 0;
	all->no->h = 0;
	all->no->addr = 0;
	all->no->line_l = 0;
	all->no->img = 0;
	all->no->en = 0;
	all->parse.txtr_no = 0;
	all->parse.txtr_so = 0;
	all->parse.txtr_we = 0;
	all->parse.txtr_ea = 0;
	all->parse.txtr_s = 0;
	all->parse.n_elem = 0;
	all->parse.n_plr = 0;
	all->parse.len_m = -1;
	all->parse.screen = 0;
	all->plr->x = 0;
	all->plr->y = 0;
	all->plr->dir_x = 0;
	all->plr->dir_y = 0;
	all->plr->olddir_x = 0;
	all->plr->olddir_y = 0;
	all->plr->start = 0;
	all->plr->end = 0;
}

void	ft_reset_t(t_all *all)
{
	if (!(all->rayc = (t_rcstr *)malloc(sizeof(t_rcstr))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	if (!(all->plr = (t_plr *)malloc(sizeof(t_plr))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	if (!(all->no = (t_txtr *)malloc(sizeof(t_txtr))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	if (!(all->so = (t_txtr *)malloc(sizeof(t_txtr))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	if (!(all->we = (t_txtr *)malloc(sizeof(t_txtr))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	if (!(all->ea = (t_txtr *)malloc(sizeof(t_txtr))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	if (!(all->butn = (t_butn *)malloc(sizeof(t_butn))))
		ft_error_mes("malloc didn't allocate memory\n", all);
	ft_inti_rayc(all);
	ft_init_rayc_no(all);
	ft_init_so_we_ea(all);
	ft_init_s_parse_plr(all);
}
