/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:14:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/30 16:14:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 128

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				line_l;
	int				bpp;
	int				en;
}					t_win;

typedef struct		s_txtr
{
	void			*img;
	void			*addr;
	int				line_l;
	int				bpp;
	int				en;
	int				h;
	int				w;
	double			x;
	double			y;
	double			dis;
}					t_txtr;

typedef struct		s_rcstr
{
	int				w;
	int				h;
	int				floor;
	int				ceilling;
	double			cmr_x;
	double			r_dir_x;
	double			r_dir_y;
	double			pln_x;
	double			pln_y;
	double			oldplnx;
	double			oldplny;
	int				map_x;
	int				map_y;
	double			s_dist_x;
	double			s_dist_y;
	double			d_dist_x;
	double			d_dist_y;
	int				stp_x;
	int				stp_y;
	int				hit;
	int				side;
	double			r_speed;
	double			m_speed;
	double			p_wall_dist;
	int				l_height;
	int				d_start;
	int				d_end;
	double			wallx;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
	int				color;
	double			*buf;
	int				n_spr;
	double			sprit_x;
	double			sprit_y;
	double			inv_det;
	double			t_rnsfx;
	double			t_rnsfy;
	int				s_scrx;
	int				sprith;
	int				spritw;
	int				s_drwsy;
	int				s_drwey;
	int				s_drwsx;
	int				s_drwex;
	int				d_x;
	int				d_y;
	int				d;
}					t_rcstr;

typedef struct		s_parse
{
	char			*txtr_no;
	char			*txtr_so;
	char			*txtr_we;
	char			*txtr_ea;
	char			*txtr_s;
	int				n_elem;
	int				h;
	int				w;
	int				r;
	int				g;
	int				b;
	char			**map_check;
	int				n_plr;
	int				len_m;
	int				screen;
}					t_parse;

typedef struct		s_plr
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			olddir_x;
	double			olddir_y;
	double			start;
	double			end;
}					t_plr;

typedef struct		s_butn
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				l;
	int				r;
	int				e;
}					t_butn;

typedef struct		s_all
{
	t_win			win;
	t_plr			*plr;
	t_rcstr			*rayc;
	t_parse			parse;
	t_txtr			*no;
	t_txtr			*so;
	t_txtr			*we;
	t_txtr			*ea;
	t_txtr			*s;
	t_butn			*butn;
	char			**map;
}					t_all;

int					get_next_line(int fd, char **line);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_adition(unsigned int n, unsigned m, char const *s1,
					char const *s2);
char				*ft_strchr(const char *str, int ch);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);

void				ft_raycaster(t_all *all);
int					ft_parser(t_all *all, char *line);
void				ft_reset_t(t_all *all);
int					try_parse_resolution(t_all *all, char *line);
void				try_parse_north_texture(t_all *all, char *path, char *exp);
void				try_parse_south_texture(t_all *all, char *path, char *exp);
void				try_parse_west_texture(t_all *all, char *path, char *exp);
void				try_parse_east_texture(t_all *all, char *path, char *exp);
void				try_parse_sprite_texture(t_all *all, char *path,
						char *exp);
int					get_info_of_text(t_all *all);
void				ft_free(t_all *all);
int					try_parse_map(t_all *all, t_list **head, int i, int j);
int					ft_error_mes(char *str, t_all *all);
int					try_parse_floor_celling_color(t_all *all, char *color,
						int isf);
void				render_screen(t_all *all);
void				heap_sort(t_all *all, int n);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
void				ft_draw_sprites(t_all *all, t_rcstr *r, t_plr *plr);
int					try_init_win(t_all *all);
int					my_close(t_all *all);
void				ft_draw_vertical(t_all *all, t_rcstr *r, int x);
void				ft_calc_heightvline(t_all *all, t_rcstr *r, t_plr *plr,
						int x);
void				valid_plr_and_sprt(t_all *all, char **map, int i, int j);
void				plr_start_pos(t_all *all, char **map, int i, int j);
void				valid_deap_map(t_all *all, char **map, int i);
void				ft_free_list(t_list **head);
int					button_pressed(int key, t_all *all);
int					button_unpressed(int key, t_all *all);
int					butn_handler(t_all *all);
void				ft_free_array(char **rgb);

#endif
