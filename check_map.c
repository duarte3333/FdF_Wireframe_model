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

void	check_empty(t_vars *vars, char *line)
{
	if (line == NULL)
	{
		write (1, "Empty file. Try again please.\n", 31);
		ft_close (vars);
	}
}

int	detect_non_digit(t_vars *vars, char *line)
{
	int		size_col;
	int		i;

	i = -1;
	size_col = counter(line);
	i = 0;
	if (size_col == 0)
	{
		write (1, "Detected a line without digits.\n", 32);
		ft_close (vars);
	}
	while (line[i] && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]) \
		&& line[i] != '\t' && line[i] != ' ' && \
		(line[i] == '-' && !ft_isdigit(line[i + 1])))
		{
			write (1, "Detected a non-digit!\n", 22);
			ft_close (vars);
		}
		i++;
	}
	return (size_col);
}

int	check_map_digits(int fd, t_vars *vars)
{
	char	*line;
	int		col_size;
	int		line_size;
	int		size_col;

	line = get_next_line(fd);
	check_empty(vars, line);
	col_size = counter(line);
	line_size = 0;
	while (line != NULL)
	{
		size_col = detect_non_digit(vars, line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL && (line_size == 1 || line_size == 2) \
		&& size_col == 1)
		{
			write (1, "File has only one or two digits vertically.\n", 45);
			ft_close (vars);
		}
	}
	free(line);
	return (1);
}

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
