#ifndef SO_LONG

# define SO_LONG

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define SIZE 32

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <errno.h>

typedef struct Maps {
	char	**map;
	void	*mlx;
	void	*win;
	int		n_rows;
	int		n_cols;
	int		moves;
	int		end_game;
	int		enem_n;
	int		p_death;
	int		n_collect;
	int		p_direction;
	int		found_collect;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	void	*r_tile;
}				t_map;

typedef struct Imgs {
	char	*path;
	int		w;
	int		h;
}			t_img;

 typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
  
/* GET NEXT LINE */
typedef struct s_nl
{
	int		rd;
	char	*buf;
	char	*next_line;
	int		nl_pos;
}			t_nl;

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *str);
void		*ft_calloc(size_t count, size_t size);
void		*ft_str_free(void *str);
char		*get_new_line(char *str, int *pos);
void		ft_bzero(void *b, size_t len);

// Map validation
void	ft_validate_map(int file, int *size);
void	ft_check_min_chars(char *line);
int		ft_map_line_length(char *str);
void	ft_check_middle_line(char *line);
void	ft_check_horizontal_border(char *line);
void	ft_check_foreign_chars(char *line);
void	ft_check_map_length(char *line);
void	ft_open_for_validation(char	*file, int *size);

/*ERROR LIST*/
void	ft_no_map_error(void);
void	ft_to_many_map_error(void);
void	ft_extension_error(void);
void	ft_walls_error(void);
void	ft_chars_error(void);
void	ft_rectangular_error(void);
void	ft_file_error(void);
void	ft_exit_error(void);
void	ft_player_error(void);
void	ft_collectible_error(void);

// Saving map
char	**ft_create_bi_array(char *file, int size, t_map *map);

// Rendering map
void	ft_render_map(t_map *map);
void	ft_populate_map(t_map *map, int offset, int start);
int		ft_compare_strings(char *s1, char *s2);
void	ft_render_tile(t_map *map, char *path, int offset);
void	ft_render_rocks(t_map *map, int offset, int index);
void	ft_render_player(t_map *map, int offset, int x, int y);
void	ft_render_exit(t_map *map, int offset, int start);
void	ft_render_collectible(t_map *map, int offset, int start);
char	*ft_itoa(int n);

//  Events
void	ft_listen_events(t_map *map);

// Player movement
void	ft_move_player(t_map *map, int x, int y);
void	ft_swap_tiles(char *tile1, char *tile2);
void	ft_remove_collect(char *player, char *collect);
void	ft_found_exit(char *player, char *collect);
void	ft_check_if_end(t_map *map);
void	ft_enemy_movement(t_map *map);

// Enemy movement
void	ft_kill_player(t_map *map, char *enemy);
void	ft_enemy_up(t_map *map, int *x, int *y, int *direction);
void	ft_enemy_right(t_map *map, int *x, int *y, int *direction);
void	ft_enemy_down(t_map *map, int *x, int *y, int *direction);
void	ft_enemy_left(t_map *map, int *x, int *y, int *direction);

// Text to console
void	ft_put_str(char *str);
void	ft_welcome_player(void);
void	ft_putnbr_fd(int n, int fd);

// Render text
void	ft_end_game(t_map *map);
#endif