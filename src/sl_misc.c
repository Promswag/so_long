/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:13:30 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/09/28 12:24:23 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		sl_close(t_data *data);
void	sl_game_init(t_data *data);
char	*sl_strjoin(char *s1, char *s2);

int	sl_close(t_data *data)
{
	sl_map_free(data);
	if (data->bg.img)
		mlx_destroy_image(data->mlx, data->bg.img);
	if (data->wall.img)
		mlx_destroy_image(data->mlx, data->wall.img);
	if (data->item.img)
		mlx_destroy_image(data->mlx, data->item.img);
	if (data->exit.img)
		mlx_destroy_image(data->mlx, data->exit.img);
	if (data->player.img)
		mlx_destroy_image(data->mlx, data->player.img);
	exit(0);
	return (0);
}

void	sl_game_init(t_data *data)
{
	data->gameover = 0;
	data->moves = 0;
	data->valid_item = 0;
	data->valid_exit = 0;
	data->tmp_exit = 0;
	data->map.item_c = 0;
	data->map.item_e = 0;
	data->map.item_p = 0;
	data->map.row = 0;
	data->map.col = 0;
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		j = 0;
		while (*(s1 + j))
			*(str + i++) = *(s1 + j++);
		j = 0;
		while (*(s2 + j))
			*(str + i++) = *(s2 + j++);
		str[i] = '\0';
	}
	free(s1);
	free(s2);
	return (str);
}
