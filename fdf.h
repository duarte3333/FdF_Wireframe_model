/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:29:15 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/11/19 16:48:58 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "Libft/libft.h"
# include "minilibx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;

}				t_vars;

typedef struct	s_point {
	float				x;
	float				y;
	float				z;
	struct s_point	*next;
	struct s_point	*prev;
}				t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 	count_digits(char *s);
void    print_triple_list(char ***tri_list);
t_list 	*ft_extract_map(char *file);
char 	***parse_matrix(t_list *matrix);
t_point	*ft_lstlast_point(t_point *lst);
t_point	*ft_lstnew_point(float x, float y, float z);
void	ft_lstadd_back_point(t_point **lst, t_point *new);
t_point *ft_create_points(char ***triple);
t_point *ft_transform_iso(t_point *points);
void draw_img_grid(t_data img, t_point *iso_points);
char	*get_next_line(int fd);
#endif
