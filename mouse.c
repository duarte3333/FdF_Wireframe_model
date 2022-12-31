#include "fdf.h"

void	free_mlx(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

//Termina a janela
int	ft_close(void *o)
{
	free_map((t_vars *) o);
	free_mlx((t_vars *) o);
	exit(0);
	return (0);
}

//Coloca todos os pixels a preto para dar refresh 
//caso se desenhe de novo
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

//Executa variacoes com base em acoes do rato
int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	clean_img(vars);
	if (button == 4)
	{
		vars->size_grid += 0.5;
	}
	else if (button == 5)
	{
		if (vars->size_grid > 0.5)
			vars->size_grid -= 0.5;
	}
	else if (button == 1)
	{
		vars->offset_x = x;
		vars->offset_y = y;
	}
	draw_img_grid(vars);
	return (0);
}
