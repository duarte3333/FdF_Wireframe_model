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

/* Esta funcao permite verificar se o ficheiro é .fdf */
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

/* Esta funcao ou liberta a lista de strings geradas pelo split ou 
invoca o print que diz que detetou um nao digito */
void	free_split(char **temp, int opt, t_vars *vars)
{
	int	i;

	if (opt == 1)
	{
		write (1, "Detected a non-digit!\n", 22);
		ft_close (vars);
	}
	if (opt == 2)
	{
		i = 0;
		while (temp[i])
			free(temp[i++]);
		free(temp);
	}
}