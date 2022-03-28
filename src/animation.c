/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:04:43 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/28 08:56:45 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animation(t_vars *mlx)
{
	if (get_collectible(mlx))
		draw_map(mlx);
	else
		usleep(10000);
	return (0);
}

int	get_collectible(t_vars *mlx)
{
	static int	i;

	if (!i)
		mlx->collectible.current_xpm = mlx->collectible.xpm1;
	else if (i == 20)
		mlx->collectible.current_xpm = mlx->collectible.xpm2;
	else if (i == 40)
		mlx->collectible.current_xpm = mlx->collectible.xpm3;
	else if (i == 60)
		mlx->collectible.current_xpm = mlx->collectible.xpm2;
	i++;
	if (i == 1 || i == 21 || i == 41 || i == 61)
		return (1);
	if (i == 80)
		i = 0;
	return (0);
}
