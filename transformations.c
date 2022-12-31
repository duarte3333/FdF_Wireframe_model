#include "fdf.h"

//Executa a projeção isometrica e varia o intervalo dos z's caso sejam negativos
t_point	isometric_projection(t_point a, t_vars *vars)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = ((temp_x - temp_y) * \
		cos(vars->angle_x)) * vars->size_grid + vars->offset_x;
	a.y = ((-(a.z) / vars->z_modify + (temp_x + temp_y) * \
	sin(vars->angle_x))) * vars->size_grid + vars->offset_y;
	vars->new_max = vars->max_z;
	if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
	{
		a.z = a.z - vars->min_z + 1;
		vars->new_max = vars->max_z - vars->min_z + 1;
	}
	return (a);
}

//Executa a projeção paralela e varia o intervalo dos z's caso sejam negativos
t_point	parallel_projection(t_point a, t_vars *vars)
{
	float	temp_z;

	temp_z = a.z;
	a.x = ((a.x - (temp_z / vars->z_modify)) * cos(vars->angle_p)) \
		* vars->size_grid + vars->offset_x;
	a.y = ((a.y - (temp_z / vars->z_modify)) * sin(vars->angle_p)) \
		* vars->size_grid + vars->offset_y;
	vars->new_max = vars->max_z;
	if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
	{
		a.z = a.z - vars->min_z + 1;
		vars->new_max = vars->max_z - vars->min_z + 1;
	}
	return (a);
}

//Executa o grid em 2D visto de cima mostrando pelas cores as altitudes em z 
t_point	top_view(t_point a, t_vars *vars)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = temp_x * vars->size_grid + vars->offset_x;
	a.y = temp_y * vars->size_grid + vars->offset_y;
	vars->new_max = vars->max_z;
	if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
	{
		a.z = a.z - vars->min_z + 1;
		vars->new_max = vars->max_z - vars->min_z + 1;
	}
	return (a);
}

//Executa o grid em 2D visto do lado direito
t_point	right_view(t_point a, t_vars *vars)
{
	float	temp_z;
	float	temp_y;

	temp_z = a.z;
	temp_y = a.y;
	a.x = -temp_y * vars->size_grid + vars->offset_x;
	a.y = ((-temp_z) / vars->z_modify) * vars->size_grid + vars->offset_y;
	vars->new_max = vars->max_z;
	if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
	{
		a.z = a.z - vars->min_z + 1;
		vars->new_max = vars->max_z - vars->min_z + 1;
	}
	return (a);
}

//Executa o grid em 2D visto de baixo
t_point	bottom_view(t_point a, t_vars *vars)
{
	float	temp_z;
	float	temp_x;

	temp_z = a.z;
	temp_x = a.x;
	a.x = temp_x * vars->size_grid + vars->offset_x;
	a.y = ((-temp_z) / vars->z_modify) * vars->size_grid + vars->offset_y;
	vars->new_max = vars->max_z;
	if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
	{
		a.z = a.z - vars->min_z + 1;
		vars->new_max = vars->max_z - vars->min_z + 1;
	}
	return (a);
}
