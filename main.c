#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || y < 0 || x >= vars->screen.max_x || y >= vars->screen.max_y))
	{
		dst = vars->img.addr + (y * vars->img.line_length + \
		x * (vars->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_set_variables(t_vars *vars)
{
	vars->offset_x = 0;
	vars->offset_y = 0;
	vars->theta = 0;
	vars->phi = 0;
	vars->qsi = 0;
	vars->flag = 2;
	vars->size_grid = 15;
	vars->angle_y = 0.523599;
	vars->angle_x = 0.523599;
	vars->angle = 0.523599;
	vars->z_modify = 1;
	vars->screen.min_x = 0;
	vars->screen.min_y = 0;
	vars->tranform_number = 1;
}

void	screen_size(t_vars *vars)
{
	vars->screen.max_x = vars->screen.max_x - vars->screen.min_x;
	vars->screen.max_y = vars->screen.max_y - vars->screen.min_y;
	vars->offset_x = -vars->screen.min_x;
	vars->offset_y = -vars->screen.min_y;
	while ((vars->screen.max_x > WINDOW_WIDTH \
	|| vars->screen.max_y > WINDOW_HEIGHT))
	{
		vars->screen.max_x = vars->screen.max_x / 2;
		vars->screen.max_y = vars->screen.max_y / 2;
		vars->offset_x = abs(vars->offset_x / 2);
		vars->offset_y = abs(vars->offset_y / 2);
		vars->size_grid = vars->size_grid / 2;
		if (vars->size_grid < 2)
		{
			if (vars->screen.max_y > 1200)
				vars->screen.max_y = 1100;
			if (vars->screen.max_x > 1920)
				vars->screen.max_x = 1820;
			break ;
		}
	}
}

void	choose_map(t_vars *vars)
{
	int	fd;

	fd = open(vars->map_file[vars->map_number], O_RDONLY);
	map_loading(vars, fd, 0);
	ft_set_variables(vars);
	map_to_point(vars);
	screen_size(vars);

	vars->map_option = 1;
	vars->offset_x = WINDOW_WIDTH / 2 \
		- vars->screen.max_x / 2 - vars->screen.min_x;
	vars->offset_y = WINDOW_HEIGHT / 2 \
		- vars->screen.max_y / 2 - vars->screen.min_y;
	vars->screen.max_x = WINDOW_WIDTH;
	vars->screen.max_y = WINDOW_HEIGHT;

	vars->img.img = \
		mlx_new_image(vars->mlx, vars->screen.max_x, vars->screen.max_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->win = mlx_new_window(vars->mlx, \
		vars->screen.max_x, vars->screen.max_y, "FdF - Duarte");
	draw_img_grid(vars);

}

//falta proteger os ac's
int	main(int ac, char **av)
{
	static t_vars	vars;

	(void) ac;
	vars.mlx = mlx_init();
	vars.map_number = 1;
	vars.max_maps = 0;
	while (av[vars.max_maps] != NULL)
		vars.max_maps++;
	vars.max_maps -= 2;
	printf("%i\n", vars.max_maps);
	vars.map_file = av;
	choose_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, 0);
	mlx_hook(vars.win, 4, 1L << 2, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}


// void	print_map(t_vars *vars)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (vars->map[x])
// 	{
// 		y = 0;
// 		while (y < vars->nb_cols)
// 		{
// 			printf(" %i,", vars->map[x][y]);
// 			y++;
// 		}
// 		printf("\n");
// 		x++;
// 	}
// 	printf("cols: %i\n", vars->nb_cols);
// 	printf("line : %i\n", vars->nb_lines);
// }