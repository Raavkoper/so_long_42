/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_xpm.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 15:00:23 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/28 09:37:03 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_xpm(t_vars *mlx)
{
	int	height;
	int	width;

	mlx->player.xpm.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/ster.xpm", &width, &height);
	mlx->wall.xpm.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/wall.xpm", &width, &height);
	mlx->empty.xpm.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/empty_space.xpm", &width, &height);
	mlx->exit.xpm_open.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/open_gate.xpm", &width, &height);
	mlx->exit.xpm_closed.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/error_gate.xpm", &width, &height);
	initialize_xpm2(mlx);
}

void	initialize_xpm2(t_vars *mlx)
{
	int	height;
	int	width;

	mlx->collectible.xpm1.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/between_1.xpm", &width, &height);
	mlx->collectible.xpm2.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/between_2.xpm", &width, &height);
	mlx->collectible.xpm3.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/between_3.xpm", &width, &height);
	mlx->enemy.xpm_left.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/dog_left.xpm", &width, &height);
	mlx->enemy.xpm_right.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/dog_right.xpm", &width, &height);
	mlx->enemy.xpm_lj.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/dog_lj.xpm", &width, &height);
	mlx->enemy.xpm_rj.img = mlx_xpm_file_to_image(mlx->mlx, \
	"xpm_files/dog_rj.xpm", &width, &height);
	initialize_addr(mlx);
}

void	initialize_addr(t_vars *mlx)
{
	mlx->player.xpm.addr = mlx_get_data_addr(mlx->player.xpm.img, \
	&mlx->player.xpm.bits_per_pixel, \
	&mlx->player.xpm.line_length, &mlx->player.xpm.endian);
	mlx->wall.xpm.addr = mlx_get_data_addr(mlx->wall.xpm.img, \
	&mlx->wall.xpm.bits_per_pixel, \
	&mlx->wall.xpm.line_length, &mlx->wall.xpm.endian);
	mlx->empty.xpm.addr = mlx_get_data_addr(mlx->empty.xpm.img, \
	&mlx->empty.xpm.bits_per_pixel, \
	&mlx->empty.xpm.line_length, &mlx->empty.xpm.endian);
	mlx->exit.xpm_closed.addr = mlx_get_data_addr(mlx->exit.xpm_closed.img, \
	&mlx->exit.xpm_closed.bits_per_pixel, \
	&mlx->exit.xpm_closed.line_length, &mlx->exit.xpm_closed.endian);
	mlx->exit.xpm_open.addr = mlx_get_data_addr(mlx->exit.xpm_open.img, \
	&mlx->exit.xpm_open.bits_per_pixel, \
	&mlx->exit.xpm_open.line_length, &mlx->exit.xpm_open.endian);
	mlx->player.current_xpm = mlx->player.xpm;
	initialize_addr2(mlx);
}

void	initialize_addr2(t_vars *mlx)
{
	mlx->collectible.xpm1.addr = mlx_get_data_addr(mlx->collectible.xpm1.img, \
	&mlx->collectible.xpm1.bits_per_pixel, \
	&mlx->collectible.xpm1.line_length, &mlx->collectible.xpm1.endian);
	mlx->collectible.xpm2.addr = mlx_get_data_addr(mlx->collectible.xpm2.img, \
	&mlx->collectible.xpm2.bits_per_pixel, \
	&mlx->collectible.xpm2.line_length, &mlx->collectible.xpm2.endian);
	mlx->collectible.xpm3.addr = mlx_get_data_addr(mlx->collectible.xpm3.img, \
	&mlx->collectible.xpm3.bits_per_pixel, \
	&mlx->collectible.xpm3.line_length, &mlx->collectible.xpm3.endian);
	mlx->enemy.xpm_left.addr = mlx_get_data_addr(mlx->enemy.xpm_left.img, \
	&mlx->enemy.xpm_left.bits_per_pixel, \
	&mlx->enemy.xpm_left.line_length, &mlx->enemy.xpm_left.endian);
	mlx->enemy.xpm_right.addr = mlx_get_data_addr(mlx->enemy.xpm_right.img, \
	&mlx->enemy.xpm_right.bits_per_pixel, \
	&mlx->enemy.xpm_right.line_length, &mlx->enemy.xpm_right.endian);
	mlx->enemy.xpm_lj.addr = mlx_get_data_addr(mlx->enemy.xpm_lj.img, \
	&mlx->enemy.xpm_lj.bits_per_pixel, \
	&mlx->enemy.xpm_lj.line_length, &mlx->enemy.xpm_lj.endian);
	mlx->enemy.xpm_rj.addr = mlx_get_data_addr(mlx->enemy.xpm_rj.img, \
	&mlx->enemy.xpm_rj.bits_per_pixel, \
	&mlx->enemy.xpm_rj.line_length, &mlx->enemy.xpm_rj.endian);
	mlx->collectible.current_xpm = mlx->collectible.xpm1;
	mlx->enemy.current_xpm = mlx->enemy.xpm_left;
}
