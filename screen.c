#include "fdf.h"

void	screen_size(t_vars *vars)
{
	vars->screen.max_x = vars->screen.max_x - vars->screen.min_x;
	vars->screen.max_y = vars->screen.max_y - vars->screen.min_y;
	vars->offset_x = -vars->screen.min_x;
	vars->offset_y = -vars->screen.min_y;
	while ((vars->screen.max_x > WINDOW_WIDTH \
	|| vars->screen.max_y > WINDOW_HEIGHT) && vars->size_grid >= 100)
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