/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 09:21:54 by rkoper        #+#    #+#                 */
/*   Updated: 2022/03/28 09:25:03 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_check(t_vars *mlx, int fd)
{
	char	*line;

	mlx->items.collectible = 0;
	mlx->items.start_pos = 0;
	mlx->items.exit = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!is_map_val(line, mlx) \
			|| !newline_count(line, mlx) || !wall_check(line))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	if (!mlx->items.exit || !mlx->items.start_pos \
		|| !mlx->items.collectible)
		return (0);
	return (1);
}

int	is_map_val(char *line, t_vars *mlx)
{
	while (*line)
	{
		if (*line == 'P')
			mlx->items.start_pos += 1;
		else if (*line == 'C')
			mlx->items.collectible += 1;
		else if (*line == 'E')
			mlx->items.exit += 1;
		else if (*line != '0' && *line != '1' && *line != '\n' && *line != 'W')
			return (0);
		line++;
	}
	return (1);
}

int	wall_check(char *line)
{
	int			len;
	static int	row = -1;

	len = ft_strlen(line);
	row += 1;
	if (line[len - 1] != '\n')
		row = 0;
	if (row == 0)
	{
		while (*line)
		{
			if (*line != '1' && *line != '\n')
				return (0);
			line++;
		}
	}
	else if (line[0] != '1' || line[len - 2] != '1')
		return (0);
	return (1);
}

int	newline_count(char *line, t_vars *mlx)
{
	static int	newlines;
	static int	length;

	newlines += 1;
	if (length != kinda_strlen(line) && newlines != 1)
		return (0);
	length = kinda_strlen(line);
	mlx->width = length;
	mlx->height = newlines;
	return (1);
}

int	kinda_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != '\n')
		i++;
	return (i);
}
