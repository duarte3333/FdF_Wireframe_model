#include "fdf.h"

int **ft_extract_map(char *file)
{
    int **map;
    int fd;
    int i;

    i = 0;
    
    printf("oi");
    fd = open(file, O_RDONLY);
    map[i] = get_next_line(fd);
    while (map[i] != 0)
    {
        map[i] = get_next_line(fd);
        i++;
    }
    close(fd);
    printf("%i", map[0]);
    printf("%i", map[1]);
	return (map);
}
