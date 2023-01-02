/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:17:24 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/02 23:51:02 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Estas funcoes usam a mlx_string_put() para escrever os comandos
//possiveis do programa

void	projection_type(t_vars *vars)
{
	int	s;
	int	y;

	s = WINDOW_WIDTH - 125;
	y = 100;
	mlx_string_put(vars->mlx, vars->win, s, 80, 0xAFA9A9, "PROJECTION TYPE");
	if (vars->tranform_number == 1)
	{
		mlx_string_put(vars->mlx, vars->win, s, y, \
		0xAFA9A9, "Isometric Projection");
	}
	else if (vars->tranform_number == 2)
	{
		mlx_string_put(vars->mlx, vars->win, s, \
		100, 0xAFA9A9, "Parallel Projection");
	}
	else if (vars->tranform_number == 3)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "Top View");
	else if (vars->tranform_number == 4)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "Right View");
	else if (vars->tranform_number == 5)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "Bottom View");
	mlx_string_put(vars->mlx, vars->win, 100, 20, 0xAFA9A9, "COMMANDS");
	mlx_string_put(vars->mlx, vars->win, 100, 50, 0xAFA9A9, "/\\ - up");
}

void	ft_part_one(t_vars *vars)
{
	projection_type (vars);
	mlx_string_put(vars->mlx, vars->win, 100, 75, 0xAFA9A9, "< - left");
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0xAFA9A9, "> - right");
	mlx_string_put(vars->mlx, vars->win, 100, 125, 0xAFA9A9, "\\/ - bottom");
	mlx_string_put(vars->mlx, vars->win, 100, 150, 0xAFA9A9, \
	"1 - change color forward");
	mlx_string_put(vars->mlx, vars->win, 100, 175, 0xAFA9A9, \
	"2 - change color backwards");
	mlx_string_put(vars->mlx, vars->win, 100, 200, 0xAFA9A9, \
	"z and x - decrease/increase z");
	mlx_string_put(vars->mlx, vars->win, 100, 225, 0xAFA9A9, \
		"SHIFT - z factor = 1:1");
	mlx_string_put(vars->mlx, vars->win, 100, 250, 0xAFA9A9, \
		"CTRL - z factor = 1:10");
	mlx_string_put(vars->mlx, vars->win, 100, 275, 0xAFA9A9, \
		"TAB - z factor = 1:100");
	mlx_string_put(vars->mlx, vars->win, 100, 300, 0xAFA9A9, \
		"w and s - rotation parallel x");
	mlx_string_put(vars->mlx, vars->win, 100, 325, 0xAFA9A9, \
		"a and d - rotation z");
	mlx_string_put(vars->mlx, vars->win, 100, 350, 0xAFA9A9, \
		"i and k - rotation x");
	mlx_string_put(vars->mlx, vars->win, 100, 375, 0xAFA9A9, \
		"j and l - rotation y");
}

void	ft_menu(t_vars *vars)
{
	if (vars->map_option == 1)
	{
		ft_part_one(vars);
		mlx_string_put(vars->mlx, vars->win, 100, 400, 0xAFA9A9, \
		"7 and 8 - rotation parallel y");
		mlx_string_put(vars->mlx, vars->win, 100, \
			425, 0xAFA9A9, "mouse click - grid location");
		mlx_string_put(vars->mlx, vars->win, 100, \
			450, 0xAFA9A9, "y and u - change projection");
		mlx_string_put(vars->mlx, vars->win, 100, 475, 0xAFA9A9, \
		"9 and 0 - menu change");
		mlx_string_put(vars->mlx, vars->win, 100, \
			500, 0xAFA9A9, "3 and 4 - change mode");
		mlx_string_put(vars->mlx, vars->win, 100, 525, 0xAFA9A9, \
		"m - change map");
		mlx_string_put(vars->mlx, vars->win, 100, \
			550, 0xAFA9A9, "r - reset map");
		mlx_string_put(vars->mlx, vars->win, WINDOW_WIDTH - 125, \
			20, 0xAFA9A9, "MAP NAME");
		mlx_string_put(vars->mlx, vars->win, WINDOW_WIDTH - 125, \
			40, 0xAFA9A9, vars->map_file[vars->map_number]);
		mlx_string_put(vars->mlx, vars->win, 100, \
			WINDOW_HEIGHT - 25, 0xAFA9A9, "By: Duarte Morais");
	}
}
