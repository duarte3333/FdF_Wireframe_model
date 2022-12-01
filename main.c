#include "fdf.h"
#include <unistd.h>
#include "X11/X.h"
#include "X11/keysym.h"
#include <stdlib.h>

#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF
#define BLUE_PIXEL 0x0000FF

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	printf("%i\n",keycode);

	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_img(t_data img)
{
	int i;

	i = 100;
	while (i)
	{
		my_mlx_pixel_put(&img, 100, i, 0x00FF0000);
		i--;
	}
}


int	main(void)
{
	t_data	img;
	t_vars	vars;
	t_list 	*a;
	t_point *lpoints;
	t_point	*iso_points;
	char ***map;

    a = ft_extract_map("42.fdf");
    map = parse_matrix(a);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH , WINDOW_HEIGHT, "Hello world!");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (MLX_ERROR);
	}
	img.img = mlx_new_image(vars.mlx, WINDOW_WIDTH , WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
			
	//Hooks
	//mlx_hook(vars.win, 2, 1L<<0, handle_keypress, &vars);
	//mlx_key_hook(vars.win, key_hook, &vars);

	lpoints = ft_create_points(map);
	iso_points = ft_transform_iso(lpoints);
	draw_img_grid(img, iso_points);



	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}