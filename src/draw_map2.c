/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:38:00 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/25 17:01:02 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_empty_space(t_vars *mlx, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	j = 0;
	while (j < TILE_SIZE)
	{
		i = 0;
		while (i < TILE_SIZE)
		{
			color = get_pixel_from_xpm(mlx->empty.xpm, i, j);
			pixel_put(&mlx->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_player(t_vars *mlx, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	j = 0;
	while (j < TILE_SIZE)
	{
		i = 0;
		while (i < TILE_SIZE)
		{
			color = get_pixel_from_xpm(mlx->player.current_xpm, i, j);
			pixel_put(&mlx->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_enemy(t_vars *mlx, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	j = 0;
	while (j < TILE_SIZE)
	{
		i = 0;
		while (i < TILE_SIZE)
		{
			color = get_pixel_from_xpm(mlx->enemy.current_xpm, i, j);
			pixel_put(&mlx->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
