/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:37:54 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 21:37:54 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Esta funcao recebe duas strings e faz a concatenação de ambas
//ou seja, junta-as
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_concat;
	char	*concat;
	char	*temp;

	size_concat = ft_strlen(s1) + ft_strlen(s2);
	concat = (char *)malloc((size_concat + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	concat[size_concat] = 0;
	temp = concat;
	while (*s1)
	{
		*concat = *s1;
		concat++;
		s1++;
	}
	while (*s2)
	{
		*concat = *s2;
		concat++;
		s2++;
	}
	concat = temp;
	return (concat);
}
// int main()
// {
// 	printf("%s", ft_strjoin("ola","banana"));
// }
// int	main(void)
// {
// 	char	**strs;
// 	char	*separator;
// 	char	*result;
// 	int	size;

// 	size = 3;
// 	strs = (char **)malloc(3 * sizeof(char *));
// 	strs[0] = (char *)malloc(sizeof(char) * 5 + 1);
// 	strs[1] = (char *)malloc(sizeof(char) * 7 + 1);
// 	strs[2] = (char *)malloc(sizeof(char) * 14 + 1);
// 	strs[0] = "Hello";
// 	strs[1] = "friend,";
// 	strs[2] = "you are awesome";
// 	separator = "BOY";
// 	result = ft_strjoin(size, strs, separator);
// 	printf("%s$\n", result);
// 	free(result);
// }
