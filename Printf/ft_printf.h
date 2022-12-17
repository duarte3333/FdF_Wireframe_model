/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:05:16 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/11/02 18:05:16 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "Libft/libft.h"
# include <stddef.h>

void	ft_pointer(long unsigned int number, int *len);
void	ft_integer(int nb, int *len);
void	ft_unsigned_decimal(unsigned int nb, int *len);
void	ft_hex_lower(unsigned int nb, int *len);
void	ft_hex_upper(unsigned int nb, int *len);
void	ft_char(char c, int *len);
void	ft_string(char *str, int *len);
void	ft_percentage(int *len);
int		ft_size_unsigned(long unsigned int nbr, int base_len);
char	*ft_itoa_unsigned(long unsigned int nbr, int base_len, char *base);
void	ft_printvariable(char variable, va_list args, int *size, int *i);
int		ft_printf(const char *string, ...);

#endif
