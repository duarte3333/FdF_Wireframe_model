/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:29:15 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/11/19 16:48:58 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "Libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
#include "X11/X.h"
#include "X11/keysym.h"
#include <stdlib.h>

#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF
#define BLUE_PIXEL 0x0000FF

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1200
#define MLX_ERROR 1
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point {
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct	s_screen {
	int		min_x;
	int		min_y;
	int		max_y;
	int		max_x;
}				t_screen;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		**map;
	int		nb_lines;
	int		nb_cols;
	float	size_grid;
	int		offset_x;
	int		offset_y;
	float	angle_x;
	float	angle_y;
	float	angle;
	int		last_x;
	int		middle_point_x;
	int		middle_point_y;
	int		max_z;
	int		min_z;
	int 	color;
	int		flag;
	float 	theta;
	float	phi;
	float	qsi;
	t_data	img;
	t_point **point_map;
	int 	new_max;
	float		z_modify;
	char 	**map_file;
	t_screen screen;
	int		map_number;
	int		tranform_number;
	int		map_option;
	int		max_maps;
}				t_vars;


char	*get_next_line(int fd);
void    map_loading(t_vars *vars, int fd, int index);
t_point init_point(int x, int y, int z);
t_point rotation_z(t_point a, t_vars *vars);
t_point rotation_y(t_point a, t_vars *vars);
t_point rotation_x(t_point a, t_vars *vars);
t_point isometric_projection(t_point a, t_vars *vars);
t_point front_view(t_point a, t_vars *vars);
t_point transformations(t_vars *vars, t_point a);
t_point parallel_projection(t_point a, t_vars *vars);
void   	ft_max_and_min(int nb, t_vars *vars);
void    screen_dimensions(t_point a, t_vars *vars);
void 	map_to_point(t_vars *vars);
void	draw_img_grid(t_vars *vars);
int 	percent_to_color(float percent, int flag);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		ft_close(void *o);
void	clean_img(t_vars *vars);
void 	choose_map(t_vars *vars);
int 	mouse_hook(int button, int x, int y, t_vars *vars);
int		handle_keypress(int keysym, t_vars *vars);

#endif
