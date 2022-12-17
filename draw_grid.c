#include "fdf.h"

//Esta funcao cria uma instancia da struct t_point e aloca o x e y
// t_point init_number(int x, int y, int y_new, t_vars *vars)
// {
//     static t_point new;
//     new.x = ((x - y_new) * cos(vars->angle_x))*vars->size_grid + vars->offset_x;;
//     new.y = ((-(vars->map[y_new][x]) + (x + y_new) * sin(vars->angle_y)))*vars->size_grid + vars->offset_y;
//     new.z = vars->map[y_new][x];
//     new.x = new.x*cos(vars->phi) - new.y*sin(vars->phi); //rotate z
//     new.y = new.x*sin(vars->phi) + new.y*cos(vars->phi);
//     new.x = new.x*cos(vars->theta) + new.z*sin(vars->theta); //rotate y
//     new.z = -new.x*sin(vars->theta) + new.z*cos(vars->theta);
//     new.y = new.y*cos(vars->qsi) + new.z*sin(vars->qsi); //rotate x
//     new.z = -new.y*sin(vars->qsi) + new.z*cos(vars->qsi);
//     my_mlx_pixel_put(&vars->img, new.x, new.y, 0x00FF0000);
//     return (new);
// }

t_point init_point(int x, int y, int z, t_vars *vars)
{
    t_point point;
 
    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

//Esta funcao cria uma lista de listas de t_points
//point_map = {{point1, point2, point3}, {point4, point5, point6}, ... }
//No fundo gera o map sendo que em cada entrada temos um point
void map_to_point(t_vars *vars)
{
    int x;
    int y;
    
    vars->point_map = malloc(sizeof(t_point *) * vars->nb_lines);
    y = -1;
    while (vars->map[++y])
	{
		x = 0;
        vars->point_map[y] = malloc(sizeof(t_point) * vars->nb_cols);
        while (x < vars->nb_cols)
		{
            (vars->point_map)[y][x] = init_point(x, y, vars->map[y][x], vars);
            //printf("%f, %f\n", vars->point_map[y][x].x, vars->point_map[y][x].y);
			x++;
		}
	}
}

//Executa a projeção isometrica e varia o intervalo dos z's caso sejam negativos
t_point isometric_projection(t_point a, t_vars *vars)
{
    int temp_x;
    int temp_y;

    temp_x = a.x;
    temp_y = a.y;
    a.x = temp_x*cos(vars->phi) - temp_y*sin(vars->phi);
    a.y = temp_x*sin(vars->phi) + temp_y*cos(vars->phi);
    temp_x = a.x;
    temp_y = a.y;
    a.x = ((temp_x - temp_y) * cos(vars->angle_x))*vars->size_grid + vars->offset_x;
    a.y = ((-(a.z) + (temp_x + temp_y) * sin(vars->angle_y)))*vars->size_grid + vars->offset_y;
    vars->new_max = vars->max_z;
    if (vars->min_z < 0 || (vars->min_z < 0 && vars->max_z < 0))
    {
        a.z = a.z - vars->min_z + 1;
        vars->new_max = vars->max_z - vars->min_z + 1;
    }
    return (a);
}

void  two_points(t_vars *vars, t_point a, t_point b)
{
    float slope;
    float z_rgb;
    float range;
    int x;

    a = isometric_projection(a, vars);
    b = isometric_projection(b, vars);
    x = a.x;
    slope = (b.y - a.y)/(b.x - a.x);
    z_rgb = a.z/vars->new_max;   
    if (b.z - a.z > 0)
        range = (b.z/vars->new_max- z_rgb);
    else
        range = -(a.z/vars->new_max - b.z/vars->new_max);
    while (x <= b.x)
    {
        z_rgb = z_rgb + range/((vars->size_grid));
        my_mlx_pixel_put(vars, x++, slope*(x - a.x) + a.y, percent_to_color(z_rgb, vars->flag));         
    }
}

t_point rotate(t_point a, t_vars *vars)
{
    int x;
    int y;
    float temp_x;
    float temp_y;
    
    temp_x = a.x;
    temp_y = a.y;
    a.x = temp_x*cos(vars->phi) - temp_y*sin(vars->phi);
    a.y = temp_x*sin(vars->phi) + temp_y*cos(vars->phi);
    return a;
}

void draw_img_grid(t_vars *vars)
{
    int x;
    int y;
    int y_new;
    int x_new;

    y = -1;
	while (++y < vars->nb_lines - 2)
	{
		x = 0;
        while (x < vars->nb_cols - 1)
		{
            y_new = vars->nb_lines - 2 - y;
            two_points(vars, (vars->point_map)[y_new][x] , (vars->point_map)[y_new][x + 1]);
            two_points(vars, (vars->point_map)[y_new][x] , (vars->point_map)[y_new - 1][x]);
            x++;
		}
	}
}

