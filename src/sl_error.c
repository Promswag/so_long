/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:18:02 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/09/28 11:30:29 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		sl_args_handler(int argc, char **argv);
int		sl_error_handler(int error);

int	sl_args_handler(int argc, char **argv)
{
	int	l;

	if (argc == 1)
		return (sl_error_handler(1));
	if (argc > 2)
		return (sl_error_handler(2));
	l = ft_strlen(argv[1]);
	if (l < 4)
		return (sl_error_handler(3));
	if (!(argv[1][l - 4] == '.' && \
		argv[1][l - 3] == 'b' && \
		argv[1][l - 2] == 'e' && \
		argv[1][l - 1] == 'r'))
		return (sl_error_handler(3));
	return (0);
}

int	sl_error_handler(int error)
{
	ft_printf("Error\n");
	if (error == 1)
		ft_printf("Missing map path.\n");
	if (error == 2)
		ft_printf("Too many arguments.\n");
	if (error == 3)
		ft_printf("Unauthorized file extension.\n");
	if (error == 10)
		ft_printf("Read error.\n");
	if (error == 11)
		ft_printf("Unauthorized map shape.\n");
	if (error == 12)
		ft_printf("Map needs to be enclosed by walls.\n");
	if (error == 13)
		ft_printf("Unauthorized characters.\n");
	if (error == 14)
		ft_printf("Map needs 1 player spawn.\n");
	if (error == 15)
		ft_printf("Map needs at least 1 collectible.\n");
	if (error == 16)
		ft_printf("Map needs at least 1 exit.\n");
	if (error == 17)
		ft_printf("Map needs a valid path.\n");
	return (-1);
}
