#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	if (!(x < 0 || y < 0 || x >= vars->width|| y >= vars->height))
	{
		dst = vars->img.addr + (y * vars->img.line_length + x * (vars->img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	print_map(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (y < vars->nb_cols)
		{
			printf(" %i,", vars->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("cols: %i\n", vars->nb_cols);
    printf("line : %i\n", vars->nb_lines);	
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
	vars->middle_point_x = vars->last_x - vars->offset_x;
	vars->middle_point_y = vars->last_x - vars->offset_x;
	vars->width = vars->nb_cols*vars->size_grid*2;
	vars->height = vars->nb_lines*vars->size_grid*2;
}

int	main(int ac, char **av)
{
	static t_vars	vars;
	int	fd;

	fd = open(av[1], O_RDONLY);
	map_loading(&vars, fd, 0);
	ft_set_variables(&vars);
	map_to_point(&vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "FdF - Duarte");
	vars.img.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								&vars.img.endian);
	mlx_hook(vars.win, 2, 1L<<0, handle_keypress, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, 0);
	mlx_hook(vars.win, 4, 1L<<2, mouse_hook, &vars);

	draw_img_grid(&vars);

	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}

// if (vars.mlx == NULL)
// 	return (MLX_ERROR);

// if (vars.win == NULL)
// {
// 	free(vars.win);
// 	return (MLX_ERROR);
// }