#include "fdf.h"

void	screen_dimensions(t_point a, t_vars *vars)
{
	int	x;
	int	y;

	ft_max_and_min(a.z, vars);
	if (vars->tranform_number == 1)
		a = isometric_projection(a, vars);
	else if (vars->tranform_number == 2)
		a = front_view(a, vars);
	else if (vars->tranform_number == 3)
		a = parallel_projection(a, vars);
	x = a.x;
	y = a.y;
	if (x < vars->screen.min_x && x < 0)
		vars->screen.min_x = x;
	if (y < vars->screen.min_y && y < 0)
		vars->screen.min_y = y;
	if (!vars->screen.max_x || x > vars->screen.max_x)
		vars->screen.max_x = x;
	if (!vars->screen.max_y || y > vars->screen.max_y)
		vars->screen.max_y = y;
}

//Esta funcao cria uma lista de listas de t_points
//point_map = {{point1, point2, point3}, {point4, point5, point6}, ... }
//No fundo gera o map sendo que em cada entrada temos um point
void	map_to_point(t_vars *vars)
{
	int	x;
	int	y;

	vars->point_map = malloc(sizeof(t_point *) * vars->nb_lines);
    y = -1;
	while (vars->map[++y])
	{
		x = 0;
		vars->point_map[y] = malloc(sizeof(t_point) * vars->nb_cols);
		while (x < vars->nb_cols)
		{
			(vars->point_map)[y][x] = init_point(x, y, vars->map[y][x]);
			screen_dimensions((vars->point_map)[y][x], vars);
			x++;
		}
	}
}
