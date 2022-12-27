#include "fdf.h"

void    screen_dimensions(t_point a, t_vars *vars)
{
    int x;
    int y;

    // a = rotation_z(a, vars);
    // a = rotation_y(a, vars);
    // a = rotation_x(a, vars);
    ft_max_and_min(a.z, vars);
    if (vars->tranform_number == 1)
        a = isometric_projection(a, vars);
    else if (vars->tranform_number == 2)
         a = front_view(a, vars);
    else if (vars->tranform_number == 3)
         a = parallel_projection(a, vars);
        //a = take_off_isometric_projection(a, vars);
    x = a.x;
    y = a.y;
    if (x < vars->screen.min_x && x < 0)
        vars->screen.min_x = x;
    if (y < vars->screen.min_y && y < 0)
        vars->screen.min_y = y;
    if (!vars->screen.max_x || x > vars->screen.max_x  )
        vars->screen.max_x = x;
    if (!vars->screen.max_y|| y > vars->screen.max_y )
        vars->screen.max_y = y;
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
            (vars->point_map)[y][x] = init_point(x, y, vars->map[y][x]);
            screen_dimensions((vars->point_map)[y][x], vars);
            //printf("%f, %f\n", vars->point_map[y][x].x, vars->point_map[y][x].y);
			x++;
		}
	}
}

t_point transformations(t_vars *vars, t_point a)
{
    //a = rotation_x(a, vars);
    //a = rotation_y(a, vars); 
    a = rotation_z(a, vars);
    
    ft_max_and_min(a.z, vars); // qsi 7 e 8 

    //printf("pre: a:%f, b:%f\n", a.x, a.y);
    if (vars->tranform_number == 1)
        a = isometric_projection(a, vars);
    if (vars->tranform_number == 2)
        a = front_view(a, vars);
    if (vars->tranform_number == 3)
        a = parallel_projection(a, vars);
    //printf("proj: a:%f, b:%f\n", a.x, a.y);
    //a = take_off_isometric_projection(a, vars);
    //printf("post: a:%f, b:%f\n", a.x, a.y);
    return (a);
}

void  two_points(t_vars *vars, t_point a, t_point b)
{
    float slope;
    float z_rgb;
    float range;
    float direction;
    float x;
    float y;
    float range_y;

    a = transformations(vars, a);
    b = transformations(vars, b);

    x = a.x;
    z_rgb = a.z/vars->new_max;   
    if (b.z - a.z > 0)
        range = (b.z/vars->new_max- z_rgb);
    else
        range = -(a.z/vars->new_max - b.z/vars->new_max);
    if (fabs(b.x - a.x) == 0)
    {
        //printf("oi");
        y = a.y;
        while (fabs(b.y - y) > 0.5)
        {
            z_rgb = z_rgb + range/((vars->size_grid));
            my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag));  
            y += ((b.y - a.y)/(fabs(b.y - a.y)));
        }
    }
    if (fabs(b.y - a.y) == 0)
    {
        //printf("ola");
        while (fabs(b.x - x) > 0.5)
        { 
            y = a.y;
            z_rgb = z_rgb + range/((vars->size_grid));
            my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag));  
            x += ((b.x - a.x)/(fabs(b.x - a.x)));
        }
    }
    else
    {
        slope = (b.y - a.y)/(b.x - a.x);
        direction = (int)(b.x - a.x)/(fabs(b.x - a.x));
        y = slope*(x - a.x) + a.y;  
        while (fabs(b.x - x) > 0.5)
        { 
            if (b.y - a.y == 0)
                y = a.y;
            else
                y = slope*(x - a.x) + a.y;
            z_rgb = z_rgb + range/((vars->size_grid));
            my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag));  
            range_y = fabs(y - (slope*((x+direction) - a.x) + a.y));
            if (range_y > 1)
            {
                while ((int)(y - (slope*((x+direction) - a.x) + a.y)))
                {
                    if ((b.x - a.x) == 0)
                        y += 1;
                    else
                        y += ((b.y - a.y)/(fabs(b.y - a.y)));
                    my_mlx_pixel_put(vars, x, y, percent_to_color(z_rgb, vars->flag)); 
                }
            }
            x += direction;      
        } 
    }
}

void    ft_menu(t_vars *vars)
{
    if (vars->map_option == 1)
    {
        mlx_string_put(vars->mlx, vars->win, 100, 20,0xAFA9A9,"COMMANDS");
        mlx_string_put(vars->mlx, vars->win, 100, 50,0xAFA9A9,"/\\ - up");
        mlx_string_put(vars->mlx, vars->win, 100, 75,0xAFA9A9,"< - left");
        mlx_string_put(vars->mlx, vars->win, 100, 100,0xAFA9A9,"> - right");
        mlx_string_put(vars->mlx, vars->win, 100, 125,0xAFA9A9,"\\/ - bottom");
        mlx_string_put(vars->mlx, vars->win, 100, 150,0xAFA9A9,"1 - change color forward");
        mlx_string_put(vars->mlx, vars->win, 100, 175,0xAFA9A9,"2 - change color backwards");
        mlx_string_put(vars->mlx, vars->win, 100, 200,0xAFA9A9,"z - decrease z");
        mlx_string_put(vars->mlx, vars->win, 100, 225,0xAFA9A9,"x - increase z");
        mlx_string_put(vars->mlx, vars->win, 100, 250,0xAFA9A9,"SHIFT - z factor = 1:1");
        mlx_string_put(vars->mlx, vars->win, 100, 275,0xAFA9A9,"CTRL - z factor = 1:10");
        mlx_string_put(vars->mlx, vars->win, 100, 300,0xAFA9A9,"w and s - rotation x");
        mlx_string_put(vars->mlx, vars->win, 100, 325,0xAFA9A9,"3 and 4 - rotation x");
        mlx_string_put(vars->mlx, vars->win, 100, 350,0xAFA9A9,"5 and 6 - rotation y");
        mlx_string_put(vars->mlx, vars->win, 100, 375,0xAFA9A9,"7 and 8 - rotation z");
        mlx_string_put(vars->mlx, vars->win, 100, 400,0xAFA9A9,"m - change map");
        mlx_string_put(vars->mlx, vars->win, 100, 425,0xAFA9A9,"r - reset map");
    }
}

void draw_img_grid(t_vars *vars)
{
    int x;
    int y;
    int y_new;

    y = -1;
	while (++y < vars->nb_lines - 1)
	{
		x = 0;
        while (x < vars->nb_cols)
		{
            y_new = vars->nb_lines - 2 - y;
            if (x < vars->nb_cols - 1)
                two_points(vars, (vars->point_map)[y_new][x] , (vars->point_map)[y_new][x + 1]);
            if (y < vars->nb_lines - 2)
                two_points(vars, (vars->point_map)[y_new][x] , (vars->point_map)[y_new - 1][x]);
            x++;
            
		}
	}
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    ft_menu(vars);
	//mlx_string_put(vars->mlx, vars->win, 500, 500,0xFFFFFF,"Hello");
}

