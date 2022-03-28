/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_alivies.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 12:00:14 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/25 16:52:58 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_player(t_vars *mlx)
{
	t_map	*iter;
	int		i;

	i = 0;
	iter = mlx->map;
	while (iter != NULL)
	{
		if (iter->content == PLAYER && i == 0)
		{
			mlx->player.x = iter->x;
			mlx->player.y = iter->y;
			iter->content = EMPTY_SPACE;
			iter = iter->next;
			i++;
			continue ;
		}
		if (iter->content == PLAYER)
			iter->content = EMPTY_SPACE;
		iter = iter->next;
	}
}

void	initialize_enemy(t_vars *mlx)
{
	t_map	*iter;
	int		i;

	mlx->enemy.x = 0;
	i = 0;
	iter = mlx->map;
	while (iter != NULL)
	{
		if (iter->content == ENEMY && i == 0)
		{
			mlx->enemy.x = iter->x;
			mlx->enemy.y = iter->y;
			iter->content = EMPTY_SPACE;
			iter = iter->next;
			i++;
			continue ;
		}
		if (iter->content == ENEMY)
			iter->content = EMPTY_SPACE;
		iter = iter->next;
	}
	if (!mlx->enemy.x)
		set_enemy(mlx);
}

void	set_enemy(t_vars *mlx)
{
	mlx->enemy.x = 32;
	mlx->enemy.y = 32;
}
