/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:03:34 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/09/28 11:33:00 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		sl_img_loader(t_data *data);
void	sl_draw(t_data *data);
void	sl_draw_tile(char c, int x, int y, t_data *data);
void	sl_draw_misc(t_data *data);
void	sl_draw_gameover(t_data *data);

void	sl_draw(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	mlx_clear_window(data->mlx, data->win);
	if (data->gameover == 0)
	{
		while (++i < data->map.row)
		{
			j = -1;
			while (++j < data->map.col)
				sl_draw_tile(data->map.map[i][j], j, i, data);
		}
		sl_draw_misc(data);
	}
	else
		sl_draw_gameover(data);
}

void	sl_draw_tile(char c, int x, int y, t_data *data)
{
	if (c == '1')
		mlx_put_image_to_window(\
		data->mlx, data->win, data->wall.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(\
		data->mlx, data->win, data->bg.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(\
		data->mlx, data->win, data->item.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(\
		data->mlx, data->win, data->exit.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(\
		data->mlx, data->win, data->player.img, x * TILE_SIZE, y * TILE_SIZE);
}

void	sl_draw_misc(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 6, 20, \
	0, ft_itoa(data->moves));
}

void	sl_draw_gameover(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 6, 20, \
	0xFFFFFF, "Victory!");
	mlx_string_put(data->mlx, data->win, 6, 20 + TILE_SIZE, \
	0xFFFFFF, "Moves : ");
	mlx_string_put(data->mlx, data->win, 6 + 3 * TILE_SIZE, 20 + TILE_SIZE, \
	0xFFFFFF, ft_itoa(data->moves));
	mlx_string_put(data->mlx, data->win, 6, 20 + 2 * TILE_SIZE, \
	0xFFFFFF, "<Press ESC to close>");
}

int	sl_img_loader(t_data *data)
{
	data->bg.height = TILE_SIZE;
	data->bg.width = TILE_SIZE;
	data->bg.img = mlx_png_file_to_image(data->mlx, "img/background.png",
			&data->bg.width, &data->bg.height);
	data->wall.height = TILE_SIZE;
	data->wall.width = TILE_SIZE;
	data->wall.img = mlx_png_file_to_image(data->mlx, "img/wall.png",
			&data->wall.width, &data->wall.height);
	data->item.height = TILE_SIZE;
	data->item.width = TILE_SIZE;
	data->item.img = mlx_png_file_to_image(data->mlx, "img/collectible.png",
			&data->item.width, &data->item.height);
	data->exit.height = TILE_SIZE;
	data->exit.width = TILE_SIZE;
	data->exit.img = mlx_png_file_to_image(data->mlx, "img/exit.png",
			&data->exit.width, &data->exit.height);
	data->player.height = TILE_SIZE;
	data->player.width = TILE_SIZE;
	data->player.img = mlx_png_file_to_image(data->mlx, "img/player.png",
			&data->player.width, &data->player.height);
	if (data->bg.img == NULL || data->wall.img == NULL || data->item.img == NULL
		|| data->exit.img == NULL || data->player.img == NULL)
		return (-1);
	return (0);
}
