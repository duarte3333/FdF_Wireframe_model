#include "fdf.h"

void draw_img_grid(t_data img, t_point *iso_points)
{
    while (iso_points)
	{
        printf("(%f, %f)\n", iso_points->x, iso_points->y);
        my_mlx_pixel_put(&img, (iso_points->x)*10 + 200, (iso_points->y)*10 + 200, 0x00FF0000);
		iso_points = iso_points->next;
	}
}