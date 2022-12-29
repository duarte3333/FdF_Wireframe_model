#include "fdf.h"

void	handle_parte_one(int keysym, t_vars *vars)
{
	if (keysym == 'm' && vars->map_number < vars->max_maps)
		change_map(vars, 1);
	else if (keysym == 'n' && vars->map_number > 2)
		change_map(vars, -1);
	else if (keysym == 'r')
		change_map(vars, 0);
	else if (keysym == XK_Escape)
		ft_close(0);
	else if (keysym == 65363 || keysym == 65361 \
		|| keysym == 65364 || keysym == 65362)
		handle_offset(keysym, vars);
	else if (keysym == 119 || keysym == 115 || keysym == 100 || keysym == 97)
		handle_angles(keysym, vars);
}

//printf("%s\n", vars->map_file[vars->map_number]);
//printf("%i\n", keysym);
int	handle_keypress(int keysym, t_vars *vars)
{
	clean_img(vars);

	handle_parte_one(keysym, vars);
	if (keysym == 49 || keysym == 50)
		handle_color(keysym, vars);
	else if (keysym == 122 || keysym == 120 \
	|| keysym == 65507 || keysym == 65505 || keysym == 65289)
		handle_z(keysym, vars);
	else if (keysym == 'g')
		vars->size_grid = 1;
	else if (keysym == 121 || keysym == 117 || keysym == 105 || keysym == 111)
		handle_projection(keysym, vars);
	else if (keysym == 51 || keysym == 52 || keysym == 53 \
	|| keysym == 54 || keysym == 55 || keysym == 56)
		handle_rotation(keysym, vars);
	draw_img_grid(vars);
	return (0);
}
