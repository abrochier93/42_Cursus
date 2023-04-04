
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct File {
	char		**map;
	int			n_rows;
	int			n_cols;
	int			n_moves;
	int			n_collect;
	int			n_player;
	int			n_exit;
	int			n_foreign;
	int			found_collect;
	int			found_exit;
	t_point		player_pos;
	int			rectangle;
	int			is_close;
	int			has_a_path;
}				t_file;


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

int 		ft_check_map(char *file, t_file *map);
void        ft_is_close(char *file, t_file *map);
int			ft_open_file(char *file);
char		**ft_create_map(char *file, t_file *map);
char		*ft_strdup(const char *s1);
void		ft_check_path(t_file *map);
void    	ft_print_map(t_file *map);
#endif