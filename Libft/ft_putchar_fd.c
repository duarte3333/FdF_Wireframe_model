/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:52:11 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/24 18:52:11 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Se fd for 0 -> standard input
//Se fd for 1 -> standard output
//Se fd for 2 -> standard error
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
