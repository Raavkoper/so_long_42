/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 12:10:29 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/28 10:37:05 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_message(char c)
{
	if (c == 'a')
		ft_printf("invalid arguments given... Usage:./so_long valid_map.ber\n");
	if (c == 'm')
		ft_printf("map error\n");
	if (c == 'b')
		ft_printf("invalid map format... Usage:./so_long valid_map.ber\n");
	exit(0);
}

void	free_map(t_map **map)
{
	t_map	*temp;

	while (*map)
	{
		temp = (*map)->next;
		free(*map);
		*map = temp;
	}
	map = NULL;
}

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel_from_xpm(t_data xpm, int x, int y)
{
	char	*dst;

	dst = xpm.addr + (y * xpm.line_length + x * (xpm.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	main(int argc, char **argv)
{
	t_vars	mlx;

	if (argc != 2)
		error_message('a');
	mlx.mlx = mlx_init();
	initialize_map(&mlx, argv);
	initialize_xpm(&mlx);
	mlx.img.img = mlx_new_image(mlx.mlx, TILE_SIZE * (mlx.width - 1), \
	TILE_SIZE * mlx.height);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, \
	&mlx.img.line_length, &mlx.img.endian);
	mlx.win = mlx_new_window(mlx.mlx, TILE_SIZE * (mlx.width - 1), \
	TILE_SIZE * mlx.height, "so_long");
	draw_map(&mlx);
	mlx_loop_hook(mlx.mlx, animation, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}
