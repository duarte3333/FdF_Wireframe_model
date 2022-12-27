#include "fdf.h"

t_point init_point(int x, int y, int z)
{
    t_point point;
 
    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

t_point rotation_x(t_point a, t_vars *vars)
{
    float temp_z;
    float temp_y;

    temp_z = a.z;
    temp_y = a.y;
    a.y = temp_y*cos(vars->theta) + temp_z*sin(vars->theta); //rotate x
    a.z = -temp_y*sin(vars->theta) + temp_z*cos(vars->theta);
    return (a);
}

t_point rotation_y(t_point a, t_vars *vars)
{
    float temp_x;
    float temp_z;

    temp_x = a.x;
    temp_z = a.z;
    a.x = temp_x*cos(vars->phi) + temp_z*sin(vars->phi); //rotate y
    a.z = -temp_x*sin(vars->phi) + temp_z*cos(vars->phi);
    return (a);
}
t_point rotation_z(t_point a, t_vars *vars)
{
    float temp_x;
    float temp_y;

    temp_x = a.x;
    temp_y = a.y;
    a.x = temp_x*cos(vars->qsi) - temp_y*sin(vars->qsi);
    a.y = temp_x*sin(vars->qsi) + temp_y*cos(vars->qsi);
    return (a);
}



//Executa a projeção isometrica e varia o intervalo dos z's caso sejam negativos
t_point isometric_projection(t_point a, t_vars *vars)
{
    float temp_x;
    float temp_y;

    //a = rotation_z(a, vars);
    temp_x = a.x;
    temp_y = a.y;
    a.x = ((temp_x - temp_y) * cos(vars->angle_x))*vars->size_grid + vars->offset_x;
    a.y = ((-(a.z)/vars->z_modify + (temp_x + temp_y) * sin(vars->angle_y)))*vars->size_grid + vars->offset_y;
    vars->new_max = vars->max_z;
    if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
    {
        a.z = a.z - vars->min_z + 1;
        vars->new_max = vars->max_z - vars->min_z + 1;
    }
    return (a);
}

t_point front_view(t_point a, t_vars *vars)
{
    float temp_x;
    float temp_y;

    //a = rotation_z(a, vars);
    temp_x = a.x;
    temp_y = a.y;
    a.x = temp_x*vars->size_grid + vars->offset_x;
    a.y = temp_y*vars->size_grid + vars->offset_y;
    vars->new_max = vars->max_z;
    if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
    {
        a.z = a.z - vars->min_z + 1;
        vars->new_max = vars->max_z - vars->min_z + 1;
    }
    return (a);
}

t_point parallel_projection(t_point a, t_vars *vars)
{
    float temp_x;
    float temp_y;

    //printf("oi");
    //a = rotation_z(a, vars);
    temp_x = a.x;
    temp_y = a.y;
    //printf("cols: %i\n", vars->nb_cols/2);
    //printf("lines: %i\n", vars->nb_lines/2);
    a.x = ((temp_x - vars->nb_cols/2)  * 10 / (a.z - 50   + vars->nb_cols/2))*vars->size_grid + vars->offset_x - 100;
    a.y = ((temp_y - vars->nb_lines/2)  * 10 / (a.z - 50   + vars->nb_lines/2))*vars->size_grid + vars->offset_y - 100;
    printf("a.x: %f, a.x %f\n", a.x, a.y);
    vars->new_max = vars->max_z;
    if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
    {
        a.z = a.z - vars->min_z + 1;
        vars->new_max = vars->max_z - vars->min_z + 1;
    }
    return (a);
}
//projX = (pointX - projectionCenterX) * projectionPlaneZ / (pointZ - projectionCenterZ) + projectionCenterX
//projY = (pointY - projectionCenterY) * projectionPlaneZ / (pointZ - projectionCenterZ) + projectionCenterY

//Esta funcao irá guardar o maximo elemento z e o minimo nas vars
void   ft_max_and_min(int nb, t_vars *vars)
{
    if (!vars->max_z || nb > vars->max_z)
        vars->max_z = nb;
    if (!vars->min_z || nb < vars->min_z)
        vars->min_z = nb;
}