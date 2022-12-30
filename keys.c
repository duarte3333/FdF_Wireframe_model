#include "fdf.h"

void	handle_parte_one(int keysym, t_vars *vars)
{
	if (keysym == 'm' && vars->map_number < vars->max_maps)
		change_map(vars, 1);
	else if (keysym == 'n' && vars->map_number > 2)
		change_map(vars, -1);
	else if (keysym == 'r')
		change_map(vars, 0);
	else if (keysym == '0')
		vars->map_option = 0;
	else if (keysym == 'b')
	{
		vars->angle_x = 1.57;
		vars->angle_y = 0;
	}
	else if (keysym == '9')
		vars->map_option = 1;
	else if (keysym == XK_Escape)
		ft_close(0);
	else if (keysym == 65363 || keysym == 65361 \
		|| keysym == 65364 || keysym == 65362)
		handle_offset(keysym, vars);
	else if (keysym == 'w' || keysym == 's' || keysym == '7' || keysym == '8')
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
	else if (keysym == 121 || keysym == 117)
		handle_projection(keysym, vars);
	else if (keysym == 'i' || keysym == 'k' || keysym == 'j' \
	|| keysym == 'l' || keysym == 'a' || keysym == 'd')
		handle_rotation(keysym, vars);
	draw_img_grid(vars);
	return (0);
}
