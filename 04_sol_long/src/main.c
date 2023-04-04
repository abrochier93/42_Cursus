#include "get_next_line.h"

void    init_file(t_file *file)
{
    file->map = NULL;
    file->n_collect = 0;
    file->n_player = 0;
    file->n_exit = 0;
    file->n_cols = 0;
    file->n_moves = 0;
    file->n_rows = 0;
    file->n_foreign = 0;
    file->found_collect = 0;
    file->found_exit = 0;
    file->player_pos.x = 0;
    file->player_pos.y = 0;
    file->rectangle = 0;
    file->is_close = 0;
    file->has_a_path = 0;
}

int main(int ac, char **av)
{
    t_file file;
    int map_error;
    (void)ac;
    
    init_file(&file);
    map_error = ft_check_map(av[1], &file);
    if (map_error == -1)
        return(0);
    printf("nombre de cols : %d\nnombre de rows : %d\n", file.n_cols, file.n_rows);
    printf("coordonnées du joueur (x;y) : [%d];[%d]\n", file.player_pos.x, file.player_pos.y);
    free(file.map);
    return (0);
}