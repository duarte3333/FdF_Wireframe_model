/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:25:48 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/31 19:46:18 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Nao existe hexadecimais negativos

void	ft_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

//Se o input for um valor invalido, o printf dá print de null
void	ft_string(char *str, int *len)
{
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
		(*len)++;
	}
}

void	ft_percentage(int *len)
{
	write(1, "%%", 1);
	(*len)++;
}
