#include "fdf.h"

float draw_line(t_point *iso_points)
{
    int nb_lines;
    int nb_columns;

    nb_lines = 10;
    nb_columns = 17;
    float end_y;
    float begin_y;
    float end_x;
    float begin_x;
    float slope;
    
    begin_y = iso_points->y;
    begin_x = iso_points->x;
    while (iso_points)
    {
        if (nb_lines == 0)
            break;
        iso_points = iso_points->next;
        nb_lines--;
    }
    end_y = iso_points->y;
    end_x = iso_points->x;
    slope = (end_y - begin_y)/(end_y - begin_x);

    return (slope, begin_x, end_y);
}
void draw_img_grid(t_data img, t_point *iso_points)
{
    float slope;
    float begin_x;
    float end_y;

    while (iso_points)
	{
        //printf("(%f, %f)\n", iso_points->x, iso_points->y);
        my_mlx_pixel_put(&img, (iso_points->x)*10 + 200, (iso_points->y)*10 + 200, 0x00FF0000);
        slope, begin_x, end_y = draw_line(iso_points);

		my_mlx_pixel_put(&img, (iso_points->x)*10 + 200, (slope*(iso_points->x - begin_x))*10 + 200, 0x00FFFFFF);
        iso_points = iso_points->next;
	}
}


