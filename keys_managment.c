#include "fdf.h"

void	ft_close(void *o)
{
	(void) o;
	exit(0);
}

void clean_img(t_vars *vars)
{
	int i;
	int j;

	i = -1;
	while(++i < vars->width)
	{
		j = -1;
		while (++j < vars->height)
			my_mlx_pixel_put(vars, i, j, 0x00000000);
	}
}

int mouse_hook(int button, int x, int y, t_vars *vars)
{   
	clean_img(vars);
	printf("key: %i\n",button);
	float dx;
	float dy;
	float middle_x;
	float middle_y;

	middle_x = vars->middle_point_x;
	middle_y = vars->middle_point_y;
	if (button == 4)
	{
		vars->size_grid += 1;
		dx = x - vars->offset_x;
		dy = y - vars->offset_y;
		printf("dx%f, dy%f\n", dx, dy);
		if (dx > 0 && dy > 0)
		{
			vars->offset_x += 5;
			vars->offset_y += 5;
		}
		else if (dx < 0 && dy > 0)
		{
			vars->offset_x -= 5;
			vars->offset_y += 5;
		}
		else if (dx > 0 && dy < 0)
		{
			vars->offset_x += 5;
			vars->offset_y -= 5;
		}
		else
		{
			vars->offset_x -= 5;
			vars->offset_y -= 5;
		}
	}

	else if (button == 5)
	{
		if (vars->size_grid > 0)
			vars->size_grid -= 1;
		dx = x - vars->offset_x;
		dy = y - vars->offset_y;
		if (dx > 0 && dy > 0)
		{
			vars->offset_x -= 5;
			vars->offset_y -= 5;
		}
		else if (dx < 0 && dy > 0)
		{
			vars->offset_x += 5;
			vars->offset_y -= 5;
		}
		else if (dx > 0 && dy < 0)
		{
			vars->offset_x -= 5;
			vars->offset_y += 5;
		}
		else
		{
			vars->offset_x += 5;
			vars->offset_y += 5;
		}
	}
	else if (button == 1)
	{
		vars->offset_x = x;
		vars->offset_y = y;
	}
	draw_img_grid(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	
}

int handle_offset(int keysym, t_vars *vars)
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

int handle_angles(int keysym, t_vars *vars)
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

int handle_reset(int keysym, t_vars *vars)
{
    vars->size_grid = 15;
    vars->offset_x = 400;
    vars->offset_y = 400;
    vars->angle_y = 0.523599;
    vars->angle_x = 0.523599;
    vars->phi = 0;
    vars->qsi = 0;
    vars->theta = 0;
}

int handle_color(int keysym, t_vars *vars)
{
    if (keysym == 49 && vars->flag < 6)
        vars->flag++;
    else if(keysym == 50 && vars->flag > 1)
        vars->flag--;
}

int handle_rotation(int keysym, t_vars *vars)
{
    if (keysym == 51)
		vars->theta += 0.01;
	else if (keysym == 52)
		vars->theta -= 0.01;
	else if (keysym == 53)
		vars->phi += 0.01;
	else if (keysym == 54)
		vars->phi -= 0.01;
	else if (keysym == 55)
		vars->qsi += 0.01;
	else if (keysym == 56)
		vars->qsi -= 0.01;
}

int	handle_keypress(int keysym, t_vars *vars)
{
	printf("key: %i\n",keysym);
	clean_img(vars);
	if (keysym == XK_Escape)
		ft_close(0);
	else if (keysym == 65363 || keysym == 65361 || keysym == 65364 || keysym == 65362)
        handle_offset(keysym, vars);
	else if (keysym == 119 || keysym == 115 || keysym == 100 || keysym == 97)
        handle_angles(keysym, vars);
	else if (keysym == 114)
        handle_reset(keysym, vars);
	else if (keysym == 49 || keysym == 50)
		handle_color(keysym, vars);
	else if (keysym == 51 || keysym == 52 || keysym == 53 \
    || keysym == 54 || keysym == 55 || keysym == 56) 
		vars->theta += 0.01;
        handle_rotation(keysym, vars);
	draw_img_grid(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}