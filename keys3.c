#include "fdf.h"

void	handle_z(int keysym, t_vars *vars)
{
	if (keysym == 122 && vars->z_modify < 20)
		vars->z_modify += 0.1;
	else if (keysym == 120 && vars->z_modify > 0.2)
		vars->z_modify -= 0.1;
	else if (keysym == 65289)
		vars->z_modify = 100;
	else if (keysym == 65507)
		vars->z_modify = 10;
	else if (keysym == 65505)
		vars->z_modify = 1;
}

void	handle_projection(int keysym, t_vars *vars)
{
	if (keysym == 121 && vars->flag < 3)
		vars->tranform_number++;
	else if (keysym == 117 && vars->flag > 1)
		vars->tranform_number--;
}

void	free_map(t_vars *vars)
{
	int	i;

	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	i = -1;
	while (vars->map[++i])
	{
		free(vars->map[i]);
		free(vars->point_map[i]);
	}
	free(vars->map);
	free(vars->point_map);
}

int	change_map(t_vars *vars, int i)
{
	vars->map_number = vars->map_number + i;
	vars->nb_cols = 0;
	vars->nb_lines = 0;
	free_map(vars);
	choose_map(vars);
	return (0);
}
