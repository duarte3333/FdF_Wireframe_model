/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:12:04 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/02 23:49:08 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Check if the file is empty */
void	check_empty(t_vars *vars, char *line)
{
	if (line == NULL)
	{
		write (1, "Empty file. Try again please.\n", 31);
		ft_close (vars);
	}
}

/* Detete caracteres que nao sejam digitos 
Ele deixa passar se a seguir ao numero estiver uma virgula
para o caso dos mapas com cores incorporadas*/
int	detect_non_digit(t_vars *vars, char *line)
{
	char	**temp;
	int		i;
	int		col_size;

	col_size = 0;
	if (!line)
		return (0);
	temp = ft_split(line, ' ');
	while (temp[col_size])
	{
		i = 0;
		while (temp[col_size][i] && temp[col_size][i] != '\n')
		{
			if (temp[col_size][i] == ',')
				break ;	
			if (temp[col_size][i] == '-' && i == 0)
				i++;
			if (!ft_isdigit(temp[col_size][i]))
				free_split(temp, 1, vars);	
			i++;
		}
		col_size++;
	}
	free_split(temp, 2, vars);
	return (col_size);
}

/* Verifica se existem caracteres nao autorizados no mapa */
int	check_map_digits(int fd, t_vars *vars)
{
	char	*line;
	int		col_size;
	int		line_size;
	int		size_col;

	line = get_next_line(fd);
	check_empty(vars, line);
	col_size = detect_non_digit(vars, line);
	line_size = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			size_col = detect_non_digit(vars, line);
		if (col_size != size_col)
		{
			free(line);
			write (1, "The map is neither square nor rectangular.\n", 44);
			exit(0);
		}
	}
	free(line);
	return (1);
}

/* Verifica todas as possibilidades para que o mapa pode falhar */
int	check_map(t_vars *vars)
{
	int	fd;

	if (!strcmp_fdf(vars->map_file[vars->map_number]))
	{
		write(1, "That file is not a .fdf file\n", 30);
		ft_close (vars);
	}
	else
	{
		fd = open(vars->map_file[vars->map_number], O_RDONLY);
		if (fd == -1)
		{
			write(1, "That file is not in the repository.\n", 37);
			ft_close (vars);
		}
		else if (check_map_digits(fd, vars))
		{
			close(fd);
			fd = open(vars->map_file[vars->map_number], O_RDONLY);
		}
		return (fd);
	}
	return (0);
}
