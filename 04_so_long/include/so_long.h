/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:57:04 by abrochie          #+#    #+#             */
/*   Updated: 2023/03/31 14:57:04 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# include <errno.h>
# include "../lib/libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_img
{
	int	w;
	int	h;
}				t_img;

typedef struct File {
	char			**map;
	int				n_rows;
	int				n_cols;
	int				n_moves;
	int				n_collect;
	int				n_player;
	int				n_exit;
	int				n_foreign;
	int				found_collect;
	int				found_exit;
	t_point			p_pos;
	int				rectangle;
	int				is_close;
	int				has_a_path;
	mlx_t			*mlx;
	double			time_next_move;
	int				game_is_finish;
	mlx_image_t		*txt_collect_count;
	mlx_image_t		*txt_collect;
	mlx_image_t		*txt_move_count;
	mlx_image_t		*txt_move;
	mlx_image_t		*exit_img;
	mlx_image_t		*player_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*floor_img;
	mlx_image_t		*collect_img;
	mlx_texture_t	*collect_text;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
}				t_file;

int			main(int ac, char **av);
void		ft_init_struct(t_file *map);
int			ft_check_file(char *str);
void		ft_check_path(t_file *map);
int			ft_validate_map(t_file *map);
void		ft_init_map(char *file, t_file *map);
int			ft_is_ber(char *str);
int			ft_print_message(t_file *map);
void		free_matrix(char **matrix);
/* Message Error*/
void		ft_file_missing(void);
void		ft_foreign_char(void);
int			ft_is_not_ber(void);
void		ft_is_not_close(void);
void		ft_is_not_rectangle(void);
void		ft_map_to_big(void);
void		ft_no_collectible(void);
void		ft_no_exit(void);
void		ft_no_path(void);
void		ft_player_error(void);
void		ft_to_many_file(void);
/*Render Game*/
int			ft_render_game(t_file *game);
void		hook(void *params);
void		ft_make_move(char *movement, t_file *game);
void		ft_loop_game(t_file *game);
void		free_game(t_file *game);
void		print_game_info(t_file *game);
void		set_player_move(t_file *game);
#endif