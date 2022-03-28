/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 13:38:50 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/25 17:00:11 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_wall(t_vars *mlx, int x, int y)
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
			color = get_pixel_from_xpm(mlx->wall.xpm, i, j);
			pixel_put(&mlx->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_collectible(t_vars *mlx, int x, int y)
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
			color = get_pixel_from_xpm(mlx->collectible.current_xpm, i, j);
			pixel_put(&mlx->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_exit(t_vars *mlx, int x, int y)
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
			if (mlx->collectible.amount == 0)
				color = get_pixel_from_xpm(mlx->exit.xpm_open, i, j);
			else
				color = get_pixel_from_xpm(mlx->exit.xpm_closed, i, j);
			pixel_put(&mlx->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
