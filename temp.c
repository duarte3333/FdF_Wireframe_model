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