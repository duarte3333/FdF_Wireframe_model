#include "fdf.h"
#include <math.h>

t_point	*ft_lstnew_point(float x, float y, float z)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
    new->prev = NULL;
	return (new);
}

t_point	*ft_lstlast_point(t_point *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_point(t_point **lst, t_point *new)
{
	t_point	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast_point(*lst);
			last->next = new;
            new->prev = *lst;
		}
		else
			*lst = new;
	}
}
t_point *ft_create_points(char ***triple)
{
	int i;
	int j;
	t_point	*point;

	i = 0;
	point = ft_lstnew_point(i, 0, ft_atoi(triple[i][0])); 
    while (triple[i])
	{
		j = 0;
		while (triple[i][j])
		{
			ft_lstadd_back_point(&point, ft_lstnew_point((float)i, (float)(-j), (float)ft_atoi(triple[i][j])));
			printf("(%f, %f)\n", point->x, point->y);
            point = point->next;
            j++;
		}
		i++;
	}
    return (point);
}

t_point *ft_transform_iso(t_point *points)
{
    while (points->prev != NULL)
    {
        points->x = (points->x - points->y) * cos(0.523599);
        points->y = -(points->z) + (points->x + points->y) * sin(0.523599);
        printf("(%f, %f)\n", points->x, points->y);
        points = points->prev;
    }
    return (points);
}