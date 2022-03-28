/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:54:13 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/25 17:03:51 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_move(t_vars *mlx)
{
	static int	i;

	if (mlx->enemy.x < mlx->player.x && (i == 0 || i == 5 \
		|| i == 10 || i == 7 || i == 9 || i == 1))
	{
		mlx->enemy.x += 32;
		mlx->enemy.current_xpm = mlx->enemy.xpm_right;
	}
	if (mlx->enemy.y < mlx->player.y && (i == 1 || i == 4 \
		|| i == 11 || i == 7 || i == 3 || i == 6))
		mlx->enemy.y += 32;
	if (mlx->enemy.x > mlx->player.x && (i == 2 || i == 7 \
		|| i == 8 || i == 4 || i == 2 || i == 11))
	{
		mlx->enemy.x -= 32;
		mlx->enemy.current_xpm = mlx->enemy.xpm_left;
	}
	if (mlx->enemy.y > mlx->player.y && (i == 3 || i == 6 \
		|| i == 9 || i == 0 || i == 4 || i == 10))
		mlx->enemy.y -= 32;
	i += 1;
	if (i == 12)
		i = 0;
}

void	check_jump(t_vars *mlx)
{
	t_map	*iter;

	iter = mlx->map;
	while (iter)
	{
		if (iter->content == WALL && iter->x == mlx->enemy.x \
			&& iter->y == mlx->enemy.y)
			break ;
		if (iter->content != WALL && iter->x == mlx->enemy.x \
			&& iter->y == mlx->enemy.y)
		{
			stop_jump(mlx);
			return ;
		}
		if (iter->next == NULL)
			return ;
		iter = iter->next;
	}
	if (mlx->enemy.current_xpm.img == mlx->enemy.xpm_right.img \
		|| mlx->enemy.current_xpm.img == mlx->enemy.xpm_rj.img)
		mlx->enemy.current_xpm = mlx->enemy.xpm_rj;
	else if (mlx->enemy.current_xpm.img == mlx->enemy.xpm_left.img \
		|| mlx->enemy.current_xpm.img == mlx->enemy.xpm_lj.img)
		mlx->enemy.current_xpm = mlx->enemy.xpm_lj;
}

void	stop_jump(t_vars *mlx)
{
	if (mlx->enemy.current_xpm.img == mlx->enemy.xpm_right.img \
		|| mlx->enemy.current_xpm.img == mlx->enemy.xpm_rj.img)
		mlx->enemy.current_xpm = mlx->enemy.xpm_right;
	else if (mlx->enemy.current_xpm.img == mlx->enemy.xpm_left.img \
		|| mlx->enemy.current_xpm.img == mlx->enemy.xpm_lj.img)
		mlx->enemy.current_xpm = mlx->enemy.xpm_left;
}
