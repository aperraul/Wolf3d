/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:00:45 by aperraul          #+#    #+#             */
/*   Updated: 2016/05/24 15:34:23 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../Libdraw/libdraw.h"
# include "../libmlx/X.h"
# include <sys/time.h>

# define WIN_X 1200
# define WIN_Y 900
# define TEX_X 64
# define TEX_Y 64

typedef struct	s_wall
{
	int			wall_x;
	double		pwd;
	int			hline;
	int			dstart;
	int			dend;
}				t_wall;

typedef struct	s_ray
{
	double		cam_x;
	t_ptd		rpos;
	t_ptd		rdir;
	t_pt		map;
	t_ptd		sdist;
	t_ptd		ddist;
	t_ptd		step;
	int			hit;
	int			side;

}				t_ray;

typedef struct	s_cam
{
	t_ptd		pos;
	t_ptd		dir;
	t_ptd		plan;
	double		mspeed;
	double		rspeed;
	int			keym;
	int			keyd;
	int			keyr;
}				t_cam;

typedef struct	s_delt
{
	struct timeval		t1;
	struct timeval		t2;
	double				dt;
}				t_delt;

typedef struct	s_texture
{
	t_img		bluestone;
	t_img		colorstone;
	t_img		eagle;
	t_img		greystone;
	t_img		mossy;
	t_img		purplestone;
	t_img		redbrick;
	t_img		wood;
	t_img		blueportal;
	t_img		orangeportal;
	int			***tab_textures;
	t_img		**tab_xpm;
}				t_texture;

typedef struct	s_portal
{
	int			type;
	int			nbb;
	int			nbo;
	t_pt		posb;
	t_pt		poso;
	int			ovb;
	int			ovo;
	int			orib;
	int			orio;
}				t_portal;

typedef struct	s_w3d
{
	int			v;
	int			size_y;
	int			nb_spawn;
	t_ptd		spawn;
	int			floor_case;
	t_mlx		*mlx;
	int			nb_lines;
	int			*nb_x_line;
	int			**map;
	t_cam		cam;
	t_delt		delt;
	t_ray		ray;
	t_wall		wall;
	t_portal	portal;
	t_texture	texture;
	int			port;
	void		*data;
}				t_w3d;

t_w3d			*ft_w3d_init(void);
void			ft_get_map(t_w3d *w3d, int ret);
int				ft_check_line(char *line, t_w3d *w3d);
int				ft_check_map(t_w3d *w3d);
void			ft_pre_w3d(t_w3d *w3d);
void			ft_wolf3d(t_w3d *w3d);
void			ft_draw_wolf3d(t_w3d *w3d, t_ray *r, int x, int map_val);
int				ft_wolf_move(int keycode, t_w3d *w3d);
int				ft_release_key(int keycode, t_w3d *w3d);
int				ft_choose_color(int val, int side, int c);
int				ft_wolf3d_loop(t_w3d *w3d);
int				ft_wall_side(t_pt map, t_ptd pos, int side);
void			ft_draw_top(t_mlx *mlx, int x, int color, int ds);
void			ft_draw_bot(t_mlx *mlx, int x, int color, int de);
void			ft_wolf_events(t_w3d *w3d);
void			ft_rotate(int i, t_ptd *cdir, t_ptd *cplan, double r);
void			ft_wolf_portal(t_w3d *w3d);
void			ft_set_blue_portal(t_w3d *w3d, t_pt *m);
void			ft_set_orange_portal(t_w3d *w3d, t_pt *m);
void			ft_portal_b_to_o(t_w3d *w3d);
void			ft_portal_o_to_b(t_w3d *w3d);
void			ft_move_forward(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir);
void			ft_move_backward(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir);
void			ft_move_left(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir);
void			ft_move_right(t_w3d *w3d, t_ptd *cpos, t_ptd *cdir);
void			ft_load_w3d_textures(t_w3d *w3d, t_mlx *mlx, t_texture *tex);
void			ft_draw_texture(t_w3d *w3d, int v, int size_y, t_pt pt_draw);
void			ft_clear_w3d(t_w3d *w3d);

#endif
