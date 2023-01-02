/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:17:58 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/02 23:34:07 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	transformations(t_vars *vars, t_point a)
{
	a = rotation_x(a, vars);
	a = rotation_y(a, vars);
	a = rotation_z(a, vars);
	ft_max_and_min(a.z, vars);
	if (vars->tranform_number == 1)
		a = isometric_projection(a, vars);
	if (vars->tranform_number == 2)
		a = parallel_projection(a, vars);
	if (vars->tranform_number == 3)
		a = top_view(a, vars);
	if (vars->tranform_number == 4)
		a = right_view(a, vars);
	if (vars->tranform_number == 5)
		a = front_view(a, vars);
	return (a);
}

void	edge_case(t_vars *vars, t_point a, t_point b, float range, float x)
{
	int	y;
	int	flag;

	flag = 0;
	y = a.y;
	while (fabs(b.y - y) > 0.5)
	{
		vars->rgb_p = vars->rgb_p + range / ((vars->size_grid));
		my_mlx_pixel_put(vars, x, y, percent_to_color(vars->rgb_p, \
			vars->flag));
		y += ((b.y - a.y) / (fabs(b.y - a.y)));
		flag++;
	}
	return ;
}

void	inicializer(t_vars *vars, t_point a, t_point b, float x)
{
	vars->rgb_p = a.z / vars->new_max;
	if (b.z - a.z > 0)
		vars->range_z = (b.z / vars->new_max - vars->rgb_p);
	else
		vars->range_z = -(a.z / vars->new_max - b.z / vars->new_max);
	if (fabs(b.x - a.x) <= 0.5 && fabs(b.y - a.y) > 0.5)
		edge_case(vars, a, b, vars->range_z, x);
	vars->slope = (b.y - a.y) / (b.x - a.x);
	vars->direction = (b.x - a.x) / (fabs(b.x - a.x));
}

void	two_points(t_vars *vars, t_point a, t_point b)
{
	float	x;
	float	y;

	a = transformations(vars, a);
	b = transformations(vars, b);
	x = a.x;
	inicializer(vars, a, b, x);
	while (fabs(b.x - x) > 0.5)
	{
		y = vars->slope * (x - a.x) + a.y;
		vars->rgb_p = vars->rgb_p + vars->range_z / ((vars->size_grid));
		my_mlx_pixel_put(vars, x, y, percent_to_color(vars->rgb_p, vars->flag));
		if ((fabs(y - (vars->slope * ((x + vars->direction) - a.x) + a.y))) > 1)
		{
			while ((int)(y - (vars->slope * \
				((x + vars->direction) - a.x) + a.y)))
			{	
				y += ((b.y - a.y) / (fabs(b.y - a.y)));
				my_mlx_pixel_put(vars, x, y, \
				percent_to_color(vars->rgb_p, vars->flag));
			}
		}
		x += vars->direction;
	}
}

void	draw_img_grid(t_vars *vars)
{
	int	x;
	int	y;
	int	y_new;

	y = -1;
	while (++y < vars->nb_lines - 1)
	{
		x = 0;
		while (x < vars->nb_cols)
		{
			y_new = vars->nb_lines - 2 - y;
			if (x < vars->nb_cols - 1)
				two_points(vars, (vars->point_map)[y_new][x], \
				(vars->point_map)[y_new][x + 1]);
			if (y < vars->nb_lines - 2)
				two_points(vars, (vars->point_map)[y_new][x], \
				(vars->point_map)[y_new - 1][x]);
			x++;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_menu(vars);
}
