/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:16 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/31 19:46:09 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Recebo o numero e passo para uma str hexadecimal
void	ft_pointer(long unsigned int number, int *len)
{
	char	*p;

	if (number == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*len) += 2;
		p = ft_itoa_unsigned(number, 16, "0123456789abcdef");
		ft_string(p, len);
		free(p);
	}
}

void	ft_integer(int nb, int *len)
{
	char	*s;

	ft_putnbr_fd(nb, 1);
	s = ft_itoa(nb);
	(*len) += ft_strlen(s);
	free(s);
}

void	ft_unsigned_decimal(unsigned int nb, int *len)
{
	char	*p;

	p = ft_itoa_unsigned(nb, 10, "0123456789");
	ft_string(p, len);
	free(p);
}

void	ft_hex_lower(unsigned int nb, int *len)
{
	char	*p;

	p = ft_itoa_unsigned(nb, 16, "0123456789abcdef");
	ft_string(p, len);
	free(p);
}

void	ft_hex_upper(unsigned int nb, int *len)
{
	char	*p;

	p = ft_itoa_unsigned(nb, 16, "0123456789ABCDEFG");
	ft_string(p, len);
	free(p);
}
