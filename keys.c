/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:18:17 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/02 18:22:39 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Estas sao as funcoes responsaveis pelo gerenciamento de teclas

void	handle_parte_one(int keysym, t_vars *vars)
{
	if (keysym == 'm' && vars->map_number < vars->max_maps - 1)
		change_map(vars, 1);
	else if (keysym == 'n' && vars->map_number > 1)
		change_map(vars, -1);
	else if (keysym == 'r')
		change_map(vars, 0);
	else if (keysym == XK_Escape)
		ft_close(vars);
	else if (keysym == 65363 || keysym == 65361 \
	|| keysym == 65364 || keysym == 65362)
		handle_offset(keysym, vars);
	else if (keysym == 'w' || keysym == 's' || keysym == '7' || keysym == '8' \
	|| keysym == 'b' || keysym == 'v')
		handle_angles(keysym, vars);
}

//printf("%s\n", vars->map_file[vars->map_number]);
//printf("%i\n", keysym);
int	handle_keypress(int keysym, t_vars *vars)
{
	clean_img(vars);
	handle_parte_one(keysym, vars);
	if (keysym == 49 || keysym == 50 || keysym == '0' || keysym == '9')
		handle_color(keysym, vars);
	else if (keysym == 122 || keysym == 120 \
	|| keysym == 65507 || keysym == 65505 || keysym == 65289)
		handle_z(keysym, vars);
	else if (keysym == 'g')
		vars->size_grid = 1;
	else if (keysym == 121 || keysym == 117 || keysym == '3')
		handle_projection(keysym, vars);
	else if (keysym == 'i' || keysym == 'k' || keysym == 'j' \
	|| keysym == 'l' || keysym == 'a' || keysym == 'd')
		handle_rotation(keysym, vars);
	draw_img_grid(vars);
	return (0);
}
