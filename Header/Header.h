/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:00:45 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/07 12:54:55 by aperraul         ###   ########.fr       */
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

# define WIN_X 2000
# define WIN_Y 2000

typedef struct	s_wall
{
	int			wall_x;
	double		pwd;
	int			hightline;
	int			drawstart;
	int			drawend;
	int			color;
}				t_wall;

typedef struct	s_ray
{
	double		cam_x;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sdist_x;
	double		sdist_y;
	double		ddist_x;
	double		ddist_y;
	double		step_x;
	double		step_y;
	int			hit;
	int			side;

}				t_ray;

typedef struct	s_cam
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
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

typedef struct	s_w3d
{
	t_mlx		*mlx;
	int			nb_lines;
	int			*nb_x_line;
	int			**map;
	t_cam		cam;
	t_delt		delt;
	t_ray		ray;
	t_wall		wall;
}				t_w3d;

t_w3d		*ft_w3d_init();
void		ft_get_map(t_w3d *w3d, int ret);
int			ft_check_line(char *line);
void		ft_pre_w3d(t_w3d *w3d);
void		ft_wolf3d(t_w3d *w3d);
void		ft_draw_wolf3d(t_w3d *w3d);
int			ft_wolf_move(int keycode, t_w3d *w3d);
int			ft_wolf3d_loop(t_w3d *w3d);
void		ft_wolf_events(t_w3d *w3d);

#endif
