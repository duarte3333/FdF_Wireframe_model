#include "fdf.h"

int count_digits(char *s)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (s[i])
    {
        if (ft_isdigit(s[i]))
            counter++;
        i++;
    }
    return (counter);
}

void    print_triple_list(char ***tri_list)
{
    int i;
    int j;
    int k;

    i = 0;
    printf("{\n");
    while (tri_list[i])
    {
        printf("[");
        j = 0;
        while (tri_list[i][j])
        {
            k = 0;
            printf("{");
            while (tri_list[i][j][k])
            {
                if (tri_list[i][j][k] != '\n')
                    printf("%c", tri_list[i][j][k]);
                k++;
            }
            printf("}");
            j++;
        }
        i++;
        printf("]\n");
    }
    printf("}\n");
}

t_list *ft_extract_map(char *file)
{
    t_list    *matrix;
    t_list    *new;
    t_list    *tmp;
    int fd;

    fd = open(file, O_RDONLY);

    matrix = ft_lstnew(get_next_line(fd));
    tmp = matrix;
    while (matrix->content)
    {
        new = ft_lstnew((char *)get_next_line(fd));
        ft_lstadd_back(&matrix, new);
        printf("%s\n", matrix->content);
/*         printf("entrei");
        printf("%p\n", matrix->next); */
        matrix = matrix->next;
    }
    close(fd);
    matrix = tmp;
	return (matrix);
}

char ***parse_matrix(t_list *matrix)
{
    char ***map;
    int i;

    i = 0;
    map = (char ***)malloc(sizeof(char **) * (ft_lstsize(matrix)));
    map[ft_lstsize(matrix) - 1] = 0;
    while (matrix->content)
    {
        map[i] = (char **)malloc(sizeof(char *) * (count_digits(matrix->content) + 1));
        map[i][count_digits(matrix->content)] = 0;
        map[i] = ft_split(matrix->content, ' ');
        matrix = matrix->next;
        i++;
    }
    //print_triple_list(map);
	return (map);
}



// int main()
// {
//     t_list *a;
//     a = ft_extract_map("42.fdf");
//     parse_matrix(a);
//     return (0);
// }

