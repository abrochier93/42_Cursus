#include "get_next_line.h"

void    ft_print_map(t_file *map)
{
    int x;
    int y = 0;
    
    while (y <= map->n_rows)
    {
        x = 0;
        while (x <= map->n_cols)
        {
            printf("%c", map->map[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}
int     ft_col_size(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return(i);
}

void    ft_is_rectangle(char *str, t_file *map)
{
    int i;

    i = 0;
    if (map->n_cols == 0)
    {    
        map->n_cols = (ft_col_size(str));
        map->n_rows += 1;
    }
    else if (map->n_cols == (ft_col_size(str) - 1)) 
    {   
        map->n_rows += 1;
        while(str[i])
        {
            if(str[i] == 'P')
                map->player_pos.y =  map->n_rows;
            i++;
        }  
    }
    else 
        map->rectangle = -1;
    return ;
}

int     ft_print_message(t_file *map)
{
    if (map->n_player != 1)
        printf("error : player number.\n");
    if (map->n_collect == 0)
        printf("error : there is no collectible.\n");
    if (map->n_exit != 1)
        printf("error : exit number.\n");
    if (map->n_foreign != 0)
        printf("nbr foreign char : %d.\n", map->n_foreign);
    if (map->rectangle == -1)
        printf("map is not rectangle");
    if (map->is_close == -1)
        printf("map is not close");
    if (map->n_player != 1 || map->n_collect == 0 || map->n_exit != 1 || \
        map->n_foreign != 0 || map->rectangle == -1 || map->is_close == -1)
        return (-1);
    return(0);
}

void    ft_check_char(char *str, t_file *map)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        if (str[i] == 'C')
            map->n_collect += 1;
        else if (str[i] == 'P')
        {
            map->player_pos.x = i;
            map->n_player += 1;
        }
        else if (str[i] == 'E')
            map->n_exit += 1;
        else if (str[i] != '1' && str[i] != '0')
            map->n_foreign += 1;
        i++;
    }
}

int	ft_open_file(char *file)
{
	int	fp;

	fp = open(file, O_RDONLY);
	if (fp == -1)
	{
		perror("Error\n");
		exit(0);
	}
	return (fp);
}

int 		ft_check_map(char *file, t_file *map)
{
    int		fp;
    char	*line;
    int     error;

	fp = ft_open_file(file);
    while (1)
	{
		line = get_next_line(fp);
		if (line == NULL || line[0] == '\n' || line[0] == '\0')
			break;
        ft_check_char(line, map);
        ft_is_rectangle(line, map);
		free(line);
	}
    ft_is_close(file, map);
    map->map = ft_create_map(file, map);
    ft_check_path(map);
    error = ft_print_message(map);
    //ft_print_map(map);
    if (error == -1)
        return (-1);
    return(0);
}
