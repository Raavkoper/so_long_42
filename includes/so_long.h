/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 12:08:35 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/28 10:37:55 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/mlx/mlx.h"
# include "../libraries/libft/libft.h"

# include <fcntl.h>

# define TILE_SIZE 32

typedef enum e_elements {
	EMPTY_SPACE = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	ENEMY = 'W',
}				t_elements;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_items {
	int	collectible;
	int	start_pos;
	int	exit;
}				t_items;

typedef struct s_map {
	int				x;
	int				y;
	char			content;
	struct s_map	*next;
}				t_map;

typedef struct s_player {
	t_data	current_xpm;
	t_data	xpm;
	int		x;
	int		y;
}				t_player;

typedef struct s_enemy {
	t_data	current_xpm;
	t_data	xpm_left;
	t_data	xpm_right;
	t_data	xpm_lj;
	t_data	xpm_rj;
	int		x;
	int		y;
}				t_enemy;

typedef struct s_wall {
	t_data	xpm;
}				t_wall;

typedef struct s_collectible {
	t_data	current_xpm;
	t_data	xpm1;
	t_data	xpm2;
	t_data	xpm3;
	int		amount;
}				t_collectible;

typedef struct s_empty {
	t_data	xpm;
}				t_empty;

typedef struct s_exit {
	t_data	xpm_closed;
	t_data	xpm_open;
}				t_exit;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				dead;
	t_data			img;
	t_map			*map;
	t_items			items;
	t_player		player;
	t_enemy			enemy;
	t_wall			wall;
	t_exit			exit;
	t_collectible	collectible;
	t_empty			empty;
}				t_vars;

int				key_hook(int keycode, t_vars *mlx);
void			pixel_put(t_data *img, int x, int y, int color);
void			read_map(int fd, t_vars *mlx);
void			error_message(char c);
void			free_map(t_map **map);
void			append_list(char c, int x, int y, t_vars *mlx);
void			print_map_values(t_map **map);
void			draw_map(t_vars *mlx);
void			draw_wall(t_vars *mlx, int x, int y);
void			draw_collectible(t_vars *mlx, int x, int y);
void			draw_exit(t_vars *mlx, int x, int y);
void			draw_empty_space(t_vars *mlx, int x, int y);
void			draw_player(t_vars *mlx, int x, int y);
void			draw_enemy(t_vars *mlx, int x, int y);
int				error_check(t_vars *mlx, int fd);
int				is_map_val(char *line, t_vars *mlx);
int				wall_check(char *line);
int				newline_count(char *line, t_vars *mlx);
int				kinda_strlen(char const *str);
unsigned int	get_pixel_from_xpm(t_data xpm, int x, int y);
void			initialize_player(t_vars *mlx);
void			initialize_enemy(t_vars *mlx);
void			initialize_map(t_vars *mlx, char **argv);
void			initialize_xpm(t_vars *mlx);
void			initialize_xpm2(t_vars *mlx);
void			initialize_addr(t_vars *mlx);
void			initialize_addr2(t_vars *mlx);
void			initialize_game(t_vars *mlx);
void			move(t_vars *mlx, char c);
int				check_wall(t_vars *mlx, char c);
void			check_collectible(t_vars *mlx);
void			check_exit(t_vars *mlx);
int				animation(t_vars *mlx);
int				get_collectible(t_vars *mlx);
void			enemy_move(t_vars *mlx);
int				pos(int num);
void			check_dead(t_vars *mlx);
void			check_close(t_vars *mlx);
void			check_jump(t_vars *mlx);
void			stop_jump(t_vars *mlx);
void			set_enemy(t_vars *mlx);
#endif