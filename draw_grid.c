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
		a = front_view(a, vars);
	if (vars->tranform_number == 3)
		a = parallel_projection(a, vars);
	return (a);
}


void  two_points(t_vars *vars, t_point a, t_point b)
{
	float	slope;
	float	z_rgb;
	float	range;
	float	direction;
	float	x;
	float	y;
	float	range_y;

	a = transformations(vars, a);
	b = transformations(vars, b);

	x = a.x;
	z_rgb = a.z / vars->new_max;
	if (b.z - a.z > 0)
		range = (b.z / vars->new_max - z_rgb);
	else
		range = -(a.z / vars->new_max - b.z / vars->new_max);
	if (fabs(b.x - a.x) >= 0 && fabs(b.x - a.x) <= 0.01)
	{
		y = a.y;
		while (fabs(b.y - y) > 0.5)
		{
			z_rgb = z_rgb + range/((vars->size_grid));
			my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag));
			y += ((b.y - a.y)/(fabs(b.y - a.y)));
		}
	}
	if (fabs(b.y - a.y) >= 0 && fabs(b.y - a.y) <= 0.01)
	{
		while (fabs(b.x - x) > 0.5)
		{
			y = a.y;
			z_rgb = z_rgb + range/((vars->size_grid));
			my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag));
			x += ((b.x - a.x)/(fabs(b.x - a.x)));
		}
	}
	slope = (b.y - a.y) / (b.x - a.x);
	direction = (int)(b.x - a.x) / (fabs(b.x - a.x));
	y = slope * (x - a.x) + a.y;

	while (fabs(b.x - x) > 0.5)
	{
		y = slope * (x - a.x) + a.y;
		z_rgb = z_rgb + range / ((vars->size_grid));
		my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag));
		range_y = fabs(y - (slope * ((x + direction) - a.x) + a.y));
		if (range_y > 1)
		{
			while ((int)(y - (slope * ((x + direction) - a.x) + a.y)))
			{
				if ((b.x - a.x) == 0)
					y += 1;
				else
					y += ((b.y - a.y) / (fabs(b.y - a.y)));
				my_mlx_pixel_put(vars, x, y, \
				percent_to_color(z_rgb, vars->flag));
			}
		}
		x += direction;
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

// void	edge_cases(t_vars *vars, t_point a, t_point b)
// {
	// if (fabs(b.x - a.x) >= 0 && fabs(b.x - a.x) <= 0.01)
	// {
	// 	y = a.y;
	// 	while (fabs(b.y - y) > 0.5)
	// 	{
	// 		z_rgb = z_rgb + range/((vars->size_grid));
	// 		my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag));
	// 		y += ((b.y - a.y)/(fabs(b.y - a.y)));
	// 	}
	// }
	// if (fabs(b.y - a.y) >= 0 && fabs(b.y - a.y) <= 0.01)
	// {
	// 	while (fabs(b.x - x) > 0.5)
	// 	{
	// 		y = a.y;
	// 		z_rgb = z_rgb + range/((vars->size_grid));
	// 		my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag));
	// 		x += ((b.x - a.x)/(fabs(b.x - a.x)));
	// 	}
	// }