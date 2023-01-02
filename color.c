/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:17:46 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/02 18:22:59 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || y < 0 || x >= vars->screen.max_x || y >= vars->screen.max_y))
	{
		dst = vars->img.addr + (y * vars->img.line_length + \
		x * (vars->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	make_color(float percent, int flag, int r, int g)
{
	if (flag == 0)
		return (create_trgb(0, 255, 255, 255));
	else if (flag == 1)
		return (create_trgb(0, percent * 255, 0, 0));
	else if (flag == 2)
		return (create_trgb(0, 0, percent * 255, 0));
	else if (flag == 3)
		return (create_trgb(0, 0, 0, percent * 255));
	else if (flag == 4)
		return (create_trgb(0, g, r, 0));
	else if (flag == 5)
		return (create_trgb(0, 0, r, g));
	else if (flag == 6)
		return (create_trgb(0, g, 0, r));
	else if (flag == 7)
		return (create_trgb(0, r, g, g));
	else if (flag == 8)
		return (create_trgb(0, g, r, g));
	else if (flag == 9)
		return (create_trgb(0, g / 3, r / 0.5, r / 1.25));
	return (0);
}

//0    -> (0,     0,     0)
//0.25 -> (255,   127.5, 0)
//0.49 -> (255,   255,   0)
//0.5  -> (255,   255,   0)
//0.75 -> (127,5, 255,   0)
//1    -> (0,     255,   0)
//Mais perto de 0.5, mais perto de (255, 255, 0)
//Mais perto de 1, mais perto de (0,255, 0)
int	percent_to_color(float percent, int flag)
{
	int	r;
	int	g;

	r = 255;
	g = 255;
	if (flag >= 4 && flag <= 9)
	{
		if (percent < 0.5)
			g = (255 * percent / 0.5);
		else
			r = 255 - (255 * (percent - 0.5) / 0.5);
		return (make_color(percent, flag, r, g));
	}
	else
		return (make_color(percent, flag, 0, 0));
}
