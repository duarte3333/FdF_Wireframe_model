#include "fdf.h"

//Esta funcao irá guardar o maximo elemento z e o minimo nas vars
void	ft_max_and_min(int nb, t_vars *vars)
{
	if (!vars->max_z || nb > vars->max_z)
		vars->max_z = nb;
	if (!vars->min_z || nb < vars->min_z)
		vars->min_z = nb;
}

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
	sin(vars->angle_y))) * vars->size_grid + vars->offset_y;
	vars->new_max = vars->max_z;
	if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
	{
		a.z = a.z - vars->min_z + 1;
		vars->new_max = vars->max_z - vars->min_z + 1;
	}
	return (a);
}

//Executa o grid em 2D visto de cima mostrando pelas cores as altitudes em z 
t_point	front_view(t_point a, t_vars *vars)
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

//printf("a.x: %f, a.x %f\n", a.x, a.y);
// t_point parallel_projection(t_point a, t_vars *vars)
// {
// 	float	temp_x;
// 	float	temp_y;

// 	temp_x = a.x;
// 	temp_y = a.y;
// 	a.x = ((temp_x - vars->nb_cols / 2)  * 10 /(a.z - 50   + \ 
//vars->nb_cols / 2)) * vars->size_grid + vars->offset_x - 100;
// 	a.y = ((temp_y - vars->nb_lines / \\
//2)  \ * 10 / (a.z - 50   + vars->nb_lines / 2))
// 		 * vars->size_grid + vars->offset_y - 100;
//     vars->new_max = vars->max_z;
//     if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
//     {
//         a.z = a.z - vars->min_z + 1;
//         vars->new_max = vars->max_z - vars->min_z + 1;
//     }
//return (a);
//}
//projX = (pointX - projectionCenterX) * \ 
//projectionPlaneZ / (pointZ - projectionCenterZ) + projectionCenterX
//projY = (pointY - projectionCenterY) * \ 
// / (pointZ - projectionCenterZ) + projectionCenterY
