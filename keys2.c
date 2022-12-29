#include "fdf.h"

void	handle_offset(int keysym, t_vars *vars)
{
	if (keysym == 65363)
		vars->offset_x += 30;
	else if (keysym == 65361)
		vars->offset_x -= 30;
	else if (keysym == 65364)
		vars->offset_y += 30;
	else if (keysym == 65362)
		vars->offset_y -= 30;
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
	vars->size_grid = 10;
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
}

//x->theta; y->phi; z->qsi;
void	handle_rotation(int keysym, t_vars *vars)
{
	if (keysym == 51)
		vars->theta -= 0.03;
	else if (keysym == 52)
		vars->theta += 0.03;
	else if (keysym == 53)
		vars->phi += 0.03;
	else if (keysym == 54)
		vars->phi -= 0.03;
	else if (keysym == 55)
		vars->qsi += 0.03;
	else if (keysym == 56)
		vars->qsi -= 0.03;
}
