/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 11:21:54 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/28 09:27:51 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map(t_vars *mlx)
{
	t_map	*iter;

	iter = mlx->map;
	while (iter)
	{
		if (iter->content == WALL)
			draw_wall(mlx, iter->x, iter->y);
		if (iter->content == COLLECTIBLE)
			draw_collectible(mlx, iter->x, iter->y);
		if (iter->content == EXIT)
			draw_exit(mlx, iter->x, iter->y);
		if (iter->content == EMPTY_SPACE)
			draw_empty_space(mlx, iter->x, iter->y);
		iter = iter->next;
	}
	draw_enemy(mlx, mlx->enemy.x, mlx->enemy.y);
	draw_player(mlx, mlx->player.x, mlx->player.y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

void	append_list(char c, int x, int y, t_vars *mlx)
{
	t_map	*new_node;
	t_map	*last;

	last = mlx->map;
	new_node = malloc(sizeof(t_map));
	if (!new_node)
	{
		free_map(&mlx->map);
		exit(EXIT_FAILURE);
	}
	new_node->x = x;
	new_node->y = y;
	new_node->content = c;
	new_node->next = NULL;
	if (!mlx->map)
	{
		mlx->map = new_node;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new_node;
}

void	read_map(int fd, t_vars *mlx)
{
	char	*line;
	char	*temp;
	int		x;
	int		y;

	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		x = 0;
		temp = line;
		while (*line && *line != '\n')
		{
			append_list(*line, x, y, mlx);
			line++;
			x += TILE_SIZE;
		}
		free(temp);
		line = get_next_line(fd);
		y += TILE_SIZE;
	}
}

void	initialize_map(t_vars *mlx, char **argv)
{
	int		fd;
	int		errorfd;
	int		len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 4] != '.' || argv[1][len - 3] != 'b' ||
		argv[1][len - 2] != 'e' || argv[1][len - 1] != 'r')
		error_message('b');
	mlx->map = NULL;
	fd = open(argv[1], O_RDONLY);
	errorfd = open(argv[1], O_RDONLY);
	errorfd = error_check(mlx, errorfd);
	if (!errorfd)
		error_message('m');
	read_map(fd, mlx);
	initialize_enemy(mlx);
	initialize_player(mlx);
	mlx->collectible.amount = mlx->items.collectible;
}

void	check_dead(t_vars *mlx)
{
	if (mlx->player.y == mlx->enemy.y && mlx->player.x == mlx->enemy.x)
	{
		ft_printf("You got eaten:C\n");
		free_map(&mlx->map);
		exit(0);
	}
}
