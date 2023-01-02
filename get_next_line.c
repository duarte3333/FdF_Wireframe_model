/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:01:12 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/11/19 16:45:59 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Se a string for NULL retorna 0
//Se a string for vazia retorna 0
//Se a string nao tiver \n retorna o seu size
//Se a string tive \n retorna o seu size + 1
static size_t	ft_strlen_nl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

//Esta funcao recebe duas strings e faz a concatenação de ambas
//ou seja, junta-as
//Enquanto a line existir e a line for diferente de '\0' -> juntar
//Enquanto o buffer for diferente de '\0' -> juntar
//O buffer vai exitir sempre
//Se chegarmos a uma \n damos break pois acabou a line
char	*ft_strjoin(char *s1, char *s2)
{
	int		size_concat;
	char	*concat;
	int		i;
	int		j;

	i = 0;
	j = -1;
	size_concat = ft_strlen_nl(s1) + ft_strlen_nl(s2);
	concat = (char *)malloc(size_concat + 1 * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1 && s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		concat[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	concat[i] = 0;
	free(s1);
	return (concat);
}

//Se o buffer tiver vazio le, caso contrario usa o que tem
//A flag serve para saber quando acabar a limpeza do buffer, 
//isto e, quando o buffer chegar ao \n
//Esta funcao le uma linha de um ficheiro e caso seja chamada 
//novamente, le a linha a seguir da que ja leu.
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;
	int			flag;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer);
		i = 0;
		j = 0;
		while (buffer[i])
		{
			if (flag)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}
