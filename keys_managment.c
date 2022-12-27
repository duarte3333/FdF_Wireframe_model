#include "fdf.h"

int	ft_close(void *o)
{
	(void) o;
	exit(0);
	return (0);
}

void	clean_img(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->screen.max_x)
	{
		j = -1;
		while (++j < vars->screen.max_y)
			my_mlx_pixel_put(vars, i, j, 0x00000000);
	}
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	clean_img(vars);
	printf("key: %i\n",button);
	if (button == 4)
	{
		vars->size_grid += 1;
	}
	else if (button == 5)
	{
		if (vars->size_grid > 2)
			vars->size_grid -= 1;
		printf("si%f", vars->size_grid);
	}
	else if (button == 1)
	{
		vars->offset_x = x;
		vars->offset_y = y;
	}
	draw_img_grid(vars);
	return (0);
}

void	handle_offset(int keysym, t_vars *vars)
{
	if (keysym == 65363)
		vars->offset_x += 10;
	else if (keysym == 65361)
		vars->offset_x -= 10;
	else if (keysym == 65364)
		vars->offset_y += 10;
	else if (keysym == 65362)
		vars->offset_y -= 10;
}

void	handle_angles(int keysym, t_vars *vars)
{
	if (keysym == 119)
		vars->angle_y += 0.01;
	else if (keysym == 115)
		vars->angle_y -= 0.01;
	else if (keysym == 100)
		vars->angle_x += 0.01;
	else if (keysym == 97)
		vars->angle_x -= 0.01;
}

void	handle_reset(t_vars *vars)
{
	vars->size_grid = 15;
	vars->angle_y = 0.523599;
	vars->angle_x = 0.523599;
	vars->offset_x = -vars->screen.min_x;
	vars->offset_y = -vars->screen.min_y;
	vars->phi = 0;
	vars->qsi = 0;
	vars->theta = 0;
}

void	handle_color(int keysym, t_vars *vars)
{
	if (keysym == 49 && vars->flag < 9)
		vars->flag++;
	else if (keysym == 50 && vars->flag > 1)
		vars->flag--;
	printf("%i\n", vars->flag);
}

//x->theta; y->phi; z->qsi;
void	handle_rotation(int keysym, t_vars *vars)
{
	if (keysym == 51)
		vars->theta -= 0.01;
	else if (keysym == 52)
		vars->theta += 0.01;
	else if (keysym == 53)
		vars->phi += 0.01;
	else if (keysym == 54)
		vars->phi -= 0.01;
	else if (keysym == 55)
		vars->qsi += 0.01;
	else if (keysym == 56)
		vars->qsi -= 0.01;
}

void	handle_z(int keysym, t_vars *vars)
{
	if (keysym == 122 && vars->z_modify < 20)
		vars->z_modify += 0.1;
	else if (keysym == 120 && vars->z_modify > 0.2)
		vars->z_modify -= 0.1;
	else if (keysym == 65507)
		vars->z_modify = 10;
	else if (keysym == 65505)
		vars->z_modify = 1;
}

void	handle_projection(int keysym, t_vars *vars)
{
	if (keysym == 121 && vars->flag < 6)
	{
		vars->tranform_number++;
		printf("nb: %i", vars->tranform_number);
	}
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
//printf("key: %i\n",keysym);
int	handle_keypress(int keysym, t_vars *vars)
{
	clean_img(vars);

	if (keysym == 'm' && vars->map_number <= vars->max_maps )
	{
		printf("%s\n", vars->map_file[vars->map_number]);
		vars->map_number++;
		vars->nb_cols = 0;
		vars->nb_lines = 0;
		free_map(vars);
		choose_map(vars);
		return (0);
	}
	if (keysym == XK_Escape)
		ft_close(0);
	else if (keysym == 65363 || keysym == 65361 \
		|| keysym == 65364 || keysym == 65362)
		handle_offset(keysym, vars);
	else if (keysym == 119 || keysym == 115 || keysym == 100 || keysym == 97)
		handle_angles(keysym, vars);
	else if (keysym == 114)
		handle_reset(vars);
	else if (keysym == 49 || keysym == 50)
		handle_color(keysym, vars);
	else if (keysym == 122 || keysym == 120 \
	|| keysym == 65507 || keysym == 65505)
		handle_z(keysym, vars);
	else if (keysym == XK_Tab)
		vars->size_grid--;
	else if (keysym == 121 || keysym == 117 || keysym == 105 || keysym == 111)
		handle_projection(keysym, vars);
	else if (keysym == 51 || keysym == 52 || keysym == 53 \
	|| keysym == 54 || keysym == 55 || keysym == 56)
		handle_rotation(keysym, vars);
	draw_img_grid(vars);
	return (0);
}
