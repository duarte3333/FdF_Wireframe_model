/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:10:16 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/02 23:48:12 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Esta funcao irá guardar o maximo elemento z e o minimo nas vars
void	ft_max_and_min(int nb, t_vars *vars)
{	
	if (!vars->max_z || nb > vars->max_z)
	{
		vars->max_z = nb;
	}
	if (!vars->min_z || nb < vars->min_z)
		vars->min_z = nb;
}

//Faco ft_split() da line que recebo
//Conto o size, para saber numero de cols e fazer o malloc()
//Depois, transformo cada elemento do output
//do ft_split() em inteiro usando o ft_atoi()
//Output por exemplo sera: map[i] = {1, 0, 0, 0}
int	*split_array(t_vars *vars, char *line)
{
	int		*t;
	char	**temp;
	int		size;
	int		i;

	size = 0;
	i = 0;
	temp = ft_split(line, ' ');
	while (temp[size])
		size++;
	vars->nb_cols = size;
	t = malloc(sizeof(int) * size);
	while (i < size)
	{
		t[i] = ft_atoi(temp[i]);
		ft_max_and_min(t[i], vars);
		free(temp[i]);
		i++;
	}
	free(temp);
	return (t);
}

//Esta funcao vai recursivamente contar o numero de linhas do ficheiro .txt,
//ou seja, vai "prender a funcao" ate acabar de contar as linhas do ficheiro
// para fazer o malloc do map : map = { "linha1", "linha2", ... } 
//Depois de prender vai acabar o que começou e a cada linha que le, 
//vai fazer ft_split() e transformar o output disso em numero
//Quando chegar ao final do ficheiro, o ultimo elemento do map será NULL
//Output por exemplo sera: map = {{1,0,0,0}, {1,0,1,0}, {0,0,0,0}}
void	map_loading(t_vars *vars, int fd, int index)
{
	char	*line;

	line = get_next_line(fd);
	vars->nb_lines++;
	if (line)
		map_loading(vars, fd, index + 1);
	else
		vars->map = malloc(sizeof(int *) * vars->nb_lines);
	if (line)
		vars->map[index] = split_array(vars, line);
	else
		vars->map[index] = (int *)line;
	free(line);
}
