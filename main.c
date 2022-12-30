#include "fdf.h"

void	ft_set_variables(t_vars *vars)
{
	vars->offset_x = 0;
	vars->offset_y = 0;
	vars->theta = 0;
	vars->phi = 0;
	vars->qsi = 0;
	vars->flag = 4;
	vars->size_grid = 10;
	vars->angle_y = 0.523599;
	vars->angle_x = 0.523599;
	vars->z_modify = 1;
	vars->screen.max_x = 0;
	vars->screen.min_x = 0;
	vars->screen.max_y = 0;
	vars->screen.min_y = 0;
	vars->max_z = 0;
	vars->min_z = 0;
	vars->tranform_number = 1;
}

void	choose_map(t_vars *vars)
{
	int	fd;

	fd = open(vars->map_file[vars->map_number], O_RDONLY);
	ft_set_variables(vars);
	map_loading(vars, fd, 0);
	map_to_point(vars);
	screen_size(vars);

	vars->img.img = \
		mlx_new_image(vars->mlx, vars->screen.max_x, vars->screen.max_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->win = mlx_new_window(vars->mlx, \
		vars->screen.max_x, vars->screen.max_y, "FdF - Duarte");
	mlx_hook(vars->win, 2, 1L << 0, handle_keypress, vars);
	mlx_hook(vars->win, 17, 0, ft_close, 0);
	mlx_hook(vars->win, 4, 1L << 2, mouse_hook, vars);
	draw_img_grid(vars);
}

//falta proteger os ac's
int	main(int ac, char **av)
{
	static t_vars	vars;

	(void) ac;
	vars.mlx = mlx_init();
	vars.map_number = 2;
	vars.max_maps = 0;
	if (av[1][0] == '1')
		vars.map_option = 1;
	while (av[vars.max_maps] != NULL)
		vars.max_maps++;
	vars.max_maps -= 1;
	printf("%i\n", vars.max_maps);
	vars.map_file = av;
	choose_map(&vars);
	mlx_loop(vars.mlx);
}









//fazer check map
//proteger ac av
//adicionar projeções extras
//github prepare

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