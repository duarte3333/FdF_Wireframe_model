/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:50:07 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/02 23:50:17 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	strcmp_fdf(char *a)
{
	int		i;
	int		j;
	char	*b;

	b = ".fdf";
	i = 0;
	j = -1;
	while (a[i] != 0)
		i++;
	i -= 5;
	while (a[++i] != 0)
	{
		if (a[i] != b[++j])
			return (0);
	}
	return (1);
}

int	counter(char *line)
{
	char	**temp;
	int		i;
	int		col_size;

	col_size = 0;
	i = -1;
	temp = ft_split(line, ' ');
	while (temp[col_size])
		col_size++;
	while (++i < col_size)
	{
		free(temp[i]);
	}
	free(temp);
	return (col_size);
}
