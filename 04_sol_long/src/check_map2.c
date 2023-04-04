#include "get_next_line.h"

void        ft_check_border_line(char *str, t_file *map)
{
    int cols;
    int i;

    cols = map->n_cols;
    i = 0;
    while (i <= (cols - 1))
    {
        if (str[i] != '1')
        {
            map->is_close = -1;
        }
        i++;
    }
}

void        ft_check_middle_lines(char *str, t_file *map)
{
    int cols;

    cols = map->n_cols;
    
    if (str[0] != '1')
    {
        map->is_close = -1;
    }  
    if (str[cols] != '1')
    {
        map->is_close = -1;
    }      
}

void        ft_is_close(char *file, t_file *map)
{
    int		fp;
    char	*line;
    int     rows;

    rows = map->n_rows;
	fp = ft_open_file(file);
    while (rows >= 1)
	{
		line = get_next_line(fp);
		if (rows == 1 || rows == map->n_rows)
            ft_check_border_line(line, map);
        else
            ft_check_middle_lines(line, map);
		free(line);
        rows--;
	}
}