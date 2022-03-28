/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 13:07:37 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/28 10:29:23 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_vars *mlx)
{
	if (keycode == 53)
	{
		free_map(&mlx->map);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13)
		move(mlx, 'w');
	if (keycode == 0)
		move(mlx, 'a');
	if (keycode == 1)
		move(mlx, 's');
	if (keycode == 2)
		move(mlx, 'd');
	return (0);
}

void	move(t_vars *mlx, char c)
{
	if (c == 'w' && check_wall(mlx, 'w'))
	{		
		mlx->player.y -= TILE_SIZE;
		enemy_move(mlx);
	}
	if (c == 'a' && check_wall(mlx, 'a'))
	{
		mlx->player.x -= TILE_SIZE;
		enemy_move(mlx);
	}
	if (c == 's' && check_wall(mlx, 's'))
	{
		mlx->player.y += TILE_SIZE;
		enemy_move(mlx);
	}
	if (c == 'd' && check_wall(mlx, 'd'))
	{
		mlx->player.x += TILE_SIZE;
		enemy_move(mlx);
	}
	check_collectible(mlx);
	check_jump(mlx);
	check_dead(mlx);
	check_exit(mlx);
	draw_map(mlx);
}

int	check_wall(t_vars *mlx, char c)
{
	t_map		*iter;
	static int	i;

	iter = mlx->map;
	while (iter)
	{
		if (c == 'w' && iter->content == WALL \
			&& iter->y == mlx->player.y - TILE_SIZE && iter->x == mlx->player.x)
			return (0);
		if (c == 'a' && iter->content == WALL \
			&& iter->y == mlx->player.y && iter->x == mlx->player.x - TILE_SIZE)
			return (0);
		if (c == 's' && iter->content == WALL \
			&& iter->y == mlx->player.y + TILE_SIZE && iter->x == mlx->player.x)
			return (0);
		if (c == 'd' && iter->content == WALL \
			&& iter->y == mlx->player.y && iter->x == mlx->player.x + TILE_SIZE)
			return (0);
		iter = iter->next;
	}
	i += 1;
	ft_printf("Moves: %d\n", i);
	return (1);
}

void	check_collectible(t_vars *mlx)
{
	t_map	*iter;

	iter = mlx->map;
	while (iter)
	{
		if (mlx->player.x == iter->x && mlx->player.y == iter->y \
			&& iter->content == COLLECTIBLE)
		{
			iter->content = EMPTY_SPACE;
			mlx->collectible.amount -= 1;
			return ;
		}
		iter = iter->next;
	}
}

void	check_exit(t_vars *mlx)
{
	t_map	*iter;

	iter = mlx->map;
	if (mlx->collectible.amount != 0)
		return ;
	while (iter)
	{
		if (mlx->player.x == iter->x && mlx->player.y == iter->y \
			&& iter->content == EXIT)
		{
			ft_printf("Good job mate;)\n");
			free_map(&mlx->map);
			exit(EXIT_SUCCESS);
		}
		iter = iter->next;
	}
}
