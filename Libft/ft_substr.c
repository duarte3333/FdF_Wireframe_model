/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:49:28 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 21:49:28 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s - uma str normal
//start - indice do str onde comeca a substr
//len - tamanho da maximo da substr
//Esta funcao vai criar uma substr desde o start ao indice len do s
//sendo o len um indice posterior ao s
//Caso o indice len exceda o tamanho da str s ele acaba a substring
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	char			*temp;

	if (start >= ft_strlen(s))
		substr = malloc(1);
	else if (ft_strlen(s) <= len)
		substr = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	temp = substr;
	while (len && (start <= ft_strlen(s)))
	{
		*substr = s[start];
		substr++;
		start++;
		len--;
	}
	*substr = '\0';
	substr = temp;
	return (substr);
}

// int main()
// {
//     printf("substr: %s\n", ft_substr("lorem ipsum dolor sit amet", 400, 20));
//     printf("substr: %s\n", ft_substr("ABCDEF", 5, 10));
//     printf("substr: %s\n", ft_substr("ABCDEF", 2, 3));
// 	printf("substr: %s\n", ft_substr("tripouille", 1, 1));
// }
