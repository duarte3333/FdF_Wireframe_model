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
	if (button == 4)
	{
		vars->size_grid += 1;
	}
	else if (button == 5)
	{
		if (vars->size_grid > 1)
			vars->size_grid -= 1;
	}
	else if (button == 1)
	{
		vars->offset_x = x;
		vars->offset_y = y;
	}
	draw_img_grid(vars);
	return (0);
}
