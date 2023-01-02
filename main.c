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
	vars->angle_p = 0.7854;
	vars->z_modify = 1;
	vars->screen.max_x = 0;
	vars->screen.min_x = 0;
	vars->screen.max_y = 0;
	vars->screen.min_y = 0;
	vars->max_z = 0;
	vars->min_z = 0;
	vars->tranform_number = 1;
}

int	strcmp_fdf(char *a)
{
	int		i;
	int		j;
	char	*b;

	b = ".fdf";
	i = 0;
	j = -1;
	while (a[i] != 0)
		i++;
	i -= 5;
	while (a[++i] != 0)
	{
		if (a[i] != b[++j])
			return (0);
	}
	return (1);
}

int	check_map_digits(int fd)
{
	int		i;
	char	*line;
	char	*temp;

	temp = line;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			if (!ft_isdigit(line[i]) && line[i] != '\t' && line[i] != ' ')
			{
				write (1, "Detected a non-digit\n", 22);
				return (0);
			}
			i++;
		}
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("SOU NULL\n");
			break ;
		}
		printf("line%s\n", line);
	}
	printf("oita");
	free(line);
	return (1);
}

int	check_map_digits_r(int fd)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		i = 0;
		while (line[i] != NULL && line[i] != '\n')
		{
			if (!ft_isdigit(line[i]) && line[i] != '\t' \
			&& line[i] != ' ' && line)
			{
				write (1, "Detected a non-digit\n", 22);
				return (0);
			}
			i++;
		}
		printf("line%s\n", line);
		check_map_digits_r(fd);
	}
	else
	{
		printf("adeus\n");
	}
	free(line);
	return (1);
}

int	check_map(t_vars *vars)
{
	int	fd;

	if (!strcmp_fdf(vars->map_file[vars->map_number]))
	{
		write(1, "That file is not a .fdf file\n", 30);
		ft_close (vars);
	}
	else
	{
		fd = open(vars->map_file[vars->map_number], O_RDONLY);
		if (fd == -1)
		{
			write(1, "That file is not in the repository.\n", 37);
			ft_close (vars);
		}
		// else if (!check_map_digits(fd))
		// {
		// 	write(1, "That file has non-digits, please change that.\n", 47);
		// 	ft_close (vars);
		// }
		// printf("saiu");
	}
	return (fd);
}

//Cria uma janela, uma imagem e desenha para um dado mapa
void	choose_map(t_vars *vars)
{
	int	fd;

	fd = check_map(vars);
	ft_set_variables(vars);
	map_loading(vars, fd, 0);
	map_to_point(vars);
	screen_size(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = \
		mlx_new_image(vars->mlx, vars->screen.max_x, vars->screen.max_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->win = mlx_new_window(vars->mlx, \
		vars->screen.max_x, vars->screen.max_y, "FdF - Duarte");
	mlx_hook(vars->win, 2, 1L << 0, handle_keypress, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_hook(vars->win, 4, 1L << 2, mouse_hook, vars);
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
	vars.map_option = 1;
	while (av[vars.max_maps] != NULL)
		vars.max_maps++;
	vars.map_file = av;
	choose_map(&vars);
	mlx_loop(vars.mlx);
}



//fazer check map e nome do ficheiro
//proteger ac av
//github prepare

//quando chegar:
//verificar teclas
//header

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