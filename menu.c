#include "fdf.h"

//Estas funcoes usam a mlx_string_put() para escrever os comandos
//possiveis do programa
void	ft_part_one(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 100, 20, 0xAFA9A9, "COMMANDS");
	mlx_string_put(vars->mlx, vars->win, 100, 50, 0xAFA9A9, "/\\ - up");
	mlx_string_put(vars->mlx, vars->win, 100, 75, 0xAFA9A9, "< - left");
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0xAFA9A9, "> - right");
	mlx_string_put(vars->mlx, vars->win, 100, 125, 0xAFA9A9, "\\/ - bottom");
	mlx_string_put(vars->mlx, vars->win, 100, 150, 0xAFA9A9, \
	"1 - change color forward");
	mlx_string_put(vars->mlx, vars->win, 100, 175, 0xAFA9A9, \
	"2 - change color backwards");
	mlx_string_put(vars->mlx, vars->win, 100, 200, 0xAFA9A9, \
	"z - decrease z");
	mlx_string_put(vars->mlx, vars->win, 100, 225, 0xAFA9A9, \
		"x - increase z");
	mlx_string_put(vars->mlx, vars->win, 100, 250, 0xAFA9A9, \
		"SHIFT - z factor = 1:1");
	mlx_string_put(vars->mlx, vars->win, 100, 275, 0xAFA9A9, \
		"CTRL - z factor = 1:10");
}

void	ft_menu(t_vars *vars)
{
	if (vars->map_option == 1)
	{
		ft_part_one(vars);
		mlx_string_put(vars->mlx, vars->win, 100, 300, 0xAFA9A9, \
		"w and s - rotation parallel x");
		mlx_string_put(vars->mlx, vars->win, 100, 325, 0xAFA9A9, \
		"a and d - rotation parallel y");
		mlx_string_put(vars->mlx, vars->win, 100, 350, 0xAFA9A9, \
		"3 and 4 - rotation x");
		mlx_string_put(vars->mlx, vars->win, 100, 375, 0xAFA9A9, \
		"5 and 6 - rotation y");
		mlx_string_put(vars->mlx, vars->win, 100, 400, 0xAFA9A9, \
		"7 and 8 - rotation z");
		mlx_string_put(vars->mlx, vars->win, 100, 425, 0xAFA9A9, \
		"m - change map");
		mlx_string_put(vars->mlx, vars->win, 100, \
			450, 0xAFA9A9, "r - reset map");
		mlx_string_put(vars->mlx, vars->win, 100, \
			475, 0xAFA9A9, "mouse click - grid location");
		mlx_string_put(vars->mlx, vars->win, 100, \
			500, 0xAFA9A9, "y and u - change projection");
	}
}
