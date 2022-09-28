/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:42:11 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/09/27 18:23:23 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		sl_key_hook(int keycode, t_data *data);
void	sl_movement_handler(int x, int y, t_data *data);
void	sl_map_update(int x, int y, t_data *data);

int	sl_key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		sl_close(data);
	if (data->gameover == 0)
	{
		if (keycode == 13)
			sl_movement_handler(0, -1, data);
		if (keycode == 1)
			sl_movement_handler(0, 1, data);
		if (keycode == 0)
			sl_movement_handler(-1, 0, data);
		if (keycode == 2)
			sl_movement_handler(1, 0, data);
	}
	sl_draw(data);
	return (0);
}

void	sl_movement_handler(int x, int y, t_data *data)
{
	char	target;

	target = data->map.map[data->player.pos.y + y][data->player.pos.x + x];
	if (target == 'C')
		data->map.item_c--;
	if (target == 'C' || target == 'E' || target == '0')
	{
		data->moves++;
		sl_map_update(x, y, data);
	}
	if (target == 'E' && data->map.item_c == 0)
		data->gameover = 1;
	if (target == 'E')
	{
		data->tmp_exit++;
		data->tmp_exit_pos.x = data->player.pos.x;
		data->tmp_exit_pos.y = data->player.pos.y;
	}
}

void	sl_map_update(int x, int y, t_data *data)
{
	data->map.map[data->player.pos.y][data->player.pos.x] = '0';
	data->map.map[data->player.pos.y + y][data->player.pos.x + x] = 'P';
	data->player.pos.y += y;
	data->player.pos.x += x;
	if (data->tmp_exit)
	{
		if (data->player.pos.x != data->tmp_exit_pos.x
			|| data->player.pos.y != data->tmp_exit_pos.y)
		{
			data->map.map[data->tmp_exit_pos.y][data->tmp_exit_pos.x] = 'E';
			data->tmp_exit--;
		}
	}
}
