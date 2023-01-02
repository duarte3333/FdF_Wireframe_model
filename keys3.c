/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:18:34 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/02 18:18:36 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_projection(int keysym, t_vars *vars)
{
	if (keysym == 121 && vars->tranform_number < 5)
		vars->tranform_number++;
	else if (keysym == 117 && vars->tranform_number > 1)
		vars->tranform_number--;
	else if (keysym == '3')
	{
		vars->map_option = vars->map_option == 0;
		change_map(vars, 0);
	}
}

void	handle_z(int keysym, t_vars *vars)
{
	if (keysym == 122 && vars->z_modify < 20)
		vars->z_modify += 0.1;
	else if (keysym == 120 && vars->z_modify > 0.2)
		vars->z_modify -= 0.1;
	else if (keysym == 65289)
		vars->z_modify = 100;
	else if (keysym == 65507)
		vars->z_modify = 10;
	else if (keysym == 65505)
		vars->z_modify = 1;
}

void	free_map(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map && vars->map[++i])
	{
		free(vars->map[i]);
		free(vars->point_map[i]);
	}
	free(vars->map);
	free(vars->point_map);
	vars->map = NULL;
	vars->point_map = NULL;
}

int	change_map(t_vars *vars, int i)
{
	vars->map_number = vars->map_number + i;
	vars->nb_cols = 0;
	vars->nb_lines = 0;
	free_map(vars);
	choose_map(vars);
	return (0);
}
